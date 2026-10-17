#include "generated/ruler_marker.h"
#include "internal.h"

namespace cocoon
{
    RulerMarker::RulerMarker(const RulerView& ruler, double location, const Image& image, const Point& image_origin) : RulerMarker(Adopt{cocoon::internal::retain([[::NSRulerMarker alloc] initWithRulerView:cocoon::internal::native<::NSRulerView>(ruler) markerLocation:static_cast<::CGFloat>(location) image:cocoon::internal::native<::NSImage>(image) imageOrigin:cocoon::internal::to(image_origin)])})
    {
    }

    RulerMarker::RulerMarker() : Object(nullptr)
    {
    }

    RulerMarker::RulerMarker(std::nullptr_t) : Object(nullptr)
    {
    }

    RulerMarker::RulerMarker(Adopt adopt) : Object(adopt)
    {
    }

    void RulerMarker::draw_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) drawRect:cocoon::internal::to(rect)];
    }

    bool RulerMarker::track_mouse(const Event& mouse_down_event, bool is_adding) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerMarker>(this) trackMouse:cocoon::internal::native<::NSEvent>(mouse_down_event) adding:static_cast<::BOOL>(is_adding)]);
    }

    bool RulerMarker::is_dragging() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerMarker>(this) isDragging]);
    }

    Image RulerMarker::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSRulerMarker>(this) image]);
    }

    void RulerMarker::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    Point RulerMarker::image_origin() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRulerMarker>(this) imageOrigin]);
    }

    void RulerMarker::set_image_origin(const Point& value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setImageOrigin:cocoon::internal::to(value)];
    }

    Rect RulerMarker::image_rect_in_ruler() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRulerMarker>(this) imageRectInRuler]);
    }

    double RulerMarker::marker_location() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerMarker>(this) markerLocation]);
    }

    void RulerMarker::set_marker_location(double value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setMarkerLocation:static_cast<::CGFloat>(value)];
    }

    bool RulerMarker::is_movable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerMarker>(this) isMovable]);
    }

    void RulerMarker::set_movable(bool value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setMovable:static_cast<::BOOL>(value)];
    }

    bool RulerMarker::is_removable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRulerMarker>(this) isRemovable]);
    }

    void RulerMarker::set_removable(bool value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setRemovable:static_cast<::BOOL>(value)];
    }

    Object RulerMarker::represented_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSRulerMarker>(this) representedObject]);
    }

    void RulerMarker::set_represented_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSRulerMarker>(this) setRepresentedObject:cocoon::internal::native_id(value)];
    }

    RulerView RulerMarker::ruler() const
    {
        return cocoon::internal::wrap<RulerView>([cocoon::internal::ns<::NSRulerMarker>(this) ruler]);
    }

    double RulerMarker::thickness_required_in_ruler() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRulerMarker>(this) thicknessRequiredInRuler]);
    }
}
