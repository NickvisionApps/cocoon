#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/scrubber_item_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class TextField;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberTextItemView` (AppKit).
     * @details \@class NSScrubberTextItemView \@abstract A simple \@c NSScrubberItemView for displaying text. The -fittingSize method can be used to measure the smallest size for the view which fits the title without truncating.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScrubberItemView.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberTextItemView scrubber_text_item_view;
     * scrubber_text_item_view.set_title("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberTextItemView scrubber_text_item_view{};
     * scrubber_text_item_view.set_title("text");
     * auto title = scrubber_text_item_view.title();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubbertextitemview
     */
    class ScrubberTextItemView : public ScrubberItemView
    {
    public:
        /// @brief Creates a new `NSScrubberTextItemView` instance and returns a handle to it.
        explicit ScrubberTextItemView();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberTextItemView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberTextItemView(Adopt adopt);
        /**
     * @brief Returns the `textField` property of `NSScrubberTextItemView`.
     * @return The converted Objective-C result.
     */
        TextField text_field() const;
        /**
     * @brief Returns the `title` property of `NSScrubberTextItemView`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSScrubberTextItemView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
    };
}
