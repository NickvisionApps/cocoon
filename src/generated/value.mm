#include "generated/value.h"
#include "internal.h"

namespace cocoon
{
    Value::Value(const void* value, const std::string& type) : Value(Adopt{cocoon::internal::retain([[::NSValue alloc] initWithBytes:value objCType:type.c_str()])})
    {
    }

    Value::Value() : Value(Adopt{cocoon::internal::retain([[::NSValue alloc] init])})
    {
    }

    Value::Value(std::nullptr_t) : Object(nullptr)
    {
    }

    Value::Value(Adopt adopt) : Object(adopt)
    {
    }

    void Value::get_value(void* value) const
    {
        [cocoon::internal::ns<::NSValue>(this) getValue:value];
    }

    void Value::get_value(void* value, std::uint64_t size) const
    {
        [cocoon::internal::ns<::NSValue>(this) getValue:value size:static_cast<::NSUInteger>(size)];
    }

    bool Value::is_equal_to_value(const Value& value) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSValue>(this) isEqualToValue:cocoon::internal::native<::NSValue>(value)]);
    }

    Value Value::value(const void* value, const std::string& type)
    {
        return cocoon::internal::wrap<Value>([::NSValue value:value withObjCType:type.c_str()]);
    }

    Value Value::value_with_bytes(const void* value, const std::string& type)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithBytes:value objCType:type.c_str()]);
    }

    Value Value::value_with_ca_transform3_d(const CATransform3D& t)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithCATransform3D:cocoon::internal::to(t)]);
    }

    Value Value::value_with_edge_insets(const Insets& insets)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithEdgeInsets:cocoon::internal::to(insets)]);
    }

    Value Value::value_with_nonretained_object(const Object& an_object)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithNonretainedObject:cocoon::internal::native_id(an_object)]);
    }

    Value Value::value_with_point(const Point& point)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithPoint:cocoon::internal::to(point)]);
    }

    Value Value::value_with_pointer(const void* pointer)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithPointer:pointer]);
    }

    Value Value::value_with_range(const Range& range)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithRange:cocoon::internal::to(range)]);
    }

    Value Value::value_with_rect(const Rect& rect)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithRect:cocoon::internal::to(rect)]);
    }

    Value Value::value_with_size(const Size& size)
    {
        return cocoon::internal::wrap<Value>([::NSValue valueWithSize:cocoon::internal::to(size)]);
    }

    CATransform3D Value::ca_transform3_d_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) CATransform3DValue]);
    }

    Insets Value::edge_insets_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) edgeInsetsValue]);
    }

    Object Value::nonretained_object_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSValue>(this) nonretainedObjectValue]);
    }

    std::string Value::obj_c_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) objCType]);
    }

    Point Value::point_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) pointValue]);
    }

    void* Value::pointer_value() const
    {
        return [cocoon::internal::ns<::NSValue>(this) pointerValue];
    }

    Range Value::range_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) rangeValue]);
    }

    Rect Value::rect_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) rectValue]);
    }

    Size Value::size_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSValue>(this) sizeValue]);
    }
}
