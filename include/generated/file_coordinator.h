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
     * @details An object that coordinates the reading and writing of files and directories among file presenters. The ''NSFileCoordinator'' class coordinates the reading and writing of files and directories among multiple processes and objects in the same process. You use instances of this class as is to read from, write to, modify the attributes of, change the location of, or delete a file or directory, but before your code to perform those actions executes, the file coordinator lets registered file presenter objects perform any tasks that they might require to ensure their own integrity. For example, if you want to change the location of a file, other objects interested in that file need to know where you intend to move it so that they can update their references. Objects that adopt the ''NSFilePresenter'' protocol must register themselves with the ''NSFileCoordinator'' class to be notified of any pending changes. They do this by calling the ''addFilePresenter(:)'' class method. A file presenter must balance calls to ''addFilePresenter(:)'' with a call to ''removeFilePresenter(:)'' before being released, even in a garbage-collected application. The file presenter class maintains a list of active file presenter objects in the current application and uses that list, plus the file coordinator classes in other processes, to deliver notifications to all of the objects interested in a particular item. Instances of ''NSFileCoordinator'' are meant to be used on a per-file-operation basis, where a file operation is something like opening and reading the contents of a file or moving a batch of files and directories to a new location. There is no benefit to keeping a file coordinator object past the length of the planned operation. In fact, because file coordinators retain file presenter objects, keeping one around could prevent the file presenter objects from being released in a timely manner. For information about implementing a file presenter object to receive file-related notifications, see ''NSFilePresenter''. \#\#\# File Presenters and iOS If your app or extension enters the background with an active file presenter, it may be terminated by the system in order to prevent deadlock on that file. To prevent this situation, call ''removeFilePresenter(:)'' to remove the file presenter in the \<doc://com.apple.documentation/documentation/uikit/uiapplicationdelegate/applicationdidenterbackground(:)> method or in response to a \<doc://com.apple.documentation/documentation/uikit/uiapplication/didenterbackgroundnotification> notification. Call ''addFilePresenter(:)'' to add the file presenter again in the \<doc://com.apple.documentation/documentation/uikit/uiapplicationdelegate/applicationwillenterforeground(:)> method or in response to a \<doc://com.apple.documentation/documentation/uikit/uiapplication/willenterforegroundnotification> notification. > Note: > The \<doc://com.apple.documentation/documentation/uikit/uidocument> class automatically removes itself when your app goes to the background. It automatically adds itself again when your app returns to the foreground. \#\#\# File Coordinators and iOS A coordinated read or write will automatically begin a background task when granted, similar to one created with the \<doc://com.apple.documentation/documentation/uikit/uiapplication/beginbackgroundtask(expirationhandler:)> method. This helps ensure that your app or extension has sufficient time to finish the read or write operation if it's suspended, without creating a deadlock on access to that file by other processes. If a process is suspended while waiting for a coordinated read or write to be granted, the request is canceled, and an 'NSError' object with the code ''NSUserCancelledError-var'' is produced. If the background task expires, the process is terminated. > Note: > The \<doc://com.apple.documentation/documentation/uikit/uidocument> class automatically requests additional background time and safely performs coordinated reads and writes when loading and saving the document. \#\#\# Threading Considerations Each file coordinator object you create should be used on a single thread only. If you need to coordinate file operations across multiple objects in different threads, each object should create its own file coordinator.
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
     * @details Registers the specified file presenter object so that it can receive notifications. This method registers the file presenter object process wide. Thus, any file coordinator objects you create later automatically know about the file presenter object and know to message it when its file or directory is affected. Be sure to balance calls to this method with a corresponding call to +removeFilePresenter: before the file presenter is deallocated, even in a garbage-collected application. If you call this method while coordinated file operations are already under way in another process, your file presenter may not receive notifications for that operation. To prevent missing such notifications, create a file coordinator, call its -coordinateReadingItemAtURL:options:error:byAccessor: method, and register your file presenter object there. If you are going to read a file and then create a file presenter for that file, both actions should occur in the same coordinated read block. Synchronizing on the presented file or directory guarantees that when your block executes, all other objects have completed any tasks and you have sole access to the item.
     * @param file_presenter Argument converted to the Objective-C parameter of the same role.
     */
        static void add_file_presenter(const Object& file_presenter);
        /**
     * @brief Calls `-[NSFileCoordinator cancel]`.
     * @details Cancels any active file coordination calls. Use this method to cancel any active calls to coordinate the reading or writing of a file. If the block passed to the file coordination call has not yet been executed — perhaps because the file coordinator is still waiting for a response from other file presenters — the file coordinator method stops waiting for a response, does not execute its block, and returns an error object with the error code NSUserCancelledError. However, if the block is already being executed, the file coordinator method does not return until the block finishes executing. You can call this method from any thread of your application and it returns immediately without waiting for the file coordinator object to respond. Thus, when this method returns, you cannot assume that the read or write operation occurred or did not occur. If you want to know whether the operation actually occurred, you must track it yourself by setting a flag when the block starts executing or by using some other means.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSFileCoordinator coordinateAccessWithIntents:queue:byAccessor:]`.
     * @details Performs a number of coordinated-read or -write operations asynchronously. This method lets you asynchronously perform coordinated read or writes. You can specify any combination of individual read or write operations. The file coordinator waits asynchronously to get access to the files and then invokes the accessor block on the specified queue. If an error occurs while waiting for access, an error message is passed to the block. You must check the block's error parameter before accessing any of the files. If the error parameter is set to nil, you can freely perform the read and write operations described by your intents. Otherwise, you may not access the files. Additionally, always use the URL property on the NSFileAccessIntent objects when accessing the files inside the accessor block. The system updates this property to account for any changes to the underlying files. Your file coordinator has access to the files only until the accessor block returns. Do not dispatch tasks that continue to access these files onto other threads or queues. In general a coordinated reader waits for a coordinated writer of the same item, and a coordinated writer waits for coordinated readers and other coordinated writers of the same item. Coordinated readers do not wait for each other. Coordinated reading or writing of items in a file package is treated as coordinated reading or writing of the file package as a whole. Coordinated reads and writes from the same file coordinator instance never block each other. However, if you make multiple, concurrent calls to this method, you risk deadlocking with another process that is similarly making multiple concurrent calls. Wherever possible, invoke this method once with multiple file access intent objects.
     * @param intents Argument converted to the Objective-C parameter of the same role.
     * @param queue Argument converted to the Objective-C parameter of the same role.
     * @param accessor Argument converted to the Objective-C parameter of the same role.
     */
        void coordinate_access_with_intents(const std::vector<FileAccessIntent>& intents, const OperationQueue& queue, std::function<void(Error)> accessor) const;
        /**
     * @brief Calls `-[NSFileCoordinator coordinateReadingItemAtURL:options:error:byAccessor:]`.
     * @details Initiates a read operation on a single file or directory using the specified options. This method executes synchronously, blocking the current thread until the reader block finishes executing. Before executing that block, the file coordinator waits until other relevant file presenter objects finish in-progress actions. When invoking these methods, declare a block variable before the accessor block and initialize it to a value that signals failure, and then inside the accessor block set it to a value that indicates success. If the coordinated operation fails, then the accessor block never runs and the NSError out parameter contains a reference that describes the error. This method calls the -relinquishPresentedItemToReader: method of any relevant file presenters. Depending on the options you specify, other methods of the file presenters may also be called. All of the called methods must return successfully before the file coordinator executes your block. If multiple file presenters are operating on the item, the order in which those presenters are notified is undefined. If the device has not yet downloaded the file at the given URL, this method blocks (potentially for a long time) while the file is downloaded.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param reader Argument converted to the Objective-C parameter of the same role.
     */
        void coordinate_reading_item_at_url(const URL& url, FileCoordinatorReadingOptions options, std::function<void(URL)> reader) const;
        /**
     * @brief Calls `-[NSFileCoordinator coordinateReadingItemAtURL:options:writingItemAtURL:options:error:byAccessor:]`.
     * @details Initiates a read operation that contains a follow-up write operation. You use this method to perform a read operation that might also contain a write operation that needs to be coordinated. This method executes synchronously, blocking the current thread until the readerWriter block finishes executing. When performing the write operation, you may call -coordinateWritingItemAtURL:options:error:byAccessor: from your readerWriter block. This method does the canonical lock ordering that is required to prevent a potential deadlock of the file operations. When invoking this method, declare a block variable before the accessor block and initialize it to a value that signals failure, and then inside the accessor block set it to a value that indicates success. If the coordinated operation fails, then the accessor block never runs and the NSError out parameter contains a reference that describes the error. This method makes the same calls to file presenters, and has the same general wait behavior, as the -coordinateReadingItemAtURL:options:error:byAccessor: and -coordinateWritingItemAtURL:options:error:byAccessor: methods.
     * @param reading_url Argument converted to the Objective-C parameter of the same role.
     * @param reading_options Argument converted to the Objective-C parameter of the same role.
     * @param writing_url Argument converted to the Objective-C parameter of the same role.
     * @param writing_options Argument converted to the Objective-C parameter of the same role.
     * @param reader_writer Argument converted to the Objective-C parameter of the same role.
     */
        void coordinate_reading_item_at_url(const URL& reading_url, FileCoordinatorReadingOptions reading_options, const URL& writing_url, FileCoordinatorWritingOptions writing_options, std::function<void(URL, URL)> reader_writer) const;
        /**
     * @brief Calls `-[NSFileCoordinator coordinateWritingItemAtURL:options:error:byAccessor:]`.
     * @details Initiates a write operation on a single file or directory using the specified options. This method executes synchronously, blocking the current thread until the writer block finishes executing. Before executing the block, the file coordinator waits until other relevant file presenter objects finish in-progress actions. When invoking this method, declare a block variable before the accessor block and initialize it to a value that signals failure, and then inside the accessor block set it to a value that indicates success. If the coordinated operation fails, then the accessor block never runs and the NSError out parameter contains a reference that describes the error. This method calls the -relinquishPresentedItemToWriter: method of any relevant file presenters. Depending on the options you specify, other methods of the file presenters may also be called. All of the called methods must return successfully before the file coordinator executes your block. With one exception, do not nest calls to file coordinator methods inside the block you pass to this method. You may call -coordinateReadingItemAtURL:options:error:byAccessor: to read the file if you discover through modification-date checking that the contents of the file have changed. However, if you call this method from inside your block, the file coordinator object throws an exception.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param writer Argument converted to the Objective-C parameter of the same role.
     */
        void coordinate_writing_item_at_url(const URL& url, FileCoordinatorWritingOptions options, std::function<void(URL)> writer) const;
        /**
     * @brief Calls `-[NSFileCoordinator coordinateWritingItemAtURL:options:writingItemAtURL:options:error:byAccessor:]`.
     * @details Initiates a write operation that involves a secondary write operation. You use this method to perform two write operations without the risk of those operations creating a deadlock. This method executes synchronously, blocking the current thread until the writer block finishes executing. You may call -coordinateWritingItemAtURL:options:error:byAccessor: from your writer block. This method does the canonical lock ordering that is required to prevent a potential deadlock of the file operations. When invoking this method, declare a block variable before the accessor block and initialize it to a value that signals failure, and then inside the accessor block set it to a value that indicates success. If the coordinated operation fails, then the accessor block never runs and the NSError out parameter contains a reference that describes the error. This method makes the same calls to file presenters, and has the same general wait behavior, as the -coordinateWritingItemAtURL:options:error:byAccessor: method.
     * @param url1 Argument converted to the Objective-C parameter of the same role.
     * @param options1 Argument converted to the Objective-C parameter of the same role.
     * @param url2 Argument converted to the Objective-C parameter of the same role.
     * @param options2 Argument converted to the Objective-C parameter of the same role.
     * @param writer Argument converted to the Objective-C parameter of the same role.
     */
        void coordinate_writing_item_at_url(const URL& url1, FileCoordinatorWritingOptions options1, const URL& url2, FileCoordinatorWritingOptions options2, std::function<void(URL, URL)> writer) const;
        /**
     * @brief Calls `-[NSFileCoordinator itemAtURL:didChangeUbiquityAttributes:]`.
     * @details Tells observing file providers that the item's ubiquity attributes have changed. This triggers the -presentedItemDidChangeUbiquityAttributes: method on any file presenters that are observing the item, even if they are running in different processes. See NSFilePresenter's observedPresentedItemUbiquityAttributes property for an explanation of valid attributes.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     */
        void item_at_url(const URL& url, const std::vector<std::string>& attributes) const;
        /**
     * @brief Calls `-[NSFileCoordinator itemAtURL:didMoveToURL:]`.
     * @details Notifies relevant file presenters that the location of a file or directory changed. If you move or rename a file or directory as part of a write operation, call this method to notify relevant file presenters that the change occurred. This method calls -presentedItemDidMoveToURL: for any of the item's file presenters. If the item is a directory, this method calls -presentedItemDidMoveToURL: on the file presenters for the item's contents. Finally, it calls -presentedSubitemAtURL:didMoveToURL: on the file presenter of any directory containing the item. You must call this method from a coordinated write block. Calling this method with the same URL in the oldURL and newURL parameters is harmless. This call must balance a call to -itemAtURL:willMoveToURL:.
     * @param old_url Argument converted to the Objective-C parameter of the same role.
     * @param new_url Argument converted to the Objective-C parameter of the same role.
     */
        void item_at_url(const URL& old_url, const URL& new_url) const;
        /**
     * @brief Calls `-[NSFileCoordinator prepareForReadingItemsAtURLs:options:writingItemsAtURLs:options:error:byAccessor:]`.
     * @details Prepare to read or write from multiple files in a single batch operation. Use this method to prepare the file coordinator for multiple read and write operations. Because file coordination requires interprocess communication, it is much more efficient to batch changes to large numbers of files and directories than to change each item individually. The file coordinator uses the values in the readingURLs and writingURLs parameters, together with reading and writing options, to prepare any relevant file presenters for the upcoming operations. This method executes synchronously, blocking the current thread until the batchAccessor block finishes executing. The batchAccessor block you provide does not have exclusive access to the given items when it is invoked. Instead, you must call coordinated read and write methods for each individual item from inside the batchAccessor block. You must then call the completion handler after all the coordinated reads and writes have completed. You can call the completion handler from any thread. Don't simply pass this method all the URLs that are passed into the nested coordinate methods. Instead pass only the top-level files and directories involved in the operation. This method triggers messages to the file presenters of those items and to the file presenters of any items contained by those items. In most cases, passing the same reading and writing options to both this method and the contained coordination operations is redundant.
     * @param reading_urls Argument converted to the Objective-C parameter of the same role.
     * @param reading_options Argument converted to the Objective-C parameter of the same role.
     * @param writing_urls Argument converted to the Objective-C parameter of the same role.
     * @param writing_options Argument converted to the Objective-C parameter of the same role.
     * @param batch_accessor Argument converted to the Objective-C parameter of the same role.
     */
        void prepare_for_reading_items_at_urls(const std::vector<URL>& reading_urls, FileCoordinatorReadingOptions reading_options, const std::vector<URL>& writing_urls, FileCoordinatorWritingOptions writing_options, std::function<void(std::function<void()>)> batch_accessor) const;
        /**
     * @brief Calls `+[NSFileCoordinator removeFilePresenter:]`.
     * @details Unregisters the specified file presenter object. Call this method to unregister file presenters before those objects are deallocated.
     * @param file_presenter Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_file_presenter(const Object& file_presenter);
        /**
     * @brief Returns the `filePresenters` property of `NSFileCoordinator`.
     * @details Returns an array containing the process's currently registered file presenter objects.
     * @return The converted Objective-C result.
     */
        static std::vector<Object> file_presenters();
        /**
     * @brief Returns the `purposeIdentifier` property of `NSFileCoordinator`.
     * @details A string that uniquely identifies the file access that was performed by this file coordinator. Every NSFileCoordinator has a unique purpose identifier that is created during initialization. Coordinated reads and writes performed by NSFileCoordinators with the same purpose identifier never block each other, even if they exist in different processes. If you are coordinating file access on behalf of a file presenter, use -initWithFilePresenter: and do not attempt to set a custom purpose identifier. Every file coordinator instance initialized with the same file presenter has the same purpose identifier. You may need to set a custom purpose identifier for the following reasons: - Your application has a File Provider extension. Any file coordination done on behalf of the File Provider needs to be done using the File Provider's purpose identifier. - You have two separate subsystems that need to work together to perform a single high-level operation, and both subsystems perform their own coordinated reads or writes. Using the same purpose identifier in both subsystems prevents possible deadlocks between the two subsystems. When creating custom purpose identifiers, you can use a reverse DNS style string, such as "com.mycompany.myapplication.mypurpose", or a UUID string. Nil and zero-length strings are not allowed. Purpose identifiers can be set only once. If you attempt to set the purpose identifier of an NSFileCoordinator that you initialized with -initWithFilePresenter: or that you already assigned a purpose identifier, an exception will be thrown.
     * @return The converted Objective-C result.
     */
        std::string purpose_identifier() const;
        /**
     * @brief Sets the `purposeIdentifier` property of `NSFileCoordinator`.
     * @details A string that uniquely identifies the file access that was performed by this file coordinator. Every NSFileCoordinator has a unique purpose identifier that is created during initialization. Coordinated reads and writes performed by NSFileCoordinators with the same purpose identifier never block each other, even if they exist in different processes. If you are coordinating file access on behalf of a file presenter, use -initWithFilePresenter: and do not attempt to set a custom purpose identifier. Every file coordinator instance initialized with the same file presenter has the same purpose identifier. You may need to set a custom purpose identifier for the following reasons: - Your application has a File Provider extension. Any file coordination done on behalf of the File Provider needs to be done using the File Provider's purpose identifier. - You have two separate subsystems that need to work together to perform a single high-level operation, and both subsystems perform their own coordinated reads or writes. Using the same purpose identifier in both subsystems prevents possible deadlocks between the two subsystems. When creating custom purpose identifiers, you can use a reverse DNS style string, such as "com.mycompany.myapplication.mypurpose", or a UUID string. Nil and zero-length strings are not allowed. Purpose identifiers can be set only once. If you attempt to set the purpose identifier of an NSFileCoordinator that you initialized with -initWithFilePresenter: or that you already assigned a purpose identifier, an exception will be thrown.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_purpose_identifier(const std::string& value) const;
    };
}
