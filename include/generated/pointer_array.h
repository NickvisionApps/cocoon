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
     * @details A collection similar to an array, but with a broader range of available memory semantics. The pointer array class is modeled after ''NSArray'', but can also hold 'nil' values. You can insert or remove 'nil' values which contribute to the array's ''count''. A pointer array can be initialized to maintain strong or weak references to objects, or according to any of the memory or personality options defined by ''NSPointerFunctions/Options''. The ''NSCopying'' and ''NSCoding'' protocols are applicable only when a pointer array is initialized to maintain strong or weak references to objects. When enumerating a pointer array with ''NSFastEnumeration'' using 'for...in', the loop will yield any 'nil' values present in the array. See [Fast Enumeration Makes It Easy to Enumerate a Collection](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/FoundationTypesandCollections/FoundationTypesandCollections.html\#//apple_ref/doc/uid/TP40011210-CH7-SW30) in [Programming with Objective-C](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ProgrammingWithObjectiveC/Introduction/Introduction.html\#//apple_ref/doc/uid/TP40011210) for more information. \#\#\# Subclassing Notes 'NSPointerArray' is not suitable for subclassing.
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
     * @details Adds a given pointer to the receiver. 'pointer' is added at index 'count'. - Parameter pointer: The pointer to add. This value may be 'NULL'.
     * @param pointer Argument converted to the Objective-C parameter of the same role.
     */
        void add_pointer(void* pointer) const;
        /**
     * @brief Calls `-[NSPointerArray compact]`.
     * @details Removes 'NULL' values from the receiver.
     */
        void compact() const;
        /**
     * @brief Calls `-[NSPointerArray insertPointer:atIndex:]`.
     * @details Inserts a pointer at a given index. Elements at and above 'index', including 'NULL' values, slide higher. - Parameter item: The pointer to add. - Parameter index: The index of an element in the receiver. This value must be less than the count of the receiver.
     * @param item Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_pointer(void* item, std::uint64_t index) const;
        /**
     * @brief Calls `+[NSPointerArray pointerArrayWithOptions:]`.
     * @details Returns a new pointer array initialized to use the given options. - Parameter options: The pointer functions options for the new instance. - Returns: A new pointer array initialized to use the given options.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerArray pointer_array_with_options(PointerFunctionsOptions options);
        /**
     * @brief Calls `+[NSPointerArray pointerArrayWithPointerFunctions:]`.
     * @details A new pointer array initialized to use the given functions. - Parameter functions: The pointer functions for the new instance. - Returns: A new pointer array initialized to use the given pointer functions.
     * @param functions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static PointerArray pointer_array_with_pointer_functions(const PointerFunctions& functions);
        /**
     * @brief Calls `-[NSPointerArray pointerAtIndex:]`.
     * @details Returns the pointer at a given index. The returned value may be 'NULL'. - Parameter index: The index of an element in the receiver. This value must be less than the count of the receiver. - Returns: The pointer at 'index'.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        void* pointer_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSPointerArray removePointerAtIndex:]`.
     * @details Removes the pointer at a given index. Elements above 'index', including 'NULL' values, slide lower. - Parameter index: The index of an element in the receiver. This value must be less than the count of the receiver.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_pointer_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSPointerArray replacePointerAtIndex:withPointer:]`.
     * @details Replaces the pointer at a given index. - Parameter index: The index of an element in the receiver. This value must be less than the count of the receiver. - Parameter item: The item with which to replace the element at 'index'. This value may be 'NULL'.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param item Argument converted to the Objective-C parameter of the same role.
     */
        void replace_pointer_at_index(std::uint64_t index, void* item) const;
        /**
     * @brief Calls `+[NSPointerArray strongObjectsPointerArray]`.
     * @details Returns a new pointer array that maintains strong references to its elements.
     * @return The converted Objective-C result.
     */
        static PointerArray strong_objects_pointer_array();
        /**
     * @brief Calls `+[NSPointerArray weakObjectsPointerArray]`.
     * @details Returns a new pointer array that maintains weak references to its elements.
     * @return The converted Objective-C result.
     */
        static PointerArray weak_objects_pointer_array();
        /**
     * @brief Returns the `allObjects` property of `NSPointerArray`.
     * @details All the objects in the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<Object> all_objects() const;
        /**
     * @brief Returns the `count` property of `NSPointerArray`.
     * @details The number of elements in the receiver. If you increase the 'count', 'NULL' values are added. If you decrease the 'count', elements at indexes 'count' and greater are removed.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Sets the `count` property of `NSPointerArray`.
     * @details The number of elements in the receiver. If you increase the 'count', 'NULL' values are added. If you decrease the 'count', elements at indexes 'count' and greater are removed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_count(std::uint64_t value) const;
        /**
     * @brief Returns the `pointerFunctions` property of `NSPointerArray`.
     * @details The functions in use by the receiver. The returned object is a new 'NSPointerFunctions' object that you can modify and/or use directly to create other pointer collections.
     * @return The converted Objective-C result.
     */
        PointerFunctions pointer_functions() const;
    };
}
