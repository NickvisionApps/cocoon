#include "generated/candidate_list_touch_bar_item_base.h"
#include "internal.h"

@interface AKCandidateListTouchBarItemBaseDelegate : NSObject <NSCandidateListTouchBarItemDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKCandidateListTouchBarItemBaseDelegate

- (void)candidateListTouchBarItem:(NSCandidateListTouchBarItem*)anItem beginSelectingCandidateAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t)>::emit((__bridge void*)strongHost, "begin_selecting_candidate_at_index", static_cast<std::int64_t>(index));
}

- (void)candidateListTouchBarItem:(NSCandidateListTouchBarItem*)anItem changeSelectionFromCandidateAtIndex:(NSInteger)previousIndex toIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t, std::int64_t)>::emit((__bridge void*)strongHost, "change_selection_from_candidate_at_index_to_index", static_cast<std::int64_t>(previousIndex), static_cast<std::int64_t>(index));
}

- (void)candidateListTouchBarItem:(NSCandidateListTouchBarItem*)anItem endSelectingCandidateAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t)>::emit((__bridge void*)strongHost, "end_selecting_candidate_at_index", static_cast<std::int64_t>(index));
}

- (void)candidateListTouchBarItem:(NSCandidateListTouchBarItem*)anItem changedCandidateListVisibility:(BOOL)isVisible
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(bool)>::emit((__bridge void*)strongHost, "changed_candidate_list_visibility", static_cast<bool>(isVisible));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(candidateListTouchBarItem:beginSelectingCandidateAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t)>::connected((__bridge void*)strongHost, "begin_selecting_candidate_at_index");
    }
    if (selector == @selector(candidateListTouchBarItem:changeSelectionFromCandidateAtIndex:toIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t, std::int64_t)>::connected((__bridge void*)strongHost, "change_selection_from_candidate_at_index_to_index");
    }
    if (selector == @selector(candidateListTouchBarItem:endSelectingCandidateAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(std::int64_t)>::connected((__bridge void*)strongHost, "end_selecting_candidate_at_index");
    }
    if (selector == @selector(candidateListTouchBarItem:changedCandidateListVisibility:))
    {
        return strongHost && cocoon::Signal<cocoon::CandidateListTouchBarItemBase, void(bool)>::connected((__bridge void*)strongHost, "changed_candidate_list_visibility");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    CandidateListTouchBarItemBase::CandidateListTouchBarItemBase() : TouchBarItem(nullptr)
    {
    }

    CandidateListTouchBarItemBase::CandidateListTouchBarItemBase(std::nullptr_t) : TouchBarItem(nullptr)
    {
    }

    CandidateListTouchBarItemBase::CandidateListTouchBarItemBase(Adopt adopt) : TouchBarItem(adopt)
    {
    }

    void CandidateListTouchBarItemBase::set_candidates(const std::vector<Object>& candidates, const Range& selected_range, const std::string& original_string) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setCandidates:cocoon::internal::to_array(candidates, [](const Object& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::native_id(e);
                                                                                                            })
                                                                forSelectedRange:cocoon::internal::to(selected_range)
                                                                        inString:cocoon::internal::to(original_string)];
    }

    void CandidateListTouchBarItemBase::update_with_insertion_point_visibility(bool is_visible) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) updateWithInsertionPointVisibility:static_cast<::BOOL>(is_visible)];
    }

    bool CandidateListTouchBarItemBase::allows_collapsing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) allowsCollapsing]);
    }

    void CandidateListTouchBarItemBase::set_allows_collapsing(bool value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setAllowsCollapsing:static_cast<::BOOL>(value)];
    }

    bool CandidateListTouchBarItemBase::allows_text_input_context_candidates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) allowsTextInputContextCandidates]);
    }

    void CandidateListTouchBarItemBase::set_allows_text_input_context_candidates(bool value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setAllowsTextInputContextCandidates:static_cast<::BOOL>(value)];
    }

    std::function<AttributedString(Object, std::int64_t)> CandidateListTouchBarItemBase::attributed_string_for_candidate() const
    {
        return [&]() -> std::function<AttributedString(Object, std::int64_t)>
        {
            auto blk = (::NSAttributedString * (^)(id, ::NSInteger))([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) attributedStringForCandidate]);
            if (!blk)
            {
                return {};
            }
            return [blk](Object a10_0, std::int64_t a10_1) -> AttributedString
            {
                auto __r = blk(cocoon::internal::native_id(a10_0), static_cast<::NSInteger>(a10_1));
                return cocoon::internal::wrap<AttributedString>(__r);
            };
        }();
    }

    void CandidateListTouchBarItemBase::set_attributed_string_for_candidate(std::function<AttributedString(Object, std::int64_t)> value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setAttributedStringForCandidate:(value ? (::NSAttributedString * (^)(id, ::NSInteger)) ^ ::NSAttributedString * (id a11_0, ::NSInteger a11_1) { auto __r = value(cocoon::internal::wrap<Object>(a11_0), static_cast<std::int64_t>(a11_1)); return cocoon::internal::native<::NSAttributedString>(__r); } : (::NSAttributedString * (^)(id, ::NSInteger)) nil)];
    }

    bool CandidateListTouchBarItemBase::is_candidate_list_visible() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) isCandidateListVisible]);
    }

    std::vector<Object> CandidateListTouchBarItemBase::candidates() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) candidates], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    View CandidateListTouchBarItemBase::client() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) client]);
    }

    void CandidateListTouchBarItemBase::set_client(const View& value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setClient:cocoon::internal::native<NSView<NSTextInputClient>>(value)];
    }

    bool CandidateListTouchBarItemBase::is_collapsed() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) isCollapsed]);
    }

    void CandidateListTouchBarItemBase::set_collapsed(bool value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setCollapsed:static_cast<::BOOL>(value)];
    }

    std::string CandidateListTouchBarItemBase::customization_label() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) customizationLabel]);
    }

    void CandidateListTouchBarItemBase::set_customization_label(const std::string& value) const
    {
        [cocoon::internal::ns<::NSCandidateListTouchBarItem>(this) setCustomizationLabel:cocoon::internal::to(value)];
    }

    void CandidateListTouchBarItemBase::install_delegate_delegate_(void* native)
    {
        ::NSCandidateListTouchBarItem* host = (__bridge ::NSCandidateListTouchBarItem*)native;
        AKCandidateListTouchBarItemBaseDelegate* delegate = [[AKCandidateListTouchBarItemBaseDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSCandidateListTouchBarItem* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSCandidateListTouchBarItem* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
