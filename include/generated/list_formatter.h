#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Formatter;
    class Locale;

    /**
     * @brief C++ handle for the Objective-C class `NSListFormatter` (Foundation).
     * @details NSListFormatter provides locale-correct formatting of a list of items using the appropriate separator and conjunction. Note that the list formatter is unaware of the context where the joined string will be used, e.g., in the beginning of the sentence or used as a standalone string in the UI, so it will not provide any sort of capitalization customization on the given items, but merely join them as-is. The string joined this way may not be grammatically correct when placed in a sentence, and it should only be used in a standalone manner.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ListFormatter list_formatter;
     * list_formatter.set_item_formatter(cocoon::Formatter());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ListFormatter list_formatter{};
     * list_formatter.set_item_formatter(cocoon::Formatter());
     * auto item_formatter = list_formatter.item_formatter();
     * list_formatter.set_locale(cocoon::Locale());
     * auto locale = list_formatter.locale();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslistformatter
     */
    class ListFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSListFormatter` instance and returns a handle to it.
        explicit ListFormatter();
        /// @brief Creates a null handle that refers to no native object.
        ListFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ListFormatter(Adopt adopt);
        using Formatter::string_for_object_value;
        /**
         * @brief Calls `+[NSListFormatter localizedStringByJoiningStrings:]`.
         * @details Convenience method to return a string constructed from an array of strings using the list format specific to the current locale. It is recommended to join only disjointed strings that are ready to display in a bullet-point list. Sentences, phrases with punctuations, and appositions may not work well when joined together.
         * @param strings Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string localized_string_by_joining_strings(const std::vector<std::string>& strings);
        /**
         * @brief Calls `-[NSListFormatter stringForObjectValue:]`.
         * @details Inherited from NSFormatter. 'obj' must be an instance of NSArray. Returns nil if 'obj' is nil, not an instance of NSArray, or if the list formatter cannot generate a string representation for all objects in the array.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_object_value(const Object& obj) const;
        /**
         * @brief Calls `-[NSListFormatter stringFromItems:]`.
         * @details Convenience method for -stringForObjectValue:. Returns a string constructed from an array in the locale-aware format. Each item is formatted using the itemFormatter. If the itemFormatter does not apply to a particular item, the method will fall back to the item's -descriptionWithLocale: or -localizedDescription if implemented, or -description if not. Returns nil if 'items' is nil or if the list formatter cannot generate a string representation for all items in the array.
         * @param items Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_from_items(const std::vector<Object>& items) const;
        /**
         * @brief Returns the `itemFormatter` property of `NSListFormatter`.
         * @details Specifies how each object should be formatted. If not set, the object is formatted using its instance method in the following order: -descriptionWithLocale:, -localizedDescription, and -description.
         * @return The converted Objective-C result.
         */
        Formatter item_formatter() const;
        /**
         * @brief Sets the `itemFormatter` property of `NSListFormatter`.
         * @details Specifies how each object should be formatted. If not set, the object is formatted using its instance method in the following order: -descriptionWithLocale:, -localizedDescription, and -description.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_item_formatter(const Formatter& value) const;
        /**
         * @brief Returns the `locale` property of `NSListFormatter`.
         * @details Specifies the locale to format the items. Defaults to autoupdatingCurrentLocale. Also resets to autoupdatingCurrentLocale on assignment of nil.
         * @return The converted Objective-C result.
         */
        Locale locale() const;
        /**
         * @brief Sets the `locale` property of `NSListFormatter`.
         * @details Specifies the locale to format the items. Defaults to autoupdatingCurrentLocale. Also resets to autoupdatingCurrentLocale on assignment of nil.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_locale(const Locale& value) const;
    };
}
