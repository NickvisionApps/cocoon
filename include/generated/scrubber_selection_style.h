#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ScrubberSelectionView;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberSelectionStyle` (AppKit).
     * @details \@class NSScrubberSelectionStyle \@abstract \@c NSScrubberSelectionStyle is an abstract class that provides decorative accessory views for selected and highlighted items within a NSScrubber control. Class properties provide convenient access to built-in styles. For a completely custom style, subclassers can override \@c -makeSelectionView to create and configure arbitrary \@c NSScrubberSelectionView subclasses.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberSelectionStyle scrubber_selection_style;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberSelectionStyle scrubber_selection_style{};
     * scrubber_selection_style.make_selection_view();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberselectionstyle
     */
    class ScrubberSelectionStyle : public Object
    {
    public:
        /// @brief Creates a new `NSScrubberSelectionStyle` instance and returns a handle to it.
        explicit ScrubberSelectionStyle();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberSelectionStyle(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberSelectionStyle(Adopt adopt);
        /**
     * @brief Calls `-[NSScrubberSelectionStyle makeSelectionView]`.
     * @return The converted Objective-C result.
     */
        ScrubberSelectionView make_selection_view() const;
        /**
     * @brief Returns the `outlineOverlayStyle` property of `NSScrubberSelectionStyle`.
     * @return The converted Objective-C result.
     */
        static ScrubberSelectionStyle outline_overlay_style();
        /**
     * @brief Returns the `roundedBackgroundStyle` property of `NSScrubberSelectionStyle`.
     * @return The converted Objective-C result.
     */
        static ScrubberSelectionStyle rounded_background_style();
    };
}
