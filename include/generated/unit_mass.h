#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitMass` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitMass unit_mass(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitmass
     */
    class UnitMass : public Dimension
    {
    public:
        UnitMass();
        /// @brief Creates a null handle that refers to no native object.
        UnitMass(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitMass(Adopt adopt);
        /**
         * @brief Returns the `carats` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass carats();
        /**
         * @brief Returns the `centigrams` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass centigrams();
        /**
         * @brief Returns the `decigrams` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass decigrams();
        /**
         * @brief Returns the `grams` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass grams();
        /**
         * @brief Returns the `kilograms` property of `NSUnitMass`.
         * @details Base unit - kilograms
         * @return The converted Objective-C result.
         */
        static UnitMass kilograms();
        /**
         * @brief Returns the `metricTons` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass metric_tons();
        /**
         * @brief Returns the `micrograms` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass micrograms();
        /**
         * @brief Returns the `milligrams` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass milligrams();
        /**
         * @brief Returns the `nanograms` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass nanograms();
        /**
         * @brief Returns the `ounces` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass ounces();
        /**
         * @brief Returns the `ouncesTroy` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass ounces_troy();
        /**
         * @brief Returns the `picograms` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass picograms();
        /**
         * @brief Returns the `poundsMass` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass pounds_mass();
        /**
         * @brief Returns the `shortTons` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass short_tons();
        /**
         * @brief Returns the `slugs` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass slugs();
        /**
         * @brief Returns the `stones` property of `NSUnitMass`.
         * @return The converted Objective-C result.
         */
        static UnitMass stones();
    };
}
