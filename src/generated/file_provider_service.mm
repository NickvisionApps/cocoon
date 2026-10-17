#include "generated/file_provider_service.h"
#include "internal.h"

namespace cocoon
{
    FileProviderService::FileProviderService() : FileProviderService(Adopt{cocoon::internal::retain([[::NSFileProviderService alloc] init])})
    {
    }

    FileProviderService::FileProviderService(std::nullptr_t) : Object(nullptr)
    {
    }

    FileProviderService::FileProviderService(Adopt adopt) : Object(adopt)
    {
    }

    void FileProviderService::get_file_provider_connection_with_completion_handler(std::function<void(XPCConnection, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSFileProviderService>(this) getFileProviderConnectionWithCompletionHandler:(completion_handler ? (void (^)(::NSXPCConnection*, ::NSError*)) ^ void(::NSXPCConnection * a154_0, ::NSError * a154_1) { completion_handler(cocoon::internal::wrap<XPCConnection>(a154_0), cocoon::internal::wrap<Error>(a154_1)); } : (void (^)(::NSXPCConnection*, ::NSError*))nil)];
    }

    std::string FileProviderService::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileProviderService>(this) name]);
    }
}
