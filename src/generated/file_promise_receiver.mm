#include "generated/file_promise_receiver.h"
#include "internal.h"

namespace cocoon
{
    FilePromiseReceiver::FilePromiseReceiver() : FilePromiseReceiver(Adopt{cocoon::internal::retain([[::NSFilePromiseReceiver alloc] init])})
    {
    }

    FilePromiseReceiver::FilePromiseReceiver(std::nullptr_t) : Object(nullptr)
    {
    }

    FilePromiseReceiver::FilePromiseReceiver(Adopt adopt) : Object(adopt)
    {
    }

    void FilePromiseReceiver::receive_promised_files_at_destination(const URL& destination_dir, const std::vector<std::pair<Object, Object>>& options, const OperationQueue& operation_queue, std::function<void(URL, Error)> reader) const
    {
        [cocoon::internal::ns<::NSFilePromiseReceiver>(this) receivePromisedFilesAtDestination:cocoon::internal::native<::NSURL>(destination_dir)
                                                                                       options:cocoon::internal::to_dictionary(options, [](const Object& k) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native_id(k);
                                                                                                                               },
                                                                                                                               [](const Object& v) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                               })
                                                                                operationQueue:cocoon::internal::native<::NSOperationQueue>(operation_queue)
                                                                                        reader:(reader ? (void (^)(::NSURL*, ::NSError*)) ^ void(::NSURL * a60_0, ::NSError * a60_1) { reader(cocoon::internal::wrap<URL>(a60_0), cocoon::internal::wrap<Error>(a60_1)); } : (void (^)(::NSURL*, ::NSError*))nil)];
    }

    std::vector<std::string> FilePromiseReceiver::file_names() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFilePromiseReceiver>(this) fileNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> FilePromiseReceiver::file_types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSFilePromiseReceiver>(this) fileTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> FilePromiseReceiver::readable_dragged_types()
    {
        return cocoon::internal::from_array<std::string>([::NSFilePromiseReceiver readableDraggedTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }
}
