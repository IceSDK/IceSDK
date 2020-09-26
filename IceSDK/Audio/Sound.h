#pragma once

#include <cstdint>

#if defined(ICESDK_FMOD)
    #include <fmod.hpp>
#endif

namespace IceSDK
{
    namespace Audio
    {
        class AudioSystem;

        class Sound
        {
        public:
            ~Sound();

            void Play();
            void Pause(bool pIsPaused = true) const;
            void Stop();
            void SetVolume(float pVolume = 1.0f) const;

            void SetFrequencyMultiplier(float pMultiplier = 1.0f);
            void Seek(uint32_t pPosition) const;
            void Reset();
            uint32_t Length() const;

        private:
            float _frequency;

            explicit Sound() = default;

#if defined(ICESDK_FMOD)
            FMOD::Sound* _sound = nullptr;
            FMOD::Channel* _sound_channel = nullptr;
#endif

            friend AudioSystem;
        };
    }  // namespace Audio
}  // namespace IceSDK
