#include "generated/json_serialization.h"
#include "internal.h"

namespace cocoon
{
    JSONSerialization::JSONSerialization() : JSONSerialization(Adopt{cocoon::internal::retain([[::NSJSONSerialization alloc] init])})
    {
    }

    JSONSerialization::JSONSerialization(std::nullptr_t) : Object(nullptr)
    {
    }

    JSONSerialization::JSONSerialization(Adopt adopt) : Object(adopt)
    {
    }

    Object JSONSerialization::json_object_with_data(const std::vector<std::uint8_t>& data, JSONReadingOptions opt)
    {
        NSError* __error = nil;
        auto __r = [::NSJSONSerialization JSONObjectWithData:cocoon::internal::to_data(data) options:static_cast<::NSJSONReadingOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object JSONSerialization::json_object_with_stream(const InputStream& stream, JSONReadingOptions opt)
    {
        NSError* __error = nil;
        auto __r = [::NSJSONSerialization JSONObjectWithStream:cocoon::internal::native<::NSInputStream>(stream) options:static_cast<::NSJSONReadingOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    std::vector<std::uint8_t> JSONSerialization::data_with_json_object(const Object& obj, JSONWritingOptions opt)
    {
        NSError* __error = nil;
        auto __r = [::NSJSONSerialization dataWithJSONObject:cocoon::internal::native_id(obj) options:static_cast<::NSJSONWritingOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_data(__r);
    }

    bool JSONSerialization::is_valid_json_object(const Object& obj)
    {
        return static_cast<bool>([::NSJSONSerialization isValidJSONObject:cocoon::internal::native_id(obj)]);
    }

    std::int64_t JSONSerialization::write_json_object(const Object& obj, const OutputStream& stream, JSONWritingOptions opt)
    {
        NSError* __error = nil;
        auto __r = [::NSJSONSerialization writeJSONObject:cocoon::internal::native_id(obj) toStream:cocoon::internal::native<::NSOutputStream>(stream) options:static_cast<::NSJSONWritingOptions>(opt) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<std::int64_t>(__r);
    }
}
