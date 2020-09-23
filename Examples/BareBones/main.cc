#include "GameBase.h"
#include "imgui.h"

#include "Graphics/Fonts/FontFace.h"
#include "Graphics/EntityHelper.h"
#include "Graphics/ImGui/Widgets/SceneGraph.h"

#include "Utils/Logger.h"

using namespace IceSDK;

class Game final : public GameBase
{
public:
protected:
	void Init() override
	{
		this->_active_scene = std::make_shared<Scene>();
	}

	void InitDraw() override
	{
		Graphics::Entity::Init(this->GetShaderManager());
		Graphics::Entity::InitScene(this->_active_scene);

		_fontHandle = GetFontManager()->LoadFont("./Roboto-Regular.ttf");
		ICESDK_TRACE("{}", _fontHandle);
		if (_fontHandle == INVALID_FONT_FACE_HANDLE)
		{
			ICESDK_CRITICAL("Failed to initialize FontFace!");
			return;
		}

		_font = Graphics::Entity::CreateText(this->_active_scene, this->GetShaderManager(), "Hello World!", 48, _fontHandle);
	}

	void Draw(float pDelta) override
	{
		// ImGuiWidgets::AssetBrowser::Frame(this->GetAssetManager());
		ImGuiWidgets::SceneGraph::Frame(this->GetActiveScene());
	}

private:
	Graphics::FontFaceHandle _fontHandle;

	Entity _font;
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
