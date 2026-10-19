#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Unit;

    /**
     * @brief C++ handle for the Objective-C class `NSMeasurement` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref Measurement to supply UnitType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MeasurementBase measurement_base(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MeasurementBase measurement_base(nullptr);
     * measurement_base.can_be_converted_to_unit(cocoon::Unit());
     * measurement_base.measurement_by_converting_to_unit(cocoon::Unit());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmeasurement
     */
    class MeasurementBase : public Object
    {
    public:
        /// @brief Creates a new `NSMeasurement` instance and returns a handle to it.
        explicit MeasurementBase(double double_value, const Object& unit);
        MeasurementBase();
        /// @brief Creates a null handle that refers to no native object.
        MeasurementBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MeasurementBase(Adopt adopt);
        /**
     * @brief Calls `-[NSMeasurement canBeConvertedToUnit:]`.
     * @details Given an NSUnit object, canBeConvertedToUnit: will check for dimensionality i.e. check the unit type (NSUnitAngle, NSUnitLength, NSUnitCustom, etc.) of the NSUnit object. It will return YES if the unit type of the given unit is the same as the unit type of the unit within the NSMeasurement object and NO if not. Note: This method will return NO if given or called on a dimensionless unit.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_be_converted_to_unit(const Unit& unit) const;
        /**
     * @brief Calls `-[NSMeasurement measurementByAddingMeasurement:]`.
     * @details Given an NSMeasurement object, these methods will first check for dimensionality i.e. check the unit type (NSUnitAngle, NSUnitLength, NSUnitCustom, etc.) of the unit contained in that object. If the unit type of the unit in the given NSMeasurement object is not the same as the unit type of the unit within the current NSMeasurement instance (i.e. the units are of differing dimensionalities), these methods will throw an InvalidArgumentException. \@return A new NSMeasurement object with the adjusted value and a unit that is the same type as the current NSMeasurement instance.
     * @param measurement Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_adding_measurement(const MeasurementBase& measurement) const;
        /**
     * @brief Calls `-[NSMeasurement measurementByConvertingToUnit:]`.
     * @details Given an NSUnit object, measurementByConvertingUnit: will first check for dimensionality i.e. check the unit type (NSUnitAngle, NSUnitLength, NSUnitCustom, etc.) of the NSUnit object. If the unit type of the given unit is not the same as the unit type of the unit within the NSMeasurement object (i.e. the units are of differing dimensionalities), measurementByConvertingToUnit: will throw an InvalidArgumentException. \@return A new NSMeasurement object with the given unit and converted value.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_converting_to_unit(const Unit& unit) const;
        /**
     * @brief Calls `-[NSMeasurement measurementBySubtractingMeasurement:]`.
     * @param measurement Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_subtracting_measurement(const MeasurementBase& measurement) const;
        /**
     * @brief Returns the `doubleValue` property of `NSMeasurement`.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `unit` property of `NSMeasurement`.
     * @return The converted Objective-C result.
     */
        Object unit() const;
    };

    template <class UnitType>
    class Measurement : public MeasurementBase
    {
    public:
        using MeasurementBase::MeasurementBase;
        Measurement() : MeasurementBase()
        {
        }
        Measurement(const MeasurementBase& other) : MeasurementBase(other)
        {
        }
        using MeasurementBase::can_be_converted_to_unit;
        using MeasurementBase::double_value;
        using MeasurementBase::measurement_by_adding_measurement;
        using MeasurementBase::measurement_by_converting_to_unit;
        using MeasurementBase::measurement_by_subtracting_measurement;
        using MeasurementBase::unit;
        auto unit() const
        {
            return cocoon::unbox<UnitType>(MeasurementBase::unit());
        }
    };
}
