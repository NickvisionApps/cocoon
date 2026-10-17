#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_whose_test.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptWhoseTest;
    class SpecifierTest;

    /**
     * @brief C++ handle for the Objective-C class `NSLogicalTest` (Foundation).
     * @details A script whose test that combines other tests using logical AND, OR, or NOT operations.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptWhoseTest.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LogicalTest logical_test;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslogicaltest
     */
    class LogicalTest : public ScriptWhoseTest
    {
    public:
        /// @brief Creates a new `NSLogicalTest` instance and returns a handle to it.
        explicit LogicalTest(const std::vector<SpecifierTest>& sub_tests);
        /// @brief Creates a new `NSLogicalTest` instance and returns a handle to it.
        explicit LogicalTest(const ScriptWhoseTest& sub_test);
        /// @brief Creates a new `NSLogicalTest` instance and returns a handle to it.
        explicit LogicalTest();
        /// @brief Creates a null handle that refers to no native object.
        LogicalTest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LogicalTest(Adopt adopt);
    };
}
