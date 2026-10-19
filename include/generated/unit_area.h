#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitArea` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitArea unit_area(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitarea
     */
    class UnitArea : public Dimension
    {
    public:
        UnitArea();
        /// @brief Creates a null handle that refers to no native object.
        UnitArea(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitArea(Adopt adopt);
        /**
     * @brief Returns the `acres` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea acres();
        /**
     * @brief Returns the `ares` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea ares();
        /**
     * @brief Returns the `hectares` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea hectares();
        /**
     * @brief Returns the `squareCentimeters` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_centimeters();
        /**
     * @brief Returns the `squareFeet` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_feet();
        /**
     * @brief Returns the `squareInches` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_inches();
        /**
     * @brief Returns the `squareKilometers` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_kilometers();
        /**
     * @brief Returns the `squareMegameters` property of `NSUnitArea`.
     * @details Base unit - squareMeters
     * @return The converted Objective-C result.
     */
        static UnitArea square_megameters();
        /**
     * @brief Returns the `squareMeters` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_meters();
        /**
     * @brief Returns the `squareMicrometers` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_micrometers();
        /**
     * @brief Returns the `squareMiles` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_miles();
        /**
     * @brief Returns the `squareMillimeters` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_millimeters();
        /**
     * @brief Returns the `squareNanometers` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_nanometers();
        /**
     * @brief Returns the `squareYards` property of `NSUnitArea`.
     * @return The converted Objective-C result.
     */
        static UnitArea square_yards();
    };
}
