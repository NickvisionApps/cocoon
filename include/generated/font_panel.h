#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/panel.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Font;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSFontPanel` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Panel.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FontPanel font_panel;
     * font_panel.set_accessory_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FontPanel font_panel{};
     * font_panel.set_accessory_view(cocoon::View());
     * auto accessory_view = font_panel.accessory_view();
     * font_panel.set_enabled(true);
     * auto enabled = font_panel.is_enabled();
     * font_panel.set_works_when_modal(true);
     * auto works_when_modal = font_panel.works_when_modal();
     * font_panel.panel_convert_font(cocoon::Font());
     * font_panel.reload_default_font_families();
     * font_panel.set_panel_font(cocoon::Font(), true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfontpanel
     */
    class FontPanel : public Panel
    {
    public:
        /// @brief Creates a new `NSFontPanel` instance and returns a handle to it.
        explicit FontPanel();
        /// @brief Creates a null handle that refers to no native object.
        FontPanel(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FontPanel(Adopt adopt);
        using Panel::set_works_when_modal;
        using Panel::works_when_modal;
        /**
         * @brief Calls `-[NSFontPanel panelConvertFont:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font panel_convert_font(const Font& font_obj) const;
        /**
         * @brief Calls `-[NSFontPanel reloadDefaultFontFamilies]`.
         * @details This method triggers a re-load to the default state, so that the delegate will be called, and have an opportunity to scrutinize the default list of fonts to be displayed in the panel.
         */
        void reload_default_font_families() const;
        /**
         * @brief Calls `-[NSFontPanel setPanelFont:isMultiple:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_panel_font(const Font& font_obj, bool flag) const;
        /**
         * @brief Returns the `accessoryView` property of `NSFontPanel`.
         * @return The converted Objective-C result.
         */
        View accessory_view() const;
        /**
         * @brief Sets the `accessoryView` property of `NSFontPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessory_view(const View& value) const;
        /**
         * @brief Returns the `enabled` property of `NSFontPanel`.
         * @return The converted Objective-C result.
         */
        bool is_enabled() const;
        /**
         * @brief Sets the `enabled` property of `NSFontPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled(bool value) const;
        /**
         * @brief Returns the `sharedFontPanel` property of `NSFontPanel`.
         * @return The converted Objective-C result.
         */
        static FontPanel shared_font_panel();
        /**
         * @brief Returns the `sharedFontPanelExists` property of `NSFontPanel`.
         * @return The converted Objective-C result.
         */
        static bool shared_font_panel_exists();
        /**
         * @brief Returns the `worksWhenModal` property of `NSFontPanel`.
         * @return The converted Objective-C result.
         */
        bool works_when_modal() const;
        /**
         * @brief Sets the `worksWhenModal` property of `NSFontPanel`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_works_when_modal(bool value) const;
    };
}
