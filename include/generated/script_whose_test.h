#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSScriptWhoseTest` (Foundation).
     * @details An abstract class that provides the basis for testing specifiers one at a time or in groups. 'NSScriptWhoseTest' is an abstract class whose sole method is ''isTrue()''. Two concrete subclasses of 'NSScriptWhoseTest' generate objects representing Boolean expressions comparing one object with another and objects representing multiple Boolean expressions connected by logical operators ('OR', 'AND', 'NOT'). These classes are, respectively, ''NSSpecifierTest'' and ''NSLogicalTest''. In evaluating itself, an ''NSWhoseSpecifier'' invokes the ''isTrue()'' method of its "test" object. You shouldn't need to subclass 'NSScriptWhoseTest', and you should rarely need to subclass one of its subclasses.
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
     * @details Returns a Boolean value that indicates whether this test evaluates to true.
     * @return The converted Objective-C result.
     */
        bool is_true() const;
    };
}
