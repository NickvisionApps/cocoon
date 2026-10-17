#include "generated/property_list_serialization.h"
#include "internal.h"

namespace cocoon
{
    PropertyListSerialization::PropertyListSerialization() : PropertyListSerialization(Adopt{cocoon::internal::retain([[::NSPropertyListSerialization alloc] init])})
    {
    }

    PropertyListSerialization::PropertyListSerialization(std::nullptr_t) : Object(nullptr)
    {
    }

    PropertyListSerialization::PropertyListSerialization(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<std::uint8_t> PropertyListSerialization::data_with_property_list(const Object& plist, PropertyListFormat format, std::uint64_t opt)
    {
        NSError* __error = nil;
        auto __r = [::NSPropertyListSerialization dataWithPropertyList:cocoon::internal::native_id(plist) format:static_cast<::NSPropertyListFormat>(format) options:static_cast<::NSPropertyListWriteOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    bool PropertyListSerialization::property_list(const Object& plist, PropertyListFormat format)
    {
        return static_cast<bool>([::NSPropertyListSerialization propertyList:cocoon::internal::native_id(plist) isValidForFormat:static_cast<::NSPropertyListFormat>(format)]);
    }

    Object PropertyListSerialization::property_list_with_data(const std::vector<std::uint8_t>& data, PropertyListMutabilityOptions opt, PropertyListFormat* format)
    {
        NSError* __error = nil;
        auto __r = [::NSPropertyListSerialization propertyListWithData:cocoon::internal::to_data(data) options:static_cast<::NSPropertyListReadOptions>(opt) format:(::NSPropertyListFormat*)(format)error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object PropertyListSerialization::property_list_with_stream(const InputStream& stream, PropertyListMutabilityOptions opt, PropertyListFormat* format)
    {
        NSError* __error = nil;
        auto __r = [::NSPropertyListSerialization propertyListWithStream:cocoon::internal::native<::NSInputStream>(stream) options:static_cast<::NSPropertyListReadOptions>(opt) format:(::NSPropertyListFormat*)(format)error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    std::int64_t PropertyListSerialization::write_property_list(const Object& plist, const OutputStream& stream, PropertyListFormat format, std::uint64_t opt)
    {
        NSError* __error = nil;
        auto __r = [::NSPropertyListSerialization writePropertyList:cocoon::internal::native_id(plist) toStream:cocoon::internal::native<::NSOutputStream>(stream) format:static_cast<::NSPropertyListFormat>(format) options:static_cast<::NSPropertyListWriteOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<std::int64_t>(__r);
    }
}
