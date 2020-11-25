#pragma once

#include "IceSDK/Assets/AssetManager.hh"
#include "IceSDK/Audio/AudioEngine.hh"
#include "IceSDK/Graphics/FontManager.hh"
#include "IceSDK/Graphics/Shaders/ShaderManager.hh"
#include "IceSDK/Graphics/SpriteBatch.hh"
#include "IceSDK/Graphics/Window.hh"
#include "IceSDK/Input/InputPipeline.hh"
#include "IceSDK/Scene.hh"

#include <bx/allocator.h>

#include <memory>

namespace IceSDK
{
    class GameBase
    {
    public:
        explicit GameBase();
        ~GameBase();

        void Run();

        /*****************************************************
         * GetAudioEngine
         *
         * Gets the active Audio Engine
         *
         * @return Audio Engine
         *****************************************************/
        Audio::AudioEngine* GetAudioEngine() const { return m_pAudioEngine; }

        /*****************************************************
         * GetSpriteBatch
         *
         * Gets the active Sprite Batch
         *
         * @return Sprite Batch
         *****************************************************/
        Graphics::SpriteBatch* GetSpriteBatch() const { return m_pSpriteBatch; }

        /*****************************************************
         * GetAssetManager
         *
         * Gets the active Asset Manager
         *
         * @return Asset Manager
         *****************************************************/
        Assets::AssetManager* GetAssetManager() const
        {
            return m_pAssetManager;
        }

        /*****************************************************
         * GetGameWindow
         *
         * Gets the active Game Window
         *
         * @return Game Window
         *****************************************************/
        Graphics::GameWindow* GetGameWindow() const { return m_pGameWindow; }

        /*****************************************************
         * GetShaderManager
         *
         * Gets the active Shader Manager
         *
         * @return Shader Manager
         *****************************************************/
        Graphics::Shaders::ShaderManager* GetShaderManager() const
        {
            return m_pShaderManager;
        }

        /*****************************************************
         * GetFontManager
         *
         * Gets the active Font Manager
         *
         * @return Font Manager
         *****************************************************/
        Graphics::FontManager* GetFontManager() const { return m_pFontManager; }

        /*****************************************************
         * GetInputPipeline
         *
         * Gets the active Input Pipeline
         *
         * @return Font Manager
         *****************************************************/
        Input::InputPipeline* GetInputPipeline() const
        {
            return m_pInputPipeline;
        }

        /*****************************************************
         * GetActiveScene
         *
         * Gets the active Scene
         *
         * @return Scene
         *****************************************************/
        std::weak_ptr<Scene> GetActiveScene() const { return m_pActiveScene; }

        /*****************************************************
         * SetSceneActive
         *
         * Sets a specific scene active.
         *
         * @param pScene Scene which shall be activated
         *****************************************************/
        void SetSceneActive(std::shared_ptr<Scene> pScene)
        {
            this->m_pActiveScene = pScene;
        }

    protected:
        /*****************************************************
         * Init
         *
         * Initializes the Game itself.
         *****************************************************/
        virtual void Init();

        /*****************************************************
         * InitDraw
         *
         * Initializes the Game's drawing mechanic.
         *****************************************************/
        virtual void InitDraw();

        /*****************************************************
         * Shutdown
         *
         * Shuts down the Game itself.
         *****************************************************/
        virtual void Shutdown();

        /*****************************************************
         * Tick
         *
         * Tick is called each frame once to update
         * stuff seperated from rendering.
         *
         * @param fDelta Delta time
         *****************************************************/
        virtual void Tick(float pDelta);

        /*****************************************************
         * Draw
         *
         * Draw is called each frame once to draw stuff
         * onto the screen.
         *
         * @param fDelta Delta time
         *****************************************************/
        virtual void Draw(float pDelta);

    private:
        /*****************************************************
         * InternalDraw
         *
         * Internal function for drawing stuff.
         * E.G Debug sprites
         *
         * @param fDelta Delta time
         *****************************************************/
        static void InternalDraw(float pDelta);

        /*****************************************************
         * InternalTick
         *
         * Internal function for Update stuff.
         * E.G Scenes, Entities, Systems
         *
         * @param fDelta Delta time
         *****************************************************/
        static void InternalTick(float pDelta);

        /*****************************************************
         * InternalDrawInit
         *
         * Initializes the Game Engine's drawing mechanic.
         *****************************************************/
        static void InternalDrawInit();

        /*****************************************************
         * Shutdown
         *
         * Shuts down the Game Engine itself.
         *****************************************************/
        static void InternalShutdown();

#ifdef ICESDK_EMSCRIPTEN
        /*****************************************************
         * GetFileName
         *
         * Gets the file name from a given path
         *
         * @param svPath Path of a file
         *
         * @return Resulting file name
         *****************************************************/
        static void InternalMainLoop(void* arg);
#else
        bool _exit = false;
#endif

        int64_t m_iLastDelta;

        std::shared_ptr<Scene> m_pActiveScene;
        Graphics::GameWindow* m_pGameWindow;
        Audio::AudioEngine* m_pAudioEngine;
        Graphics::SpriteBatch* m_pSpriteBatch;
        Assets::AssetManager* m_pAssetManager;
        Graphics::Shaders::ShaderManager* m_pShaderManager;
        Graphics::FontManager* m_pFontManager;
        Input::InputPipeline* m_pInputPipeline;
    };
}  // namespace IceSDK

/*****************************************************
 * GetGameBase
 *
 * Gets the current active Game
 *
 * @return Game
 *****************************************************/
extern IceSDK::GameBase* GetGameBase();

// Used for Android implementation
// Don't use int main()
// use int IceSDKMain() instead
#if defined(ICESDK_SDL2) && defined(ICESDK_ANDROID)
    #define IceSDKMain IceSDK_main
#else
    #undef main
    #define IceSDKMain main
#endif
