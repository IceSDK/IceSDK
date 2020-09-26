#pragma once

#include <unordered_map>

#include <bgfx/bgfx.h>

#include <string>
#include <vector>

namespace IceSDK::Graphics::Shaders
{
    enum class eShaderType : uint8_t
    {
        Fragment = 0,
        Vertex = 1
    };

    class ShaderManager
    {
    public:
        // Internal function, can be used but shouldn't! use at your own risk!
        void AppendShader(const std::string& pKey,
                          bgfx::RendererType::Enum pRenderer, eShaderType pType,
                          const std::vector<uint8_t>& pSrc);

        // Internal function, can be used but shouldn't! use at your own risk!
        bgfx::ShaderHandle LoadShader(const std::string& pKey,
                                      const eShaderType pShaderType);

        bgfx::ProgramHandle LoadProgram(const std::string& pKey);

    private:
        struct Shader
        {
            std::string name;
            bgfx::RendererType::Enum renderer;
            eShaderType type;

            std::vector<uint8_t> code;
        };

        std::unordered_map<std::string, bgfx::ProgramHandle> _programs;

        std::vector<Shader> _shaders;
    };
}  // namespace IceSDK::Graphics::Shaders
