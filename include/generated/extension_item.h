#pragma once

#include "generated/availability.h"
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
     * @return The converted Objective-C result.
     */
        std::vector<ItemProvider> attachments() const;
        /**
     * @brief Sets the `attachments` property of `NSExtensionItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attachments(const std::vector<ItemProvider>& value) const;
        /**
     * @brief Returns the `attributedContentText` property of `NSExtensionItem`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_content_text() const;
        /**
     * @brief Sets the `attributedContentText` property of `NSExtensionItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_content_text(const AttributedString& value) const;
        /**
     * @brief Returns the `attributedTitle` property of `NSExtensionItem`.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_title() const;
        /**
     * @brief Sets the `attributedTitle` property of `NSExtensionItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributed_title(const AttributedString& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSExtensionItem`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSExtensionItem`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const std::vector<std::pair<Object, Object>>& value) const;
    };
}
