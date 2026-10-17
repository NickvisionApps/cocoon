#include "generated/scroll_edge_effect_style.h"
#include "internal.h"

namespace cocoon
{
    ScrollEdgeEffectStyle::ScrollEdgeEffectStyle() : Object(nullptr)
    {
    }

    ScrollEdgeEffectStyle::ScrollEdgeEffectStyle(std::nullptr_t) : Object(nullptr)
    {
    }

    ScrollEdgeEffectStyle::ScrollEdgeEffectStyle(Adopt adopt) : Object(adopt)
    {
    }

    ScrollEdgeEffectStyle ScrollEdgeEffectStyle::automatic_style()
    {
        if (@available(macOS 26.1, *))
        {
            return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle automaticStyle]);
        }
        return ScrollEdgeEffectStyle(nullptr);
    }

    ScrollEdgeEffectStyle ScrollEdgeEffectStyle::hard_style()
    {
        if (@available(macOS 26.1, *))
        {
            return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle hardStyle]);
        }
        return ScrollEdgeEffectStyle(nullptr);
    }

    ScrollEdgeEffectStyle ScrollEdgeEffectStyle::soft_style()
    {
        if (@available(macOS 26.1, *))
        {
            return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle softStyle]);
        }
        return ScrollEdgeEffectStyle(nullptr);
    }
}
