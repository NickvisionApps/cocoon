#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class PointerFunctions;

    /**
     * @brief C++ handle for the Objective-C class `NSPointerArray` (Foundation).
     * @details NSPointerArray.h A PointerArray acts like a traditional array that slides elements on insertion or deletion. Unlike traditional arrays, it holds NULLs, which can be inserted or extracted (and contribute to count). Also unlike traditional arrays, the 'count' of the array may be set directly. Using NSPointerFunctionsWeakMemory object references will turn to NULL on last release. The copying and archiving protocols are applicable only when NSPointerArray is configured for Object uses. The fast enumeration protocol (supporting the for..in statement) will yield NULLs if present. It is defined for all types of pointers although the language syntax doesn't directly support this.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PointerArray pointer_array;
     * pointer_array.set_count(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PointerArray pointer_array{};
     * pointer_array.set_count(1);
     * auto count = pointer_array.count();
     * auto made_0 = cocoon::PointerArray::pointer_array_with_options(cocoon::PointerFunctionsOptions::StrongMemory);
     * auto made_1 = cocoon::PointerArray::pointer_array_with_pointer_functions(cocoon::PointerFunctions());
     * pointer_array.compact();
     * pointer_array.pointer_at_index(1);
     * pointer_array.remove_pointer_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspointerarray
     */
    class PointerArray : public Object
    {
    public:
        /// @brief Creates a new `NSPointerArray` instance and returns a handle to it.
        explicit PointerArray(PointerFunctionsOptions options);
        /// @brief Creates a new `NSPointerArray` instance and returns a handle to it.
        explicit PointerArray(const PointerFunctions& functions);
        /// @brief Creates a new `NSPointerArray` instance and returns a handle to it.
        explicit PointerArray();
        /// @brief Creates a null handle that refers to no native object.
        PointerArray(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PointerArray(Adopt adopt);
        /**
     * @brief Calls `-[NSPointerArray addPointer:]`.
     * @param pointer Argument converted to the Objective-C parameter of the same role.
     */
        void add_pointer(void* pointer) const;
        /**
     * @brief Calls `-[NSPointerArray compact]`.
     */
        void compact() const;
        /**
     * @brief Calls `-[NSPointerArray insertPointer:atIndex:]`.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_pointer(void* item, std::uint64_t index) const;
        /**
     * @brief Calls `+[NSPointerArray pointerArrayWithOptions:]`.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerArray pointer_array_with_options(PointerFunctionsOptions options);
        /**
     * @brief Calls `+[NSPointerArray pointerArrayWithPointerFunctions:]`.
     * @param functions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerArray pointer_array_with_pointer_functions(const PointerFunctions& functions);
        /**
     * @brief Calls `-[NSPointerArray pointerAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        void* pointer_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSPointerArray removePointerAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_pointer_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSPointerArray replacePointerAtIndex:withPointer:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void replace_pointer_at_index(std::uint64_t index, void* item) const;
        /**
     * @brief Calls `+[NSPointerArray strongObjectsPointerArray]`.
     * @return The converted Objective-C result.
     */
        static PointerArray strong_objects_pointer_array();
        /**
     * @brief Calls `+[NSPointerArray weakObjectsPointerArray]`.
     * @return The converted Objective-C result.
     */
        static PointerArray weak_objects_pointer_array();
        /**
     * @brief Returns the `allObjects` property of `NSPointerArray`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> all_objects() const;
        /**
     * @brief Returns the `count` property of `NSPointerArray`.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Sets the `count` property of `NSPointerArray`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count(std::uint64_t value) const;
        /**
     * @brief Returns the `pointerFunctions` property of `NSPointerArray`.
     * @details return an NSPointerFunctions object reflecting the functions in use. This is a new autoreleased object that can be subsequently modified and/or used directly in the creation of other pointer "collections".
     * @return The converted Objective-C result.
     */
        PointerFunctions pointer_functions() const;
    };
}
