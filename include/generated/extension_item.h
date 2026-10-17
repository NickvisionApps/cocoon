#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class ItemProvider;

    /**
     * @brief C++ handle for the Objective-C class `NSExtensionItem` (Foundation).
     * @details An immutable collection of values representing different aspects of an item for an extension to act upon.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ExtensionItem extension_item;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ExtensionItem extension_item{};
     * extension_item.set_attributed_content_text(cocoon::AttributedString());
     * auto attributed_content_text = extension_item.attributed_content_text();
     * extension_item.set_attributed_title(cocoon::AttributedString());
     * auto attributed_title = extension_item.attributed_title();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsextensionitem
     */
    class ExtensionItem : public Object
    {
    public:
        /// @brief Creates a new `NSExtensionItem` instance and returns a handle to it.
        explicit ExtensionItem();
        /// @brief Creates a null handle that refers to no native object.
        ExtensionItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ExtensionItem(Adopt adopt);
        /**
     * @brief Returns the `attachments` property of `NSExtensionItem`.
     * @details Optional array of media data associated with the extension item, including images, videos, and URLs. This is not meant to be an array of alternate data formats/types, but instead a collection to include in a social media post for example.
     * @return The converted Objective-C result.
     */
        std::vector<ItemProvider> attachments() const;
        /**
     * @brief Sets the `attachments` property of `NSExtensionItem`.
     * @details Optional array of media data associated with the extension item, including images, videos, and URLs. This is not meant to be an array of alternate data formats/types, but instead a collection to include in a social media post for example.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attachments(const std::vector<ItemProvider>& value) const;
        /**
     * @brief Returns the `attributedContentText` property of `NSExtensionItem`.
     * @details Optional content text.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_content_text() const;
        /**
     * @brief Sets the `attributedContentText` property of `NSExtensionItem`.
     * @details Optional content text.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_content_text(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSExtensionItem`.
     * @details An optional title for the item.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSExtensionItem`.
     * @details An optional title for the item.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSExtensionItem`.
     * @details Optional dictionary of key-value data. The key/value pairs accepted by the service are expected to be specified in the extension's \@c Info.plist. The values of \@c NSExtensionItem's properties will be reflected into the dictionary.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSExtensionItem`.
     * @details Optional dictionary of key-value data. The key/value pairs accepted by the service are expected to be specified in the extension's \@c Info.plist. The values of \@c NSExtensionItem's properties will be reflected into the dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const std::vector<std::pair<Object, Object>>& value) const;
    };
}
