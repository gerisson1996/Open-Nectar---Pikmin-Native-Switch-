#include <switch.h>
#include <stdio.h>
#include "pc_frame_scheduler.h"

extern "C" double piki_switch_seconds(void);

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    consoleInit(NULL);

    PadState pad;
    padConfigureInput(1, HidNpadStyleSet_NpadStandard);
    padInitializeDefault(&pad);

    printf("Pikmin Native Switch\\n");
    printf("Open Nectar ARM64/libnx bootstrap\\n\\n");
    PcFrameScheduler scheduler;
    scheduler.reset(piki_switch_seconds(), 1);

    printf("AArch64 target is running.\\n");
    printf("Open Nectar scheduler linked: %.2f Hz.\\n", 1.0 / scheduler.fixedDelta());
    printf("Press + to exit.\\n");

    while (appletMainLoop()) {
        padUpdate(&pad);
        const u64 down = padGetButtonsDown(&pad);
        if (down & HidNpadButton_Plus)
            break;
        consoleUpdate(NULL);
    }

    consoleExit(NULL);
    return 0;
}
