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

#ifdef COCOON_MACOS_27
    void RefreshController::begin_refreshing() const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) beginRefreshing];
        }
    }

#endif

#ifdef COCOON_MACOS_27
    void RefreshController::end_refreshing() const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) endRefreshing];
        }
    }

#endif

#ifdef COCOON_MACOS_27
    std::string RefreshController::action() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSRefreshController>(this) action]));
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    void RefreshController::set_action(const std::string& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) setAction:NSSelectorFromString(cocoon::internal::to(value))];
        }
    }

#endif

#ifdef COCOON_MACOS_27
    AttributedString RefreshController::attributed_title() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSRefreshController>(this) attributedTitle]);
        }
        return AttributedString(nullptr);
    }

#endif

#ifdef COCOON_MACOS_27
    void RefreshController::set_attributed_title(const AttributedString& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) setAttributedTitle:cocoon::internal::native<::NSAttributedString>(value)];
        }
    }

#endif

#ifdef COCOON_MACOS_27
    bool RefreshController::is_refreshing() const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSRefreshController>(this) isRefreshing]);
        }
        return {};
    }

#endif

#ifdef COCOON_MACOS_27
    Object RefreshController::target() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSRefreshController>(this) target]);
        }
        return Object(nullptr);
    }

#endif

#ifdef COCOON_MACOS_27
    void RefreshController::set_target(const Object& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) setTarget:cocoon::internal::native_id(value)];
        }
    }

#endif

#ifdef COCOON_MACOS_27
    Color RefreshController::tint_color() const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSRefreshController>(this) tintColor]);
        }
        return Color(nullptr);
    }

#endif

#ifdef COCOON_MACOS_27
    void RefreshController::set_tint_color(const Color& value) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSRefreshController>(this) setTintColor:cocoon::internal::native<::NSColor>(value)];
        }
    }

#endif
}

#endif
