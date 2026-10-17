#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text_field.h"
#include "types.h"

namespace cocoon
{
    class CharacterSet;
    class Menu;
    class Notification;
    class Pasteboard;
    class Text;
    class TextCheckingResult;
    class TextView;

    /**
     * @brief C++ handle for the Objective-C class `NSTokenField` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref TextField.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TokenField token_field;
     * token_field.set_completion_delay(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TokenField token_field{};
     * token_field.set_completion_delay(1);
     * auto completion_delay = token_field.completion_delay();
     * token_field.set_token_style(cocoon::TokenStyle::Default);
     * auto token_style = token_field.token_style();
     * token_field.set_tokenizing_character_set(cocoon::CharacterSet());
     * auto tokenizing_character_set = token_field.tokenizing_character_set();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstokenfield
     */
    class TokenField : public TextField
    {
    public:
        /// @brief Creates a new `NSTokenField` instance and returns a handle to it.
        explicit TokenField();
        /// @brief Creates a null handle that refers to no native object.
        TokenField(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TokenField(Adopt adopt);
        /**
     * @brief Returns the `completionDelay` property of `NSTokenField`.
     * @return The converted Objective-C result.
     */
        double completion_delay() const;
        /**
     * @brief Sets the `completionDelay` property of `NSTokenField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completion_delay(double value) const;
        /**
     * @brief Returns the `defaultCompletionDelay` property of `NSTokenField`.
     * @return The converted Objective-C result.
     */
        static double default_completion_delay();
        /**
     * @brief Returns the `defaultTokenizingCharacterSet` property of `NSTokenField`.
     * @return The converted Objective-C result.
     */
        static CharacterSet default_tokenizing_character_set();
        /**
     * @brief Returns the `tokenStyle` property of `NSTokenField`.
     * @details Sets the default token style used for each new token. However, if the delegate implements tokenField:styleForRepresentedObject:, that return value will be used instead.
     * @return The converted Objective-C result.
     */
        TokenStyle token_style() const;
        /**
     * @brief Sets the `tokenStyle` property of `NSTokenField`.
     * @details Sets the default token style used for each new token. However, if the delegate implements tokenField:styleForRepresentedObject:, that return value will be used instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_token_style(TokenStyle value) const;
        /**
     * @brief Returns the `tokenizingCharacterSet` property of `NSTokenField`.
     * @return The converted Objective-C result.
     */
        CharacterSet tokenizing_character_set() const;
        /**
     * @brief Sets the `tokenizingCharacterSet` property of `NSTokenField`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tokenizing_character_set(const CharacterSet& value) const;
        /// @brief Signal for the delegate/data-source method behind `completions_for_substring_index_of_token_index_of_selected_item`; connect a callback with `completions_for_substring_index_of_token_index_of_selected_item().connect(...)`.
        Signal<TokenField, std::vector<Object>(std::string, std::int64_t, std::int64_t*)> completions_for_substring_index_of_token_index_of_selected_item() const
        {
            return Signal<TokenField, std::vector<Object>(std::string, std::int64_t, std::int64_t*)>(handle(), "completions_for_substring_index_of_token_index_of_selected_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_add_objects_at_index`; connect a callback with `should_add_objects_at_index().connect(...)`.
        Signal<TokenField, std::vector<Object>(std::vector<Object>, std::uint64_t)> should_add_objects_at_index() const
        {
            return Signal<TokenField, std::vector<Object>(std::vector<Object>, std::uint64_t)>(handle(), "should_add_objects_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `display_string_for_represented_object`; connect a callback with `display_string_for_represented_object().connect(...)`.
        Signal<TokenField, std::string(Object)> display_string_for_represented_object() const
        {
            return Signal<TokenField, std::string(Object)>(handle(), "display_string_for_represented_object");
        }
        /// @brief Signal for the delegate/data-source method behind `editing_string_for_represented_object`; connect a callback with `editing_string_for_represented_object().connect(...)`.
        Signal<TokenField, std::string(Object)> editing_string_for_represented_object() const
        {
            return Signal<TokenField, std::string(Object)>(handle(), "editing_string_for_represented_object");
        }
        /// @brief Signal for the delegate/data-source method behind `represented_object_for_editing_string`; connect a callback with `represented_object_for_editing_string().connect(...)`.
        Signal<TokenField, Object(std::string)> represented_object_for_editing_string() const
        {
            return Signal<TokenField, Object(std::string)>(handle(), "represented_object_for_editing_string");
        }
        /// @brief Signal for the delegate/data-source method behind `write_represented_objects_to_pasteboard`; connect a callback with `write_represented_objects_to_pasteboard().connect(...)`.
        Signal<TokenField, bool(std::vector<Object>, Pasteboard)> write_represented_objects_to_pasteboard() const
        {
            return Signal<TokenField, bool(std::vector<Object>, Pasteboard)>(handle(), "write_represented_objects_to_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `read_from_pasteboard`; connect a callback with `read_from_pasteboard().connect(...)`.
        Signal<TokenField, std::vector<Object>(Pasteboard)> read_from_pasteboard() const
        {
            return Signal<TokenField, std::vector<Object>(Pasteboard)>(handle(), "read_from_pasteboard");
        }
        /// @brief Signal for the delegate/data-source method behind `menu_for_represented_object`; connect a callback with `menu_for_represented_object().connect(...)`.
        Signal<TokenField, Menu(Object)> menu_for_represented_object() const
        {
            return Signal<TokenField, Menu(Object)>(handle(), "menu_for_represented_object");
        }
        /// @brief Signal for the delegate/data-source method behind `has_menu_for_represented_object`; connect a callback with `has_menu_for_represented_object().connect(...)`.
        Signal<TokenField, bool(Object)> has_menu_for_represented_object() const
        {
            return Signal<TokenField, bool(Object)>(handle(), "has_menu_for_represented_object");
        }
        /// @brief Signal for the delegate/data-source method behind `style_for_represented_object`; connect a callback with `style_for_represented_object().connect(...)`.
        Signal<TokenField, TokenStyle(Object)> style_for_represented_object() const
        {
            return Signal<TokenField, TokenStyle(Object)>(handle(), "style_for_represented_object");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
