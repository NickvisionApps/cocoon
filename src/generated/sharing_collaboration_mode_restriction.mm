#include "generated/sharing_collaboration_mode_restriction.h"
#include "internal.h"

namespace cocoon
{
    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode) : SharingCollaborationModeRestriction(Adopt{cocoon::internal::retain([[::NSSharingCollaborationModeRestriction alloc] initWithDisabledMode:static_cast<::NSSharingCollaborationMode>(disabled_mode)])})
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message) : SharingCollaborationModeRestriction(Adopt{cocoon::internal::retain([[::NSSharingCollaborationModeRestriction alloc] initWithDisabledMode:static_cast<::NSSharingCollaborationMode>(disabled_mode) alertTitle:cocoon::internal::to(alert_title) alertMessage:cocoon::internal::to(alert_message)])})
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message, const std::string& alert_dismiss_button_title) : SharingCollaborationModeRestriction(Adopt{cocoon::internal::retain([[::NSSharingCollaborationModeRestriction alloc] initWithDisabledMode:static_cast<::NSSharingCollaborationMode>(disabled_mode) alertTitle:cocoon::internal::to(alert_title) alertMessage:cocoon::internal::to(alert_message) alertDismissButtonTitle:cocoon::internal::to(alert_dismiss_button_title)])})
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(SharingCollaborationMode disabled_mode, const std::string& alert_title, const std::string& alert_message, const std::string& alert_dismiss_button_title, const std::string& alert_recovery_suggestion_button_title, const URL& alert_recovery_suggestion_button_launch_url) : SharingCollaborationModeRestriction(Adopt{cocoon::internal::retain([[::NSSharingCollaborationModeRestriction alloc] initWithDisabledMode:static_cast<::NSSharingCollaborationMode>(disabled_mode) alertTitle:cocoon::internal::to(alert_title) alertMessage:cocoon::internal::to(alert_message) alertDismissButtonTitle:cocoon::internal::to(alert_dismiss_button_title) alertRecoverySuggestionButtonTitle:cocoon::internal::to(alert_recovery_suggestion_button_title) alertRecoverySuggestionButtonLaunchURL:cocoon::internal::native<::NSURL>(alert_recovery_suggestion_button_launch_url)])})
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction() : Object(nullptr)
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(std::nullptr_t) : Object(nullptr)
    {
    }

    SharingCollaborationModeRestriction::SharingCollaborationModeRestriction(Adopt adopt) : Object(adopt)
    {
    }

    std::string SharingCollaborationModeRestriction::alert_dismiss_button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) alertDismissButtonTitle]);
    }

    std::string SharingCollaborationModeRestriction::alert_message() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) alertMessage]);
    }

    URL SharingCollaborationModeRestriction::alert_recovery_suggestion_button_launch_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) alertRecoverySuggestionButtonLaunchURL]);
    }

    std::string SharingCollaborationModeRestriction::alert_recovery_suggestion_button_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) alertRecoverySuggestionButtonTitle]);
    }

    std::string SharingCollaborationModeRestriction::alert_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) alertTitle]);
    }

    SharingCollaborationMode SharingCollaborationModeRestriction::disabled_mode() const
    {
        return static_cast<SharingCollaborationMode>([cocoon::internal::ns<::NSSharingCollaborationModeRestriction>(this) disabledMode]);
    }
}
