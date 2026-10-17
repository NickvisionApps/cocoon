#pragma once

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
     * @details An abstract class representing a stream. This class's interface is common to all Cocoa stream classes, including its concrete subclasses ''InputStream'' and ''OutputStream''. ''Stream'' objects provide an easy way to read and write data to and from a variety of media in a device-independent way. You can create stream objects for data located in memory, in a file, or on a network (using sockets), and you can use stream objects without loading all of the data into memory at once. By default, ''Stream'' instances that aren't file-based are non-seekable, one-way streams (although custom seekable subclasses are possible). After you provide or consume data, you can't retrieve the data from the stream. \#\#\# Subclassing Notes ''Stream'' is an abstract class, incapable of instantiation and intended for you to subclass it. It publishes a programmatic interface that all subclasses must adopt and provide implementations for. The two Apple-provided concrete subclasses of ''Stream'', ''InputStream'' and ''OutputStream'', are suitable for most purposes. However, there might be situations when you want a peer subclass to ''InputStream'' and ''OutputStream''. For example, you might want a class that implements a full-duplex (two-way) stream, or a class whose instances are capable of seeking through a stream. \#\#\#\# Methods to Override All subclasses must fully implement the following methods: - ''open()'' and ''close()'' Implement ''open()'' to open the stream for reading or writing and make the stream available to the client directly or, if the stream object is scheduled on a run loop, to the delegate. Implement ''close()'' to close the stream and remove the stream object from the run loop, if necessary. A closed stream should still be able to accept new properties and report its current properties. Once you close a stream, you can't reopen it. - ''delegate'' Return and set the delegate. By a default, a stream object must be its own delegate; so a ''delegate'' message with an argument of 'nil' should restore this delegate. Don't retain the delegate to prevent retain cycles. To learn about delegates and delegation, read "Delegation" in Cocoa Fundamentals Guide. - ''schedule(in:forMode:)'' and ''remove(from:forMode:)'' Implement ''schedule(in:forMode:)'' to schedule the stream object on the specified run loop for the specified mode. Implement ''remove(from:forMode:)'' to remove the object from the run loop. See the documentation of the ''RunLoop'' class for details. Once the stream object for an open stream is scheduled on a run loop, it is the responsibility of the subclass as it processes stream data to send ''StreamDelegate/stream(:handle:)'' messages to its delegate. - ''property(forKey:)'' and ''setProperty(:forKey:)'' Implement these methods to return and set, respectively, the property value for the specified key. You may add custom properties, but be sure to handle all properties defined by ''Stream'' as well. - ''streamStatus'' and ''streamError'' Implement ''streamStatus'' to return the current status of the stream as a ''Status'' constant; you may define new ''Status'' constants, but be sure to handle the system defined constants properly. Implement ''streamError'' to return an ''NSError'' object representing the current error. You might decide to return a custom ''NSError'' object that can provide complete and localized information about the error.
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
     * @details Closes the receiver. Closing the stream terminates the flow of bytes and releases system resources that were reserved for the stream when it was opened. If the stream has been scheduled on a run loop, closing the stream implicitly removes the stream from the run loop. A stream that is closed can still be queried for its properties.
     */
        void close() const;
        /**
     * @brief Calls `+[NSStream getBoundStreamsWithBufferSize:inputStream:outputStream:]`.
     * @details Creates and returns by reference a bound pair of input and output streams. The created streams are bound to one another, such that any data written to 'outputStream' is received by 'inputStream'. - Parameters: - bufferSize: The size of the buffer, in bytes, used to transfer data from 'inputStream' to 'outputStream'. - inputStream: On return, contains an input stream. - outputStream: On return, contains an output stream.
     * @param buffer_size Argument converted to the Objective-C parameter of the same role.
     * @param input_stream Argument converted to the Objective-C parameter of the same role.
     * @param output_stream Argument converted to the Objective-C parameter of the same role.
     */
        static void get_bound_streams_with_buffer_size(std::uint64_t buffer_size, InputStream& input_stream, OutputStream& output_stream);
        /**
     * @brief Calls `+[NSStream getStreamsToHostWithName:port:inputStream:outputStream:]`.
     * @details Creates and returns by reference an 'NSInputStream' object and 'NSOutputStream' object for a socket connection with a given host on a given port. - Parameters: - hostname: The host to which to connect. - port: The port to connect to on 'host'. - inputStream: Upon return, contains the input stream. If 'nil' is passed, the stream object is not created. - outputStream: Upon return, contains the output stream. If 'nil' is passed, the stream object is not created.
     * @param hostname Argument converted to the Objective-C parameter of the same role.
     * @param port Argument converted to the Objective-C parameter of the same role.
     * @param input_stream Argument converted to the Objective-C parameter of the same role.
     * @param output_stream Argument converted to the Objective-C parameter of the same role.
     */
        static void get_streams_to_host_with_name(const std::string& hostname, std::int64_t port, InputStream& input_stream, OutputStream& output_stream);
        /**
     * @brief Calls `-[NSStream open]`.
     * @details Opens the receiving stream. A stream must be created before it can be opened. Once opened, a stream cannot be closed and reopened.
     */
        void open() const;
        /**
     * @brief Calls `-[NSStream propertyForKey:]`.
     * @details Returns the receiver's property for a given key. - Parameter key: The key for one of the receiver's properties. - Returns: The receiver's property for the key 'key'.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object property_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSStream removeFromRunLoop:forMode:]`.
     * @details Removes the receiver from a given run loop running in a given mode. - Parameters: - aRunLoop: The run loop on which the receiver was scheduled. - mode: The mode for the run loop.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSStream scheduleInRunLoop:forMode:]`.
     * @details Schedules the receiver on a given run loop in a given mode. Unless the client is polling the stream, it is responsible for ensuring that the stream is scheduled on at least one run loop and that at least one of the run loops on which the stream is scheduled is being run. - Parameters: - aRunLoop: The run loop on which to schedule the receiver. - mode: The mode for the run loop.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSStream setProperty:forKey:]`.
     * @details Attempts to set the value of a given property of the receiver and returns a Boolean value that indicates whether the value is accepted by the receiver. - Parameters: - property: The value for 'key'. - key: The key for one of the receiver's properties. - Returns: 'YES' if the value is accepted by the receiver, otherwise 'NO'.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_property(const Object& property, const std::string& key) const;
        /**
     * @brief Returns the `streamError` property of `NSStream`.
     * @details An 'NSError' object representing the stream error, or 'nil' if no error has been encountered.
     * @return The converted Objective-C result.
     */
        Error stream_error() const;
        /**
     * @brief Returns the `streamStatus` property of `NSStream`.
     * @details The receiver's status.
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
