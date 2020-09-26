#include "Utils/Logger.h"
#include "imgui.h"

#include "GameBase.h"
#include "Graphics/EntityHelper.h"
#include "Graphics/Fonts/FontFace.h"
#include "Graphics/ImGui/Widgets/SceneGraph.h"

using namespace IceSDK;

class Game final : public GameBase
{
public:
protected:
	void Init() override
	{
		this->_active_scene = std::make_shared<Scene>();
		this->_active_scene->SetGravity({ 0, -10.f });
	}

	void InitDraw() override
	{
		Graphics::Entity::Init(this->GetShaderManager());
		Graphics::Entity::InitScene(this->_active_scene);
		this->_active_scene->SetGravity({ 0, 2.f });

		_texture = this->GetAssetManager()->LoadTexture("/Assets/Box.png");
		_texture2 = this->GetAssetManager()->LoadTexture("/Assets/Ground.png");

		_gravity_entity = Graphics::Entity::CreateSprite(this->_active_scene, this->GetShaderManager(), _texture, { 50, 0, 0 }, { 50, 50 });
		_solid_entity = Graphics::Entity::CreateSprite(this->_active_scene, this->GetShaderManager(), _texture2, { 120, 250, 0 }, { 500, 50 });

		Graphics::Entity::AttachPhysicsObject(this->_active_scene, _gravity_entity); // TODO - change the namespace name "Graphics::"
		Graphics::Entity::AttachSolidPhysicsObject(this->_active_scene, _solid_entity); // TODO - change the namespace name "Graphics::"

	}

	void Draw(float pDelta) override
	{
		ImGuiWidgets::SceneGraph::Frame(this->GetActiveScene());
	}

private:
	Graphics::FontFaceHandle _fontHandle;
	Memory::Ptr<Graphics::Texture2D> _texture;
	Memory::Ptr<Graphics::Texture2D> _texture2;
	Entity _gravity_entity;
	Entity _solid_entity;
};

Memory::Ptr<Game> g_Game;
Memory::Ptr<IceSDK::GameBase> g_GameBase;

int IceSDKMain()
{
    g_Game = std::make_shared<Game>();
    g_GameBase = g_Game;

    g_Game->Run();

    g_Game = nullptr;
    g_GameBase = nullptr;
    return 0;
}

Memory::Ptr<GameBase> GetGameBase()
{
    return g_GameBase;
}
