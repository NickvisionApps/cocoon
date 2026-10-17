#include "generated/refresh_controller.h"
#include "internal.h"

#ifdef COCOON_MACOS_27
namespace cocoon
{
    RefreshController::RefreshController() : RefreshController(Adopt{cocoon::internal::retain([[::NSRefreshController alloc] init])})
    {
    }

    RefreshController::RefreshController(std::nullptr_t) : Object(nullptr)
    {
    }

    RefreshController::RefreshController(Adopt adopt) : Object(adopt)
    {
    }

    void RefreshController::begin_refreshing() const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) beginRefreshing];
    }

    void RefreshController::end_refreshing() const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) endRefreshing];
    }

    std::string RefreshController::action() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSRefreshController>(this) action]));
    }

    void RefreshController::set_action(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
    }

    AttributedString RefreshController::attributed_title() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSRefreshController>(this) attributedTitle]);
    }

    void RefreshController::set_attributed_title(const AttributedString& value) const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
    }

    bool RefreshController::is_refreshing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRefreshController>(this) isRefreshing]);
    }

    Object RefreshController::target() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSRefreshController>(this) target]);
    }

    void RefreshController::set_target(const Object& value) const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) setTarget:cocoon::internal::native_id(value)];
    }

    Color RefreshController::tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSRefreshController>(this) tintColor]);
    }

    void RefreshController::set_tint_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSRefreshController>(this) setTintColor:cocoon::internal::native<::NSColor>(value)];
    }
}

#endif