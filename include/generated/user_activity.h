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
     * @details A representation of the state of your app at a moment in time. An ''NSUserActivity'' object provides a lightweight way to capture the state of your app and put it to use later. Create this object to capture information about what a person was doing, such as viewing app content, editing a document, viewing a web page, or watching a video. When the system launches your app and an activity object is available, your app can use the information in that object to restore itself to an appropriate state. Spotlight also uses these objects to improve search results for people. To allow people to continue an activity on another device, see \<doc:implementing-handoff-in-your-app>. \#\#\# Siri If SiriKit needs to launch your app for any reason, it creates a user activity object and assigns an appropriate \<doc://com.apple.documentation/documentation/intents/ininteraction> object to its ''interaction'' property. Your app can use the interaction information to configure itself and display information related to the interaction started by SiriKit. You can also provide SiriKit with a custom user activity object containing additional data that you want passed to your app. In iOS 15 and later, a person can share content they're viewing by asking Siri to "share this". Apps built with Mac Catalyst provide the same capability with an \<doc://com.apple.documentation/documentation/appkit/nssharingservicepickertoolbaritem> in the toolbar. You can use \<doc://com.apple.documentation/documentation/uikit/uiactivityitemsconfigurationproviding/activityitemsconfiguration> or \<doc://com.apple.documentation/documentation/uikit/uiwindowscene/activityitemsconfigurationsource> to provide shareable content. In iOS, if both of those properties are \<doc://com.apple.documentation/documentation/objectivec/nil-227m0>, Siri uses the ''webpageURL'' property of your app's current user activity as a fallback value. \#\#\# Quick Note Quick Note on macOS and iOS can link to any app content represented as an ''NSUserActivity''. To appear as a link, the content must be the app's current activity, and provide at least one of the following identifiers: - term ''webpageURL'': An 'https:' URL, ideally in a canonical form that's consistent every time a person visits the same content. - term ''persistentIdentifier'': A string that uniquely identifies the content in this domain. The identifier should identify the same content across devices. - term ''targetContentIdentifier'': A string that uniquely identifies the content in this domain, but also allows disambiguating between multiple scenes of an app. The identifier should identify the same content across devices. To work well with Quick Note, content must adhere to the following guidelines: - The activity ''title'' should be clear and concise. This text describes the content of the link, like "Photo taken on July 27, 2020" or "Conversation with Maria". Use nouns for activity titles. - Keep the app's current activity up to date, using ''becomeCurrent()'' and ''resignCurrent()''. - Linkable identifiers (listed above) must be stable and consistent for the same content. When you link from a note to a document in an app, and later revisit that document, the system shows an indicator linking back to the note. The system compares identifiers to check that the document is the same as the original source of the link. - Maintain support for activities provided by your app, and support navigating to linked content indefinitely. Links added to notes are important to people, who may feel that a broken link indicates data loss. - Gracefully handle attempts to navigate to an activity that points to content that doesn't exist. For example, you can redirect to the new location of moved content, or show an error message. This situation may happen with shared notes, when a person links to content that exists only on another person's device. \#\#\# Search results If your ''NSUserActivity'' objects contain information that a person might want to search for later, set the ''isEligibleForSearch'' property to \<doc://com.apple.documentation/documentation/swift/true>. When you enable search, Spotlight indexes your user activity objects and considers them during subsequent on-device searches. For example, if a person viewed information about a particular restaurant in your app, you'd enable search for the corresponding user activity object. Subsequent searches for restaurants using Spotlight could then include the results obtained from your user activity object. In addition to on-device searches, you can contribute URLs accessed by your app with the global Spotlight search engine. Sharing a URL helps Spotlight improve its own search results for other people. To contribute a URL, put the URL in the ''webpageURL'' property of your activity object and set the ''isEligibleForPublicIndexing'' property to \<doc://com.apple.documentation/documentation/swift/true>. > Important: > Your app must maintain a strong reference to any activity objects that you use for search results. Employ user activity objects to record user-initiated activities, not as a general-purpose indexing mechanism of your app's data. To index all of your app's content, and not just the content touched by people, use the APIs of the \<doc://com.apple.documentation/documentation/corespotlight> framework.
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
         * @details Adds to the user info dictionary the entries from \@c otherDictionary. The keys and values must be of the types allowed in the user info dictionary.
         * @param other_dictionary Argument converted to the Objective-C parameter of the same role.
         */
        void add_user_info_entries_from_dictionary(const std::vector<std::pair<Object, Object>>& other_dictionary) const;
        /**
         * @brief Calls `-[NSUserActivity becomeCurrent]`.
         * @details Marks the receiver as the activity currently in use by the user. For example, the activity associated with the active window. A newly created activity is eligible for continuation on another device after the first time it becomes current.
         */
        void become_current() const;
        /**
         * @brief Calls `+[NSUserActivity deleteAllSavedUserActivitiesWithCompletionHandler:]`.
         * @details Deletes all saved user activities for this application. \@param handler A completion handler that is called when the deletion is complete.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         */
        static void delete_all_saved_user_activities_with_completion_handler(std::function<void()> handler);
        /**
         * @brief Calls `+[NSUserActivity deleteSavedUserActivitiesWithPersistentIdentifiers:completionHandler:]`.
         * @details Deletes user activities that have the specified persistent identifiers. \@param persistentIdentifiers An array of persistent identifiers for the user activities to delete. \@param handler A completion handler that is called when the deletion is complete.
         * @param persistent_identifiers Argument converted to the Objective-C parameter of the same role.
         * @param handler Argument converted to the Objective-C parameter of the same role.
         */
        static void delete_saved_user_activities_with_persistent_identifiers(const std::vector<std::string>& persistent_identifiers, std::function<void()> handler);
        /**
         * @brief Calls `-[NSUserActivity getContinuationStreamsWithCompletionHandler:]`.
         * @details When an app is launched for a continuation event it can request streams back to the originating side. Streams can only be successfully retrieved from the NSUserActivity in the NS/UIApplication delegate that is called for a continuation event. The streams returned in the completion handler will be in an unopened state. The streams should be opened immediately to start requesting information from the other side.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void get_continuation_streams_with_completion_handler(std::function<void(InputStream, OutputStream, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSUserActivity invalidate]`.
         * @details Invalidate an activity when it’s no longer eligible for continuation. For example, when the window associated with an activity is closed. An invalid activity cannot become current.
         */
        void invalidate() const;
        /**
         * @brief Calls `-[NSUserActivity resignCurrent]`.
         * @details If this activity is the current activity, it should stop being so and set the current activity to nothing.
         */
        void resign_current() const;
        /**
         * @brief Returns the `activityType` property of `NSUserActivity`.
         * @details The activity type the user activity was created with.
         * @return The converted Objective-C result.
         */
        std::string activity_type() const;
        /**
         * @brief Returns the `eligibleForHandoff` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be eligible to be handed off to another device.
         * @return The converted Objective-C result.
         */
        bool is_eligible_for_handoff() const;
        /**
         * @brief Sets the `eligibleForHandoff` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be eligible to be handed off to another device.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_eligible_for_handoff(bool value) const;
        /**
         * @brief Returns the `eligibleForPublicIndexing` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be eligible for indexing for any user of this application, on any device. Set to \@c NO if the activity contains private or sensitive information or which would not be useful to other users if indexed. The activity must also have \@c requiredUserActivityKeys or a \@c webpageURL.
         * @return The converted Objective-C result.
         */
        bool is_eligible_for_public_indexing() const;
        /**
         * @brief Sets the `eligibleForPublicIndexing` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be eligible for indexing for any user of this application, on any device. Set to \@c NO if the activity contains private or sensitive information or which would not be useful to other users if indexed. The activity must also have \@c requiredUserActivityKeys or a \@c webpageURL.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_eligible_for_public_indexing(bool value) const;
        /**
         * @brief Returns the `eligibleForSearch` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be indexed by App History.
         * @return The converted Objective-C result.
         */
        bool is_eligible_for_search() const;
        /**
         * @brief Sets the `eligibleForSearch` property of `NSUserActivity`.
         * @details Set to \@c YES if this user activity should be indexed by App History.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_eligible_for_search(bool value) const;
        /**
         * @brief Returns the `expirationDate` property of `NSUserActivity`.
         * @details If non-nil, an absolute date after which this activity is no longer eligible to be indexed or handed off.
         * @return The converted Objective-C result.
         */
        Date expiration_date() const;
        /**
         * @brief Sets the `expirationDate` property of `NSUserActivity`.
         * @details If non-nil, an absolute date after which this activity is no longer eligible to be indexed or handed off.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_expiration_date(const Date& value) const;
        /**
         * @brief Returns the `keywords` property of `NSUserActivity`.
         * @details A set of keywords, representing words or phrases in the current user’s language that might help the user to find this activity in the application history.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> keywords() const;
        /**
         * @brief Sets the `keywords` property of `NSUserActivity`.
         * @details A set of keywords, representing words or phrases in the current user’s language that might help the user to find this activity in the application history.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_keywords(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `needsSave` property of `NSUserActivity`.
         * @details If set to \@c YES, then the delegate for this user activity will receive a \@c userActivityWillSave: callback before being sent for continuation on another device.
         * @return The converted Objective-C result.
         */
        bool needs_save() const;
        /**
         * @brief Sets the `needsSave` property of `NSUserActivity`.
         * @details If set to \@c YES, then the delegate for this user activity will receive a \@c userActivityWillSave: callback before being sent for continuation on another device.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_needs_save(bool value) const;
        /**
         * @brief Returns the `persistentIdentifier` property of `NSUserActivity`.
         * @details A persistent identifier for this user activity.
         * @return The converted Objective-C result.
         */
        std::string persistent_identifier() const;
        /**
         * @brief Sets the `persistentIdentifier` property of `NSUserActivity`.
         * @details A persistent identifier for this user activity.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_persistent_identifier(const std::string& value) const;
        /**
         * @brief Returns the `referrerURL` property of `NSUserActivity`.
         * @details The URL of the webpage that referred (linked to) \@c webpageURL.
         * @return The converted Objective-C result.
         */
        URL referrer_url() const;
        /**
         * @brief Sets the `referrerURL` property of `NSUserActivity`.
         * @details The URL of the webpage that referred (linked to) \@c webpageURL.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_referrer_url(const URL& value) const;
        /**
         * @brief Returns the `requiredUserInfoKeys` property of `NSUserActivity`.
         * @details The keys from the user info property which represent the minimal information about this user activity that should be stored for later restoration. A \@c nil value means all keys in the user info are required.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> required_user_info_keys() const;
        /**
         * @brief Sets the `requiredUserInfoKeys` property of `NSUserActivity`.
         * @details The keys from the user info property which represent the minimal information about this user activity that should be stored for later restoration. A \@c nil value means all keys in the user info are required.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_required_user_info_keys(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `supportsContinuationStreams` property of `NSUserActivity`.
         * @details When used for continuation, the user activity can allow the continuing side to connect back for more information using streams. This value is set to \@c NO by default. It can be dynamically set to \@c YES to selectively support continuation streams.
         * @return The converted Objective-C result.
         */
        bool supports_continuation_streams() const;
        /**
         * @brief Sets the `supportsContinuationStreams` property of `NSUserActivity`.
         * @details When used for continuation, the user activity can allow the continuing side to connect back for more information using streams. This value is set to \@c NO by default. It can be dynamically set to \@c YES to selectively support continuation streams.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_supports_continuation_streams(bool value) const;
        /**
         * @brief Returns the `targetContentIdentifier` property of `NSUserActivity`.
         * @details A string that identifies the content of this NSUserActivity, for matching against existing documents when re-opening to see if they are the same. Setting this property is optional and does not automatically set \@c needsSave to \@c YES.
         * @return The converted Objective-C result.
         */
        std::string target_content_identifier() const;
        /**
         * @brief Sets the `targetContentIdentifier` property of `NSUserActivity`.
         * @details A string that identifies the content of this NSUserActivity, for matching against existing documents when re-opening to see if they are the same. Setting this property is optional and does not automatically set \@c needsSave to \@c YES.
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
         * @details The user info dictionary contains application-specific state needed to continue an activity on another device. Each key and value must be of the following types: \@c NSArray, \@c NSData, \@c NSDate, \@c NSDictionary, \@c NSNull, \@c NSNumber, \@c NSSet, \@c NSString, \@c NSURL, or \@c NSUUID.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> user_info() const;
        /**
         * @brief Sets the `userInfo` property of `NSUserActivity`.
         * @details The user info dictionary contains application-specific state needed to continue an activity on another device. Each key and value must be of the following types: \@c NSArray, \@c NSData, \@c NSDate, \@c NSDictionary, \@c NSNull, \@c NSNumber, \@c NSSet, \@c NSString, \@c NSURL, or \@c NSUUID.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_user_info(const std::vector<std::pair<Object, Object>>& value) const;
        /**
         * @brief Returns the `webpageURL` property of `NSUserActivity`.
         * @details When no suitable application is installed on a resuming device and this is set, the user activity will instead be continued in a web browser by loading this resource.
         * @return The converted Objective-C result.
         */
        URL webpage_url() const;
        /**
         * @brief Sets the `webpageURL` property of `NSUserActivity`.
         * @details When no suitable application is installed on a resuming device and this is set, the user activity will instead be continued in a web browser by loading this resource.
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
