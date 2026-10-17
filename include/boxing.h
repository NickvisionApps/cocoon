#pragma once

#include <cstdint>
#include <string>
#include <type_traits>
#include <vector>
#include "object.h"

namespace cocoon
{
    /// Wraps a string in an Objective-C `NSString` object.
    Object box_string(const std::string& value);
    /// Wraps an integer in an `NSNumber`.
    Object box_integer(std::int64_t value);
    /// Wraps a floating point value in an `NSNumber`.
    Object box_double(double value);
    /// Wraps a boolean in an `NSNumber`.
    Object box_bool(bool value);
    /// Reads an `NSString` object back into a string.
    std::string unbox_string(const Object& value);
    /// Reads an `NSNumber` as an integer.
    std::int64_t unbox_integer(const Object& value);
    /// Reads an `NSNumber` as a double.
    double unbox_double(const Object& value);
    /// Reads an `NSNumber` as a bool.
    bool unbox_bool(const Object& value);

    namespace detail
    {
        template <class>
        inline constexpr bool always_false = false;
    }

    template <class T>
    /**
     * Converts a C++ value (string, number, bool, enum or any handle) to a generic Object.
     * Used by the typed wrappers of Objective-C generic classes.
     * @par Example
     * @code
     * cocoon::Object a = cocoon::box(std::string("id-1"));
     * cocoon::Object b = cocoon::box(42);
     * std::string back = cocoon::unbox<std::string>(a);
     * @endcode
     */
    Object box(const T& value)
    {
        if constexpr (std::is_base_of_v<Object, T>)
        {
            return value;
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return box_string(value);
        }
        else if constexpr (std::is_same_v<T, bool>)
        {
            return box_bool(value);
        }
        else if constexpr (std::is_integral_v<T> || std::is_enum_v<T>)
        {
            return box_integer(static_cast<std::int64_t>(value));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return box_double(static_cast<double>(value));
        }
        else
        {
            static_assert(detail::always_false<T>, "unsupported generic argument type");
        }
    }

    template <class T>
    /// Converts a generic Object back to the C++ type `T` (inverse of box).
    T unbox(const Object& value)
    {
        if constexpr (std::is_base_of_v<Object, T>)
        {
            return T(Adopt{value.is_null() ? nullptr : detail::retain_native(value.handle())});
        }
        else if constexpr (std::is_same_v<T, std::string>)
        {
            return unbox_string(value);
        }
        else if constexpr (std::is_same_v<T, bool>)
        {
            return unbox_bool(value);
        }
        else if constexpr (std::is_integral_v<T> || std::is_enum_v<T>)
        {
            return static_cast<T>(unbox_integer(value));
        }
        else if constexpr (std::is_floating_point_v<T>)
        {
            return static_cast<T>(unbox_double(value));
        }
        else
        {
            static_assert(detail::always_false<T>, "unsupported generic argument type");
        }
    }

    template <class T>
    /// Boxes every element of a vector.
    std::vector<Object> box_all(const std::vector<T>& values)
    {
        std::vector<Object> result;
        result.reserve(values.size());
        for (const T& value : values)
        {
            result.push_back(box(value));
        }
        return result;
    }

    template <class T>
    /// Unboxes every element of a vector to type `T`.
    std::vector<T> unbox_all(const std::vector<Object>& values)
    {
        std::vector<T> result;
        result.reserve(values.size());
        for (const Object& value : values)
        {
            result.push_back(unbox<T>(value));
        }
        return result;
    }
}
