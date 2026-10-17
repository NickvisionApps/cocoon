#include "generated/file_access_intent.h"
#include "internal.h"

namespace cocoon
{
    FileAccessIntent::FileAccessIntent() : FileAccessIntent(Adopt{cocoon::internal::retain([[::NSFileAccessIntent alloc] init])})
    {
    }

    FileAccessIntent::FileAccessIntent(std::nullptr_t) : Object(nullptr)
    {
    }

    FileAccessIntent::FileAccessIntent(Adopt adopt) : Object(adopt)
    {
    }

    FileAccessIntent FileAccessIntent::reading_intent_with_url(const URL& url, FileCoordinatorReadingOptions options)
    {
        return cocoon::internal::wrap<FileAccessIntent>([::NSFileAccessIntent readingIntentWithURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileCoordinatorReadingOptions>(options)]);
    }

    FileAccessIntent FileAccessIntent::writing_intent_with_url(const URL& url, FileCoordinatorWritingOptions options)
    {
        return cocoon::internal::wrap<FileAccessIntent>([::NSFileAccessIntent writingIntentWithURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSFileCoordinatorWritingOptions>(options)]);
    }

    URL FileAccessIntent::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSFileAccessIntent>(this) URL]);
    }
}
