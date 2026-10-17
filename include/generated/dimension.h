#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/unit.h"
#include "types.h"

namespace cocoon
{
    class UnitConverter;

    /**
     * @brief C++ handle for the Objective-C class `NSDimension` (Foundation).
     * @details An abstract class representing a dimensional unit of measure. The Foundation framework provides concrete subclasses for many of the most common types of physical units. Table 1: ''Dimension'' subclasses. | NSDimension subclass | Description | Base unit | |---|---|---| | ''UnitAcceleration'' | Unit of measure for acceleration | meters per second squared (m/s²) | | ''UnitAngle'' | Unit of measure for planar angle and rotation | degrees (°) | | ''UnitArea'' | Unit of measure for area | square meters (m²) | | ''UnitConcentrationMass'' | Unit of measure for concentration of mass | grams per liter (g/L) | | ''UnitDispersion'' | Unit of measure for dispersion | parts per million (ppm) | | ''UnitDuration'' | Unit of measure for duration of time | seconds (sec) | | ''UnitElectricCharge'' | Unit of measure for electric charge | coulombs (C) | | ''UnitElectricCurrent'' | Unit of measure for electric current | amperes (A) | | ''UnitElectricPotentialDifference'' | Unit of measure for electric potential difference | volts (V) | | ''UnitElectricResistance'' | Unit of measure for electric resistance | ohms (Ω) | | ''UnitEnergy'' | Unit of measure for energy | joules (J) | | ''UnitFrequency'' | Unit of measure for frequency | hertz (Hz) | | ''UnitFuelEfficiency'' | Unit of measure for fuel efficiency | liters per 100 kilometers (L/100km) | | ''UnitIlluminance'' | Unit of measure for illuminance | lux (lx) | | ''UnitInformationStorage'' | Unit of measure for quantities of information | bytes (b) | | ''UnitLength'' | Unit of measure for length | meters (m) | | ''UnitMass'' | Unit of measure for mass | kilograms (kg) | | ''UnitPower'' | Unit of measure for power | watts (W) | | ''UnitPressure'' | Unit of measure for pressure | newtons per square meter (N/m²) | | ''UnitSpeed'' | Unit of measure for speed | meters per second (m/s) | | ''UnitTemperature'' | Unit of measure for temperature | kelvin (K) | | ''UnitVolume'' | Unit of measure for volume | liters (L) | Each instance of a ''Dimension'' subclass has a ''converter'', which represents the unit in terms of the dimension's ''baseUnit()''. For example, the 'NSLengthUnit' class uses ''UnitLength/meters'' as its base unit. The system defines the predefined ''UnitLength/miles'' unit by a ''UnitConverterLinear'' with a ''UnitConverterLinear/coefficient'' of '1609.34', which corresponds to the conversion ratio of miles to meters (1 mi = 1609.34 m); the system defines the predefined ''UnitLength/meters'' unit by a ''UnitConverterLinear'' with a ''UnitConverterLinear/coefficient'' of '1.0' because it's the base unit. You typically use an 'NSDimension' subclass in conjunction with the ''NSMeasurement'' class to represent specific quantities of a particular unit. \#\#\# Working with Custom Units In addition to the Apple-provided units, you can define custom units. You can initialize custom units from a symbol and converter of an existing type or implemented as a class method of an existing type for additional convenience. You can also define your own 'NSDimension' subclass to represent an entirely new unit dimension. \#\#\#\# Initializing a Custom Unit with a Specified Symbol and Definition The simplest way to define a custom unit is to create a new instance of an existing 'NSDimension' subclass using the ''init(symbol:converter:)'' method. For example, the smoot is a nonstandard unit of length (1 smoot = 1.70180 m). You can create a new instance of ''UnitLength'' as follows: \@TabNavigator { \@Tab("Swift") { '''swift let smoots = UnitLength(symbol: "smoot", converter: UnitConverterLinear(coefficient: 1.70180)) ''' } \@Tab("Objective-C") { '''objc NSUnitConverter smootsToMeters = [[NSUnitConverterLinear alloc] initWithCoefficient:1.70180]; NSUnitLength smoots = [[NSUnitLength alloc] initWithSymbol:\@"smoot" converter:smootsToMeters]; ''' } } \#\#\#\# Extending Existing Dimension Subclasses Alternatively, if you use a custom unit extensively throughout an app, consider extending the corresponding ''Dimension'' subclass and adding a static variable. For example, a measurement of speed can be furlongs per fortnight (1 fur/ftn = 201.168 m / 1,209,600 s). If an app makes frequent use of this unit, you can extend ''UnitSpeed'' to add a 'furlongsPerFortnight' static variable for convenient access as follows: \@TabNavigator { \@Tab("Swift") { '''swift extension UnitSpeed { static let furlongPerFortnight = UnitSpeed(symbol: "fur/ftn", converter: UnitConverterLinear(coefficient: 201.168 / 1209600.0)) } ''' } \@Tab("Objective-C") { '''objc \@interface NSUnitSpeed () + (NSUnitSpeed )furlongsPerFortnight; \@end \@implementation NSUnitSpeed () + (NSUnitSpeed )furlongsPerFortnight { NSUnitConverter furlongsPerFortnightToMetersPerSecond = [[NSUnitConverterLinear alloc] initWithCoefficient:201.168 / 1209600.0]; return [[NSUnitSpeed alloc] initWithSymbol:\@"fur/ftn" converter:furlongsPerFortnightToMetersPerSecond]; } \@end ''' } } \#\#\#\# Creating a Custom Dimension Subclass You can create a new subclass of ''Dimension'' to describe a new unit dimension. For example, the Foundation framework doesn't define any units for radioactivity. Radioactivity is the process by which the nucleus of an atom emits radiation. The SI unit of measure for radioactivity is the becquerel (Bq), which is the quantity of radioactive material in which one nucleus decays per second (1 Bq = 1 s-1). Radioactivity is also commonly described in terms of curies (Ci), a unit defined relative to the decay of one gram of the radium-226 isotope (1 Ci = 3.7 × 1010 Bq). You can implement a 'CustomUnitRadioactivity' class that defines both units of radioactivity as follows: \@TabNavigator { \@Tab("Swift") { '''swift class CustomRadioactivityUnit: Dimension { static let becquerel = CustomRadioactivityUnit(symbol: "Bq", UnitConverterLinear(coefficient: 1.0)) static let curie = CustomRadioactivityUnit(symbol: "Ci", UnitConverterLinear(coefficient: 3.7e10)) static let baseUnit = self.becquerel } ''' } \@Tab("Objective-C") { '''objc \@interface CustomUnitRadioactivity: NSDimension + (CustomUnitRadioactivity )becquerels; + (CustomUnitRadioactivity )curies; \@end \@implementation CustomRadioactivityUnit + (CustomUnitRadioactivity )becquerels { NSUnitConverter baseUnitConverter = [[NSUnitConverterLinear alloc] initWithCoefficient:1]; return [[CustomUnitRadioactivity alloc] initWithSymbol:\@"Bq" converter:baseUnitConverter]; } + (CustomUnitRadioactivity )curies { NSUnitConverter curiesToBecquerels = [[NSUnitConverterLinear alloc] initWithCoefficient:3.7e10]; return [[CustomUnitRadioactivity alloc] initWithSymbol:\@"Ci" converter:curiesToBecquerels]; } + (instancetype)baseUnit { return [self bacquerels]; } \@end ''' } } \#\#\# Subclassing Notes The system provides ''Dimension'' for subclassing. Although the subclasses listed in Table 1 above are suitable for most purposes, you may want to define a custom unit type. For instance, you may need a custom unit type to represent a derived unit, such as magnetic flux (measured as the product of electric potential difference and time). To represent dimensionless units, subclass ''Unit'' directly. \#\#\#\# Methods to Override All subclasses must fully implement the ''baseUnit()'' method designating the base unit, relative to which you define any additional units. You must also implement a class method named for the base unit itself, to use interchangeably. For example, the ''UnitIlluminance'' class defines its ''baseUnit()'' in terms of the lux (lx) and provides a corresponding ''UnitIlluminance/lux'' class method. \#\#\#\# Alternatives to Subclassing As described in \<doc:\#Working-with-Custom-Units>, you need to create a custom subclass of ''Dimension'' only if you or the system haven't defined a unit of the desired dimension. You can define a custom unit for an existing ''Dimension'' subclass by either calling the ''init(symbol:converter:)'' method or extending the subclass and adding a corresponding class method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Unit.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Dimension dimension{"text", cocoon::UnitConverter()};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Dimension dimension{"text", cocoon::UnitConverter()};
     * auto made_0 = cocoon::Dimension::base_unit();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdimension
     */
    class Dimension : public Unit
    {
    public:
        /// @brief Creates a new `NSDimension` instance and returns a handle to it.
        explicit Dimension(const std::string& symbol, const UnitConverter& converter);
        Dimension();
        /// @brief Creates a null handle that refers to no native object.
        Dimension(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Dimension(Adopt adopt);
        /**
     * @brief Calls `+[NSDimension baseUnit]`.
     * @details Returns the base unit of the dimension. The default implementation returns 'nil' to indicate that the 'NSDimension' class should not be used directly. When implementing a subclass, you should return a unit converter that returns the inputted value for both the 'baseUnitValueFromValue:' and 'valueFromBaseUnitValue:' methods. You can create a unit converter for a base unit using the 'NSUnitConverterLinear' 'initWithCoefficient:' initializer, passing '1' as the coefficient.
     * @return The converted Objective-C result.
     */
        static Dimension base_unit();
        /**
     * @brief Returns the `converter` property of `NSDimension`.
     * @details The unit converter that describes how this unit converts to and from the base unit of its dimension.
     * @return The converted Objective-C result.
     */
        UnitConverter converter() const;
    };
}
