#include "generated/action_cell.h"
#include "internal.h"

namespace cocoon
{
    ActionCell::ActionCell() : ActionCell(Adopt{cocoon::internal::retain([[::NSActionCell alloc] init])})
    {
    }

    ActionCell::ActionCell(std::nullptr_t) : Cell(nullptr)
    {
    }

    ActionCell::ActionCell(Adopt adopt) : Cell(adopt)
    {
    }

    std::string ActionCell::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSActionCell>(this) action]));
    }

    void ActionCell::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSActionCell>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    std::int64_t ActionCell::tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSActionCell>(this) tag]);
    }

    void ActionCell::set_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSActionCell>(this) setTag:static_cast<::NSInteger>(value)];
    }

    Object ActionCell::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSActionCell>(this) target]);
    }

    void ActionCell::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSActionCell>(this) setTarget:cocoon::internal::native_id(value)];
    }
}
