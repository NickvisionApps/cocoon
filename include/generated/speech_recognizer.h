#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSpeechRecognizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SpeechRecognizer speech_recognizer;
     * speech_recognizer.set_blocks_other_recognizers(true);
     * speech_recognizer.did_recognize_command().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SpeechRecognizer speech_recognizer{};
     * speech_recognizer.set_blocks_other_recognizers(true);
     * auto blocks_other_recognizers = speech_recognizer.blocks_other_recognizers();
     * speech_recognizer.set_commands({"a", "b"});
     * auto commands = speech_recognizer.commands();
     * speech_recognizer.set_displayed_commands_title("text");
     * auto displayed_commands_title = speech_recognizer.displayed_commands_title();
     * speech_recognizer.start_listening();
     * speech_recognizer.stop_listening();
     * speech_recognizer.did_recognize_command().connect([](std::string a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsspeechrecognizer
     */
    class SpeechRecognizer : public Object
    {
    public:
        /// @brief Creates a new `NSSpeechRecognizer` instance and returns a handle to it.
        explicit SpeechRecognizer();
        /// @brief Creates a null handle that refers to no native object.
        SpeechRecognizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SpeechRecognizer(Adopt adopt);
        /**
     * @brief Calls `-[NSSpeechRecognizer startListening]`.
     */
        void start_listening() const;
        /**
     * @brief Calls `-[NSSpeechRecognizer stopListening]`.
     */
        void stop_listening() const;
        /**
     * @brief Returns the `blocksOtherRecognizers` property of `NSSpeechRecognizer`.
     * @return The converted Objective-C result.
     */
        bool blocks_other_recognizers() const;
        /**
     * @brief Sets the `blocksOtherRecognizers` property of `NSSpeechRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_blocks_other_recognizers(bool value) const;
        /**
     * @brief Returns the `commands` property of `NSSpeechRecognizer`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> commands() const;
        /**
     * @brief Sets the `commands` property of `NSSpeechRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_commands(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `displayedCommandsTitle` property of `NSSpeechRecognizer`.
     * @return The converted Objective-C result.
     */
        std::string displayed_commands_title() const;
        /**
     * @brief Sets the `displayedCommandsTitle` property of `NSSpeechRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_displayed_commands_title(const std::string& value) const;
        /**
     * @brief Returns the `listensInForegroundOnly` property of `NSSpeechRecognizer`.
     * @return The converted Objective-C result.
     */
        bool listens_in_foreground_only() const;
        /**
     * @brief Sets the `listensInForegroundOnly` property of `NSSpeechRecognizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_listens_in_foreground_only(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `did_recognize_command`; connect a callback with `did_recognize_command().connect(...)`.
        Signal<SpeechRecognizer, void(std::string)> did_recognize_command() const
        {
            return Signal<SpeechRecognizer, void(std::string)>(handle(), "did_recognize_command");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
