#include "generated/comparison_predicate.h"
#include "internal.h"

namespace cocoon
{
    ComparisonPredicate::ComparisonPredicate(const Expression& lhs, const Expression& rhs, const std::string& selector) : ComparisonPredicate(Adopt{cocoon::internal::retain([[::NSComparisonPredicate alloc] initWithLeftExpression:cocoon::internal::native<::NSExpression>(lhs) rightExpression:cocoon::internal::native<::NSExpression>(rhs) customSelector:NSSelectorFromString(cocoon::internal::to(selector))])})
    {
    }

    ComparisonPredicate::ComparisonPredicate(const Expression& lhs, const Expression& rhs, ComparisonPredicateModifier modifier, PredicateOperatorType type, ComparisonPredicateOptions options) : ComparisonPredicate(Adopt{cocoon::internal::retain([[::NSComparisonPredicate alloc] initWithLeftExpression:cocoon::internal::native<::NSExpression>(lhs) rightExpression:cocoon::internal::native<::NSExpression>(rhs) modifier:static_cast<::NSComparisonPredicateModifier>(modifier) type:static_cast<::NSPredicateOperatorType>(type) options:static_cast<::NSComparisonPredicateOptions>(options)])})
    {
    }

    ComparisonPredicate::ComparisonPredicate() : ComparisonPredicate(Adopt{cocoon::internal::retain([[::NSComparisonPredicate alloc] init])})
    {
    }

    ComparisonPredicate::ComparisonPredicate(std::nullptr_t) : Predicate(nullptr)
    {
    }

    ComparisonPredicate::ComparisonPredicate(Adopt adopt) : Predicate(adopt)
    {
    }

    ComparisonPredicate ComparisonPredicate::predicate_with_left_expression(const Expression& lhs, const Expression& rhs, const std::string& selector)
    {
        return cocoon::internal::wrap<ComparisonPredicate>([::NSComparisonPredicate predicateWithLeftExpression:cocoon::internal::native<::NSExpression>(lhs) rightExpression:cocoon::internal::native<::NSExpression>(rhs) customSelector:NSSelectorFromString(cocoon::internal::to(selector))]);
    }

    ComparisonPredicate ComparisonPredicate::predicate_with_left_expression(const Expression& lhs, const Expression& rhs, ComparisonPredicateModifier modifier, PredicateOperatorType type, ComparisonPredicateOptions options)
    {
        return cocoon::internal::wrap<ComparisonPredicate>([::NSComparisonPredicate predicateWithLeftExpression:cocoon::internal::native<::NSExpression>(lhs) rightExpression:cocoon::internal::native<::NSExpression>(rhs) modifier:static_cast<::NSComparisonPredicateModifier>(modifier) type:static_cast<::NSPredicateOperatorType>(type) options:static_cast<::NSComparisonPredicateOptions>(options)]);
    }

    ComparisonPredicateModifier ComparisonPredicate::comparison_predicate_modifier() const
    {
        return static_cast<ComparisonPredicateModifier>([cocoon::internal::ns<::NSComparisonPredicate>(this) comparisonPredicateModifier]);
    }

    std::string ComparisonPredicate::custom_selector() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSComparisonPredicate>(this) customSelector]));
    }

    Expression ComparisonPredicate::left_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSComparisonPredicate>(this) leftExpression]);
    }

    ComparisonPredicateOptions ComparisonPredicate::options() const
    {
        return static_cast<ComparisonPredicateOptions>([cocoon::internal::ns<::NSComparisonPredicate>(this) options]);
    }

    PredicateOperatorType ComparisonPredicate::predicate_operator_type() const
    {
        return static_cast<PredicateOperatorType>([cocoon::internal::ns<::NSComparisonPredicate>(this) predicateOperatorType]);
    }

    Expression ComparisonPredicate::right_expression() const
    {
        return cocoon::internal::wrap<Expression>([cocoon::internal::ns<::NSComparisonPredicate>(this) rightExpression]);
    }
}
