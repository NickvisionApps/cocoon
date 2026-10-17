#include "generated/level_indicator.h"
#include "internal.h"

namespace cocoon
{
    LevelIndicator::LevelIndicator() : LevelIndicator(Adopt{cocoon::internal::retain([[NSLevelIndicator alloc] init])})
    {
    }

    LevelIndicator::LevelIndicator(std::nullptr_t) : Control(nullptr)
    {
    }

    LevelIndicator::LevelIndicator(Adopt adopt) : Control(adopt)
    {
    }

    Rect LevelIndicator::rect_of_tick_mark_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLevelIndicator>(this) rectOfTickMarkAtIndex:static_cast<::NSInteger>(index)]);
    }

    double LevelIndicator::tick_mark_value_at_index(std::int64_t index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicator>(this) tickMarkValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    Color LevelIndicator::critical_fill_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSLevelIndicator>(this) criticalFillColor]);
    }

    void LevelIndicator::set_critical_fill_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setCriticalFillColor:cocoon::internal::native<::NSColor>(value)];
    }

    double LevelIndicator::critical_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicator>(this) criticalValue]);
    }

    void LevelIndicator::set_critical_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setCriticalValue:static_cast<double>(value)];
    }

    bool LevelIndicator::draws_tiered_capacity_levels() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLevelIndicator>(this) drawsTieredCapacityLevels]);
    }

    void LevelIndicator::set_draws_tiered_capacity_levels(bool value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setDrawsTieredCapacityLevels:static_cast<::BOOL>(value)];
    }

    bool LevelIndicator::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSLevelIndicator>(this) isEditable]);
    }

    void LevelIndicator::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setEditable:static_cast<::BOOL>(value)];
    }

    Color LevelIndicator::fill_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSLevelIndicator>(this) fillColor]);
    }

    void LevelIndicator::set_fill_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setFillColor:cocoon::internal::native<::NSColor>(value)];
    }

    LevelIndicatorStyle LevelIndicator::level_indicator_style() const
    {
        return static_cast<LevelIndicatorStyle>([cocoon::internal::ns<::NSLevelIndicator>(this) levelIndicatorStyle]);
    }

    void LevelIndicator::set_level_indicator_style(LevelIndicatorStyle value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setLevelIndicatorStyle:static_cast<::NSLevelIndicatorStyle>(value)];
    }

    double LevelIndicator::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicator>(this) maxValue]);
    }

    void LevelIndicator::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setMaxValue:static_cast<double>(value)];
    }

    double LevelIndicator::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicator>(this) minValue]);
    }

    void LevelIndicator::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setMinValue:static_cast<double>(value)];
    }

    std::int64_t LevelIndicator::number_of_major_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSLevelIndicator>(this) numberOfMajorTickMarks]);
    }

    void LevelIndicator::set_number_of_major_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setNumberOfMajorTickMarks:static_cast<::NSInteger>(value)];
    }

    std::int64_t LevelIndicator::number_of_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSLevelIndicator>(this) numberOfTickMarks]);
    }

    void LevelIndicator::set_number_of_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setNumberOfTickMarks:static_cast<::NSInteger>(value)];
    }

    LevelIndicatorPlaceholderVisibility LevelIndicator::placeholder_visibility() const
    {
        return static_cast<LevelIndicatorPlaceholderVisibility>([cocoon::internal::ns<::NSLevelIndicator>(this) placeholderVisibility]);
    }

    void LevelIndicator::set_placeholder_visibility(LevelIndicatorPlaceholderVisibility value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setPlaceholderVisibility:static_cast<::NSLevelIndicatorPlaceholderVisibility>(value)];
    }

    Image LevelIndicator::rating_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSLevelIndicator>(this) ratingImage]);
    }

    void LevelIndicator::set_rating_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setRatingImage:cocoon::internal::native<::NSImage>(value)];
    }

    Image LevelIndicator::rating_placeholder_image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSLevelIndicator>(this) ratingPlaceholderImage]);
    }

    void LevelIndicator::set_rating_placeholder_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setRatingPlaceholderImage:cocoon::internal::native<::NSImage>(value)];
    }

    TickMarkPosition LevelIndicator::tick_mark_position() const
    {
        return static_cast<TickMarkPosition>([cocoon::internal::ns<::NSLevelIndicator>(this) tickMarkPosition]);
    }

    void LevelIndicator::set_tick_mark_position(TickMarkPosition value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setTickMarkPosition:static_cast<::NSTickMarkPosition>(value)];
    }

    Color LevelIndicator::warning_fill_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSLevelIndicator>(this) warningFillColor]);
    }

    void LevelIndicator::set_warning_fill_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setWarningFillColor:cocoon::internal::native<::NSColor>(value)];
    }

    double LevelIndicator::warning_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicator>(this) warningValue]);
    }

    void LevelIndicator::set_warning_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicator>(this) setWarningValue:static_cast<double>(value)];
    }
}
