#include "generated/positional_specifier.h"
#include "internal.h"

namespace cocoon
{
    PositionalSpecifier::PositionalSpecifier(InsertionPosition position, const ScriptObjectSpecifier& specifier) : PositionalSpecifier(Adopt{cocoon::internal::retain([[::NSPositionalSpecifier alloc] initWithPosition:static_cast<::NSInsertionPosition>(position) objectSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(specifier)])})
    {
    }

    PositionalSpecifier::PositionalSpecifier() : PositionalSpecifier(Adopt{cocoon::internal::retain([[::NSPositionalSpecifier alloc] init])})
    {
    }

    PositionalSpecifier::PositionalSpecifier(std::nullptr_t) : Object(nullptr)
    {
    }

    PositionalSpecifier::PositionalSpecifier(Adopt adopt) : Object(adopt)
    {
    }

    void PositionalSpecifier::evaluate() const
    {
        [cocoon::internal::ns<::NSPositionalSpecifier>(this) evaluate];
    }

    void PositionalSpecifier::set_insertion_class_description(const ScriptClassDescription& class_description) const
    {
        [cocoon::internal::ns<::NSPositionalSpecifier>(this) setInsertionClassDescription:cocoon::internal::native<::NSScriptClassDescription>(class_description)];
    }

    Object PositionalSpecifier::insertion_container() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSPositionalSpecifier>(this) insertionContainer]);
    }

    std::int64_t PositionalSpecifier::insertion_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPositionalSpecifier>(this) insertionIndex]);
    }

    std::string PositionalSpecifier::insertion_key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPositionalSpecifier>(this) insertionKey]);
    }

    bool PositionalSpecifier::insertion_replaces() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSPositionalSpecifier>(this) insertionReplaces]);
    }

    ScriptObjectSpecifier PositionalSpecifier::object_specifier() const
    {
        return cocoon::internal::wrap<ScriptObjectSpecifier>([cocoon::internal::ns<::NSPositionalSpecifier>(this) objectSpecifier]);
    }

    InsertionPosition PositionalSpecifier::position() const
    {
        return static_cast<InsertionPosition>([cocoon::internal::ns<::NSPositionalSpecifier>(this) position]);
    }
}
