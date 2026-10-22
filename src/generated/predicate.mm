#include "generated/predicate.h"
#include "internal.h"

namespace cocoon
{
    Predicate::Predicate(std::function<bool(Object, std::map<std::string, Object>)> block) : Predicate(Adopt{cocoon::internal::retain([::NSPredicate predicateWithBlock:(block ? (BOOL(^)(id, NSDictionary<NSString*, id>*)) ^ ::BOOL(id a203_0, NSDictionary * a203_1) { auto __r = block(cocoon::internal::wrap<Object>(a203_0), cocoon::internal::from_dictionary<std::map<std::string, Object>>(a203_1, [](id k) -> std::string { return cocoon::internal::from((NSString *)k); }, [](id v) -> Object { return cocoon::internal::wrap<Object>(v); })); return static_cast<::BOOL>(__r); } : (BOOL(^)(id, NSDictionary<NSString*, id>*))nil)])})
    {
    }

    Predicate::Predicate(const std::string& predicate_format, const std::vector<Object>& arguments) : Predicate(Adopt{cocoon::internal::retain([::NSPredicate predicateWithFormat:cocoon::internal::to(predicate_format)
                                                                                                                                                                    argumentArray:cocoon::internal::to_array(arguments, [](const Object& e) -> id
                                                                                                                                                                                                             {
                                                                                                                                                                                                                 return cocoon::internal::native_id(e);
                                                                                                                                                                                                             })])})
    {
    }

    Predicate::Predicate(const std::string& predicate_format, char* arg_list) : Predicate(Adopt{cocoon::internal::retain([::NSPredicate predicateWithFormat:cocoon::internal::to(predicate_format) arguments:(::va_list)(arg_list)])})
    {
    }

    Predicate::Predicate(bool value) : Predicate(Adopt{cocoon::internal::retain([::NSPredicate predicateWithValue:static_cast<::BOOL>(value)])})
    {
    }

    Predicate::Predicate() : Predicate(Adopt{cocoon::internal::retain([[::NSPredicate alloc] init])})
    {
    }

    Predicate::Predicate(std::nullptr_t) : Object(nullptr)
    {
    }

    Predicate::Predicate(Adopt adopt) : Object(adopt)
    {
    }

    void Predicate::allow_evaluation() const
    {
        [cocoon::internal::ns<::NSPredicate>(this) allowEvaluation];
    }

    bool Predicate::allow_evaluation_with_validator(const Object& validator) const
    {
        if (@available(macOS 26.4, *))
        {
            NSError* __error = nil;
            auto __r = [cocoon::internal::ns<::NSPredicate>(this) allowEvaluationWithValidator:cocoon::internal::native_id(validator) error:&__error];
            if (__error)
            {
                throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
            }
            return static_cast<bool>(__r);
        }
        return {};
    }

    bool Predicate::evaluate_with_object(const Object& object) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPredicate>(this) evaluateWithObject:cocoon::internal::native_id(object)]);
    }

    bool Predicate::evaluate_with_object(const Object& object, const std::map<std::string, Object>& bindings) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPredicate>(this) evaluateWithObject:cocoon::internal::native_id(object)
                                                                         substitutionVariables:cocoon::internal::to_dictionary(bindings, [](const std::string& k) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::to(k);
                                                                                                                               },
                                                                                                                               [](const Object& v) -> id
                                                                                                                               {
                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                               })]);
    }

    Predicate Predicate::predicate_from_metadata_query_string(const std::string& query_string)
    {
        return cocoon::internal::wrap<Predicate>([::NSPredicate predicateFromMetadataQueryString:cocoon::internal::to(query_string)]);
    }

    Predicate Predicate::predicate_with_substitution_variables(const std::map<std::string, Object>& variables) const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSPredicate>(this) predicateWithSubstitutionVariables:cocoon::internal::to_dictionary(variables, [](const std::string& k) -> id
                                                                                                                                                               {
                                                                                                                                                                   return cocoon::internal::to(k);
                                                                                                                                                               },
                                                                                                                                                               [](const Object& v) -> id
                                                                                                                                                               {
                                                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                                                               })]);
    }

    std::string Predicate::predicate_format() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPredicate>(this) predicateFormat]);
    }
}
