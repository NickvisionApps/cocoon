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
     * @details A unit of measure for quantities of information. Use instances of ''UnitInformationStorage'' to represent quantities of information using the ''NSMeasurement'' class. The base unit of measure for information is the bit, with a nibble representing four bits and a byte representing eight bits. Larger units of information expand on bits and bytes by orders of magnitude in both decimal and binary forms. \#\#\# Information Transfer Units of bits commonly represent the amount of transferred information. | Decimal Bits | Coefficient | Binary Bits | Coefficient | |---|---|---|---| | ''kilobits'' | '1000' | ''kibibits'' | '1024' | | ''megabits'' | '1000e2' | ''mebibits'' | '1024e2' | | ''gigabits'' | '1000e3' | ''gibibits'' | '1024e3' | | ''terabits'' | '1000e4' | ''tebibits'' | '1024e4' | | ''petabits'' | '1000e5' | ''pebibits'' | '1024e5' | | ''exabits'' | '1000e6' | ''exbibits'' | '1024e6' | | ''zettabits'' | '1000e7' | ''zebibits'' | '1024e7' | | ''yottabits'' | '1000e8' | ''yobibits'' | '1024e8' | \#\#\# Information Storage Units of bytes commonly represent the amount of stored information. | Decimal Bytes | Coefficient | Binary Bytes | Coefficient | |---|---|---|---| | ''kilobytes'' | '1000' | ''kibibytes'' | '1024' | | ''megabytes'' | '1000e2' | ''mebibytes'' | '1024e2' | | ''gigabytes'' | '1000e3' | ''gibibytes'' | '1024e3' | | ''terabytes'' | '1000e4' | ''tebibytes'' | '1024e4' | | ''petabytes'' | '1000e5' | ''pebibytes'' | '1024e5' | | ''exabytes'' | '1000e6' | ''exbibytes'' | '1024e6' | | ''zettabytes'' | '1000e7' | ''zebibytes'' | '1024e7' | | ''yottabytes'' | '1000e8' | ''yobibytes'' | '1024e8' |
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
         * @details The exabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exabits();
        /**
         * @brief Returns the `exabytes` property of `NSUnitInformationStorage`.
         * @details The exabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exabytes();
        /**
         * @brief Returns the `exbibits` property of `NSUnitInformationStorage`.
         * @details The exbibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exbibits();
        /**
         * @brief Returns the `exbibytes` property of `NSUnitInformationStorage`.
         * @details The exbibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage exbibytes();
        /**
         * @brief Returns the `gibibits` property of `NSUnitInformationStorage`.
         * @details The gibibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gibibits();
        /**
         * @brief Returns the `gibibytes` property of `NSUnitInformationStorage`.
         * @details The gibibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gibibytes();
        /**
         * @brief Returns the `gigabits` property of `NSUnitInformationStorage`.
         * @details The gigabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gigabits();
        /**
         * @brief Returns the `gigabytes` property of `NSUnitInformationStorage`.
         * @details The gigabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage gigabytes();
        /**
         * @brief Returns the `kibibits` property of `NSUnitInformationStorage`.
         * @details The kibibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kibibits();
        /**
         * @brief Returns the `kibibytes` property of `NSUnitInformationStorage`.
         * @details The kibibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kibibytes();
        /**
         * @brief Returns the `kilobits` property of `NSUnitInformationStorage`.
         * @details The kilobits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kilobits();
        /**
         * @brief Returns the `kilobytes` property of `NSUnitInformationStorage`.
         * @details The kilobytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage kilobytes();
        /**
         * @brief Returns the `mebibits` property of `NSUnitInformationStorage`.
         * @details The mebibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage mebibits();
        /**
         * @brief Returns the `mebibytes` property of `NSUnitInformationStorage`.
         * @details The mebibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage mebibytes();
        /**
         * @brief Returns the `megabits` property of `NSUnitInformationStorage`.
         * @details The megabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage megabits();
        /**
         * @brief Returns the `megabytes` property of `NSUnitInformationStorage`.
         * @details The megabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage megabytes();
        /**
         * @brief Returns the `nibbles` property of `NSUnitInformationStorage`.
         * @details The nibbles unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage nibbles();
        /**
         * @brief Returns the `pebibits` property of `NSUnitInformationStorage`.
         * @details The pebibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage pebibits();
        /**
         * @brief Returns the `pebibytes` property of `NSUnitInformationStorage`.
         * @details The pebibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage pebibytes();
        /**
         * @brief Returns the `petabits` property of `NSUnitInformationStorage`.
         * @details The petabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage petabits();
        /**
         * @brief Returns the `petabytes` property of `NSUnitInformationStorage`.
         * @details The petabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage petabytes();
        /**
         * @brief Returns the `tebibits` property of `NSUnitInformationStorage`.
         * @details The tebibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage tebibits();
        /**
         * @brief Returns the `tebibytes` property of `NSUnitInformationStorage`.
         * @details The tebibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage tebibytes();
        /**
         * @brief Returns the `terabits` property of `NSUnitInformationStorage`.
         * @details The terabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage terabits();
        /**
         * @brief Returns the `terabytes` property of `NSUnitInformationStorage`.
         * @details The terabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage terabytes();
        /**
         * @brief Returns the `yobibits` property of `NSUnitInformationStorage`.
         * @details The yobibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yobibits();
        /**
         * @brief Returns the `yobibytes` property of `NSUnitInformationStorage`.
         * @details The yobibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yobibytes();
        /**
         * @brief Returns the `yottabits` property of `NSUnitInformationStorage`.
         * @details The yottabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yottabits();
        /**
         * @brief Returns the `yottabytes` property of `NSUnitInformationStorage`.
         * @details The yottabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage yottabytes();
        /**
         * @brief Returns the `zebibits` property of `NSUnitInformationStorage`.
         * @details The zebibits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zebibits();
        /**
         * @brief Returns the `zebibytes` property of `NSUnitInformationStorage`.
         * @details The zebibytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zebibytes();
        /**
         * @brief Returns the `zettabits` property of `NSUnitInformationStorage`.
         * @details The zettabits unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zettabits();
        /**
         * @brief Returns the `zettabytes` property of `NSUnitInformationStorage`.
         * @details The zettabytes unit of information storage.
         * @return The converted Objective-C result.
         */
        static UnitInformationStorage zettabytes();
    };
}
