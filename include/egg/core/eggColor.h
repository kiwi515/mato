#ifndef EGG_CORE_COLOR_H
#define EGG_CORE_COLOR_H

namespace EGG
{
    struct Color
    {
        Color() { *(u32 *)&r = 0xFFFFFFFF; }
        Color(int _r, int _g, int _b, int _a) : r(_r), g(_g), b(_b), a(_a) {}

        u8 r, g, b, a;
    };
}

#endif