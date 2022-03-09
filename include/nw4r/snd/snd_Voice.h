#ifndef NW4R_SND_VOICE_H
#define NW4R_SND_VOICE_H
#include "types_nw4r.h"
#include "snd_AxManager.h"
#include "snd_WaveFile.h"
#include "snd_Pan.h"

namespace nw4r
{
	namespace snd
	{
		namespace detail
		{
			struct Voice
			{
				enum VoiceCallbackStatus
				{
					STATUS_0,
					STATUS_1,
					STATUS_2,
					STATUS_3
				};
				
				typedef void (* VoiceCallback)(Voice *, VoiceCallbackStatus, void *);
				
				UNKTYPE Start();
				UNKTYPE Setup(const WaveData &, u32);
				UNKTYPE SetPriority(int);
				UNKTYPE Stop();
				UNKTYPE Free();
				UNKTYPE SetPanMode(PanMode);
				UNKTYPE SetPanCurve(PanCurve);
				UNKTYPE SetVolume(float);
				UNKTYPE SetVeVolume(float, float);
				UNKTYPE SetPitch(float);
				UNKTYPE SetPan(float);
				UNKTYPE SetSurroundPan(float);
				UNKTYPE SetLpfFreq(float);
				UNKTYPE SetRemoteFilter(int);
				UNKTYPE SetOutputLine(int);
				UNKTYPE SetMainOutVolume(float);
				UNKTYPE SetMainSend(float);
				
				UNKTYPE SetFxSend(AuxBus, float);
				
				UNKTYPE SetRemoteOutVolume(int, float);
				UNKTYPE SetRemoteSend(int, float);
				UNKTYPE SetRemoteFxSend(int, float);
				
				UNKTYPE Pause(bool);
			};
		}
	}
}

#endif