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
     * @return The converted Objective-C result.
     */
        static UnitAngle arc_minutes();
        /**
     * @brief Returns the `arcSeconds` property of `NSUnitAngle`.
     * @return The converted Objective-C result.
     */
        static UnitAngle arc_seconds();
        /**
     * @brief Returns the `degrees` property of `NSUnitAngle`.
     * @details Base unit - degrees
     * @return The converted Objective-C result.
     */
        static UnitAngle degrees();
        /**
     * @brief Returns the `gradians` property of `NSUnitAngle`.
     * @return The converted Objective-C result.
     */
        static UnitAngle gradians();
        /**
     * @brief Returns the `radians` property of `NSUnitAngle`.
     * @return The converted Objective-C result.
     */
        static UnitAngle radians();
        /**
     * @brief Returns the `revolutions` property of `NSUnitAngle`.
     * @return The converted Objective-C result.
     */
        static UnitAngle revolutions();
    };
}
