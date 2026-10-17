#include "generated/user_activity.h"
#include "internal.h"

@interface AKUserActivityDelegate : NSObject <NSUserActivityDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKUserActivityDelegate

- (void)userActivityWillSave:(NSUserActivity*)userActivity
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::UserActivity, void()>::emit((__bridge void*)strongHost, "will_save");
}

- (void)userActivityWasContinued:(NSUserActivity*)userActivity
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::UserActivity, void()>::emit((__bridge void*)strongHost, "was_continued");
}

- (void)userActivity:(NSUserActivity*)userActivity didReceiveInputStream:(NSInputStream*)inputStream outputStream:(NSOutputStream*)outputStream
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::UserActivity, void(cocoon::InputStream, cocoon::OutputStream)>::emit((__bridge void*)strongHost, "did_receive_input_stream_output_stream", cocoon::internal::wrap<cocoon::InputStream>(inputStream), cocoon::internal::wrap<cocoon::OutputStream>(outputStream));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(userActivityWillSave:))
    {
        return strongHost && cocoon::Signal<cocoon::UserActivity, void()>::connected((__bridge void*)strongHost, "will_save");
    }
    if (selector == @selector(userActivityWasContinued:))
    {
        return strongHost && cocoon::Signal<cocoon::UserActivity, void()>::connected((__bridge void*)strongHost, "was_continued");
    }
    if (selector == @selector(userActivity:didReceiveInputStream:outputStream:))
    {
        return strongHost && cocoon::Signal<cocoon::UserActivity, void(cocoon::InputStream, cocoon::OutputStream)>::connected((__bridge void*)strongHost, "did_receive_input_stream_output_stream");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    UserActivity::UserActivity(const std::string& activity_type) : UserActivity(Adopt{cocoon::internal::retain([[::NSUserActivity alloc] initWithActivityType:cocoon::internal::to(activity_type)])})
    {
        UserActivity::install_delegate_delegate_(handle());
    }

    UserActivity::UserActivity() : UserActivity(Adopt{cocoon::internal::retain([[::NSUserActivity alloc] init])})
    {
        UserActivity::install_delegate_delegate_(handle());
    }

    UserActivity::UserActivity(std::nullptr_t) : Object(nullptr)
    {
    }

    UserActivity::UserActivity(Adopt adopt) : Object(adopt)
    {
    }

    void UserActivity::add_user_info_entries_from_dictionary(const std::vector<std::pair<Object, Object>>& other_dictionary) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) addUserInfoEntriesFromDictionary:cocoon::internal::to_dictionary(other_dictionary, [](const Object& k) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::native_id(k);
                                                                                                                       },
                                                                                                                       [](const Object& v) -> id
                                                                                                                       {
                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                       })];
    }

    void UserActivity::become_current() const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) becomeCurrent];
    }

    void UserActivity::delete_all_saved_user_activities_with_completion_handler(std::function<void()> handler)
    {
        [::NSUserActivity deleteAllSavedUserActivitiesWithCompletionHandler:(handler ? (void (^)(void)) ^ void() { handler(); } : (void (^)(void))nil)];
    }

    void UserActivity::delete_saved_user_activities_with_persistent_identifiers(const std::vector<std::string>& persistent_identifiers, std::function<void()> handler)
    {
        [::NSUserActivity deleteSavedUserActivitiesWithPersistentIdentifiers:cocoon::internal::to_array(persistent_identifiers, [](const std::string& e) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::to(e);
                                                                                                        })
                                                           completionHandler:(handler ? (void (^)(void)) ^ void() { handler(); } : (void (^)(void))nil)];
    }

    void UserActivity::get_continuation_streams_with_completion_handler(std::function<void(InputStream, OutputStream, Error)> completion_handler) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) getContinuationStreamsWithCompletionHandler:(completion_handler ? (void (^)(::NSInputStream*, ::NSOutputStream*, ::NSError*)) ^ void(::NSInputStream * a254_0, ::NSOutputStream * a254_1, ::NSError * a254_2) { completion_handler(cocoon::internal::wrap<InputStream>(a254_0), cocoon::internal::wrap<OutputStream>(a254_1), cocoon::internal::wrap<Error>(a254_2)); } : (void (^)(::NSInputStream*, ::NSOutputStream*, ::NSError*))nil)];
    }

    void UserActivity::invalidate() const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) invalidate];
    }

    void UserActivity::resign_current() const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) resignCurrent];
    }

    std::string UserActivity::activity_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserActivity>(this) activityType]);
    }

    bool UserActivity::is_eligible_for_handoff() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserActivity>(this) isEligibleForHandoff]);
    }

    void UserActivity::set_eligible_for_handoff(bool value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setEligibleForHandoff:static_cast<::BOOL>(value)];
    }

    bool UserActivity::is_eligible_for_public_indexing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserActivity>(this) isEligibleForPublicIndexing]);
    }

    void UserActivity::set_eligible_for_public_indexing(bool value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setEligibleForPublicIndexing:static_cast<::BOOL>(value)];
    }

    bool UserActivity::is_eligible_for_search() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserActivity>(this) isEligibleForSearch]);
    }

    void UserActivity::set_eligible_for_search(bool value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setEligibleForSearch:static_cast<::BOOL>(value)];
    }

    Date UserActivity::expiration_date() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSUserActivity>(this) expirationDate]);
    }

    void UserActivity::set_expiration_date(const Date& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setExpirationDate:cocoon::internal::native<::NSDate>(value)];
    }

    std::vector<std::string> UserActivity::keywords() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSUserActivity>(this) keywords] allObjects], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void UserActivity::set_keywords(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setKeywords:[NSSet setWithArray:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                 {
                                                                                                                     return cocoon::internal::to(e);
                                                                                                                 })]];
    }

    bool UserActivity::needs_save() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserActivity>(this) needsSave]);
    }

    void UserActivity::set_needs_save(bool value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setNeedsSave:static_cast<::BOOL>(value)];
    }

    std::string UserActivity::persistent_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserActivity>(this) persistentIdentifier]);
    }

    void UserActivity::set_persistent_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setPersistentIdentifier:cocoon::internal::to(value)];
    }

    URL UserActivity::referrer_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSUserActivity>(this) referrerURL]);
    }

    void UserActivity::set_referrer_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setReferrerURL:cocoon::internal::native<::NSURL>(value)];
    }

    std::vector<std::string> UserActivity::required_user_info_keys() const
    {
        return cocoon::internal::from_array<std::string>([[cocoon::internal::ns<::NSUserActivity>(this) requiredUserInfoKeys] allObjects], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void UserActivity::set_required_user_info_keys(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setRequiredUserInfoKeys:[NSSet setWithArray:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                                             {
                                                                                                                                 return cocoon::internal::to(e);
                                                                                                                             })]];
    }

    bool UserActivity::supports_continuation_streams() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUserActivity>(this) supportsContinuationStreams]);
    }

    void UserActivity::set_supports_continuation_streams(bool value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setSupportsContinuationStreams:static_cast<::BOOL>(value)];
    }

    std::string UserActivity::target_content_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserActivity>(this) targetContentIdentifier]);
    }

    void UserActivity::set_target_content_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setTargetContentIdentifier:cocoon::internal::to(value)];
    }

    std::string UserActivity::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUserActivity>(this) title]);
    }

    void UserActivity::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setTitle:cocoon::internal::to(value)];
    }

    std::vector<std::pair<Object, Object>> UserActivity::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSUserActivity>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }

    void UserActivity::set_user_info(const std::vector<std::pair<Object, Object>>& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setUserInfo:cocoon::internal::to_dictionary(value, [](const Object& k) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(k);
                                                                                                  },
                                                                                                  [](const Object& v) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(v);
                                                                                                  })];
    }

    URL UserActivity::webpage_url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSUserActivity>(this) webpageURL]);
    }

    void UserActivity::set_webpage_url(const URL& value) const
    {
        [cocoon::internal::ns<::NSUserActivity>(this) setWebpageURL:cocoon::internal::native<::NSURL>(value)];
    }

    void UserActivity::install_delegate_delegate_(void* native)
    {
        ::NSUserActivity* host = (__bridge ::NSUserActivity*)native;
        AKUserActivityDelegate* delegate = [[AKUserActivityDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSUserActivity* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSUserActivity* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
