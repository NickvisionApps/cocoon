#include "generated/extension_context.h"
#include "internal.h"

namespace cocoon
{
    ExtensionContext::ExtensionContext() : ExtensionContext(Adopt{cocoon::internal::retain([[::NSExtensionContext alloc] init])})
    {
    }

    ExtensionContext::ExtensionContext(std::nullptr_t) : Object(nullptr)
    {
    }

    ExtensionContext::ExtensionContext(Adopt adopt) : Object(adopt)
    {
    }

    void ExtensionContext::cancel_request_with_error(const Error& error) const
    {
        [cocoon::internal::ns<::NSExtensionContext>(this) cancelRequestWithError:cocoon::internal::native<::NSError>(error)];
    }

    void ExtensionContext::complete_request_returning_items(const std::vector<Object>& items, std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSExtensionContext>(this) completeRequestReturningItems:cocoon::internal::to_array(items, [](const Object& e) -> id
                                                                                       {
                                                                                           return cocoon::internal::native_id(e);
                                                                                       })
                                                        completionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a134_0) { completion_handler(static_cast<bool>(a134_0)); } : (void (^)(BOOL))nil)];
    }

    void ExtensionContext::open_url(const URL& url, std::function<void(bool)> completion_handler) const
    {
        [cocoon::internal::ns<::NSExtensionContext>(this) openURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(BOOL)) ^ void(::BOOL a135_0) { completion_handler(static_cast<bool>(a135_0)); } : (void (^)(BOOL))nil)];
    }

    std::vector<Object> ExtensionContext::input_items() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSExtensionContext>(this) inputItems], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }
}
