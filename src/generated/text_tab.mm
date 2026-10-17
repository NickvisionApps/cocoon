#include "generated/text_tab.h"
#include "internal.h"

namespace cocoon
{
    TextTab::TextTab(TextAlignment alignment, double loc, const std::map<std::string, Object>& options) : TextTab(Adopt{cocoon::internal::retain([[::NSTextTab alloc] initWithTextAlignment:static_cast<::NSTextAlignment>(alignment)
                                                                                                                                                                                   location:static_cast<::CGFloat>(loc)
                                                                                                                                                                                    options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                return cocoon::internal::to(k);
                                                                                                                                                                                                                            },
                                                                                                                                                                                                                            [](const Object& v) -> id
                                                                                                                                                                                                                            {
                                                                                                                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                                                                                                                            })])})
    {
    }

    TextTab::TextTab(TextTabType type, double loc) : TextTab(Adopt{cocoon::internal::retain([[::NSTextTab alloc] initWithType:static_cast<::NSTextTabType>(type) location:static_cast<::CGFloat>(loc)])})
    {
    }

    TextTab::TextTab() : TextTab(Adopt{cocoon::internal::retain([[::NSTextTab alloc] init])})
    {
    }

    TextTab::TextTab(std::nullptr_t) : Object(nullptr)
    {
    }

    TextTab::TextTab(Adopt adopt) : Object(adopt)
    {
    }

    CharacterSet TextTab::column_terminators_for_locale(const Locale& a_locale)
    {
        return cocoon::internal::wrap<CharacterSet>([::NSTextTab columnTerminatorsForLocale:cocoon::internal::native<::NSLocale>(a_locale)]);
    }

    TextAlignment TextTab::alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSTextTab>(this) alignment]);
    }

    double TextTab::location() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextTab>(this) location]);
    }

    std::map<std::string, Object> TextTab::options() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSTextTab>(this) options], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    TextTabType TextTab::tab_stop_type() const
    {
        return static_cast<TextTabType>([cocoon::internal::ns<::NSTextTab>(this) tabStopType]);
    }
}
