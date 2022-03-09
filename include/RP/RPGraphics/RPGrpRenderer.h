#ifndef RP_GRAPHICS_RENDERER_H
#define RP_GRAPHICS_RENDERER_H
#include "types_RP.h"

//! TODO
class RPGrpRenderer
{
public:
    static void Begin();
    static void End();

    void AppendDrawObject(IRPGrpDrawObject *);
};

#endif