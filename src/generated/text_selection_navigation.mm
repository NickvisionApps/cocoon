#include "generated/text_selection_navigation.h"
#include "internal.h"

namespace cocoon
{
    TextSelectionNavigation::TextSelectionNavigation(const Object& data_source) : TextSelectionNavigation(Adopt{cocoon::internal::retain([[::NSTextSelectionNavigation alloc] initWithDataSource:cocoon::internal::native_id(data_source)])})
    {
    }

    TextSelectionNavigation::TextSelectionNavigation() : Object(nullptr)
    {
    }

    TextSelectionNavigation::TextSelectionNavigation(std::nullptr_t) : Object(nullptr)
    {
    }

    TextSelectionNavigation::TextSelectionNavigation(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<TextRange> TextSelectionNavigation::deletion_ranges_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationDirection direction, TextSelectionNavigationDestination destination, bool allows_decomposition) const
    {
        return cocoon::internal::from_array<TextRange>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) deletionRangesForTextSelection:cocoon::internal::native<::NSTextSelection>(text_selection) direction:static_cast<::NSTextSelectionNavigationDirection>(direction) destination:static_cast<::NSTextSelectionNavigationDestination>(destination) allowsDecomposition:static_cast<::BOOL>(allows_decomposition)], [](id e) -> TextRange
                                                       {
                                                           return cocoon::internal::wrap<TextRange>((::NSTextRange*)e);
                                                       });
    }

    TextSelection TextSelectionNavigation::destination_selection_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationDirection direction, TextSelectionNavigationDestination destination, bool extending, bool confined) const
    {
        return cocoon::internal::wrap<TextSelection>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) destinationSelectionForTextSelection:cocoon::internal::native<::NSTextSelection>(text_selection) direction:static_cast<::NSTextSelectionNavigationDirection>(direction) destination:static_cast<::NSTextSelectionNavigationDestination>(destination) extending:static_cast<::BOOL>(extending) confined:static_cast<::BOOL>(confined)]);
    }

    void TextSelectionNavigation::flush_layout_cache() const
    {
        [cocoon::internal::ns<::NSTextSelectionNavigation>(this) flushLayoutCache];
    }

    Object TextSelectionNavigation::resolved_insertion_location_for_text_selection(const TextSelection& text_selection, TextSelectionNavigationWritingDirection writing_direction) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) resolvedInsertionLocationForTextSelection:cocoon::internal::native<::NSTextSelection>(text_selection) writingDirection:static_cast<::NSTextSelectionNavigationWritingDirection>(writing_direction)]);
    }

    TextSelection TextSelectionNavigation::text_selection_for_selection_granularity(TextSelectionGranularity selection_granularity, const Point& point, const Object& location) const
    {
        return cocoon::internal::wrap<TextSelection>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) textSelectionForSelectionGranularity:static_cast<::NSTextSelectionGranularity>(selection_granularity) enclosingPoint:cocoon::internal::to(point) inContainerAtLocation:cocoon::internal::native_id(location)]);
    }

    TextSelection TextSelectionNavigation::text_selection_for_selection_granularity(TextSelectionGranularity selection_granularity, const TextSelection& text_selection) const
    {
        return cocoon::internal::wrap<TextSelection>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) textSelectionForSelectionGranularity:static_cast<::NSTextSelectionGranularity>(selection_granularity) enclosingTextSelection:cocoon::internal::native<::NSTextSelection>(text_selection)]);
    }

    std::vector<TextSelection> TextSelectionNavigation::text_selections_interacting_at_point(const Point& point, const Object& container_location, const std::vector<TextSelection>& anchors, TextSelectionNavigationModifier modifiers, bool selecting, const Rect& bounds) const
    {
        return cocoon::internal::from_array<TextSelection>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) textSelectionsInteractingAtPoint:cocoon::internal::to(point)
                                                                                                                               inContainerAtLocation:cocoon::internal::native_id(container_location)
                                                                                                                                             anchors:cocoon::internal::to_array(anchors, [](const TextSelection& e) -> id
                                                                                                                                                                                {
                                                                                                                                                                                    return cocoon::internal::native<::NSTextSelection>(e);
                                                                                                                                                                                })
                                                                                                                                           modifiers:static_cast<::NSTextSelectionNavigationModifier>(modifiers)
                                                                                                                                           selecting:static_cast<::BOOL>(selecting)
                                                                                                                                              bounds:cocoon::internal::to(bounds)],
                                                           [](id e) -> TextSelection
                                                           {
                                                               return cocoon::internal::wrap<TextSelection>((::NSTextSelection*)e);
                                                           });
    }

    bool TextSelectionNavigation::allows_non_contiguous_ranges() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) allowsNonContiguousRanges]);
    }

    void TextSelectionNavigation::set_allows_non_contiguous_ranges(bool value) const
    {
        [cocoon::internal::ns<::NSTextSelectionNavigation>(this) setAllowsNonContiguousRanges:static_cast<::BOOL>(value)];
    }

    bool TextSelectionNavigation::rotates_coordinate_system_for_layout_orientation() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextSelectionNavigation>(this) rotatesCoordinateSystemForLayoutOrientation]);
    }

    void TextSelectionNavigation::set_rotates_coordinate_system_for_layout_orientation(bool value) const
    {
        [cocoon::internal::ns<::NSTextSelectionNavigation>(this) setRotatesCoordinateSystemForLayoutOrientation:static_cast<::BOOL>(value)];
    }
}
