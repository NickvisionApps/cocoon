#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitFrequency` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitFrequency unit_frequency(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitfrequency
     */
    class UnitFrequency : public Dimension
    {
    public:
        UnitFrequency();
        /// @brief Creates a null handle that refers to no native object.
        UnitFrequency(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitFrequency(Adopt adopt);
        /**
     * @brief Returns the `framesPerSecond` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency frames_per_second();
        /**
     * @brief Returns the `gigahertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency gigahertz();
        /**
     * @brief Returns the `hertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency hertz();
        /**
     * @brief Returns the `kilohertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency kilohertz();
        /**
     * @brief Returns the `megahertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency megahertz();
        /**
     * @brief Returns the `microhertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency microhertz();
        /**
     * @brief Returns the `millihertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency millihertz();
        /**
     * @brief Returns the `nanohertz` property of `NSUnitFrequency`.
     * @return The converted Objective-C result.
     */
        static UnitFrequency nanohertz();
        /**
     * @brief Returns the `terahertz` property of `NSUnitFrequency`.
     * @details Base unit - hertz
     * @return The converted Objective-C result.
     */
        static UnitFrequency terahertz();
    };
}
