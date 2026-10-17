#pragma once

#include "generated/enums.h"
#include "generated/scrubber_arranged_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScrubberSelectionView` (AppKit).
     * @details \@class NSScrubberSelectionView \@abstract The base view class for all selection decorations used by the \@c NSScrubber control.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberArrangedView.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberSelectionView scrubber_selection_view;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberselectionview
     */
    class ScrubberSelectionView : public ScrubberArrangedView
    {
    public:
        /// @brief Creates a new `NSScrubberSelectionView` instance and returns a handle to it.
        explicit ScrubberSelectionView();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberSelectionView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberSelectionView(Adopt adopt);
    };
}
