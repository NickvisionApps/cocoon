#include "generated/scrubber.h"
#include "internal.h"

@interface AKScrubberDataSourceDelegate : NSObject <NSScrubberDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKScrubberDataSourceDelegate

- (NSInteger)numberOfItemsForScrubber:(NSScrubber*)scrubber
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Scrubber, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_items_for_scrubber");
    return static_cast<::NSInteger>(__r);
}

- (NSScrubberItemView*)scrubber:(NSScrubber*)scrubber viewForItemAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Scrubber, cocoon::ScrubberItemView(std::int64_t)>::emit((__bridge void*)strongHost, "view_for_item_at_index", static_cast<std::int64_t>(index));
    return cocoon::internal::native<::NSScrubberItemView>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(numberOfItemsForScrubber:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_items_for_scrubber");
    }
    if (selector == @selector(scrubber:viewForItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, cocoon::ScrubberItemView(std::int64_t)>::connected((__bridge void*)strongHost, "view_for_item_at_index");
    }
    return [super respondsToSelector:selector];
}

@end

@interface AKScrubberDelegate : NSObject <NSScrubberDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKScrubberDelegate

- (void)scrubber:(NSScrubber*)scrubber didSelectItemAtIndex:(NSInteger)selectedIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void(std::int64_t)>::emit((__bridge void*)strongHost, "did_select_item_at_index", static_cast<std::int64_t>(selectedIndex));
}

- (void)scrubber:(NSScrubber*)scrubber didHighlightItemAtIndex:(NSInteger)highlightedIndex
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void(std::int64_t)>::emit((__bridge void*)strongHost, "did_highlight_item_at_index", static_cast<std::int64_t>(highlightedIndex));
}

- (void)scrubber:(NSScrubber*)scrubber didChangeVisibleRange:(NSRange)visibleRange
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void(cocoon::Range)>::emit((__bridge void*)strongHost, "did_change_visible_range", cocoon::internal::from(visibleRange));
}

- (void)didBeginInteractingWithScrubber:(NSScrubber*)scrubber
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void()>::emit((__bridge void*)strongHost, "did_begin_interacting_with_scrubber");
}

- (void)didFinishInteractingWithScrubber:(NSScrubber*)scrubber
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void()>::emit((__bridge void*)strongHost, "did_finish_interacting_with_scrubber");
}

- (void)didCancelInteractingWithScrubber:(NSScrubber*)scrubber
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Scrubber, void()>::emit((__bridge void*)strongHost, "did_cancel_interacting_with_scrubber");
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(scrubber:didSelectItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void(std::int64_t)>::connected((__bridge void*)strongHost, "did_select_item_at_index");
    }
    if (selector == @selector(scrubber:didHighlightItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void(std::int64_t)>::connected((__bridge void*)strongHost, "did_highlight_item_at_index");
    }
    if (selector == @selector(scrubber:didChangeVisibleRange:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void(cocoon::Range)>::connected((__bridge void*)strongHost, "did_change_visible_range");
    }
    if (selector == @selector(didBeginInteractingWithScrubber:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void()>::connected((__bridge void*)strongHost, "did_begin_interacting_with_scrubber");
    }
    if (selector == @selector(didFinishInteractingWithScrubber:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void()>::connected((__bridge void*)strongHost, "did_finish_interacting_with_scrubber");
    }
    if (selector == @selector(didCancelInteractingWithScrubber:))
    {
        return strongHost && cocoon::Signal<cocoon::Scrubber, void()>::connected((__bridge void*)strongHost, "did_cancel_interacting_with_scrubber");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Scrubber::Scrubber(const Rect& frame_rect) : Scrubber(Adopt{cocoon::internal::retain([[::NSScrubber alloc] initWithFrame:cocoon::internal::to(frame_rect)])})
    {
        Scrubber::install_data_source_delegate_(handle());
        Scrubber::install_delegate_delegate_(handle());
    }

    Scrubber::Scrubber() : Scrubber(Adopt{cocoon::internal::retain([[::NSScrubber alloc] init])})
    {
        Scrubber::install_data_source_delegate_(handle());
        Scrubber::install_delegate_delegate_(handle());
    }

    Scrubber::Scrubber(std::nullptr_t) : View(nullptr)
    {
    }

    Scrubber::Scrubber(Adopt adopt) : View(adopt)
    {
    }

    void Scrubber::insert_items_at_indexes(const IndexSet& indexes) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) insertItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes)];
    }

    ScrubberItemView Scrubber::item_view_for_item_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<ScrubberItemView>([cocoon::internal::ns<::NSScrubber>(this) itemViewForItemAtIndex:static_cast<::NSInteger>(index)]);
    }

    ScrubberItemView Scrubber::make_item_with_identifier(const std::string& item_identifier, const Object& owner) const
    {
        return cocoon::internal::wrap<ScrubberItemView>([cocoon::internal::ns<::NSScrubber>(this) makeItemWithIdentifier:cocoon::internal::to(item_identifier) owner:cocoon::internal::native_id(owner)]);
    }

    void Scrubber::move_item_at_index(std::int64_t old_index, std::int64_t new_index) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) moveItemAtIndex:static_cast<::NSInteger>(old_index) toIndex:static_cast<::NSInteger>(new_index)];
    }

    void Scrubber::perform_sequential_batch_updates(std::function<void()> update_block) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) performSequentialBatchUpdates:(update_block ? (void (^)(void)) ^ void() { update_block(); } : (void (^)(void))nil)];
    }

    void Scrubber::register_class(const std::string& item_view_class, const std::string& item_identifier) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) registerClass:NSClassFromString(cocoon::internal::to(item_view_class)) forItemIdentifier:cocoon::internal::to(item_identifier)];
    }

    void Scrubber::register_nib(const Nib& nib, const std::string& item_identifier) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) registerNib:cocoon::internal::native<::NSNib>(nib) forItemIdentifier:cocoon::internal::to(item_identifier)];
    }

    void Scrubber::reload_data() const
    {
        [cocoon::internal::ns<::NSScrubber>(this) reloadData];
    }

    void Scrubber::reload_items_at_indexes(const IndexSet& indexes) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) reloadItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes)];
    }

    void Scrubber::remove_items_at_indexes(const IndexSet& indexes) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) removeItemsAtIndexes:cocoon::internal::native<::NSIndexSet>(indexes)];
    }

    void Scrubber::scroll_item_at_index(std::int64_t index, ScrubberAlignment alignment) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) scrollItemAtIndex:static_cast<::NSInteger>(index) toAlignment:static_cast<::NSScrubberAlignment>(alignment)];
    }

    Color Scrubber::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSScrubber>(this) backgroundColor]);
    }

    void Scrubber::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    View Scrubber::background_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSScrubber>(this) backgroundView]);
    }

    void Scrubber::set_background_view(const View& value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setBackgroundView:cocoon::internal::native<::NSView>(value)];
    }

    bool Scrubber::is_continuous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubber>(this) isContinuous]);
    }

    void Scrubber::set_continuous(bool value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setContinuous:static_cast<::BOOL>(value)];
    }

    bool Scrubber::floats_selection_views() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubber>(this) floatsSelectionViews]);
    }

    void Scrubber::set_floats_selection_views(bool value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setFloatsSelectionViews:static_cast<::BOOL>(value)];
    }

    std::int64_t Scrubber::highlighted_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrubber>(this) highlightedIndex]);
    }

    ScrubberAlignment Scrubber::item_alignment() const
    {
        return static_cast<ScrubberAlignment>([cocoon::internal::ns<::NSScrubber>(this) itemAlignment]);
    }

    void Scrubber::set_item_alignment(ScrubberAlignment value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setItemAlignment:static_cast<::NSScrubberAlignment>(value)];
    }

    ScrubberMode Scrubber::mode() const
    {
        return static_cast<ScrubberMode>([cocoon::internal::ns<::NSScrubber>(this) mode]);
    }

    void Scrubber::set_mode(ScrubberMode value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setMode:static_cast<::NSScrubberMode>(value)];
    }

    std::int64_t Scrubber::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrubber>(this) numberOfItems]);
    }

    ScrubberLayout Scrubber::scrubber_layout() const
    {
        return cocoon::internal::wrap<ScrubberLayout>([cocoon::internal::ns<::NSScrubber>(this) scrubberLayout]);
    }

    void Scrubber::set_scrubber_layout(const ScrubberLayout& value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setScrubberLayout:cocoon::internal::native<::NSScrubberLayout>(value)];
    }

    std::int64_t Scrubber::selected_index() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSScrubber>(this) selectedIndex]);
    }

    void Scrubber::set_selected_index(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setSelectedIndex:static_cast<::NSInteger>(value)];
    }

    ScrubberSelectionStyle Scrubber::selection_background_style() const
    {
        return cocoon::internal::wrap<ScrubberSelectionStyle>([cocoon::internal::ns<::NSScrubber>(this) selectionBackgroundStyle]);
    }

    void Scrubber::set_selection_background_style(const ScrubberSelectionStyle& value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setSelectionBackgroundStyle:cocoon::internal::native<::NSScrubberSelectionStyle>(value)];
    }

    ScrubberSelectionStyle Scrubber::selection_overlay_style() const
    {
        return cocoon::internal::wrap<ScrubberSelectionStyle>([cocoon::internal::ns<::NSScrubber>(this) selectionOverlayStyle]);
    }

    void Scrubber::set_selection_overlay_style(const ScrubberSelectionStyle& value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setSelectionOverlayStyle:cocoon::internal::native<::NSScrubberSelectionStyle>(value)];
    }

    bool Scrubber::shows_additional_content_indicators() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubber>(this) showsAdditionalContentIndicators]);
    }

    void Scrubber::set_shows_additional_content_indicators(bool value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setShowsAdditionalContentIndicators:static_cast<::BOOL>(value)];
    }

    bool Scrubber::shows_arrow_buttons() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScrubber>(this) showsArrowButtons]);
    }

    void Scrubber::set_shows_arrow_buttons(bool value) const
    {
        [cocoon::internal::ns<::NSScrubber>(this) setShowsArrowButtons:static_cast<::BOOL>(value)];
    }

    void Scrubber::install_data_source_delegate_(void* native)
    {
        ::NSScrubber* host = (__bridge ::NSScrubber*)native;
        AKScrubberDataSourceDelegate* delegate = [[AKScrubberDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSScrubber* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSScrubber* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }

    void Scrubber::install_delegate_delegate_(void* native)
    {
        ::NSScrubber* host = (__bridge ::NSScrubber*)native;
        AKScrubberDelegate* delegate = [[AKScrubberDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSScrubber* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSScrubber* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
