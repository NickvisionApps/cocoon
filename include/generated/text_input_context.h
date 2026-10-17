#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Event;

    /**
     * @brief C++ handle for the Objective-C class `NSTextInputContext` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextInputContext text_input_context(nullptr);  // null handle; instances normally come from other API calls
     * text_input_context.set_accepts_glyph_info(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextInputContext text_input_context(nullptr);
     * text_input_context.set_accepts_glyph_info(true);
     * auto accepts_glyph_info = text_input_context.accepts_glyph_info();
     * text_input_context.set_allowed_input_source_locales({"a", "b"});
     * auto allowed_input_source_locales = text_input_context.allowed_input_source_locales();
     * text_input_context.set_selected_keyboard_input_source("text");
     * auto selected_keyboard_input_source = text_input_context.selected_keyboard_input_source();
     * text_input_context.activate();
     * text_input_context.deactivate();
     * text_input_context.discard_marked_text();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextinputcontext
     */
    class TextInputContext : public Object
    {
    public:
        /// @brief Creates a new `NSTextInputContext` instance and returns a handle to it.
        explicit TextInputContext(const Object& client);
        TextInputContext();
        /// @brief Creates a null handle that refers to no native object.
        TextInputContext(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextInputContext(Adopt adopt);
        /**
     * @brief Calls `-[NSTextInputContext activate]`.
     * @details Invoked when the receiver gets activated/deactivated.
     */
        void activate() const;
        /**
     * @brief Calls `-[NSTextInputContext deactivate]`.
     */
        void deactivate() const;
        /**
     * @brief Calls `-[NSTextInputContext discardMarkedText]`.
     * @details Notifies the system to discard the current conversion session. The client should clear its marked range when sending this message.
     */
        void discard_marked_text() const;
        /**
     * @brief Calls `-[NSTextInputContext handleEvent:]`.
     * @details Tells the Cocoa Text Input system to handle mouse/key events. Returns YES if the system consumed the event.
     * @param event Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool handle_event(const Event& event) const;
        /**
     * @brief Calls `-[NSTextInputContext invalidateCharacterCoordinates]`.
     * @details Notifies the text input system that information related to character positions, including the document's visual coordinates, text selection, and document contents, has been modified. Text engines implementing the NSTextInputClient protocol should send this message whenever any of these changes occur, and -[NSTextInputContext handleEvent:] will not otherwise be called. -handleEvent: serves as an implicit notification that any of these changes could have occurred.
     */
        void invalidate_character_coordinates() const;
        /**
     * @brief Calls `+[NSTextInputContext localizedNameForInputSource:]`.
     * @details Returns the display name for inputSourceIdentifier.
     * @param input_source_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_name_for_input_source(const std::string& input_source_identifier);
        /**
     * @brief Calls `-[NSTextInputContext textInputClientDidEndScrollingOrZooming]`.
     * @details Notifies the text input client was continuous updated due to user action. This includes scrolling, resizing, zooming, and any other action modifying the the geometry information of text selection while displaying the content. This method should be called after -invalidateCharacterCoordinates.
     */
        void text_input_client_did_end_scrolling_or_zooming() const;
        /**
     * @brief Calls `-[NSTextInputContext textInputClientDidScroll]`.
     */
        void text_input_client_did_scroll() const;
        /**
     * @brief Calls `-[NSTextInputContext textInputClientDidUpdateSelection]`.
     */
        void text_input_client_did_update_selection() const;
        /**
     * @brief Calls `-[NSTextInputContext textInputClientWillStartScrollingOrZooming]`.
     * @details Notifies the text input client will be continuous updated due to user action. This includes scrolling, resizing, zooming, and any other action modifying the the geometry information of text selection while displaying the content. This method should be called before -invalidateCharacterCoordinates.
     */
        void text_input_client_will_start_scrolling_or_zooming() const;
        /**
     * @brief Returns the `acceptsGlyphInfo` property of `NSTextInputContext`.
     * @details Indicates whether the client handles NSGlyphInfoAttributeName or not. The default value is determined by examining the return value sending -validAttributesForMarkedText to client at initialization.
     * @return The converted Objective-C result.
     */
        bool accepts_glyph_info() const;
        /**
     * @brief Sets the `acceptsGlyphInfo` property of `NSTextInputContext`.
     * @details Indicates whether the client handles NSGlyphInfoAttributeName or not. The default value is determined by examining the return value sending -validAttributesForMarkedText to client at initialization.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_accepts_glyph_info(bool value) const;
        /**
     * @brief Returns the `allowedInputSourceLocales` property of `NSTextInputContext`.
     * @details Specifies the set of keyboard input source locales allowed when this input context is active. NSAllRomanInputSourcesLocaleIdentifier can be specified as a valid locale.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> allowed_input_source_locales() const;
        /**
     * @brief Sets the `allowedInputSourceLocales` property of `NSTextInputContext`.
     * @details Specifies the set of keyboard input source locales allowed when this input context is active. NSAllRomanInputSourcesLocaleIdentifier can be specified as a valid locale.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_input_source_locales(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `currentInputContext` property of `NSTextInputContext`.
     * @details The current activated text input context object. The Cocoa Text Input system communicates primarily with the client of the activated input context via the NSTextInputClient protocol.
     * @return The converted Objective-C result.
     */
        static TextInputContext current_input_context();
        /**
     * @brief Returns the `keyboardInputSources` property of `NSTextInputContext`.
     * @details The array of keyboard text input source identifier strings available to the receiver.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> keyboard_input_sources() const;
        /**
     * @brief Returns the `selectedKeyboardInputSource` property of `NSTextInputContext`.
     * @details The identifier string for the selected keyboard text input source.
     * @return The converted Objective-C result.
     */
        std::string selected_keyboard_input_source() const;
        /**
     * @brief Sets the `selectedKeyboardInputSource` property of `NSTextInputContext`.
     * @details The identifier string for the selected keyboard text input source.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selected_keyboard_input_source(const std::string& value) const;
    };
}
