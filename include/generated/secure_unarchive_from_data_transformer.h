#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/value_transformer.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSecureUnarchiveFromDataTransformer` (Foundation).
     * @details A value transformer which transforms values to and from \\c NSData by archiving and unarchiving using secure coding.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ValueTransformer.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SecureUnarchiveFromDataTransformer secure_unarchive_from_data_transformer;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssecureunarchivefromdatatransformer
     */
    class SecureUnarchiveFromDataTransformer : public ValueTransformer
    {
    public:
        /// @brief Creates a new `NSSecureUnarchiveFromDataTransformer` instance and returns a handle to it.
        explicit SecureUnarchiveFromDataTransformer();
        /// @brief Creates a null handle that refers to no native object.
        SecureUnarchiveFromDataTransformer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SecureUnarchiveFromDataTransformer(Adopt adopt);
        /**
     * @brief Returns the `allowedTopLevelClasses` property of `NSSecureUnarchiveFromDataTransformer`.
     * @details The list of allowable classes which the top-level object in the archive must conform to on encoding and decoding. Returns the result of \\c +transformedValueClass if not \\c Nil; otherwise, currently returns \\c NSArray, \\c NSDictionary, \\c NSSet, \\c NSString, \\c NSNumber, \\c NSDate, \\c NSData, \\c NSURL, \\c NSUUID, and \\c NSNull. Can be overridden by subclasses to provide an expanded or different set of allowed transformation classes.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> allowed_top_level_classes();
    };
}
