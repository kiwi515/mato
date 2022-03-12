#include "matoRenderer.h"
#include "matoDebug.h"

#include <RPSystem/RPSysScene.h>
#include <RPGraphics/RPGrpRenderer.h>

namespace mato
{
    // Reimplement the stubbed out DebugDraw functionality
    void Renderer::DrawScene(RPGrpRenderer *renderer)
    {
        RPGrpRenderer::SetDrawPass(4);

        MATO_ASSERT(renderer != NULL);
        IRPGrpDrawObject *iter = renderer->GetDrawObjectList();

        for (; iter != NULL; iter = iter->GetNext())
        {
            iter->UserDraw();

            #ifndef NDEBUG
            iter->DebugDraw();
            #endif
        }
    }
    kmBranch(0x801af6c0, Renderer::DrawScene);
}