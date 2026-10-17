#pragma once

#include "generated/availability.h"
#include "generated/cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSActionCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Cell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ActionCell action_cell;
     * action_cell.set_action("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ActionCell action_cell{};
     * action_cell.set_action("text");
     * auto action = action_cell.action();
     * action_cell.set_tag(1);
     * auto tag = action_cell.tag();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsactioncell
     */
    class ActionCell : public Cell
    {
    public:
        /// @brief Creates a new `NSActionCell` instance and returns a handle to it.
        explicit ActionCell();
        /// @brief Creates a null handle that refers to no native object.
        ActionCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ActionCell(Adopt adopt);
        using Cell::action;
        using Cell::set_action;
        using Cell::set_tag;
        using Cell::set_target;
        using Cell::tag;
        using Cell::target;
        /**
     * @brief Returns the `action` property of `NSActionCell`.
     * @return The converted Objective-C result.
     */
        std::string action() const;
        /**
     * @brief Sets the `action` property of `NSActionCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_action(const std::string& value) const;
        /**
     * @brief Returns the `tag` property of `NSActionCell`.
     * @return The converted Objective-C result.
     */
        std::int64_t tag() const;
        /**
     * @brief Sets the `tag` property of `NSActionCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag(std::int64_t value) const;
        /**
     * @brief Returns the `target` property of `NSActionCell`.
     * @return The converted Objective-C result.
     */
        Object target() const;
        /**
     * @brief Sets the `target` property of `NSActionCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_target(const Object& value) const;
    };
}
