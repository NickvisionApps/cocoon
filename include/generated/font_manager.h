#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Font;
    class FontPanel;
    class Menu;

    /**
     * @brief C++ handle for the Objective-C class `NSFontManager` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FontManager font_manager;
     * font_manager.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FontManager font_manager{};
     * font_manager.set_action("text");
     * auto action = font_manager.action();
     * font_manager.set_enabled(true);
     * auto enabled = font_manager.is_enabled();
     * font_manager.available_font_names_with_traits(cocoon::FontTraitMask::ItalicFontMask);
     * font_manager.available_members_of_font_family("text");
     * font_manager.convert_font(cocoon::Font());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfontmanager
     */
    class FontManager : public Object
    {
    public:
        /// @brief Creates a new `NSFontManager` instance and returns a handle to it.
        explicit FontManager();
        /// @brief Creates a null handle that refers to no native object.
        FontManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FontManager(Adopt adopt);
        /**
         * @brief Calls `-[NSFontManager addFontTrait:]`.
         * @details These methods are action messages sent from Font Menu items:
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void add_font_trait(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager availableFontNamesWithTraits:]`.
         * @details The following is like "availableFonts", but checks traits. Returns an auto-released instance. To get fonts with "non-italic" or "non-bold" combine the flags NSUnitalicFontMask and/or NSUnboldFontMask as the argument "someTraits".
         * @param some_traits Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> available_font_names_with_traits(FontTraitMask some_traits) const;
        /**
         * @brief Calls `-[NSFontManager availableMembersOfFontFamily:]`.
         * @param fam Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::vector<Object>> available_members_of_font_family(const std::string& fam) const;
        /**
         * @brief Calls `-[NSFontManager convertAttributes:]`.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> convert_attributes(const std::map<std::string, Object>& attributes) const;
        /**
         * @brief Calls `-[NSFontManager convertFont:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font convert_font(const Font& font_obj) const;
        /**
         * @brief Calls `-[NSFontManager convertFont:toFace:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @param typeface Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font convert_font(const Font& font_obj, const std::string& typeface) const;
        /**
         * @brief Calls `-[NSFontManager convertFont:toHaveTrait:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @param trait Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font convert_font(const Font& font_obj, FontTraitMask trait) const;
        /**
         * @brief Calls `-[NSFontManager convertFont:toSize:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @param size Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font convert_font(const Font& font_obj, double size) const;
        /**
         * @brief Calls `-[NSFontManager convertFontTraits:]`.
         * @details Converts fontTraits to a new traits mask value just as -convertFont:. This method is intended to be invoked to query the font traits while the action message (usually -changeFont:) is being invoked when the current font action is either NSAddTraitFontAction or NSRemoveTraitFontAction.
         * @param traits Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontTraitMask convert_font_traits(FontTraitMask traits) const;
        /**
         * @brief Calls `-[NSFontManager convertWeight:ofFont:]`.
         * @param up_flag Argument converted to the Objective-C parameter of the same role.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font convert_weight(bool up_flag, const Font& font_obj) const;
        /**
         * @brief Calls `-[NSFontManager fontMenu:]`.
         * @param create Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Menu font_menu(bool create) const;
        /**
         * @brief Calls `-[NSFontManager fontNamed:hasTraits:]`.
         * @param f_name Argument converted to the Objective-C parameter of the same role.
         * @param some_traits Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool font_named(const std::string& f_name, FontTraitMask some_traits) const;
        /**
         * @brief Calls `-[NSFontManager fontPanel:]`.
         * @param create Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontPanel font_panel(bool create) const;
        /**
         * @brief Calls `-[NSFontManager fontWithFamily:traits:weight:size:]`.
         * @param family Argument converted to the Objective-C parameter of the same role.
         * @param traits Argument converted to the Objective-C parameter of the same role.
         * @param weight Argument converted to the Objective-C parameter of the same role.
         * @param size Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Font font_with_family(const std::string& family, FontTraitMask traits, std::int64_t weight, double size) const;
        /**
         * @brief Calls `-[NSFontManager localizedNameForFamily:face:]`.
         * @param family Argument converted to the Objective-C parameter of the same role.
         * @param face_key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_name_for_family(const std::string& family, const std::string& face_key) const;
        /**
         * @brief Calls `-[NSFontManager modifyFont:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void modify_font(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager modifyFontViaPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void modify_font_via_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager orderFrontFontPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_font_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager orderFrontStylesPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_styles_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager removeFontTrait:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void remove_font_trait(const Object& sender) const;
        /**
         * @brief Calls `-[NSFontManager sendAction]`.
         * @return The converted Objective-C result.
         */
        bool send_action() const;
        /**
         * @brief Calls `+[NSFontManager setFontManagerFactory:]`.
         * @param factory_id Argument converted to the Objective-C parameter of the same role.
         */
        static void set_font_manager_factory(const std::string& factory_id);
        /**
         * @brief Calls `-[NSFontManager setFontMenu:]`.
         * @param new_menu Argument converted to the Objective-C parameter of the same role.
         */
        void set_font_menu(const Menu& new_menu) const;
        /**
         * @brief Calls `+[NSFontManager setFontPanelFactory:]`.
         * @param factory_id Argument converted to the Objective-C parameter of the same role.
         */
        static void set_font_panel_factory(const std::string& factory_id);
        /**
         * @brief Calls `-[NSFontManager setSelectedAttributes:isMultiple:]`.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_attributes(const std::map<std::string, Object>& attributes, bool flag) const;
        /**
         * @brief Calls `-[NSFontManager setSelectedFont:isMultiple:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_font(const Font& font_obj, bool flag) const;
        /**
         * @brief Calls `-[NSFontManager traitsOfFont:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontTraitMask traits_of_font(const Font& font_obj) const;
        /**
         * @brief Calls `-[NSFontManager weightOfFont:]`.
         * @param font_obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t weight_of_font(const Font& font_obj) const;
        /**
         * @brief Returns the `action` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        std::string action() const;
        /**
         * @brief Sets the `action` property of `NSFontManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_action(const std::string& value) const;
        /**
         * @brief Returns the `availableFontFamilies` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> available_font_families() const;
        /**
         * @brief Returns the `availableFonts` property of `NSFontManager`.
         * @details Three methods for supporting app font management. The fonts and names used/returned by these functions are the same as those used by the NSFontPanel. The third method below takes as input a name as returned by "availableFontFamilies" and returns an NSArray of NSArrays. The elements of the "inner" arrays are: (0) the font's name, (1) non-family part of the name as used by NSFontPanel, (2) an NSNumber indicating the weight, and (3) an NSNumber indicating the traits.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> available_fonts() const;
        /**
         * @brief Returns the `currentFontAction` property of `NSFontManager`.
         * @details Returns the current font action used by -convertFont:. This method is intended to be invoked to query the font conversion action while the action message (usually -changeFont:) is being invoked.
         * @return The converted Objective-C result.
         */
        FontAction current_font_action() const;
        /**
         * @brief Returns the `enabled` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        bool is_enabled() const;
        /**
         * @brief Sets the `enabled` property of `NSFontManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled(bool value) const;
        /**
         * @brief Returns the `multiple` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        bool is_multiple() const;
        /**
         * @brief Returns the `selectedFont` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        Font selected_font() const;
        /**
         * @brief Returns the `sharedFontManager` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        static FontManager shared_font_manager();
        /**
         * @brief Returns the `target` property of `NSFontManager`.
         * @return The converted Objective-C result.
         */
        Object target() const;
        /**
         * @brief Sets the `target` property of `NSFontManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_target(const Object& value) const;
    };
}
