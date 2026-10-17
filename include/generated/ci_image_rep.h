#pragma once

#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CIImage;

    /**
     * @brief C++ handle for the Objective-C class `NSCIImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CIImageRep ci_image_rep;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CIImageRep ci_image_rep{};
     * auto made_0 = cocoon::CIImageRep::image_rep_with_ci_image(cocoon::CIImage());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsciimagerep
     */
    class CIImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSCIImageRep` instance and returns a handle to it.
        explicit CIImageRep(const CIImage& image);
        /// @brief Creates a new `NSCIImageRep` instance and returns a handle to it.
        explicit CIImageRep();
        /// @brief Creates a null handle that refers to no native object.
        CIImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CIImageRep(Adopt adopt);
        /**
     * @brief Calls `+[NSCIImageRep imageRepWithCIImage:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImageRep image_rep_with_ci_image(const CIImage& image);
        /**
     * @brief Returns the `CIImage` property of `NSCIImageRep`.
     * @return The converted Objective-C result.
     */
        CIImage ci_image() const;
    };
}
