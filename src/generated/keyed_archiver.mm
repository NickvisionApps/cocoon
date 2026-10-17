#include "generated/keyed_archiver.h"
#include "internal.h"

@interface AKKeyedArchiverDelegate : NSObject <NSKeyedArchiverDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKKeyedArchiverDelegate

- (id)archiver:(NSKeyedArchiver*)archiver willEncodeObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::KeyedArchiver, cocoon::Object(cocoon::Object)>::emit((__bridge void*)strongHost, "archiver_will_encode_object", cocoon::internal::wrap<cocoon::Object>(object));
    return cocoon::internal::native_id(__r);
}

- (void)archiver:(NSKeyedArchiver*)archiver didEncodeObject:(id)object
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedArchiver, void(cocoon::Object)>::emit((__bridge void*)strongHost, "archiver_did_encode_object", cocoon::internal::wrap<cocoon::Object>(object));
}

- (void)archiver:(NSKeyedArchiver*)archiver willReplaceObject:(id)object withObject:(id)newObject
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedArchiver, void(cocoon::Object, cocoon::Object)>::emit((__bridge void*)strongHost, "archiver_will_replace_object_with_object", cocoon::internal::wrap<cocoon::Object>(object), cocoon::internal::wrap<cocoon::Object>(newObject));
}

- (void)archiverWillFinish:(NSKeyedArchiver*)archiver
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedArchiver, void()>::emit((__bridge void*)strongHost, "archiver_will_finish");
}

- (void)archiverDidFinish:(NSKeyedArchiver*)archiver
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::KeyedArchiver, void()>::emit((__bridge void*)strongHost, "archiver_did_finish");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(archiver:willEncodeObject:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedArchiver, cocoon::Object(cocoon::Object)>::connected((__bridge void*)strongHost, "archiver_will_encode_object");
    }
    if (selector == @selector(archiver:didEncodeObject:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedArchiver, void(cocoon::Object)>::connected((__bridge void*)strongHost, "archiver_did_encode_object");
    }
    if (selector == @selector(archiver:willReplaceObject:withObject:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedArchiver, void(cocoon::Object, cocoon::Object)>::connected((__bridge void*)strongHost, "archiver_will_replace_object_with_object");
    }
    if (selector == @selector(archiverWillFinish:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedArchiver, void()>::connected((__bridge void*)strongHost, "archiver_will_finish");
    }
    if (selector == @selector(archiverDidFinish:))
    {
        return strongHost && cocoon::Signal<cocoon::KeyedArchiver, void()>::connected((__bridge void*)strongHost, "archiver_did_finish");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    KeyedArchiver::KeyedArchiver(const std::vector<std::uint8_t>& data) : KeyedArchiver(Adopt{cocoon::internal::retain([[::NSKeyedArchiver alloc] initForWritingWithMutableData:cocoon::internal::to_mutable_data(data)])})
    {
        KeyedArchiver::install_delegate_delegate_(handle());
    }

    KeyedArchiver::KeyedArchiver(bool requires_secure_coding) : KeyedArchiver(Adopt{cocoon::internal::retain([[::NSKeyedArchiver alloc] initRequiringSecureCoding:static_cast<::BOOL>(requires_secure_coding)])})
    {
        KeyedArchiver::install_delegate_delegate_(handle());
    }

    KeyedArchiver::KeyedArchiver() : KeyedArchiver(Adopt{cocoon::internal::retain([[::NSKeyedArchiver alloc] init])})
    {
        KeyedArchiver::install_delegate_delegate_(handle());
    }

    KeyedArchiver::KeyedArchiver(std::nullptr_t) : Coder(nullptr)
    {
    }

    KeyedArchiver::KeyedArchiver(Adopt adopt) : Coder(adopt)
    {
    }

    bool KeyedArchiver::archive_root_object(const Object& root_object, const std::string& path)
    {
        return static_cast<bool>([::NSKeyedArchiver archiveRootObject:cocoon::internal::native_id(root_object) toFile:cocoon::internal::to(path)]);
    }

    std::vector<std::uint8_t> KeyedArchiver::archived_data_with_root_object(const Object& root_object)
    {
        return cocoon::internal::from_data([::NSKeyedArchiver archivedDataWithRootObject:cocoon::internal::native_id(root_object)]);
    }

    std::vector<std::uint8_t> KeyedArchiver::archived_data_with_root_object(const Object& object, bool requires_secure_coding)
    {
        NSError* __error = nil;
        auto __r = [::NSKeyedArchiver archivedDataWithRootObject:cocoon::internal::native_id(object) requiringSecureCoding:static_cast<::BOOL>(requires_secure_coding) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    std::string KeyedArchiver::class_name_for_class(const std::string& cls) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSKeyedArchiver>(this) classNameForClass:NSClassFromString(cocoon::internal::to(cls))]);
    }

    void KeyedArchiver::encode_bool(bool value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeBool:static_cast<::BOOL>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeBytes:(const ::uint8_t*)(bytes) length:static_cast<::NSUInteger>(length) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_conditional_object(const Object& object, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeConditionalObject:cocoon::internal::native_id(object) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_double(double value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeDouble:static_cast<double>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_float(float value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeFloat:static_cast<float>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_int32(int value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeInt32:static_cast<::int32_t>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_int64(std::int64_t value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeInt64:static_cast<::int64_t>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_int(int value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeInt:static_cast<int>(value) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::encode_object(const Object& object, const std::string& key) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) encodeObject:cocoon::internal::native_id(object) forKey:cocoon::internal::to(key)];
    }

    void KeyedArchiver::finish_encoding() const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) finishEncoding];
    }

    void KeyedArchiver::set_class_name(const std::string& coded_name, const std::string& cls) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) setClassName:cocoon::internal::to(coded_name) forClass:NSClassFromString(cocoon::internal::to(cls))];
    }

    std::vector<std::uint8_t> KeyedArchiver::encoded_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSKeyedArchiver>(this) encodedData]);
    }

    PropertyListFormat KeyedArchiver::output_format() const
    {
        return static_cast<PropertyListFormat>([cocoon::internal::ns<::NSKeyedArchiver>(this) outputFormat]);
    }

    void KeyedArchiver::set_output_format(PropertyListFormat value) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) setOutputFormat:static_cast<::NSPropertyListFormat>(value)];
    }

    bool KeyedArchiver::requires_secure_coding() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSKeyedArchiver>(this) requiresSecureCoding]);
    }

    void KeyedArchiver::set_requires_secure_coding(bool value) const
    {
        [cocoon::internal::ns<::NSKeyedArchiver>(this) setRequiresSecureCoding:static_cast<::BOOL>(value)];
    }

    void KeyedArchiver::install_delegate_delegate_(void* native)
    {
        ::NSKeyedArchiver* host = (__bridge ::NSKeyedArchiver*)native;
        AKKeyedArchiverDelegate* delegate = [[AKKeyedArchiverDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSKeyedArchiver* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSKeyedArchiver* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
