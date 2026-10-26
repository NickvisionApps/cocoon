#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextRange;
    class TextSelection;

    /**
     * @brief C++ handle for the Objective-C class `NSTextSelectionNavigation` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextSelectionNavigation text_selection_navigation(nullptr);  // null handle; instances normally come from other API calls
     * text_selection_navigation.set_allows_non_contiguous_ranges(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextSelectionNavigation text_selection_navigation(nullptr);
     * text_selection_navigation.set_allows_non_contiguous_ranges(true);
     * auto allows_non_contiguous_ranges = text_selection_navigation.allows_non_contiguous_ranges();
     * text_selection_navigation.set_rotates_coordinate_system_for_layout_orientation(true);
     * auto rotates_coordinate_system_for_layout_orientation = text_selection_navigation.rotates_coordinate_system_for_layout_orientation();
     * text_selection_navigation.deletion_ranges_for_text_selection(cocoon::TextSelection(), cocoon::TextSelectionNavigationDirection::Forward, cocoon::TextSelectionNavigationDestination::Character, true);
     * text_selection_navigation.destination_selection_for_text_selection(cocoon::TextSelection(), cocoon::TextSelectionNavigationDirection::Forward, cocoon::TextSelectionNavigationDestination::Character, true, true);
     * text_selection_navigation.flush_layout_cache();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextselectionnavigation
     */
    class TextSelectionNavigation : public Object
    {
    public:
        /// @brief Creates a new `NSTextSelectionNavigation` instance and returns a handle to it.
        explicit TextSelectionNavigation(const Object& data_source);
        TextSelectionNavigation();
        /// @brief Creates a null handle that refers to no native object.
        TextSelectionNavigation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextSelectionNavigation(Adopt adopt);
        /**
         * @brief Calls `-[NSTextSelectionNavigation deletionRangesForTextSelection:direction:destination:allowsDecomposition:]`.
         * @param text_selection Argument converted to the Objective-C parameter of the same role.
         * @param direction Argument converted to the Objective-C parameter of the same role.
         * @param destination Argument converted to the Objective-C parameter of the same role.
         * @param allows_decomposition Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<TextRange> deletion_ranges_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationDirection direction, TextSelectionNavigationDestination destination, bool allows_decomposition) const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation destinationSelectionForTextSelection:direction:destination:extending:confined:]`.
         * @param text_selection Argument converted to the Objective-C parameter of the same role.
         * @param direction Argument converted to the Objective-C parameter of the same role.
         * @param destination Argument converted to the Objective-C parameter of the same role.
         * @param extending Argument converted to the Objective-C parameter of the same role.
         * @param confined Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextSelection destination_selection_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationDirection direction, TextSelectionNavigationDestination destination, bool extending, bool confined) const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation flushLayoutCache]`.
         */
        void flush_layout_cache() const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation resolvedInsertionLocationForTextSelection:writingDirection:]`.
         * @param text_selection Argument converted to the Objective-C parameter of the same role.
         * @param writing_direction Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object resolved_insertion_location_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationWritingDirection writing_direction) const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation textSelectionForSelectionGranularity:enclosingPoint:inContainerAtLocation:]`.
         * @param selection_granularity Argument converted to the Objective-C parameter of the same role.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextSelection text_selection_for_selection_granularity(TextSelectionGranularity selection_granularity, const Point& point, const Object& location) const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation textSelectionForSelectionGranularity:enclosingTextSelection:]`.
         * @param selection_granularity Argument converted to the Objective-C parameter of the same role.
         * @param text_selection Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextSelection text_selection_for_selection_granularity(TextSelectionGranularity selection_granularity, const TextSelection& text_selection) const;
        /**
         * @brief Calls `-[NSTextSelectionNavigation textSelectionsInteractingAtPoint:inContainerAtLocation:anchors:modifiers:selecting:bounds:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param container_location Argument converted to the Objective-C parameter of the same role.
         * @param anchors Argument converted to the Objective-C parameter of the same role.
         * @param modifiers Argument converted to the Objective-C parameter of the same role.
         * @param selecting Argument converted to the Objective-C parameter of the same role.
         * @param bounds Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<TextSelection> text_selections_interacting_at_point(const Point& point, const Object& container_location, const std::vector<TextSelection>& anchors, TextSelectionNavigationModifier modifiers, bool selecting, const Rect& bounds) const;
        /**
         * @brief Returns the `allowsNonContiguousRanges` property of `NSTextSelectionNavigation`.
         * @return The converted Objective-C result.
         */
        bool allows_non_contiguous_ranges() const;
        /**
         * @brief Sets the `allowsNonContiguousRanges` property of `NSTextSelectionNavigation`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_non_contiguous_ranges(bool value) const;
        /**
         * @brief Returns the `rotatesCoordinateSystemForLayoutOrientation` property of `NSTextSelectionNavigation`.
         * @return The converted Objective-C result.
         */
        bool rotates_coordinate_system_for_layout_orientation() const;
        /**
         * @brief Sets the `rotatesCoordinateSystemForLayoutOrientation` property of `NSTextSelectionNavigation`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rotates_coordinate_system_for_layout_orientation(bool value) const;
    };
}
