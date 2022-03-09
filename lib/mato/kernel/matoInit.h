#ifndef MATO_KERNEL_INIT_H
#define MATO_KERNEL_INIT_H
#include <types.h>

#ifdef __cplusplus
extern "C"
{
#endif

typedef void(* StaticCtor)(void);
extern StaticCtor __ctor_loc;
extern StaticCtor __ctor_end;

void MATOInit();

#ifdef __cplusplus
}
#endif

#endif