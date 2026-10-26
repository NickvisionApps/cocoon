#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSThread` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Thread thread;
     * thread.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Thread thread{};
     * thread.set_name("text");
     * auto name = thread.name();
     * thread.set_quality_of_service(cocoon::QualityOfService::UserInteractive);
     * auto quality_of_service = thread.quality_of_service();
     * thread.set_stack_size(1);
     * auto stack_size = thread.stack_size();
     * thread.cancel();
     * thread.start();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsthread
     */
    class Thread : public Object
    {
    public:
        /// @brief Creates a new `NSThread` instance and returns a handle to it.
        explicit Thread(std::function<void()> block);
        /// @brief Creates a new `NSThread` instance and returns a handle to it.
        explicit Thread(const Object& target, const std::string& selector, const Object& argument);
        /// @brief Creates a new `NSThread` instance and returns a handle to it.
        explicit Thread();
        /// @brief Creates a null handle that refers to no native object.
        Thread(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Thread(Adopt adopt);
        /**
         * @brief Calls `-[NSThread cancel]`.
         */
        void cancel() const;
        /**
         * @brief Calls `+[NSThread detachNewThreadSelector:toTarget:withObject:]`.
         * @param selector Argument converted to the Objective-C parameter of the same role.
         * @param target Argument converted to the Objective-C parameter of the same role.
         * @param argument Argument converted to the Objective-C parameter of the same role.
         */
        static void detach_new_thread_selector(const std::string& selector, const Object& target, const Object& argument);
        /**
         * @brief Calls `+[NSThread detachNewThreadWithBlock:]`.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        static void detach_new_thread_with_block(std::function<void()> block);
        /**
         * @brief Calls `+[NSThread exit]`.
         */
        static void exit();
        /**
         * @brief Calls `+[NSThread isMultiThreaded]`.
         * @return The converted Objective-C result.
         */
        static bool is_multi_threaded();
        /**
         * @brief Calls `-[NSThread main]`.
         */
        void main_() const;
        /**
         * @brief Calls `+[NSThread sleepForTimeInterval:]`.
         * @param ti Argument converted to the Objective-C parameter of the same role.
         */
        static void sleep_for_time_interval(double ti);
        /**
         * @brief Calls `+[NSThread sleepUntilDate:]`.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        static void sleep_until_date(const Date& date);
        /**
         * @brief Calls `-[NSThread start]`.
         */
        void start() const;
        /**
         * @brief Returns the `callStackReturnAddresses` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        static std::vector<Number> call_stack_return_addresses();
        /**
         * @brief Returns the `callStackSymbols` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> call_stack_symbols();
        /**
         * @brief Returns the `cancelled` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        bool is_cancelled() const;
        /**
         * @brief Returns the `currentThread` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        static Thread current_thread();
        /**
         * @brief Returns the `executing` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        bool is_executing() const;
        /**
         * @brief Returns the `finished` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        bool is_finished() const;
        /**
         * @brief Returns the `isMainThread` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        bool is_main_thread() const;
        /**
         * @brief Returns the `mainThread` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        static Thread main_thread();
        /**
         * @brief Returns the `name` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSThread`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
        /**
         * @brief Returns the `qualityOfService` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        QualityOfService quality_of_service() const;
        /**
         * @brief Sets the `qualityOfService` property of `NSThread`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_quality_of_service(QualityOfService value) const;
        /**
         * @brief Returns the `stackSize` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        std::uint64_t stack_size() const;
        /**
         * @brief Sets the `stackSize` property of `NSThread`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_stack_size(std::uint64_t value) const;
        /**
         * @brief Returns the `threadDictionary` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> thread_dictionary() const;
        /**
         * @brief Returns the `threadPriority` property of `NSThread`.
         * @return The converted Objective-C result.
         */
        double thread_priority() const;
        /**
         * @brief Sets the `threadPriority` property of `NSThread`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_thread_priority(double value) const;
    };
}
