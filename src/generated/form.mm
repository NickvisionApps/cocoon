#include "generated/form.h"
#include "internal.h"

namespace cocoon
{
    Form::Form() : Form(Adopt{cocoon::internal::retain([[::NSForm alloc] init])})
    {
        Matrix::install_delegate_delegate_(handle());
    }

    Form::Form(std::nullptr_t) : Matrix(nullptr)
    {
    }

    Form::Form(Adopt adopt) : Matrix(adopt)
    {
    }

    FormCell Form::add_entry(const std::string& title) const
    {
        return cocoon::internal::wrap<FormCell>([cocoon::internal::ns<::NSForm>(this) addEntry:cocoon::internal::to(title)]);
    }

    Object Form::cell_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSForm>(this) cellAtIndex:static_cast<::NSInteger>(index)]);
    }

    void Form::draw_cell_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSForm>(this) drawCellAtIndex:static_cast<::NSInteger>(index)];
    }

    std::int64_t Form::index_of_cell_with_tag(std::int64_t tag) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSForm>(this) indexOfCellWithTag:static_cast<::NSInteger>(tag)]);
    }

    std::int64_t Form::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSForm>(this) indexOfSelectedItem]);
    }

    FormCell Form::insert_entry(const std::string& title, std::int64_t index) const
    {
        return cocoon::internal::wrap<FormCell>([cocoon::internal::ns<::NSForm>(this) insertEntry:cocoon::internal::to(title) atIndex:static_cast<::NSInteger>(index)]);
    }

    double Form::preferred_text_field_width() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSForm>(this) preferredTextFieldWidth]);
    }

    void Form::remove_entry_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSForm>(this) removeEntryAtIndex:static_cast<::NSInteger>(index)];
    }

    void Form::select_text_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSForm>(this) selectTextAtIndex:static_cast<::NSInteger>(index)];
    }

    void Form::set_bezeled(bool flag) const
    {
        [cocoon::internal::ns<::NSForm>(this) setBezeled:static_cast<::BOOL>(flag)];
    }

    void Form::set_bordered(bool flag) const
    {
        [cocoon::internal::ns<::NSForm>(this) setBordered:static_cast<::BOOL>(flag)];
    }

    void Form::set_entry_width(double width) const
    {
        [cocoon::internal::ns<::NSForm>(this) setEntryWidth:static_cast<::CGFloat>(width)];
    }

    void Form::set_frame_size(const Size& new_size) const
    {
        [cocoon::internal::ns<::NSForm>(this) setFrameSize:cocoon::internal::to(new_size)];
    }

    void Form::set_interline_spacing(double spacing) const
    {
        [cocoon::internal::ns<::NSForm>(this) setInterlineSpacing:static_cast<::CGFloat>(spacing)];
    }

    void Form::set_preferred_text_field_width(double preferred_width) const
    {
        [cocoon::internal::ns<::NSForm>(this) setPreferredTextFieldWidth:static_cast<::CGFloat>(preferred_width)];
    }

    void Form::set_text_alignment(TextAlignment mode) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTextAlignment:static_cast<::NSTextAlignment>(mode)];
    }

    void Form::set_text_base_writing_direction(WritingDirection writing_direction) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTextBaseWritingDirection:static_cast<::NSWritingDirection>(writing_direction)];
    }

    void Form::set_text_font(const Font& font_obj) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTextFont:cocoon::internal::native<::NSFont>(font_obj)];
    }

    void Form::set_title_alignment(TextAlignment mode) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTitleAlignment:static_cast<::NSTextAlignment>(mode)];
    }

    void Form::set_title_base_writing_direction(WritingDirection writing_direction) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTitleBaseWritingDirection:static_cast<::NSWritingDirection>(writing_direction)];
    }

    void Form::set_title_font(const Font& font_obj) const
    {
        [cocoon::internal::ns<::NSForm>(this) setTitleFont:cocoon::internal::native<::NSFont>(font_obj)];
    }
}
