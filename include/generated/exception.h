#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSException` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Exception exception;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Exception exception{};
     * exception.raise();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsexception
     */
    class Exception : public Object
    {
    public:
        /// @brief Creates a new `NSException` instance and returns a handle to it.
        explicit Exception(const std::string& a_name, const std::string& a_reason, const std::vector<std::pair<Object, Object>>& a_user_info);
        /// @brief Creates a new `NSException` instance and returns a handle to it.
        explicit Exception();
        /// @brief Creates a null handle that refers to no native object.
        Exception(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Exception(Adopt adopt);
        /**
     * @brief Calls `+[NSException exceptionWithName:reason:userInfo:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     * @param user_info Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Exception exception_with_name(const std::string& name, const std::string& reason, const std::vector<std::pair<Object, Object>>& user_info);
        /**
     * @brief Calls `-[NSException raise]`.
     */
        void raise() const;
        template <class... Args>
        static void raise(const std::string& name, const std::string& format, const Args&... args)
        {
            raise_(name, format, std::vector<VarArg>{VarArg(args)...});
        }
        /**
     * @brief Calls `+[NSException ]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param args Argument converted to the Objective-C parameter of the same role.
     */
        static void raise_(const std::string& name, const std::string& format, const std::vector<VarArg>& args);
        /**
     * @brief Calls `+[NSException raise:format:arguments:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param arg_list Argument converted to the Objective-C parameter of the same role.
     */
        static void raise(const std::string& name, const std::string& format, char* arg_list);
        /**
     * @brief Returns the `callStackReturnAddresses` property of `NSException`.
     * @return The converted Objective-C result.
     */
        std::vector<Number> call_stack_return_addresses() const;
        /**
     * @brief Returns the `callStackSymbols` property of `NSException`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> call_stack_symbols() const;
        /**
     * @brief Returns the `name` property of `NSException`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `reason` property of `NSException`.
     * @return The converted Objective-C result.
     */
        std::string reason() const;
        /**
     * @brief Returns the `userInfo` property of `NSException`.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
    };
}
