#include "generated/file_promise_provider.h"
#include "internal.h"

@interface AKFilePromiseProviderDelegate : NSObject <NSFilePromiseProviderDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKFilePromiseProviderDelegate

- (NSString*)filePromiseProvider:(NSFilePromiseProvider*)filePromiseProvider fileNameForType:(NSString*)fileType
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FilePromiseProvider, std::string(std::string)>::emit((__bridge void*)strongHost, "file_name_for_type", cocoon::internal::from(fileType));
    return cocoon::internal::to(__r);
}

- (void)filePromiseProvider:(NSFilePromiseProvider*)filePromiseProvider writePromiseToURL:(NSURL*)url completionHandler:(void (^)(NSError*))completionHandler
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::FilePromiseProvider, void(cocoon::URL, std::function<void(cocoon::Error)>)>::emit((__bridge void*)strongHost, "write_promise_to_url_completion_handler", cocoon::internal::wrap<cocoon::URL>(url), [&]() -> std::function<void(cocoon::Error)>
                                                                                                             {
                                                                                                                 auto blk = (void (^)(::NSError*))(completionHandler);
                                                                                                                 if (!blk)
                                                                                                                 {
                                                                                                                     return {};
                                                                                                                 }
                                                                                                                 return [blk](cocoon::Error a279_0) -> void
                                                                                                                 {
                                                                                                                     blk(cocoon::internal::native<::NSError>(a279_0));
                                                                                                                 };
                                                                                                             }());
}

- (NSOperationQueue*)operationQueueForFilePromiseProvider:(NSFilePromiseProvider*)filePromiseProvider
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::FilePromiseProvider, cocoon::OperationQueue()>::emit((__bridge void*)strongHost, "operation_queue_for_file_promise_provider");
    return cocoon::internal::native<::NSOperationQueue>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(filePromiseProvider:fileNameForType:))
    {
        return strongHost && cocoon::Signal<cocoon::FilePromiseProvider, std::string(std::string)>::connected((__bridge void*)strongHost, "file_name_for_type");
    }
    if (selector == @selector(filePromiseProvider:writePromiseToURL:completionHandler:))
    {
        return strongHost && cocoon::Signal<cocoon::FilePromiseProvider, void(cocoon::URL, std::function<void(cocoon::Error)>)>::connected((__bridge void*)strongHost, "write_promise_to_url_completion_handler");
    }
    if (selector == @selector(operationQueueForFilePromiseProvider:))
    {
        return strongHost && cocoon::Signal<cocoon::FilePromiseProvider, cocoon::OperationQueue()>::connected((__bridge void*)strongHost, "operation_queue_for_file_promise_provider");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    FilePromiseProvider::FilePromiseProvider(const std::string& file_type, const Object& delegate) : FilePromiseProvider(Adopt{cocoon::internal::retain([[::NSFilePromiseProvider alloc] initWithFileType:cocoon::internal::to(file_type) delegate:cocoon::internal::native_id(delegate)])})
    {
        FilePromiseProvider::install_delegate_delegate_(handle());
    }

    FilePromiseProvider::FilePromiseProvider() : FilePromiseProvider(Adopt{cocoon::internal::retain([[::NSFilePromiseProvider alloc] init])})
    {
        FilePromiseProvider::install_delegate_delegate_(handle());
    }

    FilePromiseProvider::FilePromiseProvider(std::nullptr_t) : Object(nullptr)
    {
    }

    FilePromiseProvider::FilePromiseProvider(Adopt adopt) : Object(adopt)
    {
    }

    std::string FilePromiseProvider::file_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFilePromiseProvider>(this) fileType]);
    }

    void FilePromiseProvider::set_file_type(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFilePromiseProvider>(this) setFileType:cocoon::internal::to(value)];
    }

    Object FilePromiseProvider::user_info() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSFilePromiseProvider>(this) userInfo]);
    }

    void FilePromiseProvider::set_user_info(const Object& value) const
    {
        [cocoon::internal::ns<::NSFilePromiseProvider>(this) setUserInfo:cocoon::internal::native_id(value)];
    }

    void FilePromiseProvider::install_delegate_delegate_(void* native)
    {
        ::NSFilePromiseProvider* host = (__bridge ::NSFilePromiseProvider*)native;
        AKFilePromiseProviderDelegate* delegate = [[AKFilePromiseProviderDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSFilePromiseProvider* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSFilePromiseProvider* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
