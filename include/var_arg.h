#pragma once

#include <cstdint>
#include <string>
#include <type_traits>
#include "object.h"

namespace cocoon
{
    /**
     * @brief One argument of a C-style variadic Objective-C call (for example a format string argument).
     * @details Used by the generated variadic templates such as `Predicate::predicate_with_format`. Numbers pass by value,
     * `std::string` and handles pass as objects (`%@`), and `const char*` passes as a C string (`%s`).
     * @par Example
     * @code
     * cocoon::Predicate p = cocoon::Predicate::predicate_with_format("name == %@ AND age > %d", std::string("Ada"), 36);
     * @endcode
     */
    class VarArg
    {
    public:
        /// How an argument is passed to the callee.
        enum class Kind
        {
            /// Passed as a 64-bit integer.
            Integer,
            /// Passed as a double.
            Floating,
            /// Passed as an object pointer.
            Object,
            /// Passed as an NSString object.
            String,
            /// Passed as a C string pointer.
            CString,
        };

        template <class T, std::enable_if_t<std::is_integral_v<T> || std::is_enum_v<T>, int> = 0>
        /// Integral or enum argument.
        VarArg(T value) : kind_(Kind::Integer), integer_(static_cast<std::int64_t>(value))
        {
        }

        template <class T, std::enable_if_t<std::is_floating_point_v<T>, int> = 0>
        /// Floating point argument.
        VarArg(T value) : kind_(Kind::Floating), floating_(static_cast<double>(value))
        {
        }

        /// String argument, passed as an NSString.
        VarArg(const std::string& value) : kind_(Kind::String), text_(value)
        {
        }
        /// C string argument.
        VarArg(const char* value) : kind_(Kind::CString), text_(value)
        {
        }
        /// Object argument.
        VarArg(const Object& value) : kind_(Kind::Object), object_(value)
        {
        }

        /// @return The argument kind.
        Kind kind() const
        {
            return kind_;
        }
        /// @return The integer value (Integer kind).
        std::int64_t integer() const
        {
            return integer_;
        }
        /// @return The floating point value (Floating kind).
        double floating() const
        {
            return floating_;
        }
        /// @return The text (String and CString kinds).
        const std::string& text() const
        {
            return text_;
        }
        /// @return The object (Object kind).
        const Object& object() const
        {
            return object_;
        }

    private:
        Kind kind_;
        std::int64_t integer_ = 0;
        double floating_ = 0;
        std::string text_;
        Object object_;
    };
}
