#pragma once

#include <Availability.h>

#if defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED >= 270000
#define COCOON_MACOS_27
#endif
