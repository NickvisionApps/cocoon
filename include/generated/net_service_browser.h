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
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void remove_from_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser scheduleInRunLoop:forMode:]`.
     * @details NSNetServiceBrowser instances may be scheduled on NSRunLoops to operate in different modes, or in other threads. It is generally not necessary to schedule NSNetServiceBrowsers in other threads. NSNetServiceBrowsers are scheduled in the current thread's NSRunLoop in the NSDefaultRunLoopMode when they are created.
     * @param a_run_loop Argument converted to the Objective-C parameter of the same role.
     * @param mode Argument converted to the Objective-C parameter of the same role.
     */
        void schedule_in_run_loop(const RunLoop& a_run_loop, const std::string& mode) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForBrowsableDomains]`.
     * @details Starts a search for domains that are browsable via Bonjour and the computer's network configuration. Discovered domains are reported to the delegate's -netServiceBrowser:didFindDomain:moreComing: method. There may be more than one browsable domain.
     */
        void search_for_browsable_domains() const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForRegistrationDomains]`.
     * @details Starts a search for domains in which the network configuration allows registration (i.e. publishing). Most NSNetServiceBrowser clients do not need to use this API, as it is sufficient to publish an NSNetService instance with the empty string (see -[NSNetService initWithDomain:type:name:port:]). Discovered domains are reported to the delegate's -netServiceBrowser:didFindDomain:moreComing: method. There may be more than one registration domain.
     */
        void search_for_registration_domains() const;
        /**
     * @brief Calls `-[NSNetServiceBrowser searchForServicesOfType:inDomain:]`.
     * @details Starts a search for services of the specified type in the domain indicated by domainString. For each service discovered, a -netServiceBrowser:foundService:moreComing: message is sent to the NSNetServiceBrowser instance's delegate.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param domain_string Argument converted to the Objective-C parameter of the same role.
     */
        void search_for_services_of_type(const std::string& type, const std::string& domain_string) const;
        /**
     * @brief Calls `-[NSNetServiceBrowser stop]`.
     * @details Stops the currently running search.
     */
        void stop() const;
        /**
     * @brief Returns the `includesPeerToPeer` property of `NSNetServiceBrowser`.
     * @details Initially set to NO. Set to YES to also browse over peer to peer Wi-Fi (if available). Must be set before starting to search.
     * @return The converted Objective-C result.
     */
        bool includes_peer_to_peer() const;
        /**
     * @brief Sets the `includesPeerToPeer` property of `NSNetServiceBrowser`.
     * @details Initially set to NO. Set to YES to also browse over peer to peer Wi-Fi (if available). Must be set before starting to search.
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
