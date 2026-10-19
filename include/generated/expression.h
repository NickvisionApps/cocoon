#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Predicate;

    /**
     * @brief C++ handle for the Objective-C class `NSExpression` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Expression expression;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Expression expression{};
     * auto made_0 = cocoon::Expression::expression_for_any_key();
     * auto made_1 = cocoon::Expression::expression_for_conditional(cocoon::Predicate(), cocoon::Expression(), cocoon::Expression());
     * expression.allow_evaluation();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsexpression
     */
    class Expression : public Object
    {
    public:
        /// @brief Creates a new `NSExpression` instance and returns a handle to it.
        explicit Expression(ExpressionType type);
        /// @brief Creates a new `NSExpression` instance and returns a handle to it.
        explicit Expression();
        /// @brief Creates a null handle that refers to no native object.
        Expression(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Expression(Adopt adopt);
        /**
     * @brief Calls `-[NSExpression allowEvaluation]`.
     */
        void allow_evaluation() const;
        /**
     * @brief Calls `+[NSExpression expressionForAggregate:]`.
     * @param subexpressions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_aggregate(const std::vector<Expression>& subexpressions);
        /**
     * @brief Calls `+[NSExpression expressionForAnyKey]`.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_any_key();
        /**
     * @brief Calls `+[NSExpression expressionForBlock:arguments:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_block(std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> block, const std::vector<Expression>& arguments);
        /**
     * @brief Calls `+[NSExpression expressionForConditional:trueExpression:falseExpression:]`.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @param true_expression Argument converted to the Objective-C parameter of the same role.
     * @param false_expression Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_conditional(const Predicate& predicate, const Expression& true_expression, const Expression& false_expression);
        /**
     * @brief Calls `+[NSExpression expressionForConstantValue:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_constant_value(const Object& obj);
        /**
     * @brief Calls `+[NSExpression expressionForEvaluatedObject]`.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_evaluated_object();
        /**
     * @brief Calls `+[NSExpression expressionForFunction:arguments:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param parameters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_function(const std::string& name, const std::vector<Object>& parameters);
        /**
     * @brief Calls `+[NSExpression expressionForFunction:selectorName:arguments:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param parameters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_function(const Expression& target, const std::string& name, const std::vector<Object>& parameters);
        /**
     * @brief Calls `+[NSExpression expressionForIntersectSet:with:]`.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_intersect_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForKeyPath:]`.
     * @param key_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_key_path(const std::string& key_path);
        /**
     * @brief Calls `+[NSExpression expressionForMinusSet:with:]`.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_minus_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForSubquery:usingIteratorVariable:predicate:]`.
     * @param expression Argument converted to the Objective-C parameter of the same role.
     * @param variable Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_subquery(const Expression& expression, const std::string& variable, const Predicate& predicate);
        /**
     * @brief Calls `+[NSExpression expressionForUnionSet:with:]`.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_union_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForVariable:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_variable(const std::string& string);
        /**
     * @brief Calls `-[NSExpression expressionValueWithObject:context:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object expression_value_with_object(const Object& object, const std::vector<std::pair<Object, Object>>& context) const;
        template <class... Args>
        static Expression expression_with_format(const std::string& expression_format, const Args&... args)
        {
            return expression_with_format_(expression_format, std::vector<VarArg>{VarArg(args)...});
        }
        /**
     * @brief Calls `+[NSExpression ]`.
     * @param expression_format Argument converted to the Objective-C parameter of the same role.
     * @param args Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_with_format_(const std::string& expression_format, const std::vector<VarArg>& args);
        /**
     * @brief Calls `+[NSExpression expressionWithFormat:argumentArray:]`.
     * @param expression_format Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_with_format(const std::string& expression_format, const std::vector<Object>& arguments);
        /**
     * @brief Calls `+[NSExpression expressionWithFormat:arguments:]`.
     * @param expression_format Argument converted to the Objective-C parameter of the same role.
     * @param arg_list Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_with_format(const std::string& expression_format, char* arg_list);
        /**
     * @brief Returns the `arguments` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        std::vector<Expression> arguments() const;
        /**
     * @brief Returns the `collection` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Object collection() const;
        /**
     * @brief Returns the `constantValue` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Object constant_value() const;
        /**
     * @brief Returns the `expressionBlock` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> expression_block() const;
        /**
     * @brief Returns the `expressionType` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        ExpressionType expression_type() const;
        /**
     * @brief Returns the `falseExpression` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Expression false_expression() const;
        /**
     * @brief Returns the `function` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        std::string function() const;
        /**
     * @brief Returns the `keyPath` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        std::string key_path() const;
        /**
     * @brief Returns the `leftExpression` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Expression left_expression() const;
        /**
     * @brief Returns the `operand` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Expression operand() const;
        /**
     * @brief Returns the `predicate` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Predicate predicate() const;
        /**
     * @brief Returns the `rightExpression` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Expression right_expression() const;
        /**
     * @brief Returns the `trueExpression` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        Expression true_expression() const;
        /**
     * @brief Returns the `variable` property of `NSExpression`.
     * @return The converted Objective-C result.
     */
        std::string variable() const;
    };
}
