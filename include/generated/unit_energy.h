#pragma once

#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitEnergy` (Foundation).
     * @details A unit of measure for energy. You typically use instances of ''NSUnitEnergy'' to represent specific quantities of energy using the ''NSMeasurement'' class. \#\#\# Energy Energy is a fundamental property of matter than can be transferred and converted into different forms, such as kinetic, electric, and thermal. The SI unit for energy is the joule (J), which is derived as the work of one meter of displacement in the direction of a force of one newton (1J = 1N ∙ 1m). It can also be derived as the work required to displace an electric charge of one coulomb through an electrical potential difference of one volt (1J = 1C ∙ 1V), or the work required to produce one watt of power for one second (1J = 1W ∙ 1s). Energy is also commonly expressed in terms of the calorie (cal), or the energy needed to raise the temperature of one gram of water by one degree Celsius at a pressure of one atmosphere (1cal ≡ 4.184J). The ''NSUnitEnergy'' class defines its ''Dimension/baseUnit()'' as ''joules'', and provides the following units, which are initialized using ''UnitConverterLinear'' converters with the specified coefficients: | Name | Method | Symbol | Coefficient | |---|---|---|---| | Kilojoules | ''kilojoules'' | kJ | '1000.0' | | Joules | ''joules'' | J | '1.0' | | Kilocalories | ''kilocalories'' | kCal | '4184.0' | | Calories | ''calories'' | cal | '4.184' | | Kilowatt Hours | ''kilowattHours'' | kWh | '3600000.0' |
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitEnergy unit_energy(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitenergy
     */
    class UnitEnergy : public Dimension
    {
    public:
        UnitEnergy();
        /// @brief Creates a null handle that refers to no native object.
        UnitEnergy(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitEnergy(Adopt adopt);
        /**
     * @brief Returns the `calories` property of `NSUnitEnergy`.
     * @details The calories unit of energy.
     * @return The converted Objective-C result.
     */
        static UnitEnergy calories();
        /**
     * @brief Returns the `joules` property of `NSUnitEnergy`.
     * @details The joules unit of energy.
     * @return The converted Objective-C result.
     */
        static UnitEnergy joules();
        /**
     * @brief Returns the `kilocalories` property of `NSUnitEnergy`.
     * @details The kilocalories unit of energy.
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilocalories();
        /**
     * @brief Returns the `kilojoules` property of `NSUnitEnergy`.
     * @details The kilojoules unit of energy.
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilojoules();
        /**
     * @brief Returns the `kilowattHours` property of `NSUnitEnergy`.
     * @details The kilowatt hours unit of energy.
     * @return The converted Objective-C result.
     */
        static UnitEnergy kilowatt_hours();
    };
}
