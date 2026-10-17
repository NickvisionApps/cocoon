#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class MenuItem;
    class SharingCollaborationModeRestriction;
    class SharingService;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSSharingServicePicker` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SharingServicePicker sharing_service_picker(nullptr);  // null handle; instances normally come from other API calls
     * sharing_service_picker.did_choose_sharing_service().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SharingServicePicker sharing_service_picker(nullptr);
     * sharing_service_picker.close();
     * sharing_service_picker.show_relative_to_rect({{0, 0}, {100, 100}}, cocoon::View(), cocoon::RectEdge::MinX);
     * sharing_service_picker.did_choose_sharing_service().connect([](cocoon::SharingService a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssharingservicepicker
     */
    class SharingServicePicker : public Object
    {
    public:
        /// @brief Creates a new `NSSharingServicePicker` instance and returns a handle to it.
        explicit SharingServicePicker(const std::vector<Object>& items);
        SharingServicePicker();
        /// @brief Creates a null handle that refers to no native object.
        SharingServicePicker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SharingServicePicker(Adopt adopt);
        /**
     * @brief Calls `-[NSSharingServicePicker close]`.
     * @details Closes the picker UI. '-[NSSharingServicePickerDelegate sharingServicePicker:didChooseSharingService:]' will be invoked if 'delegate' is set, with a 'nil' service.
     */
        void close() const;
        /**
     * @brief Calls `-[NSSharingServicePicker showRelativeToRect:ofView:preferredEdge:]`.
     * @details Shows the picker, populated with sharing services related to the instance items. When the user selects one of the sharing services, the sharing service will be performed. Note that this method must be called on mouseDown.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param preferred_edge Argument converted to the Objective-C parameter of the same role.
     */
        void show_relative_to_rect(const Rect& rect, const View& view, RectEdge preferred_edge) const;
        /**
     * @brief Returns the `standardShareMenuItem` property of `NSSharingServicePicker`.
     * @details Returns a menu item suitable to display the picker for the given items.
     * @return The converted Objective-C result.
     */
        MenuItem standard_share_menu_item() const;
        /// @brief Signal for the delegate/data-source method behind `sharing_services_for_items_proposed_sharing_services`; connect a callback with `sharing_services_for_items_proposed_sharing_services().connect(...)`.
        Signal<SharingServicePicker, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)> sharing_services_for_items_proposed_sharing_services() const
        {
            return Signal<SharingServicePicker, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)>(handle(), "sharing_services_for_items_proposed_sharing_services");
        }
        /// @brief Signal for the delegate/data-source method behind `delegate_for_sharing_service`; connect a callback with `delegate_for_sharing_service().connect(...)`.
        Signal<SharingServicePicker, Object(SharingService)> delegate_for_sharing_service() const
        {
            return Signal<SharingServicePicker, Object(SharingService)>(handle(), "delegate_for_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `did_choose_sharing_service`; connect a callback with `did_choose_sharing_service().connect(...)`.
        Signal<SharingServicePicker, void(SharingService)> did_choose_sharing_service() const
        {
            return Signal<SharingServicePicker, void(SharingService)>(handle(), "did_choose_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `collaboration_mode_restrictions`; connect a callback with `collaboration_mode_restrictions().connect(...)`.
        Signal<SharingServicePicker, std::vector<SharingCollaborationModeRestriction>()> collaboration_mode_restrictions() const
        {
            return Signal<SharingServicePicker, std::vector<SharingCollaborationModeRestriction>()>(handle(), "collaboration_mode_restrictions");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
