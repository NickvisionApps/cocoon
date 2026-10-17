#include "generated/alignment_feedback_filter.h"
#include "internal.h"

namespace cocoon
{
    AlignmentFeedbackFilter::AlignmentFeedbackFilter() : AlignmentFeedbackFilter(Adopt{cocoon::internal::retain([[::NSAlignmentFeedbackFilter alloc] init])})
    {
    }

    AlignmentFeedbackFilter::AlignmentFeedbackFilter(std::nullptr_t) : Object(nullptr)
    {
    }

    AlignmentFeedbackFilter::AlignmentFeedbackFilter(Adopt adopt) : Object(adopt)
    {
    }

    Object AlignmentFeedbackFilter::alignment_feedback_token_for_horizontal_movement_in_view(const View& view, double previous_x, double aligned_x, double default_x) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) alignmentFeedbackTokenForHorizontalMovementInView:cocoon::internal::native<::NSView>(view) previousX:static_cast<::CGFloat>(previous_x) alignedX:static_cast<::CGFloat>(aligned_x) defaultX:static_cast<::CGFloat>(default_x)]);
    }

    Object AlignmentFeedbackFilter::alignment_feedback_token_for_movement_in_view(const View& view, const Point& previous_point, const Point& aligned_point, const Point& default_point) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) alignmentFeedbackTokenForMovementInView:cocoon::internal::native<::NSView>(view) previousPoint:cocoon::internal::to(previous_point) alignedPoint:cocoon::internal::to(aligned_point) defaultPoint:cocoon::internal::to(default_point)]);
    }

    Object AlignmentFeedbackFilter::alignment_feedback_token_for_vertical_movement_in_view(const View& view, double previous_y, double aligned_y, double default_y) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) alignmentFeedbackTokenForVerticalMovementInView:cocoon::internal::native<::NSView>(view) previousY:static_cast<::CGFloat>(previous_y) alignedY:static_cast<::CGFloat>(aligned_y) defaultY:static_cast<::CGFloat>(default_y)]);
    }

    void AlignmentFeedbackFilter::perform_feedback(const std::vector<Object>& alignment_feedback_tokens, HapticFeedbackPerformanceTime performance_time) const
    {
        [cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) performFeedback:cocoon::internal::to_array(alignment_feedback_tokens, [](const Object& e) -> id
                                                                                {
                                                                                    return cocoon::internal::native_id(e);
                                                                                })
                                                   performanceTime:static_cast<::NSHapticFeedbackPerformanceTime>(performance_time)];
    }

    void AlignmentFeedbackFilter::update_with_event(const Event& event) const
    {
        [cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) updateWithEvent:cocoon::internal::native<::NSEvent>(event)];
    }

    void AlignmentFeedbackFilter::update_with_pan_recognizer(const PanGestureRecognizer& pan_recognizer) const
    {
        [cocoon::internal::ns<::NSAlignmentFeedbackFilter>(this) updateWithPanRecognizer:cocoon::internal::native<::NSPanGestureRecognizer>(pan_recognizer)];
    }

    EventMask AlignmentFeedbackFilter::input_event_mask()
    {
        return static_cast<EventMask>([::NSAlignmentFeedbackFilter inputEventMask]);
    }
}
