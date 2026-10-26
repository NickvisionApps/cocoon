#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class FileAccessIntent;
    class OperationQueue;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileCoordinator` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileCoordinator file_coordinator;
     * file_coordinator.set_purpose_identifier("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileCoordinator file_coordinator{};
     * file_coordinator.set_purpose_identifier("text");
     * auto purpose_identifier = file_coordinator.purpose_identifier();
     * file_coordinator.cancel();
     * file_coordinator.item_at_url(cocoon::URL(), {"a", "b"});
     * file_coordinator.item_at_url(cocoon::URL(), cocoon::URL());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfilecoordinator
     */
    class FileCoordinator : public Object
    {
    public:
        /// @brief Creates a new `NSFileCoordinator` instance and returns a handle to it.
        explicit FileCoordinator(const Object& file_presenter_or_nil);
        /// @brief Creates a new `NSFileCoordinator` instance and returns a handle to it.
        explicit FileCoordinator();
        /// @brief Creates a null handle that refers to no native object.
        FileCoordinator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileCoordinator(Adopt adopt);
        /**
         * @brief Calls `+[NSFileCoordinator addFilePresenter:]`.
         * @details The process' file presenters. If you invoke +addFilePresenter: you have to do a balancing invocation of +removeFilePresenter: before the file presenter is deallocated, even in a garbage-collected application. If your application reads an item and then registers a file presenter for it there is a possible race condition in which between those two steps another process does coordinated reading or writing of the item, without any messages sent to your not-quite-registered file presenter. This can leave your file presenter ignorant of the fact that what it knows about the item it just read is already out of date, or under the misconception that just because it hasn't received a -relinquish... method it owns the item. To avoid that race condition you can invoke +addFilePresenter: in the same block that you pass to -coordinateReadingItemAtURL:options:error:byAccessor: to read what the file presenter will present.
         * @param file_presenter Argument converted to the Objective-C parameter of the same role.
         */
        static void add_file_presenter(const Object& file_presenter);
        /**
         * @brief Calls `-[NSFileCoordinator cancel]`.
         * @details Cancel all invocations of -coordinate... and -prepare... methods for the receiver. Any current invocation of one of those methods will stop waiting and return immediately, unless it has already invoked the passed-in block, in which case it will return when the passed-in block returns. Subsequent invocations of those methods will not invoke the blocks passed into them at all. When an invocation of -coordinate... or -prepare... returns without invoking the passed-in block because this method was invoked it instead returns an error whose domain is NSCocoaErrorDomain and whose code is NSUserCancelledError. Messages that have already been sent to NSFilePresenters will not be cancelled but the file coordination machinery will stop waiting for the replies. This method can be invoked from any thread. It always returns immediately, without waiting for anything. Cancellation is racy; you usually cannot assume that no block passed into a -coordinate... or -prepare... method is already being invoked, so the code inside those blocks typically still has to check for cancellation, whatever that means in your application.
         */
        void cancel() const;
        /**
         * @brief Calls `-[NSFileCoordinator coordinateAccessWithIntents:queue:byAccessor:]`.
         * @details Given an array of one or more NSFileAccessIntent objects that specify reading and/or writing items located by the corresponding URLs, wait asynchronously for certain other readers and writers and then invoke the passed-in block on the given queue, which must not be nil. If an error occurs, file access is not granted and a non-nil error will be passed to the accessor block. If file access is successfully granted, then 'error' will be nil and you may perform the intended file access inside the accessor block. You must use the URL property on the NSFileAccessIntent objects when performing file access in the accessor block. Within the block, the NSFileAccessIntent objects' URLs may differ from their original values to account for items that have been moved or renamed while waiting for access to be granted. When access to the intended files is granted, certain other readers and writers are made to wait until the given block returns, which defines the end of that file access. Do not allow file access to continue after the accessor block returns by dispatching work to other threads or queues. You can invoke this method to serialize your process's access of files and directories with other processes' access of the same files and directories so that inconsistencies due to overlapping reading and writing don't occur. It also causes messages to be sent to NSFilePresenters, and wait for NSFilePresenters to react, as described below. The fact that file system items can be moved or renamed while this method is waiting to invoke the block you passed when invoking it is why it's critical to use the URL property on the NSFileAccessIntent objects, not the URLs you used when initializing them. In general a coordinated reader waits for a coordinated writer of the same item, and a coordinated writer waits for coordinated readers and other coordinated writers of the same item. Coordinated readers do not wait for each other. Coordinated reading or writing of items in a file package is treated as coordinated reading or writing of the file package as a whole. A coordinated reader of a directory that is not a file package does not wait for coordinated writers of contained items, or cause such writers to wait. With one exception, a coordinated writer of a directory that is not a file package does not wait for coordinated readers and writers of contained items, or cause such readers and writers to wait. The exception is when you use NSFileCoordinatorWritingForDeleting, NSFileCoordinatorWritingForMoving, or NSFileCoordinatorWritingForReplacing. They make your coordinated writer wait for previously scheduled coordinated readers and writers of contained items, and causes subsequently scheduled coordinated readers and writers of contained items to wait. None of those rules apply to coordinated readers and writers that are using the exact same instance of NSFileCoordinator, including arrays of multiple NSFileAccessIntent objects. Instances of NSFileCoordinator never block themselves. You can take advantage of that in a couple of ways when invoking -coordinateAccessWithIntents:queue:byAccessor: multiple times on the same NSFileCoordinator instance, but take care because doing so raises the possibility of deadlocking with other processes that are doing the same sort of thing. If you can, you should invoke -coordinateAccessWithIntents:queue:byAccessor: a single time with multiple NSFileAccessIntent objects instead of invoking it multiple times with a single NSFileAccssIntent object. In addition to waiting for writers, readers wait for NSFilePresenters that are messaged as part of the coordinated reading. Coordinated reading of an item triggers the sending of messages to NSFilePresenters that implement the corresponding optional methods, even those in other processes, except the one specified when -initWithFilePresenter: was invoked: - -relinquishPresentedItemToReader: is sent to NSFilePresenters of the item and, if the item is in a file package, NSFilePresenters of the file package. If there are nested file packages then the message is sent to NSFilePresenters of all of them. - If NSFileCoordinatorReadingWithoutChanges is not used then -savePresentedItemChangesWithCompletionHandler: is also sent to the same NSFilePresenters. In addition to waiting for readers and other writers, writers wait for NSFilePresenters that are messaged as part of the coordinated writing. Coordinated writing of an item triggers the sending of messages to NSFilePresenters that implement the corresponding optional methods, even those in other processes, except the one specified when -initWithFilePresenter: was invoked: - -relinquishPresentedItemToWriter: is sent to NSFilePresenters of the item and, if the item is in a file package, NSFilePresenters of the file package. If there are nested file packages then the message is sent to NSFilePresenters of all of them. - If NSFileCoordinatorWritingForDeleting, NSFileCoordinatorWritingForMoving, or NSFileCoordinatorWritingForReplacing is used and the item is a directory then -relinquishPresentedItemToWriter: is also sent to NSFilePresenters of each item contained by it. - If NSFileCoordinatorWritingForDeleting or NSFileCoordinatorWritingForReplacing is used then -accommodatePresentedItemDeletionWithCompletionHandler: is sent to NSFilePresenters of the item and, if the item is a directory, NSFilePresenters of each item contained by it. -accommodatePresentedSubitemDeletionAtURL:completionHandler: is sent to NSFilePresenters of each file package that contains the item. - When NSFileCoordinatorWritingForReplacing is used the the definition of "the item" depends on what happened while waiting for other writers. See the description of it above. - If NSFileCoordinatorWritingForMerging is used then -savePresentedItemChangesWithCompletionHandler: is sent to NSFilePresenters of the item and, if the item is in a file package, NSFilePresenters of the file package. If there are nested file packages then the message is sent to NSFilePresenters of all of them. For both coordinated reading and writing, if there are multiple NSFilePresenters involved then the order in which they are messaged is undefined. If an NSFilePresenter signals failure then waiting will fail and outError will be set to an NSError describing the failure.
         * @param intents Argument converted to the Objective-C parameter of the same role.
         * @param queue Argument converted to the Objective-C parameter of the same role.
         * @param accessor Argument converted to the Objective-C parameter of the same role.
         */
        void coordinate_access_with_intents(const std::vector<FileAccessIntent>& intents, const OperationQueue& queue, std::function<void(Error)> accessor) const;
        /**
         * @brief Calls `-[NSFileCoordinator coordinateReadingItemAtURL:options:error:byAccessor:]`.
         * @details The next four methods behave similarly to -coordinateAccessWithIntents:queue:byAccessor: with one or two NSFileAccessIntent objects with the following exceptions: Each of these methods wait synchronously on the same thread they were invoked on before invoking the passed-in accessor block on the same thread, instead of waiting asynchronously and scheduling invocation of the block on a specific queue. The accessor block of each of these methods is passed one or more URLs that locate the intended items, perhaps changed from the original URLs to take into account the fact that the item might have been moved or renamed during the waiting. Each of these methods returns an NSError by reference instead of passing it to the accessory block. However, these methods are uncommon among Cocoa framework methods in that they don't also return a result indicating success or failure. The success of the waiting that they do is typically not interesting to invokers. Only the success of file system access done by the passed-in block is interesting. (The failure of either is of course interesting.) When invoking these methods it's cleanest to just declare a block variable outside of the block and initialize it to a value that signals failure, and then inside the block set it to a value that signals success. If the waiting fails then the invoked method sets the error reference to an NSError that describes what went wrong, your block will not be invoked, your block variable will not be set to a value that signals success, and all will be as it should be, with failure signaled and an NSError that describes the failure.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param reader Argument converted to the Objective-C parameter of the same role.
         */
        void coordinate_reading_item_at_url(const URL& url, FileCoordinatorReadingOptions options, std::function<void(URL)> reader) const;
        /**
         * @brief Calls `-[NSFileCoordinator coordinateReadingItemAtURL:options:writingItemAtURL:options:error:byAccessor:]`.
         * @param reading_url Argument converted to the Objective-C parameter of the same role.
         * @param reading_options Argument converted to the Objective-C parameter of the same role.
         * @param writing_url Argument converted to the Objective-C parameter of the same role.
         * @param writing_options Argument converted to the Objective-C parameter of the same role.
         * @param reader_writer Argument converted to the Objective-C parameter of the same role.
         */
        void coordinate_reading_item_at_url(const URL& reading_url, FileCoordinatorReadingOptions reading_options, const URL& writing_url, FileCoordinatorWritingOptions writing_options, std::function<void(URL, URL)> reader_writer) const;
        /**
         * @brief Calls `-[NSFileCoordinator coordinateWritingItemAtURL:options:error:byAccessor:]`.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param writer Argument converted to the Objective-C parameter of the same role.
         */
        void coordinate_writing_item_at_url(const URL& url, FileCoordinatorWritingOptions options, std::function<void(URL)> writer) const;
        /**
         * @brief Calls `-[NSFileCoordinator coordinateWritingItemAtURL:options:writingItemAtURL:options:error:byAccessor:]`.
         * @param url1 Argument converted to the Objective-C parameter of the same role.
         * @param options1 Argument converted to the Objective-C parameter of the same role.
         * @param url2 Argument converted to the Objective-C parameter of the same role.
         * @param options2 Argument converted to the Objective-C parameter of the same role.
         * @param writer Argument converted to the Objective-C parameter of the same role.
         */
        void coordinate_writing_item_at_url(const URL& url1, FileCoordinatorWritingOptions options1, const URL& url2, FileCoordinatorWritingOptions options2, std::function<void(URL, URL)> writer) const;
        /**
         * @brief Calls `-[NSFileCoordinator itemAtURL:didChangeUbiquityAttributes:]`.
         * @details Announce that the item located by a URL has changed one or more ubiquity attributes. See NSFilePresenter.observedPresentedItemUbiquityAttributes for an explanation of valid attributes. This triggers the sending of messages to NSFilePresenters that implement -presentedItemDidChangeUbiquityAttibutes:, even those in other processes.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         */
        void item_at_url(const URL& url, const std::vector<std::string>& attributes) const;
        /**
         * @brief Calls `-[NSFileCoordinator itemAtURL:didMoveToURL:]`.
         * @details Announce that the item located by a URL is now located by another URL. This triggers the sending of messages to NSFilePresenters that implement the corresponding optional methods, even those in other processes, except the one specified when -initWithFilePresenter: was invoked: - -presentedItemDidMoveToURL: is sent to NSFilePresenters of the item. - If the item is a directory then -presentedItemDidMoveToURL: is sent to NSFilePresenters of each item contained by it. - -presentedSubitemAtURL:didMoveToURL: is sent to NSFilePresenters of each directory that contains the item, unless that method is not implemented but -presentedItemDidChange is, and the directory is actually a file package, in which case -presentedItemDidChange is sent instead. This also balances invocations of -itemAtURL:willMoveToURL:, as described above. Useless invocations of this method are harmless, so you don't have to write code that compares NSURLs for equality, which is not straightforward. This method must be invoked from within the block passed to an invocation of -coordinateAccessWithIntents:queue:byAccessory:, -coordinateWritingItemAtURL:options:error:byAccessor:, or -coordinateReadingItemAtURL:options:writingItemAtURL:options:error:byAccessor:.
         * @param old_url Argument converted to the Objective-C parameter of the same role.
         * @param new_url Argument converted to the Objective-C parameter of the same role.
         */
        void item_at_url(const URL& old_url, const URL& new_url) const;
        /**
         * @brief Calls `-[NSFileCoordinator prepareForReadingItemsAtURLs:options:writingItemsAtURLs:options:error:byAccessor:]`.
         * @details Prepare to more efficiently do a large number of invocations of -coordinate... methods, first synchronously messaging and waiting for NSFilePresenters in a variation of what individual invocations of the -coordinate... methods would do, and then, if no error occurs, invoke the passed-in block. The passed-in block must invoke the completion handler passed to it when all of the coordinated reading and writing it does is done. The completion handler block can be invoked on any thread (or from any dispatch queue, if that's how you think of it). This method returns errors in the same manner as the -coordinate... methods. The -coordinate... methods must use interprocess communication to message instances of NSFileCoordinator and NSFilePresenter in other processes in the system. That is an expense best avoided when reading or writing many files in one operation. Using this method can greatly reduce the amount of interprocess communication required by, for example, a large batched copying or moving of files. You use it by moving all of the invocations of the -coordinate... methods your application will do during a batch operation, or the scheduling of them if the operation's work is done in a multithreaded fashion, into a block and passing that block to an invocation of this method, remembering that the completion handler passed to that block must be invoked when the operation is done. You don't simply pass all URLs that will be passed into invocations of the -coordinate... methods when invoking this method. Instead you pass the top-level files and directories involved in the operation. This method triggers messages to not just NSFilePresenters of those items, but also NSFilePresenters of items contained by those items. For example, when Finder uses this method during a copy operation readingURLs is an array of the URLs of the exact files and folders that the user has selected, even though those folders may contain many files and subfolders for which Finder is going to do coordinated reading, and writingURLs is an array that contains just the URL of the destination folder. In most cases it is redundant to pass the same reading or writing options in an invocation of this method as are passed to individual invocations of the -coordinate... methods invoked by the block passed to an invocation of this method. For example, when Finder invokes this method during a copy operation it does not pass NSFileCoordinatorReadingWithoutChanges because it is appropriate to trigger the saving of document changes right away, but it does pass it when doing the nested invocations of -coordinate... methods because it is not necessary to trigger saving again, even if the user changes the document before the Finder proceeds far enough to actually copy that document's file.
         * @param reading_urls Argument converted to the Objective-C parameter of the same role.
         * @param reading_options Argument converted to the Objective-C parameter of the same role.
         * @param writing_urls Argument converted to the Objective-C parameter of the same role.
         * @param writing_options Argument converted to the Objective-C parameter of the same role.
         * @param batch_accessor Argument converted to the Objective-C parameter of the same role.
         */
        void prepare_for_reading_items_at_urls(const std::vector<URL>& reading_urls, FileCoordinatorReadingOptions reading_options, const std::vector<URL>& writing_urls, FileCoordinatorWritingOptions writing_options, std::function<void(std::function<void()>)> batch_accessor) const;
        /**
         * @brief Calls `+[NSFileCoordinator removeFilePresenter:]`.
         * @param file_presenter Argument converted to the Objective-C parameter of the same role.
         */
        static void remove_file_presenter(const Object& file_presenter);
        /**
         * @brief Returns the `filePresenters` property of `NSFileCoordinator`.
         * @return The converted Objective-C result.
         */
        static std::vector<Object> file_presenters();
        /**
         * @brief Returns the `purposeIdentifier` property of `NSFileCoordinator`.
         * @details A string that uniquely identifies the file access that will be done by this NSFileCoordinator. Every NSFileCoordinator has a unique purpose identifier that is created during initialization. Coordinated reads and writes performed by NSFileCoordinators with the same purpose identifier never block each other, even if they exist in different processes. In addition to some of the reasons explained in the comments of -initWithFilePresenter:, you may want to set a custom purpose identifier for the following reasons: - Your application has an NSFileProviderExtension. Any file coordination done on behalf of the NSFileProviderExtension needs to be done using the same purpose identifier reported by your NSFileProviderExtension. - To avoid deadlocking when two separate subsystems need to work together to perform one high-level operation, and both subsystems perform their own coordinated reads or writes. If you are coordinating file access on behalf of an NSFilePresenter, you should use -initWithFilePresenter: and should not attempt to set a custom purpose identifier. Every NSFileCoordinator instance initialized with the same NSFilePresenter will have the same purpose identifier. When creating custom purpose identifiers, you can use a reverse DNS style string, such as "com.mycompany.myapplication.mypurpose", or a UUID string. Nil and zero-length strings are not allowed. Purpose identifiers can be set only once. If you attempt to set the purpose identifier of an NSFileCoordinator that you initialized with -initWithFilePresenter: or that you already assigned a purpose identifier, an exception will be thrown.
         * @return The converted Objective-C result.
         */
        std::string purpose_identifier() const;
        /**
         * @brief Sets the `purposeIdentifier` property of `NSFileCoordinator`.
         * @details A string that uniquely identifies the file access that will be done by this NSFileCoordinator. Every NSFileCoordinator has a unique purpose identifier that is created during initialization. Coordinated reads and writes performed by NSFileCoordinators with the same purpose identifier never block each other, even if they exist in different processes. In addition to some of the reasons explained in the comments of -initWithFilePresenter:, you may want to set a custom purpose identifier for the following reasons: - Your application has an NSFileProviderExtension. Any file coordination done on behalf of the NSFileProviderExtension needs to be done using the same purpose identifier reported by your NSFileProviderExtension. - To avoid deadlocking when two separate subsystems need to work together to perform one high-level operation, and both subsystems perform their own coordinated reads or writes. If you are coordinating file access on behalf of an NSFilePresenter, you should use -initWithFilePresenter: and should not attempt to set a custom purpose identifier. Every NSFileCoordinator instance initialized with the same NSFilePresenter will have the same purpose identifier. When creating custom purpose identifiers, you can use a reverse DNS style string, such as "com.mycompany.myapplication.mypurpose", or a UUID string. Nil and zero-length strings are not allowed. Purpose identifiers can be set only once. If you attempt to set the purpose identifier of an NSFileCoordinator that you initialized with -initWithFilePresenter: or that you already assigned a purpose identifier, an exception will be thrown.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_purpose_identifier(const std::string& value) const;
    };
}
