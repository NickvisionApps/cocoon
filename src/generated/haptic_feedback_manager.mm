#include "generated/haptic_feedback_manager.h"
#include "internal.h"

namespace cocoon
{
    HapticFeedbackManager::HapticFeedbackManager() : HapticFeedbackManager(Adopt{cocoon::internal::retain([[::NSHapticFeedbackManager alloc] init])})
    {
    }

    HapticFeedbackManager::HapticFeedbackManager(std::nullptr_t) : Object(nullptr)
    {
    }

    HapticFeedbackManager::HapticFeedbackManager(Adopt adopt) : Object(adopt)
    {
    }

    Object HapticFeedbackManager::default_performer()
    {
        return cocoon::internal::wrap<Object>([::NSHapticFeedbackManager defaultPerformer]);
    }
}
