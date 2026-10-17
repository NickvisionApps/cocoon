SPEC = {
    "deploymentTarget": "26.0",
    "renames": {
        "NSUserInterfaceLayoutOrientation": "Orientation",
        "NSLayoutConstraintOrientation": "ConstraintOrientation",
        "NSGlassEffectViewStyle": "GlassStyle",
        "NSSplitViewDividerStyle": "DividerStyle",
        "NSWindowStyleMask": "WindowStyle",
        "NSWindowTitleVisibility": "TitleVisibility",
        "NSWindowToolbarStyle": "ToolbarStyle",
        "NSAlertStyle": "AlertStyle",
        "NSApplicationActivationPolicy": "ActivationPolicy",
    },
    "enumPrefixes": {
        "NSWindowTitleVisibility": "NSWindowTitle",
    },
    "skipClasses": [],
    "availabilityOverrides": {
        "NSControl.addTarget:action:forControlEvents:": 27,
        "NSControl.removeTarget:action:forControlEvents:": 27,
        "NSTextField.borderShape": 27,
    },
    "signalOverrides": {
        "windowDidResize:": {"name": "resized", "args": [["Size", "cocoon::internal::from([(NSWindow*)notification.object contentRectForFrameRect:((NSWindow*)notification.object).frame].size)"]]},
        "toolbar:itemForItemIdentifier:willBeInsertedIntoToolbar:": {"name": "itemForIdentifier"},
        "tabView:didSelectTabViewItem:": {"name": "selectionChanged", "args": [["int", "static_cast<int>([tabView indexOfTabViewItem:tabViewItem])"]]},
    },
    "enums": [
        {"name": "ControlState", "ns": "NSControlStateValue", "underlying": "std::int64_t", "values": {"Mixed": -1, "Off": 0, "On": 1}},
    ],
    "classes": [
        {
            "name": "Color", "ns": "NSColor",
            "ctors": [{"params": [["double", "red"], ["double", "green"], ["double", "blue"], ["double", "alpha", "1.0"]], "objc": "[NSColor colorWithSRGBRed:red green:green blue:blue alpha:alpha]"}],
        },
        {
            "name": "Image", "ns": "NSImage",
            "extra": [
                {"decl": "static Image symbol(const std::string& name, const std::string& description = {});",
                 "impl": "Image {cls}::symbol(const std::string& name, const std::string& description) { return cocoon::internal::wrap<Image>([NSImage imageWithSystemSymbolName:cocoon::internal::to(name) accessibilityDescription:description.empty() ? nil : cocoon::internal::to(description)]); }"},
            ],
        },
        {
            "name": "ProcessInfo", "ns": "NSProcessInfo",
            "ctors": [{"objc": "[NSProcessInfo processInfo]"}],
        },
        {
            "name": "View", "ns": "NSView",
            "ctors": [{"objc": "[[NSView alloc] init]"}],
            "extra": [
                {"decl": "void addSubview(const View& child);",
                 "impl": """void {cls}::addSubview(const View& child)
{
    cocoon::internal::native<NSView>(child).translatesAutoresizingMaskIntoConstraints = NO;
    [cocoon::internal::ns<NSView>(this) addSubview:cocoon::internal::native<NSView>(child)];
}"""},
                {"decl": "void pinToSuperview(const Insets& insets = {});",
                 "impl": """void {cls}::pinToSuperview(const Insets& insets)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    NSView* superview = native.superview;
    if (!superview) {
        return;
    }
    [NSLayoutConstraint activateConstraints:@[
        [native.topAnchor constraintEqualToAnchor:superview.topAnchor constant:insets.top],
        [native.leadingAnchor constraintEqualToAnchor:superview.leadingAnchor constant:insets.left],
        [superview.trailingAnchor constraintEqualToAnchor:native.trailingAnchor constant:insets.right],
        [superview.bottomAnchor constraintEqualToAnchor:native.bottomAnchor constant:insets.bottom],
    ]];
}"""},
                {"decl": "void pinToSafeArea(const Insets& insets = {});",
                 "impl": """void {cls}::pinToSafeArea(const Insets& insets)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    NSView* superview = native.superview;
    if (!superview) {
        return;
    }
    NSLayoutGuide* guide = superview.safeAreaLayoutGuide;
    [NSLayoutConstraint activateConstraints:@[
        [native.topAnchor constraintEqualToAnchor:guide.topAnchor constant:insets.top],
        [native.leadingAnchor constraintEqualToAnchor:guide.leadingAnchor constant:insets.left],
        [guide.trailingAnchor constraintEqualToAnchor:native.trailingAnchor constant:insets.right],
        [guide.bottomAnchor constraintEqualToAnchor:native.bottomAnchor constant:insets.bottom],
    ]];
}"""},
                {"decl": "void centerInSuperview();",
                 "impl": """void {cls}::centerInSuperview()
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    NSView* superview = native.superview;
    if (!superview) {
        return;
    }
    [NSLayoutConstraint activateConstraints:@[
        [native.centerXAnchor constraintEqualToAnchor:superview.centerXAnchor],
        [native.centerYAnchor constraintEqualToAnchor:superview.centerYAnchor],
    ]];
}"""},
                {"decl": "void setFixedWidth(double width);",
                 "impl": "void {cls}::setFixedWidth(double width) { [[cocoon::internal::ns<NSView>(this).widthAnchor constraintEqualToConstant:width] setActive:YES]; }"},
                {"decl": "void setFixedHeight(double height);",
                 "impl": "void {cls}::setFixedHeight(double height) { [[cocoon::internal::ns<NSView>(this).heightAnchor constraintEqualToConstant:height] setActive:YES]; }"},
                {"decl": "void setFixedSize(double width, double height);",
                 "impl": "void {cls}::setFixedSize(double width, double height) { setFixedWidth(width); setFixedHeight(height); }"},
                {"decl": "void setMinimumSize(double width, double height);",
                 "impl": """void {cls}::setMinimumSize(double width, double height)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    [[native.widthAnchor constraintGreaterThanOrEqualToConstant:width] setActive:YES];
    [[native.heightAnchor constraintGreaterThanOrEqualToConstant:height] setActive:YES];
}"""},
                {"decl": "void setMaximumSize(double width, double height);",
                 "impl": """void {cls}::setMaximumSize(double width, double height)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    [[native.widthAnchor constraintLessThanOrEqualToConstant:width] setActive:YES];
    [[native.heightAnchor constraintLessThanOrEqualToConstant:height] setActive:YES];
}"""},
                {"decl": "void setBackgroundColor(const Color& color);",
                 "impl": """void {cls}::setBackgroundColor(const Color& color)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    native.wantsLayer = YES;
    native.layer.backgroundColor = color.isNull() ? nil : cocoon::internal::native<NSColor>(color).CGColor;
}"""},
                {"decl": "void setLayerCornerRadius(double radius);",
                 "impl": """void {cls}::setLayerCornerRadius(double radius)
{
    NSView* native = cocoon::internal::ns<NSView>(this);
    native.wantsLayer = YES;
    native.layer.cornerRadius = radius;
    native.layer.masksToBounds = radius > 0;
}"""},
            ],
        },
        {
            "name": "ViewController", "ns": "NSViewController",
            "forward": ["View"],
            "ctors": [{"params": [["const View&", "view"]], "objc": "cocoon::internal::makeViewController(view)", "implicit": True}],
        },
        {
            "name": "Control", "ns": "NSControl", "base": "View",
        },
        {
            "name": "Button", "ns": "NSButton", "base": "Control",
            "ctors": [{"params": [["const std::string&", "title", "\"\""]], "objc": "[NSButton buttonWithTitle:cocoon::internal::to(title) target:nil action:nil]"}],
            "extra": [{"decl": "void performClick();", "impl": "void {cls}::performClick() { [cocoon::internal::ns<{ns}>(this) performClick:nil]; }"}],
            "signals": [{"name": "clicked"}],
        },
        {
            "name": "CheckBox", "alias": True, "ns": "NSButton", "base": "Button",
            "ctors": [{"params": [["const std::string&", "title", "\"\""]], "objc": "[NSButton checkboxWithTitle:cocoon::internal::to(title) target:nil action:nil]"}],
            "signals": [{"name": "toggled", "args": [["bool", "[(NSButton*)sender state] == NSControlStateValueOn"]], "also": ["clicked"]}],
        },
        {
            "name": "RadioButton", "alias": True, "ns": "NSButton", "base": "Button",
            "ctors": [{"params": [["const std::string&", "title", "\"\""]], "objc": "[NSButton radioButtonWithTitle:cocoon::internal::to(title) target:nil action:nil]"}],
            "signals": [{"name": "toggled", "args": [["bool", "[(NSButton*)sender state] == NSControlStateValueOn"]], "also": ["clicked"]}],
        },
        {
            "name": "TextField", "ns": "NSTextField", "base": "Control",
            "ctors": [{"params": [["const std::string&", "text", "\"\""]], "objc": "[NSTextField textFieldWithString:cocoon::internal::to(text)]"}],
            "signals": [
                {"name": "editingFinished"},
                {"name": "textChanged", "notification": "NSControlTextDidChangeNotification", "args": [["std::string", "cocoon::internal::from(((NSTextField*)note.object).stringValue)"]]},
            ],
        },
        {
            "name": "Label", "alias": True, "ns": "NSTextField", "base": "TextField",
            "ctors": [{"params": [["const std::string&", "text", "\"\""]], "objc": "[NSTextField labelWithString:cocoon::internal::to(text)]"}],
        },
        {
            "name": "SecureTextField", "ns": "NSSecureTextField", "base": "TextField",
            "ctors": [{"objc": "[[NSSecureTextField alloc] init]"}],
        },
        {
            "name": "SearchField", "ns": "NSSearchField", "base": "TextField",
            "ctors": [{"objc": "[[NSSearchField alloc] init]"}],
        },
        {
            "name": "Slider", "ns": "NSSlider", "base": "Control",
            "ctors": [{"params": [["double", "minValue", "0"], ["double", "maxValue", "1"], ["double", "value", "0"]], "objc": "[NSSlider sliderWithValue:value minValue:minValue maxValue:maxValue target:nil action:nil]"}],
            "extra": [
                {"decl": "double value() const;", "impl": "double {cls}::value() const { return cocoon::internal::ns<{ns}>(this).doubleValue; }"},
                {"decl": "void setValue(double value);", "impl": "void {cls}::setValue(double value) { cocoon::internal::ns<{ns}>(this).doubleValue = value; }"},
            ],
            "signals": [{"name": "valueChanged", "args": [["double", "[(NSSlider*)sender doubleValue]"]]}],
        },
        {
            "name": "Stepper", "ns": "NSStepper", "base": "Control",
            "ctors": [{"objc": "[[NSStepper alloc] init]"}],
            "extra": [
                {"decl": "double value() const;", "impl": "double {cls}::value() const { return cocoon::internal::ns<{ns}>(this).doubleValue; }"},
                {"decl": "void setValue(double value);", "impl": "void {cls}::setValue(double value) { cocoon::internal::ns<{ns}>(this).doubleValue = value; }"},
            ],
            "signals": [{"name": "valueChanged", "args": [["double", "[(NSStepper*)sender doubleValue]"]]}],
        },
        {
            "name": "Switch", "ns": "NSSwitch", "base": "Control",
            "ctors": [{"objc": "[[NSSwitch alloc] init]"}],
            "extra": [
                {"decl": "bool isOn() const;", "impl": "bool {cls}::isOn() const { return cocoon::internal::ns<{ns}>(this).state == NSControlStateValueOn; }"},
                {"decl": "void setOn(bool on);", "impl": "void {cls}::setOn(bool on) { cocoon::internal::ns<{ns}>(this).state = on ? NSControlStateValueOn : NSControlStateValueOff; }"},
            ],
            "signals": [{"name": "toggled", "args": [["bool", "[(NSSwitch*)sender state] == NSControlStateValueOn"]]}],
        },
        {
            "name": "ProgressIndicator", "ns": "NSProgressIndicator", "base": "View",
            "ctors": [{"objc": "[[NSProgressIndicator alloc] init]"}],
            "extra": [
                {"decl": "void start();", "impl": "void {cls}::start() { [cocoon::internal::ns<{ns}>(this) startAnimation:nil]; }"},
                {"decl": "void stop();", "impl": "void {cls}::stop() { [cocoon::internal::ns<{ns}>(this) stopAnimation:nil]; }"},
            ],
        },
        {
            "name": "PopUpButton", "ns": "NSPopUpButton", "base": "Button",
            "ctors": [{"objc": "[[NSPopUpButton alloc] initWithFrame:NSZeroRect pullsDown:NO]"}],
            "signals": [{"name": "selectionChanged", "args": [["std::int64_t", "[(NSPopUpButton*)sender indexOfSelectedItem]"]], "also": ["clicked"]}],
        },
        {
            "name": "ComboBox", "ns": "NSComboBox", "base": "TextField",
            "ctors": [{"objc": "[[NSComboBox alloc] init]"}],
            "extra": [{"decl": "void addItem(const std::string& item);", "impl": "void {cls}::addItem(const std::string& item) { [cocoon::internal::ns<{ns}>(this) addItemWithObjectValue:cocoon::internal::to(item)]; }"}],
            "signals": [{"name": "selectionChanged", "notification": "NSComboBoxSelectionDidChangeNotification", "args": [["std::int64_t", "((NSComboBox*)note.object).indexOfSelectedItem"]]}],
        },
        {
            "name": "SegmentedControl", "ns": "NSSegmentedControl", "base": "Control",
            "ctors": [{"objc": "[[NSSegmentedControl alloc] init]"}],
            "signals": [{"name": "selectionChanged", "args": [["std::int64_t", "[(NSSegmentedControl*)sender selectedSegment]"]]}],
        },
        {
            "name": "DatePicker", "ns": "NSDatePicker", "base": "Control",
            "ctors": [{"objc": "[[NSDatePicker alloc] init]"}],
            "extra": [
                {"decl": "double timestamp() const;", "impl": "double {cls}::timestamp() const { return cocoon::internal::ns<{ns}>(this).dateValue.timeIntervalSince1970; }"},
                {"decl": "void setTimestamp(double seconds);", "impl": "void {cls}::setTimestamp(double seconds) { cocoon::internal::ns<{ns}>(this).dateValue = [NSDate dateWithTimeIntervalSince1970:seconds]; }"},
            ],
            "signals": [{"name": "dateChanged", "args": [["double", "((NSDatePicker*)sender).dateValue.timeIntervalSince1970"]]}],
        },
        {
            "name": "ColorWell", "ns": "NSColorWell", "base": "Control",
            "ctors": [{"objc": "[[NSColorWell alloc] init]"}],
            "signals": [{"name": "colorChanged", "args": [["Color", "cocoon::internal::wrap<Color>(((NSColorWell*)sender).color)"]]}],
        },
        {
            "name": "LevelIndicator", "ns": "NSLevelIndicator", "base": "Control",
            "ctors": [{"objc": "[[NSLevelIndicator alloc] init]"}],
        },
        {
            "name": "ImageView", "ns": "NSImageView", "base": "Control",
            "ctors": [{"params": [["const Image&", "image", "Image()"]], "objc": "cocoon::internal::makeImageView(image)"}],
        },
        {
            "name": "Box", "ns": "NSBox", "base": "View",
            "ctors": [{"objc": "[[NSBox alloc] init]"}],
        },
        {
            "name": "Separator", "alias": True, "ns": "NSBox", "base": "Box",
            "ctors": [{"objc": "cocoon::internal::makeSeparator()"}],
        },
        {
            "name": "ScrollView", "ns": "NSScrollView", "base": "View",
            "ctors": [{"objc": "[[NSScrollView alloc] init]"}],
        },
        {
            "name": "StackView", "ns": "NSStackView", "base": "View",
            "ctors": [{"objc": "[[NSStackView alloc] init]"}],
            "extra": [
                {"decl": "void addArrangedSubviews(const std::vector<View>& views);",
                 "impl": """void {cls}::addArrangedSubviews(const std::vector<View>& views)
{
    for (const View& view : views) {
        [cocoon::internal::ns<NSStackView>(this) addArrangedSubview:cocoon::internal::native<NSView>(view)];
    }
}"""},
            ],
        },
        {
            "name": "VStack", "alias": True, "ns": "NSStackView", "base": "StackView",
            "ctors": [{"objc": "cocoon::internal::makeStack(NSUserInterfaceLayoutOrientationVertical)"}],
        },
        {
            "name": "HStack", "alias": True, "ns": "NSStackView", "base": "StackView",
            "ctors": [{"objc": "cocoon::internal::makeStack(NSUserInterfaceLayoutOrientationHorizontal)"}],
        },
        {
            "name": "VisualEffectView", "ns": "NSVisualEffectView", "base": "View",
            "ctors": [{"objc": "[[NSVisualEffectView alloc] init]"}],
        },
        {
            "name": "GlassEffectView", "ns": "NSGlassEffectView", "base": "View",
            "ctors": [{"objc": "[[NSGlassEffectView alloc] init]"}],
        },
        {
            "name": "GlassEffectContainerView", "ns": "NSGlassEffectContainerView", "base": "View",
            "ctors": [{"objc": "[[NSGlassEffectContainerView alloc] init]"}],
        },
        {
            "name": "GridView", "ns": "NSGridView", "base": "View",
            "ctors": [{"objc": "[[NSGridView alloc] init]"}],
            "extra": [
                {"decl": "void addRow(const std::vector<View>& views);",
                 "impl": """void {cls}::addRow(const std::vector<View>& views)
{
    NSMutableArray<NSView*>* row = [NSMutableArray arrayWithCapacity:views.size()];
    for (const View& view : views) {
        [row addObject:view.isNull() ? NSGridCell.emptyContentView : cocoon::internal::native<NSView>(view)];
    }
    [cocoon::internal::ns<NSGridView>(this) addRowWithViews:row];
}"""},
            ],
        },
        {
            "name": "TabView", "ns": "NSTabView", "base": "View",
            "ctors": [{"objc": "[[NSTabView alloc] init]"}],
            "extra": [
                {"decl": "int addTab(const std::string& label, const View& content);",
                 "impl": """int {cls}::addTab(const std::string& label, const View& content)
{
    NSTabView* tab = cocoon::internal::ns<NSTabView>(this);
    NSTabViewItem* item = [[NSTabViewItem alloc] initWithIdentifier:cocoon::internal::to(label)];
    item.label = cocoon::internal::to(label);
    item.view = cocoon::internal::native<NSView>(content);
    [tab addTabViewItem:item];
    return static_cast<int>(tab.numberOfTabViewItems) - 1;
}"""},
                {"decl": "int currentIndex() const;",
                 "impl": """int {cls}::currentIndex() const
{
    NSTabView* tab = cocoon::internal::ns<NSTabView>(this);
    return static_cast<int>([tab indexOfTabViewItem:tab.selectedTabViewItem]);
}"""},
                {"decl": "void setCurrentIndex(int index);",
                 "impl": "void {cls}::setCurrentIndex(int index) { [cocoon::internal::ns<NSTabView>(this) selectTabViewItemAtIndex:index]; }"},
            ],
        },
        {
            "name": "SplitViewItem", "ns": "NSSplitViewItem",
            "forward": ["ViewController"],
            "ctors": [{"params": [["const ViewController&", "controller"]], "objc": "[NSSplitViewItem splitViewItemWithViewController:cocoon::internal::native<NSViewController>(controller)]"}],
            "extra": [
                {"decl": "static SplitViewItem sidebar(const ViewController& controller);",
                 "impl": "SplitViewItem {cls}::sidebar(const ViewController& controller) { return cocoon::internal::wrap<SplitViewItem>([NSSplitViewItem sidebarWithViewController:cocoon::internal::native<NSViewController>(controller)]); }"},
                {"decl": "static SplitViewItem inspector(const ViewController& controller);",
                 "impl": "SplitViewItem {cls}::inspector(const ViewController& controller) { return cocoon::internal::wrap<SplitViewItem>([NSSplitViewItem inspectorWithViewController:cocoon::internal::native<NSViewController>(controller)]); }"},
                {"decl": "void setCollapsedAnimated(bool collapsed);",
                 "impl": "void {cls}::setCollapsedAnimated(bool collapsed) { cocoon::internal::ns<{ns}>(this).animator.collapsed = collapsed; }"},
            ],
        },
        {
            "name": "SplitViewController", "ns": "NSSplitViewController",
            "forward": ["View"],
            "ctors": [{"objc": "cocoon::internal::makeSplitViewController()"}],
            "extra": [
                {"decl": "SplitViewItem addSidebar(const ViewController& controller, double minimumWidth = 200, double maximumWidth = 320);",
                 "impl": """SplitViewItem {cls}::addSidebar(const ViewController& controller, double minimumWidth, double maximumWidth)
{
    SplitViewItem item = SplitViewItem::sidebar(controller);
    item.setMinimumThickness(minimumWidth);
    item.setMaximumThickness(maximumWidth);
    addSplitViewItem(item);
    return item;
}"""},
                {"decl": "SplitViewItem addContent(const ViewController& controller, double minimumWidth = 300);",
                 "impl": """SplitViewItem {cls}::addContent(const ViewController& controller, double minimumWidth)
{
    SplitViewItem item(controller);
    item.setMinimumThickness(minimumWidth);
    addSplitViewItem(item);
    return item;
}"""},
                {"decl": "SplitViewItem addInspector(const ViewController& controller, double minimumWidth = 240, double maximumWidth = 400);",
                 "impl": """SplitViewItem {cls}::addInspector(const ViewController& controller, double minimumWidth, double maximumWidth)
{
    SplitViewItem item = SplitViewItem::inspector(controller);
    item.setMinimumThickness(minimumWidth);
    item.setMaximumThickness(maximumWidth);
    addSplitViewItem(item);
    return item;
}"""},
            ],
        },
        {
            "name": "MenuItem", "ns": "NSMenuItem",
            "includes": ["standard_action.h"],
            "forward": ["Menu"],
            "ctors": [{"params": [["const std::string&", "title", "\"\""], ["const std::string&", "shortcut", "\"\""]], "objc": "cocoon::internal::makeMenuItem(title, shortcut)"}],
            "signals": [{"name": "triggered"}],
            "extra": [
                {"decl": "static MenuItem separator();",
                 "impl": "MenuItem {cls}::separator() { return cocoon::internal::wrap<MenuItem>([NSMenuItem separatorItem]); }"},
                {"decl": "static MenuItem standard(StandardAction action);",
                 "impl": "MenuItem {cls}::standard(StandardAction action) { return cocoon::internal::wrap<MenuItem>(cocoon::internal::makeStandardMenuItem(action)); }"},
                {"decl": "void setShortcut(const std::string& shortcut);",
                 "impl": "void {cls}::setShortcut(const std::string& shortcut) { cocoon::internal::applyShortcut(cocoon::internal::ns<{ns}>(this), shortcut); }"},
                {"decl": "bool isEnabled() const;",
                 "impl": "bool {cls}::isEnabled() const { return cocoon::internal::ns<{ns}>(this).enabled; }"},
                {"decl": "void setEnabled(bool enabled);",
                 "impl": """void {cls}::setEnabled(bool enabled)
{
    NSMenuItem* item = cocoon::internal::ns<{ns}>(this);
    item.enabled = enabled;
    item.representedObject = enabled ? nil : @NO;
}"""},
                {"decl": "bool isChecked() const;",
                 "impl": "bool {cls}::isChecked() const { return cocoon::internal::ns<{ns}>(this).state == NSControlStateValueOn; }"},
                {"decl": "void setChecked(bool checked);",
                 "impl": "void {cls}::setChecked(bool checked) { cocoon::internal::ns<{ns}>(this).state = checked ? NSControlStateValueOn : NSControlStateValueOff; }"},
            ],
        },
        {
            "name": "Menu", "ns": "NSMenu",
            "includes": ["standard_action.h", "<functional>"],
            "ctors": [{"params": [["const std::string&", "title", "\"\""]], "objc": "[[NSMenu alloc] initWithTitle:cocoon::internal::to(title)]"}],
            "extra": [
                {"decl": "MenuItem addItem(const std::string& title, const std::string& shortcut = {}, std::function<void()> onTriggered = {});",
                 "impl": """MenuItem {cls}::addItem(const std::string& title, const std::string& shortcut, std::function<void()> onTriggered)
{
    MenuItem item(title, shortcut);
    if (onTriggered) {
        item.triggered().connect(std::move(onTriggered));
    }
    addItem(item);
    return item;
}"""},
                {"decl": "MenuItem addSeparator();",
                 "impl": """MenuItem {cls}::addSeparator()
{
    MenuItem item = MenuItem::separator();
    addItem(item);
    return item;
}"""},
                {"decl": "MenuItem addStandardItem(StandardAction action);",
                 "impl": """MenuItem {cls}::addStandardItem(StandardAction action)
{
    MenuItem item = MenuItem::standard(action);
    addItem(item);
    return item;
}"""},
                {"decl": "Menu addMenu(const std::string& title);",
                 "impl": """Menu {cls}::addMenu(const std::string& title)
{
    Menu submenu(title);
    MenuItem item(title);
    item.setSubmenu(submenu);
    addItem(item);
    return submenu;
}"""},
                {"decl": "Menu findMenu(const std::string& title) const;",
                 "impl": """Menu {cls}::findMenu(const std::string& title) const
{
    for (NSMenuItem* item in cocoon::internal::ns<{ns}>(this).itemArray) {
        if (item.submenu && [item.title isEqualToString:cocoon::internal::to(title)]) {
            return cocoon::internal::wrap<Menu>(item.submenu);
        }
    }
    return Menu(nullptr);
}"""},
                {"decl": "static Menu standardMenuBar(const std::string& applicationName);",
                 "impl": """Menu {cls}::standardMenuBar(const std::string& applicationName)
{
    Menu bar;
    Menu application = bar.addMenu(applicationName);
    application.addStandardItem(StandardAction::About).setTitle("About " + applicationName);
    application.addSeparator();
    application.addStandardItem(StandardAction::Hide).setTitle("Hide " + applicationName);
    application.addStandardItem(StandardAction::HideOthers);
    application.addStandardItem(StandardAction::ShowAll);
    application.addSeparator();
    application.addStandardItem(StandardAction::Quit).setTitle("Quit " + applicationName);
    Menu file = bar.addMenu("File");
    file.addStandardItem(StandardAction::Close);
    Menu edit = bar.addMenu("Edit");
    edit.addStandardItem(StandardAction::Undo);
    edit.addStandardItem(StandardAction::Redo);
    edit.addSeparator();
    edit.addStandardItem(StandardAction::Cut);
    edit.addStandardItem(StandardAction::Copy);
    edit.addStandardItem(StandardAction::Paste);
    edit.addStandardItem(StandardAction::SelectAll);
    Menu view = bar.addMenu("View");
    view.addStandardItem(StandardAction::ToggleSidebar);
    view.addStandardItem(StandardAction::ToggleFullScreen);
    Menu window = bar.addMenu("Window");
    window.addStandardItem(StandardAction::Minimize);
    window.addStandardItem(StandardAction::Zoom);
    window.addSeparator();
    window.addStandardItem(StandardAction::BringAllToFront);
    Menu help = bar.addMenu("Help");
    help.addStandardItem(StandardAction::ShowHelp).setTitle(applicationName + " Help");
    return bar;
}"""},
            ],
        },
        {
            "name": "ToolbarItem", "ns": "NSToolbarItem",
            "ctors": [{"params": [["const std::string&", "identifier"], ["const std::string&", "label"], ["const std::string&", "symbol"]], "objc": "cocoon::internal::makeToolbarItem(identifier, label, symbol)"}],
            "signals": [{"name": "clicked"}],
        },
        {
            "name": "SearchToolbarItem", "ns": "NSSearchToolbarItem", "base": "ToolbarItem",
            "ctors": [{"params": [["const std::string&", "identifier", "\"search\""]], "objc": "[[NSSearchToolbarItem alloc] initWithItemIdentifier:cocoon::internal::to(identifier)]"}],
            "signals": [{"name": "searched", "target": "((NSSearchToolbarItem*)host).searchField", "args": [["std::string", "cocoon::internal::from(((NSSearchField*)sender).stringValue)"]]}],
        },
        {
            "name": "Toolbar", "ns": "NSToolbar",
            "includes": ["<functional>"],
            "forward": ["ToolbarItem", "SearchToolbarItem"],
            "ctors": [{"params": [["const std::string&", "identifier"]], "objc": "cocoon::internal::makeToolbar(identifier)"}],
            "ctorBody": "cocoon::internal::installToolbarProvider(handle());",
            "extra": [
                {"decl": "void addItem(const ToolbarItem& item);",
                 "impl": "void {cls}::addItem(const ToolbarItem& item) { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), cocoon::internal::to(item.itemIdentifier()), cocoon::internal::native<NSToolbarItem>(item), true, false); }"},
                {"decl": "void addRequiredItem(const ToolbarItem& item);",
                 "impl": "void {cls}::addRequiredItem(const ToolbarItem& item) { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), cocoon::internal::to(item.itemIdentifier()), cocoon::internal::native<NSToolbarItem>(item), true, true); }"},
                {"decl": "void addAllowedItem(const ToolbarItem& item);",
                 "impl": "void {cls}::addAllowedItem(const ToolbarItem& item) { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), cocoon::internal::to(item.itemIdentifier()), cocoon::internal::native<NSToolbarItem>(item), false, false); }"},
                {"decl": "ToolbarItem addButton(const std::string& identifier, const std::string& label, const std::string& symbol, std::function<void()> onClicked = {});",
                 "impl": """ToolbarItem {cls}::addButton(const std::string& identifier, const std::string& label, const std::string& symbol, std::function<void()> onClicked)
{
    ToolbarItem item(identifier, label, symbol);
    if (onClicked) {
        item.clicked().connect(std::move(onClicked));
    }
    addItem(item);
    return item;
}"""},
                {"decl": "SearchToolbarItem addSearchField(const std::string& identifier, std::function<void(const std::string&)> onSearched = {});",
                 "impl": """SearchToolbarItem {cls}::addSearchField(const std::string& identifier, std::function<void(const std::string&)> onSearched)
{
    SearchToolbarItem item(identifier);
    if (onSearched) {
        item.searched().connect(std::move(onSearched));
    }
    addItem(item);
    return item;
}"""},
                {"decl": "void addFlexibleSpace();",
                 "impl": "void {cls}::addFlexibleSpace() { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), NSToolbarFlexibleSpaceItemIdentifier, nil, true, false); }"},
                {"decl": "void addSpace();",
                 "impl": "void {cls}::addSpace() { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), NSToolbarSpaceItemIdentifier, nil, true, false); }"},
                {"decl": "void addSidebarToggle();",
                 "impl": "void {cls}::addSidebarToggle() { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), NSToolbarToggleSidebarItemIdentifier, nil, true, true); }"},
                {"decl": "void addSidebarTrackingSeparator();",
                 "impl": "void {cls}::addSidebarTrackingSeparator() { cocoon::internal::toolbarAdd(cocoon::internal::ns<{ns}>(this), NSToolbarSidebarTrackingSeparatorItemIdentifier, nil, true, true); }"},
            ],
        },
        {
            "name": "Window", "ns": "NSWindow",
            "includes": ["<functional>"],
            "forward": ["ViewController"],
            "ctors": [{"params": [
                ["const std::string&", "title", "\"\""],
                ["Size", "size", "Size{800, 600}"],
                ["WindowStyle", "style", "WindowStyle::Titled | WindowStyle::Closable | WindowStyle::Miniaturizable | WindowStyle::Resizable"],
            ], "objc": "cocoon::internal::makeWindow(title, size, style)"}],
            "extra": [
                {"decl": "void show();", "impl": "void {cls}::show() { cocoon::internal::showWindow(cocoon::internal::ns<{ns}>(this)); }"},
                {"decl": "void hide();", "impl": "void {cls}::hide() { [cocoon::internal::ns<{ns}>(this) orderOut:nil]; }"},
                {"decl": "void close();", "impl": "void {cls}::close() { [cocoon::internal::ns<{ns}>(this) close]; }"},
                {"decl": "void center();", "impl": "void {cls}::center() { [cocoon::internal::ns<{ns}>(this) center]; }"},
                {"decl": "void minimize();", "impl": "void {cls}::minimize() { [cocoon::internal::ns<{ns}>(this) miniaturize:nil]; }"},
                {"decl": "void toggleFullScreen();", "impl": "void {cls}::toggleFullScreen() { [cocoon::internal::ns<{ns}>(this) toggleFullScreen:nil]; }"},
                {"decl": "void raise();", "impl": "void {cls}::raise() { [cocoon::internal::ns<{ns}>(this) makeKeyAndOrderFront:nil]; }"},
                {"decl": "bool isFullScreen() const;",
                 "impl": "bool {cls}::isFullScreen() const { return (cocoon::internal::ns<{ns}>(this).styleMask & NSWindowStyleMaskFullScreen) != 0; }"},
                {"decl": "void setContent(const ViewController& controller);",
                 "impl": """void {cls}::setContent(const ViewController& controller)
{
    NSWindow* native = cocoon::internal::ns<{ns}>(this);
    NSSize size = native.contentLayoutRect.size;
    native.contentViewController = cocoon::internal::native<NSViewController>(controller);
    [native setContentSize:size];
}"""},
                {"decl": "Size size() const;",
                 "impl": """Size {cls}::size() const
{
    NSWindow* native = cocoon::internal::ns<{ns}>(this);
    return cocoon::internal::from([native contentRectForFrameRect:native.frame].size);
}"""},
                {"decl": "void setAlwaysOnTop(bool alwaysOnTop);",
                 "impl": "void {cls}::setAlwaysOnTop(bool alwaysOnTop) { cocoon::internal::ns<{ns}>(this).level = alwaysOnTop ? NSFloatingWindowLevel : NSNormalWindowLevel; }"},
                {"decl": "void beginSheet(const Window& sheet, std::function<void()> onFinished = {});",
                 "impl": """void {cls}::beginSheet(const Window& sheet, std::function<void()> onFinished)
{
    [cocoon::internal::ns<{ns}>(this) beginSheet:cocoon::internal::native<NSWindow>(sheet)
                 completionHandler:^(NSModalResponse) {
                     if (onFinished) {
                         onFinished();
                     }
                 }];
}"""},
                {"decl": "void endSheet(const Window& sheet);",
                 "impl": "void {cls}::endSheet(const Window& sheet) { [cocoon::internal::ns<{ns}>(this) endSheet:cocoon::internal::native<NSWindow>(sheet)]; }"},
            ],
        },
        {
            "name": "Alert", "ns": "NSAlert",
            "forward": ["Window"],
            "includes": ["<functional>"],
            "ctors": [{"params": [
                ["const std::string&", "message", "\"\""],
                ["const std::string&", "informativeText", "\"\""],
                ["AlertStyle", "style", "AlertStyle::Informational"],
            ], "objc": "cocoon::internal::makeAlert(message, informativeText, style)"}],
            "extra": [
                {"decl": "int exec();",
                 "impl": "int {cls}::exec() { return static_cast<int>([cocoon::internal::ns<{ns}>(this) runModal] - NSAlertFirstButtonReturn); }"},
                {"decl": "void beginSheet(const Window& window, std::function<void(int)> onFinished = {});",
                 "impl": """void {cls}::beginSheet(const Window& window, std::function<void(int)> onFinished)
{
    [cocoon::internal::ns<{ns}>(this) beginSheetModalForWindow:cocoon::internal::native<NSWindow>(window)
                               completionHandler:^(NSModalResponse response) {
                                   if (onFinished) {
                                       onFinished(static_cast<int>(response - NSAlertFirstButtonReturn));
                                   }
                               }];
}"""},
            ],
        },
        {
            "name": "Application", "ns": "NSApplication",
            "includes": ["<functional>"],
            "forward": ["Menu"],
            "ctors": [{"params": [["int", "argc"], ["char**", "argv"]], "objc": "cocoon::internal::makeApplication()"}],
            "ctorBody": "setMenuBar(Menu::standardMenuBar(ProcessInfo().processName()));",
            "extra": [
                {"decl": "static Application instance();",
                 "impl": "Application {cls}::instance() { return cocoon::internal::wrap<Application>(NSApp); }"},
                {"decl": "int exec();",
                 "impl": """int {cls}::exec()
{
    [NSApp activate];
    [NSApp run];
    return 0;
}"""},
                {"decl": "void quit();", "impl": "void {cls}::quit() { [NSApp terminate:nil]; }"},
                {"decl": "void activate();", "impl": "void {cls}::activate() { [NSApp activate]; }"},
                {"decl": "void hide();", "impl": "void {cls}::hide() { [NSApp hide:nil]; }"},
                {"decl": "void setName(const std::string& name);",
                 "impl": "void {cls}::setName(const std::string& name) { NSProcessInfo.processInfo.processName = cocoon::internal::to(name); }"},
                {"decl": "void setDockBadge(const std::string& badge);",
                 "impl": "void {cls}::setDockBadge(const std::string& badge) { NSApp.dockTile.badgeLabel = cocoon::internal::to(badge); }"},
                {"decl": "void setMenuBar(const Menu& menu);",
                 "impl": """void {cls}::setMenuBar(const Menu& menu)
{
    NSMenu* native = cocoon::internal::native<NSMenu>(menu);
    NSApp.mainMenu = native;
    for (NSMenuItem* item in native.itemArray) {
        if ([item.title isEqualToString:@"Window"] && item.submenu) {
            NSApp.windowsMenu = item.submenu;
        }
        if ([item.title isEqualToString:@"Help"] && item.submenu) {
            NSApp.helpMenu = item.submenu;
        }
    }
}"""},
                {"decl": "static void postToMainThread(std::function<void()> function);",
                 "impl": """void {cls}::postToMainThread(std::function<void()> function)
{
    dispatch_async(dispatch_get_main_queue(), ^{
        function();
    });
}"""},
                {"decl": "static void singleShot(double seconds, std::function<void()> function);",
                 "impl": """void {cls}::singleShot(double seconds, std::function<void()> function)
{
    dispatch_after(dispatch_time(DISPATCH_TIME_NOW, static_cast<int64_t>(seconds * NSEC_PER_SEC)), dispatch_get_main_queue(), ^{
        function();
    });
}"""},
            ],
        },
    ],
}

SPEC["docs"] = {
    "Application": {"brief": "The running application (NSApplication): owns the event loop, the main menu and application level signals.",
                    "example": """#include <cocoon.h>

int main(int argc, char** argv)
{
    cocoon::Application app(argc, argv);
    app.set_name("Demo");
    cocoon::Window window("Demo", {640, 480});
    window.show();
    return app.exec();
}"""},
    "Window": {"brief": "A window (NSWindow). Windows stay alive while visible and are released when closed.",
               "example": """cocoon::Window window("Title", {800, 600});
cocoon::VStack content;
window.set_content(content);
window.set_toolbar_style(cocoon::ToolbarStyle::Unified);
window.will_close().connect([](cocoon::Notification) {});
window.show();"""},
    "View": {"brief": "The base of all views (NSView): hierarchy, geometry, Auto Layout helpers and appearance.",
             "example": """cocoon::View container;
cocoon::Button button("Press");
container.add_subview(button);
button.pin_to_superview(cocoon::Insets(12));
container.set_background_color(cocoon::Color(0.1, 0.2, 0.3));"""},
    "ViewController": {"brief": "A view controller (NSViewController). A View converts to a ViewController implicitly wherever one is needed.",
                       "example": """cocoon::View content;
cocoon::ViewController controller(content);
cocoon::Window window("Window", {400, 300});
window.set_content(controller);"""},
    "Button": {"brief": "A push button (NSButton).",
               "example": """cocoon::Button button("Click me");
button.set_bezel_style(cocoon::BezelStyle::Push);
button.clicked().connect([] {});"""},
    "CheckBox": {"brief": "A check box button.",
                 "example": """cocoon::CheckBox check("Enable feature");
check.toggled().connect([](bool on) {});"""},
    "RadioButton": {"brief": "A radio button.",
                    "example": """cocoon::RadioButton radio("Option A");
radio.toggled().connect([](bool on) {});"""},
    "TextField": {"brief": "An editable single line text field (NSTextField).",
                  "example": """cocoon::TextField field;
field.set_placeholder_string("Name");
field.text_changed().connect([](const std::string& text) {});
field.editing_finished().connect([] {});"""},
    "Label": {"brief": "A non-editable text label.",
              "example": """cocoon::Label label("Status");
label.set_string_value("Ready");
label.set_font(cocoon::Font::bold_system_font_of_size(14));"""},
    "SecureTextField": {"brief": "A password style text field.", "example": """cocoon::SecureTextField password;
password.set_placeholder_string("Password");"""},
    "SearchField": {"brief": "A search field (NSSearchField).", "example": """cocoon::SearchField search;
search.editing_finished().connect([] {});"""},
    "Slider": {"brief": "A slider control (NSSlider).",
               "example": """cocoon::Slider slider(0, 100, 50);
slider.value_changed().connect([](double value) {});"""},
    "Stepper": {"brief": "A stepper control (NSStepper).", "example": """cocoon::Stepper stepper;
stepper.set_max_value(10);
stepper.value_changed().connect([](double value) {});"""},
    "Switch": {"brief": "An on/off switch (NSSwitch).", "example": """cocoon::Switch toggle;
toggle.set_on(true);
toggle.toggled().connect([](bool on) {});"""},
    "ProgressIndicator": {"brief": "A progress bar or spinner.", "example": """cocoon::ProgressIndicator progress;
progress.set_max_value(100);
progress.set_double_value(40);
progress.start();"""},
    "PopUpButton": {"brief": "A pop-up or pull-down menu button.", "example": """cocoon::PopUpButton popup;
popup.add_items_with_titles({"Small", "Medium", "Large"});
popup.selection_changed().connect([](std::int64_t index) {});"""},
    "ComboBox": {"brief": "A text field with a drop-down list.", "example": """cocoon::ComboBox combo;
combo.add_item("First");
combo.add_item("Second");"""},
    "SegmentedControl": {"brief": "A segmented control.", "example": """cocoon::SegmentedControl segments;
segments.set_segment_count(2);
segments.set_label("One", 0);
segments.set_label("Two", 1);
segments.selection_changed().connect([](std::int64_t segment) {});"""},
    "DatePicker": {"brief": "A date and time picker.", "example": """cocoon::DatePicker picker;
picker.set_timestamp(0);
picker.date_changed().connect([](double seconds) {});"""},
    "ColorWell": {"brief": "A color selection well.", "example": """cocoon::ColorWell well;
well.color_changed().connect([](cocoon::Color color) {});"""},
    "LevelIndicator": {"brief": "A level / rating indicator.", "example": """cocoon::LevelIndicator level;
level.set_max_value(10);
level.set_double_value(7);"""},
    "ImageView": {"brief": "A view displaying an image.", "example": """cocoon::ImageView view(cocoon::Image::symbol("star"));
view.set_content_tint_color(cocoon::Color::system_yellow_color());"""},
    "Box": {"brief": "A titled or decorated box (NSBox).", "example": """cocoon::Box box;
box.set_title("Group");
cocoon::VStack content;
box.set_content_view(content);"""},
    "Separator": {"brief": "A horizontal or vertical separator line.", "example": """cocoon::VStack stack;
stack.add_arranged_subview(cocoon::Separator());"""},
    "ScrollView": {"brief": "A scrolling container (NSScrollView).", "example": """cocoon::ScrollView scroll;
cocoon::VStack content;
scroll.set_has_vertical_scroller(true);
scroll.set_document_view(content);"""},
    "StackView": {"brief": "A stack of arranged subviews (NSStackView).", "example": """cocoon::StackView stack;
stack.set_spacing(8);
stack.add_arranged_subview(cocoon::Button("A"));
stack.add_arranged_subview(cocoon::Button("B"));"""},
    "VStack": {"brief": "A vertical stack view.", "example": """cocoon::VStack stack;
stack.set_spacing(12);
stack.set_edge_insets(cocoon::Insets(24));
stack.add_arranged_subview(cocoon::Label("Hello"));"""},
    "HStack": {"brief": "A horizontal stack view.", "example": """cocoon::HStack row;
row.add_arranged_subview(cocoon::Button("OK"));
row.add_arranged_subview(cocoon::Button("Cancel"));"""},
    "VisualEffectView": {"brief": "A translucent vibrancy/blur background (NSVisualEffectView).", "example": """cocoon::VisualEffectView backdrop;
backdrop.set_material(cocoon::VisualEffectMaterial::Sidebar);"""},
    "GlassEffectView": {"brief": "A Liquid Glass surface (NSGlassEffectView, macOS 26).", "example": """cocoon::GlassEffectView glass;
glass.set_corner_radius(20);
cocoon::HStack content;
glass.set_content_view(content);"""},
    "GlassEffectContainerView": {"brief": "Groups glass views so they blend (NSGlassEffectContainerView, macOS 26).", "example": """cocoon::GlassEffectContainerView container;
container.set_spacing(24);
cocoon::GlassEffectView glass;
container.set_content_view(glass);"""},
    "GridView": {"brief": "A grid layout (NSGridView).", "example": """cocoon::GridView grid;
grid.add_row({cocoon::View(cocoon::Label("Name")), cocoon::View(cocoon::TextField())});"""},
    "TabView": {"brief": "A tabbed container (NSTabView).", "example": """cocoon::TabView tabs;
cocoon::VStack general;
tabs.add_tab("General", general);
tabs.selection_changed().connect([](int index) {});"""},
    "SplitViewController": {"brief": "A split view controller that supports sidebars, content and inspectors with Liquid Glass sidebars (NSSplitViewController).", "example": """cocoon::SplitViewController split;
cocoon::SidebarList sidebar;
cocoon::VStack content;
split.add_sidebar(sidebar);
split.add_content(content);
cocoon::Window window("Split", {900, 600});
window.set_content(split);"""},
    "SplitViewItem": {"brief": "One pane of a SplitViewController.", "example": """cocoon::SplitViewController split;
cocoon::View content;
cocoon::SplitViewItem item = split.add_content(content);
item.set_minimum_thickness(300);"""},
    "Menu": {"brief": "A menu or menu bar (NSMenu). Menu::standard_menu_bar builds the standard application menus.", "example": """cocoon::Menu bar = cocoon::Menu::standard_menu_bar("Demo");
cocoon::Menu file = bar.find_menu("File");
cocoon::MenuItem open("Open...", "Cmd+O");
open.triggered().connect([] {});
file.insert_item(open, 0);
cocoon::Application app(0, nullptr);
app.set_menu_bar(bar);"""},
    "MenuItem": {"brief": "A menu item (NSMenuItem). Shortcuts use strings such as \"Cmd+Shift+N\".", "example": """cocoon::MenuItem item("Rename", "Cmd+R");
item.set_enabled(true);
item.triggered().connect([] {});"""},
    "Toolbar": {"brief": "A customizable window toolbar (NSToolbar). Stable identifiers let the user customization be saved.", "example": """cocoon::Toolbar toolbar("com.example.toolbar");
toolbar.add_sidebar_toggle();
toolbar.add_button("add", "Add", "plus", [] {});
toolbar.add_allowed_item(cocoon::ToolbarItem("share", "Share", "square.and.arrow.up"));
toolbar.add_flexible_space();
toolbar.add_search_field("search");
toolbar.set_autosaves_configuration(true);
cocoon::Window window("Window", {800, 600});
window.set_toolbar(toolbar);"""},
    "ToolbarItem": {"brief": "A toolbar item (NSToolbarItem).", "example": """cocoon::ToolbarItem item("share", "Share", "square.and.arrow.up");
item.clicked().connect([] {});"""},
    "SearchToolbarItem": {"brief": "A search field toolbar item (NSSearchToolbarItem).", "example": """cocoon::SearchToolbarItem item("search");
item.searched().connect([](const std::string& text) {});"""},
    "Alert": {"brief": "A modal alert (NSAlert).", "example": """cocoon::Alert alert("Delete file?", "This cannot be undone.", cocoon::AlertStyle::Warning);
alert.add_button_with_title("Delete");
alert.add_button_with_title("Cancel");
int pressed = alert.exec();"""},
    "Color": {"brief": "A color (NSColor).", "example": """cocoon::Color brand(0.2, 0.4, 0.9);
cocoon::Color label = cocoon::Color::label_color();"""},
    "Font": {"brief": "A font (NSFont).", "example": """cocoon::Font title = cocoon::Font::bold_system_font_of_size(24);
cocoon::Font body = cocoon::Font::system_font_of_size(13);"""},
    "Image": {"brief": "An image (NSImage).", "example": """cocoon::Image star = cocoon::Image::symbol("star");
cocoon::Image photo = cocoon::Image::image_named("photo");"""},
    "ProcessInfo": {"brief": "Information about the running process (NSProcessInfo).", "example": """cocoon::ProcessInfo info;
std::string name = info.process_name();"""},
}
