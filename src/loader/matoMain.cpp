#include "matoMain.h"
#include "matoInit.h"

#include <stdio.h>
#include <stdarg.h>
#include <kamekLoader.h>

#include <egg/core/eggExpHeap.h>

#include <RPKernel/RPSysSystem.h>

using namespace EGG;

void * allocAdapter(u32 size, bool isForCode, const loaderFunctions *funcs)
{
    #pragma unused(funcs)

    RPSysSystem *sys = RPSysSystem::getInstance();
    Heap *sysHeap = sys->getConfigData().getSystemHeap();
    Heap *resHeap = sys->getResourceHeap();

    // Code goes in MEM1 while resources go in MEM2
    EGG::Heap *heap = (isForCode) ? sysHeap : resHeap;

    return sys->alloc(heap, size, 32);
}

void freeAdapter(void *buffer, bool isForCode, const loaderFunctions *funcs)
{
    #pragma unused(funcs)

    RPSysSystem *sys = RPSysSystem::getInstance();
    Heap *sysHeap = sys->getConfigData().getSystemHeap();
    Heap *resHeap = sys->getResourceHeap();

    // Code goes in MEM1 while resources go in MEM2
    EGG::Heap *heap = (isForCode) ? sysHeap : resHeap;

    return sys->free(heap, buffer);
}

// Patched stubbed OSReport
#ifndef NDEBUG
void MATOReport(const char *msg, ...)
{
    va_list list;
    va_start(msg, list);
    vprintf(msg, list);
    va_end(list);
}
kmBranch(0x80183f18, MATOReport);
#endif

// Entrypoint is right before main loop begins
void MATOMain()
{
    loadKamekBinaryFromDisc(&functions_us_rev1.base, "/modules/Main.bin");
} kmBranch(0x80183098, MATOMain);
