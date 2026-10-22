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
     * @details A specialized predicate for comparing expressions. Use comparison predicates to compare the results of two expressions. You create a comparison predicate with an operator, a left expression, and a right expression, and use instances of the ''NSExpression'' class to represent those expressions. When you evaluate the predicate, it returns a 'BOOL' value as the result of invoking the operator with the results of evaluating the expressions.
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
         * @details Returns a new predicate formed by combining the left and right expressions using a given selector. - Parameters: - lhs: The left hand side expression. - rhs: The right hand side expression. - selector: The selector to use for comparison. The method defined by the selector must take a single argument and return a 'BOOL' value. - Returns: A new predicate formed by combining the left and right expressions using 'selector'.
         * @param lhs Argument converted to the Objective-C parameter of the same role.
         * @param rhs Argument converted to the Objective-C parameter of the same role.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ComparisonPredicate predicate_with_left_expression(const Expression& lhs, const Expression& rhs, const std::string& selector);
        /**
         * @brief Calls `+[NSComparisonPredicate predicateWithLeftExpression:rightExpression:modifier:type:options:]`.
         * @details Creates and returns a predicate of a given type formed by combining given left and right expressions using a given modifier and options. - Parameters: - lhs: The left hand expression. - rhs: The right hand expression. - modifier: The modifier to apply. - type: The predicate operator type. - options: The options to apply. For no options, pass '0'. - Returns: A new predicate of type 'type' formed by combining the given left and right expressions using the 'modifier' and 'options'.
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
         * @details The comparison predicate modifier for the receiver. The default value is 'NSDirectPredicateModifier'.
         * @return The converted Objective-C result.
         */
        ComparisonPredicateModifier comparison_predicate_modifier() const;
        /**
         * @brief Returns the `customSelector` property of `NSComparisonPredicate`.
         * @details The selector for the receiver, or 'NULL' if there is none.
         * @return The converted Objective-C result.
         */
        std::string custom_selector() const;
        /**
         * @brief Returns the `leftExpression` property of `NSComparisonPredicate`.
         * @details The left expression for the receiver.
         * @return The converted Objective-C result.
         */
        Expression left_expression() const;
        /**
         * @brief Returns the `options` property of `NSComparisonPredicate`.
         * @details The options to use for the receiver.
         * @return The converted Objective-C result.
         */
        ComparisonPredicateOptions options() const;
        /**
         * @brief Returns the `predicateOperatorType` property of `NSComparisonPredicate`.
         * @details The predicate type for the receiver.
         * @return The converted Objective-C result.
         */
        PredicateOperatorType predicate_operator_type() const;
        /**
         * @brief Returns the `rightExpression` property of `NSComparisonPredicate`.
         * @details The right expression for the receiver.
         * @return The converted Objective-C result.
         */
        Expression right_expression() const;
    };
}
