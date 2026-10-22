#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSPickerTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PickerTouchBarItem picker_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * picker_touch_bar_item.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PickerTouchBarItem picker_touch_bar_item(nullptr);
     * picker_touch_bar_item.set_action("text");
     * auto action = picker_touch_bar_item.action();
     * picker_touch_bar_item.set_collapsed_representation_image(cocoon::Image());
     * auto collapsed_representation_image = picker_touch_bar_item.collapsed_representation_image();
     * picker_touch_bar_item.set_collapsed_representation_label("text");
     * auto collapsed_representation_label = picker_touch_bar_item.collapsed_representation_label();
     * picker_touch_bar_item.image_at_index(1);
     * picker_touch_bar_item.is_enabled_at_index(1);
     * picker_touch_bar_item.label_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspickertouchbaritem
     */
    class PickerTouchBarItem : public TouchBarItem
    {
    public:
        /// @brief Creates a new `NSPickerTouchBarItem` instance and returns a handle to it.
        explicit PickerTouchBarItem(const std::string& identifier, const std::vector<Image>& images, PickerTouchBarItemSelectionMode selection_mode, const Object& target, const std::string& action);
        /// @brief Creates a new `NSPickerTouchBarItem` instance and returns a handle to it.
        explicit PickerTouchBarItem(const std::string& identifier, const std::vector<std::string>& labels, PickerTouchBarItemSelectionMode selection_mode, const Object& target, const std::string& action);
        PickerTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        PickerTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PickerTouchBarItem(Adopt adopt);
        using TouchBarItem::customization_label;
        /**
     * @brief Calls `-[NSPickerTouchBarItem imageAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Image image_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPickerTouchBarItem isEnabledAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_enabled_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPickerTouchBarItem labelAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string label_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSPickerTouchBarItem setEnabled:atIndex:]`.
     * @param enabled Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool enabled, std::int64_t index) const;
        /**
     * @brief Calls `-[NSPickerTouchBarItem setImage:atIndex:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& image, std::int64_t index) const;
        /**
     * @brief Calls `-[NSPickerTouchBarItem setLabel:atIndex:]`.
     * @param label Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void set_label(const std::string& label, std::int64_t index) const;
        /**
     * @brief Returns the `action` property of `NSPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `collapsedRepresentationImage` property of `NSPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Image collapsed_representation_image() const;
        /**
     * @brief Sets the `collapsedRepresentationImage` property of `NSPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed_representation_image(const Image& value) const;
        /**
     * @brief Returns the `collapsedRepresentationLabel` property of `NSPickerTouchBarItem`.
     * @details The user facing label and or image visible when the control is in the collapsed representation. If the selectionMode is NSPickerSelectionModeSelectOne, the collapsed representation will automatically be populated with the associated label and or image from the seelctedIndex. Setting these values may be used to override any automatic behavior.
     * @return The converted Objective-C result.
     */
        std::string collapsed_representation_label() const;
        /**
     * @brief Sets the `collapsedRepresentationLabel` property of `NSPickerTouchBarItem`.
     * @details The user facing label and or image visible when the control is in the collapsed representation. If the selectionMode is NSPickerSelectionModeSelectOne, the collapsed representation will automatically be populated with the associated label and or image from the seelctedIndex. Setting these values may be used to override any automatic behavior.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_collapsed_representation_label(const std::string& value) const;
        /**
     * @brief Returns the `controlRepresentation` property of `NSPickerTouchBarItem`.
     * @details The style in which this item will be represented to the user. Defaults to NSPickerRepresentationAutomatic.
     * @return The converted Objective-C result.
     */
        PickerTouchBarItemControlRepresentation control_representation() const;
        /**
     * @brief Sets the `controlRepresentation` property of `NSPickerTouchBarItem`.
     * @details The style in which this item will be represented to the user. Defaults to NSPickerRepresentationAutomatic.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_control_representation(PickerTouchBarItemControlRepresentation value) const;
        /**
     * @brief Returns the `customizationLabel` property of `NSPickerTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @return The converted Objective-C result.
     */
        std::string customization_label() const;
        /**
     * @brief Sets the `customizationLabel` property of `NSPickerTouchBarItem`.
     * @details The localized string labeling this item during user customization. The default value is empty string.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_customization_label(const std::string& value) const;
        /**
     * @brief Returns the `enabled` property of `NSPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /**
     * @brief Returns the `numberOfOptions` property of `NSPickerTouchBarItem`.
     * @details The number of options represented in the control.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_options() const;
        /**
     * @brief Sets the `numberOfOptions` property of `NSPickerTouchBarItem`.
     * @details The number of options represented in the control.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_options(std::int64_t value) const;
        /**
     * @brief Returns the `selectedIndex` property of `NSPickerTouchBarItem`.
     * @details The most recently selected index of the control, or -1 if nothing is selected.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_index() const;
        /**
     * @brief Sets the `selectedIndex` property of `NSPickerTouchBarItem`.
     * @details The most recently selected index of the control, or -1 if nothing is selected.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_index(std::int64_t value) const;
        /**
     * @brief Returns the `selectionColor` property of `NSPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Color selection_color() const;
        /**
     * @brief Sets the `selectionColor` property of `NSPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_color(const Color& value) const;
        /**
     * @brief Returns the `selectionMode` property of `NSPickerTouchBarItem`.
     * @details Defaults to NSPickerTouchBarItemSelectionModeSelectOne
     * @return The converted Objective-C result.
     */
        PickerTouchBarItemSelectionMode selection_mode() const;
        /**
     * @brief Sets the `selectionMode` property of `NSPickerTouchBarItem`.
     * @details Defaults to NSPickerTouchBarItemSelectionModeSelectOne
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_mode(PickerTouchBarItemSelectionMode value) const;
        /**
     * @brief Returns the `target` property of `NSPickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSPickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
    };
}
