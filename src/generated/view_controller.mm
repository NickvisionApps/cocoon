#include "generated/view_controller.h"
#include "internal.h"

namespace cocoon
{
    ViewController::ViewController(const View& view) : ViewController(Adopt{cocoon::internal::retain(cocoon::internal::make_view_controller(view))})
    {
    }

    ViewController::ViewController(const std::string& nib_name_or_nil, const Bundle& nib_bundle_or_nil) : ViewController(Adopt{cocoon::internal::retain([[::NSViewController alloc] initWithNibName:cocoon::internal::to(nib_name_or_nil) bundle:cocoon::internal::native<::NSBundle>(nib_bundle_or_nil)])})
    {
    }

    ViewController::ViewController() : ViewController(Adopt{cocoon::internal::retain([[::NSViewController alloc] init])})
    {
    }

    ViewController::ViewController(std::nullptr_t) : Responder(nullptr)
    {
    }

    ViewController::ViewController(Adopt adopt) : Responder(adopt)
    {
    }

    void ViewController::add_child_view_controller(const ViewController& child_view_controller) const
    {
        [cocoon::internal::ns<::NSViewController>(this) addChildViewController:cocoon::internal::native<::NSViewController>(child_view_controller)];
    }

    bool ViewController::commit_editing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSViewController>(this) commitEditing]);
    }

    void ViewController::commit_editing_with_delegate(const Object& delegate, const std::string& did_commit_selector, void* context_info) const
    {
        [cocoon::internal::ns<::NSViewController>(this) commitEditingWithDelegate:cocoon::internal::native_id(delegate) didCommitSelector:NSSelectorFromString(cocoon::internal::to(did_commit_selector)) contextInfo:context_info];
    }

    void ViewController::discard_editing() const
    {
        [cocoon::internal::ns<::NSViewController>(this) discardEditing];
    }

    void ViewController::dismiss_controller(const Object& sender) const
    {
        [cocoon::internal::ns<::NSViewController>(this) dismissController:cocoon::internal::native_id(sender)];
    }

    void ViewController::dismiss_view_controller(const ViewController& view_controller) const
    {
        [cocoon::internal::ns<::NSViewController>(this) dismissViewController:cocoon::internal::native<::NSViewController>(view_controller)];
    }

    void ViewController::insert_child_view_controller(const ViewController& child_view_controller, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSViewController>(this) insertChildViewController:cocoon::internal::native<::NSViewController>(child_view_controller) atIndex:static_cast<::NSInteger>(index)];
    }

    void ViewController::load_view() const
    {
        [cocoon::internal::ns<::NSViewController>(this) loadView];
    }

    void ViewController::load_view_if_needed() const
    {
        [cocoon::internal::ns<::NSViewController>(this) loadViewIfNeeded];
    }

    void ViewController::preferred_content_size_did_change_for_view_controller(const ViewController& view_controller) const
    {
        [cocoon::internal::ns<::NSViewController>(this) preferredContentSizeDidChangeForViewController:cocoon::internal::native<::NSViewController>(view_controller)];
    }

    void ViewController::present_view_controller(const ViewController& view_controller, const Object& animator) const
    {
        [cocoon::internal::ns<::NSViewController>(this) presentViewController:cocoon::internal::native<::NSViewController>(view_controller) animator:cocoon::internal::native_id(animator)];
    }

    void ViewController::present_view_controller(const ViewController& view_controller, const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge, PopoverBehavior behavior) const
    {
        [cocoon::internal::ns<::NSViewController>(this) presentViewController:cocoon::internal::native<::NSViewController>(view_controller) asPopoverRelativeToRect:cocoon::internal::to(positioning_rect) ofView:cocoon::internal::native<::NSView>(positioning_view) preferredEdge:static_cast<::NSRectEdge>(preferred_edge) behavior:static_cast<::NSPopoverBehavior>(behavior)];
    }

    void ViewController::present_view_controller(const ViewController& view_controller, const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge, PopoverBehavior behavior, bool has_full_size_content) const
    {
        [cocoon::internal::ns<::NSViewController>(this) presentViewController:cocoon::internal::native<::NSViewController>(view_controller) asPopoverRelativeToRect:cocoon::internal::to(positioning_rect) ofView:cocoon::internal::native<::NSView>(positioning_view) preferredEdge:static_cast<::NSRectEdge>(preferred_edge) behavior:static_cast<::NSPopoverBehavior>(behavior) hasFullSizeContent:static_cast<::BOOL>(has_full_size_content)];
    }

    void ViewController::present_view_controller_as_modal_window(const ViewController& view_controller) const
    {
        [cocoon::internal::ns<::NSViewController>(this) presentViewControllerAsModalWindow:cocoon::internal::native<::NSViewController>(view_controller)];
    }

    void ViewController::present_view_controller_as_sheet(const ViewController& view_controller) const
    {
        [cocoon::internal::ns<::NSViewController>(this) presentViewControllerAsSheet:cocoon::internal::native<::NSViewController>(view_controller)];
    }

    void ViewController::remove_child_view_controller_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSViewController>(this) removeChildViewControllerAtIndex:static_cast<::NSInteger>(index)];
    }

    void ViewController::remove_from_parent_view_controller() const
    {
        [cocoon::internal::ns<::NSViewController>(this) removeFromParentViewController];
    }

    void ViewController::transition_from_view_controller(const ViewController& from_view_controller, const ViewController& to_view_controller, ViewControllerTransitionOptions options, std::function<void()> completion) const
    {
        [cocoon::internal::ns<::NSViewController>(this) transitionFromViewController:cocoon::internal::native<::NSViewController>(from_view_controller) toViewController:cocoon::internal::native<::NSViewController>(to_view_controller) options:static_cast<::NSViewControllerTransitionOptions>(options) completionHandler:(completion ? (void (^)(void)) ^ void() { completion(); } : (void (^)(void))nil)];
    }

    void ViewController::update_view_constraints() const
    {
        [cocoon::internal::ns<::NSViewController>(this) updateViewConstraints];
    }

    void ViewController::view_did_appear() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewDidAppear];
    }

    void ViewController::view_did_disappear() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewDidDisappear];
    }

    void ViewController::view_did_layout() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewDidLayout];
    }

    void ViewController::view_did_load() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewDidLoad];
    }

    void ViewController::view_will_appear() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewWillAppear];
    }

    void ViewController::view_will_disappear() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewWillDisappear];
    }

    void ViewController::view_will_layout() const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewWillLayout];
    }

    void ViewController::view_will_transition_to_size(const Size& new_size) const
    {
        [cocoon::internal::ns<::NSViewController>(this) viewWillTransitionToSize:cocoon::internal::to(new_size)];
    }

    std::vector<ViewController> ViewController::child_view_controllers() const
    {
        return cocoon::internal::from_array<ViewController>([cocoon::internal::ns<::NSViewController>(this) childViewControllers], [](id e) -> ViewController
                                                            {
                                                                return cocoon::internal::wrap<ViewController>((::NSViewController*)e);
                                                            });
    }

    void ViewController::set_child_view_controllers(const std::vector<ViewController>& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setChildViewControllers:cocoon::internal::to_array(value, [](const ViewController& e) -> id
                                                                                                           {
                                                                                                               return cocoon::internal::native<::NSViewController>(e);
                                                                                                           })];
    }

    ExtensionContext ViewController::extension_context() const
    {
        return cocoon::internal::wrap<ExtensionContext>([cocoon::internal::ns<::NSViewController>(this) extensionContext]);
    }

    Bundle ViewController::nib_bundle() const
    {
        return cocoon::internal::wrap<Bundle>([cocoon::internal::ns<::NSViewController>(this) nibBundle]);
    }

    std::string ViewController::nib_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) nibName]);
    }

    ViewController ViewController::parent_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSViewController>(this) parentViewController]);
    }

    Size ViewController::preferred_content_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) preferredContentSize]);
    }

    void ViewController::set_preferred_content_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setPreferredContentSize:cocoon::internal::to(value)];
    }

    Size ViewController::preferred_maximum_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) preferredMaximumSize]);
    }

    Size ViewController::preferred_minimum_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) preferredMinimumSize]);
    }

    Point ViewController::preferred_screen_origin() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) preferredScreenOrigin]);
    }

    void ViewController::set_preferred_screen_origin(const Point& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setPreferredScreenOrigin:cocoon::internal::to(value)];
    }

    std::vector<ViewController> ViewController::presented_view_controllers() const
    {
        return cocoon::internal::from_array<ViewController>([cocoon::internal::ns<::NSViewController>(this) presentedViewControllers], [](id e) -> ViewController
                                                            {
                                                                return cocoon::internal::wrap<ViewController>((::NSViewController*)e);
                                                            });
    }

    ViewController ViewController::presenting_view_controller() const
    {
        return cocoon::internal::wrap<ViewController>([cocoon::internal::ns<::NSViewController>(this) presentingViewController]);
    }

    Object ViewController::represented_object() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSViewController>(this) representedObject]);
    }

    void ViewController::set_represented_object(const Object& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setRepresentedObject:cocoon::internal::native_id(value)];
    }

    View ViewController::source_item_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSViewController>(this) sourceItemView]);
    }

    void ViewController::set_source_item_view(const View& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setSourceItemView:cocoon::internal::native<::NSView>(value)];
    }

    Storyboard ViewController::storyboard() const
    {
        return cocoon::internal::wrap<Storyboard>([cocoon::internal::ns<::NSViewController>(this) storyboard]);
    }

    std::string ViewController::title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSViewController>(this) title]);
    }

    void ViewController::set_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setTitle:cocoon::internal::to(value)];
    }

    View ViewController::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSViewController>(this) view]);
    }

    void ViewController::set_view(const View& value) const
    {
        [cocoon::internal::ns<::NSViewController>(this) setView:cocoon::internal::native<::NSView>(value)];
    }

    View ViewController::view_if_loaded() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSViewController>(this) viewIfLoaded]);
    }

    bool ViewController::is_view_loaded() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSViewController>(this) isViewLoaded]);
    }
}
