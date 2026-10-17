#include "generated/url_session.h"
#include "internal.h"

namespace cocoon
{
    URLSession::URLSession() : URLSession(Adopt{cocoon::internal::retain([[::NSURLSession alloc] init])})
    {
    }

    URLSession::URLSession(std::nullptr_t) : Object(nullptr)
    {
    }

    URLSession::URLSession(Adopt adopt) : Object(adopt)
    {
    }

    URLSessionDataTask URLSession::data_task_with_request(const URLRequest& request) const
    {
        return cocoon::internal::wrap<URLSessionDataTask>([cocoon::internal::ns<::NSURLSession>(this) dataTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    URLSessionDataTask URLSession::data_task_with_request(const URLRequest& request, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionDataTask>([cocoon::internal::ns<::NSURLSession>(this) dataTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSURLResponse*, ::NSError*)) ^ void(NSData * a232_0, ::NSURLResponse * a232_1, ::NSError * a232_2) { completion_handler(cocoon::internal::from_data(a232_0), cocoon::internal::wrap<URLResponse>(a232_1), cocoon::internal::wrap<Error>(a232_2)); } : (void (^)(::NSData*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionDataTask URLSession::data_task_with_url(const URL& url) const
    {
        return cocoon::internal::wrap<URLSessionDataTask>([cocoon::internal::ns<::NSURLSession>(this) dataTaskWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    URLSessionDataTask URLSession::data_task_with_url(const URL& url, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionDataTask>([cocoon::internal::ns<::NSURLSession>(this) dataTaskWithURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSURLResponse*, ::NSError*)) ^ void(NSData * a233_0, ::NSURLResponse * a233_1, ::NSError * a233_2) { completion_handler(cocoon::internal::from_data(a233_0), cocoon::internal::wrap<URLResponse>(a233_1), cocoon::internal::wrap<Error>(a233_2)); } : (void (^)(::NSData*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_request(const URLRequest& request) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_request(const URLRequest& request, std::function<void(URL, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) completionHandler:(completion_handler ? (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*)) ^ void(::NSURL * a234_0, ::NSURLResponse * a234_1, ::NSError * a234_2) { completion_handler(cocoon::internal::wrap<URL>(a234_0), cocoon::internal::wrap<URLResponse>(a234_1), cocoon::internal::wrap<Error>(a234_2)); } : (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithResumeData:cocoon::internal::to_data(resume_data)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_resume_data(const std::vector<std::uint8_t>& resume_data, std::function<void(URL, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithResumeData:cocoon::internal::to_data(resume_data) completionHandler:(completion_handler ? (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*)) ^ void(::NSURL * a235_0, ::NSURLResponse * a235_1, ::NSError * a235_2) { completion_handler(cocoon::internal::wrap<URL>(a235_0), cocoon::internal::wrap<URLResponse>(a235_1), cocoon::internal::wrap<Error>(a235_2)); } : (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_url(const URL& url) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    URLSessionDownloadTask URLSession::download_task_with_url(const URL& url, std::function<void(URL, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionDownloadTask>([cocoon::internal::ns<::NSURLSession>(this) downloadTaskWithURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*)) ^ void(::NSURL * a236_0, ::NSURLResponse * a236_1, ::NSError * a236_2) { completion_handler(cocoon::internal::wrap<URL>(a236_0), cocoon::internal::wrap<URLResponse>(a236_1), cocoon::internal::wrap<Error>(a236_2)); } : (void (^)(::NSURL*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    void URLSession::finish_tasks_and_invalidate() const
    {
        [cocoon::internal::ns<::NSURLSession>(this) finishTasksAndInvalidate];
    }

    void URLSession::flush_with_completion_handler(std::function<void()> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSession>(this) flushWithCompletionHandler:(completion_handler ? (void (^)(void)) ^ void() { completion_handler(); } : (void (^)(void))nil)];
    }

    void URLSession::get_all_tasks_with_completion_handler(std::function<void(std::vector<URLSessionTask>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSession>(this) getAllTasksWithCompletionHandler:(completion_handler ? (void (^)(NSArray<__kindof NSURLSessionTask*>*)) ^ void(NSArray * a238_0) { completion_handler(cocoon::internal::from_array<URLSessionTask>(a238_0, [](id e) -> URLSessionTask
                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                           return cocoon::internal::wrap<URLSessionTask>((::NSURLSessionTask*)e);
                                                                                                                                                                                                                                                       })); } : (void (^)(NSArray<__kindof NSURLSessionTask*>*))nil)];
    }

    void URLSession::get_tasks_with_completion_handler(std::function<void(std::vector<URLSessionDataTask>, std::vector<URLSessionUploadTask>, std::vector<URLSessionDownloadTask>)> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSession>(this) getTasksWithCompletionHandler:(completion_handler ? (void (^)(NSArray<NSURLSessionDataTask*>*, NSArray<NSURLSessionUploadTask*>*, NSArray<NSURLSessionDownloadTask*>*)) ^ void(NSArray * a239_0, NSArray * a239_1, NSArray * a239_2) { completion_handler(cocoon::internal::from_array<URLSessionDataTask>(a239_0, [](id e) -> URLSessionDataTask
                                                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<URLSessionDataTask>((::NSURLSessionDataTask*)e);
                                                                                                                                                                                                                                                                                                                                                               }),
                                                                                                                                                                                                                                                                                                              cocoon::internal::from_array<URLSessionUploadTask>(a239_1, [](id e) -> URLSessionUploadTask
                                                                                                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                                                                                                     return cocoon::internal::wrap<URLSessionUploadTask>((::NSURLSessionUploadTask*)e);
                                                                                                                                                                                                                                                                                                                                                                 }),
                                                                                                                                                                                                                                                                                                              cocoon::internal::from_array<URLSessionDownloadTask>(a239_2, [](id e) -> URLSessionDownloadTask
                                                                                                                                                                                                                                                                                                                                                                   {
                                                                                                                                                                                                                                                                                                                                                                       return cocoon::internal::wrap<URLSessionDownloadTask>((::NSURLSessionDownloadTask*)e);
                                                                                                                                                                                                                                                                                                                                                                   })); } : (void (^)(NSArray<NSURLSessionDataTask*>*, NSArray<NSURLSessionUploadTask*>*, NSArray<NSURLSessionDownloadTask*>*))nil)];
    }

    void URLSession::invalidate_and_cancel() const
    {
        [cocoon::internal::ns<::NSURLSession>(this) invalidateAndCancel];
    }

    void URLSession::reset_with_completion_handler(std::function<void()> completion_handler) const
    {
        [cocoon::internal::ns<::NSURLSession>(this) resetWithCompletionHandler:(completion_handler ? (void (^)(void)) ^ void() { completion_handler(); } : (void (^)(void))nil)];
    }

    URLSession URLSession::session_with_configuration(const URLSessionConfiguration& configuration)
    {
        return cocoon::internal::wrap<URLSession>([::NSURLSession sessionWithConfiguration:cocoon::internal::native<::NSURLSessionConfiguration>(configuration)]);
    }

    URLSession URLSession::session_with_configuration(const URLSessionConfiguration& configuration, const Object& delegate, const OperationQueue& queue)
    {
        return cocoon::internal::wrap<URLSession>([::NSURLSession sessionWithConfiguration:cocoon::internal::native<::NSURLSessionConfiguration>(configuration) delegate:cocoon::internal::native_id(delegate) delegateQueue:cocoon::internal::native<::NSOperationQueue>(queue)]);
    }

    URLSessionStreamTask URLSession::stream_task_with_host_name(const std::string& hostname, std::int64_t port) const
    {
        return cocoon::internal::wrap<URLSessionStreamTask>([cocoon::internal::ns<::NSURLSession>(this) streamTaskWithHostName:cocoon::internal::to(hostname) port:static_cast<::NSInteger>(port)]);
    }

    URLSessionStreamTask URLSession::stream_task_with_net_service(const NetService& service) const
    {
        return cocoon::internal::wrap<URLSessionStreamTask>([cocoon::internal::ns<::NSURLSession>(this) streamTaskWithNetService:cocoon::internal::native<::NSNetService>(service)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) fromData:cocoon::internal::to_data(body_data)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_request(const URLRequest& request, const std::vector<std::uint8_t>& body_data, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) fromData:cocoon::internal::to_data(body_data) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSURLResponse*, ::NSError*)) ^ void(NSData * a241_0, ::NSURLResponse * a241_1, ::NSError * a241_2) { completion_handler(cocoon::internal::from_data(a241_0), cocoon::internal::wrap<URLResponse>(a241_1), cocoon::internal::wrap<Error>(a241_2)); } : (void (^)(::NSData*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_request(const URLRequest& request, const URL& file_url) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) fromFile:cocoon::internal::native<::NSURL>(file_url)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_request(const URLRequest& request, const URL& file_url, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request) fromFile:cocoon::internal::native<::NSURL>(file_url) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSURLResponse*, ::NSError*)) ^ void(NSData * a242_0, ::NSURLResponse * a242_1, ::NSError * a242_2) { completion_handler(cocoon::internal::from_data(a242_0), cocoon::internal::wrap<URLResponse>(a242_1), cocoon::internal::wrap<Error>(a242_2)); } : (void (^)(::NSData*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_resume_data(const std::vector<std::uint8_t>& resume_data) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithResumeData:cocoon::internal::to_data(resume_data)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_resume_data(const std::vector<std::uint8_t>& resume_data, std::function<void(std::vector<std::uint8_t>, URLResponse, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithResumeData:cocoon::internal::to_data(resume_data) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSURLResponse*, ::NSError*)) ^ void(NSData * a243_0, ::NSURLResponse * a243_1, ::NSError * a243_2) { completion_handler(cocoon::internal::from_data(a243_0), cocoon::internal::wrap<URLResponse>(a243_1), cocoon::internal::wrap<Error>(a243_2)); } : (void (^)(::NSData*, ::NSURLResponse*, ::NSError*))nil)]);
    }

    URLSessionUploadTask URLSession::upload_task_with_streamed_request(const URLRequest& request) const
    {
        return cocoon::internal::wrap<URLSessionUploadTask>([cocoon::internal::ns<::NSURLSession>(this) uploadTaskWithStreamedRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    URLSessionWebSocketTask URLSession::web_socket_task_with_request(const URLRequest& request) const
    {
        return cocoon::internal::wrap<URLSessionWebSocketTask>([cocoon::internal::ns<::NSURLSession>(this) webSocketTaskWithRequest:cocoon::internal::native<::NSURLRequest>(request)]);
    }

    URLSessionWebSocketTask URLSession::web_socket_task_with_url(const URL& url) const
    {
        return cocoon::internal::wrap<URLSessionWebSocketTask>([cocoon::internal::ns<::NSURLSession>(this) webSocketTaskWithURL:cocoon::internal::native<::NSURL>(url)]);
    }

    URLSessionWebSocketTask URLSession::web_socket_task_with_url(const URL& url, const std::vector<std::string>& protocols) const
    {
        return cocoon::internal::wrap<URLSessionWebSocketTask>([cocoon::internal::ns<::NSURLSession>(this) webSocketTaskWithURL:cocoon::internal::native<::NSURL>(url)
                                                                                                                      protocols:cocoon::internal::to_array(protocols, [](const std::string& e) -> id
                                                                                                                                                           {
                                                                                                                                                               return cocoon::internal::to(e);
                                                                                                                                                           })]);
    }

    URLSessionConfiguration URLSession::configuration() const
    {
        return cocoon::internal::wrap<URLSessionConfiguration>([cocoon::internal::ns<::NSURLSession>(this) configuration]);
    }

    OperationQueue URLSession::delegate_queue() const
    {
        return cocoon::internal::wrap<OperationQueue>([cocoon::internal::ns<::NSURLSession>(this) delegateQueue]);
    }

    std::string URLSession::session_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSURLSession>(this) sessionDescription]);
    }

    void URLSession::set_session_description(const std::string& value) const
    {
        [cocoon::internal::ns<::NSURLSession>(this) setSessionDescription:cocoon::internal::to(value)];
    }

    URLSession URLSession::shared_session()
    {
        return cocoon::internal::wrap<URLSession>([::NSURLSession sharedSession]);
    }
}
