#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class NetService;
    class Number;
    class RunLoop;

    /**
     * @brief C++ handle for the Objective-C class `NSNetServiceBrowser` (Foundation).
     * @details A network service browser that finds published services on a network using multicast DNS. Services can range from standard services, such as HTTP and FTP, to custom services defined by other applications. You can use a network service browser in your code to obtain the list of accessible domains and then to obtain an ''NetService'' object for each discovered service. Each network service browser performs one search at a time, so if you want to perform multiple simultaneous searches, use multiple network service browsers. A network service browser performs all searches asynchronously using the current run loop to execute the search in the background. Results from a search are returned through the associated delegate object, which your client application must provide. Searching proceeds in the background until the object receives a ''stop()'' message. To use an 'NSNetServiceBrowser' object to search for services, allocate it, initialize it, and assign a delegate. (If you wish, you can also use the ''schedule(in:forMode:)'' and ''remove(from:forMode:)'' methods to execute searches on a run loop other than the current one.) Once your object is ready, you begin by gathering the list of accessible domains using either the ''searchForRegistrationDomains()'' or ''searchForBrowsableDomains()'' methods. From the list of returned domains, you can pick one and use the ''searchForServices(ofType:inDomain:)'' method to search for services in that domain. The 'NSNetServiceBrowser' class provides two ways to search for domains. In most cases, your client should use the ''searchForRegistrationDomains()'' method to search only for local domains to which the host machine has registration authority. This is the preferred method for accessing domains as it guarantees that the host machine can connect to services in the returned domains. Access to domains outside this list may be more limited.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NetServiceBrowser net_service_browser;
     * net_service_browser.set_includes_peer_to_peer(true);
     * net_service_browser.will_search().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NetServiceBrowser net_service_browser{};
     * net_service_browser.set_includes_peer_to_peer(true);
     * auto includes_peer_to_peer = net_service_browser.includes_peer_to_peer();
     * net_service_browser.remove_from_run_loop(cocoon::RunLoop(), "text");
     * net_service_browser.schedule_in_run_loop(cocoon::RunLoop(), "text");
     * net_service_browser.search_for_browsable_domains();
     * net_service_browser.will_search().connect([]() {});
     * net_service_browser.did_stop_search().connect([]() {});
     * net_service_browser.did_not_search().connect([](std::map<std::string, cocoon::Number> a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnetservicebrowser
     */
    class NetServiceBrowser : public Object
    {
    public:
        /// @brief Creates a new `NSNetServiceBrowser` instance and returns a handle to it.
        explicit NetServiceBrowser();
        /// @brief Creates a null handle that refers to no native object.
        NetServiceBrowser(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NetServiceBrowser(Adopt adopt);
        /**
     * @brief Calls `-[NSNetServiceBrowser removeFromRunLoop:forMode:]`.
     * @details Removes the receiver from the specified run loop. - Parameters: - aRunLoop: Run loop from which to remove the receiver. - mode: Run loop mode in which to perform this operation. You can use this method in conjunction with '-scheduleInRunLoop:forMode:' to transfer the receiver to a run loop other than the default one. Although it is possible to remove an 'NSNetService' object completely from any run loop and then attempt actions on it, you must not do it.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser scheduleInRunLoop:forMode:]`.
     * @details Adds the receiver to the specified run loop. - Parameters: - aRunLoop: Run loop in which to schedule the receiver. - mode: Run loop mode in which to perform this operation. You can use this method in conjunction with '-removeFromRunLoop:forMode:' to transfer the receiver to a run loop other than the default one. You should not attempt to run the receiver on multiple run loops.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForBrowsableDomains]`.
     * @details Initiates a search for domains visible to the host. This method returns immediately. The delegate receives a '-netServiceBrowser:didFindDomain:moreComing:' message for each domain discovered.
     */
        void search_for_browsable_domains() const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForRegistrationDomains]`.
     * @details Initiates a search for domains in which the host may register services. This method returns immediately, sending a '-netServiceBrowserWillSearch:' message to the delegate if the network was ready to initiate the search. The delegate receives a subsequent '-netServiceBrowser:didFindDomain:moreComing:' message for each domain discovered. Most network service browser clients do not have to use this method -- it is sufficient to publish a service with the empty string, which registers it in any available registration domains automatically.
     */
        void search_for_registration_domains() const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForServicesOfType:inDomain:]`.
     * @details Starts a search for services of a particular type within a specific domain. - Parameters: - type: Type of the service to search for. Must contain both the service type and transport layer information (e.g. 'http.tcp.'). - domainString: Domain name in which to perform the search. Pass the empty string ('\@""') to search default registration domains. This method returns immediately, sending a '-netServiceBrowserWillSearch:' message to the delegate if the network was ready to initiate the search. The delegate receives subsequent '-netServiceBrowser:didFindService:moreComing:' messages for each service discovered.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param domain_string Argument converted to the Objective-C parameter of the same role.
     */
        void search_for_services_of_type(const std::string& type, const std::string& domain_string) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser stop]`.
     * @details Halts a currently running search or resolution. This method sends a '-netServiceBrowserDidStopSearch:' message to the delegate and causes the browser to discard any pending search results.
     */
        void stop() const;
        /**
     * @brief Returns the `includesPeerToPeer` property of `NSNetServiceBrowser`.
     * @details Whether to browse over peer-to-peer Bluetooth and Wi-Fi, if available. This property must be set before initiating a search to have an effect. Initially set to 'NO'.
     * @return The converted Objective-C result.
     */
        bool includes_peer_to_peer() const;
        /**
     * @brief Sets the `includesPeerToPeer` property of `NSNetServiceBrowser`.
     * @details Whether to browse over peer-to-peer Bluetooth and Wi-Fi, if available. This property must be set before initiating a search to have an effect. Initially set to 'NO'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_peer_to_peer(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `will_search`; connect a callback with `will_search().connect(...)`.
        Signal<NetServiceBrowser, void()> will_search() const
        {
            return Signal<NetServiceBrowser, void()>(handle(), "will_search");
        }
        /// @brief Signal for the delegate/data-source method behind `did_stop_search`; connect a callback with `did_stop_search().connect(...)`.
        Signal<NetServiceBrowser, void()> did_stop_search() const
        {
            return Signal<NetServiceBrowser, void()>(handle(), "did_stop_search");
        }
        /// @brief Signal for the delegate/data-source method behind `did_not_search`; connect a callback with `did_not_search().connect(...)`.
        Signal<NetServiceBrowser, void(std::map<std::string, Number>)> did_not_search() const
        {
            return Signal<NetServiceBrowser, void(std::map<std::string, Number>)>(handle(), "did_not_search");
        }
        /// @brief Signal for the delegate/data-source method behind `did_find_domain_more_coming`; connect a callback with `did_find_domain_more_coming().connect(...)`.
        Signal<NetServiceBrowser, void(std::string, bool)> did_find_domain_more_coming() const
        {
            return Signal<NetServiceBrowser, void(std::string, bool)>(handle(), "did_find_domain_more_coming");
        }
        /// @brief Signal for the delegate/data-source method behind `did_find_service_more_coming`; connect a callback with `did_find_service_more_coming().connect(...)`.
        Signal<NetServiceBrowser, void(NetService, bool)> did_find_service_more_coming() const
        {
            return Signal<NetServiceBrowser, void(NetService, bool)>(handle(), "did_find_service_more_coming");
        }
        /// @brief Signal for the delegate/data-source method behind `did_remove_domain_more_coming`; connect a callback with `did_remove_domain_more_coming().connect(...)`.
        Signal<NetServiceBrowser, void(std::string, bool)> did_remove_domain_more_coming() const
        {
            return Signal<NetServiceBrowser, void(std::string, bool)>(handle(), "did_remove_domain_more_coming");
        }
        /// @brief Signal for the delegate/data-source method behind `did_remove_service_more_coming`; connect a callback with `did_remove_service_more_coming().connect(...)`.
        Signal<NetServiceBrowser, void(NetService, bool)> did_remove_service_more_coming() const
        {
            return Signal<NetServiceBrowser, void(NetService, bool)>(handle(), "did_remove_service_more_coming");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
