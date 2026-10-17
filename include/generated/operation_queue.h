#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Operation;
    class Progress;

    /**
     * @brief C++ handle for the Objective-C class `NSOperationQueue` (Foundation).
     * @details A queue that regulates the execution of operations. An operation queue invokes its queued ''Operation'' objects based on their priority and readiness. After you add an operation to a queue, it remains in the queue until the operation finishes its task. You can't directly remove an operation from a queue after you add it. > Note: > Operation queues retain operations until the operations finish, and queues themselves are retained until all operations are finished. Suspending an operation queue with operations that aren't finished can result in a memory leak. For more information about using operation queues, see the [Concurrency Programming Guide](https://developer.apple.com/library/archive/documentation/General/Conceptual/ConcurrencyProgrammingGuide/Introduction/Introduction.html\#//apple_ref/doc/uid/TP40008091). \#\#\# Determine the Execution Order An operation queue organizes and invokes its operations according to their readiness, priority level, and interoperation dependencies. If all of the queued operations have the same ''Operation/queuePriority'' and the ''Operation/isReady'' property returns \<doc://com.apple.documentation/documentation/swift/true>, the queue invokes them in the order you added them. Otherwise, the operation queue always invokes the operation with the highest priority relative to the other ready operations. However, don't rely on queue semantics to ensure a specific execution order of operations because changes in the readiness of an operation can change the resulting execution order. Interoperation dependencies provide an absolute execution order for operations, even if those operations are located in different operation queues. An operation object isn't ready to run until all of its dependent operations have finished running. For details on how to set priority levels and dependencies, see Managing Dependencies in ''Operation''. \#\#\# Respond to Operation Cancelation Finishing its task doesn't necessarily mean that the operation performed that task to completion; an operation can also be canceled. Canceling an operation object leaves the object in the queue but notifies the object that it should stop its task as quickly as possible. For currently executing operations, this means that the operation object's work code must check the cancellation state, stop what it is doing, and mark itself as finished. For operations that are queued but not yet executing, the queue must still call the operation object's ''Operation/start()'' method so that it can processes the cancellation event and mark itself as finished. > Note: > Canceling an operation causes the operation to ignore any dependencies it may have. This behavior makes it possible for the queue to invoke the operation's ''Operation/start()'' method as soon as possible. The ''Operation/start()'' method, in turn, moves the operation to the finished state so that it can be removed from the queue. For more information about operation cancellation, see \<doc:Operation\#Responding-to-the-Cancel-Command> in ''Operation''. \#\#\# Observe Operations Using Key-Value Observing The ''OperationQueue'' class is key-value coding (KVC) and key-value observing (KVO) compliant. You can observe these properties to control other parts of your application. To observe the properties, use the following key paths: - ''operations'' — Read-only - ''operationCount'' — Read-only - ''maxConcurrentOperationCount'' — Readable and writable - ''isSuspended'' — Readable and writable - ''name'' — Readable and writable Although you can attach observers to these properties, don't use Cocoa bindings to bind these properties to elements of your application's user interface. Code associated with your user interface typically must run only in your app's main thread. However, KVO notifications associated with an operation queue may occur in any thread. For more information about KVO and how to attach observers to an object, see the [Key-Value Observing Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/KeyValueObserving/KeyValueObserving.html\#//apple_ref/doc/uid/10000177i). \#\#\# Plan for Thread Safety You can safely use a single ''OperationQueue'' object from multiple threads without creating additional locks to synchronize access to that object. Operation queues use the \<doc://com.apple.documentation/documentation/dispatch> framework to initiate the execution of their operations. As a result, queues always invoke operations on a separate thread, regardless of whether the operation is synchronous or asynchronous.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::OperationQueue operation_queue;
     * operation_queue.set_max_concurrent_operation_count(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::OperationQueue operation_queue{};
     * operation_queue.set_max_concurrent_operation_count(1);
     * auto max_concurrent_operation_count = operation_queue.max_concurrent_operation_count();
     * operation_queue.set_name("text");
     * auto name = operation_queue.name();
     * operation_queue.set_quality_of_service(cocoon::QualityOfService::UserInteractive);
     * auto quality_of_service = operation_queue.quality_of_service();
     * operation_queue.add_operation(cocoon::Operation());
     * operation_queue.cancel_all_operations();
     * operation_queue.wait_until_all_operations_are_finished();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsoperationqueue
     */
    class OperationQueue : public Object
    {
    public:
        /// @brief Creates a new `NSOperationQueue` instance and returns a handle to it.
        explicit OperationQueue();
        /// @brief Creates a null handle that refers to no native object.
        OperationQueue(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit OperationQueue(Adopt adopt);
        /**
     * @brief Calls `-[NSOperationQueue addBarrierBlock:]`.
     * @details Invokes a block when the queue finishes all enqueued operations, and prevents subsequent operations from starting until the block has completed. This method is similar to 'dispatch_barrier_async'. - Parameters: - barrier: The block to invoke after all currently enqueued operations have finished. Operations you add after the barrier block don't start until the block has completed.
     * @param barrier Argument converted to the Objective-C parameter of the same role.
     */
        void add_barrier_block(std::function<void()> barrier) const;
        /**
     * @brief Calls `-[NSOperationQueue addOperation:]`.
     * @details Adds the specified operation to the receiver. Once added, the specified operation remains in the queue until it finishes executing. An operation object can be in at most one operation queue at a time and this method throws an 'NSInvalidArgumentException' exception if the operation is already in another queue. Similarly, this method throws an 'NSInvalidArgumentException' exception if the operation is currently executing or has already finished executing. - Parameter op: The operation to be added to the queue.
     * @param op Argument converted to the Objective-C parameter of the same role.
     */
        void add_operation(const Operation& op) const;
        /**
     * @brief Calls `-[NSOperationQueue addOperationWithBlock:]`.
     * @details Wraps the specified block in an operation and adds it to the receiver. This method adds a single block to the receiver by first wrapping it in an operation object. You should not attempt to get a reference to the newly created operation object or determine its type information. - Parameter block: The block to execute from the operation. The block takes no parameters and has no return value.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void add_operation_with_block(std::function<void()> block) const;
        /**
     * @brief Calls `-[NSOperationQueue addOperations:waitUntilFinished:]`.
     * @details Adds the specified operations to the queue. An operation object can be in at most one operation queue at a time and cannot be added if it is currently executing or finished. This method throws an 'NSInvalidArgumentException' exception if any of those error conditions are true for any of the operations in the 'ops' parameter. - Parameters: - ops: The operations to be added to the queue. - wait: If 'YES', the current thread is blocked until all of the specified operations finish executing. If 'NO', the operations are added to the queue and control returns immediately to the caller.
     * @param ops Argument converted to the Objective-C parameter of the same role.
     * @param wait Argument converted to the Objective-C parameter of the same role.
     */
        void add_operations(const std::vector<Operation>& ops, bool wait) const;
        /**
     * @brief Calls `-[NSOperationQueue cancelAllOperations]`.
     * @details Cancels all queued and executing operations. This method calls the 'cancel' method on all operations currently in the queue. Canceling the operations does not automatically remove them from the queue or stop those that are currently executing. For operations that are queued and waiting execution, the queue must still attempt to execute the operation before recognizing that it is canceled and moving it to the finished state. For operations that are already executing, the operation object itself must check for cancellation and stop what it is doing so that it can move to the finished state.
     */
        void cancel_all_operations() const;
        /**
     * @brief Calls `-[NSOperationQueue waitUntilAllOperationsAreFinished]`.
     * @details Blocks the current thread until all the receiver's queued and executing operations finish executing. When called, this method blocks the current thread and waits for the receiver's current and queued operations to finish executing. While the current thread is blocked, the receiver continues to launch already queued operations and monitor those that are executing. During this time, the current thread cannot add operations to the queue, but other threads may. Once all of the pending operations are finished, this method returns. If there are no operations in the queue, this method returns immediately.
     */
        void wait_until_all_operations_are_finished() const;
        /**
     * @brief Returns the `currentQueue` property of `NSOperationQueue`.
     * @details Returns the operation queue that launched the current operation. You can use this method from within a running operation object to get a reference to the operation queue that started it. Calling this method from outside the context of a running operation typically results in 'nil' being returned.
     * @return The converted Objective-C result.
     */
        static OperationQueue current_queue();
        /**
     * @brief Returns the `mainQueue` property of `NSOperationQueue`.
     * @details Returns the operation queue associated with the main thread. The returned queue executes one operation at a time on the app's main thread. The execution of operations on the main thread is interleaved with the other tasks that must execute on the main thread, such as the servicing of events and the updating of an app's user interface.
     * @return The converted Objective-C result.
     */
        static OperationQueue main_queue();
        /**
     * @brief Returns the `maxConcurrentOperationCount` property of `NSOperationQueue`.
     * @details The maximum number of queued operations that can run at the same time. The value in this property affects only the operations that the current queue has executing at the same time. Other operation queues can also execute their maximum number of operations in parallel. Reducing the number of concurrent operations does not affect any operations that are currently executing. Specifying the value 'NSOperationQueueDefaultMaxConcurrentOperationCount' (which is recommended) causes the system to set the maximum number of operations based on system conditions. The default value of this property is ''NSOperationQueueDefaultMaxConcurrentOperationCount''.
     * @return The converted Objective-C result.
     */
        std::int64_t max_concurrent_operation_count() const;
        /**
     * @brief Sets the `maxConcurrentOperationCount` property of `NSOperationQueue`.
     * @details The maximum number of queued operations that can run at the same time. The value in this property affects only the operations that the current queue has executing at the same time. Other operation queues can also execute their maximum number of operations in parallel. Reducing the number of concurrent operations does not affect any operations that are currently executing. Specifying the value 'NSOperationQueueDefaultMaxConcurrentOperationCount' (which is recommended) causes the system to set the maximum number of operations based on system conditions. The default value of this property is ''NSOperationQueueDefaultMaxConcurrentOperationCount''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_concurrent_operation_count(std::int64_t value) const;
        /**
     * @brief Returns the `name` property of `NSOperationQueue`.
     * @details The name of the operation queue. Names provide a way for you to identify your operation queues at run time. Tools may also use this name to provide additional context during debugging or analysis of your code. The default value of this property is a string containing the memory address of the operation queue.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSOperationQueue`.
     * @details The name of the operation queue. Names provide a way for you to identify your operation queues at run time. Tools may also use this name to provide additional context during debugging or analysis of your code. The default value of this property is a string containing the memory address of the operation queue.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `operationCount` property of `NSOperationQueue`.
     * @details The number of operations currently in the queue. Because the number of operations in the queue changes as those operations finish executing, the value returned by this property reflects the instantaneous number of operations at the time the property was accessed. By the time you use the value, the actual number of operations may be different. As a result, do not use this value for object enumerations or other precise calculations.
     * @return The converted Objective-C result.
     */
        std::uint64_t operation_count() const;
        /**
     * @brief Returns the `operations` property of `NSOperationQueue`.
     * @details The operations currently in the queue. The array in this property contains zero or more 'NSOperation' objects in the order you added them to the queue. This order doesn't necessarily reflect the order in which the queue invokes those operations.
     * @return The converted Objective-C result.
     */
        std::vector<Operation> operations() const;
        /**
     * @brief Returns the `progress` property of `NSOperationQueue`.
     * @details An object that represents the total progress of the operations executing in the queue. By default, ''NSOperationQueue'' doesn't report progress until the 'totalUnitCount' of the progress is set. When 'totalUnitCount' is set, the queue begins reporting progress. Each operation in the queue contributes one unit of completion to the overall progress of the queue for operations that are finished by the end of 'main'. Operations that override 'start' and don't invoke super don't contribute to the queue's progress. > Warning: > Be careful to avoid race conditions and backward progress when updating 'totalUnitCount'. Consider a queue with a progress that has a 'completedUnitCount' equal to '5' and a 'totalUnitCount' equal to '10', representing 50\% completion. If you add 90 more operations to the queue, the 'totalUnitCount' is now '100', and the progress completion reports 5\%. If the progress object is connected to a progress bar, the bar would visibly jump backward from 50\% to 5\%, which may not be desirable. To update 'totalUnitCount' in a thread-safe manner, use the 'addBarrierBlock:' method. This method ensures that the operation queue completes the operations in the queue, preventing an inadvertent backward jump in progress.
     * @return The converted Objective-C result.
     */
        Progress progress() const;
        /**
     * @brief Returns the `qualityOfService` property of `NSOperationQueue`.
     * @details The default service level to apply to operations that the queue invokes. This property specifies the service level applied to operation objects added to the queue. If the operation object has an explicit service level set, that value is used instead. For queues you create yourself, the default value is 'NSOperationQualityOfServiceBackground'. For the queue returned by the 'mainQueue' method, the default value is 'NSOperationQualityOfServiceUserInteractive' and cannot be changed.
     * @return The converted Objective-C result.
     */
        QualityOfService quality_of_service() const;
        /**
     * @brief Sets the `qualityOfService` property of `NSOperationQueue`.
     * @details The default service level to apply to operations that the queue invokes. This property specifies the service level applied to operation objects added to the queue. If the operation object has an explicit service level set, that value is used instead. For queues you create yourself, the default value is 'NSOperationQualityOfServiceBackground'. For the queue returned by the 'mainQueue' method, the default value is 'NSOperationQualityOfServiceUserInteractive' and cannot be changed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quality_of_service(QualityOfService value) const;
        /**
     * @brief Returns the `suspended` property of `NSOperationQueue`.
     * @details A Boolean value indicating whether the queue is actively scheduling operations for execution. When the value of this property is 'NO', the queue actively starts operations that are in the queue and ready to execute. Setting this property to 'YES' prevents the queue from starting any queued operations, but already executing operations continue to execute. You may continue to add operations to a queue that is suspended but those operations are not scheduled for execution until you change this property to 'NO'. Operations are removed from the queue only when they finish executing. However, in order to finish executing, an operation must first be started. Because a suspended queue does not start any new operations, it does not remove any operations (including cancelled operations) that are currently queued and not executing. The default value of this property is 'NO'.
     * @return The converted Objective-C result.
     */
        bool is_suspended() const;
        /**
     * @brief Sets the `suspended` property of `NSOperationQueue`.
     * @details A Boolean value indicating whether the queue is actively scheduling operations for execution. When the value of this property is 'NO', the queue actively starts operations that are in the queue and ready to execute. Setting this property to 'YES' prevents the queue from starting any queued operations, but already executing operations continue to execute. You may continue to add operations to a queue that is suspended but those operations are not scheduled for execution until you change this property to 'NO'. Operations are removed from the queue only when they finish executing. However, in order to finish executing, an operation must first be started. Because a suspended queue does not start any new operations, it does not remove any operations (including cancelled operations) that are currently queued and not executing. The default value of this property is 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_suspended(bool value) const;
        /**
     * @brief Returns the `underlyingQueue` property of `NSOperationQueue`.
     * @details The dispatch queue that the operation queue uses to invoke operations. The default value of this property is 'nil'. You can set the value of this property to an existing dispatch queue to have enqueued operations interspersed with blocks submitted to that dispatch queue. The value of this property should only be set if there are no operations in the queue; setting the value of this property when 'operationCount' is not equal to '0' raises an 'NSInvalidArgumentException'. The value of this property must not be the value returned by 'dispatch_get_main_queue'. The quality-of-service level set for the underlying dispatch queue overrides any value set for the operation queue's 'qualityOfService' property.
     * @return The converted Objective-C result.
     */
        Object underlying_queue() const;
        /**
     * @brief Sets the `underlyingQueue` property of `NSOperationQueue`.
     * @details The dispatch queue that the operation queue uses to invoke operations. The default value of this property is 'nil'. You can set the value of this property to an existing dispatch queue to have enqueued operations interspersed with blocks submitted to that dispatch queue. The value of this property should only be set if there are no operations in the queue; setting the value of this property when 'operationCount' is not equal to '0' raises an 'NSInvalidArgumentException'. The value of this property must not be the value returned by 'dispatch_get_main_queue'. The quality-of-service level set for the underlying dispatch queue overrides any value set for the operation queue's 'qualityOfService' property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_underlying_queue(const Object& value) const;
    };
}
