#include "generated/font_descriptor.h"
#include "internal.h"

namespace cocoon
{
    FontDescriptor::FontDescriptor(const std::map<std::string, Object>& attributes) : FontDescriptor(Adopt{cocoon::internal::retain([[::NSFontDescriptor alloc] initWithFontAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                                                                                                       {
                                                                                                                                                                                                                           return cocoon::internal::to(k);
                                                                                                                                                                                                                       },
                                                                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                                                                       {
                                                                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                                                                       })])})
    {
    }

    FontDescriptor::FontDescriptor(const std::string& font_name, const AffineTransform& matrix) : FontDescriptor(Adopt{cocoon::internal::retain([::NSFontDescriptor fontDescriptorWithName:cocoon::internal::to(font_name) matrix:cocoon::internal::native<::NSAffineTransform>(matrix)])})
    {
    }

    FontDescriptor::FontDescriptor(const std::string& font_name, double size) : FontDescriptor(Adopt{cocoon::internal::retain([::NSFontDescriptor fontDescriptorWithName:cocoon::internal::to(font_name) size:static_cast<::CGFloat>(size)])})
    {
    }

    FontDescriptor::FontDescriptor() : FontDescriptor(Adopt{cocoon::internal::retain([[::NSFontDescriptor alloc] init])})
    {
    }

    FontDescriptor::FontDescriptor(std::nullptr_t) : Object(nullptr)
    {
    }

    FontDescriptor::FontDescriptor(Adopt adopt) : Object(adopt)
    {
    }

    FontDescriptor FontDescriptor::font_descriptor_by_adding_attributes(const std::map<std::string, Object>& attributes) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorByAddingAttributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                                                                       {
                                                                                                                                                                           return cocoon::internal::to(k);
                                                                                                                                                                       },
                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                       {
                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                       })]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_design(const std::string& design) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithDesign:cocoon::internal::to(design)]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_face(const std::string& new_face) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithFace:cocoon::internal::to(new_face)]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_family(const std::string& new_family) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithFamily:cocoon::internal::to(new_family)]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_matrix(const AffineTransform& matrix) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithMatrix:cocoon::internal::native<::NSAffineTransform>(matrix)]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_size(double new_point_size) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithSize:static_cast<::CGFloat>(new_point_size)]);
    }

    FontDescriptor FontDescriptor::font_descriptor_with_symbolic_traits(FontDescriptorSymbolicTraits symbolic_traits) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) fontDescriptorWithSymbolicTraits:static_cast<::NSFontDescriptorSymbolicTraits>(symbolic_traits)]);
    }

    FontDescriptor FontDescriptor::matching_font_descriptor_with_mandatory_keys(const std::vector<std::string>& mandatory_keys) const
    {
        return cocoon::internal::wrap<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) matchingFontDescriptorWithMandatoryKeys:[NSSet setWithArray:cocoon::internal::to_array(mandatory_keys, [](const std::string& e) -> id
                                                                                                                                                                                             {
                                                                                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                                                                                             })]]);
    }

    std::vector<FontDescriptor> FontDescriptor::matching_font_descriptors_with_mandatory_keys(const std::vector<std::string>& mandatory_keys) const
    {
        return cocoon::internal::from_array<FontDescriptor>([cocoon::internal::ns<::NSFontDescriptor>(this) matchingFontDescriptorsWithMandatoryKeys:[NSSet setWithArray:cocoon::internal::to_array(mandatory_keys, [](const std::string& e) -> id
                                                                                                                                                                                                    {
                                                                                                                                                                                                        return cocoon::internal::to(e);
                                                                                                                                                                                                    })]],
                                                            [](id e) -> FontDescriptor
                                                            {
                                                                return cocoon::internal::wrap<FontDescriptor>((::NSFontDescriptor*)e);
                                                            });
    }

    Object FontDescriptor::object_for_key(const std::string& attribute) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSFontDescriptor>(this) objectForKey:cocoon::internal::to(attribute)]);
    }

    FontDescriptor FontDescriptor::preferred_font_descriptor_for_text_style(const std::string& style, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<FontDescriptor>([::NSFontDescriptor preferredFontDescriptorForTextStyle:cocoon::internal::to(style)
                                                                                                      options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                              {
                                                                                                                                                  return cocoon::internal::to(k);
                                                                                                                                              },
                                                                                                                                              [](const Object& v) -> id
                                                                                                                                              {
                                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                                              })]);
    }

    std::map<std::string, Object> FontDescriptor::font_attributes() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSFontDescriptor>(this) fontAttributes], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    AffineTransform FontDescriptor::matrix() const
    {
        return cocoon::internal::wrap<AffineTransform>([cocoon::internal::ns<::NSFontDescriptor>(this) matrix]);
    }

    double FontDescriptor::point_size() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSFontDescriptor>(this) pointSize]);
    }

    std::string FontDescriptor::postscript_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFontDescriptor>(this) postscriptName]);
    }

    bool FontDescriptor::requires_font_asset_request() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSFontDescriptor>(this) requiresFontAssetRequest]);
    }

    FontDescriptorSymbolicTraits FontDescriptor::symbolic_traits() const
    {
        return static_cast<FontDescriptorSymbolicTraits>([cocoon::internal::ns<::NSFontDescriptor>(this) symbolicTraits]);
    }
}
