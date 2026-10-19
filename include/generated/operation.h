#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSOperation` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Operation operation;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Operation operation{};
     * operation.set_name("text");
     * auto name = operation.name();
     * operation.set_quality_of_service(cocoon::QualityOfService::UserInteractive);
     * auto quality_of_service = operation.quality_of_service();
     * operation.set_queue_priority(cocoon::OperationQueuePriority::VeryLow);
     * auto queue_priority = operation.queue_priority();
     * operation.add_dependency(cocoon::Operation());
     * operation.cancel();
     * operation.remove_dependency(cocoon::Operation());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsoperation
     */
    class Operation : public Object
    {
    public:
        /// @brief Creates a new `NSOperation` instance and returns a handle to it.
        explicit Operation();
        /// @brief Creates a null handle that refers to no native object.
        Operation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Operation(Adopt adopt);
        /**
     * @brief Calls `-[NSOperation addDependency:]`.
     * @param op Argument converted to the Objective-C parameter of the same role.
     */
        void add_dependency(const Operation& op) const;
        /**
     * @brief Calls `-[NSOperation cancel]`.
     */
        void cancel() const;
        /**
     * @brief Calls `-[NSOperation main]`.
     */
        void main_() const;
        /**
     * @brief Calls `-[NSOperation removeDependency:]`.
     * @param op Argument converted to the Objective-C parameter of the same role.
     */
        void remove_dependency(const Operation& op) const;
        /**
     * @brief Calls `-[NSOperation start]`.
     */
        void start() const;
        /**
     * @brief Calls `-[NSOperation waitUntilFinished]`.
     */
        void wait_until_finished() const;
        /**
     * @brief Returns the `asynchronous` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_asynchronous() const;
        /**
     * @brief Returns the `cancelled` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_cancelled() const;
        /**
     * @brief Returns the `completionBlock` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        std::function<void()> completion_block() const;
        /**
     * @brief Sets the `completionBlock` property of `NSOperation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completion_block(std::function<void()> value) const;
        /**
     * @brief Returns the `concurrent` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_concurrent() const;
        /**
     * @brief Returns the `dependencies` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        std::vector<Operation> dependencies() const;
        /**
     * @brief Returns the `executing` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_executing() const;
        /**
     * @brief Returns the `finished` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_finished() const;
        /**
     * @brief Returns the `name` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSOperation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `qualityOfService` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        QualityOfService quality_of_service() const;
        /**
     * @brief Sets the `qualityOfService` property of `NSOperation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_quality_of_service(QualityOfService value) const;
        /**
     * @brief Returns the `queuePriority` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        OperationQueuePriority queue_priority() const;
        /**
     * @brief Sets the `queuePriority` property of `NSOperation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_queue_priority(OperationQueuePriority value) const;
        /**
     * @brief Returns the `ready` property of `NSOperation`.
     * @return The converted Objective-C result.
     */
        bool is_ready() const;
    };
}
