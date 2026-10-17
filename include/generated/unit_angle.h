#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitAngle` (Foundation).
     * @details A unit of measure for planar angle and rotation. You typically use instances of ''NSUnitAngle'' to represent specific quantities of planar angle using the ''NSMeasurement'' class. \#\#\# Angle Angle is a quantity of rotation. The SI unit for angle is the radian (rad), which is dimensionless and defined to be the angle subtended by an arc that is equal in length to the radius of a circle. Angle is also commonly expressed in terms of degrees (°) and revolutions (rev). The ''NSUnitAngle'' class defines its ''Dimension/baseUnit()'' as ''degrees'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Definition | |---|---|---|---| | Degrees | ''degrees'' | ° | '1.0' | | Arc Minutes | ''arcMinutes'' | ʹ | '0.016667' | | Arc Seconds | ''arcSeconds'' | ʺ | '0.00027778' | | Radians | ''radians'' | rad | '57.2958' | | Gradians | ''gradians'' | grad | '0.9' | | Revolutions | ''revolutions'' | rev | '360' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitAngle unit_angle(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitangle
     */
    class UnitAngle : public Dimension
    {
    public:
        UnitAngle();
        /// @brief Creates a null handle that refers to no native object.
        UnitAngle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitAngle(Adopt adopt);
        /**
     * @brief Returns the `arcMinutes` property of `NSUnitAngle`.
     * @details The arc minutes unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle arc_minutes();
        /**
     * @brief Returns the `arcSeconds` property of `NSUnitAngle`.
     * @details The arc seconds unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle arc_seconds();
        /**
     * @brief Returns the `degrees` property of `NSUnitAngle`.
     * @details The degrees unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle degrees();
        /**
     * @brief Returns the `gradians` property of `NSUnitAngle`.
     * @details The gradians unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle gradians();
        /**
     * @brief Returns the `radians` property of `NSUnitAngle`.
     * @details The radians unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle radians();
        /**
     * @brief Returns the `revolutions` property of `NSUnitAngle`.
     * @details The revolutions unit of angle.
     * @return The converted Objective-C result.
     */
        static UnitAngle revolutions();
    };
}
