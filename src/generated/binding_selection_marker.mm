#include "generated/binding_selection_marker.h"
#include "internal.h"

namespace cocoon
{
    BindingSelectionMarker::BindingSelectionMarker() : Object(nullptr)
    {
    }

    BindingSelectionMarker::BindingSelectionMarker(std::nullptr_t) : Object(nullptr)
    {
    }

    BindingSelectionMarker::BindingSelectionMarker(Adopt adopt) : Object(adopt)
    {
    }

    Object BindingSelectionMarker::default_placeholder_for_marker(const BindingSelectionMarker& marker, const std::string& object_class, const std::string& binding)
    {
        return cocoon::internal::wrap<Object>([::NSBindingSelectionMarker defaultPlaceholderForMarker:cocoon::internal::native<::NSBindingSelectionMarker>(marker) onClass:NSClassFromString(cocoon::internal::to(object_class)) withBinding:cocoon::internal::to(binding)]);
    }

    void BindingSelectionMarker::set_default_placeholder(const Object& placeholder, const BindingSelectionMarker& marker, const std::string& object_class, const std::string& binding)
    {
        [::NSBindingSelectionMarker setDefaultPlaceholder:cocoon::internal::native_id(placeholder) forMarker:cocoon::internal::native<::NSBindingSelectionMarker>(marker) onClass:NSClassFromString(cocoon::internal::to(object_class)) withBinding:cocoon::internal::to(binding)];
    }

    BindingSelectionMarker BindingSelectionMarker::multiple_values_selection_marker()
    {
        return cocoon::internal::wrap<BindingSelectionMarker>([::NSBindingSelectionMarker multipleValuesSelectionMarker]);
    }

    BindingSelectionMarker BindingSelectionMarker::no_selection_marker()
    {
        return cocoon::internal::wrap<BindingSelectionMarker>([::NSBindingSelectionMarker noSelectionMarker]);
    }

    BindingSelectionMarker BindingSelectionMarker::not_applicable_selection_marker()
    {
        return cocoon::internal::wrap<BindingSelectionMarker>([::NSBindingSelectionMarker notApplicableSelectionMarker]);
    }
}
