#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSortDescriptor` (Foundation).
     * @details An immutable description of how to order a collection of objects according to a property common to all the objects. You construct instances of ''NSSortDescriptor'' by specifying the key path of the property to compare and the order of the sort (ascending or descending). Optionally, you can also specify a selector to use to perform the comparison, which allows you to specify other comparison selectors, such as ''NSString/localizedStandardCompare(:)'' and ''NSString/localizedCaseInsensitiveCompare(:)''. Sorting raises an exception if the objects don't respond to the sort descriptor's comparison selector. You can use sort descriptors for the following: - Sorting an array (an instance of ''NSArray'' or ''NSMutableArray'' — see ''NSArray/sortedArray(using:)-82wi1'' and ''NSMutableArray/sort(using:)-4eh07'') - Comparing two objects directly (see ''compare(:to:)'') - Specifying the order of objects that return from a Core Data fetch request (see \<doc://com.apple.documentation/documentation/coredata/nsfetchrequest/sortdescriptors>)
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SortDescriptor sort_descriptor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SortDescriptor sort_descriptor{};
     * sort_descriptor.allow_evaluation();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nssortdescriptor
     */
    class SortDescriptor : public Object
    {
    public:
        /// @brief Creates a new `NSSortDescriptor` instance and returns a handle to it.
        explicit SortDescriptor(const std::string& key, bool ascending);
        /// @brief Creates a new `NSSortDescriptor` instance and returns a handle to it.
        explicit SortDescriptor(const std::string& key, bool ascending, std::function<ComparisonResult(Object, Object)> cmptr);
        /// @brief Creates a new `NSSortDescriptor` instance and returns a handle to it.
        explicit SortDescriptor(const std::string& key, bool ascending, const std::string& selector);
        /// @brief Creates a new `NSSortDescriptor` instance and returns a handle to it.
        explicit SortDescriptor();
        /// @brief Creates a null handle that refers to no native object.
        SortDescriptor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SortDescriptor(Adopt adopt);
        /**
         * @brief Calls `-[NSSortDescriptor allowEvaluation]`.
         * @details Forces a securely decoded sort descriptor to allow evaluation. When securely decoding 'NSSortDescriptor' objects encoded using 'NSSecureCoding', evaluation is disabled because it is potentially unsafe to evaluate descriptors you get out of an archive. Before you enable evaluation, you should validate key paths, selectors, and related properties to ensure no erroneous or malicious code will be executed. Once you've preflighted the sort descriptor, you can enable it for evaluation by calling this method.
         */
        void allow_evaluation() const;
        /**
         * @brief Calls `-[NSSortDescriptor compareObject:toObject:]`.
         * @details Returns a comparison result value that indicates the sort order of two objects. The ordering is determined by comparing the values specified by the sort descriptor's key of 'object1' and 'object2' using the selector specified by the sort descriptor's selector. - Parameters: - object1: The object to compare with 'object2'. This object must have a property accessible using the key-path specified by the sort descriptor's key. - object2: The object to compare with 'object1'. This object must have a property accessible using the key-path specified by the sort descriptor's key. - Returns: 'NSOrderedAscending' if 'object1' is less than 'object2', 'NSOrderedDescending' if 'object1' is greater than 'object2', or 'NSOrderedSame' if 'object1' is equal to 'object2'.
         * @param object1 Argument converted to the Objective-C parameter of the same role.
         * @param object2 Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ComparisonResult compare_object(const Object& object1, const Object& object2) const;
        /**
         * @brief Returns the `ascending` property of `NSSortDescriptor`.
         * @details A Boolean value that indicates whether the receiver specifies sorting in ascending order. 'YES' if the receiver specifies sorting in ascending order, otherwise 'NO'.
         * @return The converted Objective-C result.
         */
        bool ascending() const;
        /**
         * @brief Returns the `comparator` property of `NSSortDescriptor`.
         * @details The comparator for the sort descriptor. Call this property only for sort descriptors initialized with 'initWithKey:ascending:comparator:'.
         * @return The converted Objective-C result.
         */
        std::function<ComparisonResult(Object, Object)> comparator() const;
        /**
         * @brief Returns the `key` property of `NSSortDescriptor`.
         * @details The key that specifies the property to compare during sorting.
         * @return The converted Objective-C result.
         */
        std::string key() const;
        /**
         * @brief Returns the `reversedSortDescriptor` property of `NSSortDescriptor`.
         * @details Returns a sort descriptor that reverses the sort order.
         * @return The converted Objective-C result.
         */
        Object reversed_sort_descriptor() const;
        /**
         * @brief Returns the `selector` property of `NSSortDescriptor`.
         * @details The selector for comparing objects.
         * @return The converted Objective-C result.
         */
        std::string selector() const;
    };
}
