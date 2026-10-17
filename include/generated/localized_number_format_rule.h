#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSLocalizedNumberFormatRule` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LocalizedNumberFormatRule localized_number_format_rule(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LocalizedNumberFormatRule localized_number_format_rule(nullptr);
     * auto made_0 = cocoon::LocalizedNumberFormatRule::automatic();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslocalizednumberformatrule
     */
    class LocalizedNumberFormatRule : public Object
    {
    public:
        LocalizedNumberFormatRule();
        /// @brief Creates a null handle that refers to no native object.
        LocalizedNumberFormatRule(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LocalizedNumberFormatRule(Adopt adopt);
        /**
     * @brief Calls `+[NSLocalizedNumberFormatRule automatic]`.
     * @return The converted Objective-C result.
     */
        static LocalizedNumberFormatRule automatic();
    };
}
