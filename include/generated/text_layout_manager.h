#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class OperationQueue;
    class TextContainer;
    class TextContentManager;
    class TextElement;
    class TextLayoutFragment;
    class TextRange;
    class TextSelection;
    class TextSelectionNavigation;
    class TextViewportLayoutController;

    /**
     * @brief C++ handle for the Objective-C class `NSTextLayoutManager` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextLayoutManager text_layout_manager;
     * text_layout_manager.set_layout_queue(cocoon::OperationQueue());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextLayoutManager text_layout_manager{};
     * text_layout_manager.set_layout_queue(cocoon::OperationQueue());
     * auto layout_queue = text_layout_manager.layout_queue();
     * text_layout_manager.set_limits_layout_for_suspicious_contents(true);
     * auto limits_layout_for_suspicious_contents = text_layout_manager.limits_layout_for_suspicious_contents();
     * text_layout_manager.set_resolves_natural_alignment_with_base_writing_direction(true);
     * auto resolves_natural_alignment_with_base_writing_direction = text_layout_manager.resolves_natural_alignment_with_base_writing_direction();
     * text_layout_manager.ensure_layout_for_bounds({{0, 0}, {100, 100}});
     * text_layout_manager.ensure_layout_for_range(cocoon::TextRange());
     * text_layout_manager.invalidate_layout_for_range(cocoon::TextRange());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextlayoutmanager
     */
    class TextLayoutManager : public Object
    {
    public:
        /// @brief Creates a new `NSTextLayoutManager` instance and returns a handle to it.
        explicit TextLayoutManager();
        /// @brief Creates a null handle that refers to no native object.
        TextLayoutManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextLayoutManager(Adopt adopt);
        /**
         * @brief Calls `-[NSTextLayoutManager addRenderingAttribute:value:forTextRange:]`.
         * @param rendering_attribute Argument converted to the Objective-C parameter of the same role.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         */
        void add_rendering_attribute(const std::string& rendering_attribute, const Object& value, const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager ensureLayoutForBounds:]`.
         * @param bounds Argument converted to the Objective-C parameter of the same role.
         */
        void ensure_layout_for_bounds(const Rect& bounds) const;
        /**
         * @brief Calls `-[NSTextLayoutManager ensureLayoutForRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void ensure_layout_for_range(const TextRange& range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager enumerateRenderingAttributesFromLocation:reverse:usingBlock:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param reverse Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_rendering_attributes_from_location(const Object& location, bool reverse, std::function<bool(TextLayoutManager, std::map<std::string, Object>, TextRange)> block) const;
        /**
         * @brief Calls `-[NSTextLayoutManager enumerateTextLayoutFragmentsFromLocation:options:usingBlock:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object enumerate_text_layout_fragments_from_location(const Object& location, TextLayoutFragmentEnumerationOptions options, std::function<bool(TextLayoutFragment)> block) const;
        /**
         * @brief Calls `-[NSTextLayoutManager enumerateTextSegmentsInRange:type:options:usingBlock:]`.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param block Argument converted to the Objective-C parameter of the same role.
         */
        void enumerate_text_segments_in_range(const TextRange& text_range, TextLayoutManagerSegmentType type, TextLayoutManagerSegmentOptions options, std::function<bool(TextRange, Rect, double, TextContainer)> block) const;
        /**
         * @brief Calls `-[NSTextLayoutManager invalidateLayoutForRange:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         */
        void invalidate_layout_for_range(const TextRange& range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager invalidateRenderingAttributesForTextRange:]`.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         */
        void invalidate_rendering_attributes_for_text_range(const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager removeRenderingAttribute:forTextRange:]`.
         * @param rendering_attribute Argument converted to the Objective-C parameter of the same role.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         */
        void remove_rendering_attribute(const std::string& rendering_attribute, const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager renderingAttributesForLink:atLocation:]`.
         * @param link Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> rendering_attributes_for_link(const Object& link, const Object& location) const;
        /**
         * @brief Calls `-[NSTextLayoutManager replaceContentsInRange:withAttributedString:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param attributed_string Argument converted to the Objective-C parameter of the same role.
         */
        void replace_contents_in_range(const TextRange& range, const AttributedString& attributed_string) const;
        /**
         * @brief Calls `-[NSTextLayoutManager replaceContentsInRange:withTextElements:]`.
         * @param range Argument converted to the Objective-C parameter of the same role.
         * @param text_elements Argument converted to the Objective-C parameter of the same role.
         */
        void replace_contents_in_range(const TextRange& range, const std::vector<TextElement>& text_elements) const;
        /**
         * @brief Calls `-[NSTextLayoutManager replaceTextContentManager:]`.
         * @param text_content_manager Argument converted to the Objective-C parameter of the same role.
         */
        void replace_text_content_manager(const TextContentManager& text_content_manager) const;
        /**
         * @brief Calls `-[NSTextLayoutManager setRenderingAttributes:forTextRange:]`.
         * @param rendering_attributes Argument converted to the Objective-C parameter of the same role.
         * @param text_range Argument converted to the Objective-C parameter of the same role.
         */
        void set_rendering_attributes(const std::map<std::string, Object>& rendering_attributes, const TextRange& text_range) const;
        /**
         * @brief Calls `-[NSTextLayoutManager textLayoutFragmentForLocation:]`.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextLayoutFragment text_layout_fragment_for_location(const Object& location) const;
        /**
         * @brief Calls `-[NSTextLayoutManager textLayoutFragmentForPosition:]`.
         * @param position Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        TextLayoutFragment text_layout_fragment_for_position(const Point& position) const;
        /**
         * @brief Returns the `layoutQueue` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        OperationQueue layout_queue() const;
        /**
         * @brief Sets the `layoutQueue` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_layout_queue(const OperationQueue& value) const;
        /**
         * @brief Returns the `limitsLayoutForSuspiciousContents` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        bool limits_layout_for_suspicious_contents() const;
        /**
         * @brief Sets the `limitsLayoutForSuspiciousContents` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_limits_layout_for_suspicious_contents(bool value) const;
        /**
         * @brief Returns the `linkRenderingAttributes` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        static std::map<std::string, Object> link_rendering_attributes();
        /**
         * @brief Returns the `renderingAttributesValidator` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        std::function<void(TextLayoutManager, TextLayoutFragment)> rendering_attributes_validator() const;
        /**
         * @brief Sets the `renderingAttributesValidator` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_rendering_attributes_validator(std::function<void(TextLayoutManager, TextLayoutFragment)> value) const;
        /**
         * @brief Returns the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextLayoutManager`.
         * @details Specifies the behavior for resolving ''NSTextAlignment.natural'' to the visual alignment. When set to ''true'', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is ''true''.
         * @return The converted Objective-C result.
         */
        bool resolves_natural_alignment_with_base_writing_direction() const;
        /**
         * @brief Sets the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextLayoutManager`.
         * @details Specifies the behavior for resolving ''NSTextAlignment.natural'' to the visual alignment. When set to ''true'', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is ''true''.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_resolves_natural_alignment_with_base_writing_direction(bool value) const;
        /**
         * @brief Returns the `textContainer` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        TextContainer text_container() const;
        /**
         * @brief Sets the `textContainer` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_container(const TextContainer& value) const;
        /**
         * @brief Returns the `textContentManager` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        TextContentManager text_content_manager() const;
        /**
         * @brief Returns the `textSelectionNavigation` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        TextSelectionNavigation text_selection_navigation() const;
        /**
         * @brief Sets the `textSelectionNavigation` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_selection_navigation(const TextSelectionNavigation& value) const;
        /**
         * @brief Returns the `textSelections` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        std::vector<TextSelection> text_selections() const;
        /**
         * @brief Sets the `textSelections` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_selections(const std::vector<TextSelection>& value) const;
        /**
         * @brief Returns the `textViewportLayoutController` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        TextViewportLayoutController text_viewport_layout_controller() const;
        /**
         * @brief Returns the `usageBoundsForTextContainer` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        Rect usage_bounds_for_text_container() const;
        /**
         * @brief Returns the `usesFontLeading` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        bool uses_font_leading() const;
        /**
         * @brief Sets the `usesFontLeading` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_font_leading(bool value) const;
        /**
         * @brief Returns the `usesHyphenation` property of `NSTextLayoutManager`.
         * @return The converted Objective-C result.
         */
        bool uses_hyphenation() const;
        /**
         * @brief Sets the `usesHyphenation` property of `NSTextLayoutManager`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_hyphenation(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `text_layout_fragment_for_location_in_text_element`; connect a callback with `text_layout_fragment_for_location_in_text_element().connect(...)`.
        Signal<TextLayoutManager, TextLayoutFragment(Object, TextElement)> text_layout_fragment_for_location_in_text_element() const
        {
            return Signal<TextLayoutManager, TextLayoutFragment(Object, TextElement)>(handle(), "text_layout_fragment_for_location_in_text_element");
        }
        /// @brief Signal for the delegate/data-source method behind `should_break_line_before_location_hyphenating`; connect a callback with `should_break_line_before_location_hyphenating().connect(...)`.
        Signal<TextLayoutManager, bool(Object, bool)> should_break_line_before_location_hyphenating() const
        {
            return Signal<TextLayoutManager, bool(Object, bool)>(handle(), "should_break_line_before_location_hyphenating");
        }
        /// @brief Signal for the delegate/data-source method behind `rendering_attributes_for_link_at_location_default_attributes`; connect a callback with `rendering_attributes_for_link_at_location_default_attributes().connect(...)`.
        Signal<TextLayoutManager, std::map<std::string, Object>(Object, Object, std::map<std::string, Object>)> rendering_attributes_for_link_at_location_default_attributes() const
        {
            return Signal<TextLayoutManager, std::map<std::string, Object>(Object, Object, std::map<std::string, Object>)>(handle(), "rendering_attributes_for_link_at_location_default_attributes");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
