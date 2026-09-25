#include <switch.h>
#include <stdint.h>
#include "piki_switch_platform.h"

extern "C" uint64_t piki_switch_ticks(void)
{
    return armGetSystemTick();
}

extern "C" double piki_switch_seconds(void)
{
    return armTicksToNs(armGetSystemTick()) / 1000000000.0;
}

extern "C" void piki_switch_sleep_ns(uint64_t ns)
{
    svcSleepThread((int64_t)ns);
}
