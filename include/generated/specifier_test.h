#pragma once

#include "generated/enums.h"
#include "generated/script_whose_test.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSSpecifierTest` (Foundation).
     * @details A script whose test that compares an object specifier against a value using a comparison operator. The specifiers are evaluated normally before the comparison operator is evaluated.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptWhoseTest.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SpecifierTest specifier_test(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsspecifiertest
     */
    class SpecifierTest : public ScriptWhoseTest
    {
    public:
        /// @brief Creates a new `NSSpecifierTest` instance and returns a handle to it.
        explicit SpecifierTest(const ScriptObjectSpecifier& obj1, TestComparisonOperation comp_op, const Object& obj2);
        SpecifierTest();
        /// @brief Creates a null handle that refers to no native object.
        SpecifierTest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SpecifierTest(Adopt adopt);
    };
}
