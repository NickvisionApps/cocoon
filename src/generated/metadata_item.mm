#include "generated/metadata_item.h"
#include "internal.h"

namespace cocoon
{
    MetadataItem::MetadataItem(const URL& url) : MetadataItem(Adopt{cocoon::internal::retain([[::NSMetadataItem alloc] initWithURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    MetadataItem::MetadataItem() : MetadataItem(Adopt{cocoon::internal::retain([[::NSMetadataItem alloc] init])})
    {
    }

    MetadataItem::MetadataItem(std::nullptr_t) : Object(nullptr)
    {
    }

    MetadataItem::MetadataItem(Adopt adopt) : Object(adopt)
    {
    }

    Object MetadataItem::value_for_attribute(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSMetadataItem>(this) valueForAttribute:cocoon::internal::to(key)]);
    }

    std::map<std::string, Object> MetadataItem::values_for_attributes(const std::vector<std::string>& keys) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSMetadataItem>(this) valuesForAttributes:cocoon::internal::to_array(keys, [](const std::string& e) -> id
                                                                                                                                   {
                                                                                                                                       return cocoon::internal::to(e);
                                                                                                                                   })],
                                                                  [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    std::vector<std::string> MetadataItem::attributes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSMetadataItem>(this) attributes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
