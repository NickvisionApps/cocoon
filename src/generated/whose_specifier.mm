#include "generated/whose_specifier.h"
#include "internal.h"

namespace cocoon
{
    WhoseSpecifier::WhoseSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const ScriptWhoseTest& test) : WhoseSpecifier(Adopt{cocoon::internal::retain([[::NSWhoseSpecifier alloc] initWithContainerClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_desc) containerSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(container) key:cocoon::internal::to(property) test:cocoon::internal::native<::NSScriptWhoseTest>(test)])})
    {
    }

    WhoseSpecifier::WhoseSpecifier() : WhoseSpecifier(Adopt{cocoon::internal::retain([[::NSWhoseSpecifier alloc] init])})
    {
    }

    WhoseSpecifier::WhoseSpecifier(std::nullptr_t) : ScriptObjectSpecifier(nullptr)
    {
    }

    WhoseSpecifier::WhoseSpecifier(Adopt adopt) : ScriptObjectSpecifier(adopt)
    {
    }

    WhoseSubelementIdentifier WhoseSpecifier::end_subelement_identifier() const
    {
        return static_cast<WhoseSubelementIdentifier>([cocoon::internal::ns<::NSWhoseSpecifier>(this) endSubelementIdentifier]);
    }

    void WhoseSpecifier::set_end_subelement_identifier(WhoseSubelementIdentifier value) const
    {
        [cocoon::internal::ns<::NSWhoseSpecifier>(this) setEndSubelementIdentifier:static_cast<::NSWhoseSubelementIdentifier>(value)];
    }

    std::int64_t WhoseSpecifier::end_subelement_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWhoseSpecifier>(this) endSubelementIndex]);
    }

    void WhoseSpecifier::set_end_subelement_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSWhoseSpecifier>(this) setEndSubelementIndex:static_cast<::NSInteger>(value)];
    }

    WhoseSubelementIdentifier WhoseSpecifier::start_subelement_identifier() const
    {
        return static_cast<WhoseSubelementIdentifier>([cocoon::internal::ns<::NSWhoseSpecifier>(this) startSubelementIdentifier]);
    }

    void WhoseSpecifier::set_start_subelement_identifier(WhoseSubelementIdentifier value) const
    {
        [cocoon::internal::ns<::NSWhoseSpecifier>(this) setStartSubelementIdentifier:static_cast<::NSWhoseSubelementIdentifier>(value)];
    }

    std::int64_t WhoseSpecifier::start_subelement_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSWhoseSpecifier>(this) startSubelementIndex]);
    }

    void WhoseSpecifier::set_start_subelement_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSWhoseSpecifier>(this) setStartSubelementIndex:static_cast<::NSInteger>(value)];
    }

    ScriptWhoseTest WhoseSpecifier::test() const
    {
        return cocoon::internal::wrap<ScriptWhoseTest>([cocoon::internal::ns<::NSWhoseSpecifier>(this) test]);
    }

    void WhoseSpecifier::set_test(const ScriptWhoseTest& value) const
    {
        [cocoon::internal::ns<::NSWhoseSpecifier>(this) setTest:cocoon::internal::native<::NSScriptWhoseTest>(value)];
    }
}
