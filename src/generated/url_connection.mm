#include "generated/url_connection.h"
#include "internal.h"

namespace cocoon
{
    URLConnection::URLConnection() : URLConnection(Adopt{cocoon::internal::retain([[::NSURLConnection alloc] init])})
    {
    }

    URLConnection::URLConnection(std::nullptr_t) : Object(nullptr)
    {
    }

    URLConnection::URLConnection(Adopt adopt) : Object(adopt)
    {
    }

    bool URLConnection::can_handle_request(const URLRequest& request)
    {
        return static_cast<bool>([::NSURLConnection canHandleRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    void URLConnection::cancel() const
    {
        [cocoon::internal::ns<::NSURLConnection>(this) cancel];
    }

    void URLConnection::schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSURLConnection>(this) scheduleInRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    void URLConnection::send_asynchronous_request(const URLRequest& request, const OperationQueue& queue, std::function<void(URLResponse, std::vector<std::uint8_t>, Error)> handler)
    {
        [::NSURLConnection sendAsynchronousRequest:cocoon::internal::native<::NSURLRequest>(request) queue:cocoon::internal::native<::NSOperationQueue>(queue) completionHandler:(handler ? (void (^)(::NSURLResponse*, ::NSData*, ::NSError*)) ^ void(::NSURLResponse * a229_0, NSData * a229_1, ::NSError * a229_2) { handler(cocoon::internal::wrap<URLResponse>(a229_0), cocoon::internal::from_data(a229_1), cocoon::internal::wrap<Error>(a229_2)); } : (void (^)(::NSURLResponse*, ::NSData*, ::NSError*))nil)];
    }

    std::vector<std::uint8_t> URLConnection::send_synchronous_request(const URLRequest& request, URLResponse& response)
    {
        NSError* __error = nil;
        ::NSURLResponse* __v_response = nil;
        auto __r = [::NSURLConnection sendSynchronousRequest:cocoon::internal::native<::NSURLRequest>(request) returningResponse:&__v_response error:&__error];
        response = cocoon::internal::wrap<URLResponse>(__v_response);
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    void URLConnection::set_delegate_queue(const OperationQueue& queue) const
    {
        [cocoon::internal::ns<::NSURLConnection>(this) setDelegateQueue:cocoon::internal::native<::NSOperationQueue>(queue)];
    }

    void URLConnection::start() const
    {
        [cocoon::internal::ns<::NSURLConnection>(this) start];
    }

    void URLConnection::unschedule_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const
    {
        [cocoon::internal::ns<::NSURLConnection>(this) unscheduleFromRunLoop:cocoon::internal::native<::NSRunLoop>(a_run_loop) forMode:cocoon::internal::to(mode)];
    }

    URLRequest URLConnection::current_request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLConnection>(this) currentRequest]);
    }

    URLRequest URLConnection::original_request() const
    {
        return cocoon::internal::wrap<URLRequest>([cocoon::internal::ns<::NSURLConnection>(this) originalRequest]);
    }
}
