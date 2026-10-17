#include "generated/sound.h"
#include "internal.h"

@interface AKSoundDelegate : NSObject <NSSoundDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSoundDelegate

- (void)sound:(NSSound*)sound didFinishPlaying:(BOOL)flag
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::Sound, void(bool)>::emit((__bridge void*)strongHost, "did_finish_playing", static_cast<bool>(flag));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(sound:didFinishPlaying:))
    {
        return strongHost && cocoon::Signal<cocoon::Sound, void(bool)>::connected((__bridge void*)strongHost, "did_finish_playing");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Sound::Sound(const std::string& path, bool by_ref) : Sound(Adopt{cocoon::internal::retain([[::NSSound alloc] initWithContentsOfFile:cocoon::internal::to(path) byReference:static_cast<::BOOL>(by_ref)])})
    {
        Sound::install_delegate_delegate_(handle());
    }

    Sound::Sound(const URL& url, bool by_ref) : Sound(Adopt{cocoon::internal::retain([[::NSSound alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url) byReference:static_cast<::BOOL>(by_ref)])})
    {
        Sound::install_delegate_delegate_(handle());
    }

    Sound::Sound(const std::vector<std::uint8_t>& data) : Sound(Adopt{cocoon::internal::retain([[::NSSound alloc] initWithData:cocoon::internal::to_data(data)])})
    {
        Sound::install_delegate_delegate_(handle());
    }

    Sound::Sound(const Pasteboard& pasteboard) : Sound(Adopt{cocoon::internal::retain([[::NSSound alloc] initWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)])})
    {
        Sound::install_delegate_delegate_(handle());
    }

    Sound::Sound() : Sound(Adopt{cocoon::internal::retain([[::NSSound alloc] init])})
    {
        Sound::install_delegate_delegate_(handle());
    }

    Sound::Sound(std::nullptr_t) : Object(nullptr)
    {
    }

    Sound::Sound(Adopt adopt) : Object(adopt)
    {
    }

    bool Sound::can_init_with_pasteboard(const Pasteboard& pasteboard)
    {
        return static_cast<bool>([::NSSound canInitWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)]);
    }

    bool Sound::pause() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) pause]);
    }

    bool Sound::play() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) play]);
    }

    bool Sound::resume() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) resume]);
    }

    bool Sound::set_name(const std::string& string) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) setName:cocoon::internal::to(string)]);
    }

    Sound Sound::sound_named(const std::string& name)
    {
        return cocoon::internal::wrap<Sound>([::NSSound soundNamed:cocoon::internal::to(name)]);
    }

    bool Sound::stop() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) stop]);
    }

    void Sound::write_to_pasteboard(const Pasteboard& pasteboard) const
    {
        [cocoon::internal::ns<::NSSound>(this) writeToPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)];
    }

    double Sound::current_time() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSound>(this) currentTime]);
    }

    void Sound::set_current_time(double value) const
    {
        [cocoon::internal::ns<::NSSound>(this) setCurrentTime:static_cast<::NSTimeInterval>(value)];
    }

    double Sound::duration() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSSound>(this) duration]);
    }

    bool Sound::loops() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) loops]);
    }

    void Sound::set_loops(bool value) const
    {
        [cocoon::internal::ns<::NSSound>(this) setLoops:static_cast<::BOOL>(value)];
    }

    std::string Sound::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSound>(this) name]);
    }

    std::string Sound::playback_device_identifier() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSound>(this) playbackDeviceIdentifier]);
    }

    void Sound::set_playback_device_identifier(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSound>(this) setPlaybackDeviceIdentifier:cocoon::internal::to(value)];
    }

    bool Sound::is_playing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSound>(this) isPlaying]);
    }

    std::vector<std::string> Sound::sound_unfiltered_types()
    {
        return cocoon::internal::from_array<std::string>([::NSSound soundUnfilteredTypes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    float Sound::volume() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSSound>(this) volume]);
    }

    void Sound::set_volume(float value) const
    {
        [cocoon::internal::ns<::NSSound>(this) setVolume:static_cast<float>(value)];
    }

    void Sound::install_delegate_delegate_(void* native)
    {
        ::NSSound* host = (__bridge ::NSSound*)native;
        AKSoundDelegate* delegate = [[AKSoundDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSound* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSound* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
