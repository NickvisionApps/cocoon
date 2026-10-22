#include "generated/font_collection.h"
#include "internal.h"

namespace cocoon
{
    FontCollection::FontCollection(const std::vector<FontDescriptor>& query_descriptors) : FontCollection(Adopt{cocoon::internal::retain([::NSFontCollection fontCollectionWithDescriptors:cocoon::internal::to_array(query_descriptors, [](const FontDescriptor& e) -> id
                                                                                                                                                                                                                      {
                                                                                                                                                                                                                          return cocoon::internal::native<::NSFontDescriptor>(e);
                                                                                                                                                                                                                      })])})
    {
    }

    FontCollection::FontCollection(const Locale& locale) : FontCollection(Adopt{cocoon::internal::retain([::NSFontCollection fontCollectionWithLocale:cocoon::internal::native<::NSLocale>(locale)])})
    {
    }

    FontCollection::FontCollection(const std::string& name) : FontCollection(Adopt{cocoon::internal::retain([::NSFontCollection fontCollectionWithName:cocoon::internal::to(name)])})
    {
    }

    FontCollection::FontCollection(const std::string& name, FontCollectionVisibility visibility) : FontCollection(Adopt{cocoon::internal::retain([::NSFontCollection fontCollectionWithName:cocoon::internal::to(name) visibility:static_cast<::NSFontCollectionVisibility>(visibility)])})
    {
    }

    FontCollection::FontCollection() : FontCollection(Adopt{cocoon::internal::retain([[::NSFontCollection alloc] init])})
    {
    }

    FontCollection::FontCollection(std::nullptr_t) : Object(nullptr)
    {
    }

    FontCollection::FontCollection(Adopt adopt) : Object(adopt)
    {
    }

    bool FontCollection::hide_font_collection_with_name(const std::string& name, FontCollectionVisibility visibility)
    {
        NSError* __error = nil;
        auto __r = [::NSFontCollection hideFontCollectionWithName:cocoon::internal::to(name) visibility:static_cast<::NSFontCollectionVisibility>(visibility) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<FontDescriptor> FontCollection::matching_descriptors_for_family(const std::string& family) const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) matchingDescriptorsForFamily:cocoon::internal::to(family)], [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    std::vector<FontDescriptor> FontCollection::matching_descriptors_for_family(const std::string& family, const std::map<std::string, Number>& options) const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) matchingDescriptorsForFamily:cocoon::internal::to(family)
                                                                                                                                 options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::to(k);
                                                                                                                                                                         },
                                                                                                                                                                         [](const Number& v) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::native<::NSNumber>(v);
                                                                                                                                                                         })],
                                                            [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    std::vector<FontDescriptor> FontCollection::matching_descriptors_with_options(const std::map<std::string, Number>& options) const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) matchingDescriptorsWithOptions:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                           {
                                                                                                                                                                               return cocoon::internal::to(k);
                                                                                                                                                                           },
                                                                                                                                                                           [](const Number& v) -> id
                                                                                                                                                                           {
                                                                                                                                                                               return cocoon::internal::native<::NSNumber>(v);
                                                                                                                                                                           })],
                                                            [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    bool FontCollection::rename_font_collection_with_name(const std::string& old_name, FontCollectionVisibility visibility, const std::string& new_name)
    {
        NSError* __error = nil;
        auto __r = [::NSFontCollection renameFontCollectionWithName:cocoon::internal::to(old_name) visibility:static_cast<::NSFontCollectionVisibility>(visibility) toName:cocoon::internal::to(new_name) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool FontCollection::show_font_collection(const FontCollection& collection, const std::string& name, FontCollectionVisibility visibility)
    {
        NSError* __error = nil;
        auto __r = [::NSFontCollection showFontCollection:cocoon::internal::native<::NSFontCollection>(collection) withName:cocoon::internal::to(name) visibility:static_cast<::NSFontCollectionVisibility>(visibility) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    std::vector<std::string> FontCollection::all_font_collection_names()
    {
        return cocoon::internal::from_array<std::string>([::NSFontCollection allFontCollectionNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<FontDescriptor> FontCollection::exclusion_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) exclusionDescriptors], [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    FontCollection FontCollection::font_collection_with_all_available_descriptors()
    {
        return cocoon::internal::wrap<FontCollection>([::NSFontCollection fontCollectionWithAllAvailableDescriptors]);
    }

    std::vector<FontDescriptor> FontCollection::matching_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) matchingDescriptors], [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    std::vector<FontDescriptor> FontCollection::query_descriptors() const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontCollection>(this) queryDescriptors], [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }
}
