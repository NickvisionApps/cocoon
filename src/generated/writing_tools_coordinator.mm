#include "generated/writing_tools_coordinator.h"
#include "internal.h"

namespace cocoon
{
    WritingToolsCoordinator::WritingToolsCoordinator(const Object& delegate) : WritingToolsCoordinator(Adopt{cocoon::internal::retain([[::NSWritingToolsCoordinator alloc] initWithDelegate:cocoon::internal::native_id(delegate)])})
    {
    }

    WritingToolsCoordinator::WritingToolsCoordinator() : WritingToolsCoordinator(Adopt{cocoon::internal::retain([[::NSWritingToolsCoordinator alloc] init])})
    {
    }

    WritingToolsCoordinator::WritingToolsCoordinator(std::nullptr_t) : Object(nullptr)
    {
    }

    WritingToolsCoordinator::WritingToolsCoordinator(Adopt adopt) : Object(adopt)
    {
    }

    void WritingToolsCoordinator::cancel_text_animations_with_identifiers(const std::vector<UUID>& identifiers) const
    {
        if (@available(macOS 27.0, *))
        {
            [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) cancelTextAnimationsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const UUID& e) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native<::NSUUID>(e);
                                                                                                        })];
        }
    }

    bool WritingToolsCoordinator::show_grammar_presentation_for_range(const Range& range, const WritingToolsCoordinatorContext& context) const
    {
        if (@available(macOS 27.0, *))
        {
            return static_cast<bool>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) showGrammarPresentationForRange:cocoon::internal::to(range) inContext:cocoon::internal::native<::NSWritingToolsCoordinatorContext>(context)]);
        }
        return {};
    }

    UUID WritingToolsCoordinator::start_text_animation(WritingToolsCoordinatorTextAnimation text_animation, const Range& range, const WritingToolsCoordinatorContext& context, WritingDirection writing_direction) const
    {
        if (@available(macOS 27.0, *))
        {
            return cocoon::internal::wrap<UUID>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) startTextAnimation:static_cast<::NSWritingToolsCoordinatorTextAnimation>(text_animation) forRange:cocoon::internal::to(range) inContext:cocoon::internal::native<::NSWritingToolsCoordinatorContext>(context) writingDirection:static_cast<::NSWritingDirection>(writing_direction)]);
        }
        return UUID(nullptr);
    }

    void WritingToolsCoordinator::stop_writing_tools() const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) stopWritingTools];
    }

    void WritingToolsCoordinator::update_for_reflowed_text_in_context_with_identifier(const UUID& context_id) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) updateForReflowedTextInContextWithIdentifier:cocoon::internal::native<::NSUUID>(context_id)];
    }

    void WritingToolsCoordinator::update_range(const Range& range, const AttributedString& replacement_text, WritingToolsCoordinatorTextUpdateReason reason, const UUID& context_id) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) updateRange:cocoon::internal::to(range) withText:cocoon::internal::native<::NSAttributedString>(replacement_text) reason:static_cast<::NSWritingToolsCoordinatorTextUpdateReason>(reason) forContextWithIdentifier:cocoon::internal::native<::NSUUID>(context_id)];
    }

    WritingToolsBehavior WritingToolsCoordinator::behavior() const
    {
        return static_cast<WritingToolsBehavior>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) behavior]);
    }

    View WritingToolsCoordinator::decoration_container_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) decorationContainerView]);
    }

    void WritingToolsCoordinator::set_decoration_container_view(const View& value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) setDecorationContainerView:cocoon::internal::native<::NSView>(value)];
    }

    View WritingToolsCoordinator::effect_container_view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) effectContainerView]);
    }

    void WritingToolsCoordinator::set_effect_container_view(const View& value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) setEffectContainerView:cocoon::internal::native<::NSView>(value)];
    }

    bool WritingToolsCoordinator::includes_text_list_markers() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) includesTextListMarkers]);
    }

    void WritingToolsCoordinator::set_includes_text_list_markers(bool value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) setIncludesTextListMarkers:static_cast<::BOOL>(value)];
    }

    bool WritingToolsCoordinator::is_writing_tools_available()
    {
        return static_cast<bool>([::NSWritingToolsCoordinator isWritingToolsAvailable]);
    }

    WritingToolsBehavior WritingToolsCoordinator::preferred_behavior() const
    {
        return static_cast<WritingToolsBehavior>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) preferredBehavior]);
    }

    void WritingToolsCoordinator::set_preferred_behavior(WritingToolsBehavior value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) setPreferredBehavior:static_cast<::NSWritingToolsBehavior>(value)];
    }

    WritingToolsResultOptions WritingToolsCoordinator::preferred_result_options() const
    {
        return static_cast<WritingToolsResultOptions>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) preferredResultOptions]);
    }

    void WritingToolsCoordinator::set_preferred_result_options(WritingToolsResultOptions value) const
    {
        [cocoon::internal::ns<::NSWritingToolsCoordinator>(this) setPreferredResultOptions:static_cast<::NSWritingToolsResultOptions>(value)];
    }

    WritingToolsResultOptions WritingToolsCoordinator::result_options() const
    {
        return static_cast<WritingToolsResultOptions>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) resultOptions]);
    }

    WritingToolsCoordinatorState WritingToolsCoordinator::state() const
    {
        return static_cast<WritingToolsCoordinatorState>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) state]);
    }

    View WritingToolsCoordinator::view() const
    {
        return cocoon::internal::wrap<View>([cocoon::internal::ns<::NSWritingToolsCoordinator>(this) view]);
    }
}
