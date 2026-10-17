#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class OperationQueue;
    class TextAttachment;
    class TextAttachmentViewProvider;
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
     * @details The primary class that you use to manage text layout and presentation for custom text displays. 'NSTextLayoutManager' is the centerpiece of the TextKit object network maintaining the layout geometry through an array of ''NSTextContainer'' objects. It lays out results using ''NSTextLayoutFragment'' and ''NSTextElement'' objects vended from a ''NSTextContentManager'' that participates in the content layout process.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextLayoutManager text_layout_manager;
     * text_layout_manager.set_layout_queue(cocoon::OperationQueue());
     * text_layout_manager.cache_text_attachment_view_provider_for_text_attachment().connect([](auto&&...) {});
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
     * text_layout_manager.cache_text_attachment_view_provider_for_text_attachment().connect([](cocoon::TextAttachmentViewProvider a0, cocoon::TextAttachment a1) {});
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
     * @details Adds a rendering attribute for the range you specify. Passing 'nil' for value indicates overriding the specified attribute by removing it from the final attributes passed to the layout and rendering engine. This is a convenience over ''setRenderingAttributes:forTextRange:''. - Parameters: - renderingAttribute: The \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/key> attribute to add. - value: The attribute value, or 'nil' to remove. - textRange: The range to apply the attribute to.
     * @param rendering_attribute Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param text_range Argument converted to the Objective-C parameter of the same role.
     */
        void add_rendering_attribute(const std::string& rendering_attribute, const Object& value, const TextRange& text_range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager ensureLayoutForBounds:]`.
     * @details Performs the layout for filling bounds inside the last text container. - Parameters: - bounds: A \<doc://com.apple.documentation/documentation/corefoundation/cgrect> that describes the layout bounds.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_bounds(const Rect& bounds) const;
        /**
     * @brief Calls `-[NSTextLayoutManager ensureLayoutForRange:]`.
     * @details Performs the layout for the specified text range. - Parameters: - range: The text range to lay out.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void ensure_layout_for_range(const TextRange& range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager enumerateRenderingAttributesFromLocation:reverse:usingBlock:]`.
     * @details Enumerates the rendering attributes from the specified location. It enumerates only ranges with rendering attributes specified. Returning 'false' from block breaks out of the enumeration. Rendering attributes override the document text attributes stored in ''NSTextParagraph'' objects supplied by ''NSTextContentManager''. ''NSTextLayoutFragment'' associated with a text paragraph applies the overriding attributes before executing layout. Specifying \<doc://com.apple.documentation/documentation/foundation/nsnull> to an attribute indicates removing it from the document attributes. Rendering attributes are invalidated upon re-layout of the text layout fragment that they belong to. - Parameters: - location: The starting location. - reverse: Whether to enumerate in reverse. - block: A block called for each range with rendering attributes. Return 'false' to stop.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param reverse Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_rendering_attributes_from_location(const Object& location, bool reverse, std::function<bool(TextLayoutManager, std::map<std::string, Object>, TextRange)> block) const;
        /**
     * @brief Calls `-[NSTextLayoutManager enumerateTextLayoutFragmentsFromLocation:options:usingBlock:]`.
     * @details Enumerates the text layout fragments starting at the specified location. If 'location' is 'nil', it assumes 'self.textContentManager.documentRange.location'; uses 'documentRange.endLocation' for reverse enumeration. When enumerating backward, it starts with the fragment preceding the one containing 'location'. If enumerated at least one fragment, it returns the edge of the enumerated range. Note that the enumerated range might not match the range of the last element returned. Returning 'false' from block breaks out of the enumeration. - Parameters: - location: The starting location, or 'nil' for the document edge. - options: Enumeration options controlling direction and behavior. - block: A block called for each layout fragment. Return 'false' to stop. - Returns: The edge of the enumerated range, or 'nil'.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object enumerate_text_layout_fragments_from_location(const Object& location, TextLayoutFragmentEnumerationOptions options, std::function<bool(TextLayoutFragment)> block) const;
        /**
     * @brief Calls `-[NSTextLayoutManager enumerateTextSegmentsInRange:type:options:usingBlock:]`.
     * @details Enumerates text segments of a specific type and in the text range you provide. A text segment is both logically and visually contiguous portion of the text content inside a line fragment. It can be defined with a single text range. The segments are enumerated visually from left to right. Returning 'false' from block breaks out of the enumeration. - Parameters: - textRange: The range to enumerate segments in. - type: The segment type. - options: Options controlling segment behavior. - block: A block called for each segment. Return 'false' to stop.
     * @param text_range Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void enumerate_text_segments_in_range(const TextRange& text_range, TextLayoutManagerSegmentType type, TextLayoutManagerSegmentOptions options, std::function<bool(TextRange, Rect, double, TextContainer)> block) const;
        /**
     * @brief Calls `-[NSTextLayoutManager invalidateLayoutForRange:]`.
     * @details Invalidates layout information for the specified text range. - Parameters: - range: The text range to invalidate.
     * @param range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_layout_for_range(const TextRange& range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager invalidateRenderingAttributesForTextRange:]`.
     * @details Invalidates the rendering attributes in the specified text range. Enumerating rendering attributes will skip the invalidated range. - Parameters: - textRange: The range to invalidate.
     * @param text_range Argument converted to the Objective-C parameter of the same role.
     */
        void invalidate_rendering_attributes_for_text_range(const TextRange& text_range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager removeRenderingAttribute:forTextRange:]`.
     * @details Removes the rendering attribute from the specified text range. This is a convenience over ''setRenderingAttributes:forTextRange:''. - Parameters: - renderingAttribute: The \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/key> attribute to remove. - textRange: The range to remove the attribute from.
     * @param rendering_attribute Argument converted to the Objective-C parameter of the same role.
     * @param text_range Argument converted to the Objective-C parameter of the same role.
     */
        void remove_rendering_attribute(const std::string& rendering_attribute, const TextRange& text_range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager renderingAttributesForLink:atLocation:]`.
     * @details Returns a dictionary of rendering attributes for rendering a link. Just as other rendering attributes, specifying \<doc://com.apple.documentation/documentation/foundation/nsnull> removes the attribute from the final attributes used for rendering. It has priority over the general rendering attributes. - Parameters: - link: The link object. - location: The document location of the link. - Returns: A dictionary of rendering attributes.
     * @param link Argument converted to the Objective-C parameter of the same role.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> rendering_attributes_for_link(const Object& link, const Object& location) const;
        /**
     * @brief Calls `-[NSTextLayoutManager replaceContentsInRange:withAttributedString:]`.
     * @details Replaces content at the location you specify with an attributed string you provide. - Parameters: - range: The range of the content to replace. - attributedString: An attributed string to replace the content at 'range'.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param attributed_string Argument converted to the Objective-C parameter of the same role.
     */
        void replace_contents_in_range(const TextRange& range, const AttributedString& attributed_string) const;
        /**
     * @brief Calls `-[NSTextLayoutManager replaceContentsInRange:withTextElements:]`.
     * @details Replaces content at the location you specify with the text elements you provide. - Parameters: - range: The range of the content to replace. - textElements: An array of text elements.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @param text_elements Argument converted to the Objective-C parameter of the same role.
     */
        void replace_contents_in_range(const TextRange& range, const std::vector<TextElement>& text_elements) const;
        /**
     * @brief Calls `-[NSTextLayoutManager replaceTextContentManager:]`.
     * @details Replaces the current text content manager with a new one you provide. This method should be used in order to replace an ''NSTextContentManager'' with a new one, leaving all related objects intact. This method makes sure the ''NSTextLayoutManager'' doesn't get deallocated while migrating to the new manager. - Parameters: - textContentManager: The new content manager.
     * @param text_content_manager Argument converted to the Objective-C parameter of the same role.
     */
        void replace_text_content_manager(const TextContentManager& text_content_manager) const;
        /**
     * @brief Calls `-[NSTextLayoutManager setRenderingAttributes:forTextRange:]`.
     * @details Sets the rendering attributes for the range you specify. - Parameters: - renderingAttributes: The attributes to set. - textRange: The range to apply attributes to.
     * @param rendering_attributes Argument converted to the Objective-C parameter of the same role.
     * @param text_range Argument converted to the Objective-C parameter of the same role.
     */
        void set_rendering_attributes(const std::map<std::string, Object>& rendering_attributes, const TextRange& text_range) const;
        /**
     * @brief Calls `-[NSTextLayoutManager textLayoutFragmentForLocation:]`.
     * @details Returns the text layout fragment from the document at the specified location. - Parameters: - location: A document location. - Returns: The layout fragment containing the location, or 'nil'.
     * @param location Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextLayoutFragment text_layout_fragment_for_location(const Object& location) const;
        /**
     * @brief Calls `-[NSTextLayoutManager textLayoutFragmentForPosition:]`.
     * @details Returns the text layout fragment at the position you specify in the text container. - Parameters: - position: A \<doc://com.apple.documentation/documentation/corefoundation/cgpoint> in the text container coordinate system. - Returns: The layout fragment containing the position, or 'nil'.
     * @param position Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        TextLayoutFragment text_layout_fragment_for_position(const Point& position) const;
        /**
     * @brief Returns the `layoutQueue` property of `NSTextLayoutManager`.
     * @details The queue that the framework dispatches layout operations on. If non-nil, it performs layout in the specified queue until 'estimatedUsageBounds' is 'false'.
     * @return The converted Objective-C result.
     */
        OperationQueue layout_queue() const;
        /**
     * @brief Sets the `layoutQueue` property of `NSTextLayoutManager`.
     * @details The queue that the framework dispatches layout operations on. If non-nil, it performs layout in the specified queue until 'estimatedUsageBounds' is 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_queue(const OperationQueue& value) const;
        /**
     * @brief Returns the `limitsLayoutForSuspiciousContents` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls internal security analysis for malicious inputs and activates defensive behaviors. By enabling this functionality, it's possible certain text such as a very long paragraph might result in unexpected layout. The default value is 'false'.
     * @return The converted Objective-C result.
     */
        bool limits_layout_for_suspicious_contents() const;
        /**
     * @brief Sets the `limitsLayoutForSuspiciousContents` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls internal security analysis for malicious inputs and activates defensive behaviors. By enabling this functionality, it's possible certain text such as a very long paragraph might result in unexpected layout. The default value is 'false'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_limits_layout_for_suspicious_contents(bool value) const;
        /**
     * @brief Returns the `linkRenderingAttributes` property of `NSTextLayoutManager`.
     * @details Returns the default set of attributes for rendering 'NSLinkAttributeName'. The base ''NSTextLayoutManager'' class returns with ''NSUnderlineStyle/single'' for \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/key/1524865-underlinestyle> in Swift or ''NSUnderlineStyleAttributeName'' in Objective-C, and the platform link color for \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/key/1533563-foregroundcolor> in Swift or ''NSForegroundColorAttributeName'' in Objective-C. The platform color for macOS is 'linkColor'. Other platforms use 'blueColor'.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, Object> link_rendering_attributes();
        /**
     * @brief Returns the `renderingAttributesValidator` property of `NSTextLayoutManager`.
     * @details A callback block that the framework invokes whenever the text layout manager needs to validate the rendering attributes for the range. The validator should use ''setRenderingAttributes:forTextRange:'' to fill the rendering attributes appropriate for the range inside 'textLayoutFragment'.
     * @return The converted Objective-C result.
     */
        std::function<void(TextLayoutManager, TextLayoutFragment)> rendering_attributes_validator() const;
        /**
     * @brief Sets the `renderingAttributesValidator` property of `NSTextLayoutManager`.
     * @details A callback block that the framework invokes whenever the text layout manager needs to validate the rendering attributes for the range. The validator should use ''setRenderingAttributes:forTextRange:'' to fill the rendering attributes appropriate for the range inside 'textLayoutFragment'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_rendering_attributes_validator(std::function<void(TextLayoutManager, TextLayoutFragment)> value) const;
        /**
     * @brief Returns the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextLayoutManager`.
     * @details Specifies the behavior for resolving ''NSTextAlignment/natural'' to the visual alignment. When set to 'true', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is 'true'.
     * @return The converted Objective-C result.
     */
        bool resolves_natural_alignment_with_base_writing_direction() const;
        /**
     * @brief Sets the `resolvesNaturalAlignmentWithBaseWritingDirection` property of `NSTextLayoutManager`.
     * @details Specifies the behavior for resolving ''NSTextAlignment/natural'' to the visual alignment. When set to 'true', the resolved visual alignment is determined by the resolved base writing direction; otherwise, it is using the user’s preferred language. The default value is 'true'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_resolves_natural_alignment_with_base_writing_direction(bool value) const;
        /**
     * @brief Returns the `textContainer` property of `NSTextLayoutManager`.
     * @details The text container object that provides geometric information for the layout destination. If 'isSimpleRectangularTextContainer' is 'false', ''NSTextLayoutManager'' always fills from the top instead of allowing non-contiguous layout support.
     * @return The converted Objective-C result.
     */
        TextContainer text_container() const;
        /**
     * @brief Sets the `textContainer` property of `NSTextLayoutManager`.
     * @details The text container object that provides geometric information for the layout destination. If 'isSimpleRectangularTextContainer' is 'false', ''NSTextLayoutManager'' always fills from the top instead of allowing non-contiguous layout support.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_container(const TextContainer& value) const;
        /**
     * @brief Returns the `textContentManager` property of `NSTextLayoutManager`.
     * @details Returns the text content manager associated with this text layout manager.
     * @return The converted Objective-C result.
     */
        TextContentManager text_content_manager() const;
        /**
     * @brief Returns the `textSelectionNavigation` property of `NSTextLayoutManager`.
     * @details Returns a text selection navigation configured to have the text layout manager as its data source.
     * @return The converted Objective-C result.
     */
        TextSelectionNavigation text_selection_navigation() const;
        /**
     * @brief Sets the `textSelectionNavigation` property of `NSTextLayoutManager`.
     * @details Returns a text selection navigation configured to have the text layout manager as its data source.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_selection_navigation(const TextSelectionNavigation& value) const;
        /**
     * @brief Returns the `textSelections` property of `NSTextLayoutManager`.
     * @details An array of text selections associated by the text layout manager. Each ''NSTextSelection'' represents an insertion point. The selection state is shared among all view ports connected to the text layout manager via text containers.
     * @return The converted Objective-C result.
     */
        std::vector<TextSelection> text_selections() const;
        /**
     * @brief Sets the `textSelections` property of `NSTextLayoutManager`.
     * @details An array of text selections associated by the text layout manager. Each ''NSTextSelection'' represents an insertion point. The selection state is shared among all view ports connected to the text layout manager via text containers.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_text_selections(const std::vector<TextSelection>& value) const;
        /**
     * @brief Returns the `textViewportLayoutController` property of `NSTextLayoutManager`.
     * @details Returns the text viewport layout controller associated with the text layout manager's text container.
     * @return The converted Objective-C result.
     */
        TextViewportLayoutController text_viewport_layout_controller() const;
        /**
     * @brief Returns the `usageBoundsForTextContainer` property of `NSTextLayoutManager`.
     * @details Returns the usage bounds for the text container. KVO-compliant. Views can observe this property in order to trigger a resize operation. For example, 'UIView'/'NSView' should call 'setNeedsUpdateConstraints()' when the usage bounds changes.
     * @return The converted Objective-C result.
     */
        Rect usage_bounds_for_text_container() const;
        /**
     * @brief Returns the `usesFontLeading` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls whether the framework uses the leading information specified by the font when laying out text. If set to 'true', uses the leading as specified by the font. However, this isn't appropriate for most UI text. The default value is 'true'.
     * @return The converted Objective-C result.
     */
        bool uses_font_leading() const;
        /**
     * @brief Sets the `usesFontLeading` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls whether the framework uses the leading information specified by the font when laying out text. If set to 'true', uses the leading as specified by the font. However, this isn't appropriate for most UI text. The default value is 'true'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uses_font_leading(bool value) const;
        /**
     * @brief Returns the `usesHyphenation` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls whether the text layout manager attempts to hyphenate when wrapping lines. May be overridden on a per-paragraph basis by the 'NSParagraphStyle''s 'usesDefaultHyphenation'. The receiver makes the best effort to decide the exact logic including the hyphenation factor based on the context. The default value is 'false'. Can be overridden by the preference key '"NSUsesDefaultHyphenation"'.
     * @return The converted Objective-C result.
     */
        bool uses_hyphenation() const;
        /**
     * @brief Sets the `usesHyphenation` property of `NSTextLayoutManager`.
     * @details A Boolean value that controls whether the text layout manager attempts to hyphenate when wrapping lines. May be overridden on a per-paragraph basis by the 'NSParagraphStyle''s 'usesDefaultHyphenation'. The receiver makes the best effort to decide the exact logic including the hyphenation factor based on the context. The default value is 'false'. Can be overridden by the preference key '"NSUsesDefaultHyphenation"'.
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
        /// @brief Signal for the delegate/data-source method behind `cache_text_attachment_view_provider_for_text_attachment`; connect a callback with `cache_text_attachment_view_provider_for_text_attachment().connect(...)`.
        Signal<TextLayoutManager, void(TextAttachmentViewProvider, TextAttachment)> cache_text_attachment_view_provider_for_text_attachment() const
        {
            return Signal<TextLayoutManager, void(TextAttachmentViewProvider, TextAttachment)>(handle(), "cache_text_attachment_view_provider_for_text_attachment");
        }
        /// @brief Signal for the delegate/data-source method behind `retrieve_cached_text_attachment_view_provider_for_text_attachment`; connect a callback with `retrieve_cached_text_attachment_view_provider_for_text_attachment().connect(...)`.
        Signal<TextLayoutManager, TextAttachmentViewProvider(TextAttachment)> retrieve_cached_text_attachment_view_provider_for_text_attachment() const
        {
            return Signal<TextLayoutManager, TextAttachmentViewProvider(TextAttachment)>(handle(), "retrieve_cached_text_attachment_view_provider_for_text_attachment");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
