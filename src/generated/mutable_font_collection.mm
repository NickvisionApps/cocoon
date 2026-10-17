#include "generated/mutable_font_collection.h"
#include "internal.h"

namespace cocoon
{
    MutableFontCollection::MutableFontCollection() : MutableFontCollection(Adopt{cocoon::internal::retain([[::NSMutableFontCollection alloc] init])})
    {
    }

    MutableFontCollection::MutableFontCollection(std::nullptr_t) : FontCollection(nullptr)
    {
    }

    MutableFontCollection::MutableFontCollection(Adopt adopt) : FontCollection(adopt)
    {
    }

    void MutableFontCollection::add_query_for_descriptors(const std::vector<FontDescriptor>& descriptors) const
    {
        [cocoon::internal::ns<::NSMutableFontCollection>(this) addQueryForDescriptors:cocoon::internal::to_array(descriptors, [](const FontDescriptor& e) -> id
                                                                                     {
                                                                                         return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                     })];
    }

    MutableFontCollection MutableFontCollection::font_collection_with_descriptors(const std::vector<FontDescriptor>& query_descriptors)
    {
        return cocoon::internal::wrap<MutableFontCollection>([::NSMutableFontCollection fontCollectionWithDescriptors:cocoon::internal::to_array(query_descriptors, [](const FontDescriptor& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                                                     })]);
    }

    MutableFontCollection MutableFontCollection::font_collection_with_locale(const Locale& locale)
    {
        return cocoon::internal::wrap<MutableFontCollection>([::NSMutableFontCollection fontCollectionWithLocale:cocoon::internal::native<::NSLocale>(locale)]);
    }

    MutableFontCollection MutableFontCollection::font_collection_with_name(const std::string& name)
    {
        return cocoon::internal::wrap<MutableFontCollection>([::NSMutableFontCollection fontCollectionWithName:cocoon::internal::to(name)]);
    }

    MutableFontCollection MutableFontCollection::font_collection_with_name(const std::string& name, FontCollectionVisibility visibility)
    {
        return cocoon::internal::wrap<MutableFontCollection>([::NSMutableFontCollection fontCollectionWithName:cocoon::internal::to(name) visibility:static_cast<::NSFontCollectionVisibility>(visibility)]);
    }

    void MutableFontCollection::remove_query_for_descriptors(const std::vector<FontDescriptor>& descriptors) const
    {
        [cocoon::internal::ns<::NSMutableFontCollection>(this) removeQueryForDescriptors:cocoon::internal::to_array(descriptors, [](const FontDescriptor& e) -> id
                                                                                        {
                                                                                            return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                        })];
    }

    std::vector<FontDescriptor> MutableFontCollection::exclusion_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSMutableFontCollection>(this) exclusionDescriptors], [](id e) -> FontDescriptor
                                              {
                                                  return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                              });
    }

    void MutableFontCollection::set_exclusion_descriptors(const std::vector<FontDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSMutableFontCollection>(this) setExclusionDescriptors:cocoon::internal::to_array(value, [](const FontDescriptor& e) -> id
                                                                                      {
                                                                                          return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                      })];
    }

    MutableFontCollection MutableFontCollection::font_collection_with_all_available_descriptors()
    {
        return cocoon::internal::wrap<MutableFontCollection>([::NSMutableFontCollection fontCollectionWithAllAvailableDescriptors]);
    }

    std::vector<FontDescriptor> MutableFontCollection::query_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSMutableFontCollection>(this) queryDescriptors], [](id e) -> FontDescriptor
                                              {
                                                  return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                              });
    }

    void MutableFontCollection::set_query_descriptors(const std::vector<FontDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSMutableFontCollection>(this) setQueryDescriptors:cocoon::internal::to_array(value, [](const FontDescriptor& e) -> id
                                                                                  {
                                                                                      return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                  })];
    }
}
