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
     * @details A unit of measure for frequency. You typically use instances of ''NSUnitFrequency'' to represent specific quantities of frequency using the ''NSMeasurement'' class. \#\#\# Frequency Frequency is a quantity of occurrences for a repeating event over time. The SI unit for frequency is the hertz (Hz), which is a derived as one occurrence per second ('1 Hz = 1 / 1s'). The ''UnitFrequency'' class defines its ''Dimension/baseUnit()'' as ''hertz'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Terahertz | ''terahertz'' | THz | '1e12' | | Gigahertz | ''gigahertz'' | GHz | '1e9' | | Megahertz | ''megahertz'' | MHz | '1000000.0' | | Kilohertz | ''kilohertz'' | kHz | '1000.0' | | Hertz | ''hertz'' | Hz | '1' | | Millihertz | ''millihertz'' | mHz | '0.001' | | Microhertz | ''microhertz'' | µHz | '0.000001' | | Nanohertz | ''nanohertz'' | nHz | '1e-9' |
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
         * @details The gigahertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency gigahertz();
        /**
         * @brief Returns the `hertz` property of `NSUnitFrequency`.
         * @details The hertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency hertz();
        /**
         * @brief Returns the `kilohertz` property of `NSUnitFrequency`.
         * @details The kilohertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency kilohertz();
        /**
         * @brief Returns the `megahertz` property of `NSUnitFrequency`.
         * @details The megahertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency megahertz();
        /**
         * @brief Returns the `microhertz` property of `NSUnitFrequency`.
         * @details The microhertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency microhertz();
        /**
         * @brief Returns the `millihertz` property of `NSUnitFrequency`.
         * @details The millihertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency millihertz();
        /**
         * @brief Returns the `nanohertz` property of `NSUnitFrequency`.
         * @details The nanohertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency nanohertz();
        /**
         * @brief Returns the `terahertz` property of `NSUnitFrequency`.
         * @details The terahertz unit of frequency.
         * @return The converted Objective-C result.
         */
        static UnitFrequency terahertz();
    };
}
