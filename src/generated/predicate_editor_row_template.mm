#include "generated/predicate_editor_row_template.h"
#include "internal.h"

namespace cocoon
{
    PredicateEditorRowTemplate::PredicateEditorRowTemplate(const std::vector<Number>& compound_types) : PredicateEditorRowTemplate(Adopt{cocoon::internal::retain([[::NSPredicateEditorRowTemplate alloc] initWithCompoundTypes:cocoon::internal::to_array(compound_types, [](const Number& e) -> id
                                                                                                                                                                                                                               {
                                                                                                                                                                                                                                   return cocoon::internal::native<::NSNumber>(e);
                                                                                                                                                                                                                               })])})
    {
    }

    PredicateEditorRowTemplate::PredicateEditorRowTemplate(const std::vector<Expression>& left_expressions, AttributeType attribute_type, ComparisonPredicateModifier modifier, const std::vector<Number>& operators, std::uint64_t options) : PredicateEditorRowTemplate(Adopt{cocoon::internal::retain([[::NSPredicateEditorRowTemplate alloc] initWithLeftExpressions:cocoon::internal::to_array(left_expressions, [](const Expression& e) -> id
                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                            return cocoon::internal::native<::NSExpression>(e);
                                                                                                                                                                                                                                                                                                                                                                        })
                                                                                                                                                                                                                                                                                                                              rightExpressionAttributeType:static_cast<::NSAttributeType>(attribute_type)
                                                                                                                                                                                                                                                                                                                                                  modifier:static_cast<::NSComparisonPredicateModifier>(modifier)
                                                                                                                                                                                                                                                                                                                                                 operators:cocoon::internal::to_array(operators, [](const Number& e) -> id
                                                                                                                                                                                                                                                                                                                                                                        {
                                                                                                                                                                                                                                                                                                                                                                            return cocoon::internal::native<::NSNumber>(e);
                                                                                                                                                                                                                                                                                                                                                                        })
                                                                                                                                                                                                                                                                                                                                                   options:static_cast<::NSUInteger>(options)])})
    {
    }

    PredicateEditorRowTemplate::PredicateEditorRowTemplate(const std::vector<Expression>& left_expressions, const std::vector<Expression>& right_expressions, ComparisonPredicateModifier modifier, const std::vector<Number>& operators, std::uint64_t options) : PredicateEditorRowTemplate(Adopt{cocoon::internal::retain([[::NSPredicateEditorRowTemplate alloc] initWithLeftExpressions:cocoon::internal::to_array(left_expressions, [](const Expression& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::native<::NSExpression>(e);
                                                                                                                                                                                                                                                                                                                                                                                            })
                                                                                                                                                                                                                                                                                                                                                              rightExpressions:cocoon::internal::to_array(right_expressions, [](const Expression& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::native<::NSExpression>(e);
                                                                                                                                                                                                                                                                                                                                                                                            })
                                                                                                                                                                                                                                                                                                                                                                      modifier:static_cast<::NSComparisonPredicateModifier>(modifier)
                                                                                                                                                                                                                                                                                                                                                                     operators:cocoon::internal::to_array(operators, [](const Number& e) -> id
                                                                                                                                                                                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                                                                                                                                                                                return cocoon::internal::native<::NSNumber>(e);
                                                                                                                                                                                                                                                                                                                                                                                            })
                                                                                                                                                                                                                                                                                                                                                                       options:static_cast<::NSUInteger>(options)])})
    {
    }

    PredicateEditorRowTemplate::PredicateEditorRowTemplate() : PredicateEditorRowTemplate(Adopt{cocoon::internal::retain([[::NSPredicateEditorRowTemplate alloc] init])})
    {
    }

    PredicateEditorRowTemplate::PredicateEditorRowTemplate(std::nullptr_t) : Object(nullptr)
    {
    }

    PredicateEditorRowTemplate::PredicateEditorRowTemplate(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<Predicate> PredicateEditorRowTemplate::displayable_subpredicates_of_predicate(const Predicate& predicate) const
    {
        return cocoon::internal::from_array<Predicate>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) displayableSubpredicatesOfPredicate:cocoon::internal::native<::NSPredicate>(predicate)], [](id e) -> Predicate
                                         {
                                             return cocoon::internal::wrap<Predicate>((::NSPredicate*)e);
                                         });
    }

    double PredicateEditorRowTemplate::match_for_predicate(const Predicate& predicate) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) matchForPredicate:cocoon::internal::native<::NSPredicate>(predicate)]);
    }

    Predicate PredicateEditorRowTemplate::predicate_with_subpredicates(const std::vector<Predicate>& subpredicates) const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) predicateWithSubpredicates:cocoon::internal::to_array(subpredicates, [](const Predicate& e) -> id
                                                                                                                         {
                                                                                                                             return cocoon::internal::native<::NSPredicate>(e);
                                                                                                                         })]);
    }

    void PredicateEditorRowTemplate::set_predicate(const Predicate& predicate) const
    {
        [cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) setPredicate:cocoon::internal::native<::NSPredicate>(predicate)];
    }

    std::vector<PredicateEditorRowTemplate> PredicateEditorRowTemplate::templates_with_attribute_key_paths(const std::vector<std::string>& key_paths, const Object& entity_description)
    {
        return cocoon::internal::from_array<PredicateEditorRowTemplate>([::NSPredicateEditorRowTemplate templatesWithAttributeKeyPaths:cocoon::internal::to_array(key_paths, [](const std::string& e) -> id
                                                                                                                                      {
                                                                                                                                          return cocoon::internal::to(e);
                                                                                                                                      })
                                                                                                     inEntityDescription:cocoon::internal::native_id(entity_description)],
                                                          [](id e) -> PredicateEditorRowTemplate
                                                          {
                                                              return cocoon::internal::wrap<PredicateEditorRowTemplate>((::NSPredicateEditorRowTemplate*)e);
                                                          });
    }

    std::vector<Number> PredicateEditorRowTemplate::compound_types() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) compoundTypes], [](id e) -> Number
                                      {
                                          return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                      });
    }

    std::vector<Expression> PredicateEditorRowTemplate::left_expressions() const
    {
        return cocoon::internal::from_array<Expression>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) leftExpressions], [](id e) -> Expression
                                          {
                                              return cocoon::internal::wrap<Expression>((::NSExpression*)e);
                                          });
    }

    ComparisonPredicateModifier PredicateEditorRowTemplate::modifier() const
    {
        return static_cast<ComparisonPredicateModifier>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) modifier]);
    }

    std::vector<Number> PredicateEditorRowTemplate::operators() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) operators], [](id e) -> Number
                                      {
                                          return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                      });
    }

    std::uint64_t PredicateEditorRowTemplate::options() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) options]);
    }

    AttributeType PredicateEditorRowTemplate::right_expression_attribute_type() const
    {
        return static_cast<AttributeType>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) rightExpressionAttributeType]);
    }

    std::vector<Expression> PredicateEditorRowTemplate::right_expressions() const
    {
        return cocoon::internal::from_array<Expression>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) rightExpressions], [](id e) -> Expression
                                          {
                                              return cocoon::internal::wrap<Expression>((::NSExpression*)e);
                                          });
    }

    std::vector<View> PredicateEditorRowTemplate::template_views() const
    {
        return cocoon::internal::from_array<View>([cocoon::internal::ns<::NSPredicateEditorRowTemplate>(this) templateViews], [](id e) -> View
                                    {
                                        return cocoon::internal::wrap<View>((::NSView*)e);
                                    });
    }
}
