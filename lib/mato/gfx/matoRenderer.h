#ifndef MATO_GFX_RENDERER_H
#define MATO_GFX_RENDERER_H
#include "types_mato.h"

#include <types_rp.h>

namespace mato
{
    class Renderer
    {
    public:
        static void DrawScene(RPGrpRenderer *);
    };
}

#endif