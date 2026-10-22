#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAccessibilityElement` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AccessibilityElement accessibility_element;
     * accessibility_element.set_accessibility_frame_in_parent_space({{0, 0}, {100, 100}});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AccessibilityElement accessibility_element{};
     * accessibility_element.set_accessibility_frame_in_parent_space({{0, 0}, {100, 100}});
     * auto accessibility_frame_in_parent_space = accessibility_element.accessibility_frame_in_parent_space();
     * accessibility_element.accessibility_add_child_element(cocoon::AccessibilityElement());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsaccessibilityelement
     */
    class AccessibilityElement : public Object
    {
    public:
        /// @brief Creates a new `NSAccessibilityElement` instance and returns a handle to it.
        explicit AccessibilityElement();
        /// @brief Creates a null handle that refers to no native object.
        AccessibilityElement(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AccessibilityElement(Adopt adopt);
        /**
         * @brief Calls `-[NSAccessibilityElement accessibilityAddChildElement:]`.
         * @param child_element Argument converted to the Objective-C parameter of the same role.
         */
        void accessibility_add_child_element(const AccessibilityElement& child_element) const;
        /**
         * @brief Calls `+[NSAccessibilityElement accessibilityElementWithRole:frame:label:parent:]`.
         * @param role Argument converted to the Objective-C parameter of the same role.
         * @param frame Argument converted to the Objective-C parameter of the same role.
         * @param label Argument converted to the Objective-C parameter of the same role.
         * @param parent Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object accessibility_element_with_role(const std::string& role, const Rect& frame, const std::string& label, const Object& parent);
        /**
         * @brief Returns the `accessibilityFrameInParentSpace` property of `NSAccessibilityElement`.
         * @return The converted Objective-C result.
         */
        Rect accessibility_frame_in_parent_space() const;
        /**
         * @brief Sets the `accessibilityFrameInParentSpace` property of `NSAccessibilityElement`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessibility_frame_in_parent_space(const Rect& value) const;
    };
}
