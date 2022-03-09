#ifndef NW4R_G3D_ANMOBJ_H
#define NW4R_G3D_ANMOBJ_H
#include "types_nw4r.h"
#include "g3d_rescommon.h"
#include "g3d_obj.h"

namespace nw4r
{
    namespace g3d
    {
        typedef f32 (* PlayPolicyFunc)(f32, f32, f32);
        f32 PlayPolicy_Onetime(f32, f32, f32);
        f32 PlayPolicy_Loop(f32, f32, f32);

        struct FrameCtrl
        {
            inline FrameCtrl(f32 f1, f32 f2, PlayPolicyFunc policy)
                : mFrame(0.0f), mRate(1.0f), FLOAT_0x8(f1), FLOAT_0xC(f2) {}
            
            inline f32 GetFrm() const
            {
                return mFrame;
            }

            inline f32 GetRate() const
            {
                return mRate;
            }

            inline void SetFrm(f32 frm)
            {
                f32 newFrm = mPolicy(FLOAT_0x8, FLOAT_0xC, frm);
                mFrame = newFrm;
            }

            inline void SetRate(f32 rate)
            {
                mRate = rate;
            }

            inline void SetPolicy(PlayPolicyFunc func)
            {
                mPolicy = func;    
            }

            inline void UpdateFrm()
            {
                SetFrm(mFrame + mRate * smBaseUpdateRate);
            }

            f32 mFrame; // at 0x0
            f32 mRate; // at 0x4
            f32 FLOAT_0x8;
            f32 FLOAT_0xC;
            PlayPolicyFunc mPolicy; // at 0x10

            static f32 smBaseUpdateRate;
        };

        struct AnmObj : G3dObj
        {
            enum AnmFlag
            {
                ANMFLAG_ISBOUND = 0x4
            };

            inline AnmObj(MEMAllocator *pAllocator, G3dObj *pParent)
                : G3dObj(pAllocator, pParent), mFlags(0) {}

            virtual ~AnmObj();
            
            void SetAnmFlag(AnmFlag, bool);
            bool TestAnmFlag(AnmFlag) const;
            virtual bool IsDerivedFrom(const TypeObj&) const;
            virtual const TypeObj GetTypeObj() const;
            static const TypeObj GetTypeObjStatic();
            virtual const char * GetTypeName() const;

            u32 mFlags; // at 0x0

            NW4R_G3D_TYPE_OBJ_DECL(AnmObj);
        };
    }
}

#endif