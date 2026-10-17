#include "generated/locale.h"
#include "internal.h"

namespace cocoon
{
    Locale::Locale(const std::string& string) : Locale(Adopt{cocoon::internal::retain([[::NSLocale alloc] initWithLocaleIdentifier:cocoon::internal::to(string)])})
    {
    }

    Locale::Locale() : Object(nullptr)
    {
    }

    Locale::Locale(std::nullptr_t) : Object(nullptr)
    {
    }

    Locale::Locale(Adopt adopt) : Object(adopt)
    {
    }

    std::string Locale::canonical_language_identifier_from_string(const std::string& string)
    {
        return cocoon::internal::from([::NSLocale canonicalLanguageIdentifierFromString:cocoon::internal::to(string)]);
    }

    std::string Locale::canonical_locale_identifier_from_string(const std::string& string)
    {
        return cocoon::internal::from([::NSLocale canonicalLocaleIdentifierFromString:cocoon::internal::to(string)]);
    }

    LocaleLanguageDirection Locale::character_direction_for_language(const std::string& iso_lang_code)
    {
        return static_cast<LocaleLanguageDirection>([::NSLocale characterDirectionForLanguage:cocoon::internal::to(iso_lang_code)]);
    }

    std::map<std::string, std::string> Locale::components_from_locale_identifier(const std::string& string)
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([::NSLocale componentsFromLocaleIdentifier:cocoon::internal::to(string)], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    std::string Locale::display_name_for_key(const std::string& key, const Object& value) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) displayNameForKey:cocoon::internal::to(key) value:cocoon::internal::native_id(value)]);
    }

    LocaleLanguageDirection Locale::line_direction_for_language(const std::string& iso_lang_code)
    {
        return static_cast<LocaleLanguageDirection>([::NSLocale lineDirectionForLanguage:cocoon::internal::to(iso_lang_code)]);
    }

    std::string Locale::locale_identifier_from_components(const std::map<std::string, std::string>& dict)
    {
        return cocoon::internal::from([::NSLocale localeIdentifierFromComponents:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const std::string& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(v);
                                                                                     })]);
    }

    std::string Locale::locale_identifier_from_windows_locale_code(unsigned int lcid)
    {
        return cocoon::internal::from([::NSLocale localeIdentifierFromWindowsLocaleCode:static_cast<::uint32_t>(lcid)]);
    }

    Locale Locale::locale_with_locale_identifier(const std::string& ident)
    {
        return cocoon::internal::wrap<Locale>([::NSLocale localeWithLocaleIdentifier:cocoon::internal::to(ident)]);
    }

    std::string Locale::localized_string_for_calendar_identifier(const std::string& calendar_identifier) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForCalendarIdentifier:cocoon::internal::to(calendar_identifier)]);
    }

    std::string Locale::localized_string_for_collation_identifier(const std::string& collation_identifier) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForCollationIdentifier:cocoon::internal::to(collation_identifier)]);
    }

    std::string Locale::localized_string_for_collator_identifier(const std::string& collator_identifier) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForCollatorIdentifier:cocoon::internal::to(collator_identifier)]);
    }

    std::string Locale::localized_string_for_country_code(const std::string& country_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForCountryCode:cocoon::internal::to(country_code)]);
    }

    std::string Locale::localized_string_for_currency_code(const std::string& currency_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForCurrencyCode:cocoon::internal::to(currency_code)]);
    }

    std::string Locale::localized_string_for_language_code(const std::string& language_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForLanguageCode:cocoon::internal::to(language_code)]);
    }

    std::string Locale::localized_string_for_locale_identifier(const std::string& locale_identifier) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForLocaleIdentifier:cocoon::internal::to(locale_identifier)]);
    }

    std::string Locale::localized_string_for_script_code(const std::string& script_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForScriptCode:cocoon::internal::to(script_code)]);
    }

    std::string Locale::localized_string_for_variant_code(const std::string& variant_code) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localizedStringForVariantCode:cocoon::internal::to(variant_code)]);
    }

    Object Locale::object_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSLocale>(this) objectForKey:cocoon::internal::to(key)]);
    }

    unsigned int Locale::windows_locale_code_from_locale_identifier(const std::string& locale_identifier)
    {
        return static_cast<unsigned int>([::NSLocale windowsLocaleCodeFromLocaleIdentifier:cocoon::internal::to(locale_identifier)]);
    }

    std::vector<std::string> Locale::iso_country_codes()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale ISOCountryCodes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Locale::iso_currency_codes()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale ISOCurrencyCodes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> Locale::iso_language_codes()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale ISOLanguageCodes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Locale::alternate_quotation_begin_delimiter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) alternateQuotationBeginDelimiter]);
    }

    std::string Locale::alternate_quotation_end_delimiter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) alternateQuotationEndDelimiter]);
    }

    Locale Locale::autoupdating_current_locale()
    {
        return cocoon::internal::wrap<Locale>([::NSLocale autoupdatingCurrentLocale]);
    }

    std::vector<std::string> Locale::available_locale_identifiers()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale availableLocaleIdentifiers], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Locale::calendar_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) calendarIdentifier]);
    }

    std::string Locale::collation_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) collationIdentifier]);
    }

    std::string Locale::collator_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) collatorIdentifier]);
    }

    std::vector<std::string> Locale::common_iso_currency_codes()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale commonISOCurrencyCodes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Locale::country_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) countryCode]);
    }

    std::string Locale::currency_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) currencyCode]);
    }

    std::string Locale::currency_symbol() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) currencySymbol]);
    }

    Locale Locale::current_locale()
    {
        return cocoon::internal::wrap<Locale>([::NSLocale currentLocale]);
    }

    std::string Locale::decimal_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) decimalSeparator]);
    }

    CharacterSet Locale::exemplar_character_set() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSLocale>(this) exemplarCharacterSet]);
    }

    std::string Locale::grouping_separator() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) groupingSeparator]);
    }

    std::string Locale::language_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) languageCode]);
    }

    std::string Locale::language_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) languageIdentifier]);
    }

    std::string Locale::locale_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) localeIdentifier]);
    }

    std::vector<std::string> Locale::preferred_languages()
    {
        return cocoon::internal::from_array<std::string>([::NSLocale preferredLanguages], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::string Locale::quotation_begin_delimiter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) quotationBeginDelimiter]);
    }

    std::string Locale::quotation_end_delimiter() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) quotationEndDelimiter]);
    }

    std::string Locale::region_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) regionCode]);
    }

    std::string Locale::script_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) scriptCode]);
    }

    Locale Locale::system_locale()
    {
        return cocoon::internal::wrap<Locale>([::NSLocale systemLocale]);
    }

    bool Locale::uses_metric_system() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLocale>(this) usesMetricSystem]);
    }

    std::string Locale::variant_code() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLocale>(this) variantCode]);
    }
}
