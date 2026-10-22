#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CharacterSet;

    /**
     * @brief C++ handle for the Objective-C class `NSLocale` (Foundation).
     * @details Information about linguistic, cultural, and technological conventions for use in formatting data for presentation. In Swift, this object bridges to ''Locale''; use ''NSLocale'' when you need reference semantics or other Foundation-specific behavior. You typically use a locale to format and interpret information about and according to the user's customs and preferences. You can initialize any number of locale instances with ''init(localeIdentifier:)'' using one of the locale identifiers found in the ''availableLocaleIdentifiers'' array. However, you usually use a locale configured to match the preferences of the current user. Use the ''current'' property to get the locale matching the current user's preferences. If you need to be alerted when the user does make changes to region settings, register for the ''currentLocaleDidChangeNotification'' notification. Alternatively, you can use the ''autoupdatingCurrent'' property to get a locale that automatically updates with the user's configuration settings: \@TabNavigator { \@Tab("Swift") { '''swift let locale = NSLocale.autoupdatingCurrent ''' } \@Tab("Objective-C") { '''objc NSLocale locale = [NSLocale autoupdatingCurrentLocale]; ''' } } You can inspect a locale by reading its properties, as listed in Getting Information About a Locale. For properties containing a code or identifier, you can then obtain a string suitable for presentation to the user with the methods listed in Getting Display Information About a Locale. For example, you can report the user's language as a string localized in that language using the autoupdating locale obtained in the previous example: \@TabNavigator { \@Tab("Swift") { '''swift let code = locale.languageCode! let language = locale.localizedString(forLanguageCode: code)! print("\\(language)") // Prints "English" for locale en_US, "français" for fr_FR ''' } \@Tab("Objective-C") { '''objc NSString code = locale.languageCode; NSString language = [locale localizedStringForLanguageCode:code]; NSLog(\@"\%\@",language); // Prints "English" for locale en_US, "français" for fr_FR ''' } } You frequently use a locale in conjunction with a formatter. For example, the ''DateFormatter'' class has a ''DateFormatter/locale'' property that ensures dates are converted to strings that match the user's expectations about date formatting. By default, this property indicates the user's current locale, which is usually the behavior you want, but you can instead set it to another locale instance to obtain a different output. See [Data Formatting Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DataFormatting/DataFormatting.html\#//apple_ref/doc/uid/10000029i) for more information about working with formatters. ''NSLocale'' is toll-free bridged with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cflocale>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''Locale'' structure, which bridges to the ''NSLocale'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Locale locale{"text"};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Locale locale{"text"};
     * locale.localized_string_for_calendar_identifier("text");
     * locale.localized_string_for_collation_identifier("text");
     * locale.localized_string_for_collator_identifier("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nslocale
     */
    class Locale : public Object
    {
    public:
        /// @brief Creates a new `NSLocale` instance and returns a handle to it.
        explicit Locale(const std::string& string);
        Locale();
        /// @brief Creates a null handle that refers to no native object.
        Locale(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Locale(Adopt adopt);
        /**
         * @brief Calls `+[NSLocale canonicalLanguageIdentifierFromString:]`.
         * @details Returns a canonical language identifier by mapping an arbitrary locale identification string to the canonical identifier.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string canonical_language_identifier_from_string(const std::string& string);
        /**
         * @brief Calls `+[NSLocale canonicalLocaleIdentifierFromString:]`.
         * @details Returns the canonical identifier for a given locale identification string.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string canonical_locale_identifier_from_string(const std::string& string);
        /**
         * @brief Calls `+[NSLocale characterDirectionForLanguage:]`.
         * @details Returns the direction of the sequence of characters in a line for the specified ISO language code.
         * @param iso_lang_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static LocaleLanguageDirection character_direction_for_language(const std::string& iso_lang_code);
        /**
         * @brief Calls `+[NSLocale componentsFromLocaleIdentifier:]`.
         * @details Returns a dictionary that is the result of parsing a locale ID.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::map<std::string, std::string> components_from_locale_identifier(const std::string& string);
        /**
         * @brief Calls `-[NSLocale displayNameForKey:value:]`.
         * @details Returns the display name for the given locale component value.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string display_name_for_key(const std::string& key, const Object& value) const;
        /**
         * @brief Calls `+[NSLocale lineDirectionForLanguage:]`.
         * @details Returns the direction of the sequence of lines for the specified ISO language code.
         * @param iso_lang_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static LocaleLanguageDirection line_direction_for_language(const std::string& iso_lang_code);
        /**
         * @brief Calls `+[NSLocale localeIdentifierFromComponents:]`.
         * @details Returns a locale identifier from the components specified in a given dictionary.
         * @param dict Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string locale_identifier_from_components(const std::map<std::string, std::string>& dict);
        /**
         * @brief Calls `+[NSLocale localeIdentifierFromWindowsLocaleCode:]`.
         * @details Returns a locale identifier from a Windows locale code.
         * @param lcid Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string locale_identifier_from_windows_locale_code(unsigned int lcid);
        /**
         * @brief Calls `-[NSLocale localizedStringForCalendarIdentifier:]`.
         * @details Returns a localized string for the specified calendar identifier.
         * @param calendar_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_calendar_identifier(const std::string& calendar_identifier) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForCollationIdentifier:]`.
         * @details Returns a localized string for the specified collation identifier.
         * @param collation_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_collation_identifier(const std::string& collation_identifier) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForCollatorIdentifier:]`.
         * @details Returns a localized string for the specified collator identifier.
         * @param collator_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_collator_identifier(const std::string& collator_identifier) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForCountryCode:]`.
         * @details Returns a localized string for the specified country or region code.
         * @param country_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_country_code(const std::string& country_code) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForCurrencyCode:]`.
         * @details Returns a localized string for the specified currency code.
         * @param currency_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_currency_code(const std::string& currency_code) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForLanguageCode:]`.
         * @details Returns a localized string for the specified language code.
         * @param language_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_language_code(const std::string& language_code) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForLocaleIdentifier:]`.
         * @details Returns a localized string for the specified locale identifier.
         * @param locale_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_locale_identifier(const std::string& locale_identifier) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForScriptCode:]`.
         * @details Returns a localized string for the specified script code.
         * @param script_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_script_code(const std::string& script_code) const;
        /**
         * @brief Calls `-[NSLocale localizedStringForVariantCode:]`.
         * @details Returns a localized string for the specified variant code.
         * @param variant_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string localized_string_for_variant_code(const std::string& variant_code) const;
        /**
         * @brief Calls `-[NSLocale objectForKey:]`.
         * @details Returns the object corresponding to the specified key.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& key) const;
        /**
         * @brief Calls `+[NSLocale windowsLocaleCodeFromLocaleIdentifier:]`.
         * @details Returns a Windows locale code from the locale identifier.
         * @param locale_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static unsigned int windows_locale_code_from_locale_identifier(const std::string& locale_identifier);
        /**
         * @brief Returns the `ISOCountryCodes` property of `NSLocale`.
         * @details An array of NSString objects that represents all known legal ISO country codes.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> iso_country_codes();
        /**
         * @brief Returns the `ISOCurrencyCodes` property of `NSLocale`.
         * @details An array of NSString objects that represents all known legal ISO currency codes.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> iso_currency_codes();
        /**
         * @brief Returns the `ISOLanguageCodes` property of `NSLocale`.
         * @details An array of NSString objects that represents all known legal ISO language codes.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> iso_language_codes();
        /**
         * @brief Returns the `alternateQuotationBeginDelimiter` property of `NSLocale`.
         * @details The begin quotation delimiter for the locale when using alternate quotation marks.
         * @return The converted Objective-C result.
         */
        std::string alternate_quotation_begin_delimiter() const;
        /**
         * @brief Returns the `alternateQuotationEndDelimiter` property of `NSLocale`.
         * @details The end quotation delimiter for the locale when using alternate quotation marks.
         * @return The converted Objective-C result.
         */
        std::string alternate_quotation_end_delimiter() const;
        /**
         * @brief Returns the `autoupdatingCurrentLocale` property of `NSLocale`.
         * @details A locale representing the user's region settings at the time the property is read.
         * @return The converted Objective-C result.
         */
        static Locale autoupdating_current_locale();
        /**
         * @brief Returns the `availableLocaleIdentifiers` property of `NSLocale`.
         * @details An array of NSString objects, each of which identifies a locale available on the system.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> available_locale_identifiers();
        /**
         * @brief Returns the `calendarIdentifier` property of `NSLocale`.
         * @details The calendar identifier for the locale.
         * @return The converted Objective-C result.
         */
        std::string calendar_identifier() const;
        /**
         * @brief Returns the `collationIdentifier` property of `NSLocale`.
         * @details The collation identifier for the locale.
         * @return The converted Objective-C result.
         */
        std::string collation_identifier() const;
        /**
         * @brief Returns the `collatorIdentifier` property of `NSLocale`.
         * @details The collator identifier for the locale.
         * @return The converted Objective-C result.
         */
        std::string collator_identifier() const;
        /**
         * @brief Returns the `commonISOCurrencyCodes` property of `NSLocale`.
         * @details An array of common ISO currency codes.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> common_iso_currency_codes();
        /**
         * @brief Returns the `countryCode` property of `NSLocale`.
         * @details The country or region code for the locale.
         * @return The converted Objective-C result.
         */
        std::string country_code() const;
        /**
         * @brief Returns the `currencyCode` property of `NSLocale`.
         * @details The currency code for the locale.
         * @return The converted Objective-C result.
         */
        std::string currency_code() const;
        /**
         * @brief Returns the `currencySymbol` property of `NSLocale`.
         * @details The currency symbol for the locale.
         * @return The converted Objective-C result.
         */
        std::string currency_symbol() const;
        /**
         * @brief Returns the `currentLocale` property of `NSLocale`.
         * @details An object representing the user's current locale.
         * @return The converted Objective-C result.
         */
        static Locale current_locale();
        /**
         * @brief Returns the `decimalSeparator` property of `NSLocale`.
         * @details The decimal separator for the locale.
         * @return The converted Objective-C result.
         */
        std::string decimal_separator() const;
        /**
         * @brief Returns the `exemplarCharacterSet` property of `NSLocale`.
         * @details The exemplar character set for the locale.
         * @return The converted Objective-C result.
         */
        CharacterSet exemplar_character_set() const;
        /**
         * @brief Returns the `groupingSeparator` property of `NSLocale`.
         * @details The grouping separator for the locale.
         * @return The converted Objective-C result.
         */
        std::string grouping_separator() const;
        /**
         * @brief Returns the `languageCode` property of `NSLocale`.
         * @details The language code for the locale.
         * @return The converted Objective-C result.
         */
        std::string language_code() const;
        /**
         * @brief Returns the `languageIdentifier` property of `NSLocale`.
         * @details Returns the identifier for the language part of the locale. For example, returns "en-US" for "en_US\@rg=gbzzzz" locale.
         * @return The converted Objective-C result.
         */
        std::string language_identifier() const;
        /**
         * @brief Returns the `localeIdentifier` property of `NSLocale`.
         * @details The identifier for the locale.
         * @return The converted Objective-C result.
         */
        std::string locale_identifier() const;
        /**
         * @brief Returns the `preferredLanguages` property of `NSLocale`.
         * @details An ordered list of the user's preferred languages.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> preferred_languages();
        /**
         * @brief Returns the `quotationBeginDelimiter` property of `NSLocale`.
         * @details The begin quotation delimiter for the locale.
         * @return The converted Objective-C result.
         */
        std::string quotation_begin_delimiter() const;
        /**
         * @brief Returns the `quotationEndDelimiter` property of `NSLocale`.
         * @details The end quotation delimiter for the locale.
         * @return The converted Objective-C result.
         */
        std::string quotation_end_delimiter() const;
        /**
         * @brief Returns the `regionCode` property of `NSLocale`.
         * @details Returns the region code of the locale. If the 'rg' subtag is present, the value of the subtag will be used. For example, returns "GB" for "en_US\@rg=gbzzzz" locale. If the 'localeIdentifier' doesn’t contain a region, returns 'nil'.
         * @return The converted Objective-C result.
         */
        std::string region_code() const;
        /**
         * @brief Returns the `scriptCode` property of `NSLocale`.
         * @details The script code for the locale.
         * @return The converted Objective-C result.
         */
        std::string script_code() const;
        /**
         * @brief Returns the `systemLocale` property of `NSLocale`.
         * @details The default generic root locale with little localization.
         * @return The converted Objective-C result.
         */
        static Locale system_locale();
        /**
         * @brief Returns the `usesMetricSystem` property of `NSLocale`.
         * @details A Boolean value that indicates whether the locale uses the metric system.
         * @return The converted Objective-C result.
         */
        bool uses_metric_system() const;
        /**
         * @brief Returns the `variantCode` property of `NSLocale`.
         * @details The variant code for the locale.
         * @return The converted Objective-C result.
         */
        std::string variant_code() const;
    };
}
