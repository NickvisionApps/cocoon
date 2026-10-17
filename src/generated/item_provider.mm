#include "generated/item_provider.h"
#include "internal.h"

namespace cocoon
{
    ItemProvider::ItemProvider(const URL& file_url) : ItemProvider(Adopt{cocoon::internal::retain([[::NSItemProvider alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(file_url)])})
    {
    }

    ItemProvider::ItemProvider(const Object& item, const std::string& type_identifier) : ItemProvider(Adopt{cocoon::internal::retain([[::NSItemProvider alloc] initWithItem:cocoon::internal::native_id(item) typeIdentifier:cocoon::internal::to(type_identifier)])})
    {
    }

    ItemProvider::ItemProvider(const Object& object) : ItemProvider(Adopt{cocoon::internal::retain([[::NSItemProvider alloc] initWithObject:cocoon::internal::native_id(object)])})
    {
    }

    ItemProvider::ItemProvider() : ItemProvider(Adopt{cocoon::internal::retain([[::NSItemProvider alloc] init])})
    {
    }

    ItemProvider::ItemProvider(std::nullptr_t) : Object(nullptr)
    {
    }

    ItemProvider::ItemProvider(Adopt adopt) : Object(adopt)
    {
    }

    bool ItemProvider::can_load_object_of_class(const std::string& a_class) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSItemProvider>(this) canLoadObjectOfClass:NSClassFromString(cocoon::internal::to(a_class))]);
    }

    bool ItemProvider::has_item_conforming_to_type_identifier(const std::string& type_identifier) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSItemProvider>(this) hasItemConformingToTypeIdentifier:cocoon::internal::to(type_identifier)]);
    }

    bool ItemProvider::has_representation_conforming_to_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSItemProvider>(this) hasRepresentationConformingToTypeIdentifier:cocoon::internal::to(type_identifier) fileOptions:static_cast<::NSItemProviderFileOptions>(file_options)]);
    }

    Progress ItemProvider::load_data_representation_for_type_identifier(const std::string& type_identifier, std::function<void(std::vector<std::uint8_t>, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSItemProvider>(this) loadDataRepresentationForTypeIdentifier:cocoon::internal::to(type_identifier) completionHandler:(completion_handler ? (void (^)(::NSData*, ::NSError*)) ^ void(NSData * a169_0, ::NSError * a169_1) { completion_handler(cocoon::internal::from_data(a169_0), cocoon::internal::wrap<Error>(a169_1)); } : (void (^)(::NSData*, ::NSError*))nil)]);
    }

    Progress ItemProvider::load_file_representation_for_type_identifier(const std::string& type_identifier, std::function<void(URL, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSItemProvider>(this) loadFileRepresentationForTypeIdentifier:cocoon::internal::to(type_identifier) completionHandler:(completion_handler ? (void (^)(::NSURL*, ::NSError*)) ^ void(::NSURL * a170_0, ::NSError * a170_1) { completion_handler(cocoon::internal::wrap<URL>(a170_0), cocoon::internal::wrap<Error>(a170_1)); } : (void (^)(::NSURL*, ::NSError*))nil)]);
    }

    Progress ItemProvider::load_in_place_file_representation_for_type_identifier(const std::string& type_identifier, std::function<void(URL, bool, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSItemProvider>(this) loadInPlaceFileRepresentationForTypeIdentifier:cocoon::internal::to(type_identifier) completionHandler:(completion_handler ? (void (^)(::NSURL*, BOOL, ::NSError*)) ^ void(::NSURL * a171_0, ::BOOL a171_1, ::NSError * a171_2) { completion_handler(cocoon::internal::wrap<URL>(a171_0), static_cast<bool>(a171_1), cocoon::internal::wrap<Error>(a171_2)); } : (void (^)(::NSURL*, BOOL, ::NSError*))nil)]);
    }

    void ItemProvider::load_item_for_type_identifier(const std::string& type_identifier, const std::vector<std::pair<Object, Object>>& options, std::function<void(Object, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) loadItemForTypeIdentifier:cocoon::internal::to(type_identifier)
                                                          options:cocoon::internal::to_dictionary(options, [](const Object& k) -> id
                                                                                    {
                                                                                        return cocoon::internal::native_id(k);
                                                                                    },
                                                                                    [](const Object& v) -> id
                                                                                    {
                                                                                        return cocoon::internal::native_id(v);
                                                                                    })
                                                completionHandler:(completion_handler ? (::NSItemProviderCompletionHandler) ^ void(id a172_0, ::NSError * a172_1) { completion_handler(cocoon::internal::wrap<Object>(a172_0), cocoon::internal::wrap<Error>(a172_1)); } : (::NSItemProviderCompletionHandler)nil)];
    }

    Progress ItemProvider::load_object_of_class(const std::string& a_class, std::function<void(Object, Error)> completion_handler) const
    {
        return cocoon::internal::wrap<Progress>([cocoon::internal::ns<::NSItemProvider>(this) loadObjectOfClass:NSClassFromString(cocoon::internal::to(a_class)) completionHandler:(completion_handler ? (void (^)(__kindof id<NSItemProviderReading>, ::NSError*)) ^ void(id a173_0, ::NSError * a173_1) { completion_handler(cocoon::internal::wrap<Object>(a173_0), cocoon::internal::wrap<Error>(a173_1)); } : (void (^)(__kindof id<NSItemProviderReading>, ::NSError*))nil)]);
    }

    void ItemProvider::load_preview_image_with_options(const std::vector<std::pair<Object, Object>>& options, std::function<void(Object, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) loadPreviewImageWithOptions:cocoon::internal::to_dictionary(options, [](const Object& k) -> id
                                                                                      {
                                                                                          return cocoon::internal::native_id(k);
                                                                                      },
                                                                                      [](const Object& v) -> id
                                                                                      {
                                                                                          return cocoon::internal::native_id(v);
                                                                                      })
                                                  completionHandler:(completion_handler ? (::NSItemProviderCompletionHandler) ^ void(id a174_0, ::NSError * a174_1) { completion_handler(cocoon::internal::wrap<Object>(a174_0), cocoon::internal::wrap<Error>(a174_1)); } : (::NSItemProviderCompletionHandler)nil)];
    }

    void ItemProvider::register_cloud_kit_share(const Object& share, const Object& container) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerCloudKitShare:cocoon::internal::native_id(share) container:cocoon::internal::native_id(container)];
    }

    void ItemProvider::register_cloud_kit_share_with_preparation_handler(std::function<void(std::function<void(Object, Object, Error)>)> preparation_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerCloudKitShareWithPreparationHandler:(preparation_handler ? (void (^)(void (^)(::CKShare*, ::CKContainer*, ::NSError*))) ^ void(id a175_0) { preparation_handler([&]() -> std::function<void(Object, Object, Error)>
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    auto blk = (void (^)(::CKShare*, ::CKContainer*, ::NSError*))(a175_0);
                                                                                                                                                                                                                    if (!blk)
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        return {};
                                                                                                                                                                                                                    }
                                                                                                                                                                                                                    return [blk](Object a176_0, Object a176_1, Error a176_2) -> void
                                                                                                                                                                                                                    {
                                                                                                                                                                                                                        blk(cocoon::internal::native_id(a176_0), cocoon::internal::native_id(a176_1), cocoon::internal::native<::NSError>(a176_2));
                                                                                                                                                                                                                    };
                                                                                                                                                                                                                }()); } : (void (^)(void (^)(::CKShare*, ::CKContainer*, ::NSError*)))nil)];
    }

    void ItemProvider::register_data_representation_for_type_identifier(const std::string& type_identifier, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(std::vector<std::uint8_t>, Error)>)> load_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerDataRepresentationForTypeIdentifier:cocoon::internal::to(type_identifier) visibility:static_cast<::NSItemProviderRepresentationVisibility>(visibility) loadHandler:(load_handler ? (::NSProgress * (^)(void (^)(::NSData*, ::NSError*))) ^ ::NSProgress * (id a177_0) { auto __r = load_handler([&]() -> std::function<void(std::vector<std::uint8_t>, Error)> { auto blk = (void (^)(::NSData * , ::NSError * ))(a177_0); if (!blk) { return {}; } return [blk](std::vector<std::uint8_t> a178_0, Error a178_1) -> void { blk(cocoon::internal::to_data(a178_0), cocoon::internal::native<::NSError>(a178_1)); }; }()); return cocoon::internal::native<::NSProgress>(__r); } : (::NSProgress * (^)(void (^)(::NSData*, ::NSError*))) nil)];
    }

    void ItemProvider::register_file_representation_for_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(URL, bool, Error)>)> load_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerFileRepresentationForTypeIdentifier:cocoon::internal::to(type_identifier) fileOptions:static_cast<::NSItemProviderFileOptions>(file_options) visibility:static_cast<::NSItemProviderRepresentationVisibility>(visibility) loadHandler:(load_handler ? (::NSProgress * (^)(void (^)(::NSURL*, BOOL, ::NSError*))) ^ ::NSProgress * (id a179_0) { auto __r = load_handler([&]() -> std::function<void(URL, bool, Error)> { auto blk = (void (^)(::NSURL * , BOOL, ::NSError * ))(a179_0); if (!blk) { return {}; } return [blk](URL a180_0, bool a180_1, Error a180_2) -> void { blk(cocoon::internal::native<::NSURL>(a180_0), static_cast<::BOOL>(a180_1), cocoon::internal::native<::NSError>(a180_2)); }; }()); return cocoon::internal::native<::NSProgress>(__r); } : (::NSProgress * (^)(void (^)(::NSURL*, BOOL, ::NSError*))) nil)];
    }

    void ItemProvider::register_item_for_type_identifier(const std::string& type_identifier, std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> load_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerItemForTypeIdentifier:cocoon::internal::to(type_identifier) loadHandler:(load_handler ? (::NSItemProviderLoadHandler) ^ void(id a181_0, Class a181_1, NSDictionary * a181_2) { load_handler([&]() -> std::function<void(Object, Error)>
                                                                                                                                                                                                                              {
                                                                                                                                                                                                                                  auto blk = (::NSItemProviderCompletionHandler)(a181_0);
                                                                                                                                                                                                                                  if (!blk)
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                      return {};
                                                                                                                                                                                                                                  }
                                                                                                                                                                                                                                  return [blk](Object a182_0, Error a182_1) -> void
                                                                                                                                                                                                                                  {
                                                                                                                                                                                                                                      blk(cocoon::internal::native_id(a182_0), cocoon::internal::native<::NSError>(a182_1));
                                                                                                                                                                                                                                  };
                                                                                                                                                                                                                              }(),
                                                                                                                                                                                                                              cocoon::internal::from(NSStringFromClass(a181_1)), cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>(a181_2, [](id k) -> Object
                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<Object>(k);
                                                                                                                                                                                                                                                                                                                               },
                                                                                                                                                                                                                                                                                                                               [](id v) -> Object
                                                                                                                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                                                                                                                   return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                                                                               })); } : (::NSItemProviderLoadHandler)nil)];
    }

    void ItemProvider::register_object(const Object& object, ItemProviderRepresentationVisibility visibility) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerObject:cocoon::internal::native_id(object) visibility:static_cast<::NSItemProviderRepresentationVisibility>(visibility)];
    }

    void ItemProvider::register_object_of_class(const std::string& a_class, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(Object, Error)>)> load_handler) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) registerObjectOfClass:NSClassFromString(cocoon::internal::to(a_class)) visibility:static_cast<::NSItemProviderRepresentationVisibility>(visibility) loadHandler:(load_handler ? (::NSProgress * (^)(void (^)(__kindof id<NSItemProviderWriting>, ::NSError*))) ^ ::NSProgress * (id a183_0) { auto __r = load_handler([&]() -> std::function<void(Object, Error)> { auto blk = (void (^)( id<NSItemProviderWriting> , ::NSError * ))(a183_0); if (!blk) { return {}; } return [blk](Object a184_0, Error a184_1) -> void { blk(cocoon::internal::native_id(a184_0), cocoon::internal::native<::NSError>(a184_1)); }; }()); return cocoon::internal::native<::NSProgress>(__r); } : (::NSProgress * (^)(void (^)(__kindof id<NSItemProviderWriting>, ::NSError*))) nil)];
    }

    std::vector<std::string> ItemProvider::registered_type_identifiers_with_file_options(ItemProviderFileOptions file_options) const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSItemProvider>(this) registeredTypeIdentifiersWithFileOptions:static_cast<::NSItemProviderFileOptions>(file_options)], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    Rect ItemProvider::container_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSItemProvider>(this) containerFrame]);
    }

    Size ItemProvider::preferred_presentation_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSItemProvider>(this) preferredPresentationSize]);
    }

    std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> ItemProvider::preview_image_handler() const
    {
        return [&]() -> std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)>
        {
            auto blk = (::NSItemProviderLoadHandler)([cocoon::internal::ns<::NSItemProvider>(this) previewImageHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](std::function<void(Object, Error)> a185_0, std::string a185_1, std::vector<std::pair<Object, Object>> a185_2) -> void
            {
                blk((a185_0 ? (::NSItemProviderCompletionHandler) ^ void(id a186_0, ::NSError * a186_1) { a185_0(cocoon::internal::wrap<Object>(a186_0), cocoon::internal::wrap<Error>(a186_1)); } : (::NSItemProviderCompletionHandler)nil), NSClassFromString(cocoon::internal::to(a185_1)), cocoon::internal::to_dictionary(a185_2, [](const Object& k) -> id
                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                           return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                                       },
                                                                                                                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                                                                                                                       {
                                                                                                                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                       }));
            };
        }();
    }

    void ItemProvider::set_preview_image_handler(std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> value) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) setPreviewImageHandler:(value ? (::NSItemProviderLoadHandler) ^ void(id a187_0, Class a187_1, NSDictionary * a187_2) { value([&]() -> std::function<void(Object, Error)>
                                                                                                                                                                     {
                                                                                                                                                                         auto blk = (::NSItemProviderCompletionHandler)(a187_0);
                                                                                                                                                                         if (!blk)
                                                                                                                                                                         {
                                                                                                                                                                             return {};
                                                                                                                                                                         }
                                                                                                                                                                         return [blk](Object a188_0, Error a188_1) -> void
                                                                                                                                                                         {
                                                                                                                                                                             blk(cocoon::internal::native_id(a188_0), cocoon::internal::native<::NSError>(a188_1));
                                                                                                                                                                         };
                                                                                                                                                                     }(),
                                                                                                                                                                     cocoon::internal::from(NSStringFromClass(a187_1)), cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>(a187_2, [](id k) -> Object
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                          return cocoon::internal::wrap<Object>(k);
                                                                                                                                                                                                                                                                      },
                                                                                                                                                                                                                                                                      [](id v) -> Object
                                                                                                                                                                                                                                                                      {
                                                                                                                                                                                                                                                                          return cocoon::internal::wrap<Object>(v);
                                                                                                                                                                                                                                                                      })); } : (::NSItemProviderLoadHandler)nil)];
    }

    std::vector<std::string> ItemProvider::registered_type_identifiers() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSItemProvider>(this) registeredTypeIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    Rect ItemProvider::source_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSItemProvider>(this) sourceFrame]);
    }

    std::string ItemProvider::suggested_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSItemProvider>(this) suggestedName]);
    }

    void ItemProvider::set_suggested_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSItemProvider>(this) setSuggestedName:cocoon::internal::to(value)];
    }
}
