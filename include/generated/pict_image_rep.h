#pragma once

#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPICTImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PICTImageRep pict_image_rep;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspictimagerep
     */
    class PICTImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSPICTImageRep` instance and returns a handle to it.
        explicit PICTImageRep(const std::vector<std::uint8_t>& pict_data);
        /// @brief Creates a new `NSPICTImageRep` instance and returns a handle to it.
        explicit PICTImageRep();
        /// @brief Creates a null handle that refers to no native object.
        PICTImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PICTImageRep(Adopt adopt);
        /**
     * @brief Calls `+[NSPICTImageRep imageRepWithData:]`.
     * @param pict_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PICTImageRep image_rep_with_data(const std::vector<std::uint8_t>& pict_data);
        /**
     * @brief Returns the `PICTRepresentation` property of `NSPICTImageRep`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> pict_representation() const;
        /**
     * @brief Returns the `boundingBox` property of `NSPICTImageRep`.
     * @return The converted Objective-C result.
     */
        Rect bounding_box() const;
    };
}
