#include "generated/extension_item.h"
#include "internal.h"

namespace cocoon
{
    ExtensionItem::ExtensionItem() : ExtensionItem(Adopt{cocoon::internal::retain([[::NSExtensionItem alloc] init])})
    {
    }

    ExtensionItem::ExtensionItem(std::nullptr_t) : Object(nullptr)
    {
    }

    ExtensionItem::ExtensionItem(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<ItemProvider> ExtensionItem::attachments() const
    {
        return cocoon::internal::from_array<ItemProvider>([cocoon::internal::ns<::NSExtensionItem>(this) attachments], [](id e) -> ItemProvider
                                            {
                                                return cocoon::internal::wrap<ItemProvider>((::NSItemProvider*)e);
                                            });
    }

    void ExtensionItem::set_attachments(const std::vector<ItemProvider>& value) const
    {
        [cocoon::internal::ns<::NSExtensionItem>(this) setAttachments:cocoon::internal::to_array(value, [](const ItemProvider& e) -> id
                                                                     {
                                                                         return cocoon::internal::native<::NSItemProvider>(e);
                                                                     })];
    }

    AttributedString ExtensionItem::attributed_content_text() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSExtensionItem>(this) attributedContentText]);
    }

    void ExtensionItem::set_attributed_content_text(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSExtensionItem>(this) setAttributedContentText:cocoon::internal::native<::NSAttributedString>(value)];
    }

    AttributedString ExtensionItem::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSExtensionItem>(this) attributedTitle]);
    }

    void ExtensionItem::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSExtensionItem>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    std::vector<std::pair<Object, Object>> ExtensionItem::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSExtensionItem>(this) userInfo], [](id k) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(k);
                                                                           },
                                                                           [](id v) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(v);
                                                                           });
    }

    void ExtensionItem::set_user_info(const std::vector<std::pair<Object, Object>>& value) const
    {
        [cocoon::internal::ns<::NSExtensionItem>(this) setUserInfo:cocoon::internal::to_dictionary(value, [](const Object& k) -> id
                                                                       {
                                                                           return cocoon::internal::native_id(k);
                                                                       },
                                                                       [](const Object& v) -> id
                                                                       {
                                                                           return cocoon::internal::native_id(v);
                                                                       })];
    }
}
