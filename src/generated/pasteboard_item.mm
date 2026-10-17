#include "generated/pasteboard_item.h"
#include "internal.h"

namespace cocoon
{
    PasteboardItem::PasteboardItem() : PasteboardItem(Adopt{cocoon::internal::retain([[::NSPasteboardItem alloc] init])})
    {
    }

    PasteboardItem::PasteboardItem(std::nullptr_t) : Object(nullptr)
    {
    }

    PasteboardItem::PasteboardItem(Adopt adopt) : Object(adopt)
    {
    }

    std::string PasteboardItem::available_type_from_array(const std::vector<std::string>& types) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboardItem>(this) availableTypeFromArray:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                                        {
                                                                                                                                            return cocoon::internal::to(e);
                                                                                                                                        })]);
    }

    std::vector<std::uint8_t> PasteboardItem::data_for_type(const std::string& type) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSPasteboardItem>(this) dataForType:cocoon::internal::to(type)]);
    }

    void PasteboardItem::detect_metadata_for_types(const std::vector<std::string>& types, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboardItem>(this) detectMetadataForTypes:[NSSet setWithArray:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                              {
                                                                                                                                  return cocoon::internal::to(e);
                                                                                                                              })]
                                                             completionHandler:(completion_handler ? (void (^)(NSDictionary<NSPasteboardMetadataType, id>*, ::NSError*)) ^ void(NSDictionary * a70_0, ::NSError * a70_1) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, Object>>(a70_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                   return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                               },
                                                                                                                                                                                                                                                                                                               [](id v) -> Object
                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                                                               }),
                                                                                                                                                                                                                                              cocoon::internal::wrap<Error>(a70_1)); } : (void (^)(NSDictionary<NSPasteboardMetadataType, id>*, ::NSError*))nil)];
    }

    void PasteboardItem::detect_patterns_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::vector<std::string>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboardItem>(this) detectPatternsForPatterns:[NSSet setWithArray:cocoon::internal::to_array(patterns, [](const std::string& e) -> id
                                                                                                                                 {
                                                                                                                                     return cocoon::internal::to(e);
                                                                                                                                 })]
                                                                completionHandler:(completion_handler ? (void (^)(NSSet<NSPasteboardDetectionPattern>*, ::NSError*)) ^ void(NSSet * a71_0, ::NSError * a71_1) { completion_handler(cocoon::internal::from_array<std::string>([a71_0 allObjects], [](id e) -> std::string
                                                                                                                                                                                                                                                                             {
                                                                                                                                                                                                                                                                                 return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                             }),
                                                                                                                                                                                                                                   cocoon::internal::wrap<Error>(a71_1)); } : (void (^)(NSSet<NSPasteboardDetectionPattern>*, ::NSError*))nil)];
    }

    void PasteboardItem::detect_values_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboardItem>(this) detectValuesForPatterns:[NSSet setWithArray:cocoon::internal::to_array(patterns, [](const std::string& e) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::to(e);
                                                                                                                               })]
                                                              completionHandler:(completion_handler ? (void (^)(NSDictionary<NSPasteboardDetectionPattern, id>*, ::NSError*)) ^ void(NSDictionary * a72_0, ::NSError * a72_1) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, Object>>(a72_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                        return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                    },
                                                                                                                                                                                                                                                                                                                    [](id v) -> Object
                                                                                                                                                                                                                                                                                                                    {
                                                                                                                                                                                                                                                                                                                        return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                                                                    }),
                                                                                                                                                                                                                                                   cocoon::internal::wrap<Error>(a72_1)); } : (void (^)(NSDictionary<NSPasteboardDetectionPattern, id>*, ::NSError*))nil)];
    }

    Object PasteboardItem::property_list_for_type(const std::string& type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPasteboardItem>(this) propertyListForType:cocoon::internal::to(type)]);
    }

    bool PasteboardItem::set_data(const std::vector<std::uint8_t>& data, const std::string& type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboardItem>(this) setData:cocoon::internal::to_data(data) forType:cocoon::internal::to(type)]);
    }

    bool PasteboardItem::set_data_provider(const Object& data_provider, const std::vector<std::string>& types) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboardItem>(this) setDataProvider:cocoon::internal::native_id(data_provider)
                                                                                        forTypes:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                            {
                                                                                                                                return cocoon::internal::to(e);
                                                                                                                            })]);
    }

    bool PasteboardItem::set_property_list(const Object& property_list, const std::string& type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboardItem>(this) setPropertyList:cocoon::internal::native_id(property_list) forType:cocoon::internal::to(type)]);
    }

    bool PasteboardItem::set_string(const std::string& string, const std::string& type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboardItem>(this) setString:cocoon::internal::to(string) forType:cocoon::internal::to(type)]);
    }

    std::string PasteboardItem::string_for_type(const std::string& type) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboardItem>(this) stringForType:cocoon::internal::to(type)]);
    }

    std::vector<std::string> PasteboardItem::types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPasteboardItem>(this) types], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }
}
