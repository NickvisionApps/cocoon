#include "generated/scanner.h"
#include "internal.h"

namespace cocoon
{
    Scanner::Scanner(const std::string& string) : Scanner(Adopt{cocoon::internal::retain([[::NSScanner alloc] initWithString:cocoon::internal::to(string)])})
    {
    }

    Scanner::Scanner() : Scanner(Adopt{cocoon::internal::retain([[::NSScanner alloc] init])})
    {
    }

    Scanner::Scanner(std::nullptr_t) : Object(nullptr)
    {
    }

    Scanner::Scanner(Adopt adopt) : Object(adopt)
    {
    }

    Object Scanner::localized_scanner_with_string(const std::string& string)
    {
        return cocoon::internal::wrap<Object>([::NSScanner localizedScannerWithString:cocoon::internal::to(string)]);
    }

    bool Scanner::scan_characters_from_set(const CharacterSet& set, std::string& result) const
    {
        NSString* __v_result = nil;
        auto __r = [cocoon::internal::ns<::NSScanner>(this) scanCharactersFromSet:cocoon::internal::native<::NSCharacterSet>(set) intoString:&__v_result];
        result = cocoon::internal::from(__v_result);
        return static_cast<bool>(__r);
    }

    bool Scanner::scan_decimal(Decimal* dcm) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanDecimal:(::NSDecimal*)(dcm)]);
    }

    bool Scanner::scan_double(double* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanDouble:(double*)(result)]);
    }

    bool Scanner::scan_float(float* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanFloat:(float*)(result)]);
    }

    bool Scanner::scan_hex_double(double* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanHexDouble:(double*)(result)]);
    }

    bool Scanner::scan_hex_float(float* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanHexFloat:(float*)(result)]);
    }

    bool Scanner::scan_hex_int(unsigned int* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanHexInt:(unsigned int*)(result)]);
    }

    bool Scanner::scan_hex_long_long(std::uint64_t* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanHexLongLong:(unsigned long long*)(result)]);
    }

    bool Scanner::scan_int(int* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanInt:(int*)(result)]);
    }

    bool Scanner::scan_integer(std::int64_t* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanInteger:(::NSInteger*)(result)]);
    }

    bool Scanner::scan_long_long(std::int64_t* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanLongLong:(long long*)(result)]);
    }

    bool Scanner::scan_string(const std::string& string, std::string& result) const
    {
        NSString* __v_result = nil;
        auto __r = [cocoon::internal::ns<::NSScanner>(this) scanString:cocoon::internal::to(string) intoString:&__v_result];
        result = cocoon::internal::from(__v_result);
        return static_cast<bool>(__r);
    }

    bool Scanner::scan_unsigned_long_long(std::uint64_t* result) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) scanUnsignedLongLong:(unsigned long long*)(result)]);
    }

    bool Scanner::scan_up_to_characters_from_set(const CharacterSet& set, std::string& result) const
    {
        NSString* __v_result = nil;
        auto __r = [cocoon::internal::ns<::NSScanner>(this) scanUpToCharactersFromSet:cocoon::internal::native<::NSCharacterSet>(set) intoString:&__v_result];
        result = cocoon::internal::from(__v_result);
        return static_cast<bool>(__r);
    }

    bool Scanner::scan_up_to_string(const std::string& string, std::string& result) const
    {
        NSString* __v_result = nil;
        auto __r = [cocoon::internal::ns<::NSScanner>(this) scanUpToString:cocoon::internal::to(string) intoString:&__v_result];
        result = cocoon::internal::from(__v_result);
        return static_cast<bool>(__r);
    }

    bool Scanner::is_at_end() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) isAtEnd]);
    }

    bool Scanner::case_sensitive() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScanner>(this) caseSensitive]);
    }

    void Scanner::set_case_sensitive(bool value) const
    {
        [cocoon::internal::ns<::NSScanner>(this) setCaseSensitive:static_cast<::BOOL>(value)];
    }

    CharacterSet Scanner::characters_to_be_skipped() const
    {
        return cocoon::internal::wrap<CharacterSet>([cocoon::internal::ns<::NSScanner>(this) charactersToBeSkipped]);
    }

    void Scanner::set_characters_to_be_skipped(const CharacterSet& value) const
    {
        [cocoon::internal::ns<::NSScanner>(this) setCharactersToBeSkipped:cocoon::internal::native<::NSCharacterSet>(value)];
    }

    Object Scanner::locale() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSScanner>(this) locale]);
    }

    void Scanner::set_locale(const Object& value) const
    {
        [cocoon::internal::ns<::NSScanner>(this) setLocale:cocoon::internal::native_id(value)];
    }

    std::uint64_t Scanner::scan_location() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSScanner>(this) scanLocation]);
    }

    void Scanner::set_scan_location(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSScanner>(this) setScanLocation:static_cast<::NSUInteger>(value)];
    }

    std::string Scanner::string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSScanner>(this) string]);
    }
}
