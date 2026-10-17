#include "generated/popover_touch_bar_item.h"
#include "internal.h"

namespace cocoon
{
    PopoverTouchBarItem::PopoverTouchBarItem() : TouchBarItem(nullptr)
    {
    }

    PopoverTouchBarItem::PopoverTouchBarItem(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    PopoverTouchBarItem::PopoverTouchBarItem(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    void PopoverTouchBarItem::dismiss_popover(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) dismissPopover:cocoon::internal::native_id(sender)];
    }

    GestureRecognizer PopoverTouchBarItem::make_standard_activate_popover_gesture_recognizer() const
    {
        return cocoon::internal::wrap<GestureRecognizer>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) makeStandardActivatePopoverGestureRecognizer]);
    }

    void PopoverTouchBarItem::show_popover(const Object& sender) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) showPopover:cocoon::internal::native_id(sender)];
    }

    View PopoverTouchBarItem::collapsed_representation() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) collapsedRepresentation]);
    }

    void PopoverTouchBarItem::set_collapsed_representation(const View& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setCollapsedRepresentation:cocoon::internal::native<::NSView>(value)];
    }

    Image PopoverTouchBarItem::collapsed_representation_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) collapsedRepresentationImage]);
    }

    void PopoverTouchBarItem::set_collapsed_representation_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setCollapsedRepresentationImage:cocoon::internal::native<::NSImage>(value)];
    }

    std::string PopoverTouchBarItem::collapsed_representation_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) collapsedRepresentationLabel]);
    }

    void PopoverTouchBarItem::set_collapsed_representation_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setCollapsedRepresentationLabel:cocoon::internal::to(value)];
    }

    std::string PopoverTouchBarItem::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) customizationLabel]);
    }

    void PopoverTouchBarItem::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    TouchBar PopoverTouchBarItem::popover_touch_bar() const
    {
        return cocoon::internal::wrap<TouchBar>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) popoverTouchBar]);
    }

    void PopoverTouchBarItem::set_popover_touch_bar(const TouchBar& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setPopoverTouchBar:cocoon::internal::native<::NSTouchBar>(value)];
    }

    TouchBar PopoverTouchBarItem::press_and_hold_touch_bar() const
    {
        return cocoon::internal::wrap<TouchBar>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) pressAndHoldTouchBar]);
    }

    void PopoverTouchBarItem::set_press_and_hold_touch_bar(const TouchBar& value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setPressAndHoldTouchBar:cocoon::internal::native<::NSTouchBar>(value)];
    }

    bool PopoverTouchBarItem::shows_close_button() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPopoverTouchBarItem>(this) showsCloseButton]);
    }

    void PopoverTouchBarItem::set_shows_close_button(bool value) const
    {
        [cocoon::internal::ns<::NSPopoverTouchBarItem>(this) setShowsCloseButton:static_cast<::BOOL>(value)];
    }
}
