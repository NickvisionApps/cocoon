#pragma once

#include "generated/availability.h"
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
         * @details \@method addBarrierBlock: \@param barrier A block to execute \@discussion The 'addBarrierBlock:' method executes the block when the NSOperationQueue has finished all enqueued operations and prevents any subsequent operations to be executed until the barrier has been completed. This acts similarly to the 'dispatch_barrier_async' function.
         * @param barrier Argument converted to the Objective-C parameter of the same role.
         */
        void add_barrier_block(std::function<void()> barrier) const;
        /**
         * @brief Calls `-[NSOperationQueue addOperation:]`.
         * @param op Argument converted to the Objective-C parameter of the same role.
         */
        void add_operation(const Operation& op) const;
        /**
         * @brief Calls `-[NSOperationQueue addOperationWithBlock:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void add_operation_with_block(std::function<void()> block) const;
        /**
         * @brief Calls `-[NSOperationQueue addOperations:waitUntilFinished:]`.
         * @param ops Argument converted to the Objective-C parameter of the same role.
         * @param wait Argument converted to the Objective-C parameter of the same role.
         */
        void add_operations(const std::vector<Operation>& ops, bool wait) const;
        /**
         * @brief Calls `-[NSOperationQueue cancelAllOperations]`.
         */
        void cancel_all_operations() const;
        /**
         * @brief Calls `-[NSOperationQueue waitUntilAllOperationsAreFinished]`.
         */
        void wait_until_all_operations_are_finished() const;
        /**
         * @brief Returns the `currentQueue` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        static OperationQueue current_queue();
        /**
         * @brief Returns the `mainQueue` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        static OperationQueue main_queue();
        /**
         * @brief Returns the `maxConcurrentOperationCount` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        std::int64_t max_concurrent_operation_count() const;
        /**
         * @brief Sets the `maxConcurrentOperationCount` property of `NSOperationQueue`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_concurrent_operation_count(std::int64_t value) const;
        /**
         * @brief Returns the `name` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSOperationQueue`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
        /**
         * @brief Returns the `operationCount` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        std::uint64_t operation_count() const;
        /**
         * @brief Returns the `operations` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        std::vector<Operation> operations() const;
        /**
         * @brief Returns the `progress` property of `NSOperationQueue`.
         * @details \@property progress \@discussion The 'progress' property represents a total progress of the operations executed in the queue. By default NSOperationQueue does not report progress until the 'totalUnitCount' of the progress is set. When the 'totalUnitCount' property of the progress is set the queue then opts into participating in progress reporting. When enabled, each operation will contribute 1 unit of completion to the overall progress of the queue for operations that are finished by the end of main (operations that override start and do not invoke super will not contribute to progress). Special attention to race conditions should be made when updating the 'totalUnitCount' of the progress as well as care should be taken to avoid 'backwards progress'. For example; when a NSOperationQueue's progress is 5/10, representing 50\% completed, and there are 90 more operations about to be added and the 'totalUnitCount' that would then make the progress report as 5/100 which represents 5\%. In this example it would mean that any progress bar would jump from displaying 50\% back to 5\%, which might not be desirable. In the cases where the 'totalUnitCount' needs to be adjusted it is suggested to do this for thread-safety in a barrier by using the 'addBarrierBlock:' API. This ensures that no un-expected execution state occurs adjusting into a potentially backwards moving progress scenario. \@example NSOperationQueue queue = [[NSOperationQueue alloc] init]; queue.progress.totalUnitCount = 10;
         * @return The converted Objective-C result.
         */
        Progress progress() const;
        /**
         * @brief Returns the `qualityOfService` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        QualityOfService quality_of_service() const;
        /**
         * @brief Sets the `qualityOfService` property of `NSOperationQueue`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_quality_of_service(QualityOfService value) const;
        /**
         * @brief Returns the `suspended` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        bool is_suspended() const;
        /**
         * @brief Sets the `suspended` property of `NSOperationQueue`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_suspended(bool value) const;
        /**
         * @brief Returns the `underlyingQueue` property of `NSOperationQueue`.
         * @return The converted Objective-C result.
         */
        Object underlying_queue() const;
        /**
         * @brief Sets the `underlyingQueue` property of `NSOperationQueue`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_underlying_queue(const Object& value) const;
    };
}
