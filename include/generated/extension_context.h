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
     * @param error Argument converted to the Objective-C parameter of the same role.
     */
        void cancel_request_with_error(const Error& error) const;
        /**
     * @brief Calls `-[NSExtensionContext completeRequestReturningItems:completionHandler:]`.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void complete_request_returning_items(const std::vector<Object>& items, std::function<void(bool)> completion_handler) const;
        /**
     * @brief Calls `-[NSExtensionContext openURL:completionHandler:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void open_url(const URL& url, std::function<void(bool)> completion_handler) const;
        /**
     * @brief Returns the `inputItems` property of `NSExtensionContext`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> input_items() const;
    };
}
