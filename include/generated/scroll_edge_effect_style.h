#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScrollEdgeEffectStyle` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrollEdgeEffectStyle scroll_edge_effect_style(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrolledgeeffectstyle
     */
    class ScrollEdgeEffectStyle : public Object
    {
    public:
        ScrollEdgeEffectStyle();
        /// @brief Creates a null handle that refers to no native object.
        ScrollEdgeEffectStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrollEdgeEffectStyle(Adopt adopt);
        /**
         * @brief Returns the `automaticStyle` property of `NSScrollEdgeEffectStyle`.
         * @details The automatic scroll edge effect style.
         * @return The converted Objective-C result.
         */
        static ScrollEdgeEffectStyle automatic_style();
        /**
         * @brief Returns the `hardStyle` property of `NSScrollEdgeEffectStyle`.
         * @details A scroll edge effect with a hard cutoff.
         * @return The converted Objective-C result.
         */
        static ScrollEdgeEffectStyle hard_style();
        /**
         * @brief Returns the `softStyle` property of `NSScrollEdgeEffectStyle`.
         * @details A scroll edge effect with a soft edge.
         * @return The converted Objective-C result.
         */
        static ScrollEdgeEffectStyle soft_style();
    };
}
