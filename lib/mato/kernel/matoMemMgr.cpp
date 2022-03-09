#include "matoMemMgr.h"

#include <RPKernel/RPSysConfigData.h>
#include <RPKernel/RPSysSystem.h>

#define MATO_HEAP_SIZE (64 * 1024) // 64k

namespace mato
{
    using namespace EGG;

    void MemManager::Initialize()
    {
        sGameHeap = ExpHeap::create(MATO_HEAP_SIZE, RPSysSystem::getConfigData().getSystemHeap(), 0);
 
        MATO_ASSERT_EX(sGameHeap != NULL, "Main game heap creation failed!!!\n");
        MATO_LOG("Game heap location: %08X\n", sGameHeap);
    }

    ExpHeap *MemManager::sGameHeap;
}