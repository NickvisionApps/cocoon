#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMethodSignature` (Foundation).
     * @details A record of the type information for the return value and parameters of a method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MethodSignature method_signature;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MethodSignature method_signature{};
     * auto made_0 = cocoon::MethodSignature::signature_with_obj_c_types("text");
     * method_signature.get_argument_type_at_index(1);
     * method_signature.is_oneway();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmethodsignature
     */
    class MethodSignature : public Object
    {
    public:
        /// @brief Creates a new `NSMethodSignature` instance and returns a handle to it.
        explicit MethodSignature();
        /// @brief Creates a null handle that refers to no native object.
        MethodSignature(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MethodSignature(Adopt adopt);
        /**
         * @brief Calls `-[NSMethodSignature getArgumentTypeAtIndex:]`.
         * @details Returns the type encoding for the argument at a given index.
         * @param idx Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string get_argument_type_at_index(std::uint64_t idx) const;
        /**
         * @brief Calls `-[NSMethodSignature isOneway]`.
         * @details Returns a Boolean value that indicates whether the receiver is asynchronous (the 'oneway' qualifier).
         * @return The converted Objective-C result.
         */
        bool is_oneway() const;
        /**
         * @brief Calls `+[NSMethodSignature signatureWithObjCTypes:]`.
         * @details Returns an ''NSMethodSignature'' object for the given Objective-C method type string.
         * @param types Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static MethodSignature signature_with_obj_c_types(const std::string& types);
        /**
         * @brief Returns the `frameLength` property of `NSMethodSignature`.
         * @details The number of bytes required by the receiver to store its arguments on the stack frame.
         * @return The converted Objective-C result.
         */
        std::uint64_t frame_length() const;
        /**
         * @brief Returns the `methodReturnLength` property of `NSMethodSignature`.
         * @details The number of bytes required for the return value.
         * @return The converted Objective-C result.
         */
        std::uint64_t method_return_length() const;
        /**
         * @brief Returns the `methodReturnType` property of `NSMethodSignature`.
         * @details A C string encoding the return type of the method.
         * @return The converted Objective-C result.
         */
        std::string method_return_type() const;
        /**
         * @brief Returns the `numberOfArguments` property of `NSMethodSignature`.
         * @details The number of arguments recorded in the receiver.
         * @return The converted Objective-C result.
         */
        std::uint64_t number_of_arguments() const;
    };
}
