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
     * auto made_0 = cocoon::Locale::locale_with_locale_identifier("text");
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
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string canonical_language_identifier_from_string(const std::string& string);
        /**
     * @brief Calls `+[NSLocale canonicalLocaleIdentifierFromString:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string canonical_locale_identifier_from_string(const std::string& string);
        /**
     * @brief Calls `+[NSLocale characterDirectionForLanguage:]`.
     * @param iso_lang_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static LocaleLanguageDirection character_direction_for_language(const std::string& iso_lang_code);
        /**
     * @brief Calls `+[NSLocale componentsFromLocaleIdentifier:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, std::string> components_from_locale_identifier(const std::string& string);
        /**
     * @brief Calls `-[NSLocale displayNameForKey:value:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string display_name_for_key(const std::string& key, const Object& value) const;
        /**
     * @brief Calls `+[NSLocale lineDirectionForLanguage:]`.
     * @param iso_lang_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static LocaleLanguageDirection line_direction_for_language(const std::string& iso_lang_code);
        /**
     * @brief Calls `+[NSLocale localeIdentifierFromComponents:]`.
     * @param dict Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string locale_identifier_from_components(const std::map<std::string, std::string>& dict);
        /**
     * @brief Calls `+[NSLocale localeIdentifierFromWindowsLocaleCode:]`.
     * @param lcid Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string locale_identifier_from_windows_locale_code(unsigned int lcid);
        /**
     * @brief Calls `+[NSLocale localeWithLocaleIdentifier:]`.
     * @param ident Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Locale locale_with_locale_identifier(const std::string& ident);
        /**
     * @brief Calls `-[NSLocale localizedStringForCalendarIdentifier:]`.
     * @param calendar_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_calendar_identifier(const std::string& calendar_identifier) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForCollationIdentifier:]`.
     * @param collation_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_collation_identifier(const std::string& collation_identifier) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForCollatorIdentifier:]`.
     * @param collator_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_collator_identifier(const std::string& collator_identifier) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForCountryCode:]`.
     * @param country_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_country_code(const std::string& country_code) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForCurrencyCode:]`.
     * @param currency_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_currency_code(const std::string& currency_code) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForLanguageCode:]`.
     * @param language_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_language_code(const std::string& language_code) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForLocaleIdentifier:]`.
     * @param locale_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_locale_identifier(const std::string& locale_identifier) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForScriptCode:]`.
     * @param script_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_script_code(const std::string& script_code) const;
        /**
     * @brief Calls `-[NSLocale localizedStringForVariantCode:]`.
     * @param variant_code Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_string_for_variant_code(const std::string& variant_code) const;
        /**
     * @brief Calls `-[NSLocale objectForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_for_key(const std::string& key) const;
        /**
     * @brief Calls `+[NSLocale windowsLocaleCodeFromLocaleIdentifier:]`.
     * @param locale_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static unsigned int windows_locale_code_from_locale_identifier(const std::string& locale_identifier);
        /**
     * @brief Returns the `ISOCountryCodes` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> iso_country_codes();
        /**
     * @brief Returns the `ISOCurrencyCodes` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> iso_currency_codes();
        /**
     * @brief Returns the `ISOLanguageCodes` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> iso_language_codes();
        /**
     * @brief Returns the `alternateQuotationBeginDelimiter` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string alternate_quotation_begin_delimiter() const;
        /**
     * @brief Returns the `alternateQuotationEndDelimiter` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string alternate_quotation_end_delimiter() const;
        /**
     * @brief Returns the `autoupdatingCurrentLocale` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static Locale autoupdating_current_locale();
        /**
     * @brief Returns the `availableLocaleIdentifiers` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> available_locale_identifiers();
        /**
     * @brief Returns the `calendarIdentifier` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string calendar_identifier() const;
        /**
     * @brief Returns the `collationIdentifier` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string collation_identifier() const;
        /**
     * @brief Returns the `collatorIdentifier` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string collator_identifier() const;
        /**
     * @brief Returns the `commonISOCurrencyCodes` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> common_iso_currency_codes();
        /**
     * @brief Returns the `countryCode` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string country_code() const;
        /**
     * @brief Returns the `currencyCode` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string currency_code() const;
        /**
     * @brief Returns the `currencySymbol` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string currency_symbol() const;
        /**
     * @brief Returns the `currentLocale` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static Locale current_locale();
        /**
     * @brief Returns the `decimalSeparator` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string decimal_separator() const;
        /**
     * @brief Returns the `exemplarCharacterSet` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        CharacterSet exemplar_character_set() const;
        /**
     * @brief Returns the `groupingSeparator` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string grouping_separator() const;
        /**
     * @brief Returns the `languageCode` property of `NSLocale`.
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
     * @return The converted Objective-C result.
     */
        std::string locale_identifier() const;
        /**
     * @brief Returns the `preferredLanguages` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> preferred_languages();
        /**
     * @brief Returns the `quotationBeginDelimiter` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string quotation_begin_delimiter() const;
        /**
     * @brief Returns the `quotationEndDelimiter` property of `NSLocale`.
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
     * @return The converted Objective-C result.
     */
        std::string script_code() const;
        /**
     * @brief Returns the `systemLocale` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        static Locale system_locale();
        /**
     * @brief Returns the `usesMetricSystem` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        bool uses_metric_system() const;
        /**
     * @brief Returns the `variantCode` property of `NSLocale`.
     * @return The converted Objective-C result.
     */
        std::string variant_code() const;
    };
}
