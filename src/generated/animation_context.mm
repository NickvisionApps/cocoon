#include "generated/animation_context.h"
#include "internal.h"

namespace cocoon
{
    AnimationContext::AnimationContext() : AnimationContext(Adopt{cocoon::internal::retain([[::NSAnimationContext alloc] init])})
    {
    }

    AnimationContext::AnimationContext(std::nullptr_t) : Object(nullptr)
    {
    }

    AnimationContext::AnimationContext(Adopt adopt) : Object(adopt)
    {
    }

    void AnimationContext::begin_grouping()
    {
        [::NSAnimationContext beginGrouping];
    }

    void AnimationContext::end_grouping()
    {
        [::NSAnimationContext endGrouping];
    }

    void AnimationContext::run_animation_group(std::function<void(AnimationContext)> changes)
    {
        [::NSAnimationContext runAnimationGroup:(changes ? (void (^)(::NSAnimationContext*)) ^ void(::NSAnimationContext * a2_0) { changes(cocoon::internal::wrap<AnimationContext>(a2_0)); } : (void (^)(::NSAnimationContext*))nil)];
    }

    void AnimationContext::run_animation_group(std::function<void(AnimationContext)> changes, std::function<void()> completion_handler)
    {
        [::NSAnimationContext runAnimationGroup:(changes ? (void (^)(::NSAnimationContext*)) ^ void(::NSAnimationContext * a3_0) { changes(cocoon::internal::wrap<AnimationContext>(a3_0)); } : (void (^)(::NSAnimationContext*))nil) completionHandler:(completion_handler ? (void (^)(void)) ^ void() { completion_handler(); } : (void (^)(void))nil)];
    }

    bool AnimationContext::allows_implicit_animation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAnimationContext>(this) allowsImplicitAnimation]);
    }

    void AnimationContext::set_allows_implicit_animation(bool value) const
    {
        [cocoon::internal::ns<::NSAnimationContext>(this) setAllowsImplicitAnimation:static_cast<::BOOL>(value)];
    }

    std::function<void()> AnimationContext::completion_handler() const
    {
        return [&]() -> std::function<void()>
        {
            auto blk = (void (^)(void))([cocoon::internal::ns<::NSAnimationContext>(this) completionHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> void
            {
                blk();
            };
        }();
    }

    void AnimationContext::set_completion_handler(std::function<void()> value) const
    {
        [cocoon::internal::ns<::NSAnimationContext>(this) setCompletionHandler:(value ? (void (^)(void)) ^ void() { value(); } : (void (^)(void))nil)];
    }

    AnimationContext AnimationContext::current_context()
    {
        return cocoon::internal::wrap<AnimationContext>([::NSAnimationContext currentContext]);
    }

    double AnimationContext::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSAnimationContext>(this) duration]);
    }

    void AnimationContext::set_duration(double value) const
    {
        [cocoon::internal::ns<::NSAnimationContext>(this) setDuration:static_cast<::NSTimeInterval>(value)];
    }

    Object AnimationContext::timing_function() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSAnimationContext>(this) timingFunction]);
    }

    void AnimationContext::set_timing_function(const Object& value) const
    {
        [cocoon::internal::ns<::NSAnimationContext>(this) setTimingFunction:cocoon::internal::native_id(value)];
    }
}
