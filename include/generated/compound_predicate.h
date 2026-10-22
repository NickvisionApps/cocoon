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
     * @details A specialized predicate that evaluates logical combinations of other predicates. Use ''NSCompoundPredicate'' to create an 'AND' or 'OR' compound predicate of one or more other predicates, or the 'NOT' of a single predicate. For the logical 'AND' and 'OR' operations: - An 'AND' predicate with no subpredicates evaluates to \<doc://com.apple.documentation/documentation/swift/true>. - An 'OR' predicate with no subpredicates evaluates to \<doc://com.apple.documentation/documentation/swift/false>. - A compound predicate with one or more subpredicates evaluates to the truth of its subpredicates.
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
         * @details Returns a new predicate that you form using an AND operation on the predicates in a specified array. - Parameters: - subpredicates: An array of 'NSPredicate' objects. - Returns: A new predicate formed by AND-ing the predicates specified by 'subpredicates'. An AND predicate with no subpredicates evaluates to TRUE.
         * @param subpredicates Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate and_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates);
        /**
         * @brief Calls `+[NSCompoundPredicate notPredicateWithSubpredicate:]`.
         * @details Returns a new predicate that you form using a NOT operation on a specified predicate.
         * @param predicate Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate not_predicate_with_subpredicate(const Predicate& predicate);
        /**
         * @brief Calls `+[NSCompoundPredicate orPredicateWithSubpredicates:]`.
         * @details Returns a new predicate that you form using an OR operation on the predicates in a specified array. An OR predicate with no subpredicates evaluates to FALSE.
         * @param subpredicates Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static CompoundPredicate or_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates);
        /**
         * @brief Returns the `compoundPredicateType` property of `NSCompoundPredicate`.
         * @details The predicate type for the receiver.
         * @return The converted Objective-C result.
         */
        CompoundPredicateType compound_predicate_type() const;
        /**
         * @brief Returns the `subpredicates` property of `NSCompoundPredicate`.
         * @details The receiver's subpredicates.
         * @return The converted Objective-C result.
         */
        std::vector<Object> subpredicates() const;
    };
}
