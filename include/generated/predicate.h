#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPredicate` (Foundation).
     * @details A definition of logical conditions for constraining a search for a fetch or for in-memory filtering. Predicates represent logical conditions, which you can use to filter collections of objects. Although it's common to create predicates directly from instances of ''NSComparisonPredicate'', ''NSCompoundPredicate'', and ''NSExpression'', you often create predicates from a format string that the class methods parse on ''NSPredicate''. Examples of predicate format strings include: - Simple comparisons, such as 'grade == "7"' or 'firstName like "Juan"' - Case- and diacritic-insensitive lookups, such as 'name contains[cd] "stein"' - Logical operations, such as '(firstName like "Mei") OR (lastName like "Chen")' - Temporal range constraints, such as 'date between {$YESTERDAY, $TOMORROW}' - Relational conditions, such as 'group.name like "work"' - Aggregate operations, such as '\@sum.items.price \< 1000' For a complete syntax reference, refer to the [Predicate Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Predicates/AdditionalChapters/Introduction.html\#//apple_ref/doc/uid/TP40001789). You can also create predicates that include variables using the ''evaluate(with:substitutionVariables:)'' method so that you can predefine the predicate before substituting concrete values at runtime.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Predicate predicate;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Predicate predicate{};
     * auto made_0 = cocoon::Predicate::predicate_from_metadata_query_string("text");
     * predicate.allow_evaluation();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspredicate
     */
    class Predicate : public Object
    {
    public:
        /// @brief Creates a new `NSPredicate` instance and returns a handle to it.
        explicit Predicate(std::function<bool(Object, std::map<std::string, Object>)> block);
        /// @brief Creates a new `NSPredicate` instance and returns a handle to it.
        explicit Predicate(const std::string& predicate_format, const std::vector<Object>& arguments);
        /// @brief Creates a new `NSPredicate` instance and returns a handle to it.
        explicit Predicate(const std::string& predicate_format, char* arg_list);
        /// @brief Creates a new `NSPredicate` instance and returns a handle to it.
        explicit Predicate(bool value);
        /// @brief Creates a new `NSPredicate` instance and returns a handle to it.
        explicit Predicate();
        /// @brief Creates a null handle that refers to no native object.
        Predicate(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Predicate(Adopt adopt);
        /**
     * @brief Calls `-[NSPredicate allowEvaluation]`.
     * @details Forces a securely decoded predicate to allow evaluation. When securely decoding 'NSPredicate' objects encoded using 'NSSecureCoding', evaluation is disabled because it is potentially unsafe to evaluate predicates you get out of an archive. Before you enable evaluation, you should validate key paths, selectors, and other details to ensure no erroneous or malicious code will be executed. Once you've verified the predicate, you can enable the receiver for evaluation by calling 'allowEvaluation'.
     */
        void allow_evaluation() const;
        /**
     * @brief Calls `-[NSPredicate allowEvaluationWithValidator:error:]`.
     * @param validator Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool allow_evaluation_with_validator(const Object& validator) const;
        /**
     * @brief Calls `-[NSPredicate evaluateWithObject:]`.
     * @details Returns a Boolean value that indicates whether the specified object matches the conditions that the predicate specifies.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool evaluate_with_object(const Object& object) const;
        /**
     * @brief Calls `-[NSPredicate evaluateWithObject:substitutionVariables:]`.
     * @details Returns a Boolean value that indicates whether the specified object matches the conditions that the predicate specifies after substituting in the values from a specified variables dictionary. This method returns the same result as the two step process of first invoking 'predicateWithSubstitutionVariables:' on the predicate and then invoking 'evaluateWithObject:' on the returned value. This method is optimized for situations which require repeatedly evaluating a predicate with substitution variables with different variable substitutions.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param bindings Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool evaluate_with_object(const Object& object, const std::map<std::string, Object>& bindings) const;
        /**
     * @brief Calls `+[NSPredicate predicateFromMetadataQueryString:]`.
     * @details Creates a predicate with a metadata query string.
     * @param query_string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Predicate predicate_from_metadata_query_string(const std::string& query_string);
        /**
     * @brief Calls `-[NSPredicate predicateWithSubstitutionVariables:]`.
     * @details Returns a copy of the predicate and substitutes the predicates variables with specified values from a specified substitution variables dictionary. The predicate itself is not modified by this method, so you can reuse it for any number of substitutions.
     * @param variables Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Predicate predicate_with_substitution_variables(const std::map<std::string, Object>& variables) const;
        /**
     * @brief Returns the `predicateFormat` property of `NSPredicate`.
     * @details The predicate's format string. The return value of this property is not guaranteed to be the same as the string used to create the predicate using 'predicateWithFormat:' or similar methods.
     * @return The converted Objective-C result.
     */
        std::string predicate_format() const;
    };
}
