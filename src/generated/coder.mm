#include "generated/coder.h"
#include "internal.h"

namespace cocoon
{
    Coder::Coder() : Coder(Adopt{cocoon::internal::retain([[::NSCoder alloc] init])})
    {
    }

    Coder::Coder(std::nullptr_t) : Object(nullptr)
    {
    }

    Coder::Coder(Adopt adopt) : Object(adopt)
    {
    }

    bool Coder::contains_value_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCoder>(this) containsValueForKey:cocoon::internal::to(key)]);
    }

    void Coder::decode_array_of_obj_c_type(const std::string& item_type, std::uint64_t count, void* array) const
    {
        [cocoon::internal::ns<::NSCoder>(this) decodeArrayOfObjCType:item_type.c_str() count:static_cast<::NSUInteger>(count) at:array];
    }

    std::vector<Object> Coder::decode_array_of_objects_of_class(const std::string& cls, const std::string& key) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSCoder>(this) decodeArrayOfObjectsOfClass:NSClassFromString(cocoon::internal::to(cls)) forKey:cocoon::internal::to(key)], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    std::vector<Object> Coder::decode_array_of_objects_of_classes(const std::vector<std::string>& classes, const std::string& key) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSCoder>(this) decodeArrayOfObjectsOfClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                                                                                                        {
                                                                                                                                                                            return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                                                        })]
                                                                                                                  forKey:cocoon::internal::to(key)],
                                                    [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    bool Coder::decode_bool_for_key(const std::string& key) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCoder>(this) decodeBoolForKey:cocoon::internal::to(key)]);
    }

    const std::uint8_t* Coder::decode_bytes_for_key(const std::string& key, std::uint64_t length) const
    {
        return (const std::uint8_t*)([cocoon::internal::ns<::NSCoder>(this) decodeBytesForKey:cocoon::internal::to(key) minimumLength:static_cast<::NSUInteger>(length)]);
    }

    const std::uint8_t* Coder::decode_bytes_for_key(const std::string& key, std::uint64_t* lengthp) const
    {
        return (const std::uint8_t*)([cocoon::internal::ns<::NSCoder>(this) decodeBytesForKey:cocoon::internal::to(key) returnedLength:(::NSUInteger*)(lengthp)]);
    }

    void* Coder::decode_bytes_with_minimum_length(std::uint64_t length) const
    {
        return [cocoon::internal::ns<::NSCoder>(this) decodeBytesWithMinimumLength:static_cast<::NSUInteger>(length)];
    }

    void* Coder::decode_bytes_with_returned_length(std::uint64_t* lengthp) const
    {
        return [cocoon::internal::ns<::NSCoder>(this) decodeBytesWithReturnedLength:(::NSUInteger*)(lengthp)];
    }

    std::vector<std::uint8_t> Coder::decode_data_object() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSCoder>(this) decodeDataObject]);
    }

    std::vector<std::pair<Object, Object>> Coder::decode_dictionary_with_keys_of_class(const std::string& key_cls, const std::string& object_cls, const std::string& key) const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSCoder>(this) decodeDictionaryWithKeysOfClass:NSClassFromString(cocoon::internal::to(key_cls)) objectsOfClass:NSClassFromString(cocoon::internal::to(object_cls)) forKey:cocoon::internal::to(key)], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    std::vector<std::pair<Object, Object>> Coder::decode_dictionary_with_keys_of_classes(const std::vector<std::string>& key_classes, const std::vector<std::string>& object_classes, const std::string& key) const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSCoder>(this) decodeDictionaryWithKeysOfClasses:[NSSet setWithArray:cocoon::internal::to_array(key_classes, [](const std::string& e) -> id
                                                                                                                                                                                                                 {
                                                                                                                                                                                                                     return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                                                                                                 })]
                                                                                                                                                 objectsOfClasses:[NSSet setWithArray:cocoon::internal::to_array(object_classes, [](const std::string& e) -> id
                                                                                                                                                                                                                 {
                                                                                                                                                                                                                     return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                                                                                                 })]
                                                                                                                                                           forKey:cocoon::internal::to(key)],
                                                                                         [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    double Coder::decode_double_for_key(const std::string& key) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCoder>(this) decodeDoubleForKey:cocoon::internal::to(key)]);
    }

    float Coder::decode_float_for_key(const std::string& key) const
    {
        return static_cast<float>([cocoon::internal::ns<::NSCoder>(this) decodeFloatForKey:cocoon::internal::to(key)]);
    }

    int Coder::decode_int32_for_key(const std::string& key) const
    {
        return static_cast<int>([cocoon::internal::ns<::NSCoder>(this) decodeInt32ForKey:cocoon::internal::to(key)]);
    }

    std::int64_t Coder::decode_int64_for_key(const std::string& key) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCoder>(this) decodeInt64ForKey:cocoon::internal::to(key)]);
    }

    int Coder::decode_int_for_key(const std::string& key) const
    {
        return static_cast<int>([cocoon::internal::ns<::NSCoder>(this) decodeIntForKey:cocoon::internal::to(key)]);
    }

    std::int64_t Coder::decode_integer_for_key(const std::string& key) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCoder>(this) decodeIntegerForKey:cocoon::internal::to(key)]);
    }

    Object Coder::decode_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodeObject]);
    }

    Object Coder::decode_object_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodeObjectForKey:cocoon::internal::to(key)]);
    }

    Object Coder::decode_object_of_class(const std::string& a_class, const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodeObjectOfClass:NSClassFromString(cocoon::internal::to(a_class)) forKey:cocoon::internal::to(key)]);
    }

    Object Coder::decode_object_of_classes(const std::vector<std::string>& classes, const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodeObjectOfClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                                                                                          {
                                                                                                                                                              return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                                          })]
                                                                                                    forKey:cocoon::internal::to(key)]);
    }

    Point Coder::decode_point() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodePoint]);
    }

    Point Coder::decode_point_for_key(const std::string& key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodePointForKey:cocoon::internal::to(key)]);
    }

    Object Coder::decode_property_list() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodePropertyList]);
    }

    Object Coder::decode_property_list_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCoder>(this) decodePropertyListForKey:cocoon::internal::to(key)]);
    }

    Rect Coder::decode_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodeRect]);
    }

    Rect Coder::decode_rect_for_key(const std::string& key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodeRectForKey:cocoon::internal::to(key)]);
    }

    Size Coder::decode_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodeSize]);
    }

    Size Coder::decode_size_for_key(const std::string& key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCoder>(this) decodeSizeForKey:cocoon::internal::to(key)]);
    }

    Object Coder::decode_top_level_object_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSCoder>(this) decodeTopLevelObjectAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object Coder::decode_top_level_object_for_key(const std::string& key) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSCoder>(this) decodeTopLevelObjectForKey:cocoon::internal::to(key) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object Coder::decode_top_level_object_of_class(const std::string& a_class, const std::string& key) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSCoder>(this) decodeTopLevelObjectOfClass:NSClassFromString(cocoon::internal::to(a_class)) forKey:cocoon::internal::to(key) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object Coder::decode_top_level_object_of_classes(const std::vector<std::string>& classes, const std::string& key) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSCoder>(this) decodeTopLevelObjectOfClasses:[NSSet setWithArray:cocoon::internal::to_array(classes, [](const std::string& e) -> id
                                                                                                                                       {
                                                                                                                                           return NSClassFromString(cocoon::internal::to(e));
                                                                                                                                       })]
                                                                                 forKey:cocoon::internal::to(key)
                                                                                  error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    void Coder::decode_value_of_obj_c_type(const std::string& type, void* data) const
    {
        [cocoon::internal::ns<::NSCoder>(this) decodeValueOfObjCType:type.c_str() at:data];
    }

    void Coder::decode_value_of_obj_c_type(const std::string& type, void* data, std::uint64_t size) const
    {
        [cocoon::internal::ns<::NSCoder>(this) decodeValueOfObjCType:type.c_str() at:data size:static_cast<::NSUInteger>(size)];
    }

    void Coder::encode_array_of_obj_c_type(const std::string& type, std::uint64_t count, const void* array) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeArrayOfObjCType:type.c_str() count:static_cast<::NSUInteger>(count) at:array];
    }

    void Coder::encode_bool(bool value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeBool:static_cast<::BOOL>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_bycopy_object(const Object& an_object) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeBycopyObject:cocoon::internal::native_id(an_object)];
    }

    void Coder::encode_byref_object(const Object& an_object) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeByrefObject:cocoon::internal::native_id(an_object)];
    }

    void Coder::encode_bytes(const void* byteaddr, std::uint64_t length) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeBytes:byteaddr length:static_cast<::NSUInteger>(length)];
    }

    void Coder::encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeBytes:(const ::uint8_t*)(bytes) length:static_cast<::NSUInteger>(length) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_conditional_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeConditionalObject:cocoon::internal::native_id(object)];
    }

    void Coder::encode_conditional_object(const Object& object, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeConditionalObject:cocoon::internal::native_id(object) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_data_object(const std::vector<std::uint8_t>& data) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeDataObject:cocoon::internal::to_data(data)];
    }

    void Coder::encode_double(double value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeDouble:static_cast<double>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_float(float value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeFloat:static_cast<float>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_int32(int value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeInt32:static_cast<::int32_t>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_int64(std::int64_t value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeInt64:static_cast<::int64_t>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_int(int value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeInt:static_cast<int>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_integer(std::int64_t value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeInteger:static_cast<::NSInteger>(value) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeObject:cocoon::internal::native_id(object)];
    }

    void Coder::encode_object(const Object& object, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeObject:cocoon::internal::native_id(object) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_point(const Point& point) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodePoint:cocoon::internal::to(point)];
    }

    void Coder::encode_point(const Point& point, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodePoint:cocoon::internal::to(point) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_property_list(const Object& a_property_list) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodePropertyList:cocoon::internal::native_id(a_property_list)];
    }

    void Coder::encode_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeRect:cocoon::internal::to(rect)];
    }

    void Coder::encode_rect(const Rect& rect, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeRect:cocoon::internal::to(rect) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_root_object(const Object& root_object) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeRootObject:cocoon::internal::native_id(root_object)];
    }

    void Coder::encode_size(const Size& size) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeSize:cocoon::internal::to(size)];
    }

    void Coder::encode_size(const Size& size, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeSize:cocoon::internal::to(size) forKey:cocoon::internal::to(key)];
    }

    void Coder::encode_value_of_obj_c_type(const std::string& type, const void* addr) const
    {
        [cocoon::internal::ns<::NSCoder>(this) encodeValueOfObjCType:type.c_str() at:addr];
    }

    void Coder::fail_with_error(const Error& error) const
    {
        [cocoon::internal::ns<::NSCoder>(this) failWithError:cocoon::internal::native<::NSError>(error)];
    }

    std::int64_t Coder::version_for_class_name(const std::string& class_name) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSCoder>(this) versionForClassName:cocoon::internal::to(class_name)]);
    }

    std::vector<std::string> Coder::allowed_classes() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSCoder>(this) allowedClasses] allObjects], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from(NSStringFromClass(e));
                                                         });
    }

    bool Coder::allows_keyed_coding() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCoder>(this) allowsKeyedCoding]);
    }

    DecodingFailurePolicy Coder::decoding_failure_policy() const
    {
        return static_cast<DecodingFailurePolicy>([cocoon::internal::ns<::NSCoder>(this) decodingFailurePolicy]);
    }

    Error Coder::error() const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSCoder>(this) error]);
    }

    bool Coder::requires_secure_coding() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCoder>(this) requiresSecureCoding]);
    }

    unsigned int Coder::system_version() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSCoder>(this) systemVersion]);
    }
}
