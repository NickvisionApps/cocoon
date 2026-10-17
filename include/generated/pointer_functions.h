#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPointerFunctions` (Foundation).
     * @details An instance of 'NSPointerFunctions' defines callout functions appropriate for managing a pointer reference held somewhere else. The functions specified by an instance of 'NSPointerFunctions' are separated into two clusters—those that define "personality" such as "object" or "C-string", and those that describe memory management issues such as a memory deallocation function. There are constants for common personalities and memory manager selections (see 'Memory and Personality Options'). ''NSHashTable'', ''NSMapTable'', and ''NSPointerArray'' use an 'NSPointerFunctions' object to define the acquisition and retention behavior for the pointers they manage. Note, however, that not all combinations of personality and memory management behavior are valid for these collections. The pointer collection objects copy the 'NSPointerFunctions' object on input and output, so you cannot usefully subclass 'NSPointerFunctions'. \#\#\# Subclassing Notes 'NSPointerFunctions' is not suitable for subclassing.
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
     * pointer_functions.set_uses_strong_write_barrier(true);
     * auto uses_strong_write_barrier = pointer_functions.uses_strong_write_barrier();
     * pointer_functions.set_uses_weak_read_and_write_barriers(true);
     * auto uses_weak_read_and_write_barriers = pointer_functions.uses_weak_read_and_write_barriers();
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
     * @details Returns a new 'NSPointerFunctions' object initialized with the given options. - Parameter options: The options for the new 'NSPointerFunctions' object. - Returns: A new 'NSPointerFunctions' object initialized with the given options.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerFunctions pointer_functions_with_options(PointerFunctionsOptions options);
        /**
     * @brief Returns the `acquireFunction` property of `NSPointerFunctions`.
     * @details The function used to acquire memory. This specifies the function to use for copy-in operations.
     * @return The converted Objective-C result.
     */
        auto acquire_function() const -> void* (*)(void*, std::uint64_t (*)(void*), bool);
        /**
     * @brief Sets the `acquireFunction` property of `NSPointerFunctions`.
     * @details The function used to acquire memory. This specifies the function to use for copy-in operations.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_acquire_function(void* (*value)(void*, std::uint64_t (*)(void*), bool)) const;
        /**
     * @brief Returns the `descriptionFunction` property of `NSPointerFunctions`.
     * @details The function used to describe elements. This function is used by description methods for hash and map tables.
     * @return The converted Objective-C result.
     */
        auto description_function() const -> void* (*)(void*);
        /**
     * @brief Sets the `descriptionFunction` property of `NSPointerFunctions`.
     * @details The function used to describe elements. This function is used by description methods for hash and map tables.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_description_function(void* (*value)(void*)) const;
        /**
     * @brief Returns the `hashFunction` property of `NSPointerFunctions`.
     * @details The hash function.
     * @return The converted Objective-C result.
     */
        auto hash_function() const -> std::uint64_t (*)(void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `hashFunction` property of `NSPointerFunctions`.
     * @details The hash function.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hash_function(std::uint64_t (*value)(void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `isEqualFunction` property of `NSPointerFunctions`.
     * @details The function used to compare pointers.
     * @return The converted Objective-C result.
     */
        auto is_equal_function() const -> bool (*)(void*, void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `isEqualFunction` property of `NSPointerFunctions`.
     * @details The function used to compare pointers.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_is_equal_function(bool (*value)(void*, void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `relinquishFunction` property of `NSPointerFunctions`.
     * @details The function used to relinquish memory. This specifies the function to use when an item is removed from a table or pointer array.
     * @return The converted Objective-C result.
     */
        auto relinquish_function() const -> void (*)(void*, std::uint64_t (*)(void*));
        /**
     * @brief Sets the `relinquishFunction` property of `NSPointerFunctions`.
     * @details The function used to relinquish memory. This specifies the function to use when an item is removed from a table or pointer array.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_relinquish_function(void (*value)(void*, std::uint64_t (*)(void*))) const;
        /**
     * @brief Returns the `sizeFunction` property of `NSPointerFunctions`.
     * @details The function used to determine the size of pointers. This function is used for copy-in operations (unless the collection has an object personality).
     * @return The converted Objective-C result.
     */
        auto size_function() const -> std::uint64_t (*)(void*);
        /**
     * @brief Sets the `sizeFunction` property of `NSPointerFunctions`.
     * @details The function used to determine the size of pointers. This function is used for copy-in operations (unless the collection has an object personality).
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size_function(std::uint64_t (*value)(void*)) const;
        /**
     * @brief Returns the `usesStrongWriteBarrier` property of `NSPointerFunctions`.
     * @details Specifies whether, in a garbage collected environment, pointers should be assigned using a strong write barrier. If you use garbage collection, read and write barrier functions must be used when pointers are from memory scanned by the collector.
     * @return The converted Objective-C result.
     */
        bool uses_strong_write_barrier() const;
        /**
     * @brief Sets the `usesStrongWriteBarrier` property of `NSPointerFunctions`.
     * @details Specifies whether, in a garbage collected environment, pointers should be assigned using a strong write barrier. If you use garbage collection, read and write barrier functions must be used when pointers are from memory scanned by the collector.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_strong_write_barrier(bool value) const;
        /**
     * @brief Returns the `usesWeakReadAndWriteBarriers` property of `NSPointerFunctions`.
     * @details Specifies whether, in a garbage collected environment, pointers should use weak read and write barriers. If you use garbage collection, read and write barrier functions must be used when pointers are from memory scanned by the collector.
     * @return The converted Objective-C result.
     */
        bool uses_weak_read_and_write_barriers() const;
        /**
     * @brief Sets the `usesWeakReadAndWriteBarriers` property of `NSPointerFunctions`.
     * @details Specifies whether, in a garbage collected environment, pointers should use weak read and write barriers. If you use garbage collection, read and write barrier functions must be used when pointers are from memory scanned by the collector.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_weak_read_and_write_barriers(bool value) const;
    };
}
