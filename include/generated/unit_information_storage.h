#pragma once

#include "generated/availability.h"
#include "generated/dimension.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnitInformationStorage` (Foundation).
     * @details A dimension for representing amounts of digital information. Base Unit: Byte The values of the below follow IEC 80000-13 definitions and conventions.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Dimension.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UnitInformationStorage unit_information_storage(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunitinformationstorage
     */
    class UnitInformationStorage : public Dimension
    {
    public:
        UnitInformationStorage();
        /// @brief Creates a null handle that refers to no native object.
        UnitInformationStorage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UnitInformationStorage(Adopt adopt);
        /**
         * @brief Returns the `bits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage bits();
        /**
         * @brief Returns the `bytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage bytes();
        /**
         * @brief Returns the `exabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exabits();
        /**
         * @brief Returns the `exabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exabytes();
        /**
         * @brief Returns the `exbibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exbibits();
        /**
         * @brief Returns the `exbibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exbibytes();
        /**
         * @brief Returns the `gibibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gibibits();
        /**
         * @brief Returns the `gibibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gibibytes();
        /**
         * @brief Returns the `gigabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gigabits();
        /**
         * @brief Returns the `gigabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gigabytes();
        /**
         * @brief Returns the `kibibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kibibits();
        /**
         * @brief Returns the `kibibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kibibytes();
        /**
         * @brief Returns the `kilobits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kilobits();
        /**
         * @brief Returns the `kilobytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kilobytes();
        /**
         * @brief Returns the `mebibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage mebibits();
        /**
         * @brief Returns the `mebibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage mebibytes();
        /**
         * @brief Returns the `megabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage megabits();
        /**
         * @brief Returns the `megabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage megabytes();
        /**
         * @brief Returns the `nibbles` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage nibbles();
        /**
         * @brief Returns the `pebibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage pebibits();
        /**
         * @brief Returns the `pebibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage pebibytes();
        /**
         * @brief Returns the `petabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage petabits();
        /**
         * @brief Returns the `petabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage petabytes();
        /**
         * @brief Returns the `tebibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage tebibits();
        /**
         * @brief Returns the `tebibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage tebibytes();
        /**
         * @brief Returns the `terabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage terabits();
        /**
         * @brief Returns the `terabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage terabytes();
        /**
         * @brief Returns the `yobibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yobibits();
        /**
         * @brief Returns the `yobibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yobibytes();
        /**
         * @brief Returns the `yottabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yottabits();
        /**
         * @brief Returns the `yottabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yottabytes();
        /**
         * @brief Returns the `zebibits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zebibits();
        /**
         * @brief Returns the `zebibytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zebibytes();
        /**
         * @brief Returns the `zettabits` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zettabits();
        /**
         * @brief Returns the `zettabytes` property of `NSUnitInformationStorage`.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zettabytes();
    };
}
