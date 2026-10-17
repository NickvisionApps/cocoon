#include "generated/combo_box_cell.h"
#include "internal.h"

@interface AKComboBoxCellDataSourceDelegate : NSObject <NSComboBoxCellDataSource>
{
@public
    __weak id host;
}
@end

@implementation AKComboBoxCellDataSourceDelegate

- (NSInteger)numberOfItemsInComboBoxCell:(NSComboBoxCell*)comboBoxCell
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBoxCell, std::int64_t()>::emit((__bridge void*)strongHost, "number_of_items_in_combo_box_cell");
    return static_cast<::NSInteger>(__r);
}

- (id)comboBoxCell:(NSComboBoxCell*)comboBoxCell objectValueForItemAtIndex:(NSInteger)index
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBoxCell, cocoon::Object(std::int64_t)>::emit((__bridge void*)strongHost, "object_value_for_item_at_index", static_cast<std::int64_t>(index));
    return cocoon::internal::native_id(__r);
}

- (NSUInteger)comboBoxCell:(NSComboBoxCell*)comboBoxCell indexOfItemWithStringValue:(NSString*)string
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBoxCell, std::uint64_t(std::string)>::emit((__bridge void*)strongHost, "index_of_item_with_string_value", cocoon::internal::from(string));
    return static_cast<::NSUInteger>(__r);
}

- (NSString*)comboBoxCell:(NSComboBoxCell*)comboBoxCell completedString:(NSString*)uncompletedString
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::ComboBoxCell, std::string(std::string)>::emit((__bridge void*)strongHost, "combo_box_cell_completed_string", cocoon::internal::from(uncompletedString));
    return cocoon::internal::to(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(numberOfItemsInComboBoxCell:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBoxCell, std::int64_t()>::connected((__bridge void*)strongHost, "number_of_items_in_combo_box_cell");
    }
    if (selector == @selector(comboBoxCell:objectValueForItemAtIndex:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBoxCell, cocoon::Object(std::int64_t)>::connected((__bridge void*)strongHost, "object_value_for_item_at_index");
    }
    if (selector == @selector(comboBoxCell:indexOfItemWithStringValue:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBoxCell, std::uint64_t(std::string)>::connected((__bridge void*)strongHost, "index_of_item_with_string_value");
    }
    if (selector == @selector(comboBoxCell:completedString:))
    {
        return strongHost && cocoon::Signal<cocoon::ComboBoxCell, std::string(std::string)>::connected((__bridge void*)strongHost, "combo_box_cell_completed_string");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    ComboBoxCell::ComboBoxCell() : ComboBoxCell(Adopt{cocoon::internal::retain([[::NSComboBoxCell alloc] init])})
    {
        ComboBoxCell::install_data_source_delegate_(handle());
    }

    ComboBoxCell::ComboBoxCell(std::nullptr_t) : TextFieldCell(nullptr)
    {
    }

    ComboBoxCell::ComboBoxCell(Adopt adopt) : TextFieldCell(adopt)
    {
    }

    void ComboBoxCell::add_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) addItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    void ComboBoxCell::add_items_with_object_values(const std::vector<Object>& objects) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) addItemsWithObjectValues:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                              {
                                                                                  return cocoon::internal::native_id(e);
                                                                              })];
    }

    std::string ComboBoxCell::completed_string(const std::string& string) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSComboBoxCell>(this) completedString:cocoon::internal::to(string)]);
    }

    void ComboBoxCell::deselect_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) deselectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    std::int64_t ComboBoxCell::index_of_item_with_object_value(const Object& object) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBoxCell>(this) indexOfItemWithObjectValue:cocoon::internal::native_id(object)]);
    }

    void ComboBoxCell::insert_item_with_object_value(const Object& object, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) insertItemWithObjectValue:cocoon::internal::native_id(object) atIndex:static_cast<::NSInteger>(index)];
    }

    Object ComboBoxCell::item_object_value_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSComboBoxCell>(this) itemObjectValueAtIndex:static_cast<::NSInteger>(index)]);
    }

    void ComboBoxCell::note_number_of_items_changed() const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) noteNumberOfItemsChanged];
    }

    void ComboBoxCell::reload_data() const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) reloadData];
    }

    void ComboBoxCell::remove_all_items() const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) removeAllItems];
    }

    void ComboBoxCell::remove_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) removeItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void ComboBoxCell::remove_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) removeItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    void ComboBoxCell::scroll_item_at_index_to_top(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) scrollItemAtIndexToTop:static_cast<::NSInteger>(index)];
    }

    void ComboBoxCell::scroll_item_at_index_to_visible(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) scrollItemAtIndexToVisible:static_cast<::NSInteger>(index)];
    }

    void ComboBoxCell::select_item_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) selectItemAtIndex:static_cast<::NSInteger>(index)];
    }

    void ComboBoxCell::select_item_with_object_value(const Object& object) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) selectItemWithObjectValue:cocoon::internal::native_id(object)];
    }

    bool ComboBoxCell::is_button_bordered() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBoxCell>(this) isButtonBordered]);
    }

    void ComboBoxCell::set_button_bordered(bool value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setButtonBordered:static_cast<::BOOL>(value)];
    }

    bool ComboBoxCell::completes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBoxCell>(this) completes]);
    }

    void ComboBoxCell::set_completes(bool value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setCompletes:static_cast<::BOOL>(value)];
    }

    bool ComboBoxCell::has_vertical_scroller() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBoxCell>(this) hasVerticalScroller]);
    }

    void ComboBoxCell::set_has_vertical_scroller(bool value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setHasVerticalScroller:static_cast<::BOOL>(value)];
    }

    std::int64_t ComboBoxCell::index_of_selected_item() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBoxCell>(this) indexOfSelectedItem]);
    }

    Size ComboBoxCell::intercell_spacing() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSComboBoxCell>(this) intercellSpacing]);
    }

    void ComboBoxCell::set_intercell_spacing(const Size& value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setIntercellSpacing:cocoon::internal::to(value)];
    }

    double ComboBoxCell::item_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSComboBoxCell>(this) itemHeight]);
    }

    void ComboBoxCell::set_item_height(double value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setItemHeight:static_cast<::CGFloat>(value)];
    }

    std::int64_t ComboBoxCell::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBoxCell>(this) numberOfItems]);
    }

    std::int64_t ComboBoxCell::number_of_visible_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSComboBoxCell>(this) numberOfVisibleItems]);
    }

    void ComboBoxCell::set_number_of_visible_items(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setNumberOfVisibleItems:static_cast<::NSInteger>(value)];
    }

    Object ComboBoxCell::object_value_of_selected_item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSComboBoxCell>(this) objectValueOfSelectedItem]);
    }

    std::vector<Object> ComboBoxCell::object_values() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSComboBoxCell>(this) objectValues], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    bool ComboBoxCell::uses_data_source() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSComboBoxCell>(this) usesDataSource]);
    }

    void ComboBoxCell::set_uses_data_source(bool value) const
    {
        [cocoon::internal::ns<::NSComboBoxCell>(this) setUsesDataSource:static_cast<::BOOL>(value)];
    }

    void ComboBoxCell::install_data_source_delegate_(void* native)
    {
        ::NSComboBoxCell* host = (__bridge ::NSComboBoxCell*)native;
        AKComboBoxCellDataSourceDelegate* delegate = [[AKComboBoxCellDataSourceDelegate alloc] init];
        delegate->host = host;
        host.dataSource = delegate;
        __weak::NSComboBoxCell* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSComboBoxCell* strongHost = weakHost;
            strongHost.dataSource = nil;
            strongHost.dataSource = delegate;
        });
    }
}
