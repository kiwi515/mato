#ifndef MATO_GFX_GX_H
#define MATO_GFX_GX_H
#include <types.h>

#include <nw4r/ut/ut_Color.h>

namespace mato
{
    class MatoGX
    {
    public:
        static void DrawColor(nw4r::ut::Color);
        static void DrawBox(f32 x1, f32 y1, f32 x2, f32 y2);

    private:
        static void DrawBoxSetting(f32 x1, f32 y1, f32 x2, f32 y2);
    };
}

#endif