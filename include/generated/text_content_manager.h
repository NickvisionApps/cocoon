#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class TextElement;
    class TextLayoutManager;
    class TextRange;

    /**
     * @brief C++ handle for the Objective-C class `NSTextContentManager` (AppKit).
     * @details An abstract class that defines the interface and a default implementation for managing the text document contents. The concrete subclass overrides ''NSTextElementProvider'' for managing the content backing store. It is the root object that strongly references the rest of objects in the TextKit network via an array of ''NSTextLayoutManager''. It manages the editing transaction by tracking the ''NSTextLayoutManager'' that is active and focused for editing.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextContentManager text_content_manager;
     * text_content_manager.set_automatically_synchronizes_text_layout_managers(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextContentManager text_content_manager{};
     * text_content_manager.set_automatically_synchronizes_text_layout_managers(true);
     * auto automatically_synchronizes_text_layout_managers = text_content_manager.automatically_synchronizes_text_layout_managers();
     * text_content_manager.set_automatically_synchronizes_to_backing_store(true);
     * auto automatically_synchronizes_to_backing_store = text_content_manager.automatically_synchronizes_to_backing_store();
     * text_content_manager.set_primary_text_layout_manager(cocoon::TextLayoutManager());
     * auto primary_text_layout_manager = text_content_manager.primary_text_layout_manager();
     * text_content_manager.add_text_layout_manager(cocoon::TextLayoutManager());
     * text_content_manager.record_edit_action_in_range(cocoon::TextRange(), cocoon::TextRange());
     * text_content_manager.remove_text_layout_manager(cocoon::TextLayoutManager());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextcontentmanager
     */
    class TextContentManager : public Object
    {
    public:
        /// @brief Creates a new `NSTextContentManager` instance and returns a handle to it.
        explicit TextContentManager();
        /// @brief Creates a null handle that refers to no native object.
        TextContentManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextContentManager(Adopt adopt);
        /**
     * @brief Calls `-[NSTextContentManager addTextLayoutManager:]`.
     * @details Adds the text layout manager you provide to the list of layout managers. - Parameters: - textLayoutManager: The text layout manager to add.
     * @param text_layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void add_text_layout_manager(const TextLayoutManager& text_layout_manager) const;
        /**
     * @brief Calls `-[NSTextContentManager performEditingTransactionUsingBlock:]`.
     * @details Performs an editing transaction and invokes a block upon completion. Invoked by ''primaryTextLayoutManager'' controlling the active editing transaction. Can be nested. The outermost transaction toggles ''hasEditingTransaction'' and sends synchronization messages if enabled after invoking 'transaction'. - Parameters: - transaction: The block to execute within the editing transaction.
     * @param transaction Argument converted to the Objective-C parameter of the same role.
     */
        void perform_editing_transaction_using_block(std::function<void()> transaction) const;
        /**
     * @brief Calls `-[NSTextContentManager recordEditActionInRange:newTextRange:]`.
     * @details Records information about an edit action to the transaction. 'originalTextRange' is the range edited before the action, and 'newTextRange' is the corresponding range after the action. The concrete subclass should invoke this method for each edit action. - Parameters: - originalTextRange: The range before the edit. - newTextRange: The corresponding range after the edit.
     * @param original_text_range Argument converted to the Objective-C parameter of the same role.
     * @param new_text_range Argument converted to the Objective-C parameter of the same role.
     */
        void record_edit_action_in_range(const TextRange& original_text_range, const TextRange& new_text_range) const;
        /**
     * @brief Calls `-[NSTextContentManager removeTextLayoutManager:]`.
     * @details Removes the text layout manager you specify from the list of layout managers. - Parameters: - textLayoutManager: The text layout manager to remove.
     * @param text_layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void remove_text_layout_manager(const TextLayoutManager& text_layout_manager) const;
        /**
     * @brief Calls `-[NSTextContentManager synchronizeTextLayoutManagers:]`.
     * @details Synchronizes changes to all nonprimary text layout managers. If 'completionHandler' is 'nil', this method performs the operation synchronously. The framework passes any error to the 'completionHandler'. The method blocks (or fails, if synchronous) when there's an active transaction. - Parameters: - completionHandler: A completion handler that runs on success, or to handle error conditions.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void synchronize_text_layout_managers(std::function<void(Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSTextContentManager textElementsForRange:]`.
     * @details Returns an array of text elements that intersect with the range you specify. This method can return a set of elements that don't fill the entire range if the entire range isn't synchronously available. Uses ''NSTextElementProvider/enumerateTextElements(from:options:using:)'' to fill the array. - Parameters: - range: An ''NSTextRange'' that describes the range of text to process. - Returns: An array of ''NSTextElement''.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<TextElement> text_elements_for_range(const TextRange& range) const;
        /**
     * @brief Returns the `automaticallySynchronizesTextLayoutManagers` property of `NSTextContentManager`.
     * @details Determines if the framework should automatically synchronize all text layout managers when exiting an editing transaction. The default value is 'true'.
     * @return The converted Objective-C result.
     */
        bool automatically_synchronizes_text_layout_managers() const;
        /**
     * @brief Sets the `automaticallySynchronizesTextLayoutManagers` property of `NSTextContentManager`.
     * @details Determines if the framework should automatically synchronize all text layout managers when exiting an editing transaction. The default value is 'true'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_synchronizes_text_layout_managers(bool value) const;
        /**
     * @brief Returns the `automaticallySynchronizesToBackingStore` property of `NSTextContentManager`.
     * @details Determines whether to automatically synchronize with the backing store when an editing transaction finishes. The default value is 'false'.
     * @return The converted Objective-C result.
     */
        bool automatically_synchronizes_to_backing_store() const;
        /**
     * @brief Sets the `automaticallySynchronizesToBackingStore` property of `NSTextContentManager`.
     * @details Determines whether to automatically synchronize with the backing store when an editing transaction finishes. The default value is 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_automatically_synchronizes_to_backing_store(bool value) const;
        /**
     * @brief Returns the `hasEditingTransaction` property of `NSTextContentManager`.
     * @details Indicates there's an active editing transaction from the primary text layout manager. The synchronization operations to non-primary text layout managers and the backing store block (or fail when synchronous) while this property is 'true'. Non-primary text layout managers should avoid accessing the elements while this is 'true'. KVO-compliant.
     * @return The converted Objective-C result.
     */
        bool has_editing_transaction() const;
        /**
     * @brief Returns the `primaryTextLayoutManager` property of `NSTextContentManager`.
     * @details The primary text layout manager for this content. The primary ''NSTextLayoutManager'' interacts with the user, allowing edits. Setting this property to an ''NSTextLayoutManager'' not in ''textLayoutManagers'' resets it to 'nil'. It automatically synchronizes pending edits before switching to a new primary object. The operation is synchronous. This property is KVO-compliant.
     * @return The converted Objective-C result.
     */
        TextLayoutManager primary_text_layout_manager() const;
        /**
     * @brief Sets the `primaryTextLayoutManager` property of `NSTextContentManager`.
     * @details The primary text layout manager for this content. The primary ''NSTextLayoutManager'' interacts with the user, allowing edits. Setting this property to an ''NSTextLayoutManager'' not in ''textLayoutManagers'' resets it to 'nil'. It automatically synchronizes pending edits before switching to a new primary object. The operation is synchronous. This property is KVO-compliant.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_primary_text_layout_manager(const TextLayoutManager& value) const;
        /**
     * @brief Returns the `textLayoutManagers` property of `NSTextContentManager`.
     * @details The array of text layout managers associated with this text content manager. This property is KVO-compliant.
     * @return The converted Objective-C result.
     */
        std::vector<TextLayoutManager> text_layout_managers() const;
        /// @brief Signal for the delegate/data-source method behind `text_element_at_location`; connect a callback with `text_element_at_location().connect(...)`.
        Signal<TextContentManager, TextElement(Object)> text_element_at_location() const
        {
            return Signal<TextContentManager, TextElement(Object)>(handle(), "text_element_at_location");
        }
        /// @brief Signal for the delegate/data-source method behind `should_enumerate_text_element_options`; connect a callback with `should_enumerate_text_element_options().connect(...)`.
        Signal<TextContentManager, bool(TextElement, TextContentManagerEnumerationOptions)> should_enumerate_text_element_options() const
        {
            return Signal<TextContentManager, bool(TextElement, TextContentManagerEnumerationOptions)>(handle(), "should_enumerate_text_element_options");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
