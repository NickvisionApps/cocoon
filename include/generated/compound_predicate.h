#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/predicate.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Predicate;

    /**
     * @brief C++ handle for the Objective-C class `NSCompoundPredicate` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Predicate.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CompoundPredicate compound_predicate;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CompoundPredicate compound_predicate{};
     * auto made_0 = cocoon::CompoundPredicate::not_predicate_with_subpredicate(cocoon::Predicate());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscompoundpredicate
     */
    class CompoundPredicate : public Predicate
    {
    public:
        /// @brief Creates a new `NSCompoundPredicate` instance and returns a handle to it.
        explicit CompoundPredicate(CompoundPredicateType type, const std::vector<Predicate>& subpredicates);
        /// @brief Creates a new `NSCompoundPredicate` instance and returns a handle to it.
        explicit CompoundPredicate();
        /// @brief Creates a null handle that refers to no native object.
        CompoundPredicate(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CompoundPredicate(Adopt adopt);
        /**
         * @brief Calls `+[NSCompoundPredicate andPredicateWithSubpredicates:]`.
         * @details Convenience Methods
         * @param subpredicates Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate and_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates);
        /**
         * @brief Calls `+[NSCompoundPredicate notPredicateWithSubpredicate:]`.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate not_predicate_with_subpredicate(const Predicate& predicate);
        /**
         * @brief Calls `+[NSCompoundPredicate orPredicateWithSubpredicates:]`.
         * @param subpredicates Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate or_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates);
        /**
         * @brief Returns the `compoundPredicateType` property of `NSCompoundPredicate`.
         * @return The converted Objective-C result.
         */
        CompoundPredicateType compound_predicate_type() const;
        /**
         * @brief Returns the `subpredicates` property of `NSCompoundPredicate`.
         * @return The converted Objective-C result.
         */
        std::vector<Object> subpredicates() const;
    };
}
