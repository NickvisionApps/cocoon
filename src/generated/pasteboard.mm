#include "generated/pasteboard.h"
#include "internal.h"

namespace cocoon
{
    Pasteboard::Pasteboard(const std::string& name) : Pasteboard(Adopt{cocoon::internal::retain([::NSPasteboard pasteboardWithName:cocoon::internal::to(name)])})
    {
    }

    Pasteboard::Pasteboard() : Pasteboard(Adopt{cocoon::internal::retain([::NSPasteboard pasteboardWithUniqueName])})
    {
    }

    Pasteboard::Pasteboard(std::nullptr_t) : Object(nullptr)
    {
    }

    Pasteboard::Pasteboard(Adopt adopt) : Object(adopt)
    {
    }

    std::int64_t Pasteboard::add_types(const std::vector<std::string>& new_types, const Object& new_owner) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPasteboard>(this) addTypes:cocoon::internal::to_array(new_types, [](const std::string& e) -> id
                                                                                                                         {
                                                                                                                             return cocoon::internal::to(e);
                                                                                                                         })
                                                                                        owner:cocoon::internal::native_id(new_owner)]);
    }

    std::string Pasteboard::available_type_from_array(const std::vector<std::string>& types) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboard>(this) availableTypeFromArray:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                                    {
                                                                                                                                        return cocoon::internal::to(e);
                                                                                                                                    })]);
    }

    bool Pasteboard::can_read_item_with_data_conforming_to_types(const std::vector<std::string>& types) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) canReadItemWithDataConformingToTypes:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                                             {
                                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                                             })]);
    }

    bool Pasteboard::can_read_object_for_classes(const std::vector<std::string>& class_array, const std::map<std::string, Object>& options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) canReadObjectForClasses:cocoon::internal::to_array(class_array, [](const std::string& e) -> id
                                                                                                                                {
                                                                                                                                    return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                })
                                                                                             options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                     {
                                                                                                                                         return cocoon::internal::to(k);
                                                                                                                                     },
                                                                                                                                     [](const Object& v) -> id
                                                                                                                                     {
                                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                                     })]);
    }

    std::int64_t Pasteboard::clear_contents() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPasteboard>(this) clearContents]);
    }

    std::vector<std::uint8_t> Pasteboard::data_for_type(const std::string& data_type) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSPasteboard>(this) dataForType:cocoon::internal::to(data_type)]);
    }

    std::int64_t Pasteboard::declare_types(const std::vector<std::string>& new_types, const Object& new_owner) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPasteboard>(this) declareTypes:cocoon::internal::to_array(new_types, [](const std::string& e) -> id
                                                                                                                             {
                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                             })
                                                                                            owner:cocoon::internal::native_id(new_owner)]);
    }

    void Pasteboard::detect_metadata_for_types(const std::vector<std::string>& types, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboard>(this) detectMetadataForTypes:[NSSet setWithArray:cocoon::internal::to_array(types, [](const std::string& e) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::to(e);
                                                                                                                          })]
                                                         completionHandler:(completion_handler ? (void (^)(NSDictionary<NSPasteboardMetadataType, id>*, ::NSError*)) ^ void(NSDictionary * a67_0, ::NSError * a67_1) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, Object>>(a67_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                               return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                           },
                                                                                                                                                                                                                                                                                                           [](id v) -> Object
                                                                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                                                                               return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                                                           }),
                                                                                                                                                                                                                                          cocoon::internal::wrap<Error>(a67_1)); } : (void (^)(NSDictionary<NSPasteboardMetadataType, id>*, ::NSError*))nil)];
    }

    void Pasteboard::detect_patterns_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::vector<std::string>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboard>(this) detectPatternsForPatterns:[NSSet setWithArray:cocoon::internal::to_array(patterns, [](const std::string& e) -> id
                                                                                                                             {
                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                             })]
                                                            completionHandler:(completion_handler ? (void (^)(NSSet<NSPasteboardDetectionPattern>*, ::NSError*)) ^ void(NSSet * a68_0, ::NSError * a68_1) { completion_handler(cocoon::internal::from_array<std::string>([a68_0 allObjects], [](id e) -> std::string
                                                                                                                                                                                                                                                                         {
                                                                                                                                                                                                                                                                             return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                                         }),
                                                                                                                                                                                                                               cocoon::internal::wrap<Error>(a68_1)); } : (void (^)(NSSet<NSPasteboardDetectionPattern>*, ::NSError*))nil)];
    }

    void Pasteboard::detect_values_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSPasteboard>(this) detectValuesForPatterns:[NSSet setWithArray:cocoon::internal::to_array(patterns, [](const std::string& e) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::to(e);
                                                                                                                           })]
                                                          completionHandler:(completion_handler ? (void (^)(NSDictionary<NSPasteboardDetectionPattern, id>*, ::NSError*)) ^ void(NSDictionary * a69_0, ::NSError * a69_1) { completion_handler(cocoon::internal::from_dictionary<std::map<std::string, Object>>(a69_0, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                },
                                                                                                                                                                                                                                                                                                                [](id v) -> Object
                                                                                                                                                                                                                                                                                                                {
                                                                                                                                                                                                                                                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                                                                }),
                                                                                                                                                                                                                                               cocoon::internal::wrap<Error>(a69_1)); } : (void (^)(NSDictionary<NSPasteboardDetectionPattern, id>*, ::NSError*))nil)];
    }

    std::uint64_t Pasteboard::index_of_pasteboard_item(const PasteboardItem& pasteboard_item) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPasteboard>(this) indexOfPasteboardItem:cocoon::internal::native<::NSPasteboardItem>(pasteboard_item)]);
    }

    Pasteboard Pasteboard::pasteboard_by_filtering_data(const std::vector<std::uint8_t>& data, const std::string& type)
    {
        return cocoon::internal::wrap<Pasteboard>([::NSPasteboard pasteboardByFilteringData:cocoon::internal::to_data(data) ofType:cocoon::internal::to(type)]);
    }

    Pasteboard Pasteboard::pasteboard_by_filtering_file(const std::string& filename)
    {
        return cocoon::internal::wrap<Pasteboard>([::NSPasteboard pasteboardByFilteringFile:cocoon::internal::to(filename)]);
    }

    Pasteboard Pasteboard::pasteboard_by_filtering_types_in_pasteboard(const Pasteboard& pboard)
    {
        return cocoon::internal::wrap<Pasteboard>([::NSPasteboard pasteboardByFilteringTypesInPasteboard:cocoon::internal::native<::NSPasteboard>(pboard)]);
    }

    std::int64_t Pasteboard::prepare_for_new_contents_with_options(PasteboardContentsOptions options) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPasteboard>(this) prepareForNewContentsWithOptions:static_cast<::NSPasteboardContentsOptions>(options)]);
    }

    Object Pasteboard::property_list_for_type(const std::string& data_type) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPasteboard>(this) propertyListForType:cocoon::internal::to(data_type)]);
    }

    std::string Pasteboard::read_file_contents_type(const std::string& type, const std::string& filename) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboard>(this) readFileContentsType:cocoon::internal::to(type) toFile:cocoon::internal::to(filename)]);
    }

    FileWrapper Pasteboard::read_file_wrapper() const
    {
        return cocoon::internal::wrap<FileWrapper>([cocoon::internal::ns<::NSPasteboard>(this) readFileWrapper]);
    }

    std::vector<Object> Pasteboard::read_objects_for_classes(const std::vector<std::string>& class_array, const std::map<std::string, Object>& options) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSPasteboard>(this) readObjectsForClasses:cocoon::internal::to_array(class_array, [](const std::string& e) -> id
                                                                                                                                                 {
                                                                                                                                                     return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                                 })
                                                                                                              options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                      {
                                                                                                                                                          return cocoon::internal::to(k);
                                                                                                                                                      },
                                                                                                                                                      [](const Object& v) -> id
                                                                                                                                                      {
                                                                                                                                                          return cocoon::internal::native_id(v);
                                                                                                                                                      })],
                                                    [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void Pasteboard::release_globally() const
    {
        [cocoon::internal::ns<::NSPasteboard>(this) releaseGlobally];
    }

    bool Pasteboard::set_data(const std::vector<std::uint8_t>& data, const std::string& data_type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) setData:cocoon::internal::to_data(data) forType:cocoon::internal::to(data_type)]);
    }

    bool Pasteboard::set_property_list(const Object& plist, const std::string& data_type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) setPropertyList:cocoon::internal::native_id(plist) forType:cocoon::internal::to(data_type)]);
    }

    bool Pasteboard::set_string(const std::string& string, const std::string& data_type) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) setString:cocoon::internal::to(string) forType:cocoon::internal::to(data_type)]);
    }

    std::string Pasteboard::string_for_type(const std::string& data_type) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboard>(this) stringForType:cocoon::internal::to(data_type)]);
    }

    std::vector<std::string> Pasteboard::types_filterable_to(const std::string& type)
    {
        return cocoon::internal::from_array<std::string>([::NSPasteboard typesFilterableTo:cocoon::internal::to(type)], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool Pasteboard::write_file_contents(const std::string& filename) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) writeFileContents:cocoon::internal::to(filename)]);
    }

    bool Pasteboard::write_file_wrapper(const FileWrapper& wrapper) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) writeFileWrapper:cocoon::internal::native<::NSFileWrapper>(wrapper)]);
    }

    bool Pasteboard::write_objects(const std::vector<Object>& objects) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPasteboard>(this) writeObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::native_id(e);
                                                                                                                     })]);
    }

    PasteboardAccessBehavior Pasteboard::access_behavior() const
    {
        return static_cast<PasteboardAccessBehavior>([cocoon::internal::ns<::NSPasteboard>(this) accessBehavior]);
    }

    std::int64_t Pasteboard::change_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPasteboard>(this) changeCount]);
    }

    Pasteboard Pasteboard::general_pasteboard()
    {
        return cocoon::internal::wrap<Pasteboard>([::NSPasteboard generalPasteboard]);
    }

    std::string Pasteboard::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPasteboard>(this) name]);
    }

    std::vector<PasteboardItem> Pasteboard::pasteboard_items() const
    {
        return cocoon::internal::from_array<PasteboardItem>([cocoon::internal::ns<::NSPasteboard>(this) pasteboardItems], [](id e) -> PasteboardItem
                                                            {
                                                                return cocoon::internal::wrap<PasteboardItem>((::NSPasteboardItem*)e);
                                                            });
    }

    std::vector<std::string> Pasteboard::types() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSPasteboard>(this) types], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }
}
