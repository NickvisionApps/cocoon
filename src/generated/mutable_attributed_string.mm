#include "generated/mutable_attributed_string.h"
#include "internal.h"

namespace cocoon
{
    MutableAttributedString::MutableAttributedString() : MutableAttributedString(Adopt{cocoon::internal::retain([[::NSMutableAttributedString alloc] init])})
    {
    }

    MutableAttributedString::MutableAttributedString(std::nullptr_t) : AttributedString(nullptr)
    {
    }

    MutableAttributedString::MutableAttributedString(Adopt adopt) : AttributedString(adopt)
    {
    }

    void MutableAttributedString::add_attribute(const std::string& name, const Object& value, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) addAttribute:cocoon::internal::to(name) value:cocoon::internal::native_id(value) range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::add_attributes(const std::map<std::string, Object>& attrs, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) addAttributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                   {
                                                                                       return cocoon::internal::to(k);
                                                                                   },
                                                                                   [](const Object& v) -> id
                                                                                   {
                                                                                       return cocoon::internal::native_id(v);
                                                                                   })
                                                           range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::append_attributed_string(const AttributedString& attr_string) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) appendAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string)];
    }

    void MutableAttributedString::apply_font_traits(FontTraitMask trait_mask, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) applyFontTraits:static_cast<::NSFontTraitMask>(trait_mask) range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::begin_editing() const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) beginEditing];
    }

    void MutableAttributedString::delete_characters_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) deleteCharactersInRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::end_editing() const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) endEditing];
    }

    void MutableAttributedString::fix_attachment_attribute_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) fixAttachmentAttributeInRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::fix_attributes_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) fixAttributesInRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::fix_font_attribute_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) fixFontAttributeInRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::fix_paragraph_style_attribute_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) fixParagraphStyleAttributeInRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::insert_attributed_string(const AttributedString& attr_string, std::uint64_t loc) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) insertAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string) atIndex:static_cast<::NSUInteger>(loc)];
    }

    bool MutableAttributedString::read_from_data(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& opts, std::map<std::string, Object>& dict) const
    {
        NSError* __error = nil;
        NSDictionary* __v_dict = nil;
        auto __r = [cocoon::internal::ns<::NSMutableAttributedString>(this) readFromData:cocoon::internal::to_data(data)
                                                                   options:cocoon::internal::to_dictionary(opts, [](const std::string& k) -> id
                                                                                             {
                                                                                                 return cocoon::internal::to(k);
                                                                                             },
                                                                                             [](const Object& v) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native_id(v);
                                                                                             })
                                                        documentAttributes:&__v_dict
                                                                     error:&__error];
        dict = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_dict, [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    bool MutableAttributedString::read_from_url(const URL& url, const std::map<std::string, Object>& opts, std::map<std::string, Object>& dict) const
    {
        NSError* __error = nil;
        NSDictionary* __v_dict = nil;
        auto __r = [cocoon::internal::ns<::NSMutableAttributedString>(this) readFromURL:cocoon::internal::native<::NSURL>(url)
                                                                  options:cocoon::internal::to_dictionary(opts, [](const std::string& k) -> id
                                                                                            {
                                                                                                return cocoon::internal::to(k);
                                                                                            },
                                                                                            [](const Object& v) -> id
                                                                                            {
                                                                                                return cocoon::internal::native_id(v);
                                                                                            })
                                                       documentAttributes:&__v_dict
                                                                    error:&__error];
        dict = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_dict, [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void MutableAttributedString::remove_attribute(const std::string& name, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) removeAttribute:cocoon::internal::to(name) range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::replace_characters_in_range(const Range& range, const AttributedString& attr_string) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) replaceCharactersInRange:cocoon::internal::to(range) withAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string)];
    }

    void MutableAttributedString::replace_characters_in_range(const Range& range, const std::string& str) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) replaceCharactersInRange:cocoon::internal::to(range) withString:cocoon::internal::to(str)];
    }

    void MutableAttributedString::set_alignment(TextAlignment alignment, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) setAlignment:static_cast<::NSTextAlignment>(alignment) range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::set_attributed_string(const AttributedString& attr_string) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) setAttributedString:cocoon::internal::native<::NSAttributedString>(attr_string)];
    }

    void MutableAttributedString::set_attributes(const std::map<std::string, Object>& attrs, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) setAttributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                   {
                                                                                       return cocoon::internal::to(k);
                                                                                   },
                                                                                   [](const Object& v) -> id
                                                                                   {
                                                                                       return cocoon::internal::native_id(v);
                                                                                   })
                                                           range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::set_base_writing_direction(WritingDirection writing_direction, const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(writing_direction) range:cocoon::internal::to(range)];
    }

    void MutableAttributedString::subscript_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) subscriptRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::superscript_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) superscriptRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::unscript_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) unscriptRange:cocoon::internal::to(range)];
    }

    void MutableAttributedString::update_attachments_from_path(const std::string& path) const
    {
        [cocoon::internal::ns<::NSMutableAttributedString>(this) updateAttachmentsFromPath:cocoon::internal::to(path)];
    }

    std::string MutableAttributedString::mutable_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSMutableAttributedString>(this) mutableString]);
    }
}
