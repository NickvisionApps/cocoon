#include "generated/text_container.h"
#include "internal.h"

namespace cocoon
{
    TextContainer::TextContainer(const Size& a_container_size) : TextContainer(Adopt{cocoon::internal::retain([[::NSTextContainer alloc] initWithContainerSize:cocoon::internal::to(a_container_size)])})
    {
    }

    TextContainer::TextContainer() : TextContainer(Adopt{cocoon::internal::retain([[::NSTextContainer alloc] init])})
    {
    }

    TextContainer::TextContainer(std::nullptr_t) : Object(nullptr)
    {
    }

    TextContainer::TextContainer(Adopt adopt) : Object(adopt)
    {
    }

    Rect TextContainer::line_fragment_rect_for_proposed_rect(const Rect& proposed_rect, std::uint64_t character_index, WritingDirection base_writing_direction, Rect* remaining_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextContainer>(this) lineFragmentRectForProposedRect:cocoon::internal::to(proposed_rect) atIndex:static_cast<::NSUInteger>(character_index) writingDirection:static_cast<::NSWritingDirection>(base_writing_direction) remainingRect:(::CGRect*)(remaining_rect)]);
    }

    Rect TextContainer::line_fragment_rect_for_proposed_rect(const Rect& proposed_rect, LineSweepDirection sweep_direction, LineMovementDirection movement_direction, Rect* remaining_rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextContainer>(this) lineFragmentRectForProposedRect:cocoon::internal::to(proposed_rect) sweepDirection:static_cast<::NSLineSweepDirection>(sweep_direction) movementDirection:static_cast<::NSLineMovementDirection>(movement_direction) remainingRect:(::NSRectPointer)(remaining_rect)]);
    }

    void TextContainer::replace_layout_manager(const LayoutManager& new_layout_manager) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) replaceLayoutManager:cocoon::internal::native<::NSLayoutManager>(new_layout_manager)];
    }

    Size TextContainer::container_size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextContainer>(this) containerSize]);
    }

    void TextContainer::set_container_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setContainerSize:cocoon::internal::to(value)];
    }

    std::vector<BezierPath> TextContainer::exclusion_paths() const
    {
        return cocoon::internal::from_array<BezierPath>([cocoon::internal::ns<::NSTextContainer>(this) exclusionPaths], [](id e) -> BezierPath
                                          {
                                              return cocoon::internal::wrap<BezierPath>((::NSBezierPath*)e);
                                          });
    }

    void TextContainer::set_exclusion_paths(const std::vector<BezierPath>& value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setExclusionPaths:cocoon::internal::to_array(value, [](const BezierPath& e) -> id
                                                                        {
                                                                            return cocoon::internal::native<::NSBezierPath>(e);
                                                                        })];
    }

    bool TextContainer::height_tracks_text_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContainer>(this) heightTracksTextView]);
    }

    void TextContainer::set_height_tracks_text_view(bool value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setHeightTracksTextView:static_cast<::BOOL>(value)];
    }

    LayoutManager TextContainer::layout_manager() const
    {
        return cocoon::internal::wrap<LayoutManager>([cocoon::internal::ns<::NSTextContainer>(this) layoutManager]);
    }

    void TextContainer::set_layout_manager(const LayoutManager& value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setLayoutManager:cocoon::internal::native<::NSLayoutManager>(value)];
    }

    LineBreakMode TextContainer::line_break_mode() const
    {
        return static_cast<LineBreakMode>([cocoon::internal::ns<::NSTextContainer>(this) lineBreakMode]);
    }

    void TextContainer::set_line_break_mode(LineBreakMode value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setLineBreakMode:static_cast<::NSLineBreakMode>(value)];
    }

    double TextContainer::line_fragment_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextContainer>(this) lineFragmentPadding]);
    }

    void TextContainer::set_line_fragment_padding(double value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setLineFragmentPadding:static_cast<::CGFloat>(value)];
    }

    std::uint64_t TextContainer::maximum_number_of_lines() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSTextContainer>(this) maximumNumberOfLines]);
    }

    void TextContainer::set_maximum_number_of_lines(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setMaximumNumberOfLines:static_cast<::NSUInteger>(value)];
    }

    bool TextContainer::is_simple_rectangular_text_container() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContainer>(this) isSimpleRectangularTextContainer]);
    }

    Size TextContainer::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextContainer>(this) size]);
    }

    void TextContainer::set_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setSize:cocoon::internal::to(value)];
    }

    TextLayoutManager TextContainer::text_layout_manager() const
    {
        return cocoon::internal::wrap<TextLayoutManager>([cocoon::internal::ns<::NSTextContainer>(this) textLayoutManager]);
    }

    TextView TextContainer::text_view() const
    {
        return cocoon::internal::wrap<TextView>([cocoon::internal::ns<::NSTextContainer>(this) textView]);
    }

    void TextContainer::set_text_view(const TextView& value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setTextView:cocoon::internal::native<::NSTextView>(value)];
    }

    bool TextContainer::width_tracks_text_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextContainer>(this) widthTracksTextView]);
    }

    void TextContainer::set_width_tracks_text_view(bool value) const
    {
        [cocoon::internal::ns<::NSTextContainer>(this) setWidthTracksTextView:static_cast<::BOOL>(value)];
    }
}
