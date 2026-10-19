#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/mutable_attributed_string.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Font;
    class LayoutManager;

    /**
     * @brief C++ handle for the Objective-C class `NSTextStorage` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref MutableAttributedString.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextStorage text_storage;
     * text_storage.will_process_editing_range_change_in_length().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextStorage text_storage{};
     * text_storage.set_font(cocoon::Font());
     * auto font = text_storage.font();
     * text_storage.set_foreground_color(cocoon::Color());
     * auto foreground_color = text_storage.foreground_color();
     * text_storage.add_layout_manager(cocoon::LayoutManager());
     * text_storage.process_editing();
     * text_storage.remove_layout_manager(cocoon::LayoutManager());
     * text_storage.will_process_editing_range_change_in_length().connect([](cocoon::TextStorageEditActions a0, cocoon::Range a1, std::int64_t a2) {});
     * text_storage.did_process_editing_range_change_in_length().connect([](cocoon::TextStorageEditActions a0, cocoon::Range a1, std::int64_t a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextstorage
     */
    class TextStorage : public MutableAttributedString
    {
    public:
        /// @brief Creates a new `NSTextStorage` instance and returns a handle to it.
        explicit TextStorage();
        /// @brief Creates a null handle that refers to no native object.
        TextStorage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextStorage(Adopt adopt);
        /**
     * @brief Calls `-[NSTextStorage addLayoutManager:]`.
     * @param a_layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void add_layout_manager(const LayoutManager& a_layout_manager) const;
        /**
     * @brief Calls `-[NSTextStorage edited:range:changeInLength:]`.
     * @param edited_mask Argument converted to the Objective-C parameter of the same role.
     * @param edited_range Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void edited(TextStorageEditActions edited_mask, const Range& edited_range, std::int64_t delta) const;
        /**
     * @brief Calls `-[NSTextStorage ensureAttributesAreFixedInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_attributes_are_fixed_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSTextStorage invalidateAttributesInRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_attributes_in_range(const Range& range) const;
        /**
     * @brief Calls `-[NSTextStorage processEditing]`.
     */
        void process_editing() const;
        /**
     * @brief Calls `-[NSTextStorage removeLayoutManager:]`.
     * @param a_layout_manager Argument converted to the Objective-C parameter of the same role.
     */
        void remove_layout_manager(const LayoutManager& a_layout_manager) const;
        /**
     * @brief Returns the `attributeRuns` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::vector<TextStorage> attribute_runs() const;
        /**
     * @brief Sets the `attributeRuns` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attribute_runs(const std::vector<TextStorage>& value) const;
        /**
     * @brief Returns the `changeInLength` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::int64_t change_in_length() const;
        /**
     * @brief Returns the `characters` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::vector<TextStorage> characters() const;
        /**
     * @brief Sets the `characters` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_characters(const std::vector<TextStorage>& value) const;
        /**
     * @brief Returns the `editedMask` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        TextStorageEditActions edited_mask() const;
        /**
     * @brief Returns the `editedRange` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        Range edited_range() const;
        /**
     * @brief Returns the `fixesAttributesLazily` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        bool fixes_attributes_lazily() const;
        /**
     * @brief Returns the `font` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        Font font() const;
        /**
     * @brief Sets the `font` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_font(const Font& value) const;
        /**
     * @brief Returns the `foregroundColor` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        Color foreground_color() const;
        /**
     * @brief Sets the `foregroundColor` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_foreground_color(const Color& value) const;
        /**
     * @brief Returns the `layoutManagers` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::vector<LayoutManager> layout_managers() const;
        /**
     * @brief Returns the `paragraphs` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::vector<TextStorage> paragraphs() const;
        /**
     * @brief Sets the `paragraphs` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paragraphs(const std::vector<TextStorage>& value) const;
        /**
     * @brief Returns the `textStorageObserver` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        Object text_storage_observer() const;
        /**
     * @brief Sets the `textStorageObserver` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_storage_observer(const Object& value) const;
        /**
     * @brief Returns the `words` property of `NSTextStorage`.
     * @return The converted Objective-C result.
     */
        std::vector<TextStorage> words() const;
        /**
     * @brief Sets the `words` property of `NSTextStorage`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_words(const std::vector<TextStorage>& value) const;
        /// @brief Signal for the delegate/data-source method behind `will_process_editing_range_change_in_length`; connect a callback with `will_process_editing_range_change_in_length().connect(...)`.
        Signal<TextStorage, void(TextStorageEditActions, Range, std::int64_t)> will_process_editing_range_change_in_length() const
        {
            return Signal<TextStorage, void(TextStorageEditActions, Range, std::int64_t)>(handle(), "will_process_editing_range_change_in_length");
        }
        /// @brief Signal for the delegate/data-source method behind `did_process_editing_range_change_in_length`; connect a callback with `did_process_editing_range_change_in_length().connect(...)`.
        Signal<TextStorage, void(TextStorageEditActions, Range, std::int64_t)> did_process_editing_range_change_in_length() const
        {
            return Signal<TextStorage, void(TextStorageEditActions, Range, std::int64_t)>(handle(), "did_process_editing_range_change_in_length");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
