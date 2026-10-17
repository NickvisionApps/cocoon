#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/toolbar_item.h"
#include "types.h"

namespace cocoon
{
    class SharingCollaborationModeRestriction;
    class SharingService;

    /**
     * @brief C++ handle for the Objective-C class `NSSharingServicePickerToolbarItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ToolbarItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SharingServicePickerToolbarItem sharing_service_picker_toolbar_item;
     * sharing_service_picker_toolbar_item.did_choose_sharing_service().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SharingServicePickerToolbarItem sharing_service_picker_toolbar_item{};
     * sharing_service_picker_toolbar_item.did_choose_sharing_service().connect([](cocoon::SharingService a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssharingservicepickertoolbaritem
     */
    class SharingServicePickerToolbarItem : public ToolbarItem
    {
    public:
        /// @brief Creates a new `NSSharingServicePickerToolbarItem` instance and returns a handle to it.
        explicit SharingServicePickerToolbarItem();
        /// @brief Creates a null handle that refers to no native object.
        SharingServicePickerToolbarItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SharingServicePickerToolbarItem(Adopt adopt);
        /// @brief Signal for the delegate/data-source method behind `sharing_services_for_items_proposed_sharing_services`; connect a callback with `sharing_services_for_items_proposed_sharing_services().connect(...)`.
        Signal<SharingServicePickerToolbarItem, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)> sharing_services_for_items_proposed_sharing_services() const
        {
            return Signal<SharingServicePickerToolbarItem, std::vector<SharingService>(std::vector<Object>, std::vector<SharingService>)>(handle(), "sharing_services_for_items_proposed_sharing_services");
        }
        /// @brief Signal for the delegate/data-source method behind `delegate_for_sharing_service`; connect a callback with `delegate_for_sharing_service().connect(...)`.
        Signal<SharingServicePickerToolbarItem, Object(SharingService)> delegate_for_sharing_service() const
        {
            return Signal<SharingServicePickerToolbarItem, Object(SharingService)>(handle(), "delegate_for_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `did_choose_sharing_service`; connect a callback with `did_choose_sharing_service().connect(...)`.
        Signal<SharingServicePickerToolbarItem, void(SharingService)> did_choose_sharing_service() const
        {
            return Signal<SharingServicePickerToolbarItem, void(SharingService)>(handle(), "did_choose_sharing_service");
        }
        /// @brief Signal for the delegate/data-source method behind `collaboration_mode_restrictions`; connect a callback with `collaboration_mode_restrictions().connect(...)`.
        Signal<SharingServicePickerToolbarItem, std::vector<SharingCollaborationModeRestriction>()> collaboration_mode_restrictions() const
        {
            return Signal<SharingServicePickerToolbarItem, std::vector<SharingCollaborationModeRestriction>()>(handle(), "collaboration_mode_restrictions");
        }
        /// @brief Signal for the delegate/data-source method behind `items_for_sharing_service_picker_toolbar_item`; connect a callback with `items_for_sharing_service_picker_toolbar_item().connect(...)`.
        Signal<SharingServicePickerToolbarItem, std::vector<Object>()> items_for_sharing_service_picker_toolbar_item() const
        {
            return Signal<SharingServicePickerToolbarItem, std::vector<Object>()>(handle(), "items_for_sharing_service_picker_toolbar_item");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
