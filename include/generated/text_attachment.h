#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class FileWrapper;
    class Image;

    /**
     * @brief C++ handle for the Objective-C class `NSTextAttachment` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextAttachment text_attachment;
     * text_attachment.set_allows_text_attachment_view(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextAttachment text_attachment{};
     * text_attachment.set_allows_text_attachment_view(true);
     * auto allows_text_attachment_view = text_attachment.allows_text_attachment_view();
     * text_attachment.set_bounds({{0, 0}, {100, 100}});
     * auto bounds = text_attachment.bounds();
     * text_attachment.set_file_type("text");
     * auto file_type = text_attachment.file_type();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextattachment
     */
    class TextAttachment : public Object
    {
    public:
        /// @brief Creates a new `NSTextAttachment` instance and returns a handle to it.
        explicit TextAttachment(const std::vector<std::uint8_t>& content_data, const std::string& uti);
        /// @brief Creates a new `NSTextAttachment` instance and returns a handle to it.
        explicit TextAttachment(const FileWrapper& file_wrapper);
        /// @brief Creates a new `NSTextAttachment` instance and returns a handle to it.
        explicit TextAttachment();
        /// @brief Creates a null handle that refers to no native object.
        TextAttachment(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextAttachment(Adopt adopt);
        /**
     * @brief Calls `+[NSTextAttachment registerTextAttachmentViewProviderClass:forFileType:]`.
     * @param text_attachment_view_provider_class Argument converted to the Objective-C parameter of the same role.
     * @param file_type Argument converted to the Objective-C parameter of the same role.
     */
        static void register_text_attachment_view_provider_class(const std::string& text_attachment_view_provider_class, const std::string& file_type);
        /**
     * @brief Calls `+[NSTextAttachment textAttachmentViewProviderClassForFileType:]`.
     * @param file_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string text_attachment_view_provider_class_for_file_type(const std::string& file_type);
        /**
     * @brief Returns the `allowsTextAttachmentView` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        bool allows_text_attachment_view() const;
        /**
     * @brief Sets the `allowsTextAttachmentView` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allows_text_attachment_view(bool value) const;
        /**
     * @brief Returns the `attachmentCell` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        Object attachment_cell() const;
        /**
     * @brief Sets the `attachmentCell` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attachment_cell(const Object& value) const;
        /**
     * @brief Returns the `bounds` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        Rect bounds() const;
        /**
     * @brief Sets the `bounds` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bounds(const Rect& value) const;
        /**
     * @brief Returns the `contents` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> contents() const;
        /**
     * @brief Sets the `contents` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_contents(const std::vector<std::uint8_t>& value) const;
        /**
     * @brief Returns the `fileType` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        std::string file_type() const;
        /**
     * @brief Sets the `fileType` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_type(const std::string& value) const;
        /**
     * @brief Returns the `fileWrapper` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        FileWrapper file_wrapper() const;
        /**
     * @brief Sets the `fileWrapper` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_wrapper(const FileWrapper& value) const;
        /**
     * @brief Returns the `image` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `lineLayoutPadding` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        double line_layout_padding() const;
        /**
     * @brief Sets the `lineLayoutPadding` property of `NSTextAttachment`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_layout_padding(double value) const;
        /**
     * @brief Returns the `usesTextAttachmentView` property of `NSTextAttachment`.
     * @return The converted Objective-C result.
     */
        bool uses_text_attachment_view() const;
    };
}
