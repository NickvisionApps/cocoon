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
     * @details An expression for use in a comparison predicate. Comparison operations in an ''NSPredicate'' derive from two expressions as instances of the ''NSExpression'' class. You create expressions for constant values, key paths, and so on. Generally, anywhere in the ''NSExpression'' class hierarchy where there's a composite API and subtypes that may only reasonably respond to a subset of that API, invoking a method that doesn't make sense for that subtype throws an exception. \#\#\# Aggregate Expressions ''ExpressionType/aggregate'' allows you to create predicates containing expressions that evaluate to collections that contain further expressions. The collection may be an ''NSArray'', ''NSSet'', or ''NSDictionary'' object. Core Data doesn't support aggregate expressions. \#\#\# Subquery Expressions The ''ExpressionType/subquery'' creates a subexpression that returns a subset of a collection of objects. This allows you to create sophisticated queries across relationships, such as a search for multiple correlated values on the destination object of a relationship. \#\#\# Set Expressions The set expressions (''ExpressionType/unionSet'', ''ExpressionType/intersectSet'', and ''ExpressionType/minusSet'') combine results in a manner similar to the ''NSSet'' methods. Both sides of these expressions must evaluate to a collection; the left side must evaluate to an 'NSSet' object, and the right side can be any other collection type. '''objc (expression UNION expression) (expression INTERSECT expression) (expression MINUS expression) ''' Core Data doesn't support set expressions. \#\#\# Function Expressions In macOS 10.4, ''NSExpression'' only supports a predefined set of functions: 'sum', 'count', 'min', 'max', and 'average'. You access these predefined functions in the predicate syntax using custom keywords (for example, 'MAX(1, 5, 10)'). In macOS 10.5 and later, function expressions also support arbitrary method invocations. To implement this extended functionality, use the syntax 'FUNCTION(receiver, selectorName, arguments, ...),' as in the following example: '''objc FUNCTION(\@"/Developer/Tools/otest", \@"lastPathComponent") => \@"otest" ''' All methods must take one or more 'id' arguments and return an 'id' value, although you can use the 'CAST' expression to convert datatypes with lossy string representations (for example, 'CAST(\#\#\#\#, "NSDate")'). macOS 10.5 extends the 'CAST' expression to provide support for casting to classes for use in creating receivers for function expressions. Although Core Data supports evaluation of the predefined functions, it doesn't support the evaluation of custom predicate functions in the persistent stores (during a fetch).
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
     * @details Forces a securely decoded expression to allow evaluation. When securely decoding an 'NSExpression' object encoded using 'NSSecureCoding', evaluation is disabled because it is potentially unsafe to evaluate expressions you get out of an archive. Before you enable evaluation, you should validate key paths, selectors, etc to ensure no erroneous or malicious code will be executed. Once you've preflighted the expression, you can enable the expression for evaluation by calling 'allowEvaluation'.
     */
        void allow_evaluation() const;
        /**
     * @brief Calls `+[NSExpression expressionForAggregate:]`.
     * @details Creates an expression that returns a collection containing the results of other expressions.
     * @param subexpressions Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_aggregate(const std::vector<Expression>& subexpressions);
        /**
     * @brief Calls `+[NSExpression expressionForAnyKey]`.
     * @details Creates an expression that represents any key for a Spotlight query.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_any_key();
        /**
     * @brief Calls `+[NSExpression expressionForBlock:arguments:]`.
     * @details Creates an expression that invokes a block with the parameters.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_block(std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> block, const std::vector<Expression>& arguments);
        /**
     * @brief Calls `+[NSExpression expressionForConditional:trueExpression:falseExpression:]`.
     * @details Creates an expression that will return the result of trueExpression or falseExpression depending on the value of predicate.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @param true_expression Argument converted to the Objective-C parameter of the same role.
     * @param false_expression Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_conditional(const Predicate& predicate, const Expression& true_expression, const Expression& false_expression);
        /**
     * @brief Calls `+[NSExpression expressionForConstantValue:]`.
     * @details Creates an expression that returns a constant value.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_constant_value(const Object& obj);
        /**
     * @brief Calls `+[NSExpression expressionForEvaluatedObject]`.
     * @details Creates an expression that represents the object you're evaluating.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_evaluated_object();
        /**
     * @brief Calls `+[NSExpression expressionForFunction:arguments:]`.
     * @details Creates an expression that invokes one of the predefined functions.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param parameters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_function(const std::string& name, const std::vector<Object>& parameters);
        /**
     * @brief Calls `+[NSExpression expressionForFunction:selectorName:arguments:]`.
     * @details Creates an expression that invokes a selector on a target with parameters.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param parameters Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_function(const Expression& target, const std::string& name, const std::vector<Object>& parameters);
        /**
     * @brief Calls `+[NSExpression expressionForIntersectSet:with:]`.
     * @details Returns an expression that will return the intersection of the collections expressed by left and right.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_intersect_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForKeyPath:]`.
     * @details Creates an expression that invokes the value function with a specified key path. - Parameters: - keyPath: The key path that the new expression should evaluate. - Returns: A new expression that invokes 'value(forKeyPath:)' with 'keyPath'.
     * @param key_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_key_path(const std::string& key_path);
        /**
     * @brief Calls `+[NSExpression expressionForMinusSet:with:]`.
     * @details Returns an expression that will return the disjunction of the collections expressed by left and right.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_minus_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForSubquery:usingIteratorVariable:predicate:]`.
     * @details Creates an expression that filters a collection using a subquery.
     * @param expression Argument converted to the Objective-C parameter of the same role.
     * @param variable Argument converted to the Objective-C parameter of the same role.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_subquery(const Expression& expression, const std::string& variable, const Predicate& predicate);
        /**
     * @brief Calls `+[NSExpression expressionForUnionSet:with:]`.
     * @details Returns an expression that will return the union of the collections expressed by left and right.
     * @param left Argument converted to the Objective-C parameter of the same role.
     * @param right Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_union_set(const Expression& left, const Expression& right);
        /**
     * @brief Calls `+[NSExpression expressionForVariable:]`.
     * @details Creates an expression that pulls a value from the variable bindings dictionary.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_for_variable(const std::string& string);
        /**
     * @brief Calls `-[NSExpression expressionValueWithObject:context:]`.
     * @details Evaluates an expression using a specified object and context.
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
     * @details Creates the expression with the specified expression arguments.
     * @param expression_format Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_with_format(const std::string& expression_format, const std::vector<Object>& arguments);
        /**
     * @brief Calls `+[NSExpression expressionWithFormat:arguments:]`.
     * @details Creates the expression with the specified expression arguments.
     * @param expression_format Argument converted to the Objective-C parameter of the same role.
     * @param arg_list Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Expression expression_with_format(const std::string& expression_format, char* arg_list);
        /**
     * @brief Returns the `arguments` property of `NSExpression`.
     * @details The arguments for the expression. The array of expressions which will be passed as parameters during invocation of the selector on the operand of a function expression.
     * @return The converted Objective-C result.
     */
        std::vector<Expression> arguments() const;
        /**
     * @brief Returns the `collection` property of `NSExpression`.
     * @details The collection of expressions in an aggregate expression, or the collection element of a subquery expression.
     * @return The converted Objective-C result.
     */
        Object collection() const;
        /**
     * @brief Returns the `constantValue` property of `NSExpression`.
     * @details The constant value of the expression.
     * @return The converted Objective-C result.
     */
        Object constant_value() const;
        /**
     * @brief Returns the `expressionBlock` property of `NSExpression`.
     * @details The block that executes to evaluate the expression.
     * @return The converted Objective-C result.
     */
        std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> expression_block() const;
        /**
     * @brief Returns the `expressionType` property of `NSExpression`.
     * @details The expression type for the expression. Accessing this property raises an exception if it is not applicable to the expression.
     * @return The converted Objective-C result.
     */
        ExpressionType expression_type() const;
        /**
     * @brief Returns the `falseExpression` property of `NSExpression`.
     * @details An expression to evaluate if a conditional expression's predicate evaluates to false.
     * @return The converted Objective-C result.
     */
        Expression false_expression() const;
        /**
     * @brief Returns the `function` property of `NSExpression`.
     * @details The function for the expression.
     * @return The converted Objective-C result.
     */
        std::string function() const;
        /**
     * @brief Returns the `keyPath` property of `NSExpression`.
     * @details The key path for the expression.
     * @return The converted Objective-C result.
     */
        std::string key_path() const;
        /**
     * @brief Returns the `leftExpression` property of `NSExpression`.
     * @details The left expression of an aggregate expression.
     * @return The converted Objective-C result.
     */
        Expression left_expression() const;
        /**
     * @brief Returns the `operand` property of `NSExpression`.
     * @details The operand for the expression. The operand is the object on which the expression's selector or block will be invoked. The object is the result of evaluating a key path or one of the defined functions.
     * @return The converted Objective-C result.
     */
        Expression operand() const;
        /**
     * @brief Returns the `predicate` property of `NSExpression`.
     * @details The predicate of a subquery expression.
     * @return The converted Objective-C result.
     */
        Predicate predicate() const;
        /**
     * @brief Returns the `rightExpression` property of `NSExpression`.
     * @details The right expression of an aggregate expression.
     * @return The converted Objective-C result.
     */
        Expression right_expression() const;
        /**
     * @brief Returns the `trueExpression` property of `NSExpression`.
     * @details An expression to evaluate if a conditional expression's predicate evaluates to true.
     * @return The converted Objective-C result.
     */
        Expression true_expression() const;
        /**
     * @brief Returns the `variable` property of `NSExpression`.
     * @details The variable for the expression.
     * @return The converted Objective-C result.
     */
        std::string variable() const;
    };
}
