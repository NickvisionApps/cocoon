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
         */
        void allow_evaluation() const;
        /**
         * @brief Calls `-[NSSortDescriptor compareObject:toObject:]`.
         * @param object1 Argument converted to the Objective-C parameter of the same role.
         * @param object2 Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ComparisonResult compare_object(const Object& object1, const Object& object2) const;
        /**
         * @brief Returns the `ascending` property of `NSSortDescriptor`.
         * @return The converted Objective-C result.
         */
        bool ascending() const;
        /**
         * @brief Returns the `comparator` property of `NSSortDescriptor`.
         * @return The converted Objective-C result.
         */
        std::function<ComparisonResult(Object, Object)> comparator() const;
        /**
         * @brief Returns the `key` property of `NSSortDescriptor`.
         * @return The converted Objective-C result.
         */
        std::string key() const;
        /**
         * @brief Returns the `reversedSortDescriptor` property of `NSSortDescriptor`.
         * @return The converted Objective-C result.
         */
        Object reversed_sort_descriptor() const;
        /**
         * @brief Returns the `selector` property of `NSSortDescriptor`.
         * @return The converted Objective-C result.
         */
        std::string selector() const;
    };
}
