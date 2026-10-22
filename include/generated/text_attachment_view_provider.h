#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class TextAttachment;
    class TextContainer;
    class TextLayoutManager;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSTextAttachmentViewProvider` (AppKit).
     * @details A container object that associates a text attachment at a particular document location with a view object. Use 'NSTextAttachmentViewProvider' when you need to represent document locations in terms of an ''NSTextLocation'' or an ''NSTextRange'' or you want to support view-based text attachments. The view provider controls the view placement and layout without requiring view classes to be aware of the text attachment coordination using a ''NSTextLayoutManager'' in macOS 12 or iOS 15 and later.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextAttachmentViewProvider text_attachment_view_provider(nullptr);  // null handle; instances normally come from other API calls
     * text_attachment_view_provider.set_tracks_text_attachment_view_bounds(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextAttachmentViewProvider text_attachment_view_provider(nullptr);
     * text_attachment_view_provider.set_tracks_text_attachment_view_bounds(true);
     * auto tracks_text_attachment_view_bounds = text_attachment_view_provider.tracks_text_attachment_view_bounds();
     * text_attachment_view_provider.set_view(cocoon::View());
     * auto view = text_attachment_view_provider.view();
     * text_attachment_view_provider.load_view();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextattachmentviewprovider
     */
    class TextAttachmentViewProvider : public Object
    {
    public:
        /// @brief Creates a new `NSTextAttachmentViewProvider` instance and returns a handle to it.
        explicit TextAttachmentViewProvider(const TextAttachment& text_attachment, const View& parent_view, const TextLayoutManager& text_layout_manager, const Object& location);
        TextAttachmentViewProvider();
        /// @brief Creates a null handle that refers to no native object.
        TextAttachmentViewProvider(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextAttachmentViewProvider(Adopt adopt);
        /**
         * @brief Calls `-[NSTextAttachmentViewProvider attachmentBoundsForAttributes:location:textContainer:proposedLineFragment:position:]`.
         * @details Returns the layout bounds for an attachment at a specific text location that contains the text attributes you specify. - Parameters: - attributes: A dictionary that contains a list of key and attribute pairs that describe the customization of the string. - location: An ''NSTextLocation'' that indicates the location of the attachment inside the document. - textContainer: The ''NSTextContainer'' that defines the area to fill in with text. - proposedLineFragment: A \<doc://com.apple.documentation/documentation/corefoundation/cgrect> that describes the boundaries of the line fragment. - position: A \<doc://com.apple.documentation/documentation/corefoundation/cgpoint> inside 'proposedLineFragment'. - Returns: A \<doc://com.apple.documentation/documentation/corefoundation/cgrect> that describes the bounds of the attachment.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param text_container Argument converted to the Objective-C parameter of the same role.
         * @param proposed_line_fragment Argument converted to the Objective-C parameter of the same role.
         * @param position Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect attachment_bounds_for_attributes(const std::map<std::string, Object>& attributes, const Object& location, const TextContainer& text_container, const Rect& proposed_line_fragment, const Point& position) const;
        /**
         * @brief Calls `-[NSTextAttachmentViewProvider loadView]`.
         * @details Creates the custom view hierarchy for this attachment. Use this method to create a custom view hierarchy. Don't call this method directly; the framework calls it at the appropriate time.
         */
        void load_view() const;
        /**
         * @brief Returns the `textAttachment` property of `NSTextAttachmentViewProvider`.
         * @details The text attachment for this view. Specify the value of this property at initialization time using the ''NSTextAttachmentViewProvider/init(textAttachment:parentView:textLayoutManager:location:)'' initializer.
         * @return The converted Objective-C result.
         */
        TextAttachment text_attachment() const;
        /**
         * @brief Returns the `textLayoutManager` property of `NSTextAttachmentViewProvider`.
         * @details The text layout manager for this view. Specify the value of this property at initialization time using the ''NSTextAttachmentViewProvider/init(textAttachment:parentView:textLayoutManager:location:)'' initializer.
         * @return The converted Objective-C result.
         */
        TextLayoutManager text_layout_manager() const;
        /**
         * @brief Returns the `tracksTextAttachmentViewBounds` property of `NSTextAttachmentViewProvider`.
         * @details A Boolean value that determines the text attachment's bounds policy. If 'true', the framework calls the 'textAttachment' property's ''NSTextAttachmentViewProvider/attachmentBounds(for:location:textContainer:proposedLineFragment:position:)'' method and examines the text attachment view provider to determine the bounds instead of using the 'bounds' property of this instance. Defaults to 'false'.
         * @return The converted Objective-C result.
         */
        bool tracks_text_attachment_view_bounds() const;
        /**
         * @brief Sets the `tracksTextAttachmentViewBounds` property of `NSTextAttachmentViewProvider`.
         * @details A Boolean value that determines the text attachment's bounds policy. If 'true', the framework calls the 'textAttachment' property's ''NSTextAttachmentViewProvider/attachmentBounds(for:location:textContainer:proposedLineFragment:position:)'' method and examines the text attachment view provider to determine the bounds instead of using the 'bounds' property of this instance. Defaults to 'false'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_tracks_text_attachment_view_bounds(bool value) const;
        /**
         * @brief Returns the `view` property of `NSTextAttachmentViewProvider`.
         * @details The text attachment's view. The getter first invokes ''loadView'' if the view hasn't been set yet. > Important: Subclasses must call the superclass implementation if they override the setter or getter.
         * @return The converted Objective-C result.
         */
        View view() const;
        /**
         * @brief Sets the `view` property of `NSTextAttachmentViewProvider`.
         * @details The text attachment's view. The getter first invokes ''loadView'' if the view hasn't been set yet. > Important: Subclasses must call the superclass implementation if they override the setter or getter.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_view(const View& value) const;
    };
}
