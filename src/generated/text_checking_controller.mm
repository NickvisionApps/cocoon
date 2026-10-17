#include "generated/text_checking_controller.h"
#include "internal.h"

namespace cocoon
{
    TextCheckingController::TextCheckingController(const Object& client) : TextCheckingController(Adopt{cocoon::internal::retain([[::NSTextCheckingController alloc] initWithClient:cocoon::internal::native_id(client)])})
    {
    }

    TextCheckingController::TextCheckingController() : Object(nullptr)
    {
    }

    TextCheckingController::TextCheckingController(std::nullptr_t) : Object(nullptr)
    {
    }

    TextCheckingController::TextCheckingController(Adopt adopt) : Object(adopt)
    {
    }

    void TextCheckingController::change_spelling(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) changeSpelling:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::check_spelling(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) checkSpelling:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::check_text_in_document(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) checkTextInDocument:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::check_text_in_range(const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) checkTextInRange:cocoon::internal::to(range)
                                                             types:static_cast<::NSTextCheckingTypes>(checking_types)
                                                           options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })];
    }

    void TextCheckingController::check_text_in_selection(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) checkTextInSelection:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::consider_text_checking_for_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) considerTextCheckingForRange:cocoon::internal::to(range)];
    }

    void TextCheckingController::did_change_selected_range() const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) didChangeSelectedRange];
    }

    void TextCheckingController::did_change_text_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) didChangeTextInRange:cocoon::internal::to(range)];
    }

    void TextCheckingController::ignore_spelling(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) ignoreSpelling:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::inserted_text_in_range(const Range& range) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) insertedTextInRange:cocoon::internal::to(range)];
    }

    void TextCheckingController::invalidate() const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) invalidate];
    }

    Menu TextCheckingController::menu_at_index(std::uint64_t location, bool clicked_on_selection, Range* effective_range) const
    {
        return cocoon::internal::wrap<Menu>([cocoon::internal::ns<::NSTextCheckingController>(this) menuAtIndex:static_cast<::NSUInteger>(location) clickedOnSelection:static_cast<::BOOL>(clicked_on_selection) effectiveRange:(::NSRangePointer)(effective_range)]);
    }

    void TextCheckingController::order_front_substitutions_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) orderFrontSubstitutionsPanel:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::show_guess_panel(const Object& sender) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) showGuessPanel:cocoon::internal::native_id(sender)];
    }

    void TextCheckingController::update_candidates() const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) updateCandidates];
    }

    std::vector<std::string> TextCheckingController::valid_annotations() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSTextCheckingController>(this) validAnnotations], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::int64_t TextCheckingController::spell_checker_document_tag() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSTextCheckingController>(this) spellCheckerDocumentTag]);
    }

    void TextCheckingController::set_spell_checker_document_tag(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSTextCheckingController>(this) setSpellCheckerDocumentTag:static_cast<::NSInteger>(value)];
    }
}
