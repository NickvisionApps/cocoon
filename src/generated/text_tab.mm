#include "generated/text_tab.h"
#include "internal.h"

namespace cocoon
{
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
