#include <objc/runtime.h>
#include "internal.h"
#include "table_list.h"

static char sourceKey;

@interface AKTableSource : NSObject <NSTableViewDataSource, NSTableViewDelegate>
@property(nonatomic, copy) NSArray<NSArray<NSString*>*>* rows;
@property(nonatomic, copy) void (^onSelect)(int);
@property(nonatomic, copy) void (^onDouble)(int);
@end

@implementation AKTableSource

- (NSInteger)numberOfRowsInTableView:(NSTableView*)tableView
{
    return self.rows.count;
}

- (NSView*)tableView:(NSTableView*)tableView viewForTableColumn:(NSTableColumn*)tableColumn row:(NSInteger)row
{
    NSTableCellView* cell = [tableView makeViewWithIdentifier:@"AKTableCell" owner:nil];
    if (!cell)
    {
        cell = [[NSTableCellView alloc] init];
        cell.identifier = @"AKTableCell";
        NSTextField* field = [NSTextField labelWithString:@""];
        field.translatesAutoresizingMaskIntoConstraints = NO;
        field.lineBreakMode = NSLineBreakByTruncatingTail;
        [cell addSubview:field];
        cell.textField = field;
        [NSLayoutConstraint activateConstraints:@[
            [field.leadingAnchor constraintEqualToAnchor:cell.leadingAnchor
                                                constant:2],
            [field.trailingAnchor constraintEqualToAnchor:cell.trailingAnchor
                                                 constant:-2],
            [field.centerYAnchor constraintEqualToAnchor:cell.centerYAnchor],
        ]];
    }
    NSUInteger column = (NSUInteger)tableColumn.identifier.integerValue;
    NSArray<NSString*>* cells = self.rows[row];
    cell.textField.stringValue = column < cells.count ? cells[column] : @"";
    return cell;
}

- (void)tableViewSelectionDidChange:(NSNotification*)notification
{
    if (self.onSelect)
    {
        self.onSelect((int)[(NSTableView*)notification.object selectedRow]);
    }
}

- (void)double_clicked:(NSTableView*)sender
{
    if (self.onDouble)
    {
        self.onDouble((int)sender.clickedRow);
    }
}

@end

namespace cocoon
{
    TableList::TableList(Adopt adopt) : View(adopt)
    {
    }

    TableList::TableList() : TableList(Adopt{cocoon::internal::retain([[NSScrollView alloc] init])})
    {
        NSScrollView* scroll = cocoon::internal::ns<NSScrollView>(this);
        NSTableView* table = [[NSTableView alloc] init];
        AKTableSource* source = [[AKTableSource alloc] init];
        __weak NSScrollView* weakScroll = scroll;
        source.rows = @[];
        source.onSelect = ^(int row) {
            NSScrollView* strongScroll = weakScroll;
            if (strongScroll)
            {
                Signal<TableList, void(int)>::emit((__bridge void*)strongScroll, "selection_changed", row);
            }
        };
        source.onDouble = ^(int row) {
            NSScrollView* strongScroll = weakScroll;
            if (strongScroll)
            {
                Signal<TableList, void(int)>::emit((__bridge void*)strongScroll, "double_clicked", row);
            }
        };
        table.dataSource = source;
        table.delegate = source;
        table.target = source;
        table.doubleAction = @selector(double_clicked:);
        scroll.documentView = table;
        scroll.hasVerticalScroller = YES;
        objc_setAssociatedObject(table, &sourceKey, source, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }

    void TableList::set_columns(const std::vector<std::string>& titles) const
    {
        NSTableView* table = (NSTableView*)cocoon::internal::ns<NSScrollView>(this).documentView;
        for (NSTableColumn* column in [table.tableColumns copy])
        {
            [table removeTableColumn:column];
        }
        for (size_t i = 0; i < titles.size(); ++i)
        {
            NSTableColumn* column = [[NSTableColumn alloc] initWithIdentifier:[NSString stringWithFormat:@"%zu", i]];
            column.title = cocoon::internal::to(titles[i]);
            [table addTableColumn:column];
        }
    }

    void TableList::set_rows(const std::vector<std::vector<std::string>>& rows) const
    {
        NSTableView* table = (NSTableView*)cocoon::internal::ns<NSScrollView>(this).documentView;
        NSMutableArray<NSArray<NSString*>*>* converted = [NSMutableArray arrayWithCapacity:rows.size()];
        for (const std::vector<std::string>& row : rows)
        {
            [converted addObject:cocoon::internal::to(row)];
        }
        ((AKTableSource*)table.dataSource).rows = converted;
        [table reloadData];
    }

    int TableList::selected_row() const
    {
        return static_cast<int>(((NSTableView*)cocoon::internal::ns<NSScrollView>(this).documentView).selectedRow);
    }

    void TableList::select_row(int row) const
    {
        [(NSTableView*)cocoon::internal::ns<NSScrollView>(this).documentView selectRowIndexes:[NSIndexSet indexSetWithIndex:row] byExtendingSelection:NO];
    }

    void TableList::set_alternating_rows(bool alternating) const
    {
        ((NSTableView*)cocoon::internal::ns<NSScrollView>(this).documentView).usesAlternatingRowBackgroundColors = alternating;
    }
}
