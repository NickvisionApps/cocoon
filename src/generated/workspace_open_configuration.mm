#include "generated/workspace_open_configuration.h"
#include "internal.h"

namespace cocoon
{
    WorkspaceOpenConfiguration::WorkspaceOpenConfiguration() : WorkspaceOpenConfiguration(Adopt{cocoon::internal::retain([[::NSWorkspaceOpenConfiguration alloc] init])})
    {
    }

    WorkspaceOpenConfiguration::WorkspaceOpenConfiguration(std::nullptr_t) : Object(nullptr)
    {
    }

    WorkspaceOpenConfiguration::WorkspaceOpenConfiguration(Adopt adopt) : Object(adopt)
    {
    }

    WorkspaceOpenConfiguration WorkspaceOpenConfiguration::configuration()
    {
        return cocoon::internal::wrap<WorkspaceOpenConfiguration>([::NSWorkspaceOpenConfiguration configuration]);
    }

    bool WorkspaceOpenConfiguration::activates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) activates]);
    }

    void WorkspaceOpenConfiguration::set_activates(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setActivates:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::adds_to_recent_items() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) addsToRecentItems]);
    }

    void WorkspaceOpenConfiguration::set_adds_to_recent_items(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setAddsToRecentItems:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::allows_running_application_substitution() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) allowsRunningApplicationSubstitution]);
    }

    void WorkspaceOpenConfiguration::set_allows_running_application_substitution(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setAllowsRunningApplicationSubstitution:static_cast<::BOOL>(value)];
    }

    AppleEventDescriptor WorkspaceOpenConfiguration::apple_event() const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) appleEvent]);
    }

    void WorkspaceOpenConfiguration::set_apple_event(const AppleEventDescriptor& value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setAppleEvent:cocoon::internal::native<::NSAppleEventDescriptor>(value)];
    }

    int WorkspaceOpenConfiguration::architecture() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) architecture]);
    }

    void WorkspaceOpenConfiguration::set_architecture(int value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setArchitecture:static_cast<::cpu_type_t>(value)];
    }

    std::vector<std::string> WorkspaceOpenConfiguration::arguments() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) arguments], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void WorkspaceOpenConfiguration::set_arguments(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setArguments:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::to(e);
                                                                                                            })];
    }

    bool WorkspaceOpenConfiguration::creates_new_application_instance() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) createsNewApplicationInstance]);
    }

    void WorkspaceOpenConfiguration::set_creates_new_application_instance(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setCreatesNewApplicationInstance:static_cast<::BOOL>(value)];
    }

    std::map<std::string, std::string> WorkspaceOpenConfiguration::environment() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) environment], [](id k) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                     },
                                                                                     [](id v) -> std::string
                                                                                     {
                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                     });
    }

    void WorkspaceOpenConfiguration::set_environment(const std::map<std::string, std::string>& value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setEnvironment:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::to(k);
                                                                                                                   },
                                                                                                                   [](const std::string& v) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::to(v);
                                                                                                                   })];
    }

    bool WorkspaceOpenConfiguration::is_for_printing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) isForPrinting]);
    }

    void WorkspaceOpenConfiguration::set_for_printing(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setForPrinting:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::hides() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) hides]);
    }

    void WorkspaceOpenConfiguration::set_hides(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setHides:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::hides_others() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) hidesOthers]);
    }

    void WorkspaceOpenConfiguration::set_hides_others(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setHidesOthers:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::prompts_user_if_needed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) promptsUserIfNeeded]);
    }

    void WorkspaceOpenConfiguration::set_prompts_user_if_needed(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setPromptsUserIfNeeded:static_cast<::BOOL>(value)];
    }

    bool WorkspaceOpenConfiguration::requires_universal_links() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) requiresUniversalLinks]);
    }

    void WorkspaceOpenConfiguration::set_requires_universal_links(bool value) const
    {
        [cocoon::internal::ns<::NSWorkspaceOpenConfiguration>(this) setRequiresUniversalLinks:static_cast<::BOOL>(value)];
    }
}
