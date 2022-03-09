#include "matoGX.h"

#include <GX/GXLight.h>
#include <GX/GXVert.h>
#include <GX/GXGeometry.h>
#include <GX/GXPixel.h>
#include <GX/GXFrameBuf.h>
#include <GX/GXTransform.h>
#include <GX/GXBump.h>
#include <GX/GXAttr.h>
#include <math/mtx44.h>

#include <nw4r/math/math_types.h>

#include <egg/core/eggSystem.h>
#include <egg/core/eggVideo.h>

namespace mato
{
    void MatoGX::DrawColor(nw4r::ut::Color color)
    {        
        GXSetChanMatColor(GX_CHANNEL_ID_4, color);

        if (color.mChannels.a == 255)
        {
            GXSetBlendMode(0, 1, 0, 15);
        }
        else
        {
            GXSetBlendMode(1, 4, 5, 15);
        }
    }

    void MatoGX::DrawBox(f32 x1, f32 y1, f32 x2, f32 y2)
    {
        DrawBoxSetting(x1, y1, x2, y2);
        
        GXBegin(0x80, 0, 4);
            GXPosition3f32(x1, y1, 0.0f);
            GXPosition3f32(x2, y1, 0.0f);
            GXPosition3f32(x2, y2, 0.0f);
            GXPosition3f32(x1, y2, 0.0f);
        GXEnd();
    }

    void MatoGX::DrawBoxSetting(f32 x1, f32 y1, f32 x2, f32 y2)
    {
        nw4r::math::MTX44 mtx;
        C_MTXOrtho(mtx, y1, y2, x1, x2, 0.0f, 1.0f);
        
        GXSetProjection(mtx, 1);
        
        GXSetViewport(x1, y1, (x2 - x1), (y2 - y1), 0.0f, 1.0f);
        GXSetScissor(x1, y1, (x2 - x1), (y2 - y1));
        
        nw4r::math::MTX34 mtx34;
        PSMTXIdentity(mtx34);
        GXLoadPosMtxImm(mtx34, 0);
        GXSetCurrentMtx(0);

        GXClearVtxDesc();
        GXInvalidateVtxCache();
        GXSetVtxDesc(GX_ATTR_VTX, 1);
        GXSetVtxDesc(GX_ATTR_VTX_CLR, 0);
        GXSetVtxDesc(GX_ATTR_VTX_TEX_COORD, 0);
        GXSetVtxAttrFmt(0, GX_ATTR_VTX, 1, 4, 0);

        GXSetNumChans(1);
        GXSetChanCtrl(GX_CHANNEL_ID_4, 0, 0, 0, 0, 0, 2);

        GXSetNumTexGens(0);
        GXSetNumIndStages(0);
        __GXSetIndirectMask(0);

        GXSetNumTevStages(1);
        GXSetTevOp(GX_TEV_STAGE_ID_0, 4);
        GXSetTevOrder(GX_TEV_STAGE_ID_0, GX_TEX_COORD_ID_INVALID, GX_TEX_MAP_ID_INVALID, 4);

        GXSetColorUpdate(1);
        GXSetAlphaUpdate(1);

        GXSetZMode(0, 0, 0);
        GXSetCullMode(2);
    }
}