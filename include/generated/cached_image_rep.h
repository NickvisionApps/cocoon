#pragma once

#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCachedImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CachedImageRep cached_image_rep;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscachedimagerep
     */
    class CachedImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSCachedImageRep` instance and returns a handle to it.
        explicit CachedImageRep();
        /// @brief Creates a null handle that refers to no native object.
        CachedImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CachedImageRep(Adopt adopt);
    };
}
