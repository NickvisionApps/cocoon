#include "generated/constants.h"
#include "internal.h"

namespace cocoon
{
    std::string NotificationName::workspace_accessibility_display_options_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceAccessibilityDisplayOptionsDidChangeNotification", nil));
    }
    std::string NotificationName::animation_progress_mark_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimationProgressMarkNotification", nil));
    }
    std::string NotificationName::application_did_become_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidBecomeActiveNotification", nil));
    }
    std::string NotificationName::application_did_hide_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidHideNotification", nil));
    }
    std::string NotificationName::application_did_finish_launching_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidFinishLaunchingNotification", nil));
    }
    std::string NotificationName::application_did_resign_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidResignActiveNotification", nil));
    }
    std::string NotificationName::application_did_unhide_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidUnhideNotification", nil));
    }
    std::string NotificationName::application_did_update_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidUpdateNotification", nil));
    }
    std::string NotificationName::application_will_become_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillBecomeActiveNotification", nil));
    }
    std::string NotificationName::application_will_hide_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillHideNotification", nil));
    }
    std::string NotificationName::application_will_finish_launching_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillFinishLaunchingNotification", nil));
    }
    std::string NotificationName::application_will_resign_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillResignActiveNotification", nil));
    }
    std::string NotificationName::application_will_unhide_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillUnhideNotification", nil));
    }
    std::string NotificationName::application_will_update_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillUpdateNotification", nil));
    }
    std::string NotificationName::application_will_terminate_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationWillTerminateNotification", nil));
    }
    std::string NotificationName::application_did_change_screen_parameters_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidChangeScreenParametersNotification", nil));
    }
    std::string NotificationName::application_protected_data_will_become_unavailable_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationProtectedDataWillBecomeUnavailableNotification", nil));
    }
    std::string NotificationName::application_protected_data_did_become_available_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationProtectedDataDidBecomeAvailableNotification", nil));
    }
    std::string NotificationName::application_should_begin_suppressing_high_dynamic_range_content_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationShouldBeginSuppressingHighDynamicRangeContentNotification", nil));
    }
    std::string NotificationName::application_should_end_suppressing_high_dynamic_range_content_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationShouldEndSuppressingHighDynamicRangeContentNotification", nil));
    }
    std::string NotificationName::application_did_change_occlusion_state_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidChangeOcclusionStateNotification", nil));
    }
    std::string NotificationName::browser_column_configuration_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBrowserColumnConfigurationDidChangeNotification", nil));
    }
    std::string NotificationName::system_colors_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSystemColorsDidChangeNotification", nil));
    }
    std::string NotificationName::color_list_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSColorListDidChangeNotification", nil));
    }
    std::string NotificationName::color_panel_color_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSColorPanelColorDidChangeNotification", nil));
    }
    std::string NotificationName::combo_box_will_pop_up_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSComboBoxWillPopUpNotification", nil));
    }
    std::string NotificationName::combo_box_will_dismiss_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSComboBoxWillDismissNotification", nil));
    }
    std::string NotificationName::combo_box_selection_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSComboBoxSelectionDidChangeNotification", nil));
    }
    std::string NotificationName::combo_box_selection_is_changing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSComboBoxSelectionIsChangingNotification", nil));
    }
    std::string NotificationName::control_text_did_begin_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSControlTextDidBeginEditingNotification", nil));
    }
    std::string NotificationName::control_text_did_end_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSControlTextDidEndEditingNotification", nil));
    }
    std::string NotificationName::control_text_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSControlTextDidChangeNotification", nil));
    }
    std::string NotificationName::antialias_threshold_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAntialiasThresholdChangedNotification", nil));
    }
    std::string NotificationName::font_set_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontSetChangedNotification", nil));
    }
    std::string NotificationName::font_collection_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionDidChangeNotification", nil));
    }
    std::string NotificationName::context_help_mode_did_activate_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContextHelpModeDidActivateNotification", nil));
    }
    std::string NotificationName::context_help_mode_did_deactivate_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContextHelpModeDidDeactivateNotification", nil));
    }
    std::string NotificationName::image_rep_registry_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageRepRegistryDidChangeNotification", nil));
    }
    std::string NotificationName::menu_will_send_action_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuWillSendActionNotification", nil));
    }
    std::string NotificationName::menu_did_send_action_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidSendActionNotification", nil));
    }
    std::string NotificationName::menu_did_add_item_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidAddItemNotification", nil));
    }
    std::string NotificationName::menu_did_remove_item_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidRemoveItemNotification", nil));
    }
    std::string NotificationName::menu_did_change_item_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidChangeItemNotification", nil));
    }
    std::string NotificationName::menu_did_begin_tracking_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidBeginTrackingNotification", nil));
    }
    std::string NotificationName::menu_did_end_tracking_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuDidEndTrackingNotification", nil));
    }
    std::string NotificationName::outline_view_selection_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewSelectionDidChangeNotification", nil));
    }
    std::string NotificationName::outline_view_column_did_move_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewColumnDidMoveNotification", nil));
    }
    std::string NotificationName::outline_view_column_did_resize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewColumnDidResizeNotification", nil));
    }
    std::string NotificationName::outline_view_selection_is_changing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewSelectionIsChangingNotification", nil));
    }
    std::string NotificationName::outline_view_item_will_expand_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewItemWillExpandNotification", nil));
    }
    std::string NotificationName::outline_view_item_did_expand_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewItemDidExpandNotification", nil));
    }
    std::string NotificationName::outline_view_item_will_collapse_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewItemWillCollapseNotification", nil));
    }
    std::string NotificationName::outline_view_item_did_collapse_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewItemDidCollapseNotification", nil));
    }
    std::string NotificationName::pop_up_button_will_pop_up_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopUpButtonWillPopUpNotification", nil));
    }
    std::string NotificationName::pop_up_button_cell_will_pop_up_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopUpButtonCellWillPopUpNotification", nil));
    }
    std::string NotificationName::popover_will_show_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverWillShowNotification", nil));
    }
    std::string NotificationName::popover_did_show_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverDidShowNotification", nil));
    }
    std::string NotificationName::popover_will_close_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverWillCloseNotification", nil));
    }
    std::string NotificationName::popover_did_close_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverDidCloseNotification", nil));
    }
    std::string NotificationName::rule_editor_rows_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorRowsDidChangeNotification", nil));
    }
    std::string NotificationName::screen_color_space_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScreenColorSpaceDidChangeNotification", nil));
    }
    std::string NotificationName::scroll_view_will_start_live_magnify_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScrollViewWillStartLiveMagnifyNotification", nil));
    }
    std::string NotificationName::scroll_view_did_end_live_magnify_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScrollViewDidEndLiveMagnifyNotification", nil));
    }
    std::string NotificationName::scroll_view_will_start_live_scroll_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScrollViewWillStartLiveScrollNotification", nil));
    }
    std::string NotificationName::scroll_view_did_live_scroll_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScrollViewDidLiveScrollNotification", nil));
    }
    std::string NotificationName::scroll_view_did_end_live_scroll_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSScrollViewDidEndLiveScrollNotification", nil));
    }
    std::string NotificationName::preferred_scroller_style_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPreferredScrollerStyleDidChangeNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_spelling_correction_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticSpellingCorrectionNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_text_replacement_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticTextReplacementNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_quote_substitution_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticQuoteSubstitutionNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_dash_substitution_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticDashSubstitutionNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_capitalization_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticCapitalizationNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_period_substitution_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticPeriodSubstitutionNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_text_completion_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticTextCompletionNotification", nil));
    }
    std::string NotificationName::spell_checker_did_change_automatic_inline_prediction_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellCheckerDidChangeAutomaticInlinePredictionNotification", nil));
    }
    std::string NotificationName::split_view_will_resize_subviews_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSplitViewWillResizeSubviewsNotification", nil));
    }
    std::string NotificationName::split_view_did_resize_subviews_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSplitViewDidResizeSubviewsNotification", nil));
    }
    std::string NotificationName::table_view_selection_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTableViewSelectionDidChangeNotification", nil));
    }
    std::string NotificationName::table_view_column_did_move_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTableViewColumnDidMoveNotification", nil));
    }
    std::string NotificationName::table_view_column_did_resize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTableViewColumnDidResizeNotification", nil));
    }
    std::string NotificationName::table_view_selection_is_changing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTableViewSelectionIsChangingNotification", nil));
    }
    std::string NotificationName::text_did_begin_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextDidBeginEditingNotification", nil));
    }
    std::string NotificationName::text_did_end_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextDidEndEditingNotification", nil));
    }
    std::string NotificationName::text_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextDidChangeNotification", nil));
    }
    std::string NotificationName::text_alternatives_selected_alternative_string_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextAlternativesSelectedAlternativeStringNotification", nil));
    }
    std::string NotificationName::text_content_storage_unsupported_attribute_added_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentStorageUnsupportedAttributeAddedNotification", nil));
    }
    std::string NotificationName::text_input_context_keyboard_selection_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextInputContextKeyboardSelectionDidChangeNotification", nil));
    }
    std::string NotificationName::text_storage_will_process_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextStorageWillProcessEditingNotification", nil));
    }
    std::string NotificationName::text_storage_did_process_editing_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextStorageDidProcessEditingNotification", nil));
    }
    std::string NotificationName::text_view_will_change_notifying_text_view_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextViewWillChangeNotifyingTextViewNotification", nil));
    }
    std::string NotificationName::text_view_did_change_selection_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextViewDidChangeSelectionNotification", nil));
    }
    std::string NotificationName::text_view_did_change_typing_attributes_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextViewDidChangeTypingAttributesNotification", nil));
    }
    std::string NotificationName::text_view_will_switch_to_ns_layout_manager_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextViewWillSwitchToNSLayoutManagerNotification", nil));
    }
    std::string NotificationName::text_view_did_switch_to_ns_layout_manager_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextViewDidSwitchToNSLayoutManagerNotification", nil));
    }
    std::string NotificationName::toolbar_will_add_item_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarWillAddItemNotification", nil));
    }
    std::string NotificationName::toolbar_did_remove_item_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarDidRemoveItemNotification", nil));
    }
    std::string NotificationName::view_frame_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewFrameDidChangeNotification", nil));
    }
    std::string NotificationName::view_bounds_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewBoundsDidChangeNotification", nil));
    }
    std::string NotificationName::view_did_update_tracking_areas_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewDidUpdateTrackingAreasNotification", nil));
    }
    std::string NotificationName::window_did_become_key_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidBecomeKeyNotification", nil));
    }
    std::string NotificationName::window_did_become_main_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidBecomeMainNotification", nil));
    }
    std::string NotificationName::window_did_change_screen_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidChangeScreenNotification", nil));
    }
    std::string NotificationName::window_did_deminiaturize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidDeminiaturizeNotification", nil));
    }
    std::string NotificationName::window_did_expose_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidExposeNotification", nil));
    }
    std::string NotificationName::window_did_miniaturize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidMiniaturizeNotification", nil));
    }
    std::string NotificationName::window_did_move_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidMoveNotification", nil));
    }
    std::string NotificationName::window_did_resign_key_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidResignKeyNotification", nil));
    }
    std::string NotificationName::window_did_resign_main_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidResignMainNotification", nil));
    }
    std::string NotificationName::window_did_resize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidResizeNotification", nil));
    }
    std::string NotificationName::window_did_update_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidUpdateNotification", nil));
    }
    std::string NotificationName::window_will_close_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillCloseNotification", nil));
    }
    std::string NotificationName::window_will_miniaturize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillMiniaturizeNotification", nil));
    }
    std::string NotificationName::window_will_move_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillMoveNotification", nil));
    }
    std::string NotificationName::window_will_begin_sheet_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillBeginSheetNotification", nil));
    }
    std::string NotificationName::window_did_end_sheet_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidEndSheetNotification", nil));
    }
    std::string NotificationName::window_did_change_backing_properties_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidChangeBackingPropertiesNotification", nil));
    }
    std::string NotificationName::window_did_change_screen_profile_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidChangeScreenProfileNotification", nil));
    }
    std::string NotificationName::window_will_start_live_resize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillStartLiveResizeNotification", nil));
    }
    std::string NotificationName::window_did_end_live_resize_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidEndLiveResizeNotification", nil));
    }
    std::string NotificationName::window_will_enter_full_screen_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillEnterFullScreenNotification", nil));
    }
    std::string NotificationName::window_did_enter_full_screen_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidEnterFullScreenNotification", nil));
    }
    std::string NotificationName::window_will_exit_full_screen_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillExitFullScreenNotification", nil));
    }
    std::string NotificationName::window_did_exit_full_screen_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidExitFullScreenNotification", nil));
    }
    std::string NotificationName::window_will_enter_version_browser_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillEnterVersionBrowserNotification", nil));
    }
    std::string NotificationName::window_did_enter_version_browser_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidEnterVersionBrowserNotification", nil));
    }
    std::string NotificationName::window_will_exit_version_browser_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowWillExitVersionBrowserNotification", nil));
    }
    std::string NotificationName::window_did_exit_version_browser_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidExitVersionBrowserNotification", nil));
    }
    std::string NotificationName::window_did_change_occlusion_state_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowDidChangeOcclusionStateNotification", nil));
    }
    std::string NotificationName::application_did_finish_restoring_windows_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationDidFinishRestoringWindowsNotification", nil));
    }
    std::string NotificationName::workspace_will_launch_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceWillLaunchApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_launch_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidLaunchApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_terminate_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidTerminateApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_hide_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidHideApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_unhide_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidUnhideApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_activate_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidActivateApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_deactivate_application_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidDeactivateApplicationNotification", nil));
    }
    std::string NotificationName::workspace_did_mount_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidMountNotification", nil));
    }
    std::string NotificationName::workspace_did_unmount_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidUnmountNotification", nil));
    }
    std::string NotificationName::workspace_will_unmount_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceWillUnmountNotification", nil));
    }
    std::string NotificationName::workspace_did_rename_volume_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidRenameVolumeNotification", nil));
    }
    std::string NotificationName::workspace_will_power_off_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceWillPowerOffNotification", nil));
    }
    std::string NotificationName::workspace_will_sleep_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceWillSleepNotification", nil));
    }
    std::string NotificationName::workspace_did_wake_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidWakeNotification", nil));
    }
    std::string NotificationName::workspace_screens_did_sleep_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceScreensDidSleepNotification", nil));
    }
    std::string NotificationName::workspace_screens_did_wake_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceScreensDidWakeNotification", nil));
    }
    std::string NotificationName::workspace_session_did_become_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceSessionDidBecomeActiveNotification", nil));
    }
    std::string NotificationName::workspace_session_did_resign_active_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceSessionDidResignActiveNotification", nil));
    }
    std::string NotificationName::workspace_did_change_file_labels_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDidChangeFileLabelsNotification", nil));
    }
    std::string NotificationName::workspace_active_space_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceActiveSpaceDidChangeNotification", nil));
    }
    std::string NotificationName::apple_event_manager_will_process_first_event_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleEventManagerWillProcessFirstEventNotification", nil));
    }
    std::string NotificationName::bundle_did_load_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBundleDidLoadNotification", nil));
    }
    std::string NotificationName::calendar_day_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarDayChangedNotification", nil));
    }
    std::string NotificationName::class_description_needed_for_class_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSClassDescriptionNeededForClassNotification", nil));
    }
    std::string NotificationName::system_clock_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSystemClockDidChangeNotification", nil));
    }
    std::string NotificationName::file_handle_read_completion_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleReadCompletionNotification", nil));
    }
    std::string NotificationName::file_handle_read_to_end_of_file_completion_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleReadToEndOfFileCompletionNotification", nil));
    }
    std::string NotificationName::file_handle_connection_accepted_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleConnectionAcceptedNotification", nil));
    }
    std::string NotificationName::file_handle_data_available_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleDataAvailableNotification", nil));
    }
    std::string NotificationName::ubiquity_identity_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUbiquityIdentityDidChangeNotification", nil));
    }
    std::string NotificationName::http_cookie_manager_cookies_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieManagerCookiesChangedNotification", nil));
    }
    std::string NotificationName::current_locale_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCurrentLocaleDidChangeNotification", nil));
    }
    std::string NotificationName::metadata_query_did_start_gathering_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryDidStartGatheringNotification", nil));
    }
    std::string NotificationName::metadata_query_gathering_progress_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryGatheringProgressNotification", nil));
    }
    std::string NotificationName::metadata_query_did_finish_gathering_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryDidFinishGatheringNotification", nil));
    }
    std::string NotificationName::metadata_query_did_update_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryDidUpdateNotification", nil));
    }
    std::string NotificationName::port_did_become_invalid_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPortDidBecomeInvalidNotification", nil));
    }
    std::string NotificationName::process_info_thermal_state_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProcessInfoThermalStateDidChangeNotification", nil));
    }
    std::string NotificationName::process_info_power_state_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProcessInfoPowerStateDidChangeNotification", nil));
    }
    std::string NotificationName::task_did_terminate_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTaskDidTerminateNotification", nil));
    }
    std::string NotificationName::system_time_zone_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSystemTimeZoneDidChangeNotification", nil));
    }
    std::string NotificationName::ubiquitous_key_value_store_did_change_externally_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUbiquitousKeyValueStoreDidChangeExternallyNotification", nil));
    }
    std::string NotificationName::undo_manager_checkpoint_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerCheckpointNotification", nil));
    }
    std::string NotificationName::undo_manager_will_undo_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerWillUndoChangeNotification", nil));
    }
    std::string NotificationName::undo_manager_will_redo_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerWillRedoChangeNotification", nil));
    }
    std::string NotificationName::undo_manager_did_undo_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerDidUndoChangeNotification", nil));
    }
    std::string NotificationName::undo_manager_did_redo_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerDidRedoChangeNotification", nil));
    }
    std::string NotificationName::undo_manager_did_open_undo_group_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerDidOpenUndoGroupNotification", nil));
    }
    std::string NotificationName::undo_manager_will_close_undo_group_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerWillCloseUndoGroupNotification", nil));
    }
    std::string NotificationName::undo_manager_did_close_undo_group_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerDidCloseUndoGroupNotification", nil));
    }
    std::string NotificationName::user_defaults_did_change_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUserDefaultsDidChangeNotification", nil));
    }

    std::string StringConstants::accessibility_error_code_exception_info()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityErrorCodeExceptionInfo", nil));
    }
    std::string StringConstants::accessibility_text_completion_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextCompletionAttribute", nil));
    }
    std::string StringConstants::accessibility_search_identifiers_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchIdentifiersKey", nil));
    }
    std::string StringConstants::accessibility_search_current_element_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchCurrentElementKey", nil));
    }
    std::string StringConstants::accessibility_search_current_range_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchCurrentRangeKey", nil));
    }
    std::string StringConstants::accessibility_search_direction_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchDirectionKey", nil));
    }
    std::string StringConstants::accessibility_search_results_limit_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchResultsLimitKey", nil));
    }
    std::string StringConstants::accessibility_search_text_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchTextKey", nil));
    }
    std::string StringConstants::accessibility_search_direction_next()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchDirectionNext", nil));
    }
    std::string StringConstants::accessibility_search_direction_previous()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchDirectionPrevious", nil));
    }
    std::string StringConstants::accessibility_search_result_element_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchResultElementKey", nil));
    }
    std::string StringConstants::accessibility_search_result_range_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchResultRangeKey", nil));
    }
    std::string StringConstants::accessibility_search_result_description_override_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchResultDescriptionOverrideKey", nil));
    }
    std::string StringConstants::accessibility_search_result_loader_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchResultLoaderKey", nil));
    }
    std::string StringConstants::animation_progress_mark()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimationProgressMark", nil));
    }
    std::string StringConstants::application_launch_is_default_launch_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationLaunchIsDefaultLaunchKey", nil));
    }
    std::string StringConstants::application_launch_user_notification_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSApplicationLaunchUserNotificationKey", nil));
    }
    std::string StringConstants::type_identifier_date_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTypeIdentifierDateText", nil));
    }
    std::string StringConstants::type_identifier_address_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTypeIdentifierAddressText", nil));
    }
    std::string StringConstants::type_identifier_phone_number_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTypeIdentifierPhoneNumberText", nil));
    }
    std::string StringConstants::type_identifier_transit_information_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTypeIdentifierTransitInformationText", nil));
    }
    std::string StringConstants::popover_close_reason_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverCloseReasonKey", nil));
    }
    std::string StringConstants::text_movement_user_info_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextMovementUserInfoKey", nil));
    }
    std::string StringConstants::all_roman_input_sources_locale_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAllRomanInputSourcesLocaleIdentifier", nil));
    }
    std::string StringConstants::user_activity_document_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUserActivityDocumentURLKey", nil));
    }
    std::string StringConstants::backing_property_old_scale_factor_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBackingPropertyOldScaleFactorKey", nil));
    }
    std::string StringConstants::backing_property_old_color_space_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBackingPropertyOldColorSpaceKey", nil));
    }
    std::string StringConstants::workspace_application_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceApplicationKey", nil));
    }
    std::string StringConstants::workspace_volume_localized_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceVolumeLocalizedNameKey", nil));
    }
    std::string StringConstants::workspace_volume_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceVolumeURLKey", nil));
    }
    std::string StringConstants::workspace_volume_old_localized_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceVolumeOldLocalizedNameKey", nil));
    }
    std::string StringConstants::workspace_volume_old_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceVolumeOldURLKey", nil));
    }
    std::string StringConstants::apple_script_error_message()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleScriptErrorMessage", nil));
    }
    std::string StringConstants::apple_script_error_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleScriptErrorNumber", nil));
    }
    std::string StringConstants::apple_script_error_app_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleScriptErrorAppName", nil));
    }
    std::string StringConstants::apple_script_error_brief_message()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleScriptErrorBriefMessage", nil));
    }
    std::string StringConstants::apple_script_error_range()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppleScriptErrorRange", nil));
    }
    std::string StringConstants::loaded_classes()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLoadedClasses", nil));
    }
    std::string StringConstants::assertion_handler_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAssertionHandlerKey", nil));
    }
    std::string StringConstants::file_handle_notification_data_item()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleNotificationDataItem", nil));
    }
    std::string StringConstants::file_handle_notification_file_handle_item()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleNotificationFileHandleItem", nil));
    }
    std::string StringConstants::file_manager_unmount_dissenting_process_identifier_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileManagerUnmountDissentingProcessIdentifierErrorKey", nil));
    }
    std::string StringConstants::item_provider_preferred_image_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSItemProviderPreferredImageSizeKey", nil));
    }
    std::string StringConstants::item_provider_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSItemProviderErrorDomain", nil));
    }
    std::string StringConstants::keyed_archive_root_object_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyedArchiveRootObjectKey", nil));
    }
    std::string StringConstants::metadata_query_update_added_items_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUpdateAddedItemsKey", nil));
    }
    std::string StringConstants::metadata_query_update_changed_items_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUpdateChangedItemsKey", nil));
    }
    std::string StringConstants::metadata_query_update_removed_items_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUpdateRemovedItemsKey", nil));
    }
    std::string StringConstants::metadata_query_result_content_relevance_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryResultContentRelevanceAttribute", nil));
    }
    std::string StringConstants::metadata_query_user_home_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUserHomeScope", nil));
    }
    std::string StringConstants::metadata_query_local_computer_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryLocalComputerScope", nil));
    }
    std::string StringConstants::metadata_query_network_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryNetworkScope", nil));
    }
    std::string StringConstants::metadata_query_indexed_local_computer_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryIndexedLocalComputerScope", nil));
    }
    std::string StringConstants::metadata_query_indexed_network_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryIndexedNetworkScope", nil));
    }
    std::string StringConstants::metadata_query_ubiquitous_documents_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUbiquitousDocumentsScope", nil));
    }
    std::string StringConstants::metadata_query_ubiquitous_data_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryUbiquitousDataScope", nil));
    }
    std::string StringConstants::metadata_query_accessible_ubiquitous_external_documents_scope()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope", nil));
    }
    std::string StringConstants::metadata_item_fs_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFSNameKey", nil));
    }
    std::string StringConstants::metadata_item_display_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDisplayNameKey", nil));
    }
    std::string StringConstants::metadata_item_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemURLKey", nil));
    }
    std::string StringConstants::metadata_item_path_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPathKey", nil));
    }
    std::string StringConstants::metadata_item_fs_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFSSizeKey", nil));
    }
    std::string StringConstants::metadata_item_fs_creation_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFSCreationDateKey", nil));
    }
    std::string StringConstants::metadata_item_fs_content_change_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFSContentChangeDateKey", nil));
    }
    std::string StringConstants::metadata_item_content_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContentTypeKey", nil));
    }
    std::string StringConstants::metadata_item_content_type_tree_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContentTypeTreeKey", nil));
    }
    std::string StringConstants::metadata_item_is_ubiquitous_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemIsUbiquitousKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_has_unresolved_conflicts_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemHasUnresolvedConflictsKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_downloading_status_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadingStatusKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_downloading_status_not_downloaded()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadingStatusNotDownloaded", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_downloading_status_downloaded()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadingStatusDownloaded", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_downloading_status_current()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadingStatusCurrent", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_is_downloading_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemIsDownloadingKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_is_uploaded_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemIsUploadedKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_is_uploading_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemIsUploadingKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_percent_downloaded_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemPercentDownloadedKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_percent_uploaded_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemPercentUploadedKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_downloading_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadingErrorKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_uploading_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemUploadingErrorKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_download_requested_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemDownloadRequestedKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_is_external_document_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemIsExternalDocumentKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_container_display_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemContainerDisplayNameKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_url_in_local_container_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemURLInLocalContainerKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_item_is_shared_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousItemIsSharedKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_current_user_role_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemCurrentUserRoleKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_current_user_permissions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemCurrentUserPermissionsKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_owner_name_components_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemOwnerNameComponentsKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_most_recent_editor_name_components_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemMostRecentEditorNameComponentsKey", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_role_owner()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemRoleOwner", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_role_participant()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemRoleParticipant", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_permissions_read_only()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemPermissionsReadOnly", nil));
    }
    std::string StringConstants::metadata_ubiquitous_shared_item_permissions_read_write()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataUbiquitousSharedItemPermissionsReadWrite", nil));
    }
    std::string StringConstants::metadata_item_attribute_change_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAttributeChangeDateKey", nil));
    }
    std::string StringConstants::metadata_item_keywords_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemKeywordsKey", nil));
    }
    std::string StringConstants::metadata_item_title_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTitleKey", nil));
    }
    std::string StringConstants::metadata_item_authors_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAuthorsKey", nil));
    }
    std::string StringConstants::metadata_item_editors_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemEditorsKey", nil));
    }
    std::string StringConstants::metadata_item_participants_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemParticipantsKey", nil));
    }
    std::string StringConstants::metadata_item_projects_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemProjectsKey", nil));
    }
    std::string StringConstants::metadata_item_downloaded_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDownloadedDateKey", nil));
    }
    std::string StringConstants::metadata_item_where_froms_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemWhereFromsKey", nil));
    }
    std::string StringConstants::metadata_item_comment_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCommentKey", nil));
    }
    std::string StringConstants::metadata_item_copyright_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCopyrightKey", nil));
    }
    std::string StringConstants::metadata_item_last_used_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLastUsedDateKey", nil));
    }
    std::string StringConstants::metadata_item_content_creation_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContentCreationDateKey", nil));
    }
    std::string StringConstants::metadata_item_content_modification_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContentModificationDateKey", nil));
    }
    std::string StringConstants::metadata_item_date_added_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDateAddedKey", nil));
    }
    std::string StringConstants::metadata_item_duration_seconds_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDurationSecondsKey", nil));
    }
    std::string StringConstants::metadata_item_contact_keywords_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContactKeywordsKey", nil));
    }
    std::string StringConstants::metadata_item_version_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemVersionKey", nil));
    }
    std::string StringConstants::metadata_item_pixel_height_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPixelHeightKey", nil));
    }
    std::string StringConstants::metadata_item_pixel_width_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPixelWidthKey", nil));
    }
    std::string StringConstants::metadata_item_pixel_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPixelCountKey", nil));
    }
    std::string StringConstants::metadata_item_color_space_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemColorSpaceKey", nil));
    }
    std::string StringConstants::metadata_item_bits_per_sample_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemBitsPerSampleKey", nil));
    }
    std::string StringConstants::metadata_item_flash_on_off_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFlashOnOffKey", nil));
    }
    std::string StringConstants::metadata_item_focal_length_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFocalLengthKey", nil));
    }
    std::string StringConstants::metadata_item_acquisition_make_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAcquisitionMakeKey", nil));
    }
    std::string StringConstants::metadata_item_acquisition_model_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAcquisitionModelKey", nil));
    }
    std::string StringConstants::metadata_item_iso_speed_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemISOSpeedKey", nil));
    }
    std::string StringConstants::metadata_item_orientation_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemOrientationKey", nil));
    }
    std::string StringConstants::metadata_item_layer_names_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLayerNamesKey", nil));
    }
    std::string StringConstants::metadata_item_white_balance_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemWhiteBalanceKey", nil));
    }
    std::string StringConstants::metadata_item_aperture_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemApertureKey", nil));
    }
    std::string StringConstants::metadata_item_profile_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemProfileNameKey", nil));
    }
    std::string StringConstants::metadata_item_resolution_width_dpi_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemResolutionWidthDPIKey", nil));
    }
    std::string StringConstants::metadata_item_resolution_height_dpi_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemResolutionHeightDPIKey", nil));
    }
    std::string StringConstants::metadata_item_exposure_mode_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExposureModeKey", nil));
    }
    std::string StringConstants::metadata_item_exposure_time_seconds_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExposureTimeSecondsKey", nil));
    }
    std::string StringConstants::metadata_item_exif_version_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemEXIFVersionKey", nil));
    }
    std::string StringConstants::metadata_item_camera_owner_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCameraOwnerKey", nil));
    }
    std::string StringConstants::metadata_item_focal_length35mm_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFocalLength35mmKey", nil));
    }
    std::string StringConstants::metadata_item_lens_model_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLensModelKey", nil));
    }
    std::string StringConstants::metadata_item_exifgps_version_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemEXIFGPSVersionKey", nil));
    }
    std::string StringConstants::metadata_item_altitude_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAltitudeKey", nil));
    }
    std::string StringConstants::metadata_item_latitude_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLatitudeKey", nil));
    }
    std::string StringConstants::metadata_item_longitude_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLongitudeKey", nil));
    }
    std::string StringConstants::metadata_item_speed_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemSpeedKey", nil));
    }
    std::string StringConstants::metadata_item_timestamp_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTimestampKey", nil));
    }
    std::string StringConstants::metadata_item_gps_track_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSTrackKey", nil));
    }
    std::string StringConstants::metadata_item_image_direction_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemImageDirectionKey", nil));
    }
    std::string StringConstants::metadata_item_named_location_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemNamedLocationKey", nil));
    }
    std::string StringConstants::metadata_item_gps_status_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSStatusKey", nil));
    }
    std::string StringConstants::metadata_item_gps_measure_mode_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSMeasureModeKey", nil));
    }
    std::string StringConstants::metadata_item_gpsdop_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDOPKey", nil));
    }
    std::string StringConstants::metadata_item_gps_map_datum_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSMapDatumKey", nil));
    }
    std::string StringConstants::metadata_item_gps_dest_latitude_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDestLatitudeKey", nil));
    }
    std::string StringConstants::metadata_item_gps_dest_longitude_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDestLongitudeKey", nil));
    }
    std::string StringConstants::metadata_item_gps_dest_bearing_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDestBearingKey", nil));
    }
    std::string StringConstants::metadata_item_gps_dest_distance_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDestDistanceKey", nil));
    }
    std::string StringConstants::metadata_item_gps_processing_method_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSProcessingMethodKey", nil));
    }
    std::string StringConstants::metadata_item_gps_area_information_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSAreaInformationKey", nil));
    }
    std::string StringConstants::metadata_item_gps_date_stamp_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDateStampKey", nil));
    }
    std::string StringConstants::metadata_item_gps_differental_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGPSDifferentalKey", nil));
    }
    std::string StringConstants::metadata_item_codecs_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCodecsKey", nil));
    }
    std::string StringConstants::metadata_item_media_types_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMediaTypesKey", nil));
    }
    std::string StringConstants::metadata_item_streamable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemStreamableKey", nil));
    }
    std::string StringConstants::metadata_item_total_bit_rate_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTotalBitRateKey", nil));
    }
    std::string StringConstants::metadata_item_video_bit_rate_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemVideoBitRateKey", nil));
    }
    std::string StringConstants::metadata_item_audio_bit_rate_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudioBitRateKey", nil));
    }
    std::string StringConstants::metadata_item_delivery_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDeliveryTypeKey", nil));
    }
    std::string StringConstants::metadata_item_album_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAlbumKey", nil));
    }
    std::string StringConstants::metadata_item_has_alpha_channel_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemHasAlphaChannelKey", nil));
    }
    std::string StringConstants::metadata_item_red_eye_on_off_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRedEyeOnOffKey", nil));
    }
    std::string StringConstants::metadata_item_metering_mode_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMeteringModeKey", nil));
    }
    std::string StringConstants::metadata_item_max_aperture_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMaxApertureKey", nil));
    }
    std::string StringConstants::metadata_item_f_number_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFNumberKey", nil));
    }
    std::string StringConstants::metadata_item_exposure_program_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExposureProgramKey", nil));
    }
    std::string StringConstants::metadata_item_exposure_time_string_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExposureTimeStringKey", nil));
    }
    std::string StringConstants::metadata_item_headline_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemHeadlineKey", nil));
    }
    std::string StringConstants::metadata_item_instructions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemInstructionsKey", nil));
    }
    std::string StringConstants::metadata_item_city_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCityKey", nil));
    }
    std::string StringConstants::metadata_item_state_or_province_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemStateOrProvinceKey", nil));
    }
    std::string StringConstants::metadata_item_country_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCountryKey", nil));
    }
    std::string StringConstants::metadata_item_text_content_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTextContentKey", nil));
    }
    std::string StringConstants::metadata_item_audio_sample_rate_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudioSampleRateKey", nil));
    }
    std::string StringConstants::metadata_item_audio_channel_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudioChannelCountKey", nil));
    }
    std::string StringConstants::metadata_item_tempo_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTempoKey", nil));
    }
    std::string StringConstants::metadata_item_key_signature_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemKeySignatureKey", nil));
    }
    std::string StringConstants::metadata_item_time_signature_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemTimeSignatureKey", nil));
    }
    std::string StringConstants::metadata_item_audio_encoding_application_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudioEncodingApplicationKey", nil));
    }
    std::string StringConstants::metadata_item_composer_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemComposerKey", nil));
    }
    std::string StringConstants::metadata_item_lyricist_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLyricistKey", nil));
    }
    std::string StringConstants::metadata_item_audio_track_number_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudioTrackNumberKey", nil));
    }
    std::string StringConstants::metadata_item_recording_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRecordingDateKey", nil));
    }
    std::string StringConstants::metadata_item_musical_genre_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMusicalGenreKey", nil));
    }
    std::string StringConstants::metadata_item_is_general_midi_sequence_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemIsGeneralMIDISequenceKey", nil));
    }
    std::string StringConstants::metadata_item_recording_year_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRecordingYearKey", nil));
    }
    std::string StringConstants::metadata_item_organizations_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemOrganizationsKey", nil));
    }
    std::string StringConstants::metadata_item_languages_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemLanguagesKey", nil));
    }
    std::string StringConstants::metadata_item_rights_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRightsKey", nil));
    }
    std::string StringConstants::metadata_item_publishers_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPublishersKey", nil));
    }
    std::string StringConstants::metadata_item_contributors_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemContributorsKey", nil));
    }
    std::string StringConstants::metadata_item_coverage_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCoverageKey", nil));
    }
    std::string StringConstants::metadata_item_subject_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemSubjectKey", nil));
    }
    std::string StringConstants::metadata_item_theme_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemThemeKey", nil));
    }
    std::string StringConstants::metadata_item_description_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDescriptionKey", nil));
    }
    std::string StringConstants::metadata_item_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemIdentifierKey", nil));
    }
    std::string StringConstants::metadata_item_audiences_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAudiencesKey", nil));
    }
    std::string StringConstants::metadata_item_number_of_pages_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemNumberOfPagesKey", nil));
    }
    std::string StringConstants::metadata_item_page_width_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPageWidthKey", nil));
    }
    std::string StringConstants::metadata_item_page_height_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPageHeightKey", nil));
    }
    std::string StringConstants::metadata_item_security_method_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemSecurityMethodKey", nil));
    }
    std::string StringConstants::metadata_item_creator_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCreatorKey", nil));
    }
    std::string StringConstants::metadata_item_encoding_applications_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemEncodingApplicationsKey", nil));
    }
    std::string StringConstants::metadata_item_due_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDueDateKey", nil));
    }
    std::string StringConstants::metadata_item_star_rating_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemStarRatingKey", nil));
    }
    std::string StringConstants::metadata_item_phone_numbers_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPhoneNumbersKey", nil));
    }
    std::string StringConstants::metadata_item_email_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemEmailAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_instant_message_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemInstantMessageAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_kind_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemKindKey", nil));
    }
    std::string StringConstants::metadata_item_recipients_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRecipientsKey", nil));
    }
    std::string StringConstants::metadata_item_finder_comment_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFinderCommentKey", nil));
    }
    std::string StringConstants::metadata_item_fonts_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemFontsKey", nil));
    }
    std::string StringConstants::metadata_item_apple_loops_root_key_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAppleLoopsRootKeyKey", nil));
    }
    std::string StringConstants::metadata_item_apple_loops_key_filter_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAppleLoopsKeyFilterTypeKey", nil));
    }
    std::string StringConstants::metadata_item_apple_loops_loop_mode_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAppleLoopsLoopModeKey", nil));
    }
    std::string StringConstants::metadata_item_apple_loop_descriptors_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAppleLoopDescriptorsKey", nil));
    }
    std::string StringConstants::metadata_item_musical_instrument_category_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMusicalInstrumentCategoryKey", nil));
    }
    std::string StringConstants::metadata_item_musical_instrument_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemMusicalInstrumentNameKey", nil));
    }
    std::string StringConstants::metadata_item_cf_bundle_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemCFBundleIdentifierKey", nil));
    }
    std::string StringConstants::metadata_item_information_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemInformationKey", nil));
    }
    std::string StringConstants::metadata_item_director_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemDirectorKey", nil));
    }
    std::string StringConstants::metadata_item_producer_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemProducerKey", nil));
    }
    std::string StringConstants::metadata_item_genre_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemGenreKey", nil));
    }
    std::string StringConstants::metadata_item_performers_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemPerformersKey", nil));
    }
    std::string StringConstants::metadata_item_original_format_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemOriginalFormatKey", nil));
    }
    std::string StringConstants::metadata_item_original_source_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemOriginalSourceKey", nil));
    }
    std::string StringConstants::metadata_item_author_email_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAuthorEmailAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_recipient_email_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRecipientEmailAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_author_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemAuthorAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_recipient_addresses_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemRecipientAddressesKey", nil));
    }
    std::string StringConstants::metadata_item_is_likely_junk_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemIsLikelyJunkKey", nil));
    }
    std::string StringConstants::metadata_item_executable_architectures_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExecutableArchitecturesKey", nil));
    }
    std::string StringConstants::metadata_item_executable_platform_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemExecutablePlatformKey", nil));
    }
    std::string StringConstants::metadata_item_application_categories_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemApplicationCategoriesKey", nil));
    }
    std::string StringConstants::metadata_item_is_application_managed_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMetadataItemIsApplicationManagedKey", nil));
    }
    std::string StringConstants::net_services_error_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNetServicesErrorCode", nil));
    }
    std::string StringConstants::person_name_component_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentKey", nil));
    }
    std::string StringConstants::person_name_component_given_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentGivenName", nil));
    }
    std::string StringConstants::person_name_component_family_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentFamilyName", nil));
    }
    std::string StringConstants::person_name_component_middle_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentMiddleName", nil));
    }
    std::string StringConstants::person_name_component_prefix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentPrefix", nil));
    }
    std::string StringConstants::person_name_component_suffix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentSuffix", nil));
    }
    std::string StringConstants::person_name_component_nickname()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentNickname", nil));
    }
    std::string StringConstants::person_name_component_delimiter()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPersonNameComponentDelimiter", nil));
    }
    std::string StringConstants::operation_not_supported_for_key_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOperationNotSupportedForKeyException", nil));
    }
    std::string StringConstants::grammar_range()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGrammarRange", nil));
    }
    std::string StringConstants::grammar_user_description()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGrammarUserDescription", nil));
    }
    std::string StringConstants::grammar_corrections()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGrammarCorrections", nil));
    }
    std::string StringConstants::url_file_scheme()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileScheme", nil));
    }
    std::string StringConstants::url_credential_storage_remove_synchronizable_credentials()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLCredentialStorageRemoveSynchronizableCredentials", nil));
    }
    std::string StringConstants::url_error_failing_url_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorFailingURLErrorKey", nil));
    }
    std::string StringConstants::url_error_failing_url_peer_trust_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorFailingURLPeerTrustErrorKey", nil));
    }
    std::string StringConstants::url_error_background_task_cancelled_reason_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorBackgroundTaskCancelledReasonKey", nil));
    }
    std::string StringConstants::url_protection_space_http()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLProtectionSpaceHTTP", nil));
    }
    std::string StringConstants::url_protection_space_https()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLProtectionSpaceHTTPS", nil));
    }
    std::string StringConstants::url_protection_space_http_proxy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLProtectionSpaceHTTPProxy", nil));
    }
    std::string StringConstants::url_protection_space_https_proxy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLProtectionSpaceHTTPSProxy", nil));
    }
    std::string StringConstants::url_protection_space_socks_proxy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLProtectionSpaceSOCKSProxy", nil));
    }
    std::string StringConstants::url_authentication_method_default()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodDefault", nil));
    }
    std::string StringConstants::url_authentication_method_http_basic()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodHTTPBasic", nil));
    }
    std::string StringConstants::url_authentication_method_http_digest()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodHTTPDigest", nil));
    }
    std::string StringConstants::url_authentication_method_html_form()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodHTMLForm", nil));
    }
    std::string StringConstants::url_authentication_method_ntlm()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodNTLM", nil));
    }
    std::string StringConstants::url_authentication_method_negotiate()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodNegotiate", nil));
    }
    std::string StringConstants::url_authentication_method_client_certificate()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodClientCertificate", nil));
    }
    std::string StringConstants::url_authentication_method_server_trust()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAuthenticationMethodServerTrust", nil));
    }
    std::string StringConstants::url_session_download_task_resume_data()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLSessionDownloadTaskResumeData", nil));
    }
    std::string StringConstants::url_session_upload_task_resume_data()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLSessionUploadTaskResumeData", nil));
    }
    std::string StringConstants::ubiquitous_key_value_store_change_reason_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUbiquitousKeyValueStoreChangeReasonKey", nil));
    }
    std::string StringConstants::ubiquitous_key_value_store_changed_keys_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUbiquitousKeyValueStoreChangedKeysKey", nil));
    }
    std::string StringConstants::undo_manager_group_is_discardable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndoManagerGroupIsDiscardableKey", nil));
    }
    std::string StringConstants::user_activity_type_browsing_web()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUserActivityTypeBrowsingWeb", nil));
    }
    std::string StringConstants::global_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGlobalDomain", nil));
    }
    std::string StringConstants::argument_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSArgumentDomain", nil));
    }
    std::string StringConstants::registration_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRegistrationDomain", nil));
    }

    std::string AccessibilityAttributeName::accessibility_role_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRoleAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_role_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRoleDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_subrole_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySubroleAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_help_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHelpAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_value_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityValueAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_min_value_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMinValueAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_max_value_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMaxValueAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_enabled_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityEnabledAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_focused_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFocusedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_parent_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityParentAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_children_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityChildrenAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_window_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_top_level_ui_element_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTopLevelUIElementAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_children_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedChildrenAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visible_children_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleChildrenAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_position_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPositionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_size_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySizeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_contents_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityContentsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_title_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTitleAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_shown_menu_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityShownMenuAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_shared_focus_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySharedFocusElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_previous_contents_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPreviousContentsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_next_contents_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityNextContentsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_header_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeaderAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_edited_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityEditedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_tabs_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTabsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_horizontal_scroll_bar_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHorizontalScrollBarAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_vertical_scroll_bar_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVerticalScrollBarAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_overflow_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityOverflowButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_increment_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIncrementButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_decrement_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDecrementButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_filename_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFilenameAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_expanded_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityExpandedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_splitters_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySplittersAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDocumentAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_activation_point_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityActivationPointAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_url_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityURLAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_index_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIndexAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_contains_protected_content_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityContainsProtectedContentAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_alternate_ui_visible_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAlternateUIVisibleAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_required_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRequiredAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_auto_interactable_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAutoInteractableAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_date_time_components_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDateTimeComponentsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_embedded_image_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityEmbeddedImageDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_path_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPathAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_text_input_marked_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextInputMarkedRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_block_quote_level_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBlockQuoteLevelAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_heading_level_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevelAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_language_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLanguageAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visited_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisitedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_title_ui_element_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTitleUIElementAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_serves_as_title_for_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityServesAsTitleForUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_linked_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLinkedUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedTextAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_text_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedTextRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_number_of_characters_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityNumberOfCharactersAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visible_character_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleCharacterRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_shared_text_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySharedTextUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_shared_character_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySharedCharacterRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_insertion_point_line_number_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityInsertionPointLineNumberAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_children_in_navigation_order_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityChildrenInNavigationOrderAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_main_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMainAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_minimized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMinimizedAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_close_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCloseButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_zoom_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityZoomButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_minimize_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMinimizeButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_toolbar_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityToolbarButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_proxy_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityProxyAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_grow_area_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityGrowAreaAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_modal_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityModalAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_default_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDefaultButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_cancel_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCancelButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_full_screen_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFullScreenButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_menu_bar_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuBarAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_windows_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_frontmost_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFrontmostAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_hidden_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHiddenAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_main_window_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMainWindowAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_focused_window_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFocusedWindowAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_focused_ui_element_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFocusedUIElementAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_extras_menu_bar_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityExtrasMenuBarAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_orientation_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityOrientationAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_column_titles_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColumnTitlesAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_search_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_search_menu_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchMenuAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_clear_button_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityClearButtonAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_rows_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visible_rows_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleRowsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_rows_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedRowsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_columns_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColumnsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visible_columns_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleColumnsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_columns_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedColumnsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_sort_direction_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySortDirectionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_selected_cells_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedCellsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_visible_cells_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleCellsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_row_header_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowHeaderUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_column_header_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColumnHeaderUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_row_index_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowIndexRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_column_index_range_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColumnIndexRangeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_horizontal_units_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHorizontalUnitsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_vertical_units_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVerticalUnitsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_horizontal_unit_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHorizontalUnitDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_vertical_unit_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVerticalUnitDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_handles_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHandlesAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_disclosing_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDisclosingAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_disclosed_rows_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDisclosedRowsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_disclosed_by_row_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDisclosedByRowAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_disclosure_level_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDisclosureLevelAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_allowed_values_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAllowedValuesAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_label_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLabelUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_label_value_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLabelValueAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_marker_ui_elements_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkerUIElementsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_marker_values_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkerValuesAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_marker_group_ui_element_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkerGroupUIElementAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_units_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnitsAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_unit_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnitDescriptionAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_marker_type_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkerTypeAttribute", nil));
    }
    std::string AccessibilityAttributeName::accessibility_marker_type_description_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkerTypeDescriptionAttribute", nil));
    }

    std::string AccessibilityParameterizedAttributeName::accessibility_line_for_index_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLineForIndexParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_range_for_line_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRangeForLineParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_string_for_range_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStringForRangeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_range_for_position_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRangeForPositionParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_range_for_index_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRangeForIndexParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_bounds_for_range_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBoundsForRangeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_rtf_for_range_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRTFForRangeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_style_range_for_index_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStyleRangeForIndexParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_attributed_string_for_range_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAttributedStringForRangeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_index_for_child_ui_element_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIndexForChildUIElementAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_index_for_child_ui_element_in_navigation_order_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIndexForChildUIElementInNavigationOrderAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_cell_for_column_and_row_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCellForColumnAndRowParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_layout_point_for_screen_point_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLayoutPointForScreenPointParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_layout_size_for_screen_size_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLayoutSizeForScreenSizeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_screen_point_for_layout_point_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityScreenPointForLayoutPointParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_screen_size_for_layout_size_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityScreenSizeForLayoutSizeParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_ui_elements_for_search_predicate_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUIElementsForSearchPredicateParameterizedAttribute", nil));
    }
    std::string AccessibilityParameterizedAttributeName::accessibility_results_for_search_predicate_parameterized_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityResultsForSearchPredicateParameterizedAttribute", nil));
    }

    std::string AttributedStringKey::accessibility_font_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_foreground_color_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityForegroundColorTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_background_color_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBackgroundColorTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_underline_color_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnderlineColorTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_strikethrough_color_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStrikethroughColorTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_underline_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnderlineTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_superscript_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySuperscriptTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_strikethrough_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStrikethroughTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_shadow_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityShadowTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_attachment_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAttachmentTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_link_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLinkTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_autocorrected_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAutocorrectedTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_text_alignment_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextAlignmentAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_font_bold_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontBoldAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_font_italic_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontItalicAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_list_item_prefix_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListItemPrefixTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_list_item_index_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListItemIndexTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_list_item_level_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListItemLevelTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_misspelled_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMisspelledTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_marked_misspelled_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMarkedMisspelledTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_language_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLanguageTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_custom_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCustomTextAttribute", nil));
    }
    std::string AttributedStringKey::accessibility_annotation_text_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnotationTextAttribute", nil));
    }
    std::string AttributedStringKey::font_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontAttributeName", nil));
    }
    std::string AttributedStringKey::paragraph_style_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSParagraphStyleAttributeName", nil));
    }
    std::string AttributedStringKey::foreground_color_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSForegroundColorAttributeName", nil));
    }
    std::string AttributedStringKey::background_color_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBackgroundColorAttributeName", nil));
    }
    std::string AttributedStringKey::ligature_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLigatureAttributeName", nil));
    }
    std::string AttributedStringKey::kern_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKernAttributeName", nil));
    }
    std::string AttributedStringKey::tracking_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTrackingAttributeName", nil));
    }
    std::string AttributedStringKey::strikethrough_style_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStrikethroughStyleAttributeName", nil));
    }
    std::string AttributedStringKey::underline_style_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnderlineStyleAttributeName", nil));
    }
    std::string AttributedStringKey::stroke_color_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStrokeColorAttributeName", nil));
    }
    std::string AttributedStringKey::stroke_width_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStrokeWidthAttributeName", nil));
    }
    std::string AttributedStringKey::shadow_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSShadowAttributeName", nil));
    }
    std::string AttributedStringKey::text_effect_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextEffectAttributeName", nil));
    }
    std::string AttributedStringKey::attachment_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAttachmentAttributeName", nil));
    }
    std::string AttributedStringKey::link_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLinkAttributeName", nil));
    }
    std::string AttributedStringKey::baseline_offset_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBaselineOffsetAttributeName", nil));
    }
    std::string AttributedStringKey::underline_color_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnderlineColorAttributeName", nil));
    }
    std::string AttributedStringKey::strikethrough_color_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStrikethroughColorAttributeName", nil));
    }
    std::string AttributedStringKey::writing_direction_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWritingDirectionAttributeName", nil));
    }
    std::string AttributedStringKey::text_highlight_style_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightStyleAttributeName", nil));
    }
    std::string AttributedStringKey::text_highlight_color_scheme_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemeAttributeName", nil));
    }
    std::string AttributedStringKey::adaptive_image_glyph_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAdaptiveImageGlyphAttributeName", nil));
    }
    std::string AttributedStringKey::writing_tools_exclusion_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWritingToolsExclusionAttributeName", nil));
    }
    std::string AttributedStringKey::cursor_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCursorAttributeName", nil));
    }
    std::string AttributedStringKey::tool_tip_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolTipAttributeName", nil));
    }
    std::string AttributedStringKey::marked_clause_segment_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMarkedClauseSegmentAttributeName", nil));
    }
    std::string AttributedStringKey::text_alternatives_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextAlternativesAttributeName", nil));
    }
    std::string AttributedStringKey::spelling_state_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpellingStateAttributeName", nil));
    }
    std::string AttributedStringKey::superscript_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSuperscriptAttributeName", nil));
    }
    std::string AttributedStringKey::glyph_info_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGlyphInfoAttributeName", nil));
    }
    std::string AttributedStringKey::inline_presentation_intent_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInlinePresentationIntentAttributeName", nil));
    }
    std::string AttributedStringKey::alternate_description_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAlternateDescriptionAttributeName", nil));
    }
    std::string AttributedStringKey::image_url_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageURLAttributeName", nil));
    }
    std::string AttributedStringKey::language_identifier_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLanguageIdentifierAttributeName", nil));
    }
    std::string AttributedStringKey::markdown_source_position_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMarkdownSourcePositionAttributeName", nil));
    }
    std::string AttributedStringKey::replacement_index_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSReplacementIndexAttributeName", nil));
    }
    std::string AttributedStringKey::morphology_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMorphologyAttributeName", nil));
    }
    std::string AttributedStringKey::inflection_rule_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionRuleAttributeName", nil));
    }
    std::string AttributedStringKey::inflection_agreement_argument_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionAgreementArgumentAttributeName", nil));
    }
    std::string AttributedStringKey::inflection_agreement_concept_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionAgreementConceptAttributeName", nil));
    }
    std::string AttributedStringKey::inflection_referent_concept_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionReferentConceptAttributeName", nil));
    }
    std::string AttributedStringKey::inflection_alternative_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionAlternativeAttributeName", nil));
    }
    std::string AttributedStringKey::localized_number_format_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedNumberFormatAttributeName", nil));
    }
    std::string AttributedStringKey::list_item_delimiter_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSListItemDelimiterAttributeName", nil));
    }

    std::string AccessibilityAnnotationAttributeKey::accessibility_annotation_label()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnotationLabel", nil));
    }
    std::string AccessibilityAnnotationAttributeKey::accessibility_annotation_element()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnotationElement", nil));
    }
    std::string AccessibilityAnnotationAttributeKey::accessibility_annotation_location()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnotationLocation", nil));
    }

    std::string AccessibilityFontAttributeKey::accessibility_font_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontNameKey", nil));
    }
    std::string AccessibilityFontAttributeKey::accessibility_font_family_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontFamilyKey", nil));
    }
    std::string AccessibilityFontAttributeKey::accessibility_visible_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisibleNameKey", nil));
    }
    std::string AccessibilityFontAttributeKey::accessibility_font_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontSizeKey", nil));
    }

    std::string AccessibilityOrientationValue::accessibility_vertical_orientation_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVerticalOrientationValue", nil));
    }
    std::string AccessibilityOrientationValue::accessibility_horizontal_orientation_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHorizontalOrientationValue", nil));
    }
    std::string AccessibilityOrientationValue::accessibility_unknown_orientation_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownOrientationValue", nil));
    }

    std::string AccessibilitySortDirectionValue::accessibility_ascending_sort_direction_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAscendingSortDirectionValue", nil));
    }
    std::string AccessibilitySortDirectionValue::accessibility_descending_sort_direction_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDescendingSortDirectionValue", nil));
    }
    std::string AccessibilitySortDirectionValue::accessibility_unknown_sort_direction_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownSortDirectionValue", nil));
    }

    std::string AccessibilityRulerMarkerTypeValue::accessibility_left_tab_stop_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLeftTabStopMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_right_tab_stop_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRightTabStopMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_center_tab_stop_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCenterTabStopMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_decimal_tab_stop_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDecimalTabStopMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_head_indent_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadIndentMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_tail_indent_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTailIndentMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_first_line_indent_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFirstLineIndentMarkerTypeValue", nil));
    }
    std::string AccessibilityRulerMarkerTypeValue::accessibility_unknown_marker_type_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownMarkerTypeValue", nil));
    }

    std::string AccessibilityRulerUnitValue::accessibility_inches_unit_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityInchesUnitValue", nil));
    }
    std::string AccessibilityRulerUnitValue::accessibility_centimeters_unit_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCentimetersUnitValue", nil));
    }
    std::string AccessibilityRulerUnitValue::accessibility_points_unit_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPointsUnitValue", nil));
    }
    std::string AccessibilityRulerUnitValue::accessibility_picas_unit_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPicasUnitValue", nil));
    }
    std::string AccessibilityRulerUnitValue::accessibility_unknown_unit_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownUnitValue", nil));
    }

    std::string AccessibilityActionName::accessibility_press_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPressAction", nil));
    }
    std::string AccessibilityActionName::accessibility_increment_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIncrementAction", nil));
    }
    std::string AccessibilityActionName::accessibility_decrement_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDecrementAction", nil));
    }
    std::string AccessibilityActionName::accessibility_confirm_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityConfirmAction", nil));
    }
    std::string AccessibilityActionName::accessibility_pick_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPickAction", nil));
    }
    std::string AccessibilityActionName::accessibility_cancel_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCancelAction", nil));
    }
    std::string AccessibilityActionName::accessibility_raise_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRaiseAction", nil));
    }
    std::string AccessibilityActionName::accessibility_show_menu_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityShowMenuAction", nil));
    }
    std::string AccessibilityActionName::accessibility_delete_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDeleteAction", nil));
    }
    std::string AccessibilityActionName::accessibility_scroll_to_visible_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityScrollToVisibleAction", nil));
    }
    std::string AccessibilityActionName::accessibility_show_alternate_ui_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityShowAlternateUIAction", nil));
    }
    std::string AccessibilityActionName::accessibility_show_default_ui_action()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityShowDefaultUIAction", nil));
    }

    std::string AccessibilityNotificationName::accessibility_main_window_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMainWindowChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_focused_window_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFocusedWindowChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_focused_ui_element_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFocusedUIElementChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_application_activated_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityApplicationActivatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_application_deactivated_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityApplicationDeactivatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_application_hidden_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityApplicationHiddenNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_application_shown_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityApplicationShownNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_window_created_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowCreatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_window_moved_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowMovedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_window_resized_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowResizedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_window_miniaturized_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowMiniaturizedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_window_deminiaturized_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowDeminiaturizedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_drawer_created_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDrawerCreatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_sheet_created_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySheetCreatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_ui_element_destroyed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUIElementDestroyedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_value_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityValueChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_title_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTitleChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_resized_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityResizedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_moved_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMovedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_created_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCreatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_layout_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLayoutChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_help_tag_created_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHelpTagCreatedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_text_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedTextChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_row_count_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowCountChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_children_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedChildrenChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_rows_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedRowsChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_columns_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedColumnsChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_row_expanded_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowExpandedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_row_collapsed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowCollapsedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_autocorrection_occurred_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAutocorrectionOccurredNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_text_input_marking_session_began_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextInputMarkingSessionBeganNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_text_input_marking_session_ended_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextInputMarkingSessionEndedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_source_drag_began_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingSourceDragBeganNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_source_drag_ended_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingSourceDragEndedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_destination_drop_allowed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingDestinationDropAllowedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_destination_drop_not_allowed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingDestinationDropNotAllowedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_destination_drag_accepted_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingDestinationDragAcceptedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_dragging_destination_drag_not_accepted_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDraggingDestinationDragNotAcceptedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_cells_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedCellsChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_units_changed_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnitsChangedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_selected_children_moved_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySelectedChildrenMovedNotification", nil));
    }
    std::string AccessibilityNotificationName::accessibility_announcement_requested_notification()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnouncementRequestedNotification", nil));
    }

    std::string AccessibilityRole::accessibility_unknown_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownRole", nil));
    }
    std::string AccessibilityRole::accessibility_button_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityButtonRole", nil));
    }
    std::string AccessibilityRole::accessibility_radio_button_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRadioButtonRole", nil));
    }
    std::string AccessibilityRole::accessibility_check_box_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCheckBoxRole", nil));
    }
    std::string AccessibilityRole::accessibility_slider_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySliderRole", nil));
    }
    std::string AccessibilityRole::accessibility_tab_group_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTabGroupRole", nil));
    }
    std::string AccessibilityRole::accessibility_text_field_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextFieldRole", nil));
    }
    std::string AccessibilityRole::accessibility_static_text_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStaticTextRole", nil));
    }
    std::string AccessibilityRole::accessibility_text_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_scroll_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityScrollAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_pop_up_button_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPopUpButtonRole", nil));
    }
    std::string AccessibilityRole::accessibility_menu_button_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuButtonRole", nil));
    }
    std::string AccessibilityRole::accessibility_table_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTableRole", nil));
    }
    std::string AccessibilityRole::accessibility_application_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityApplicationRole", nil));
    }
    std::string AccessibilityRole::accessibility_group_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityGroupRole", nil));
    }
    std::string AccessibilityRole::accessibility_radio_group_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRadioGroupRole", nil));
    }
    std::string AccessibilityRole::accessibility_list_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListRole", nil));
    }
    std::string AccessibilityRole::accessibility_scroll_bar_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityScrollBarRole", nil));
    }
    std::string AccessibilityRole::accessibility_value_indicator_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityValueIndicatorRole", nil));
    }
    std::string AccessibilityRole::accessibility_image_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityImageRole", nil));
    }
    std::string AccessibilityRole::accessibility_menu_bar_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuBarRole", nil));
    }
    std::string AccessibilityRole::accessibility_menu_bar_item_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuBarItemRole", nil));
    }
    std::string AccessibilityRole::accessibility_menu_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuRole", nil));
    }
    std::string AccessibilityRole::accessibility_menu_item_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMenuItemRole", nil));
    }
    std::string AccessibilityRole::accessibility_column_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColumnRole", nil));
    }
    std::string AccessibilityRole::accessibility_row_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRowRole", nil));
    }
    std::string AccessibilityRole::accessibility_toolbar_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityToolbarRole", nil));
    }
    std::string AccessibilityRole::accessibility_busy_indicator_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBusyIndicatorRole", nil));
    }
    std::string AccessibilityRole::accessibility_progress_indicator_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityProgressIndicatorRole", nil));
    }
    std::string AccessibilityRole::accessibility_window_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWindowRole", nil));
    }
    std::string AccessibilityRole::accessibility_drawer_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDrawerRole", nil));
    }
    std::string AccessibilityRole::accessibility_system_wide_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySystemWideRole", nil));
    }
    std::string AccessibilityRole::accessibility_outline_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityOutlineRole", nil));
    }
    std::string AccessibilityRole::accessibility_incrementor_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIncrementorRole", nil));
    }
    std::string AccessibilityRole::accessibility_browser_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBrowserRole", nil));
    }
    std::string AccessibilityRole::accessibility_combo_box_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityComboBoxRole", nil));
    }
    std::string AccessibilityRole::accessibility_split_group_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySplitGroupRole", nil));
    }
    std::string AccessibilityRole::accessibility_splitter_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySplitterRole", nil));
    }
    std::string AccessibilityRole::accessibility_color_well_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityColorWellRole", nil));
    }
    std::string AccessibilityRole::accessibility_grow_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityGrowAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_sheet_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySheetRole", nil));
    }
    std::string AccessibilityRole::accessibility_help_tag_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHelpTagRole", nil));
    }
    std::string AccessibilityRole::accessibility_matte_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMatteRole", nil));
    }
    std::string AccessibilityRole::accessibility_ruler_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRulerRole", nil));
    }
    std::string AccessibilityRole::accessibility_ruler_marker_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRulerMarkerRole", nil));
    }
    std::string AccessibilityRole::accessibility_link_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLinkRole", nil));
    }
    std::string AccessibilityRole::accessibility_disclosure_triangle_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDisclosureTriangleRole", nil));
    }
    std::string AccessibilityRole::accessibility_grid_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityGridRole", nil));
    }
    std::string AccessibilityRole::accessibility_relevance_indicator_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRelevanceIndicatorRole", nil));
    }
    std::string AccessibilityRole::accessibility_date_time_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDateTimeAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_level_indicator_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLevelIndicatorRole", nil));
    }
    std::string AccessibilityRole::accessibility_cell_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCellRole", nil));
    }
    std::string AccessibilityRole::accessibility_popover_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPopoverRole", nil));
    }
    std::string AccessibilityRole::accessibility_page_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPageRole", nil));
    }
    std::string AccessibilityRole::accessibility_heading_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingRole", nil));
    }
    std::string AccessibilityRole::accessibility_list_marker_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListMarkerRole", nil));
    }
    std::string AccessibilityRole::accessibility_web_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityWebAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_layout_area_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLayoutAreaRole", nil));
    }
    std::string AccessibilityRole::accessibility_layout_item_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLayoutItemRole", nil));
    }
    std::string AccessibilityRole::accessibility_handle_role()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHandleRole", nil));
    }

    std::string AccessibilitySubrole::accessibility_unknown_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnknownSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_close_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCloseButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_zoom_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityZoomButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_minimize_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMinimizeButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_toolbar_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityToolbarButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_table_row_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTableRowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_outline_row_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityOutlineRowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_secure_text_field_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySecureTextFieldSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_standard_window_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStandardWindowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_dialog_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDialogSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_system_dialog_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySystemDialogSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_floating_window_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFloatingWindowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_system_floating_window_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySystemFloatingWindowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_increment_arrow_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIncrementArrowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_decrement_arrow_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDecrementArrowSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_increment_page_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityIncrementPageSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_decrement_page_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDecrementPageSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_search_field_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySearchFieldSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_text_attachment_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextAttachmentSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_text_link_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextLinkSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_timeline_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTimelineSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_sort_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySortButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_rating_indicator_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRatingIndicatorSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_content_list_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityContentListSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_definition_list_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDefinitionListSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_full_screen_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFullScreenButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_toggle_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityToggleSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_switch_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySwitchSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_description_list_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDescriptionListSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_tab_button_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTabButtonSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_collection_list_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCollectionListSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_section_list_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySectionListSubrole", nil));
    }
    std::string AccessibilitySubrole::accessibility_suggestion_subrole()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySuggestionSubrole", nil));
    }

    std::string AccessibilityNotificationUserInfoKey::accessibility_ui_elements_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUIElementsKey", nil));
    }
    std::string AccessibilityNotificationUserInfoKey::accessibility_priority_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPriorityKey", nil));
    }
    std::string AccessibilityNotificationUserInfoKey::accessibility_announcement_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnnouncementKey", nil));
    }

    std::string AccessibilitySearchKey::accessibility_any_type_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityAnyTypeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_article_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityArticleSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_blockquote_same_level_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBlockquoteSameLevelSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_blockquote_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBlockquoteSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_bold_font_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityBoldFontSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_button_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityButtonSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_check_box_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityCheckBoxSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_control_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityControlSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_different_type_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityDifferentTypeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_font_change_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontChangeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_font_color_change_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFontColorChangeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_frame_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityFrameSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_graphic_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityGraphicSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level1_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel1SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level2_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel2SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level3_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel3SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level4_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel4SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level5_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel5SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_level6_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingLevel6SearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_same_level_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingSameLevelSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_heading_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityHeadingSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_italic_font_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityItalicFontSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_keyboard_focusable_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityKeyboardFocusableSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_landmark_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLandmarkSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_link_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLinkSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_list_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityListSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_live_region_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityLiveRegionSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_misspelled_word_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityMisspelledWordSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_outline_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityOutlineSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_plain_text_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityPlainTextSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_radio_group_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityRadioGroupSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_same_type_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilitySameTypeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_static_text_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStaticTextSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_style_change_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityStyleChangeSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_table_same_level_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTableSameLevelSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_table_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTableSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_text_field_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextFieldSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_text_state_change_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextStateChangeTypeKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_text_state_sync_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityTextStateSyncKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_underline_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnderlineSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_unvisited_link_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityUnvisitedLinkSearchKey", nil));
    }
    std::string AccessibilitySearchKey::accessibility_visited_link_search_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAccessibilityVisitedLinkSearchKey", nil));
    }

    std::string ViewAnimationKey::view_animation_target_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationTargetKey", nil));
    }
    std::string ViewAnimationKey::view_animation_start_frame_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationStartFrameKey", nil));
    }
    std::string ViewAnimationKey::view_animation_end_frame_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationEndFrameKey", nil));
    }
    std::string ViewAnimationKey::view_animation_effect_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationEffectKey", nil));
    }

    std::string ViewAnimationEffectName::view_animation_fade_in_effect()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationFadeInEffect", nil));
    }
    std::string ViewAnimationEffectName::view_animation_fade_out_effect()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewAnimationFadeOutEffect", nil));
    }

    std::string AnimatablePropertyKey::animation_trigger_order_in()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimationTriggerOrderIn", nil));
    }
    std::string AnimatablePropertyKey::animation_trigger_order_out()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimationTriggerOrderOut", nil));
    }

    std::string AppearanceName::aqua()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameAqua", nil));
    }
    std::string AppearanceName::dark_aqua()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameDarkAqua", nil));
    }
    std::string AppearanceName::vibrant_dark()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameVibrantDark", nil));
    }
    std::string AppearanceName::vibrant_light()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameVibrantLight", nil));
    }
    std::string AppearanceName::accessibility_high_contrast_aqua()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameAccessibilityHighContrastAqua", nil));
    }
    std::string AppearanceName::accessibility_high_contrast_dark_aqua()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameAccessibilityHighContrastDarkAqua", nil));
    }
    std::string AppearanceName::accessibility_high_contrast_vibrant_light()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameAccessibilityHighContrastVibrantLight", nil));
    }
    std::string AppearanceName::accessibility_high_contrast_vibrant_dark()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceNameAccessibilityHighContrastVibrantDark", nil));
    }

    double AppKitVersion::number()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSAppKitVersion>("NSAppKitVersionNumber", ::NSAppKitVersion()));
    }

    std::string RunLoopMode::modal_panel_run_loop_mode()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSModalPanelRunLoopMode", nil));
    }
    std::string RunLoopMode::event_tracking_run_loop_mode()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSEventTrackingRunLoopMode", nil));
    }
    std::string RunLoopMode::default_run_loop_mode()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefaultRunLoopMode", nil));
    }
    std::string RunLoopMode::run_loop_common_modes()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRunLoopCommonModes", nil));
    }

    std::string AboutPanelOptionKey::about_panel_option_credits()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAboutPanelOptionCredits", nil));
    }
    std::string AboutPanelOptionKey::about_panel_option_application_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAboutPanelOptionApplicationName", nil));
    }
    std::string AboutPanelOptionKey::about_panel_option_application_icon()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAboutPanelOptionApplicationIcon", nil));
    }
    std::string AboutPanelOptionKey::about_panel_option_version()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAboutPanelOptionVersion", nil));
    }
    std::string AboutPanelOptionKey::about_panel_option_application_version()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAboutPanelOptionApplicationVersion", nil));
    }

    std::string TextEffectStyle::text_effect_letterpress_style()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextEffectLetterpressStyle", nil));
    }

    std::string TextHighlightStyle::default_()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightStyleDefault", nil));
    }

    std::string TextHighlightColorScheme::default_()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemeDefault", nil));
    }
    std::string TextHighlightColorScheme::purple()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemePurple", nil));
    }
    std::string TextHighlightColorScheme::pink()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemePink", nil));
    }
    std::string TextHighlightColorScheme::orange()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemeOrange", nil));
    }
    std::string TextHighlightColorScheme::mint()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemeMint", nil));
    }
    std::string TextHighlightColorScheme::blue()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextHighlightColorSchemeBlue", nil));
    }

    std::string AttributedStringDocumentType::plain_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPlainTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::rtf_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRTFTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::rtfd_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRTFDTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::html_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTMLTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::mac_simple_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMacSimpleTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::doc_format_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDocFormatTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::word_ml_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWordMLTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::web_archive_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWebArchiveTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::office_open_xml_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOfficeOpenXMLTextDocumentType", nil));
    }
    std::string AttributedStringDocumentType::open_document_text_document_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOpenDocumentTextDocumentType", nil));
    }

    std::string TextLayoutSectionKey::text_layout_section_orientation()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextLayoutSectionOrientation", nil));
    }
    std::string TextLayoutSectionKey::text_layout_section_range()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextLayoutSectionRange", nil));
    }

    std::string AttributedStringDocumentAttributeKey::document_type_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDocumentTypeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::character_encoding_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCharacterEncodingDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::default_attributes_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefaultAttributesDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::paper_size_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPaperSizeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::view_size_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewSizeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::view_zoom_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewZoomDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::view_mode_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSViewModeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::default_font_excluded_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefaultFontExcludedDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::read_only_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSReadOnlyDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::background_color_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBackgroundColorDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::hyphenation_factor_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHyphenationFactorDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::default_tab_interval_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefaultTabIntervalDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::text_layout_sections_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextLayoutSectionsAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::text_scaling_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextScalingDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::source_text_scaling_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSourceTextScalingDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::cocoa_version_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCocoaVersionDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::converted_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSConvertedDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::file_type_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::title_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTitleDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::company_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCompanyDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::copyright_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCopyrightDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::subject_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSubjectDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::author_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAuthorDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::keywords_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeywordsDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::comment_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCommentDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::editor_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSEditorDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::creation_time_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCreationTimeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::modification_time_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSModificationTimeDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::manager_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSManagerDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::category_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCategoryDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::appearance_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppearanceDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::excluded_elements_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSExcludedElementsDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::text_encoding_name_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextEncodingNameDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::prefix_spaces_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrefixSpacesDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::left_margin_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLeftMarginDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::right_margin_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRightMarginDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::top_margin_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTopMarginDocumentAttribute", nil));
    }
    std::string AttributedStringDocumentAttributeKey::bottom_margin_document_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBottomMarginDocumentAttribute", nil));
    }

    std::string AttributedStringDocumentReadingOptionKey::document_type_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDocumentTypeDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::default_attributes_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefaultAttributesDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::character_encoding_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCharacterEncodingDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::target_text_scaling_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTargetTextScalingDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::source_text_scaling_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSourceTextScalingDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::text_kit1_list_marker_format_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextKit1ListMarkerFormatDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::text_encoding_name_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextEncodingNameDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::base_url_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBaseURLDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::timeout_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTimeoutDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::web_preferences_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWebPreferencesDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::web_resource_load_delegate_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWebResourceLoadDelegateDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::text_size_multiplier_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextSizeMultiplierDocumentOption", nil));
    }
    std::string AttributedStringDocumentReadingOptionKey::file_type_document_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeDocumentOption", nil));
    }

    std::string BitmapImageRepPropertyKey::image_compression_method()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageCompressionMethod", nil));
    }
    std::string BitmapImageRepPropertyKey::image_compression_factor()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageCompressionFactor", nil));
    }
    std::string BitmapImageRepPropertyKey::image_dither_transparency()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageDitherTransparency", nil));
    }
    std::string BitmapImageRepPropertyKey::image_rgb_color_table()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageRGBColorTable", nil));
    }
    std::string BitmapImageRepPropertyKey::image_interlaced()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageInterlaced", nil));
    }
    std::string BitmapImageRepPropertyKey::image_color_sync_profile_data()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageColorSyncProfileData", nil));
    }
    std::string BitmapImageRepPropertyKey::image_frame_count()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageFrameCount", nil));
    }
    std::string BitmapImageRepPropertyKey::image_current_frame()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageCurrentFrame", nil));
    }
    std::string BitmapImageRepPropertyKey::image_current_frame_duration()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageCurrentFrameDuration", nil));
    }
    std::string BitmapImageRepPropertyKey::image_loop_count()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageLoopCount", nil));
    }
    std::string BitmapImageRepPropertyKey::image_gamma()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageGamma", nil));
    }
    std::string BitmapImageRepPropertyKey::image_progressive()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageProgressive", nil));
    }
    std::string BitmapImageRepPropertyKey::image_exif_data()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageEXIFData", nil));
    }
    std::string BitmapImageRepPropertyKey::image_iptc_data()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageIPTCData", nil));
    }
    std::string BitmapImageRepPropertyKey::image_fallback_background_color()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageFallbackBackgroundColor", nil));
    }

    std::string TouchBarItemIdentifier::candidate_list()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierCandidateList", nil));
    }
    std::string TouchBarItemIdentifier::character_picker()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierCharacterPicker", nil));
    }
    std::string TouchBarItemIdentifier::text_color_picker()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierTextColorPicker", nil));
    }
    std::string TouchBarItemIdentifier::text_style()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierTextStyle", nil));
    }
    std::string TouchBarItemIdentifier::text_alignment()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierTextAlignment", nil));
    }
    std::string TouchBarItemIdentifier::text_list()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierTextList", nil));
    }
    std::string TouchBarItemIdentifier::text_format()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierTextFormat", nil));
    }
    std::string TouchBarItemIdentifier::fixed_space_small()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierFixedSpaceSmall", nil));
    }
    std::string TouchBarItemIdentifier::fixed_space_large()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierFixedSpaceLarge", nil));
    }
    std::string TouchBarItemIdentifier::flexible_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierFlexibleSpace", nil));
    }
    std::string TouchBarItemIdentifier::other_items_proxy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTouchBarItemIdentifierOtherItemsProxy", nil));
    }

    std::string CollectionViewSupplementaryElementKind::collection_element_kind_section_header()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCollectionElementKindSectionHeader", nil));
    }
    std::string CollectionViewSupplementaryElementKind::collection_element_kind_section_footer()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCollectionElementKindSectionFooter", nil));
    }
    std::string CollectionViewSupplementaryElementKind::collection_element_kind_inter_item_gap_indicator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCollectionElementKindInterItemGapIndicator", nil));
    }

    std::string DraggingImageComponentKey::dragging_image_component_icon_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDraggingImageComponentIconKey", nil));
    }
    std::string DraggingImageComponentKey::dragging_image_component_label_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDraggingImageComponentLabelKey", nil));
    }

    std::string ExceptionName::text_line_too_long_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextLineTooLongException", nil));
    }
    std::string ExceptionName::text_no_selection_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextNoSelectionException", nil));
    }
    std::string ExceptionName::word_tables_write_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWordTablesWriteException", nil));
    }
    std::string ExceptionName::word_tables_read_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWordTablesReadException", nil));
    }
    std::string ExceptionName::text_read_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextReadException", nil));
    }
    std::string ExceptionName::text_write_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextWriteException", nil));
    }
    std::string ExceptionName::pasteboard_communication_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardCommunicationException", nil));
    }
    std::string ExceptionName::printing_communication_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintingCommunicationException", nil));
    }
    std::string ExceptionName::abort_modal_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAbortModalException", nil));
    }
    std::string ExceptionName::abort_printing_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAbortPrintingException", nil));
    }
    std::string ExceptionName::illegal_selector_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSIllegalSelectorException", nil));
    }
    std::string ExceptionName::app_kit_virtual_memory_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppKitVirtualMemoryException", nil));
    }
    std::string ExceptionName::bad_rtf_directive_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadRTFDirectiveException", nil));
    }
    std::string ExceptionName::bad_rtf_font_table_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadRTFFontTableException", nil));
    }
    std::string ExceptionName::bad_rtf_style_sheet_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadRTFStyleSheetException", nil));
    }
    std::string ExceptionName::typed_stream_version_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTypedStreamVersionException", nil));
    }
    std::string ExceptionName::tiff_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTIFFException", nil));
    }
    std::string ExceptionName::print_package_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPackageException", nil));
    }
    std::string ExceptionName::bad_rtf_color_table_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadRTFColorTableException", nil));
    }
    std::string ExceptionName::dragging_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDraggingException", nil));
    }
    std::string ExceptionName::color_list_io_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSColorListIOException", nil));
    }
    std::string ExceptionName::color_list_not_editable_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSColorListNotEditableException", nil));
    }
    std::string ExceptionName::bad_bitmap_parameters_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadBitmapParametersException", nil));
    }
    std::string ExceptionName::window_server_communication_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWindowServerCommunicationException", nil));
    }
    std::string ExceptionName::font_unavailable_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontUnavailableException", nil));
    }
    std::string ExceptionName::ppd_include_not_found_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPPDIncludeNotFoundException", nil));
    }
    std::string ExceptionName::ppd_parse_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPPDParseException", nil));
    }
    std::string ExceptionName::ppd_include_stack_overflow_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPPDIncludeStackOverflowException", nil));
    }
    std::string ExceptionName::ppd_include_stack_underflow_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPPDIncludeStackUnderflowException", nil));
    }
    std::string ExceptionName::rtf_property_stack_overflow_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRTFPropertyStackOverflowException", nil));
    }
    std::string ExceptionName::app_kit_ignored_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAppKitIgnoredException", nil));
    }
    std::string ExceptionName::bad_comparison_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBadComparisonException", nil));
    }
    std::string ExceptionName::image_cache_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageCacheException", nil));
    }
    std::string ExceptionName::nib_loading_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNibLoadingException", nil));
    }
    std::string ExceptionName::browser_illegal_delegate_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSBrowserIllegalDelegateException", nil));
    }
    std::string ExceptionName::print_operation_exists_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintOperationExistsException", nil));
    }
    std::string ExceptionName::decimal_number_exactness_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDecimalNumberExactnessException", nil));
    }
    std::string ExceptionName::decimal_number_overflow_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDecimalNumberOverflowException", nil));
    }
    std::string ExceptionName::decimal_number_underflow_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDecimalNumberUnderflowException", nil));
    }
    std::string ExceptionName::decimal_number_divide_by_zero_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDecimalNumberDivideByZeroException", nil));
    }
    std::string ExceptionName::generic_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGenericException", nil));
    }
    std::string ExceptionName::range_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRangeException", nil));
    }
    std::string ExceptionName::invalid_argument_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvalidArgumentException", nil));
    }
    std::string ExceptionName::internal_inconsistency_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInternalInconsistencyException", nil));
    }
    std::string ExceptionName::malloc_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMallocException", nil));
    }
    std::string ExceptionName::object_inaccessible_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSObjectInaccessibleException", nil));
    }
    std::string ExceptionName::object_not_available_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSObjectNotAvailableException", nil));
    }
    std::string ExceptionName::destination_invalid_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDestinationInvalidException", nil));
    }
    std::string ExceptionName::port_timeout_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPortTimeoutException", nil));
    }
    std::string ExceptionName::invalid_send_port_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvalidSendPortException", nil));
    }
    std::string ExceptionName::invalid_receive_port_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvalidReceivePortException", nil));
    }
    std::string ExceptionName::port_send_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPortSendException", nil));
    }
    std::string ExceptionName::port_receive_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPortReceiveException", nil));
    }
    std::string ExceptionName::old_style_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOldStyleException", nil));
    }
    std::string ExceptionName::inconsistent_archive_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInconsistentArchiveException", nil));
    }
    std::string ExceptionName::file_handle_operation_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHandleOperationException", nil));
    }
    std::string ExceptionName::undefined_key_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUndefinedKeyException", nil));
    }
    std::string ExceptionName::invalid_archive_operation_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvalidArchiveOperationException", nil));
    }
    std::string ExceptionName::invalid_unarchive_operation_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvalidUnarchiveOperationException", nil));
    }
    std::string ExceptionName::invocation_operation_void_result_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvocationOperationVoidResultException", nil));
    }
    std::string ExceptionName::invocation_operation_cancelled_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvocationOperationCancelledException", nil));
    }
    std::string ExceptionName::character_conversion_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCharacterConversionException", nil));
    }
    std::string ExceptionName::parse_error_exception()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSParseErrorException", nil));
    }

    std::string FontCollectionMatchingOptionKey::font_collection_include_disabled_fonts_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionIncludeDisabledFontsOption", nil));
    }
    std::string FontCollectionMatchingOptionKey::font_collection_remove_duplicates_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionRemoveDuplicatesOption", nil));
    }
    std::string FontCollectionMatchingOptionKey::font_collection_disallow_auto_activation_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionDisallowAutoActivationOption", nil));
    }

    std::string FontCollectionUserInfoKey::font_collection_action_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionActionKey", nil));
    }
    std::string FontCollectionUserInfoKey::font_collection_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionNameKey", nil));
    }
    std::string FontCollectionUserInfoKey::font_collection_old_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionOldNameKey", nil));
    }
    std::string FontCollectionUserInfoKey::font_collection_visibility_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionVisibilityKey", nil));
    }

    std::string FontCollectionActionTypeKey::font_collection_was_shown()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionWasShown", nil));
    }
    std::string FontCollectionActionTypeKey::font_collection_was_hidden()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionWasHidden", nil));
    }
    std::string FontCollectionActionTypeKey::font_collection_was_renamed()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionWasRenamed", nil));
    }

    std::string FontCollectionName::font_collection_all_fonts()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionAllFonts", nil));
    }
    std::string FontCollectionName::font_collection_user()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionUser", nil));
    }
    std::string FontCollectionName::font_collection_favorites()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionFavorites", nil));
    }
    std::string FontCollectionName::font_collection_recently_used()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCollectionRecentlyUsed", nil));
    }

    std::string FontDescriptorAttributeName::font_family_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFamilyAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_name_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontNameAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_face_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFaceAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_size_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontSizeAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_visible_name_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVisibleNameAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_matrix_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontMatrixAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_variation_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_character_set_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCharacterSetAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_cascade_list_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontCascadeListAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_traits_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTraitsAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_fixed_advance_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFixedAdvanceAttribute", nil));
    }
    std::string FontDescriptorAttributeName::font_feature_settings_attribute()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFeatureSettingsAttribute", nil));
    }

    std::string FontDescriptorTraitKey::font_symbolic_trait()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontSymbolicTrait", nil));
    }
    std::string FontDescriptorTraitKey::font_weight_trait()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontWeightTrait", nil));
    }
    std::string FontDescriptorTraitKey::font_width_trait()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontWidthTrait", nil));
    }
    std::string FontDescriptorTraitKey::font_slant_trait()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontSlantTrait", nil));
    }

    std::string FontDescriptorVariationKey::font_variation_axis_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAxisIdentifierKey", nil));
    }
    std::string FontDescriptorVariationKey::font_variation_axis_minimum_value_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAxisMinimumValueKey", nil));
    }
    std::string FontDescriptorVariationKey::font_variation_axis_maximum_value_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAxisMaximumValueKey", nil));
    }
    std::string FontDescriptorVariationKey::font_variation_axis_default_value_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAxisDefaultValueKey", nil));
    }
    std::string FontDescriptorVariationKey::font_variation_axis_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontVariationAxisNameKey", nil));
    }

    std::string FontDescriptorFeatureKey::font_feature_type_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFeatureTypeIdentifierKey", nil));
    }
    std::string FontDescriptorFeatureKey::font_feature_selector_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFeatureSelectorIdentifierKey", nil));
    }

    double FontWeight::ultra_light()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightUltraLight", ::NSFontWeight()));
    }
    double FontWeight::thin()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightThin", ::NSFontWeight()));
    }
    double FontWeight::light()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightLight", ::NSFontWeight()));
    }
    double FontWeight::regular()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightRegular", ::NSFontWeight()));
    }
    double FontWeight::medium()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightMedium", ::NSFontWeight()));
    }
    double FontWeight::semibold()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightSemibold", ::NSFontWeight()));
    }
    double FontWeight::bold()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightBold", ::NSFontWeight()));
    }
    double FontWeight::heavy()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightHeavy", ::NSFontWeight()));
    }
    double FontWeight::black()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWeight>("NSFontWeightBlack", ::NSFontWeight()));
    }

    double FontWidth::compressed()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWidth>("NSFontWidthCompressed", ::NSFontWidth()));
    }
    double FontWidth::condensed()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWidth>("NSFontWidthCondensed", ::NSFontWidth()));
    }
    double FontWidth::standard()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWidth>("NSFontWidthStandard", ::NSFontWidth()));
    }
    double FontWidth::expanded()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSFontWidth>("NSFontWidthExpanded", ::NSFontWidth()));
    }

    std::string FontDescriptorSystemDesign::default_()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontDescriptorSystemDesignDefault", nil));
    }
    std::string FontDescriptorSystemDesign::serif()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontDescriptorSystemDesignSerif", nil));
    }
    std::string FontDescriptorSystemDesign::monospaced()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontDescriptorSystemDesignMonospaced", nil));
    }
    std::string FontDescriptorSystemDesign::rounded()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontDescriptorSystemDesignRounded", nil));
    }

    std::string FontTextStyle::large_title()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleLargeTitle", nil));
    }
    std::string FontTextStyle::title1()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleTitle1", nil));
    }
    std::string FontTextStyle::title2()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleTitle2", nil));
    }
    std::string FontTextStyle::title3()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleTitle3", nil));
    }
    std::string FontTextStyle::headline()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleHeadline", nil));
    }
    std::string FontTextStyle::subheadline()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleSubheadline", nil));
    }
    std::string FontTextStyle::body()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleBody", nil));
    }
    std::string FontTextStyle::callout()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleCallout", nil));
    }
    std::string FontTextStyle::footnote()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleFootnote", nil));
    }
    std::string FontTextStyle::caption1()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleCaption1", nil));
    }
    std::string FontTextStyle::caption2()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontTextStyleCaption2", nil));
    }

    std::string ColorSpaceName::calibrated_white_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalibratedWhiteColorSpace", nil));
    }
    std::string ColorSpaceName::calibrated_rgb_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalibratedRGBColorSpace", nil));
    }
    std::string ColorSpaceName::device_white_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceWhiteColorSpace", nil));
    }
    std::string ColorSpaceName::device_rgb_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceRGBColorSpace", nil));
    }
    std::string ColorSpaceName::device_cmyk_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceCMYKColorSpace", nil));
    }
    std::string ColorSpaceName::named_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNamedColorSpace", nil));
    }
    std::string ColorSpaceName::pattern_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPatternColorSpace", nil));
    }
    std::string ColorSpaceName::custom_color_space()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCustomColorSpace", nil));
    }

    double NumberConstants::white()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSWhite", ::CGFloat()));
    }
    double NumberConstants::light_gray()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSLightGray", ::CGFloat()));
    }
    double NumberConstants::dark_gray()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSDarkGray", ::CGFloat()));
    }
    double NumberConstants::black()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSBlack", ::CGFloat()));
    }
    double NumberConstants::grid_view_size_for_content()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSGridViewSizeForContent", ::CGFloat()));
    }
    double NumberConstants::view_no_intrinsic_metric()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSViewNoIntrinsicMetric", ::CGFloat()));
    }
    double NumberConstants::split_view_controller_automatic_dimension()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSSplitViewControllerAutomaticDimension", ::CGFloat()));
    }
    double NumberConstants::split_view_item_unspecified_dimension()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::CGFloat>("NSSplitViewItemUnspecifiedDimension", ::CGFloat()));
    }
    double NumberConstants::apple_event_time_out_default()
    {
        return static_cast<double>(cocoon::internal::load_symbol<double>("NSAppleEventTimeOutDefault", double()));
    }
    double NumberConstants::apple_event_time_out_none()
    {
        return static_cast<double>(cocoon::internal::load_symbol<double>("NSAppleEventTimeOutNone", double()));
    }
    bool NumberConstants::debug_enabled()
    {
        return static_cast<bool>(cocoon::internal::load_symbol<::BOOL>("NSDebugEnabled", ::BOOL()));
    }
    bool NumberConstants::zombie_enabled()
    {
        return static_cast<bool>(cocoon::internal::load_symbol<::BOOL>("NSZombieEnabled", ::BOOL()));
    }
    bool NumberConstants::deallocate_zombies()
    {
        return static_cast<bool>(cocoon::internal::load_symbol<::BOOL>("NSDeallocateZombies", ::BOOL()));
    }
    bool NumberConstants::keep_allocation_statistics()
    {
        return static_cast<bool>(cocoon::internal::load_symbol<::BOOL>("NSKeepAllocationStatistics", ::BOOL()));
    }
    double NumberConstants::foundation_version_number()
    {
        return static_cast<double>(cocoon::internal::load_symbol<double>("NSFoundationVersionNumber", double()));
    }
    std::int64_t NumberConstants::url_session_transfer_size_unknown()
    {
        return static_cast<std::int64_t>(cocoon::internal::load_symbol<::int64_t>("NSURLSessionTransferSizeUnknown", ::int64_t()));
    }
    float NumberConstants::url_session_task_priority_default()
    {
        return static_cast<float>(cocoon::internal::load_symbol<float>("NSURLSessionTaskPriorityDefault", float()));
    }
    float NumberConstants::url_session_task_priority_low()
    {
        return static_cast<float>(cocoon::internal::load_symbol<float>("NSURLSessionTaskPriorityLow", float()));
    }
    float NumberConstants::url_session_task_priority_high()
    {
        return static_cast<float>(cocoon::internal::load_symbol<float>("NSURLSessionTaskPriorityHigh", float()));
    }

    std::string DeviceDescriptionKey::device_resolution()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceResolution", nil));
    }
    std::string DeviceDescriptionKey::device_color_space_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceColorSpaceName", nil));
    }
    std::string DeviceDescriptionKey::device_bits_per_sample()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceBitsPerSample", nil));
    }
    std::string DeviceDescriptionKey::device_is_screen()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceIsScreen", nil));
    }
    std::string DeviceDescriptionKey::device_is_printer()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceIsPrinter", nil));
    }
    std::string DeviceDescriptionKey::device_size()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeviceSize", nil));
    }

    std::string GraphicsContextAttributeKey::graphics_context_destination_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGraphicsContextDestinationAttributeName", nil));
    }
    std::string GraphicsContextAttributeKey::graphics_context_representation_format_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGraphicsContextRepresentationFormatAttributeName", nil));
    }

    std::string GraphicsContextRepresentationFormatName::graphics_context_ps_format()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGraphicsContextPSFormat", nil));
    }
    std::string GraphicsContextRepresentationFormatName::graphics_context_pdf_format()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSGraphicsContextPDFFormat", nil));
    }

    std::string ImageHintKey::image_hint_ctm()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageHintCTM", nil));
    }
    std::string ImageHintKey::image_hint_interpolation()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageHintInterpolation", nil));
    }
    std::string ImageHintKey::image_hint_user_interface_layout_direction()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageHintUserInterfaceLayoutDirection", nil));
    }

    std::string ImageName::add_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameAddTemplate", nil));
    }
    std::string ImageName::bluetooth_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameBluetoothTemplate", nil));
    }
    std::string ImageName::bonjour()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameBonjour", nil));
    }
    std::string ImageName::bookmarks_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameBookmarksTemplate", nil));
    }
    std::string ImageName::caution()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameCaution", nil));
    }
    std::string ImageName::computer()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameComputer", nil));
    }
    std::string ImageName::enter_full_screen_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameEnterFullScreenTemplate", nil));
    }
    std::string ImageName::exit_full_screen_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameExitFullScreenTemplate", nil));
    }
    std::string ImageName::folder()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFolder", nil));
    }
    std::string ImageName::folder_burnable()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFolderBurnable", nil));
    }
    std::string ImageName::folder_smart()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFolderSmart", nil));
    }
    std::string ImageName::follow_link_freestanding_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFollowLinkFreestandingTemplate", nil));
    }
    std::string ImageName::home_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameHomeTemplate", nil));
    }
    std::string ImageName::i_chat_theater_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameIChatTheaterTemplate", nil));
    }
    std::string ImageName::lock_locked_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameLockLockedTemplate", nil));
    }
    std::string ImageName::lock_unlocked_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameLockUnlockedTemplate", nil));
    }
    std::string ImageName::network()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameNetwork", nil));
    }
    std::string ImageName::path_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNamePathTemplate", nil));
    }
    std::string ImageName::quick_look_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameQuickLookTemplate", nil));
    }
    std::string ImageName::refresh_freestanding_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameRefreshFreestandingTemplate", nil));
    }
    std::string ImageName::refresh_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameRefreshTemplate", nil));
    }
    std::string ImageName::remove_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameRemoveTemplate", nil));
    }
    std::string ImageName::reveal_freestanding_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameRevealFreestandingTemplate", nil));
    }
    std::string ImageName::share_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameShareTemplate", nil));
    }
    std::string ImageName::slideshow_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameSlideshowTemplate", nil));
    }
    std::string ImageName::status_available()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStatusAvailable", nil));
    }
    std::string ImageName::status_none()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStatusNone", nil));
    }
    std::string ImageName::status_partially_available()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStatusPartiallyAvailable", nil));
    }
    std::string ImageName::status_unavailable()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStatusUnavailable", nil));
    }
    std::string ImageName::stop_progress_freestanding_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStopProgressFreestandingTemplate", nil));
    }
    std::string ImageName::stop_progress_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameStopProgressTemplate", nil));
    }
    std::string ImageName::trash_empty()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTrashEmpty", nil));
    }
    std::string ImageName::trash_full()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTrashFull", nil));
    }
    std::string ImageName::action_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameActionTemplate", nil));
    }
    std::string ImageName::smart_badge_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameSmartBadgeTemplate", nil));
    }
    std::string ImageName::icon_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameIconViewTemplate", nil));
    }
    std::string ImageName::list_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameListViewTemplate", nil));
    }
    std::string ImageName::column_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameColumnViewTemplate", nil));
    }
    std::string ImageName::flow_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFlowViewTemplate", nil));
    }
    std::string ImageName::invalid_data_freestanding_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameInvalidDataFreestandingTemplate", nil));
    }
    std::string ImageName::go_forward_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameGoForwardTemplate", nil));
    }
    std::string ImageName::go_back_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameGoBackTemplate", nil));
    }
    std::string ImageName::go_right_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameGoRightTemplate", nil));
    }
    std::string ImageName::go_left_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameGoLeftTemplate", nil));
    }
    std::string ImageName::right_facing_triangle_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameRightFacingTriangleTemplate", nil));
    }
    std::string ImageName::left_facing_triangle_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameLeftFacingTriangleTemplate", nil));
    }
    std::string ImageName::mobile_me()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameMobileMe", nil));
    }
    std::string ImageName::multiple_documents()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameMultipleDocuments", nil));
    }
    std::string ImageName::user_accounts()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameUserAccounts", nil));
    }
    std::string ImageName::preferences_general()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNamePreferencesGeneral", nil));
    }
    std::string ImageName::advanced()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameAdvanced", nil));
    }
    std::string ImageName::info()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameInfo", nil));
    }
    std::string ImageName::font_panel()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameFontPanel", nil));
    }
    std::string ImageName::color_panel()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameColorPanel", nil));
    }
    std::string ImageName::user()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameUser", nil));
    }
    std::string ImageName::user_group()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameUserGroup", nil));
    }
    std::string ImageName::everyone()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameEveryone", nil));
    }
    std::string ImageName::user_guest()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameUserGuest", nil));
    }
    std::string ImageName::menu_on_state_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameMenuOnStateTemplate", nil));
    }
    std::string ImageName::menu_mixed_state_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameMenuMixedStateTemplate", nil));
    }
    std::string ImageName::application_icon()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameApplicationIcon", nil));
    }
    std::string ImageName::touch_bar_add_detail_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAddDetailTemplate", nil));
    }
    std::string ImageName::touch_bar_add_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAddTemplate", nil));
    }
    std::string ImageName::touch_bar_alarm_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAlarmTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_input_mute_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioInputMuteTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_input_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioInputTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_output_mute_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioOutputMuteTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_output_volume_high_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioOutputVolumeHighTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_output_volume_low_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioOutputVolumeLowTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_output_volume_medium_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioOutputVolumeMediumTemplate", nil));
    }
    std::string ImageName::touch_bar_audio_output_volume_off_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarAudioOutputVolumeOffTemplate", nil));
    }
    std::string ImageName::touch_bar_bookmarks_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarBookmarksTemplate", nil));
    }
    std::string ImageName::touch_bar_color_picker_fill()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarColorPickerFill", nil));
    }
    std::string ImageName::touch_bar_color_picker_font()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarColorPickerFont", nil));
    }
    std::string ImageName::touch_bar_color_picker_stroke()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarColorPickerStroke", nil));
    }
    std::string ImageName::touch_bar_communication_audio_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarCommunicationAudioTemplate", nil));
    }
    std::string ImageName::touch_bar_communication_video_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarCommunicationVideoTemplate", nil));
    }
    std::string ImageName::touch_bar_compose_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarComposeTemplate", nil));
    }
    std::string ImageName::touch_bar_delete_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarDeleteTemplate", nil));
    }
    std::string ImageName::touch_bar_download_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarDownloadTemplate", nil));
    }
    std::string ImageName::touch_bar_enter_full_screen_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarEnterFullScreenTemplate", nil));
    }
    std::string ImageName::touch_bar_exit_full_screen_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarExitFullScreenTemplate", nil));
    }
    std::string ImageName::touch_bar_fast_forward_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarFastForwardTemplate", nil));
    }
    std::string ImageName::touch_bar_folder_copy_to_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarFolderCopyToTemplate", nil));
    }
    std::string ImageName::touch_bar_folder_move_to_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarFolderMoveToTemplate", nil));
    }
    std::string ImageName::touch_bar_folder_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarFolderTemplate", nil));
    }
    std::string ImageName::touch_bar_get_info_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarGetInfoTemplate", nil));
    }
    std::string ImageName::touch_bar_go_back_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarGoBackTemplate", nil));
    }
    std::string ImageName::touch_bar_go_down_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarGoDownTemplate", nil));
    }
    std::string ImageName::touch_bar_go_forward_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarGoForwardTemplate", nil));
    }
    std::string ImageName::touch_bar_go_up_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarGoUpTemplate", nil));
    }
    std::string ImageName::touch_bar_history_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarHistoryTemplate", nil));
    }
    std::string ImageName::touch_bar_icon_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarIconViewTemplate", nil));
    }
    std::string ImageName::touch_bar_list_view_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarListViewTemplate", nil));
    }
    std::string ImageName::touch_bar_mail_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarMailTemplate", nil));
    }
    std::string ImageName::touch_bar_new_folder_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarNewFolderTemplate", nil));
    }
    std::string ImageName::touch_bar_new_message_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarNewMessageTemplate", nil));
    }
    std::string ImageName::touch_bar_open_in_browser_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarOpenInBrowserTemplate", nil));
    }
    std::string ImageName::touch_bar_pause_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarPauseTemplate", nil));
    }
    std::string ImageName::touch_bar_play_pause_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarPlayPauseTemplate", nil));
    }
    std::string ImageName::touch_bar_play_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarPlayTemplate", nil));
    }
    std::string ImageName::touch_bar_quick_look_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarQuickLookTemplate", nil));
    }
    std::string ImageName::touch_bar_record_start_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRecordStartTemplate", nil));
    }
    std::string ImageName::touch_bar_record_stop_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRecordStopTemplate", nil));
    }
    std::string ImageName::touch_bar_refresh_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRefreshTemplate", nil));
    }
    std::string ImageName::touch_bar_remove_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRemoveTemplate", nil));
    }
    std::string ImageName::touch_bar_rewind_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRewindTemplate", nil));
    }
    std::string ImageName::touch_bar_rotate_left_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRotateLeftTemplate", nil));
    }
    std::string ImageName::touch_bar_rotate_right_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarRotateRightTemplate", nil));
    }
    std::string ImageName::touch_bar_search_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSearchTemplate", nil));
    }
    std::string ImageName::touch_bar_share_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarShareTemplate", nil));
    }
    std::string ImageName::touch_bar_sidebar_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSidebarTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_ahead15_seconds_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipAhead15SecondsTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_ahead30_seconds_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipAhead30SecondsTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_ahead_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipAheadTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_back15_seconds_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipBack15SecondsTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_back30_seconds_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipBack30SecondsTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_back_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipBackTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_to_end_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipToEndTemplate", nil));
    }
    std::string ImageName::touch_bar_skip_to_start_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSkipToStartTemplate", nil));
    }
    std::string ImageName::touch_bar_slideshow_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarSlideshowTemplate", nil));
    }
    std::string ImageName::touch_bar_tag_icon_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTagIconTemplate", nil));
    }
    std::string ImageName::touch_bar_text_bold_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextBoldTemplate", nil));
    }
    std::string ImageName::touch_bar_text_box_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextBoxTemplate", nil));
    }
    std::string ImageName::touch_bar_text_center_align_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextCenterAlignTemplate", nil));
    }
    std::string ImageName::touch_bar_text_italic_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextItalicTemplate", nil));
    }
    std::string ImageName::touch_bar_text_justified_align_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextJustifiedAlignTemplate", nil));
    }
    std::string ImageName::touch_bar_text_left_align_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextLeftAlignTemplate", nil));
    }
    std::string ImageName::touch_bar_text_list_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextListTemplate", nil));
    }
    std::string ImageName::touch_bar_text_right_align_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextRightAlignTemplate", nil));
    }
    std::string ImageName::touch_bar_text_strikethrough_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextStrikethroughTemplate", nil));
    }
    std::string ImageName::touch_bar_text_underline_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarTextUnderlineTemplate", nil));
    }
    std::string ImageName::touch_bar_user_add_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarUserAddTemplate", nil));
    }
    std::string ImageName::touch_bar_user_group_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarUserGroupTemplate", nil));
    }
    std::string ImageName::touch_bar_user_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarUserTemplate", nil));
    }
    std::string ImageName::touch_bar_volume_down_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarVolumeDownTemplate", nil));
    }
    std::string ImageName::touch_bar_volume_up_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarVolumeUpTemplate", nil));
    }
    std::string ImageName::touch_bar_playhead_template()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageNameTouchBarPlayheadTemplate", nil));
    }

    std::string BindingInfoKey::observed_object_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSObservedObjectKey", nil));
    }
    std::string BindingInfoKey::observed_key_path_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSObservedKeyPathKey", nil));
    }
    std::string BindingInfoKey::options_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOptionsKey", nil));
    }

    std::string BindingName::alignment_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAlignmentBinding", nil));
    }
    std::string BindingName::alternate_image_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAlternateImageBinding", nil));
    }
    std::string BindingName::alternate_title_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAlternateTitleBinding", nil));
    }
    std::string BindingName::animate_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimateBinding", nil));
    }
    std::string BindingName::animation_delay_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAnimationDelayBinding", nil));
    }
    std::string BindingName::argument_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSArgumentBinding", nil));
    }
    std::string BindingName::attributed_string_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAttributedStringBinding", nil));
    }
    std::string BindingName::content_array_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentArrayBinding", nil));
    }
    std::string BindingName::content_array_for_multiple_selection_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentArrayForMultipleSelectionBinding", nil));
    }
    std::string BindingName::content_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentBinding", nil));
    }
    std::string BindingName::content_dictionary_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentDictionaryBinding", nil));
    }
    std::string BindingName::content_height_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentHeightBinding", nil));
    }
    std::string BindingName::content_object_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentObjectBinding", nil));
    }
    std::string BindingName::content_objects_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentObjectsBinding", nil));
    }
    std::string BindingName::content_set_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentSetBinding", nil));
    }
    std::string BindingName::content_values_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentValuesBinding", nil));
    }
    std::string BindingName::content_width_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentWidthBinding", nil));
    }
    std::string BindingName::critical_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCriticalValueBinding", nil));
    }
    std::string BindingName::data_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDataBinding", nil));
    }
    std::string BindingName::display_pattern_title_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDisplayPatternTitleBinding", nil));
    }
    std::string BindingName::display_pattern_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDisplayPatternValueBinding", nil));
    }
    std::string BindingName::document_edited_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDocumentEditedBinding", nil));
    }
    std::string BindingName::double_click_argument_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDoubleClickArgumentBinding", nil));
    }
    std::string BindingName::double_click_target_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDoubleClickTargetBinding", nil));
    }
    std::string BindingName::editable_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSEditableBinding", nil));
    }
    std::string BindingName::enabled_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSEnabledBinding", nil));
    }
    std::string BindingName::excluded_keys_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSExcludedKeysBinding", nil));
    }
    std::string BindingName::filter_predicate_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFilterPredicateBinding", nil));
    }
    std::string BindingName::font_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontBinding", nil));
    }
    std::string BindingName::font_bold_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontBoldBinding", nil));
    }
    std::string BindingName::font_family_name_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontFamilyNameBinding", nil));
    }
    std::string BindingName::font_italic_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontItalicBinding", nil));
    }
    std::string BindingName::font_name_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontNameBinding", nil));
    }
    std::string BindingName::font_size_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFontSizeBinding", nil));
    }
    std::string BindingName::header_title_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHeaderTitleBinding", nil));
    }
    std::string BindingName::hidden_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHiddenBinding", nil));
    }
    std::string BindingName::image_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSImageBinding", nil));
    }
    std::string BindingName::included_keys_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSIncludedKeysBinding", nil));
    }
    std::string BindingName::initial_key_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInitialKeyBinding", nil));
    }
    std::string BindingName::initial_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInitialValueBinding", nil));
    }
    std::string BindingName::is_indeterminate_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSIsIndeterminateBinding", nil));
    }
    std::string BindingName::label_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLabelBinding", nil));
    }
    std::string BindingName::localized_key_dictionary_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedKeyDictionaryBinding", nil));
    }
    std::string BindingName::managed_object_context_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSManagedObjectContextBinding", nil));
    }
    std::string BindingName::maximum_recents_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMaximumRecentsBinding", nil));
    }
    std::string BindingName::max_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMaxValueBinding", nil));
    }
    std::string BindingName::max_width_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMaxWidthBinding", nil));
    }
    std::string BindingName::min_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMinValueBinding", nil));
    }
    std::string BindingName::min_width_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMinWidthBinding", nil));
    }
    std::string BindingName::mixed_state_image_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMixedStateImageBinding", nil));
    }
    std::string BindingName::off_state_image_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOffStateImageBinding", nil));
    }
    std::string BindingName::on_state_image_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOnStateImageBinding", nil));
    }
    std::string BindingName::positioning_rect_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPositioningRectBinding", nil));
    }
    std::string BindingName::predicate_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPredicateBinding", nil));
    }
    std::string BindingName::recent_searches_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRecentSearchesBinding", nil));
    }
    std::string BindingName::represented_filename_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRepresentedFilenameBinding", nil));
    }
    std::string BindingName::row_height_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRowHeightBinding", nil));
    }
    std::string BindingName::selected_identifier_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedIdentifierBinding", nil));
    }
    std::string BindingName::selected_index_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedIndexBinding", nil));
    }
    std::string BindingName::selected_label_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedLabelBinding", nil));
    }
    std::string BindingName::selected_object_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedObjectBinding", nil));
    }
    std::string BindingName::selected_objects_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedObjectsBinding", nil));
    }
    std::string BindingName::selected_tag_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedTagBinding", nil));
    }
    std::string BindingName::selected_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedValueBinding", nil));
    }
    std::string BindingName::selected_values_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectedValuesBinding", nil));
    }
    std::string BindingName::selection_indexes_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectionIndexesBinding", nil));
    }
    std::string BindingName::selection_index_paths_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectionIndexPathsBinding", nil));
    }
    std::string BindingName::sort_descriptors_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSortDescriptorsBinding", nil));
    }
    std::string BindingName::target_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTargetBinding", nil));
    }
    std::string BindingName::text_color_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextColorBinding", nil));
    }
    std::string BindingName::title_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTitleBinding", nil));
    }
    std::string BindingName::tool_tip_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolTipBinding", nil));
    }
    std::string BindingName::transparent_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTransparentBinding", nil));
    }
    std::string BindingName::value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValueBinding", nil));
    }
    std::string BindingName::value_path_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValuePathBinding", nil));
    }
    std::string BindingName::value_url_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValueURLBinding", nil));
    }
    std::string BindingName::visible_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVisibleBinding", nil));
    }
    std::string BindingName::warning_value_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWarningValueBinding", nil));
    }
    std::string BindingName::width_binding()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWidthBinding", nil));
    }

    std::string BindingOption::allows_editing_multiple_values_selection_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAllowsEditingMultipleValuesSelectionBindingOption", nil));
    }
    std::string BindingOption::allows_null_argument_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAllowsNullArgumentBindingOption", nil));
    }
    std::string BindingOption::always_presents_application_modal_alerts_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAlwaysPresentsApplicationModalAlertsBindingOption", nil));
    }
    std::string BindingOption::conditionally_sets_editable_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSConditionallySetsEditableBindingOption", nil));
    }
    std::string BindingOption::conditionally_sets_enabled_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSConditionallySetsEnabledBindingOption", nil));
    }
    std::string BindingOption::conditionally_sets_hidden_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSConditionallySetsHiddenBindingOption", nil));
    }
    std::string BindingOption::continuously_updates_value_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContinuouslyUpdatesValueBindingOption", nil));
    }
    std::string BindingOption::creates_sort_descriptor_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCreatesSortDescriptorBindingOption", nil));
    }
    std::string BindingOption::deletes_objects_on_remove_bindings_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDeletesObjectsOnRemoveBindingsOption", nil));
    }
    std::string BindingOption::display_name_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDisplayNameBindingOption", nil));
    }
    std::string BindingOption::display_pattern_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDisplayPatternBindingOption", nil));
    }
    std::string BindingOption::content_placement_tag_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSContentPlacementTagBindingOption", nil));
    }
    std::string BindingOption::handles_content_as_compound_value_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHandlesContentAsCompoundValueBindingOption", nil));
    }
    std::string BindingOption::inserts_null_placeholder_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInsertsNullPlaceholderBindingOption", nil));
    }
    std::string BindingOption::invokes_separately_with_array_objects_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInvokesSeparatelyWithArrayObjectsBindingOption", nil));
    }
    std::string BindingOption::multiple_values_placeholder_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMultipleValuesPlaceholderBindingOption", nil));
    }
    std::string BindingOption::no_selection_placeholder_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNoSelectionPlaceholderBindingOption", nil));
    }
    std::string BindingOption::not_applicable_placeholder_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNotApplicablePlaceholderBindingOption", nil));
    }
    std::string BindingOption::null_placeholder_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNullPlaceholderBindingOption", nil));
    }
    std::string BindingOption::raises_for_not_applicable_keys_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRaisesForNotApplicableKeysBindingOption", nil));
    }
    std::string BindingOption::predicate_format_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPredicateFormatBindingOption", nil));
    }
    std::string BindingOption::selector_name_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectorNameBindingOption", nil));
    }
    std::string BindingOption::selects_all_when_setting_content_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSelectsAllWhenSettingContentBindingOption", nil));
    }
    std::string BindingOption::validates_immediately_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValidatesImmediatelyBindingOption", nil));
    }
    std::string BindingOption::value_transformer_name_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValueTransformerNameBindingOption", nil));
    }
    std::string BindingOption::value_transformer_binding_option()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSValueTransformerBindingOption", nil));
    }

    std::string UserInterfaceItemIdentifier::menu_item_import_from_device_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMenuItemImportFromDeviceIdentifier", nil));
    }
    std::string UserInterfaceItemIdentifier::outline_view_disclosure_button_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewDisclosureButtonKey", nil));
    }
    std::string UserInterfaceItemIdentifier::outline_view_show_hide_button_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOutlineViewShowHideButtonKey", nil));
    }
    std::string UserInterfaceItemIdentifier::table_view_row_view_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTableViewRowViewKey", nil));
    }

    std::string TextTabOptionKey::tab_column_terminators_attribute_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTabColumnTerminatorsAttributeName", nil));
    }

    std::string PasteboardType::string()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeString", nil));
    }
    std::string PasteboardType::pdf()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypePDF", nil));
    }
    std::string PasteboardType::tiff()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeTIFF", nil));
    }
    std::string PasteboardType::png()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypePNG", nil));
    }
    std::string PasteboardType::rtf()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeRTF", nil));
    }
    std::string PasteboardType::rtfd()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeRTFD", nil));
    }
    std::string PasteboardType::html()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeHTML", nil));
    }
    std::string PasteboardType::tabular_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeTabularText", nil));
    }
    std::string PasteboardType::font()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeFont", nil));
    }
    std::string PasteboardType::ruler()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeRuler", nil));
    }
    std::string PasteboardType::color()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeColor", nil));
    }
    std::string PasteboardType::sound()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeSound", nil));
    }
    std::string PasteboardType::multiple_text_selection()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeMultipleTextSelection", nil));
    }
    std::string PasteboardType::text_finder_options()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeTextFinderOptions", nil));
    }
    std::string PasteboardType::url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeURL", nil));
    }
    std::string PasteboardType::file_url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardTypeFileURL", nil));
    }
    std::string PasteboardType::file_contents_pboard_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileContentsPboardType", nil));
    }
    std::string PasteboardType::sound_pboard_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSoundPboardType", nil));
    }
    std::string PasteboardType::find_panel_search_options_pboard_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFindPanelSearchOptionsPboardType", nil));
    }

    std::string PasteboardName::general()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardNameGeneral", nil));
    }
    std::string PasteboardName::font()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardNameFont", nil));
    }
    std::string PasteboardName::ruler()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardNameRuler", nil));
    }
    std::string PasteboardName::find()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardNameFind", nil));
    }
    std::string PasteboardName::drag()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardNameDrag", nil));
    }

    std::string PasteboardDetectionPattern::probable_web_url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternProbableWebURL", nil));
    }
    std::string PasteboardDetectionPattern::probable_web_search()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternProbableWebSearch", nil));
    }
    std::string PasteboardDetectionPattern::number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternNumber", nil));
    }
    std::string PasteboardDetectionPattern::link()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternLink", nil));
    }
    std::string PasteboardDetectionPattern::phone_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternPhoneNumber", nil));
    }
    std::string PasteboardDetectionPattern::email_address()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternEmailAddress", nil));
    }
    std::string PasteboardDetectionPattern::postal_address()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternPostalAddress", nil));
    }
    std::string PasteboardDetectionPattern::calendar_event()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternCalendarEvent", nil));
    }
    std::string PasteboardDetectionPattern::shipment_tracking_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternShipmentTrackingNumber", nil));
    }
    std::string PasteboardDetectionPattern::flight_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternFlightNumber", nil));
    }
    std::string PasteboardDetectionPattern::money_amount()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardDetectionPatternMoneyAmount", nil));
    }

    std::string PasteboardMetadataType::content_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardMetadataTypeContentType", nil));
    }

    std::string PasteboardReadingOptionKey::pasteboard_url_reading_file_ur_ls_only_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardURLReadingFileURLsOnlyKey", nil));
    }
    std::string PasteboardReadingOptionKey::pasteboard_url_reading_contents_conform_to_types_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPasteboardURLReadingContentsConformToTypesKey", nil));
    }

    std::string PopoverCloseReasonValue::popover_close_reason_standard()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverCloseReasonStandard", nil));
    }
    std::string PopoverCloseReasonValue::popover_close_reason_detach_to_window()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPopoverCloseReasonDetachToWindow", nil));
    }

    std::string PrintInfoAttributeKey::print_paper_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPaperName", nil));
    }
    std::string PrintInfoAttributeKey::print_paper_size()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPaperSize", nil));
    }
    std::string PrintInfoAttributeKey::print_orientation()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintOrientation", nil));
    }
    std::string PrintInfoAttributeKey::print_scaling_factor()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintScalingFactor", nil));
    }
    std::string PrintInfoAttributeKey::print_left_margin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintLeftMargin", nil));
    }
    std::string PrintInfoAttributeKey::print_right_margin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintRightMargin", nil));
    }
    std::string PrintInfoAttributeKey::print_top_margin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintTopMargin", nil));
    }
    std::string PrintInfoAttributeKey::print_bottom_margin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintBottomMargin", nil));
    }
    std::string PrintInfoAttributeKey::print_horizontally_centered()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintHorizontallyCentered", nil));
    }
    std::string PrintInfoAttributeKey::print_vertically_centered()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintVerticallyCentered", nil));
    }
    std::string PrintInfoAttributeKey::print_horizontal_pagination()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintHorizontalPagination", nil));
    }
    std::string PrintInfoAttributeKey::print_vertical_pagination()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintVerticalPagination", nil));
    }
    std::string PrintInfoAttributeKey::print_printer()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPrinter", nil));
    }
    std::string PrintInfoAttributeKey::print_copies()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintCopies", nil));
    }
    std::string PrintInfoAttributeKey::print_all_pages()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintAllPages", nil));
    }
    std::string PrintInfoAttributeKey::print_first_page()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintFirstPage", nil));
    }
    std::string PrintInfoAttributeKey::print_last_page()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintLastPage", nil));
    }
    std::string PrintInfoAttributeKey::print_must_collate()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintMustCollate", nil));
    }
    std::string PrintInfoAttributeKey::print_reverse_page_order()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintReversePageOrder", nil));
    }
    std::string PrintInfoAttributeKey::print_job_disposition()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintJobDisposition", nil));
    }
    std::string PrintInfoAttributeKey::print_pages_across()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPagesAcross", nil));
    }
    std::string PrintInfoAttributeKey::print_pages_down()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPagesDown", nil));
    }
    std::string PrintInfoAttributeKey::print_time()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintTime", nil));
    }
    std::string PrintInfoAttributeKey::print_detailed_error_reporting()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintDetailedErrorReporting", nil));
    }
    std::string PrintInfoAttributeKey::print_fax_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintFaxNumber", nil));
    }
    std::string PrintInfoAttributeKey::print_printer_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPrinterName", nil));
    }
    std::string PrintInfoAttributeKey::print_selection_only()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintSelectionOnly", nil));
    }
    std::string PrintInfoAttributeKey::print_job_saving_url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintJobSavingURL", nil));
    }
    std::string PrintInfoAttributeKey::print_job_saving_file_name_extension_hidden()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintJobSavingFileNameExtensionHidden", nil));
    }
    std::string PrintInfoAttributeKey::print_header_and_footer()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintHeaderAndFooter", nil));
    }

    std::string PrintJobDispositionValue::print_spool_job()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintSpoolJob", nil));
    }
    std::string PrintJobDispositionValue::print_preview_job()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPreviewJob", nil));
    }
    std::string PrintJobDispositionValue::print_save_job()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintSaveJob", nil));
    }
    std::string PrintJobDispositionValue::print_cancel_job()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintCancelJob", nil));
    }

    std::string PrintPanelJobStyleHint::print_photo_job_style_hint()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPhotoJobStyleHint", nil));
    }
    std::string PrintPanelJobStyleHint::print_all_presets_job_style_hint()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintAllPresetsJobStyleHint", nil));
    }
    std::string PrintPanelJobStyleHint::print_no_presets_job_style_hint()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintNoPresetsJobStyleHint", nil));
    }

    std::string PrintPanelAccessorySummaryKey::print_panel_accessory_summary_item_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPanelAccessorySummaryItemNameKey", nil));
    }
    std::string PrintPanelAccessorySummaryKey::print_panel_accessory_summary_item_description_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPrintPanelAccessorySummaryItemDescriptionKey", nil));
    }

    std::string RuleEditorPredicatePartKey::rule_editor_predicate_left_expression()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateLeftExpression", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_right_expression()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateRightExpression", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_comparison_modifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateComparisonModifier", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_options()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateOptions", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_operator_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateOperatorType", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_custom_selector()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateCustomSelector", nil));
    }
    std::string RuleEditorPredicatePartKey::rule_editor_predicate_compound_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRuleEditorPredicateCompoundType", nil));
    }

    std::string RulerViewUnitName::ruler_view_unit_inches()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRulerViewUnitInches", nil));
    }
    std::string RulerViewUnitName::ruler_view_unit_centimeters()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRulerViewUnitCentimeters", nil));
    }
    std::string RulerViewUnitName::ruler_view_unit_points()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRulerViewUnitPoints", nil));
    }
    std::string RulerViewUnitName::ruler_view_unit_picas()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRulerViewUnitPicas", nil));
    }

    std::string SharingServiceName::compose_email()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameComposeEmail", nil));
    }
    std::string SharingServiceName::compose_message()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameComposeMessage", nil));
    }
    std::string SharingServiceName::send_via_air_drop()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameSendViaAirDrop", nil));
    }
    std::string SharingServiceName::add_to_safari_reading_list()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameAddToSafariReadingList", nil));
    }
    std::string SharingServiceName::add_to_i_photo()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameAddToIPhoto", nil));
    }
    std::string SharingServiceName::add_to_aperture()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameAddToAperture", nil));
    }
    std::string SharingServiceName::use_as_desktop_picture()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameUseAsDesktopPicture", nil));
    }
    std::string SharingServiceName::cloud_sharing()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSharingServiceNameCloudSharing", nil));
    }

    double SliderAccessoryWidth::default_()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSSliderAccessoryWidth>("NSSliderAccessoryWidthDefault", ::NSSliderAccessoryWidth()));
    }
    double SliderAccessoryWidth::wide()
    {
        return static_cast<double>(cocoon::internal::load_symbol<::NSSliderAccessoryWidth>("NSSliderAccessoryWidthWide", ::NSSliderAccessoryWidth()));
    }

    std::string VoiceAttributeKey::voice_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceName", nil));
    }
    std::string VoiceAttributeKey::voice_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceIdentifier", nil));
    }
    std::string VoiceAttributeKey::voice_age()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceAge", nil));
    }
    std::string VoiceAttributeKey::voice_gender()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceGender", nil));
    }
    std::string VoiceAttributeKey::voice_demo_text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceDemoText", nil));
    }
    std::string VoiceAttributeKey::voice_locale_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceLocaleIdentifier", nil));
    }
    std::string VoiceAttributeKey::voice_supported_characters()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceSupportedCharacters", nil));
    }
    std::string VoiceAttributeKey::voice_individually_spoken_characters()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceIndividuallySpokenCharacters", nil));
    }

    std::string SpeechDictionaryKey::speech_dictionary_locale_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryLocaleIdentifier", nil));
    }
    std::string SpeechDictionaryKey::speech_dictionary_modification_date()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryModificationDate", nil));
    }
    std::string SpeechDictionaryKey::speech_dictionary_pronunciations()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryPronunciations", nil));
    }
    std::string SpeechDictionaryKey::speech_dictionary_abbreviations()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryAbbreviations", nil));
    }
    std::string SpeechDictionaryKey::speech_dictionary_entry_spelling()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryEntrySpelling", nil));
    }
    std::string SpeechDictionaryKey::speech_dictionary_entry_phonemes()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechDictionaryEntryPhonemes", nil));
    }

    std::string VoiceGenderName::voice_gender_neuter()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceGenderNeuter", nil));
    }
    std::string VoiceGenderName::voice_gender_male()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceGenderMale", nil));
    }
    std::string VoiceGenderName::voice_gender_female()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceGenderFemale", nil));
    }
    std::string VoiceGenderName::voice_gender_neutral()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSVoiceGenderNeutral", nil));
    }

    std::string SpeechPropertyKey::speech_status_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechStatusProperty", nil));
    }
    std::string SpeechPropertyKey::speech_errors_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorsProperty", nil));
    }
    std::string SpeechPropertyKey::speech_input_mode_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechInputModeProperty", nil));
    }
    std::string SpeechPropertyKey::speech_character_mode_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechCharacterModeProperty", nil));
    }
    std::string SpeechPropertyKey::speech_number_mode_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechNumberModeProperty", nil));
    }
    std::string SpeechPropertyKey::speech_rate_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechRateProperty", nil));
    }
    std::string SpeechPropertyKey::speech_pitch_base_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPitchBaseProperty", nil));
    }
    std::string SpeechPropertyKey::speech_pitch_mod_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPitchModProperty", nil));
    }
    std::string SpeechPropertyKey::speech_volume_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechVolumeProperty", nil));
    }
    std::string SpeechPropertyKey::speech_synthesizer_info_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechSynthesizerInfoProperty", nil));
    }
    std::string SpeechPropertyKey::speech_recent_sync_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechRecentSyncProperty", nil));
    }
    std::string SpeechPropertyKey::speech_phoneme_symbols_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeSymbolsProperty", nil));
    }
    std::string SpeechPropertyKey::speech_current_voice_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechCurrentVoiceProperty", nil));
    }
    std::string SpeechPropertyKey::speech_command_delimiter_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechCommandDelimiterProperty", nil));
    }
    std::string SpeechPropertyKey::speech_reset_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechResetProperty", nil));
    }
    std::string SpeechPropertyKey::speech_output_to_file_url_property()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechOutputToFileURLProperty", nil));
    }

    std::string SpeechMode::text()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechModeText", nil));
    }
    std::string SpeechMode::phoneme()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechModePhoneme", nil));
    }
    std::string SpeechMode::normal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechModeNormal", nil));
    }
    std::string SpeechMode::literal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechModeLiteral", nil));
    }

    std::string SpeechStatusKey::speech_status_output_busy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechStatusOutputBusy", nil));
    }
    std::string SpeechStatusKey::speech_status_output_paused()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechStatusOutputPaused", nil));
    }
    std::string SpeechStatusKey::speech_status_number_of_characters_left()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechStatusNumberOfCharactersLeft", nil));
    }
    std::string SpeechStatusKey::speech_status_phoneme_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechStatusPhonemeCode", nil));
    }

    std::string SpeechErrorKey::speech_error_count()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorCount", nil));
    }
    std::string SpeechErrorKey::speech_error_oldest_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorOldestCode", nil));
    }
    std::string SpeechErrorKey::speech_error_oldest_character_offset()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorOldestCharacterOffset", nil));
    }
    std::string SpeechErrorKey::speech_error_newest_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorNewestCode", nil));
    }
    std::string SpeechErrorKey::speech_error_newest_character_offset()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechErrorNewestCharacterOffset", nil));
    }

    std::string SpeechSynthesizerInfoKey::speech_synthesizer_info_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechSynthesizerInfoIdentifier", nil));
    }
    std::string SpeechSynthesizerInfoKey::speech_synthesizer_info_version()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechSynthesizerInfoVersion", nil));
    }

    std::string SpeechPhonemeInfoKey::speech_phoneme_info_opcode()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeInfoOpcode", nil));
    }
    std::string SpeechPhonemeInfoKey::speech_phoneme_info_symbol()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeInfoSymbol", nil));
    }
    std::string SpeechPhonemeInfoKey::speech_phoneme_info_example()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeInfoExample", nil));
    }
    std::string SpeechPhonemeInfoKey::speech_phoneme_info_hilite_start()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeInfoHiliteStart", nil));
    }
    std::string SpeechPhonemeInfoKey::speech_phoneme_info_hilite_end()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechPhonemeInfoHiliteEnd", nil));
    }

    std::string SpeechCommandDelimiterKey::speech_command_prefix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechCommandPrefix", nil));
    }
    std::string SpeechCommandDelimiterKey::speech_command_suffix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSpeechCommandSuffix", nil));
    }

    std::string TextCheckingOptionKey::text_checking_orthography_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingOrthographyKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_quotes_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingQuotesKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_replacements_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingReplacementsKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_reference_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingReferenceDateKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_reference_time_zone_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingReferenceTimeZoneKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_document_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingDocumentURLKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_document_title_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingDocumentTitleKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_document_author_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingDocumentAuthorKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_regular_expressions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingRegularExpressionsKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_selected_range_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingSelectedRangeKey", nil));
    }
    std::string TextCheckingOptionKey::text_checking_generate_inline_predictions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingGenerateInlinePredictionsKey", nil));
    }

    std::string TextContentType::username()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeUsername", nil));
    }
    std::string TextContentType::password()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypePassword", nil));
    }
    std::string TextContentType::one_time_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeOneTimeCode", nil));
    }
    std::string TextContentType::new_password()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeNewPassword", nil));
    }
    std::string TextContentType::name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeName", nil));
    }
    std::string TextContentType::name_prefix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeNamePrefix", nil));
    }
    std::string TextContentType::given_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeGivenName", nil));
    }
    std::string TextContentType::middle_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeMiddleName", nil));
    }
    std::string TextContentType::family_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeFamilyName", nil));
    }
    std::string TextContentType::name_suffix()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeNameSuffix", nil));
    }
    std::string TextContentType::nickname()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeNickname", nil));
    }
    std::string TextContentType::job_title()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeJobTitle", nil));
    }
    std::string TextContentType::organization_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeOrganizationName", nil));
    }
    std::string TextContentType::location()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeLocation", nil));
    }
    std::string TextContentType::full_street_address()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeFullStreetAddress", nil));
    }
    std::string TextContentType::street_address_line1()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeStreetAddressLine1", nil));
    }
    std::string TextContentType::street_address_line2()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeStreetAddressLine2", nil));
    }
    std::string TextContentType::address_city()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeAddressCity", nil));
    }
    std::string TextContentType::address_state()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeAddressState", nil));
    }
    std::string TextContentType::address_city_and_state()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeAddressCityAndState", nil));
    }
    std::string TextContentType::sublocality()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeSublocality", nil));
    }
    std::string TextContentType::country_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCountryName", nil));
    }
    std::string TextContentType::postal_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypePostalCode", nil));
    }
    std::string TextContentType::telephone_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeTelephoneNumber", nil));
    }
    std::string TextContentType::email_address()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeEmailAddress", nil));
    }
    std::string TextContentType::url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeURL", nil));
    }
    std::string TextContentType::credit_card_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardNumber", nil));
    }
    std::string TextContentType::credit_card_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardName", nil));
    }
    std::string TextContentType::credit_card_given_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardGivenName", nil));
    }
    std::string TextContentType::credit_card_middle_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardMiddleName", nil));
    }
    std::string TextContentType::credit_card_family_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardFamilyName", nil));
    }
    std::string TextContentType::credit_card_security_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardSecurityCode", nil));
    }
    std::string TextContentType::credit_card_expiration()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardExpiration", nil));
    }
    std::string TextContentType::credit_card_expiration_month()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardExpirationMonth", nil));
    }
    std::string TextContentType::credit_card_expiration_year()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardExpirationYear", nil));
    }
    std::string TextContentType::credit_card_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeCreditCardType", nil));
    }
    std::string TextContentType::shipment_tracking_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeShipmentTrackingNumber", nil));
    }
    std::string TextContentType::flight_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeFlightNumber", nil));
    }
    std::string TextContentType::date_time()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeDateTime", nil));
    }
    std::string TextContentType::birthdate()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeBirthdate", nil));
    }
    std::string TextContentType::birthdate_day()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeBirthdateDay", nil));
    }
    std::string TextContentType::birthdate_month()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeBirthdateMonth", nil));
    }
    std::string TextContentType::birthdate_year()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextContentTypeBirthdateYear", nil));
    }

    std::string PasteboardTypeTextFinderOptionKey::text_finder_case_insensitive_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextFinderCaseInsensitiveKey", nil));
    }
    std::string PasteboardTypeTextFinderOptionKey::text_finder_matching_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextFinderMatchingTypeKey", nil));
    }

    std::string TextListMarkerFormat::text_list_marker_box()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerBox", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_check()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerCheck", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_circle()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerCircle", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_diamond()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerDiamond", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_disc()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerDisc", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_hyphen()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerHyphen", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_square()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerSquare", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_lowercase_hexadecimal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerLowercaseHexadecimal", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_uppercase_hexadecimal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerUppercaseHexadecimal", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_octal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerOctal", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_lowercase_alpha()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerLowercaseAlpha", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_uppercase_alpha()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerUppercaseAlpha", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_lowercase_latin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerLowercaseLatin", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_uppercase_latin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerUppercaseLatin", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_lowercase_roman()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerLowercaseRoman", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_uppercase_roman()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerUppercaseRoman", nil));
    }
    std::string TextListMarkerFormat::text_list_marker_decimal()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextListMarkerDecimal", nil));
    }

    std::string PasteboardTypeFindPanelSearchOptionKey::find_panel_case_insensitive_search()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFindPanelCaseInsensitiveSearch", nil));
    }
    std::string PasteboardTypeFindPanelSearchOptionKey::find_panel_substring_match()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFindPanelSubstringMatch", nil));
    }

    std::string ToolbarUserInfoKey::toolbar_item_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarItemKey", nil));
    }
    std::string ToolbarUserInfoKey::toolbar_new_index_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarNewIndexKey", nil));
    }

    std::string ToolbarItemIdentifier::toolbar_space_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarSpaceItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_flexible_space_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarFlexibleSpaceItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_show_colors_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarShowColorsItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_show_fonts_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarShowFontsItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_print_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarPrintItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_toggle_sidebar_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarToggleSidebarItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_toggle_inspector_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarToggleInspectorItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_cloud_sharing_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarCloudSharingItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_writing_tools_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarWritingToolsItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_sidebar_tracking_separator_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarSidebarTrackingSeparatorItemIdentifier", nil));
    }
    std::string ToolbarItemIdentifier::toolbar_inspector_tracking_separator_item_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSToolbarInspectorTrackingSeparatorItemIdentifier", nil));
    }

    std::string ViewFullScreenModeOptionKey::full_screen_mode_all_screens()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFullScreenModeAllScreens", nil));
    }
    std::string ViewFullScreenModeOptionKey::full_screen_mode_setting()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFullScreenModeSetting", nil));
    }
    std::string ViewFullScreenModeOptionKey::full_screen_mode_window_level()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFullScreenModeWindowLevel", nil));
    }
    std::string ViewFullScreenModeOptionKey::full_screen_mode_application_presentation_options()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFullScreenModeApplicationPresentationOptions", nil));
    }

    std::string DefinitionOptionKey::definition_presentation_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefinitionPresentationTypeKey", nil));
    }

    std::string DefinitionPresentationType::overlay()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefinitionPresentationTypeOverlay", nil));
    }
    std::string DefinitionPresentationType::dictionary_application()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDefinitionPresentationTypeDictionaryApplication", nil));
    }

    std::string WorkspaceDesktopImageOptionKey::workspace_desktop_image_scaling_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDesktopImageScalingKey", nil));
    }
    std::string WorkspaceDesktopImageOptionKey::workspace_desktop_image_allow_clipping_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDesktopImageAllowClippingKey", nil));
    }
    std::string WorkspaceDesktopImageOptionKey::workspace_desktop_image_fill_color_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSWorkspaceDesktopImageFillColorKey", nil));
    }

    std::string AttributedStringFormattingContextKey::inflection_concepts_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSInflectionConceptsKey", nil));
    }

    std::string CalendarIdentifier::gregorian()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierGregorian", nil));
    }
    std::string CalendarIdentifier::buddhist()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierBuddhist", nil));
    }
    std::string CalendarIdentifier::chinese()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierChinese", nil));
    }
    std::string CalendarIdentifier::coptic()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierCoptic", nil));
    }
    std::string CalendarIdentifier::ethiopic_amete_mihret()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierEthiopicAmeteMihret", nil));
    }
    std::string CalendarIdentifier::ethiopic_amete_alem()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierEthiopicAmeteAlem", nil));
    }
    std::string CalendarIdentifier::hebrew()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierHebrew", nil));
    }
    std::string CalendarIdentifier::iso8601()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierISO8601", nil));
    }
    std::string CalendarIdentifier::indian()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierIndian", nil));
    }
    std::string CalendarIdentifier::islamic()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierIslamic", nil));
    }
    std::string CalendarIdentifier::islamic_civil()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierIslamicCivil", nil));
    }
    std::string CalendarIdentifier::japanese()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierJapanese", nil));
    }
    std::string CalendarIdentifier::persian()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierPersian", nil));
    }
    std::string CalendarIdentifier::republic_of_china()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierRepublicOfChina", nil));
    }
    std::string CalendarIdentifier::islamic_tabular()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierIslamicTabular", nil));
    }
    std::string CalendarIdentifier::islamic_umm_al_qura()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierIslamicUmmAlQura", nil));
    }
    std::string CalendarIdentifier::bangla()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierBangla", nil));
    }
    std::string CalendarIdentifier::gujarati()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierGujarati", nil));
    }
    std::string CalendarIdentifier::kannada()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierKannada", nil));
    }
    std::string CalendarIdentifier::malayalam()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierMalayalam", nil));
    }
    std::string CalendarIdentifier::marathi()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierMarathi", nil));
    }
    std::string CalendarIdentifier::odia()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierOdia", nil));
    }
    std::string CalendarIdentifier::tamil()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierTamil", nil));
    }
    std::string CalendarIdentifier::telugu()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierTelugu", nil));
    }
    std::string CalendarIdentifier::vikram()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierVikram", nil));
    }
    std::string CalendarIdentifier::dangi()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierDangi", nil));
    }
    std::string CalendarIdentifier::vietnamese()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCalendarIdentifierVietnamese", nil));
    }

    std::string DistributedNotificationCenterType::local_notification_center_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalNotificationCenterType", nil));
    }

    std::string ErrorDomain::cocoa_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCocoaErrorDomain", nil));
    }
    std::string ErrorDomain::posix_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSPOSIXErrorDomain", nil));
    }
    std::string ErrorDomain::os_status_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSOSStatusErrorDomain", nil));
    }
    std::string ErrorDomain::mach_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMachErrorDomain", nil));
    }
    std::string ErrorDomain::net_services_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNetServicesErrorDomain", nil));
    }
    std::string ErrorDomain::stream_socket_ssl_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSSLErrorDomain", nil));
    }
    std::string ErrorDomain::stream_socks_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSErrorDomain", nil));
    }
    std::string ErrorDomain::url_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorDomain", nil));
    }
    std::string ErrorDomain::xml_parser_error_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSXMLParserErrorDomain", nil));
    }

    std::string ErrorUserInfoKey::underlying_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnderlyingErrorKey", nil));
    }
    std::string ErrorUserInfoKey::multiple_underlying_errors_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMultipleUnderlyingErrorsKey", nil));
    }
    std::string ErrorUserInfoKey::localized_description_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedDescriptionKey", nil));
    }
    std::string ErrorUserInfoKey::localized_failure_reason_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedFailureReasonErrorKey", nil));
    }
    std::string ErrorUserInfoKey::localized_recovery_suggestion_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedRecoverySuggestionErrorKey", nil));
    }
    std::string ErrorUserInfoKey::localized_recovery_options_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedRecoveryOptionsErrorKey", nil));
    }
    std::string ErrorUserInfoKey::recovery_attempter_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSRecoveryAttempterErrorKey", nil));
    }
    std::string ErrorUserInfoKey::help_anchor_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHelpAnchorErrorKey", nil));
    }
    std::string ErrorUserInfoKey::debug_description_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDebugDescriptionErrorKey", nil));
    }
    std::string ErrorUserInfoKey::localized_failure_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocalizedFailureErrorKey", nil));
    }
    std::string ErrorUserInfoKey::string_encoding_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingErrorKey", nil));
    }
    std::string ErrorUserInfoKey::url_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorKey", nil));
    }
    std::string ErrorUserInfoKey::file_path_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFilePathErrorKey", nil));
    }
    std::string ErrorUserInfoKey::url_error_network_unavailable_reason_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLErrorNetworkUnavailableReasonKey", nil));
    }

    std::string FileAttributeKey::file_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileType", nil));
    }
    std::string FileAttributeKey::file_size()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSize", nil));
    }
    std::string FileAttributeKey::file_modification_date()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileModificationDate", nil));
    }
    std::string FileAttributeKey::file_reference_count()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileReferenceCount", nil));
    }
    std::string FileAttributeKey::file_device_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileDeviceIdentifier", nil));
    }
    std::string FileAttributeKey::file_owner_account_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileOwnerAccountName", nil));
    }
    std::string FileAttributeKey::file_group_owner_account_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileGroupOwnerAccountName", nil));
    }
    std::string FileAttributeKey::file_posix_permissions()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFilePosixPermissions", nil));
    }
    std::string FileAttributeKey::file_system_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemNumber", nil));
    }
    std::string FileAttributeKey::file_system_file_number()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemFileNumber", nil));
    }
    std::string FileAttributeKey::file_extension_hidden()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileExtensionHidden", nil));
    }
    std::string FileAttributeKey::file_hfs_creator_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHFSCreatorCode", nil));
    }
    std::string FileAttributeKey::file_hfs_type_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileHFSTypeCode", nil));
    }
    std::string FileAttributeKey::file_immutable()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileImmutable", nil));
    }
    std::string FileAttributeKey::file_append_only()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileAppendOnly", nil));
    }
    std::string FileAttributeKey::file_creation_date()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileCreationDate", nil));
    }
    std::string FileAttributeKey::file_owner_account_id()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileOwnerAccountID", nil));
    }
    std::string FileAttributeKey::file_group_owner_account_id()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileGroupOwnerAccountID", nil));
    }
    std::string FileAttributeKey::file_busy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileBusy", nil));
    }
    std::string FileAttributeKey::file_protection_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileProtectionKey", nil));
    }
    std::string FileAttributeKey::file_system_size()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemSize", nil));
    }
    std::string FileAttributeKey::file_system_free_size()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemFreeSize", nil));
    }
    std::string FileAttributeKey::file_system_nodes()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemNodes", nil));
    }
    std::string FileAttributeKey::file_system_free_nodes()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileSystemFreeNodes", nil));
    }

    std::string FileAttributeType::file_type_directory()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeDirectory", nil));
    }
    std::string FileAttributeType::file_type_regular()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeRegular", nil));
    }
    std::string FileAttributeType::file_type_symbolic_link()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeSymbolicLink", nil));
    }
    std::string FileAttributeType::file_type_socket()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeSocket", nil));
    }
    std::string FileAttributeType::file_type_character_special()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeCharacterSpecial", nil));
    }
    std::string FileAttributeType::file_type_block_special()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeBlockSpecial", nil));
    }
    std::string FileAttributeType::file_type_unknown()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileTypeUnknown", nil));
    }

    std::string FileProtectionType::file_protection_none()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileProtectionNone", nil));
    }
    std::string FileProtectionType::file_protection_complete()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileProtectionComplete", nil));
    }
    std::string FileProtectionType::file_protection_complete_unless_open()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileProtectionCompleteUnlessOpen", nil));
    }
    std::string FileProtectionType::file_protection_complete_until_first_user_authentication()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSFileProtectionCompleteUntilFirstUserAuthentication", nil));
    }

    std::string HTTPCookiePropertyKey::http_cookie_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieName", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_value()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieValue", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_origin_url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieOriginURL", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_version()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieVersion", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_domain()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieDomain", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_path()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookiePath", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_secure()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieSecure", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_expires()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieExpires", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_comment()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieComment", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_comment_url()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieCommentURL", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_discard()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieDiscard", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_maximum_age()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieMaximumAge", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_port()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookiePort", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_set_by_java_script()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieSetByJavaScript", nil));
    }
    std::string HTTPCookiePropertyKey::http_cookie_same_site_policy()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieSameSitePolicy", nil));
    }

    std::string HTTPCookieStringPolicy::http_cookie_same_site_lax()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieSameSiteLax", nil));
    }
    std::string HTTPCookieStringPolicy::http_cookie_same_site_strict()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSHTTPCookieSameSiteStrict", nil));
    }

    std::string KeyValueOperator::average_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSAverageKeyValueOperator", nil));
    }
    std::string KeyValueOperator::count_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSCountKeyValueOperator", nil));
    }
    std::string KeyValueOperator::distinct_union_of_arrays_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDistinctUnionOfArraysKeyValueOperator", nil));
    }
    std::string KeyValueOperator::distinct_union_of_objects_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDistinctUnionOfObjectsKeyValueOperator", nil));
    }
    std::string KeyValueOperator::distinct_union_of_sets_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSDistinctUnionOfSetsKeyValueOperator", nil));
    }
    std::string KeyValueOperator::maximum_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMaximumKeyValueOperator", nil));
    }
    std::string KeyValueOperator::minimum_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSMinimumKeyValueOperator", nil));
    }
    std::string KeyValueOperator::sum_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSumKeyValueOperator", nil));
    }
    std::string KeyValueOperator::union_of_arrays_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnionOfArraysKeyValueOperator", nil));
    }
    std::string KeyValueOperator::union_of_objects_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnionOfObjectsKeyValueOperator", nil));
    }
    std::string KeyValueOperator::union_of_sets_key_value_operator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSUnionOfSetsKeyValueOperator", nil));
    }

    std::string KeyValueChangeKey::key_value_change_kind_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyValueChangeKindKey", nil));
    }
    std::string KeyValueChangeKey::key_value_change_new_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyValueChangeNewKey", nil));
    }
    std::string KeyValueChangeKey::key_value_change_old_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyValueChangeOldKey", nil));
    }
    std::string KeyValueChangeKey::key_value_change_indexes_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyValueChangeIndexesKey", nil));
    }
    std::string KeyValueChangeKey::key_value_change_notification_is_prior_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSKeyValueChangeNotificationIsPriorKey", nil));
    }

    std::string LocaleKey::locale_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleIdentifier", nil));
    }
    std::string LocaleKey::locale_language_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleLanguageCode", nil));
    }
    std::string LocaleKey::locale_country_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCountryCode", nil));
    }
    std::string LocaleKey::locale_script_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleScriptCode", nil));
    }
    std::string LocaleKey::locale_variant_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleVariantCode", nil));
    }
    std::string LocaleKey::locale_exemplar_character_set()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleExemplarCharacterSet", nil));
    }
    std::string LocaleKey::locale_calendar()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCalendar", nil));
    }
    std::string LocaleKey::locale_collation_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCollationIdentifier", nil));
    }
    std::string LocaleKey::locale_uses_metric_system()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleUsesMetricSystem", nil));
    }
    std::string LocaleKey::locale_measurement_system()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleMeasurementSystem", nil));
    }
    std::string LocaleKey::locale_decimal_separator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleDecimalSeparator", nil));
    }
    std::string LocaleKey::locale_grouping_separator()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleGroupingSeparator", nil));
    }
    std::string LocaleKey::locale_currency_symbol()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCurrencySymbol", nil));
    }
    std::string LocaleKey::locale_currency_code()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCurrencyCode", nil));
    }
    std::string LocaleKey::locale_collator_identifier()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleCollatorIdentifier", nil));
    }
    std::string LocaleKey::locale_quotation_begin_delimiter_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleQuotationBeginDelimiterKey", nil));
    }
    std::string LocaleKey::locale_quotation_end_delimiter_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleQuotationEndDelimiterKey", nil));
    }
    std::string LocaleKey::locale_alternate_quotation_begin_delimiter_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleAlternateQuotationBeginDelimiterKey", nil));
    }
    std::string LocaleKey::locale_alternate_quotation_end_delimiter_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSLocaleAlternateQuotationEndDelimiterKey", nil));
    }

    std::string ProgressUserInfoKey::progress_estimated_time_remaining_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressEstimatedTimeRemainingKey", nil));
    }
    std::string ProgressUserInfoKey::progress_throughput_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressThroughputKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_operation_kind_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileURLKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_total_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileTotalCountKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_completed_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileCompletedCountKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_animation_image_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileAnimationImageKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_animation_image_original_rect_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileAnimationImageOriginalRectKey", nil));
    }
    std::string ProgressUserInfoKey::progress_file_icon_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileIconKey", nil));
    }

    std::string ProgressKind::file()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressKindFile", nil));
    }

    std::string ProgressFileOperationKind::downloading()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindDownloading", nil));
    }
    std::string ProgressFileOperationKind::decompressing_after_downloading()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindDecompressingAfterDownloading", nil));
    }
    std::string ProgressFileOperationKind::receiving()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindReceiving", nil));
    }
    std::string ProgressFileOperationKind::copying()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindCopying", nil));
    }
    std::string ProgressFileOperationKind::uploading()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindUploading", nil));
    }
    std::string ProgressFileOperationKind::duplicating()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSProgressFileOperationKindDuplicating", nil));
    }

    std::string StreamPropertyKey::stream_socket_security_level_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelKey", nil));
    }
    std::string StreamPropertyKey::stream_socks_proxy_configuration_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyConfigurationKey", nil));
    }
    std::string StreamPropertyKey::stream_data_written_to_memory_stream_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamDataWrittenToMemoryStreamKey", nil));
    }
    std::string StreamPropertyKey::stream_file_current_offset_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamFileCurrentOffsetKey", nil));
    }
    std::string StreamPropertyKey::stream_network_service_type()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceType", nil));
    }

    std::string StreamSocketSecurityLevel::none()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelNone", nil));
    }
    std::string StreamSocketSecurityLevel::ss_lv2()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelSSLv2", nil));
    }
    std::string StreamSocketSecurityLevel::ss_lv3()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelSSLv3", nil));
    }
    std::string StreamSocketSecurityLevel::tl_sv1()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelTLSv1", nil));
    }
    std::string StreamSocketSecurityLevel::negotiated_ssl()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSocketSecurityLevelNegotiatedSSL", nil));
    }

    std::string StreamSOCKSProxyConfiguration::stream_socks_proxy_host_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyHostKey", nil));
    }
    std::string StreamSOCKSProxyConfiguration::stream_socks_proxy_port_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyPortKey", nil));
    }
    std::string StreamSOCKSProxyConfiguration::stream_socks_proxy_version_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyVersionKey", nil));
    }
    std::string StreamSOCKSProxyConfiguration::stream_socks_proxy_user_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyUserKey", nil));
    }
    std::string StreamSOCKSProxyConfiguration::stream_socks_proxy_password_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyPasswordKey", nil));
    }

    std::string StreamSOCKSProxyVersion::n4()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyVersion4", nil));
    }
    std::string StreamSOCKSProxyVersion::n5()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamSOCKSProxyVersion5", nil));
    }

    std::string StreamNetworkServiceTypeValue::stream_network_service_type_vo_ip()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceTypeVoIP", nil));
    }
    std::string StreamNetworkServiceTypeValue::stream_network_service_type_video()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceTypeVideo", nil));
    }
    std::string StreamNetworkServiceTypeValue::stream_network_service_type_background()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceTypeBackground", nil));
    }
    std::string StreamNetworkServiceTypeValue::stream_network_service_type_voice()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceTypeVoice", nil));
    }
    std::string StreamNetworkServiceTypeValue::stream_network_service_type_call_signaling()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStreamNetworkServiceTypeCallSignaling", nil));
    }

    std::string StringTransform::latin_to_katakana()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToKatakana", nil));
    }
    std::string StringTransform::latin_to_hiragana()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToHiragana", nil));
    }
    std::string StringTransform::latin_to_hangul()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToHangul", nil));
    }
    std::string StringTransform::latin_to_arabic()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToArabic", nil));
    }
    std::string StringTransform::latin_to_hebrew()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToHebrew", nil));
    }
    std::string StringTransform::latin_to_thai()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToThai", nil));
    }
    std::string StringTransform::latin_to_cyrillic()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToCyrillic", nil));
    }
    std::string StringTransform::latin_to_greek()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformLatinToGreek", nil));
    }
    std::string StringTransform::to_latin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformToLatin", nil));
    }
    std::string StringTransform::mandarin_to_latin()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformMandarinToLatin", nil));
    }
    std::string StringTransform::hiragana_to_katakana()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformHiraganaToKatakana", nil));
    }
    std::string StringTransform::fullwidth_to_halfwidth()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformFullwidthToHalfwidth", nil));
    }
    std::string StringTransform::to_xml_hex()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformToXMLHex", nil));
    }
    std::string StringTransform::to_unicode_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformToUnicodeName", nil));
    }
    std::string StringTransform::strip_combining_marks()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformStripCombiningMarks", nil));
    }
    std::string StringTransform::strip_diacritics()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringTransformStripDiacritics", nil));
    }

    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_suggested_encodings_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionSuggestedEncodingsKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_disallowed_encodings_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionDisallowedEncodingsKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_use_only_suggested_encodings_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionUseOnlySuggestedEncodingsKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_allow_lossy_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionAllowLossyKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_from_windows_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionFromWindowsKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_lossy_substitution_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionLossySubstitutionKey", nil));
    }
    std::string StringEncodingDetectionOptionsKey::string_encoding_detection_likely_language_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSStringEncodingDetectionLikelyLanguageKey", nil));
    }

    std::string TextCheckingKey::text_checking_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingNameKey", nil));
    }
    std::string TextCheckingKey::text_checking_job_title_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingJobTitleKey", nil));
    }
    std::string TextCheckingKey::text_checking_organization_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingOrganizationKey", nil));
    }
    std::string TextCheckingKey::text_checking_street_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingStreetKey", nil));
    }
    std::string TextCheckingKey::text_checking_city_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingCityKey", nil));
    }
    std::string TextCheckingKey::text_checking_state_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingStateKey", nil));
    }
    std::string TextCheckingKey::text_checking_zip_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingZIPKey", nil));
    }
    std::string TextCheckingKey::text_checking_country_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingCountryKey", nil));
    }
    std::string TextCheckingKey::text_checking_phone_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingPhoneKey", nil));
    }
    std::string TextCheckingKey::text_checking_airline_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingAirlineKey", nil));
    }
    std::string TextCheckingKey::text_checking_flight_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSTextCheckingFlightKey", nil));
    }

    std::string URLResourceKey::url_keys_of_unset_values_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLKeysOfUnsetValuesKey", nil));
    }
    std::string URLResourceKey::url_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLNameKey", nil));
    }
    std::string URLResourceKey::url_localized_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLocalizedNameKey", nil));
    }
    std::string URLResourceKey::url_is_regular_file_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsRegularFileKey", nil));
    }
    std::string URLResourceKey::url_is_directory_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsDirectoryKey", nil));
    }
    std::string URLResourceKey::url_is_symbolic_link_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsSymbolicLinkKey", nil));
    }
    std::string URLResourceKey::url_is_volume_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsVolumeKey", nil));
    }
    std::string URLResourceKey::url_is_package_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsPackageKey", nil));
    }
    std::string URLResourceKey::url_is_application_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsApplicationKey", nil));
    }
    std::string URLResourceKey::url_application_is_scriptable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLApplicationIsScriptableKey", nil));
    }
    std::string URLResourceKey::url_is_system_immutable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsSystemImmutableKey", nil));
    }
    std::string URLResourceKey::url_is_user_immutable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsUserImmutableKey", nil));
    }
    std::string URLResourceKey::url_is_hidden_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsHiddenKey", nil));
    }
    std::string URLResourceKey::url_has_hidden_extension_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLHasHiddenExtensionKey", nil));
    }
    std::string URLResourceKey::url_creation_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLCreationDateKey", nil));
    }
    std::string URLResourceKey::url_content_access_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLContentAccessDateKey", nil));
    }
    std::string URLResourceKey::url_content_modification_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLContentModificationDateKey", nil));
    }
    std::string URLResourceKey::url_attribute_modification_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAttributeModificationDateKey", nil));
    }
    std::string URLResourceKey::url_link_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLinkCountKey", nil));
    }
    std::string URLResourceKey::url_parent_directory_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLParentDirectoryURLKey", nil));
    }
    std::string URLResourceKey::url_volume_url_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeURLKey", nil));
    }
    std::string URLResourceKey::url_content_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLContentTypeKey", nil));
    }
    std::string URLResourceKey::url_localized_type_description_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLocalizedTypeDescriptionKey", nil));
    }
    std::string URLResourceKey::url_label_number_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLabelNumberKey", nil));
    }
    std::string URLResourceKey::url_label_color_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLabelColorKey", nil));
    }
    std::string URLResourceKey::url_localized_label_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLLocalizedLabelKey", nil));
    }
    std::string URLResourceKey::url_effective_icon_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLEffectiveIconKey", nil));
    }
    std::string URLResourceKey::url_custom_icon_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLCustomIconKey", nil));
    }
    std::string URLResourceKey::url_file_resource_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceIdentifierKey", nil));
    }
    std::string URLResourceKey::url_volume_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIdentifierKey", nil));
    }
    std::string URLResourceKey::url_preferred_io_block_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLPreferredIOBlockSizeKey", nil));
    }
    std::string URLResourceKey::url_is_readable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsReadableKey", nil));
    }
    std::string URLResourceKey::url_is_writable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsWritableKey", nil));
    }
    std::string URLResourceKey::url_is_executable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsExecutableKey", nil));
    }
    std::string URLResourceKey::url_file_security_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileSecurityKey", nil));
    }
    std::string URLResourceKey::url_is_excluded_from_backup_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsExcludedFromBackupKey", nil));
    }
    std::string URLResourceKey::url_tag_names_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLTagNamesKey", nil));
    }
    std::string URLResourceKey::url_path_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLPathKey", nil));
    }
    std::string URLResourceKey::url_canonical_path_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLCanonicalPathKey", nil));
    }
    std::string URLResourceKey::url_is_mount_trigger_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsMountTriggerKey", nil));
    }
    std::string URLResourceKey::url_generation_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLGenerationIdentifierKey", nil));
    }
    std::string URLResourceKey::url_document_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLDocumentIdentifierKey", nil));
    }
    std::string URLResourceKey::url_added_to_directory_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLAddedToDirectoryDateKey", nil));
    }
    std::string URLResourceKey::url_quarantine_properties_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLQuarantinePropertiesKey", nil));
    }
    std::string URLResourceKey::url_file_resource_type_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeKey", nil));
    }
    std::string URLResourceKey::url_file_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileIdentifierKey", nil));
    }
    std::string URLResourceKey::url_file_content_identifier_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileContentIdentifierKey", nil));
    }
    std::string URLResourceKey::url_may_share_file_content_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLMayShareFileContentKey", nil));
    }
    std::string URLResourceKey::url_may_have_extended_attributes_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLMayHaveExtendedAttributesKey", nil));
    }
    std::string URLResourceKey::url_is_purgeable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsPurgeableKey", nil));
    }
    std::string URLResourceKey::url_is_sparse_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsSparseKey", nil));
    }
    std::string URLResourceKey::url_file_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileSizeKey", nil));
    }
    std::string URLResourceKey::url_file_allocated_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileAllocatedSizeKey", nil));
    }
    std::string URLResourceKey::url_total_file_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLTotalFileSizeKey", nil));
    }
    std::string URLResourceKey::url_total_file_allocated_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLTotalFileAllocatedSizeKey", nil));
    }
    std::string URLResourceKey::url_is_alias_file_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsAliasFileKey", nil));
    }
    std::string URLResourceKey::url_file_protection_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileProtectionKey", nil));
    }
    std::string URLResourceKey::url_directory_entry_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLDirectoryEntryCountKey", nil));
    }
    std::string URLResourceKey::url_volume_localized_format_description_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeLocalizedFormatDescriptionKey", nil));
    }
    std::string URLResourceKey::url_volume_total_capacity_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeTotalCapacityKey", nil));
    }
    std::string URLResourceKey::url_volume_available_capacity_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeAvailableCapacityKey", nil));
    }
    std::string URLResourceKey::url_volume_resource_count_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeResourceCountKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_persistent_i_ds_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsPersistentIDsKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_symbolic_links_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsSymbolicLinksKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_hard_links_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsHardLinksKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_journaling_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsJournalingKey", nil));
    }
    std::string URLResourceKey::url_volume_is_journaling_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsJournalingKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_sparse_files_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsSparseFilesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_zero_runs_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsZeroRunsKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_case_sensitive_names_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsCaseSensitiveNamesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_case_preserved_names_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsCasePreservedNamesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_root_directory_dates_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsRootDirectoryDatesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_volume_sizes_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsVolumeSizesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_renaming_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsRenamingKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_advisory_file_locking_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsAdvisoryFileLockingKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_extended_security_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsExtendedSecurityKey", nil));
    }
    std::string URLResourceKey::url_volume_is_browsable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsBrowsableKey", nil));
    }
    std::string URLResourceKey::url_volume_maximum_file_size_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeMaximumFileSizeKey", nil));
    }
    std::string URLResourceKey::url_volume_is_ejectable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsEjectableKey", nil));
    }
    std::string URLResourceKey::url_volume_is_removable_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsRemovableKey", nil));
    }
    std::string URLResourceKey::url_volume_is_internal_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsInternalKey", nil));
    }
    std::string URLResourceKey::url_volume_is_automounted_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsAutomountedKey", nil));
    }
    std::string URLResourceKey::url_volume_is_local_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsLocalKey", nil));
    }
    std::string URLResourceKey::url_volume_is_read_only_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsReadOnlyKey", nil));
    }
    std::string URLResourceKey::url_volume_creation_date_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeCreationDateKey", nil));
    }
    std::string URLResourceKey::url_volume_url_for_remounting_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeURLForRemountingKey", nil));
    }
    std::string URLResourceKey::url_volume_uuid_string_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeUUIDStringKey", nil));
    }
    std::string URLResourceKey::url_volume_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeNameKey", nil));
    }
    std::string URLResourceKey::url_volume_localized_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeLocalizedNameKey", nil));
    }
    std::string URLResourceKey::url_volume_is_encrypted_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsEncryptedKey", nil));
    }
    std::string URLResourceKey::url_volume_is_root_file_system_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeIsRootFileSystemKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_compression_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsCompressionKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_file_cloning_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsFileCloningKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_swap_renaming_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsSwapRenamingKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_exclusive_renaming_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsExclusiveRenamingKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_immutable_files_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsImmutableFilesKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_access_permissions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsAccessPermissionsKey", nil));
    }
    std::string URLResourceKey::url_volume_supports_file_protection_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSupportsFileProtectionKey", nil));
    }
    std::string URLResourceKey::url_volume_available_capacity_for_important_usage_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeAvailableCapacityForImportantUsageKey", nil));
    }
    std::string URLResourceKey::url_volume_available_capacity_for_opportunistic_usage_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeAvailableCapacityForOpportunisticUsageKey", nil));
    }
    std::string URLResourceKey::url_volume_type_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeTypeNameKey", nil));
    }
    std::string URLResourceKey::url_volume_subtype_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeSubtypeKey", nil));
    }
    std::string URLResourceKey::url_volume_mount_from_location_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLVolumeMountFromLocationKey", nil));
    }
    std::string URLResourceKey::url_is_ubiquitous_item_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLIsUbiquitousItemKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_has_unresolved_conflicts_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemHasUnresolvedConflictsKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_downloading_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsDownloadingKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_uploaded_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsUploadedKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_uploading_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsUploadingKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_downloading_status_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadingStatusKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_downloading_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadingErrorKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_uploading_error_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemUploadingErrorKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_download_requested_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadRequestedKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_container_display_name_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemContainerDisplayNameKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_excluded_from_sync_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsExcludedFromSyncKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_shared_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsSharedKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_shared_item_current_user_role_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemCurrentUserRoleKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_shared_item_current_user_permissions_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemCurrentUserPermissionsKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_shared_item_owner_name_components_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemOwnerNameComponentsKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_shared_item_most_recent_editor_name_components_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemMostRecentEditorNameComponentsKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_supported_sync_controls_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemSupportedSyncControlsKey", nil));
    }
    std::string URLResourceKey::url_ubiquitous_item_is_sync_paused_key()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemIsSyncPausedKey", nil));
    }

    std::string URLFileResourceType::named_pipe()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeNamedPipe", nil));
    }
    std::string URLFileResourceType::character_special()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeCharacterSpecial", nil));
    }
    std::string URLFileResourceType::directory()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeDirectory", nil));
    }
    std::string URLFileResourceType::block_special()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeBlockSpecial", nil));
    }
    std::string URLFileResourceType::regular()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeRegular", nil));
    }
    std::string URLFileResourceType::symbolic_link()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeSymbolicLink", nil));
    }
    std::string URLFileResourceType::socket()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeSocket", nil));
    }
    std::string URLFileResourceType::unknown()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileResourceTypeUnknown", nil));
    }

    std::string URLFileProtectionType::url_file_protection_none()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileProtectionNone", nil));
    }
    std::string URLFileProtectionType::url_file_protection_complete()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileProtectionComplete", nil));
    }
    std::string URLFileProtectionType::url_file_protection_complete_unless_open()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileProtectionCompleteUnlessOpen", nil));
    }
    std::string URLFileProtectionType::url_file_protection_complete_until_first_user_authentication()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLFileProtectionCompleteUntilFirstUserAuthentication", nil));
    }

    std::string URLUbiquitousItemDownloadingStatus::not_downloaded()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadingStatusNotDownloaded", nil));
    }
    std::string URLUbiquitousItemDownloadingStatus::downloaded()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadingStatusDownloaded", nil));
    }
    std::string URLUbiquitousItemDownloadingStatus::current()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousItemDownloadingStatusCurrent", nil));
    }

    std::string URLUbiquitousSharedItemRole::owner()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemRoleOwner", nil));
    }
    std::string URLUbiquitousSharedItemRole::participant()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemRoleParticipant", nil));
    }

    std::string URLUbiquitousSharedItemPermissions::read_only()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemPermissionsReadOnly", nil));
    }
    std::string URLUbiquitousSharedItemPermissions::read_write()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSURLUbiquitousSharedItemPermissionsReadWrite", nil));
    }

    std::string ValueTransformerName::negate_boolean_transformer_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSNegateBooleanTransformerName", nil));
    }
    std::string ValueTransformerName::is_nil_transformer_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSIsNilTransformerName", nil));
    }
    std::string ValueTransformerName::is_not_nil_transformer_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSIsNotNilTransformerName", nil));
    }
    std::string ValueTransformerName::secure_unarchive_from_data_transformer_name()
    {
        return cocoon::internal::from(cocoon::internal::load_symbol<NSString*>("NSSecureUnarchiveFromDataTransformerName", nil));
    }
}
