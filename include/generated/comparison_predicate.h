#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/predicate.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Expression;

    /**
     * @brief C++ handle for the Objective-C class `NSComparisonPredicate` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Predicate.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ComparisonPredicate comparison_predicate;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ComparisonPredicate comparison_predicate{};
     * auto made_0 = cocoon::ComparisonPredicate::predicate_with_left_expression(cocoon::Expression(), cocoon::Expression(), "text");
     * auto made_1 = cocoon::ComparisonPredicate::predicate_with_left_expression(cocoon::Expression(), cocoon::Expression(), cocoon::ComparisonPredicateModifier::DirectPredicateModifier, cocoon::PredicateOperatorType::LessThanPredicateOperatorType, cocoon::ComparisonPredicateOptions::CaseInsensitivePredicateOption);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscomparisonpredicate
     */
    class ComparisonPredicate : public Predicate
    {
    public:
        /// @brief Creates a new `NSComparisonPredicate` instance and returns a handle to it.
        explicit ComparisonPredicate(const Expression& lhs, const Expression& rhs, const std::string& selector);
        /// @brief Creates a new `NSComparisonPredicate` instance and returns a handle to it.
        explicit ComparisonPredicate(const Expression& lhs, const Expression& rhs, ComparisonPredicateModifier modifier, PredicateOperatorType type, ComparisonPredicateOptions options);
        /// @brief Creates a new `NSComparisonPredicate` instance and returns a handle to it.
        explicit ComparisonPredicate();
        /// @brief Creates a null handle that refers to no native object.
        ComparisonPredicate(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ComparisonPredicate(Adopt adopt);
        /**
         * @brief Calls `+[NSComparisonPredicate predicateWithLeftExpression:rightExpression:customSelector:]`.
         * @param lhs Argument converted to the Objective-C parameter of the same role.
         * @param rhs Argument converted to the Objective-C parameter of the same role.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ComparisonPredicate predicate_with_left_expression(const Expression& lhs, const Expression& rhs, const std::string& selector);
        /**
         * @brief Calls `+[NSComparisonPredicate predicateWithLeftExpression:rightExpression:modifier:type:options:]`.
         * @param lhs Argument converted to the Objective-C parameter of the same role.
         * @param rhs Argument converted to the Objective-C parameter of the same role.
         * @param modifier Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ComparisonPredicate predicate_with_left_expression(const Expression& lhs, const Expression& rhs, ComparisonPredicateModifier modifier, PredicateOperatorType type, ComparisonPredicateOptions options);
        /**
         * @brief Returns the `comparisonPredicateModifier` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        ComparisonPredicateModifier comparison_predicate_modifier() const;
        /**
         * @brief Returns the `customSelector` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        std::string custom_selector() const;
        /**
         * @brief Returns the `leftExpression` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        Expression left_expression() const;
        /**
         * @brief Returns the `options` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        ComparisonPredicateOptions options() const;
        /**
         * @brief Returns the `predicateOperatorType` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        PredicateOperatorType predicate_operator_type() const;
        /**
         * @brief Returns the `rightExpression` property of `NSComparisonPredicate`.
         * @return The converted Objective-C result.
         */
        Expression right_expression() const;
    };
}
