#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class IndexSet;
    class Nib;
    class ScrubberItemView;
    class ScrubberLayout;
    class ScrubberSelectionStyle;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSScrubber` (AppKit).
     * @details \@class NSScrubber \@abstract \@c NSScrubber is a control designed for the NSTouchBar environment. \@c NSScrubber arranges a finite number of "items" (represented by views of type \@c NSScrubberItemView ) according to a layout object (see \@c NSScrubberLayout ), and provides several methods for navigating and selecting those items. Clients provide data to \@c NSScrubber via a data source object (see the \@c NSScrubberDataSource protocol) and react to user interaction via a delegate object (see the \@c NSScrubberDelegate protocol).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Scrubber scrubber;
     * scrubber.set_background_color(cocoon::Color());
     * scrubber.did_select_item_at_index().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Scrubber scrubber{};
     * scrubber.set_background_color(cocoon::Color());
     * auto background_color = scrubber.background_color();
     * scrubber.set_background_view(cocoon::View());
     * auto background_view = scrubber.background_view();
     * scrubber.set_continuous(true);
     * auto continuous = scrubber.is_continuous();
     * scrubber.insert_items_at_indexes(cocoon::IndexSet());
     * scrubber.item_view_for_item_at_index(1);
     * scrubber.move_item_at_index(1, 1);
     * scrubber.did_select_item_at_index().connect([](std::int64_t a0) {});
     * scrubber.did_highlight_item_at_index().connect([](std::int64_t a0) {});
     * scrubber.did_change_visible_range().connect([](cocoon::Range a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsscrubber
     */
    class Scrubber : public View
    {
    public:
        /// @brief Creates a new `NSScrubber` instance and returns a handle to it.
        explicit Scrubber(const Rect& frame_rect);
        /// @brief Creates a new `NSScrubber` instance and returns a handle to it.
        explicit Scrubber();
        /// @brief Creates a null handle that refers to no native object.
        Scrubber(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Scrubber(Adopt adopt);
        using View::set_background_color;
        /**
     * @brief Calls `-[NSScrubber insertItemsAtIndexes:]`.
     * @details Inserts new items at the specified indexes. NSScrubber will request views for each new index from the \@c dataSource. This method uses the same semantics as \@c NSMutableArray; each index in the set specifies the destination index after all previous insertions have occurred. Therefore, an NSIndexSet of [1,2,3] will result in three new contiguous items.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     */
        void insert_items_at_indexes(const IndexSet& indexes) const;
        /**
     * @brief Calls `-[NSScrubber itemViewForItemAtIndex:]`.
     * @details Returns the \@c NSScrubberItemView for the given index, if one currently exists; returns \@c nil otherwise.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ScrubberItemView item_view_for_item_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSScrubber makeItemWithIdentifier:owner:]`.
     * @details Creates or reuses a \@c NSScrubberItemView corresponding to the provided \@c itemIdentifier. \@c NSScrubber searches, in order: the reuse queue, the list of registered classes, and then the list of registered nibs. If the reuse queue is empty, and there is no Class or Interface Builder archive registered for the \@c itemIdentifier, this method returns \@c nil.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @param owner Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ScrubberItemView make_item_with_identifier(const std::string& item_identifier, const Object& owner) const;
        /**
     * @brief Calls `-[NSScrubber moveItemAtIndex:toIndex:]`.
     * @details Moves an item from one index to another. \@c oldIndex refers to the item's index prior to the movement, whereas \@c newIndex refers to the item's final location.
     * @param old_index Argument converted to the Objective-C parameter of the same role.
     * @param new_index Argument converted to the Objective-C parameter of the same role.
     */
        void move_item_at_index(std::int64_t old_index, std::int64_t new_index) const;
        /**
     * @brief Calls `-[NSScrubber performSequentialBatchUpdates:]`.
     * @details Updates inside the \@c performSequentialBatchUpdates block are processed and displayed all at once, including insertion, removal, moving, reloading items, and changing the selected index. Changes are performed iteratively using the same semantics as \@c NSMutableArray. NSScrubber expects its dataSource to reflect the changes made inside \@c -performSequentialBatchUpdates: immediately after the \@c updateBlock finishes executing.
     * @param update_block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_sequential_batch_updates(std::function<void()> update_block) const;
        /**
     * @brief Calls `-[NSScrubber registerClass:forItemIdentifier:]`.
     * @details Registers a \@c NSScrubberItemView class to be instantiated for the given \@c itemIdentifier. Raises an exception if \@c itemViewClass is not a subclass of \@c NSScrubberItemView. Passing \@c nil for \@c itemViewClass removes a previous registration. Registrations made through this method do not persist through NSCoding.
     * @param item_view_class Argument converted to the Objective-C parameter of the same role.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_class(const std::string& item_view_class, const std::string& item_identifier) const;
        /**
     * @brief Calls `-[NSScrubber registerNib:forItemIdentifier:]`.
     * @details Register a nib to be instantiated for the given \@c itemIdentifier. The nib must contain a top-level object which is a subclass of NSScrubberItemView; otherwise, \@c -makeItemWithIdentifier: may return \@c nil for this identifier. Passing \@c nil for \@c nib removes a previous registration.
     * @param nib Argument converted to the Objective-C parameter of the same role.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void register_nib(const Nib& nib, const std::string& item_identifier) const;
        /**
     * @brief Calls `-[NSScrubber reloadData]`.
     * @details Invalidate all data within the scrubber control, triggering a reload of all content, and clearing the current selection.
     */
        void reload_data() const;
        /**
     * @brief Calls `-[NSScrubber reloadItemsAtIndexes:]`.
     * @details Reloads the items at the specified indexes. NSScrubber will request new views for each item and smoothly crossfade between them before discarding the original views.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     */
        void reload_items_at_indexes(const IndexSet& indexes) const;
        /**
     * @brief Calls `-[NSScrubber removeItemsAtIndexes:]`.
     * @details Removes the items at the specified indexes. This method uses the same semantics as \@c NSMutableArray.
     * @param indexes Argument converted to the Objective-C parameter of the same role.
     */
        void remove_items_at_indexes(const IndexSet& indexes) const;
        /**
     * @brief Calls `-[NSScrubber scrollItemAtIndex:toAlignment:]`.
     * @details Scrolls an item to a given alignment within the control. If \@c NSScrubberAlignmentNone is provided, then the control scrolls the minimum amount necessary to make the item visible. Scrolling is animated if called on the animator proxy.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param alignment Argument converted to the Objective-C parameter of the same role.
     */
        void scroll_item_at_index(std::int64_t index, ScrubberAlignment alignment) const;
        /**
     * @brief Returns the `backgroundColor` property of `NSScrubber`.
     * @details If set, \@c backgroundColor is displayed behind the scrubber content. The background color is suppressed if the scrubber is assigned a non-nil \@c backgroundView. The default value is \@c nil.
     * @return The converted Objective-C result.
     */
        Color background_color() const;
        /**
     * @brief Sets the `backgroundColor` property of `NSScrubber`.
     * @details If set, \@c backgroundColor is displayed behind the scrubber content. The background color is suppressed if the scrubber is assigned a non-nil \@c backgroundView. The default value is \@c nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_color(const Color& value) const;
        /**
     * @brief Returns the `backgroundView` property of `NSScrubber`.
     * @details If non-nil, the \@c backgroundView is displayed below the scrubber content. The view's layout is managed by \@c NSScrubber to match the content area. If this property is non-nil, the \@c backgroundColor property has no effect. The default value is \@c nil.
     * @return The converted Objective-C result.
     */
        View background_view() const;
        /**
     * @brief Sets the `backgroundView` property of `NSScrubber`.
     * @details If non-nil, the \@c backgroundView is displayed below the scrubber content. The view's layout is managed by \@c NSScrubber to match the content area. If this property is non-nil, the \@c backgroundColor property has no effect. The default value is \@c nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_view(const View& value) const;
        /**
     * @brief Returns the `continuous` property of `NSScrubber`.
     * @details When \@c continuous is \@c YES, panning over the control in \@c NSScrubberModeFixed will immediately select the item under the user's finger, and scrolling in \@c NSScrubberModeFree will continuously select items as they pass through the current \@c itemAlignment. The default is \@c NO.
     * @return The converted Objective-C result.
     */
        bool is_continuous() const;
        /**
     * @brief Sets the `continuous` property of `NSScrubber`.
     * @details When \@c continuous is \@c YES, panning over the control in \@c NSScrubberModeFixed will immediately select the item under the user's finger, and scrolling in \@c NSScrubberModeFree will continuously select items as they pass through the current \@c itemAlignment. The default is \@c NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_continuous(bool value) const;
        /**
     * @brief Returns the `floatsSelectionViews` property of `NSScrubber`.
     * @details When \@c floatsSelectionViews is \@c YES, the selection decorations provided by \@c selectionBackgroundStyle and \@c selectionOverlayStyle will smoothly float between selected items, rather than animating their entrance/exit in-place. The default is \@c NO.
     * @return The converted Objective-C result.
     */
        bool floats_selection_views() const;
        /**
     * @brief Sets the `floatsSelectionViews` property of `NSScrubber`.
     * @details When \@c floatsSelectionViews is \@c YES, the selection decorations provided by \@c selectionBackgroundStyle and \@c selectionOverlayStyle will smoothly float between selected items, rather than animating their entrance/exit in-place. The default is \@c NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_floats_selection_views(bool value) const;
        /**
     * @brief Returns the `highlightedIndex` property of `NSScrubber`.
     * @details The index of the currently highlighted item within the control. If there is no highlighted item, the value of this property is (-1).
     * @return The converted Objective-C result.
     */
        std::int64_t highlighted_index() const;
        /**
     * @brief Returns the `itemAlignment` property of `NSScrubber`.
     * @details If the value of \@c itemAlignment is not \@c NSScrubberAlignmentNone, the scrubber will ensure that some item rests at the preferred alignment within the control following a scrolling or paging interaction. The default value is \@c NSScrubberAlignmentNone.
     * @return The converted Objective-C result.
     */
        ScrubberAlignment item_alignment() const;
        /**
     * @brief Sets the `itemAlignment` property of `NSScrubber`.
     * @details If the value of \@c itemAlignment is not \@c NSScrubberAlignmentNone, the scrubber will ensure that some item rests at the preferred alignment within the control following a scrolling or paging interaction. The default value is \@c NSScrubberAlignmentNone.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_alignment(ScrubberAlignment value) const;
        /**
     * @brief Returns the `mode` property of `NSScrubber`.
     * @details Describes the interaction mode for the scrubber control. See the \@c NSScrubberMode enumeration for a list of possible values. The default value is \@c NSScrubberModeFixed.
     * @return The converted Objective-C result.
     */
        ScrubberMode mode() const;
        /**
     * @brief Sets the `mode` property of `NSScrubber`.
     * @details Describes the interaction mode for the scrubber control. See the \@c NSScrubberMode enumeration for a list of possible values. The default value is \@c NSScrubberModeFixed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_mode(ScrubberMode value) const;
        /**
     * @brief Returns the `numberOfItems` property of `NSScrubber`.
     * @details Returns the number of items represented by the scrubber control.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `scrubberLayout` property of `NSScrubber`.
     * @return The converted Objective-C result.
     */
        ScrubberLayout scrubber_layout() const;
        /**
     * @brief Sets the `scrubberLayout` property of `NSScrubber`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scrubber_layout(const ScrubberLayout& value) const;
        /**
     * @brief Returns the `selectedIndex` property of `NSScrubber`.
     * @details The index of the selected item within the control. If there is no selected item, the value of this property is (-1). Setting this property through the animator proxy will animate the selection change. Programmatic selection changes do not trigger delegate callbacks.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_index() const;
        /**
     * @brief Sets the `selectedIndex` property of `NSScrubber`.
     * @details The index of the selected item within the control. If there is no selected item, the value of this property is (-1). Setting this property through the animator proxy will animate the selection change. Programmatic selection changes do not trigger delegate callbacks.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_index(std::int64_t value) const;
        /**
     * @brief Returns the `selectionBackgroundStyle` property of `NSScrubber`.
     * @details Specifies a style of decoration to place behind items that are selected and/or highlighted. The default value is \@c nil, indicating no built-in background decoration.
     * @return The converted Objective-C result.
     */
        ScrubberSelectionStyle selection_background_style() const;
        /**
     * @brief Sets the `selectionBackgroundStyle` property of `NSScrubber`.
     * @details Specifies a style of decoration to place behind items that are selected and/or highlighted. The default value is \@c nil, indicating no built-in background decoration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_background_style(const ScrubberSelectionStyle& value) const;
        /**
     * @brief Returns the `selectionOverlayStyle` property of `NSScrubber`.
     * @details Specifies a style of decoration to place above items that are selected and/or highlighted. The default value is \@c nil, indicating no built-in overlay decoration.
     * @return The converted Objective-C result.
     */
        ScrubberSelectionStyle selection_overlay_style() const;
        /**
     * @brief Sets the `selectionOverlayStyle` property of `NSScrubber`.
     * @details Specifies a style of decoration to place above items that are selected and/or highlighted. The default value is \@c nil, indicating no built-in overlay decoration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_overlay_style(const ScrubberSelectionStyle& value) const;
        /**
     * @brief Returns the `showsAdditionalContentIndicators` property of `NSScrubber`.
     * @details If \@c showsAdditionalContentIndicators is \@c YES, the control will draw a fade effect to indicate that there is additional unscrolled content. The default is \@c NO.
     * @return The converted Objective-C result.
     */
        bool shows_additional_content_indicators() const;
        /**
     * @brief Sets the `showsAdditionalContentIndicators` property of `NSScrubber`.
     * @details If \@c showsAdditionalContentIndicators is \@c YES, the control will draw a fade effect to indicate that there is additional unscrolled content. The default is \@c NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_additional_content_indicators(bool value) const;
        /**
     * @brief Returns the `showsArrowButtons` property of `NSScrubber`.
     * @details If \@c showsArrowButtons is \@c YES, the control provides leading and trailing arrow buttons. Tapping an arrow button moves the selection index by one element; pressing and holding repeatedly moves the selection. The default is \@c NO.
     * @return The converted Objective-C result.
     */
        bool shows_arrow_buttons() const;
        /**
     * @brief Sets the `showsArrowButtons` property of `NSScrubber`.
     * @details If \@c showsArrowButtons is \@c YES, the control provides leading and trailing arrow buttons. Tapping an arrow button moves the selection index by one element; pressing and holding repeatedly moves the selection. The default is \@c NO.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_arrow_buttons(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `number_of_items_for_scrubber`; connect a callback with `number_of_items_for_scrubber().connect(...)`.
        Signal<Scrubber, std::int64_t()> number_of_items_for_scrubber() const
        {
            return Signal<Scrubber, std::int64_t()>(handle(), "number_of_items_for_scrubber");
        }
        /// @brief Signal for the delegate/data-source method behind `view_for_item_at_index`; connect a callback with `view_for_item_at_index().connect(...)`.
        Signal<Scrubber, ScrubberItemView(std::int64_t)> view_for_item_at_index() const
        {
            return Signal<Scrubber, ScrubberItemView(std::int64_t)>(handle(), "view_for_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `did_select_item_at_index`; connect a callback with `did_select_item_at_index().connect(...)`.
        Signal<Scrubber, void(std::int64_t)> did_select_item_at_index() const
        {
            return Signal<Scrubber, void(std::int64_t)>(handle(), "did_select_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `did_highlight_item_at_index`; connect a callback with `did_highlight_item_at_index().connect(...)`.
        Signal<Scrubber, void(std::int64_t)> did_highlight_item_at_index() const
        {
            return Signal<Scrubber, void(std::int64_t)>(handle(), "did_highlight_item_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_visible_range`; connect a callback with `did_change_visible_range().connect(...)`.
        Signal<Scrubber, void(Range)> did_change_visible_range() const
        {
            return Signal<Scrubber, void(Range)>(handle(), "did_change_visible_range");
        }
        /// @brief Signal for the delegate/data-source method behind `did_begin_interacting_with_scrubber`; connect a callback with `did_begin_interacting_with_scrubber().connect(...)`.
        Signal<Scrubber, void()> did_begin_interacting_with_scrubber() const
        {
            return Signal<Scrubber, void()>(handle(), "did_begin_interacting_with_scrubber");
        }
        /// @brief Signal for the delegate/data-source method behind `did_finish_interacting_with_scrubber`; connect a callback with `did_finish_interacting_with_scrubber().connect(...)`.
        Signal<Scrubber, void()> did_finish_interacting_with_scrubber() const
        {
            return Signal<Scrubber, void()>(handle(), "did_finish_interacting_with_scrubber");
        }
        /// @brief Signal for the delegate/data-source method behind `did_cancel_interacting_with_scrubber`; connect a callback with `did_cancel_interacting_with_scrubber().connect(...)`.
        Signal<Scrubber, void()> did_cancel_interacting_with_scrubber() const
        {
            return Signal<Scrubber, void()>(handle(), "did_cancel_interacting_with_scrubber");
        }

    protected:
        static void install_data_source_delegate_(void* native);
        static void install_delegate_delegate_(void* native);
    };
}
