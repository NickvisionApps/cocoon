#include "generated/tracking_area.h"
#include "internal.h"

namespace cocoon
{
    TrackingArea::TrackingArea(const Rect& rect, TrackingAreaOptions options, const Object& owner, const std::vector<std::pair<Object, Object>>& user_info) : TrackingArea(Adopt{cocoon::internal::retain([[::NSTrackingArea alloc] initWithRect:cocoon::internal::to(rect)
                                                                                                                                                                                                                                         options:static_cast<::NSTrackingAreaOptions>(options)
                                                                                                                                                                                                                                           owner:cocoon::internal::native_id(owner)
                                                                                                                                                                                                                                        userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                     return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                                                 },
                                                                                                                                                                                                                                                                                 [](const Object& v) -> id
                                                                                                                                                                                                                                                                                 {
                                                                                                                                                                                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                                                 })])})
    {
    }

    TrackingArea::TrackingArea() : TrackingArea(Adopt{cocoon::internal::retain([[::NSTrackingArea alloc] init])})
    {
    }

    TrackingArea::TrackingArea(std::nullptr_t) : Object(nullptr)
    {
    }

    TrackingArea::TrackingArea(Adopt adopt) : Object(adopt)
    {
    }

    TrackingAreaOptions TrackingArea::options() const
    {
        return static_cast<TrackingAreaOptions>([cocoon::internal::ns<::NSTrackingArea>(this) options]);
    }

    Object TrackingArea::owner() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTrackingArea>(this) owner]);
    }

    Rect TrackingArea::rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTrackingArea>(this) rect]);
    }

    std::vector<std::pair<Object, Object>> TrackingArea::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSTrackingArea>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }
}
