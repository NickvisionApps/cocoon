#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class ScrubberLayoutAttributes;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubberArrangedView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScrubberArrangedView scrubber_arranged_view;
     * scrubber_arranged_view.set_highlighted(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScrubberArrangedView scrubber_arranged_view{};
     * scrubber_arranged_view.set_highlighted(true);
     * auto highlighted = scrubber_arranged_view.is_highlighted();
     * scrubber_arranged_view.set_selected(true);
     * auto selected = scrubber_arranged_view.is_selected();
     * scrubber_arranged_view.apply_layout_attributes(cocoon::ScrubberLayoutAttributes());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubberarrangedview
     */
    class ScrubberArrangedView : public View
    {
    public:
        /// @brief Creates a new `NSScrubberArrangedView` instance and returns a handle to it.
        explicit ScrubberArrangedView();
        /// @brief Creates a null handle that refers to no native object.
        ScrubberArrangedView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScrubberArrangedView(Adopt adopt);
        /**
     * @brief Calls `-[NSScrubberArrangedView applyLayoutAttributes:]`.
     * @param layout_attributes Argument converted to the Objective-C parameter of the same role.
     */
        void apply_layout_attributes(const ScrubberLayoutAttributes& layout_attributes) const;
        /**
     * @brief Returns the `highlighted` property of `NSScrubberArrangedView`.
     * @return The converted Objective-C result.
     */
        bool is_highlighted() const;
        /**
     * @brief Sets the `highlighted` property of `NSScrubberArrangedView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_highlighted(bool value) const;
        /**
     * @brief Returns the `selected` property of `NSScrubberArrangedView`.
     * @return The converted Objective-C result.
     */
        bool is_selected() const;
        /**
     * @brief Sets the `selected` property of `NSScrubberArrangedView`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected(bool value) const;
    };
}
