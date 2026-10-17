#include "generated/directory_enumerator_base.h"
#include "internal.h"

namespace cocoon
{
    DirectoryEnumeratorBase::DirectoryEnumeratorBase() : DirectoryEnumeratorBase(Adopt{cocoon::internal::retain([[::NSDirectoryEnumerator alloc] init])})
    {
    }

    DirectoryEnumeratorBase::DirectoryEnumeratorBase(std::nullptr_t) : EnumeratorBase(nullptr)
    {
    }

    DirectoryEnumeratorBase::DirectoryEnumeratorBase(Adopt adopt) : EnumeratorBase(adopt)
    {
    }

    void DirectoryEnumeratorBase::skip_descendants() const
    {
        [cocoon::internal::ns<::NSDirectoryEnumerator>(this) skipDescendants];
    }

    void DirectoryEnumeratorBase::skip_descendents() const
    {
        [cocoon::internal::ns<::NSDirectoryEnumerator>(this) skipDescendents];
    }

    std::map<std::string, Object> DirectoryEnumeratorBase::directory_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSDirectoryEnumerator>(this) directoryAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    std::map<std::string, Object> DirectoryEnumeratorBase::file_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSDirectoryEnumerator>(this) fileAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    bool DirectoryEnumeratorBase::is_enumerating_directory_post_order() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDirectoryEnumerator>(this) isEnumeratingDirectoryPostOrder]);
    }

    std::uint64_t DirectoryEnumeratorBase::level() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSDirectoryEnumerator>(this) level]);
    }
}
