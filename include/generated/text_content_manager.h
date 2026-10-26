#pragma once

#include "generated/availability.h"
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
         * @param text_layout_manager Argument converted to the Objective-C parameter of the same role.
         */
        void add_text_layout_manager(const TextLayoutManager& text_layout_manager) const;
        /**
         * @brief Calls `-[NSTextContentManager performEditingTransactionUsingBlock:]`.
         * @param transaction Argument converted to the Objective-C parameter of the same role.
         */
        void perform_editing_transaction_using_block(std::function<void()> transaction) const;
        /**
         * @brief Calls `-[NSTextContentManager recordEditActionInRange:newTextRange:]`.
         * @param original_text_range Argument converted to the Objective-C parameter of the same role.
         * @param new_text_range Argument converted to the Objective-C parameter of the same role.
         */
        void record_edit_action_in_range(const TextRange& original_text_range, const TextRange& new_text_range) const;
        /**
         * @brief Calls `-[NSTextContentManager removeTextLayoutManager:]`.
         * @param text_layout_manager Argument converted to the Objective-C parameter of the same role.
         */
        void remove_text_layout_manager(const TextLayoutManager& text_layout_manager) const;
        /**
         * @brief Calls `-[NSTextContentManager synchronizeTextLayoutManagers:]`.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void synchronize_text_layout_managers(std::function<void(Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSTextContentManager textElementsForRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<TextElement> text_elements_for_range(const TextRange& range) const;
        /**
         * @brief Returns the `automaticallySynchronizesTextLayoutManagers` property of `NSTextContentManager`.
         * @return The converted Objective-C result.
         */
        bool automatically_synchronizes_text_layout_managers() const;
        /**
         * @brief Sets the `automaticallySynchronizesTextLayoutManagers` property of `NSTextContentManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_synchronizes_text_layout_managers(bool value) const;
        /**
         * @brief Returns the `automaticallySynchronizesToBackingStore` property of `NSTextContentManager`.
         * @return The converted Objective-C result.
         */
        bool automatically_synchronizes_to_backing_store() const;
        /**
         * @brief Sets the `automaticallySynchronizesToBackingStore` property of `NSTextContentManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_synchronizes_to_backing_store(bool value) const;
        /**
         * @brief Returns the `hasEditingTransaction` property of `NSTextContentManager`.
         * @return The converted Objective-C result.
         */
        bool has_editing_transaction() const;
        /**
         * @brief Returns the `primaryTextLayoutManager` property of `NSTextContentManager`.
         * @return The converted Objective-C result.
         */
        TextLayoutManager primary_text_layout_manager() const;
        /**
         * @brief Sets the `primaryTextLayoutManager` property of `NSTextContentManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_primary_text_layout_manager(const TextLayoutManager& value) const;
        /**
         * @brief Returns the `textLayoutManagers` property of `NSTextContentManager`.
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
