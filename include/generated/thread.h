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
     * @details A thread of execution. Use this class when you want to have an Objective-C method run in its own thread of execution. Threads are especially useful when you need to perform a lengthy task, but don't want it to block the execution of the rest of the application. In particular, you can use threads to avoid blocking the main thread of the application, which handles user interface and event-related actions. Threads can also be used to divide a large job into several smaller jobs, which can lead to performance increases on multi-core computers. The ''Thread'' class supports semantics similar to those of ''Operation'' for monitoring the runtime condition of a thread. You can use these semantics to cancel the execution of a thread or determine if the thread is still executing or has finished its task. Canceling a thread requires support from your thread code; see the description for ''cancel()'' for more information. \#\#\# Subclassing Notes You can subclass ''Thread'' and override the ''main()'' method to implement your thread's main entry point. If you override ''main()'', you do not need to invoke the inherited behavior by calling 'super'.
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
         * @details Changes the cancelled state of the receiver to indicate that it should exit. The semantics of this method are the same as those used for 'NSOperation'. This method sets state information in the receiver that is then reflected by the 'isCancelled' property. Threads that support cancellation should periodically call the 'isCancelled' method to determine if the thread has in fact been cancelled, and exit if it has been.
         */
        void cancel() const;
        /**
         * @brief Calls `+[NSThread detachNewThreadSelector:toTarget:withObject:]`.
         * @details Detaches a new thread and uses the specified selector as the thread entry point. The objects 'aTarget' and 'anArgument' are retained during the execution of the detached thread, then released. The detached thread is exited (using the 'exit' class method) as soon as 'aTarget' has completed executing the 'aSelector' method. If this thread is the first thread detached in the application, this method posts the 'NSWillBecomeMultiThreaded' notification with object 'nil' to the default notification center. - Parameters: - selector: The selector for the message to send to the target. This selector must take only one argument and must not have a return value. - target: The object that will receive the message 'aSelector' on the new thread. - argument: The single argument passed to the target. May be 'nil'.
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
         * @details Terminates the current thread. This method uses the 'currentThread' class method to access the current thread. Before exiting the thread, this method posts the 'NSThreadWillExit' notification with the thread being exited to the default notification center. Because notifications are delivered synchronously, all observers of 'NSThreadWillExit' are guaranteed to receive the notification before the thread exits. Invoking this method should be avoided as it does not give your thread a chance to clean up any resources it allocated during its execution.
         */
        static void exit();
        /**
         * @brief Calls `+[NSThread isMultiThreaded]`.
         * @details Returns whether the application is multithreaded. An application is considered multithreaded if a thread was ever detached from the main thread using either 'detachNewThreadSelector:toTarget:withObject:' or 'start'. If you detached a thread in your application using a non-Cocoa API, such as the POSIX or Multiprocessing Services APIs, this method could still return 'NO'. The detached thread does not have to be currently running for the application to be considered multithreaded -- this method only indicates whether a single thread has been spawned. - Returns: 'YES' if the application is multithreaded, otherwise 'NO'.
         * @return The converted Objective-C result.
         */
        static bool is_multi_threaded();
        /**
         * @brief Calls `-[NSThread main]`.
         * @details The main entry point routine for the thread. The default implementation of this method takes the target and selector used to initialize the receiver and invokes the selector on the specified target. If you subclass 'NSThread', you can override this method and use it to implement the main body of your thread instead. If you do so, you do not need to invoke 'super'. You should never invoke this method directly. You should always start your thread by invoking the 'start' method.
         */
        void main_() const;
        /**
         * @brief Calls `+[NSThread sleepForTimeInterval:]`.
         * @details Sleeps the thread for a given time interval. No run loop processing occurs while the thread is blocked. - Parameter ti: The duration of the sleep.
         * @param ti Argument converted to the Objective-C parameter of the same role.
         */
        static void sleep_for_time_interval(double ti);
        /**
         * @brief Calls `+[NSThread sleepUntilDate:]`.
         * @details Blocks the current thread until the time specified. No run loop processing occurs while the thread is blocked. - Parameter date: The time at which to resume processing.
         * @param date Argument converted to the Objective-C parameter of the same role.
         */
        static void sleep_until_date(const Date& date);
        /**
         * @brief Calls `-[NSThread start]`.
         * @details Starts the receiver. This method asynchronously spawns the new thread and invokes the receiver's 'main' method on the new thread. The 'isExecuting' property returns 'YES' once the thread starts executing, which may occur after the 'start' method returns. If you initialized the receiver with a target and selector, the default 'main' method invokes that selector automatically. If this thread is the first thread detached in the application, this method posts the 'NSWillBecomeMultiThreaded' notification with object 'nil' to the default notification center.
         */
        void start() const;
        /**
         * @brief Returns the `callStackReturnAddresses` property of `NSThread`.
         * @details Returns an array containing the call stack return addresses. Each element is an 'NSNumber' object containing an 'NSUInteger' value.
         * @return The converted Objective-C result.
         */
        static std::vector<Number> call_stack_return_addresses();
        /**
         * @brief Returns the `callStackSymbols` property of `NSThread`.
         * @details Returns an array containing the call stack symbols. Each element is an 'NSString' object with a value in a format determined by the 'backtrace_symbols()' function. The return value describes the call stack backtrace of the current thread at the moment this method was called.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> call_stack_symbols();
        /**
         * @brief Returns the `cancelled` property of `NSThread`.
         * @details A Boolean value that indicates whether the receiver is cancelled. If your thread supports cancellation, it should check this property periodically and exit if it ever returns 'YES'.
         * @return The converted Objective-C result.
         */
        bool is_cancelled() const;
        /**
         * @brief Returns the `currentThread` property of `NSThread`.
         * @details Returns the thread object representing the current thread of execution.
         * @return The converted Objective-C result.
         */
        static Thread current_thread();
        /**
         * @brief Returns the `executing` property of `NSThread`.
         * @details A Boolean value that indicates whether the receiver is executing.
         * @return The converted Objective-C result.
         */
        bool is_executing() const;
        /**
         * @brief Returns the `finished` property of `NSThread`.
         * @details A Boolean value that indicates whether the receiver has finished execution.
         * @return The converted Objective-C result.
         */
        bool is_finished() const;
        /**
         * @brief Returns the `isMainThread` property of `NSThread`.
         * @details A Boolean value that indicates whether the receiver is the main thread.
         * @return The converted Objective-C result.
         */
        bool is_main_thread() const;
        /**
         * @brief Returns the `mainThread` property of `NSThread`.
         * @details Returns the 'NSThread' object representing the main thread.
         * @return The converted Objective-C result.
         */
        static Thread main_thread();
        /**
         * @brief Returns the `name` property of `NSThread`.
         * @details The name of the receiver.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSThread`.
         * @details The name of the receiver.
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
         * @details The stack size of the receiver, in bytes. This value must be in bytes and a multiple of 4KB. To change the stack size, you must set this property before starting your thread. Setting the stack size after the thread has started changes the attribute size (which is reflected by the 'stackSize' method), but it does not affect the actual number of pages set aside for the thread.
         * @return The converted Objective-C result.
         */
        std::uint64_t stack_size() const;
        /**
         * @brief Sets the `stackSize` property of `NSThread`.
         * @details The stack size of the receiver, in bytes. This value must be in bytes and a multiple of 4KB. To change the stack size, you must set this property before starting your thread. Setting the stack size after the thread has started changes the attribute size (which is reflected by the 'stackSize' method), but it does not affect the actual number of pages set aside for the thread.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_stack_size(std::uint64_t value) const;
        /**
         * @brief Returns the `threadDictionary` property of `NSThread`.
         * @details The thread object's dictionary. You can use the returned dictionary to store thread-specific data. The thread dictionary is not used during any manipulations of the 'NSThread' object -- it is simply a place where you can store any interesting data. For example, Foundation uses it to store the thread's default 'NSConnection' and 'NSAssertionHandler' instances. You may define your own keys for the dictionary.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> thread_dictionary() const;
        /**
         * @brief Returns the `threadPriority` property of `NSThread`.
         * @details The receiver's priority. The thread's priority, which is specified by a floating point number from 0.0 to 1.0, where 1.0 is highest priority. The priorities in this range are mapped to the operating system's priority values. A "typical" thread priority might be 0.5, but because the priority is determined by the kernel, there is no guarantee what this value actually will be.
         * @return The converted Objective-C result.
         */
        double thread_priority() const;
        /**
         * @brief Sets the `threadPriority` property of `NSThread`.
         * @details The receiver's priority. The thread's priority, which is specified by a floating point number from 0.0 to 1.0, where 1.0 is highest priority. The priorities in this range are mapped to the operating system's priority values. A "typical" thread priority might be 0.5, but because the priority is determined by the kernel, there is no guarantee what this value actually will be.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_thread_priority(double value) const;
    };
}
