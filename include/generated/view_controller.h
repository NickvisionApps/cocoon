#pragma once

#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Bundle;
    class ExtensionContext;
    class Storyboard;
    class View;

    /**
     * @brief A view controller (NSViewController). A View converts to a ViewController implicitly wherever one is needed.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * cocoon::View content;
     * cocoon::ViewController controller(content);
     * cocoon::Window window("Window", {400, 300});
     * window.set_content(controller);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ViewController view_controller{};
     * view_controller.set_preferred_content_size({100, 100});
     * auto preferred_content_size = view_controller.preferred_content_size();
     * view_controller.set_preferred_screen_origin({0, 0});
     * auto preferred_screen_origin = view_controller.preferred_screen_origin();
     * view_controller.set_source_item_view(cocoon::View());
     * auto source_item_view = view_controller.source_item_view();
     * view_controller.add_child_view_controller(cocoon::ViewController());
     * view_controller.commit_editing();
     * view_controller.discard_editing();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewcontroller
     */
    class ViewController : public Responder
    {
    public:
        /// @brief Creates a new `NSViewController` instance and returns a handle to it.
        ViewController(const View& view);
        /// @brief Creates a new `NSViewController` instance and returns a handle to it.
        explicit ViewController(const std::string& nib_name_or_nil, const Bundle& nib_bundle_or_nil);
        /// @brief Creates a new `NSViewController` instance and returns a handle to it.
        explicit ViewController();
        /// @brief Creates a null handle that refers to no native object.
        ViewController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewController(Adopt adopt);
        /**
     * @brief Calls `-[NSViewController addChildViewController:]`.
     * @details A convenience method for adding a child view controller; this simply calls insertChildViewController:atIndex: at the end of the array.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void add_child_view_controller(const ViewController& child_view_controller) const;
        /**
     * @brief Calls `-[NSViewController commitEditing]`.
     * @return The converted Objective-C result.
     */
        bool commit_editing() const;
        /**
     * @brief Calls `-[NSViewController commitEditingWithDelegate:didCommitSelector:contextInfo:]`.
     * @details Conformance to KVB's NSEditor informal protocol. The default implementations of these methods pass on the message to each registered editor, which are typically controls in the nib that are bound to the nib file's owner. You can override these methods to customize what is done when your view's presentation to the user is about to end because, for example, the user has selected another of a set of views or hit a panel's OK button (committing time) or because the user has hit a panel's Cancel button (discarding time). This class also conforms to KVB's NSEditorRegistration protocol, but you're not encouraged to override those methods.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param did_commit_selector Argument converted to the Objective-C parameter of the same role.
     * @param context_info Argument converted to the Objective-C parameter of the same role.
     */
        void commit_editing_with_delegate(const Object& delegate, const std::string& did_commit_selector, void* context_info) const;
        /**
     * @brief Calls `-[NSViewController discardEditing]`.
     */
        void discard_editing() const;
        /**
     * @brief Calls `-[NSViewController dismissController:]`.
     * @details Dismisses the receiver. If the receiver’s presenter is an NSViewController, it will be sent a -dismissViewController: message with this receiver as the parameter. Does nothing if the receiver is not currently presented.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void dismiss_controller(const Object& sender) const;
        /**
     * @brief Calls `-[NSViewController dismissViewController:]`.
     * @details Dismisses the viewController that was previously presented with the same animator that presented the viewController. This is the generic way to close a given viewController, no matter how it was presented.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void dismiss_view_controller(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSViewController insertChildViewController:atIndex:]`.
     * @details Primitive method to insert a child view controller in the childViewControllers array. If the child controller has a different parent controller, it will first be removed from its current parent by calling [childViewController removeFromParentViewController]. If this method is overridden then the super implementation should be called. This is the primitive to override for performing insert operations in a container class, and has little value in itself if the parent doesn't do something with the children.
     * @param child_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_child_view_controller(const ViewController& child_view_controller, std::int64_t index) const;
        /**
     * @brief Calls `-[NSViewController loadView]`.
     * @details The default implementation of this method invokes [self nibName] and [self nibBundle] and then uses the NSNib class to load the nib with this object as the file's owner. If the "view" outlet of the file's owner in the nib is properly connected, the regular nib loading machinery will send this object a -setView: message. You can override this method to customize how nib loading is done, including merely adding new behavior immediately before or immediately after nib loading done by the default implementation. One can also use viewDidLoad to modify things after the view has been loaded. You should not invoke this method from other objects unless you take care to avoid redundant invocations; NSViewController's default implement can handle them but overrides in subclasses might not. (Typically other objects should instead invoke -view and let the view controller do whatever it takes to fulfill the request.) In general, you should not call this method, and let NSViewController call it when needed. If you need it called, simply call [viewController view]. Prior to 10.10, -loadView would not have well defined behavior if [self nibName] returned nil. On 10.10 and later, if nibName is nil, NSViewController will automatically try to load a nib with the same name as the classname. This allows a convenience of doing [[MyViewController alloc] init] (which has a nil nibName) and having it automatically load a nib with the name "MyViewController".
     */
        void load_view() const;
        /**
     * @brief Calls `-[NSViewController loadViewIfNeeded]`.
     * @details If the view controller's view has not been loaded, loads the view.
     */
        void load_view_if_needed() const;
        /**
     * @brief Calls `-[NSViewController preferredContentSizeDidChangeForViewController:]`.
     * @details Sent to a view controller when the 'preferredContentSize' property of one of its child or presented view controllers changes.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void preferred_content_size_did_change_for_view_controller(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSViewController presentViewController:animator:]`.
     * @details Presents the viewController with a specific animator that handles both the presentation and dismissal of the viewController. The animator is held onto until dismissViewController: is called. This is the fundamental primitive for displaying view controllers that block interaction in some way. The method will assert if animator is nil. In general, you will not directly call this method unless you have a custom animator. Instead, you will use one of the standard cover methods that provide the animator: [NSViewController presentViewControllerAsSheet:], [NSViewController presentViewControllerAsModalWindow:], [NSViewController presentViewController:asPopoverRelativeToRect:...]
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @param animator Argument converted to the Objective-C parameter of the same role.
     */
        void present_view_controller(const ViewController& view_controller, const Object& animator) const;
        /**
     * @brief Calls `-[NSViewController presentViewController:asPopoverRelativeToRect:ofView:preferredEdge:behavior:]`.
     * @details Presents the viewController as a popover. The viewController is made the delegate and contentViewController of the popover while it is shown. NSPopover delegate methods can be used to customize the popover. This method calls [self presentViewController:viewController animator:] with an animator that controls the displaying of the popover. Call [presentingViewController dismissViewController:viewController] to close the viewController that was previously shown as a popover.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @param positioning_rect Argument converted to the Objective-C parameter of the same role.
     * @param positioning_view Argument converted to the Objective-C parameter of the same role.
     * @param preferred_edge Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     */
        void present_view_controller(const ViewController& view_controller, const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge, PopoverBehavior behavior) const;
        /**
     * @brief Calls `-[NSViewController presentViewController:asPopoverRelativeToRect:ofView:preferredEdge:behavior:hasFullSizeContent:]`.
     * @details This is the same as 'presentViewController:asPopoverRelativeToRect:ofView:preferredEdge:behavior:', except that it allows for configuring whether the popover has full size content or not.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     * @param positioning_rect Argument converted to the Objective-C parameter of the same role.
     * @param positioning_view Argument converted to the Objective-C parameter of the same role.
     * @param preferred_edge Argument converted to the Objective-C parameter of the same role.
     * @param behavior Argument converted to the Objective-C parameter of the same role.
     * @param has_full_size_content Argument converted to the Objective-C parameter of the same role.
     */
        void present_view_controller(const ViewController& view_controller, const Rect& positioning_rect, const View& positioning_view, RectEdge preferred_edge, PopoverBehavior behavior, bool has_full_size_content) const;
        /**
     * @brief Calls `-[NSViewController presentViewControllerAsModalWindow:]`.
     * @details Presents the viewController as a modal window (also known as an alert). The viewController is made the delegate and contentViewController of the window while it is shown. NSWindow delegate methods can be used to prevent closing of the window (if needed). This method calls [self presentViewController:viewController animator:] with an animator that controls the displaying of the window. Call [presentingViewController dismissViewController:viewController] to close the viewController that was previously shown as a modal window.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void present_view_controller_as_modal_window(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSViewController presentViewControllerAsSheet:]`.
     * @details Presents the viewController as a sheet. The viewController is made the delegate and contentViewController of the sheet while it is shown. This method calls [self presentViewController:viewController animator:] with an animator that controls the sheet animation. Call [presentingViewController dismissViewController:viewController] to close the viewController that was previously shown as a sheet.
     * @param view_controller Argument converted to the Objective-C parameter of the same role.
     */
        void present_view_controller_as_sheet(const ViewController& view_controller) const;
        /**
     * @brief Calls `-[NSViewController removeChildViewControllerAtIndex:]`.
     * @details Primitive method to remove a child view controller in the childViewControllers array. This method can be overridden to do additional work when a child is removed. If it is overridden, then the super implementation should be called. This is the primitive to override for performing insert operations in a container class, and has little value in itself if the parent doesn't do something with the children.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_child_view_controller_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSViewController removeFromParentViewController]`.
     * @details Removes the child controller from this parent controller. This method simply calls [self.parentViewController removeChildViewControllerAtIndex:index] with the appropriate index in the array.
     */
        void remove_from_parent_view_controller() const;
        /**
     * @brief Calls `-[NSViewController transitionFromViewController:toViewController:options:completionHandler:]`.
     * @details This method can be used to transition between sibling child view controllers. The receiver of this method is their common parent view controller. (Use [NSViewController addChildViewController:] to create the parent/child relationship.) This method will add the toViewController's view to the superview of the fromViewController's view. The fromViewController's view will be removed from the parent at the appropriate time. It is important to allow this method to add and remove the views. This method will throw an exception/assertion if the parent view controllers are not the same as the receiver, or if fromViewController.view does not have a superview.
     * @param from_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param to_view_controller Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param completion Argument converted to the Objective-C parameter of the same role.
     */
        void transition_from_view_controller(const ViewController& from_view_controller, const ViewController& to_view_controller, ViewControllerTransitionOptions options, std::function<void()> completion) const;
        /**
     * @brief Calls `-[NSViewController updateViewConstraints]`.
     * @details The base implementation sends -updateConstraints to the view. When a view has a view controller, this message is sent to the view controller during the autolayout updateConstraints pass in lieu of sending updateConstraints directly to the view. You may override this method in a NSViewController subclass for updating custom constraints instead of subclassing your view and overriding -[NSView updateConstraints]. Overrides must call super or send -updateConstraints to the view. This method is only called for applications that link on 10.10 and higher.
     */
        void update_view_constraints() const;
        /**
     * @brief Calls `-[NSViewController viewDidAppear]`.
     * @details Called when the view has been fully transitioned onto the screen, meaning it is not "hidden", does not have a hidden ancestor, and is in a window that's ordered in. Default does nothing. In general, it is good practice to call [super viewDidAppear] in case a superclass implements this method.
     */
        void view_did_appear() const;
        /**
     * @brief Calls `-[NSViewController viewDidDisappear]`.
     * @details Called after the view has been fully transitioned off the screen, meaning it is now "hidden" or has a hidden ancestor, or it not in a window, or is in a window that is ordered out. Default does nothing. In general, it is good practice to call [super viewDidDisappear] in case a superclass implements this method.
     */
        void view_did_disappear() const;
        /**
     * @brief Calls `-[NSViewController viewDidLayout]`.
     * @details Called just after the view controller's view's layout method is invoked. Subclasses can implement as necessary. The default is a no-op.
     */
        void view_did_layout() const;
        /**
     * @brief Calls `-[NSViewController viewDidLoad]`.
     * @details Called after the view has been loaded. For view controllers created in code, this is after -loadView. For view controllers unarchived from a nib, this is after the view is set. Default does nothing.
     */
        void view_did_load() const;
        /**
     * @brief Calls `-[NSViewController viewWillAppear]`.
     * @details Called when the view is about to appear, meaning it is going from a state of being "hidden" or having a hidden ancestor, and/or not being in a window or being in a window that is ordered out, to a state where none of these conditions is true. Default does nothing. In general, it is good practice to call [super viewWillAppear] in case a superclass implements this method. Causing a view to become hidden or removed from its window, or causing its window to be ordered out, in response to -viewWillAppear is not recommended and may result in an exception being raised. When such responses are necessary, defer them to a future runloop cycle.
     */
        void view_will_appear() const;
        /**
     * @brief Calls `-[NSViewController viewWillDisappear]`.
     * @details Called when the view is about to disappear, meaning it is going from a state of not being "hidden", nor having a hidden ancestor, nor having a nil window or being in a window that's ordered out, to a state where at least one of these conditions is true. Default does nothing. In general, it is good practice to call [super viewWillDisappear] in case a superclass implements this method. Causing a view to become unhidden, or causing its window to be ordered in, in response to -viewWillDisappear is not recommended and may result in an exception being raised. When such responses are necessary, defer them to a future runloop cycle.
     */
        void view_will_disappear() const;
        /**
     * @brief Calls `-[NSViewController viewWillLayout]`.
     * @details Called just before the view controller's view's layout method is invoked. Subclasses can implement as necessary. The default is a no-op.
     */
        void view_will_layout() const;
        /**
     * @brief Calls `-[NSViewController viewWillTransitionToSize:]`.
     * @details Sent to a service view controller when its view is about to be resized. Override this, if desired, to perform relayout in response to the resize, potentially in an animated way.
     * @param new_size Argument converted to the Objective-C parameter of the same role.
     */
        void view_will_transition_to_size(const Size& new_size) const;
        /**
     * @brief Returns the `childViewControllers` property of `NSViewController`.
     * @details An array of children view controllers. Assignment of the array filters all additions and removals through the insert and remove API below.
     * @return The converted Objective-C result.
     */
        std::vector<ViewController> child_view_controllers() const;
        /**
     * @brief Sets the `childViewControllers` property of `NSViewController`.
     * @details An array of children view controllers. Assignment of the array filters all additions and removals through the insert and remove API below.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_child_view_controllers(const std::vector<ViewController>& value) const;
        /**
     * @brief Returns the `extensionContext` property of `NSViewController`.
     * @details Returns the extension context. Also acts as a convenience method for a view controller to check if it participating in an extension request.
     * @return The converted Objective-C result.
     */
        ExtensionContext extension_context() const;
        /**
     * @brief Returns the `nibBundle` property of `NSViewController`.
     * @details Return the bundle that the nib will be loaded from. The default implementation returns whatever value was passed to the initializer.
     * @return The converted Objective-C result.
     */
        Bundle nib_bundle() const;
        /**
     * @brief Returns the `nibName` property of `NSViewController`.
     * @details Return the name of the nib to be loaded to instantiate the view. The default implementation returns whatever value was passed to the initializer.
     * @return The converted Objective-C result.
     */
        std::string nib_name() const;
        /**
     * @brief Returns the `parentViewController` property of `NSViewController`.
     * @details Returns the ancestor of this view controller. Can return nil if this is the contentViewController, or there is no parent for the given view controller.
     * @return The converted Objective-C result.
     */
        ViewController parent_view_controller() const;
        /**
     * @brief Returns the `preferredContentSize` property of `NSViewController`.
     * @details Expresses the view's desired size. May be consulted by a parent ViewController when performing layout.
     * @return The converted Objective-C result.
     */
        Size preferred_content_size() const;
        /**
     * @brief Sets the `preferredContentSize` property of `NSViewController`.
     * @details Expresses the view's desired size. May be consulted by a parent ViewController when performing layout.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_content_size(const Size& value) const;
        /**
     * @brief Returns the `preferredMaximumSize` property of `NSViewController`.
     * @details For services that vend UI. Expresses the largest allowable size for the service’s root view, in screen units. A service should return the maximum dimensions that are potentially useful for its root view, based on the items the service has been sent. This defaults to a large or infinite size.
     * @return The converted Objective-C result.
     */
        Size preferred_maximum_size() const;
        /**
     * @brief Returns the `preferredMinimumSize` property of `NSViewController`.
     * @details For services that vend UI. Expresses the smallest allowable size for the service’s root view, in screen units. A service should return the minimum dimensions its root view can accommodate, based on the items the service has been sent. This defaults to a small but non-empty size.
     * @return The converted Objective-C result.
     */
        Size preferred_minimum_size() const;
        /**
     * @brief Returns the `preferredScreenOrigin` property of `NSViewController`.
     * @details For services that vend UI. Set this to position the service UI's lower-left corner in screen space. (Use the 'preferredContentSize' property to specify the service UI's desired size, in screen units.)
     * @return The converted Objective-C result.
     */
        Point preferred_screen_origin() const;
        /**
     * @brief Sets the `preferredScreenOrigin` property of `NSViewController`.
     * @details For services that vend UI. Set this to position the service UI's lower-left corner in screen space. (Use the 'preferredContentSize' property to specify the service UI's desired size, in screen units.)
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_screen_origin(const Point& value) const;
        /**
     * @brief Returns the `presentedViewControllers` property of `NSViewController`.
     * @details The view controllers that were presented by this view controller. In other words, 'self' displayed each of the items in the array. This is a one-to-many relationship.
     * @return The converted Objective-C result.
     */
        std::vector<ViewController> presented_view_controllers() const;
        /**
     * @brief Returns the `presentingViewController` property of `NSViewController`.
     * @details The view controller that presented this view controller (or its farthest ancestor). In other words, 'presentingViewController' is the one that displayed 'self' to screen.
     * @return The converted Objective-C result.
     */
        ViewController presenting_view_controller() const;
        /**
     * @brief Returns the `representedObject` property of `NSViewController`.
     * @details The object whose value is being presented in the view. The default implementation of -setRepresentedObject: doesn't copy the passed-in object, it retains it. (In another words, "representedObject" is a to-one relationship, not an attribute.) This class is key-value coding and key-value observing compliant for "representedObject" so when you use it as the file's owner of a view's nib you can bind controls to the file's owner using key paths that start with "representedObject."
     * @return The converted Objective-C result.
     */
        Object represented_object() const;
        /**
     * @brief Sets the `representedObject` property of `NSViewController`.
     * @details The object whose value is being presented in the view. The default implementation of -setRepresentedObject: doesn't copy the passed-in object, it retains it. (In another words, "representedObject" is a to-one relationship, not an attribute.) This class is key-value coding and key-value observing compliant for "representedObject" so when you use it as the file's owner of a view's nib you can bind controls to the file's owner using key paths that start with "representedObject."
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_represented_object(const Object& value) const;
        /**
     * @brief Returns the `sourceItemView` property of `NSViewController`.
     * @details For services that vend UI. Identifies the view (if any) in the service’s UI that displays the source image. Defaults to nil. When your service loads its UI (or in your service UI's xib file), you can set this to point to an image view, or some containing border view, that’s a descendant of the ViewController’s view. Doing so helps the system to position and animate the service’s UI with respect to the source item representation. If your service UI doesn't display the source item at its original screen position and size, leave this set to nil.
     * @return The converted Objective-C result.
     */
        View source_item_view() const;
        /**
     * @brief Sets the `sourceItemView` property of `NSViewController`.
     * @details For services that vend UI. Identifies the view (if any) in the service’s UI that displays the source image. Defaults to nil. When your service loads its UI (or in your service UI's xib file), you can set this to point to an image view, or some containing border view, that’s a descendant of the ViewController’s view. Doing so helps the system to position and animate the service’s UI with respect to the source item representation. If your service UI doesn't display the source item at its original screen position and size, leave this set to nil.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_source_item_view(const View& value) const;
        /**
     * @brief Returns the `storyboard` property of `NSViewController`.
     * @details The Storyboard the ViewController was loaded from. Returns nil if the ViewController was not loaded from a Storyboard.
     * @return The converted Objective-C result.
     */
        Storyboard storyboard() const;
        /**
     * @brief Returns the `title` property of `NSViewController`.
     * @details The localized title of the view. This class doesn't actually do anything with the value of this property other than hold onto it, and be KVC and KVO compliant for "title." The default implementation of -setTitle: copies the passed-in object ("title" is an attribute). This property is here because so many anticipated uses of this class will involve letting the user choose among multiple named views using a pulldown menu or something like that.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /**
     * @brief Sets the `title` property of `NSViewController`.
     * @details The localized title of the view. This class doesn't actually do anything with the value of this property other than hold onto it, and be KVC and KVO compliant for "title." The default implementation of -setTitle: copies the passed-in object ("title" is an attribute). This property is here because so many anticipated uses of this class will involve letting the user choose among multiple named views using a pulldown menu or something like that.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_title(const std::string& value) const;
        /**
     * @brief Returns the `view` property of `NSViewController`.
     * @details The default implementation of the getter first invokes [self loadView] if the view hasn't been set yet. After -loadView is called, -viewDidLoad will be called. The setter can be used to assign a view that's created in a different manner than what -view's default implementation would do.
     * @return The converted Objective-C result.
     */
        View view() const;
        /**
     * @brief Sets the `view` property of `NSViewController`.
     * @details The default implementation of the getter first invokes [self loadView] if the view hasn't been set yet. After -loadView is called, -viewDidLoad will be called. The setter can be used to assign a view that's created in a different manner than what -view's default implementation would do.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_view(const View& value) const;
        /**
     * @brief Returns the `viewIfLoaded` property of `NSViewController`.
     * @details Returns the view controller's view, or nil if the view has not been loaded.
     * @return The converted Objective-C result.
     */
        View view_if_loaded() const;
        /**
     * @brief Returns the `viewLoaded` property of `NSViewController`.
     * @details Returns whether the view has been loaded or not.
     * @return The converted Objective-C result.
     */
        bool is_view_loaded() const;
    };
}
