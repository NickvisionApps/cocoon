#include "generated/animation.h"
#include "internal.h"

@interface AKAnimationDelegate : NSObject <NSAnimationDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKAnimationDelegate

- (BOOL)animationShouldStart:(NSAnimation*)animation
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Animation, bool()>::emit((__bridge void*)strongHost, "should_start");
    return static_cast<::BOOL>(__r);
}

- (void)animationDidStop:(NSAnimation*)animation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Animation, void()>::emit((__bridge void*)strongHost, "did_stop");
}

- (void)animationDidEnd:(NSAnimation*)animation
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Animation, void()>::emit((__bridge void*)strongHost, "did_end");
}

- (float)animation:(NSAnimation*)animation valueForProgress:(NSAnimationProgress)progress
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Animation, float(float)>::emit((__bridge void*)strongHost, "value_for_progress", static_cast<float>(progress));
    return static_cast<float>(__r);
}

- (void)animation:(NSAnimation*)animation didReachProgressMark:(NSAnimationProgress)progress
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Animation, void(float)>::emit((__bridge void*)strongHost, "did_reach_progress_mark", static_cast<float>(progress));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(animationShouldStart:))
    {
        return strongHost && cocoon::Signal<cocoon::Animation, bool()>::connected((__bridge void*)strongHost, "should_start");
    }
    if (selector == @selector(animationDidStop:))
    {
        return strongHost && cocoon::Signal<cocoon::Animation, void()>::connected((__bridge void*)strongHost, "did_stop");
    }
    if (selector == @selector(animationDidEnd:))
    {
        return strongHost && cocoon::Signal<cocoon::Animation, void()>::connected((__bridge void*)strongHost, "did_end");
    }
    if (selector == @selector(animation:valueForProgress:))
    {
        return strongHost && cocoon::Signal<cocoon::Animation, float(float)>::connected((__bridge void*)strongHost, "value_for_progress");
    }
    if (selector == @selector(animation:didReachProgressMark:))
    {
        return strongHost && cocoon::Signal<cocoon::Animation, void(float)>::connected((__bridge void*)strongHost, "did_reach_progress_mark");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Animation::Animation(double duration, AnimationCurve animation_curve) : Animation(Adopt{cocoon::internal::retain([[::NSAnimation alloc] initWithDuration:static_cast<::NSTimeInterval>(duration) animationCurve:static_cast<::NSAnimationCurve>(animation_curve)])})
    {
        Animation::install_delegate_delegate_(handle());
    }

    Animation::Animation() : Animation(Adopt{cocoon::internal::retain([[::NSAnimation alloc] init])})
    {
        Animation::install_delegate_delegate_(handle());
    }

    Animation::Animation(std::nullptr_t) : Object(nullptr)
    {
    }

    Animation::Animation(Adopt adopt) : Object(adopt)
    {
    }

    void Animation::add_progress_mark(float progress_mark) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) addProgressMark:static_cast<::NSAnimationProgress>(progress_mark)];
    }

    void Animation::clear_start_animation() const
    {
        [cocoon::internal::ns<::NSAnimation>(this) clearStartAnimation];
    }

    void Animation::clear_stop_animation() const
    {
        [cocoon::internal::ns<::NSAnimation>(this) clearStopAnimation];
    }

    void Animation::remove_progress_mark(float progress_mark) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) removeProgressMark:static_cast<::NSAnimationProgress>(progress_mark)];
    }

    void Animation::start_animation() const
    {
        [cocoon::internal::ns<::NSAnimation>(this) startAnimation];
    }

    void Animation::start_when_animation(const Animation& animation, float start_progress) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) startWhenAnimation:cocoon::internal::native<::NSAnimation>(animation) reachesProgress:static_cast<::NSAnimationProgress>(start_progress)];
    }

    void Animation::stop_animation() const
    {
        [cocoon::internal::ns<::NSAnimation>(this) stopAnimation];
    }

    void Animation::stop_when_animation(const Animation& animation, float stop_progress) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) stopWhenAnimation:cocoon::internal::native<::NSAnimation>(animation) reachesProgress:static_cast<::NSAnimationProgress>(stop_progress)];
    }

    bool Animation::is_animating() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAnimation>(this) isAnimating]);
    }

    AnimationBlockingMode Animation::animation_blocking_mode() const
    {
        return static_cast<AnimationBlockingMode>([cocoon::internal::ns<::NSAnimation>(this) animationBlockingMode]);
    }

    void Animation::set_animation_blocking_mode(AnimationBlockingMode value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setAnimationBlockingMode:static_cast<::NSAnimationBlockingMode>(value)];
    }

    AnimationCurve Animation::animation_curve() const
    {
        return static_cast<AnimationCurve>([cocoon::internal::ns<::NSAnimation>(this) animationCurve]);
    }

    void Animation::set_animation_curve(AnimationCurve value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setAnimationCurve:static_cast<::NSAnimationCurve>(value)];
    }

    float Animation::current_progress() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSAnimation>(this) currentProgress]);
    }

    void Animation::set_current_progress(float value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setCurrentProgress:static_cast<::NSAnimationProgress>(value)];
    }

    float Animation::current_value() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSAnimation>(this) currentValue]);
    }

    double Animation::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSAnimation>(this) duration]);
    }

    void Animation::set_duration(double value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setDuration:static_cast<::NSTimeInterval>(value)];
    }

    float Animation::frame_rate() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSAnimation>(this) frameRate]);
    }

    void Animation::set_frame_rate(float value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setFrameRate:static_cast<float>(value)];
    }

    std::vector<Number> Animation::progress_marks() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSAnimation>(this) progressMarks], [](id e) -> Number
                                                    {
                                                        return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                                    });
    }

    void Animation::set_progress_marks(const std::vector<Number>& value) const
    {
        [cocoon::internal::ns<::NSAnimation>(this) setProgressMarks:cocoon::internal::to_array(value, [](const Number& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSNumber>(e);
                                                                                               })];
    }

    std::vector<std::string> Animation::run_loop_modes_for_animating() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSAnimation>(this) runLoopModesForAnimating], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void Animation::install_delegate_delegate_(void* native)
    {
        ::NSAnimation* host = (__bridge ::NSAnimation*)native;
        AKAnimationDelegate* delegate = [[AKAnimationDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSAnimation* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSAnimation* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
