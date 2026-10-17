#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief A stack of arranged subviews (NSStackView).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * cocoon::StackView stack;
     * stack.set_spacing(8);
     * stack.add_arranged_subview(cocoon::Button("A"));
     * stack.add_arranged_subview(cocoon::Button("B"));
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StackView stack_view{};
     * stack_view.set_alignment(cocoon::LayoutAttribute::Left);
     * auto alignment = stack_view.alignment();
     * stack_view.set_detaches_hidden_views(true);
     * auto detaches_hidden_views = stack_view.detaches_hidden_views();
     * stack_view.set_distribution(cocoon::StackViewDistribution::GravityAreas);
     * auto distribution = stack_view.distribution();
     * stack_view.add_arranged_subview(cocoon::View());
     * stack_view.add_view(cocoon::View(), cocoon::StackViewGravity::Top);
     * stack_view.clipping_resistance_priority_for_orientation(cocoon::ConstraintOrientation::Horizontal);
     * stack_view.will_detach_views().connect([](std::vector<cocoon::View> a0) {});
     * stack_view.did_reattach_views().connect([](std::vector<cocoon::View> a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstackview
     */
    class StackView : public View
    {
    public:
        /// @brief Creates a new `NSStackView` instance and returns a handle to it.
        explicit StackView();
        /// @brief Creates a null handle that refers to no native object.
        StackView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StackView(Adopt adopt);
        /**
     * @brief Calls `-[NSStackView addArrangedSubview:]`.
     * @details Adds a view to the end of the arrangedSubviews list. If the view is not a subview of the receiver, it will be added as one.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void add_arranged_subview(const View& view) const;
        /**
     * @brief Calls `-[NSStackView addView:inGravity:]`.
     * @details Adds the view to the given gravity area at the end of that gravity area. This method will update the StackView's layout, and could result in the StackView changing its size or views being detached / clipped.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param gravity Argument converted to the Objective-C parameter of the same role.
     */
        void add_view(const View& view, StackViewGravity gravity) const;
        /**
     * @brief Calls `-[NSStackView clippingResistancePriorityForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float clipping_resistance_priority_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSStackView customSpacingAfterView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double custom_spacing_after_view(const View& view) const;
        /**
     * @brief Calls `-[NSStackView huggingPriorityForOrientation:]`.
     * @details Priority at which the StackView wants its internal spacing to be as small as possible, defaults to NSLayoutPriorityDefaultLow Spacing within a StackView is managed completely by the StackView. However, extra layout constraints can be added in conjunction with the StackView to create a more customized layout. Below describes the constraints the StackView uses to space its internal views. Spacing between view gravities have constraints with the following constraints: - Length >= spacing \@ NSLayoutPriorityRequired - Length == spacing \@ huggingPriority Spacing between views (within a gravity) have the following constraints: - Length >= spacing \@ NSLayoutPriorityRequired - Length == spacing \@ MAX(NSLayoutPriorityDefaultHigh, huggingPriority)
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float hugging_priority_for_orientation(ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSStackView insertArrangedSubview:atIndex:]`.
     * @details Adds a view to the arrangedSubviews list at a specific index. If the view is already in the arrangedSubviews list, it will move the view to the specified index (but not change the subview index). If the view is not a subview of the receiver, it will be added as one (not necessarily at the same index).
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_arranged_subview(const View& view, std::int64_t index) const;
        /**
     * @brief Calls `-[NSStackView insertView:atIndex:inGravity:]`.
     * @details Adds the view to the given gravity area at the index within that gravity area. Index numbers & counts are specific to each gravity area, and are indexed based on the set userInterfaceLayoutDirection. (For a L2R layout, index 0 in the leading gravity is the furthest left index; for a R2L layout index 0 in the leading gravity is the furthest right index) This method will update the StackView's layout, and could result in the StackView changing its size or views being detached / clipped. An NSRangeException will be raised if the index is out of bounds
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param gravity Argument converted to the Objective-C parameter of the same role.
     */
        void insert_view(const View& view, std::uint64_t index, StackViewGravity gravity) const;
        /**
     * @brief Calls `-[NSStackView removeArrangedSubview:]`.
     * @details Removes a subview from the list of arranged subviews without removing it as a subview of the receiver. Removing the view as a subview (either by -[view removeFromSuperview] or setting the receiver's subviews) will automatically remove it as an arranged subview.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void remove_arranged_subview(const View& view) const;
        /**
     * @brief Calls `-[NSStackView removeView:]`.
     * @details Will remove view from the StackView. [view removeFromSuperview] will have the same behavior in the case that view is visible (not detached) from the StackView. In the case that view had been detached, this method must be used to remove it from the StackView. view must be managed by the StackView, an exception will be raised if not.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void remove_view(const View& view) const;
        /**
     * @brief Calls `-[NSStackView setClippingResistancePriority:forOrientation:]`.
     * @param clipping_resistance_priority Argument converted to the Objective-C parameter of the same role.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     */
        void set_clipping_resistance_priority(float clipping_resistance_priority, ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSStackView setCustomSpacing:afterView:]`.
     * @details Set and get custom spacing after a view. This custom spacing is used instead of the default spacing set with the spacing property. This is saved across layout updates, until the view is removed from the StackView or the custom spacing is changed. A value of NSStackViewSpacingUseDefault signifies that the spacing is the default spacing set with the StackView property. 'view' must be managed by the StackView, an exception will be raised if not.
     * @param spacing Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void set_custom_spacing(double spacing, const View& view) const;
        /**
     * @brief Calls `-[NSStackView setHuggingPriority:forOrientation:]`.
     * @param hugging_priority Argument converted to the Objective-C parameter of the same role.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     */
        void set_hugging_priority(float hugging_priority, ConstraintOrientation orientation) const;
        /**
     * @brief Calls `-[NSStackView setViews:inGravity:]`.
     * @param views Argument converted to the Objective-C parameter of the same role.
     * @param gravity Argument converted to the Objective-C parameter of the same role.
     */
        void set_views(const std::vector<View>& views, StackViewGravity gravity) const;
        /**
     * @brief Calls `-[NSStackView setVisibilityPriority:forView:]`.
     * @details Sets and gets the visibility priorities for views in the StackView. When detaching a view, it will first detach views with the lowest visibility priority. If multiple views share the same lowest visibility priority, all of them will be dropped. Defaults to 'NSStackViewVisibilityPriorityMustHold'. Setting the visibility priority to NSStackViewVisibilityPriorityNotVisible will force that view to be detached (regardless of available space), and will set the view to be hidden if 'detachesHiddenViews' is set to 'YES'. 'view' must be managed by the StackView, an exception will be raised if not.
     * @param priority Argument converted to the Objective-C parameter of the same role.
     * @param view Argument converted to the Objective-C parameter of the same role.
     */
        void set_visibility_priority(float priority, const View& view) const;
        /**
     * @brief Calls `+[NSStackView stackViewWithViews:]`.
     * @param views Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static StackView stack_view_with_views(const std::vector<View>& views);
        /**
     * @brief Calls `-[NSStackView viewsInGravity:]`.
     * @param gravity Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<View> views_in_gravity(StackViewGravity gravity) const;
        /**
     * @brief Calls `-[NSStackView visibilityPriorityForView:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float visibility_priority_for_view(const View& view) const;
        /**
     * @brief Returns the `alignment` property of `NSStackView`.
     * @details Describes how subviews are aligned within the StackView, defaults to 'NSLayoutAttributeCenterY' for horizontal stacks, 'NSLayoutAttributeCenterX' for vertical stacks. Setting 'NSLayoutAttributeNotAnAttribute' will cause the internal alignment constraints to not be created, and could result in an ambiguous layout. Setting an inapplicable attribute for the set orientation will result in the alignment being ignored (similar to its handling with NSLayoutAttributeNotAnAttribute). The alignment constraints are established at a priority of 'NSLayoutPriorityDefaultLow' and are overridable for individual views using external constraints.
     * @return The converted Objective-C result.
     */
        LayoutAttribute alignment() const;
        /**
     * @brief Sets the `alignment` property of `NSStackView`.
     * @details Describes how subviews are aligned within the StackView, defaults to 'NSLayoutAttributeCenterY' for horizontal stacks, 'NSLayoutAttributeCenterX' for vertical stacks. Setting 'NSLayoutAttributeNotAnAttribute' will cause the internal alignment constraints to not be created, and could result in an ambiguous layout. Setting an inapplicable attribute for the set orientation will result in the alignment being ignored (similar to its handling with NSLayoutAttributeNotAnAttribute). The alignment constraints are established at a priority of 'NSLayoutPriorityDefaultLow' and are overridable for individual views using external constraints.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alignment(LayoutAttribute value) const;
        /**
     * @brief Returns the `arrangedSubviews` property of `NSStackView`.
     * @details The list of views that are arranged in a stack by the receiver. They are a subset of \\c -subviews, with potential difference in ordering.
     * @return The converted Objective-C result.
     */
        std::vector<View> arranged_subviews() const;
        /**
     * @brief Returns the `detachedViews` property of `NSStackView`.
     * @details The arrangedSubviews that are currently detached/hidden.
     * @return The converted Objective-C result.
     */
        std::vector<View> detached_views() const;
        /**
     * @brief Returns the `detachesHiddenViews` property of `NSStackView`.
     * @details If YES, when a stacked view's 'hidden' property is set to YES, the view will be detached from the stack and reattached when set to NO. Similarly, if the view has a lowered visibility priority and is detached from the stack view, it will be set as 'hidden' rather than removed from the view hierarchy. Defaults to YES for apps linked on the 10.11 SDK or later.
     * @return The converted Objective-C result.
     */
        bool detaches_hidden_views() const;
        /**
     * @brief Sets the `detachesHiddenViews` property of `NSStackView`.
     * @details If YES, when a stacked view's 'hidden' property is set to YES, the view will be detached from the stack and reattached when set to NO. Similarly, if the view has a lowered visibility priority and is detached from the stack view, it will be set as 'hidden' rather than removed from the view hierarchy. Defaults to YES for apps linked on the 10.11 SDK or later.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_detaches_hidden_views(bool value) const;
        /**
     * @brief Returns the `distribution` property of `NSStackView`.
     * @details The spacing and sizing distribution of stacked views along the primary axis. The default value is 'gravityAreas'.
     * @return The converted Objective-C result.
     */
        StackViewDistribution distribution() const;
        /**
     * @brief Sets the `distribution` property of `NSStackView`.
     * @details The spacing and sizing distribution of stacked views along the primary axis. The default value is 'gravityAreas'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_distribution(StackViewDistribution value) const;
        /**
     * @brief Returns the `edgeInsets` property of `NSStackView`.
     * @details Default padding inside the StackView, around all of the subviews.
     * @return The converted Objective-C result.
     */
        Insets edge_insets() const;
        /**
     * @brief Sets the `edgeInsets` property of `NSStackView`.
     * @details Default padding inside the StackView, around all of the subviews.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_edge_insets(const Insets& value) const;
        /**
     * @brief Returns the `orientation` property of `NSStackView`.
     * @details Orientation of the StackView, defaults to NSUserInterfaceLayoutOrientationHorizontal
     * @return The converted Objective-C result.
     */
        Orientation orientation() const;
        /**
     * @brief Sets the `orientation` property of `NSStackView`.
     * @details Orientation of the StackView, defaults to NSUserInterfaceLayoutOrientationHorizontal
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_orientation(Orientation value) const;
        /**
     * @brief Returns the `spacing` property of `NSStackView`.
     * @details Default (minimum) spacing between each view
     * @return The converted Objective-C result.
     */
        double spacing() const;
        /**
     * @brief Sets the `spacing` property of `NSStackView`.
     * @details Default (minimum) spacing between each view
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_spacing(double value) const;
        /**
     * @brief Returns the `views` property of `NSStackView`.
     * @details Returns an array of all the views managed by this StackView, regardless of detach-status or gravity area. This is indexed in the order of indexing within the StackView. Detached views are indexed at the positions they would have been if they were still attached.
     * @return The converted Objective-C result.
     */
        std::vector<View> views() const;
        /// @brief Convenience helper `add_arranged_subviews` provided by cocoon.
        void add_arranged_subviews(const std::vector<View>& views) const;
        /// @brief Signal for the delegate/data-source method behind `will_detach_views`; connect a callback with `will_detach_views().connect(...)`.
        Signal<StackView, void(std::vector<View>)> will_detach_views() const
        {
            return Signal<StackView, void(std::vector<View>)>(handle(), "will_detach_views");
        }
        /// @brief Signal for the delegate/data-source method behind `did_reattach_views`; connect a callback with `did_reattach_views().connect(...)`.
        Signal<StackView, void(std::vector<View>)> did_reattach_views() const
        {
            return Signal<StackView, void(std::vector<View>)>(handle(), "did_reattach_views");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
