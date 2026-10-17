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
     * @details A numeric quantity labeled with a unit of measure, with support for unit conversion and unit-aware calculations. An ''NSMeasurement'' object represents a quantity and unit of measure. The ''NSMeasurement'' class provides a programmatic interface to converting measurements into different units, as well as calculating the sum or difference between two measurements. ''NSMeasurement'' objects are initialized with an ''Unit'' object and 'double' value. ''NSMeasurement'' objects are immutable, and cannot be changed after being created. You can use the ''MeasurementFormatter'' class to create localized string representations of ''NSMeasurement'' objects. > Important: > The Swift overlay to the Foundation framework provides the ''Measurement'' structure, which bridges to the ''NSMeasurement'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Returns a Boolean value that indicates whether this measurement can be converted to the given unit.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_be_converted_to_unit(const Unit& unit) const;
        /**
     * @brief Calls `-[NSMeasurement measurementByAddingMeasurement:]`.
     * @details Returns a new measurement by adding the receiver to the given measurement. - Parameter measurement: The measurement to add. Must be of the same dimensionality as the receiver. - Returns: A new 'NSMeasurement' with the adjusted value and the same unit as the receiver.
     * @param measurement Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_adding_measurement(const MeasurementBase& measurement) const;
        /**
     * @brief Calls `-[NSMeasurement measurementByConvertingToUnit:]`.
     * @details Returns a measurement created by converting the receiver to the specified unit. - Parameter unit: The unit to convert to. Must be of the same dimensionality as the receiver's unit. - Returns: A new 'NSMeasurement' object with the given unit and converted value.
     * @param unit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_converting_to_unit(const Unit& unit) const;
        /**
     * @brief Calls `-[NSMeasurement measurementBySubtractingMeasurement:]`.
     * @details Returns a new measurement by subtracting the given measurement from the receiver. - Parameter measurement: The measurement to subtract. Must be of the same dimensionality as the receiver. - Returns: A new 'NSMeasurement' with the adjusted value and the same unit as the receiver.
     * @param measurement Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        MeasurementBase measurement_by_subtracting_measurement(const MeasurementBase& measurement) const;
        /**
     * @brief Returns the `doubleValue` property of `NSMeasurement`.
     * @details The value component of the measurement.
     * @return The converted Objective-C result.
     */
        double double_value() const;
        /**
     * @brief Returns the `unit` property of `NSMeasurement`.
     * @details The unit component of the measurement.
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
