#include "generated/text_attachment.h"
#include "internal.h"

namespace cocoon
{
    TextAttachment::TextAttachment(const std::vector<std::uint8_t>& content_data, const std::string& uti) : TextAttachment(Adopt{cocoon::internal::retain([[::NSTextAttachment alloc] initWithData:cocoon::internal::to_data(content_data) ofType:cocoon::internal::to(uti)])})
    {
    }

    TextAttachment::TextAttachment(const FileWrapper& file_wrapper) : TextAttachment(Adopt{cocoon::internal::retain([[::NSTextAttachment alloc] initWithFileWrapper:cocoon::internal::native<::NSFileWrapper>(file_wrapper)])})
    {
    }

    TextAttachment::TextAttachment() : TextAttachment(Adopt{cocoon::internal::retain([[::NSTextAttachment alloc] init])})
    {
    }

    TextAttachment::TextAttachment(std::nullptr_t) : Object(nullptr)
    {
    }

    TextAttachment::TextAttachment(Adopt adopt) : Object(adopt)
    {
    }

    void TextAttachment::register_text_attachment_view_provider_class(const std::string& text_attachment_view_provider_class, const std::string& file_type)
    {
        [::NSTextAttachment registerTextAttachmentViewProviderClass:NSClassFromString(cocoon::internal::to(text_attachment_view_provider_class)) forFileType:cocoon::internal::to(file_type)];
    }

    std::string TextAttachment::text_attachment_view_provider_class_for_file_type(const std::string& file_type)
    {
        return cocoon::internal::from(NSStringFromClass([::NSTextAttachment textAttachmentViewProviderClassForFileType:cocoon::internal::to(file_type)]));
    }

    bool TextAttachment::allows_text_attachment_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextAttachment>(this) allowsTextAttachmentView]);
    }

    void TextAttachment::set_allows_text_attachment_view(bool value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setAllowsTextAttachmentView:static_cast<::BOOL>(value)];
    }

    Object TextAttachment::attachment_cell() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSTextAttachment>(this) attachmentCell]);
    }

    void TextAttachment::set_attachment_cell(const Object& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setAttachmentCell:cocoon::internal::native_id(value)];
    }

    Rect TextAttachment::bounds() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextAttachment>(this) bounds]);
    }

    void TextAttachment::set_bounds(const Rect& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setBounds:cocoon::internal::to(value)];
    }

    std::vector<std::uint8_t> TextAttachment::contents() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSTextAttachment>(this) contents]);
    }

    void TextAttachment::set_contents(const std::vector<std::uint8_t>& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setContents:cocoon::internal::to_data(value)];
    }

    std::string TextAttachment::file_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSTextAttachment>(this) fileType]);
    }

    void TextAttachment::set_file_type(const std::string& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setFileType:cocoon::internal::to(value)];
    }

    FileWrapper TextAttachment::file_wrapper() const
    {
        return cocoon::internal::wrap<FileWrapper>([cocoon::internal::ns<::NSTextAttachment>(this) fileWrapper]);
    }

    void TextAttachment::set_file_wrapper(const FileWrapper& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setFileWrapper:cocoon::internal::native<::NSFileWrapper>(value)];
    }

    Image TextAttachment::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSTextAttachment>(this) image]);
    }

    void TextAttachment::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    double TextAttachment::line_layout_padding() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSTextAttachment>(this) lineLayoutPadding]);
    }

    void TextAttachment::set_line_layout_padding(double value) const
    {
        [cocoon::internal::ns<::NSTextAttachment>(this) setLineLayoutPadding:static_cast<::CGFloat>(value)];
    }

    bool TextAttachment::uses_text_attachment_view() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSTextAttachment>(this) usesTextAttachmentView]);
    }
}
