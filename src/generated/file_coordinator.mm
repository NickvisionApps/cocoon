#include "generated/file_coordinator.h"
#include "internal.h"

namespace cocoon
{
    FileCoordinator::FileCoordinator(const Object& file_presenter_or_nil) : FileCoordinator(Adopt{cocoon::internal::retain([[::NSFileCoordinator alloc] initWithFilePresenter:cocoon::internal::native_id(file_presenter_or_nil)])})
    {
    }

    FileCoordinator::FileCoordinator() : FileCoordinator(Adopt{cocoon::internal::retain([[::NSFileCoordinator alloc] init])})
    {
    }

    FileCoordinator::FileCoordinator(std::nullptr_t) : Object(nullptr)
    {
    }

    FileCoordinator::FileCoordinator(Adopt adopt) : Object(adopt)
    {
    }

    void FileCoordinator::add_file_presenter(const Object& file_presenter)
    {
        [::NSFileCoordinator addFilePresenter:cocoon::internal::native_id(file_presenter)];
    }

    void FileCoordinator::cancel() const
    {
        [cocoon::internal::ns<::NSFileCoordinator>(this) cancel];
    }

    void FileCoordinator::coordinate_access_with_intents(const std::vector<FileAccessIntent>& intents, const OperationQueue& queue, std::function<void(Error)> accessor) const
    {
        [cocoon::internal::ns<::NSFileCoordinator>(this) coordinateAccessWithIntents:cocoon::internal::to_array(intents, [](const FileAccessIntent& e) -> id
                                                                                    {
                                                                                        return cocoon::internal::native<::NSFileAccessIntent>(e);
                                                                                    })
                                                                 queue:cocoon::internal::native<::NSOperationQueue>(queue)
                                                            byAccessor:(accessor ? (void (^)(::NSError*)) ^ void(::NSError * a136_0) { accessor(cocoon::internal::wrap<Error>(a136_0)); } : (void (^)(::NSError*))nil)];
    }

    void FileCoordinator::coordinate_reading_item_at_url(const URL& url, FileCoordinatorReadingOptions options, std::function<void(URL)> reader) const
    {
        NSError* __error = nil;
        [cocoon::internal::ns<::NSFileCoordinator>(this) coordinateReadingItemAtURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileCoordinatorReadingOptions>(options) error:&__error byAccessor:(reader ? (void (^)(::NSURL*)) ^ void(::NSURL * a137_0) { reader(cocoon::internal::wrap<URL>(a137_0)); } : (void (^)(::NSURL*))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
    }

    void FileCoordinator::coordinate_reading_item_at_url(const URL& reading_url, FileCoordinatorReadingOptions reading_options, const URL& writing_url, FileCoordinatorWritingOptions writing_options, std::function<void(URL, URL)> reader_writer) const
    {
        NSError* __error = nil;
        [cocoon::internal::ns<::NSFileCoordinator>(this) coordinateReadingItemAtURL:cocoon::internal::native<::NSURL>(reading_url) options:static_cast<::NSFileCoordinatorReadingOptions>(reading_options) writingItemAtURL:cocoon::internal::native<::NSURL>(writing_url) options:static_cast<::NSFileCoordinatorWritingOptions>(writing_options) error:&__error byAccessor:(reader_writer ? (void (^)(::NSURL*, ::NSURL*)) ^ void(::NSURL * a138_0, ::NSURL * a138_1) { reader_writer(cocoon::internal::wrap<URL>(a138_0), cocoon::internal::wrap<URL>(a138_1)); } : (void (^)(::NSURL*, ::NSURL*))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
    }

    void FileCoordinator::coordinate_writing_item_at_url(const URL& url, FileCoordinatorWritingOptions options, std::function<void(URL)> writer) const
    {
        NSError* __error = nil;
        [cocoon::internal::ns<::NSFileCoordinator>(this) coordinateWritingItemAtURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileCoordinatorWritingOptions>(options) error:&__error byAccessor:(writer ? (void (^)(::NSURL*)) ^ void(::NSURL * a139_0) { writer(cocoon::internal::wrap<URL>(a139_0)); } : (void (^)(::NSURL*))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
    }

    void FileCoordinator::coordinate_writing_item_at_url(const URL& url1, FileCoordinatorWritingOptions options1, const URL& url2, FileCoordinatorWritingOptions options2, std::function<void(URL, URL)> writer) const
    {
        NSError* __error = nil;
        [cocoon::internal::ns<::NSFileCoordinator>(this) coordinateWritingItemAtURL:cocoon::internal::native<::NSURL>(url1) options:static_cast<::NSFileCoordinatorWritingOptions>(options1) writingItemAtURL:cocoon::internal::native<::NSURL>(url2) options:static_cast<::NSFileCoordinatorWritingOptions>(options2) error:&__error byAccessor:(writer ? (void (^)(::NSURL*, ::NSURL*)) ^ void(::NSURL * a140_0, ::NSURL * a140_1) { writer(cocoon::internal::wrap<URL>(a140_0), cocoon::internal::wrap<URL>(a140_1)); } : (void (^)(::NSURL*, ::NSURL*))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
    }

    void FileCoordinator::item_at_url(const URL& url, const std::vector<std::string>& attributes) const
    {
        [cocoon::internal::ns<::NSFileCoordinator>(this) itemAtURL:cocoon::internal::native<::NSURL>(url)
                         didChangeUbiquityAttributes:[NSSet setWithArray:cocoon::internal::to_array(attributes, [](const std::string& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::to(e);
                                                                                      })]];
    }

    void FileCoordinator::item_at_url(const URL& old_url, const URL& new_url) const
    {
        [cocoon::internal::ns<::NSFileCoordinator>(this) itemAtURL:cocoon::internal::native<::NSURL>(old_url) didMoveToURL:cocoon::internal::native<::NSURL>(new_url)];
    }

    void FileCoordinator::prepare_for_reading_items_at_urls(const std::vector<URL>& reading_urls, FileCoordinatorReadingOptions reading_options, const std::vector<URL>& writing_urls, FileCoordinatorWritingOptions writing_options, std::function<void(std::function<void()>)> batch_accessor) const
    {
        NSError* __error = nil;
        [cocoon::internal::ns<::NSFileCoordinator>(this) prepareForReadingItemsAtURLs:cocoon::internal::to_array(reading_urls, [](const URL& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::native<::NSURL>(e);
                                                                                     })
                                                                options:static_cast<::NSFileCoordinatorReadingOptions>(reading_options)
                                                     writingItemsAtURLs:cocoon::internal::to_array(writing_urls, [](const URL& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::native<::NSURL>(e);
                                                                                     })
                                                                options:static_cast<::NSFileCoordinatorWritingOptions>(writing_options)
                                                                  error:&__error
                                                             byAccessor:(batch_accessor ? (void (^)(void (^)(void))) ^ void(id a141_0) { batch_accessor([&]() -> std::function<void()>
                                                                                                                                                        {
                                                                                                                                                            auto blk = (void (^)(void))(a141_0);
                                                                                                                                                            if (!blk)
                                                                                                                                                            {
                                                                                                                                                                return {};
                                                                                                                                                            }
                                                                                                                                                            return [blk]() -> void
                                                                                                                                                            {
                                                                                                                                                                blk();
                                                                                                                                                            };
                                                                                                                                                        }()); } : (void (^)(void (^)(void)))nil)];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
    }

    void FileCoordinator::remove_file_presenter(const Object& file_presenter)
    {
        [::NSFileCoordinator removeFilePresenter:cocoon::internal::native_id(file_presenter)];
    }

    std::vector<Object> FileCoordinator::file_presenters()
    {
        return cocoon::internal::from_array<Object>([::NSFileCoordinator filePresenters], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::string FileCoordinator::purpose_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileCoordinator>(this) purposeIdentifier]);
    }

    void FileCoordinator::set_purpose_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSFileCoordinator>(this) setPurposeIdentifier:cocoon::internal::to(value)];
    }
}
