#pragma once

#include <glm/vec2.hpp>

namespace IceSDK::Math
{
    template<typename T>
    struct Rect
    {
        T top, bottom, left, right;

        Rect(glm::vec2 pos, glm::vec2 size)
        {
            top = pos.y;
            left = pos.x;

            bottom = pos.y + size.y;
            right = pos.x + size.x;
        }

        T Width() { return right - left; }

        T Height() { return bottom - top; }

        T X() { return left; }

        T Y() { return top; }

        glm::vec2 Position() { return { X(), Y() }; }

        glm::vec2 Size() { return { Width(), Height() }; }

        T length() { return (left - right) * (top - bottom); }
    };

    typedef Rect<float> Rectf;
    typedef Rect<double> Rectd;

    inline float Max(float x, float y)
    {
        if (x > y) return x;

        return y;
    }

    inline float Min(float x, float y)
    {
        if (x > y) return y;

        return x;
    }
}  // namespace IceSDK::Math
