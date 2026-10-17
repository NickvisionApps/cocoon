#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class ItemProvider;

    /**
     * @brief C++ handle for the Objective-C class `NSPreviewRepresentingActivityItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PreviewRepresentingActivityItem preview_representing_activity_item(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspreviewrepresentingactivityitem
     */
    class PreviewRepresentingActivityItem : public Object
    {
    public:
        /// @brief Creates a new `NSPreviewRepresentingActivityItem` instance and returns a handle to it.
        explicit PreviewRepresentingActivityItem(const Object& item, const std::string& title, const Image& image, const Image& icon);
        /// @brief Creates a new `NSPreviewRepresentingActivityItem` instance and returns a handle to it.
        explicit PreviewRepresentingActivityItem(const Object& item, const std::string& title, const ItemProvider& image_provider, const ItemProvider& icon_provider);
        PreviewRepresentingActivityItem();
        /// @brief Creates a null handle that refers to no native object.
        PreviewRepresentingActivityItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PreviewRepresentingActivityItem(Adopt adopt);
    };
}
