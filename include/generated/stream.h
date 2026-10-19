#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class InputStream;
    class OutputStream;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSStream` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Stream stream;
     * stream.handle_event().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Stream stream{};
     * stream.close();
     * stream.open();
     * stream.property_for_key("text");
     * stream.handle_event().connect([](cocoon::StreamEvent a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsstream
     */
    class Stream : public Object
    {
    public:
        /// @brief Creates a new `NSStream` instance and returns a handle to it.
        explicit Stream();
        /// @brief Creates a null handle that refers to no native object.
        Stream(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Stream(Adopt adopt);
        /**
     * @brief Calls `-[NSStream close]`.
     */
        void close() const;
        /**
     * @brief Calls `+[NSStream getBoundStreamsWithBufferSize:inputStream:outputStream:]`.
     * @param buffer_size Argument converted to the Objective-C parameter of the same role.
     * @param input_stream Argument converted to the Objective-C parameter of the same role.
     * @param output_stream Argument converted to the Objective-C parameter of the same role.
     */
        static void get_bound_streams_with_buffer_size(std::uint64_t buffer_size, InputStream& input_stream, OutputStream& output_stream);
        /**
     * @brief Calls `+[NSStream getStreamsToHostWithName:port:inputStream:outputStream:]`.
     * @param hostname Argument converted to the Objective-C parameter of the same role.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param input_stream Argument converted to the Objective-C parameter of the same role.
     * @param output_stream Argument converted to the Objective-C parameter of the same role.
     */
        static void get_streams_to_host_with_name(const std::string& hostname, std::int64_t port, InputStream& input_stream, OutputStream& output_stream);
        /**
     * @brief Calls `-[NSStream open]`.
     */
        void open() const;
        /**
     * @brief Calls `-[NSStream propertyForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object property_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSStream removeFromRunLoop:forMode:]`.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSStream scheduleInRunLoop:forMode:]`.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSStream setProperty:forKey:]`.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_property(const Object& property, const std::string& key) const;
        /**
     * @brief Returns the `streamError` property of `NSStream`.
     * @return The converted Objective-C result.
     */
        Error stream_error() const;
        /**
     * @brief Returns the `streamStatus` property of `NSStream`.
     * @return The converted Objective-C result.
     */
        StreamStatus stream_status() const;
        /// @brief Signal for the delegate/data-source method behind `handle_event`; connect a callback with `handle_event().connect(...)`.
        Signal<Stream, void(StreamEvent)> handle_event() const
        {
            return Signal<Stream, void(StreamEvent)>(handle(), "handle_event");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
