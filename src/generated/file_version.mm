#include "generated/file_version.h"
#include "internal.h"

namespace cocoon
{
    FileVersion::FileVersion() : FileVersion(Adopt{cocoon::internal::retain([[::NSFileVersion alloc] init])})
    {
    }

    FileVersion::FileVersion(std::nullptr_t) : Object(nullptr)
    {
    }

    FileVersion::FileVersion(Adopt adopt) : Object(adopt)
    {
    }

    FileVersion FileVersion::add_version_of_item_at_url(const URL& url, const URL& contents_url, FileVersionAddingOptions options)
    {
        NSError* __error = nil;
        auto __r = [::NSFileVersion addVersionOfItemAtURL:cocoon::internal::native<::NSURL>(url) withContentsOfURL:cocoon::internal::native<::NSURL>(contents_url) options:static_cast<::NSFileVersionAddingOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileVersion>(__r);
    }

    FileVersion FileVersion::current_version_of_item_at_url(const URL& url)
    {
        return cocoon::internal::wrap<FileVersion>([::NSFileVersion currentVersionOfItemAtURL:cocoon::internal::native<::NSURL>(url)]);
    }

    void FileVersion::get_nonlocal_versions_of_item_at_url(const URL& url, std::function<void(std::vector<FileVersion>, Error)> completion_handler)
    {
        [::NSFileVersion getNonlocalVersionsOfItemAtURL:cocoon::internal::native<::NSURL>(url) completionHandler:(completion_handler ? (void (^)(NSArray<NSFileVersion*>*, ::NSError*)) ^ void(NSArray * a155_0, ::NSError * a155_1) { completion_handler(cocoon::internal::from_array<FileVersion>(a155_0, [](id e) -> FileVersion
                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                        return cocoon::internal::wrap<FileVersion>((::NSFileVersion*)e);
                                                                                                                                                                                                                                                                                                    }),
                                                                                                                                                                                                                                                          cocoon::internal::wrap<Error>(a155_1)); } : (void (^)(NSArray<NSFileVersion*>*, ::NSError*))nil)];
    }

    std::vector<FileVersion> FileVersion::other_versions_of_item_at_url(const URL& url)
    {
        return cocoon::internal::from_array<FileVersion>([::NSFileVersion otherVersionsOfItemAtURL:cocoon::internal::native<::NSURL>(url)], [](id e) -> FileVersion
                                                         {
                                                             return cocoon::internal::wrap<FileVersion>((::NSFileVersion*)e);
                                                         });
    }

    bool FileVersion::remove_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileVersion>(this) removeAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FileVersion::remove_other_versions_of_item_at_url(const URL& url)
    {
        NSError* __error = nil;
        auto __r = [::NSFileVersion removeOtherVersionsOfItemAtURL:cocoon::internal::native<::NSURL>(url) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    URL FileVersion::replace_item_at_url(const URL& url, FileVersionReplacingOptions options) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSFileVersion>(this) replaceItemAtURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileVersionReplacingOptions>(options) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<URL>(__r);
    }

    URL FileVersion::temporary_directory_url_for_new_version_of_item_at_url(const URL& url)
    {
        return cocoon::internal::wrap<URL>([::NSFileVersion temporaryDirectoryURLForNewVersionOfItemAtURL:cocoon::internal::native<::NSURL>(url)]);
    }

    std::vector<FileVersion> FileVersion::unresolved_conflict_versions_of_item_at_url(const URL& url)
    {
        return cocoon::internal::from_array<FileVersion>([::NSFileVersion unresolvedConflictVersionsOfItemAtURL:cocoon::internal::native<::NSURL>(url)], [](id e) -> FileVersion
                                                         {
                                                             return cocoon::internal::wrap<FileVersion>((::NSFileVersion*)e);
                                                         });
    }

    FileVersion FileVersion::version_of_item_at_url(const URL& url, const Object& persistent_identifier)
    {
        return cocoon::internal::wrap<FileVersion>([::NSFileVersion versionOfItemAtURL:cocoon::internal::native<::NSURL>(url) forPersistentIdentifier:cocoon::internal::native_id(persistent_identifier)]);
    }

    URL FileVersion::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileVersion>(this) URL]);
    }

    bool FileVersion::is_conflict() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileVersion>(this) isConflict]);
    }

    bool FileVersion::is_discardable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileVersion>(this) isDiscardable]);
    }

    void FileVersion::set_discardable(bool value) const
    {
        [cocoon::internal::ns<::NSFileVersion>(this) setDiscardable:static_cast<::BOOL>(value)];
    }

    bool FileVersion::has_local_contents() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileVersion>(this) hasLocalContents]);
    }

    bool FileVersion::has_thumbnail() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileVersion>(this) hasThumbnail]);
    }

    std::string FileVersion::localized_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileVersion>(this) localizedName]);
    }

    std::string FileVersion::localized_name_of_saving_computer() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFileVersion>(this) localizedNameOfSavingComputer]);
    }

    Date FileVersion::modification_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSFileVersion>(this) modificationDate]);
    }

    PersonNameComponents FileVersion::originator_name_components() const
    {
        return cocoon::internal::wrap<PersonNameComponents>([cocoon::internal::ns<::NSFileVersion>(this) originatorNameComponents]);
    }

    bool FileVersion::is_resolved() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFileVersion>(this) isResolved]);
    }

    void FileVersion::set_resolved(bool value) const
    {
        [cocoon::internal::ns<::NSFileVersion>(this) setResolved:static_cast<::BOOL>(value)];
    }
}
