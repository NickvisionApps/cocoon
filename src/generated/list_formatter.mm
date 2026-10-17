#include "generated/list_formatter.h"
#include "internal.h"

namespace cocoon
{
    ListFormatter::ListFormatter() : ListFormatter(Adopt{cocoon::internal::retain([[::NSListFormatter alloc] init])})
    {
    }

    ListFormatter::ListFormatter(std::nullptr_t) : Formatter(nullptr)
    {
    }

    ListFormatter::ListFormatter(Adopt adopt) : Formatter(adopt)
    {
    }

    std::string ListFormatter::localized_string_by_joining_strings(const std::vector<std::string>& strings)
    {
        return cocoon::internal::from([::NSListFormatter localizedStringByJoiningStrings:cocoon::internal::to_array(strings, [](const std::string& e) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::to(e);
                                                                                                                    })]);
    }

    std::string ListFormatter::string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSListFormatter>(this) stringForObjectValue:cocoon::internal::native_id(obj)]);
    }

    std::string ListFormatter::string_from_items(const std::vector<Object>& items) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSListFormatter>(this) stringFromItems:cocoon::internal::to_array(items, [](const Object& e) -> id
                                                                                                                                {
                                                                                                                                    return cocoon::internal::native_id(e);
                                                                                                                                })]);
    }

    Formatter ListFormatter::item_formatter() const
    {
        return cocoon::internal::wrap<Formatter>([cocoon::internal::ns<::NSListFormatter>(this) itemFormatter]);
    }

    void ListFormatter::set_item_formatter(const Formatter& value) const
    {
        [cocoon::internal::ns<::NSListFormatter>(this) setItemFormatter:cocoon::internal::native<::NSFormatter>(value)];
    }

    Locale ListFormatter::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSListFormatter>(this) locale]);
    }

    void ListFormatter::set_locale(const Locale& value) const
    {
        [cocoon::internal::ns<::NSListFormatter>(this) setLocale:cocoon::internal::native<::NSLocale>(value)];
    }
}
