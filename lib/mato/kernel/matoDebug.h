#ifndef MATO_KERNEL_DEBUG_H
#define MATO_KERNEL_DEBUG_H
#include "types.h"

// Uses a stubbed-out function that is never called (RPSysGameConfigIntNode::read)
// Set a Dolphin breakpoint for this address
typedef void (* Func)();
const Func BREAK = ((Func)0x801867f8);

#ifndef NDEBUG

#define MATO_BREAKPOINT() do { \
    MATO_LOG("BREAKPOINT! %s, in %s (line %d)\n", __FILE__, __FUNCTION__, __LINE__); \
    (*BREAK)(); \
} while(0)

#define MATO_BREAKPOINT_COND(cond) do { \
    if ((cond)) MATO_BREAKPOINT(); \
} while (0)

#else
#define MATO_BREAKPOINT
#endif

#endif