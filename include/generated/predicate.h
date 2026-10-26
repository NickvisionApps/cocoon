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
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool evaluate_with_object(const Object& object) const;
        /**
         * @brief Calls `-[NSPredicate evaluateWithObject:substitutionVariables:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param bindings Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool evaluate_with_object(const Object& object, const std::map<std::string, Object>& bindings) const;
        /**
         * @brief Calls `+[NSPredicate predicateFromMetadataQueryString:]`.
         * @param query_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Predicate predicate_from_metadata_query_string(const std::string& query_string);
        /**
         * @brief Calls `-[NSPredicate predicateWithSubstitutionVariables:]`.
         * @param variables Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Predicate predicate_with_substitution_variables(const std::map<std::string, Object>& variables) const;
        /**
         * @brief Returns the `predicateFormat` property of `NSPredicate`.
         * @return The converted Objective-C result.
         */
        std::string predicate_format() const;
    };
}
