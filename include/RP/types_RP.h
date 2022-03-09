#ifndef TYPES_RP_H
#define TYPES_RP_H
#include <types.h>

//! Provides year, month, month day
typedef u16 RPTime16;
//! Provides year, month, month day, week day, hour
typedef u32 RPTime32;

struct RPSysUnknownBase;

// RPGraphics
struct IRPGrpDrawObject;
struct RPGrpRenderer;
struct RPGrpFogManager;

// RPKernel
struct RPSysSystem;
struct RPSysConfigData;
struct RPSysFile;
struct IRPSysHostIOSocket;
struct RPSysTextWriter;
struct RPSysMessage;
struct RPSysWideTextWriter;
struct RPSysLytAllocator;

// RPSystem
struct RPSysSceneCreator;
struct RPSysScene;
struct RPSysSceneMgr;
struct RPSysProjectLocal;
struct RPSysGameConfig;
struct RPSysTagParameters;
struct RPSysTagParm;
template <typename T> struct RPSysPrimTagParm;
struct RPSysStringTagParm;
struct RPSysResourceManager;
struct RPSysQueuedScene;
struct RPSysCommonObject;
struct RPSysDvdStatus;
struct RPSysSaveDataMgr;
struct RPSysFontManager;
struct RPSysSaveData;

// RPSports
struct RPSportsCommonData;
struct RPSportsPlayerData;
struct RPSportsBaseScene;
struct RPBoxBoxer;
struct RPBoxBoxerEnergy;
struct RPBoxBoxerCombo;
struct RPBowResourceManager;
struct RPGolConfig;

// RPParty
struct RPPartyCommonData;
struct RPPartyPlayerData;

#endif