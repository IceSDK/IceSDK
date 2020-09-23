#pragma once

namespace IceSDK::Math
{
    float Max(float x, float y)
    {
        if (x > y)
            return x;

        return y;
    }

    float Min(float x, float y)
    {
        if (x > y)
            return y;

        return x;
    }
} // namespace IceSDK::Math