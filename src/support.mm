#include <algorithm>
#include <map>
#include <memory>
#include <objc/runtime.h>
#include "internal.h"

static char toolbarStateKey;

namespace
{
    struct ToolbarState
    {
        std::vector<std::string> defaults;
        std::vector<std::string> allowed;
        std::vector<std::string> immovable;
        std::map<std::string, cocoon::ToolbarItem> items;
    };
}

@interface AKToolbarState : NSObject
{
@public
    std::shared_ptr<ToolbarState> state;
}
@end

@implementation AKToolbarState
@end

static std::shared_ptr<ToolbarState> state_of(NSToolbar* toolbar)
{
    AKToolbarState* box = objc_getAssociatedObject(toolbar, &toolbarStateKey);
    if (!box)
    {
        box = [[AKToolbarState alloc] init];
        box->state = std::make_shared<ToolbarState>();
        objc_setAssociatedObject(toolbar, &toolbarStateKey, box, OBJC_ASSOCIATION_RETAIN_NONATOMIC);
    }
    return box->state;
}

namespace cocoon::internal
{
    NSApplication* make_application()
    {
        NSApplication* application = [NSApplication sharedApplication];
        [application setActivationPolicy:NSApplicationActivationPolicyRegular];
        return application;
    }

    NSWindow* make_window(const std::string& title, cocoon::Size size, cocoon::WindowStyle style)
    {
        NSWindow* window = [[NSWindow alloc] initWithContentRect:NSMakeRect(0, 0, size.width, size.height)
                                                       styleMask:static_cast<NSWindowStyleMask>(style)
                                                         backing:NSBackingStoreBuffered
                                                           defer:NO];
        window.releasedWhenClosed = NO;
        window.title = to(title);
        [window center];
        return window;
    }

    void show_window(NSWindow* window)
    {
        static NSMutableSet<NSWindowController*>* openControllers = [NSMutableSet set];
        NSWindowController* controller = window.windowController;
        if (!controller)
        {
            controller = [[NSWindowController alloc] initWithWindow:window];
            [openControllers addObject:controller];
            __block id token = [NSNotificationCenter.defaultCenter addObserverForName:NSWindowWillCloseNotification
                                                                               object:window
                                                                                queue:nil
                                                                           usingBlock:^(NSNotification* note) {
                                                                               [openControllers removeObject:controller];
                                                                               [NSNotificationCenter.defaultCenter removeObserver:token];
                                                                           }];
        }
        [controller showWindow:nil];
        [window makeKeyAndOrderFront:nil];
    }

    NSViewController* make_view_controller(const cocoon::View& view)
    {
        NSViewController* controller = [[NSViewController alloc] init];
        controller.view = native<NSView>(view);
        return controller;
    }

    NSSplitViewController* make_split_view_controller()
    {
        NSSplitViewController* controller = [[NSSplitViewController alloc] init];
        controller.splitView.vertical = YES;
        controller.splitView.dividerStyle = NSSplitViewDividerStyleThin;
        return controller;
    }

    void apply_shortcut(NSMenuItem* item, const std::string& shortcut)
    {
        NSDictionary<NSString*, NSString*>* named = @{
            @"return" : @"\r",
            @"enter" : @"\r",
            @"esc" : @"\x1b",
            @"escape" : @"\x1b",
            @"tab" : @"\t",
            @"space" : @" ",
            @"delete" : @"\x7f",
            @"backspace" : @"\x7f",
            @"up" : [NSString stringWithFormat:@"%C", (unichar)NSUpArrowFunctionKey],
            @"down" : [NSString stringWithFormat:@"%C", (unichar)NSDownArrowFunctionKey],
            @"left" : [NSString stringWithFormat:@"%C", (unichar)NSLeftArrowFunctionKey],
            @"right" : [NSString stringWithFormat:@"%C", (unichar)NSRightArrowFunctionKey],
        };
        NSDictionary<NSString*, NSNumber*>* modifiers = @{
            @"cmd" : @(NSEventModifierFlagCommand),
            @"command" : @(NSEventModifierFlagCommand),
            @"ctrl" : @(NSEventModifierFlagControl),
            @"control" : @(NSEventModifierFlagControl),
            @"opt" : @(NSEventModifierFlagOption),
            @"alt" : @(NSEventModifierFlagOption),
            @"option" : @(NSEventModifierFlagOption),
            @"shift" : @(NSEventModifierFlagShift),
        };
        NSEventModifierFlags mask = 0;
        NSString* key = @"";
        for (NSString* part in [to(shortcut).lowercaseString componentsSeparatedByString:@"+"])
        {
            if (modifiers[part])
            {
                mask |= modifiers[part].unsignedIntegerValue;
            }
            else
            {
                key = named[part] ?: part;
            }
        }
        item.keyEquivalent = key;
        item.keyEquivalentModifierMask = mask;
    }

    NSMenuItem* make_menu_item(const std::string& title, const std::string& shortcut)
    {
        NSMenuItem* item = [[NSMenuItem alloc] initWithTitle:to(title) action:nil keyEquivalent:@""];
        apply_shortcut(item, shortcut);
        return item;
    }

    NSMenuItem* make_standard_menu_item(cocoon::StandardAction action)
    {
        struct Spec
        {
            NSString* title;
            NSString* selector;
            NSString* key;
            NSEventModifierFlags mask;
        };
        const NSEventModifierFlags command = NSEventModifierFlagCommand;
        const Spec specs[] = {
            {@"About {}", @"orderFrontStandardAboutPanel:", @"", 0},
            {@"Hide {}", @"hide:", @"h", command},
            {@"Hide Others", @"hideOtherApplications:", @"h", command | NSEventModifierFlagOption},
            {@"Show All", @"unhideAllApplications:", @"", 0},
            {@"Quit {}", @"terminate:", @"q", command},
            {@"Undo", @"undo:", @"z", command},
            {@"Redo", @"redo:", @"z", command | NSEventModifierFlagShift},
            {@"Cut", @"cut:", @"x", command},
            {@"Copy", @"copy:", @"c", command},
            {@"Paste", @"paste:", @"v", command},
            {@"Select All", @"selectAll:", @"a", command},
            {@"Close", @"performClose:", @"w", command},
            {@"Minimize", @"performMiniaturize:", @"m", command},
            {@"Zoom", @"performZoom:", @"", 0},
            {@"Enter Full Screen", @"toggleFullScreen:", @"f", command | NSEventModifierFlagControl},
            {@"Bring All to Front", @"arrangeInFront:", @"", 0},
            {@"Toggle Sidebar", @"toggleSidebar:", @"s", command | NSEventModifierFlagControl},
            {@"{} Help", @"showHelp:", @"?", command},
        };
        const Spec& spec = specs[static_cast<int>(action)];
        NSMenuItem* item = [[NSMenuItem alloc] initWithTitle:[spec.title stringByReplacingOccurrencesOfString:@"{}" withString:NSProcessInfo.processInfo.processName]
                                                      action:NSSelectorFromString(spec.selector)
                                               keyEquivalent:spec.key];
        item.keyEquivalentModifierMask = spec.mask;
        return item;
    }

    NSToolbar* make_toolbar(const std::string& identifier)
    {
        NSToolbar* toolbar = [[NSToolbar alloc] initWithIdentifier:to(identifier)];
        toolbar.allowsUserCustomization = YES;
        toolbar.autosavesConfiguration = YES;
        state_of(toolbar);
        return toolbar;
    }

    NSToolbarItem* make_toolbar_item(const std::string& identifier, const std::string& label, const std::string& symbol)
    {
        NSToolbarItem* item = [[NSToolbarItem alloc] initWithItemIdentifier:to(identifier)];
        item.label = to(label);
        item.paletteLabel = to(label);
        item.toolTip = to(label);
        if (!symbol.empty())
        {
            item.image = [NSImage imageWithSystemSymbolName:to(symbol) accessibilityDescription:to(label)];
        }
        return item;
    }

    void install_toolbar_provider(void* native)
    {
        NSToolbar* toolbar = (__bridge NSToolbar*)native;
        std::shared_ptr<ToolbarState> state = state_of(toolbar);
        cocoon::Toolbar handle(cocoon::Adopt{cocoon::detail::retain_native(native)});
        handle.default_item_identifiers().connect([state]
                                                  {
                                                      return state->defaults;
                                                  });
        handle.allowed_item_identifiers().connect([state]
                                                  {
                                                      std::vector<std::string> result = state->allowed;
                                                      result.push_back(from(NSToolbarSpaceItemIdentifier));
                                                      result.push_back(from(NSToolbarFlexibleSpaceItemIdentifier));
                                                      return result;
                                                  });
        handle.immovable_item_identifiers().connect([state]
                                                    {
                                                        return state->immovable;
                                                    });
        handle.item_for_identifier().connect([state](std::string identifier, bool)
                                             {
                                                 auto found = state->items.find(identifier);
                                                 return found == state->items.end() ? cocoon::ToolbarItem(nullptr) : found->second;
                                             });
    }

    void toolbar_add(NSToolbar* toolbar, NSString* identifier, NSToolbarItem* item, bool isDefault, bool required)
    {
        std::shared_ptr<ToolbarState> state = state_of(toolbar);
        std::string name = from(identifier);
        if (item)
        {
            state->items[name] = wrap<cocoon::ToolbarItem>(item);
        }
        if (std::find(state->allowed.begin(), state->allowed.end(), name) == state->allowed.end())
        {
            state->allowed.push_back(name);
        }
        if (required)
        {
            state->immovable.push_back(name);
        }
        if (isDefault)
        {
            state->defaults.push_back(name);
            [toolbar insertItemWithItemIdentifier:identifier atIndex:toolbar.items.count];
        }
    }

    NSAlert* make_alert(const std::string& message, const std::string& informativeText, cocoon::AlertStyle style)
    {
        NSAlert* alert = [[NSAlert alloc] init];
        alert.messageText = to(message);
        alert.informativeText = to(informativeText);
        alert.alertStyle = static_cast<NSAlertStyle>(style);
        return alert;
    }

    NSImageView* make_image_view(const cocoon::Image& image)
    {
        NSImageView* view = [[NSImageView alloc] init];
        if (!image.is_null())
        {
            view.image = native<NSImage>(image);
        }
        return view;
    }

    NSBox* make_separator()
    {
        NSBox* box = [[NSBox alloc] init];
        box.boxType = NSBoxSeparator;
        return box;
    }

    NSStackView* make_stack(NSUserInterfaceLayoutOrientation orientation)
    {
        NSStackView* stack = [[NSStackView alloc] init];
        stack.orientation = orientation;
        return stack;
    }
}
