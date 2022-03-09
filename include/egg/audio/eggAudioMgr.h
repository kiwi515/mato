#ifndef EGG_AUDIO_AUDIOMGR_H
#define EGG_AUDIO_AUDIOMGR_H
#include "types_egg.h"
#include "eggIAudioMgr.h"
#include "eggAudioHeapMgr.h"
#include "eggAudioArcPlayerMgr.h"

namespace EGG
{
    class SimpleAudioMgr : public IAudioMgr, public SoundHeapMgr, public ArcPlayer
    {
        virtual ~SimpleAudioMgr(); // at 0x80
    };
}

#endif