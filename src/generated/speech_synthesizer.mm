#include "generated/speech_synthesizer.h"
#include "internal.h"

@interface AKSpeechSynthesizerDelegate : NSObject <NSSpeechSynthesizerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSpeechSynthesizerDelegate

- (void)speechSynthesizer:(NSSpeechSynthesizer*)sender didEncounterErrorAtIndex:(NSUInteger)characterIndex ofString:(NSString*)string message:(NSString*)message
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpeechSynthesizer, void(std::uint64_t, std::string, std::string)>::emit((__bridge void*)strongHost, "did_encounter_error_at_index_of_string_message", static_cast<std::uint64_t>(characterIndex), cocoon::internal::from(string), cocoon::internal::from(message));
}

- (void)speechSynthesizer:(NSSpeechSynthesizer*)sender didEncounterSyncMessage:(NSString*)message
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpeechSynthesizer, void(std::string)>::emit((__bridge void*)strongHost, "did_encounter_sync_message", cocoon::internal::from(message));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(speechSynthesizer:didEncounterErrorAtIndex:ofString:message:))
    {
        return strongHost && cocoon::Signal<cocoon::SpeechSynthesizer, void(std::uint64_t, std::string, std::string)>::connected((__bridge void*)strongHost, "did_encounter_error_at_index_of_string_message");
    }
    if (selector == @selector(speechSynthesizer:didEncounterSyncMessage:))
    {
        return strongHost && cocoon::Signal<cocoon::SpeechSynthesizer, void(std::string)>::connected((__bridge void*)strongHost, "did_encounter_sync_message");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SpeechSynthesizer::SpeechSynthesizer() : SpeechSynthesizer(Adopt{cocoon::internal::retain([[::NSSpeechSynthesizer alloc] init])})
    {
        SpeechSynthesizer::install_delegate_delegate_(handle());
    }

    SpeechSynthesizer::SpeechSynthesizer(std::nullptr_t) : Object(nullptr)
    {
    }

    SpeechSynthesizer::SpeechSynthesizer(Adopt adopt) : Object(adopt)
    {
    }

    void SpeechSynthesizer::add_speech_dictionary(const std::map<std::string, Object>& speech_dictionary) const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) addSpeechDictionary:cocoon::internal::to_dictionary(speech_dictionary, [](const std::string& k) -> id
                                                                                                               {
                                                                                                                   return cocoon::internal::to(k);
                                                                                                               },
                                                                                                               [](const Object& v) -> id
                                                                                                               {
                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                               })];
    }

    void SpeechSynthesizer::continue_speaking() const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) continueSpeaking];
    }

    Object SpeechSynthesizer::object_for_property(const std::string& property) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSSpeechSynthesizer>(this) objectForProperty:cocoon::internal::to(property) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    void SpeechSynthesizer::pause_speaking_at_boundary(SpeechBoundary boundary) const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) pauseSpeakingAtBoundary:static_cast<::NSSpeechBoundary>(boundary)];
    }

    std::string SpeechSynthesizer::phonemes_from_text(const std::string& text) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpeechSynthesizer>(this) phonemesFromText:cocoon::internal::to(text)]);
    }

    bool SpeechSynthesizer::set_object(const Object& object, const std::string& property) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSSpeechSynthesizer>(this) setObject:cocoon::internal::native_id(object) forProperty:cocoon::internal::to(property) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    void SpeechSynthesizer::stop_speaking_at_boundary(SpeechBoundary boundary) const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) stopSpeakingAtBoundary:static_cast<::NSSpeechBoundary>(boundary)];
    }

    float SpeechSynthesizer::rate() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSSpeechSynthesizer>(this) rate]);
    }

    void SpeechSynthesizer::set_rate(float value) const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) setRate:static_cast<float>(value)];
    }

    float SpeechSynthesizer::volume() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSSpeechSynthesizer>(this) volume]);
    }

    void SpeechSynthesizer::set_volume(float value) const
    {
        [cocoon::internal::ns<::NSSpeechSynthesizer>(this) setVolume:static_cast<float>(value)];
    }

    void SpeechSynthesizer::install_delegate_delegate_(void* native)
    {
        ::NSSpeechSynthesizer* host = (__bridge ::NSSpeechSynthesizer*)native;
        AKSpeechSynthesizerDelegate* delegate = [[AKSpeechSynthesizerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSpeechSynthesizer* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSpeechSynthesizer* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
