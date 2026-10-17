#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Event;
    class Image;
    class RulerView;

    /**
     * @brief C++ handle for the Objective-C class `NSRulerMarker` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::RulerMarker ruler_marker{cocoon::RulerView(), 1, cocoon::Image(), {0, 0}};
     * ruler_marker.set_image(cocoon::Image());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::RulerMarker ruler_marker{cocoon::RulerView(), 1, cocoon::Image(), {0, 0}};
     * ruler_marker.set_image(cocoon::Image());
     * auto image = ruler_marker.image();
     * ruler_marker.set_image_origin({0, 0});
     * auto image_origin = ruler_marker.image_origin();
     * ruler_marker.set_marker_location(1);
     * auto marker_location = ruler_marker.marker_location();
     * ruler_marker.draw_rect({{0, 0}, {100, 100}});
     * ruler_marker.track_mouse(cocoon::Event(), true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsrulermarker
     */
    class RulerMarker : public Object
    {
    public:
        /// @brief Creates a new `NSRulerMarker` instance and returns a handle to it.
        explicit RulerMarker(const RulerView& ruler, double location, const Image& image, const Point& image_origin);
        RulerMarker();
        /// @brief Creates a null handle that refers to no native object.
        RulerMarker(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit RulerMarker(Adopt adopt);
        /**
     * @brief Calls `-[NSRulerMarker drawRect:]`.
     * @details Draws the object at it's current location. Only rect needs to be drawn.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void draw_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSRulerMarker trackMouse:adding:]`.
     * @details Handles the given mmouseDown event. Performs a modal tracking loop until mouseUp allowing the object to be moved, if movable or removed, if removable.
     * @param mouse_down_event Argument converted to the Objective-C parameter of the same role.
     * @param is_adding Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool track_mouse(const Event& mouse_down_event, bool is_adding) const;
        /**
     * @brief Returns the `dragging` property of `NSRulerMarker`.
     * @details Returns YES if the ruler object is currently being dragged.
     * @return The converted Objective-C result.
     */
        bool is_dragging() const;
        /**
     * @brief Returns the `image` property of `NSRulerMarker`.
     * @details The image is what's drawn in the ruler.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSRulerMarker`.
     * @details The image is what's drawn in the ruler.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `imageOrigin` property of `NSRulerMarker`.
     * @details The image is drawn such that the image origin is on the baseline of the ruler at the object's location.
     * @return The converted Objective-C result.
     */
        Point image_origin() const;
        /**
     * @brief Sets the `imageOrigin` property of `NSRulerMarker`.
     * @details The image is drawn such that the image origin is on the baseline of the ruler at the object's location.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image_origin(const Point& value) const;
        /**
     * @brief Returns the `imageRectInRuler` property of `NSRulerMarker`.
     * @details Returns the rect that would be occupied by the object's image in the ruler's bounds coordinates. This takes the flippedness of the ruler into account.
     * @return The converted Objective-C result.
     */
        Rect image_rect_in_ruler() const;
        /**
     * @brief Returns the `markerLocation` property of `NSRulerMarker`.
     * @details The location is set by the -init... method and the -setLocation: method. Location is an x position for horizontal rulers or a y position for vertical rulers. It is expressed in the client view's coordinate system.
     * @return The converted Objective-C result.
     */
        double marker_location() const;
        /**
     * @brief Sets the `markerLocation` property of `NSRulerMarker`.
     * @details The location is set by the -init... method and the -setLocation: method. Location is an x position for horizontal rulers or a y position for vertical rulers. It is expressed in the client view's coordinate system.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_marker_location(double value) const;
        /**
     * @brief Returns the `movable` property of `NSRulerMarker`.
     * @details Objects are movable, but not removable by default. Movable means the ruler object can be dragged by the user. Removable means it can be deleted by the user.
     * @return The converted Objective-C result.
     */
        bool is_movable() const;
        /**
     * @brief Sets the `movable` property of `NSRulerMarker`.
     * @details Objects are movable, but not removable by default. Movable means the ruler object can be dragged by the user. Removable means it can be deleted by the user.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_movable(bool value) const;
        /**
     * @brief Returns the `removable` property of `NSRulerMarker`.
     * @return The converted Objective-C result.
     */
        bool is_removable() const;
        /**
     * @brief Sets the `removable` property of `NSRulerMarker`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_removable(bool value) const;
        /**
     * @brief Returns the `representedObject` property of `NSRulerMarker`.
     * @details The representedObject of an NSRulerMarker is purely for the client's use. It must be able to copy itself. A represented object should be some small object. The text object uses NSStrings for most ruler objects or NSTextTab objects for tab stops.
     * @return The converted Objective-C result.
     */
        Object represented_object() const;
        /**
     * @brief Sets the `representedObject` property of `NSRulerMarker`.
     * @details The representedObject of an NSRulerMarker is purely for the client's use. It must be able to copy itself. A represented object should be some small object. The text object uses NSStrings for most ruler objects or NSTextTab objects for tab stops.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_object(const Object& value) const;
        /**
     * @brief Returns the `ruler` property of `NSRulerMarker`.
     * @details Returns the ruler.
     * @return The converted Objective-C result.
     */
        RulerView ruler() const;
        /**
     * @brief Returns the `thicknessRequiredInRuler` property of `NSRulerMarker`.
     * @details Returns the height or width (depending on the ruler's orientation) required in the ruler to display the object.
     * @return The converted Objective-C result.
     */
        double thickness_required_in_ruler() const;
    };
}
