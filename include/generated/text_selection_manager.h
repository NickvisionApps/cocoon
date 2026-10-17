#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DraggingSession;
    class GestureRecognizer;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextSelectionManager` (AppKit).
     * @details An object that coordinates text selection behavior for custom text views. ''NSTextSelectionManager'' provides a centralized way to manage text selection interactions using a set of gesture recognizers. For keyboard-based selection, integrate ''NSTextSelectionNavigation'' with your view. The selection manager works with a delegate to update and respond to selection changes, and with a data source to query the text layout system.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextSelectionManager text_selection_manager;
     * text_selection_manager.set_text_selection_mode(cocoon::TextSelectionMode::Editable);
     * text_selection_manager.selection_manager_will_begin_selection().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextSelectionManager text_selection_manager{};
     * text_selection_manager.set_text_selection_mode(cocoon::TextSelectionMode::Editable);
     * auto text_selection_mode = text_selection_manager.text_selection_mode();
     * text_selection_manager.selection_manager_will_begin_selection().connect([]() {});
     * text_selection_manager.selection_manager_did_end_selection().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextselectionmanager
     */
    class TextSelectionManager : public Object
    {
    public:
        /// @brief Creates a new `NSTextSelectionManager` instance and returns a handle to it.
        explicit TextSelectionManager();
        /// @brief Creates a null handle that refers to no native object.
        TextSelectionManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextSelectionManager(Adopt adopt);
        /**
     * @brief Returns the `gesturesForFailureRequirements` property of `NSTextSelectionManager`.
     * @details The gesture recognizers managed by the selection manager. Other gesture recognizers in the view hierarchy can declare dependencies on these gestures using 'requireGestureRecognizerToFail:' to ensure proper gesture recognition precedence.
     * @return The converted Objective-C result.
     */
        std::vector<GestureRecognizer> gestures_for_failure_requirements() const;
        /**
     * @brief Returns the `textSelectionMode` property of `NSTextSelectionManager`.
     * @details The interaction mode for text selection. Determines whether text is editable, selectable only, or non-interactive. The default value is 'NSTextSelectionModeEditable'.
     * @return The converted Objective-C result.
     */
        TextSelectionMode text_selection_mode() const;
        /**
     * @brief Sets the `textSelectionMode` property of `NSTextSelectionManager`.
     * @details The interaction mode for text selection. Determines whether text is editable, selectable only, or non-interactive. The default value is 'NSTextSelectionModeEditable'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_selection_mode(TextSelectionMode value) const;
        /// @brief Signal for the delegate/data-source method behind `selection_manager_should_begin_selection_at_point`; connect a callback with `selection_manager_should_begin_selection_at_point().connect(...)`.
        Signal<TextSelectionManager, bool(Point)> selection_manager_should_begin_selection_at_point() const
        {
            return Signal<TextSelectionManager, bool(Point)>(handle(), "selection_manager_should_begin_selection_at_point");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_manager_will_begin_selection`; connect a callback with `selection_manager_will_begin_selection().connect(...)`.
        Signal<TextSelectionManager, void()> selection_manager_will_begin_selection() const
        {
            return Signal<TextSelectionManager, void()>(handle(), "selection_manager_will_begin_selection");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_manager_did_end_selection`; connect a callback with `selection_manager_did_end_selection().connect(...)`.
        Signal<TextSelectionManager, void()> selection_manager_did_end_selection() const
        {
            return Signal<TextSelectionManager, void()>(handle(), "selection_manager_did_end_selection");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_manager_location_of_text_container_at_point`; connect a callback with `selection_manager_location_of_text_container_at_point().connect(...)`.
        Signal<TextSelectionManager, Object(Point)> selection_manager_location_of_text_container_at_point() const
        {
            return Signal<TextSelectionManager, Object(Point)>(handle(), "selection_manager_location_of_text_container_at_point");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_manager_frame_of_text_container_at_point`; connect a callback with `selection_manager_frame_of_text_container_at_point().connect(...)`.
        Signal<TextSelectionManager, Rect(Point)> selection_manager_frame_of_text_container_at_point() const
        {
            return Signal<TextSelectionManager, Rect(Point)>(handle(), "selection_manager_frame_of_text_container_at_point");
        }
        /// @brief Signal for the delegate/data-source method behind `selection_manager_make_dragging_session_with_gesture`; connect a callback with `selection_manager_make_dragging_session_with_gesture().connect(...)`.
        Signal<TextSelectionManager, DraggingSession(GestureRecognizer)> selection_manager_make_dragging_session_with_gesture() const
        {
            return Signal<TextSelectionManager, DraggingSession(GestureRecognizer)>(handle(), "selection_manager_make_dragging_session_with_gesture");
        }
        /// @brief Signal for the delegate/data-source method behind `enumerate_substrings_from_location_options_using_block`; connect a callback with `enumerate_substrings_from_location_options_using_block().connect(...)`.
        Signal<TextSelectionManager, void(StringEnumerationOptions, std::function<void(std::string, TextRange, TextRange, bool&)>)> enumerate_substrings_from_location_options_using_block() const
        {
            return Signal<TextSelectionManager, void(StringEnumerationOptions, std::function<void(std::string, TextRange, TextRange, bool&)>)>(handle(), "enumerate_substrings_from_location_options_using_block");
        }
        /// @brief Signal for the delegate/data-source method behind `text_range_for_selection_granularity_enclosing_location`; connect a callback with `text_range_for_selection_granularity_enclosing_location().connect(...)`.
        Signal<TextSelectionManager, TextRange(Object)> text_range_for_selection_granularity_enclosing_location() const
        {
            return Signal<TextSelectionManager, TextRange(Object)>(handle(), "text_range_for_selection_granularity_enclosing_location");
        }
        /// @brief Signal for the delegate/data-source method behind `location_from_location_with_offset`; connect a callback with `location_from_location_with_offset().connect(...)`.
        Signal<TextSelectionManager, Object(std::int64_t)> location_from_location_with_offset() const
        {
            return Signal<TextSelectionManager, Object(std::int64_t)>(handle(), "location_from_location_with_offset");
        }
        /// @brief Signal for the delegate/data-source method behind `offset_from_location_to_location`; connect a callback with `offset_from_location_to_location().connect(...)`.
        Signal<TextSelectionManager, std::int64_t(Object)> offset_from_location_to_location() const
        {
            return Signal<TextSelectionManager, std::int64_t(Object)>(handle(), "offset_from_location_to_location");
        }
        /// @brief Signal for the delegate/data-source method behind `base_writing_direction_at_location`; connect a callback with `base_writing_direction_at_location().connect(...)`.
        Signal<TextSelectionManager, TextSelectionNavigationWritingDirection()> base_writing_direction_at_location() const
        {
            return Signal<TextSelectionManager, TextSelectionNavigationWritingDirection()>(handle(), "base_writing_direction_at_location");
        }
        /// @brief Signal for the delegate/data-source method behind `enumerate_caret_offsets_in_line_fragment_at_location_using_block`; connect a callback with `enumerate_caret_offsets_in_line_fragment_at_location_using_block().connect(...)`.
        Signal<TextSelectionManager, void(std::function<void(double, Object, bool, bool&)>)> enumerate_caret_offsets_in_line_fragment_at_location_using_block() const
        {
            return Signal<TextSelectionManager, void(std::function<void(double, Object, bool, bool&)>)>(handle(), "enumerate_caret_offsets_in_line_fragment_at_location_using_block");
        }
        /// @brief Signal for the delegate/data-source method behind `line_fragment_range_for_point_in_container_at_location`; connect a callback with `line_fragment_range_for_point_in_container_at_location().connect(...)`.
        Signal<TextSelectionManager, TextRange(Object)> line_fragment_range_for_point_in_container_at_location() const
        {
            return Signal<TextSelectionManager, TextRange(Object)>(handle(), "line_fragment_range_for_point_in_container_at_location");
        }
        /// @brief Signal for the delegate/data-source method behind `enumerate_container_boundaries_from_location_reverse_using_block`; connect a callback with `enumerate_container_boundaries_from_location_reverse_using_block().connect(...)`.
        Signal<TextSelectionManager, void(bool, std::function<void(Object, bool&)>)> enumerate_container_boundaries_from_location_reverse_using_block() const
        {
            return Signal<TextSelectionManager, void(bool, std::function<void(Object, bool&)>)>(handle(), "enumerate_container_boundaries_from_location_reverse_using_block");
        }
        /// @brief Signal for the delegate/data-source method behind `text_layout_orientation_at_location`; connect a callback with `text_layout_orientation_at_location().connect(...)`.
        Signal<TextSelectionManager, TextSelectionNavigationLayoutOrientation()> text_layout_orientation_at_location() const
        {
            return Signal<TextSelectionManager, TextSelectionNavigationLayoutOrientation()>(handle(), "text_layout_orientation_at_location");
        }
        /// @brief Signal for the delegate/data-source method behind `convert_interaction_point_to_container_at_location`; connect a callback with `convert_interaction_point_to_container_at_location().connect(...)`.
        Signal<TextSelectionManager, Point(Object)> convert_interaction_point_to_container_at_location() const
        {
            return Signal<TextSelectionManager, Point(Object)>(handle(), "convert_interaction_point_to_container_at_location");
        }

    protected:
        static void install_delegate_delegate_(void* native);
        static void install_text_selection_data_source_delegate_(void* native);
    };
}
