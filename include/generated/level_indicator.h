#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;

    /**
     * @brief A level / rating indicator.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::LevelIndicator level;
     * level.set_max_value(10);
     * level.set_double_value(7);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LevelIndicator level_indicator{};
     * level_indicator.set_critical_fill_color(cocoon::Color());
     * auto critical_fill_color = level_indicator.critical_fill_color();
     * level_indicator.set_critical_value(1);
     * auto critical_value = level_indicator.critical_value();
     * level_indicator.set_draws_tiered_capacity_levels(true);
     * auto draws_tiered_capacity_levels = level_indicator.draws_tiered_capacity_levels();
     * level_indicator.rect_of_tick_mark_at_index(1);
     * level_indicator.tick_mark_value_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslevelindicator
     */
    class LevelIndicator : public Control
    {
    public:
        /// @brief Creates a new `NSLevelIndicator` instance and returns a handle to it.
        explicit LevelIndicator();
        /// @brief Creates a null handle that refers to no native object.
        LevelIndicator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LevelIndicator(Adopt adopt);
        /**
         * @brief Calls `-[NSLevelIndicator rectOfTickMarkAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect rect_of_tick_mark_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSLevelIndicator tickMarkValueAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double tick_mark_value_at_index(std::int64_t index) const;
        /**
         * @brief Returns the `criticalFillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing values above the "critical" threshold. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @return The converted Objective-C result.
         */
        Color critical_fill_color() const;
        /**
         * @brief Sets the `criticalFillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing values above the "critical" threshold. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_critical_fill_color(const Color& value) const;
        /**
         * @brief Returns the `criticalValue` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        double critical_value() const;
        /**
         * @brief Sets the `criticalValue` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_critical_value(double value) const;
        /**
         * @brief Returns the `drawsTieredCapacityLevels` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        bool draws_tiered_capacity_levels() const;
        /**
         * @brief Sets the `drawsTieredCapacityLevels` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_tiered_capacity_levels(bool value) const;
        /**
         * @brief Returns the `editable` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        bool is_editable() const;
        /**
         * @brief Sets the `editable` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_editable(bool value) const;
        /**
         * @brief Returns the `fillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing the "normal" state, and by the rating indicator when drawing stars. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @return The converted Objective-C result.
         */
        Color fill_color() const;
        /**
         * @brief Sets the `fillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing the "normal" state, and by the rating indicator when drawing stars. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_fill_color(const Color& value) const;
        /**
         * @brief Returns the `levelIndicatorStyle` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        LevelIndicatorStyle level_indicator_style() const;
        /**
         * @brief Sets the `levelIndicatorStyle` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_level_indicator_style(LevelIndicatorStyle value) const;
        /**
         * @brief Returns the `maxValue` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        double max_value() const;
        /**
         * @brief Sets the `maxValue` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_max_value(double value) const;
        /**
         * @brief Returns the `minValue` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        double min_value() const;
        /**
         * @brief Sets the `minValue` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_min_value(double value) const;
        /**
         * @brief Returns the `numberOfMajorTickMarks` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_major_tick_marks() const;
        /**
         * @brief Sets the `numberOfMajorTickMarks` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_major_tick_marks(std::int64_t value) const;
        /**
         * @brief Returns the `numberOfTickMarks` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_tick_marks() const;
        /**
         * @brief Sets the `numberOfTickMarks` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_number_of_tick_marks(std::int64_t value) const;
        /**
         * @brief Returns the `placeholderVisibility` property of `NSLevelIndicator`.
         * @details For a rating-style indicator, sets the conditions under which rating placeholders are displayed. This property currently has no effect for other indicator styles. The default value is 'NSLevelIndicatorPlaceholderVisibilityAutomatic'.
         * @return The converted Objective-C result.
         */
        LevelIndicatorPlaceholderVisibility placeholder_visibility() const;
        /**
         * @brief Sets the `placeholderVisibility` property of `NSLevelIndicator`.
         * @details For a rating-style indicator, sets the conditions under which rating placeholders are displayed. This property currently has no effect for other indicator styles. The default value is 'NSLevelIndicatorPlaceholderVisibilityAutomatic'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_placeholder_visibility(LevelIndicatorPlaceholderVisibility value) const;
        /**
         * @brief Returns the `ratingImage` property of `NSLevelIndicator`.
         * @details Sets the image used by the rating indicator style in place of the default star image. The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        Image rating_image() const;
        /**
         * @brief Sets the `ratingImage` property of `NSLevelIndicator`.
         * @details Sets the image used by the rating indicator style in place of the default star image. The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rating_image(const Image& value) const;
        /**
         * @brief Returns the `ratingPlaceholderImage` property of `NSLevelIndicator`.
         * @details Sets the image used by the rating indicator style in place of the default faded placeholder image. If the custom placeholder is a template image, its fill opacity can be adjusted by modifying the opacity of the template image. If both a ''ratingImage'' and ''ratingPlaceholderImage'' are set, each rating position is sized such that either image will fit without scaling (i.e. sized to the maximum width and height of both images). The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        Image rating_placeholder_image() const;
        /**
         * @brief Sets the `ratingPlaceholderImage` property of `NSLevelIndicator`.
         * @details Sets the image used by the rating indicator style in place of the default faded placeholder image. If the custom placeholder is a template image, its fill opacity can be adjusted by modifying the opacity of the template image. If both a ''ratingImage'' and ''ratingPlaceholderImage'' are set, each rating position is sized such that either image will fit without scaling (i.e. sized to the maximum width and height of both images). The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rating_placeholder_image(const Image& value) const;
        /**
         * @brief Returns the `tickMarkPosition` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        TickMarkPosition tick_mark_position() const;
        /**
         * @brief Sets the `tickMarkPosition` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tick_mark_position(TickMarkPosition value) const;
        /**
         * @brief Returns the `warningFillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing values above the "warning" threshold. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @return The converted Objective-C result.
         */
        Color warning_fill_color() const;
        /**
         * @brief Sets the `warningFillColor` property of `NSLevelIndicator`.
         * @details Sets the fill color used by Continuous and Discrete Capacity indicators when drawing values above the "warning" threshold. The default value is a system-defined color which may vary between level indicator styles and OS releases.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_warning_fill_color(const Color& value) const;
        /**
         * @brief Returns the `warningValue` property of `NSLevelIndicator`.
         * @return The converted Objective-C result.
         */
        double warning_value() const;
        /**
         * @brief Sets the `warningValue` property of `NSLevelIndicator`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_warning_value(double value) const;
    };
}
