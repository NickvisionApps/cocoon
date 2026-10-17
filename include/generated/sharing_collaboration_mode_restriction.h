#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSSharingCollaborationModeRestriction` (AppKit).
     * @details Specifies whether a specific type of sharing should be disabled in the share picker, and if so, whether a reason should be provided for the disablement. If a reason is provided, the corresponding mode will show up as an option, but an alert explaining why it is disabled will show if it is chosen, and the mode will switch back to the supported one. Optionally, an extra alert button can be provided for a "recovery suggestion". This can give a user a way to fix whatever is causing this type of sharing to be disabled. If no reason is provided, the corresponding mode will not show up as an option.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SharingCollaborationModeRestriction sharing_collaboration_mode_restriction{cocoon::SharingCollaborationMode::SendCopy};
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssharingcollaborationmoderestriction
     */
    class SharingCollaborationModeRestriction : public Object
    {
    public:
        /// @brief Creates a new `NSSharingCollaborationModeRestriction` instance and returns a handle to it.
        explicit SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode);
        /// @brief Creates a new `NSSharingCollaborationModeRestriction` instance and returns a handle to it.
        explicit SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message);
        /// @brief Creates a new `NSSharingCollaborationModeRestriction` instance and returns a handle to it.
        explicit SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message, const std::string& alert_dismiss_button_title);
        /// @brief Creates a new `NSSharingCollaborationModeRestriction` instance and returns a handle to it.
        explicit SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message, const std::string& alert_dismiss_button_title, const std::string& alert_recovery_suggestion_button_title, const URL& alert_recovery_suggestion_button_launch_url);
        SharingCollaborationModeRestriction();
        /// @brief Creates a null handle that refers to no native object.
        SharingCollaborationModeRestriction(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SharingCollaborationModeRestriction(Adopt adopt);
        /**
     * @brief Returns the `alertDismissButtonTitle` property of `NSSharingCollaborationModeRestriction`.
     * @details The label on the alert button which will simply confirm that the alert was viewed and dismiss it Defaults to "OK"
     * @return The converted Objective-C result.
     */
        std::string alert_dismiss_button_title() const;
        /**
     * @brief Returns the `alertMessage` property of `NSSharingCollaborationModeRestriction`.
     * @details The message of the alert if a reason for disabling is provided
     * @return The converted Objective-C result.
     */
        std::string alert_message() const;
        /**
     * @brief Returns the `alertRecoverySuggestionButtonLaunchURL` property of `NSSharingCollaborationModeRestriction`.
     * @details The URL that is opened when the user selects the recovery suggestion, if any
     * @return The converted Objective-C result.
     */
        URL alert_recovery_suggestion_button_launch_url() const;
        /**
     * @brief Returns the `alertRecoverySuggestionButtonTitle` property of `NSSharingCollaborationModeRestriction`.
     * @details The label on the recovery suggestion button if it is provided
     * @return The converted Objective-C result.
     */
        std::string alert_recovery_suggestion_button_title() const;
        /**
     * @brief Returns the `alertTitle` property of `NSSharingCollaborationModeRestriction`.
     * @details The title of the alert if a reason for disabling is provided
     * @return The converted Objective-C result.
     */
        std::string alert_title() const;
        /**
     * @brief Returns the `disabledMode` property of `NSSharingCollaborationModeRestriction`.
     * @details The type of sharing which should be disabled
     * @return The converted Objective-C result.
     */
        SharingCollaborationMode disabled_mode() const;
    };
}
