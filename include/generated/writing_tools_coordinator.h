#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class UUID;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSWritingToolsCoordinator` (AppKit).
     * @details An object that manages interactions between Writing Tools and your custom text view. Add a 'NSWritingToolsCoordinator' object to a custom view when you want to add Writing Tools support to that view. The coordinator manages interactions between your view and the Writing Tools UI and back-end capabilities. When creating a coordinator, you supply a delegate object to respond to requests from the system and provide needed information. Your delegate delivers your view’s text to Writing Tools, incorporates suggested changes back into your text storage, and supports the animations that Writing Tools creates to show the state of an operation. Create the 'NSWritingToolsCoordinator' object when setting up your UI, and initialize it with a custom object that adopts the ''NSWritingToolsCoordinator/Delegate'' protocol. Add the coordinator to the ''NSView/writingToolsCoordinator'' property of your view. When a coordinator is present on a view, the system adds UI elements to initiate Writing Tools operations. When defining the delegate, choose an object from your app that has access to your view and its text storage. You can adopt the ''NSWritingToolsCoordinator/Delegate'' protocol in the view itself, or in another type that your view uses to manage content. During the interactions with Writing Tools, the delegate gets and sets the contents of the view’s text storage and supports Writing Tools behaviors. > Note: You don’t need to create an 'NSWritingToolsCoordinator' object if you display text using a \<doc://com.apple.documentation/documentation/uikit/uitextview>, ''NSTextField'', ''NSTextView'', \<doc://com.apple.documentation/documentation/swiftui/textfield>, or \<doc://com.apple.documentation/documentation/swiftui/texteditor> view. Those views already include the required support to handle Writing Tools interactions.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WritingToolsCoordinator writing_tools_coordinator;
     * writing_tools_coordinator.set_decoration_container_view(cocoon::View());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::WritingToolsCoordinator writing_tools_coordinator{};
     * writing_tools_coordinator.set_decoration_container_view(cocoon::View());
     * auto decoration_container_view = writing_tools_coordinator.decoration_container_view();
     * writing_tools_coordinator.set_effect_container_view(cocoon::View());
     * auto effect_container_view = writing_tools_coordinator.effect_container_view();
     * writing_tools_coordinator.set_includes_text_list_markers(true);
     * auto includes_text_list_markers = writing_tools_coordinator.includes_text_list_markers();
     * writing_tools_coordinator.stop_writing_tools();
     * writing_tools_coordinator.update_for_reflowed_text_in_context_with_identifier(cocoon::UUID());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswritingtoolscoordinator
     */
    class WritingToolsCoordinator : public Object
    {
    public:
        /// @brief Creates a new `NSWritingToolsCoordinator` instance and returns a handle to it.
        explicit WritingToolsCoordinator(const Object& delegate);
        /// @brief Creates a new `NSWritingToolsCoordinator` instance and returns a handle to it.
        explicit WritingToolsCoordinator();
        /// @brief Creates a null handle that refers to no native object.
        WritingToolsCoordinator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WritingToolsCoordinator(Adopt adopt);
        /**
     * @brief Calls `-[NSWritingToolsCoordinator stopWritingTools]`.
     * @details Stops the current Writing Tools operation and dismisses the system UI. Call this method to abort the current Writing Tools operation. This method dismisses the system’s Writing Tools UI and stops any in-flight interactions with your view. This method does not undo any changes that Writing Tools already made to your view’s content.
     */
        void stop_writing_tools() const;
        /**
     * @brief Calls `-[NSWritingToolsCoordinator updateForReflowedTextInContextWithIdentifier:]`.
     * @details Informs the coordinator that a change occurred to the view or its text that requires a layout update. - Parameters: - contextID: The unique identifier of the context object affected by the change. Pass the identifier for the context object that comes after the changes. Use this method to inform Writing Tools when the geometry of your view changes, or when the text that precedes one of your context objects changes. Changes to the view’s geometry or text can affect the flow of any remaining text, and require a layout update. Writing Tools uses this method to refresh any layout-dependent information it’s currently tracking. For example, it uses it to refresh the location of proofreading marks it’s displaying in your view. If a text change affects the text inside a context object, call the ''updateRange(:with:reason:forContextWithIdentifier:)'' method to report that change instead.
     * @param context_id Argument converted to the Objective-C parameter of the same role.
     */
        void update_for_reflowed_text_in_context_with_identifier(const UUID& context_id) const;
        /**
     * @brief Calls `-[NSWritingToolsCoordinator updateRange:withText:reason:forContextWithIdentifier:]`.
     * @details Informs the coordinator about changes your app made to the text in the specified context object. - Parameters: - range: The range of text to replace. This range is relative to the starting location of the specified context object’s text in your view’s text storage. If you initialized the context object with the entire contents of your view’s text storage, specify the range of text you’re replacing in your text storage. However, if you initialized the context object with only a portion of your view’s text, specify a range that is relative to the starting location of the context object’s text. - replacementText: The text that replaces the previous content in 'range'. Specify an empty string to delete the text in the specified range. - reason: The reason you updated the text. - contextID: The unique identifier of the context object that contains the text you modified. If you make any changes to the text Writing Tools is evaluating, call this method to report those changes to your view’s coordinator object. You might make changes in response to an undo command or when someone types into the same part of your view’s text. Calling this method keeps the coordinator object informed of any changes, and ensures it delivers accurate information to its delegate. In response, the coordinator refreshes previews and other information related to your view. If the scope of the update is significantly large, the coordinator can optionally cancel the Writing Tools session altogether. Use this method to report changes that precisely intersect your context object’s text. The first time you call this method for a context object, report changes only to the original attributed string in that object. If you call this method more than once, report changes to the newly modified version of that string. Don’t use this method to report changes to text that comes before or after the context object. If you make changes before your context object, report those changes separately using the ''updateForReflowedTextInContextWithIdentifier(:)'' method. > Warning: Failure to call this method for a change can cause Writing Tools to deliver inaccurate information to your delegate and lead to data loss.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param replacement_text Argument converted to the Objective-C parameter of the same role.
     * @param reason Argument converted to the Objective-C parameter of the same role.
     * @param context_id Argument converted to the Objective-C parameter of the same role.
     */
        void update_range(const Range& range, const AttributedString& replacement_text, WritingToolsCoordinatorTextUpdateReason reason, const UUID& context_id) const;
        /**
     * @brief Returns the `behavior` property of `NSWritingToolsCoordinator`.
     * @details The actual level of Writing Tools support the system provides for your view. The system chooses this value based on the device capabilities, and takes the value in the ''preferredBehavior'' property into consideration when making the choice. The value in this property is never the default option, and is instead one of the specific options such as ''NSWritingToolsBehavior/none'', ''NSWritingToolsBehavior/limited'', or ''NSWritingToolsBehavior/complete''.
     * @return The converted Objective-C result.
     */
        WritingToolsBehavior behavior() const;
        /**
     * @brief Returns the `decorationContainerView` property of `NSWritingToolsCoordinator`.
     * @details The view that Writing Tools uses to display background decorations such as proofreading marks. Writing Tools uses the view in this property to host proofreading marks and other visual elements that show any suggested changes. Set this property to a subview situated visibly below the text in your custom text view. It's also satisfactory to place this view visually in front of the text. Make sure the size of the view is big enough to cover all of the affected text. If you don’t assign a value to this property, the coordinator places its own decoration view behind the subviews in your custom view. The default value of this property is 'nil'. If you display your view’s text using multiple text containers, implement the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsSingleContainerSubrangesOf:in:completion:)'' and ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsDecorationContainerViewFor:in:completion:)'' methods to provide separate decoration views for each container.
     * @return The converted Objective-C result.
     */
        View decoration_container_view() const;
        /**
     * @brief Sets the `decorationContainerView` property of `NSWritingToolsCoordinator`.
     * @details The view that Writing Tools uses to display background decorations such as proofreading marks. Writing Tools uses the view in this property to host proofreading marks and other visual elements that show any suggested changes. Set this property to a subview situated visibly below the text in your custom text view. It's also satisfactory to place this view visually in front of the text. Make sure the size of the view is big enough to cover all of the affected text. If you don’t assign a value to this property, the coordinator places its own decoration view behind the subviews in your custom view. The default value of this property is 'nil'. If you display your view’s text using multiple text containers, implement the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsSingleContainerSubrangesOf:in:completion:)'' and ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsDecorationContainerViewFor:in:completion:)'' methods to provide separate decoration views for each container.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_decoration_container_view(const View& value) const;
        /**
     * @brief Returns the `effectContainerView` property of `NSWritingToolsCoordinator`.
     * @details The view that Writing Tools uses to display visual effects during the text-rewriting process. Writing Tools uses the view in this property to host the visual effects it creates when making interactive changes to your view’s content. These visual effects let people know the state of the text and provide feedback about what’s happening to it. Set this property to a subview that sits visually above, and covers, all of the text in your custom text view. If you don’t assign a value to this property, the coordinator places its own effect view in front of the subviews in your custom view. The default value of this property is 'nil'. If you display your view’s text using multiple text containers, implement the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsSingleContainerSubrangesOf:in:completion:)'' method to request multiple previews.
     * @return The converted Objective-C result.
     */
        View effect_container_view() const;
        /**
     * @brief Sets the `effectContainerView` property of `NSWritingToolsCoordinator`.
     * @details The view that Writing Tools uses to display visual effects during the text-rewriting process. Writing Tools uses the view in this property to host the visual effects it creates when making interactive changes to your view’s content. These visual effects let people know the state of the text and provide feedback about what’s happening to it. Set this property to a subview that sits visually above, and covers, all of the text in your custom text view. If you don’t assign a value to this property, the coordinator places its own effect view in front of the subviews in your custom view. The default value of this property is 'nil'. If you display your view’s text using multiple text containers, implement the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:requestsSingleContainerSubrangesOf:in:completion:)'' method to request multiple previews.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_effect_container_view(const View& value) const;
        /**
     * @brief Returns the `includesTextListMarkers` property of `NSWritingToolsCoordinator`.
     * @return The converted Objective-C result.
     */
        bool includes_text_list_markers() const;
        /**
     * @brief Sets the `includesTextListMarkers` property of `NSWritingToolsCoordinator`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_includes_text_list_markers(bool value) const;
        /**
     * @brief Returns the `isWritingToolsAvailable` property of `NSWritingToolsCoordinator`.
     * @details A Boolean value that indicates whether Writing Tools features are currently available. The value of this property is 'true' when Writing Tools features are available, and 'false' when they aren’t. Writing Tools support might be unavailable because of device constraints or because the system isn’t ready to process Writing Tools requests.
     * @return The converted Objective-C result.
     */
        static bool is_writing_tools_available();
        /**
     * @brief Returns the `preferredBehavior` property of `NSWritingToolsCoordinator`.
     * @details The level of Writing Tools support you want the system to provide for your view. Use this property to request an inline or panel-based experience, or to disable Writing Tools for your view altogether. The default value of this property is ''NSWritingToolsBehavior/default''.
     * @return The converted Objective-C result.
     */
        WritingToolsBehavior preferred_behavior() const;
        /**
     * @brief Sets the `preferredBehavior` property of `NSWritingToolsCoordinator`.
     * @details The level of Writing Tools support you want the system to provide for your view. Use this property to request an inline or panel-based experience, or to disable Writing Tools for your view altogether. The default value of this property is ''NSWritingToolsBehavior/default''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_behavior(WritingToolsBehavior value) const;
        /**
     * @brief Returns the `preferredResultOptions` property of `NSWritingToolsCoordinator`.
     * @details The type of content you allow Writing Tools to generate for your custom text view. Writing Tools can create plain text or rich text, and it can format text using lists or tables as needed. If your view doesn’t support specific types of content, specify the types you do support in this property. The default value of this property is ''NSWritingToolsResultOptions/default'', which lets the system determine the type of content to generate.
     * @return The converted Objective-C result.
     */
        WritingToolsResultOptions preferred_result_options() const;
        /**
     * @brief Sets the `preferredResultOptions` property of `NSWritingToolsCoordinator`.
     * @details The type of content you allow Writing Tools to generate for your custom text view. Writing Tools can create plain text or rich text, and it can format text using lists or tables as needed. If your view doesn’t support specific types of content, specify the types you do support in this property. The default value of this property is ''NSWritingToolsResultOptions/default'', which lets the system determine the type of content to generate.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_result_options(WritingToolsResultOptions value) const;
        /**
     * @brief Returns the `resultOptions` property of `NSWritingToolsCoordinator`.
     * @details The type of content the system generates for your custom text view. This property contains the set of options that Writing Tools outputs for your view. Writing Tools takes the value in the ''NSWritingToolsCoordinator/preferredResultOptions'' property into consideration when determining this value.
     * @return The converted Objective-C result.
     */
        WritingToolsResultOptions result_options() const;
        /**
     * @brief Returns the `state` property of `NSWritingToolsCoordinator`.
     * @details The current level of Writing Tools activity in your view. Use this property to determine when Writing Tools is actively making changes to your view. During the course of Writing Tools interactions, the system reports state changes to the delegate’s ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:willChangeTo:completion:)'' method and updates this property accordingly.
     * @return The converted Objective-C result.
     */
        WritingToolsCoordinatorState state() const;
        /**
     * @brief Returns the `view` property of `NSWritingToolsCoordinator`.
     * @details The view that currently uses the writing tools coordinator. Use this property to refer to the view that currently owns the coordinator object. The system updates this property automatically when you assign the coordinator to the ''NSView/writingToolsCoordinator'' property of your view. The value of this property is 'nil' if there is no associated view.
     * @return The converted Objective-C result.
     */
        View view() const;
    };
}
