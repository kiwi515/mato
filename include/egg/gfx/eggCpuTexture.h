#ifndef EGG_GFX_CPU_TEXTURE_H
#define EGG_GFX_CPU_TEXTURE_H
#include "types_egg.h"
#include "eggAssert.h"
#include <GX/GXTexture.h>

namespace EGG
{
    class CpuTexture
    {
    private:
        u16 mFlags; // at 0x0
        u16 mWidth; // at 0x2
        u16 mHeight; // at 0x4
        u8 mTexFormat; // at 0x6
        u8 mWrapS; // at 0x7
        u8 mWrapT; // at 0x8
        u8 mMinFilt; // at 0x9
        u8 mMagFilt; // at 0xA
        char UNK_0xB[0x10 - 0xB];
        void *mpBuffer; // at 0x10

        void makeGradient(UNKTYPE);

    public:
        struct Header
        {
            u8 mTexFormat;
            u8 BYTE_0x1;
            u16 mWidth;
            u16 mHeight;
            u8 BYTE_0x5;
            u8 mWrapS;
            u8 mWrapT;
            u8 BYTE_0x8;
            u16 SHORT_0x9;
            u32 WORD_0xC;
            u8 BYTE_0xD;
            u8 BYTE_0xE;
            u8 BYTE_0xF;
            u8 BYTE_0x10;
            u8 mMinFilt;
            u8 mMagFilt;
            u8 BYTE_0x13;
            u8 BYTE_0x14;
            u8 BYTE_0x15;
            u16 SHORT_0x16;
            u32 WORD_0x18;
        };

        enum TexFlag
        {
            CONFIGURED = 0x1,
            HAS_HEADER
        };

        virtual ~CpuTexture() {} // at 0x8
        virtual void configure(); // at 0xC
        virtual void initTexObj(GXTexObj *) const; // at 0x10
        virtual void loadTexObj(GXTexMapID); // at 0x14

        CpuTexture();
        CpuTexture(u16, u16, GXTexFmt);
        
        void invalidateTexBuffer() const;
        void flushTexBuffer() const;
        u32 getTexBufferSize() const;
        void buildHeader() const;
        Header * initHeader();
        UNKTYPE func_80086A04(UNKTYPE);
        UNKTYPE func_80086C8C(UNKTYPE);
        void allocTexBuffer();
        void allocTexBufferAndHeader();
        UNKTYPE func_8008737C(u16, u16, GXColor);

        bool isConfigured() const { return mFlags & CONFIGURED; }
        bool checkHasHeader() const { return mFlags & HAS_HEADER; }
        // Only 4 official symbols besides configure/getTexBufferSize
        u16 getWidth() const { return mWidth; }
        u16 getHeight() const { return mHeight; }
        GXTexFmt getFormat() const { return (GXTexFmt)mTexFormat; }
        UNKTYPE * getBuffer() const { return mpBuffer; }

        Header * getHeader() const
        {
            return (Header *)((u8 *)mpBuffer - sizeof(Header));
        }

        void setBuffer(void *pBuffer)
        {
            #line 180
            EGG_ASSERT(pBuffer);
            #line 180
            EGG_ASSERT(( u32 )pBuffer % 32 == 0);

            mpBuffer = pBuffer;
            mFlags &= ~HAS_HEADER;
        }
    };
}

#endif