#include <functional>
#include <objc/runtime.h>
#include "internal.h"
#include "sidebar_list.h"

static char sourceKey;

@interface AKSidebarNode : NSObject
@property(nonatomic) int identifier;
@property(nonatomic, copy) NSString* title;
@property(nonatomic, copy) NSString* symbol;
@property(nonatomic) BOOL header;
@property(nonatomic, copy) NSArray<AKSidebarNode*>* children;
@end

@implementation AKSidebarNode
@end

@interface AKSidebarSource : NSObject <NSOutlineViewDataSource, NSOutlineViewDelegate>
@property(nonatomic, copy) NSArray<AKSidebarNode*>* roots;
@property(nonatomic, strong) NSMutableDictionary<NSNumber*, AKSidebarNode*>* index;
@property(nonatomic, copy) void (^onSelect)(int);
@end

@implementation AKSidebarSource

- (NSInteger)outlineView:(NSOutlineView*)outlineView numberOfChildrenOfItem:(id)item
{
    return item ? [(AKSidebarNode*)item children].count : self.roots.count;
}

- (id)outlineView:(NSOutlineView*)outlineView child:(NSInteger)index ofItem:(id)item
{
    return item ? [(AKSidebarNode*)item children][index] : self.roots[index];
}

- (BOOL)outlineView:(NSOutlineView*)outlineView isItemExpandable:(id)item
{
    return [(AKSidebarNode*)item children].count > 0;
}

- (BOOL)outlineView:(NSOutlineView*)outlineView isGroupItem:(id)item
{
    return [(AKSidebarNode*)item header];
}

- (BOOL)outlineView:(NSOutlineView*)outlineView shouldSelectItem:(id)item
{
    return ![(AKSidebarNode*)item header];
}

- (NSView*)outlineView:(NSOutlineView*)outlineView viewForTableColumn:(NSTableColumn*)tableColumn item:(id)item
{
    AKSidebarNode* node = item;
    NSTableCellView* cell = [outlineView makeViewWithIdentifier:@"AKSidebarCell" owner:nil];
    if (!cell)
    {
        cell = [[NSTableCellView alloc] init];
        cell.identifier = @"AKSidebarCell";
        NSImageView* imageView = [[NSImageView alloc] init];
        NSTextField* textField = [NSTextField labelWithString:@""];
        imageView.translatesAutoresizingMaskIntoConstraints = NO;
        textField.translatesAutoresizingMaskIntoConstraints = NO;
        textField.lineBreakMode = NSLineBreakByTruncatingTail;
        [cell addSubview:imageView];
        [cell addSubview:textField];
        cell.imageView = imageView;
        cell.textField = textField;
        [NSLayoutConstraint activateConstraints:@[
            [imageView.leadingAnchor constraintEqualToAnchor:cell.leadingAnchor
                                                    constant:2],
            [imageView.centerYAnchor constraintEqualToAnchor:cell.centerYAnchor],
            [imageView.widthAnchor constraintEqualToConstant:18],
            [textField.leadingAnchor constraintEqualToAnchor:imageView.trailingAnchor
                                                    constant:6],
            [textField.trailingAnchor constraintEqualToAnchor:cell.trailingAnchor
                                                     constant:-2],
            [textField.centerYAnchor constraintEqualToAnchor:cell.centerYAnchor],
        ]];
    }
    cell.textField.stringValue = node.title;
    cell.imageView.image = node.symbol.length ? [NSImage imageWithSystemSymbolName:node.symbol accessibilityDescription:node.title] : nil;
    cell.imageView.hidden = cell.imageView.image == nil;
    return cell;
}

- (void)outlineViewSelectionDidChange:(NSNotification*)notification
{
    NSOutlineView* outlineView = notification.object;
    AKSidebarNode* node = outlineView.selectedRow >= 0 ? [outlineView itemAtRow:outlineView.selectedRow] : nil;
    if (self.onSelect)
    {
        self.onSelect(node ? node.identifier : -1);
    }
}

@end

namespace cocoon
{
    SidebarList::SidebarList(Adopt adopt) : View(adopt)
    {
    }

    SidebarList::SidebarList() : SidebarList(Adopt{cocoon::internal::retain([[NSScrollView alloc] init])})
    {
        NSScrollView* scroll = cocoon::internal::ns<NSScrollView>(this);
        NSOutlineView* outline = [[NSOutlineView alloc] init];
        NSTableColumn* column = [[NSTableColumn alloc] initWithIdentifier:@"main"];
        AKSidebarSource* source = [[AKSidebarSource alloc] init];
        __weak NSScrollView* weakScroll = scroll;
        source.index = [NSMutableDictionary dictionary];
        source.roots = @[];
        source.onSelect = ^(int identifier) {
            NSScrollView* strongScroll = weakScroll;
            if (strongScroll)
            {
                Signal<SidebarList, void(int)>::emit((__bridge void*)strongScroll, "selection_changed", identifier);
            }
        };
        [outline addTableColumn:column];
        outline.outlineTableColumn = column;
        outline.headerView = nil;
        outline.style = NSTableViewStyleSourceList;
        outline.floatsGroupRows = NO;
        outline.backgroundColor = NSColor.clearColor;
        outline.dataSource = source;
        outline.delegate = source;
        scroll.documentView = outline;
        scroll.hasVerticalScroller = YES;
        scroll.autohidesScrollers = YES;
        outline.rowSizeStyle = NSTableViewRowSizeStyleMedium;
        scroll.drawsBackground = NO;
        objc_setAssociatedObject(outline, &sourceKey, source, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }

    void SidebarList::set_items(const std::vector<SidebarItem>& items) const
    {
        NSOutlineView* outline = (NSOutlineView*)cocoon::internal::ns<NSScrollView>(this).documentView;
        AKSidebarSource* source = (AKSidebarSource*)outline.dataSource;
        [source.index removeAllObjects];
        std::function<NSArray<AKSidebarNode*>*(const std::vector<SidebarItem>&)> build = [&](const std::vector<SidebarItem>& level)
        {
            NSMutableArray<AKSidebarNode*>* nodes = [NSMutableArray arrayWithCapacity:level.size()];
            for (const SidebarItem& item : level)
            {
                AKSidebarNode* node = [[AKSidebarNode alloc] init];
                node.identifier = item.id;
                node.title = cocoon::internal::to(item.title);
                node.symbol = cocoon::internal::to(item.symbol);
                node.header = item.is_header;
                node.children = build(item.children);
                source.index[@(item.id)] = node;
                [nodes addObject:node];
            }
            return nodes;
        };
        source.roots = build(items);
        [outline reloadData];
        [outline expandItem:nil expandChildren:YES];
    }

    void SidebarList::select_item(int id) const
    {
        NSOutlineView* outline = (NSOutlineView*)cocoon::internal::ns<NSScrollView>(this).documentView;
        AKSidebarNode* node = ((AKSidebarSource*)outline.dataSource).index[@(id)];
        NSInteger row = node ? [outline rowForItem:node] : -1;
        if (row >= 0)
        {
            [outline selectRowIndexes:[NSIndexSet indexSetWithIndex:row] byExtendingSelection:NO];
        }
    }

    int SidebarList::selected_item() const
    {
        NSOutlineView* outline = (NSOutlineView*)cocoon::internal::ns<NSScrollView>(this).documentView;
        AKSidebarNode* node = outline.selectedRow >= 0 ? [outline itemAtRow:outline.selectedRow] : nil;
        return node ? node.identifier : -1;
    }

    void SidebarList::expand_all() const
    {
        [(NSOutlineView*)cocoon::internal::ns<NSScrollView>(this).documentView expandItem:nil expandChildren:YES];
    }
}
