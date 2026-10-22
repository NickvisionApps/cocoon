#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSEPSImageRep` (AppKit).
     * @details An object that can render an image from encapsulated PostScript (EPS) code.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::EPSImageRep eps_image_rep;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsepsimagerep
     */
    class EPSImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSEPSImageRep` instance and returns a handle to it.
        explicit EPSImageRep(const std::vector<std::uint8_t>& eps_data);
        /// @brief Creates a new `NSEPSImageRep` instance and returns a handle to it.
        explicit EPSImageRep();
        /// @brief Creates a null handle that refers to no native object.
        EPSImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit EPSImageRep(Adopt adopt);
        /**
         * @brief Calls `+[NSEPSImageRep imageRepWithData:]`.
         * @details Creates and returns a representation of an image initialized with the specified EPS data. Convenience of '-initWithData:'. - Note: This method always returns 'nil' on macOS 14.0 and later.
         * @param eps_data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static EPSImageRep image_rep_with_data(const std::vector<std::uint8_t>& eps_data);
        /**
         * @brief Returns the `EPSRepresentation` property of `NSEPSImageRep`.
         * @details The EPS representation of the image representation.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> eps_representation() const;
        /**
         * @brief Returns the `boundingBox` property of `NSEPSImageRep`.
         * @details The rectangle that bounds the image representation.
         * @return The converted Objective-C result.
         */
        Rect bounding_box() const;
    };
}
