#include "generated/accessibility_element.h"
#include "internal.h"

namespace cocoon
{
    AccessibilityElement::AccessibilityElement() : AccessibilityElement(Adopt{cocoon::internal::retain([[::NSAccessibilityElement alloc] init])})
    {
    }

    AccessibilityElement::AccessibilityElement(std::nullptr_t) : Object(nullptr)
    {
    }

    AccessibilityElement::AccessibilityElement(Adopt adopt) : Object(adopt)
    {
    }

    void AccessibilityElement::accessibility_add_child_element(const AccessibilityElement& child_element) const
    {
        [cocoon::internal::ns<::NSAccessibilityElement>(this) accessibilityAddChildElement:cocoon::internal::native<::NSAccessibilityElement>(child_element)];
    }

    Object AccessibilityElement::accessibility_element_with_role(const std::string& role, const Rect& frame, const std::string& label, const Object& parent)
    {
        return cocoon::internal::wrap<Object>([::NSAccessibilityElement accessibilityElementWithRole:cocoon::internal::to(role) frame:cocoon::internal::to(frame) label:cocoon::internal::to(label) parent:cocoon::internal::native_id(parent)]);
    }

    Rect AccessibilityElement::accessibility_frame_in_parent_space() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAccessibilityElement>(this) accessibilityFrameInParentSpace]);
    }

    void AccessibilityElement::set_accessibility_frame_in_parent_space(const Rect& value) const
    {
        [cocoon::internal::ns<::NSAccessibilityElement>(this) setAccessibilityFrameInParentSpace:cocoon::internal::to(value)];
    }
}
