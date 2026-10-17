#include "generated/attributed_string.h"
#include "internal.h"

namespace cocoon
{
    AttributedString::AttributedString(const URL& markdown_file, const AttributedStringMarkdownParsingOptions& options, const URL& base_url) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                                 {
                                                                                                                                                                                     NSError* __error = nil;
                                                                                                                                                                                     id __r = [[::NSAttributedString alloc] initWithContentsOfMarkdownFileAtURL:cocoon::internal::native<::NSURL>(markdown_file) options:cocoon::internal::native<::NSAttributedStringMarkdownParsingOptions>(options) baseURL:cocoon::internal::native<::NSURL>(base_url) error:&__error];
                                                                                                                                                                                     if (!__r && __error)
                                                                                                                                                                                     {
                                                                                                                                                                                         throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                                     }
                                                                                                                                                                                     return __r;
                                                                                                                                                                                 }())})
    {
    }

    AttributedString::AttributedString(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options, std::map<std::string, Object>& dict) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                                                     {
                                                                                                                                                                                                         NSError* __error = nil;
                                                                                                                                                                                                         NSDictionary* __v_dict = nil;
                                                                                                                                                                                                         id __r = [[::NSAttributedString alloc] initWithData:cocoon::internal::to_data(data)
                                                                                                                                                                                                                                                     options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
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
                                                                                                                                                                                                         if (!__r && __error)
                                                                                                                                                                                                         {
                                                                                                                                                                                                             throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                                                         }
                                                                                                                                                                                                         return __r;
                                                                                                                                                                                                     }())})
    {
    }

    AttributedString::AttributedString(const std::vector<std::uint8_t>& data, std::map<std::string, Object>& dict) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                       {
                                                                                                                                                           NSDictionary* __v_dict = nil;
                                                                                                                                                           id __r = [[::NSAttributedString alloc] initWithDocFormat:cocoon::internal::to_data(data) documentAttributes:&__v_dict];
                                                                                                                                                           dict = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_dict, [](id k) -> std::string
                                                                                                                                                                                                                     {
                                                                                                                                                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                     },
                                                                                                                                                                                                                     [](id v) -> Object
                                                                                                                                                                                                                     {
                                                                                                                                                                                                                         return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                     });
                                                                                                                                                           return __r;
                                                                                                                                                       }())})
    {
    }

    AttributedString::AttributedString(const AttributedString& format, AttributedStringFormattingOptions options, const Locale& locale, char* arguments) : AttributedString(Adopt{cocoon::internal::retain([[::NSAttributedString alloc] initWithFormat:cocoon::internal::native<::NSAttributedString>(format) options:static_cast<::NSAttributedStringFormattingOptions>(options) locale:cocoon::internal::native<::NSLocale>(locale) arguments:(::va_list)(arguments)])})
    {
    }

    AttributedString::AttributedString(const AttributedString& format, AttributedStringFormattingOptions options, const Locale& locale, const std::map<std::string, Object>& context, char* arguments) : AttributedString(Adopt{cocoon::internal::retain([[::NSAttributedString alloc] initWithFormat:cocoon::internal::native<::NSAttributedString>(format)
                                                                                                                                                                                                                                                                                options:static_cast<::NSAttributedStringFormattingOptions>(options)
                                                                                                                                                                                                                                                                                 locale:cocoon::internal::native<::NSLocale>(locale)
                                                                                                                                                                                                                                                                                context:cocoon::internal::to_dictionary(context, [](const std::string& k) -> id
                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                              return cocoon::internal::to(k);
                                                                                                                                                                                                                                                                                                          },
                                                                                                                                                                                                                                                                                                          [](const Object& v) -> id
                                                                                                                                                                                                                                                                                                          {
                                                                                                                                                                                                                                                                                                              return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                                          })
                                                                                                                                                                                                                                                                              arguments:(::va_list)(arguments)])})
    {
    }

    AttributedString::AttributedString(const std::vector<std::uint8_t>& data, const URL& base, std::map<std::string, Object>& dict) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                        {
                                                                                                                                                                            NSDictionary* __v_dict = nil;
                                                                                                                                                                            id __r = [[::NSAttributedString alloc] initWithHTML:cocoon::internal::to_data(data) baseURL:cocoon::internal::native<::NSURL>(base) documentAttributes:&__v_dict];
                                                                                                                                                                            dict = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_dict, [](id k) -> std::string
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                          return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                      },
                                                                                                                                                                                                                                      [](id v) -> Object
                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                          return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                      });
                                                                                                                                                                            return __r;
                                                                                                                                                                        }())})
    {
    }

    AttributedString::AttributedString(const std::vector<std::uint8_t>& markdown, const AttributedStringMarkdownParsingOptions& options, const URL& base_url) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                                                  {
                                                                                                                                                                                                      NSError* __error = nil;
                                                                                                                                                                                                      id __r = [[::NSAttributedString alloc] initWithMarkdown:cocoon::internal::to_data(markdown) options:cocoon::internal::native<::NSAttributedStringMarkdownParsingOptions>(options) baseURL:cocoon::internal::native<::NSURL>(base_url) error:&__error];
                                                                                                                                                                                                      if (!__r && __error)
                                                                                                                                                                                                      {
                                                                                                                                                                                                          throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                                                      }
                                                                                                                                                                                                      return __r;
                                                                                                                                                                                                  }())})
    {
    }

    AttributedString::AttributedString(const std::string& markdown_string, const AttributedStringMarkdownParsingOptions& options, const URL& base_url) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                                           {
                                                                                                                                                                                               NSError* __error = nil;
                                                                                                                                                                                               id __r = [[::NSAttributedString alloc] initWithMarkdownString:cocoon::internal::to(markdown_string) options:cocoon::internal::native<::NSAttributedStringMarkdownParsingOptions>(options) baseURL:cocoon::internal::native<::NSURL>(base_url) error:&__error];
                                                                                                                                                                                               if (!__r && __error)
                                                                                                                                                                                               {
                                                                                                                                                                                                   throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                                               }
                                                                                                                                                                                               return __r;
                                                                                                                                                                                           }())})
    {
    }

    AttributedString::AttributedString(const FileWrapper& wrapper, std::map<std::string, Object>& dict) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                            {
                                                                                                                                                NSDictionary* __v_dict = nil;
                                                                                                                                                id __r = [[::NSAttributedString alloc] initWithRTFDFileWrapper:cocoon::internal::native<::NSFileWrapper>(wrapper) documentAttributes:&__v_dict];
                                                                                                                                                dict = cocoon::internal::from_dictionary<std::map<std::string, Object>>(__v_dict, [](id k) -> std::string
                                                                                                                                                                                                          {
                                                                                                                                                                                                              return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                          },
                                                                                                                                                                                                          [](id v) -> Object
                                                                                                                                                                                                          {
                                                                                                                                                                                                              return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                          });
                                                                                                                                                return __r;
                                                                                                                                            }())})
    {
    }

    AttributedString::AttributedString(const std::string& str) : AttributedString(Adopt{cocoon::internal::retain([[::NSAttributedString alloc] initWithString:cocoon::internal::to(str)])})
    {
    }

    AttributedString::AttributedString(const std::string& str, const std::map<std::string, Object>& attrs) : AttributedString(Adopt{cocoon::internal::retain([[::NSAttributedString alloc] initWithString:cocoon::internal::to(str)
                                                                                                                                                                                 attributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                                                                                                                                              {
                                                                                                                                                                                                                  return cocoon::internal::to(k);
                                                                                                                                                                                                              },
                                                                                                                                                                                                              [](const Object& v) -> id
                                                                                                                                                                                                              {
                                                                                                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                                                                                                              })])})
    {
    }

    AttributedString::AttributedString(const URL& url, const std::map<std::string, Object>& options, std::map<std::string, Object>& dict) : AttributedString(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                                                              {
                                                                                                                                                                                  NSError* __error = nil;
                                                                                                                                                                                  NSDictionary* __v_dict = nil;
                                                                                                                                                                                  id __r = [[::NSAttributedString alloc] initWithURL:cocoon::internal::native<::NSURL>(url)
                                                                                                                                                                                                                             options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
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
                                                                                                                                                                                  if (!__r && __error)
                                                                                                                                                                                  {
                                                                                                                                                                                      throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                                                                  }
                                                                                                                                                                                  return __r;
                                                                                                                                                                              }())})
    {
    }

    AttributedString::AttributedString() : AttributedString(Adopt{cocoon::internal::retain([[::NSAttributedString alloc] init])})
    {
    }

    AttributedString::AttributedString(std::nullptr_t) : Object(nullptr)
    {
    }

    AttributedString::AttributedString(Adopt adopt) : Object(adopt)
    {
    }

    FileWrapper AttributedString::rtfd_file_wrapper_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        return cocoon::internal::wrap<FileWrapper>([cocoon::internal::ns<::NSAttributedString>(this) RTFDFileWrapperFromRange:cocoon::internal::to(range)
                                                                               documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::to(k);
                                                                                                                    },
                                                                                                                    [](const Object& v) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::native_id(v);
                                                                                                                    })]);
    }

    std::vector<std::uint8_t> AttributedString::rtfd_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSAttributedString>(this) RTFDFromRange:cocoon::internal::to(range)
                                                            documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(k);
                                                                                                 },
                                                                                                 [](const Object& v) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(v);
                                                                                                 })]);
    }

    std::vector<std::uint8_t> AttributedString::rtf_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSAttributedString>(this) RTFFromRange:cocoon::internal::to(range)
                                                           documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                {
                                                                                                    return cocoon::internal::to(k);
                                                                                                },
                                                                                                [](const Object& v) -> id
                                                                                                {
                                                                                                    return cocoon::internal::native_id(v);
                                                                                                })]);
    }

    Object AttributedString::attribute(const std::string& attr_name, std::uint64_t location, Range* range) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAttributedString>(this) attribute:cocoon::internal::to(attr_name) atIndex:static_cast<::NSUInteger>(location) effectiveRange:(::NSRangePointer)(range)]);
    }

    Object AttributedString::attribute(const std::string& attr_name, std::uint64_t location, Range* range, const Range& range_limit) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAttributedString>(this) attribute:cocoon::internal::to(attr_name) atIndex:static_cast<::NSUInteger>(location) longestEffectiveRange:(::NSRangePointer)(range)inRange:cocoon::internal::to(range_limit)]);
    }

    AttributedString AttributedString::attributed_string_by_inflecting_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSAttributedString>(this) attributedStringByInflectingString]);
    }

    AttributedString AttributedString::attributed_string_with_adaptive_image_glyph(const AdaptiveImageGlyph& adaptive_image_glyph, const std::map<std::string, Object>& attributes)
    {
        return cocoon::internal::wrap<AttributedString>([::NSAttributedString attributedStringWithAdaptiveImageGlyph:cocoon::internal::native<::NSAdaptiveImageGlyph>(adaptive_image_glyph)
                                                                                            attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                         {
                                                                                                                             return cocoon::internal::to(k);
                                                                                                                         },
                                                                                                                         [](const Object& v) -> id
                                                                                                                         {
                                                                                                                             return cocoon::internal::native_id(v);
                                                                                                                         })]);
    }

    AttributedString AttributedString::attributed_string_with_attachment(const TextAttachment& attachment)
    {
        return cocoon::internal::wrap<AttributedString>([::NSAttributedString attributedStringWithAttachment:cocoon::internal::native<::NSTextAttachment>(attachment)]);
    }

    AttributedString AttributedString::attributed_string_with_attachment(const TextAttachment& attachment, const std::map<std::string, Object>& attributes)
    {
        return cocoon::internal::wrap<AttributedString>([::NSAttributedString attributedStringWithAttachment:cocoon::internal::native<::NSTextAttachment>(attachment)
                                                                                    attributes:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::to(k);
                                                                                                                 },
                                                                                                                 [](const Object& v) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                 })]);
    }

    AttributedString AttributedString::attributed_substring_from_range(const Range& range) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSAttributedString>(this) attributedSubstringFromRange:cocoon::internal::to(range)]);
    }

    std::map<std::string, Object> AttributedString::attributes_at_index(std::uint64_t location, Range* range) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSAttributedString>(this) attributesAtIndex:static_cast<::NSUInteger>(location) effectiveRange:(::NSRangePointer)(range)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    std::map<std::string, Object> AttributedString::attributes_at_index(std::uint64_t location, Range* range, const Range& range_limit) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSAttributedString>(this) attributesAtIndex:static_cast<::NSUInteger>(location) longestEffectiveRange:(::NSRangePointer)(range)inRange:cocoon::internal::to(range_limit)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Rect AttributedString::bounding_rect_with_size(const Size& size, StringDrawingOptions options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) boundingRectWithSize:cocoon::internal::to(size) options:static_cast<::NSStringDrawingOptions>(options)]);
    }

    Rect AttributedString::bounding_rect_with_size(const Size& size, StringDrawingOptions options, const StringDrawingContext& context) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) boundingRectWithSize:cocoon::internal::to(size) options:static_cast<::NSStringDrawingOptions>(options) context:cocoon::internal::native<::NSStringDrawingContext>(context)]);
    }

    bool AttributedString::contains_attachments_in_range(const Range& range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedString>(this) containsAttachmentsInRange:cocoon::internal::to(range)]);
    }

    std::vector<std::uint8_t> AttributedString::data_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSAttributedString>(this) dataFromRange:cocoon::internal::to(range)
                                                  documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                       {
                                                                                           return cocoon::internal::to(k);
                                                                                       },
                                                                                       [](const Object& v) -> id
                                                                                       {
                                                                                           return cocoon::internal::native_id(v);
                                                                                       })
                                                               error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    std::vector<std::uint8_t> AttributedString::doc_format_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSAttributedString>(this) docFormatFromRange:cocoon::internal::to(range)
                                                                 documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::to(k);
                                                                                                      },
                                                                                                      [](const Object& v) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native_id(v);
                                                                                                      })]);
    }

    Range AttributedString::double_click_at_index(std::uint64_t location) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) doubleClickAtIndex:static_cast<::NSUInteger>(location)]);
    }

    void AttributedString::draw_at_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) drawAtPoint:cocoon::internal::to(point)];
    }

    void AttributedString::draw_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) drawInRect:cocoon::internal::to(rect)];
    }

    void AttributedString::draw_with_rect(const Rect& rect, StringDrawingOptions options) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) drawWithRect:cocoon::internal::to(rect) options:static_cast<::NSStringDrawingOptions>(options)];
    }

    void AttributedString::draw_with_rect(const Rect& rect, StringDrawingOptions options, const StringDrawingContext& context) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) drawWithRect:cocoon::internal::to(rect) options:static_cast<::NSStringDrawingOptions>(options) context:cocoon::internal::native<::NSStringDrawingContext>(context)];
    }

    void AttributedString::enumerate_attribute(const std::string& attr_name, const Range& enumeration_range, AttributedStringEnumerationOptions opts, std::function<void(Object, Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) enumerateAttribute:cocoon::internal::to(attr_name) inRange:cocoon::internal::to(enumeration_range) options:static_cast<::NSAttributedStringEnumerationOptions>(opts) usingBlock:(block ? (void (^)(id, ::NSRange, BOOL*)) ^ void(id a125_0, ::NSRange a125_1, ::BOOL * a125_2) { bool __o125_2 = a125_2 ? static_cast<bool>(*a125_2) : bool(); block(cocoon::internal::wrap<Object>(a125_0), cocoon::internal::from(a125_1), __o125_2); if (a125_2) { *a125_2 = static_cast<::BOOL>(__o125_2); } } : (void (^)(id, ::NSRange, BOOL*))nil)];
    }

    void AttributedString::enumerate_attributes_in_range(const Range& enumeration_range, AttributedStringEnumerationOptions opts, std::function<void(std::map<std::string, Object>, Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSAttributedString>(this) enumerateAttributesInRange:cocoon::internal::to(enumeration_range) options:static_cast<::NSAttributedStringEnumerationOptions>(opts) usingBlock:(block ? (void (^)(NSDictionary<NSAttributedStringKey, id>*, ::NSRange, BOOL*)) ^ void(NSDictionary * a126_0, ::NSRange a126_1, ::BOOL * a126_2) { bool __o126_2 = a126_2 ? static_cast<bool>(*a126_2) : bool(); block(cocoon::internal::from_dictionary<std::map<std::string, Object>>(a126_0, [](id k) -> std::string { return cocoon::internal::from((NSString *)k); }, [](id v) -> Object { return cocoon::internal::wrap<Object>(v); }), cocoon::internal::from(a126_1), __o126_2); if (a126_2) { *a126_2 = static_cast<::BOOL>(__o126_2); } } : (void (^)(NSDictionary<NSAttributedStringKey, id>*, ::NSRange, BOOL*))nil)];
    }

    FileWrapper AttributedString::file_wrapper_from_range(const Range& range, const std::map<std::string, Object>& dict) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSAttributedString>(this) fileWrapperFromRange:cocoon::internal::to(range)
                                                         documentAttributes:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                              {
                                                                                                  return cocoon::internal::to(k);
                                                                                              },
                                                                                              [](const Object& v) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(v);
                                                                                              })
                                                                      error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<FileWrapper>(__r);
    }

    std::map<std::string, Object> AttributedString::font_attributes_in_range(const Range& range) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSAttributedString>(this) fontAttributesInRange:cocoon::internal::to(range)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    bool AttributedString::is_equal_to_attributed_string(const AttributedString& other) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedString>(this) isEqualToAttributedString:cocoon::internal::native<::NSAttributedString>(other)]);
    }

    std::int64_t AttributedString::item_number_in_text_list(const TextList& list, std::uint64_t location) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAttributedString>(this) itemNumberInTextList:cocoon::internal::native<::NSTextList>(list) atIndex:static_cast<::NSUInteger>(location)]);
    }

    std::uint64_t AttributedString::line_break_before_index(std::uint64_t location, const Range& a_range) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSAttributedString>(this) lineBreakBeforeIndex:static_cast<::NSUInteger>(location) withinRange:cocoon::internal::to(a_range)]);
    }

    std::uint64_t AttributedString::line_break_by_hyphenating_before_index(std::uint64_t location, const Range& a_range) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSAttributedString>(this) lineBreakByHyphenatingBeforeIndex:static_cast<::NSUInteger>(location) withinRange:cocoon::internal::to(a_range)]);
    }

    std::uint64_t AttributedString::next_word_from_index(std::uint64_t location, bool is_forward) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSAttributedString>(this) nextWordFromIndex:static_cast<::NSUInteger>(location) forward:static_cast<::BOOL>(is_forward)]);
    }

    bool AttributedString::prefers_rtfd_in_range(const Range& range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedString>(this) prefersRTFDInRange:cocoon::internal::to(range)]);
    }

    Range AttributedString::range_of_text_block(const TextBlock& block, std::uint64_t location) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) rangeOfTextBlock:cocoon::internal::native<::NSTextBlock>(block) atIndex:static_cast<::NSUInteger>(location)]);
    }

    Range AttributedString::range_of_text_list(const TextList& list, std::uint64_t location) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) rangeOfTextList:cocoon::internal::native<::NSTextList>(list) atIndex:static_cast<::NSUInteger>(location)]);
    }

    Range AttributedString::range_of_text_table(const TextTable& table, std::uint64_t location) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) rangeOfTextTable:cocoon::internal::native<::NSTextTable>(table) atIndex:static_cast<::NSUInteger>(location)]);
    }

    std::map<std::string, Object> AttributedString::ruler_attributes_in_range(const Range& range) const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSAttributedString>(this) rulerAttributesInRange:cocoon::internal::to(range)], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    Size AttributedString::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) size]);
    }

    bool AttributedString::contains_attachments() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAttributedString>(this) containsAttachments]);
    }

    std::uint64_t AttributedString::length() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSAttributedString>(this) length]);
    }

    std::string AttributedString::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAttributedString>(this) string]);
    }

    std::vector<std::string> AttributedString::text_types()
    {
        return cocoon::internal::from_array<std::string>([::NSAttributedString textTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> AttributedString::text_unfiltered_types()
    {
        return cocoon::internal::from_array<std::string>([::NSAttributedString textUnfilteredTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
