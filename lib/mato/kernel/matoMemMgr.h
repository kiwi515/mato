#ifndef MATO_KERNEL_MEM_MGR_H
#define MATO_KERNEL_MEM_MGR_H
#include "types.h"
#include "matoAssert.h"
#include "matoDebug.h"

#include <egg/core/eggExpHeap.h>

namespace mato
{
    class MemManager
    {
    public:
        static void Initialize();

        static void * Alloc(u32 size, s32 align)
        {
            MATO_ASSERT(sGameHeap != NULL);
            return sGameHeap->alloc(size, align);
        }

        static void Free(void *block)
        {
            MATO_ASSERT(sGameHeap != NULL);
            MATO_ASSERT(block != NULL);
            sGameHeap->free(block);
        }

        static u32 GetFreeSize()
        {
            MATO_ASSERT(sGameHeap != NULL);
            return sGameHeap->getAllocatableSize(4);
        }

    private:
        static EGG::ExpHeap *sGameHeap;
    };
}

inline void * operator new(size_t size)
{
    return mato::MemManager::Alloc(size, 4);
}

inline void * operator new[](size_t size)
{
    return mato::MemManager::Alloc(size, 4);
}

inline void operator delete(void *block)
{
    mato::MemManager::Free(block);
}

inline void operator delete[](void *block)
{
    mato::MemManager::Free(block);
}

#endif