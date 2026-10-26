#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSURLQueryItem` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::URLQueryItem url_query_item;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::URLQueryItem url_query_item{};
     * auto made_0 = cocoon::URLQueryItem::query_item_with_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsurlqueryitem
     */
    class URLQueryItem : public Object
    {
    public:
        /// @brief Creates a new `NSURLQueryItem` instance and returns a handle to it.
        explicit URLQueryItem(const std::string& name, const std::string& value);
        /// @brief Creates a new `NSURLQueryItem` instance and returns a handle to it.
        explicit URLQueryItem();
        /// @brief Creates a null handle that refers to no native object.
        URLQueryItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit URLQueryItem(Adopt adopt);
        /**
         * @brief Calls `+[NSURLQueryItem queryItemWithName:value:]`.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLQueryItem query_item_with_name(const std::string& name, const std::string& value);
        /**
         * @brief Returns the `name` property of `NSURLQueryItem`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `value` property of `NSURLQueryItem`.
         * @return The converted Objective-C result.
         */
        std::string value() const;
    };
}
