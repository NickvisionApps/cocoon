#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Progress;

    /**
     * @brief A progress bar or spinner.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::ProgressIndicator progress;
     * progress.set_max_value(100);
     * progress.set_double_value(40);
     * progress.start();
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ProgressIndicator progress_indicator{};
     * progress_indicator.set_control_size(cocoon::ControlSize::Regular);
     * auto control_size = progress_indicator.control_size();
     * progress_indicator.set_displayed_when_stopped(true);
     * auto displayed_when_stopped = progress_indicator.is_displayed_when_stopped();
     * progress_indicator.set_double_value(1);
     * auto double_value = progress_indicator.double_value();
     * progress_indicator.increment_by(1);
     * progress_indicator.size_to_fit();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsprogressindicator
     */
    class ProgressIndicator : public View
    {
    public:
        /// @brief Creates a new `NSProgressIndicator` instance and returns a handle to it.
        explicit ProgressIndicator();
        /// @brief Creates a null handle that refers to no native object.
        ProgressIndicator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ProgressIndicator(Adopt adopt);
        /**
         * @brief Calls `-[NSProgressIndicator incrementBy:]`.
         * @details Equivalent to [self setDoubleValue:[self doubleValue] + delta].
         * @param delta Argument converted to the Objective-C parameter of the same role.
         */
        void increment_by(double delta) const;
        /**
         * @brief Calls `-[NSProgressIndicator sizeToFit]`.
         * @details For the spinning style, it will size the view to its default size. For the bar style, the height will be set to the recommended height.
         */
        void size_to_fit() const;
        /**
         * @brief Calls `-[NSProgressIndicator startAnimation:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void start_animation(const Object& sender) const;
        /**
         * @brief Calls `-[NSProgressIndicator stopAnimation:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void stop_animation(const Object& sender) const;
        /**
         * @brief Returns the `controlSize` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        ControlSize control_size() const;
        /**
         * @brief Sets the `controlSize` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_control_size(ControlSize value) const;
        /**
         * @brief Returns the `displayedWhenStopped` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        bool is_displayed_when_stopped() const;
        /**
         * @brief Sets the `displayedWhenStopped` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_displayed_when_stopped(bool value) const;
        /**
         * @brief Returns the `doubleValue` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        double double_value() const;
        /**
         * @brief Sets the `doubleValue` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_double_value(double value) const;
        /**
         * @brief Returns the `indeterminate` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        bool is_indeterminate() const;
        /**
         * @brief Sets the `indeterminate` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_indeterminate(bool value) const;
        /**
         * @brief Returns the `maxValue` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        double max_value() const;
        /**
         * @brief Sets the `maxValue` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_value(double value) const;
        /**
         * @brief Returns the `minValue` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        double min_value() const;
        /**
         * @brief Sets the `minValue` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_value(double value) const;
        /**
         * @brief Returns the `observedProgress` property of `NSProgressIndicator`.
         * @details When set NSProgressIndicator will update doubleValue, minValue, maxValue, and indeterminate automatically.
         * @return The converted Objective-C result.
         */
        Progress observed_progress() const;
        /**
         * @brief Sets the `observedProgress` property of `NSProgressIndicator`.
         * @details When set NSProgressIndicator will update doubleValue, minValue, maxValue, and indeterminate automatically.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_observed_progress(const Progress& value) const;
        /**
         * @brief Returns the `style` property of `NSProgressIndicator`.
         * @return The converted Objective-C result.
         */
        ProgressIndicatorStyle style() const;
        /**
         * @brief Sets the `style` property of `NSProgressIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_style(ProgressIndicatorStyle value) const;
        /**
         * @brief Returns the `usesThreadedAnimation` property of `NSProgressIndicator`.
         * @details YES if the NSProgressIndicator uses a thread instead of a timer (defaults to YES).
         * @return The converted Objective-C result.
         */
        bool uses_threaded_animation() const;
        /**
         * @brief Sets the `usesThreadedAnimation` property of `NSProgressIndicator`.
         * @details YES if the NSProgressIndicator uses a thread instead of a timer (defaults to YES).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_threaded_animation(bool value) const;
        /// @brief Convenience helper `start` provided by cocoon.
        void start() const;
        /// @brief Convenience helper `stop` provided by cocoon.
        void stop() const;
    };
}
