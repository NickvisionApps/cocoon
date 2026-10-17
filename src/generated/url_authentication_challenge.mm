#include "generated/url_authentication_challenge.h"
#include "internal.h"

namespace cocoon
{
    URLAuthenticationChallenge::URLAuthenticationChallenge(const URLAuthenticationChallenge& challenge, const Object& sender) : URLAuthenticationChallenge(Adopt{cocoon::internal::retain([[::NSURLAuthenticationChallenge alloc] initWithAuthenticationChallenge:cocoon::internal::native<::NSURLAuthenticationChallenge>(challenge) sender:cocoon::internal::native_id(sender)])})
    {
    }

    URLAuthenticationChallenge::URLAuthenticationChallenge(const URLProtectionSpace& space, const URLCredential& credential, std::int64_t previous_failure_count, const URLResponse& response, const Error& error, const Object& sender) : URLAuthenticationChallenge(Adopt{cocoon::internal::retain([[::NSURLAuthenticationChallenge alloc] initWithProtectionSpace:cocoon::internal::native<::NSURLProtectionSpace>(space) proposedCredential:cocoon::internal::native<::NSURLCredential>(credential) previousFailureCount:static_cast<::NSInteger>(previous_failure_count) failureResponse:cocoon::internal::native<::NSURLResponse>(response) error:cocoon::internal::native<::NSError>(error) sender:cocoon::internal::native_id(sender)])})
    {
    }

    URLAuthenticationChallenge::URLAuthenticationChallenge() : URLAuthenticationChallenge(Adopt{cocoon::internal::retain([[::NSURLAuthenticationChallenge alloc] init])})
    {
    }

    URLAuthenticationChallenge::URLAuthenticationChallenge(std::nullptr_t) : Object(nullptr)
    {
    }

    URLAuthenticationChallenge::URLAuthenticationChallenge(Adopt adopt) : Object(adopt)
    {
    }

    Error URLAuthenticationChallenge::error() const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSURLAuthenticationChallenge>(this) error]);
    }

    URLResponse URLAuthenticationChallenge::failure_response() const
    {
        return cocoon::internal::wrap<URLResponse>([cocoon::internal::ns<::NSURLAuthenticationChallenge>(this) failureResponse]);
    }

    std::int64_t URLAuthenticationChallenge::previous_failure_count() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSURLAuthenticationChallenge>(this) previousFailureCount]);
    }

    URLCredential URLAuthenticationChallenge::proposed_credential() const
    {
        return cocoon::internal::wrap<URLCredential>([cocoon::internal::ns<::NSURLAuthenticationChallenge>(this) proposedCredential]);
    }

    URLProtectionSpace URLAuthenticationChallenge::protection_space() const
    {
        return cocoon::internal::wrap<URLProtectionSpace>([cocoon::internal::ns<::NSURLAuthenticationChallenge>(this) protectionSpace]);
    }
}
