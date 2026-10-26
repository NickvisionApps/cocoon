#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/inflection_rule.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Morphology;

    /**
     * @brief C++ handle for the Objective-C class `NSInflectionRuleExplicit` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref InflectionRule.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::InflectionRuleExplicit inflection_rule_explicit{cocoon::Morphology()};
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsinflectionruleexplicit
     */
    class InflectionRuleExplicit : public InflectionRule
    {
    public:
        /// @brief Creates a new `NSInflectionRuleExplicit` instance and returns a handle to it.
        explicit InflectionRuleExplicit(const Morphology& morphology);
        InflectionRuleExplicit();
        /// @brief Creates a null handle that refers to no native object.
        InflectionRuleExplicit(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit InflectionRuleExplicit(Adopt adopt);
        /**
         * @brief Returns the `morphology` property of `NSInflectionRuleExplicit`.
         * @return The converted Objective-C result.
         */
        Morphology morphology() const;
    };
}
