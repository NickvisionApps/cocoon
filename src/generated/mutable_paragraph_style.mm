#include "generated/mutable_paragraph_style.h"
#include "internal.h"

namespace cocoon
{
    MutableParagraphStyle::MutableParagraphStyle() : MutableParagraphStyle(Adopt{cocoon::internal::retain([[::NSMutableParagraphStyle alloc] init])})
    {
    }

    MutableParagraphStyle::MutableParagraphStyle(std::nullptr_t) : ParagraphStyle(nullptr)
    {
    }

    MutableParagraphStyle::MutableParagraphStyle(Adopt adopt) : ParagraphStyle(adopt)
    {
    }

    void MutableParagraphStyle::add_tab_stop(const TextTab& an_object) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) addTabStop:cocoon::internal::native<::NSTextTab>(an_object)];
    }

    void MutableParagraphStyle::remove_tab_stop(const TextTab& an_object) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) removeTabStop:cocoon::internal::native<::NSTextTab>(an_object)];
    }

    void MutableParagraphStyle::set_paragraph_style(const ParagraphStyle& obj) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setParagraphStyle:cocoon::internal::native<::NSParagraphStyle>(obj)];
    }

    TextAlignment MutableParagraphStyle::alignment() const
    {
        return static_cast<TextAlignment>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) alignment]);
    }

    void MutableParagraphStyle::set_alignment(TextAlignment value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setAlignment:static_cast<::NSTextAlignment>(value)];
    }

    bool MutableParagraphStyle::allows_default_tightening_for_truncation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) allowsDefaultTighteningForTruncation]);
    }

    void MutableParagraphStyle::set_allows_default_tightening_for_truncation(bool value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setAllowsDefaultTighteningForTruncation:static_cast<::BOOL>(value)];
    }

    WritingDirection MutableParagraphStyle::base_writing_direction() const
    {
        return static_cast<WritingDirection>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) baseWritingDirection]);
    }

    void MutableParagraphStyle::set_base_writing_direction(WritingDirection value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setBaseWritingDirection:static_cast<::NSWritingDirection>(value)];
    }

    double MutableParagraphStyle::default_tab_interval() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) defaultTabInterval]);
    }

    void MutableParagraphStyle::set_default_tab_interval(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setDefaultTabInterval:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::first_line_head_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) firstLineHeadIndent]);
    }

    void MutableParagraphStyle::set_first_line_head_indent(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setFirstLineHeadIndent:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::head_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) headIndent]);
    }

    void MutableParagraphStyle::set_head_indent(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setHeadIndent:static_cast<::CGFloat>(value)];
    }

    std::int64_t MutableParagraphStyle::header_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) headerLevel]);
    }

    void MutableParagraphStyle::set_header_level(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setHeaderLevel:static_cast<::NSInteger>(value)];
    }

    float MutableParagraphStyle::hyphenation_factor() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) hyphenationFactor]);
    }

    void MutableParagraphStyle::set_hyphenation_factor(float value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setHyphenationFactor:static_cast<float>(value)];
    }

    LineBreakMode MutableParagraphStyle::line_break_mode() const
    {
        return static_cast<LineBreakMode>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) lineBreakMode]);
    }

    void MutableParagraphStyle::set_line_break_mode(LineBreakMode value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setLineBreakMode:static_cast<::NSLineBreakMode>(value)];
    }

    LineBreakStrategy MutableParagraphStyle::line_break_strategy() const
    {
        return static_cast<LineBreakStrategy>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) lineBreakStrategy]);
    }

    void MutableParagraphStyle::set_line_break_strategy(LineBreakStrategy value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setLineBreakStrategy:static_cast<::NSLineBreakStrategy>(value)];
    }

    double MutableParagraphStyle::line_height_multiple() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) lineHeightMultiple]);
    }

    void MutableParagraphStyle::set_line_height_multiple(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setLineHeightMultiple:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::line_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) lineSpacing]);
    }

    void MutableParagraphStyle::set_line_spacing(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setLineSpacing:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::maximum_line_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) maximumLineHeight]);
    }

    void MutableParagraphStyle::set_maximum_line_height(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setMaximumLineHeight:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::minimum_line_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) minimumLineHeight]);
    }

    void MutableParagraphStyle::set_minimum_line_height(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setMinimumLineHeight:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::paragraph_spacing() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) paragraphSpacing]);
    }

    void MutableParagraphStyle::set_paragraph_spacing(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setParagraphSpacing:static_cast<::CGFloat>(value)];
    }

    double MutableParagraphStyle::paragraph_spacing_before() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) paragraphSpacingBefore]);
    }

    void MutableParagraphStyle::set_paragraph_spacing_before(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setParagraphSpacingBefore:static_cast<::CGFloat>(value)];
    }

    std::vector<TextTab> MutableParagraphStyle::tab_stops() const
    {
        return cocoon::internal::from_array<TextTab>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) tabStops], [](id e) -> TextTab
                                                     {
                                                         return cocoon::internal::wrap<TextTab>((::NSTextTab*)e);
                                                     });
    }

    void MutableParagraphStyle::set_tab_stops(const std::vector<TextTab>& value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setTabStops:cocoon::internal::to_array(value, [](const TextTab& e) -> id
                                                                                                      {
                                                                                                          return cocoon::internal::native<::NSTextTab>(e);
                                                                                                      })];
    }

    double MutableParagraphStyle::tail_indent() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) tailIndent]);
    }

    void MutableParagraphStyle::set_tail_indent(double value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setTailIndent:static_cast<::CGFloat>(value)];
    }

    std::vector<TextBlock> MutableParagraphStyle::text_blocks() const
    {
        return cocoon::internal::from_array<TextBlock>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) textBlocks], [](id e) -> TextBlock
                                                       {
                                                           return cocoon::internal::wrap<TextBlock>((::NSTextBlock*)e);
                                                       });
    }

    void MutableParagraphStyle::set_text_blocks(const std::vector<TextBlock>& value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setTextBlocks:cocoon::internal::to_array(value, [](const TextBlock& e) -> id
                                                                                                        {
                                                                                                            return cocoon::internal::native<::NSTextBlock>(e);
                                                                                                        })];
    }

    std::vector<TextList> MutableParagraphStyle::text_lists() const
    {
        return cocoon::internal::from_array<TextList>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) textLists], [](id e) -> TextList
                                                      {
                                                          return cocoon::internal::wrap<TextList>((::NSTextList*)e);
                                                      });
    }

    void MutableParagraphStyle::set_text_lists(const std::vector<TextList>& value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setTextLists:cocoon::internal::to_array(value, [](const TextList& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSTextList>(e);
                                                                                                       })];
    }

    float MutableParagraphStyle::tightening_factor_for_truncation() const
    {
        return static_cast<float>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) tighteningFactorForTruncation]);
    }

    void MutableParagraphStyle::set_tightening_factor_for_truncation(float value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setTighteningFactorForTruncation:static_cast<float>(value)];
    }

    bool MutableParagraphStyle::uses_default_hyphenation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSMutableParagraphStyle>(this) usesDefaultHyphenation]);
    }

    void MutableParagraphStyle::set_uses_default_hyphenation(bool value) const
    {
        [cocoon::internal::ns<::NSMutableParagraphStyle>(this) setUsesDefaultHyphenation:static_cast<::BOOL>(value)];
    }
}
