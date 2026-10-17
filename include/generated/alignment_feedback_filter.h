#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Event;
    class PanGestureRecognizer;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSAlignmentFeedbackFilter` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AlignmentFeedbackFilter alignment_feedback_filter;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AlignmentFeedbackFilter alignment_feedback_filter{};
     * alignment_feedback_filter.alignment_feedback_token_for_horizontal_movement_in_view(cocoon::View(), 1, 1, 1);
     * alignment_feedback_filter.alignment_feedback_token_for_movement_in_view(cocoon::View(), {0, 0}, {0, 0}, {0, 0});
     * alignment_feedback_filter.alignment_feedback_token_for_vertical_movement_in_view(cocoon::View(), 1, 1, 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsalignmentfeedbackfilter
     */
    class AlignmentFeedbackFilter : public Object
    {
    public:
        /// @brief Creates a new `NSAlignmentFeedbackFilter` instance and returns a handle to it.
        explicit AlignmentFeedbackFilter();
        /// @brief Creates a null handle that refers to no native object.
        AlignmentFeedbackFilter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AlignmentFeedbackFilter(Adopt adopt);
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter alignmentFeedbackTokenForHorizontalMovementInView:previousX:alignedX:defaultX:]`.
     * @details Same as alignmentFeedbackTokenForMovementInView:previousPoint:alignedPoint:defaultPoint:, except that it ignores any vertical movement.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param previous_x Argument converted to the Objective-C parameter of the same role.
     * @param aligned_x Argument converted to the Objective-C parameter of the same role.
     * @param default_x Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object alignment_feedback_token_for_horizontal_movement_in_view(const View& view, double previous_x, double aligned_x, double default_x) const;
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter alignmentFeedbackTokenForMovementInView:previousPoint:alignedPoint:defaultPoint:]`.
     * @details Prepare haptic feedback for object movement due to alignment from one location to another. Returns a context object which may be performed later, or nil if no alignment should be performed. previousPoint must be the last location which the user saw the object at. alignedPoint must be the latest location if the alignment is allowed. defaultPoint must be the location which the item will be at if the alignment does not take effect. To prevent unnecessary haptic feedback to the user, it's important that the correct three locations are used.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param previous_point Argument converted to the Objective-C parameter of the same role.
     * @param aligned_point Argument converted to the Objective-C parameter of the same role.
     * @param default_point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object alignment_feedback_token_for_movement_in_view(const View& view, const Point& previous_point, const Point& aligned_point, const Point& default_point) const;
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter alignmentFeedbackTokenForVerticalMovementInView:previousY:alignedY:defaultY:]`.
     * @details Same as alignmentFeedbackTokenForMovementInView:previousPoint:alignedPoint:defaultPoint:, except that it ignores any horizontal movement.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param previous_y Argument converted to the Objective-C parameter of the same role.
     * @param aligned_y Argument converted to the Objective-C parameter of the same role.
     * @param default_y Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object alignment_feedback_token_for_vertical_movement_in_view(const View& view, double previous_y, double aligned_y, double default_y) const;
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter performFeedback:performanceTime:]`.
     * @details Performs haptic feedback described by one or more alignment feedback tokens, typically at most one per dimension. This should be called immediately before the updated location will be presented to the user.
     * @param alignment_feedback_tokens Argument converted to the Objective-C parameter of the same role.
     * @param performance_time Argument converted to the Objective-C parameter of the same role.
     */
        void perform_feedback(const std::vector<Object>& alignment_feedback_tokens, HapticFeedbackPerformanceTime performance_time) const;
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter updateWithEvent:]`.
     * @details Input a new event matching +inputEventMask.
     * @param event Argument converted to the Objective-C parameter of the same role.
     */
        void update_with_event(const Event& event) const;
        /**
     * @brief Calls `-[NSAlignmentFeedbackFilter updateWithPanRecognizer:]`.
     * @details Input events from a pan gesture recognizer. Use this instead of -updateWithEvent: if your event handling uses gesture recognizers.
     * @param pan_recognizer Argument converted to the Objective-C parameter of the same role.
     */
        void update_with_pan_recognizer(const PanGestureRecognizer& pan_recognizer) const;
        /**
     * @brief Returns the `inputEventMask` property of `NSAlignmentFeedbackFilter`.
     * @details The event mask indicating which event types the filter accepts. Suitable for use in tracking loops.
     * @return The converted Objective-C result.
     */
        static EventMask input_event_mask();
    };
}
