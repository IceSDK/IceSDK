#pragma once

#include <vector>
#include <unordered_map>

#include "glm/vec2.hpp"
#include "glm/vec4.hpp"

#include "Graphics/Texture2D.h"

#include "ft2build.h"
#include FT_FREETYPE_H

#define FT_ATLAS_SIZE 1024 // 1024x1024

namespace IceSDK::Graphics
{
    struct Glyph
    {
        glm::vec2 Size;   // Bottom && Right
        glm::vec2 Offset; // Top    && left
        float Advance;    // Left string offset

        size_t AtlasIndex;

        std::vector<glm::vec4> PixelData; // TODO: delete this data
    };

    struct FontAtlas
    {
        std::unordered_map<int32_t, Glyph> Glyphs;
        Memory::Ptr<Graphics::Texture2D> Atlas;

        glm::vec2 Pen;

        inline bool Fits(const Glyph &glyph)
        {
            size_t total_size = 0;
            for (auto &_glyph : this->Glyphs)
                total_size += _glyph.second.PixelData.size();

            total_size += glyph.PixelData.size();
            if (total_size * 4 > FT_ATLAS_SIZE * FT_ATLAS_SIZE)
                return false;

            return true;
        }
    };
} // namespace IceSDK::Graphics
