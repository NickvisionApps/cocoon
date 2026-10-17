#include "generated/keyed_unarchiver.h"
#include "internal.h"

@interface AKKeyedUnarchiverDelegate : NSObject <NSKeyedUnarchiverDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKKeyedUnarchiverDelegate

- (Class)unarchiver:(NSKeyedUnarchiver*)unarchiver cannotDecodeObjectOfClassName:(NSString*)name originalClasses:(NSArray<NSString*>*)classNames
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::KeyedUnarchiver, std::string(std::string, std::vector<std::string>)>::emit((__bridge void*)strongHost, "unarchiver_cannot_decode_object_of_class_name_original_classes", cocoon::internal::from(name), cocoon::internal::from_array<std::string>(classNames, [](id e) -> std::string
                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                               return cocoon::internal::from((NSString*)e);
                                                                                                                                                                                                                                                           }));
    return NSClassFromString(cocoon::internal::to(__r));
}

- (id)unarchiver:(NSKeyedUnarchiver*)unarchiver didDecodeObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::KeyedUnarchiver, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "unarchiver_did_decode_object", cocoon::internal::wrap<cocoon::Object>(object));
    return cocoon::internal::native_id(__r);
}

- (void)unarchiver:(NSKeyedUnarchiver*)unarchiver willReplaceObject:(id)object withObject:(id)newObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedUnarchiver, void(cocoon::Object, cocoon::Object)>::emit((__bridge void*)strongHost, "unarchiver_will_replace_object_with_object", cocoon::internal::wrap<cocoon::Object>(object), cocoon::internal::wrap<cocoon::Object>(newObject));
}

- (void)unarchiverWillFinish:(NSKeyedUnarchiver*)unarchiver
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedUnarchiver, void()>::emit((__bridge void*)strongHost, "unarchiver_will_finish");
}

- (void)unarchiverDidFinish:(NSKeyedUnarchiver*)unarchiver
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedUnarchiver, void()>::emit((__bridge void*)strongHost, "unarchiver_did_finish");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(unarchiver:cannotDecodeObjectOfClassName:originalClasses:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedUnarchiver, std::string(std::string, std::vector<std::string>)>::connected((__bridge void*)strongHost, "unarchiver_cannot_decode_object_of_class_name_original_classes");
    }
    if (selector == @selector(unarchiver:didDecodeObject:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedUnarchiver, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "unarchiver_did_decode_object");
    }
    if (selector == @selector(unarchiver:willReplaceObject:withObject:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedUnarchiver, void(cocoon::Object, cocoon::Object)>::connected((__bridge void*)strongHost, "unarchiver_will_replace_object_with_object");
    }
    if (selector == @selector(unarchiverWillFinish:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedUnarchiver, void()>::connected((__bridge void*)strongHost, "unarchiver_will_finish");
    }
    if (selector == @selector(unarchiverDidFinish:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedUnarchiver, void()>::connected((__bridge void*)strongHost, "unarchiver_did_finish");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    KeyedUnarchiver::KeyedUnarchiver(const std::vector<std::uint8_t>& data) : KeyedUnarchiver(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                               {
                                                                                                                   NSError* __error = nil;
                                                                                                                   id __r = [[::NSKeyedUnarchiver alloc] initForReadingFromData:cocoon::internal::to_data(data) error:&__error];
                                                                                                                   if (!__r && __error)
                                                                                                                   {
                                                                                                                       throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                   }
                                                                                                                   return __r;
                                                                                                               }())})
    {
        KeyedUnarchiver::install_delegate_delegate_(handle());
    }

    KeyedUnarchiver::KeyedUnarchiver() : KeyedUnarchiver(Adopt{cocoon::internal::retain([[::NSKeyedUnarchiver alloc] init])})
    {
        KeyedUnarchiver::install_delegate_delegate_(handle());
    }

    KeyedUnarchiver::KeyedUnarchiver(std::nullptr_t) : Coder(nullptr)
    {
    }

    KeyedUnarchiver::KeyedUnarchiver(Adopt adopt) : Coder(adopt)
    {
    }

    std::string KeyedUnarchiver::class_for_class_name(const std::string& coded_name) const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSKeyedUnarchiver>(this) classForClassName:cocoon::internal::to(coded_name)]));
    }

    bool KeyedUnarchiver::contains_value_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) containsValueForKey:cocoon::internal::to(key)]);
    }

    bool KeyedUnarchiver::decode_bool_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeBoolForKey:cocoon::internal::to(key)]);
    }

    const std::uint8_t* KeyedUnarchiver::decode_bytes_for_key(const std::string& key, std::uint64_t* lengthp) const
    {
        return (const std::uint8_t*)([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeBytesForKey:cocoon::internal::to(key) returnedLength:(::NSUInteger*)(lengthp)]);
    }

    double KeyedUnarchiver::decode_double_for_key(const std::string& key) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeDoubleForKey:cocoon::internal::to(key)]);
    }

    float KeyedUnarchiver::decode_float_for_key(const std::string& key) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeFloatForKey:cocoon::internal::to(key)]);
    }

    int KeyedUnarchiver::decode_int32_for_key(const std::string& key) const
    {
        return static_cast<int>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeInt32ForKey:cocoon::internal::to(key)]);
    }

    std::int64_t KeyedUnarchiver::decode_int64_for_key(const std::string& key) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeInt64ForKey:cocoon::internal::to(key)]);
    }

    int KeyedUnarchiver::decode_int_for_key(const std::string& key) const
    {
        return static_cast<int>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeIntForKey:cocoon::internal::to(key)]);
    }

    Object KeyedUnarchiver::decode_object_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodeObjectForKey:cocoon::internal::to(key)]);
    }

    void KeyedUnarchiver::finish_decoding() const
    {
        [cocoon::internal::ns<::NSKeyedUnarchiver>(this) finishDecoding];
    }

    void KeyedUnarchiver::set_class(const std::string& cls, const std::string& coded_name) const
    {
        [cocoon::internal::ns<::NSKeyedUnarchiver>(this) setClass:NSClassFromString(cocoon::internal::to(cls)) forClassName:cocoon::internal::to(coded_name)];
    }

    Object KeyedUnarchiver::unarchive_object_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<Object>([::NSKeyedUnarchiver unarchiveObjectWithData:cocoon::internal::to_data(data)]);
    }

    Object KeyedUnarchiver::unarchive_object_with_file(const std::string& path)
    {
        return cocoon::internal::wrap<Object>([::NSKeyedUnarchiver unarchiveObjectWithFile:cocoon::internal::to(path)]);
    }

    Object KeyedUnarchiver::unarchive_top_level_object_with_data(const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchiveTopLevelObjectWithData:cocoon::internal::to_data(data) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    std::vector<Object> KeyedUnarchiver::unarchived_array_of_objects_of_class(const std::string& cls, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedArrayOfObjectsOfClass:NSClassFromString(cocoon::internal::to(cls)) fromData:cocoon::internal::to_data(data) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<Object>(__r, [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<Object> KeyedUnarchiver::unarchived_array_of_objects_of_classes(const std::vector<std::string>& classes, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedArrayOfObjectsOfClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                                           {
                                                                                                               return NSClassFromString(cocoon::internal::to(e));
                                                                                                           })]
                                                                 fromData:cocoon::internal::to_data(data)
                                                                    error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<Object>(__r, [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<std::pair<Object, Object>> KeyedUnarchiver::unarchived_dictionary_with_keys_of_class(const std::string& key_cls, const std::string& value_cls, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedDictionaryWithKeysOfClass:NSClassFromString(cocoon::internal::to(key_cls)) objectsOfClass:NSClassFromString(cocoon::internal::to(value_cls)) fromData:cocoon::internal::to_data(data) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>(__r, [](id k) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(k);
                                                                           },
                                                                           [](id v) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(v);
                                                                           });
    }

    std::vector<std::pair<Object, Object>> KeyedUnarchiver::unarchived_dictionary_with_keys_of_classes(const std::vector<std::string>& key_classes, const std::vector<std::string>& value_classes, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedDictionaryWithKeysOfClasses:[NSSet setWithArray:cocoon::internal::to_array(key_classes, [](const std::string& e) -> id
                                                                                                               {
                                                                                                                   return NSClassFromString(cocoon::internal::to(e));
                                                                                                               })]
                                                             objectsOfClasses:[NSSet setWithArray:cocoon::internal::to_array(value_classes, [](const std::string& e) -> id
                                                                                                               {
                                                                                                                   return NSClassFromString(cocoon::internal::to(e));
                                                                                                               })]
                                                                     fromData:cocoon::internal::to_data(data)
                                                                        error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>(__r, [](id k) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(k);
                                                                           },
                                                                           [](id v) -> Object
                                                                           {
                                                                               return cocoon::internal::wrap<Object>(v);
                                                                           });
    }

    Object KeyedUnarchiver::unarchived_object_of_class(const std::string& cls, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedObjectOfClass:NSClassFromString(cocoon::internal::to(cls)) fromData:cocoon::internal::to_data(data) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object KeyedUnarchiver::unarchived_object_of_classes(const std::vector<std::string>& classes, const std::vector<std::uint8_t>& data)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedUnarchiver unarchivedObjectOfClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                                   {
                                                                                                       return NSClassFromString(cocoon::internal::to(e));
                                                                                                   })]
                                                         fromData:cocoon::internal::to_data(data)
                                                            error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    DecodingFailurePolicy KeyedUnarchiver::decoding_failure_policy() const
    {
        return static_cast<DecodingFailurePolicy>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) decodingFailurePolicy]);
    }

    void KeyedUnarchiver::set_decoding_failure_policy(DecodingFailurePolicy value) const
    {
        [cocoon::internal::ns<::NSKeyedUnarchiver>(this) setDecodingFailurePolicy:static_cast<::NSDecodingFailurePolicy>(value)];
    }

    bool KeyedUnarchiver::requires_secure_coding() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSKeyedUnarchiver>(this) requiresSecureCoding]);
    }

    void KeyedUnarchiver::set_requires_secure_coding(bool value) const
    {
        [cocoon::internal::ns<::NSKeyedUnarchiver>(this) setRequiresSecureCoding:static_cast<::BOOL>(value)];
    }

    void KeyedUnarchiver::install_delegate_delegate_(void* native)
    {
        ::NSKeyedUnarchiver* host = (__bridge ::NSKeyedUnarchiver*)native;
        AKKeyedUnarchiverDelegate* delegate = [[AKKeyedUnarchiverDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSKeyedUnarchiver* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSKeyedUnarchiver* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
