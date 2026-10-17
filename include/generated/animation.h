#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSAnimation` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Animation animation;
     * animation.set_animation_blocking_mode(cocoon::AnimationBlockingMode::Blocking);
     * animation.did_stop().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Animation animation{};
     * animation.set_animation_blocking_mode(cocoon::AnimationBlockingMode::Blocking);
     * auto animation_blocking_mode = animation.animation_blocking_mode();
     * animation.set_animation_curve(cocoon::AnimationCurve::EaseInOut);
     * auto animation_curve = animation.animation_curve();
     * animation.set_current_progress(1);
     * auto current_progress = animation.current_progress();
     * animation.add_progress_mark(1);
     * animation.clear_start_animation();
     * animation.clear_stop_animation();
     * animation.did_stop().connect([]() {});
     * animation.did_end().connect([]() {});
     * animation.did_reach_progress_mark().connect([](float a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsanimation
     */
    class Animation : public Object
    {
    public:
        /// @brief Creates a new `NSAnimation` instance and returns a handle to it.
        explicit Animation(double duration, AnimationCurve animation_curve);
        /// @brief Creates a new `NSAnimation` instance and returns a handle to it.
        explicit Animation();
        /// @brief Creates a null handle that refers to no native object.
        Animation(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Animation(Adopt adopt);
        /**
     * @brief Calls `-[NSAnimation addProgressMark:]`.
     * @param progress_mark Argument converted to the Objective-C parameter of the same role.
     */
        void add_progress_mark(float progress_mark) const;
        /**
     * @brief Calls `-[NSAnimation clearStartAnimation]`.
     */
        void clear_start_animation() const;
        /**
     * @brief Calls `-[NSAnimation clearStopAnimation]`.
     */
        void clear_stop_animation() const;
        /**
     * @brief Calls `-[NSAnimation removeProgressMark:]`.
     * @param progress_mark Argument converted to the Objective-C parameter of the same role.
     */
        void remove_progress_mark(float progress_mark) const;
        /**
     * @brief Calls `-[NSAnimation startAnimation]`.
     */
        void start_animation() const;
        /**
     * @brief Calls `-[NSAnimation startWhenAnimation:reachesProgress:]`.
     * @param animation Argument converted to the Objective-C parameter of the same role.
     * @param start_progress Argument converted to the Objective-C parameter of the same role.
     */
        void start_when_animation(const Animation& animation, float start_progress) const;
        /**
     * @brief Calls `-[NSAnimation stopAnimation]`.
     */
        void stop_animation() const;
        /**
     * @brief Calls `-[NSAnimation stopWhenAnimation:reachesProgress:]`.
     * @param animation Argument converted to the Objective-C parameter of the same role.
     * @param stop_progress Argument converted to the Objective-C parameter of the same role.
     */
        void stop_when_animation(const Animation& animation, float stop_progress) const;
        /**
     * @brief Returns the `animating` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        bool is_animating() const;
        /**
     * @brief Returns the `animationBlockingMode` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        AnimationBlockingMode animation_blocking_mode() const;
        /**
     * @brief Sets the `animationBlockingMode` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_animation_blocking_mode(AnimationBlockingMode value) const;
        /**
     * @brief Returns the `animationCurve` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        AnimationCurve animation_curve() const;
        /**
     * @brief Sets the `animationCurve` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_animation_curve(AnimationCurve value) const;
        /**
     * @brief Returns the `currentProgress` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        float current_progress() const;
        /**
     * @brief Sets the `currentProgress` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_current_progress(float value) const;
        /**
     * @brief Returns the `currentValue` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        float current_value() const;
        /**
     * @brief Returns the `duration` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        double duration() const;
        /**
     * @brief Sets the `duration` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_duration(double value) const;
        /**
     * @brief Returns the `frameRate` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        float frame_rate() const;
        /**
     * @brief Sets the `frameRate` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame_rate(float value) const;
        /**
     * @brief Returns the `progressMarks` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        std::vector<Number> progress_marks() const;
        /**
     * @brief Sets the `progressMarks` property of `NSAnimation`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_progress_marks(const std::vector<Number>& value) const;
        /**
     * @brief Returns the `runLoopModesForAnimating` property of `NSAnimation`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> run_loop_modes_for_animating() const;
        /// @brief Signal for the delegate/data-source method behind `should_start`; connect a callback with `should_start().connect(...)`.
        Signal<Animation, bool()> should_start() const
        {
            return Signal<Animation, bool()>(handle(), "should_start");
        }
        /// @brief Signal for the delegate/data-source method behind `did_stop`; connect a callback with `did_stop().connect(...)`.
        Signal<Animation, void()> did_stop() const
        {
            return Signal<Animation, void()>(handle(), "did_stop");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end`; connect a callback with `did_end().connect(...)`.
        Signal<Animation, void()> did_end() const
        {
            return Signal<Animation, void()>(handle(), "did_end");
        }
        /// @brief Signal for the delegate/data-source method behind `value_for_progress`; connect a callback with `value_for_progress().connect(...)`.
        Signal<Animation, float(float)> value_for_progress() const
        {
            return Signal<Animation, float(float)>(handle(), "value_for_progress");
        }
        /// @brief Signal for the delegate/data-source method behind `did_reach_progress_mark`; connect a callback with `did_reach_progress_mark().connect(...)`.
        Signal<Animation, void(float)> did_reach_progress_mark() const
        {
            return Signal<Animation, void(float)>(handle(), "did_reach_progress_mark");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
