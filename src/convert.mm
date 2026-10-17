#include "internal.h"

namespace cocoon::internal
{
    NSString* to(const std::string& value)
    {
        return [NSString stringWithUTF8String:value.c_str()] ?: @"";
    }

    std::string from(const char* value)
    {
        return value ? std::string(value) : std::string();
    }

    std::string from(NSString* value)
    {
        return value ? std::string(value.UTF8String) : std::string();
    }

    NSArray<NSString*>* to(const std::vector<std::string>& value)
    {
        NSMutableArray<NSString*>* result = [NSMutableArray arrayWithCapacity:value.size()];
        for (const std::string& item : value)
        {
            [result addObject:to(item)];
        }
        return result;
    }

    std::vector<std::string> from(NSArray<NSString*>* value)
    {
        std::vector<std::string> result;
        for (NSString* item in value)
        {
            result.push_back(from(item));
        }
        return result;
    }

    std::vector<std::string> from_urls(NSArray<NSURL*>* value)
    {
        std::vector<std::string> result;
        for (NSURL* item in value)
        {
            result.push_back(from(item.path));
        }
        return result;
    }

    CGSize to(const cocoon::Size& value)
    {
        return CGSizeMake(value.width, value.height);
    }

    cocoon::Size from(CGSize value)
    {
        return {value.width, value.height};
    }

    CGPoint to(const cocoon::Point& value)
    {
        return CGPointMake(value.x, value.y);
    }

    cocoon::Point from(CGPoint value)
    {
        return {value.x, value.y};
    }

    CGRect to(const cocoon::Rect& value)
    {
        return CGRectMake(value.origin.x, value.origin.y, value.size.width, value.size.height);
    }

    cocoon::Rect from(CGRect value)
    {
        return {{value.origin.x, value.origin.y}, {value.size.width, value.size.height}};
    }

    NSEdgeInsets to(const cocoon::Insets& value)
    {
        return NSEdgeInsetsMake(value.top, value.left, value.bottom, value.right);
    }

    cocoon::Insets from(NSEdgeInsets value)
    {
        return cocoon::Insets(value.top, value.left, value.bottom, value.right);
    }

    NSData* to_data(const std::vector<std::uint8_t>& value)
    {
        return [NSData dataWithBytes:value.data() length:value.size()];
    }

    NSMutableData* to_mutable_data(const std::vector<std::uint8_t>& value)
    {
        return [NSMutableData dataWithBytes:value.data() length:value.size()];
    }

    std::vector<std::uint8_t> from_data(NSData* value)
    {
        if (!value)
        {
            return {};
        }
        const std::uint8_t* bytes = static_cast<const std::uint8_t*>(value.bytes);
        return std::vector<std::uint8_t>(bytes, bytes + value.length);
    }
}

namespace cocoon::internal
{
    std::vector<std::uint64_t> pack_var_args(const std::vector<cocoon::VarArg>& args)
    {
        static NSMutableArray* keepAlive = [NSMutableArray array];
        std::vector<std::uint64_t> slots;
        slots.reserve(args.size());
        for (const cocoon::VarArg& arg : args)
        {
            std::uint64_t slot = 0;
            switch (arg.kind())
            {
                case cocoon::VarArg::Kind::Integer:
                    slot = static_cast<std::uint64_t>(arg.integer());
                    break;
                case cocoon::VarArg::Kind::Floating:
                {
                    double value = arg.floating();
                    std::memcpy(&slot, &value, sizeof(slot));
                    break;
                }
                case cocoon::VarArg::Kind::Object:
                    slot = reinterpret_cast<std::uint64_t>(arg.object().handle());
                    break;
                case cocoon::VarArg::Kind::String:
                {
                    NSString* string = to(arg.text());
                    [keepAlive addObject:string];
                    slot = reinterpret_cast<std::uint64_t>((__bridge void*)string);
                    break;
                }
                case cocoon::VarArg::Kind::CString:
                    slot = reinterpret_cast<std::uint64_t>(arg.text().c_str());
                    break;
            }
            slots.push_back(slot);
        }
        return slots;
    }
}

namespace cocoon
{
    Object box_string(const std::string& value)
    {
        return cocoon::internal::wrap<Object>(cocoon::internal::to(value));
    }

    Object box_integer(std::int64_t value)
    {
        return cocoon::internal::wrap<Object>(@(value));
    }

    Object box_double(double value)
    {
        return cocoon::internal::wrap<Object>(@(value));
    }

    Object box_bool(bool value)
    {
        return cocoon::internal::wrap<Object>(@(value));
    }

    std::string unbox_string(const Object& value)
    {
        id object = cocoon::internal::native_id(value);
        if ([object isKindOfClass:NSString.class])
        {
            return cocoon::internal::from((NSString*)object);
        }
        return cocoon::internal::from([object description]);
    }

    std::int64_t unbox_integer(const Object& value)
    {
        return [(NSNumber*)cocoon::internal::native_id(value) longLongValue];
    }

    double unbox_double(const Object& value)
    {
        return [(NSNumber*)cocoon::internal::native_id(value) doubleValue];
    }

    bool unbox_bool(const Object& value)
    {
        return [(NSNumber*)cocoon::internal::native_id(value) boolValue];
    }
}
