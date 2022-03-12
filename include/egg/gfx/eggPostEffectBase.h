#ifndef EGG_GFX_POST_EFFECT_BASE_H
#define EGG_GFX_POST_EFFECT_BASE_H
#include "types_egg.h"
#include <RevoSDK/GX/GX.h>

namespace EGG
{
    class PostEffectBase
    {
    public:
        enum PostEffectFlags
        {
            POSTEFFECT_HIDDEN = 0x1
        };

    protected:
        u16 mFlags; // at 0x0
        u32 mBlendMode; // at 0x4
        CapTexture *mpCapTexture; // at 0x8
        f32 mOffsetX; // at 0xC
        f32 mOffsetY; // at 0x10
        f32 mScaleX; // at 0x14
        f32 mScaleY; // at 0x18

    public:
        PostEffectBase();
        virtual ~PostEffectBase(); // at 0x8
        virtual void onReset(); // at 0xC
        virtual void draw(f32, f32); // at 0x10
        virtual void reset(); // at 0x14
        virtual void preDraw(); // at 0x18
        virtual void drawDL(f32, f32, f32, f32); // at 0x1C
        virtual void loadTexObj(); // at 0x20

        bool isVisible() const { return ((mFlags & POSTEFFECT_HIDDEN) == 0); }
        CapTexture * getCapTexture() const { return mpCapTexture; }

        void drawTexture();
        void setGXVtxState();
        void setGXChanState();
        void setGXIndStages();
        void setGXFog();
        void setGXBlendMode();

        static void scaleColor(GXColor&, const GXColor&, f32, bool);
        static void setProjectionGX(const eggScreen&);
    };
}

#endif