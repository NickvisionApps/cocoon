#include "generated/paragraph_style.h"
#include "internal.h"

namespace cocoon
{
    ParagraphStyle::ParagraphStyle() : ParagraphStyle(Adopt{cocoon::internal::retain([[::NSParagraphStyle alloc] init])})
    {
    }

    ParagraphStyle::ParagraphStyle(std::nullptr_t) : Object(nullptr)
    {
    }

    ParagraphStyle::ParagraphStyle(Adopt adopt) : Object(adopt)
    {
    }

    WritingDirection ParagraphStyle::default_writing_direction_for_language(const std::string& language_name)
    {
        return static_cast<WritingDirection>([::NSParagraphStyle defaultWritingDirectionForLanguage:cocoon::internal::to(language_name)]);
    }

    bool ParagraphStyle::allows_default_tightening_for_truncation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSParagraphStyle>(this) allowsDefaultTighteningForTruncation]);
    }

    WritingDirection ParagraphStyle::base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSParagraphStyle>(this) baseWritingDirection]);
    }

    ParagraphStyle ParagraphStyle::default_paragraph_style()
    {
        return cocoon::internal::wrap<ParagraphStyle>([::NSParagraphStyle defaultParagraphStyle]);
    }

    double ParagraphStyle::default_tab_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) defaultTabInterval]);
    }

    double ParagraphStyle::first_line_head_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) firstLineHeadIndent]);
    }

    double ParagraphStyle::head_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) headIndent]);
    }

    float ParagraphStyle::hyphenation_factor() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSParagraphStyle>(this) hyphenationFactor]);
    }

    LineBreakMode ParagraphStyle::line_break_mode() const
    {
        return static_cast<LineBreakMode>([cocoon::internal::ns<::NSParagraphStyle>(this) lineBreakMode]);
    }

    LineBreakStrategy ParagraphStyle::line_break_strategy() const
    {
        return static_cast<LineBreakStrategy>([cocoon::internal::ns<::NSParagraphStyle>(this) lineBreakStrategy]);
    }

    double ParagraphStyle::line_height_multiple() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) lineHeightMultiple]);
    }

    double ParagraphStyle::line_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) lineSpacing]);
    }

    double ParagraphStyle::maximum_line_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) maximumLineHeight]);
    }

    double ParagraphStyle::minimum_line_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) minimumLineHeight]);
    }

    double ParagraphStyle::paragraph_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) paragraphSpacing]);
    }

    double ParagraphStyle::paragraph_spacing_before() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) paragraphSpacingBefore]);
    }

    std::vector<TextTab> ParagraphStyle::tab_stops() const
    {
        return cocoon::internal::from_array<TextTab>([cocoon::internal::ns<::NSParagraphStyle>(this) tabStops], [](id e) -> TextTab
                                                     {
                                                         return cocoon::internal::wrap<TextTab>((::NSTextTab*)e);
                                                     });
    }

    double ParagraphStyle::tail_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSParagraphStyle>(this) tailIndent]);
    }

    std::vector<TextList> ParagraphStyle::text_lists() const
    {
        return cocoon::internal::from_array<TextList>([cocoon::internal::ns<::NSParagraphStyle>(this) textLists], [](id e) -> TextList
                                                      {
                                                          return cocoon::internal::wrap<TextList>((::NSTextList*)e);
                                                      });
    }

    bool ParagraphStyle::uses_default_hyphenation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSParagraphStyle>(this) usesDefaultHyphenation]);
    }
}
