#pragma once

// Common compile-time identity for the native Nintendo Switch port.
// Keep desktop/Android platform code behind their existing guards while
// allowing portable Open Nectar code to detect libnx explicitly.
#ifndef PIKI_SWITCH
#define PIKI_SWITCH 1
#endif

#ifndef PIKI_PC_PORT
#define PIKI_PC_PORT 1
#endif

#ifndef DTK_CONFIG_NONMATCHING
#define DTK_CONFIG_NONMATCHING 1
#endif

#ifndef PIKI_USE_DGX
#define PIKI_USE_DGX 0
#endif

#ifndef PIKI_USE_JAUDIO
#define PIKI_USE_JAUDIO 0
#endif
