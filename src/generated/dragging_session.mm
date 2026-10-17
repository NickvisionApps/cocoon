#include "generated/dragging_session.h"
#include "internal.h"

namespace cocoon
{
    DraggingSession::DraggingSession() : DraggingSession(Adopt{cocoon::internal::retain([[::NSDraggingSession alloc] init])})
    {
    }

    DraggingSession::DraggingSession(std::nullptr_t) : Object(nullptr)
    {
    }

    DraggingSession::DraggingSession(Adopt adopt) : Object(adopt)
    {
    }

    void DraggingSession::enumerate_dragging_items_with_options(DraggingItemEnumerationOptions enum_opts, const View& view, const std::vector<std::string>& class_array, const std::map<std::string, Object>& search_options, std::function<void(DraggingItem, std::int64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSDraggingSession>(this) enumerateDraggingItemsWithOptions:static_cast<::NSDraggingItemEnumerationOptions>(enum_opts)
                                                                     forView:cocoon::internal::native<::NSView>(view)
                                                                     classes:cocoon::internal::to_array(class_array, [](const std::string& e) -> id
                                                                                          {
                                                                                              return NSClassFromString(cocoon::internal::to(e));
                                                                                          })
                                                               searchOptions:cocoon::internal::to_dictionary(search_options, [](const std::string& k) -> id
                                                                                               {
                                                                                                   return cocoon::internal::to(k);
                                                                                               },
                                                                                               [](const Object& v) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native_id(v);
                                                                                               })
                                                                  usingBlock:(block ? (void (^)(::NSDraggingItem*, ::NSInteger, BOOL*)) ^ void(::NSDraggingItem * a56_0, ::NSInteger a56_1, ::BOOL * a56_2) { bool __o56_2 = a56_2 ? static_cast<bool>(*a56_2) : bool(); block(cocoon::internal::wrap<DraggingItem>(a56_0), static_cast<std::int64_t>(a56_1), __o56_2); if (a56_2) { *a56_2 = static_cast<::BOOL>(__o56_2); } } : (void (^)(::NSDraggingItem*, ::NSInteger, BOOL*))nil)];
    }

    bool DraggingSession::animates_to_starting_positions_on_cancel_or_fail() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSDraggingSession>(this) animatesToStartingPositionsOnCancelOrFail]);
    }

    void DraggingSession::set_animates_to_starting_positions_on_cancel_or_fail(bool value) const
    {
        [cocoon::internal::ns<::NSDraggingSession>(this) setAnimatesToStartingPositionsOnCancelOrFail:static_cast<::BOOL>(value)];
    }

    DraggingFormation DraggingSession::dragging_formation() const
    {
        return static_cast<DraggingFormation>([cocoon::internal::ns<::NSDraggingSession>(this) draggingFormation]);
    }

    void DraggingSession::set_dragging_formation(DraggingFormation value) const
    {
        [cocoon::internal::ns<::NSDraggingSession>(this) setDraggingFormation:static_cast<::NSDraggingFormation>(value)];
    }

    std::int64_t DraggingSession::dragging_leader_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDraggingSession>(this) draggingLeaderIndex]);
    }

    void DraggingSession::set_dragging_leader_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSDraggingSession>(this) setDraggingLeaderIndex:static_cast<::NSInteger>(value)];
    }

    Point DraggingSession::dragging_location() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDraggingSession>(this) draggingLocation]);
    }

    Pasteboard DraggingSession::dragging_pasteboard() const
    {
        return cocoon::internal::wrap<Pasteboard>([cocoon::internal::ns<::NSDraggingSession>(this) draggingPasteboard]);
    }

    std::int64_t DraggingSession::dragging_sequence_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDraggingSession>(this) draggingSequenceNumber]);
    }
}
