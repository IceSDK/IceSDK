#include "pch.h"

#include "Graphics/EntityHelper.h"

#include "ECS/Components/BaseComponent.h"
#include "ECS/Components/TransformComponent.h"
#include "ECS/Scene.h"

#include "Utils/Instrumentor.h"

#include "Graphics/Components/MeshComponent.h"
#include "Graphics/Components/ShaderComponent.h"
#include "Graphics/Components/SpriteComponent.h"
#include "Graphics/Components/TextComponent.h"

#include "ECS/Components/BaseComponent.h"
#include "ECS/Components/TransformComponent.h"
#include "ECS/Components/RigidbodyComponent.h"
#include "ECS/Scene.h"

/* Sprite Shaders */
#include "Graphics/Shaders/compiled/fs_sprite.d3d9.h"
#include "Graphics/Shaders/compiled/fs_sprite.d3d11.h"
#include "Graphics/Shaders/compiled/fs_sprite.d3d12.h"
#include "Graphics/Shaders/compiled/fs_sprite.d3d9.h"
#include "Graphics/Shaders/compiled/fs_sprite.glsl.h"
#include "Graphics/Shaders/compiled/fs_sprite.metal.h"
#include "Graphics/Shaders/compiled/fs_sprite.vulkan.h"
#include "Graphics/Shaders/compiled/vs_sprite.d3d11.h"
#include "Graphics/Shaders/compiled/vs_sprite.d3d12.h"
#include "Graphics/Shaders/compiled/vs_sprite.d3d9.h"
#include "Graphics/Shaders/compiled/vs_sprite.glsl.h"
#include "Graphics/Shaders/compiled/vs_sprite.metal.h"
#include "Graphics/Shaders/compiled/vs_sprite.vulkan.h"
#include "Graphics/Systems/SpriteRenderingSystem.h"
#include "Graphics/Systems/TextRenderingSystem.h"
#include "Physics/PhysicsSystem.h"

using namespace IceSDK;
using namespace IceSDK::Graphics;
using namespace IceSDK::Graphics::Entity;

static bgfx::VertexLayout g_2DPosTexCoordColourLayout;
struct Pos2DTexCoordColourVertex
{
    glm::vec2 pos;
    glm::vec2 uv;
    glm::vec4 colour;

    static void Init()
    {
        ICESDK_PROFILE_FUNCTION();

        g_2DPosTexCoordColourLayout.begin()
            .add(bgfx::Attrib::Position, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::TexCoord0, 2, bgfx::AttribType::Float)
            .add(bgfx::Attrib::Color0, 4, bgfx::AttribType::Float)
            .end();
    }
};

static Pos2DTexCoordColourVertex g_SpriteVertices[4] =
{
	{{1.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
	{{1.0f, 0.0f}, {1.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
	{{0.0f, 0.0f}, {0.0f, 0.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
	{{0.0f, 1.0f}, {0.0f, 1.0f}, {1.0f, 1.0f, 1.0f, 1.0f}},
};

static const uint16_t g_SpriteIndices[6] =
{
	0,
	1,
	3,
	1,
	2,
	3,
};

IceSDK::Entity Graphics::Entity::CreateSprite(
	Memory::Ptr<IceSDK::Scene> pScene,
	Memory::Ptr<Shaders::ShaderManager> pShaderManager,
	Memory::Ptr<Texture2D> pTex,
	const glm::vec3& position,
	const glm::vec2& size)
{
    ICESDK_PROFILE_FUNCTION();

    auto entity = pScene->CreateEntity("Sprite");

	entity.AddComponent<IceSDK::Components::TransformComponent>(position, glm::vec3{ 1.0f, 1.0f, 1.0f });
	entity.AddComponent<Graphics::Components::MeshComponent>(
		bgfx::createVertexBuffer(
			bgfx::makeRef(g_SpriteVertices, sizeof g_SpriteVertices),
			g_2DPosTexCoordColourLayout),
		bgfx::createIndexBuffer(bgfx::makeRef(g_SpriteIndices, sizeof g_SpriteIndices)));

    entity.AddComponent<Graphics::Components::ShaderComponent>(
        pShaderManager.get()->LoadProgram("Sprite"));

	glm::vec2 TexSize{ 0 };
	if (size.x != -1.f && size.y != -1.f)
		TexSize = size;
	else if (pTex != nullptr)
		TexSize = { pTex->Width(), pTex->Height() };

    entity.AddComponent<Graphics::Components::SpriteComponent>(TexSize, pTex);

    return entity;
}

IceSDK::Entity Graphics::Entity::CreateText(
	Memory::Ptr<IceSDK::Scene> pScene,
	Memory::Ptr<Shaders::ShaderManager> pShaderManager,
	const std::string& pText, size_t pFontSize, FontFaceHandle pFontFace)
{
    ICESDK_PROFILE_FUNCTION();

    auto entity = Entity::CreateSprite(pScene, pShaderManager, nullptr);

	auto& baseComponent = entity.GetComponent<IceSDK::Components::BaseComponent>();
	baseComponent.name = "TextSprite";

    entity.AddComponent<Graphics::Components::TextComponent>(
        pText, (uint64_t) 0, pFontSize, pFontFace);

    return entity;
}

void IceSDK::Graphics::Entity::AttachPhysicsObject(Memory::Ptr<IceSDK::Scene> pScene, IceSDK::Entity target)
{
	auto& transform = target.GetComponent<IceSDK::Components::TransformComponent>();
	auto& sprite = target.GetComponent<Graphics::Components::SpriteComponent>(); // TODO - we are using that to get size.

	IceSDK::Components::RigidbodyComponent phys_comp;
	phys_comp.body_def.type = b2_dynamicBody;
	phys_comp.body_def.position = b2Vec2(transform.position.x, transform.position.y);
	phys_comp.body = pScene->GetWorld()->CreateBody(&phys_comp.body_def);
	phys_comp.shape.SetAsBox(sprite.size.x, sprite.size.y);


	b2FixtureDef fixtureDef; // TODO - make these settings are editable (by scene)
	fixtureDef.density = 1.0f;
	fixtureDef.friction = 2.0f;
	fixtureDef.restitution = 0.5f;

	fixtureDef.shape = &phys_comp.shape;

	phys_comp.body->CreateFixture(&fixtureDef);

	target.AddComponent<IceSDK::Components::RigidbodyComponent>(phys_comp);
}

void IceSDK::Graphics::Entity::AttachSolidPhysicsObject(Memory::Ptr<IceSDK::Scene> pScene, IceSDK::Entity target)
{
	auto& transform = target.GetComponent<IceSDK::Components::TransformComponent>();
	auto& sprite = target.GetComponent<Graphics::Components::SpriteComponent>(); // TODO - we are using that to get size.

	IceSDK::Components::RigidbodyComponent phys_comp;
	phys_comp.body_def.position = b2Vec2(transform.position.x, transform.position.y);
	phys_comp.body = pScene->GetWorld()->CreateBody(&phys_comp.body_def);
	phys_comp.shape.SetAsBox(sprite.size.x, sprite.size.y);

	phys_comp.body->CreateFixture(&phys_comp.shape, 0.f);

	target.AddComponent<IceSDK::Components::RigidbodyComponent>(phys_comp);
}

void Graphics::Entity::Init(const Memory::Ptr<Graphics::Shaders::ShaderManager>& pShaderManager)
{
	ICESDK_PROFILE_FUNCTION();

    Pos2DTexCoordColourVertex::Init();
    Graphics::FontFace::Init();

    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D9, Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_d3d9[0],
                             &fs_sprite_d3d9[sizeof fs_sprite_d3d9]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D11,
        Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_d3d11[0],
                             &fs_sprite_d3d11[sizeof fs_sprite_d3d11]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D12,
        Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_d3d12[0],
                             &fs_sprite_d3d12[sizeof fs_sprite_d3d12]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::OpenGL, Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_glsl[0],
                             &fs_sprite_glsl[sizeof fs_sprite_glsl]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Metal, Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_metal[0],
                             &fs_sprite_metal[sizeof fs_sprite_metal]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Vulkan, Shaders::eShaderType::Fragment,
        std::vector<uint8_t>(&fs_sprite_vulkan[0],
                             &fs_sprite_vulkan[sizeof fs_sprite_vulkan]));

    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D9, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_d3d9[0],
                             &vs_sprite_d3d9[sizeof vs_sprite_d3d9]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D11, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_d3d11[0],
                             &vs_sprite_d3d11[sizeof vs_sprite_d3d11]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Direct3D12, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_d3d12[0],
                             &vs_sprite_d3d12[sizeof vs_sprite_d3d12]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::OpenGL, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_glsl[0],
                             &vs_sprite_glsl[sizeof vs_sprite_glsl]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Metal, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_metal[0],
                             &vs_sprite_metal[sizeof vs_sprite_metal]));
    pShaderManager->AppendShader(
        "Sprite", bgfx::RendererType::Vulkan, Shaders::eShaderType::Vertex,
        std::vector<uint8_t>(&vs_sprite_vulkan[0],
                             &vs_sprite_vulkan[sizeof vs_sprite_vulkan]));
}

void Graphics::Entity::InitScene(const Memory::Ptr<IceSDK::Scene>& pScene)
{
    ICESDK_PROFILE_FUNCTION();

	pScene->RegisterSystem<Systems::SpriteRenderingSystem>();
	pScene->RegisterSystem<Systems::TextRenderingSystem>();
	pScene->RegisterSystem<Systems::Physics::PhysicsSystem>();
}
