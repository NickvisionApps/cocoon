#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CachedURLResponse;
    class MutableURLRequest;
    class URLRequest;
    class URLSessionTask;

    /**
     * @brief C++ handle for the Objective-C class `NSURLProtocol` (Foundation).
     * @details An abstract class that handles the loading of protocol-specific URL data. Don't instantiate a ''URLProtocol'' subclass directly. Instead, create subclasses for any custom protocols or URL schemes that your app supports. When a download starts, the system creates the appropriate protocol object to handle the corresponding URL request. You define your protocol class and call the ''registerClass(:)'' class method during your app's launch time so that the system is aware of your protocol. > Note: > You cannot use this class to define custom URL schemes and protocols in watchOS 2 and later. To support the customization of protocol-specific requests, create extensions to the ''URLRequest'' class to provide any custom API that you need. You can store and retrieve protocol-specific request data by using ''URLProtocol'''s class methods ''property(forKey:in:)'' and ''setProperty(:forKey:in:)''. Create a ''URLResponse'' for each request your subclass processes successfully. You may want to create a custom ''URLResponse'' class to provide protocol specific information. \#\#\# Subclassing notes When overriding methods of this class, be aware that methods that take a 'task' parameter are preferred by the system to those that do not. Therefore, you should override the task-based methods when subclassing, as follows: Swift: - Initialization — Override ''init(task:cachedResponse:client:)'' instead of or in addition to ''init(request:cachedResponse:client:)''. Also override the task-based ''canInit(with:)-18gbo'' instead of or in addition to the request-based ''canInit(with:)-76brg''. Objective-C: - Initialization — Override ''canInit(with:)-18gbo'' and ''init(task:cachedResponse:client:)'' instead of or in addition to ''canInit(with:)-76brg'' and ''init(request:cachedResponse:client:)''.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLProtocol url_protocol;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLProtocol url_protocol{};
     * url_protocol.start_loading();
     * url_protocol.stop_loading();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlprotocol
     */
    class URLProtocol : public Object
    {
    public:
        /// @brief Creates a new `NSURLProtocol` instance and returns a handle to it.
        explicit URLProtocol(const URLRequest& request, const CachedURLResponse& cached_response, const Object& client);
        /// @brief Creates a new `NSURLProtocol` instance and returns a handle to it.
        explicit URLProtocol(const URLSessionTask& task, const CachedURLResponse& cached_response, const Object& client);
        /// @brief Creates a new `NSURLProtocol` instance and returns a handle to it.
        explicit URLProtocol();
        /// @brief Creates a null handle that refers to no native object.
        URLProtocol(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLProtocol(Adopt adopt);
        /**
     * @brief Calls `+[NSURLProtocol canInitWithRequest:]`.
     * @details Determines whether the protocol subclass can handle the specified request. A concrete subclass should inspect the given request and determine whether or not the implementation can perform a load with that request. This is an abstract method. Subclasses must provide an implementation. - Parameter request: A request to inspect. - Returns: 'YES' if the protocol can handle the given request, 'NO' if not.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_request(const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol canInitWithTask:]`.
     * @details Determines whether the protocol subclass can handle the specified task.
     * @param task Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_task(const URLSessionTask& task);
        /**
     * @brief Calls `+[NSURLProtocol canonicalRequestForRequest:]`.
     * @details Returns a canonical version of the specified request. It is up to each concrete protocol implementation to define what "canonical" means. However, a protocol should guarantee that the same input request always yields the same canonical form. Special consideration should be given when implementing this method since the canonical form of a request is used to look up objects in the URL cache, a process which performs equality checks between 'NSURLRequest' objects. This is an abstract method; subclasses must provide an implementation. - Parameter request: A request to make canonical. - Returns: The canonical form of the given request.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLRequest canonical_request_for_request(const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol propertyForKey:inRequest:]`.
     * @details Fetches the property associated with the specified key in the specified request. The purpose of this method is to provide an interface for protocol implementors to access protocol-specific information associated with 'NSURLRequest' objects. - Parameters: - key: The string to use for the property lookup. - request: The request to use for the property lookup. - Returns: The property stored with the given key, or 'nil' if no property had previously been stored with the given key in the given request.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object property_for_key(const std::string& key, const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol registerClass:]`.
     * @details Attempts to register a subclass of ''URLProtocol'', making it visible to the URL loading system. When the URL loading system begins to load a request, each protocol class that has been registered is consulted in turn to see if it can be initialized with a given request. The first protocol handler class to provide a 'YES' answer to '+canInitWithRequest:' "wins" and that protocol implementation is used to perform the URL load. There is no guarantee that all registered protocol classes will be consulted. Registering a class places it first on the list of classes that will be consulted. - Parameter protocolClass: The class to register. - Returns: 'YES' if the protocol was registered successfully, 'NO' if not. The only way that failure can occur is if the given class is not a subclass of 'NSURLProtocol'.
     * @param protocol_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool register_class(const std::string& protocol_class);
        /**
     * @brief Calls `+[NSURLProtocol removePropertyForKey:inRequest:]`.
     * @details Removes the property associated with the specified key in the specified request. Like 'setProperty:forKey:inRequest:', the purpose of this method is to give protocol implementors the ability to store protocol-specific information in an 'NSURLRequest'. - Parameters: - key: The key whose value should be removed. - request: The request to be modified.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_property_for_key(const std::string& key, const MutableURLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol requestIsCacheEquivalent:toRequest:]`.
     * @details A Boolean value indicating whether two requests are equivalent for cache purposes. Requests are considered equivalent for cache purposes if and only if they would be handled by the same protocol AND that protocol declares them equivalent after performing implementation-specific checks. - Returns: 'YES' if the two requests are cache-equivalent, 'NO' otherwise.
     * @param a Argument converted to the Objective-C parameter of the same role.
     * @param b Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool request_is_cache_equivalent(const URLRequest& a, const URLRequest& b);
        /**
     * @brief Calls `+[NSURLProtocol setProperty:forKey:inRequest:]`.
     * @details Sets the property associated with the specified key in the specified request. The purpose of this method is to provide an interface for protocol implementors to customize protocol-specific information associated with 'NSMutableURLRequest' objects. - Parameters: - value: The property to store. - key: The string to use for the property storage. - request: The request in which to store the property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     */
        static void set_property(const Object& value, const std::string& key, const MutableURLRequest& request);
        /**
     * @brief Calls `-[NSURLProtocol startLoading]`.
     * @details Starts protocol-specific loading of the request. When this method is called, the protocol implementation should start loading a request.
     */
        void start_loading() const;
        /**
     * @brief Calls `-[NSURLProtocol stopLoading]`.
     * @details Stops protocol-specific loading of the request. When this method is called, the protocol implementation should end the work of loading a request. This could be in response to a cancel operation, so protocol implementations must be able to handle this call while a load is in progress.
     */
        void stop_loading() const;
        /**
     * @brief Calls `+[NSURLProtocol unregisterClass:]`.
     * @details Unregisters the specified subclass of ''URLProtocol''. After unregistration, a protocol class is no longer consulted in calls to 'NSURLProtocol' class methods. - Parameter protocolClass: The class to unregister.
     * @param protocol_class Argument converted to the Objective-C parameter of the same role.
     */
        static void unregister_class(const std::string& protocol_class);
        /**
     * @brief Returns the `cachedResponse` property of `NSURLProtocol`.
     * @details The protocol's cached response.
     * @return The converted Objective-C result.
     */
        CachedURLResponse cached_response() const;
        /**
     * @brief Returns the `request` property of `NSURLProtocol`.
     * @details The protocol's request.
     * @return The converted Objective-C result.
     */
        URLRequest request() const;
        /**
     * @brief Returns the `task` property of `NSURLProtocol`.
     * @details The protocol's task.
     * @return The converted Objective-C result.
     */
        URLSessionTask task() const;
    };
}
