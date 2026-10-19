#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScriptWhoseTest` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ScriptWhoseTest script_whose_test;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ScriptWhoseTest script_whose_test{};
     * script_whose_test.is_true();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsscriptwhosetest
     */
    class ScriptWhoseTest : public Object
    {
    public:
        /// @brief Creates a new `NSScriptWhoseTest` instance and returns a handle to it.
        explicit ScriptWhoseTest();
        /// @brief Creates a null handle that refers to no native object.
        ScriptWhoseTest(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ScriptWhoseTest(Adopt adopt);
        /**
     * @brief Calls `-[NSScriptWhoseTest isTrue]`.
     * @return The converted Objective-C result.
     */
        bool is_true() const;
    };
}
