/**
 * @brief Enum for Bowling's sound archive (BRSAR)
 */
enum rp_Bow_sound
{
    /* 0x00 */ SE_TR_Training_Kabeyoke_Replay_WallEffect,
    /* 0x01 */ SE_TR_HitFloor,
    /* 0x02 */ SE_TR_HitFloor_TVSP,
    /* 0x03 */ SE_TR_Release,
    /* 0x04 */ SE_TR_Release_TVSP,
    /* 0x05 */ SE_LV_StandingPositionAdj,
    /* 0x06 */ SE_LV_StandingPositionAdj_TVSP,
    /* 0x07 */ SE_LV_ThrowAngleAdj,
    /* 0x08 */ SE_LV_ThrowAngleAdj_TVSP,
    /* 0x09 */ SE_TR_PushB_forThrow,
    /* 0x0A */ SE_TR_PushB_forThrow_TVSP,
    /* 0x0B */ SE_TR_AdjModeChange,
    /* 0x0C */ SE_TR_AdjModeChange_TVSP,
    /* 0x0D */ SE_TR_CameraYoru,
    /* 0x0E */ SE_TR_CameraYoru_TVSP,
    /* 0x0F */ SE_TR_CameraHiku,
    /* 0x10 */ SE_TR_CameraHiku_TVSP,
    /* 0x11 */ SE_LV_BowlRoll,
    /* 0x12 */ SE_LV_BowlRoll_NPC,
    /* 0x13 */ SE_LV_BowlRollGutter,
    /* 0x14 */ SE_LV_BowlRollGutter_NPC,
    /* 0x15 */ SE_TR_BowlHitPin1,
    /* 0x16 */ SE_TR_BowlHitPin1_NPC,
    /* 0x17 */ SE_TR_BowlHitPin2,
    /* 0x18 */ SE_TR_BowlHitPin2_NPC,
    /* 0x19 */ SE_TR_PinHitPin1,
    /* 0x1A */ SE_TR_PinHitPin1_NPC,
    /* 0x1B */ SE_TR_PinHitFloor1,
    /* 0x1C */ SE_TR_PinHitFloor1_NPC,
    /* 0x1D */ SE_TR_PinHitFloor2,
    /* 0x1E */ SE_TR_BowlHitWallFast,
    /* 0x1F */ SE_TR_BowlHitWallFast_NPC,
    /* 0x20 */ SE_TR_BowlHitWallSlow,
    /* 0x21 */ SE_TR_BowlHitWallSlow_NPC,
    /* 0x22 */ SE_TR_GutterFall,
    /* 0x23 */ SE_TR_bow_walk1,
    /* 0x24 */ SE_TR_bow_walk2,
    /* 0x25 */ SE_TR_bow_walk3,
    /* 0x26 */ SE_TR_bow_walk4,
    /* 0x27 */ SE_TR_CrushGate,
    /* 0x28 */ SE_TR_LaneGapHit,
    /* 0x29 */ SE_TR_KeyError,
    /* 0x2A */ SE_TR_KeyError_TVSP,
    /* 0x2B */ SE_TR_Training_Miss,
    /* 0x2C */ SE_TR_Training_Nagitaoshi_HitWall,
    /* 0x2D */ SE_TR_Training_Nagitaoshi_YamiSwOn,
    /* 0x2E */ SE_TR_PinScoreDisp,
    /* 0x2F */ SE_TR_Kansei_Strike,
    /* 0x30 */ SE_TR_Kansei_spare,
    /* 0x31 */ SE_TR_Kansei_9_X,
    /* 0x32 */ SE_TR_Kansei_X_1,
    /* 0x33 */ SE_TR_Kansei_split,
    /* 0x34 */ SE_TR_Kansei_gutter,
    /* 0x35 */ SE_TR_Kansei_no_spare_any_pin,
    /* 0x36 */ SE_TR_Kansei_no_spare_but_get1over,
    /* 0x37 */ SE_TR_KanseiWaraigoe,
    /* 0x38 */ SE_TR_Kansei_Bikkuri,
    /* 0x39 */ SE_LV_Kansei_Base,
    /* 0x3A */ SE_LV_TrialEnvSE,
    /* 0x3B */ SE_LV_NagitaoshiEnvSE,
    /* 0x3C */ SE_LV_GateChallengeEnvSE,
    /* 0x3D */ SE_LV_Kansei_Base_BackView,
    /* 0x3E */ BGM_Env,
    /* 0x3F */ BGM_GameScoreDisp,
    /* 0x40 */ BGM_TrainingResultDisp,
    /* 0x41 */ BGM_Training_Gatetoshi,
    /* 0x42 */ BGM_Training_Nagitaoshi,
    /* 0x43 */ BGM_Training_Spareget,
    /* 0x44 */ FANFARE_Strike,
    /* 0x45 */ FANFARE_SpareGet,
    /* 0x46 */ FANFARE_Training_SpareGet,
    /* 0x47 */ FANFARE_Training_Nagitaoshi,
    /* 0x48 */ FANFARE_Training_Kabeyoke,
    /* 0x49 */ BGM_Close,
    /* 0x4A */ BGM_CoursePresentationDemo_WS,
    /* 0x4B */ VOICE_TR_NiceThrow,
    /* 0x4C */ VOICE_TR_NiceCover,
    /* 0x4D */ VOICE_TR_GreatShot,
    /* 0x4E */ VOICE_TR_Perfect,
    /* 0x4F */ VOICE_TR_ChallengeCleard,
    /* 0x50 */ VOICE_TR_NiceThrow_NPC,
    /* 0x51 */ VOICE_TR_NiceCover_NPC,
    /* 0x52 */ VOICE_TR_GreatShot_NPC,
    /* 0x53 */ VOICE_TR_NiceThrowTraining,
    /* 0x54 */ VOICE_TR_NiceStrike_MainLaneNPC,
    /* 0x55 */ VOICE_TR_NiceSpare_MainLaneNPC,
    /* 0x56 */ RP_COM_GAME_SE_PAUSE_01_CTSP,
    /* 0x57 */ RP_COM_GAME_SE_PAUSE_01_TVSP,
    /* 0x58 */ RP_COM_GAME_SE_PAUSE_01,
    /* 0x59 */ FANFARE_GameSet,
    /* 0x5A */ FANFARE_GameSet_Win,
    /* 0x5B */ FANFARE_GameSet_Lose,
    /* 0x5C */ FANFARE_GameSet_Tie,
    /* 0x5D */ SE_TR_Common_KeikokuForDebug,
    /* 0x5E */ SE_TR_Common_Sports_Cursol,
    /* 0x5F */ SE_TR_Common_Sports_Decide,
    /* 0x60 */ SE_TR_Common_Sports_Decide_TVSP,
    /* 0x61 */ SE_TR_Common_Sports_DecideBig,
    /* 0x62 */ SE_TR_Common_Sports_DecideBig_TVSP,
    /* 0x63 */ SE_TR_Common_Sports_DemoSkipButton,
    /* 0x64 */ SE_TR_Common_Sports_DemoSkipButton_TVSP,
    /* 0x65 */ SE_TR_Common_Sports_Cancel,
    /* 0x66 */ SE_TR_Common_Sports_Cancel_TVSP,
    /* 0x67 */ SE_TR_Common_Sports_Wipe,
    /* 0x68 */ SE_TR_Common_Jyunban,
    /* 0x69 */ SE_TR_Common_Jyunban_TVSP,
    /* 0x6A */ SE_TR_Common_Medal_Platinum,
    /* 0x6B */ SE_TR_Common_Medal_Gold,
    /* 0x6C */ SE_TR_Common_Medal_Silver,
    /* 0x6D */ SE_TR_Common_Medal_Copper,
    /* 0x6E */ SE_TR_Common_Sports_Game_Start,
    /* 0x6F */ SE_TR_Common_Sports_Game_End,
    /* 0x70 */ SE_TR_Common_Sports_MyBestRecord,
    /* 0x71 */ SE_TR_Common_Sports_KanseiRecord,
    /* 0x72 */ SE_TR_Common_Sports_Training_Good,
    /* 0x73 */ SE_TR_Common_Sports_Training_GoodLong,
    /* 0x74 */ SE_TR_Common_Sports_Training_VeryGoodLong,
    /* 0x75 */ SE_TR_Common_Sports_Training_GoodLongSoft,
    /* 0x76 */ SE_TR_Common_Sports_Training_NotGood,
    /* 0x77 */ RP_COM_GAME_SE_PAUSE_KEY_A_02_CTSP,
    /* 0x78 */ RP_COM_GAME_SE_PAUSE_KEY_A_02_TVSP,
    /* 0x79 */ RP_COM_GAME_SE_PAUSE_KEY_A_02,
    /* 0x7A */ RP_COM_GAME_SE_PAUSE_KEY_A_03_CTSP,
    /* 0x7B */ RP_COM_GAME_SE_PAUSE_KEY_A_03_TVSP,
    /* 0x7C */ RP_COM_GAME_SE_PAUSE_KEY_A_03,
    /* 0x7D */ RP_COM_GAME_SE_PAUSE_Cursor_01,
    /* 0x7E */ SE_LV_Common_click_CTSP,
    /* 0x7F */ SE_LV_Common_click_TVSP,
    /* 0x80 */ SE_TR_Common_ModeChange_CTSP,
    /* 0x81 */ SE_TR_Common_ModeChange_TVSP,
    /* 0x82 */ SE_TR_Common_KeyError_CTSP,
    /* 0x83 */ SE_TR_Common_KeyError_TVSP,
    /* 0x84 */ RP_COMMON_SE_KEY_CURSOR_01,
    /* 0x85 */ RP_COMMON_SE_KEY_BACK_01_CTSP,
    /* 0x86 */ RP_COMMON_SE_KEY_BACK_01_TVSP,
    /* 0x87 */ SE_TR_COMMON_win_OPEN,
    /* 0x88 */ SE_TR_COMMON_win_CLOSE,
    /* 0x89 */ SE_TR_COMMON_Jyukurendo_ScoreFlash,
    /* 0x8A */ SE_TR_COMMON_Jyukurendo_NameFlash,
    /* 0x8B */ SE_TR_COMMON_Jyukurendo_NameSmoke,
    /* 0x8C */ SE_TR_COMMON_Push_AB_CTSP,
    /* 0x8D */ SE_TR_COMMON_Push_AB_TVSP,
    /* 0x8E */ VOICE_TR_Common_BronzeMedal,
    /* 0x8F */ VOICE_TR_Common_SilverMedal,
    /* 0x90 */ VOICE_TR_Common_GoldMedal,
    /* 0x91 */ VOICE_TR_Common_PlatinumMedal,
    /* 0x92 */ VOICE_TR_Common_HighScore,
    /* 0x93 */ STRM_Training_Result01,
    /* 0x94 */ STRM_Training_Result02,
    /* 0x95 */ STRM_Training_Result03,
    /* 0x96 */ Bgm_Tutorial,
    /* 0x97 */ RP_COMMON_SE_MESS_10,
    /* 0x98 */ RP_COMMON_SE_MESS_20,
    /* 0x99 */ RP_COMMON_SE_KEY_A_04_CTSP,
    /* 0x9A */ RP_COMMON_SE_KEY_A_04_TVSP,
    /* 0x9B */ RP_COMMON_SE_KEY_A_04,
    /* 0x9C */ RP_COM_GAME_SE_PAUSE_KEY_A_01_CTSP,
    /* 0x9D */ RP_COM_GAME_SE_PAUSE_KEY_A_01_TVSP,
    /* 0x9E */ RP_COM_GAME_SE_PAUSE_KEY_A_01
};
