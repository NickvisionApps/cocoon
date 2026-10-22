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
     * @details An object representing a single name/value pair for an item in the query portion of a URL. In Swift, this object bridges to ''URLQueryItem''; use ''NSURLQueryItem'' when you need reference semantics or other Foundation-specific behavior. You use query items with the ''NSURLComponents/queryItems'' property of an ''NSURLComponents'' object. > Important: > The Swift overlay to the Foundation framework provides the ''URLQueryItem'' structure, which bridges to the ''NSURLQueryItem'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
         * @details Creates a new query item with the specified name and value. To use the newly initialized query item in composing a URL, add it to the ''NSURLComponents/queryItems'' array of an ''NSURLComponents'' instance. Because assigning an array of query items to an ''NSURLComponents'' instance automatically encodes the name and value properties, you should not percent-encode these strings. - Parameters: - name: The name of the query item. For example, in the URL 'http://www.apple.com/search/?q=iPad', the 'name' parameter is 'q'. - value: The value for the query item. For example, in the URL 'http://www.apple.com/search/?q=iPad', the 'value' parameter is 'iPad'. - Returns: A new query item object.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static URLQueryItem query_item_with_name(const std::string& name, const std::string& value);
        /**
         * @brief Returns the `name` property of `NSURLQueryItem`.
         * @details The name of the query item. For example, in the URL 'http://www.apple.com/search/?q=iPad', the 'name' parameter is 'q'. This string is not percent-encoded.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `value` property of `NSURLQueryItem`.
         * @details The value for the query item. For example, in the URL 'http://www.apple.com/search/?q=iPad', the 'value' parameter is 'iPad'. This string is not percent-encoded.
         * @return The converted Objective-C result.
         */
        std::string value() const;
    };
}
