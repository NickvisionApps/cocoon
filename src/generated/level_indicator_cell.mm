#include "generated/level_indicator_cell.h"
#include "internal.h"

namespace cocoon
{
    LevelIndicatorCell::LevelIndicatorCell(LevelIndicatorStyle level_indicator_style) : LevelIndicatorCell(Adopt{cocoon::internal::retain([[::NSLevelIndicatorCell alloc] initWithLevelIndicatorStyle:static_cast<::NSLevelIndicatorStyle>(level_indicator_style)])})
    {
    }

    LevelIndicatorCell::LevelIndicatorCell() : LevelIndicatorCell(Adopt{cocoon::internal::retain([[::NSLevelIndicatorCell alloc] init])})
    {
    }

    LevelIndicatorCell::LevelIndicatorCell(std::nullptr_t) : ActionCell(nullptr)
    {
    }

    LevelIndicatorCell::LevelIndicatorCell(Adopt adopt) : ActionCell(adopt)
    {
    }

    Rect LevelIndicatorCell::rect_of_tick_mark_at_index(std::int64_t index) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSLevelIndicatorCell>(this) rectOfTickMarkAtIndex:static_cast<::NSInteger>(index)]);
    }

    double LevelIndicatorCell::tick_mark_value_at_index(std::int64_t index) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) tickMarkValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    double LevelIndicatorCell::critical_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) criticalValue]);
    }

    void LevelIndicatorCell::set_critical_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setCriticalValue:static_cast<double>(value)];
    }

    LevelIndicatorStyle LevelIndicatorCell::level_indicator_style() const
    {
        return static_cast<LevelIndicatorStyle>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) levelIndicatorStyle]);
    }

    void LevelIndicatorCell::set_level_indicator_style(LevelIndicatorStyle value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setLevelIndicatorStyle:static_cast<::NSLevelIndicatorStyle>(value)];
    }

    double LevelIndicatorCell::max_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) maxValue]);
    }

    void LevelIndicatorCell::set_max_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setMaxValue:static_cast<double>(value)];
    }

    double LevelIndicatorCell::min_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) minValue]);
    }

    void LevelIndicatorCell::set_min_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setMinValue:static_cast<double>(value)];
    }

    std::int64_t LevelIndicatorCell::number_of_major_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) numberOfMajorTickMarks]);
    }

    void LevelIndicatorCell::set_number_of_major_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setNumberOfMajorTickMarks:static_cast<::NSInteger>(value)];
    }

    std::int64_t LevelIndicatorCell::number_of_tick_marks() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) numberOfTickMarks]);
    }

    void LevelIndicatorCell::set_number_of_tick_marks(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setNumberOfTickMarks:static_cast<::NSInteger>(value)];
    }

    TickMarkPosition LevelIndicatorCell::tick_mark_position() const
    {
        return static_cast<TickMarkPosition>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) tickMarkPosition]);
    }

    void LevelIndicatorCell::set_tick_mark_position(TickMarkPosition value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setTickMarkPosition:static_cast<::NSTickMarkPosition>(value)];
    }

    double LevelIndicatorCell::warning_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSLevelIndicatorCell>(this) warningValue]);
    }

    void LevelIndicatorCell::set_warning_value(double value) const
    {
        [cocoon::internal::ns<::NSLevelIndicatorCell>(this) setWarningValue:static_cast<double>(value)];
    }
}
