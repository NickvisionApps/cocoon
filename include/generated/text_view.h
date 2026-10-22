#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/text.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class CandidateListTouchBarItemBase;
    class Color;
    class Event;
    class Image;
    class LayoutManager;
    class Menu;
    class Notification;
    class Orthography;
    class ParagraphStyle;
    class Pasteboard;
    class RulerMarker;
    class RulerView;
    class ScrollView;
    class SharingServicePicker;
    class TextAttachment;
    class TextCheckingResult;
    class TextContainer;
    class TextContentStorage;
    class TextLayoutFragment;
    class TextLayoutManager;
    class TextRange;
    class TextStorage;
    class TextViewportLayoutController;
    class URL;
    class UndoManager;
    class Value;

    /**
     * @brief C++ handle for the Objective-C class `NSTextView` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Text.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextView text_view;
     * text_view.set_accepts_glyph_info(true);
     * text_view.clicked_on_cell_in_rect_at_index().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextView text_view{};
     * text_view.set_accepts_glyph_info(true);
     * auto accepts_glyph_info = text_view.accepts_glyph_info();
     * text_view.set_allowed_input_source_locales({"a", "b"});
     * auto allowed_input_source_locales = text_view.allowed_input_source_locales();
     * text_view.set_allowed_writing_tools_result_options(cocoon::WritingToolsResultOptions::Default);
     * auto allowed_writing_tools_result_options = text_view.allowed_writing_tools_result_options();
     * auto made_0 = cocoon::TextView::field_editor();
     * auto made_1 = cocoon::TextView::text_view_using_text_layout_manager(true);
     * text_view.break_undo_coalescing();
     * text_view.character_index_for_insertion_at_point({0, 0});
     * text_view.clean_up_after_drag_operation();
     * text_view.clicked_on_cell_in_rect_at_index().connect([](cocoon::Object a0, cocoon::Rect a1, std::uint64_t a2) {});
     * text_view.double_clicked_on_cell_in_rect_at_index().connect([](cocoon::Object a0, cocoon::Rect a1, std::uint64_t a2) {});
     * text_view.dragged_cell_in_rect_event_at_index().connect([](cocoon::Object a0, cocoon::Rect a1, cocoon::Event a2, std::uint64_t a3) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextview
     */
    class TextView : public Text
    {
    public:
        /// @brief Creates a new `NSTextView` instance and returns a handle to it.
        explicit TextView(bool using_text_layout_manager);
        /// @brief Creates a new `NSTextView` instance and returns a handle to it.
        explicit TextView(const Rect& frame_rect);
        /// @brief Creates a new `NSTextView` instance and returns a handle to it.
        explicit TextView(const Rect& frame_rect, const TextContainer& container);
        /// @brief Creates a new `NSTextView` instance and returns a handle to it.
        explicit TextView();
        /// @brief Creates a null handle that refers to no native object.
        TextView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextView(Adopt adopt);
        using Responder::valid_requestor_for_send_type;
        using Text::background_color;
        using Text::draws_background;
        using Text::imports_graphics;
        using Text::is_editable;
        using Text::is_field_editor;
        using Text::is_rich_text;
        using Text::is_ruler_visible;
        using Text::is_selectable;
        using Text::set_alignment;
        using Text::set_background_color;
        using Text::set_base_writing_direction;
        using Text::set_draws_background;
        using Text::set_editable;
        using Text::set_field_editor;
        using Text::set_imports_graphics;
        using Text::set_rich_text;
        using Text::set_selectable;
        using Text::set_selected_range;
        using Text::set_uses_font_panel;
        using Text::uses_font_panel;
        using View::candidate_list_touch_bar_item;
        using View::ruler_view;
        using View::set_needs_display_in_rect;
        /**
         * @brief Calls `-[NSTextView alignJustified:]`.
         * @details New Text commands
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void align_justified(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView breakUndoCoalescing]`.
         */
        void break_undo_coalescing() const;
        /**
         * @brief Calls `-[NSTextView changeAttributes:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void change_attributes(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView changeColor:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void change_color(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView changeDocumentBackgroundColor:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void change_document_background_color(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView changeLayoutOrientation:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void change_layout_orientation(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView characterIndexForInsertionAtPoint:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::uint64_t character_index_for_insertion_at_point(const Point& point) const;
        /**
         * @brief Calls `-[NSTextView checkTextInDocument:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_document(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView checkTextInRange:types:options:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_range(const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options) const;
        /**
         * @brief Calls `-[NSTextView checkTextInSelection:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void check_text_in_selection(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView cleanUpAfterDragOperation]`.
         */
        void clean_up_after_drag_operation() const;
        /**
         * @brief Calls `-[NSTextView clickedOnLink:atIndex:]`.
         * @param link Argument converted to the Objective-C parameter of the same role.
         * @param char_index Argument converted to the Objective-C parameter of the same role.
         */
        void clicked_on_link(const Object& link, std::uint64_t char_index) const;
        /**
         * @brief Calls `-[NSTextView complete:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void complete(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView completionsForPartialWordRange:indexOfSelectedItem:]`.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> completions_for_partial_word_range(const Range& char_range, std::int64_t* index) const;
        /**
         * @brief Calls `-[NSTextView didChangeText]`.
         */
        void did_change_text() const;
        /**
         * @brief Calls `-[NSTextView dragImageForSelectionWithEvent:origin:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param origin Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image drag_image_for_selection_with_event(const Event& event, Point* origin) const;
        /**
         * @brief Calls `-[NSTextView dragOperationForDraggingInfo:type:]`.
         * @param drag_info Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        DragOperation drag_operation_for_dragging_info(const Object& drag_info, const std::string& type) const;
        /**
         * @brief Calls `-[NSTextView dragSelectionWithEvent:offset:slideBack:]`.
         * @param event Argument converted to the Objective-C parameter of the same role.
         * @param mouse_offset Argument converted to the Objective-C parameter of the same role.
         * @param slide_back Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool drag_selection_with_event(const Event& event, const Size& mouse_offset, bool slide_back) const;
        /**
         * @brief Calls `-[NSTextView drawInsertionPointInRect:color:turnedOn:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void draw_insertion_point_in_rect(const Rect& rect, const Color& color, bool flag) const;
        /**
         * @brief Calls `-[NSTextView drawTextHighlightBackgroundForTextRange:origin:]`.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @param origin Argument converted to the Objective-C parameter of the same role.
         */
        void draw_text_highlight_background_for_text_range(const TextRange& text_range, const Point& origin) const;
        /**
         * @brief Calls `-[NSTextView drawViewBackgroundInRect:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_view_background_in_rect(const Rect& rect) const;
        /**
         * @brief Calls `+[NSTextView fieldEditor]`.
         * @return The converted Objective-C result.
         */
        static TextView field_editor();
        /**
         * @brief Calls `-[NSTextView handleTextCheckingResults:forRange:types:options:orthography:wordCount:]`.
         * @param results Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param checking_types Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param orthography Argument converted to the Objective-C parameter of the same role.
         * @param word_count Argument converted to the Objective-C parameter of the same role.
         */
        void handle_text_checking_results(const std::vector<TextCheckingResult>& results, const Range& range, std::uint64_t checking_types, const std::map<std::string, Object>& options, const Orthography& orthography, std::int64_t word_count) const;
        /**
         * @brief Calls `-[NSTextView highlight:]`.
         * @details An action for toggling 'NSTextHighlightStyleAttributeName' in the receiver’s selected range. The sender should be a menu item with a 'representedObject' of type ('NSTextHighlightColorScheme').
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void highlight(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView insertCompletion:forPartialWordRange:movement:isFinal:]`.
         * @param word Argument converted to the Objective-C parameter of the same role.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @param movement Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void insert_completion(const std::string& word, const Range& char_range, std::int64_t movement, bool flag) const;
        /**
         * @brief Calls `-[NSTextView invalidateTextContainerOrigin]`.
         */
        void invalidate_text_container_origin() const;
        /**
         * @brief Calls `-[NSTextView loosenKerning:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void loosen_kerning(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView lowerBaseline:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void lower_baseline(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontLinkPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_link_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontListPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_list_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontSharingServicePicker:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_sharing_service_picker(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontSpacingPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_spacing_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontSubstitutionsPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_substitutions_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView orderFrontTablePanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void order_front_table_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView outline:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void outline(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView pasteAsPlainText:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void paste_as_plain_text(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView pasteAsRichText:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void paste_as_rich_text(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView performFindPanelAction:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void perform_find_panel_action(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView performValidatedReplacementInRange:withAttributedString:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param attributed_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool perform_validated_replacement_in_range(const Range& range, const AttributedString& attributed_string) const;
        /**
         * @brief Calls `-[NSTextView preferredPasteboardTypeFromArray:restrictedToTypesFromArray:]`.
         * @param available_types Argument converted to the Objective-C parameter of the same role.
         * @param allowed_types Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string preferred_pasteboard_type_from_array(const std::vector<std::string>& available_types, const std::vector<std::string>& allowed_types) const;
        /**
         * @brief Calls `-[NSTextView quickLookPreviewableItemsInRanges:]`.
         * @param ranges Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> quick_look_previewable_items_in_ranges(const std::vector<Value>& ranges) const;
        /**
         * @brief Calls `-[NSTextView raiseBaseline:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void raise_baseline(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView readSelectionFromPasteboard:]`.
         * @param pboard Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool read_selection_from_pasteboard(const Pasteboard& pboard) const;
        /**
         * @brief Calls `-[NSTextView readSelectionFromPasteboard:type:]`.
         * @param pboard Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool read_selection_from_pasteboard(const Pasteboard& pboard, const std::string& type) const;
        /**
         * @brief Calls `+[NSTextView registerForServices]`.
         */
        static void register_for_services();
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView registerTextAttachmentViewProviderReusePolicy:forTextAttachmentViewProviderType:]`.
         * @details Register the NSTextAttachmentViewProviderReusePolicy for all instances of a particular subclass of NSTextAttachmentViewProvider.
         * @param policy Argument converted to the Objective-C parameter of the same role.
         * @param view_provider_type Argument converted to the Objective-C parameter of the same role.
         */
        void register_text_attachment_view_provider_reuse_policy(TextAttachmentViewProviderReusePolicy policy, const std::string& view_provider_type) const;
#endif

        /**
         * @brief Calls `-[NSTextView replaceTextContainer:]`.
         * @param new_container Argument converted to the Objective-C parameter of the same role.
         */
        void replace_text_container(const TextContainer& new_container) const;
        /**
         * @brief Calls `-[NSTextView rulerView:didAddMarker:]`.
         * @param ruler Argument converted to the Objective-C parameter of the same role.
         * @param marker Argument converted to the Objective-C parameter of the same role.
         */
        void ruler_view(const RulerView& ruler, const RulerMarker& marker) const;
        /**
         * @brief Calls `-[NSTextView rulerView:handleMouseDown:]`.
         * @param ruler Argument converted to the Objective-C parameter of the same role.
         * @param event Argument converted to the Objective-C parameter of the same role.
         */
        void ruler_view(const RulerView& ruler, const Event& event) const;
        /**
         * @brief Calls `-[NSTextView rulerView:willAddMarker:atLocation:]`.
         * @param ruler Argument converted to the Objective-C parameter of the same role.
         * @param marker Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double ruler_view(const RulerView& ruler, const RulerMarker& marker, double location) const;
        /**
         * @brief Calls `+[NSTextView scrollableDocumentContentTextView]`.
         * @return The converted Objective-C result.
         */
        static ScrollView scrollable_document_content_text_view();
        /**
         * @brief Calls `+[NSTextView scrollablePlainDocumentContentTextView]`.
         * @return The converted Objective-C result.
         */
        static ScrollView scrollable_plain_document_content_text_view();
        /**
         * @brief Calls `+[NSTextView scrollableTextView]`.
         * @return The converted Objective-C result.
         */
        static ScrollView scrollable_text_view();
        /**
         * @brief Calls `-[NSTextView selectionRangeForProposedRange:granularity:]`.
         * @param proposed_char_range Argument converted to the Objective-C parameter of the same role.
         * @param granularity Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range selection_range_for_proposed_range(const Range& proposed_char_range, SelectionGranularity granularity) const;
        /**
         * @brief Calls `-[NSTextView setAlignment:range:]`.
         * @param alignment Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void set_alignment(TextAlignment alignment, const Range& range) const;
        /**
         * @brief Calls `-[NSTextView setBaseWritingDirection:range:]`.
         * @param writing_direction Argument converted to the Objective-C parameter of the same role.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void set_base_writing_direction(WritingDirection writing_direction, const Range& range) const;
        /**
         * @brief Calls `-[NSTextView setConstrainedFrameSize:]`.
         * @param desired_size Argument converted to the Objective-C parameter of the same role.
         */
        void set_constrained_frame_size(const Size& desired_size) const;
        /**
         * @brief Calls `-[NSTextView setLayoutOrientation:]`.
         * @param orientation Argument converted to the Objective-C parameter of the same role.
         */
        void set_layout_orientation(TextLayoutOrientation orientation) const;
        /**
         * @brief Calls `-[NSTextView setNeedsDisplayInRect:avoidAdditionalLayout:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_needs_display_in_rect(const Rect& rect, bool flag) const;
        /**
         * @brief Calls `-[NSTextView setSelectedRange:]`.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_range(const Range& char_range) const;
        /**
         * @brief Calls `-[NSTextView setSelectedRange:affinity:stillSelecting:]`.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         * @param affinity Argument converted to the Objective-C parameter of the same role.
         * @param still_selecting_flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_range(const Range& char_range, SelectionAffinity affinity, bool still_selecting_flag) const;
        /**
         * @brief Calls `-[NSTextView setSelectedRanges:affinity:stillSelecting:]`.
         * @param ranges Argument converted to the Objective-C parameter of the same role.
         * @param affinity Argument converted to the Objective-C parameter of the same role.
         * @param still_selecting_flag Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_ranges(const std::vector<Value>& ranges, SelectionAffinity affinity, bool still_selecting_flag) const;
        /**
         * @brief Calls `-[NSTextView setSpellingState:range:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         */
        void set_spelling_state(std::int64_t value, const Range& char_range) const;
        /**
         * @brief Calls `-[NSTextView shouldChangeTextInRange:replacementString:]`.
         * @param affected_char_range Argument converted to the Objective-C parameter of the same role.
         * @param replacement_string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool should_change_text_in_range(const Range& affected_char_range, const std::string& replacement_string) const;
        /**
         * @brief Calls `-[NSTextView shouldChangeTextInRanges:replacementStrings:]`.
         * @param affected_ranges Argument converted to the Objective-C parameter of the same role.
         * @param replacement_strings Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool should_change_text_in_ranges(const std::vector<Value>& affected_ranges, const std::vector<std::string>& replacement_strings) const;
        /**
         * @brief Calls `-[NSTextView showFindIndicatorForRange:]`.
         * @param char_range Argument converted to the Objective-C parameter of the same role.
         */
        void show_find_indicator_for_range(const Range& char_range) const;
        /**
         * @brief Calls `-[NSTextView smartDeleteRangeForProposedRange:]`.
         * @param proposed_char_range Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Range smart_delete_range_for_proposed_range(const Range& proposed_char_range) const;
        /**
         * @brief Calls `-[NSTextView smartInsertAfterStringForString:replacingRange:]`.
         * @param paste_string Argument converted to the Objective-C parameter of the same role.
         * @param char_range_to_replace Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string smart_insert_after_string_for_string(const std::string& paste_string, const Range& char_range_to_replace) const;
        /**
         * @brief Calls `-[NSTextView smartInsertBeforeStringForString:replacingRange:]`.
         * @param paste_string Argument converted to the Objective-C parameter of the same role.
         * @param char_range_to_replace Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string smart_insert_before_string_for_string(const std::string& paste_string, const Range& char_range_to_replace) const;
        /**
         * @brief Calls `-[NSTextView smartInsertForString:replacingRange:beforeString:afterString:]`.
         * @param paste_string Argument converted to the Objective-C parameter of the same role.
         * @param char_range_to_replace Argument converted to the Objective-C parameter of the same role.
         * @param before_string Argument converted to the Objective-C parameter of the same role.
         * @param after_string Argument converted to the Objective-C parameter of the same role.
         */
        void smart_insert_for_string(const std::string& paste_string, const Range& char_range_to_replace, std::string& before_string, std::string& after_string) const;
        /**
         * @brief Calls `-[NSTextView startSpeaking:]`.
         * @details Speech support
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void start_speaking(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView stopSpeaking:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void stop_speaking(const Object& sender) const;
        /**
         * @brief Calls `+[NSTextView textViewUsingTextLayoutManager:]`.
         * @param using_text_layout_manager Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static TextView text_view_using_text_layout_manager(bool using_text_layout_manager);
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView textViewportLayoutController:configureRenderingSurfaceForTextLayoutFragment:]`.
         * @details 'NSTextViewportLayoutControllerDelegate' method that the framework calls when the layout controller lays out a text layout fragment in the UI. Requires a call to super.
         * @param text_viewport_layout_controller Argument converted to the Objective-C parameter of the same role.
         * @param text_layout_fragment Argument converted to the Objective-C parameter of the same role.
         */
        void text_viewport_layout_controller(const TextViewportLayoutController& text_viewport_layout_controller, const TextLayoutFragment& text_layout_fragment) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView textViewportLayoutControllerDidLayout:]`.
         * @details 'NSTextViewportLayoutControllerDelegate' method that the framework calls when the text viewport layout controller finishes its layout process. Requires a call to super.
         * @param text_viewport_layout_controller Argument converted to the Objective-C parameter of the same role.
         */
        void text_viewport_layout_controller_did_layout(const TextViewportLayoutController& text_viewport_layout_controller) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView textViewportLayoutControllerReceivedSetNeedsLayout:]`.
         * @details 'NSTextViewportLayoutControllerDelegate' method that the framework calls when the text viewport layout controller receives a 'setNeedsLayout' call. Requires a call to super.
         * @param text_viewport_layout_controller Argument converted to the Objective-C parameter of the same role.
         */
        void text_viewport_layout_controller_received_set_needs_layout(const TextViewportLayoutController& text_viewport_layout_controller) const;
#endif

#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView textViewportLayoutControllerWillLayout:]`.
         * @details 'NSTextViewportLayoutControllerDelegate' method that the framework calls when the text viewport layout controller starts its layout process. Requires a call to super.
         * @param text_viewport_layout_controller Argument converted to the Objective-C parameter of the same role.
         */
        void text_viewport_layout_controller_will_layout(const TextViewportLayoutController& text_viewport_layout_controller) const;
#endif

        /**
         * @brief Calls `-[NSTextView tightenKerning:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void tighten_kerning(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticDashSubstitution:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_dash_substitution(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticDataDetection:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_data_detection(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticLinkDetection:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_link_detection(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticQuoteSubstitution:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_quote_substitution(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticSpellingCorrection:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_spelling_correction(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticTextCompletion:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_text_completion(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleAutomaticTextReplacement:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_automatic_text_replacement(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleContinuousSpellChecking:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_continuous_spell_checking(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleGrammarChecking:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_grammar_checking(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleQuickLookPreviewPanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_quick_look_preview_panel(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView toggleSmartInsertDelete:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_smart_insert_delete(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView turnOffKerning:]`.
         * @details New Font menu commands
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void turn_off_kerning(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView turnOffLigatures:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void turn_off_ligatures(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView updateCandidates]`.
         */
        void update_candidates() const;
        /**
         * @brief Calls `-[NSTextView updateDragTypeRegistration]`.
         */
        void update_drag_type_registration() const;
        /**
         * @brief Calls `-[NSTextView updateFontPanel]`.
         */
        void update_font_panel() const;
        /**
         * @brief Calls `-[NSTextView updateInsertionPointStateAndRestartTimer:]`.
         * @param restart_flag Argument converted to the Objective-C parameter of the same role.
         */
        void update_insertion_point_state_and_restart_timer(bool restart_flag) const;
        /**
         * @brief Calls `-[NSTextView updateQuickLookPreviewPanel]`.
         */
        void update_quick_look_preview_panel() const;
        /**
         * @brief Calls `-[NSTextView updateRuler]`.
         * @details Especially for subclassers
         */
        void update_ruler() const;
        /**
         * @brief Calls `-[NSTextView updateTextTouchBarItems]`.
         */
        void update_text_touch_bar_items() const;
        /**
         * @brief Calls `-[NSTextView updateTouchBarItemIdentifiers]`.
         */
        void update_touch_bar_item_identifiers() const;
        /**
         * @brief Calls `-[NSTextView useAllLigatures:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void use_all_ligatures(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView useStandardKerning:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void use_standard_kerning(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView useStandardLigatures:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void use_standard_ligatures(const Object& sender) const;
        /**
         * @brief Calls `-[NSTextView validRequestorForSendType:returnType:]`.
         * @param send_type Argument converted to the Objective-C parameter of the same role.
         * @param return_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object valid_requestor_for_send_type(const std::string& send_type, const std::string& return_type) const;
#ifdef COCOON_MACOS_27
        /**
         * @brief Calls `-[NSTextView viewportBoundsForTextViewportLayoutController:]`.
         * @details 'NSTextViewportLayoutControllerDelegate' method that the framework calls to request the current viewport, which is the view visible bounds plus the overdraw area. Requires a call to super.
         * @param text_viewport_layout_controller Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect viewport_bounds_for_text_viewport_layout_controller(const TextViewportLayoutController& text_viewport_layout_controller) const;
#endif

        /**
         * @brief Calls `-[NSTextView writeSelectionToPasteboard:type:]`.
         * @param pboard Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool write_selection_to_pasteboard(const Pasteboard& pboard, const std::string& type) const;
        /**
         * @brief Calls `-[NSTextView writeSelectionToPasteboard:types:]`.
         * @param pboard Argument converted to the Objective-C parameter of the same role.
         * @param types Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool write_selection_to_pasteboard(const Pasteboard& pboard, const std::vector<std::string>& types) const;
        /**
         * @brief Returns the `acceptableDragTypes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> acceptable_drag_types() const;
        /**
         * @brief Returns the `acceptsGlyphInfo` property of `NSTextView`.
         * @details Glyph info support
         * @return The converted Objective-C result.
         */
        bool accepts_glyph_info() const;
        /**
         * @brief Sets the `acceptsGlyphInfo` property of `NSTextView`.
         * @details Glyph info support
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accepts_glyph_info(bool value) const;
        /**
         * @brief Returns the `allowedInputSourceLocales` property of `NSTextView`.
         * @details Returns an array of locale identifiers representing keyboard input sources allowed to be enabled when the receiver has the keyboard focus.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> allowed_input_source_locales() const;
        /**
         * @brief Sets the `allowedInputSourceLocales` property of `NSTextView`.
         * @details Returns an array of locale identifiers representing keyboard input sources allowed to be enabled when the receiver has the keyboard focus.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allowed_input_source_locales(const std::vector<std::string>& value) const;
        /**
         * @brief Returns the `allowedWritingToolsResultOptions` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        WritingToolsResultOptions allowed_writing_tools_result_options() const;
        /**
         * @brief Sets the `allowedWritingToolsResultOptions` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allowed_writing_tools_result_options(WritingToolsResultOptions value) const;
        /**
         * @brief Returns the `allowsCharacterPickerTouchBarItem` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool allows_character_picker_touch_bar_item() const;
        /**
         * @brief Sets the `allowsCharacterPickerTouchBarItem` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_character_picker_touch_bar_item(bool value) const;
        /**
         * @brief Returns the `allowsDocumentBackgroundColorChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool allows_document_background_color_change() const;
        /**
         * @brief Sets the `allowsDocumentBackgroundColorChange` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_document_background_color_change(bool value) const;
        /**
         * @brief Returns the `allowsImageEditing` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool allows_image_editing() const;
        /**
         * @brief Sets the `allowsImageEditing` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_image_editing(bool value) const;
        /**
         * @brief Returns the `allowsUndo` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool allows_undo() const;
        /**
         * @brief Sets the `allowsUndo` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_undo(bool value) const;
        /**
         * @brief Returns the `automaticDashSubstitutionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_dash_substitution_enabled() const;
        /**
         * @brief Sets the `automaticDashSubstitutionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_dash_substitution_enabled(bool value) const;
        /**
         * @brief Returns the `automaticDataDetectionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_data_detection_enabled() const;
        /**
         * @brief Sets the `automaticDataDetectionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_data_detection_enabled(bool value) const;
        /**
         * @brief Returns the `automaticLinkDetectionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_link_detection_enabled() const;
        /**
         * @brief Sets the `automaticLinkDetectionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_link_detection_enabled(bool value) const;
        /**
         * @brief Returns the `automaticQuoteSubstitutionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_quote_substitution_enabled() const;
        /**
         * @brief Sets the `automaticQuoteSubstitutionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_quote_substitution_enabled(bool value) const;
        /**
         * @brief Returns the `automaticSpellingCorrectionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_spelling_correction_enabled() const;
        /**
         * @brief Sets the `automaticSpellingCorrectionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_spelling_correction_enabled(bool value) const;
        /**
         * @brief Returns the `automaticTextCompletionEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_text_completion_enabled() const;
        /**
         * @brief Sets the `automaticTextCompletionEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_text_completion_enabled(bool value) const;
        /**
         * @brief Returns the `automaticTextReplacementEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_automatic_text_replacement_enabled() const;
        /**
         * @brief Sets the `automaticTextReplacementEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatic_text_replacement_enabled(bool value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `candidateListTouchBarItem` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        CandidateListTouchBarItemBase candidate_list_touch_bar_item() const;
        /**
         * @brief Returns the `coalescingUndo` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_coalescing_undo() const;
        /**
         * @brief Returns the `continuousSpellCheckingEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_continuous_spell_checking_enabled() const;
        /**
         * @brief Sets the `continuousSpellCheckingEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_continuous_spell_checking_enabled(bool value) const;
        /**
         * @brief Returns the `defaultParagraphStyle` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        ParagraphStyle default_paragraph_style() const;
        /**
         * @brief Sets the `defaultParagraphStyle` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_default_paragraph_style(const ParagraphStyle& value) const;
        /**
         * @brief Returns the `displaysLinkToolTips` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool displays_link_tool_tips() const;
        /**
         * @brief Sets the `displaysLinkToolTips` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_displays_link_tool_tips(bool value) const;
        /**
         * @brief Returns the `drawsBackground` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool draws_background() const;
        /**
         * @brief Sets the `drawsBackground` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_draws_background(bool value) const;
        /**
         * @brief Returns the `editable` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_editable() const;
        /**
         * @brief Sets the `editable` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_editable(bool value) const;
        /**
         * @brief Returns the `enabledTextCheckingTypes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::uint64_t enabled_text_checking_types() const;
        /**
         * @brief Sets the `enabledTextCheckingTypes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_enabled_text_checking_types(std::uint64_t value) const;
        /**
         * @brief Returns the `fieldEditor` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_field_editor() const;
        /**
         * @brief Sets the `fieldEditor` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_field_editor(bool value) const;
        /**
         * @brief Returns the `grammarCheckingEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_grammar_checking_enabled() const;
        /**
         * @brief Sets the `grammarCheckingEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_grammar_checking_enabled(bool value) const;
        /**
         * @brief Returns the `importsGraphics` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool imports_graphics() const;
        /**
         * @brief Sets the `importsGraphics` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_imports_graphics(bool value) const;
        /**
         * @brief Returns the `incrementalSearchingEnabled` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_incremental_searching_enabled() const;
        /**
         * @brief Sets the `incrementalSearchingEnabled` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_incremental_searching_enabled(bool value) const;
        /**
         * @brief Returns the `inlinePredictionType` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextInputTraitType inline_prediction_type() const;
        /**
         * @brief Sets the `inlinePredictionType` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_inline_prediction_type(TextInputTraitType value) const;
        /**
         * @brief Returns the `insertionPointColor` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Color insertion_point_color() const;
        /**
         * @brief Sets the `insertionPointColor` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_insertion_point_color(const Color& value) const;
        /**
         * @brief Returns the `layoutManager` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        LayoutManager layout_manager() const;
        /**
         * @brief Returns the `linkTextAttributes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> link_text_attributes() const;
        /**
         * @brief Sets the `linkTextAttributes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_link_text_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `markedTextAttributes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> marked_text_attributes() const;
        /**
         * @brief Sets the `markedTextAttributes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_marked_text_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `mathExpressionCompletionType` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextInputTraitType math_expression_completion_type() const;
        /**
         * @brief Sets the `mathExpressionCompletionType` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_math_expression_completion_type(TextInputTraitType value) const;
        /**
         * @brief Returns the `rangeForUserCharacterAttributeChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Range range_for_user_character_attribute_change() const;
        /**
         * @brief Returns the `rangeForUserCompletion` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Range range_for_user_completion() const;
        /**
         * @brief Returns the `rangeForUserParagraphAttributeChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Range range_for_user_paragraph_attribute_change() const;
        /**
         * @brief Returns the `rangeForUserTextChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Range range_for_user_text_change() const;
        /**
         * @brief Returns the `rangesForUserCharacterAttributeChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<Value> ranges_for_user_character_attribute_change() const;
        /**
         * @brief Returns the `rangesForUserParagraphAttributeChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<Value> ranges_for_user_paragraph_attribute_change() const;
        /**
         * @brief Returns the `rangesForUserTextChange` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<Value> ranges_for_user_text_change() const;
        /**
         * @brief Returns the `readablePasteboardTypes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> readable_pasteboard_types() const;
        /**
         * @brief Returns the `richText` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_rich_text() const;
        /**
         * @brief Sets the `richText` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rich_text(bool value) const;
        /**
         * @brief Returns the `rulerVisible` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_ruler_visible() const;
        /**
         * @brief Sets the `rulerVisible` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_ruler_visible(bool value) const;
        /**
         * @brief Returns the `selectable` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_selectable() const;
        /**
         * @brief Sets the `selectable` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selectable(bool value) const;
        /**
         * @brief Returns the `selectedRanges` property of `NSTextView`.
         * @details Selected/Marked range
         * @return The converted Objective-C result.
         */
        std::vector<Value> selected_ranges() const;
        /**
         * @brief Sets the `selectedRanges` property of `NSTextView`.
         * @details Selected/Marked range
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_ranges(const std::vector<Value>& value) const;
        /**
         * @brief Returns the `selectedTextAttributes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> selected_text_attributes() const;
        /**
         * @brief Sets the `selectedTextAttributes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected_text_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `selectionAffinity` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        SelectionAffinity selection_affinity() const;
        /**
         * @brief Returns the `selectionGranularity` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        SelectionGranularity selection_granularity() const;
        /**
         * @brief Sets the `selectionGranularity` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selection_granularity(SelectionGranularity value) const;
        /**
         * @brief Returns the `shouldDrawInsertionPoint` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool should_draw_insertion_point() const;
        /**
         * @brief Returns the `smartInsertDeleteEnabled` property of `NSTextView`.
         * @details Smart copy/paste/delete/substitution support
         * @return The converted Objective-C result.
         */
        bool smart_insert_delete_enabled() const;
        /**
         * @brief Sets the `smartInsertDeleteEnabled` property of `NSTextView`.
         * @details Smart copy/paste/delete/substitution support
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_smart_insert_delete_enabled(bool value) const;
        /**
         * @brief Returns the `spellCheckerDocumentTag` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::int64_t spell_checker_document_tag() const;
        /**
         * @brief Returns the `stronglyReferencesTextStorage` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        static bool strongly_references_text_storage();
        /**
         * @brief Returns the `textContainer` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextContainer text_container() const;
        /**
         * @brief Sets the `textContainer` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_container(const TextContainer& value) const;
        /**
         * @brief Returns the `textContainerInset` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Size text_container_inset() const;
        /**
         * @brief Sets the `textContainerInset` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_container_inset(const Size& value) const;
        /**
         * @brief Returns the `textContainerOrigin` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        Point text_container_origin() const;
        /**
         * @brief Returns the `textContentStorage` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextContentStorage text_content_storage() const;
        /**
         * @brief Returns the `textHighlightAttributes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> text_highlight_attributes() const;
        /**
         * @brief Sets the `textHighlightAttributes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_highlight_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `textLayoutManager` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextLayoutManager text_layout_manager() const;
        /**
         * @brief Returns the `textStorage` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        TextStorage text_storage() const;
        /**
         * @brief Returns the `typingAttributes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> typing_attributes() const;
        /**
         * @brief Sets the `typingAttributes` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_typing_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `usesAdaptiveColorMappingForDarkAppearance` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_adaptive_color_mapping_for_dark_appearance() const;
        /**
         * @brief Sets the `usesAdaptiveColorMappingForDarkAppearance` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_adaptive_color_mapping_for_dark_appearance(bool value) const;
        /**
         * @brief Returns the `usesFindBar` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_find_bar() const;
        /**
         * @brief Sets the `usesFindBar` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_find_bar(bool value) const;
        /**
         * @brief Returns the `usesFindPanel` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_find_panel() const;
        /**
         * @brief Sets the `usesFindPanel` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_find_panel(bool value) const;
        /**
         * @brief Returns the `usesFontPanel` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_font_panel() const;
        /**
         * @brief Sets the `usesFontPanel` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_font_panel(bool value) const;
        /**
         * @brief Returns the `usesInspectorBar` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_inspector_bar() const;
        /**
         * @brief Sets the `usesInspectorBar` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_inspector_bar(bool value) const;
        /**
         * @brief Returns the `usesRolloverButtonForSelection` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool uses_rollover_button_for_selection() const;
        /**
         * @brief Sets the `usesRolloverButtonForSelection` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_rollover_button_for_selection(bool value) const;
        /**
         * @brief Returns the `usesRuler` property of `NSTextView`.
         * @details Other NSTextView methods
         * @return The converted Objective-C result.
         */
        bool uses_ruler() const;
        /**
         * @brief Sets the `usesRuler` property of `NSTextView`.
         * @details Other NSTextView methods
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_ruler(bool value) const;
        /**
         * @brief Returns the `writablePasteboardTypes` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> writable_pasteboard_types() const;
        /**
         * @brief Returns the `writingToolsActive` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        bool is_writing_tools_active() const;
        /**
         * @brief Returns the `writingToolsBehavior` property of `NSTextView`.
         * @return The converted Objective-C result.
         */
        WritingToolsBehavior writing_tools_behavior() const;
        /**
         * @brief Sets the `writingToolsBehavior` property of `NSTextView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_writing_tools_behavior(WritingToolsBehavior value) const;
        /// @brief Signal for the delegate/data-source method behind `clicked_on_link_at_index`; connect a callback with `clicked_on_link_at_index().connect(...)`.
        Signal<TextView, bool(Object, std::uint64_t)> clicked_on_link_at_index() const
        {
            return Signal<TextView, bool(Object, std::uint64_t)>(handle(), "clicked_on_link_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `clicked_on_cell_in_rect_at_index`; connect a callback with `clicked_on_cell_in_rect_at_index().connect(...)`.
        Signal<TextView, void(Object, Rect, std::uint64_t)> clicked_on_cell_in_rect_at_index() const
        {
            return Signal<TextView, void(Object, Rect, std::uint64_t)>(handle(), "clicked_on_cell_in_rect_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `double_clicked_on_cell_in_rect_at_index`; connect a callback with `double_clicked_on_cell_in_rect_at_index().connect(...)`.
        Signal<TextView, void(Object, Rect, std::uint64_t)> double_clicked_on_cell_in_rect_at_index() const
        {
            return Signal<TextView, void(Object, Rect, std::uint64_t)>(handle(), "double_clicked_on_cell_in_rect_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `dragged_cell_in_rect_event_at_index`; connect a callback with `dragged_cell_in_rect_event_at_index().connect(...)`.
        Signal<TextView, void(Object, Rect, Event, std::uint64_t)> dragged_cell_in_rect_event_at_index() const
        {
            return Signal<TextView, void(Object, Rect, Event, std::uint64_t)>(handle(), "dragged_cell_in_rect_event_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `writable_pasteboard_types_for_cell_at_index`; connect a callback with `writable_pasteboard_types_for_cell_at_index().connect(...)`.
        Signal<TextView, std::vector<std::string>(Object, std::uint64_t)> writable_pasteboard_types_for_cell_at_index() const
        {
            return Signal<TextView, std::vector<std::string>(Object, std::uint64_t)>(handle(), "writable_pasteboard_types_for_cell_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `write_cell_at_index_to_pasteboard_type`; connect a callback with `write_cell_at_index_to_pasteboard_type().connect(...)`.
        Signal<TextView, bool(Object, std::uint64_t, Pasteboard, std::string)> write_cell_at_index_to_pasteboard_type() const
        {
            return Signal<TextView, bool(Object, std::uint64_t, Pasteboard, std::string)>(handle(), "write_cell_at_index_to_pasteboard_type");
        }
        /// @brief Signal for the delegate/data-source method behind `will_change_selection_from_character_range_to_character_range`; connect a callback with `will_change_selection_from_character_range_to_character_range().connect(...)`.
        Signal<TextView, Range(Range, Range)> will_change_selection_from_character_range_to_character_range() const
        {
            return Signal<TextView, Range(Range, Range)>(handle(), "will_change_selection_from_character_range_to_character_range");
        }
        /// @brief Signal for the delegate/data-source method behind `will_change_selection_from_character_ranges_to_character_ranges`; connect a callback with `will_change_selection_from_character_ranges_to_character_ranges().connect(...)`.
        Signal<TextView, std::vector<Value>(std::vector<Value>, std::vector<Value>)> will_change_selection_from_character_ranges_to_character_ranges() const
        {
            return Signal<TextView, std::vector<Value>(std::vector<Value>, std::vector<Value>)>(handle(), "will_change_selection_from_character_ranges_to_character_ranges");
        }
        /// @brief Signal for the delegate/data-source method behind `should_change_text_in_ranges_replacement_strings`; connect a callback with `should_change_text_in_ranges_replacement_strings().connect(...)`.
        Signal<TextView, bool(std::vector<Value>, std::vector<std::string>)> should_change_text_in_ranges_replacement_strings() const
        {
            return Signal<TextView, bool(std::vector<Value>, std::vector<std::string>)>(handle(), "should_change_text_in_ranges_replacement_strings");
        }
        /// @brief Signal for the delegate/data-source method behind `should_change_typing_attributes_to_attributes`; connect a callback with `should_change_typing_attributes_to_attributes().connect(...)`.
        Signal<TextView, std::map<std::string, Object>(std::map<std::string, Object>, std::map<std::string, Object>)> should_change_typing_attributes_to_attributes() const
        {
            return Signal<TextView, std::map<std::string, Object>(std::map<std::string, Object>, std::map<std::string, Object>)>(handle(), "should_change_typing_attributes_to_attributes");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_selection`; connect a callback with `did_change_selection().connect(...)`.
        Signal<TextView, void(Notification)> did_change_selection() const
        {
            return Signal<TextView, void(Notification)>(handle(), "did_change_selection");
        }
        /// @brief Signal for the delegate/data-source method behind `did_change_typing_attributes`; connect a callback with `did_change_typing_attributes().connect(...)`.
        Signal<TextView, void(Notification)> did_change_typing_attributes() const
        {
            return Signal<TextView, void(Notification)>(handle(), "did_change_typing_attributes");
        }
        /// @brief Signal for the delegate/data-source method behind `will_display_tool_tip_for_character_at_index`; connect a callback with `will_display_tool_tip_for_character_at_index().connect(...)`.
        Signal<TextView, std::string(std::string, std::uint64_t)> will_display_tool_tip_for_character_at_index() const
        {
            return Signal<TextView, std::string(std::string, std::uint64_t)>(handle(), "will_display_tool_tip_for_character_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `completions_for_partial_word_range_index_of_selected_item`; connect a callback with `completions_for_partial_word_range_index_of_selected_item().connect(...)`.
        Signal<TextView, std::vector<std::string>(std::vector<std::string>, Range, std::int64_t*)> completions_for_partial_word_range_index_of_selected_item() const
        {
            return Signal<TextView, std::vector<std::string>(std::vector<std::string>, Range, std::int64_t*)>(handle(), "completions_for_partial_word_range_index_of_selected_item");
        }
        /// @brief Signal for the delegate/data-source method behind `should_change_text_in_range_replacement_string`; connect a callback with `should_change_text_in_range_replacement_string().connect(...)`.
        Signal<TextView, bool(Range, std::string)> should_change_text_in_range_replacement_string() const
        {
            return Signal<TextView, bool(Range, std::string)>(handle(), "should_change_text_in_range_replacement_string");
        }
        /// @brief Signal for the delegate/data-source method behind `do_command_by_selector`; connect a callback with `do_command_by_selector().connect(...)`.
        Signal<TextView, bool(std::string)> do_command_by_selector() const
        {
            return Signal<TextView, bool(std::string)>(handle(), "do_command_by_selector");
        }
        /// @brief Signal for the delegate/data-source method behind `should_set_spelling_state_range`; connect a callback with `should_set_spelling_state_range().connect(...)`.
        Signal<TextView, std::int64_t(std::int64_t, Range)> should_set_spelling_state_range() const
        {
            return Signal<TextView, std::int64_t(std::int64_t, Range)>(handle(), "should_set_spelling_state_range");
        }
        /// @brief Signal for the delegate/data-source method behind `menu_for_event_at_index`; connect a callback with `menu_for_event_at_index().connect(...)`.
        Signal<TextView, Menu(Menu, Event, std::uint64_t)> menu_for_event_at_index() const
        {
            return Signal<TextView, Menu(Menu, Event, std::uint64_t)>(handle(), "menu_for_event_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `will_check_text_in_range_options_types`; connect a callback with `will_check_text_in_range_options_types().connect(...)`.
        Signal<TextView, std::map<std::string, Object>(Range, std::map<std::string, Object>, std::uint64_t*)> will_check_text_in_range_options_types() const
        {
            return Signal<TextView, std::map<std::string, Object>(Range, std::map<std::string, Object>, std::uint64_t*)>(handle(), "will_check_text_in_range_options_types");
        }
        /// @brief Signal for the delegate/data-source method behind `did_check_text_in_range_types_options_results_orthography_word_count`; connect a callback with `did_check_text_in_range_types_options_results_orthography_word_count().connect(...)`.
        Signal<TextView, std::vector<TextCheckingResult>(Range, std::uint64_t, std::map<std::string, Object>, std::vector<TextCheckingResult>, Orthography, std::int64_t)> did_check_text_in_range_types_options_results_orthography_word_count() const
        {
            return Signal<TextView, std::vector<TextCheckingResult>(Range, std::uint64_t, std::map<std::string, Object>, std::vector<TextCheckingResult>, Orthography, std::int64_t)>(handle(), "did_check_text_in_range_types_options_results_orthography_word_count");
        }
        /// @brief Signal for the delegate/data-source method behind `u_rl_for_contents_of_text_attachment_at_index`; connect a callback with `u_rl_for_contents_of_text_attachment_at_index().connect(...)`.
        Signal<TextView, URL(TextAttachment, std::uint64_t)> u_rl_for_contents_of_text_attachment_at_index() const
        {
            return Signal<TextView, URL(TextAttachment, std::uint64_t)>(handle(), "u_rl_for_contents_of_text_attachment_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `will_show_sharing_service_picker_for_items`; connect a callback with `will_show_sharing_service_picker_for_items().connect(...)`.
        Signal<TextView, SharingServicePicker(SharingServicePicker, std::vector<Object>)> will_show_sharing_service_picker_for_items() const
        {
            return Signal<TextView, SharingServicePicker(SharingServicePicker, std::vector<Object>)>(handle(), "will_show_sharing_service_picker_for_items");
        }
        /// @brief Signal for the delegate/data-source method behind `undo_manager_for_text_view`; connect a callback with `undo_manager_for_text_view().connect(...)`.
        Signal<TextView, UndoManager()> undo_manager_for_text_view() const
        {
            return Signal<TextView, UndoManager()>(handle(), "undo_manager_for_text_view");
        }
        /// @brief Signal for the delegate/data-source method behind `should_update_touch_bar_item_identifiers`; connect a callback with `should_update_touch_bar_item_identifiers().connect(...)`.
        Signal<TextView, std::vector<std::string>(std::vector<std::string>)> should_update_touch_bar_item_identifiers() const
        {
            return Signal<TextView, std::vector<std::string>(std::vector<std::string>)>(handle(), "should_update_touch_bar_item_identifiers");
        }
        /// @brief Signal for the delegate/data-source method behind `candidates_for_selected_range`; connect a callback with `candidates_for_selected_range().connect(...)`.
        Signal<TextView, std::vector<Object>(Range)> candidates_for_selected_range() const
        {
            return Signal<TextView, std::vector<Object>(Range)>(handle(), "candidates_for_selected_range");
        }
        /// @brief Signal for the delegate/data-source method behind `text_view_candidates_for_selected_range`; connect a callback with `text_view_candidates_for_selected_range().connect(...)`.
        Signal<TextView, std::vector<TextCheckingResult>(std::vector<TextCheckingResult>, Range)> text_view_candidates_for_selected_range() const
        {
            return Signal<TextView, std::vector<TextCheckingResult>(std::vector<TextCheckingResult>, Range)>(handle(), "text_view_candidates_for_selected_range");
        }
        /// @brief Signal for the delegate/data-source method behind `should_select_candidate_at_index`; connect a callback with `should_select_candidate_at_index().connect(...)`.
        Signal<TextView, bool(std::uint64_t)> should_select_candidate_at_index() const
        {
            return Signal<TextView, bool(std::uint64_t)>(handle(), "should_select_candidate_at_index");
        }
        /// @brief Signal for the delegate/data-source method behind `writing_tools_will_begin`; connect a callback with `writing_tools_will_begin().connect(...)`.
        Signal<TextView, void()> writing_tools_will_begin() const
        {
            return Signal<TextView, void()>(handle(), "writing_tools_will_begin");
        }
        /// @brief Signal for the delegate/data-source method behind `writing_tools_did_end`; connect a callback with `writing_tools_did_end().connect(...)`.
        Signal<TextView, void()> writing_tools_did_end() const
        {
            return Signal<TextView, void()>(handle(), "writing_tools_did_end");
        }
        /// @brief Signal for the delegate/data-source method behind `writing_tools_ignored_ranges_in_enclosing_range`; connect a callback with `writing_tools_ignored_ranges_in_enclosing_range().connect(...)`.
        Signal<TextView, std::vector<Value>(Range)> writing_tools_ignored_ranges_in_enclosing_range() const
        {
            return Signal<TextView, std::vector<Value>(Range)>(handle(), "writing_tools_ignored_ranges_in_enclosing_range");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
