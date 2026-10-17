#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSNull` (Foundation).
     * @details A singleton object used to represent null values in collection objects that don't allow 'nil' values. ''NSNull'' is "toll-free bridged" with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cfnull>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Null null;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Null null{};
     * auto made_0 = cocoon::Null::null();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnull
     */
    class Null : public Object
    {
    public:
        /// @brief Creates a new `NSNull` instance and returns a handle to it.
        explicit Null();
        /// @brief Creates a null handle that refers to no native object.
        Null(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Null(Adopt adopt);
        /**
     * @brief Calls `+[NSNull null]`.
     * @details Returns the singleton instance of 'NSNull'.
     * @return The converted Objective-C result.
     */
        static Null null();
    };
}
