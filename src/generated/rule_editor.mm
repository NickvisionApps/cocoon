#include "generated/rule_editor.h"
#include "internal.h"

@interface AKRuleEditorDelegate : NSObject <NSRuleEditorDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKRuleEditorDelegate

- (NSInteger)ruleEditor:(NSRuleEditor*)editor numberOfChildrenForCriterion:(id)criterion withRowType:(NSRuleEditorRowType)rowType
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::RuleEditor, std::int64_t(cocoon::Object, cocoon::RuleEditorRowType)>::emit((__bridge void*)strongHost, "number_of_children_for_criterion_with_row_type", cocoon::internal::wrap<cocoon::Object>(criterion), static_cast<cocoon::RuleEditorRowType>(rowType));
    return static_cast<::NSInteger>(__r);
}

- (id)ruleEditor:(NSRuleEditor*)editor child:(NSInteger)index forCriterion:(id)criterion withRowType:(NSRuleEditorRowType)rowType
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::RuleEditor, cocoon::Object(std::int64_t, cocoon::Object, cocoon::RuleEditorRowType)>::emit((__bridge void*)strongHost, "child_for_criterion_with_row_type", static_cast<std::int64_t>(index), cocoon::internal::wrap<cocoon::Object>(criterion), static_cast<cocoon::RuleEditorRowType>(rowType));
    return cocoon::internal::native_id(__r);
}

- (id)ruleEditor:(NSRuleEditor*)editor displayValueForCriterion:(id)criterion inRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::RuleEditor, cocoon::Object(cocoon::Object, std::int64_t)>::emit((__bridge void*)strongHost, "display_value_for_criterion_in_row", cocoon::internal::wrap<cocoon::Object>(criterion), static_cast<std::int64_t>(row));
    return cocoon::internal::native_id(__r);
}

- (NSDictionary<NSRuleEditorPredicatePartKey, id>*)ruleEditor:(NSRuleEditor*)editor predicatePartsForCriterion:(id)criterion withDisplayValue:(id)value inRow:(NSInteger)row
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::RuleEditor, std::map<std::string, cocoon::Object>(cocoon::Object, cocoon::Object, std::int64_t)>::emit((__bridge void*)strongHost, "predicate_parts_for_criterion_with_display_value_in_row", cocoon::internal::wrap<cocoon::Object>(criterion), cocoon::internal::wrap<cocoon::Object>(value), static_cast<std::int64_t>(row));
    return cocoon::internal::to_dictionary(__r, [](const std::string& k) -> id
                             {
                                 return cocoon::internal::to(k);
                             },
                             [](const cocoon::Object& v) -> id
                             {
                                 return cocoon::internal::native_id(v);
                             });
}

- (void)ruleEditorRowsDidChange:(NSNotification*)notification
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::RuleEditor, void(cocoon::Notification)>::emit((__bridge void*)strongHost, "rows_did_change", cocoon::internal::wrap<cocoon::Notification>(notification));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(ruleEditor:numberOfChildrenForCriterion:withRowType:))
    {
        return strongHost && cocoon::Signal<cocoon::RuleEditor, std::int64_t(cocoon::Object, cocoon::RuleEditorRowType)>::connected((__bridge void*)strongHost, "number_of_children_for_criterion_with_row_type");
    }
    if (selector == @selector(ruleEditor:child:forCriterion:withRowType:))
    {
        return strongHost && cocoon::Signal<cocoon::RuleEditor, cocoon::Object(std::int64_t, cocoon::Object, cocoon::RuleEditorRowType)>::connected((__bridge void*)strongHost, "child_for_criterion_with_row_type");
    }
    if (selector == @selector(ruleEditor:displayValueForCriterion:inRow:))
    {
        return strongHost && cocoon::Signal<cocoon::RuleEditor, cocoon::Object(cocoon::Object, std::int64_t)>::connected((__bridge void*)strongHost, "display_value_for_criterion_in_row");
    }
    if (selector == @selector(ruleEditor:predicatePartsForCriterion:withDisplayValue:inRow:))
    {
        return strongHost && cocoon::Signal<cocoon::RuleEditor, std::map<std::string, cocoon::Object>(cocoon::Object, cocoon::Object, std::int64_t)>::connected((__bridge void*)strongHost, "predicate_parts_for_criterion_with_display_value_in_row");
    }
    if (selector == @selector(ruleEditorRowsDidChange:))
    {
        return strongHost && cocoon::Signal<cocoon::RuleEditor, void(cocoon::Notification)>::connected((__bridge void*)strongHost, "rows_did_change");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    RuleEditor::RuleEditor() : RuleEditor(Adopt{cocoon::internal::retain([[::NSRuleEditor alloc] init])})
    {
        RuleEditor::install_delegate_delegate_(handle());
    }

    RuleEditor::RuleEditor(std::nullptr_t) : Control(nullptr)
    {
    }

    RuleEditor::RuleEditor(Adopt adopt) : Control(adopt)
    {
    }

    void RuleEditor::add_row(const Object& sender) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) addRow:cocoon::internal::native_id(sender)];
    }

    std::vector<Object> RuleEditor::criteria_for_row(std::int64_t row) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSRuleEditor>(this) criteriaForRow:static_cast<::NSInteger>(row)], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<Object> RuleEditor::display_values_for_row(std::int64_t row) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSRuleEditor>(this) displayValuesForRow:static_cast<::NSInteger>(row)], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void RuleEditor::insert_row_at_index(std::int64_t row_index, RuleEditorRowType row_type, std::int64_t parent_row, bool should_animate) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) insertRowAtIndex:static_cast<::NSInteger>(row_index) withType:static_cast<::NSRuleEditorRowType>(row_type) asSubrowOfRow:static_cast<::NSInteger>(parent_row) animate:static_cast<::BOOL>(should_animate)];
    }

    std::int64_t RuleEditor::parent_row_for_row(std::int64_t row_index) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSRuleEditor>(this) parentRowForRow:static_cast<::NSInteger>(row_index)]);
    }

    Predicate RuleEditor::predicate_for_row(std::int64_t row) const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSRuleEditor>(this) predicateForRow:static_cast<::NSInteger>(row)]);
    }

    void RuleEditor::reload_criteria() const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) reloadCriteria];
    }

    void RuleEditor::reload_predicate() const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) reloadPredicate];
    }

    void RuleEditor::remove_row_at_index(std::int64_t row_index) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) removeRowAtIndex:static_cast<::NSInteger>(row_index)];
    }

    void RuleEditor::remove_rows_at_indexes(const IndexSet& row_indexes, bool include_subrows) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) removeRowsAtIndexes:cocoon::internal::native<::NSIndexSet>(row_indexes) includeSubrows:static_cast<::BOOL>(include_subrows)];
    }

    std::int64_t RuleEditor::row_for_display_value(const Object& display_value) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSRuleEditor>(this) rowForDisplayValue:cocoon::internal::native_id(display_value)]);
    }

    RuleEditorRowType RuleEditor::row_type_for_row(std::int64_t row_index) const
    {
        return static_cast<RuleEditorRowType>([cocoon::internal::ns<::NSRuleEditor>(this) rowTypeForRow:static_cast<::NSInteger>(row_index)]);
    }

    void RuleEditor::select_row_indexes(const IndexSet& indexes, bool extend) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) selectRowIndexes:cocoon::internal::native<::NSIndexSet>(indexes) byExtendingSelection:static_cast<::BOOL>(extend)];
    }

    void RuleEditor::set_criteria(const std::vector<Object>& criteria, const std::vector<Object>& values, std::int64_t row_index) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setCriteria:cocoon::internal::to_array(criteria, [](const Object& e) -> id
                                                               {
                                                                   return cocoon::internal::native_id(e);
                                                               })
                                 andDisplayValues:cocoon::internal::to_array(values, [](const Object& e) -> id
                                                               {
                                                                   return cocoon::internal::native_id(e);
                                                               })
                                    forRowAtIndex:static_cast<::NSInteger>(row_index)];
    }

    IndexSet RuleEditor::subrow_indexes_for_row(std::int64_t row_index) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSRuleEditor>(this) subrowIndexesForRow:static_cast<::NSInteger>(row_index)]);
    }

    bool RuleEditor::can_remove_all_rows() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRuleEditor>(this) canRemoveAllRows]);
    }

    void RuleEditor::set_can_remove_all_rows(bool value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setCanRemoveAllRows:static_cast<::BOOL>(value)];
    }

    std::string RuleEditor::criteria_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRuleEditor>(this) criteriaKeyPath]);
    }

    void RuleEditor::set_criteria_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setCriteriaKeyPath:cocoon::internal::to(value)];
    }

    std::string RuleEditor::display_values_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRuleEditor>(this) displayValuesKeyPath]);
    }

    void RuleEditor::set_display_values_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setDisplayValuesKeyPath:cocoon::internal::to(value)];
    }

    bool RuleEditor::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSRuleEditor>(this) isEditable]);
    }

    void RuleEditor::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setEditable:static_cast<::BOOL>(value)];
    }

    std::map<std::string, std::string> RuleEditor::formatting_dictionary() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, std::string>>([cocoon::internal::ns<::NSRuleEditor>(this) formattingDictionary], [](id k) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)k);
                                                                       },
                                                                       [](id v) -> std::string
                                                                       {
                                                                           return cocoon::internal::from((NSString*)v);
                                                                       });
    }

    void RuleEditor::set_formatting_dictionary(const std::map<std::string, std::string>& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setFormattingDictionary:cocoon::internal::to_dictionary(value, [](const std::string& k) -> id
                                                                                {
                                                                                    return cocoon::internal::to(k);
                                                                                },
                                                                                [](const std::string& v) -> id
                                                                                {
                                                                                    return cocoon::internal::to(v);
                                                                                })];
    }

    std::string RuleEditor::formatting_strings_filename() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRuleEditor>(this) formattingStringsFilename]);
    }

    void RuleEditor::set_formatting_strings_filename(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setFormattingStringsFilename:cocoon::internal::to(value)];
    }

    RuleEditorNestingMode RuleEditor::nesting_mode() const
    {
        return static_cast<RuleEditorNestingMode>([cocoon::internal::ns<::NSRuleEditor>(this) nestingMode]);
    }

    void RuleEditor::set_nesting_mode(RuleEditorNestingMode value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setNestingMode:static_cast<::NSRuleEditorNestingMode>(value)];
    }

    std::int64_t RuleEditor::number_of_rows() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSRuleEditor>(this) numberOfRows]);
    }

    Predicate RuleEditor::predicate() const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSRuleEditor>(this) predicate]);
    }

    std::string RuleEditor::row_class() const
    {
        return cocoon::internal::from(NSStringFromClass([cocoon::internal::ns<::NSRuleEditor>(this) rowClass]));
    }

    void RuleEditor::set_row_class(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setRowClass:NSClassFromString(cocoon::internal::to(value))];
    }

    double RuleEditor::row_height() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSRuleEditor>(this) rowHeight]);
    }

    void RuleEditor::set_row_height(double value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setRowHeight:static_cast<::CGFloat>(value)];
    }

    std::string RuleEditor::row_type_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRuleEditor>(this) rowTypeKeyPath]);
    }

    void RuleEditor::set_row_type_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setRowTypeKeyPath:cocoon::internal::to(value)];
    }

    IndexSet RuleEditor::selected_row_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSRuleEditor>(this) selectedRowIndexes]);
    }

    std::string RuleEditor::subrows_key_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSRuleEditor>(this) subrowsKeyPath]);
    }

    void RuleEditor::set_subrows_key_path(const std::string& value) const
    {
        [cocoon::internal::ns<::NSRuleEditor>(this) setSubrowsKeyPath:cocoon::internal::to(value)];
    }

    void RuleEditor::install_delegate_delegate_(void* native)
    {
        ::NSRuleEditor* host = (__bridge ::NSRuleEditor*)native;
        AKRuleEditorDelegate* delegate = [[AKRuleEditorDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSRuleEditor* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSRuleEditor* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
