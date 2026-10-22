#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSExtensionContext` (Foundation).
     * @details The host app context from which an app extension is invoked. When a host app sends a request to an app extension, it provides an extension context. For many app extensions, the most important part of the context is the data the user wants to work with, which is contained in the ''inputItems'' property.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ExtensionContext extension_context;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ExtensionContext extension_context{};
     * extension_context.cancel_request_with_error(cocoon::Error());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsextensioncontext
     */
    class ExtensionContext : public Object
    {
    public:
        /// @brief Creates a new `NSExtensionContext` instance and returns a handle to it.
        explicit ExtensionContext();
        /// @brief Creates a null handle that refers to no native object.
        ExtensionContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ExtensionContext(Adopt adopt);
        /**
         * @brief Calls `-[NSExtensionContext cancelRequestWithError:]`.
         * @details Signals the host to cancel the app extension request, with the supplied error, which should be non-nil. The \@c userInfo of the \@c NSError will contain a key \@c NSExtensionItemsAndErrorsKey which will have as its value a dictionary of \@c NSExtensionItems and associated \@c NSError instances.
         * @param error Argument converted to the Objective-C parameter of the same role.
         */
        void cancel_request_with_error(const Error& error) const;
        /**
         * @brief Calls `-[NSExtensionContext completeRequestReturningItems:completionHandler:]`.
         * @details Signals the host to complete the app extension request with the supplied result items. The completion handler optionally contains any work which the extension may need to perform after the request has been completed, as a background-priority task. The \@c expired parameter will be \@c YES if the system decides to prematurely terminate a previous non-expiration invocation of the completion handler. Calling this method will eventually dismiss the associated view controller.
         * @param items Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void complete_request_returning_items(const std::vector<Object>& items, std::function<void(bool)> completion_handler) const;
        /**
         * @brief Calls `-[NSExtensionContext openURL:completionHandler:]`.
         * @details Asks the host to open a URL on the extension's behalf.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void open_url(const URL& url, std::function<void(bool)> completion_handler) const;
        /**
         * @brief Returns the `inputItems` property of `NSExtensionContext`.
         * @details The list of input NSExtensionItems associated with the context. If the context has no input items, this array will be empty.
         * @return The converted Objective-C result.
         */
        std::vector<Object> input_items() const;
    };
}
