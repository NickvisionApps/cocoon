#include "generated/apple_script.h"
#include "internal.h"

namespace cocoon
{
    AppleScript::AppleScript(const URL& url, std::map<std::string, Object>& error_info) : AppleScript(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                     {
                                                                                                                                         NSDictionary* __v_error_info = nil;
                                                                                                                                         id __r = [[::NSAppleScript alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url) error:&__v_error_info];
                                                                                                                                         error_info = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_error_info, [](id k) -> std::string
                                                                                                                                                                                                                       {
                                                                                                                                                                                                                           return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                       },
                                                                                                                                                                                                                       [](id v) -> Object
                                                                                                                                                                                                                       {
                                                                                                                                                                                                                           return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                       });
                                                                                                                                         return __r;
                                                                                                                                     }())})
    {
    }

    AppleScript::AppleScript(const std::string& source) : AppleScript(Adopt{cocoon::internal::retain([[::NSAppleScript alloc] initWithSource:cocoon::internal::to(source)])})
    {
    }

    AppleScript::AppleScript() : AppleScript(Adopt{cocoon::internal::retain([[::NSAppleScript alloc] init])})
    {
    }

    AppleScript::AppleScript(std::nullptr_t) : Object(nullptr)
    {
    }

    AppleScript::AppleScript(Adopt adopt) : Object(adopt)
    {
    }

    bool AppleScript::compile_and_return_error(std::map<std::string, Object>& error_info) const
    {
        NSDictionary* __v_error_info = nil;
        auto __r = [cocoon::internal::ns<::NSAppleScript>(this) compileAndReturnError:&__v_error_info];
        error_info = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_error_info, [](id k) -> std::string
                                                                                      {
                                                                                          return cocoon::internal::from((NSString*)k);
                                                                                      },
                                                                                      [](id v) -> Object
                                                                                      {
                                                                                          return cocoon::internal::wrap<Object>(v);
                                                                                      });
        return static_cast<bool>(__r);
    }

    AppleEventDescriptor AppleScript::execute_and_return_error(std::map<std::string, Object>& error_info) const
    {
        NSDictionary* __v_error_info = nil;
        auto __r = [cocoon::internal::ns<::NSAppleScript>(this) executeAndReturnError:&__v_error_info];
        error_info = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_error_info, [](id k) -> std::string
                                                                                      {
                                                                                          return cocoon::internal::from((NSString*)k);
                                                                                      },
                                                                                      [](id v) -> Object
                                                                                      {
                                                                                          return cocoon::internal::wrap<Object>(v);
                                                                                      });
        return cocoon::internal::wrap<AppleEventDescriptor>(__r);
    }

    AppleEventDescriptor AppleScript::execute_apple_event(const AppleEventDescriptor& event, std::map<std::string, Object>& error_info) const
    {
        NSDictionary* __v_error_info = nil;
        auto __r = [cocoon::internal::ns<::NSAppleScript>(this) executeAppleEvent:cocoon::internal::native<::NSAppleEventDescriptor>(event) error:&__v_error_info];
        error_info = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_error_info, [](id k) -> std::string
                                                                                      {
                                                                                          return cocoon::internal::from((NSString*)k);
                                                                                      },
                                                                                      [](id v) -> Object
                                                                                      {
                                                                                          return cocoon::internal::wrap<Object>(v);
                                                                                      });
        return cocoon::internal::wrap<AppleEventDescriptor>(__r);
    }

    bool AppleScript::is_compiled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAppleScript>(this) isCompiled]);
    }

    AttributedString AppleScript::rich_text_source() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSAppleScript>(this) richTextSource]);
    }

    std::string AppleScript::source() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAppleScript>(this) source]);
    }
}
