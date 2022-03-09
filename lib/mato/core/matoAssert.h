#ifndef MATO_ASSERT_H
#define MATO_ASSERT_H
#include "types.h"

#include <stdarg.h>
#include <stdio.h>

#include <OS/OSError.h>
#include <OS/OSFatal.h>

#define ASSERT_BG 0x008CFFFF
#define ASSERT_FG 0xFFFFFF00

#ifndef NDEBUG
    #define MATO_LOG(...) \
        OSReport(__VA_ARGS__);

    #define MATO_ASSERT(exp) \
        if (!(exp)) mato::mato_fail_assert(__FILE__, __LINE__, #exp)

    #define MATO_ASSERT_EX(exp, ...) \
        if (!(exp)) mato::mato_fail_assert_ex(__FILE__, __LINE__, __VA_ARGS__)
#else
    #define MATO_LOG(msg, ...)
    #define MATO_ASSERT(exp, ...)
    #define MATO_ASSERT_EX(exp, ...)
#endif

namespace mato
{
    static void mato_fail_assert(const char *file, int line, const char *msg)
    {
        MATO_LOG("---------- HALT -------------\n");

        char buf[1024];
        sprintf(buf, "Assertion Failed: %s (line %d)\n%s", file, line, msg);

        u32 fg = ASSERT_FG;
        u32 bg = ASSERT_BG;
        OSFatal(&fg, &bg, buf);
    }

    static void mato_fail_assert_ex(const char *file, int line, const char *msg, ...)
    {
        MATO_LOG("---------- HALT -------------\n");

        char msg_buf[512];
        va_list list;
        va_start(msg, list);
        vsnprintf(msg_buf, sizeof(msg_buf), msg, list);
        va_end(list);

        char assert_buf[1024];
        sprintf(assert_buf, "Assertion Failed: %s (line %d)\n%s", file, line, msg_buf);

        u32 fg = ASSERT_FG;
        u32 bg = ASSERT_BG;
        OSFatal(&fg, &bg, assert_buf);
    }
}
#endif