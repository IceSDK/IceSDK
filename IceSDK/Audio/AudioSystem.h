#pragma once

#include "Audio/AudioEnums.h"
#include "Audio/Sound.h"

#include "Utils/Memory.h"

#include <string>
#include <vector>

#ifdef ICESDK_FMOD
extern FMOD::System* g_FMODSystem;
#endif

namespace IceSDK
{
    namespace Audio
    {
        class AudioSystem
        {
        public:
            explicit AudioSystem();

            static void Init();

            Memory::Ptr<Sound> Load(const std::string& pPath);
            Memory::Ptr<Sound> Load(std::vector<uint8_t> pBuffer);

            void CreateGroup(const std::string& pName);

        private:
            std::vector<Memory::Ptr<Sound>> _loaded_audio;
            eAudioEngine _audio_engine = FMOD;

            friend Sound;
        };
    }  // namespace Audio
}  // namespace IceSDK
