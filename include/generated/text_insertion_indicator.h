#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTextInsertionIndicator` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextInsertionIndicator text_insertion_indicator;
     * text_insertion_indicator.set_automatic_mode_options(cocoon::TextInsertionIndicatorAutomaticModeOptions::ShowEffectsView);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextInsertionIndicator text_insertion_indicator{};
     * text_insertion_indicator.set_automatic_mode_options(cocoon::TextInsertionIndicatorAutomaticModeOptions::ShowEffectsView);
     * auto automatic_mode_options = text_insertion_indicator.automatic_mode_options();
     * text_insertion_indicator.set_color(cocoon::Color());
     * auto color = text_insertion_indicator.color();
     * text_insertion_indicator.set_display_mode(cocoon::TextInsertionIndicatorDisplayMode::Automatic);
     * auto display_mode = text_insertion_indicator.display_mode();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextinsertionindicator
     */
    class TextInsertionIndicator : public View
    {
    public:
        /// @brief Creates a new `NSTextInsertionIndicator` instance and returns a handle to it.
        explicit TextInsertionIndicator();
        /// @brief Creates a null handle that refers to no native object.
        TextInsertionIndicator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextInsertionIndicator(Adopt adopt);
        /**
     * @brief Returns the `automaticModeOptions` property of `NSTextInsertionIndicator`.
     * @details Options for the NSTextInsertionIndicatorDisplayModeAutomatic display mode. Defaults to NSTextInsertionIndicatorAutomaticModeOptionsShowEffectsView.
     * @return The converted Objective-C result.
     */
        TextInsertionIndicatorAutomaticModeOptions automatic_mode_options() const;
        /**
     * @brief Sets the `automaticModeOptions` property of `NSTextInsertionIndicator`.
     * @details Options for the NSTextInsertionIndicatorDisplayModeAutomatic display mode. Defaults to NSTextInsertionIndicatorAutomaticModeOptionsShowEffectsView.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatic_mode_options(TextInsertionIndicatorAutomaticModeOptions value) const;
        /**
     * @brief Returns the `color` property of `NSTextInsertionIndicator`.
     * @details The color of the indicator. \@discussion Defaults to NSColor.textInsertionPointColor. \@note If set to \@c nil, uses NSColor.textInsertionPointColor.
     * @return The converted Objective-C result.
     */
        Color color() const;
        /**
     * @brief Sets the `color` property of `NSTextInsertionIndicator`.
     * @details The color of the indicator. \@discussion Defaults to NSColor.textInsertionPointColor. \@note If set to \@c nil, uses NSColor.textInsertionPointColor.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_color(const Color& value) const;
        /**
     * @brief Returns the `displayMode` property of `NSTextInsertionIndicator`.
     * @details Sets-returns the indicator's display mode.
     * @return The converted Objective-C result.
     */
        TextInsertionIndicatorDisplayMode display_mode() const;
        /**
     * @brief Sets the `displayMode` property of `NSTextInsertionIndicator`.
     * @details Sets-returns the indicator's display mode.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_display_mode(TextInsertionIndicatorDisplayMode value) const;
        /**
     * @brief Returns the `effectsViewInserter` property of `NSTextInsertionIndicator`.
     * @details Sets-returns a block that inserts a view into the view hierarchy. \@discussion During dictation the NSTextInsertionIndicator displays a glow effect by inserting a view below the text view. If an application needs to insert the view in a different way, the application can specify a block of code that will be called when the glow effect needs to be displayed.
     * @return The converted Objective-C result.
     */
        std::function<void(View)> effects_view_inserter() const;
        /**
     * @brief Sets the `effectsViewInserter` property of `NSTextInsertionIndicator`.
     * @details Sets-returns a block that inserts a view into the view hierarchy. \@discussion During dictation the NSTextInsertionIndicator displays a glow effect by inserting a view below the text view. If an application needs to insert the view in a different way, the application can specify a block of code that will be called when the glow effect needs to be displayed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_effects_view_inserter(std::function<void(View)> value) const;
    };
}
