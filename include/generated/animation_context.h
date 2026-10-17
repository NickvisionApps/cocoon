#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSAnimationContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AnimationContext animation_context;
     * animation_context.set_allows_implicit_animation(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AnimationContext animation_context{};
     * animation_context.set_allows_implicit_animation(true);
     * auto allows_implicit_animation = animation_context.allows_implicit_animation();
     * animation_context.set_duration(1);
     * auto duration = animation_context.duration();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsanimationcontext
     */
    class AnimationContext : public Object
    {
    public:
        /// @brief Creates a new `NSAnimationContext` instance and returns a handle to it.
        explicit AnimationContext();
        /// @brief Creates a null handle that refers to no native object.
        AnimationContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AnimationContext(Adopt adopt);
        /**
     * @brief Calls `+[NSAnimationContext beginGrouping]`.
     */
        static void begin_grouping();
        /**
     * @brief Calls `+[NSAnimationContext endGrouping]`.
     */
        static void end_grouping();
        /**
     * @brief Calls `+[NSAnimationContext runAnimationGroup:]`.
     * @param changes Argument converted to the Objective-C parameter of the same role.
     */
        static void run_animation_group(std::function<void(AnimationContext)> changes);
        /**
     * @brief Calls `+[NSAnimationContext runAnimationGroup:completionHandler:]`.
     * @param changes Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        static void run_animation_group(std::function<void(AnimationContext)> changes, std::function<void()> completion_handler);
        /**
     * @brief Returns the `allowsImplicitAnimation` property of `NSAnimationContext`.
     * @details Determine if animations are enabled or not. Using the -animator proxy will automatically set allowsImplicitAnimation to YES. When YES, other properties can implicitly animate along with the initially changed property. For instance, calling [[view animator] setFrame:frame] will allow subviews to also animate their frame positions. This is only applicable when layer backed on Mac OS 10.8 and later. The default value is NO.
     * @return The converted Objective-C result.
     */
        bool allows_implicit_animation() const;
        /**
     * @brief Sets the `allowsImplicitAnimation` property of `NSAnimationContext`.
     * @details Determine if animations are enabled or not. Using the -animator proxy will automatically set allowsImplicitAnimation to YES. When YES, other properties can implicitly animate along with the initially changed property. For instance, calling [[view animator] setFrame:frame] will allow subviews to also animate their frame positions. This is only applicable when layer backed on Mac OS 10.8 and later. The default value is NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_implicit_animation(bool value) const;
        /**
     * @brief Returns the `completionHandler` property of `NSAnimationContext`.
     * @return The converted Objective-C result.
     */
        std::function<void()> completion_handler() const;
        /**
     * @brief Sets the `completionHandler` property of `NSAnimationContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completion_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `currentContext` property of `NSAnimationContext`.
     * @return The converted Objective-C result.
     */
        static AnimationContext current_context();
        /**
     * @brief Returns the `duration` property of `NSAnimationContext`.
     * @return The converted Objective-C result.
     */
        double duration() const;
        /**
     * @brief Sets the `duration` property of `NSAnimationContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_duration(double value) const;
        /**
     * @brief Returns the `timingFunction` property of `NSAnimationContext`.
     * @return The converted Objective-C result.
     */
        Object timing_function() const;
        /**
     * @brief Sets the `timingFunction` property of `NSAnimationContext`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_timing_function(const Object& value) const;
    };
}
