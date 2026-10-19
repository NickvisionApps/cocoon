#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Error;
    class InputStream;
    class OutputStream;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSUserActivity` (Foundation).
     * @details NSUserActivity encapsulates the state of a user activity in an application on a particular device, in a way that allows the same activity to be continued on another device in a corresponding application from the same developer. Examples of user user activities include editing a document, viewing a web page, or watching a video.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserActivity user_activity;
     * user_activity.set_eligible_for_handoff(true);
     * user_activity.will_save().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserActivity user_activity{};
     * user_activity.set_eligible_for_handoff(true);
     * auto eligible_for_handoff = user_activity.is_eligible_for_handoff();
     * user_activity.set_eligible_for_public_indexing(true);
     * auto eligible_for_public_indexing = user_activity.is_eligible_for_public_indexing();
     * user_activity.set_eligible_for_search(true);
     * auto eligible_for_search = user_activity.is_eligible_for_search();
     * user_activity.become_current();
     * user_activity.invalidate();
     * user_activity.resign_current();
     * user_activity.will_save().connect([]() {});
     * user_activity.was_continued().connect([]() {});
     * user_activity.did_receive_input_stream_output_stream().connect([](cocoon::InputStream a0, cocoon::OutputStream a1) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuseractivity
     */
    class UserActivity : public Object
    {
    public:
        /// @brief Creates a new `NSUserActivity` instance and returns a handle to it.
        explicit UserActivity(const std::string& activity_type);
        /// @brief Creates a new `NSUserActivity` instance and returns a handle to it.
        explicit UserActivity();
        /// @brief Creates a null handle that refers to no native object.
        UserActivity(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserActivity(Adopt adopt);
        /**
     * @brief Calls `-[NSUserActivity addUserInfoEntriesFromDictionary:]`.
     * @details Adds to the userInfo dictionary the entries from otherDictionary. The keys and values must be of the types allowed in the userInfo
     * @param other_dictionary Argument converted to the Objective-C parameter of the same role.
     */
        void add_user_info_entries_from_dictionary(const std::vector<std::pair<Object, Object>>& other_dictionary) const;
        /**
     * @brief Calls `-[NSUserActivity becomeCurrent]`.
     * @details Marks the receiver as the activity currently in use by the user, for example, the activity associated with the active window. A newly created activity is eligible for continuation on another device after the first time it becomes current.
     */
        void become_current() const;
        /**
     * @brief Calls `+[NSUserActivity deleteAllSavedUserActivitiesWithCompletionHandler:]`.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        static void delete_all_saved_user_activities_with_completion_handler(std::function<void()> handler);
        /**
     * @brief Calls `+[NSUserActivity deleteSavedUserActivitiesWithPersistentIdentifiers:completionHandler:]`.
     * @param persistent_identifiers Argument converted to the Objective-C parameter of the same role.
     * @param handler Argument converted to the Objective-C parameter of the same role.
     */
        static void delete_saved_user_activities_with_persistent_identifiers(const std::vector<std::string>& persistent_identifiers, std::function<void()> handler);
        /**
     * @brief Calls `-[NSUserActivity getContinuationStreamsWithCompletionHandler:]`.
     * @details When an app is launched for a continuation event it can request streams back to the originating side. Streams can only be successfully retrieved from the NSUserActivity in the NS/UIApplication delegate that is called for a continuation event. This functionality is optional and is not expected to be needed in most continuation cases. The streams returned in the completion handler will be in an unopened state. The streams should be opened immediately to start requesting information from the other side.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_continuation_streams_with_completion_handler(std::function<void(InputStream, OutputStream, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSUserActivity invalidate]`.
     * @details Invalidate an activity when it's no longer eligible for continuation, for example, when the window associated with an activity is closed. An invalid activity cannot become current.
     */
        void invalidate() const;
        /**
     * @brief Calls `-[NSUserActivity resignCurrent]`.
     * @details If this activity is the current activity, it should stop being so and set the current activity to nothing.
     */
        void resign_current() const;
        /**
     * @brief Returns the `activityType` property of `NSUserActivity`.
     * @details The activityType the user activity was created with.
     * @return The converted Objective-C result.
     */
        std::string activity_type() const;
        /**
     * @brief Returns the `eligibleForHandoff` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be eligible to be handed off to another device
     * @return The converted Objective-C result.
     */
        bool is_eligible_for_handoff() const;
        /**
     * @brief Sets the `eligibleForHandoff` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be eligible to be handed off to another device
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_eligible_for_handoff(bool value) const;
        /**
     * @brief Returns the `eligibleForPublicIndexing` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be eligible for indexing for any user of this application, on any device, or NO if the activity contains private or sensitive information or which would not be useful to other users if indexed. The activity must also have requiredUserActivityKeys or a webpageURL
     * @return The converted Objective-C result.
     */
        bool is_eligible_for_public_indexing() const;
        /**
     * @brief Sets the `eligibleForPublicIndexing` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be eligible for indexing for any user of this application, on any device, or NO if the activity contains private or sensitive information or which would not be useful to other users if indexed. The activity must also have requiredUserActivityKeys or a webpageURL
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_eligible_for_public_indexing(bool value) const;
        /**
     * @brief Returns the `eligibleForSearch` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be indexed by App History
     * @return The converted Objective-C result.
     */
        bool is_eligible_for_search() const;
        /**
     * @brief Sets the `eligibleForSearch` property of `NSUserActivity`.
     * @details Set to YES if this user activity should be indexed by App History
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_eligible_for_search(bool value) const;
        /**
     * @brief Returns the `expirationDate` property of `NSUserActivity`.
     * @details If non-nil, then an absolute date after which this activity is no longer eligible to be indexed or handed off.
     * @return The converted Objective-C result.
     */
        Date expiration_date() const;
        /**
     * @brief Sets the `expirationDate` property of `NSUserActivity`.
     * @details If non-nil, then an absolute date after which this activity is no longer eligible to be indexed or handed off.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_expiration_date(const Date& value) const;
        /**
     * @brief Returns the `keywords` property of `NSUserActivity`.
     * @details A set of NSString keywords, representing words or phrases in the current user's language that might help the user to find this activity in the application history.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> keywords() const;
        /**
     * @brief Sets the `keywords` property of `NSUserActivity`.
     * @details A set of NSString keywords, representing words or phrases in the current user's language that might help the user to find this activity in the application history.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_keywords(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `needsSave` property of `NSUserActivity`.
     * @details If set to YES, then the delegate for this user activity will receive a userActivityWillSave: callback before being sent for continuation on another device.
     * @return The converted Objective-C result.
     */
        bool needs_save() const;
        /**
     * @brief Sets the `needsSave` property of `NSUserActivity`.
     * @details If set to YES, then the delegate for this user activity will receive a userActivityWillSave: callback before being sent for continuation on another device.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_needs_save(bool value) const;
        /**
     * @brief Returns the `persistentIdentifier` property of `NSUserActivity`.
     * @return The converted Objective-C result.
     */
        std::string persistent_identifier() const;
        /**
     * @brief Sets the `persistentIdentifier` property of `NSUserActivity`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_persistent_identifier(const std::string& value) const;
        /**
     * @brief Returns the `referrerURL` property of `NSUserActivity`.
     * @details The URL of the webpage that referred (linked to) webpageURL.
     * @return The converted Objective-C result.
     */
        URL referrer_url() const;
        /**
     * @brief Sets the `referrerURL` property of `NSUserActivity`.
     * @details The URL of the webpage that referred (linked to) webpageURL.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_referrer_url(const URL& value) const;
        /**
     * @brief Returns the `requiredUserInfoKeys` property of `NSUserActivity`.
     * @details The keys from the userInfo property which represent the minimal information about this user activity that should be stored for later restoration. A nil value means all keys in .userInfo are required.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> required_user_info_keys() const;
        /**
     * @brief Sets the `requiredUserInfoKeys` property of `NSUserActivity`.
     * @details The keys from the userInfo property which represent the minimal information about this user activity that should be stored for later restoration. A nil value means all keys in .userInfo are required.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_required_user_info_keys(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `supportsContinuationStreams` property of `NSUserActivity`.
     * @details When used for continuation, the user activity can allow the continuing side to connect back for more information using streams. This value is set to NO by default. It can be dynamically set to YES to selectively support continuation streams based on the state of the user activity.
     * @return The converted Objective-C result.
     */
        bool supports_continuation_streams() const;
        /**
     * @brief Sets the `supportsContinuationStreams` property of `NSUserActivity`.
     * @details When used for continuation, the user activity can allow the continuing side to connect back for more information using streams. This value is set to NO by default. It can be dynamically set to YES to selectively support continuation streams based on the state of the user activity.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_supports_continuation_streams(bool value) const;
        /**
     * @brief Returns the `targetContentIdentifier` property of `NSUserActivity`.
     * @details A string that identifies the content of this NSUserActivity, for matching against existing documents when re-opening to see if they are the same. Setting this property is optional and does not automatically set .needsSave to YES.
     * @return The converted Objective-C result.
     */
        std::string target_content_identifier() const;
        /**
     * @brief Sets the `targetContentIdentifier` property of `NSUserActivity`.
     * @details A string that identifies the content of this NSUserActivity, for matching against existing documents when re-opening to see if they are the same. Setting this property is optional and does not automatically set .needsSave to YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target_content_identifier(const std::string& value) const;
        /**
     * @brief Returns the `title` property of `NSUserActivity`.
     * @details An optional, user-visible title for this activity, such as a document name or web page title.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSUserActivity`.
     * @details An optional, user-visible title for this activity, such as a document name or web page title.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSUserActivity`.
     * @details The userInfo dictionary contains application-specific state needed to continue an activity on another device. Each key and value must be of the following types: NSArray, NSData, NSDate, NSDictionary, NSNull, NSNumber, NSSet, NSString, NSURL, or NSUUID. File scheme URLs which refer to iCloud documents may be translated to valid file URLs on a receiving device.
     * @return The converted Objective-C result.
     */
        std::vector<std::pair<Object, Object>> user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSUserActivity`.
     * @details The userInfo dictionary contains application-specific state needed to continue an activity on another device. Each key and value must be of the following types: NSArray, NSData, NSDate, NSDictionary, NSNull, NSNumber, NSSet, NSString, NSURL, or NSUUID. File scheme URLs which refer to iCloud documents may be translated to valid file URLs on a receiving device.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const std::vector<std::pair<Object, Object>>& value) const;
        /**
     * @brief Returns the `webpageURL` property of `NSUserActivity`.
     * @details When no suitable application is installed on a resuming device and the webpageURL is set, the user activity will instead be continued in a web browser by loading this resource.
     * @return The converted Objective-C result.
     */
        URL webpage_url() const;
        /**
     * @brief Sets the `webpageURL` property of `NSUserActivity`.
     * @details When no suitable application is installed on a resuming device and the webpageURL is set, the user activity will instead be continued in a web browser by loading this resource.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_webpage_url(const URL& value) const;
        /// @brief Signal for the delegate/data-source method behind `will_save`; connect a callback with `will_save().connect(...)`.
        Signal<UserActivity, void()> will_save() const
        {
            return Signal<UserActivity, void()>(handle(), "will_save");
        }
        /// @brief Signal for the delegate/data-source method behind `was_continued`; connect a callback with `was_continued().connect(...)`.
        Signal<UserActivity, void()> was_continued() const
        {
            return Signal<UserActivity, void()>(handle(), "was_continued");
        }
        /// @brief Signal for the delegate/data-source method behind `did_receive_input_stream_output_stream`; connect a callback with `did_receive_input_stream_output_stream().connect(...)`.
        Signal<UserActivity, void(InputStream, OutputStream)> did_receive_input_stream_output_stream() const
        {
            return Signal<UserActivity, void(InputStream, OutputStream)>(handle(), "did_receive_input_stream_output_stream");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
