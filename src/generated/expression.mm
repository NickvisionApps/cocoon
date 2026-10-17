#include "generated/expression.h"
#include "internal.h"

namespace cocoon
{
    Expression::Expression(ExpressionType type) : Expression(Adopt{cocoon::internal::retain([[::NSExpression alloc] initWithExpressionType:static_cast<::NSExpressionType>(type)])})
    {
    }

    Expression::Expression() : Expression(Adopt{cocoon::internal::retain([[::NSExpression alloc] init])})
    {
    }

    Expression::Expression(std::nullptr_t) : Object(nullptr)
    {
    }

    Expression::Expression(Adopt adopt) : Object(adopt)
    {
    }

    void Expression::allow_evaluation() const
    {
        [cocoon::internal::ns<::NSExpression>(this) allowEvaluation];
    }

    Expression Expression::expression_for_aggregate(const std::vector<Expression>& subexpressions)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForAggregate:cocoon::internal::to_array(subexpressions, [](const Expression& e) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::native<::NSExpression>(e);
                                                                                                                    })]);
    }

    Expression Expression::expression_for_any_key()
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForAnyKey]);
    }

    Expression Expression::expression_for_block(std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> block, const std::vector<Expression>& arguments)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForBlock:(block ? (id(^)(id, NSArray<NSExpression*>*, ::NSMutableDictionary*)) ^ id(id a132_0, NSArray * a132_1, NSDictionary * a132_2) { auto __r = block(cocoon::internal::wrap<Object>(a132_0), cocoon::internal::from_array<Expression>(a132_1, [](id e) -> Expression { return cocoon::internal::wrap<Expression>((::NSExpression *)e); }), cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>(a132_2, [](id k) -> Object { return cocoon::internal::wrap<Object>(k); }, [](id v) -> Object { return cocoon::internal::wrap<Object>(v); })); return cocoon::internal::native_id(__r); } : (id(^)(id, NSArray<NSExpression*>*, ::NSMutableDictionary*))nil)
                                                                           arguments:cocoon::internal::to_array(arguments, [](const Expression& e) -> id
                                                                                                                {
                                                                                                                    return cocoon::internal::native<::NSExpression>(e);
                                                                                                                })]);
    }

    Expression Expression::expression_for_conditional(const Predicate& predicate, const Expression& true_expression, const Expression& false_expression)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForConditional:cocoon::internal::native<::NSPredicate>(predicate) trueExpression:cocoon::internal::native<::NSExpression>(true_expression) falseExpression:cocoon::internal::native<::NSExpression>(false_expression)]);
    }

    Expression Expression::expression_for_constant_value(const Object& obj)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForConstantValue:cocoon::internal::native_id(obj)]);
    }

    Expression Expression::expression_for_evaluated_object()
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForEvaluatedObject]);
    }

    Expression Expression::expression_for_function(const std::string& name, const std::vector<Object>& parameters)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForFunction:cocoon::internal::to(name)
                                                                              arguments:cocoon::internal::to_array(parameters, [](const Object& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::native_id(e);
                                                                                                                   })]);
    }

    Expression Expression::expression_for_function(const Expression& target, const std::string& name, const std::vector<Object>& parameters)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForFunction:cocoon::internal::native<::NSExpression>(target)
                                                                           selectorName:cocoon::internal::to(name)
                                                                              arguments:cocoon::internal::to_array(parameters, [](const Object& e) -> id
                                                                                                                   {
                                                                                                                       return cocoon::internal::native_id(e);
                                                                                                                   })]);
    }

    Expression Expression::expression_for_intersect_set(const Expression& left, const Expression& right)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForIntersectSet:cocoon::internal::native<::NSExpression>(left) with:cocoon::internal::native<::NSExpression>(right)]);
    }

    Expression Expression::expression_for_key_path(const std::string& key_path)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForKeyPath:cocoon::internal::to(key_path)]);
    }

    Expression Expression::expression_for_minus_set(const Expression& left, const Expression& right)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForMinusSet:cocoon::internal::native<::NSExpression>(left) with:cocoon::internal::native<::NSExpression>(right)]);
    }

    Expression Expression::expression_for_subquery(const Expression& expression, const std::string& variable, const Predicate& predicate)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForSubquery:cocoon::internal::native<::NSExpression>(expression) usingIteratorVariable:cocoon::internal::to(variable) predicate:cocoon::internal::native<::NSPredicate>(predicate)]);
    }

    Expression Expression::expression_for_union_set(const Expression& left, const Expression& right)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForUnionSet:cocoon::internal::native<::NSExpression>(left) with:cocoon::internal::native<::NSExpression>(right)]);
    }

    Expression Expression::expression_for_variable(const std::string& string)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionForVariable:cocoon::internal::to(string)]);
    }

    Object Expression::expression_value_with_object(const Object& object, const std::vector<std::pair<Object, Object>>& context) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSExpression>(this) expressionValueWithObject:cocoon::internal::native_id(object)
                                                                                                            context:[cocoon::internal::to_dictionary(context, [](const Object& k) -> id
                                                                                                                                                     {
                                                                                                                                                         return cocoon::internal::native_id(k);
                                                                                                                                                     },
                                                                                                                                                     [](const Object& v) -> id
                                                                                                                                                     {
                                                                                                                                                         return cocoon::internal::native_id(v);
                                                                                                                                                     }) mutableCopy]]);
    }

    Expression Expression::expression_with_format_(const std::string& expression_format, const std::vector<VarArg>& args)
    {
        std::vector<std::uint64_t> __slots = cocoon::internal::pack_var_args(args);
        va_list __list = cocoon::internal::make_va_list(__slots);
        return cocoon::internal::wrap<Expression>([::NSExpression expressionWithFormat:cocoon::internal::to(expression_format) arguments:__list]);
    }

    Expression Expression::expression_with_format(const std::string& expression_format, const std::vector<Object>& arguments)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionWithFormat:cocoon::internal::to(expression_format)
                                                                         argumentArray:cocoon::internal::to_array(arguments, [](const Object& e) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(e);
                                                                                                                  })]);
    }

    Expression Expression::expression_with_format(const std::string& expression_format, char* arg_list)
    {
        return cocoon::internal::wrap<Expression>([::NSExpression expressionWithFormat:cocoon::internal::to(expression_format) arguments:(::va_list)(arg_list)]);
    }

    std::vector<Expression> Expression::arguments() const
    {
        return cocoon::internal::from_array<Expression>([cocoon::internal::ns<::NSExpression>(this) arguments], [](id e) -> Expression
                                                        {
                                                            return cocoon::internal::wrap<Expression>((::NSExpression*)e);
                                                        });
    }

    Object Expression::collection() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSExpression>(this) collection]);
    }

    Object Expression::constant_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSExpression>(this) constantValue]);
    }

    std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)> Expression::expression_block() const
    {
        return [&]() -> std::function<Object(Object, std::vector<Expression>, std::vector<std::pair<Object, Object>>)>
        {
            auto blk = (id(^)(id, NSArray<NSExpression*>*, ::NSMutableDictionary*))([cocoon::internal::ns<::NSExpression>(this) expressionBlock]);
            if (!blk)
            {
                return {};
            }
            return [blk](Object a133_0, std::vector<Expression> a133_1, std::vector<std::pair<Object, Object>> a133_2) -> Object
            {
                auto __r = blk(cocoon::internal::native_id(a133_0), cocoon::internal::to_array(a133_1, [](const Expression& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSExpression>(e);
                                                                                               }),
                               [cocoon::internal::to_dictionary(a133_2, [](const Object& k) -> id
                                                                {
                                                                    return cocoon::internal::native_id(k);
                                                                },
                                                                [](const Object& v) -> id
                                                                {
                                                                    return cocoon::internal::native_id(v);
                                                                }) mutableCopy]);
                return cocoon::internal::wrap<Object>(__r);
            };
        }();
    }

    ExpressionType Expression::expression_type() const
    {
        return static_cast<ExpressionType>([cocoon::internal::ns<::NSExpression>(this) expressionType]);
    }

    Expression Expression::false_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSExpression>(this) falseExpression]);
    }

    std::string Expression::function() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSExpression>(this) function]);
    }

    std::string Expression::key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSExpression>(this) keyPath]);
    }

    Expression Expression::left_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSExpression>(this) leftExpression]);
    }

    Expression Expression::operand() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSExpression>(this) operand]);
    }

    Predicate Expression::predicate() const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSExpression>(this) predicate]);
    }

    Expression Expression::right_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSExpression>(this) rightExpression]);
    }

    Expression Expression::true_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSExpression>(this) trueExpression]);
    }

    std::string Expression::variable() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSExpression>(this) variable]);
    }
}
