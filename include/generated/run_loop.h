#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CFRunLoop;
    class Date;
    class Port;
    class Timer;

    /**
     * @brief C++ handle for the Objective-C class `NSRunLoop` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RunLoop run_loop;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RunLoop run_loop{};
     * run_loop.accept_input_for_mode("text", cocoon::Date());
     * run_loop.add_port(cocoon::Port(), "text");
     * run_loop.add_timer(cocoon::Timer(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsrunloop
     */
    class RunLoop : public Object
    {
    public:
        /// @brief Creates a new `NSRunLoop` instance and returns a handle to it.
        explicit RunLoop();
        /// @brief Creates a null handle that refers to no native object.
        RunLoop(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RunLoop(Adopt adopt);
        /**
     * @brief Calls `-[NSRunLoop acceptInputForMode:beforeDate:]`.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @param limit_date Argument converted to the Objective-C parameter of the same role.
     */
        void accept_input_for_mode(const std::string& mode, const Date& limit_date) const;
        /**
     * @brief Calls `-[NSRunLoop addPort:forMode:]`.
     * @param a_port Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void add_port(const Port& a_port, const std::string& mode) const;
        /**
     * @brief Calls `-[NSRunLoop addTimer:forMode:]`.
     * @param timer Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void add_timer(const Timer& timer, const std::string& mode) const;
        /**
     * @brief Calls `-[NSRunLoop cancelPerformSelector:target:argument:]`.
     * @param a_selector Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param arg Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_perform_selector(const std::string& a_selector, const Object& target, const Object& arg) const;
        /**
     * @brief Calls `-[NSRunLoop cancelPerformSelectorsWithTarget:]`.
     * @param target Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_perform_selectors_with_target(const Object& target) const;
        /**
     * @brief Calls `-[NSRunLoop getCFRunLoop]`.
     * @return The converted Objective-C result.
     */
        CFRunLoop get_cf_run_loop() const;
        /**
     * @brief Calls `-[NSRunLoop limitDateForMode:]`.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date limit_date_for_mode(const std::string& mode) const;
        /**
     * @brief Calls `-[NSRunLoop performBlock:]`.
     * @details Schedules the execution of a block on the target run loop. - parameter: block The block to execute
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_block(std::function<void()> block) const;
        /**
     * @brief Calls `-[NSRunLoop performInModes:block:]`.
     * @details Schedules the execution of a block on the target run loop in given modes. - parameter: modes An array of input modes for which the block may be executed. - parameter: block The block to execute
     * @param modes Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_in_modes(const std::vector<std::string>& modes, std::function<void()> block) const;
        /**
     * @brief Calls `-[NSRunLoop performSelector:target:argument:order:modes:]`.
     * @param a_selector Argument converted to the Objective-C parameter of the same role.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param arg Argument converted to the Objective-C parameter of the same role.
     * @param order Argument converted to the Objective-C parameter of the same role.
     * @param modes Argument converted to the Objective-C parameter of the same role.
     */
        void perform_selector(const std::string& a_selector, const Object& target, const Object& arg, std::uint64_t order, const std::vector<std::string>& modes) const;
        /**
     * @brief Calls `-[NSRunLoop removePort:forMode:]`.
     * @param a_port Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_port(const Port& a_port, const std::string& mode) const;
        /**
     * @brief Calls `-[NSRunLoop run]`.
     */
        void run() const;
        /**
     * @brief Calls `-[NSRunLoop runMode:beforeDate:]`.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     * @param limit_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool run_mode(const std::string& mode, const Date& limit_date) const;
        /**
     * @brief Calls `-[NSRunLoop runUntilDate:]`.
     * @param limit_date Argument converted to the Objective-C parameter of the same role.
     */
        void run_until_date(const Date& limit_date) const;
        /**
     * @brief Returns the `currentMode` property of `NSRunLoop`.
     * @return The converted Objective-C result.
     */
        std::string current_mode() const;
        /**
     * @brief Returns the `currentRunLoop` property of `NSRunLoop`.
     * @return The converted Objective-C result.
     */
        static RunLoop current_run_loop();
        /**
     * @brief Returns the `mainRunLoop` property of `NSRunLoop`.
     * @return The converted Objective-C result.
     */
        static RunLoop main_run_loop();
    };
}
