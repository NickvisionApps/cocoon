#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSSpeechSynthesizer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SpeechSynthesizer speech_synthesizer;
     * speech_synthesizer.set_rate(1);
     * speech_synthesizer.did_encounter_error_at_index_of_string_message().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SpeechSynthesizer speech_synthesizer{};
     * speech_synthesizer.set_rate(1);
     * auto rate = speech_synthesizer.rate();
     * speech_synthesizer.set_volume(1);
     * auto volume = speech_synthesizer.volume();
     * speech_synthesizer.continue_speaking();
     * speech_synthesizer.object_for_property("text");
     * speech_synthesizer.pause_speaking_at_boundary(cocoon::SpeechBoundary::ImmediateBoundary);
     * speech_synthesizer.did_encounter_error_at_index_of_string_message().connect([](std::uint64_t a0, std::string a1, std::string a2) {});
     * speech_synthesizer.did_encounter_sync_message().connect([](std::string a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsspeechsynthesizer
     */
    class SpeechSynthesizer : public Object
    {
    public:
        /// @brief Creates a new `NSSpeechSynthesizer` instance and returns a handle to it.
        explicit SpeechSynthesizer();
        /// @brief Creates a null handle that refers to no native object.
        SpeechSynthesizer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SpeechSynthesizer(Adopt adopt);
        /**
     * @brief Calls `-[NSSpeechSynthesizer addSpeechDictionary:]`.
     * @param speech_dictionary Argument converted to the Objective-C parameter of the same role.
     */
        void add_speech_dictionary(const std::map<std::string, Object>& speech_dictionary) const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer continueSpeaking]`.
     */
        void continue_speaking() const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer objectForProperty:error:]`.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_for_property(const std::string& property) const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer pauseSpeakingAtBoundary:]`.
     * @param boundary Argument converted to the Objective-C parameter of the same role.
     */
        void pause_speaking_at_boundary(SpeechBoundary boundary) const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer phonemesFromText:]`.
     * @param text Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string phonemes_from_text(const std::string& text) const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer setObject:forProperty:error:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_object(const Object& object, const std::string& property) const;
        /**
     * @brief Calls `-[NSSpeechSynthesizer stopSpeakingAtBoundary:]`.
     * @param boundary Argument converted to the Objective-C parameter of the same role.
     */
        void stop_speaking_at_boundary(SpeechBoundary boundary) const;
        /**
     * @brief Returns the `rate` property of `NSSpeechSynthesizer`.
     * @return The converted Objective-C result.
     */
        float rate() const;
        /**
     * @brief Sets the `rate` property of `NSSpeechSynthesizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rate(float value) const;
        /**
     * @brief Returns the `volume` property of `NSSpeechSynthesizer`.
     * @return The converted Objective-C result.
     */
        float volume() const;
        /**
     * @brief Sets the `volume` property of `NSSpeechSynthesizer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_volume(float value) const;
        /// @brief Signal for the delegate/data-source method behind `did_encounter_error_at_index_of_string_message`; connect a callback with `did_encounter_error_at_index_of_string_message().connect(...)`.
        Signal<SpeechSynthesizer, void(std::uint64_t, std::string, std::string)> did_encounter_error_at_index_of_string_message() const
        {
            return Signal<SpeechSynthesizer, void(std::uint64_t, std::string, std::string)>(handle(), "did_encounter_error_at_index_of_string_message");
        }
        /// @brief Signal for the delegate/data-source method behind `did_encounter_sync_message`; connect a callback with `did_encounter_sync_message().connect(...)`.
        Signal<SpeechSynthesizer, void(std::string)> did_encounter_sync_message() const
        {
            return Signal<SpeechSynthesizer, void(std::string)>(handle(), "did_encounter_sync_message");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
