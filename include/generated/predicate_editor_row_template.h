#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Expression;
    class Number;
    class Predicate;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSPredicateEditorRowTemplate` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PredicateEditorRowTemplate predicate_editor_row_template;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PredicateEditorRowTemplate predicate_editor_row_template{};
     * predicate_editor_row_template.displayable_subpredicates_of_predicate(cocoon::Predicate());
     * predicate_editor_row_template.match_for_predicate(cocoon::Predicate());
     * predicate_editor_row_template.set_predicate(cocoon::Predicate());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspredicateeditorrowtemplate
     */
    class PredicateEditorRowTemplate : public Object
    {
    public:
        /// @brief Creates a new `NSPredicateEditorRowTemplate` instance and returns a handle to it.
        explicit PredicateEditorRowTemplate(const std::vector<Number>& compound_types);
        /// @brief Creates a new `NSPredicateEditorRowTemplate` instance and returns a handle to it.
        explicit PredicateEditorRowTemplate(const std::vector<Expression>& left_expressions, AttributeType attribute_type, ComparisonPredicateModifier modifier, const std::vector<Number>& operators, std::uint64_t options);
        /// @brief Creates a new `NSPredicateEditorRowTemplate` instance and returns a handle to it.
        explicit PredicateEditorRowTemplate(const std::vector<Expression>& left_expressions, const std::vector<Expression>& right_expressions, ComparisonPredicateModifier modifier, const std::vector<Number>& operators, std::uint64_t options);
        /// @brief Creates a new `NSPredicateEditorRowTemplate` instance and returns a handle to it.
        explicit PredicateEditorRowTemplate();
        /// @brief Creates a null handle that refers to no native object.
        PredicateEditorRowTemplate(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PredicateEditorRowTemplate(Adopt adopt);
        /**
     * @brief Calls `-[NSPredicateEditorRowTemplate displayableSubpredicatesOfPredicate:]`.
     * @details for a given predicate, returns the subpredicates that should be made subrows. For NSCompoundPredicate, this returns the array of subpredicates; it returns nil for other types of predicates. This is only called if matchForPredicate: returns a positive value for the given predicate. Developers can override this to create custom templates that handle complicated compound predicates.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Predicate> displayable_subpredicates_of_predicate(const Predicate& predicate) const;
        /**
     * @brief Calls `-[NSPredicateEditorRowTemplate matchForPredicate:]`.
     * @details returns a positive number if the template can represent the predicate, and zero if it cannot. The highest match determines which template is responsible for displaying the predicate. Developers can override this to determine which predicates their custom template handles. By default, this returns values in the range [0., 1.]
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double match_for_predicate(const Predicate& predicate) const;
        /**
     * @brief Calls `-[NSPredicateEditorRowTemplate predicateWithSubpredicates:]`.
     * @details returns the predicate represented by the template's views' values and the given subpredicates. Developers can override this to return the predicate represented by their custom views.
     * @param subpredicates Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Predicate predicate_with_subpredicates(const std::vector<Predicate>& subpredicates) const;
        /**
     * @brief Calls `-[NSPredicateEditorRowTemplate setPredicate:]`.
     * @details sets the value of the views according to the given predicate. This is only called if matchForPredicate: returns a positive value for the given predicate. Developers can override this to set the values of their custom views.
     * @param predicate Argument converted to the Objective-C parameter of the same role.
     */
        void set_predicate(const Predicate& predicate) const;
        /**
     * @brief Calls `+[NSPredicateEditorRowTemplate templatesWithAttributeKeyPaths:inEntityDescription:]`.
     * @details CoreData convenience method: creates an array of templates of the popup-popup-view variety from the given key paths. The key paths may cross relationships but must terminate in attributes.
     * @param key_paths Argument converted to the Objective-C parameter of the same role.
     * @param entity_description Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<PredicateEditorRowTemplate> templates_with_attribute_key_paths(const std::vector<std::string>& key_paths, const Object& entity_description);
        /**
     * @brief Returns the `compoundTypes` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        std::vector<Number> compound_types() const;
        /**
     * @brief Returns the `leftExpressions` property of `NSPredicateEditorRowTemplate`.
     * @details returns the various values set in the initializers, or zero/nil if they do not apply
     * @return The converted Objective-C result.
     */
        std::vector<Expression> left_expressions() const;
        /**
     * @brief Returns the `modifier` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        ComparisonPredicateModifier modifier() const;
        /**
     * @brief Returns the `operators` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        std::vector<Number> operators() const;
        /**
     * @brief Returns the `options` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        std::uint64_t options() const;
        /**
     * @brief Returns the `rightExpressionAttributeType` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        AttributeType right_expression_attribute_type() const;
        /**
     * @brief Returns the `rightExpressions` property of `NSPredicateEditorRowTemplate`.
     * @return The converted Objective-C result.
     */
        std::vector<Expression> right_expressions() const;
        /**
     * @brief Returns the `templateViews` property of `NSPredicateEditorRowTemplate`.
     * @details returns the list of views that are placed in the row. NSPopUpButtons are treated specially in that the items of multiple templates are merged together; other views are added as-is. Developers can override this to return views in addition to or instead of the default views.
     * @return The converted Objective-C result.
     */
        std::vector<View> template_views() const;
    };
}
