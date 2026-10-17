#include "generated/speech_recognizer.h"
#include "internal.h"

@interface AKSpeechRecognizerDelegate : NSObject <NSSpeechRecognizerDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKSpeechRecognizerDelegate

- (void)speechRecognizer:(NSSpeechRecognizer*)sender didRecognizeCommand:(NSString*)command
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::SpeechRecognizer, void(std::string)>::emit((__bridge void*)strongHost, "did_recognize_command", cocoon::internal::from(command));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(speechRecognizer:didRecognizeCommand:))
    {
        return strongHost && cocoon::Signal<cocoon::SpeechRecognizer, void(std::string)>::connected((__bridge void*)strongHost, "did_recognize_command");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    SpeechRecognizer::SpeechRecognizer() : SpeechRecognizer(Adopt{cocoon::internal::retain([[::NSSpeechRecognizer alloc] init])})
    {
        SpeechRecognizer::install_delegate_delegate_(handle());
    }

    SpeechRecognizer::SpeechRecognizer(std::nullptr_t) : Object(nullptr)
    {
    }

    SpeechRecognizer::SpeechRecognizer(Adopt adopt) : Object(adopt)
    {
    }

    void SpeechRecognizer::start_listening() const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) startListening];
    }

    void SpeechRecognizer::stop_listening() const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) stopListening];
    }

    bool SpeechRecognizer::blocks_other_recognizers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpeechRecognizer>(this) blocksOtherRecognizers]);
    }

    void SpeechRecognizer::set_blocks_other_recognizers(bool value) const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) setBlocksOtherRecognizers:static_cast<::BOOL>(value)];
    }

    std::vector<std::string> SpeechRecognizer::commands() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSSpeechRecognizer>(this) commands], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    void SpeechRecognizer::set_commands(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) setCommands:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(e);
                                                                                                 })];
    }

    std::string SpeechRecognizer::displayed_commands_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSpeechRecognizer>(this) displayedCommandsTitle]);
    }

    void SpeechRecognizer::set_displayed_commands_title(const std::string& value) const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) setDisplayedCommandsTitle:cocoon::internal::to(value)];
    }

    bool SpeechRecognizer::listens_in_foreground_only() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSpeechRecognizer>(this) listensInForegroundOnly]);
    }

    void SpeechRecognizer::set_listens_in_foreground_only(bool value) const
    {
        [cocoon::internal::ns<::NSSpeechRecognizer>(this) setListensInForegroundOnly:static_cast<::BOOL>(value)];
    }

    void SpeechRecognizer::install_delegate_delegate_(void* native)
    {
        ::NSSpeechRecognizer* host = (__bridge ::NSSpeechRecognizer*)native;
        AKSpeechRecognizerDelegate* delegate = [[AKSpeechRecognizerDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSSpeechRecognizer* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSSpeechRecognizer* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
