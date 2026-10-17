#include "generated/picker_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    PickerTouchBarItem::PickerTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    PickerTouchBarItem::PickerTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    PickerTouchBarItem::PickerTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    Image PickerTouchBarItem::image_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) imageAtIndex:static_cast<::NSInteger>(index)]);
    }

    bool PickerTouchBarItem::is_enabled_at_index(std::int64_t index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) isEnabledAtIndex:static_cast<::NSInteger>(index)]);
    }

    std::string PickerTouchBarItem::label_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPickerTouchBarItem>(this) labelAtIndex:static_cast<::NSInteger>(index)]);
    }

    PickerTouchBarItem PickerTouchBarItem::picker_touch_bar_item_with_identifier(const std::string& identifier, const std::vector<Image>& images, PickerTouchBarItemSelectionMode selection_mode, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<PickerTouchBarItem>([::NSPickerTouchBarItem pickerTouchBarItemWithIdentifier:cocoon::internal::to(identifier)
                                                                                              images:cocoon::internal::to_array(images, [](const Image& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native<::NSImage>(e);
                                                                                                                  })
                                                                                       selectionMode:static_cast<::NSPickerTouchBarItemSelectionMode>(selection_mode)
                                                                                              target:cocoon::internal::native_id(target)
                                                                                              action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    PickerTouchBarItem PickerTouchBarItem::picker_touch_bar_item_with_identifier(const std::string& identifier, const std::vector<std::string>& labels, PickerTouchBarItemSelectionMode selection_mode, const Object& target, const std::string& action)
    {
        return cocoon::internal::wrap<PickerTouchBarItem>([::NSPickerTouchBarItem pickerTouchBarItemWithIdentifier:cocoon::internal::to(identifier)
                                                                                              labels:cocoon::internal::to_array(labels, [](const std::string& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::to(e);
                                                                                                                  })
                                                                                       selectionMode:static_cast<::NSPickerTouchBarItemSelectionMode>(selection_mode)
                                                                                              target:cocoon::internal::native_id(target)
                                                                                              action:NSSelectorFromString(cocoon::internal::to(action))]);
    }

    void PickerTouchBarItem::set_enabled(bool enabled, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setEnabled:static_cast<::BOOL>(enabled) atIndex:static_cast<::NSInteger>(index)];
    }

    void PickerTouchBarItem::set_image(const Image& image, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setImage:cocoon::internal::native<::NSImage>(image) atIndex:static_cast<::NSInteger>(index)];
    }

    void PickerTouchBarItem::set_label(const std::string& label, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setLabel:cocoon::internal::to(label) atIndex:static_cast<::NSInteger>(index)];
    }

    std::string PickerTouchBarItem::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSPickerTouchBarItem>(this) action]));
    }

    void PickerTouchBarItem::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    Image PickerTouchBarItem::collapsed_representation_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) collapsedRepresentationImage]);
    }

    void PickerTouchBarItem::set_collapsed_representation_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setCollapsedRepresentationImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string PickerTouchBarItem::collapsed_representation_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPickerTouchBarItem>(this) collapsedRepresentationLabel]);
    }

    void PickerTouchBarItem::set_collapsed_representation_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setCollapsedRepresentationLabel:cocoon::internal::to(value)];
    }

    PickerTouchBarItemControlRepresentation PickerTouchBarItem::control_representation() const
    {
        return static_cast<PickerTouchBarItemControlRepresentation>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) controlRepresentation]);
    }

    void PickerTouchBarItem::set_control_representation(PickerTouchBarItemControlRepresentation value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setControlRepresentation:static_cast<::NSPickerTouchBarItemControlRepresentation>(value)];
    }

    std::string PickerTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPickerTouchBarItem>(this) customizationLabel]);
    }

    void PickerTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    bool PickerTouchBarItem::is_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) isEnabled]);
    }

    void PickerTouchBarItem::set_enabled(bool value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setEnabled:static_cast<::BOOL>(value)];
    }

    std::int64_t PickerTouchBarItem::number_of_options() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) numberOfOptions]);
    }

    void PickerTouchBarItem::set_number_of_options(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setNumberOfOptions:static_cast<::NSInteger>(value)];
    }

    std::int64_t PickerTouchBarItem::selected_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) selectedIndex]);
    }

    void PickerTouchBarItem::set_selected_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setSelectedIndex:static_cast<::NSInteger>(value)];
    }

    Color PickerTouchBarItem::selection_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) selectionColor]);
    }

    void PickerTouchBarItem::set_selection_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setSelectionColor:cocoon::internal::native<::NSColor>(value)];
    }

    PickerTouchBarItemSelectionMode PickerTouchBarItem::selection_mode() const
    {
        return static_cast<PickerTouchBarItemSelectionMode>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) selectionMode]);
    }

    void PickerTouchBarItem::set_selection_mode(PickerTouchBarItemSelectionMode value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setSelectionMode:static_cast<::NSPickerTouchBarItemSelectionMode>(value)];
    }

    Object PickerTouchBarItem::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPickerTouchBarItem>(this) target]);
    }

    void PickerTouchBarItem::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSPickerTouchBarItem>(this) setTarget:cocoon::internal::native_id(value)];
    }
}
