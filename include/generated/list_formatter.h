#pragma once

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
     * @details An object that provides locale-correct formatting of a list of items using the appropriate separator and conjunction. The list formatter isn't aware of the context where the formatted string will be used and doesn't provide capitalization customization of the list items. The formatted result may not be grammatically correct if placed in a sentence, and it should only be used in a standalone manner.
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
     * @details Returns a string constructed from an array of strings using the list format specific to the current locale. It is recommended to join only disjointed strings that are ready to display in a bullet-point list. Sentences, phrases with punctuations, and appositions may not work well when joined together.
     * @param strings Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_by_joining_strings(const std::vector<std::string>& strings);
        /**
     * @brief Calls `-[NSListFormatter stringForObjectValue:]`.
     * @details Creates a formatted string for an array of items. The list formatter uses 'itemFormatter' to format each item in the array. If 'itemFormatter' doesn't apply to a particular item, the list formatter falls back to the item's 'description(withLocale:)' or 'localizedDescription' if implemented. If those methods aren't implemented, the formatter uses 'description' instead. - Parameters: - obj: An array of objects to format as a list. - Returns: A formatted string representing the list of objects in an array. Returns 'nil' if the formatter can't generate a description for all objects in the array, or if 'obj' is 'nil'.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_object_value(const Object& obj) const;
        /**
     * @brief Calls `-[NSListFormatter stringFromItems:]`.
     * @details Returns a string constructed from an array using the locale-aware format. Each item is formatted using the 'itemFormatter'. If the 'itemFormatter' does not apply to a particular item, the method will fall back to the item's 'descriptionWithLocale:' or 'localizedDescription' if implemented, or 'description' if not. Returns 'nil' if 'items' is 'nil' or if the list formatter cannot generate a string representation for all items in the array.
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_items(const std::vector<Object>& items) const;
        /**
     * @brief Returns the `itemFormatter` property of `NSListFormatter`.
     * @details Specifies how each object should be formatted. If not set, the object is formatted using its instance method in the following order: 'descriptionWithLocale:', 'localizedDescription', and 'description'.
     * @return The converted Objective-C result.
     */
        Formatter item_formatter() const;
        /**
     * @brief Sets the `itemFormatter` property of `NSListFormatter`.
     * @details Specifies how each object should be formatted. If not set, the object is formatted using its instance method in the following order: 'descriptionWithLocale:', 'localizedDescription', and 'description'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_formatter(const Formatter& value) const;
        /**
     * @brief Returns the `locale` property of `NSListFormatter`.
     * @details Specifies the locale to format the items. Defaults to 'autoupdatingCurrentLocale'. Also resets to 'autoupdatingCurrentLocale' on assignment of 'nil'.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSListFormatter`.
     * @details Specifies the locale to format the items. Defaults to 'autoupdatingCurrentLocale'. Also resets to 'autoupdatingCurrentLocale' on assignment of 'nil'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
    };
}
