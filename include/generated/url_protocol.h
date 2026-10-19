#pragma once

#include "generated/availability.h"
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
     * @details \@class NSURLProtocol \@abstract NSURLProtocol is an abstract class which provides the basic structure for performing protocol-specific loading of URL data. Concrete subclasses handle the specifics associated with one or more protocols or URL schemes.
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
     * @details \@method canInitWithRequest: \@abstract This method determines whether this protocol can handle the given request. \@discussion A concrete subclass should inspect the given request and determine whether or not the implementation can perform a load with that request. This is an abstract method. Subclasses must provide an implementation. \@param request A request to inspect. \@result YES if the protocol can handle the given request, NO if not.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_request(const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol canInitWithTask:]`.
     * @param task Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_task(const URLSessionTask& task);
        /**
     * @brief Calls `+[NSURLProtocol canonicalRequestForRequest:]`.
     * @details \@method canonicalRequestForRequest: \@abstract This method returns a canonical version of the given request. \@discussion It is up to each concrete protocol implementation to define what "canonical" means. However, a protocol should guarantee that the same input request always yields the same canonical form. Special consideration should be given when implementing this method since the canonical form of a request is used to look up objects in the URL cache, a process which performs equality checks between NSURLRequest objects. \<p> This is an abstract method; subclasses must provide an implementation. \@param request A request to make canonical. \@result The canonical form of the given request.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static URLRequest canonical_request_for_request(const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol propertyForKey:inRequest:]`.
     * @details \@method propertyForKey:inRequest: \@abstract Returns the property in the given request previously stored with the given key. \@discussion The purpose of this method is to provide an interface for protocol implementors to access protocol-specific information associated with NSURLRequest objects. \@param key The string to use for the property lookup. \@param request The request to use for the property lookup. \@result The property stored with the given key, or nil if no property had previously been stored with the given key in the given request.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object property_for_key(const std::string& key, const URLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol registerClass:]`.
     * @details \@method registerClass: \@abstract This method registers a protocol class, making it visible to several other NSURLProtocol class methods. \@discussion When the URL loading system begins to load a request, each protocol class that has been registered is consulted in turn to see if it can be initialized with a given request. The first protocol handler class to provide a YES answer to \<tt>+canInitWithRequest:\</tt> "wins" and that protocol implementation is used to perform the URL load. There is no guarantee that all registered protocol classes will be consulted. Hence, it should be noted that registering a class places it first on the list of classes that will be consulted in calls to \<tt>+canInitWithRequest:\</tt>, moving it in front of all classes that had been registered previously. \<p>A similar design governs the process to create the canonical form of a request with the \<tt>+canonicalRequestForRequest:\</tt> class method. \@param protocolClass the class to register. \@result YES if the protocol was registered successfully, NO if not. The only way that failure can occur is if the given class is not a subclass of NSURLProtocol.
     * @param protocol_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool register_class(const std::string& protocol_class);
        /**
     * @brief Calls `+[NSURLProtocol removePropertyForKey:inRequest:]`.
     * @details \@method removePropertyForKey:inRequest: \@abstract Remove any property stored under the given key \@discussion Like setProperty:forKey:inRequest: above, the purpose of this method is to give protocol implementors the ability to store protocol-specific information in an NSURLRequest \@param key The key whose value should be removed \@param request The request to be modified
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     */
        static void remove_property_for_key(const std::string& key, const MutableURLRequest& request);
        /**
     * @brief Calls `+[NSURLProtocol requestIsCacheEquivalent:toRequest:]`.
     * @details \@method requestIsCacheEquivalent:toRequest: \@abstract Compares two requests for equivalence with regard to caching. \@discussion Requests are considered equivalent for cache purposes if and only if they would be handled by the same protocol AND that protocol declares them equivalent after performing implementation-specific checks. \@result YES if the two requests are cache-equivalent, NO otherwise.
     * @param a Argument converted to the Objective-C parameter of the same role.
     * @param b Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool request_is_cache_equivalent(const URLRequest& a, const URLRequest& b);
        /**
     * @brief Calls `+[NSURLProtocol setProperty:forKey:inRequest:]`.
     * @details \@method setProperty:forKey:inRequest: \@abstract Stores the given property in the given request using the given key. \@discussion The purpose of this method is to provide an interface for protocol implementors to customize protocol-specific information associated with NSMutableURLRequest objects. \@param value The property to store. \@param key The string to use for the property storage. \@param request The request in which to store the property.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param request Argument converted to the Objective-C parameter of the same role.
     */
        static void set_property(const Object& value, const std::string& key, const MutableURLRequest& request);
        /**
     * @brief Calls `-[NSURLProtocol startLoading]`.
     * @details \@method startLoading \@abstract Starts protocol-specific loading of a request. \@discussion When this method is called, the protocol implementation should start loading a request.
     */
        void start_loading() const;
        /**
     * @brief Calls `-[NSURLProtocol stopLoading]`.
     * @details \@method stopLoading \@abstract Stops protocol-specific loading of a request. \@discussion When this method is called, the protocol implementation should end the work of loading a request. This could be in response to a cancel operation, so protocol implementations must be able to handle this call while a load is in progress.
     */
        void stop_loading() const;
        /**
     * @brief Calls `+[NSURLProtocol unregisterClass:]`.
     * @details \@method unregisterClass: \@abstract This method unregisters a protocol. \@discussion After unregistration, a protocol class is no longer consulted in calls to NSURLProtocol class methods. \@param protocolClass The class to unregister.
     * @param protocol_class Argument converted to the Objective-C parameter of the same role.
     */
        static void unregister_class(const std::string& protocol_class);
        /**
     * @brief Returns the `cachedResponse` property of `NSURLProtocol`.
     * @details \@abstract Returns the NSCachedURLResponse of the receiver. \@result The NSCachedURLResponse of the receiver.
     * @return The converted Objective-C result.
     */
        CachedURLResponse cached_response() const;
        /**
     * @brief Returns the `request` property of `NSURLProtocol`.
     * @details \@abstract Returns the NSURLRequest of the receiver. \@result The NSURLRequest of the receiver.
     * @return The converted Objective-C result.
     */
        URLRequest request() const;
        /**
     * @brief Returns the `task` property of `NSURLProtocol`.
     * @return The converted Objective-C result.
     */
        URLSessionTask task() const;
    };
}
