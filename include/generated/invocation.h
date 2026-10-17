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
     * @details An Objective-C message rendered as an object. ''NSInvocation'' objects are used to store and forward messages between objects and between applications, primarily by ''Timer'' objects and the distributed objects system. An ''NSInvocation'' object contains all the elements of an Objective-C message: a target, a selector, arguments, and the return value. Each of these elements can be set directly, and the return value is set automatically when the ''NSInvocation'' object is dispatched. An ''NSInvocation'' object can be repeatedly dispatched to different targets; its arguments can be modified between dispatch for varying results; even its selector can be changed to another with the same method signature (argument and return types). This flexibility makes ''NSInvocation'' useful for repeating messages with many arguments and variations; rather than retyping a slightly different expression for each message, you modify the ''NSInvocation'' object as needed each time before dispatching it to a new target. ''NSInvocation'' does not support invocations of methods with either variable numbers of arguments or 'union' arguments. You should use the ''invocationWithMethodSignature:'' class method to create ''NSInvocation'' objects; you should not create these objects using \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/alloc> and \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/init()>. This class does not retain the arguments for the contained invocation by default. If those objects might disappear between the time you create your instance of ''NSInvocation'' and the time you use it, you should explicitly retain the objects yourself or invoke the ''retainArguments'' method to have the invocation object retain them itself. > Note: > ''NSInvocation'' conforms to the ''NSCoding'' protocol, but only supports coding by an ''NSPortCoder''. ''NSInvocation'' does not support archiving.
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
     * @details Returns by indirection the receiver's argument at a specified index. Indices 0 and 1 indicate the hidden arguments 'self' and 'cmd', respectively; these values can be retrieved directly with the 'target' and 'selector' properties. Use indices 2 and greater for the arguments normally passed in a message. - Parameter argumentLocation: An untyped buffer to hold the returned argument. - Parameter idx: An integer specifying the index of the argument to get.
     * @param argument_location Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     */
        void get_argument(void* argument_location, std::int64_t idx) const;
        /**
     * @brief Calls `-[NSInvocation getReturnValue:]`.
     * @details Gets the invocation's return value. - Parameter retLoc: An untyped buffer into which the invocation copies its return value. It should be large enough to accommodate the value.
     * @param ret_loc Argument converted to the Objective-C parameter of the same role.
     */
        void get_return_value(void* ret_loc) const;
        /**
     * @brief Calls `+[NSInvocation invocationWithMethodSignature:]`.
     * @details Returns an 'NSInvocation' object able to construct messages using a given method signature. The new object must have its selector set and its arguments set with 'setArgument:atIndex:' before it can be invoked. Do not use the 'alloc'/'init' approach to create 'NSInvocation' objects. - Parameter sig: An object encapsulating a method signature.
     * @param sig Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Invocation invocation_with_method_signature(const MethodSignature& sig);
        /**
     * @brief Calls `-[NSInvocation invoke]`.
     * @details Sends the receiver's message (with arguments) to its target and sets the return value. You must set the receiver's target, selector, and argument values before calling this method.
     */
        void invoke() const;
        /**
     * @brief Calls `-[NSInvocation invokeUsingIMP:]`.
     * @param imp Argument converted to the Objective-C parameter of the same role.
     */
        void invoke_using_imp(void (*imp)()) const;
        /**
     * @brief Calls `-[NSInvocation invokeWithTarget:]`.
     * @details Sets the receiver's target, sends the receiver's message (with arguments) to that target, and sets the return value. You must set the receiver's selector and argument values before calling this method. - Parameter target: The object to set as the receiver's target.
     * @param target Argument converted to the Objective-C parameter of the same role.
     */
        void invoke_with_target(const Object& target) const;
        /**
     * @brief Calls `-[NSInvocation retainArguments]`.
     * @details If the receiver hasn't already done so, retains the target and all object arguments of the receiver and copies all of its C-string arguments and blocks. For efficiency, newly created 'NSInvocation' objects don't retain or copy their arguments, nor do they retain their targets, copy C strings, or copy any associated blocks. You should instruct an 'NSInvocation' object to retain its arguments if you intend to cache it, because the arguments may otherwise be released before the invocation is invoked.
     */
        void retain_arguments() const;
        /**
     * @brief Calls `-[NSInvocation setArgument:atIndex:]`.
     * @details Sets an argument of the receiver. Indices 0 and 1 indicate the hidden arguments 'self' and 'cmd', respectively; you should set these values directly with the 'target' and 'selector' properties. Use indices 2 and greater for the arguments normally passed in a message. - Parameter argumentLocation: An untyped buffer containing an argument to be assigned to the receiver. - Parameter idx: An integer specifying the index of the argument.
     * @param argument_location Argument converted to the Objective-C parameter of the same role.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     */
        void set_argument(void* argument_location, std::int64_t idx) const;
        /**
     * @brief Calls `-[NSInvocation setReturnValue:]`.
     * @details Sets the receiver's return value. This value is normally set when you send an 'invoke' or 'invokeWithTarget:' message. - Parameter retLoc: An untyped buffer whose contents are copied as the receiver's return value.
     * @param ret_loc Argument converted to the Objective-C parameter of the same role.
     */
        void set_return_value(void* ret_loc) const;
        /**
     * @brief Returns the `argumentsRetained` property of `NSInvocation`.
     * @details A Boolean value that indicates if the receiver has retained its arguments.
     * @return The converted Objective-C result.
     */
        bool arguments_retained() const;
        /**
     * @brief Returns the `methodSignature` property of `NSInvocation`.
     * @details The receiver's method signature.
     * @return The converted Objective-C result.
     */
        MethodSignature method_signature() const;
        /**
     * @brief Returns the `selector` property of `NSInvocation`.
     * @details The receiver's selector, or 0 if it hasn't been set.
     * @return The converted Objective-C result.
     */
        std::string selector() const;
        /**
     * @brief Sets the `selector` property of `NSInvocation`.
     * @details The receiver's selector, or 0 if it hasn't been set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selector(const std::string& value) const;
        /**
     * @brief Returns the `target` property of `NSInvocation`.
     * @details The receiver's target, or 'nil' if the receiver has no target. The target is the receiver of the message sent by 'invoke'.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSInvocation`.
     * @details The receiver's target, or 'nil' if the receiver has no target. The target is the receiver of the message sent by 'invoke'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
    };
}
