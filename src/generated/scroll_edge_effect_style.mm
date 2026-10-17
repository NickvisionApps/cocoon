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
        return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle automaticStyle]);
    }

    ScrollEdgeEffectStyle ScrollEdgeEffectStyle::hard_style()
    {
        return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle hardStyle]);
    }

    ScrollEdgeEffectStyle ScrollEdgeEffectStyle::soft_style()
    {
        return cocoon::internal::wrap<ScrollEdgeEffectStyle>([::NSScrollEdgeEffectStyle softStyle]);
    }
}
