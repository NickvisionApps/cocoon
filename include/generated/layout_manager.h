#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGContext;
    class Cell;
    class Color;
    class Font;
    class GlyphGenerator;
    class ParagraphStyle;
    class RulerMarker;
    class RulerView;
    class TextBlock;
    class TextContainer;
    class TextStorage;
    class TextView;
    class Typesetter;
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSLayoutManager` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::LayoutManager layout_manager;
     * layout_manager.set_allows_non_contiguous_layout(true);
     * layout_manager.did_invalidate_layout().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::LayoutManager layout_manager{};
     * layout_manager.set_allows_non_contiguous_layout(true);
     * auto allows_non_contiguous_layout = layout_manager.allows_non_contiguous_layout();
     * layout_manager.set_background_layout_enabled(true);
     * auto background_layout_enabled = layout_manager.background_layout_enabled();
     * layout_manager.set_default_attachment_scaling(cocoon::ImageScaling::ImageScaleProportionallyDown);
     * auto default_attachment_scaling = layout_manager.default_attachment_scaling();
     * layout_manager.cg_glyph_at_index(1);
     * layout_manager.add_text_container(cocoon::TextContainer());
     * layout_manager.attachment_size_for_glyph_at_index(1);
     * layout_manager.did_invalidate_layout().connect([]() {});
     * layout_manager.did_complete_layout_for_text_container_at_end().connect([](cocoon::TextContainer a0, bool a1) {});
     * layout_manager.text_container_did_change_geometry_from_size().connect([](cocoon::TextContainer a0, cocoon::Size a1) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nslayoutmanager
     */
    class LayoutManager : public Object
    {
    public:
        /// @brief Creates a new `NSLayoutManager` instance and returns a handle to it.
        explicit LayoutManager();
        /// @brief Creates a null handle that refers to no native object.
        LayoutManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit LayoutManager(Adopt adopt);
        /**
     * @brief Calls `-[NSLayoutManager CGGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint16_t cg_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager CGGlyphAtIndex:isValidIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param is_valid_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint16_t cg_glyph_at_index(std::uint64_t glyph_index, bool* is_valid_index) const;
        /**
     * @brief Calls `-[NSLayoutManager addTemporaryAttribute:value:forCharacterRange:]`.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void add_temporary_attribute(const std::string& attr_name, const Object& value, const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager addTemporaryAttributes:forCharacterRange:]`.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void add_temporary_attributes(const std::map<std::string, Object>& attrs, const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager addTextContainer:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void add_text_container(const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager attachmentSizeForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size attachment_size_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager boundingRectForGlyphRange:inTextContainer:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounding_rect_for_glyph_range(const Range& glyph_range, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager boundsRectForTextBlock:atIndex:effectiveRange:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounds_rect_for_text_block(const TextBlock& block, std::uint64_t glyph_index, Range* effective_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager boundsRectForTextBlock:glyphRange:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounds_rect_for_text_block(const TextBlock& block, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager characterIndexForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t character_index_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager characterIndexForPoint:inTextContainer:fractionOfDistanceBetweenInsertionPoints:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param partial_fraction Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t character_index_for_point(const Point& point, const TextContainer& container, double* partial_fraction) const;
        /**
     * @brief Calls `-[NSLayoutManager characterRangeForGlyphRange:actualGlyphRange:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param actual_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range character_range_for_glyph_range(const Range& glyph_range, Range* actual_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager defaultBaselineOffsetForFont:]`.
     * @param the_font Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double default_baseline_offset_for_font(const Font& the_font) const;
        /**
     * @brief Calls `-[NSLayoutManager defaultLineHeightForFont:]`.
     * @param the_font Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double default_line_height_for_font(const Font& the_font) const;
        /**
     * @brief Calls `-[NSLayoutManager drawBackgroundForGlyphRange:atPoint:]`.
     * @param glyphs_to_show Argument converted to the Objective-C parameter of the same role.
     * @param origin Argument converted to the Objective-C parameter of the same role.
     */
        void draw_background_for_glyph_range(const Range& glyphs_to_show, const Point& origin) const;
        /**
     * @brief Calls `-[NSLayoutManager drawGlyphsForGlyphRange:atPoint:]`.
     * @param glyphs_to_show Argument converted to the Objective-C parameter of the same role.
     * @param origin Argument converted to the Objective-C parameter of the same role.
     */
        void draw_glyphs_for_glyph_range(const Range& glyphs_to_show, const Point& origin) const;
        /**
     * @brief Calls `-[NSLayoutManager drawStrikethroughForGlyphRange:strikethroughType:baselineOffset:lineFragmentRect:lineFragmentGlyphRange:containerOrigin:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param strikethrough_val Argument converted to the Objective-C parameter of the same role.
     * @param baseline_offset Argument converted to the Objective-C parameter of the same role.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container_origin Argument converted to the Objective-C parameter of the same role.
     */
        void draw_strikethrough_for_glyph_range(const Range& glyph_range, UnderlineStyle strikethrough_val, double baseline_offset, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const;
        /**
     * @brief Calls `-[NSLayoutManager drawUnderlineForGlyphRange:underlineType:baselineOffset:lineFragmentRect:lineFragmentGlyphRange:containerOrigin:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param underline_val Argument converted to the Objective-C parameter of the same role.
     * @param baseline_offset Argument converted to the Objective-C parameter of the same role.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container_origin Argument converted to the Objective-C parameter of the same role.
     */
        void draw_underline_for_glyph_range(const Range& glyph_range, UnderlineStyle underline_val, double baseline_offset, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const;
        /**
     * @brief Calls `-[NSLayoutManager drawsOutsideLineFragmentForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool draws_outside_line_fragment_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureGlyphsForCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_glyphs_for_character_range(const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureGlyphsForGlyphRange:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_glyphs_for_glyph_range(const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureLayoutForBoundingRect:inTextContainer:]`.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_bounding_rect(const Rect& bounds, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureLayoutForCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_character_range(const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureLayoutForGlyphRange:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_glyph_range(const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager ensureLayoutForTextContainer:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_text_container(const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager enumerateEnclosingRectsForGlyphRange:withinSelectedGlyphRange:inTextContainer:usingBlock:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param selected_range Argument converted to the Objective-C parameter of the same role.
     * @param text_container Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_enclosing_rects_for_glyph_range(const Range& glyph_range, const Range& selected_range, const TextContainer& text_container, std::function<void(Rect, bool&)> block) const;
        /**
     * @brief Calls `-[NSLayoutManager enumerateLineFragmentsForGlyphRange:usingBlock:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_line_fragments_for_glyph_range(const Range& glyph_range, std::function<void(Rect, Rect, TextContainer, Range, bool&)> block) const;
        /**
     * @brief Calls `-[NSLayoutManager fillBackgroundRectArray:count:forCharacterRange:color:]`.
     * @param rect_array Argument converted to the Objective-C parameter of the same role.
     * @param rect_count Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param color Argument converted to the Objective-C parameter of the same role.
     */
        void fill_background_rect_array(const Rect* rect_array, std::uint64_t rect_count, const Range& char_range, const Color& color) const;
        /**
     * @brief Calls `-[NSLayoutManager firstUnlaidCharacterIndex]`.
     * @return The converted Objective-C result.
     */
        std::uint64_t first_unlaid_character_index() const;
        /**
     * @brief Calls `-[NSLayoutManager firstUnlaidGlyphIndex]`.
     * @return The converted Objective-C result.
     */
        std::uint64_t first_unlaid_glyph_index() const;
        /**
     * @brief Calls `-[NSLayoutManager fractionOfDistanceThroughGlyphForPoint:inTextContainer:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double fraction_of_distance_through_glyph_for_point(const Point& point, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager getFirstUnlaidCharacterIndex:glyphIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     */
        void get_first_unlaid_character_index(std::uint64_t* char_index, std::uint64_t* glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager getGlyphsInRange:glyphs:properties:characterIndexes:bidiLevels:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param glyph_buffer Argument converted to the Objective-C parameter of the same role.
     * @param props Argument converted to the Objective-C parameter of the same role.
     * @param char_index_buffer Argument converted to the Objective-C parameter of the same role.
     * @param bidi_level_buffer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t get_glyphs_in_range(const Range& glyph_range, std::uint16_t* glyph_buffer, GlyphProperty* props, std::uint64_t* char_index_buffer, std::uint8_t* bidi_level_buffer) const;
        /**
     * @brief Calls `-[NSLayoutManager getLineFragmentInsertionPointsForCharacterAtIndex:alternatePositions:inDisplayOrder:positions:characterIndexes:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param a_flag Argument converted to the Objective-C parameter of the same role.
     * @param d_flag Argument converted to the Objective-C parameter of the same role.
     * @param positions Argument converted to the Objective-C parameter of the same role.
     * @param char_indexes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t get_line_fragment_insertion_points_for_character_at_index(std::uint64_t char_index, bool a_flag, bool d_flag, double* positions, std::uint64_t* char_indexes) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphAtIndex:isValidIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param is_valid_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int glyph_at_index(std::uint64_t glyph_index, bool* is_valid_index) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphIndexForCharacterAtIndex:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t glyph_index_for_character_at_index(std::uint64_t char_index) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphIndexForPoint:inTextContainer:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t glyph_index_for_point(const Point& point, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphIndexForPoint:inTextContainer:fractionOfDistanceThroughGlyph:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param partial_fraction Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t glyph_index_for_point(const Point& point, const TextContainer& container, double* partial_fraction) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphRangeForBoundingRect:inTextContainer:]`.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range glyph_range_for_bounding_rect(const Rect& bounds, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphRangeForBoundingRectWithoutAdditionalLayout:inTextContainer:]`.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range glyph_range_for_bounding_rect_without_additional_layout(const Rect& bounds, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphRangeForCharacterRange:actualCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param actual_char_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range glyph_range_for_character_range(const Range& char_range, Range* actual_char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager glyphRangeForTextContainer:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range glyph_range_for_text_container(const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager insertTextContainer:atIndex:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_text_container(const TextContainer& container, std::uint64_t index) const;
        /**
     * @brief Calls `-[NSLayoutManager invalidateDisplayForCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_display_for_character_range(const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager invalidateDisplayForGlyphRange:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_display_for_glyph_range(const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager invalidateGlyphsForCharacterRange:changeInLength:actualCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     * @param actual_char_range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_glyphs_for_character_range(const Range& char_range, std::int64_t delta, Range* actual_char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager invalidateLayoutForCharacterRange:actualCharacterRange:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param actual_char_range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_layout_for_character_range(const Range& char_range, Range* actual_char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager isValidGlyphIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_valid_glyph_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager layoutManagerOwnsFirstResponderInWindow:]`.
     * @param window Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool layout_manager_owns_first_responder_in_window(const Window& window) const;
        /**
     * @brief Calls `-[NSLayoutManager layoutRectForTextBlock:atIndex:effectiveRange:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect layout_rect_for_text_block(const TextBlock& block, std::uint64_t glyph_index, Range* effective_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager layoutRectForTextBlock:glyphRange:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect layout_rect_for_text_block(const TextBlock& block, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager lineFragmentRectForGlyphAtIndex:effectiveRange:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager lineFragmentRectForGlyphAtIndex:effectiveRange:withoutAdditionalLayout:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const;
        /**
     * @brief Calls `-[NSLayoutManager lineFragmentUsedRectForGlyphAtIndex:effectiveRange:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_used_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager lineFragmentUsedRectForGlyphAtIndex:effectiveRange:withoutAdditionalLayout:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect line_fragment_used_rect_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const;
        /**
     * @brief Calls `-[NSLayoutManager locationForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point location_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager notShownAttributeForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool not_shown_attribute_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager processEditingForTextStorage:edited:range:changeInLength:invalidatedRange:]`.
     * @param text_storage Argument converted to the Objective-C parameter of the same role.
     * @param edit_mask Argument converted to the Objective-C parameter of the same role.
     * @param new_char_range Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     * @param invalidated_char_range Argument converted to the Objective-C parameter of the same role.
     */
        void process_editing_for_text_storage(const TextStorage& text_storage, TextStorageEditActions edit_mask, const Range& new_char_range, std::int64_t delta, const Range& invalidated_char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager propertyForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        GlyphProperty property_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager rangeOfNominallySpacedGlyphsContainingIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range range_of_nominally_spaced_glyphs_containing_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager rectArrayForCharacterRange:withinSelectedCharacterRange:inTextContainer:rectCount:]`.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     * @param sel_char_range Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param rect_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect* rect_array_for_character_range(const Range& char_range, const Range& sel_char_range, const TextContainer& container, std::uint64_t* rect_count) const;
        /**
     * @brief Calls `-[NSLayoutManager rectArrayForGlyphRange:withinSelectedGlyphRange:inTextContainer:rectCount:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param sel_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param rect_count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect* rect_array_for_glyph_range(const Range& glyph_range, const Range& sel_glyph_range, const TextContainer& container, std::uint64_t* rect_count) const;
        /**
     * @brief Calls `-[NSLayoutManager removeTemporaryAttribute:forCharacterRange:]`.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void remove_temporary_attribute(const std::string& attr_name, const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager removeTextContainerAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_text_container_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSLayoutManager replaceTextStorage:]`.
     * @param new_text_storage Argument converted to the Objective-C parameter of the same role.
     */
        void replace_text_storage(const TextStorage& new_text_storage) const;
        /**
     * @brief Calls `-[NSLayoutManager rulerAccessoryViewForTextView:paragraphStyle:ruler:enabled:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @param is_enabled Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        View ruler_accessory_view_for_text_view(const TextView& view, const ParagraphStyle& style, const RulerView& ruler, bool is_enabled) const;
        /**
     * @brief Calls `-[NSLayoutManager rulerMarkersForTextView:paragraphStyle:ruler:]`.
     * @param view Argument converted to the Objective-C parameter of the same role.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param ruler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<RulerMarker> ruler_markers_for_text_view(const TextView& view, const ParagraphStyle& style, const RulerView& ruler) const;
        /**
     * @brief Calls `-[NSLayoutManager setAttachmentSize:forGlyphRange:]`.
     * @param attachment_size Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_attachment_size(const Size& attachment_size, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setBoundsRect:forTextBlock:glyphRange:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds_rect(const Rect& rect, const TextBlock& block, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setDrawsOutsideLineFragment:forGlyphAtIndex:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     */
        void set_draws_outside_line_fragment(bool flag, std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager setExtraLineFragmentRect:usedRect:textContainer:]`.
     * @param fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param used_rect Argument converted to the Objective-C parameter of the same role.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void set_extra_line_fragment_rect(const Rect& fragment_rect, const Rect& used_rect, const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager setGlyphs:properties:characterIndexes:font:forGlyphRange:]`.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param props Argument converted to the Objective-C parameter of the same role.
     * @param char_indexes Argument converted to the Objective-C parameter of the same role.
     * @param a_font Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_glyphs(const std::uint16_t* glyphs, const GlyphProperty* props, const std::uint64_t* char_indexes, const Font& a_font, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setLayoutRect:forTextBlock:glyphRange:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_rect(const Rect& rect, const TextBlock& block, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setLineFragmentRect:forGlyphRange:usedRect:]`.
     * @param fragment_rect Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param used_rect Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_fragment_rect(const Rect& fragment_rect, const Range& glyph_range, const Rect& used_rect) const;
        /**
     * @brief Calls `-[NSLayoutManager setLocation:forStartOfGlyphRange:]`.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_location(const Point& location, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setNotShownAttribute:forGlyphAtIndex:]`.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     */
        void set_not_shown_attribute(bool flag, std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager setTemporaryAttributes:forCharacterRange:]`.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @param char_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_temporary_attributes(const std::map<std::string, Object>& attrs, const Range& char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager setTextContainer:forGlyphRange:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_container(const TextContainer& container, const Range& glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager showAttachmentCell:inRect:characterIndex:]`.
     * @param cell Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param attachment_index Argument converted to the Objective-C parameter of the same role.
     */
        void show_attachment_cell(const Cell& cell, const Rect& rect, std::uint64_t attachment_index) const;
        /**
     * @brief Calls `-[NSLayoutManager showCGGlyphs:positions:count:font:textMatrix:attributes:inContext:]`.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param positions Argument converted to the Objective-C parameter of the same role.
     * @param glyph_count Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     * @param text_matrix Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @param cg_context Argument converted to the Objective-C parameter of the same role.
     */
        void show_cg_glyphs(const std::uint16_t* glyphs, const Point* positions, std::int64_t glyph_count, const Font& font, const AffineTransform3& text_matrix, const std::map<std::string, Object>& attributes, const CGContext& cg_context) const;
        /**
     * @brief Calls `-[NSLayoutManager strikethroughGlyphRange:strikethroughType:lineFragmentRect:lineFragmentGlyphRange:containerOrigin:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param strikethrough_val Argument converted to the Objective-C parameter of the same role.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container_origin Argument converted to the Objective-C parameter of the same role.
     */
        void strikethrough_glyph_range(const Range& glyph_range, UnderlineStyle strikethrough_val, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const;
        /**
     * @brief Calls `-[NSLayoutManager temporaryAttribute:atCharacterIndex:effectiveRange:]`.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object temporary_attribute(const std::string& attr_name, std::uint64_t location, Range* range) const;
        /**
     * @brief Calls `-[NSLayoutManager temporaryAttribute:atCharacterIndex:longestEffectiveRange:inRange:]`.
     * @param attr_name Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param range_limit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object temporary_attribute(const std::string& attr_name, std::uint64_t location, Range* range, const Range& range_limit) const;
        /**
     * @brief Calls `-[NSLayoutManager temporaryAttributesAtCharacterIndex:effectiveRange:]`.
     * @param char_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_char_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> temporary_attributes_at_character_index(std::uint64_t char_index, Range* effective_char_range) const;
        /**
     * @brief Calls `-[NSLayoutManager temporaryAttributesAtCharacterIndex:longestEffectiveRange:inRange:]`.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param range_limit Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> temporary_attributes_at_character_index(std::uint64_t location, Range* range, const Range& range_limit) const;
        /**
     * @brief Calls `-[NSLayoutManager textContainerChangedGeometry:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void text_container_changed_geometry(const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager textContainerChangedTextView:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     */
        void text_container_changed_text_view(const TextContainer& container) const;
        /**
     * @brief Calls `-[NSLayoutManager textContainerForGlyphAtIndex:effectiveRange:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextContainer text_container_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range) const;
        /**
     * @brief Calls `-[NSLayoutManager textContainerForGlyphAtIndex:effectiveRange:withoutAdditionalLayout:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @param effective_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param flag Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextContainer text_container_for_glyph_at_index(std::uint64_t glyph_index, Range* effective_glyph_range, bool flag) const;
        /**
     * @brief Calls `-[NSLayoutManager truncatedGlyphRangeInLineFragmentForGlyphAtIndex:]`.
     * @param glyph_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Range truncated_glyph_range_in_line_fragment_for_glyph_at_index(std::uint64_t glyph_index) const;
        /**
     * @brief Calls `-[NSLayoutManager underlineGlyphRange:underlineType:lineFragmentRect:lineFragmentGlyphRange:containerOrigin:]`.
     * @param glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param underline_val Argument converted to the Objective-C parameter of the same role.
     * @param line_rect Argument converted to the Objective-C parameter of the same role.
     * @param line_glyph_range Argument converted to the Objective-C parameter of the same role.
     * @param container_origin Argument converted to the Objective-C parameter of the same role.
     */
        void underline_glyph_range(const Range& glyph_range, UnderlineStyle underline_val, const Rect& line_rect, const Range& line_glyph_range, const Point& container_origin) const;
        /**
     * @brief Calls `-[NSLayoutManager usedRectForTextContainer:]`.
     * @param container Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect used_rect_for_text_container(const TextContainer& container) const;
        /**
     * @brief Returns the `allowsNonContiguousLayout` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool allows_non_contiguous_layout() const;
        /**
     * @brief Sets the `allowsNonContiguousLayout` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_non_contiguous_layout(bool value) const;
        /**
     * @brief Returns the `backgroundLayoutEnabled` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool background_layout_enabled() const;
        /**
     * @brief Sets the `backgroundLayoutEnabled` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_background_layout_enabled(bool value) const;
        /**
     * @brief Returns the `defaultAttachmentScaling` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        ImageScaling default_attachment_scaling() const;
        /**
     * @brief Sets the `defaultAttachmentScaling` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_default_attachment_scaling(ImageScaling value) const;
        /**
     * @brief Returns the `extraLineFragmentRect` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        Rect extra_line_fragment_rect() const;
        /**
     * @brief Returns the `extraLineFragmentTextContainer` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        TextContainer extra_line_fragment_text_container() const;
        /**
     * @brief Returns the `extraLineFragmentUsedRect` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        Rect extra_line_fragment_used_rect() const;
        /**
     * @brief Returns the `firstTextView` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        TextView first_text_view() const;
        /**
     * @brief Returns the `glyphGenerator` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        GlyphGenerator glyph_generator() const;
        /**
     * @brief Sets the `glyphGenerator` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_glyph_generator(const GlyphGenerator& value) const;
        /**
     * @brief Returns the `hasNonContiguousLayout` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool has_non_contiguous_layout() const;
        /**
     * @brief Returns the `limitsLayoutForSuspiciousContents` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool limits_layout_for_suspicious_contents() const;
        /**
     * @brief Sets the `limitsLayoutForSuspiciousContents` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_limits_layout_for_suspicious_contents(bool value) const;
        /**
     * @brief Returns the `numberOfGlyphs` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        std::uint64_t number_of_glyphs() const;
        /**
     * @brief Returns the `showsControlCharacters` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool shows_control_characters() const;
        /**
     * @brief Sets the `showsControlCharacters` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_control_characters(bool value) const;
        /**
     * @brief Returns the `showsInvisibleCharacters` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool shows_invisible_characters() const;
        /**
     * @brief Sets the `showsInvisibleCharacters` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_shows_invisible_characters(bool value) const;
        /**
     * @brief Returns the `textContainers` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        std::vector<TextContainer> text_containers() const;
        /**
     * @brief Returns the `textStorage` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        TextStorage text_storage() const;
        /**
     * @brief Sets the `textStorage` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_storage(const TextStorage& value) const;
        /**
     * @brief Returns the `textViewForBeginningOfSelection` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        TextView text_view_for_beginning_of_selection() const;
        /**
     * @brief Returns the `typesetter` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        Typesetter typesetter() const;
        /**
     * @brief Sets the `typesetter` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_typesetter(const Typesetter& value) const;
        /**
     * @brief Returns the `typesetterBehavior` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        TypesetterBehavior typesetter_behavior() const;
        /**
     * @brief Sets the `typesetterBehavior` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_typesetter_behavior(TypesetterBehavior value) const;
        /**
     * @brief Returns the `usesDefaultHyphenation` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool uses_default_hyphenation() const;
        /**
     * @brief Sets the `usesDefaultHyphenation` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_default_hyphenation(bool value) const;
        /**
     * @brief Returns the `usesFontLeading` property of `NSLayoutManager`.
     * @return The converted Objective-C result.
     */
        bool uses_font_leading() const;
        /**
     * @brief Sets the `usesFontLeading` property of `NSLayoutManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_font_leading(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `should_generate_glyphs_properties_character_indexes_font_for_glyph_range`; connect a callback with `should_generate_glyphs_properties_character_indexes_font_for_glyph_range().connect(...)`.
        Signal<LayoutManager, std::uint64_t(const std::uint16_t*, const GlyphProperty*, const std::uint64_t*, Font, Range)> should_generate_glyphs_properties_character_indexes_font_for_glyph_range() const
        {
            return Signal<LayoutManager, std::uint64_t(const std::uint16_t*, const GlyphProperty*, const std::uint64_t*, Font, Range)>(handle(), "should_generate_glyphs_properties_character_indexes_font_for_glyph_range");
        }
        /// @brief Signal for the delegate/data-source method behind `line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect`; connect a callback with `line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect().connect(...)`.
        Signal<LayoutManager, double(std::uint64_t, Rect)> line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect() const
        {
            return Signal<LayoutManager, double(std::uint64_t, Rect)>(handle(), "line_spacing_after_glyph_at_index_with_proposed_line_fragment_rect");
        }
        /// @brief Signal for the delegate/data-source method behind `paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect`; connect a callback with `paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect().connect(...)`.
        Signal<LayoutManager, double(std::uint64_t, Rect)> paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect() const
        {
            return Signal<LayoutManager, double(std::uint64_t, Rect)>(handle(), "paragraph_spacing_before_glyph_at_index_with_proposed_line_fragment_rect");
        }
        /// @brief Signal for the delegate/data-source method behind `paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect`; connect a callback with `paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect().connect(...)`.
        Signal<LayoutManager, double(std::uint64_t, Rect)> paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect() const
        {
            return Signal<LayoutManager, double(std::uint64_t, Rect)>(handle(), "paragraph_spacing_after_glyph_at_index_with_proposed_line_fragment_rect");
        }
        /// @brief Signal for the delegate/data-source method behind `should_use_action_for_control_character_at_index`; connect a callback with `should_use_action_for_control_character_at_index().connect(...)`.
        Signal<LayoutManager, ControlCharacterAction(ControlCharacterAction, std::uint64_t)> should_use_action_for_control_character_at_index() const
        {
            return Signal<LayoutManager, ControlCharacterAction(ControlCharacterAction, std::uint64_t)>(handle(), "should_use_action_for_control_character_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `should_break_line_by_word_before_character_at_index`; connect a callback with `should_break_line_by_word_before_character_at_index().connect(...)`.
        Signal<LayoutManager, bool(std::uint64_t)> should_break_line_by_word_before_character_at_index() const
        {
            return Signal<LayoutManager, bool(std::uint64_t)>(handle(), "should_break_line_by_word_before_character_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `should_break_line_by_hyphenating_before_character_at_index`; connect a callback with `should_break_line_by_hyphenating_before_character_at_index().connect(...)`.
        Signal<LayoutManager, bool(std::uint64_t)> should_break_line_by_hyphenating_before_character_at_index() const
        {
            return Signal<LayoutManager, bool(std::uint64_t)>(handle(), "should_break_line_by_hyphenating_before_character_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index`; connect a callback with `bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index().connect(...)`.
        Signal<LayoutManager, Rect(std::uint64_t, TextContainer, Rect, Point, std::uint64_t)> bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index() const
        {
            return Signal<LayoutManager, Rect(std::uint64_t, TextContainer, Rect, Point, std::uint64_t)>(handle(), "bounding_box_for_control_glyph_at_index_for_text_container_proposed_line_fragment_glyph_position_character_index");
        }
        /// @brief Signal for the delegate/data-source method behind `should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range`; connect a callback with `should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range().connect(...)`.
        Signal<LayoutManager, bool(Rect*, Rect*, double*, TextContainer, Range)> should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range() const
        {
            return Signal<LayoutManager, bool(Rect*, Rect*, double*, TextContainer, Range)>(handle(), "should_set_line_fragment_rect_line_fragment_used_rect_baseline_offset_in_text_container_for_glyph_range");
        }
        /// @brief Signal for the delegate/data-source method behind `did_invalidate_layout`; connect a callback with `did_invalidate_layout().connect(...)`.
        Signal<LayoutManager, void()> did_invalidate_layout() const
        {
            return Signal<LayoutManager, void()>(handle(), "did_invalidate_layout");
        }
        /// @brief Signal for the delegate/data-source method behind `did_complete_layout_for_text_container_at_end`; connect a callback with `did_complete_layout_for_text_container_at_end().connect(...)`.
        Signal<LayoutManager, void(TextContainer, bool)> did_complete_layout_for_text_container_at_end() const
        {
            return Signal<LayoutManager, void(TextContainer, bool)>(handle(), "did_complete_layout_for_text_container_at_end");
        }
        /// @brief Signal for the delegate/data-source method behind `text_container_did_change_geometry_from_size`; connect a callback with `text_container_did_change_geometry_from_size().connect(...)`.
        Signal<LayoutManager, void(TextContainer, Size)> text_container_did_change_geometry_from_size() const
        {
            return Signal<LayoutManager, void(TextContainer, Size)>(handle(), "text_container_did_change_geometry_from_size");
        }
        /// @brief Signal for the delegate/data-source method behind `should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range`; connect a callback with `should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range().connect(...)`.
        Signal<LayoutManager, std::map<std::string, Object>(std::map<std::string, Object>, bool, std::uint64_t, Range*)> should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range() const
        {
            return Signal<LayoutManager, std::map<std::string, Object>(std::map<std::string, Object>, bool, std::uint64_t, Range*)>(handle(), "should_use_temporary_attributes_for_drawing_to_screen_at_character_index_effective_range");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
