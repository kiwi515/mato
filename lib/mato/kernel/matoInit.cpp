#include "matoInit.h"
#include "matoAssert.h"
#include "matoMemMgr.h"

void MATOInitCPP();

void MATOInit()
{
    mato::MemManager::Initialize();
    MATOInitCPP();
}
kmBranch(0x80183b9c, &MATOInit);

void MATOInitCPP()
{
    MATO_LOG("__ctor_loc=%08X\n", __ctor_loc);
    MATO_LOG("__ctor_end=%08X\n", __ctor_end);
    
    for (StaticCtor *p = &__ctor_loc; p < &__ctor_end; p++)
    {
        (*p)();
    }
}