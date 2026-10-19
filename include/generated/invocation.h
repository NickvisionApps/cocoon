#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class MethodSignature;

    /**
     * @brief C++ handle for the Objective-C class `NSInvocation` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Invocation invocation;
     * invocation.set_selector("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Invocation invocation{};
     * invocation.set_selector("text");
     * auto selector = invocation.selector();
     * auto made_0 = cocoon::Invocation::invocation_with_method_signature(cocoon::MethodSignature());
     * invocation.invoke();
     * invocation.retain_arguments();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsinvocation
     */
    class Invocation : public Object
    {
    public:
        /// @brief Creates a new `NSInvocation` instance and returns a handle to it.
        explicit Invocation();
        /// @brief Creates a null handle that refers to no native object.
        Invocation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Invocation(Adopt adopt);
        /**
     * @brief Calls `-[NSInvocation getArgument:atIndex:]`.
     * @param argument_location Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     */
        void get_argument(void* argument_location, std::int64_t idx) const;
        /**
     * @brief Calls `-[NSInvocation getReturnValue:]`.
     * @param ret_loc Argument converted to the Objective-C parameter of the same role.
     */
        void get_return_value(void* ret_loc) const;
        /**
     * @brief Calls `+[NSInvocation invocationWithMethodSignature:]`.
     * @param sig Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Invocation invocation_with_method_signature(const MethodSignature& sig);
        /**
     * @brief Calls `-[NSInvocation invoke]`.
     */
        void invoke() const;
        /**
     * @brief Calls `-[NSInvocation invokeUsingIMP:]`.
     * @param imp Argument converted to the Objective-C parameter of the same role.
     */
        void invoke_using_imp(void (*imp)()) const;
        /**
     * @brief Calls `-[NSInvocation invokeWithTarget:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     */
        void invoke_with_target(const Object& target) const;
        /**
     * @brief Calls `-[NSInvocation retainArguments]`.
     */
        void retain_arguments() const;
        /**
     * @brief Calls `-[NSInvocation setArgument:atIndex:]`.
     * @param argument_location Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     */
        void set_argument(void* argument_location, std::int64_t idx) const;
        /**
     * @brief Calls `-[NSInvocation setReturnValue:]`.
     * @param ret_loc Argument converted to the Objective-C parameter of the same role.
     */
        void set_return_value(void* ret_loc) const;
        /**
     * @brief Returns the `argumentsRetained` property of `NSInvocation`.
     * @return The converted Objective-C result.
     */
        bool arguments_retained() const;
        /**
     * @brief Returns the `methodSignature` property of `NSInvocation`.
     * @return The converted Objective-C result.
     */
        MethodSignature method_signature() const;
        /**
     * @brief Returns the `selector` property of `NSInvocation`.
     * @return The converted Objective-C result.
     */
        std::string selector() const;
        /**
     * @brief Sets the `selector` property of `NSInvocation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selector(const std::string& value) const;
        /**
     * @brief Returns the `target` property of `NSInvocation`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSInvocation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
    };
}
