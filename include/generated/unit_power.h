#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitPower` (Foundation).
     * @details A unit of measure for power. You typically use instances of ''NSUnitPower'' to represent specific quantities of power using the ''NSMeasurement'' class. \#\#\# Power Power is the amount of energy used over time. The SI unit for power is the watt (W), which is derived as one joule per second (1W = 1J / 1s). The ''NSUnitPower'' class defines its ''Dimension/baseUnit()'' as ''watts'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Terawatts | ''terawatts'' | TW | '1e12' | | Gigawatts | ''gigawatts'' | GW | '1e9' | | Megawatts | ''megawatts'' | MW | '1000000.0' | | Kilowatts | ''kilowatts'' | kW | '1000.0' | | Watts | ''watts'' | W | '1' | | Milliwatts | ''milliwatts'' | mW | '0.001' | | Microwatts | ''microwatts'' | µW | '0.000001' | | Nanowatts | ''nanowatts'' | nW | '1e-9' | | Picowatts | ''picowatts'' | pW | '1e-12' | | Femtowatts | ''femtowatts'' | fW | '1e-15' | | Horsepower | ''horsepower'' | hp | '745.7' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitPower unit_power(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitpower
     */
    class UnitPower : public Dimension
    {
    public:
        UnitPower();
        /// @brief Creates a null handle that refers to no native object.
        UnitPower(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitPower(Adopt adopt);
        /**
     * @brief Returns the `femtowatts` property of `NSUnitPower`.
     * @details The femtowatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower femtowatts();
        /**
     * @brief Returns the `gigawatts` property of `NSUnitPower`.
     * @details The gigawatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower gigawatts();
        /**
     * @brief Returns the `horsepower` property of `NSUnitPower`.
     * @details The horsepower unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower horsepower();
        /**
     * @brief Returns the `kilowatts` property of `NSUnitPower`.
     * @details The kilowatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower kilowatts();
        /**
     * @brief Returns the `megawatts` property of `NSUnitPower`.
     * @details The megawatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower megawatts();
        /**
     * @brief Returns the `microwatts` property of `NSUnitPower`.
     * @details The microwatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower microwatts();
        /**
     * @brief Returns the `milliwatts` property of `NSUnitPower`.
     * @details The milliwatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower milliwatts();
        /**
     * @brief Returns the `nanowatts` property of `NSUnitPower`.
     * @details The nanowatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower nanowatts();
        /**
     * @brief Returns the `picowatts` property of `NSUnitPower`.
     * @details The picowatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower picowatts();
        /**
     * @brief Returns the `terawatts` property of `NSUnitPower`.
     * @details The terawatts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower terawatts();
        /**
     * @brief Returns the `watts` property of `NSUnitPower`.
     * @details The watts unit of power.
     * @return The converted Objective-C result.
     */
        static UnitPower watts();
    };
}
