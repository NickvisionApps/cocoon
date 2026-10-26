#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class InputStream;
    class Number;
    class OutputStream;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSNetService` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NetService net_service;
     * net_service.set_includes_peer_to_peer(true);
     * net_service.will_publish().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NetService net_service{};
     * net_service.set_includes_peer_to_peer(true);
     * auto includes_peer_to_peer = net_service.includes_peer_to_peer();
     * net_service.txt_record_data();
     * net_service.publish();
     * net_service.publish_with_options(cocoon::NetServiceOptions::NoAutoRename);
     * net_service.will_publish().connect([]() {});
     * net_service.did_publish().connect([]() {});
     * net_service.did_not_publish().connect([](std::map<std::string, cocoon::Number> a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnetservice
     */
    class NetService : public Object
    {
    public:
        /// @brief Creates a new `NSNetService` instance and returns a handle to it.
        explicit NetService(const std::string& domain, const std::string& type, const std::string& name);
        /// @brief Creates a new `NSNetService` instance and returns a handle to it.
        explicit NetService(const std::string& domain, const std::string& type, const std::string& name, int port);
        /// @brief Creates a new `NSNetService` instance and returns a handle to it.
        explicit NetService();
        /// @brief Creates a null handle that refers to no native object.
        NetService(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NetService(Adopt adopt);
        /**
         * @brief Calls `-[NSNetService TXTRecordData]`.
         * @details Returns the raw TXT record of the NSNetService instance. If the instance has not been resolved, or the delegate's -netService:didUpdateTXTRecordData: has not been called, this will return nil. It is permitted to have a zero-length TXT record.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> txt_record_data() const;
        /**
         * @brief Calls `+[NSNetService dataFromTXTRecordDictionary:]`.
         * @details Returns an NSData created from the provided dictionary. The keys in the provided dictionary must be NSStrings, and the values must be NSDatas. If the dictionary cannot be converted into an NSData suitable for a TXT record, this method will return nil. For applications linked on or after Mac OS X 10.5, this method will throw an NSInvalidArgumentException if it is passed nil as the argument.
         * @param txt_dictionary Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::uint8_t> data_from_txt_record_dictionary(const std::map<std::string, std::vector<std::uint8_t>>& txt_dictionary);
        /**
         * @brief Calls `+[NSNetService dictionaryFromTXTRecordData:]`.
         * @details Returns an NSDictionary created from the provided NSData. The keys will be UTF8-encoded NSStrings. The values are NSDatas. The caller is responsible for interpreting these as types appropriate to the keys. If the NSData cannot be converted into an appropriate NSDictionary, this method will return nil. For applications linked on or after Mac OS X 10.5, this method will throw an NSInvalidException if it is passed nil as the argument.
         * @param txt_data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::map<std::string, std::vector<std::uint8_t>> dictionary_from_txt_record_data(const std::vector<std::uint8_t>& txt_data);
        /**
         * @brief Calls `-[NSNetService getInputStream:outputStream:]`.
         * @details Retrieves streams from the NSNetService instance. The instance's delegate methods are not called. Returns YES if the streams requested are created successfully. Returns NO if or any reason the stream could not be created. If only one stream is desired, pass NULL for the address of the other stream. The streams that are created are not open, and are not scheduled in any run loop for any mode.
         * @param input_stream Argument converted to the Objective-C parameter of the same role.
         * @param output_stream Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool get_input_stream(InputStream& input_stream, OutputStream& output_stream) const;
        /**
         * @brief Calls `-[NSNetService publish]`.
         * @details Advertises a given service on the network. This method returns immediately. Success or failure is indicated by callbacks to the NSNetService instance's delegate. If the name of the service is the default name (\@""), then the service will be renamed automatically. If the name of the service has been specified, then the service will not be renamed automatically. If more control over renaming is required, then -[NSNetService publishWithOptions:] is available.
         */
        void publish() const;
        /**
         * @brief Calls `-[NSNetService publishWithOptions:]`.
         * @details Advertises a given service on the network. This method returns immediately. Success or failure is indicated by callbacks to the NSNetService instance's delegate. See the notes above for NSNetServiceNoAutoRename for information about controlling the auto-renaming behavior using this method.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void publish_with_options(NetServiceOptions options) const;
        /**
         * @brief Calls `-[NSNetService removeFromRunLoop:forMode:]`.
         * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
         * @brief Calls `-[NSNetService resolveWithTimeout:]`.
         * @details Starts a resolve for the NSNetService instance of the specified duration. If the delegate's -netServiceDidResolveAddress: method is called before the timeout expires, the resolve is successful. If the timeout is reached, the delegate's -netService:didNotResolve: method will be called. The value of the NSNetServicesErrorCode key in the error dictionary will be NSNetServicesTimeoutError.
         * @param timeout Argument converted to the Objective-C parameter of the same role.
         */
        void resolve_with_timeout(double timeout) const;
        /**
         * @brief Calls `-[NSNetService scheduleInRunLoop:forMode:]`.
         * @details NSNetService instances may be scheduled on NSRunLoops to operate in different modes, or in other threads. It is generally not necessary to schedule NSNetServices in other threads. NSNetServices are scheduled in the current thread's NSRunLoop in the NSDefaultRunLoopMode when they are created.
         * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
         * @param mode Argument converted to the Objective-C parameter of the same role.
         */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
         * @brief Calls `-[NSNetService setTXTRecordData:]`.
         * @details Sets the TXT record of the NSNetService instance that has been or will be published. Pass nil to remove the TXT record from the instance.
         * @param record_data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_txt_record_data(const std::vector<std::uint8_t>& record_data) const;
        /**
         * @brief Calls `-[NSNetService startMonitoring]`.
         * @details Starts monitoring the NSNetService instance for events. In Mac OS X 10.4 Tiger, monitored NSNetService instances inform their delegates of changes to the instance's TXT record by calling the delegate's -netService:didUpdateTXTRecordData: method.
         */
        void start_monitoring() const;
        /**
         * @brief Calls `-[NSNetService stop]`.
         * @details Halts a service which is either publishing or resolving.
         */
        void stop() const;
        /**
         * @brief Calls `-[NSNetService stopMonitoring]`.
         * @details Stops monitoring the NSNetService instance for events.
         */
        void stop_monitoring() const;
        /**
         * @brief Returns the `addresses` property of `NSNetService`.
         * @details The addresses of the service. This is an NSArray of NSData instances, each of which contains a single struct sockaddr suitable for use with connect(2). In the event that no addresses are resolved for the service or the service has not yet been resolved, an empty NSArray is returned.
         * @return The converted Objective-C result.
         */
        std::vector<std::vector<std::uint8_t>> addresses() const;
        /**
         * @brief Returns the `domain` property of `NSNetService`.
         * @details Returns the domain of the discovered or published service.
         * @return The converted Objective-C result.
         */
        std::string domain() const;
        /**
         * @brief Returns the `hostName` property of `NSNetService`.
         * @details Returns the DNS host name of the computer hosting the discovered or published service. If a successful resolve has not yet occurred, this method will return nil.
         * @return The converted Objective-C result.
         */
        std::string host_name() const;
        /**
         * @brief Returns the `includesPeerToPeer` property of `NSNetService`.
         * @details Initially set to NO. Set to YES to also publish, resolve, or monitor this service over peer to peer Wi-Fi (if available). Must be set before operation starts.
         * @return The converted Objective-C result.
         */
        bool includes_peer_to_peer() const;
        /**
         * @brief Sets the `includesPeerToPeer` property of `NSNetService`.
         * @details Initially set to NO. Set to YES to also publish, resolve, or monitor this service over peer to peer Wi-Fi (if available). Must be set before operation starts.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_includes_peer_to_peer(bool value) const;
        /**
         * @brief Returns the `name` property of `NSNetService`.
         * @details Returns the name of the discovered or published service.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `port` property of `NSNetService`.
         * @details The port of a resolved service. This returns -1 if the service has not been resolved.
         * @return The converted Objective-C result.
         */
        std::int64_t port() const;
        /**
         * @brief Returns the `type` property of `NSNetService`.
         * @details Returns the type of the discovered or published service.
         * @return The converted Objective-C result.
         */
        std::string type() const;
        /// @brief Signal for the delegate/data-source method behind `will_publish`; connect a callback with `will_publish().connect(...)`.
        Signal<NetService, void()> will_publish() const
        {
            return Signal<NetService, void()>(handle(), "will_publish");
        }
        /// @brief Signal for the delegate/data-source method behind `did_publish`; connect a callback with `did_publish().connect(...)`.
        Signal<NetService, void()> did_publish() const
        {
            return Signal<NetService, void()>(handle(), "did_publish");
        }
        /// @brief Signal for the delegate/data-source method behind `did_not_publish`; connect a callback with `did_not_publish().connect(...)`.
        Signal<NetService, void(std::map<std::string, Number>)> did_not_publish() const
        {
            return Signal<NetService, void(std::map<std::string, Number>)>(handle(), "did_not_publish");
        }
        /// @brief Signal for the delegate/data-source method behind `will_resolve`; connect a callback with `will_resolve().connect(...)`.
        Signal<NetService, void()> will_resolve() const
        {
            return Signal<NetService, void()>(handle(), "will_resolve");
        }
        /// @brief Signal for the delegate/data-source method behind `did_resolve_address`; connect a callback with `did_resolve_address().connect(...)`.
        Signal<NetService, void()> did_resolve_address() const
        {
            return Signal<NetService, void()>(handle(), "did_resolve_address");
        }
        /// @brief Signal for the delegate/data-source method behind `did_not_resolve`; connect a callback with `did_not_resolve().connect(...)`.
        Signal<NetService, void(std::map<std::string, Number>)> did_not_resolve() const
        {
            return Signal<NetService, void(std::map<std::string, Number>)>(handle(), "did_not_resolve");
        }
        /// @brief Signal for the delegate/data-source method behind `did_stop`; connect a callback with `did_stop().connect(...)`.
        Signal<NetService, void()> did_stop() const
        {
            return Signal<NetService, void()>(handle(), "did_stop");
        }
        /// @brief Signal for the delegate/data-source method behind `did_update_txt_record_data`; connect a callback with `did_update_txt_record_data().connect(...)`.
        Signal<NetService, void(std::vector<std::uint8_t>)> did_update_txt_record_data() const
        {
            return Signal<NetService, void(std::vector<std::uint8_t>)>(handle(), "did_update_txt_record_data");
        }
        /// @brief Signal for the delegate/data-source method behind `did_accept_connection_with_input_stream_output_stream`; connect a callback with `did_accept_connection_with_input_stream_output_stream().connect(...)`.
        Signal<NetService, void(InputStream, OutputStream)> did_accept_connection_with_input_stream_output_stream() const
        {
            return Signal<NetService, void(InputStream, OutputStream)>(handle(), "did_accept_connection_with_input_stream_output_stream");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
