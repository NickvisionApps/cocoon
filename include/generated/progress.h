#pragma once

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
     * @details An object that conveys ongoing progress to the user for a specified task. The ''Progress'' class provides a self-contained mechanism for progress reporting. It makes it easy for code that performs work to report the progress of that work, and for user interface code to observe that progress for presentation to the user. Specifically, you can use a progress object to show the user a progress bar and explanatory text that update as you do work. It also allows the user to cancel or pause work. \#\#\# Reporting Progress Using the methods of this class, your code can report the progress it's currently making toward completing a task, including progress in related subtasks. You can create instances of this class using the ''init(parent:userInfo:)'' instance method or the ''init(totalUnitCount:)'' class method. Progress objects have many properties that you can use to observe and report current progress. For instance, the ''totalUnitCount'' property represents the total number of units of work, and the ''completedUnitCount'' and ''fractionCompleted'' properties represent how much of that work is complete. The ''fractionCompleted'' property is useful for updating progress indicators or textual descriptors. To check whether progress is complete, test the ''isFinished'' property. The following code shows a sample method that reports the progress of performing an operation on a piece of data. When creating the progress object, you set the value of its ''totalUnitCount'' property to a suitable batch size for the operation, and the ''completedUnitCount'' count is '0'. Each time the loop executes and processes a batch of data, you increment the progress object's ''completedUnitCount'' property appropriately. '''objc - (void)startTaskWithData:(NSData )data { NSUInteger batchSize = ... use a suitable batch size NSProgress progress = [NSProgress progressWithTotalUnitCount:batchSize]; for (NSUInteger index = 0; index \< batchSize; index++) { // Check for cancellation. if ([progress isCancelled]) { // Tidy up as necessary. break; } // Do something with this batch of data. // Report progress (add 1 because the work is complete for the current index). [progress setCompletedUnitCount:(index + 1)]; } } ''' Each of the properties of a progress object, including ''totalUnitCount'', ''completedUnitCount'', and ''fractionCompleted'', support key-value observing (KVO). This makes it extremely easy for a view or window controller object to observe the properties, and update UI elements, such as progress indicators, when the values change. It also means that there is a nonzero cost to updating the values of those properties, so avoid using a unit count that is too granular. If you're iterating over a large dataset, for example, and each operation takes only a trivial amount of time, divide the work into batches so you can update the unit count once per batch rather than once per iteration. \#\#\# Reporting Progress for Multiple Operations Sometimes, your code may need to report the overall progress of an operation that consists of several suboperations. To accomplish this, your code can report the progress of each suboperation by building up a tree of progress objects. The ''Progress'' reporting mechanism supports a loosely coupled relationship between progress objects. Suboperations don't need to know anything about the containing progress item — you can create new progress objects as suboperations of another progress instance. When you assign a progress instance, the system allocates a portion of the containing progress instance's pending unit count. When the suboperation's progress object completes, the containing progress object's ''completedUnitCount'' property automatically increases by a predefined amount. > Note: > The ''completedUnitCount'' property for a containing progress object only updates when the suboperation is '100\%' complete. The ''fractionCompleted'' property for a containing progress object updates continuously as work progresses for all suboperations. You add suboperation progress objects to your tree implicitly or explicitly. \#\#\#\# Adding a Progress Operation Implicitly Add a suboperation implicitly by setting a pending unit count for the containing progress object and creating a new ''Progress'' instance. When you create the new progress instance, the system sets it as a suboperation of the containing progress object, and assigns the pending unit count. As an example, consider that you're tracking the progress of code downloading and copying files on disk. You can use a single progress object to track the entire task, but it's easier to manage each subtask using a separate progress object. You start by creating an overall progress object with a suitable total unit count, call ''becomeCurrent(withPendingUnitCount:)'', then create your suboperation progress objects before finally calling ''resignCurrent()''. The system divides the pending unit count that you specify in the first method equally among the suboperation progress objects you create between these two method calls. Each suboperation progress object maintains its own internal unit count. When the suboperation object's ''completedUnitCount'' equals or exceeds its ''totalUnitCount'', the system increases the containing progress object's ''completedUnitCount'' by the assigned portion of the original pending unit count. In the following example, the overall progress object has 100 units. The two suboperation objects, therefore, get 50 pending units each, and keep track internally of 10 units of work each. When each suboperation completes its 10 units, the system increases the overall progress object's completed unit count by 50. '''objc - (void)startLongOperation { self.overallProgress = [NSProgress progressWithTotalUnitCount:100]; [self.overallProgress becomeCurrentWithPendingUnitCount:50]; [self work1]; [self.overallProgress resignCurrent]; [self.overallProgress becomeCurrentWithPendingUnitCount:50]; [self work2]; [self.overallProgress resignCurrent]; } - (void)work1 { NSProgress firstTaskProgress = [NSProgress progressWithTotalUnitCount:10]; // Perform first task. } - (void)work2 { NSProgress secondTaskProgress = [NSProgress progressWithTotalUnitCount:10]; // Perform second task. } ''' If you don't create any suboperation progress objects between the calls to ''becomeCurrent(withPendingUnitCount:)'' and ''resignCurrent()'', the containing progress object automatically updates its ''completedUnitCount'' by adding the pending units. \#\#\#\# Adding a Progress Operation Explicitly To add a progress operation explicitly, call ''addChild(:withPendingUnitCount:)'' on the containing progress object. The value for the pending unit count is the amount of the containing progress object's ''totalUnitCount'' that the suboperation consumes, which conforms to the ''ProgressReporting'' protocol. In the following example, the overall progress object has 10 units. The suboperation progress for the download gets eight units and tracks the download of a photo. The progress for the filter takes a lot less time and gets the remaining two units. When the download completes, the system updates the containing progress object's completed unit count by eight. When the filter completes, the system updates it by the remaining two units. '''objc - (void)startLongOperation { self.overallProgress = [NSProgress progressWithTotalUnitCount:10]; [self.overallProgress addChild:download.progress withPendingUnitCount:8]; // Do the download. [self.overallProgress addChild:filter.progress withPendingUnitCount:2]; // Perform the filter. } '''
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
        explicit Progress();
        /// @brief Creates a null handle that refers to no native object.
        Progress(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Progress(Adopt adopt);
        /**
     * @brief Calls `-[NSProgress addChild:withPendingUnitCount:]`.
     * @details Adds a process object as a suboperation of a progress tree. - Parameters: - child: The progress instance to add to the progress tree. - inUnitCount: The number of units of work for the new suboperation to complete. You assign the suboperation a portion of the receiver's total unit count according to 'inUnitCount'.
     * @param child Argument converted to the Objective-C parameter of the same role.
     * @param in_unit_count Argument converted to the Objective-C parameter of the same role.
     */
        void add_child(const Progress& child, std::int64_t in_unit_count) const;
        /**
     * @brief Calls `+[NSProgress addSubscriberForFileURL:withPublishingHandler:]`.
     * @details Registers a file URL to hear about the progress of a file operation. - Parameters: - url: The URL of the file to observe. - publishingHandler: A closure that the system invokes when a progress object that represents a file operation matching the specified URL calls '-publish'. - Returns: A proxy of the progress object to observe. The system invokes the passed-in block when a progress object calls '-publish' with an 'NSProgressFileURLKey' user info dictionary entry that's a URL that is the same as this method's URL, or that is an item that the URL directly contains. The progress object that passes to your block is a proxy of the published progress object. The passed-in block may return another block. If it does, the system invokes the returned block when the observed progress object invokes '-unpublish', the publishing process terminates, or you invoke '+removeSubscriber:'. The system invokes the blocks you provide on the main thread.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param publishing_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object add_subscriber_for_file_url(const URL& url, std::function<std::function<void()>(Progress)> publishing_handler);
        /**
     * @brief Calls `-[NSProgress becomeCurrentWithPendingUnitCount:]`.
     * @details Sets the progress object as the current object of the current thread, and assigns the amount of work for the next suboperation progress object to perform. - Parameter unitCount: The number of units of work for the next progress object that initializes when you invoke '-initWithParent:userInfo:' in the current thread with this progress object as the containing progress object. The number represents the portion of work to perform in relation to the total number of units of work, which is the value of the progress object's 'totalUnitCount' property. The units of work for this parameter must be the same units of work in the progress object's 'totalUnitCount' property. Use this method to build a tree of progress objects. You must always balance invocations of this method with invocations of '-resignCurrent'.
     * @param unit_count Argument converted to the Objective-C parameter of the same role.
     */
        void become_current_with_pending_unit_count(std::int64_t unit_count) const;
        /**
     * @brief Calls `-[NSProgress cancel]`.
     * @details Cancels progress tracking. This method invokes the block for 'cancellationHandler', if there is one, and ensures that any subsequent reads of the 'isCancelled' property return 'YES'. If the receiver has suboperations, the system cancels their progress as well.
     */
        void cancel() const;
        /**
     * @brief Calls `+[NSProgress currentProgress]`.
     * @details Returns the progress instance, if any, associated with the current thread. If you invoke '-becomeCurrentWithPendingUnitCount:' on the current thread, this method returns the progress instance. Use this per-thread value to allow code that performs work to report useful progress even when it's widely separated from the code that actually presents progress information to the user, and without requiring layers of intervening code to pass around an 'NSProgress' instance. To ensure that you report progress in known units of work, you typically work with a suboperation progress object that you create by calling '+progressWithTotalUnitCount:'.
     * @return The converted Objective-C result.
     */
        static Progress current_progress();
        /**
     * @brief Calls `+[NSProgress discreteProgressWithTotalUnitCount:]`.
     * @details Creates and returns a progress instance with the specified unit count that isn't part of any existing progress tree. - Parameter unitCount: The total number of units of work to assign to the progress instance. - Returns: A new progress instance with its containing progress object set to 'nil'. Use this method to create the top-level progress object that your custom classes return. The receiver of the returned progress object can add it to a progress tree using '-addChild:withPendingUnitCount:'. You're responsible for updating the progress count of the created progress object. You can invoke this method on one thread and then message the returned 'NSProgress' on another thread. For example, you can capture the created progress instance in a block that you pass to 'dispatch_async()'. In that block, you can invoke methods like '-becomeCurrentWithPendingUnitCount:' or '-resignCurrent', and set the 'completedUnitCount' or 'isCancelled' properties as your app finishes its work.
     * @param unit_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Progress discrete_progress_with_total_unit_count(std::int64_t unit_count);
        /**
     * @brief Calls `-[NSProgress pause]`.
     * @details Pauses progress tracking. This method invokes the block for 'pausingHandler', if there is one, and ensures that any subsequent reads of the 'isPaused' property return 'YES'. If the receiver has suboperations, the system pauses their progress as well.
     */
        void pause() const;
        /**
     * @brief Calls `-[NSProgress performAsCurrentWithPendingUnitCount:usingBlock:]`.
     * @details Retrieves the current thread's progress object, executes the specified block, and increments the progress object by the specified units of work. - Parameters: - unitCount: The number of units of work to increment for the current progress object. - work: A block that wraps the work you specify to complete for incrementing the current progress. Use this function as a convenience method to wrap an existing method or block to increment the current progress object. This function is the same as calling '-becomeCurrentWithPendingUnitCount:', doing the work you specify in the block, and calling '-resignCurrent'.
     * @param unit_count Argument converted to the Objective-C parameter of the same role.
     * @param work Argument converted to the Objective-C parameter of the same role.
     */
        void perform_as_current_with_pending_unit_count(std::int64_t unit_count, std::function<void()> work) const;
        /**
     * @brief Calls `+[NSProgress progressWithTotalUnitCount:]`.
     * @details Creates and returns a progress instance. - Parameter unitCount: The total number of units of work to assign to the progress instance. If a current progress object exists, the initializer uses it to set the value of the 'totalUnitCount' property. In many cases, you can precede code that does a substantial amount of work with an invocation of this method, then repeatedly set the 'completedUnitCount' or 'isCancelled' property in the loop that does the work. You can invoke this method on one thread and then message the returned 'NSProgress' on another thread. For example, you can capture the created progress instance in a block that you pass to 'dispatch_async()'. In that block, you can invoke methods like '-becomeCurrentWithPendingUnitCount:' or '-resignCurrent', and set the 'completedUnitCount' or 'isCancelled' properties as your app finishes its work.
     * @param unit_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Progress progress_with_total_unit_count(std::int64_t unit_count);
        /**
     * @brief Calls `+[NSProgress progressWithTotalUnitCount:parent:pendingUnitCount:]`.
     * @details Creates a progress instance for the specified progress object with a unit count that's a portion of the containing object's total unit count. - Parameters: - unitCount: The total number of units of work to assign to the progress instance. - parent: The containing progress object for the created progress object. - portionOfParentTotalUnitCount: The unit count for the progress object.
     * @param unit_count Argument converted to the Objective-C parameter of the same role.
     * @param parent Argument converted to the Objective-C parameter of the same role.
     * @param portion_of_parent_total_unit_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Progress progress_with_total_unit_count(std::int64_t unit_count, const Progress& parent, std::int64_t portion_of_parent_total_unit_count);
        /**
     * @brief Calls `-[NSProgress publish]`.
     * @details Publishes the progress object for other processes to observe it. Entries in the user info dictionary determine whether another process can discover the progress object to observe it, and how it does that. For example, an 'NSProgressFileURLKey' entry makes a progress object discoverable by corresponding invokers of '+addSubscriberForFileURL:withPublishingHandler:'. When you make a progress object observable by other processes, you must ensure that at least 'localizedDescription', 'isIndeterminate', and 'fractionCompleted' always work when you send proxies of your progress object in other processes. You make 'isIndeterminate' and 'fractionCompleted' work by accurately setting the total and completed unit counts of the progress. You make 'localizedDescription' work by setting the value of the kind property to something valid, like 'NSProgressKindFile', and then fulfilling the requirements for that kind of progress. You can publish an instance of 'NSProgress' one time only.
     */
        void publish() const;
        /**
     * @brief Calls `+[NSProgress removeSubscriber:]`.
     * @details Removes a proxy progress object that the add subscriber method returns. - Parameter subscriber: The proxy of the progress object to observe. If the block for '+addSubscriberForFileURL:withPublishingHandler:' returns a closure, the system invokes that closure on the main thread when you invoke '+removeSubscriber:'.
     * @param subscriber Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_subscriber(const Object& subscriber);
        /**
     * @brief Calls `-[NSProgress resignCurrent]`.
     * @details Restores the previous progress object to become the current progress object on the thread. This method restores the current progress object to what it was before invoking '-becomeCurrentWithPendingUnitCount:'.
     */
        void resign_current() const;
        /**
     * @brief Calls `-[NSProgress resume]`.
     * @details Resumes progress tracking. This method invokes the block for 'resumingHandler', if there is one, and ensures that any subsequent reads of the 'isPaused' property return 'NO'. If the receiver has suboperations, the system resumes their progress as well.
     */
        void resume() const;
        /**
     * @brief Calls `-[NSProgress setUserInfoObject:forKey:]`.
     * @details Sets a value in the user info dictionary. - Parameters: - objectOrNil: The object to set for the specified key, or 'nil' to remove an existing entry in the dictionary. - key: The key for storing the specified object. Use this method to set a value in the 'userInfo' dictionary, with appropriate KVO notification for properties with values that can depend on values in the user info dictionary, like 'localizedDescription'.
     * @param object_or_nil Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info_object(const Object& object_or_nil, const std::string& key) const;
        /**
     * @brief Calls `-[NSProgress unpublish]`.
     * @details Removes a progress object from publication, making it unobservable by other processes.
     */
        void unpublish() const;
        /**
     * @brief Returns the `cancellable` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking work that you can cancel. By default, 'NSProgress' objects are cancelable. You typically use this property to communicate whether controls for canceling appear in a progress-reporting user interface. 'NSProgress' itself doesn't do anything with this property other than help pass the value from progress reporters to progress observers. If an 'NSProgress' is cancelable, implement the ability to cancel progress either by setting a block for the 'cancellationHandler' property, or by polling the 'isCancelled' property periodically while performing the relevant work. It's valid for the value of this property to change during the lifetime of an 'NSProgress' object. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @return The converted Objective-C result.
     */
        bool is_cancellable() const;
        /**
     * @brief Sets the `cancellable` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking work that you can cancel. By default, 'NSProgress' objects are cancelable. You typically use this property to communicate whether controls for canceling appear in a progress-reporting user interface. 'NSProgress' itself doesn't do anything with this property other than help pass the value from progress reporters to progress observers. If an 'NSProgress' is cancelable, implement the ability to cancel progress either by setting a block for the 'cancellationHandler' property, or by polling the 'isCancelled' property periodically while performing the relevant work. It's valid for the value of this property to change during the lifetime of an 'NSProgress' object. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cancellable(bool value) const;
        /**
     * @brief Returns the `cancellationHandler` property of `NSProgress`.
     * @details The block to invoke when canceling progress. If the receiver is a suboperation of another progress object, the system invokes the 'cancellationHandler' block when canceling the containing progress object. You're responsible for canceling any work for the progress object. You can invoke the cancellation handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the cancellation handler block.
     * @return The converted Objective-C result.
     */
        std::function<void()> cancellation_handler() const;
        /**
     * @brief Sets the `cancellationHandler` property of `NSProgress`.
     * @details The block to invoke when canceling progress. If the receiver is a suboperation of another progress object, the system invokes the 'cancellationHandler' block when canceling the containing progress object. You're responsible for canceling any work for the progress object. You can invoke the cancellation handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the cancellation handler block.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cancellation_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `cancelled` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking canceled work. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property. If the receiver has a canceled containing progress object, the receiver reports a canceled status.
     * @return The converted Objective-C result.
     */
        bool is_cancelled() const;
        /**
     * @brief Returns the `completedUnitCount` property of `NSProgress`.
     * @details The number of completed units of work for the current job. For an 'NSProgress' with a kind of 'NSProgressKindFile', the unit of this property is bytes, and the 'NSProgressFileTotalCountKey' and 'NSProgressFileCompletedCountKey' keys in the 'userInfo' dictionary report the overall count of files. For any other kind of 'NSProgress', the unit of measurement doesn't matter as long as it's consistent. You can report the values to the user in the 'localizedDescription' and 'localizedAdditionalDescription'.
     * @return The converted Objective-C result.
     */
        std::int64_t completed_unit_count() const;
        /**
     * @brief Sets the `completedUnitCount` property of `NSProgress`.
     * @details The number of completed units of work for the current job. For an 'NSProgress' with a kind of 'NSProgressKindFile', the unit of this property is bytes, and the 'NSProgressFileTotalCountKey' and 'NSProgressFileCompletedCountKey' keys in the 'userInfo' dictionary report the overall count of files. For any other kind of 'NSProgress', the unit of measurement doesn't matter as long as it's consistent. You can report the values to the user in the 'localizedDescription' and 'localizedAdditionalDescription'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completed_unit_count(std::int64_t value) const;
        /**
     * @brief Returns the `estimatedTimeRemaining` property of `NSProgress`.
     * @details How much time is probably left in the operation, as an 'NSNumber' containing a number of seconds. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @return The converted Objective-C result.
     */
        Number estimated_time_remaining() const;
        /**
     * @brief Sets the `estimatedTimeRemaining` property of `NSProgress`.
     * @details How much time is probably left in the operation, as an 'NSNumber' containing a number of seconds. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_estimated_time_remaining(const Number& value) const;
        /**
     * @brief Returns the `fileCompletedCount` property of `NSProgress`.
     * @details If the progress is operating on a set of files, the number of completed files in the operation. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @return The converted Objective-C result.
     */
        Number file_completed_count() const;
        /**
     * @brief Sets the `fileCompletedCount` property of `NSProgress`.
     * @details If the progress is operating on a set of files, the number of completed files in the operation. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_completed_count(const Number& value) const;
        /**
     * @brief Returns the `fileOperationKind` property of `NSProgress`.
     * @details The kind of file operation for the progress object. Set this value when the 'kind' property is 'NSProgressKindFile' to describe the kind of file operation. If present, 'NSProgress' presents additional information in its localized description by setting a value in the 'userInfo' dictionary.
     * @return The converted Objective-C result.
     */
        std::string file_operation_kind() const;
        /**
     * @brief Sets the `fileOperationKind` property of `NSProgress`.
     * @details The kind of file operation for the progress object. Set this value when the 'kind' property is 'NSProgressKindFile' to describe the kind of file operation. If present, 'NSProgress' presents additional information in its localized description by setting a value in the 'userInfo' dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_operation_kind(const std::string& value) const;
        /**
     * @brief Returns the `fileTotalCount` property of `NSProgress`.
     * @details If the progress is operating on a set of files, the total number of files in the operation. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @return The converted Objective-C result.
     */
        Number file_total_count() const;
        /**
     * @brief Sets the `fileTotalCount` property of `NSProgress`.
     * @details If the progress is operating on a set of files, the total number of files in the operation. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_total_count(const Number& value) const;
        /**
     * @brief Returns the `fileURL` property of `NSProgress`.
     * @details A URL that represents the file for the current progress object. Set this value for a progress that you publish to subscribers that register for updates using '+addSubscriberForFileURL:withPublishingHandler:'. If present, 'NSProgress' presents additional information in its localized description by setting a value in the 'userInfo' dictionary.
     * @return The converted Objective-C result.
     */
        URL file_url() const;
        /**
     * @brief Sets the `fileURL` property of `NSProgress`.
     * @details A URL that represents the file for the current progress object. Set this value for a progress that you publish to subscribers that register for updates using '+addSubscriberForFileURL:withPublishingHandler:'. If present, 'NSProgress' presents additional information in its localized description by setting a value in the 'userInfo' dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_url(const URL& value) const;
        /**
     * @brief Returns the `finished` property of `NSProgress`.
     * @details A Boolean value that indicates the progress object is complete. A progress object finishes when the 'completedUnitCount' equals or exceeds the 'totalUnitCount'. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @return The converted Objective-C result.
     */
        bool is_finished() const;
        /**
     * @brief Returns the `fractionCompleted` property of `NSProgress`.
     * @details The fraction of the overall work completed by this progress object, including work done by any children it may have. If the receiver object doesn't have any suboperations, 'fractionCompleted' is generally the result of dividing 'completedUnitCount' by 'totalUnitCount'. Setting both 'totalUnitCount' and 'completedUnitCount' to zero indicates that there is no progress to track. In this case, 'isIndeterminate' returns 'NO' and 'fractionCompleted' returns '0.0'. If the receiver does have suboperations, 'fractionCompleted' reflects progress from those progress objects in addition to its own 'completedUnitCount'. When the suboperations finish, the 'completedUnitCount' of the containing progress object updates.
     * @return The converted Objective-C result.
     */
        double fraction_completed() const;
        /**
     * @brief Returns the `indeterminate` property of `NSProgress`.
     * @details A Boolean value that indicates whether the tracked progress is indeterminate. Use indeterminate progress only when you're unable to determine a reasonable value for either 'completedUnitCount' or 'totalUnitCount'. Progress is indeterminate when the value of the 'totalUnitCount' or 'completedUnitCount' is less than zero or if both values are zero. When progress is indeterminate, 'fractionCompleted' returns '0.0' and 'isFinished' returns 'NO'. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @return The converted Objective-C result.
     */
        bool is_indeterminate() const;
        /**
     * @brief Returns the `kind` property of `NSProgress`.
     * @details An object that represents the kind of progress for the progress object. This property identifies the kind of progress for the progress object, such as 'NSProgressKindFile'. It can be 'nil'. If you set a non-'nil' value to 'kind', the default 'localizedDescription' getter uses the kind of progress to determine how to use the values of other properties, along with values in the user info dictionary, to create a string representation.
     * @return The converted Objective-C result.
     */
        std::string kind() const;
        /**
     * @brief Sets the `kind` property of `NSProgress`.
     * @details An object that represents the kind of progress for the progress object. This property identifies the kind of progress for the progress object, such as 'NSProgressKindFile'. It can be 'nil'. If you set a non-'nil' value to 'kind', the default 'localizedDescription' getter uses the kind of progress to determine how to use the values of other properties, along with values in the user info dictionary, to create a string representation.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_kind(const std::string& value) const;
        /**
     * @brief Returns the `localizedAdditionalDescription` property of `NSProgress`.
     * @details A more specific localized description of tracked progress for the receiver. If you don't specify your own custom value for this property, 'NSProgress' uses the value of the 'kind' property to determine how to use the values of other properties, as well as values in the user info dictionary, to return an automatically computed string. If it fails to do that, it returns an empty string. The 'localizedAdditionalDescription' is more specific than 'localizedDescription' about the work the receiver is tracking at any particular moment. Depending on the kind of progress, the completed and total unit counts, and other parameters, localized additional descriptions resemble the following: - 3 of 10 files - 123 KB of 789.1 MB - 3.3 MB of 103.92 GB -- 2 hours remaining - 1.61 GB of 3.22 GB (2 KB/sec) -- 2 minutes remaining - 1 minute remaining (1 KB/sec)
     * @return The converted Objective-C result.
     */
        std::string localized_additional_description() const;
        /**
     * @brief Sets the `localizedAdditionalDescription` property of `NSProgress`.
     * @details A more specific localized description of tracked progress for the receiver. If you don't specify your own custom value for this property, 'NSProgress' uses the value of the 'kind' property to determine how to use the values of other properties, as well as values in the user info dictionary, to return an automatically computed string. If it fails to do that, it returns an empty string. The 'localizedAdditionalDescription' is more specific than 'localizedDescription' about the work the receiver is tracking at any particular moment. Depending on the kind of progress, the completed and total unit counts, and other parameters, localized additional descriptions resemble the following: - 3 of 10 files - 123 KB of 789.1 MB - 3.3 MB of 103.92 GB -- 2 hours remaining - 1.61 GB of 3.22 GB (2 KB/sec) -- 2 minutes remaining - 1 minute remaining (1 KB/sec)
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_additional_description(const std::string& value) const;
        /**
     * @brief Returns the `localizedDescription` property of `NSProgress`.
     * @details A localized description of tracked progress for the receiver. If you don't specify your own custom value for this property, 'NSProgress' uses the value of the 'kind' property to determine how to use the values of other properties, as well as values in the user info dictionary, to return an automatically computed string. If it fails to do that, it returns an empty string. The 'localizedDescription' represents a general description of the work the receiver tracks. Depending on the kind of progress, the completed and total unit counts, and other parameters, localized descriptions resemble the following: - Copying 10 files... - 30\% completed - Copying “TextEdit”... By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @return The converted Objective-C result.
     */
        std::string localized_description() const;
        /**
     * @brief Sets the `localizedDescription` property of `NSProgress`.
     * @details A localized description of tracked progress for the receiver. If you don't specify your own custom value for this property, 'NSProgress' uses the value of the 'kind' property to determine how to use the values of other properties, as well as values in the user info dictionary, to return an automatically computed string. If it fails to do that, it returns an empty string. The 'localizedDescription' represents a general description of the work the receiver tracks. Depending on the kind of progress, the completed and total unit counts, and other parameters, localized descriptions resemble the following: - Copying 10 files... - 30\% completed - Copying “TextEdit”... By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_localized_description(const std::string& value) const;
        /**
     * @brief Returns the `old` property of `NSProgress`.
     * @details A Boolean value that indicates when the observed progress object invokes the publish method before you subscribe to it. The publish and subscribe mechanism is generally level-triggered, in that when you invoke '+addSubscriberForFileURL:withPublishingHandler:', the system invokes your block for every relevant published and unpublished progress object. Sometimes you need to implement edge-triggered behavior, in which you do something either exactly when new progress begins or not at all. There's no reliable definition of before in this case, which involves multiple processes in a preemptively scheduled system. Don't use this method for anything more important than best efforts at animating. It can be inaccurate due to processes coming and going from unpredictable user actions.
     * @return The converted Objective-C result.
     */
        bool is_old() const;
        /**
     * @brief Returns the `pausable` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking work that you can pause. By default, 'NSProgress' objects aren't pausable. You typically use this property to communicate whether controls for pausing appear in a progress-reporting user interface. 'NSProgress' itself doesn't do anything with this property other than help pass the value from progress reporters to progress observers. If an 'NSProgress' is pausable, implement the ability to pause either by setting a block for the 'pausingHandler' property, or by polling the 'isPaused' property periodically while performing the relevant work. It's valid for the value of this property to change during the lifetime of an 'NSProgress' object. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @return The converted Objective-C result.
     */
        bool is_pausable() const;
        /**
     * @brief Sets the `pausable` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking work that you can pause. By default, 'NSProgress' objects aren't pausable. You typically use this property to communicate whether controls for pausing appear in a progress-reporting user interface. 'NSProgress' itself doesn't do anything with this property other than help pass the value from progress reporters to progress observers. If an 'NSProgress' is pausable, implement the ability to pause either by setting a block for the 'pausingHandler' property, or by polling the 'isPaused' property periodically while performing the relevant work. It's valid for the value of this property to change during the lifetime of an 'NSProgress' object. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pausable(bool value) const;
        /**
     * @brief Returns the `paused` property of `NSProgress`.
     * @details A Boolean value that indicates whether the receiver is tracking paused work. By default, 'NSProgress' is KVO-compliant for this property. It sends notifications on the same thread that updates the property. If the receiver has a paused containing progress object, the receiver reports a paused status.
     * @return The converted Objective-C result.
     */
        bool is_paused() const;
        /**
     * @brief Returns the `pausingHandler` property of `NSProgress`.
     * @details The block to invoke when pausing progress. If the receiver is a suboperation of another progress object, the system invokes the 'pausingHandler' block when pausing the containing progress object. You're responsible for pausing any work for the progress object. You can invoke the pausing handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the pausing handler block.
     * @return The converted Objective-C result.
     */
        std::function<void()> pausing_handler() const;
        /**
     * @brief Sets the `pausingHandler` property of `NSProgress`.
     * @details The block to invoke when pausing progress. If the receiver is a suboperation of another progress object, the system invokes the 'pausingHandler' block when pausing the containing progress object. You're responsible for pausing any work for the progress object. You can invoke the pausing handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the pausing handler block.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pausing_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `resumingHandler` property of `NSProgress`.
     * @details The block to invoke when progress resumes. If the receiver is a suboperation of another progress object, the system invokes the 'resumingHandler' block when resuming the containing progress object. You're responsible for resuming any work for the progress object. You can invoke the resuming handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the resuming handler block.
     * @return The converted Objective-C result.
     */
        std::function<void()> resuming_handler() const;
        /**
     * @brief Sets the `resumingHandler` property of `NSProgress`.
     * @details The block to invoke when progress resumes. If the receiver is a suboperation of another progress object, the system invokes the 'resumingHandler' block when resuming the containing progress object. You're responsible for resuming any work for the progress object. You can invoke the resuming handler on any queue. If you must do work on a specific queue, dispatch to that queue from within the resuming handler block.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resuming_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `throughput` property of `NSProgress`.
     * @details How fast data is being processed, as an 'NSNumber' containing bytes per second. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @return The converted Objective-C result.
     */
        Number throughput() const;
        /**
     * @brief Sets the `throughput` property of `NSProgress`.
     * @details How fast data is being processed, as an 'NSNumber' containing bytes per second. This property is optional. If present, 'NSProgress' will use the information to present more information in its localized description. This property sets a value in the user info dictionary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_throughput(const Number& value) const;
        /**
     * @brief Returns the `totalUnitCount` property of `NSProgress`.
     * @details The total number of tracked units of work for the current progress. For an 'NSProgress' with a kind of 'NSProgressKindFile', the unit of this property is bytes, and the 'NSProgressFileTotalCountKey' and 'NSProgressFileCompletedCountKey' keys in the 'userInfo' dictionary report the overall count of files. For any other kind of 'NSProgress', the unit of measurement doesn't matter as long as it's consistent. You can report the values to the user in the 'localizedDescription' and 'localizedAdditionalDescription'.
     * @return The converted Objective-C result.
     */
        std::int64_t total_unit_count() const;
        /**
     * @brief Sets the `totalUnitCount` property of `NSProgress`.
     * @details The total number of tracked units of work for the current progress. For an 'NSProgress' with a kind of 'NSProgressKindFile', the unit of this property is bytes, and the 'NSProgressFileTotalCountKey' and 'NSProgressFileCompletedCountKey' keys in the 'userInfo' dictionary report the overall count of files. For any other kind of 'NSProgress', the unit of measurement doesn't matter as long as it's consistent. You can report the values to the user in the 'localizedDescription' and 'localizedAdditionalDescription'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_total_unit_count(std::int64_t value) const;
        /**
     * @brief Returns the `userInfo` property of `NSProgress`.
     * @details A dictionary of arbitrary values for the receiver. A KVO-compliant dictionary that changes in response to '-setUserInfoObject:forKey:'. The dictionary sends all of its KVO notifications on the thread that updates the property. Some entries have meanings that the 'NSProgress' class recognizes. See the 'NSProgress...Key' string constants listed below.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> user_info() const;
    };
}
