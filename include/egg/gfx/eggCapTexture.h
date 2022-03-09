#ifndef EGG_GFX_CAP_TEXTURE_H
#define EGG_GFX_CAP_TEXTURE_H
#include "types_egg.h"
#include "eggCpuTexture.h"
#include <GX/GXTexture.h>

namespace EGG
{
    class CapTexture : public CpuTexture
    {
    public:
        CapTexture() {}

        virtual ~CapTexture() {} // at 0x8
        virtual void configure(); // at 0xC
        virtual void loadTexObj(GXTexMapID); // at 0x14

        void setColor(const GXColor& c)
        {
            COLOR_0x1C = c; 
        }

    private:
        GXTexMapID mTexMapID; // at 0x18
        GXColor COLOR_0x1C;
        UNKWORD WORD_0x20;
        u8 BYTES_0x24[0x2A - 0x24];
    };
}

#endif