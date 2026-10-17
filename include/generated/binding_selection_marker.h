#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSBindingSelectionMarker` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BindingSelectionMarker binding_selection_marker(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbindingselectionmarker
     */
    class BindingSelectionMarker : public Object
    {
    public:
        BindingSelectionMarker();
        /// @brief Creates a null handle that refers to no native object.
        BindingSelectionMarker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BindingSelectionMarker(Adopt adopt);
        /**
     * @brief Calls `+[NSBindingSelectionMarker defaultPlaceholderForMarker:onClass:withBinding:]`.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     * @param object_class Argument converted to the Objective-C parameter of the same role.
     * @param binding Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object default_placeholder_for_marker(const BindingSelectionMarker& marker, const std::string& object_class, const std::string& binding);
        /**
     * @brief Calls `+[NSBindingSelectionMarker setDefaultPlaceholder:forMarker:onClass:withBinding:]`.
     * @param placeholder Argument converted to the Objective-C parameter of the same role.
     * @param marker Argument converted to the Objective-C parameter of the same role.
     * @param object_class Argument converted to the Objective-C parameter of the same role.
     * @param binding Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_placeholder(const Object& placeholder, const BindingSelectionMarker& marker, const std::string& object_class, const std::string& binding);
        /**
     * @brief Returns the `multipleValuesSelectionMarker` property of `NSBindingSelectionMarker`.
     * @return The converted Objective-C result.
     */
        static BindingSelectionMarker multiple_values_selection_marker();
        /**
     * @brief Returns the `noSelectionMarker` property of `NSBindingSelectionMarker`.
     * @return The converted Objective-C result.
     */
        static BindingSelectionMarker no_selection_marker();
        /**
     * @brief Returns the `notApplicableSelectionMarker` property of `NSBindingSelectionMarker`.
     * @return The converted Objective-C result.
     */
        static BindingSelectionMarker not_applicable_selection_marker();
    };
}
