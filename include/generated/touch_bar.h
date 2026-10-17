#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TouchBarItem;

    /**
     * @brief C++ handle for the Objective-C class `NSTouchBar` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TouchBar touch_bar;
     * touch_bar.set_automatic_customize_touch_bar_menu_item_enabled(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TouchBar touch_bar{};
     * touch_bar.set_automatic_customize_touch_bar_menu_item_enabled(true);
     * auto automatic_customize_touch_bar_menu_item_enabled = touch_bar.is_automatic_customize_touch_bar_menu_item_enabled();
     * touch_bar.set_customization_allowed_item_identifiers({"a", "b"});
     * auto customization_allowed_item_identifiers = touch_bar.customization_allowed_item_identifiers();
     * touch_bar.set_customization_identifier("text");
     * auto customization_identifier = touch_bar.customization_identifier();
     * touch_bar.item_for_identifier("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstouchbar
     */
    class TouchBar : public Object
    {
    public:
        /// @brief Creates a new `NSTouchBar` instance and returns a handle to it.
        explicit TouchBar();
        /// @brief Creates a null handle that refers to no native object.
        TouchBar(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TouchBar(Adopt adopt);
        /**
     * @brief Calls `-[NSTouchBar itemForIdentifier:]`.
     * @details Returns an instantiated NSTouchBarItem for the given identifier. Items are resolved from the following locations, in order: items already in the instantiated items array items in the defaultTouchBarItems set items returned from the delegate's -touchBar:makeItemForIdentifier: method some special identifiers are handled automatically NSTouchBarItemIdentifierFixedSpaceSmall -> NSTouchBar will automatically create a standard small space NSTouchBarItemIdentifierFixedSpaceLarge -> NSTouchBar will automatically create a standard large space NSTouchBarItemIdentifierFlexibleSpace -> NSTouchBar will automatically create a standard flexible space NSTouchBarItemIdentifierOtherItemsProxy -> NSTouchBar will automatically create a special item that acts as a proxy for the items of NSTouchBar closer to the first responder.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TouchBarItem item_for_identifier(const std::string& identifier) const;
        /**
     * @brief Returns the `automaticCustomizeTouchBarMenuItemEnabled` property of `NSTouchBar`.
     * @details Convenience method for the NSApp's automaticCustomizeTouchBarMenuItemEnabled property.
     * @return The converted Objective-C result.
     */
        static bool is_automatic_customize_touch_bar_menu_item_enabled();
        /**
     * @brief Sets the `automaticCustomizeTouchBarMenuItemEnabled` property of `NSTouchBar`.
     * @details Convenience method for the NSApp's automaticCustomizeTouchBarMenuItemEnabled property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_automatic_customize_touch_bar_menu_item_enabled(bool value);
        /**
     * @brief Returns the `customizationAllowedItemIdentifiers` property of `NSTouchBar`.
     * @details The items that are presented in the customization palette for the user to add to the NSTouchBar. These items will be presented to the user in the order specified in this array. This property is archived.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> customization_allowed_item_identifiers() const;
        /**
     * @brief Sets the `customizationAllowedItemIdentifiers` property of `NSTouchBar`.
     * @details The items that are presented in the customization palette for the user to add to the NSTouchBar. These items will be presented to the user in the order specified in this array. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_allowed_item_identifiers(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `customizationIdentifier` property of `NSTouchBar`.
     * @details A string uniquely identifying this bar for customization purposes. All bars with this identifier will have their items coordinated automatically during customization or instantiation. NSTouchBars lacking a customizationIdentifier are not customizable. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string customization_identifier() const;
        /**
     * @brief Sets the `customizationIdentifier` property of `NSTouchBar`.
     * @details A string uniquely identifying this bar for customization purposes. All bars with this identifier will have their items coordinated automatically during customization or instantiation. NSTouchBars lacking a customizationIdentifier are not customizable. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_identifier(const std::string& value) const;
        /**
     * @brief Returns the `customizationRequiredItemIdentifiers` property of `NSTouchBar`.
     * @details Some items are too important to be removed. The corresponding item identifiers should be listed here. During customization the user will be prevented from removing these items from the NSTouchBar. This property is archived.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> customization_required_item_identifiers() const;
        /**
     * @brief Sets the `customizationRequiredItemIdentifiers` property of `NSTouchBar`.
     * @details Some items are too important to be removed. The corresponding item identifiers should be listed here. During customization the user will be prevented from removing these items from the NSTouchBar. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_required_item_identifiers(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `defaultItemIdentifiers` property of `NSTouchBar`.
     * @details An array of identifiers specifying the items in this NSTouchBar. When constructing the instantiated items array, the identifiers in this array will be fed through the -itemForIdentifier: method. Item identifiers should be globally unique, excepting NSTouchBarItemIdentifierFixedSpaceSmall, NSTouchBarItemIdentifierFixedSpaceLarge, NSTouchBarItemIdentifierFlexibleSpace, and NSTouchBarItemIdentifierOtherItemsProxy. This array also corresponds to the item ordering for the receiver in the “default set” in the customization palette. This property is archived.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> default_item_identifiers() const;
        /**
     * @brief Sets the `defaultItemIdentifiers` property of `NSTouchBar`.
     * @details An array of identifiers specifying the items in this NSTouchBar. When constructing the instantiated items array, the identifiers in this array will be fed through the -itemForIdentifier: method. Item identifiers should be globally unique, excepting NSTouchBarItemIdentifierFixedSpaceSmall, NSTouchBarItemIdentifierFixedSpaceLarge, NSTouchBarItemIdentifierFlexibleSpace, and NSTouchBarItemIdentifierOtherItemsProxy. This array also corresponds to the item ordering for the receiver in the “default set” in the customization palette. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_item_identifiers(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `escapeKeyReplacementItemIdentifier` property of `NSTouchBar`.
     * @details An item identifier designating an item that replaces the standard system escape key. The item may be located in the templateItems set, or provided by the delegate. This property is not archived.
     * @return The converted Objective-C result.
     */
        std::string escape_key_replacement_item_identifier() const;
        /**
     * @brief Sets the `escapeKeyReplacementItemIdentifier` property of `NSTouchBar`.
     * @details An item identifier designating an item that replaces the standard system escape key. The item may be located in the templateItems set, or provided by the delegate. This property is not archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_escape_key_replacement_item_identifier(const std::string& value) const;
        /**
     * @brief Returns the `itemIdentifiers` property of `NSTouchBar`.
     * @details The resolved array of item identifiers. If the bar has not been customized this will match the defaultItemIdentifiers. This property is not archived.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> item_identifiers() const;
        /**
     * @brief Returns the `principalItemIdentifier` property of `NSTouchBar`.
     * @details Specifying a principal item identifier communicates that the item with that identifier has special significance to this NSTouchBar. Currently, that item will be placed in the center of the resolved row. Note that multiple visible bars may each specify a principal item identifier - but only one of them can have the request honored. This property is archived.
     * @return The converted Objective-C result.
     */
        std::string principal_item_identifier() const;
        /**
     * @brief Sets the `principalItemIdentifier` property of `NSTouchBar`.
     * @details Specifying a principal item identifier communicates that the item with that identifier has special significance to this NSTouchBar. Currently, that item will be placed in the center of the resolved row. Note that multiple visible bars may each specify a principal item identifier - but only one of them can have the request honored. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_principal_item_identifier(const std::string& value) const;
        /**
     * @brief Returns the `templateItems` property of `NSTouchBar`.
     * @details Items in this set are the first step in resolving instantiated items from their identifiers. If an item identifier is specified in the itemIdentifiers array, and an item with that identifier is in this set, it will be added to the items array in the corresponding location. This property is archived.
     * @return The converted Objective-C result.
     */
        std::vector<TouchBarItem> template_items() const;
        /**
     * @brief Sets the `templateItems` property of `NSTouchBar`.
     * @details Items in this set are the first step in resolving instantiated items from their identifiers. If an item identifier is specified in the itemIdentifiers array, and an item with that identifier is in this set, it will be added to the items array in the corresponding location. This property is archived.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_template_items(const std::vector<TouchBarItem>& value) const;
        /**
     * @brief Returns the `visible` property of `NSTouchBar`.
     * @details When YES, the NSTouchBar is attached to an eligible NSTouchBar provider, and its items are displayable, assuming adequate space. This property is key value observable.
     * @return The converted Objective-C result.
     */
        bool is_visible() const;
        /// @brief Signal for the delegate/data-source method behind `make_item_for_identifier`; connect a callback with `make_item_for_identifier().connect(...)`.
        Signal<TouchBar, TouchBarItem(std::string)> make_item_for_identifier() const
        {
            return Signal<TouchBar, TouchBarItem(std::string)>(handle(), "make_item_for_identifier");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
