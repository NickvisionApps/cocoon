#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class DraggingItem;
    class Pasteboard;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSDraggingSession` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DraggingSession dragging_session;
     * dragging_session.set_animates_to_starting_positions_on_cancel_or_fail(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DraggingSession dragging_session{};
     * dragging_session.set_animates_to_starting_positions_on_cancel_or_fail(true);
     * auto animates_to_starting_positions_on_cancel_or_fail = dragging_session.animates_to_starting_positions_on_cancel_or_fail();
     * dragging_session.set_dragging_formation(cocoon::DraggingFormation::Default);
     * auto dragging_formation = dragging_session.dragging_formation();
     * dragging_session.set_dragging_leader_index(1);
     * auto dragging_leader_index = dragging_session.dragging_leader_index();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdraggingsession
     */
    class DraggingSession : public Object
    {
    public:
        /// @brief Creates a new `NSDraggingSession` instance and returns a handle to it.
        explicit DraggingSession();
        /// @brief Creates a null handle that refers to no native object.
        DraggingSession(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DraggingSession(Adopt adopt);
        /**
     * @brief Calls `-[NSDraggingSession enumerateDraggingItemsWithOptions:forView:classes:searchOptions:usingBlock:]`.
     * @details Enumerate through each dragging item. Any changes made to the properties of the draggingItem are reflected in the drag when the destination is not overriding them. Classes in the provided array must implement the NSPasteboardReading protocol. Cocoa classes that implement this protocol include NSImage, NSString, NSURL, NSColor, NSAttributedString, and NSPasteboardItem. For every item on the pasteboard, each class in the provided array will be queried for the types it can read using -readableTypesForPasteboard:. An instance will be created of the first class found in the provided array whose readable types match a conforming type contained in that pasteboard item. If an Instance is created from the pasteboard item data, it is placed into an NSDraggingItem along with the dragging properties of that item such as the drag image. The NSDraggingItem is then passed as a parameter to the provided block. Additional search options, such as restricting the search to file URLs with particular content types, can be specified with a search options dictionary. See the comments for the Pasteboard Reading Options keys in NSPasteboard.h for a full description. Note: all coordinate properties in the NSDraggingItem are in the coordinate system of view. If view is nil, the screen coordinate space is used.
     * @param enum_opts Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param class_array Argument converted to the Objective-C parameter of the same role.
     * @param search_options Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_dragging_items_with_options(DraggingItemEnumerationOptions enum_opts, const View& view, const std::vector<std::string>& class_array, const std::map<std::string, Object>& search_options, std::function<void(DraggingItem, std::int64_t, bool&)> block) const;
        /**
     * @brief Returns the `animatesToStartingPositionsOnCancelOrFail` property of `NSDraggingSession`.
     * @details Controls whether the dragging image animates back to its starting point on a cancelled or failed drag. -draggingSession:endedAtPoint:operation: is a good time to change this value depending on the result of the drag operation. The default value is YES.
     * @return The converted Objective-C result.
     */
        bool animates_to_starting_positions_on_cancel_or_fail() const;
        /**
     * @brief Sets the `animatesToStartingPositionsOnCancelOrFail` property of `NSDraggingSession`.
     * @details Controls whether the dragging image animates back to its starting point on a cancelled or failed drag. -draggingSession:endedAtPoint:operation: is a good time to change this value depending on the result of the drag operation. The default value is YES.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_animates_to_starting_positions_on_cancel_or_fail(bool value) const;
        /**
     * @brief Returns the `draggingFormation` property of `NSDraggingSession`.
     * @details Controls the dragging formation when the drag is over the source. The default value is NSDraggingFormationNone.
     * @return The converted Objective-C result.
     */
        DraggingFormation dragging_formation() const;
        /**
     * @brief Sets the `draggingFormation` property of `NSDraggingSession`.
     * @details Controls the dragging formation when the drag is over the source. The default value is NSDraggingFormationNone.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_formation(DraggingFormation value) const;
        /**
     * @brief Returns the `draggingLeaderIndex` property of `NSDraggingSession`.
     * @details The index of the draggingItem under the cursor. The default is the NSDraggingItem closest to the location in the event that was passed to -beginDraggingSessionWithItems:event:source:
     * @return The converted Objective-C result.
     */
        std::int64_t dragging_leader_index() const;
        /**
     * @brief Sets the `draggingLeaderIndex` property of `NSDraggingSession`.
     * @details The index of the draggingItem under the cursor. The default is the NSDraggingItem closest to the location in the event that was passed to -beginDraggingSessionWithItems:event:source:
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dragging_leader_index(std::int64_t value) const;
        /**
     * @brief Returns the `draggingLocation` property of `NSDraggingSession`.
     * @details The current location (cursor) of the drag in screen coordinates.
     * @return The converted Objective-C result.
     */
        Point dragging_location() const;
        /**
     * @brief Returns the `draggingPasteboard` property of `NSDraggingSession`.
     * @details Returns the pasteboard object that holds the data being dragged.
     * @return The converted Objective-C result.
     */
        Pasteboard dragging_pasteboard() const;
        /**
     * @brief Returns the `draggingSequenceNumber` property of `NSDraggingSession`.
     * @details Returns a number that uniquely identifies the dragging session.
     * @return The converted Objective-C result.
     */
        std::int64_t dragging_sequence_number() const;
    };
}
