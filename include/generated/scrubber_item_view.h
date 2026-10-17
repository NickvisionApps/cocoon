#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/scrubber_arranged_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScrubberItemView` (AppKit).
     * @details \@class NSScrubberItemView \@abstract The base view class that is arranged by a \@c NSScrubber control.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberArrangedView.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberItemView scrubber_item_view;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberitemview
     */
    class ScrubberItemView : public ScrubberArrangedView
    {
    public:
        /// @brief Creates a new `NSScrubberItemView` instance and returns a handle to it.
        explicit ScrubberItemView();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberItemView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberItemView(Adopt adopt);
    };
}
