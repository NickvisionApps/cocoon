#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPointerFunctions` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PointerFunctions pointer_functions;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PointerFunctions pointer_functions{};
     * auto made_0 = cocoon::PointerFunctions::pointer_functions_with_options(cocoon::PointerFunctionsOptions::StrongMemory);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspointerfunctions
     */
    class PointerFunctions : public Object
    {
    public:
        /// @brief Creates a new `NSPointerFunctions` instance and returns a handle to it.
        explicit PointerFunctions(PointerFunctionsOptions options);
        /// @brief Creates a new `NSPointerFunctions` instance and returns a handle to it.
        explicit PointerFunctions();
        /// @brief Creates a null handle that refers to no native object.
        PointerFunctions(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PointerFunctions(Adopt adopt);
        /**
     * @brief Calls `+[NSPointerFunctions pointerFunctionsWithOptions:]`.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerFunctions pointer_functions_with_options(PointerFunctionsOptions options);
        /**
     * @brief Returns the `acquireFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto acquire_function() const -> void* (*)(void*, std::uint64_t (*)(void*), bool);
        /**
     * @brief Sets the `acquireFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_acquire_function(void* (*value)(void*, std::uint64_t (*)(void*), bool)) const;
        /**
     * @brief Returns the `descriptionFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto description_function() const -> void* (*)(void*);
        /**
     * @brief Sets the `descriptionFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_description_function(void* (*value)(void*)) const;
        /**
     * @brief Returns the `hashFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto hash_function() const -> std::uint64_t (*)(void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `hashFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hash_function(std::uint64_t (*value)(void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `isEqualFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto is_equal_function() const -> bool (*)(void*, void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `isEqualFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_is_equal_function(bool (*value)(void*, void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `relinquishFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto relinquish_function() const -> void (*)(void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `relinquishFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_relinquish_function(void (*value)(void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `sizeFunction` property of `NSPointerFunctions`.
     * @return The converted Objective-C result.
     */
        auto size_function() const -> std::uint64_t (*)(void*);
        /**
     * @brief Sets the `sizeFunction` property of `NSPointerFunctions`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size_function(std::uint64_t (*value)(void*)) const;
    };
}
