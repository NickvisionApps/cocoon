#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view_controller.h"
#include "types.h"

namespace cocoon
{
    class ViewController;

    /**
     * @brief C++ handle for the Objective-C class `NSPageController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PageController page_controller;
     * page_controller.prepare_view_controller_with_object().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PageController page_controller{};
     * page_controller.set_selected_index(1);
     * auto selected_index = page_controller.selected_index();
     * page_controller.set_transition_style(cocoon::PageControllerTransitionStyle::StackHistory);
     * auto transition_style = page_controller.transition_style();
     * page_controller.complete_transition();
     * page_controller.prepare_view_controller_with_object().connect([](cocoon::ViewController a0, cocoon::Object a1) {});
     * page_controller.did_transition_to_object().connect([](cocoon::Object a0) {});
     * page_controller.will_start_live_transition().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspagecontroller
     */
    class PageController : public ViewController
    {
    public:
        /// @brief Creates a new `NSPageController` instance and returns a handle to it.
        explicit PageController();
        /// @brief Creates a null handle that refers to no native object.
        PageController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PageController(Adopt adopt);
        /**
     * @brief Calls `-[NSPageController completeTransition]`.
     * @details Hide the transition view used for animation and show the selectedViewController.view. Generally, this is called during pageControllerDidEndLiveTransition: in the delegate when the new contents of view is ready to be displayed.
     */
        void complete_transition() const;
        /**
     * @brief Calls `-[NSPageController navigateBack:]`.
     * @details Supported IBActions - all IB actions are animated and delegate LiveTransition methods are called.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void navigate_back(const Object& sender) const;
        /**
     * @brief Calls `-[NSPageController navigateForward:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void navigate_forward(const Object& sender) const;
        /**
     * @brief Calls `-[NSPageController navigateForwardToObject:]`.
     * @details Clears the arrangedObjects array after the selected index, adds the argument to the arrangedObjects array, and sets the selectedIndex to the argument.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void navigate_forward_to_object(const Object& object) const;
        /**
     * @brief Calls `-[NSPageController takeSelectedIndexFrom:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void take_selected_index_from(const Object& sender) const;
        /**
     * @brief Returns the `arrangedObjects` property of `NSPageController`.
     * @details Array of all displayed objects (after sorting and potentially filtering by you). The delegate will be asked for snapshots as they are needed. Alternatively, you may never directly set this array and use the -navigateForwardToRepresentedObject API to create a history as the user navigates. This property is KVO compliant.
     * @return The converted Objective-C result.
     */
        std::vector<Object> arranged_objects() const;
        /**
     * @brief Sets the `arrangedObjects` property of `NSPageController`.
     * @details Array of all displayed objects (after sorting and potentially filtering by you). The delegate will be asked for snapshots as they are needed. Alternatively, you may never directly set this array and use the -navigateForwardToRepresentedObject API to create a history as the user navigates. This property is KVO compliant.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_arranged_objects(const std::vector<Object>& value) const;
        /**
     * @brief Returns the `selectedIndex` property of `NSPageController`.
     * @details The index into the arrangedObjects that is being displayed. This property is KVO compliant. To animate a transition to a new index, use NSPageController's animator object.
     * @return The converted Objective-C result.
     */
        std::int64_t selected_index() const;
        /**
     * @brief Sets the `selectedIndex` property of `NSPageController`.
     * @details The index into the arrangedObjects that is being displayed. This property is KVO compliant. To animate a transition to a new index, use NSPageController's animator object.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_index(std::int64_t value) const;
        /**
     * @brief Returns the `selectedViewController` property of `NSPageController`.
     * @details The viewController associated with the selected arrangedObject. May be nil if delegate is not supplying viewControllers.
     * @return The converted Objective-C result.
     */
        ViewController selected_view_controller() const;
        /**
     * @brief Returns the `transitionStyle` property of `NSPageController`.
     * @details The animation style used when transitioning from one page to another. The default value is NSPageControllerTransitionStyleStackHistory
     * @return The converted Objective-C result.
     */
        PageControllerTransitionStyle transition_style() const;
        /**
     * @brief Sets the `transitionStyle` property of `NSPageController`.
     * @details The animation style used when transitioning from one page to another. The default value is NSPageControllerTransitionStyleStackHistory
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transition_style(PageControllerTransitionStyle value) const;
        /// @brief Signal for the delegate/data-source method behind `identifier_for_object`; connect a callback with `identifier_for_object().connect(...)`.
        Signal<PageController, std::string(Object)> identifier_for_object() const
        {
            return Signal<PageController, std::string(Object)>(handle(), "identifier_for_object");
        }
        /// @brief Signal for the delegate/data-source method behind `view_controller_for_identifier`; connect a callback with `view_controller_for_identifier().connect(...)`.
        Signal<PageController, ViewController(std::string)> view_controller_for_identifier() const
        {
            return Signal<PageController, ViewController(std::string)>(handle(), "view_controller_for_identifier");
        }
        /// @brief Signal for the delegate/data-source method behind `frame_for_object`; connect a callback with `frame_for_object().connect(...)`.
        Signal<PageController, Rect(Object)> frame_for_object() const
        {
            return Signal<PageController, Rect(Object)>(handle(), "frame_for_object");
        }
        /// @brief Signal for the delegate/data-source method behind `prepare_view_controller_with_object`; connect a callback with `prepare_view_controller_with_object().connect(...)`.
        Signal<PageController, void(ViewController, Object)> prepare_view_controller_with_object() const
        {
            return Signal<PageController, void(ViewController, Object)>(handle(), "prepare_view_controller_with_object");
        }
        /// @brief Signal for the delegate/data-source method behind `did_transition_to_object`; connect a callback with `did_transition_to_object().connect(...)`.
        Signal<PageController, void(Object)> did_transition_to_object() const
        {
            return Signal<PageController, void(Object)>(handle(), "did_transition_to_object");
        }
        /// @brief Signal for the delegate/data-source method behind `will_start_live_transition`; connect a callback with `will_start_live_transition().connect(...)`.
        Signal<PageController, void()> will_start_live_transition() const
        {
            return Signal<PageController, void()>(handle(), "will_start_live_transition");
        }
        /// @brief Signal for the delegate/data-source method behind `did_end_live_transition`; connect a callback with `did_end_live_transition().connect(...)`.
        Signal<PageController, void()> did_end_live_transition() const
        {
            return Signal<PageController, void()>(handle(), "did_end_live_transition");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
