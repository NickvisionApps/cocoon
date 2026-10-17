#include "generated/error.h"
#include "internal.h"

namespace cocoon
{
    Error::Error(const std::string& domain, std::int64_t code, const std::map<std::string, Object>& dict) : Error(Adopt{cocoon::internal::retain([[::NSError alloc] initWithDomain:cocoon::internal::to(domain)
                                                                                                                                                                              code:static_cast<::NSInteger>(code)
                                                                                                                                                                          userInfo:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                                                                                                                                   {
                                                                                                                                                                                                                       return cocoon::internal::to(k);
                                                                                                                                                                                                                   },
                                                                                                                                                                                                                   [](const Object& v) -> id
                                                                                                                                                                                                                   {
                                                                                                                                                                                                                       return cocoon::internal::native_id(v);
                                                                                                                                                                                                                   })])})
    {
    }

    Error::Error() : Error(Adopt{cocoon::internal::retain([[::NSError alloc] init])})
    {
    }

    Error::Error(std::nullptr_t) : Object(nullptr)
    {
    }

    Error::Error(Adopt adopt) : Object(adopt)
    {
    }

    Error Error::error_with_domain(const std::string& domain, std::int64_t code, const std::map<std::string, Object>& dict)
    {
        return cocoon::internal::wrap<Error>([::NSError errorWithDomain:cocoon::internal::to(domain)
                                                                   code:static_cast<::NSInteger>(code)
                                                               userInfo:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::to(k);
                                                                                                        },
                                                                                                        [](const Object& v) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native_id(v);
                                                                                                        })]);
    }

    void Error::set_user_info_value_provider_for_domain(const std::string& error_domain, std::function<Object(Error, std::string)> provider)
    {
        [::NSError setUserInfoValueProviderForDomain:cocoon::internal::to(error_domain) provider:(provider ? (id(^)(::NSError*, ::NSErrorUserInfoKey)) ^ id(::NSError * a130_0, NSString * a130_1) { auto __r = provider(cocoon::internal::wrap<Error>(a130_0), cocoon::internal::from(a130_1)); return cocoon::internal::native_id(__r); } : (id(^)(::NSError*, ::NSErrorUserInfoKey))nil)];
    }

    std::function<Object(Error, std::string)> Error::user_info_value_provider_for_domain(const std::string& error_domain)
    {
        return [&]() -> std::function<Object(Error, std::string)>
        {
            auto blk = (id(^)(::NSError*, ::NSErrorUserInfoKey))([::NSError userInfoValueProviderForDomain:cocoon::internal::to(error_domain)]);
            if (!blk)
            {
                return {};
            }
            return [blk](Error a131_0, std::string a131_1) -> Object
            {
                auto __r = blk(cocoon::internal::native<::NSError>(a131_0), cocoon::internal::to(a131_1));
                return cocoon::internal::wrap<Object>(__r);
            };
        }();
    }

    std::int64_t Error::code() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSError>(this) code]);
    }

    std::string Error::domain() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSError>(this) domain]);
    }

    std::string Error::help_anchor() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSError>(this) helpAnchor]);
    }

    std::string Error::localized_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSError>(this) localizedDescription]);
    }

    std::string Error::localized_failure_reason() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSError>(this) localizedFailureReason]);
    }

    std::vector<std::string> Error::localized_recovery_options() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSError>(this) localizedRecoveryOptions], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string Error::localized_recovery_suggestion() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSError>(this) localizedRecoverySuggestion]);
    }

    Object Error::recovery_attempter() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSError>(this) recoveryAttempter]);
    }

    std::vector<Error> Error::underlying_errors() const
    {
        return cocoon::internal::from_array<Error>([cocoon::internal::ns<::NSError>(this) underlyingErrors], [](id e) -> Error
                                                   {
                                                       return cocoon::internal::wrap<Error>((::NSError*)e);
                                                   });
    }

    std::map<std::string, Object> Error::user_info() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSError>(this) userInfo], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }
}
