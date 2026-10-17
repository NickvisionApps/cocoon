#pragma once

#include "generated/action_cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSLevelIndicatorCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ActionCell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LevelIndicatorCell level_indicator_cell;
     * level_indicator_cell.set_critical_value(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LevelIndicatorCell level_indicator_cell{};
     * level_indicator_cell.set_critical_value(1);
     * auto critical_value = level_indicator_cell.critical_value();
     * level_indicator_cell.set_level_indicator_style(cocoon::LevelIndicatorStyle::Relevancy);
     * auto level_indicator_style = level_indicator_cell.level_indicator_style();
     * level_indicator_cell.set_max_value(1);
     * auto max_value = level_indicator_cell.max_value();
     * level_indicator_cell.rect_of_tick_mark_at_index(1);
     * level_indicator_cell.tick_mark_value_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslevelindicatorcell
     */
    class LevelIndicatorCell : public ActionCell
    {
    public:
        /// @brief Creates a new `NSLevelIndicatorCell` instance and returns a handle to it.
        explicit LevelIndicatorCell(LevelIndicatorStyle level_indicator_style);
        /// @brief Creates a new `NSLevelIndicatorCell` instance and returns a handle to it.
        explicit LevelIndicatorCell();
        /// @brief Creates a null handle that refers to no native object.
        LevelIndicatorCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LevelIndicatorCell(Adopt adopt);
        /**
     * @brief Calls `-[NSLevelIndicatorCell rectOfTickMarkAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect rect_of_tick_mark_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSLevelIndicatorCell tickMarkValueAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double tick_mark_value_at_index(std::int64_t index) const;
        /**
     * @brief Returns the `criticalValue` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        double critical_value() const;
        /**
     * @brief Sets the `criticalValue` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_critical_value(double value) const;
        /**
     * @brief Returns the `levelIndicatorStyle` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        LevelIndicatorStyle level_indicator_style() const;
        /**
     * @brief Sets the `levelIndicatorStyle` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_level_indicator_style(LevelIndicatorStyle value) const;
        /**
     * @brief Returns the `maxValue` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        double max_value() const;
        /**
     * @brief Sets the `maxValue` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_value(double value) const;
        /**
     * @brief Returns the `minValue` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        double min_value() const;
        /**
     * @brief Sets the `minValue` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_value(double value) const;
        /**
     * @brief Returns the `numberOfMajorTickMarks` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_major_tick_marks() const;
        /**
     * @brief Sets the `numberOfMajorTickMarks` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_major_tick_marks(std::int64_t value) const;
        /**
     * @brief Returns the `numberOfTickMarks` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_tick_marks() const;
        /**
     * @brief Sets the `numberOfTickMarks` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_number_of_tick_marks(std::int64_t value) const;
        /**
     * @brief Returns the `tickMarkPosition` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        TickMarkPosition tick_mark_position() const;
        /**
     * @brief Sets the `tickMarkPosition` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tick_mark_position(TickMarkPosition value) const;
        /**
     * @brief Returns the `warningValue` property of `NSLevelIndicatorCell`.
     * @return The converted Objective-C result.
     */
        double warning_value() const;
        /**
     * @brief Sets the `warningValue` property of `NSLevelIndicatorCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_warning_value(double value) const;
    };
}
