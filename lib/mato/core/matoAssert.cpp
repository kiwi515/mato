#include "matoAssert.h"

namespace mato
{
    // For overriding EGG's system_halt

    static void mato_fail_assert_valist(const char *file, int line, const char *msg, va_list args)
    {
        MATO_LOG("---------- HALT -------------\n");

        char msg_buf[512];
        vsnprintf(msg_buf, sizeof(msg_buf), msg, args);

        char assert_buf[1024];
        sprintf(assert_buf, "Assertion Failed: %s (line %d)\n%s", file, line, msg_buf);

        u32 fg = ASSERT_FG;
        u32 bg = ASSERT_BG;
        OSFatal(&fg, &bg, assert_buf);
    }

    static void mato_system_halt(char *file, int line, const char *msg, ...)
    {
        va_list list;
        va_start(msg, list);
        mato::mato_fail_assert_valist(file, line, msg, list);
        va_end(list);
    }
    kmBranch(0x800a1f08, &mato_system_halt);
}