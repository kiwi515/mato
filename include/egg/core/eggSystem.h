#ifndef EGG_CORE_SYSTEM_H
#define EGG_CORE_SYSTEM_H
#include "eggHeap.h"

namespace EGG
{
	struct ConfigurationData
	{
		virtual Video * getVideo() = 0; // at 0x8
		virtual Heap * getSystemHeap() = 0; // at 0xc
		virtual Display * getDisplay() = 0; // at 0x10
		virtual XfbManager * getXfbMgr() = 0; // at 0x14
		virtual PerformanceView * getPerfView() = 0; // at 0x18
		virtual SceneManager * getSceneMgr() = 0; // at 0x1C
		virtual IAudioMgr * getAudioMgr() = 0; // at 0x20
		virtual void onBeginFrame(); // at 0x24
		virtual void onEndFrame(); // at 0x28
		virtual void initMemory(); // at 0x2C
		virtual void run(); // at 0x30
		
		void *mMEM1ArenaLo; // at 0x4
		void *mMEM1ArenaHi; // at 0x8
		void *mMEM2ArenaLo; // at 0xC
		void *mMEM2ArenaHi; // at 0x10
		u32 mArenaSize; // at 0x14
		Heap *mRootHeapMem1; // at 0x18
		Heap *mRootHeapMem2; // at 0x1c
		Heap *mRootHeapDebug; // at 0x20
		Heap *mSystemHeap; // at 0x24
		char UNK_0x28[0x38 - 0x28];
		Video *mVideo; // at 0x38
		XfbManager *mXfbMgr; // at 0x3C
		Display *mDisplay; // at 0x40
		PerformanceView *mPerfView; // at 0x44
		SceneManager *mSceneMgr; // at 0x48
		IAudioMgr *mAudioMgr; // at 0x4C
	};
	
	struct BaseSystem
	{
		static ConfigurationData * mConfigData;
		
		static inline Heap * getRootHeapMem1()
		{
			return mConfigData->mRootHeapMem1;
		}
		
		static inline Heap * getRootHeapMem2()
		{
			return mConfigData->mRootHeapMem2;
		}
		
		static inline Heap * getRootHeapDebug()
		{
			return mConfigData->mRootHeapDebug;
		}
		
		static inline Video * getVideo()
		{
			return mConfigData->getVideo();
		}
		
		static inline Display * getDisplay()
		{
			return mConfigData->getDisplay();
		}

		static inline XfbManager * getXfbManager()
		{
			return mConfigData->getXfbMgr();
		}
	};
}

#endif