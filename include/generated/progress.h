#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSProgress` (Foundation).
     * @details NSProgress is used to report the amount of work done, and provides a way to allow the user to cancel that work. Since work is often split up into several parts, progress objects can form a tree where children represent part of the overall total work. Each parent may have as many children as required, but each child only has one parent. The top level progress object in this tree is typically the one that you would display to a user. The leaf objects are updated as work completes, and the updates propagate up the tree. The work that an NSProgress does is tracked via a "unit count." There are two unit count values: total and completed. In its leaf form, an NSProgress is created with a total unit count and its completed unit count is updated with -setCompletedUnitCount: until it matches the total unit count. The progress is then considered finished. When progress objects form nodes in trees, they are still created with a total unit count. Portions of the total are then handed out to children as a "pending unit count." The total amount handed out to children should add up to the parent's totalUnitCount. When those children become finished, the pending unit count assigned to that child is added to the parent's completedUnitCount. Therefore, when all children are finished, the parent's completedUnitCount is equal to its totalUnitCount and it becomes finished itself. Children NSProgress objects can be added implicitly or by invoking the -addChild:withPendingUnitCount: method on the parent. Implicitly added children are attached to a parent progress between a call to -becomeCurrentWithPendingUnitCount: and a call to -resignCurrent. The implicit child is created with the +progressWithTotalUnitCount: method or by passing the result of +currentProgress to the -initWithParent:userInfo: method. Both kinds of children can be attached to the same parent progress object. If you have an idea in advance that some portions of the work will take more or less time than the others, you can use different values of pending unit count for each child. If you are designing an interface of an object that reports progress, then the recommended approach is to vend an NSProgress property and adopt the NSProgressReporting protocol. The progress should be created with the -discreteProgressWithTotalUnitCount: method. You can then either update the progress object directly or set it to have children of its own. Users of your object can compose your progress into their tree by using the -addChild:withPendingUnitCount: method. If you want to provide progress reporting for a single method, then the recommended approach is to implicitly attach to a current NSProgress by creating an NSProgress object at the very beginning of your method using +progressWithTotalUnitCount:. This progress object will consume the pending unit count, and then you can set up the progress object with children of its own. The localizedDescription and localizedAdditionalDescription properties are meant to be observed as well as set. So are the cancellable and pausable properties. totalUnitCount and completedUnitCount on the other hand are often not the best properties to observe when presenting progress to the user. For example, you should observe fractionCompleted instead of observing totalUnitCount and completedUnitCount and doing your own calculation. NSProgress' default implementation of fractionCompleted does fairly sophisticated things like taking child NSProgresses into account.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Progress progress;
     * progress.set_cancellable(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Progress progress{};
     * progress.set_cancellable(true);
     * auto cancellable = progress.is_cancellable();
     * progress.set_completed_unit_count(1);
     * auto completed_unit_count = progress.completed_unit_count();
     * progress.set_estimated_time_remaining(cocoon::Number());
     * auto estimated_time_remaining = progress.estimated_time_remaining();
     * auto made_0 = cocoon::Progress::current_progress();
     * auto made_1 = cocoon::Progress::discrete_progress_with_total_unit_count(1);
     * progress.add_child(cocoon::Progress(), 1);
     * progress.become_current_with_pending_unit_count(1);
     * progress.cancel();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsprogress
     */
    class Progress : public Object
    {
    public:
        /// @brief Creates a new `NSProgress` instance and returns a handle to it.
        explicit Progress(const Progress& parent_progress_or_nil, const std::map<std::string, Object>& user_info_or_nil);
        /// @brief Creates a new `NSProgress` instance and returns a handle to it.
        explicit Progress(std::int64_t unit_count);
        /// @brief Creates a new `NSProgress` instance and returns a handle to it.
        explicit Progress(std::int64_t unit_count, const Progress& parent, std::int64_t portion_of_parent_total_unit_count);
        /// @brief Creates a new `NSProgress` instance and returns a handle to it.
        explicit Progress();
        /// @brief Creates a null handle that refers to no native object.
        Progress(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Progress(Adopt adopt);
        /**
         * @brief Calls `-[NSProgress addChild:withPendingUnitCount:]`.
         * @details Directly add a child progress to the receiver, assigning it a portion of the receiver's total unit count.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @param in_unit_count Argument converted to the Objective-C parameter of the same role.
         */
        void add_child(const Progress& child, std::int64_t in_unit_count) const;
        /**
         * @brief Calls `+[NSProgress addSubscriberForFileURL:withPublishingHandler:]`.
         * @details Register to hear about file progress. The passed-in block will be invoked when -publish has been sent to an NSProgress whose NSProgressFileURLKey user info dictionary entry is an NSURL locating the same item located by the passed-in NSURL, or an item directly contained by it. The NSProgress passed to your block will be a proxy of the one that was published. The passed-in block may return another block. If it does, then that returned block will be invoked when the corresponding invocation of -unpublish is made, or the publishing process terminates, or +removeSubscriber: is invoked. Your blocks will be invoked on the main thread.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param publishing_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object add_subscriber_for_file_url(const URL& url, std::function<std::function<void()>(Progress)> publishing_handler);
        /**
         * @brief Calls `-[NSProgress becomeCurrentWithPendingUnitCount:]`.
         * @details Make the receiver the current thread's current progress object, returned by +currentProgress. At the same time, record how large a portion of the work represented by the receiver will be represented by the next progress object initialized by invoking -initWithParent:userInfo: in the current thread with the receiver as the parent. This will be used when that child is sent -setCompletedUnitCount: and the receiver is notified of that. With this mechanism, code that doesn't know anything about its callers can report progress accurately by using +progressWithTotalUnitCount: and -setCompletedUnitCount:. The calling code will account for the fact that the work done is only a portion of the work to be done as part of a larger operation. The unit of work in a call to -becomeCurrentWithPendingUnitCount: has to be the same unit of work as that used for the value of the totalUnitCount property, but the unit of work used by the child can be a completely different one, and often will be. You must always balance invocations of this method with invocations of -resignCurrent.
         * @param unit_count Argument converted to the Objective-C parameter of the same role.
         */
        void become_current_with_pending_unit_count(std::int64_t unit_count) const;
        /**
         * @brief Calls `-[NSProgress cancel]`.
         * @details Invoke the block registered with the cancellationHandler property, if there is one, and set the cancelled property to YES. Do this for the receiver, any descendants of the receiver, the instance of NSProgress that was published in another process to make the receiver if that's the case, and any descendants of such a published instance of NSProgress.
         */
        void cancel() const;
        /**
         * @brief Calls `+[NSProgress currentProgress]`.
         * @details The instance of NSProgress associated with the current thread by a previous invocation of -becomeCurrentWithPendingUnitCount:, if any. The purpose of this per-thread value is to allow code that does work to usefully report progress even when it is widely separated from the code that actually presents progress to the user, without requiring layers of intervening code to pass the instance of NSProgress through. Using the result of invoking this directly will often not be the right thing to do, because the invoking code will often not even know what units of work the current progress object deals in. Invoking +progressWithTotalUnitCount: to create a child NSProgress object and then using that to report progress makes more sense in that situation.
         * @return The converted Objective-C result.
         */
        static Progress current_progress();
        /**
         * @brief Calls `+[NSProgress discreteProgressWithTotalUnitCount:]`.
         * @details Return an instance of NSProgress that has been initialized with -initWithParent:userInfo:. The initializer is passed nil for the parent, resulting in a progress object that is not part of an existing progress tree. The value of the totalUnitCount property is also set.
         * @param unit_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Progress discrete_progress_with_total_unit_count(std::int64_t unit_count);
        /**
         * @brief Calls `-[NSProgress pause]`.
         * @details Invoke the block registered with the pausingHandler property, if there is one, and set the paused property to YES. Do this for the receiver, any descendants of the receiver, the instance of NSProgress that was published in another process to make the receiver if that's the case, and any descendants of such a published instance of NSProgress.
         */
        void pause() const;
        /**
         * @brief Calls `-[NSProgress performAsCurrentWithPendingUnitCount:usingBlock:]`.
         * @details Become current, do some work, then resign current.
         * @param unit_count Argument converted to the Objective-C parameter of the same role.
         * @param work Argument converted to the Objective-C parameter of the same role.
         */
        void perform_as_current_with_pending_unit_count(std::int64_t unit_count, std::function<void()> work) const;
        /**
         * @brief Calls `-[NSProgress publish]`.
         * @details Make the NSProgress observable by other processes. Whether or not another process can discover the NSProgress to observe it, and how it would do that, depends on entries in the user info dictionary. For example, an NSProgressFileURLKey entry makes an NSProgress discoverable by corresponding invokers of +addSubscriberForFileURL:withPublishingHandler:. When you make an NSProgress observable by other processes you must ensure that at least -localizedDescription, -isIndeterminate, and -fractionCompleted always work when sent to proxies of your NSProgress in other processes. You make -isIndeterminate and -fractionCompleted always work by accurately setting the total and completed unit counts of the progress. You make -localizedDescription always work by setting the value of the kind property to something valid, like NSProgressKindFile, and then fulfilling the requirements for that specific kind of progress. (You can instead set the value of localizedDescription directly but that is not perfectly reliable because other processes might be using different localization languages than yours.) You can publish an instance of NSProgress at most once.
         */
        void publish() const;
        /**
         * @brief Calls `+[NSProgress removeSubscriber:]`.
         * @details Given the object returned by a previous invocation of -addSubscriberForFileURL:withPublishingHandler:, deregister.
         * @param subscriber Argument converted to the Objective-C parameter of the same role.
         */
        static void remove_subscriber(const Object& subscriber);
        /**
         * @brief Calls `-[NSProgress resignCurrent]`.
         * @details Balance the most recent previous invocation of -becomeCurrentWithPendingUnitCount: on the same thread by restoring the current progress object to what it was before -becomeCurrentWithPendingUnitCount: was invoked.
         */
        void resign_current() const;
        /**
         * @brief Calls `-[NSProgress resume]`.
         * @details Invoke the block registered with the resumingHandler property, if there is one, and set the paused property to NO. Do this for the receiver, any descendants of the receiver, the instance of NSProgress that was published in another process to make the receiver if that's the case, and any descendants of such a published instance of NSProgress.
         */
        void resume() const;
        /**
         * @brief Calls `-[NSProgress setUserInfoObject:forKey:]`.
         * @details Set a value in the dictionary returned by invocations of -userInfo, with appropriate KVO notification for properties whose values can depend on values in the user info dictionary, like localizedDescription. If a nil value is passed then the dictionary entry is removed.
         * @param object_or_nil Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void set_user_info_object(const Object& object_or_nil, const std::string& key) const;
        /**
         * @brief Calls `-[NSProgress unpublish]`.
         * @details Make the NSProgress no longer observable by other processes.
         */
        void unpublish() const;
        /**
         * @brief Returns the `cancellable` property of `NSProgress`.
         * @details Whether the work being done can be cancelled or paused, respectively. By default NSProgresses are cancellable but not pausable. NSProgress is by default KVO-compliant for these properties, with the notifications always being sent on the thread which updates the property. These properties are for communicating whether controls for cancelling and pausing should appear in a progress reporting user interface. NSProgress itself does not do anything with these properties other than help pass their values from progress reporters to progress observers. It is valid for the values of these properties to change in virtually any way during the lifetime of an NSProgress. Of course, if an NSProgress is cancellable you should actually implement cancellability by setting a cancellation handler or by making your code poll the result of invoking -isCancelled. Likewise for pausability.
         * @return The converted Objective-C result.
         */
        bool is_cancellable() const;
        /**
         * @brief Sets the `cancellable` property of `NSProgress`.
         * @details Whether the work being done can be cancelled or paused, respectively. By default NSProgresses are cancellable but not pausable. NSProgress is by default KVO-compliant for these properties, with the notifications always being sent on the thread which updates the property. These properties are for communicating whether controls for cancelling and pausing should appear in a progress reporting user interface. NSProgress itself does not do anything with these properties other than help pass their values from progress reporters to progress observers. It is valid for the values of these properties to change in virtually any way during the lifetime of an NSProgress. Of course, if an NSProgress is cancellable you should actually implement cancellability by setting a cancellation handler or by making your code poll the result of invoking -isCancelled. Likewise for pausability.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cancellable(bool value) const;
        /**
         * @brief Returns the `cancellationHandler` property of `NSProgress`.
         * @details A block to be invoked when cancel is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @return The converted Objective-C result.
         */
        std::function<void()> cancellation_handler() const;
        /**
         * @brief Sets the `cancellationHandler` property of `NSProgress`.
         * @details A block to be invoked when cancel is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cancellation_handler(std::function<void()> value) const;
        /**
         * @brief Returns the `cancelled` property of `NSProgress`.
         * @details Whether the work being done has been cancelled or paused, respectively. NSProgress is by default KVO-compliant for these properties, with the notifications always being sent on the thread which updates the property. Instances of NSProgress that have parents are at least as cancelled or paused as their parents.
         * @return The converted Objective-C result.
         */
        bool is_cancelled() const;
        /**
         * @brief Returns the `completedUnitCount` property of `NSProgress`.
         * @return The converted Objective-C result.
         */
        std::int64_t completed_unit_count() const;
        /**
         * @brief Sets the `completedUnitCount` property of `NSProgress`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_completed_unit_count(std::int64_t value) const;
        /**
         * @brief Returns the `estimatedTimeRemaining` property of `NSProgress`.
         * @details How much time is probably left in the operation, as an NSNumber containing a number of seconds. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        Number estimated_time_remaining() const;
        /**
         * @brief Sets the `estimatedTimeRemaining` property of `NSProgress`.
         * @details How much time is probably left in the operation, as an NSNumber containing a number of seconds. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_estimated_time_remaining(const Number& value) const;
        /**
         * @brief Returns the `fileCompletedCount` property of `NSProgress`.
         * @details If the progress is operating on a set of files, then set to the number of completed files in the operation. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        Number file_completed_count() const;
        /**
         * @brief Sets the `fileCompletedCount` property of `NSProgress`.
         * @details If the progress is operating on a set of files, then set to the number of completed files in the operation. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_file_completed_count(const Number& value) const;
        /**
         * @brief Returns the `fileOperationKind` property of `NSProgress`.
         * @details When the kind property is NSProgressKindFile, this value should be set. It describes the kind of file operation being performed. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        std::string file_operation_kind() const;
        /**
         * @brief Sets the `fileOperationKind` property of `NSProgress`.
         * @details When the kind property is NSProgressKindFile, this value should be set. It describes the kind of file operation being performed. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_file_operation_kind(const std::string& value) const;
        /**
         * @brief Returns the `fileTotalCount` property of `NSProgress`.
         * @details If the progress is operating on a set of files, then set to the total number of files in the operation. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        Number file_total_count() const;
        /**
         * @brief Sets the `fileTotalCount` property of `NSProgress`.
         * @details If the progress is operating on a set of files, then set to the total number of files in the operation. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_file_total_count(const Number& value) const;
        /**
         * @brief Returns the `fileURL` property of `NSProgress`.
         * @details A URL identifying the item on which progress is being made. This is required for any NSProgress that is published using -publish to be reported to subscribers registered with +addSubscriberForFileURL:withPublishingHandler: If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        URL file_url() const;
        /**
         * @brief Sets the `fileURL` property of `NSProgress`.
         * @details A URL identifying the item on which progress is being made. This is required for any NSProgress that is published using -publish to be reported to subscribers registered with +addSubscriberForFileURL:withPublishingHandler: If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_file_url(const URL& value) const;
        /**
         * @brief Returns the `finished` property of `NSProgress`.
         * @details True if the progress is considered finished. This property is observable.
         * @return The converted Objective-C result.
         */
        bool is_finished() const;
        /**
         * @brief Returns the `fractionCompleted` property of `NSProgress`.
         * @details The fraction of the overall work completed by this progress object, including work done by any children it may have.
         * @return The converted Objective-C result.
         */
        double fraction_completed() const;
        /**
         * @brief Returns the `indeterminate` property of `NSProgress`.
         * @details Whether the progress being made is indeterminate. -isIndeterminate returns YES when the value of the totalUnitCount or completedUnitCount property is less than zero. Zero values for both of those properties indicates that there turned out to not be any work to do after all; -isIndeterminate returns NO and -fractionCompleted returns 1.0 in that case. NSProgress is by default KVO-compliant for these properties, with the notifications always being sent on the thread which updates the property.
         * @return The converted Objective-C result.
         */
        bool is_indeterminate() const;
        /**
         * @brief Returns the `kind` property of `NSProgress`.
         * @details Either a string identifying what kind of progress is being made, like NSProgressKindFile, or nil. If the value of the localizedDescription property has not been set to a non-nil value then the default implementation of -localizedDescription uses the progress kind to determine how to use the values of other properties, as well as values in the user info dictionary, to create a string that is presentable to the user. This is most useful when -localizedDescription is actually being invoked in another process, whose localization language may be different, as a result of using the publish and subscribe mechanism described here.
         * @return The converted Objective-C result.
         */
        std::string kind() const;
        /**
         * @brief Sets the `kind` property of `NSProgress`.
         * @details Either a string identifying what kind of progress is being made, like NSProgressKindFile, or nil. If the value of the localizedDescription property has not been set to a non-nil value then the default implementation of -localizedDescription uses the progress kind to determine how to use the values of other properties, as well as values in the user info dictionary, to create a string that is presentable to the user. This is most useful when -localizedDescription is actually being invoked in another process, whose localization language may be different, as a result of using the publish and subscribe mechanism described here.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_kind(const std::string& value) const;
        /**
         * @brief Returns the `localizedAdditionalDescription` property of `NSProgress`.
         * @details A more specific description of what progress is being made, fit to present to the user. NSProgress is by default KVO-compliant for this property, with the notifications always being sent on thread which updates the property. The default implementation of the getter for this property does not always return the most recently set value of the property. If the most recently set value of this property is nil then NSProgress uses the value of the kind property to determine how to use the values of other properties, as well as values in the user info dictionary, to return a computed string. If it fails to do that then it returns an empty string. The difference between this and localizedDescription is that this text is meant to be more specific about what work is being done at any particular moment. For example, depending on the kind of progress, the completed and total unit counts, and other parameters, these kinds of strings may be generated: 3 of 10 files 123 KB of 789.1 MB 3.3 MB of 103.92 GB — 2 minutes remaining 1.61 GB of 3.22 GB (2 KB/sec) — 2 minutes remaining 1 minute remaining (1 KB/sec)
         * @return The converted Objective-C result.
         */
        std::string localized_additional_description() const;
        /**
         * @brief Sets the `localizedAdditionalDescription` property of `NSProgress`.
         * @details A more specific description of what progress is being made, fit to present to the user. NSProgress is by default KVO-compliant for this property, with the notifications always being sent on thread which updates the property. The default implementation of the getter for this property does not always return the most recently set value of the property. If the most recently set value of this property is nil then NSProgress uses the value of the kind property to determine how to use the values of other properties, as well as values in the user info dictionary, to return a computed string. If it fails to do that then it returns an empty string. The difference between this and localizedDescription is that this text is meant to be more specific about what work is being done at any particular moment. For example, depending on the kind of progress, the completed and total unit counts, and other parameters, these kinds of strings may be generated: 3 of 10 files 123 KB of 789.1 MB 3.3 MB of 103.92 GB — 2 minutes remaining 1.61 GB of 3.22 GB (2 KB/sec) — 2 minutes remaining 1 minute remaining (1 KB/sec)
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_localized_additional_description(const std::string& value) const;
        /**
         * @brief Returns the `localizedDescription` property of `NSProgress`.
         * @details A description of what progress is being made, fit to present to the user. NSProgress is by default KVO-compliant for this property, with the notifications always being sent on thread which updates the property. The default implementation of the getter for this property does not always return the most recently set value of the property. If the most recently set value of this property is nil then NSProgress uses the value of the kind property to determine how to use the values of other properties, as well as values in the user info dictionary, to return a computed string. If it fails to do that then it returns an empty string. For example, depending on the kind of progress, the completed and total unit counts, and other parameters, these kinds of strings may be generated: Copying 10 files… 30\% completed Copying “TextEdit”…
         * @return The converted Objective-C result.
         */
        std::string localized_description() const;
        /**
         * @brief Sets the `localizedDescription` property of `NSProgress`.
         * @details A description of what progress is being made, fit to present to the user. NSProgress is by default KVO-compliant for this property, with the notifications always being sent on thread which updates the property. The default implementation of the getter for this property does not always return the most recently set value of the property. If the most recently set value of this property is nil then NSProgress uses the value of the kind property to determine how to use the values of other properties, as well as values in the user info dictionary, to return a computed string. If it fails to do that then it returns an empty string. For example, depending on the kind of progress, the completed and total unit counts, and other parameters, these kinds of strings may be generated: Copying 10 files… 30\% completed Copying “TextEdit”…
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_localized_description(const std::string& value) const;
        /**
         * @brief Returns the `old` property of `NSProgress`.
         * @details Return YES if the receiver represents progress that was published before the invocation of +addSubscriberForFileURL:withPublishingHandler: that resulted in the receiver appearing in this process, NO otherwise. The publish and subscribe mechanism described here is generally "level triggered," in that when you invoke +addSubscriberForFileURL:withPublishingHandler: your block will be invoked for every relevant NSProgress that has already been published and not yet unpublished. Sometimes however you need to implement "edge triggered" behavior, in which you do something either exactly when new progress begins or not at all. In the example described above, the Dock does not animate file icon flying when this method returns YES. Note that there is no reliable definition of "before" in this case, which involves multiple processes in a preemptively scheduled system. You should not use this method for anything more important than best efforts at animating perfectly in the face of processes coming and going due to unpredictable user actions.
         * @return The converted Objective-C result.
         */
        bool is_old() const;
        /**
         * @brief Returns the `pausable` property of `NSProgress`.
         * @return The converted Objective-C result.
         */
        bool is_pausable() const;
        /**
         * @brief Sets the `pausable` property of `NSProgress`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pausable(bool value) const;
        /**
         * @brief Returns the `paused` property of `NSProgress`.
         * @return The converted Objective-C result.
         */
        bool is_paused() const;
        /**
         * @brief Returns the `pausingHandler` property of `NSProgress`.
         * @details A block to be invoked when pause is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @return The converted Objective-C result.
         */
        std::function<void()> pausing_handler() const;
        /**
         * @brief Sets the `pausingHandler` property of `NSProgress`.
         * @details A block to be invoked when pause is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_pausing_handler(std::function<void()> value) const;
        /**
         * @brief Returns the `resumingHandler` property of `NSProgress`.
         * @details A block to be invoked when resume is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @return The converted Objective-C result.
         */
        std::function<void()> resuming_handler() const;
        /**
         * @brief Sets the `resumingHandler` property of `NSProgress`.
         * @details A block to be invoked when resume is invoked. The block will be invoked even when the method is invoked on an ancestor of the receiver, or an instance of NSProgress in another process that resulted from publishing the receiver or an ancestor of the receiver. Your block won't be invoked on any particular queue. If it must do work on a specific queue then it should schedule that work on that queue.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_resuming_handler(std::function<void()> value) const;
        /**
         * @brief Returns the `throughput` property of `NSProgress`.
         * @details How fast data is being processed, as an NSNumber containing bytes per second. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @return The converted Objective-C result.
         */
        Number throughput() const;
        /**
         * @brief Sets the `throughput` property of `NSProgress`.
         * @details How fast data is being processed, as an NSNumber containing bytes per second. This property is optional. If present, NSProgress will use the information to present more information in its localized description. This property sets a value in the userInfo dictionary.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_throughput(const Number& value) const;
        /**
         * @brief Returns the `totalUnitCount` property of `NSProgress`.
         * @details The size of the job whose progress is being reported, and how much of it has been completed so far, respectively. For an NSProgress with a kind of NSProgressKindFile, the unit of these properties is bytes while the NSProgressFileTotalCountKey and NSProgressFileCompletedCountKey keys in the userInfo dictionary are used for the overall count of files. For any other kind of NSProgress, the unit of measurement you use does not matter as long as you are consistent. The values may be reported to the user in the localizedDescription and localizedAdditionalDescription. If the receiver NSProgress object is a "leaf progress" (no children), then the fractionCompleted is generally completedUnitCount / totalUnitCount. If the receiver NSProgress has children, the fractionCompleted will reflect progress made in child objects in addition to its own completedUnitCount. As children finish, the completedUnitCount of the parent will be updated.
         * @return The converted Objective-C result.
         */
        std::int64_t total_unit_count() const;
        /**
         * @brief Sets the `totalUnitCount` property of `NSProgress`.
         * @details The size of the job whose progress is being reported, and how much of it has been completed so far, respectively. For an NSProgress with a kind of NSProgressKindFile, the unit of these properties is bytes while the NSProgressFileTotalCountKey and NSProgressFileCompletedCountKey keys in the userInfo dictionary are used for the overall count of files. For any other kind of NSProgress, the unit of measurement you use does not matter as long as you are consistent. The values may be reported to the user in the localizedDescription and localizedAdditionalDescription. If the receiver NSProgress object is a "leaf progress" (no children), then the fractionCompleted is generally completedUnitCount / totalUnitCount. If the receiver NSProgress has children, the fractionCompleted will reflect progress made in child objects in addition to its own completedUnitCount. As children finish, the completedUnitCount of the parent will be updated.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_total_unit_count(std::int64_t value) const;
        /**
         * @brief Returns the `userInfo` property of `NSProgress`.
         * @details Arbitrary values associated with the receiver. Returns a KVO-compliant dictionary that changes as -setUserInfoObject:forKey: is sent to the receiver. The dictionary will send all of its KVO notifications on the thread which updates the property. The result will never be nil, but may be an empty dictionary. Some entries have meanings that are recognized by the NSProgress class itself. See the NSProgress...Key string constants listed below.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> user_info() const;
    };
}
