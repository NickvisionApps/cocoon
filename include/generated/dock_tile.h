#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSDockTile` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DockTile dock_tile;
     * dock_tile.set_badge_label("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DockTile dock_tile{};
     * dock_tile.set_badge_label("text");
     * auto badge_label = dock_tile.badge_label();
     * dock_tile.set_content_view(cocoon::View());
     * auto content_view = dock_tile.content_view();
     * dock_tile.set_shows_application_badge(true);
     * auto shows_application_badge = dock_tile.shows_application_badge();
     * dock_tile.display();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdocktile
     */
    class DockTile : public Object
    {
    public:
        /// @brief Creates a new `NSDockTile` instance and returns a handle to it.
        explicit DockTile();
        /// @brief Creates a null handle that refers to no native object.
        DockTile(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DockTile(Adopt adopt);
        /**
     * @brief Calls `-[NSDockTile display]`.
     * @details cause the dock tile to be redrawn. The contentView and any subviews will be sent drawRect: messages.
     */
        void display() const;
        /**
     * @brief Returns the `badgeLabel` property of `NSDockTile`.
     * @details Badge the dock icon with a localized string. The badge appearance is system defined. This is often used to show an unread count in the application dock icon.
     * @return The converted Objective-C result.
     */
        std::string badge_label() const;
        /**
     * @brief Sets the `badgeLabel` property of `NSDockTile`.
     * @details Badge the dock icon with a localized string. The badge appearance is system defined. This is often used to show an unread count in the application dock icon.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_badge_label(const std::string& value) const;
        /**
     * @brief Returns the `contentView` property of `NSDockTile`.
     * @details set the content view to view. view should be height and width resizable. In order to initiate drawing in view, you must call -[NSDockTile display].
     * @return The converted Objective-C result.
     */
        View content_view() const;
        /**
     * @brief Sets the `contentView` property of `NSDockTile`.
     * @details set the content view to view. view should be height and width resizable. In order to initiate drawing in view, you must call -[NSDockTile display].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view(const View& value) const;
        /**
     * @brief Returns the `owner` property of `NSDockTile`.
     * @details -owner will return NSApp for the application dock tile, or the NSWindow for a mini window dock tile.
     * @return The converted Objective-C result.
     */
        Object owner() const;
        /**
     * @brief Returns the `showsApplicationBadge` property of `NSDockTile`.
     * @details setShowsApplicationBadge: sets whether or not the dock tile should be badged with the application icon. Default is YES for NSWindow dock tiles, NO for the NSApplication dock tile.
     * @return The converted Objective-C result.
     */
        bool shows_application_badge() const;
        /**
     * @brief Sets the `showsApplicationBadge` property of `NSDockTile`.
     * @details setShowsApplicationBadge: sets whether or not the dock tile should be badged with the application icon. Default is YES for NSWindow dock tiles, NO for the NSApplication dock tile.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_application_badge(bool value) const;
        /**
     * @brief Returns the `size` property of `NSDockTile`.
     * @details get the size of the dock tile, in screen coordinates
     * @return The converted Objective-C result.
     */
        Size size() const;
    };
}
