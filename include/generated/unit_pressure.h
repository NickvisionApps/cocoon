#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitPressure` (Foundation).
     * @details A unit of measure for pressure. You typically use instances of ''NSUnitPressure'' to represent specific quantities of pressure using the ''NSMeasurement'' class. \#\#\# Pressure Pressure is the normal force over a surface. The SI unit for pressure is the pascal (Pa), which is derived as one newton of force over one square meter ('1 Pa = 1 N / 1 m'2). The ''UnitPressure'' class defines its ''Dimension/baseUnit()'' as ''newtonsPerMetersSquared'' and provides the following units, which ''UnitConverterLinear'' converters initialize with the given coefficients: | Name | Method | Symbol | Definition | |---|---|---|---| | Newtons Per Meter Squared (Equivalent to Pascals) | ''newtonsPerMetersSquared'' | N/m² | '1.0' | | Gigapascals | ''gigapascals'' | GPa | '1e9' | | Megapascals | ''megapascals'' | MPa | '1000000.0' | | Kilopascals | ''kilopascals'' | kPa | '1000.0' | | Hectopascals | ''hectopascals'' | hPa | '100.0' | | Inches of Mercury | ''inchesOfMercury'' | inHg | '3386.39' | | Bars | ''bars'' | bar | '100000' | | Millibars | ''millibars'' | mbar | '100' | | Millimeters of Mercury | ''millimetersOfMercury'' | mmHg | '133.322' | | Pounds Per Square Inch | ''poundsForcePerSquareInch'' | psi | '6894.76' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitPressure unit_pressure(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitpressure
     */
    class UnitPressure : public Dimension
    {
    public:
        UnitPressure();
        /// @brief Creates a null handle that refers to no native object.
        UnitPressure(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitPressure(Adopt adopt);
        /**
     * @brief Returns the `bars` property of `NSUnitPressure`.
     * @details The bars unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure bars();
        /**
     * @brief Returns the `gigapascals` property of `NSUnitPressure`.
     * @details The gigapascals unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure gigapascals();
        /**
     * @brief Returns the `hectopascals` property of `NSUnitPressure`.
     * @details The hectopascals unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure hectopascals();
        /**
     * @brief Returns the `inchesOfMercury` property of `NSUnitPressure`.
     * @details The inches of mercury unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure inches_of_mercury();
        /**
     * @brief Returns the `kilopascals` property of `NSUnitPressure`.
     * @details The kilopascals unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure kilopascals();
        /**
     * @brief Returns the `megapascals` property of `NSUnitPressure`.
     * @details The megapascals unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure megapascals();
        /**
     * @brief Returns the `millibars` property of `NSUnitPressure`.
     * @details The millibars unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure millibars();
        /**
     * @brief Returns the `millimetersOfMercury` property of `NSUnitPressure`.
     * @details The millimeters of mercury unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure millimeters_of_mercury();
        /**
     * @brief Returns the `newtonsPerMetersSquared` property of `NSUnitPressure`.
     * @details The newtons per meters squared unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure newtons_per_meters_squared();
        /**
     * @brief Returns the `poundsForcePerSquareInch` property of `NSUnitPressure`.
     * @details The pounds per square inch unit of pressure.
     * @return The converted Objective-C result.
     */
        static UnitPressure pounds_force_per_square_inch();
    };
}
