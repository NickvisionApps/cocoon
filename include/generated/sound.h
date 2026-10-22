#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Pasteboard;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSSound` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Sound sound;
     * sound.set_current_time(1);
     * sound.did_finish_playing().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Sound sound{};
     * sound.set_current_time(1);
     * auto current_time = sound.current_time();
     * sound.set_loops(true);
     * auto loops = sound.loops();
     * sound.set_playback_device_identifier("text");
     * auto playback_device_identifier = sound.playback_device_identifier();
     * auto made_0 = cocoon::Sound::sound_named("text");
     * sound.pause();
     * sound.play();
     * sound.resume();
     * sound.did_finish_playing().connect([](bool a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssound
     */
    class Sound : public Object
    {
    public:
        /// @brief Creates a new `NSSound` instance and returns a handle to it.
        explicit Sound(const std::string& path, bool by_ref);
        /// @brief Creates a new `NSSound` instance and returns a handle to it.
        explicit Sound(const URL& url, bool by_ref);
        /// @brief Creates a new `NSSound` instance and returns a handle to it.
        explicit Sound(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSSound` instance and returns a handle to it.
        explicit Sound(const Pasteboard& pasteboard);
        /// @brief Creates a new `NSSound` instance and returns a handle to it.
        explicit Sound();
        /// @brief Creates a null handle that refers to no native object.
        Sound(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Sound(Adopt adopt);
        /**
         * @brief Calls `+[NSSound canInitWithPasteboard:]`.
         * @param pasteboard Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool can_init_with_pasteboard(const Pasteboard& pasteboard);
        /**
         * @brief Calls `-[NSSound pause]`.
         * @details - (BOOL)play; / sound is played asynchronously
         * @return The converted Objective-C result.
         */
        bool pause() const;
        /**
         * @brief Calls `-[NSSound play]`.
         * @return The converted Objective-C result.
         */
        bool play() const;
        /**
         * @brief Calls `-[NSSound resume]`.
         * @details - (BOOL)pause; / returns NO if sound not paused
         * @return The converted Objective-C result.
         */
        bool resume() const;
        /**
         * @brief Calls `-[NSSound setName:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_name(const std::string& string) const;
        /**
         * @brief Calls `+[NSSound soundNamed:]`.
         * @details If this finds & creates the sound, only name is saved when archived.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Sound sound_named(const std::string& name);
        /**
         * @brief Calls `-[NSSound stop]`.
         * @details - (BOOL)resume; / returns NO if sound not resumed
         * @return The converted Objective-C result.
         */
        bool stop() const;
        /**
         * @brief Calls `-[NSSound writeToPasteboard:]`.
         * @param pasteboard Argument converted to the Objective-C parameter of the same role.
         */
        void write_to_pasteboard(const Pasteboard& pasteboard) const;
        /**
         * @brief Returns the `currentTime` property of `NSSound`.
         * @details Getter: If the sound is playing, currentTime returns the number of seconds into the sound where playing is occurring. If the sound is not playing, currentTime returns the number of seconds into the sound where playing would start. Setter: Sets the location of the currently playing audio to seconds. If the sound is not playing, this sets the number of seconds into the sound where playing would begin. The currentTime is not archived, copied, or stored on the pasteboard - all new sounds start with a currentTime of 0.
         * @return The converted Objective-C result.
         */
        double current_time() const;
        /**
         * @brief Sets the `currentTime` property of `NSSound`.
         * @details Getter: If the sound is playing, currentTime returns the number of seconds into the sound where playing is occurring. If the sound is not playing, currentTime returns the number of seconds into the sound where playing would start. Setter: Sets the location of the currently playing audio to seconds. If the sound is not playing, this sets the number of seconds into the sound where playing would begin. The currentTime is not archived, copied, or stored on the pasteboard - all new sounds start with a currentTime of 0.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_current_time(double value) const;
        /**
         * @brief Returns the `duration` property of `NSSound`.
         * @details Returns the duration of the sound in seconds.
         * @return The converted Objective-C result.
         */
        double duration() const;
        /**
         * @brief Returns the `loops` property of `NSSound`.
         * @details Setter: Sets whether the sound should automatically restart when it is finished playing. If the sound is currently playing, this takes effect immediately. The default is NO. A looping sound does not send sound:didFinishPlaying: to its delegate unless it is sent a stop message. Getter: Returns whether the sound will automatically restart when it is finished playing.
         * @return The converted Objective-C result.
         */
        bool loops() const;
        /**
         * @brief Sets the `loops` property of `NSSound`.
         * @details Setter: Sets whether the sound should automatically restart when it is finished playing. If the sound is currently playing, this takes effect immediately. The default is NO. A looping sound does not send sound:didFinishPlaying: to its delegate unless it is sent a stop message. Getter: Returns whether the sound will automatically restart when it is finished playing.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_loops(bool value) const;
        /**
         * @brief Returns the `name` property of `NSSound`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Returns the `playbackDeviceIdentifier` property of `NSSound`.
         * @details Setter: Set the UID of the audio device where playback will occur. Pass nil to play on the default output device. Getter: Get the UID of the audio device where playback will occur. Returns nil if playback tracks the default device, which is the default.
         * @return The converted Objective-C result.
         */
        std::string playback_device_identifier() const;
        /**
         * @brief Sets the `playbackDeviceIdentifier` property of `NSSound`.
         * @details Setter: Set the UID of the audio device where playback will occur. Pass nil to play on the default output device. Getter: Get the UID of the audio device where playback will occur. Returns nil if playback tracks the default device, which is the default.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_playback_device_identifier(const std::string& value) const;
        /**
         * @brief Returns the `playing` property of `NSSound`.
         * @return The converted Objective-C result.
         */
        bool is_playing() const;
        /**
         * @brief Returns the `soundUnfilteredTypes` property of `NSSound`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> sound_unfiltered_types();
        /**
         * @brief Returns the `volume` property of `NSSound`.
         * @details Sets and gets the volume for the sound without affecting the system-wide volume. The valid range is between 0. and 1., inclusive.
         * @return The converted Objective-C result.
         */
        float volume() const;
        /**
         * @brief Sets the `volume` property of `NSSound`.
         * @details Sets and gets the volume for the sound without affecting the system-wide volume. The valid range is between 0. and 1., inclusive.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_volume(float value) const;
        /// @brief Signal for the delegate/data-source method behind `did_finish_playing`; connect a callback with `did_finish_playing().connect(...)`.
        Signal<Sound, void(bool)> did_finish_playing() const
        {
            return Signal<Sound, void(bool)>(handle(), "did_finish_playing");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
