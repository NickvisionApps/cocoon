#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/formatter.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Locale;
    class PersonNameComponents;

    /**
     * @brief C++ handle for the Objective-C class `NSPersonNameComponentsFormatter` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Formatter.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PersonNameComponentsFormatter person_name_components_formatter;
     * person_name_components_formatter.set_locale(cocoon::Locale());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PersonNameComponentsFormatter person_name_components_formatter{};
     * person_name_components_formatter.set_locale(cocoon::Locale());
     * auto locale = person_name_components_formatter.locale();
     * person_name_components_formatter.set_phonetic(true);
     * auto phonetic = person_name_components_formatter.is_phonetic();
     * person_name_components_formatter.set_style(cocoon::PersonNameComponentsFormatterStyle::Default);
     * auto style = person_name_components_formatter.style();
     * person_name_components_formatter.annotated_string_from_person_name_components(cocoon::PersonNameComponents());
     * person_name_components_formatter.person_name_components_from_string("text");
     * person_name_components_formatter.string_from_person_name_components(cocoon::PersonNameComponents());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspersonnamecomponentsformatter
     */
    class PersonNameComponentsFormatter : public Formatter
    {
    public:
        /// @brief Creates a new `NSPersonNameComponentsFormatter` instance and returns a handle to it.
        explicit PersonNameComponentsFormatter();
        /// @brief Creates a null handle that refers to no native object.
        PersonNameComponentsFormatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PersonNameComponentsFormatter(Adopt adopt);
        /**
     * @brief Calls `-[NSPersonNameComponentsFormatter annotatedStringFromPersonNameComponents:]`.
     * @details Returns attributed string with annotations for each component. For each range, attributes can be obtained by querying dictionary key NSPersonNameComponentKey , using NSPersonNameComponent constant values.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AttributedString annotated_string_from_person_name_components(const PersonNameComponents& components) const;
        /**
     * @brief Calls `+[NSPersonNameComponentsFormatter localizedStringFromPersonNameComponents:style:options:]`.
     * @details Shortcut for converting an NSPersonNameComponents object into a string without explicitly creating an instance. Create an instance for greater customizability.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @param name_format_style Argument converted to the Objective-C parameter of the same role.
     * @param name_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_string_from_person_name_components(const PersonNameComponents& components, PersonNameComponentsFormatterStyle name_format_style, PersonNameComponentsFormatterOptions name_options);
        /**
     * @brief Calls `-[NSPersonNameComponentsFormatter personNameComponentsFromString:]`.
     * @details Convenience method on getObjectValue:forString:error:. Returns an NSPersonNameComponents object representing the name components found in the provided string.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        PersonNameComponents person_name_components_from_string(const std::string& string) const;
        /**
     * @brief Calls `-[NSPersonNameComponentsFormatter stringFromPersonNameComponents:]`.
     * @details Convenience method on stringForObjectValue:. Returns a string containing the formatted value of the provided components object.
     * @param components Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_from_person_name_components(const PersonNameComponents& components) const;
        /**
     * @brief Returns the `locale` property of `NSPersonNameComponentsFormatter`.
     * @details Specifies the locale to format names. Defaults to autoupdatingCurrentLocale. Also resets to autoupdatingCurrentLocale on assignment of nil.
     * @return The converted Objective-C result.
     */
        Locale locale() const;
        /**
     * @brief Sets the `locale` property of `NSPersonNameComponentsFormatter`.
     * @details Specifies the locale to format names. Defaults to autoupdatingCurrentLocale. Also resets to autoupdatingCurrentLocale on assignment of nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_locale(const Locale& value) const;
        /**
     * @brief Returns the `phonetic` property of `NSPersonNameComponentsFormatter`.
     * @details Specify that the formatter should only format the components object's phoneticRepresentation
     * @return The converted Objective-C result.
     */
        bool is_phonetic() const;
        /**
     * @brief Sets the `phonetic` property of `NSPersonNameComponentsFormatter`.
     * @details Specify that the formatter should only format the components object's phoneticRepresentation
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_phonetic(bool value) const;
        /**
     * @brief Returns the `style` property of `NSPersonNameComponentsFormatter`.
     * @details Specify the formatting style for the formatted string on an instance. ShortStyle will fall back to user preferences and language-specific defaults
     * @return The converted Objective-C result.
     */
        PersonNameComponentsFormatterStyle style() const;
        /**
     * @brief Sets the `style` property of `NSPersonNameComponentsFormatter`.
     * @details Specify the formatting style for the formatted string on an instance. ShortStyle will fall back to user preferences and language-specific defaults
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_style(PersonNameComponentsFormatterStyle value) const;
    };
}
