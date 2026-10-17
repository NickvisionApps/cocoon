#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/touch_bar_item.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class SharingCollaborationModeRestriction;
    class SharingService;

    /**
     * @brief C++ handle for the Objective-C class `NSSharingServicePickerTouchBarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TouchBarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SharingServicePickerTouchBarItem sharing_service_picker_touch_bar_item(nullptr);  // null handle; instances normally come from other API calls
     * sharing_service_picker_touch_bar_item.set_button_image(cocoon::Image());
     * sharing_service_picker_touch_bar_item.did_choose_sharing_service().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SharingServicePickerTouchBarItem sharing_service_picker_touch_bar_item(nullptr);
     * sharing_service_picker_touch_bar_item.set_button_image(cocoon::Image());
     * auto button_image = sharing_service_picker_touch_bar_item.button_image();
     * sharing_service_picker_touch_bar_item.set_button_title("text");
     * auto button_title = sharing_service_picker_touch_bar_item.button_title();
     * sharing_service_picker_touch_bar_item.set_enabled(true);
     * auto enabled = sharing_service_picker_touch_bar_item.is_enabled();
     * sharing_service_picker_touch_bar_item.did_choose_sharing_service().connect([](cocoon::SharingService a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssharingservicepickertouchbaritem
     */
    class SharingServicePickerTouchBarItem : public TouchBarItem
    {
    public:
        SharingServicePickerTouchBarItem();
        /// @brief Creates a null handle that refers to no native object.
        SharingServicePickerTouchBarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SharingServicePickerTouchBarItem(Adopt adopt);
        /**
     * @brief Returns the `buttonImage` property of `NSSharingServicePickerTouchBarItem`.
     * @return The converted Objective-C result.
     */
        Image button_image() const;
        /**
     * @brief Sets the `buttonImage` property of `NSSharingServicePickerTouchBarItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_image(const Image& value) const;
        /**
     * @brief Returns the `buttonTitle` property of `NSSharingServicePickerTouchBarItem`.
     * @details Get/set the button title and image. By default, the button title is an empty string, and the button image is a share picker image.
     * @return The converted Objective-C result.
     */
        std::string button_title() const;
        /**
     * @brief Sets the `buttonTitle` property of `NSSharingServicePickerTouchBarItem`.
     * @details Get/set the button title and image. By default, the button title is an empty string, and the button image is a share picker image.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_button_title(const std::string& value) const;
        /**
     * @brief Returns the `enabled` property of `NSSharingServicePickerTouchBarItem`.
     * @details Enables or disabled the sharing button; if the popover is shown, it will first be closed.
     * @return The converted Objective-C result.
     */
        bool is_enabled() const;
        /**
     * @brief Sets the `enabled` property of `NSSharingServicePickerTouchBarItem`.
     * @details Enables or disabled the sharing button; if the popover is shown, it will first be closed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_enabled(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `sharing_services_for_items_proposed_sharing_services`; connect a callback with `sharing_services_for_items_proposed_sharing_services().connect(...)`.
        Signal<SharingServicePickerTouchBarItem, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)> sharing_services_for_items_proposed_sharing_services() const
        {
            return Signal<SharingServicePickerTouchBarItem, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)>(handle(), "sharing_services_for_items_proposed_sharing_services");
        }
        /// @brief Signal for the delegate/data-source method behind `delegate_for_sharing_service`; connect a callback with `delegate_for_sharing_service().connect(...)`.
        Signal<SharingServicePickerTouchBarItem, Object(SharingService)> delegate_for_sharing_service() const
        {
            return Signal<SharingServicePickerTouchBarItem, Object(SharingService)>(handle(), "delegate_for_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `did_choose_sharing_service`; connect a callback with `did_choose_sharing_service().connect(...)`.
        Signal<SharingServicePickerTouchBarItem, void(SharingService)> did_choose_sharing_service() const
        {
            return Signal<SharingServicePickerTouchBarItem, void(SharingService)>(handle(), "did_choose_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `collaboration_mode_restrictions`; connect a callback with `collaboration_mode_restrictions().connect(...)`.
        Signal<SharingServicePickerTouchBarItem, std::vector<SharingCollaborationModeRestriction>()> collaboration_mode_restrictions() const
        {
            return Signal<SharingServicePickerTouchBarItem, std::vector<SharingCollaborationModeRestriction>()>(handle(), "collaboration_mode_restrictions");
        }
        /// @brief Signal for the delegate/data-source method behind `items_for_sharing_service_picker_touch_bar_item`; connect a callback with `items_for_sharing_service_picker_touch_bar_item().connect(...)`.
        Signal<SharingServicePickerTouchBarItem, std::vector<Object>()> items_for_sharing_service_picker_touch_bar_item() const
        {
            return Signal<SharingServicePickerTouchBarItem, std::vector<Object>()>(handle(), "items_for_sharing_service_picker_touch_bar_item");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
