#pragma once

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
     * @details A network service that broadcasts its availability using multicast DNS. The ''NetService'' class represents a network service, either one your application publishes or is a client of. This class and the ''NetServiceBrowser'' class use multicast DNS to convey information about network services to and from your application. The API of ''NetService'' provides a convenient way to publish the services offered by your application and to resolve the socket address for a service. The types of services you access using ''NetService'' are the same types that you access directly using BSD sockets. HTTP and FTP are two services commonly provided by systems. (For a list of common services and the ports used by those services, see the file '/etc/services'.) Applications can also define their own custom services to provide specific data to clients. You can use the ''NetService'' class as either a publisher of a service or a client of a service. If your application publishes a service, your code must acquire a port and prepare a socket to communicate with clients. Once your socket is ready, you use the ''NetService'' class to notify clients that your service is ready. If your application is the client of a network service, you can either create an ''NetService'' object directly (if you know the exact host and port information) or use an ''NetServiceBrowser'' object to browse for services. To publish a service, initialize your ''NetService'' object with the service name, domain, type, and port information. All of this information must be valid for the socket created by your application. Once initialized, call the ''publish()'' method to broadcast your service information to the network. When connecting to a service, use the ''NetServiceBrowser'' class to locate the service on the network and obtain the corresponding ''NetService'' object. Once you have the object, call the ''resolve(withTimeout:)'' method to verify that the service is available and ready for your application. If it is, the ''addresses'' property provides the socket information you can use to connect to the service. The methods of ''NetService'' operate asynchronously so your application is not impacted by the speed of the network. All information about a service is returned to your application through the ''NetService'' object's delegate. You must provide a delegate object to respond to messages and to handle errors appropriately.
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
     * @details Returns the TXT record for the receiver. If the instance has not been resolved, or the delegate's '-netService:didUpdateTXTRecordData:' has not been called, this will return 'nil'. It is permitted to have a zero-length TXT record.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> txt_record_data() const;
        /**
     * @brief Calls `+[NSNetService dataFromTXTRecordDictionary:]`.
     * @details Returns an 'NSData' object representing a TXT record formed from a given dictionary. - Parameters: - txtDictionary: A dictionary containing a TXT record. - Returns: An 'NSData' object representing TXT data formed from 'txtDictionary'. Fails an assertion if 'txtDictionary' cannot be represented as an 'NSData' object.
     * @param txt_dictionary Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> data_from_txt_record_dictionary(const std::map<std::string, std::vector<std::uint8_t>>& txt_dictionary);
        /**
     * @brief Calls `+[NSNetService dictionaryFromTXTRecordData:]`.
     * @details Returns a dictionary representing a TXT record given as an 'NSData' object. - Parameters: - txtData: A data object encoding a TXT record. - Returns: A dictionary representing 'txtData'. The dictionary's keys are UTF8-encoded 'NSString' objects. The values associated with all the dictionary's keys are 'NSData' objects that encapsulate strings or data. Fails an assertion if 'txtData' cannot be represented as an 'NSDictionary' object.
     * @param txt_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, std::vector<std::uint8_t>> dictionary_from_txt_record_data(const std::vector<std::uint8_t>& txt_data);
        /**
     * @brief Calls `-[NSNetService getInputStream:outputStream:]`.
     * @details Creates a pair of input and output streams for the receiver and returns a Boolean value that indicates whether they were retrieved successfully. - Parameters: - inputStream: Upon return, the input stream for the receiver. Pass 'NULL' if you do not need this stream. - outputStream: Upon return, the output stream for the receiver. Pass 'NULL' if you do not need this stream. - Returns: 'YES' if the streams are created successfully, otherwise 'NO'. After this method is called, no delegate callbacks are called by the receiver. The streams that are created are not open, and are not scheduled in any run loop for any mode.
     * @param input_stream Argument converted to the Objective-C parameter of the same role.
     * @param output_stream Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool get_input_stream(InputStream& input_stream, OutputStream& output_stream) const;
        /**
     * @brief Calls `-[NSNetService publish]`.
     * @details Attempts to advertise the receiver's on the network. This method returns immediately, with success or failure indicated by the callbacks to the delegate. This is equivalent to calling '-publishWithOptions:' with the default options ('0').
     */
        void publish() const;
        /**
     * @brief Calls `-[NSNetService publishWithOptions:]`.
     * @details Attempts to advertise the receiver on the network, with the given options. - Parameters: - options: Options for the receiver. The supported options are described in 'NSNetServiceOptions'. This method returns immediately, with success or failure indicated by the callbacks to the delegate.
     * @param options Argument converted to the Objective-C parameter of the same role.
     */
        void publish_with_options(NetServiceOptions options) const;
        /**
     * @brief Calls `-[NSNetService removeFromRunLoop:forMode:]`.
     * @details Removes the service from the given run loop for a given mode. - Parameters: - aRunLoop: The run loop from which to remove the receiver. - mode: The run loop mode from which to remove the receiver. You can use this method in conjunction with '-scheduleInRunLoop:forMode:' to transfer the service to a different run loop. Although it is possible to remove an 'NSNetService' object completely from any run loop and then attempt actions on it, it is an error to do so.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetService resolveWithTimeout:]`.
     * @details Starts a resolve process of a finite duration for the service. - Parameters: - timeout: The maximum number of seconds to attempt a resolve. A value of '0.0' indicates no timeout and a resolve process of indefinite duration. During the resolve period, the service sends '-netServiceDidResolveAddress:' to the delegate for each address it discovers that matches the service parameters. Once the timeout is hit, the service sends '-netServiceDidStop:' to the delegate. If no addresses resolve during the timeout period, the service sends '-netService:didNotResolve:' to the delegate.
     * @param timeout Argument converted to the Objective-C parameter of the same role.
     */
        void resolve_with_timeout(double timeout) const;
        /**
     * @brief Calls `-[NSNetService scheduleInRunLoop:forMode:]`.
     * @details Adds the service to the specified run loop. - Parameters: - aRunLoop: The run loop to which to add the receiver. - mode: The run loop mode to which to add the receiver. You can use this method in conjunction with '-removeFromRunLoop:forMode:' to transfer a service to a different run loop. You should not attempt to run a service on multiple run loops.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetService setTXTRecordData:]`.
     * @details Sets the TXT record for the receiver, and returns a Boolean value that indicates whether the operation was successful. - Parameters: - recordData: The TXT record for the receiver. Pass 'nil' to remove the TXT record from the instance. - Returns: 'YES' if 'recordData' is successfully set as the TXT record, otherwise 'NO'.
     * @param record_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_txt_record_data(const std::vector<std::uint8_t>& record_data) const;
        /**
     * @brief Calls `-[NSNetService startMonitoring]`.
     * @details Starts the monitoring of TXT-record updates for the receiver. The delegate must implement '-netService:didUpdateTXTRecordData:', which is called when the TXT record for the receiver is updated.
     */
        void start_monitoring() const;
        /**
     * @brief Calls `-[NSNetService stop]`.
     * @details Halts a currently running attempt to publish or resolve a service. The delegate will receive '-netServiceDidStop:' after the service stops. It is safe to remove all strong references to the service immediately after calling this method.
     */
        void stop() const;
        /**
     * @brief Calls `-[NSNetService stopMonitoring]`.
     * @details Stops the monitoring of TXT-record updates for the receiver.
     */
        void stop_monitoring() const;
        /**
     * @brief Returns the `addresses` property of `NSNetService`.
     * @details A read-only array containing 'NSData' objects, each of which contains a socket address for the service. Each 'NSData' object in the returned array contains an appropriate 'sockaddr' structure that you can use to connect to the socket. The exact type of this structure depends on the service to which you are connecting. If no addresses were resolved for the service, the returned array contains zero elements. It is possible for a single service to resolve to more than one address or not resolve to any addresses. A service might resolve to multiple addresses if the computer publishing the service is currently multihoming.
     * @return The converted Objective-C result.
     */
        std::vector<std::vector<std::uint8_t>> addresses() const;
        /**
     * @brief Returns the `domain` property of `NSNetService`.
     * @details A string containing the domain for this service. This can be an explicit domain name or it can contain the generic local domain name, '\@"local."' (note the trailing period, which indicates an absolute name).
     * @return The converted Objective-C result.
     */
        std::string domain() const;
        /**
     * @brief Returns the `hostName` property of `NSNetService`.
     * @details A string containing the DNS hostname for this service. This value is 'nil' until the service has been resolved (when 'addresses' is non-'nil').
     * @return The converted Objective-C result.
     */
        std::string host_name() const;
        /**
     * @brief Returns the `includesPeerToPeer` property of `NSNetService`.
     * @details Specifies whether to also publish, resolve, or monitor this service over peer-to-peer Bluetooth and Wi-Fi, if available. This property must be set before calling '-publish', '-publishWithOptions:', '-resolveWithTimeout:', or '-startMonitoring' in order to take effect. Initially set to 'NO'.
     * @return The converted Objective-C result.
     */
        bool includes_peer_to_peer() const;
        /**
     * @brief Sets the `includesPeerToPeer` property of `NSNetService`.
     * @details Specifies whether to also publish, resolve, or monitor this service over peer-to-peer Bluetooth and Wi-Fi, if available. This property must be set before calling '-publish', '-publishWithOptions:', '-resolveWithTimeout:', or '-startMonitoring' in order to take effect. Initially set to 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_peer_to_peer(bool value) const;
        /**
     * @brief Returns the `name` property of `NSNetService`.
     * @details A string containing the name of this service. This value is set when the object is first initialized, whether by your code or by a browser object.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `port` property of `NSNetService`.
     * @details The port on which the service is listening for connections. If the object was initialized by calling '-initWithDomain:type:name:port:', then the value was set when the object was first initialized. If the object was initialized by calling '-initWithDomain:type:name:', the value of this property is not valid ('-1') until after the service has successfully been resolved (when 'addresses' is non-'nil').
     * @return The converted Objective-C result.
     */
        std::int64_t port() const;
        /**
     * @brief Returns the `type` property of `NSNetService`.
     * @details The type of the published service. This value is set when the object is first initialized, whether by your code or by a browser object.
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
