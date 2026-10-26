#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSInflectionRule` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InflectionRule inflection_rule(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsinflectionrule
     */
    class InflectionRule : public Object
    {
    public:
        InflectionRule();
        /// @brief Creates a null handle that refers to no native object.
        InflectionRule(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InflectionRule(Adopt adopt);
        /**
         * @brief Calls `+[NSInflectionRule canInflectLanguage:]`.
         * @param language Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool can_inflect_language(const std::string& language);
        /**
         * @brief Returns the `automaticRule` property of `NSInflectionRule`.
         * @return The converted Objective-C result.
         */
        static InflectionRule automatic_rule();
        /**
         * @brief Returns the `canInflectPreferredLocalization` property of `NSInflectionRule`.
         * @return The converted Objective-C result.
         */
        static bool can_inflect_preferred_localization();
    };
}
