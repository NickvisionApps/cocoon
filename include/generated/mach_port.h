#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/port.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Port;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSMachPort` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Port.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MachPort mach_port;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MachPort mach_port{};
     * mach_port.delegate();
     * mach_port.remove_from_run_loop(cocoon::RunLoop(), "text");
     * mach_port.schedule_in_run_loop(cocoon::RunLoop(), "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmachport
     */
    class MachPort : public Port
    {
    public:
        /// @brief Creates a new `NSMachPort` instance and returns a handle to it.
        explicit MachPort(unsigned int mach_port);
        /// @brief Creates a new `NSMachPort` instance and returns a handle to it.
        explicit MachPort(unsigned int mach_port, MachPortOptions f);
        /// @brief Creates a new `NSMachPort` instance and returns a handle to it.
        explicit MachPort();
        /// @brief Creates a null handle that refers to no native object.
        MachPort(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MachPort(Adopt adopt);
        using Port::delegate;
        using Port::remove_from_run_loop;
        using Port::schedule_in_run_loop;
        using Port::set_delegate;
        /**
     * @brief Calls `-[NSMachPort delegate]`.
     * @return The converted Objective-C result.
     */
        Object delegate() const;
        /**
     * @brief Calls `+[NSMachPort portWithMachPort:]`.
     * @param mach_port Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Port port_with_mach_port(unsigned int mach_port);
        /**
     * @brief Calls `+[NSMachPort portWithMachPort:options:]`.
     * @param mach_port Argument converted to the Objective-C parameter of the same role.
     * @param f Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Port port_with_mach_port(unsigned int mach_port, MachPortOptions f);
        /**
     * @brief Calls `-[NSMachPort removeFromRunLoop:forMode:]`.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSMachPort scheduleInRunLoop:forMode:]`.
     * @param run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSMachPort setDelegate:]`.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     */
        void set_delegate(const Object& an_object) const;
        /**
     * @brief Returns the `machPort` property of `NSMachPort`.
     * @return The converted Objective-C result.
     */
        unsigned int mach_port() const;
    };
}
