#ifndef RP_KERNEL_CONFIG_DATA_H
#define RP_KERNEL_CONFIG_DATA_H
#include "types_RP.h"

#include <egg/core/eggSystem.h>

class RPSysConfigData : public EGG::ConfigurationData
{
public:
    virtual EGG::Video * getVideo(); // at 0x8
    virtual EGG::Heap * getSystemHeap(); // at 0xc
    virtual EGG::Display * getDisplay(); // at 0x10
    virtual EGG::XfbManager * getXfbMgr(); // at 0x14
    virtual EGG::PerformanceView * getPerfView(); // at 0x18
    virtual EGG::SceneManager * getSceneMgr(); // at 0x1C
    virtual EGG::IAudioMgr * getAudioMgr(); // at 0x20
};

#endif