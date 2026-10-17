#include "generated/help_manager.h"
#include "internal.h"

namespace cocoon
{
    HelpManager::HelpManager() : HelpManager(Adopt{cocoon::internal::retain([[::NSHelpManager alloc] init])})
    {
    }

    HelpManager::HelpManager(std::nullptr_t) : Object(nullptr)
    {
    }

    HelpManager::HelpManager(Adopt adopt) : Object(adopt)
    {
    }

    AttributedString HelpManager::context_help_for_object(const Object& object) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSHelpManager>(this) contextHelpForObject:cocoon::internal::native_id(object)]);
    }

    void HelpManager::find_string(const std::string& query, const std::string& book) const
    {
        [cocoon::internal::ns<::NSHelpManager>(this) findString:cocoon::internal::to(query) inBook:cocoon::internal::to(book)];
    }

    void HelpManager::open_help_anchor(const std::string& anchor, const std::string& book) const
    {
        [cocoon::internal::ns<::NSHelpManager>(this) openHelpAnchor:cocoon::internal::to(anchor) inBook:cocoon::internal::to(book)];
    }

    bool HelpManager::register_books_in_bundle(const Bundle& bundle) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHelpManager>(this) registerBooksInBundle:cocoon::internal::native<::NSBundle>(bundle)]);
    }

    void HelpManager::remove_context_help_for_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSHelpManager>(this) removeContextHelpForObject:cocoon::internal::native_id(object)];
    }

    void HelpManager::set_context_help(const AttributedString& attr_string, const Object& object) const
    {
        [cocoon::internal::ns<::NSHelpManager>(this) setContextHelp:cocoon::internal::native<::NSAttributedString>(attr_string) forObject:cocoon::internal::native_id(object)];
    }

    bool HelpManager::show_context_help_for_object(const Object& object, const Point& pt) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSHelpManager>(this) showContextHelpForObject:cocoon::internal::native_id(object) locationHint:cocoon::internal::to(pt)]);
    }

    bool HelpManager::is_context_help_mode_active()
    {
        return static_cast<bool>([::NSHelpManager isContextHelpModeActive]);
    }

    void HelpManager::set_context_help_mode_active(bool value)
    {
        [::NSHelpManager setContextHelpModeActive:static_cast<::BOOL>(value)];
    }

    HelpManager HelpManager::shared_help_manager()
    {
        return cocoon::internal::wrap<HelpManager>([::NSHelpManager sharedHelpManager]);
    }
}
