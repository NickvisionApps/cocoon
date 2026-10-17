#pragma once

#include <Availability.h>

#if defined(COCOON_SDK_MAJOR)
#if COCOON_SDK_MAJOR >= 27
#define COCOON_MACOS_27
#endif
#elif defined(__MAC_OS_X_VERSION_MAX_ALLOWED) && __MAC_OS_X_VERSION_MAX_ALLOWED >= 270000
#define COCOON_MACOS_27
#endif
