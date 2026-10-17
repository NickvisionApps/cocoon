#pragma once

#include <cstdint>
#include <string>

namespace cocoon
{
    /** @brief Named constants of type `NSNotificationName`; each function reads the SDK symbol at runtime. */
    struct NotificationName
    {
        /// @brief Value of the SDK constant `NSWorkspaceAccessibilityDisplayOptionsDidChangeNotification`.
        static std::string workspace_accessibility_display_options_did_change_notification();
        /// @brief Value of the SDK constant `NSAnimationProgressMarkNotification`.
        static std::string animation_progress_mark_notification();
        /// @brief Value of the SDK constant `NSApplicationDidBecomeActiveNotification`.
        static std::string application_did_become_active_notification();
        /// @brief Value of the SDK constant `NSApplicationDidHideNotification`.
        static std::string application_did_hide_notification();
        /// @brief Value of the SDK constant `NSApplicationDidFinishLaunchingNotification`.
        static std::string application_did_finish_launching_notification();
        /// @brief Value of the SDK constant `NSApplicationDidResignActiveNotification`.
        static std::string application_did_resign_active_notification();
        /// @brief Value of the SDK constant `NSApplicationDidUnhideNotification`.
        static std::string application_did_unhide_notification();
        /// @brief Value of the SDK constant `NSApplicationDidUpdateNotification`.
        static std::string application_did_update_notification();
        /// @brief Value of the SDK constant `NSApplicationWillBecomeActiveNotification`.
        static std::string application_will_become_active_notification();
        /// @brief Value of the SDK constant `NSApplicationWillHideNotification`.
        static std::string application_will_hide_notification();
        /// @brief Value of the SDK constant `NSApplicationWillFinishLaunchingNotification`.
        static std::string application_will_finish_launching_notification();
        /// @brief Value of the SDK constant `NSApplicationWillResignActiveNotification`.
        static std::string application_will_resign_active_notification();
        /// @brief Value of the SDK constant `NSApplicationWillUnhideNotification`.
        static std::string application_will_unhide_notification();
        /// @brief Value of the SDK constant `NSApplicationWillUpdateNotification`.
        static std::string application_will_update_notification();
        /// @brief Value of the SDK constant `NSApplicationWillTerminateNotification`.
        static std::string application_will_terminate_notification();
        /// @brief Value of the SDK constant `NSApplicationDidChangeScreenParametersNotification`.
        static std::string application_did_change_screen_parameters_notification();
        /// @brief Value of the SDK constant `NSApplicationProtectedDataWillBecomeUnavailableNotification`.
        static std::string application_protected_data_will_become_unavailable_notification();
        /// @brief Value of the SDK constant `NSApplicationProtectedDataDidBecomeAvailableNotification`.
        static std::string application_protected_data_did_become_available_notification();
        /// @brief Value of the SDK constant `NSApplicationShouldBeginSuppressingHighDynamicRangeContentNotification`.
        static std::string application_should_begin_suppressing_high_dynamic_range_content_notification();
        /// @brief Value of the SDK constant `NSApplicationShouldEndSuppressingHighDynamicRangeContentNotification`.
        static std::string application_should_end_suppressing_high_dynamic_range_content_notification();
        /// @brief Value of the SDK constant `NSApplicationDidChangeOcclusionStateNotification`.
        static std::string application_did_change_occlusion_state_notification();
        /// @brief Value of the SDK constant `NSBrowserColumnConfigurationDidChangeNotification`.
        static std::string browser_column_configuration_did_change_notification();
        /// @brief Value of the SDK constant `NSSystemColorsDidChangeNotification`.
        static std::string system_colors_did_change_notification();
        /// @brief Value of the SDK constant `NSColorListDidChangeNotification`.
        static std::string color_list_did_change_notification();
        /// @brief Value of the SDK constant `NSColorPanelColorDidChangeNotification`.
        static std::string color_panel_color_did_change_notification();
        /// @brief Value of the SDK constant `NSComboBoxWillPopUpNotification`.
        static std::string combo_box_will_pop_up_notification();
        /// @brief Value of the SDK constant `NSComboBoxWillDismissNotification`.
        static std::string combo_box_will_dismiss_notification();
        /// @brief Value of the SDK constant `NSComboBoxSelectionDidChangeNotification`.
        static std::string combo_box_selection_did_change_notification();
        /// @brief Value of the SDK constant `NSComboBoxSelectionIsChangingNotification`.
        static std::string combo_box_selection_is_changing_notification();
        /// @brief Value of the SDK constant `NSControlTextDidBeginEditingNotification`.
        static std::string control_text_did_begin_editing_notification();
        /// @brief Value of the SDK constant `NSControlTextDidEndEditingNotification`.
        static std::string control_text_did_end_editing_notification();
        /// @brief Value of the SDK constant `NSControlTextDidChangeNotification`.
        static std::string control_text_did_change_notification();
        /// @brief Value of the SDK constant `NSAntialiasThresholdChangedNotification`.
        static std::string antialias_threshold_changed_notification();
        /// @brief Value of the SDK constant `NSFontSetChangedNotification`.
        static std::string font_set_changed_notification();
        /// @brief Value of the SDK constant `NSFontCollectionDidChangeNotification`.
        static std::string font_collection_did_change_notification();
        /// @brief Value of the SDK constant `NSContextHelpModeDidActivateNotification`.
        static std::string context_help_mode_did_activate_notification();
        /// @brief Value of the SDK constant `NSContextHelpModeDidDeactivateNotification`.
        static std::string context_help_mode_did_deactivate_notification();
        /// @brief Value of the SDK constant `NSImageRepRegistryDidChangeNotification`.
        static std::string image_rep_registry_did_change_notification();
        /// @brief Value of the SDK constant `NSMenuWillSendActionNotification`.
        static std::string menu_will_send_action_notification();
        /// @brief Value of the SDK constant `NSMenuDidSendActionNotification`.
        static std::string menu_did_send_action_notification();
        /// @brief Value of the SDK constant `NSMenuDidAddItemNotification`.
        static std::string menu_did_add_item_notification();
        /// @brief Value of the SDK constant `NSMenuDidRemoveItemNotification`.
        static std::string menu_did_remove_item_notification();
        /// @brief Value of the SDK constant `NSMenuDidChangeItemNotification`.
        static std::string menu_did_change_item_notification();
        /// @brief Value of the SDK constant `NSMenuDidBeginTrackingNotification`.
        static std::string menu_did_begin_tracking_notification();
        /// @brief Value of the SDK constant `NSMenuDidEndTrackingNotification`.
        static std::string menu_did_end_tracking_notification();
        /// @brief Value of the SDK constant `NSOutlineViewSelectionDidChangeNotification`.
        static std::string outline_view_selection_did_change_notification();
        /// @brief Value of the SDK constant `NSOutlineViewColumnDidMoveNotification`.
        static std::string outline_view_column_did_move_notification();
        /// @brief Value of the SDK constant `NSOutlineViewColumnDidResizeNotification`.
        static std::string outline_view_column_did_resize_notification();
        /// @brief Value of the SDK constant `NSOutlineViewSelectionIsChangingNotification`.
        static std::string outline_view_selection_is_changing_notification();
        /// @brief Value of the SDK constant `NSOutlineViewItemWillExpandNotification`.
        static std::string outline_view_item_will_expand_notification();
        /// @brief Value of the SDK constant `NSOutlineViewItemDidExpandNotification`.
        static std::string outline_view_item_did_expand_notification();
        /// @brief Value of the SDK constant `NSOutlineViewItemWillCollapseNotification`.
        static std::string outline_view_item_will_collapse_notification();
        /// @brief Value of the SDK constant `NSOutlineViewItemDidCollapseNotification`.
        static std::string outline_view_item_did_collapse_notification();
        /// @brief Value of the SDK constant `NSPopUpButtonWillPopUpNotification`.
        static std::string pop_up_button_will_pop_up_notification();
        /// @brief Value of the SDK constant `NSPopUpButtonCellWillPopUpNotification`.
        static std::string pop_up_button_cell_will_pop_up_notification();
        /// @brief Value of the SDK constant `NSPopoverWillShowNotification`.
        static std::string popover_will_show_notification();
        /// @brief Value of the SDK constant `NSPopoverDidShowNotification`.
        static std::string popover_did_show_notification();
        /// @brief Value of the SDK constant `NSPopoverWillCloseNotification`.
        static std::string popover_will_close_notification();
        /// @brief Value of the SDK constant `NSPopoverDidCloseNotification`.
        static std::string popover_did_close_notification();
        /// @brief Value of the SDK constant `NSRuleEditorRowsDidChangeNotification`.
        static std::string rule_editor_rows_did_change_notification();
        /// @brief Value of the SDK constant `NSScreenColorSpaceDidChangeNotification`.
        static std::string screen_color_space_did_change_notification();
        /// @brief Value of the SDK constant `NSScrollViewWillStartLiveMagnifyNotification`.
        static std::string scroll_view_will_start_live_magnify_notification();
        /// @brief Value of the SDK constant `NSScrollViewDidEndLiveMagnifyNotification`.
        static std::string scroll_view_did_end_live_magnify_notification();
        /// @brief Value of the SDK constant `NSScrollViewWillStartLiveScrollNotification`.
        static std::string scroll_view_will_start_live_scroll_notification();
        /// @brief Value of the SDK constant `NSScrollViewDidLiveScrollNotification`.
        static std::string scroll_view_did_live_scroll_notification();
        /// @brief Value of the SDK constant `NSScrollViewDidEndLiveScrollNotification`.
        static std::string scroll_view_did_end_live_scroll_notification();
        /// @brief Value of the SDK constant `NSPreferredScrollerStyleDidChangeNotification`.
        static std::string preferred_scroller_style_did_change_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticSpellingCorrectionNotification`.
        static std::string spell_checker_did_change_automatic_spelling_correction_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticTextReplacementNotification`.
        static std::string spell_checker_did_change_automatic_text_replacement_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticQuoteSubstitutionNotification`.
        static std::string spell_checker_did_change_automatic_quote_substitution_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticDashSubstitutionNotification`.
        static std::string spell_checker_did_change_automatic_dash_substitution_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticCapitalizationNotification`.
        static std::string spell_checker_did_change_automatic_capitalization_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticPeriodSubstitutionNotification`.
        static std::string spell_checker_did_change_automatic_period_substitution_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticTextCompletionNotification`.
        static std::string spell_checker_did_change_automatic_text_completion_notification();
        /// @brief Value of the SDK constant `NSSpellCheckerDidChangeAutomaticInlinePredictionNotification`.
        static std::string spell_checker_did_change_automatic_inline_prediction_notification();
        /// @brief Value of the SDK constant `NSSplitViewWillResizeSubviewsNotification`.
        static std::string split_view_will_resize_subviews_notification();
        /// @brief Value of the SDK constant `NSSplitViewDidResizeSubviewsNotification`.
        static std::string split_view_did_resize_subviews_notification();
        /// @brief Value of the SDK constant `NSTableViewSelectionDidChangeNotification`.
        static std::string table_view_selection_did_change_notification();
        /// @brief Value of the SDK constant `NSTableViewColumnDidMoveNotification`.
        static std::string table_view_column_did_move_notification();
        /// @brief Value of the SDK constant `NSTableViewColumnDidResizeNotification`.
        static std::string table_view_column_did_resize_notification();
        /// @brief Value of the SDK constant `NSTableViewSelectionIsChangingNotification`.
        static std::string table_view_selection_is_changing_notification();
        /// @brief Value of the SDK constant `NSTextDidBeginEditingNotification`.
        static std::string text_did_begin_editing_notification();
        /// @brief Value of the SDK constant `NSTextDidEndEditingNotification`.
        static std::string text_did_end_editing_notification();
        /// @brief Value of the SDK constant `NSTextDidChangeNotification`.
        static std::string text_did_change_notification();
        /// @brief Value of the SDK constant `NSTextAlternativesSelectedAlternativeStringNotification`.
        static std::string text_alternatives_selected_alternative_string_notification();
        /// @brief Value of the SDK constant `NSTextContentStorageUnsupportedAttributeAddedNotification`.
        static std::string text_content_storage_unsupported_attribute_added_notification();
        /// @brief Value of the SDK constant `NSTextInputContextKeyboardSelectionDidChangeNotification`.
        static std::string text_input_context_keyboard_selection_did_change_notification();
        /// @brief Value of the SDK constant `NSTextStorageWillProcessEditingNotification`.
        static std::string text_storage_will_process_editing_notification();
        /// @brief Value of the SDK constant `NSTextStorageDidProcessEditingNotification`.
        static std::string text_storage_did_process_editing_notification();
        /// @brief Value of the SDK constant `NSTextViewWillChangeNotifyingTextViewNotification`.
        static std::string text_view_will_change_notifying_text_view_notification();
        /// @brief Value of the SDK constant `NSTextViewDidChangeSelectionNotification`.
        static std::string text_view_did_change_selection_notification();
        /// @brief Value of the SDK constant `NSTextViewDidChangeTypingAttributesNotification`.
        static std::string text_view_did_change_typing_attributes_notification();
        /// @brief Value of the SDK constant `NSTextViewWillSwitchToNSLayoutManagerNotification`.
        static std::string text_view_will_switch_to_ns_layout_manager_notification();
        /// @brief Value of the SDK constant `NSTextViewDidSwitchToNSLayoutManagerNotification`.
        static std::string text_view_did_switch_to_ns_layout_manager_notification();
        /// @brief Value of the SDK constant `NSToolbarWillAddItemNotification`.
        static std::string toolbar_will_add_item_notification();
        /// @brief Value of the SDK constant `NSToolbarDidRemoveItemNotification`.
        static std::string toolbar_did_remove_item_notification();
        /// @brief Value of the SDK constant `NSViewFrameDidChangeNotification`.
        static std::string view_frame_did_change_notification();
        /// @brief Value of the SDK constant `NSViewBoundsDidChangeNotification`.
        static std::string view_bounds_did_change_notification();
        /// @brief Value of the SDK constant `NSViewDidUpdateTrackingAreasNotification`.
        static std::string view_did_update_tracking_areas_notification();
        /// @brief Value of the SDK constant `NSWindowDidBecomeKeyNotification`.
        static std::string window_did_become_key_notification();
        /// @brief Value of the SDK constant `NSWindowDidBecomeMainNotification`.
        static std::string window_did_become_main_notification();
        /// @brief Value of the SDK constant `NSWindowDidChangeScreenNotification`.
        static std::string window_did_change_screen_notification();
        /// @brief Value of the SDK constant `NSWindowDidDeminiaturizeNotification`.
        static std::string window_did_deminiaturize_notification();
        /// @brief Value of the SDK constant `NSWindowDidExposeNotification`.
        static std::string window_did_expose_notification();
        /// @brief Value of the SDK constant `NSWindowDidMiniaturizeNotification`.
        static std::string window_did_miniaturize_notification();
        /// @brief Value of the SDK constant `NSWindowDidMoveNotification`.
        static std::string window_did_move_notification();
        /// @brief Value of the SDK constant `NSWindowDidResignKeyNotification`.
        static std::string window_did_resign_key_notification();
        /// @brief Value of the SDK constant `NSWindowDidResignMainNotification`.
        static std::string window_did_resign_main_notification();
        /// @brief Value of the SDK constant `NSWindowDidResizeNotification`.
        static std::string window_did_resize_notification();
        /// @brief Value of the SDK constant `NSWindowDidUpdateNotification`.
        static std::string window_did_update_notification();
        /// @brief Value of the SDK constant `NSWindowWillCloseNotification`.
        static std::string window_will_close_notification();
        /// @brief Value of the SDK constant `NSWindowWillMiniaturizeNotification`.
        static std::string window_will_miniaturize_notification();
        /// @brief Value of the SDK constant `NSWindowWillMoveNotification`.
        static std::string window_will_move_notification();
        /// @brief Value of the SDK constant `NSWindowWillBeginSheetNotification`.
        static std::string window_will_begin_sheet_notification();
        /// @brief Value of the SDK constant `NSWindowDidEndSheetNotification`.
        static std::string window_did_end_sheet_notification();
        /// @brief Value of the SDK constant `NSWindowDidChangeBackingPropertiesNotification`.
        static std::string window_did_change_backing_properties_notification();
        /// @brief Value of the SDK constant `NSWindowDidChangeScreenProfileNotification`.
        static std::string window_did_change_screen_profile_notification();
        /// @brief Value of the SDK constant `NSWindowWillStartLiveResizeNotification`.
        static std::string window_will_start_live_resize_notification();
        /// @brief Value of the SDK constant `NSWindowDidEndLiveResizeNotification`.
        static std::string window_did_end_live_resize_notification();
        /// @brief Value of the SDK constant `NSWindowWillEnterFullScreenNotification`.
        static std::string window_will_enter_full_screen_notification();
        /// @brief Value of the SDK constant `NSWindowDidEnterFullScreenNotification`.
        static std::string window_did_enter_full_screen_notification();
        /// @brief Value of the SDK constant `NSWindowWillExitFullScreenNotification`.
        static std::string window_will_exit_full_screen_notification();
        /// @brief Value of the SDK constant `NSWindowDidExitFullScreenNotification`.
        static std::string window_did_exit_full_screen_notification();
        /// @brief Value of the SDK constant `NSWindowWillEnterVersionBrowserNotification`.
        static std::string window_will_enter_version_browser_notification();
        /// @brief Value of the SDK constant `NSWindowDidEnterVersionBrowserNotification`.
        static std::string window_did_enter_version_browser_notification();
        /// @brief Value of the SDK constant `NSWindowWillExitVersionBrowserNotification`.
        static std::string window_will_exit_version_browser_notification();
        /// @brief Value of the SDK constant `NSWindowDidExitVersionBrowserNotification`.
        static std::string window_did_exit_version_browser_notification();
        /// @brief Value of the SDK constant `NSWindowDidChangeOcclusionStateNotification`.
        static std::string window_did_change_occlusion_state_notification();
        /// @brief Value of the SDK constant `NSApplicationDidFinishRestoringWindowsNotification`.
        static std::string application_did_finish_restoring_windows_notification();
        /// @brief Value of the SDK constant `NSWorkspaceWillLaunchApplicationNotification`.
        static std::string workspace_will_launch_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidLaunchApplicationNotification`.
        static std::string workspace_did_launch_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidTerminateApplicationNotification`.
        static std::string workspace_did_terminate_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidHideApplicationNotification`.
        static std::string workspace_did_hide_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidUnhideApplicationNotification`.
        static std::string workspace_did_unhide_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidActivateApplicationNotification`.
        static std::string workspace_did_activate_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidDeactivateApplicationNotification`.
        static std::string workspace_did_deactivate_application_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidMountNotification`.
        static std::string workspace_did_mount_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidUnmountNotification`.
        static std::string workspace_did_unmount_notification();
        /// @brief Value of the SDK constant `NSWorkspaceWillUnmountNotification`.
        static std::string workspace_will_unmount_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidRenameVolumeNotification`.
        static std::string workspace_did_rename_volume_notification();
        /// @brief Value of the SDK constant `NSWorkspaceWillPowerOffNotification`.
        static std::string workspace_will_power_off_notification();
        /// @brief Value of the SDK constant `NSWorkspaceWillSleepNotification`.
        static std::string workspace_will_sleep_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidWakeNotification`.
        static std::string workspace_did_wake_notification();
        /// @brief Value of the SDK constant `NSWorkspaceScreensDidSleepNotification`.
        static std::string workspace_screens_did_sleep_notification();
        /// @brief Value of the SDK constant `NSWorkspaceScreensDidWakeNotification`.
        static std::string workspace_screens_did_wake_notification();
        /// @brief Value of the SDK constant `NSWorkspaceSessionDidBecomeActiveNotification`.
        static std::string workspace_session_did_become_active_notification();
        /// @brief Value of the SDK constant `NSWorkspaceSessionDidResignActiveNotification`.
        static std::string workspace_session_did_resign_active_notification();
        /// @brief Value of the SDK constant `NSWorkspaceDidChangeFileLabelsNotification`.
        static std::string workspace_did_change_file_labels_notification();
        /// @brief Value of the SDK constant `NSWorkspaceActiveSpaceDidChangeNotification`.
        static std::string workspace_active_space_did_change_notification();
        /// @brief Value of the SDK constant `NSAppleEventManagerWillProcessFirstEventNotification`.
        static std::string apple_event_manager_will_process_first_event_notification();
        /// @brief Value of the SDK constant `NSBundleDidLoadNotification`.
        static std::string bundle_did_load_notification();
        /// @brief Value of the SDK constant `NSCalendarDayChangedNotification`.
        static std::string calendar_day_changed_notification();
        /// @brief Value of the SDK constant `NSClassDescriptionNeededForClassNotification`.
        static std::string class_description_needed_for_class_notification();
        /// @brief Value of the SDK constant `NSSystemClockDidChangeNotification`.
        static std::string system_clock_did_change_notification();
        /// @brief Value of the SDK constant `NSFileHandleReadCompletionNotification`.
        static std::string file_handle_read_completion_notification();
        /// @brief Value of the SDK constant `NSFileHandleReadToEndOfFileCompletionNotification`.
        static std::string file_handle_read_to_end_of_file_completion_notification();
        /// @brief Value of the SDK constant `NSFileHandleConnectionAcceptedNotification`.
        static std::string file_handle_connection_accepted_notification();
        /// @brief Value of the SDK constant `NSFileHandleDataAvailableNotification`.
        static std::string file_handle_data_available_notification();
        /// @brief Value of the SDK constant `NSUbiquityIdentityDidChangeNotification`.
        static std::string ubiquity_identity_did_change_notification();
        /// @brief Value of the SDK constant `NSHTTPCookieManagerCookiesChangedNotification`.
        static std::string http_cookie_manager_cookies_changed_notification();
        /// @brief Value of the SDK constant `NSCurrentLocaleDidChangeNotification`.
        static std::string current_locale_did_change_notification();
        /// @brief Value of the SDK constant `NSMetadataQueryDidStartGatheringNotification`.
        static std::string metadata_query_did_start_gathering_notification();
        /// @brief Value of the SDK constant `NSMetadataQueryGatheringProgressNotification`.
        static std::string metadata_query_gathering_progress_notification();
        /// @brief Value of the SDK constant `NSMetadataQueryDidFinishGatheringNotification`.
        static std::string metadata_query_did_finish_gathering_notification();
        /// @brief Value of the SDK constant `NSMetadataQueryDidUpdateNotification`.
        static std::string metadata_query_did_update_notification();
        /// @brief Value of the SDK constant `NSPortDidBecomeInvalidNotification`.
        static std::string port_did_become_invalid_notification();
        /// @brief Value of the SDK constant `NSProcessInfoThermalStateDidChangeNotification`.
        static std::string process_info_thermal_state_did_change_notification();
        /// @brief Value of the SDK constant `NSProcessInfoPowerStateDidChangeNotification`.
        static std::string process_info_power_state_did_change_notification();
        /// @brief Value of the SDK constant `NSTaskDidTerminateNotification`.
        static std::string task_did_terminate_notification();
        /// @brief Value of the SDK constant `NSSystemTimeZoneDidChangeNotification`.
        static std::string system_time_zone_did_change_notification();
        /// @brief Value of the SDK constant `NSUbiquitousKeyValueStoreDidChangeExternallyNotification`.
        static std::string ubiquitous_key_value_store_did_change_externally_notification();
        /// @brief Value of the SDK constant `NSUndoManagerCheckpointNotification`.
        static std::string undo_manager_checkpoint_notification();
        /// @brief Value of the SDK constant `NSUndoManagerWillUndoChangeNotification`.
        static std::string undo_manager_will_undo_change_notification();
        /// @brief Value of the SDK constant `NSUndoManagerWillRedoChangeNotification`.
        static std::string undo_manager_will_redo_change_notification();
        /// @brief Value of the SDK constant `NSUndoManagerDidUndoChangeNotification`.
        static std::string undo_manager_did_undo_change_notification();
        /// @brief Value of the SDK constant `NSUndoManagerDidRedoChangeNotification`.
        static std::string undo_manager_did_redo_change_notification();
        /// @brief Value of the SDK constant `NSUndoManagerDidOpenUndoGroupNotification`.
        static std::string undo_manager_did_open_undo_group_notification();
        /// @brief Value of the SDK constant `NSUndoManagerWillCloseUndoGroupNotification`.
        static std::string undo_manager_will_close_undo_group_notification();
        /// @brief Value of the SDK constant `NSUndoManagerDidCloseUndoGroupNotification`.
        static std::string undo_manager_did_close_undo_group_notification();
        /// @brief Value of the SDK constant `NSUserDefaultsDidChangeNotification`.
        static std::string user_defaults_did_change_notification();
    };

    /** @brief Named constants of type `NSStringConstants`; each function reads the SDK symbol at runtime. */
    struct StringConstants
    {
        /// @brief Value of the SDK constant `NSAccessibilityErrorCodeExceptionInfo`.
        static std::string accessibility_error_code_exception_info();
        /// @brief Value of the SDK constant `NSAccessibilityTextCompletionAttribute`.
        static std::string accessibility_text_completion_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySearchIdentifiersKey`.
        static std::string accessibility_search_identifiers_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchCurrentElementKey`.
        static std::string accessibility_search_current_element_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchCurrentRangeKey`.
        static std::string accessibility_search_current_range_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchDirectionKey`.
        static std::string accessibility_search_direction_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchResultsLimitKey`.
        static std::string accessibility_search_results_limit_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchTextKey`.
        static std::string accessibility_search_text_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchDirectionNext`.
        static std::string accessibility_search_direction_next();
        /// @brief Value of the SDK constant `NSAccessibilitySearchDirectionPrevious`.
        static std::string accessibility_search_direction_previous();
        /// @brief Value of the SDK constant `NSAccessibilitySearchResultElementKey`.
        static std::string accessibility_search_result_element_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchResultRangeKey`.
        static std::string accessibility_search_result_range_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchResultDescriptionOverrideKey`.
        static std::string accessibility_search_result_description_override_key();
        /// @brief Value of the SDK constant `NSAccessibilitySearchResultLoaderKey`.
        static std::string accessibility_search_result_loader_key();
        /// @brief Value of the SDK constant `NSAnimationProgressMark`.
        static std::string animation_progress_mark();
        /// @brief Value of the SDK constant `NSApplicationLaunchIsDefaultLaunchKey`.
        static std::string application_launch_is_default_launch_key();
        /// @brief Value of the SDK constant `NSApplicationLaunchUserNotificationKey`.
        static std::string application_launch_user_notification_key();
        /// @brief Value of the SDK constant `NSTypeIdentifierDateText`.
        static std::string type_identifier_date_text();
        /// @brief Value of the SDK constant `NSTypeIdentifierAddressText`.
        static std::string type_identifier_address_text();
        /// @brief Value of the SDK constant `NSTypeIdentifierPhoneNumberText`.
        static std::string type_identifier_phone_number_text();
        /// @brief Value of the SDK constant `NSTypeIdentifierTransitInformationText`.
        static std::string type_identifier_transit_information_text();
        /// @brief Value of the SDK constant `NSPopoverCloseReasonKey`.
        static std::string popover_close_reason_key();
        /// @brief Value of the SDK constant `NSTextMovementUserInfoKey`.
        static std::string text_movement_user_info_key();
        /// @brief Value of the SDK constant `NSAllRomanInputSourcesLocaleIdentifier`.
        static std::string all_roman_input_sources_locale_identifier();
        /// @brief Value of the SDK constant `NSUserActivityDocumentURLKey`.
        static std::string user_activity_document_url_key();
        /// @brief Value of the SDK constant `NSBackingPropertyOldScaleFactorKey`.
        static std::string backing_property_old_scale_factor_key();
        /// @brief Value of the SDK constant `NSBackingPropertyOldColorSpaceKey`.
        static std::string backing_property_old_color_space_key();
        /// @brief Value of the SDK constant `NSWorkspaceApplicationKey`.
        static std::string workspace_application_key();
        /// @brief Value of the SDK constant `NSWorkspaceVolumeLocalizedNameKey`.
        static std::string workspace_volume_localized_name_key();
        /// @brief Value of the SDK constant `NSWorkspaceVolumeURLKey`.
        static std::string workspace_volume_url_key();
        /// @brief Value of the SDK constant `NSWorkspaceVolumeOldLocalizedNameKey`.
        static std::string workspace_volume_old_localized_name_key();
        /// @brief Value of the SDK constant `NSWorkspaceVolumeOldURLKey`.
        static std::string workspace_volume_old_url_key();
        /// @brief Value of the SDK constant `NSAppleScriptErrorMessage`.
        static std::string apple_script_error_message();
        /// @brief Value of the SDK constant `NSAppleScriptErrorNumber`.
        static std::string apple_script_error_number();
        /// @brief Value of the SDK constant `NSAppleScriptErrorAppName`.
        static std::string apple_script_error_app_name();
        /// @brief Value of the SDK constant `NSAppleScriptErrorBriefMessage`.
        static std::string apple_script_error_brief_message();
        /// @brief Value of the SDK constant `NSAppleScriptErrorRange`.
        static std::string apple_script_error_range();
        /// @brief Value of the SDK constant `NSLoadedClasses`.
        static std::string loaded_classes();
        /// @brief Value of the SDK constant `NSAssertionHandlerKey`.
        static std::string assertion_handler_key();
        /// @brief Value of the SDK constant `NSFileHandleNotificationDataItem`.
        static std::string file_handle_notification_data_item();
        /// @brief Value of the SDK constant `NSFileHandleNotificationFileHandleItem`.
        static std::string file_handle_notification_file_handle_item();
        /// @brief Value of the SDK constant `NSFileManagerUnmountDissentingProcessIdentifierErrorKey`.
        static std::string file_manager_unmount_dissenting_process_identifier_error_key();
        /// @brief Value of the SDK constant `NSItemProviderPreferredImageSizeKey`.
        static std::string item_provider_preferred_image_size_key();
        /// @brief Value of the SDK constant `NSItemProviderErrorDomain`.
        static std::string item_provider_error_domain();
        /// @brief Value of the SDK constant `NSKeyedArchiveRootObjectKey`.
        static std::string keyed_archive_root_object_key();
        /// @brief Value of the SDK constant `NSMetadataQueryUpdateAddedItemsKey`.
        static std::string metadata_query_update_added_items_key();
        /// @brief Value of the SDK constant `NSMetadataQueryUpdateChangedItemsKey`.
        static std::string metadata_query_update_changed_items_key();
        /// @brief Value of the SDK constant `NSMetadataQueryUpdateRemovedItemsKey`.
        static std::string metadata_query_update_removed_items_key();
        /// @brief Value of the SDK constant `NSMetadataQueryResultContentRelevanceAttribute`.
        static std::string metadata_query_result_content_relevance_attribute();
        /// @brief Value of the SDK constant `NSMetadataQueryUserHomeScope`.
        static std::string metadata_query_user_home_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryLocalComputerScope`.
        static std::string metadata_query_local_computer_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryNetworkScope`.
        static std::string metadata_query_network_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryIndexedLocalComputerScope`.
        static std::string metadata_query_indexed_local_computer_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryIndexedNetworkScope`.
        static std::string metadata_query_indexed_network_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryUbiquitousDocumentsScope`.
        static std::string metadata_query_ubiquitous_documents_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryUbiquitousDataScope`.
        static std::string metadata_query_ubiquitous_data_scope();
        /// @brief Value of the SDK constant `NSMetadataQueryAccessibleUbiquitousExternalDocumentsScope`.
        static std::string metadata_query_accessible_ubiquitous_external_documents_scope();
        /// @brief Value of the SDK constant `NSMetadataItemFSNameKey`.
        static std::string metadata_item_fs_name_key();
        /// @brief Value of the SDK constant `NSMetadataItemDisplayNameKey`.
        static std::string metadata_item_display_name_key();
        /// @brief Value of the SDK constant `NSMetadataItemURLKey`.
        static std::string metadata_item_url_key();
        /// @brief Value of the SDK constant `NSMetadataItemPathKey`.
        static std::string metadata_item_path_key();
        /// @brief Value of the SDK constant `NSMetadataItemFSSizeKey`.
        static std::string metadata_item_fs_size_key();
        /// @brief Value of the SDK constant `NSMetadataItemFSCreationDateKey`.
        static std::string metadata_item_fs_creation_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemFSContentChangeDateKey`.
        static std::string metadata_item_fs_content_change_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemContentTypeKey`.
        static std::string metadata_item_content_type_key();
        /// @brief Value of the SDK constant `NSMetadataItemContentTypeTreeKey`.
        static std::string metadata_item_content_type_tree_key();
        /// @brief Value of the SDK constant `NSMetadataItemIsUbiquitousKey`.
        static std::string metadata_item_is_ubiquitous_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemHasUnresolvedConflictsKey`.
        static std::string metadata_ubiquitous_item_has_unresolved_conflicts_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadingStatusKey`.
        static std::string metadata_ubiquitous_item_downloading_status_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadingStatusNotDownloaded`.
        static std::string metadata_ubiquitous_item_downloading_status_not_downloaded();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadingStatusDownloaded`.
        static std::string metadata_ubiquitous_item_downloading_status_downloaded();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadingStatusCurrent`.
        static std::string metadata_ubiquitous_item_downloading_status_current();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemIsDownloadingKey`.
        static std::string metadata_ubiquitous_item_is_downloading_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemIsUploadedKey`.
        static std::string metadata_ubiquitous_item_is_uploaded_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemIsUploadingKey`.
        static std::string metadata_ubiquitous_item_is_uploading_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemPercentDownloadedKey`.
        static std::string metadata_ubiquitous_item_percent_downloaded_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemPercentUploadedKey`.
        static std::string metadata_ubiquitous_item_percent_uploaded_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadingErrorKey`.
        static std::string metadata_ubiquitous_item_downloading_error_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemUploadingErrorKey`.
        static std::string metadata_ubiquitous_item_uploading_error_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemDownloadRequestedKey`.
        static std::string metadata_ubiquitous_item_download_requested_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemIsExternalDocumentKey`.
        static std::string metadata_ubiquitous_item_is_external_document_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemContainerDisplayNameKey`.
        static std::string metadata_ubiquitous_item_container_display_name_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemURLInLocalContainerKey`.
        static std::string metadata_ubiquitous_item_url_in_local_container_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousItemIsSharedKey`.
        static std::string metadata_ubiquitous_item_is_shared_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemCurrentUserRoleKey`.
        static std::string metadata_ubiquitous_shared_item_current_user_role_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemCurrentUserPermissionsKey`.
        static std::string metadata_ubiquitous_shared_item_current_user_permissions_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemOwnerNameComponentsKey`.
        static std::string metadata_ubiquitous_shared_item_owner_name_components_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemMostRecentEditorNameComponentsKey`.
        static std::string metadata_ubiquitous_shared_item_most_recent_editor_name_components_key();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemRoleOwner`.
        static std::string metadata_ubiquitous_shared_item_role_owner();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemRoleParticipant`.
        static std::string metadata_ubiquitous_shared_item_role_participant();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemPermissionsReadOnly`.
        static std::string metadata_ubiquitous_shared_item_permissions_read_only();
        /// @brief Value of the SDK constant `NSMetadataUbiquitousSharedItemPermissionsReadWrite`.
        static std::string metadata_ubiquitous_shared_item_permissions_read_write();
        /// @brief Value of the SDK constant `NSMetadataItemAttributeChangeDateKey`.
        static std::string metadata_item_attribute_change_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemKeywordsKey`.
        static std::string metadata_item_keywords_key();
        /// @brief Value of the SDK constant `NSMetadataItemTitleKey`.
        static std::string metadata_item_title_key();
        /// @brief Value of the SDK constant `NSMetadataItemAuthorsKey`.
        static std::string metadata_item_authors_key();
        /// @brief Value of the SDK constant `NSMetadataItemEditorsKey`.
        static std::string metadata_item_editors_key();
        /// @brief Value of the SDK constant `NSMetadataItemParticipantsKey`.
        static std::string metadata_item_participants_key();
        /// @brief Value of the SDK constant `NSMetadataItemProjectsKey`.
        static std::string metadata_item_projects_key();
        /// @brief Value of the SDK constant `NSMetadataItemDownloadedDateKey`.
        static std::string metadata_item_downloaded_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemWhereFromsKey`.
        static std::string metadata_item_where_froms_key();
        /// @brief Value of the SDK constant `NSMetadataItemCommentKey`.
        static std::string metadata_item_comment_key();
        /// @brief Value of the SDK constant `NSMetadataItemCopyrightKey`.
        static std::string metadata_item_copyright_key();
        /// @brief Value of the SDK constant `NSMetadataItemLastUsedDateKey`.
        static std::string metadata_item_last_used_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemContentCreationDateKey`.
        static std::string metadata_item_content_creation_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemContentModificationDateKey`.
        static std::string metadata_item_content_modification_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemDateAddedKey`.
        static std::string metadata_item_date_added_key();
        /// @brief Value of the SDK constant `NSMetadataItemDurationSecondsKey`.
        static std::string metadata_item_duration_seconds_key();
        /// @brief Value of the SDK constant `NSMetadataItemContactKeywordsKey`.
        static std::string metadata_item_contact_keywords_key();
        /// @brief Value of the SDK constant `NSMetadataItemVersionKey`.
        static std::string metadata_item_version_key();
        /// @brief Value of the SDK constant `NSMetadataItemPixelHeightKey`.
        static std::string metadata_item_pixel_height_key();
        /// @brief Value of the SDK constant `NSMetadataItemPixelWidthKey`.
        static std::string metadata_item_pixel_width_key();
        /// @brief Value of the SDK constant `NSMetadataItemPixelCountKey`.
        static std::string metadata_item_pixel_count_key();
        /// @brief Value of the SDK constant `NSMetadataItemColorSpaceKey`.
        static std::string metadata_item_color_space_key();
        /// @brief Value of the SDK constant `NSMetadataItemBitsPerSampleKey`.
        static std::string metadata_item_bits_per_sample_key();
        /// @brief Value of the SDK constant `NSMetadataItemFlashOnOffKey`.
        static std::string metadata_item_flash_on_off_key();
        /// @brief Value of the SDK constant `NSMetadataItemFocalLengthKey`.
        static std::string metadata_item_focal_length_key();
        /// @brief Value of the SDK constant `NSMetadataItemAcquisitionMakeKey`.
        static std::string metadata_item_acquisition_make_key();
        /// @brief Value of the SDK constant `NSMetadataItemAcquisitionModelKey`.
        static std::string metadata_item_acquisition_model_key();
        /// @brief Value of the SDK constant `NSMetadataItemISOSpeedKey`.
        static std::string metadata_item_iso_speed_key();
        /// @brief Value of the SDK constant `NSMetadataItemOrientationKey`.
        static std::string metadata_item_orientation_key();
        /// @brief Value of the SDK constant `NSMetadataItemLayerNamesKey`.
        static std::string metadata_item_layer_names_key();
        /// @brief Value of the SDK constant `NSMetadataItemWhiteBalanceKey`.
        static std::string metadata_item_white_balance_key();
        /// @brief Value of the SDK constant `NSMetadataItemApertureKey`.
        static std::string metadata_item_aperture_key();
        /// @brief Value of the SDK constant `NSMetadataItemProfileNameKey`.
        static std::string metadata_item_profile_name_key();
        /// @brief Value of the SDK constant `NSMetadataItemResolutionWidthDPIKey`.
        static std::string metadata_item_resolution_width_dpi_key();
        /// @brief Value of the SDK constant `NSMetadataItemResolutionHeightDPIKey`.
        static std::string metadata_item_resolution_height_dpi_key();
        /// @brief Value of the SDK constant `NSMetadataItemExposureModeKey`.
        static std::string metadata_item_exposure_mode_key();
        /// @brief Value of the SDK constant `NSMetadataItemExposureTimeSecondsKey`.
        static std::string metadata_item_exposure_time_seconds_key();
        /// @brief Value of the SDK constant `NSMetadataItemEXIFVersionKey`.
        static std::string metadata_item_exif_version_key();
        /// @brief Value of the SDK constant `NSMetadataItemCameraOwnerKey`.
        static std::string metadata_item_camera_owner_key();
        /// @brief Value of the SDK constant `NSMetadataItemFocalLength35mmKey`.
        static std::string metadata_item_focal_length35mm_key();
        /// @brief Value of the SDK constant `NSMetadataItemLensModelKey`.
        static std::string metadata_item_lens_model_key();
        /// @brief Value of the SDK constant `NSMetadataItemEXIFGPSVersionKey`.
        static std::string metadata_item_exifgps_version_key();
        /// @brief Value of the SDK constant `NSMetadataItemAltitudeKey`.
        static std::string metadata_item_altitude_key();
        /// @brief Value of the SDK constant `NSMetadataItemLatitudeKey`.
        static std::string metadata_item_latitude_key();
        /// @brief Value of the SDK constant `NSMetadataItemLongitudeKey`.
        static std::string metadata_item_longitude_key();
        /// @brief Value of the SDK constant `NSMetadataItemSpeedKey`.
        static std::string metadata_item_speed_key();
        /// @brief Value of the SDK constant `NSMetadataItemTimestampKey`.
        static std::string metadata_item_timestamp_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSTrackKey`.
        static std::string metadata_item_gps_track_key();
        /// @brief Value of the SDK constant `NSMetadataItemImageDirectionKey`.
        static std::string metadata_item_image_direction_key();
        /// @brief Value of the SDK constant `NSMetadataItemNamedLocationKey`.
        static std::string metadata_item_named_location_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSStatusKey`.
        static std::string metadata_item_gps_status_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSMeasureModeKey`.
        static std::string metadata_item_gps_measure_mode_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDOPKey`.
        static std::string metadata_item_gpsdop_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSMapDatumKey`.
        static std::string metadata_item_gps_map_datum_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDestLatitudeKey`.
        static std::string metadata_item_gps_dest_latitude_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDestLongitudeKey`.
        static std::string metadata_item_gps_dest_longitude_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDestBearingKey`.
        static std::string metadata_item_gps_dest_bearing_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDestDistanceKey`.
        static std::string metadata_item_gps_dest_distance_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSProcessingMethodKey`.
        static std::string metadata_item_gps_processing_method_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSAreaInformationKey`.
        static std::string metadata_item_gps_area_information_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDateStampKey`.
        static std::string metadata_item_gps_date_stamp_key();
        /// @brief Value of the SDK constant `NSMetadataItemGPSDifferentalKey`.
        static std::string metadata_item_gps_differental_key();
        /// @brief Value of the SDK constant `NSMetadataItemCodecsKey`.
        static std::string metadata_item_codecs_key();
        /// @brief Value of the SDK constant `NSMetadataItemMediaTypesKey`.
        static std::string metadata_item_media_types_key();
        /// @brief Value of the SDK constant `NSMetadataItemStreamableKey`.
        static std::string metadata_item_streamable_key();
        /// @brief Value of the SDK constant `NSMetadataItemTotalBitRateKey`.
        static std::string metadata_item_total_bit_rate_key();
        /// @brief Value of the SDK constant `NSMetadataItemVideoBitRateKey`.
        static std::string metadata_item_video_bit_rate_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudioBitRateKey`.
        static std::string metadata_item_audio_bit_rate_key();
        /// @brief Value of the SDK constant `NSMetadataItemDeliveryTypeKey`.
        static std::string metadata_item_delivery_type_key();
        /// @brief Value of the SDK constant `NSMetadataItemAlbumKey`.
        static std::string metadata_item_album_key();
        /// @brief Value of the SDK constant `NSMetadataItemHasAlphaChannelKey`.
        static std::string metadata_item_has_alpha_channel_key();
        /// @brief Value of the SDK constant `NSMetadataItemRedEyeOnOffKey`.
        static std::string metadata_item_red_eye_on_off_key();
        /// @brief Value of the SDK constant `NSMetadataItemMeteringModeKey`.
        static std::string metadata_item_metering_mode_key();
        /// @brief Value of the SDK constant `NSMetadataItemMaxApertureKey`.
        static std::string metadata_item_max_aperture_key();
        /// @brief Value of the SDK constant `NSMetadataItemFNumberKey`.
        static std::string metadata_item_f_number_key();
        /// @brief Value of the SDK constant `NSMetadataItemExposureProgramKey`.
        static std::string metadata_item_exposure_program_key();
        /// @brief Value of the SDK constant `NSMetadataItemExposureTimeStringKey`.
        static std::string metadata_item_exposure_time_string_key();
        /// @brief Value of the SDK constant `NSMetadataItemHeadlineKey`.
        static std::string metadata_item_headline_key();
        /// @brief Value of the SDK constant `NSMetadataItemInstructionsKey`.
        static std::string metadata_item_instructions_key();
        /// @brief Value of the SDK constant `NSMetadataItemCityKey`.
        static std::string metadata_item_city_key();
        /// @brief Value of the SDK constant `NSMetadataItemStateOrProvinceKey`.
        static std::string metadata_item_state_or_province_key();
        /// @brief Value of the SDK constant `NSMetadataItemCountryKey`.
        static std::string metadata_item_country_key();
        /// @brief Value of the SDK constant `NSMetadataItemTextContentKey`.
        static std::string metadata_item_text_content_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudioSampleRateKey`.
        static std::string metadata_item_audio_sample_rate_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudioChannelCountKey`.
        static std::string metadata_item_audio_channel_count_key();
        /// @brief Value of the SDK constant `NSMetadataItemTempoKey`.
        static std::string metadata_item_tempo_key();
        /// @brief Value of the SDK constant `NSMetadataItemKeySignatureKey`.
        static std::string metadata_item_key_signature_key();
        /// @brief Value of the SDK constant `NSMetadataItemTimeSignatureKey`.
        static std::string metadata_item_time_signature_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudioEncodingApplicationKey`.
        static std::string metadata_item_audio_encoding_application_key();
        /// @brief Value of the SDK constant `NSMetadataItemComposerKey`.
        static std::string metadata_item_composer_key();
        /// @brief Value of the SDK constant `NSMetadataItemLyricistKey`.
        static std::string metadata_item_lyricist_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudioTrackNumberKey`.
        static std::string metadata_item_audio_track_number_key();
        /// @brief Value of the SDK constant `NSMetadataItemRecordingDateKey`.
        static std::string metadata_item_recording_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemMusicalGenreKey`.
        static std::string metadata_item_musical_genre_key();
        /// @brief Value of the SDK constant `NSMetadataItemIsGeneralMIDISequenceKey`.
        static std::string metadata_item_is_general_midi_sequence_key();
        /// @brief Value of the SDK constant `NSMetadataItemRecordingYearKey`.
        static std::string metadata_item_recording_year_key();
        /// @brief Value of the SDK constant `NSMetadataItemOrganizationsKey`.
        static std::string metadata_item_organizations_key();
        /// @brief Value of the SDK constant `NSMetadataItemLanguagesKey`.
        static std::string metadata_item_languages_key();
        /// @brief Value of the SDK constant `NSMetadataItemRightsKey`.
        static std::string metadata_item_rights_key();
        /// @brief Value of the SDK constant `NSMetadataItemPublishersKey`.
        static std::string metadata_item_publishers_key();
        /// @brief Value of the SDK constant `NSMetadataItemContributorsKey`.
        static std::string metadata_item_contributors_key();
        /// @brief Value of the SDK constant `NSMetadataItemCoverageKey`.
        static std::string metadata_item_coverage_key();
        /// @brief Value of the SDK constant `NSMetadataItemSubjectKey`.
        static std::string metadata_item_subject_key();
        /// @brief Value of the SDK constant `NSMetadataItemThemeKey`.
        static std::string metadata_item_theme_key();
        /// @brief Value of the SDK constant `NSMetadataItemDescriptionKey`.
        static std::string metadata_item_description_key();
        /// @brief Value of the SDK constant `NSMetadataItemIdentifierKey`.
        static std::string metadata_item_identifier_key();
        /// @brief Value of the SDK constant `NSMetadataItemAudiencesKey`.
        static std::string metadata_item_audiences_key();
        /// @brief Value of the SDK constant `NSMetadataItemNumberOfPagesKey`.
        static std::string metadata_item_number_of_pages_key();
        /// @brief Value of the SDK constant `NSMetadataItemPageWidthKey`.
        static std::string metadata_item_page_width_key();
        /// @brief Value of the SDK constant `NSMetadataItemPageHeightKey`.
        static std::string metadata_item_page_height_key();
        /// @brief Value of the SDK constant `NSMetadataItemSecurityMethodKey`.
        static std::string metadata_item_security_method_key();
        /// @brief Value of the SDK constant `NSMetadataItemCreatorKey`.
        static std::string metadata_item_creator_key();
        /// @brief Value of the SDK constant `NSMetadataItemEncodingApplicationsKey`.
        static std::string metadata_item_encoding_applications_key();
        /// @brief Value of the SDK constant `NSMetadataItemDueDateKey`.
        static std::string metadata_item_due_date_key();
        /// @brief Value of the SDK constant `NSMetadataItemStarRatingKey`.
        static std::string metadata_item_star_rating_key();
        /// @brief Value of the SDK constant `NSMetadataItemPhoneNumbersKey`.
        static std::string metadata_item_phone_numbers_key();
        /// @brief Value of the SDK constant `NSMetadataItemEmailAddressesKey`.
        static std::string metadata_item_email_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemInstantMessageAddressesKey`.
        static std::string metadata_item_instant_message_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemKindKey`.
        static std::string metadata_item_kind_key();
        /// @brief Value of the SDK constant `NSMetadataItemRecipientsKey`.
        static std::string metadata_item_recipients_key();
        /// @brief Value of the SDK constant `NSMetadataItemFinderCommentKey`.
        static std::string metadata_item_finder_comment_key();
        /// @brief Value of the SDK constant `NSMetadataItemFontsKey`.
        static std::string metadata_item_fonts_key();
        /// @brief Value of the SDK constant `NSMetadataItemAppleLoopsRootKeyKey`.
        static std::string metadata_item_apple_loops_root_key_key();
        /// @brief Value of the SDK constant `NSMetadataItemAppleLoopsKeyFilterTypeKey`.
        static std::string metadata_item_apple_loops_key_filter_type_key();
        /// @brief Value of the SDK constant `NSMetadataItemAppleLoopsLoopModeKey`.
        static std::string metadata_item_apple_loops_loop_mode_key();
        /// @brief Value of the SDK constant `NSMetadataItemAppleLoopDescriptorsKey`.
        static std::string metadata_item_apple_loop_descriptors_key();
        /// @brief Value of the SDK constant `NSMetadataItemMusicalInstrumentCategoryKey`.
        static std::string metadata_item_musical_instrument_category_key();
        /// @brief Value of the SDK constant `NSMetadataItemMusicalInstrumentNameKey`.
        static std::string metadata_item_musical_instrument_name_key();
        /// @brief Value of the SDK constant `NSMetadataItemCFBundleIdentifierKey`.
        static std::string metadata_item_cf_bundle_identifier_key();
        /// @brief Value of the SDK constant `NSMetadataItemInformationKey`.
        static std::string metadata_item_information_key();
        /// @brief Value of the SDK constant `NSMetadataItemDirectorKey`.
        static std::string metadata_item_director_key();
        /// @brief Value of the SDK constant `NSMetadataItemProducerKey`.
        static std::string metadata_item_producer_key();
        /// @brief Value of the SDK constant `NSMetadataItemGenreKey`.
        static std::string metadata_item_genre_key();
        /// @brief Value of the SDK constant `NSMetadataItemPerformersKey`.
        static std::string metadata_item_performers_key();
        /// @brief Value of the SDK constant `NSMetadataItemOriginalFormatKey`.
        static std::string metadata_item_original_format_key();
        /// @brief Value of the SDK constant `NSMetadataItemOriginalSourceKey`.
        static std::string metadata_item_original_source_key();
        /// @brief Value of the SDK constant `NSMetadataItemAuthorEmailAddressesKey`.
        static std::string metadata_item_author_email_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemRecipientEmailAddressesKey`.
        static std::string metadata_item_recipient_email_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemAuthorAddressesKey`.
        static std::string metadata_item_author_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemRecipientAddressesKey`.
        static std::string metadata_item_recipient_addresses_key();
        /// @brief Value of the SDK constant `NSMetadataItemIsLikelyJunkKey`.
        static std::string metadata_item_is_likely_junk_key();
        /// @brief Value of the SDK constant `NSMetadataItemExecutableArchitecturesKey`.
        static std::string metadata_item_executable_architectures_key();
        /// @brief Value of the SDK constant `NSMetadataItemExecutablePlatformKey`.
        static std::string metadata_item_executable_platform_key();
        /// @brief Value of the SDK constant `NSMetadataItemApplicationCategoriesKey`.
        static std::string metadata_item_application_categories_key();
        /// @brief Value of the SDK constant `NSMetadataItemIsApplicationManagedKey`.
        static std::string metadata_item_is_application_managed_key();
        /// @brief Value of the SDK constant `NSNetServicesErrorCode`.
        static std::string net_services_error_code();
        /// @brief Value of the SDK constant `NSPersonNameComponentKey`.
        static std::string person_name_component_key();
        /// @brief Value of the SDK constant `NSPersonNameComponentGivenName`.
        static std::string person_name_component_given_name();
        /// @brief Value of the SDK constant `NSPersonNameComponentFamilyName`.
        static std::string person_name_component_family_name();
        /// @brief Value of the SDK constant `NSPersonNameComponentMiddleName`.
        static std::string person_name_component_middle_name();
        /// @brief Value of the SDK constant `NSPersonNameComponentPrefix`.
        static std::string person_name_component_prefix();
        /// @brief Value of the SDK constant `NSPersonNameComponentSuffix`.
        static std::string person_name_component_suffix();
        /// @brief Value of the SDK constant `NSPersonNameComponentNickname`.
        static std::string person_name_component_nickname();
        /// @brief Value of the SDK constant `NSPersonNameComponentDelimiter`.
        static std::string person_name_component_delimiter();
        /// @brief Value of the SDK constant `NSOperationNotSupportedForKeyException`.
        static std::string operation_not_supported_for_key_exception();
        /// @brief Value of the SDK constant `NSGrammarRange`.
        static std::string grammar_range();
        /// @brief Value of the SDK constant `NSGrammarUserDescription`.
        static std::string grammar_user_description();
        /// @brief Value of the SDK constant `NSGrammarCorrections`.
        static std::string grammar_corrections();
        /// @brief Value of the SDK constant `NSURLFileScheme`.
        static std::string url_file_scheme();
        /// @brief Value of the SDK constant `NSURLCredentialStorageRemoveSynchronizableCredentials`.
        static std::string url_credential_storage_remove_synchronizable_credentials();
        /// @brief Value of the SDK constant `NSURLErrorFailingURLErrorKey`.
        static std::string url_error_failing_url_error_key();
        /// @brief Value of the SDK constant `NSURLErrorFailingURLPeerTrustErrorKey`.
        static std::string url_error_failing_url_peer_trust_error_key();
        /// @brief Value of the SDK constant `NSURLErrorBackgroundTaskCancelledReasonKey`.
        static std::string url_error_background_task_cancelled_reason_key();
        /// @brief Value of the SDK constant `NSURLProtectionSpaceHTTP`.
        static std::string url_protection_space_http();
        /// @brief Value of the SDK constant `NSURLProtectionSpaceHTTPS`.
        static std::string url_protection_space_https();
        /// @brief Value of the SDK constant `NSURLProtectionSpaceHTTPProxy`.
        static std::string url_protection_space_http_proxy();
        /// @brief Value of the SDK constant `NSURLProtectionSpaceHTTPSProxy`.
        static std::string url_protection_space_https_proxy();
        /// @brief Value of the SDK constant `NSURLProtectionSpaceSOCKSProxy`.
        static std::string url_protection_space_socks_proxy();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodDefault`.
        static std::string url_authentication_method_default();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodHTTPBasic`.
        static std::string url_authentication_method_http_basic();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodHTTPDigest`.
        static std::string url_authentication_method_http_digest();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodHTMLForm`.
        static std::string url_authentication_method_html_form();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodNTLM`.
        static std::string url_authentication_method_ntlm();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodNegotiate`.
        static std::string url_authentication_method_negotiate();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodClientCertificate`.
        static std::string url_authentication_method_client_certificate();
        /// @brief Value of the SDK constant `NSURLAuthenticationMethodServerTrust`.
        static std::string url_authentication_method_server_trust();
        /// @brief Value of the SDK constant `NSURLSessionDownloadTaskResumeData`.
        static std::string url_session_download_task_resume_data();
        /// @brief Value of the SDK constant `NSURLSessionUploadTaskResumeData`.
        static std::string url_session_upload_task_resume_data();
        /// @brief Value of the SDK constant `NSUbiquitousKeyValueStoreChangeReasonKey`.
        static std::string ubiquitous_key_value_store_change_reason_key();
        /// @brief Value of the SDK constant `NSUbiquitousKeyValueStoreChangedKeysKey`.
        static std::string ubiquitous_key_value_store_changed_keys_key();
        /// @brief Value of the SDK constant `NSUndoManagerGroupIsDiscardableKey`.
        static std::string undo_manager_group_is_discardable_key();
        /// @brief Value of the SDK constant `NSUserActivityTypeBrowsingWeb`.
        static std::string user_activity_type_browsing_web();
        /// @brief Value of the SDK constant `NSGlobalDomain`.
        static std::string global_domain();
        /// @brief Value of the SDK constant `NSArgumentDomain`.
        static std::string argument_domain();
        /// @brief Value of the SDK constant `NSRegistrationDomain`.
        static std::string registration_domain();
    };

    /** @brief Named constants of type `NSAccessibilityAttributeName`; each function reads the SDK symbol at runtime. */
    struct AccessibilityAttributeName
    {
        /// @brief Value of the SDK constant `NSAccessibilityRoleAttribute`.
        static std::string accessibility_role_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRoleDescriptionAttribute`.
        static std::string accessibility_role_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySubroleAttribute`.
        static std::string accessibility_subrole_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHelpAttribute`.
        static std::string accessibility_help_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityValueAttribute`.
        static std::string accessibility_value_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMinValueAttribute`.
        static std::string accessibility_min_value_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMaxValueAttribute`.
        static std::string accessibility_max_value_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityEnabledAttribute`.
        static std::string accessibility_enabled_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFocusedAttribute`.
        static std::string accessibility_focused_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityParentAttribute`.
        static std::string accessibility_parent_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityChildrenAttribute`.
        static std::string accessibility_children_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityWindowAttribute`.
        static std::string accessibility_window_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTopLevelUIElementAttribute`.
        static std::string accessibility_top_level_ui_element_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedChildrenAttribute`.
        static std::string accessibility_selected_children_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleChildrenAttribute`.
        static std::string accessibility_visible_children_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityPositionAttribute`.
        static std::string accessibility_position_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySizeAttribute`.
        static std::string accessibility_size_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityContentsAttribute`.
        static std::string accessibility_contents_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTitleAttribute`.
        static std::string accessibility_title_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDescriptionAttribute`.
        static std::string accessibility_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityShownMenuAttribute`.
        static std::string accessibility_shown_menu_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySharedFocusElementsAttribute`.
        static std::string accessibility_shared_focus_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityPreviousContentsAttribute`.
        static std::string accessibility_previous_contents_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityNextContentsAttribute`.
        static std::string accessibility_next_contents_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHeaderAttribute`.
        static std::string accessibility_header_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityEditedAttribute`.
        static std::string accessibility_edited_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTabsAttribute`.
        static std::string accessibility_tabs_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHorizontalScrollBarAttribute`.
        static std::string accessibility_horizontal_scroll_bar_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVerticalScrollBarAttribute`.
        static std::string accessibility_vertical_scroll_bar_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityOverflowButtonAttribute`.
        static std::string accessibility_overflow_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityIncrementButtonAttribute`.
        static std::string accessibility_increment_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDecrementButtonAttribute`.
        static std::string accessibility_decrement_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFilenameAttribute`.
        static std::string accessibility_filename_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityExpandedAttribute`.
        static std::string accessibility_expanded_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedAttribute`.
        static std::string accessibility_selected_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySplittersAttribute`.
        static std::string accessibility_splitters_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDocumentAttribute`.
        static std::string accessibility_document_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityActivationPointAttribute`.
        static std::string accessibility_activation_point_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityURLAttribute`.
        static std::string accessibility_url_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityIndexAttribute`.
        static std::string accessibility_index_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityContainsProtectedContentAttribute`.
        static std::string accessibility_contains_protected_content_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAlternateUIVisibleAttribute`.
        static std::string accessibility_alternate_ui_visible_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRequiredAttribute`.
        static std::string accessibility_required_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAutoInteractableAttribute`.
        static std::string accessibility_auto_interactable_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDateTimeComponentsAttribute`.
        static std::string accessibility_date_time_components_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityEmbeddedImageDescriptionAttribute`.
        static std::string accessibility_embedded_image_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityPathAttribute`.
        static std::string accessibility_path_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTextInputMarkedRangeAttribute`.
        static std::string accessibility_text_input_marked_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityBlockQuoteLevelAttribute`.
        static std::string accessibility_block_quote_level_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevelAttribute`.
        static std::string accessibility_heading_level_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLanguageAttribute`.
        static std::string accessibility_language_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisitedAttribute`.
        static std::string accessibility_visited_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTitleUIElementAttribute`.
        static std::string accessibility_title_ui_element_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityServesAsTitleForUIElementsAttribute`.
        static std::string accessibility_serves_as_title_for_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLinkedUIElementsAttribute`.
        static std::string accessibility_linked_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedTextAttribute`.
        static std::string accessibility_selected_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedTextRangeAttribute`.
        static std::string accessibility_selected_text_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityNumberOfCharactersAttribute`.
        static std::string accessibility_number_of_characters_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleCharacterRangeAttribute`.
        static std::string accessibility_visible_character_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySharedTextUIElementsAttribute`.
        static std::string accessibility_shared_text_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySharedCharacterRangeAttribute`.
        static std::string accessibility_shared_character_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityInsertionPointLineNumberAttribute`.
        static std::string accessibility_insertion_point_line_number_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityChildrenInNavigationOrderAttribute`.
        static std::string accessibility_children_in_navigation_order_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMainAttribute`.
        static std::string accessibility_main_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMinimizedAttribute`.
        static std::string accessibility_minimized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityCloseButtonAttribute`.
        static std::string accessibility_close_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityZoomButtonAttribute`.
        static std::string accessibility_zoom_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMinimizeButtonAttribute`.
        static std::string accessibility_minimize_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityToolbarButtonAttribute`.
        static std::string accessibility_toolbar_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityProxyAttribute`.
        static std::string accessibility_proxy_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityGrowAreaAttribute`.
        static std::string accessibility_grow_area_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityModalAttribute`.
        static std::string accessibility_modal_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDefaultButtonAttribute`.
        static std::string accessibility_default_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityCancelButtonAttribute`.
        static std::string accessibility_cancel_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFullScreenButtonAttribute`.
        static std::string accessibility_full_screen_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMenuBarAttribute`.
        static std::string accessibility_menu_bar_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityWindowsAttribute`.
        static std::string accessibility_windows_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFrontmostAttribute`.
        static std::string accessibility_frontmost_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHiddenAttribute`.
        static std::string accessibility_hidden_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMainWindowAttribute`.
        static std::string accessibility_main_window_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFocusedWindowAttribute`.
        static std::string accessibility_focused_window_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFocusedUIElementAttribute`.
        static std::string accessibility_focused_ui_element_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityExtrasMenuBarAttribute`.
        static std::string accessibility_extras_menu_bar_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityOrientationAttribute`.
        static std::string accessibility_orientation_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityColumnTitlesAttribute`.
        static std::string accessibility_column_titles_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySearchButtonAttribute`.
        static std::string accessibility_search_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySearchMenuAttribute`.
        static std::string accessibility_search_menu_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityClearButtonAttribute`.
        static std::string accessibility_clear_button_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRowsAttribute`.
        static std::string accessibility_rows_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleRowsAttribute`.
        static std::string accessibility_visible_rows_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedRowsAttribute`.
        static std::string accessibility_selected_rows_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityColumnsAttribute`.
        static std::string accessibility_columns_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleColumnsAttribute`.
        static std::string accessibility_visible_columns_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedColumnsAttribute`.
        static std::string accessibility_selected_columns_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySortDirectionAttribute`.
        static std::string accessibility_sort_direction_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedCellsAttribute`.
        static std::string accessibility_selected_cells_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleCellsAttribute`.
        static std::string accessibility_visible_cells_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRowHeaderUIElementsAttribute`.
        static std::string accessibility_row_header_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityColumnHeaderUIElementsAttribute`.
        static std::string accessibility_column_header_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRowIndexRangeAttribute`.
        static std::string accessibility_row_index_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityColumnIndexRangeAttribute`.
        static std::string accessibility_column_index_range_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHorizontalUnitsAttribute`.
        static std::string accessibility_horizontal_units_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVerticalUnitsAttribute`.
        static std::string accessibility_vertical_units_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHorizontalUnitDescriptionAttribute`.
        static std::string accessibility_horizontal_unit_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityVerticalUnitDescriptionAttribute`.
        static std::string accessibility_vertical_unit_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityHandlesAttribute`.
        static std::string accessibility_handles_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDisclosingAttribute`.
        static std::string accessibility_disclosing_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDisclosedRowsAttribute`.
        static std::string accessibility_disclosed_rows_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDisclosedByRowAttribute`.
        static std::string accessibility_disclosed_by_row_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityDisclosureLevelAttribute`.
        static std::string accessibility_disclosure_level_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAllowedValuesAttribute`.
        static std::string accessibility_allowed_values_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLabelUIElementsAttribute`.
        static std::string accessibility_label_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLabelValueAttribute`.
        static std::string accessibility_label_value_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkerUIElementsAttribute`.
        static std::string accessibility_marker_ui_elements_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkerValuesAttribute`.
        static std::string accessibility_marker_values_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkerGroupUIElementAttribute`.
        static std::string accessibility_marker_group_ui_element_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityUnitsAttribute`.
        static std::string accessibility_units_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityUnitDescriptionAttribute`.
        static std::string accessibility_unit_description_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkerTypeAttribute`.
        static std::string accessibility_marker_type_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkerTypeDescriptionAttribute`.
        static std::string accessibility_marker_type_description_attribute();
    };

    /** @brief Named constants of type `NSAccessibilityParameterizedAttributeName`; each function reads the SDK symbol at runtime. */
    struct AccessibilityParameterizedAttributeName
    {
        /// @brief Value of the SDK constant `NSAccessibilityLineForIndexParameterizedAttribute`.
        static std::string accessibility_line_for_index_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRangeForLineParameterizedAttribute`.
        static std::string accessibility_range_for_line_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityStringForRangeParameterizedAttribute`.
        static std::string accessibility_string_for_range_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRangeForPositionParameterizedAttribute`.
        static std::string accessibility_range_for_position_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRangeForIndexParameterizedAttribute`.
        static std::string accessibility_range_for_index_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityBoundsForRangeParameterizedAttribute`.
        static std::string accessibility_bounds_for_range_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityRTFForRangeParameterizedAttribute`.
        static std::string accessibility_rtf_for_range_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityStyleRangeForIndexParameterizedAttribute`.
        static std::string accessibility_style_range_for_index_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAttributedStringForRangeParameterizedAttribute`.
        static std::string accessibility_attributed_string_for_range_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityIndexForChildUIElementAttribute`.
        static std::string accessibility_index_for_child_ui_element_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityIndexForChildUIElementInNavigationOrderAttribute`.
        static std::string accessibility_index_for_child_ui_element_in_navigation_order_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityCellForColumnAndRowParameterizedAttribute`.
        static std::string accessibility_cell_for_column_and_row_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLayoutPointForScreenPointParameterizedAttribute`.
        static std::string accessibility_layout_point_for_screen_point_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLayoutSizeForScreenSizeParameterizedAttribute`.
        static std::string accessibility_layout_size_for_screen_size_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityScreenPointForLayoutPointParameterizedAttribute`.
        static std::string accessibility_screen_point_for_layout_point_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityScreenSizeForLayoutSizeParameterizedAttribute`.
        static std::string accessibility_screen_size_for_layout_size_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityUIElementsForSearchPredicateParameterizedAttribute`.
        static std::string accessibility_ui_elements_for_search_predicate_parameterized_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityResultsForSearchPredicateParameterizedAttribute`.
        static std::string accessibility_results_for_search_predicate_parameterized_attribute();
    };

    /** @brief Named constants of type `NSAttributedStringKey`; each function reads the SDK symbol at runtime. */
    struct AttributedStringKey
    {
        /// @brief Value of the SDK constant `NSAccessibilityFontTextAttribute`.
        static std::string accessibility_font_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityForegroundColorTextAttribute`.
        static std::string accessibility_foreground_color_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityBackgroundColorTextAttribute`.
        static std::string accessibility_background_color_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityUnderlineColorTextAttribute`.
        static std::string accessibility_underline_color_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityStrikethroughColorTextAttribute`.
        static std::string accessibility_strikethrough_color_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityUnderlineTextAttribute`.
        static std::string accessibility_underline_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilitySuperscriptTextAttribute`.
        static std::string accessibility_superscript_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityStrikethroughTextAttribute`.
        static std::string accessibility_strikethrough_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityShadowTextAttribute`.
        static std::string accessibility_shadow_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAttachmentTextAttribute`.
        static std::string accessibility_attachment_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLinkTextAttribute`.
        static std::string accessibility_link_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAutocorrectedTextAttribute`.
        static std::string accessibility_autocorrected_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityTextAlignmentAttribute`.
        static std::string accessibility_text_alignment_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFontBoldAttribute`.
        static std::string accessibility_font_bold_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityFontItalicAttribute`.
        static std::string accessibility_font_italic_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityListItemPrefixTextAttribute`.
        static std::string accessibility_list_item_prefix_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityListItemIndexTextAttribute`.
        static std::string accessibility_list_item_index_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityListItemLevelTextAttribute`.
        static std::string accessibility_list_item_level_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMisspelledTextAttribute`.
        static std::string accessibility_misspelled_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityMarkedMisspelledTextAttribute`.
        static std::string accessibility_marked_misspelled_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityLanguageTextAttribute`.
        static std::string accessibility_language_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityCustomTextAttribute`.
        static std::string accessibility_custom_text_attribute();
        /// @brief Value of the SDK constant `NSAccessibilityAnnotationTextAttribute`.
        static std::string accessibility_annotation_text_attribute();
        /// @brief Value of the SDK constant `NSFontAttributeName`.
        static std::string font_attribute_name();
        /// @brief Value of the SDK constant `NSParagraphStyleAttributeName`.
        static std::string paragraph_style_attribute_name();
        /// @brief Value of the SDK constant `NSForegroundColorAttributeName`.
        static std::string foreground_color_attribute_name();
        /// @brief Value of the SDK constant `NSBackgroundColorAttributeName`.
        static std::string background_color_attribute_name();
        /// @brief Value of the SDK constant `NSLigatureAttributeName`.
        static std::string ligature_attribute_name();
        /// @brief Value of the SDK constant `NSKernAttributeName`.
        static std::string kern_attribute_name();
        /// @brief Value of the SDK constant `NSTrackingAttributeName`.
        static std::string tracking_attribute_name();
        /// @brief Value of the SDK constant `NSStrikethroughStyleAttributeName`.
        static std::string strikethrough_style_attribute_name();
        /// @brief Value of the SDK constant `NSUnderlineStyleAttributeName`.
        static std::string underline_style_attribute_name();
        /// @brief Value of the SDK constant `NSStrokeColorAttributeName`.
        static std::string stroke_color_attribute_name();
        /// @brief Value of the SDK constant `NSStrokeWidthAttributeName`.
        static std::string stroke_width_attribute_name();
        /// @brief Value of the SDK constant `NSShadowAttributeName`.
        static std::string shadow_attribute_name();
        /// @brief Value of the SDK constant `NSTextEffectAttributeName`.
        static std::string text_effect_attribute_name();
        /// @brief Value of the SDK constant `NSAttachmentAttributeName`.
        static std::string attachment_attribute_name();
        /// @brief Value of the SDK constant `NSLinkAttributeName`.
        static std::string link_attribute_name();
        /// @brief Value of the SDK constant `NSBaselineOffsetAttributeName`.
        static std::string baseline_offset_attribute_name();
        /// @brief Value of the SDK constant `NSUnderlineColorAttributeName`.
        static std::string underline_color_attribute_name();
        /// @brief Value of the SDK constant `NSStrikethroughColorAttributeName`.
        static std::string strikethrough_color_attribute_name();
        /// @brief Value of the SDK constant `NSWritingDirectionAttributeName`.
        static std::string writing_direction_attribute_name();
        /// @brief Value of the SDK constant `NSTextHighlightStyleAttributeName`.
        static std::string text_highlight_style_attribute_name();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemeAttributeName`.
        static std::string text_highlight_color_scheme_attribute_name();
        /// @brief Value of the SDK constant `NSAdaptiveImageGlyphAttributeName`.
        static std::string adaptive_image_glyph_attribute_name();
        /// @brief Value of the SDK constant `NSWritingToolsExclusionAttributeName`.
        static std::string writing_tools_exclusion_attribute_name();
        /// @brief Value of the SDK constant `NSCursorAttributeName`.
        static std::string cursor_attribute_name();
        /// @brief Value of the SDK constant `NSToolTipAttributeName`.
        static std::string tool_tip_attribute_name();
        /// @brief Value of the SDK constant `NSMarkedClauseSegmentAttributeName`.
        static std::string marked_clause_segment_attribute_name();
        /// @brief Value of the SDK constant `NSTextAlternativesAttributeName`.
        static std::string text_alternatives_attribute_name();
        /// @brief Value of the SDK constant `NSSpellingStateAttributeName`.
        static std::string spelling_state_attribute_name();
        /// @brief Value of the SDK constant `NSSuperscriptAttributeName`.
        static std::string superscript_attribute_name();
        /// @brief Value of the SDK constant `NSGlyphInfoAttributeName`.
        static std::string glyph_info_attribute_name();
        /// @brief Value of the SDK constant `NSInlinePresentationIntentAttributeName`.
        static std::string inline_presentation_intent_attribute_name();
        /// @brief Value of the SDK constant `NSAlternateDescriptionAttributeName`.
        static std::string alternate_description_attribute_name();
        /// @brief Value of the SDK constant `NSImageURLAttributeName`.
        static std::string image_url_attribute_name();
        /// @brief Value of the SDK constant `NSLanguageIdentifierAttributeName`.
        static std::string language_identifier_attribute_name();
        /// @brief Value of the SDK constant `NSMarkdownSourcePositionAttributeName`.
        static std::string markdown_source_position_attribute_name();
        /// @brief Value of the SDK constant `NSReplacementIndexAttributeName`.
        static std::string replacement_index_attribute_name();
        /// @brief Value of the SDK constant `NSMorphologyAttributeName`.
        static std::string morphology_attribute_name();
        /// @brief Value of the SDK constant `NSInflectionRuleAttributeName`.
        static std::string inflection_rule_attribute_name();
        /// @brief Value of the SDK constant `NSInflectionAgreementArgumentAttributeName`.
        static std::string inflection_agreement_argument_attribute_name();
        /// @brief Value of the SDK constant `NSInflectionAgreementConceptAttributeName`.
        static std::string inflection_agreement_concept_attribute_name();
        /// @brief Value of the SDK constant `NSInflectionReferentConceptAttributeName`.
        static std::string inflection_referent_concept_attribute_name();
        /// @brief Value of the SDK constant `NSInflectionAlternativeAttributeName`.
        static std::string inflection_alternative_attribute_name();
        /// @brief Value of the SDK constant `NSLocalizedNumberFormatAttributeName`.
        static std::string localized_number_format_attribute_name();
        /// @brief Value of the SDK constant `NSListItemDelimiterAttributeName`.
        static std::string list_item_delimiter_attribute_name();
    };

    /** @brief Named constants of type `NSAccessibilityAnnotationAttributeKey`; each function reads the SDK symbol at runtime. */
    struct AccessibilityAnnotationAttributeKey
    {
        /// @brief Value of the SDK constant `NSAccessibilityAnnotationLabel`.
        static std::string accessibility_annotation_label();
        /// @brief Value of the SDK constant `NSAccessibilityAnnotationElement`.
        static std::string accessibility_annotation_element();
        /// @brief Value of the SDK constant `NSAccessibilityAnnotationLocation`.
        static std::string accessibility_annotation_location();
    };

    /** @brief Named constants of type `NSAccessibilityFontAttributeKey`; each function reads the SDK symbol at runtime. */
    struct AccessibilityFontAttributeKey
    {
        /// @brief Value of the SDK constant `NSAccessibilityFontNameKey`.
        static std::string accessibility_font_name_key();
        /// @brief Value of the SDK constant `NSAccessibilityFontFamilyKey`.
        static std::string accessibility_font_family_key();
        /// @brief Value of the SDK constant `NSAccessibilityVisibleNameKey`.
        static std::string accessibility_visible_name_key();
        /// @brief Value of the SDK constant `NSAccessibilityFontSizeKey`.
        static std::string accessibility_font_size_key();
    };

    /** @brief Named constants of type `NSAccessibilityOrientationValue`; each function reads the SDK symbol at runtime. */
    struct AccessibilityOrientationValue
    {
        /// @brief Value of the SDK constant `NSAccessibilityVerticalOrientationValue`.
        static std::string accessibility_vertical_orientation_value();
        /// @brief Value of the SDK constant `NSAccessibilityHorizontalOrientationValue`.
        static std::string accessibility_horizontal_orientation_value();
        /// @brief Value of the SDK constant `NSAccessibilityUnknownOrientationValue`.
        static std::string accessibility_unknown_orientation_value();
    };

    /** @brief Named constants of type `NSAccessibilitySortDirectionValue`; each function reads the SDK symbol at runtime. */
    struct AccessibilitySortDirectionValue
    {
        /// @brief Value of the SDK constant `NSAccessibilityAscendingSortDirectionValue`.
        static std::string accessibility_ascending_sort_direction_value();
        /// @brief Value of the SDK constant `NSAccessibilityDescendingSortDirectionValue`.
        static std::string accessibility_descending_sort_direction_value();
        /// @brief Value of the SDK constant `NSAccessibilityUnknownSortDirectionValue`.
        static std::string accessibility_unknown_sort_direction_value();
    };

    /** @brief Named constants of type `NSAccessibilityRulerMarkerTypeValue`; each function reads the SDK symbol at runtime. */
    struct AccessibilityRulerMarkerTypeValue
    {
        /// @brief Value of the SDK constant `NSAccessibilityLeftTabStopMarkerTypeValue`.
        static std::string accessibility_left_tab_stop_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityRightTabStopMarkerTypeValue`.
        static std::string accessibility_right_tab_stop_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityCenterTabStopMarkerTypeValue`.
        static std::string accessibility_center_tab_stop_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityDecimalTabStopMarkerTypeValue`.
        static std::string accessibility_decimal_tab_stop_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityHeadIndentMarkerTypeValue`.
        static std::string accessibility_head_indent_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityTailIndentMarkerTypeValue`.
        static std::string accessibility_tail_indent_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityFirstLineIndentMarkerTypeValue`.
        static std::string accessibility_first_line_indent_marker_type_value();
        /// @brief Value of the SDK constant `NSAccessibilityUnknownMarkerTypeValue`.
        static std::string accessibility_unknown_marker_type_value();
    };

    /** @brief Named constants of type `NSAccessibilityRulerUnitValue`; each function reads the SDK symbol at runtime. */
    struct AccessibilityRulerUnitValue
    {
        /// @brief Value of the SDK constant `NSAccessibilityInchesUnitValue`.
        static std::string accessibility_inches_unit_value();
        /// @brief Value of the SDK constant `NSAccessibilityCentimetersUnitValue`.
        static std::string accessibility_centimeters_unit_value();
        /// @brief Value of the SDK constant `NSAccessibilityPointsUnitValue`.
        static std::string accessibility_points_unit_value();
        /// @brief Value of the SDK constant `NSAccessibilityPicasUnitValue`.
        static std::string accessibility_picas_unit_value();
        /// @brief Value of the SDK constant `NSAccessibilityUnknownUnitValue`.
        static std::string accessibility_unknown_unit_value();
    };

    /** @brief Named constants of type `NSAccessibilityActionName`; each function reads the SDK symbol at runtime. */
    struct AccessibilityActionName
    {
        /// @brief Value of the SDK constant `NSAccessibilityPressAction`.
        static std::string accessibility_press_action();
        /// @brief Value of the SDK constant `NSAccessibilityIncrementAction`.
        static std::string accessibility_increment_action();
        /// @brief Value of the SDK constant `NSAccessibilityDecrementAction`.
        static std::string accessibility_decrement_action();
        /// @brief Value of the SDK constant `NSAccessibilityConfirmAction`.
        static std::string accessibility_confirm_action();
        /// @brief Value of the SDK constant `NSAccessibilityPickAction`.
        static std::string accessibility_pick_action();
        /// @brief Value of the SDK constant `NSAccessibilityCancelAction`.
        static std::string accessibility_cancel_action();
        /// @brief Value of the SDK constant `NSAccessibilityRaiseAction`.
        static std::string accessibility_raise_action();
        /// @brief Value of the SDK constant `NSAccessibilityShowMenuAction`.
        static std::string accessibility_show_menu_action();
        /// @brief Value of the SDK constant `NSAccessibilityDeleteAction`.
        static std::string accessibility_delete_action();
        /// @brief Value of the SDK constant `NSAccessibilityScrollToVisibleAction`.
        static std::string accessibility_scroll_to_visible_action();
        /// @brief Value of the SDK constant `NSAccessibilityShowAlternateUIAction`.
        static std::string accessibility_show_alternate_ui_action();
        /// @brief Value of the SDK constant `NSAccessibilityShowDefaultUIAction`.
        static std::string accessibility_show_default_ui_action();
    };

    /** @brief Named constants of type `NSAccessibilityNotificationName`; each function reads the SDK symbol at runtime. */
    struct AccessibilityNotificationName
    {
        /// @brief Value of the SDK constant `NSAccessibilityMainWindowChangedNotification`.
        static std::string accessibility_main_window_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityFocusedWindowChangedNotification`.
        static std::string accessibility_focused_window_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityFocusedUIElementChangedNotification`.
        static std::string accessibility_focused_ui_element_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityApplicationActivatedNotification`.
        static std::string accessibility_application_activated_notification();
        /// @brief Value of the SDK constant `NSAccessibilityApplicationDeactivatedNotification`.
        static std::string accessibility_application_deactivated_notification();
        /// @brief Value of the SDK constant `NSAccessibilityApplicationHiddenNotification`.
        static std::string accessibility_application_hidden_notification();
        /// @brief Value of the SDK constant `NSAccessibilityApplicationShownNotification`.
        static std::string accessibility_application_shown_notification();
        /// @brief Value of the SDK constant `NSAccessibilityWindowCreatedNotification`.
        static std::string accessibility_window_created_notification();
        /// @brief Value of the SDK constant `NSAccessibilityWindowMovedNotification`.
        static std::string accessibility_window_moved_notification();
        /// @brief Value of the SDK constant `NSAccessibilityWindowResizedNotification`.
        static std::string accessibility_window_resized_notification();
        /// @brief Value of the SDK constant `NSAccessibilityWindowMiniaturizedNotification`.
        static std::string accessibility_window_miniaturized_notification();
        /// @brief Value of the SDK constant `NSAccessibilityWindowDeminiaturizedNotification`.
        static std::string accessibility_window_deminiaturized_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDrawerCreatedNotification`.
        static std::string accessibility_drawer_created_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySheetCreatedNotification`.
        static std::string accessibility_sheet_created_notification();
        /// @brief Value of the SDK constant `NSAccessibilityUIElementDestroyedNotification`.
        static std::string accessibility_ui_element_destroyed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityValueChangedNotification`.
        static std::string accessibility_value_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityTitleChangedNotification`.
        static std::string accessibility_title_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityResizedNotification`.
        static std::string accessibility_resized_notification();
        /// @brief Value of the SDK constant `NSAccessibilityMovedNotification`.
        static std::string accessibility_moved_notification();
        /// @brief Value of the SDK constant `NSAccessibilityCreatedNotification`.
        static std::string accessibility_created_notification();
        /// @brief Value of the SDK constant `NSAccessibilityLayoutChangedNotification`.
        static std::string accessibility_layout_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityHelpTagCreatedNotification`.
        static std::string accessibility_help_tag_created_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedTextChangedNotification`.
        static std::string accessibility_selected_text_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityRowCountChangedNotification`.
        static std::string accessibility_row_count_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedChildrenChangedNotification`.
        static std::string accessibility_selected_children_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedRowsChangedNotification`.
        static std::string accessibility_selected_rows_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedColumnsChangedNotification`.
        static std::string accessibility_selected_columns_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityRowExpandedNotification`.
        static std::string accessibility_row_expanded_notification();
        /// @brief Value of the SDK constant `NSAccessibilityRowCollapsedNotification`.
        static std::string accessibility_row_collapsed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityAutocorrectionOccurredNotification`.
        static std::string accessibility_autocorrection_occurred_notification();
        /// @brief Value of the SDK constant `NSAccessibilityTextInputMarkingSessionBeganNotification`.
        static std::string accessibility_text_input_marking_session_began_notification();
        /// @brief Value of the SDK constant `NSAccessibilityTextInputMarkingSessionEndedNotification`.
        static std::string accessibility_text_input_marking_session_ended_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingSourceDragBeganNotification`.
        static std::string accessibility_dragging_source_drag_began_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingSourceDragEndedNotification`.
        static std::string accessibility_dragging_source_drag_ended_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingDestinationDropAllowedNotification`.
        static std::string accessibility_dragging_destination_drop_allowed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingDestinationDropNotAllowedNotification`.
        static std::string accessibility_dragging_destination_drop_not_allowed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingDestinationDragAcceptedNotification`.
        static std::string accessibility_dragging_destination_drag_accepted_notification();
        /// @brief Value of the SDK constant `NSAccessibilityDraggingDestinationDragNotAcceptedNotification`.
        static std::string accessibility_dragging_destination_drag_not_accepted_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedCellsChangedNotification`.
        static std::string accessibility_selected_cells_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilityUnitsChangedNotification`.
        static std::string accessibility_units_changed_notification();
        /// @brief Value of the SDK constant `NSAccessibilitySelectedChildrenMovedNotification`.
        static std::string accessibility_selected_children_moved_notification();
        /// @brief Value of the SDK constant `NSAccessibilityAnnouncementRequestedNotification`.
        static std::string accessibility_announcement_requested_notification();
    };

    /** @brief Named constants of type `NSAccessibilityRole`; each function reads the SDK symbol at runtime. */
    struct AccessibilityRole
    {
        /// @brief Value of the SDK constant `NSAccessibilityUnknownRole`.
        static std::string accessibility_unknown_role();
        /// @brief Value of the SDK constant `NSAccessibilityButtonRole`.
        static std::string accessibility_button_role();
        /// @brief Value of the SDK constant `NSAccessibilityRadioButtonRole`.
        static std::string accessibility_radio_button_role();
        /// @brief Value of the SDK constant `NSAccessibilityCheckBoxRole`.
        static std::string accessibility_check_box_role();
        /// @brief Value of the SDK constant `NSAccessibilitySliderRole`.
        static std::string accessibility_slider_role();
        /// @brief Value of the SDK constant `NSAccessibilityTabGroupRole`.
        static std::string accessibility_tab_group_role();
        /// @brief Value of the SDK constant `NSAccessibilityTextFieldRole`.
        static std::string accessibility_text_field_role();
        /// @brief Value of the SDK constant `NSAccessibilityStaticTextRole`.
        static std::string accessibility_static_text_role();
        /// @brief Value of the SDK constant `NSAccessibilityTextAreaRole`.
        static std::string accessibility_text_area_role();
        /// @brief Value of the SDK constant `NSAccessibilityScrollAreaRole`.
        static std::string accessibility_scroll_area_role();
        /// @brief Value of the SDK constant `NSAccessibilityPopUpButtonRole`.
        static std::string accessibility_pop_up_button_role();
        /// @brief Value of the SDK constant `NSAccessibilityMenuButtonRole`.
        static std::string accessibility_menu_button_role();
        /// @brief Value of the SDK constant `NSAccessibilityTableRole`.
        static std::string accessibility_table_role();
        /// @brief Value of the SDK constant `NSAccessibilityApplicationRole`.
        static std::string accessibility_application_role();
        /// @brief Value of the SDK constant `NSAccessibilityGroupRole`.
        static std::string accessibility_group_role();
        /// @brief Value of the SDK constant `NSAccessibilityRadioGroupRole`.
        static std::string accessibility_radio_group_role();
        /// @brief Value of the SDK constant `NSAccessibilityListRole`.
        static std::string accessibility_list_role();
        /// @brief Value of the SDK constant `NSAccessibilityScrollBarRole`.
        static std::string accessibility_scroll_bar_role();
        /// @brief Value of the SDK constant `NSAccessibilityValueIndicatorRole`.
        static std::string accessibility_value_indicator_role();
        /// @brief Value of the SDK constant `NSAccessibilityImageRole`.
        static std::string accessibility_image_role();
        /// @brief Value of the SDK constant `NSAccessibilityMenuBarRole`.
        static std::string accessibility_menu_bar_role();
        /// @brief Value of the SDK constant `NSAccessibilityMenuBarItemRole`.
        static std::string accessibility_menu_bar_item_role();
        /// @brief Value of the SDK constant `NSAccessibilityMenuRole`.
        static std::string accessibility_menu_role();
        /// @brief Value of the SDK constant `NSAccessibilityMenuItemRole`.
        static std::string accessibility_menu_item_role();
        /// @brief Value of the SDK constant `NSAccessibilityColumnRole`.
        static std::string accessibility_column_role();
        /// @brief Value of the SDK constant `NSAccessibilityRowRole`.
        static std::string accessibility_row_role();
        /// @brief Value of the SDK constant `NSAccessibilityToolbarRole`.
        static std::string accessibility_toolbar_role();
        /// @brief Value of the SDK constant `NSAccessibilityBusyIndicatorRole`.
        static std::string accessibility_busy_indicator_role();
        /// @brief Value of the SDK constant `NSAccessibilityProgressIndicatorRole`.
        static std::string accessibility_progress_indicator_role();
        /// @brief Value of the SDK constant `NSAccessibilityWindowRole`.
        static std::string accessibility_window_role();
        /// @brief Value of the SDK constant `NSAccessibilityDrawerRole`.
        static std::string accessibility_drawer_role();
        /// @brief Value of the SDK constant `NSAccessibilitySystemWideRole`.
        static std::string accessibility_system_wide_role();
        /// @brief Value of the SDK constant `NSAccessibilityOutlineRole`.
        static std::string accessibility_outline_role();
        /// @brief Value of the SDK constant `NSAccessibilityIncrementorRole`.
        static std::string accessibility_incrementor_role();
        /// @brief Value of the SDK constant `NSAccessibilityBrowserRole`.
        static std::string accessibility_browser_role();
        /// @brief Value of the SDK constant `NSAccessibilityComboBoxRole`.
        static std::string accessibility_combo_box_role();
        /// @brief Value of the SDK constant `NSAccessibilitySplitGroupRole`.
        static std::string accessibility_split_group_role();
        /// @brief Value of the SDK constant `NSAccessibilitySplitterRole`.
        static std::string accessibility_splitter_role();
        /// @brief Value of the SDK constant `NSAccessibilityColorWellRole`.
        static std::string accessibility_color_well_role();
        /// @brief Value of the SDK constant `NSAccessibilityGrowAreaRole`.
        static std::string accessibility_grow_area_role();
        /// @brief Value of the SDK constant `NSAccessibilitySheetRole`.
        static std::string accessibility_sheet_role();
        /// @brief Value of the SDK constant `NSAccessibilityHelpTagRole`.
        static std::string accessibility_help_tag_role();
        /// @brief Value of the SDK constant `NSAccessibilityMatteRole`.
        static std::string accessibility_matte_role();
        /// @brief Value of the SDK constant `NSAccessibilityRulerRole`.
        static std::string accessibility_ruler_role();
        /// @brief Value of the SDK constant `NSAccessibilityRulerMarkerRole`.
        static std::string accessibility_ruler_marker_role();
        /// @brief Value of the SDK constant `NSAccessibilityLinkRole`.
        static std::string accessibility_link_role();
        /// @brief Value of the SDK constant `NSAccessibilityDisclosureTriangleRole`.
        static std::string accessibility_disclosure_triangle_role();
        /// @brief Value of the SDK constant `NSAccessibilityGridRole`.
        static std::string accessibility_grid_role();
        /// @brief Value of the SDK constant `NSAccessibilityRelevanceIndicatorRole`.
        static std::string accessibility_relevance_indicator_role();
        /// @brief Value of the SDK constant `NSAccessibilityDateTimeAreaRole`.
        static std::string accessibility_date_time_area_role();
        /// @brief Value of the SDK constant `NSAccessibilityLevelIndicatorRole`.
        static std::string accessibility_level_indicator_role();
        /// @brief Value of the SDK constant `NSAccessibilityCellRole`.
        static std::string accessibility_cell_role();
        /// @brief Value of the SDK constant `NSAccessibilityPopoverRole`.
        static std::string accessibility_popover_role();
        /// @brief Value of the SDK constant `NSAccessibilityPageRole`.
        static std::string accessibility_page_role();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingRole`.
        static std::string accessibility_heading_role();
        /// @brief Value of the SDK constant `NSAccessibilityListMarkerRole`.
        static std::string accessibility_list_marker_role();
        /// @brief Value of the SDK constant `NSAccessibilityWebAreaRole`.
        static std::string accessibility_web_area_role();
        /// @brief Value of the SDK constant `NSAccessibilityLayoutAreaRole`.
        static std::string accessibility_layout_area_role();
        /// @brief Value of the SDK constant `NSAccessibilityLayoutItemRole`.
        static std::string accessibility_layout_item_role();
        /// @brief Value of the SDK constant `NSAccessibilityHandleRole`.
        static std::string accessibility_handle_role();
    };

    /** @brief Named constants of type `NSAccessibilitySubrole`; each function reads the SDK symbol at runtime. */
    struct AccessibilitySubrole
    {
        /// @brief Value of the SDK constant `NSAccessibilityUnknownSubrole`.
        static std::string accessibility_unknown_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityCloseButtonSubrole`.
        static std::string accessibility_close_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityZoomButtonSubrole`.
        static std::string accessibility_zoom_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityMinimizeButtonSubrole`.
        static std::string accessibility_minimize_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityToolbarButtonSubrole`.
        static std::string accessibility_toolbar_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityTableRowSubrole`.
        static std::string accessibility_table_row_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityOutlineRowSubrole`.
        static std::string accessibility_outline_row_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySecureTextFieldSubrole`.
        static std::string accessibility_secure_text_field_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityStandardWindowSubrole`.
        static std::string accessibility_standard_window_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityDialogSubrole`.
        static std::string accessibility_dialog_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySystemDialogSubrole`.
        static std::string accessibility_system_dialog_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityFloatingWindowSubrole`.
        static std::string accessibility_floating_window_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySystemFloatingWindowSubrole`.
        static std::string accessibility_system_floating_window_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityIncrementArrowSubrole`.
        static std::string accessibility_increment_arrow_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityDecrementArrowSubrole`.
        static std::string accessibility_decrement_arrow_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityIncrementPageSubrole`.
        static std::string accessibility_increment_page_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityDecrementPageSubrole`.
        static std::string accessibility_decrement_page_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySearchFieldSubrole`.
        static std::string accessibility_search_field_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityTextAttachmentSubrole`.
        static std::string accessibility_text_attachment_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityTextLinkSubrole`.
        static std::string accessibility_text_link_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityTimelineSubrole`.
        static std::string accessibility_timeline_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySortButtonSubrole`.
        static std::string accessibility_sort_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityRatingIndicatorSubrole`.
        static std::string accessibility_rating_indicator_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityContentListSubrole`.
        static std::string accessibility_content_list_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityDefinitionListSubrole`.
        static std::string accessibility_definition_list_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityFullScreenButtonSubrole`.
        static std::string accessibility_full_screen_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityToggleSubrole`.
        static std::string accessibility_toggle_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySwitchSubrole`.
        static std::string accessibility_switch_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityDescriptionListSubrole`.
        static std::string accessibility_description_list_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityTabButtonSubrole`.
        static std::string accessibility_tab_button_subrole();
        /// @brief Value of the SDK constant `NSAccessibilityCollectionListSubrole`.
        static std::string accessibility_collection_list_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySectionListSubrole`.
        static std::string accessibility_section_list_subrole();
        /// @brief Value of the SDK constant `NSAccessibilitySuggestionSubrole`.
        static std::string accessibility_suggestion_subrole();
    };

    /** @brief Named constants of type `NSAccessibilityNotificationUserInfoKey`; each function reads the SDK symbol at runtime. */
    struct AccessibilityNotificationUserInfoKey
    {
        /// @brief Value of the SDK constant `NSAccessibilityUIElementsKey`.
        static std::string accessibility_ui_elements_key();
        /// @brief Value of the SDK constant `NSAccessibilityPriorityKey`.
        static std::string accessibility_priority_key();
        /// @brief Value of the SDK constant `NSAccessibilityAnnouncementKey`.
        static std::string accessibility_announcement_key();
    };

    /** @brief Named constants of type `NSAccessibilitySearchKey`; each function reads the SDK symbol at runtime. */
    struct AccessibilitySearchKey
    {
        /// @brief Value of the SDK constant `NSAccessibilityAnyTypeSearchKey`.
        static std::string accessibility_any_type_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityArticleSearchKey`.
        static std::string accessibility_article_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityBlockquoteSameLevelSearchKey`.
        static std::string accessibility_blockquote_same_level_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityBlockquoteSearchKey`.
        static std::string accessibility_blockquote_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityBoldFontSearchKey`.
        static std::string accessibility_bold_font_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityButtonSearchKey`.
        static std::string accessibility_button_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityCheckBoxSearchKey`.
        static std::string accessibility_check_box_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityControlSearchKey`.
        static std::string accessibility_control_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityDifferentTypeSearchKey`.
        static std::string accessibility_different_type_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityFontChangeSearchKey`.
        static std::string accessibility_font_change_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityFontColorChangeSearchKey`.
        static std::string accessibility_font_color_change_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityFrameSearchKey`.
        static std::string accessibility_frame_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityGraphicSearchKey`.
        static std::string accessibility_graphic_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel1SearchKey`.
        static std::string accessibility_heading_level1_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel2SearchKey`.
        static std::string accessibility_heading_level2_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel3SearchKey`.
        static std::string accessibility_heading_level3_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel4SearchKey`.
        static std::string accessibility_heading_level4_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel5SearchKey`.
        static std::string accessibility_heading_level5_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingLevel6SearchKey`.
        static std::string accessibility_heading_level6_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingSameLevelSearchKey`.
        static std::string accessibility_heading_same_level_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityHeadingSearchKey`.
        static std::string accessibility_heading_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityItalicFontSearchKey`.
        static std::string accessibility_italic_font_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityKeyboardFocusableSearchKey`.
        static std::string accessibility_keyboard_focusable_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityLandmarkSearchKey`.
        static std::string accessibility_landmark_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityLinkSearchKey`.
        static std::string accessibility_link_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityListSearchKey`.
        static std::string accessibility_list_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityLiveRegionSearchKey`.
        static std::string accessibility_live_region_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityMisspelledWordSearchKey`.
        static std::string accessibility_misspelled_word_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityOutlineSearchKey`.
        static std::string accessibility_outline_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityPlainTextSearchKey`.
        static std::string accessibility_plain_text_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityRadioGroupSearchKey`.
        static std::string accessibility_radio_group_search_key();
        /// @brief Value of the SDK constant `NSAccessibilitySameTypeSearchKey`.
        static std::string accessibility_same_type_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityStaticTextSearchKey`.
        static std::string accessibility_static_text_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityStyleChangeSearchKey`.
        static std::string accessibility_style_change_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityTableSameLevelSearchKey`.
        static std::string accessibility_table_same_level_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityTableSearchKey`.
        static std::string accessibility_table_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityTextFieldSearchKey`.
        static std::string accessibility_text_field_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityTextStateChangeTypeKey`.
        static std::string accessibility_text_state_change_type_key();
        /// @brief Value of the SDK constant `NSAccessibilityTextStateSyncKey`.
        static std::string accessibility_text_state_sync_key();
        /// @brief Value of the SDK constant `NSAccessibilityUnderlineSearchKey`.
        static std::string accessibility_underline_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityUnvisitedLinkSearchKey`.
        static std::string accessibility_unvisited_link_search_key();
        /// @brief Value of the SDK constant `NSAccessibilityVisitedLinkSearchKey`.
        static std::string accessibility_visited_link_search_key();
    };

    /** @brief Named constants of type `NSViewAnimationKey`; each function reads the SDK symbol at runtime. */
    struct ViewAnimationKey
    {
        /// @brief Value of the SDK constant `NSViewAnimationTargetKey`.
        static std::string view_animation_target_key();
        /// @brief Value of the SDK constant `NSViewAnimationStartFrameKey`.
        static std::string view_animation_start_frame_key();
        /// @brief Value of the SDK constant `NSViewAnimationEndFrameKey`.
        static std::string view_animation_end_frame_key();
        /// @brief Value of the SDK constant `NSViewAnimationEffectKey`.
        static std::string view_animation_effect_key();
    };

    /** @brief Named constants of type `NSViewAnimationEffectName`; each function reads the SDK symbol at runtime. */
    struct ViewAnimationEffectName
    {
        /// @brief Value of the SDK constant `NSViewAnimationFadeInEffect`.
        static std::string view_animation_fade_in_effect();
        /// @brief Value of the SDK constant `NSViewAnimationFadeOutEffect`.
        static std::string view_animation_fade_out_effect();
    };

    /** @brief Named constants of type `NSAnimatablePropertyKey`; each function reads the SDK symbol at runtime. */
    struct AnimatablePropertyKey
    {
        /// @brief Value of the SDK constant `NSAnimationTriggerOrderIn`.
        static std::string animation_trigger_order_in();
        /// @brief Value of the SDK constant `NSAnimationTriggerOrderOut`.
        static std::string animation_trigger_order_out();
    };

    /** @brief Named constants of type `NSAppearanceName`; each function reads the SDK symbol at runtime. */
    struct AppearanceName
    {
        /// @brief Value of the SDK constant `NSAppearanceNameAqua`.
        static std::string aqua();
        /// @brief Value of the SDK constant `NSAppearanceNameDarkAqua`.
        static std::string dark_aqua();
        /// @brief Value of the SDK constant `NSAppearanceNameVibrantDark`.
        static std::string vibrant_dark();
        /// @brief Value of the SDK constant `NSAppearanceNameVibrantLight`.
        static std::string vibrant_light();
        /// @brief Value of the SDK constant `NSAppearanceNameAccessibilityHighContrastAqua`.
        static std::string accessibility_high_contrast_aqua();
        /// @brief Value of the SDK constant `NSAppearanceNameAccessibilityHighContrastDarkAqua`.
        static std::string accessibility_high_contrast_dark_aqua();
        /// @brief Value of the SDK constant `NSAppearanceNameAccessibilityHighContrastVibrantLight`.
        static std::string accessibility_high_contrast_vibrant_light();
        /// @brief Value of the SDK constant `NSAppearanceNameAccessibilityHighContrastVibrantDark`.
        static std::string accessibility_high_contrast_vibrant_dark();
    };

    /** @brief Named constants of type `NSAppKitVersion`; each function reads the SDK symbol at runtime. */
    struct AppKitVersion
    {
        /// @brief Value of the SDK constant `NSAppKitVersionNumber`.
        static double number();
    };

    /** @brief Named constants of type `NSRunLoopMode`; each function reads the SDK symbol at runtime. */
    struct RunLoopMode
    {
        /// @brief Value of the SDK constant `NSModalPanelRunLoopMode`.
        static std::string modal_panel_run_loop_mode();
        /// @brief Value of the SDK constant `NSEventTrackingRunLoopMode`.
        static std::string event_tracking_run_loop_mode();
        /// @brief Value of the SDK constant `NSDefaultRunLoopMode`.
        static std::string default_run_loop_mode();
        /// @brief Value of the SDK constant `NSRunLoopCommonModes`.
        static std::string run_loop_common_modes();
    };

    /** @brief Named constants of type `NSAboutPanelOptionKey`; each function reads the SDK symbol at runtime. */
    struct AboutPanelOptionKey
    {
        /// @brief Value of the SDK constant `NSAboutPanelOptionCredits`.
        static std::string about_panel_option_credits();
        /// @brief Value of the SDK constant `NSAboutPanelOptionApplicationName`.
        static std::string about_panel_option_application_name();
        /// @brief Value of the SDK constant `NSAboutPanelOptionApplicationIcon`.
        static std::string about_panel_option_application_icon();
        /// @brief Value of the SDK constant `NSAboutPanelOptionVersion`.
        static std::string about_panel_option_version();
        /// @brief Value of the SDK constant `NSAboutPanelOptionApplicationVersion`.
        static std::string about_panel_option_application_version();
    };

    /** @brief Named constants of type `NSTextEffectStyle`; each function reads the SDK symbol at runtime. */
    struct TextEffectStyle
    {
        /// @brief Value of the SDK constant `NSTextEffectLetterpressStyle`.
        static std::string text_effect_letterpress_style();
    };

    /** @brief Named constants of type `NSTextHighlightStyle`; each function reads the SDK symbol at runtime. */
    struct TextHighlightStyle
    {
        /// @brief Value of the SDK constant `NSTextHighlightStyleDefault`.
        static std::string default_();
    };

    /** @brief Named constants of type `NSTextHighlightColorScheme`; each function reads the SDK symbol at runtime. */
    struct TextHighlightColorScheme
    {
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemeDefault`.
        static std::string default_();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemePurple`.
        static std::string purple();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemePink`.
        static std::string pink();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemeOrange`.
        static std::string orange();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemeMint`.
        static std::string mint();
        /// @brief Value of the SDK constant `NSTextHighlightColorSchemeBlue`.
        static std::string blue();
    };

    /** @brief Named constants of type `NSAttributedStringDocumentType`; each function reads the SDK symbol at runtime. */
    struct AttributedStringDocumentType
    {
        /// @brief Value of the SDK constant `NSPlainTextDocumentType`.
        static std::string plain_text_document_type();
        /// @brief Value of the SDK constant `NSRTFTextDocumentType`.
        static std::string rtf_text_document_type();
        /// @brief Value of the SDK constant `NSRTFDTextDocumentType`.
        static std::string rtfd_text_document_type();
        /// @brief Value of the SDK constant `NSHTMLTextDocumentType`.
        static std::string html_text_document_type();
        /// @brief Value of the SDK constant `NSMacSimpleTextDocumentType`.
        static std::string mac_simple_text_document_type();
        /// @brief Value of the SDK constant `NSDocFormatTextDocumentType`.
        static std::string doc_format_text_document_type();
        /// @brief Value of the SDK constant `NSWordMLTextDocumentType`.
        static std::string word_ml_text_document_type();
        /// @brief Value of the SDK constant `NSWebArchiveTextDocumentType`.
        static std::string web_archive_text_document_type();
        /// @brief Value of the SDK constant `NSOfficeOpenXMLTextDocumentType`.
        static std::string office_open_xml_text_document_type();
        /// @brief Value of the SDK constant `NSOpenDocumentTextDocumentType`.
        static std::string open_document_text_document_type();
    };

    /** @brief Named constants of type `NSTextLayoutSectionKey`; each function reads the SDK symbol at runtime. */
    struct TextLayoutSectionKey
    {
        /// @brief Value of the SDK constant `NSTextLayoutSectionOrientation`.
        static std::string text_layout_section_orientation();
        /// @brief Value of the SDK constant `NSTextLayoutSectionRange`.
        static std::string text_layout_section_range();
    };

    /** @brief Named constants of type `NSAttributedStringDocumentAttributeKey`; each function reads the SDK symbol at runtime. */
    struct AttributedStringDocumentAttributeKey
    {
        /// @brief Value of the SDK constant `NSDocumentTypeDocumentAttribute`.
        static std::string document_type_document_attribute();
        /// @brief Value of the SDK constant `NSCharacterEncodingDocumentAttribute`.
        static std::string character_encoding_document_attribute();
        /// @brief Value of the SDK constant `NSDefaultAttributesDocumentAttribute`.
        static std::string default_attributes_document_attribute();
        /// @brief Value of the SDK constant `NSPaperSizeDocumentAttribute`.
        static std::string paper_size_document_attribute();
        /// @brief Value of the SDK constant `NSViewSizeDocumentAttribute`.
        static std::string view_size_document_attribute();
        /// @brief Value of the SDK constant `NSViewZoomDocumentAttribute`.
        static std::string view_zoom_document_attribute();
        /// @brief Value of the SDK constant `NSViewModeDocumentAttribute`.
        static std::string view_mode_document_attribute();
        /// @brief Value of the SDK constant `NSDefaultFontExcludedDocumentAttribute`.
        static std::string default_font_excluded_document_attribute();
        /// @brief Value of the SDK constant `NSReadOnlyDocumentAttribute`.
        static std::string read_only_document_attribute();
        /// @brief Value of the SDK constant `NSBackgroundColorDocumentAttribute`.
        static std::string background_color_document_attribute();
        /// @brief Value of the SDK constant `NSHyphenationFactorDocumentAttribute`.
        static std::string hyphenation_factor_document_attribute();
        /// @brief Value of the SDK constant `NSDefaultTabIntervalDocumentAttribute`.
        static std::string default_tab_interval_document_attribute();
        /// @brief Value of the SDK constant `NSTextLayoutSectionsAttribute`.
        static std::string text_layout_sections_attribute();
        /// @brief Value of the SDK constant `NSTextScalingDocumentAttribute`.
        static std::string text_scaling_document_attribute();
        /// @brief Value of the SDK constant `NSSourceTextScalingDocumentAttribute`.
        static std::string source_text_scaling_document_attribute();
        /// @brief Value of the SDK constant `NSCocoaVersionDocumentAttribute`.
        static std::string cocoa_version_document_attribute();
        /// @brief Value of the SDK constant `NSPaperMarginDocumentAttribute`.
        static std::string paper_margin_document_attribute();
        /// @brief Value of the SDK constant `NSConvertedDocumentAttribute`.
        static std::string converted_document_attribute();
        /// @brief Value of the SDK constant `NSFileTypeDocumentAttribute`.
        static std::string file_type_document_attribute();
        /// @brief Value of the SDK constant `NSTitleDocumentAttribute`.
        static std::string title_document_attribute();
        /// @brief Value of the SDK constant `NSCompanyDocumentAttribute`.
        static std::string company_document_attribute();
        /// @brief Value of the SDK constant `NSCopyrightDocumentAttribute`.
        static std::string copyright_document_attribute();
        /// @brief Value of the SDK constant `NSSubjectDocumentAttribute`.
        static std::string subject_document_attribute();
        /// @brief Value of the SDK constant `NSAuthorDocumentAttribute`.
        static std::string author_document_attribute();
        /// @brief Value of the SDK constant `NSKeywordsDocumentAttribute`.
        static std::string keywords_document_attribute();
        /// @brief Value of the SDK constant `NSCommentDocumentAttribute`.
        static std::string comment_document_attribute();
        /// @brief Value of the SDK constant `NSEditorDocumentAttribute`.
        static std::string editor_document_attribute();
        /// @brief Value of the SDK constant `NSCreationTimeDocumentAttribute`.
        static std::string creation_time_document_attribute();
        /// @brief Value of the SDK constant `NSModificationTimeDocumentAttribute`.
        static std::string modification_time_document_attribute();
        /// @brief Value of the SDK constant `NSManagerDocumentAttribute`.
        static std::string manager_document_attribute();
        /// @brief Value of the SDK constant `NSCategoryDocumentAttribute`.
        static std::string category_document_attribute();
        /// @brief Value of the SDK constant `NSAppearanceDocumentAttribute`.
        static std::string appearance_document_attribute();
        /// @brief Value of the SDK constant `NSExcludedElementsDocumentAttribute`.
        static std::string excluded_elements_document_attribute();
        /// @brief Value of the SDK constant `NSTextEncodingNameDocumentAttribute`.
        static std::string text_encoding_name_document_attribute();
        /// @brief Value of the SDK constant `NSPrefixSpacesDocumentAttribute`.
        static std::string prefix_spaces_document_attribute();
        /// @brief Value of the SDK constant `NSLeftMarginDocumentAttribute`.
        static std::string left_margin_document_attribute();
        /// @brief Value of the SDK constant `NSRightMarginDocumentAttribute`.
        static std::string right_margin_document_attribute();
        /// @brief Value of the SDK constant `NSTopMarginDocumentAttribute`.
        static std::string top_margin_document_attribute();
        /// @brief Value of the SDK constant `NSBottomMarginDocumentAttribute`.
        static std::string bottom_margin_document_attribute();
    };

    /** @brief Named constants of type `NSAttributedStringDocumentReadingOptionKey`; each function reads the SDK symbol at runtime. */
    struct AttributedStringDocumentReadingOptionKey
    {
        /// @brief Value of the SDK constant `NSDocumentTypeDocumentOption`.
        static std::string document_type_document_option();
        /// @brief Value of the SDK constant `NSDefaultAttributesDocumentOption`.
        static std::string default_attributes_document_option();
        /// @brief Value of the SDK constant `NSCharacterEncodingDocumentOption`.
        static std::string character_encoding_document_option();
        /// @brief Value of the SDK constant `NSTargetTextScalingDocumentOption`.
        static std::string target_text_scaling_document_option();
        /// @brief Value of the SDK constant `NSSourceTextScalingDocumentOption`.
        static std::string source_text_scaling_document_option();
        /// @brief Value of the SDK constant `NSTextKit1ListMarkerFormatDocumentOption`.
        static std::string text_kit1_list_marker_format_document_option();
        /// @brief Value of the SDK constant `NSTextEncodingNameDocumentOption`.
        static std::string text_encoding_name_document_option();
        /// @brief Value of the SDK constant `NSBaseURLDocumentOption`.
        static std::string base_url_document_option();
        /// @brief Value of the SDK constant `NSTimeoutDocumentOption`.
        static std::string timeout_document_option();
        /// @brief Value of the SDK constant `NSWebPreferencesDocumentOption`.
        static std::string web_preferences_document_option();
        /// @brief Value of the SDK constant `NSWebResourceLoadDelegateDocumentOption`.
        static std::string web_resource_load_delegate_document_option();
        /// @brief Value of the SDK constant `NSTextSizeMultiplierDocumentOption`.
        static std::string text_size_multiplier_document_option();
        /// @brief Value of the SDK constant `NSFileTypeDocumentOption`.
        static std::string file_type_document_option();
    };

    /** @brief Named constants of type `NSBitmapImageRepPropertyKey`; each function reads the SDK symbol at runtime. */
    struct BitmapImageRepPropertyKey
    {
        /// @brief Value of the SDK constant `NSImageCompressionMethod`.
        static std::string image_compression_method();
        /// @brief Value of the SDK constant `NSImageCompressionFactor`.
        static std::string image_compression_factor();
        /// @brief Value of the SDK constant `NSImageDitherTransparency`.
        static std::string image_dither_transparency();
        /// @brief Value of the SDK constant `NSImageRGBColorTable`.
        static std::string image_rgb_color_table();
        /// @brief Value of the SDK constant `NSImageInterlaced`.
        static std::string image_interlaced();
        /// @brief Value of the SDK constant `NSImageColorSyncProfileData`.
        static std::string image_color_sync_profile_data();
        /// @brief Value of the SDK constant `NSImageFrameCount`.
        static std::string image_frame_count();
        /// @brief Value of the SDK constant `NSImageCurrentFrame`.
        static std::string image_current_frame();
        /// @brief Value of the SDK constant `NSImageCurrentFrameDuration`.
        static std::string image_current_frame_duration();
        /// @brief Value of the SDK constant `NSImageLoopCount`.
        static std::string image_loop_count();
        /// @brief Value of the SDK constant `NSImageGamma`.
        static std::string image_gamma();
        /// @brief Value of the SDK constant `NSImageProgressive`.
        static std::string image_progressive();
        /// @brief Value of the SDK constant `NSImageEXIFData`.
        static std::string image_exif_data();
        /// @brief Value of the SDK constant `NSImageIPTCData`.
        static std::string image_iptc_data();
        /// @brief Value of the SDK constant `NSImageFallbackBackgroundColor`.
        static std::string image_fallback_background_color();
    };

    /** @brief Named constants of type `NSTouchBarItemIdentifier`; each function reads the SDK symbol at runtime. */
    struct TouchBarItemIdentifier
    {
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierCandidateList`.
        static std::string candidate_list();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierCharacterPicker`.
        static std::string character_picker();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierTextColorPicker`.
        static std::string text_color_picker();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierTextStyle`.
        static std::string text_style();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierTextAlignment`.
        static std::string text_alignment();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierTextList`.
        static std::string text_list();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierTextFormat`.
        static std::string text_format();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierFixedSpaceSmall`.
        static std::string fixed_space_small();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierFixedSpaceLarge`.
        static std::string fixed_space_large();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierFlexibleSpace`.
        static std::string flexible_space();
        /// @brief Value of the SDK constant `NSTouchBarItemIdentifierOtherItemsProxy`.
        static std::string other_items_proxy();
    };

    /** @brief Named constants of type `NSCollectionViewSupplementaryElementKind`; each function reads the SDK symbol at runtime. */
    struct CollectionViewSupplementaryElementKind
    {
        /// @brief Value of the SDK constant `NSCollectionElementKindSectionHeader`.
        static std::string collection_element_kind_section_header();
        /// @brief Value of the SDK constant `NSCollectionElementKindSectionFooter`.
        static std::string collection_element_kind_section_footer();
        /// @brief Value of the SDK constant `NSCollectionElementKindInterItemGapIndicator`.
        static std::string collection_element_kind_inter_item_gap_indicator();
    };

    /** @brief Named constants of type `NSDraggingImageComponentKey`; each function reads the SDK symbol at runtime. */
    struct DraggingImageComponentKey
    {
        /// @brief Value of the SDK constant `NSDraggingImageComponentIconKey`.
        static std::string dragging_image_component_icon_key();
        /// @brief Value of the SDK constant `NSDraggingImageComponentLabelKey`.
        static std::string dragging_image_component_label_key();
    };

    /** @brief Named constants of type `NSExceptionName`; each function reads the SDK symbol at runtime. */
    struct ExceptionName
    {
        /// @brief Value of the SDK constant `NSTextLineTooLongException`.
        static std::string text_line_too_long_exception();
        /// @brief Value of the SDK constant `NSTextNoSelectionException`.
        static std::string text_no_selection_exception();
        /// @brief Value of the SDK constant `NSWordTablesWriteException`.
        static std::string word_tables_write_exception();
        /// @brief Value of the SDK constant `NSWordTablesReadException`.
        static std::string word_tables_read_exception();
        /// @brief Value of the SDK constant `NSTextReadException`.
        static std::string text_read_exception();
        /// @brief Value of the SDK constant `NSTextWriteException`.
        static std::string text_write_exception();
        /// @brief Value of the SDK constant `NSPasteboardCommunicationException`.
        static std::string pasteboard_communication_exception();
        /// @brief Value of the SDK constant `NSPrintingCommunicationException`.
        static std::string printing_communication_exception();
        /// @brief Value of the SDK constant `NSAbortModalException`.
        static std::string abort_modal_exception();
        /// @brief Value of the SDK constant `NSAbortPrintingException`.
        static std::string abort_printing_exception();
        /// @brief Value of the SDK constant `NSIllegalSelectorException`.
        static std::string illegal_selector_exception();
        /// @brief Value of the SDK constant `NSAppKitVirtualMemoryException`.
        static std::string app_kit_virtual_memory_exception();
        /// @brief Value of the SDK constant `NSBadRTFDirectiveException`.
        static std::string bad_rtf_directive_exception();
        /// @brief Value of the SDK constant `NSBadRTFFontTableException`.
        static std::string bad_rtf_font_table_exception();
        /// @brief Value of the SDK constant `NSBadRTFStyleSheetException`.
        static std::string bad_rtf_style_sheet_exception();
        /// @brief Value of the SDK constant `NSTypedStreamVersionException`.
        static std::string typed_stream_version_exception();
        /// @brief Value of the SDK constant `NSTIFFException`.
        static std::string tiff_exception();
        /// @brief Value of the SDK constant `NSPrintPackageException`.
        static std::string print_package_exception();
        /// @brief Value of the SDK constant `NSBadRTFColorTableException`.
        static std::string bad_rtf_color_table_exception();
        /// @brief Value of the SDK constant `NSDraggingException`.
        static std::string dragging_exception();
        /// @brief Value of the SDK constant `NSColorListIOException`.
        static std::string color_list_io_exception();
        /// @brief Value of the SDK constant `NSColorListNotEditableException`.
        static std::string color_list_not_editable_exception();
        /// @brief Value of the SDK constant `NSBadBitmapParametersException`.
        static std::string bad_bitmap_parameters_exception();
        /// @brief Value of the SDK constant `NSWindowServerCommunicationException`.
        static std::string window_server_communication_exception();
        /// @brief Value of the SDK constant `NSFontUnavailableException`.
        static std::string font_unavailable_exception();
        /// @brief Value of the SDK constant `NSPPDIncludeNotFoundException`.
        static std::string ppd_include_not_found_exception();
        /// @brief Value of the SDK constant `NSPPDParseException`.
        static std::string ppd_parse_exception();
        /// @brief Value of the SDK constant `NSPPDIncludeStackOverflowException`.
        static std::string ppd_include_stack_overflow_exception();
        /// @brief Value of the SDK constant `NSPPDIncludeStackUnderflowException`.
        static std::string ppd_include_stack_underflow_exception();
        /// @brief Value of the SDK constant `NSRTFPropertyStackOverflowException`.
        static std::string rtf_property_stack_overflow_exception();
        /// @brief Value of the SDK constant `NSAppKitIgnoredException`.
        static std::string app_kit_ignored_exception();
        /// @brief Value of the SDK constant `NSBadComparisonException`.
        static std::string bad_comparison_exception();
        /// @brief Value of the SDK constant `NSImageCacheException`.
        static std::string image_cache_exception();
        /// @brief Value of the SDK constant `NSNibLoadingException`.
        static std::string nib_loading_exception();
        /// @brief Value of the SDK constant `NSBrowserIllegalDelegateException`.
        static std::string browser_illegal_delegate_exception();
        /// @brief Value of the SDK constant `NSPrintOperationExistsException`.
        static std::string print_operation_exists_exception();
        /// @brief Value of the SDK constant `NSDecimalNumberExactnessException`.
        static std::string decimal_number_exactness_exception();
        /// @brief Value of the SDK constant `NSDecimalNumberOverflowException`.
        static std::string decimal_number_overflow_exception();
        /// @brief Value of the SDK constant `NSDecimalNumberUnderflowException`.
        static std::string decimal_number_underflow_exception();
        /// @brief Value of the SDK constant `NSDecimalNumberDivideByZeroException`.
        static std::string decimal_number_divide_by_zero_exception();
        /// @brief Value of the SDK constant `NSGenericException`.
        static std::string generic_exception();
        /// @brief Value of the SDK constant `NSRangeException`.
        static std::string range_exception();
        /// @brief Value of the SDK constant `NSInvalidArgumentException`.
        static std::string invalid_argument_exception();
        /// @brief Value of the SDK constant `NSInternalInconsistencyException`.
        static std::string internal_inconsistency_exception();
        /// @brief Value of the SDK constant `NSMallocException`.
        static std::string malloc_exception();
        /// @brief Value of the SDK constant `NSObjectInaccessibleException`.
        static std::string object_inaccessible_exception();
        /// @brief Value of the SDK constant `NSObjectNotAvailableException`.
        static std::string object_not_available_exception();
        /// @brief Value of the SDK constant `NSDestinationInvalidException`.
        static std::string destination_invalid_exception();
        /// @brief Value of the SDK constant `NSPortTimeoutException`.
        static std::string port_timeout_exception();
        /// @brief Value of the SDK constant `NSInvalidSendPortException`.
        static std::string invalid_send_port_exception();
        /// @brief Value of the SDK constant `NSInvalidReceivePortException`.
        static std::string invalid_receive_port_exception();
        /// @brief Value of the SDK constant `NSPortSendException`.
        static std::string port_send_exception();
        /// @brief Value of the SDK constant `NSPortReceiveException`.
        static std::string port_receive_exception();
        /// @brief Value of the SDK constant `NSOldStyleException`.
        static std::string old_style_exception();
        /// @brief Value of the SDK constant `NSInconsistentArchiveException`.
        static std::string inconsistent_archive_exception();
        /// @brief Value of the SDK constant `NSFileHandleOperationException`.
        static std::string file_handle_operation_exception();
        /// @brief Value of the SDK constant `NSUndefinedKeyException`.
        static std::string undefined_key_exception();
        /// @brief Value of the SDK constant `NSInvalidArchiveOperationException`.
        static std::string invalid_archive_operation_exception();
        /// @brief Value of the SDK constant `NSInvalidUnarchiveOperationException`.
        static std::string invalid_unarchive_operation_exception();
        /// @brief Value of the SDK constant `NSInvocationOperationVoidResultException`.
        static std::string invocation_operation_void_result_exception();
        /// @brief Value of the SDK constant `NSInvocationOperationCancelledException`.
        static std::string invocation_operation_cancelled_exception();
        /// @brief Value of the SDK constant `NSCharacterConversionException`.
        static std::string character_conversion_exception();
        /// @brief Value of the SDK constant `NSParseErrorException`.
        static std::string parse_error_exception();
    };

    /** @brief Named constants of type `NSFontCollectionMatchingOptionKey`; each function reads the SDK symbol at runtime. */
    struct FontCollectionMatchingOptionKey
    {
        /// @brief Value of the SDK constant `NSFontCollectionIncludeDisabledFontsOption`.
        static std::string font_collection_include_disabled_fonts_option();
        /// @brief Value of the SDK constant `NSFontCollectionRemoveDuplicatesOption`.
        static std::string font_collection_remove_duplicates_option();
        /// @brief Value of the SDK constant `NSFontCollectionDisallowAutoActivationOption`.
        static std::string font_collection_disallow_auto_activation_option();
    };

    /** @brief Named constants of type `NSFontCollectionUserInfoKey`; each function reads the SDK symbol at runtime. */
    struct FontCollectionUserInfoKey
    {
        /// @brief Value of the SDK constant `NSFontCollectionActionKey`.
        static std::string font_collection_action_key();
        /// @brief Value of the SDK constant `NSFontCollectionNameKey`.
        static std::string font_collection_name_key();
        /// @brief Value of the SDK constant `NSFontCollectionOldNameKey`.
        static std::string font_collection_old_name_key();
        /// @brief Value of the SDK constant `NSFontCollectionVisibilityKey`.
        static std::string font_collection_visibility_key();
    };

    /** @brief Named constants of type `NSFontCollectionActionTypeKey`; each function reads the SDK symbol at runtime. */
    struct FontCollectionActionTypeKey
    {
        /// @brief Value of the SDK constant `NSFontCollectionWasShown`.
        static std::string font_collection_was_shown();
        /// @brief Value of the SDK constant `NSFontCollectionWasHidden`.
        static std::string font_collection_was_hidden();
        /// @brief Value of the SDK constant `NSFontCollectionWasRenamed`.
        static std::string font_collection_was_renamed();
    };

    /** @brief Named constants of type `NSFontCollectionName`; each function reads the SDK symbol at runtime. */
    struct FontCollectionName
    {
        /// @brief Value of the SDK constant `NSFontCollectionAllFonts`.
        static std::string font_collection_all_fonts();
        /// @brief Value of the SDK constant `NSFontCollectionUser`.
        static std::string font_collection_user();
        /// @brief Value of the SDK constant `NSFontCollectionFavorites`.
        static std::string font_collection_favorites();
        /// @brief Value of the SDK constant `NSFontCollectionRecentlyUsed`.
        static std::string font_collection_recently_used();
    };

    /** @brief Named constants of type `NSFontDescriptorAttributeName`; each function reads the SDK symbol at runtime. */
    struct FontDescriptorAttributeName
    {
        /// @brief Value of the SDK constant `NSFontFamilyAttribute`.
        static std::string font_family_attribute();
        /// @brief Value of the SDK constant `NSFontNameAttribute`.
        static std::string font_name_attribute();
        /// @brief Value of the SDK constant `NSFontFaceAttribute`.
        static std::string font_face_attribute();
        /// @brief Value of the SDK constant `NSFontSizeAttribute`.
        static std::string font_size_attribute();
        /// @brief Value of the SDK constant `NSFontVisibleNameAttribute`.
        static std::string font_visible_name_attribute();
        /// @brief Value of the SDK constant `NSFontMatrixAttribute`.
        static std::string font_matrix_attribute();
        /// @brief Value of the SDK constant `NSFontVariationAttribute`.
        static std::string font_variation_attribute();
        /// @brief Value of the SDK constant `NSFontCharacterSetAttribute`.
        static std::string font_character_set_attribute();
        /// @brief Value of the SDK constant `NSFontCascadeListAttribute`.
        static std::string font_cascade_list_attribute();
        /// @brief Value of the SDK constant `NSFontTraitsAttribute`.
        static std::string font_traits_attribute();
        /// @brief Value of the SDK constant `NSFontFixedAdvanceAttribute`.
        static std::string font_fixed_advance_attribute();
        /// @brief Value of the SDK constant `NSFontFeatureSettingsAttribute`.
        static std::string font_feature_settings_attribute();
    };

    /** @brief Named constants of type `NSFontDescriptorTraitKey`; each function reads the SDK symbol at runtime. */
    struct FontDescriptorTraitKey
    {
        /// @brief Value of the SDK constant `NSFontSymbolicTrait`.
        static std::string font_symbolic_trait();
        /// @brief Value of the SDK constant `NSFontWeightTrait`.
        static std::string font_weight_trait();
        /// @brief Value of the SDK constant `NSFontWidthTrait`.
        static std::string font_width_trait();
        /// @brief Value of the SDK constant `NSFontSlantTrait`.
        static std::string font_slant_trait();
    };

    /** @brief Named constants of type `NSFontDescriptorVariationKey`; each function reads the SDK symbol at runtime. */
    struct FontDescriptorVariationKey
    {
        /// @brief Value of the SDK constant `NSFontVariationAxisIdentifierKey`.
        static std::string font_variation_axis_identifier_key();
        /// @brief Value of the SDK constant `NSFontVariationAxisMinimumValueKey`.
        static std::string font_variation_axis_minimum_value_key();
        /// @brief Value of the SDK constant `NSFontVariationAxisMaximumValueKey`.
        static std::string font_variation_axis_maximum_value_key();
        /// @brief Value of the SDK constant `NSFontVariationAxisDefaultValueKey`.
        static std::string font_variation_axis_default_value_key();
        /// @brief Value of the SDK constant `NSFontVariationAxisNameKey`.
        static std::string font_variation_axis_name_key();
    };

    /** @brief Named constants of type `NSFontDescriptorFeatureKey`; each function reads the SDK symbol at runtime. */
    struct FontDescriptorFeatureKey
    {
        /// @brief Value of the SDK constant `NSFontFeatureTypeIdentifierKey`.
        static std::string font_feature_type_identifier_key();
        /// @brief Value of the SDK constant `NSFontFeatureSelectorIdentifierKey`.
        static std::string font_feature_selector_identifier_key();
    };

    /** @brief Named constants of type `NSFontWeight`; each function reads the SDK symbol at runtime. */
    struct FontWeight
    {
        /// @brief Value of the SDK constant `NSFontWeightUltraLight`.
        static double ultra_light();
        /// @brief Value of the SDK constant `NSFontWeightThin`.
        static double thin();
        /// @brief Value of the SDK constant `NSFontWeightLight`.
        static double light();
        /// @brief Value of the SDK constant `NSFontWeightRegular`.
        static double regular();
        /// @brief Value of the SDK constant `NSFontWeightMedium`.
        static double medium();
        /// @brief Value of the SDK constant `NSFontWeightSemibold`.
        static double semibold();
        /// @brief Value of the SDK constant `NSFontWeightBold`.
        static double bold();
        /// @brief Value of the SDK constant `NSFontWeightHeavy`.
        static double heavy();
        /// @brief Value of the SDK constant `NSFontWeightBlack`.
        static double black();
    };

    /** @brief Named constants of type `NSFontWidth`; each function reads the SDK symbol at runtime. */
    struct FontWidth
    {
        /// @brief Value of the SDK constant `NSFontWidthCompressed`.
        static double compressed();
        /// @brief Value of the SDK constant `NSFontWidthCondensed`.
        static double condensed();
        /// @brief Value of the SDK constant `NSFontWidthStandard`.
        static double standard();
        /// @brief Value of the SDK constant `NSFontWidthExpanded`.
        static double expanded();
    };

    /** @brief Named constants of type `NSFontDescriptorSystemDesign`; each function reads the SDK symbol at runtime. */
    struct FontDescriptorSystemDesign
    {
        /// @brief Value of the SDK constant `NSFontDescriptorSystemDesignDefault`.
        static std::string default_();
        /// @brief Value of the SDK constant `NSFontDescriptorSystemDesignSerif`.
        static std::string serif();
        /// @brief Value of the SDK constant `NSFontDescriptorSystemDesignMonospaced`.
        static std::string monospaced();
        /// @brief Value of the SDK constant `NSFontDescriptorSystemDesignRounded`.
        static std::string rounded();
    };

    /** @brief Named constants of type `NSFontTextStyle`; each function reads the SDK symbol at runtime. */
    struct FontTextStyle
    {
        /// @brief Value of the SDK constant `NSFontTextStyleLargeTitle`.
        static std::string large_title();
        /// @brief Value of the SDK constant `NSFontTextStyleTitle1`.
        static std::string title1();
        /// @brief Value of the SDK constant `NSFontTextStyleTitle2`.
        static std::string title2();
        /// @brief Value of the SDK constant `NSFontTextStyleTitle3`.
        static std::string title3();
        /// @brief Value of the SDK constant `NSFontTextStyleHeadline`.
        static std::string headline();
        /// @brief Value of the SDK constant `NSFontTextStyleSubheadline`.
        static std::string subheadline();
        /// @brief Value of the SDK constant `NSFontTextStyleBody`.
        static std::string body();
        /// @brief Value of the SDK constant `NSFontTextStyleCallout`.
        static std::string callout();
        /// @brief Value of the SDK constant `NSFontTextStyleFootnote`.
        static std::string footnote();
        /// @brief Value of the SDK constant `NSFontTextStyleCaption1`.
        static std::string caption1();
        /// @brief Value of the SDK constant `NSFontTextStyleCaption2`.
        static std::string caption2();
    };

    /** @brief Named constants of type `NSColorSpaceName`; each function reads the SDK symbol at runtime. */
    struct ColorSpaceName
    {
        /// @brief Value of the SDK constant `NSCalibratedWhiteColorSpace`.
        static std::string calibrated_white_color_space();
        /// @brief Value of the SDK constant `NSCalibratedRGBColorSpace`.
        static std::string calibrated_rgb_color_space();
        /// @brief Value of the SDK constant `NSDeviceWhiteColorSpace`.
        static std::string device_white_color_space();
        /// @brief Value of the SDK constant `NSDeviceRGBColorSpace`.
        static std::string device_rgb_color_space();
        /// @brief Value of the SDK constant `NSDeviceCMYKColorSpace`.
        static std::string device_cmyk_color_space();
        /// @brief Value of the SDK constant `NSNamedColorSpace`.
        static std::string named_color_space();
        /// @brief Value of the SDK constant `NSPatternColorSpace`.
        static std::string pattern_color_space();
        /// @brief Value of the SDK constant `NSCustomColorSpace`.
        static std::string custom_color_space();
    };

    /** @brief Named constants of type `NSNumberConstants`; each function reads the SDK symbol at runtime. */
    struct NumberConstants
    {
        /// @brief Value of the SDK constant `NSWhite`.
        static double white();
        /// @brief Value of the SDK constant `NSLightGray`.
        static double light_gray();
        /// @brief Value of the SDK constant `NSDarkGray`.
        static double dark_gray();
        /// @brief Value of the SDK constant `NSBlack`.
        static double black();
        /// @brief Value of the SDK constant `NSGridViewSizeForContent`.
        static double grid_view_size_for_content();
        /// @brief Value of the SDK constant `NSViewNoIntrinsicMetric`.
        static double view_no_intrinsic_metric();
        /// @brief Value of the SDK constant `NSSplitViewControllerAutomaticDimension`.
        static double split_view_controller_automatic_dimension();
        /// @brief Value of the SDK constant `NSSplitViewItemUnspecifiedDimension`.
        static double split_view_item_unspecified_dimension();
        /// @brief Value of the SDK constant `NSAppleEventTimeOutDefault`.
        static double apple_event_time_out_default();
        /// @brief Value of the SDK constant `NSAppleEventTimeOutNone`.
        static double apple_event_time_out_none();
        /// @brief Value of the SDK constant `NSDebugEnabled`.
        static bool debug_enabled();
        /// @brief Value of the SDK constant `NSZombieEnabled`.
        static bool zombie_enabled();
        /// @brief Value of the SDK constant `NSDeallocateZombies`.
        static bool deallocate_zombies();
        /// @brief Value of the SDK constant `NSKeepAllocationStatistics`.
        static bool keep_allocation_statistics();
        /// @brief Value of the SDK constant `NSFoundationVersionNumber`.
        static double foundation_version_number();
        /// @brief Value of the SDK constant `NSURLSessionTransferSizeUnknown`.
        static std::int64_t url_session_transfer_size_unknown();
        /// @brief Value of the SDK constant `NSURLSessionTaskPriorityDefault`.
        static float url_session_task_priority_default();
        /// @brief Value of the SDK constant `NSURLSessionTaskPriorityLow`.
        static float url_session_task_priority_low();
        /// @brief Value of the SDK constant `NSURLSessionTaskPriorityHigh`.
        static float url_session_task_priority_high();
    };

    /** @brief Named constants of type `NSDeviceDescriptionKey`; each function reads the SDK symbol at runtime. */
    struct DeviceDescriptionKey
    {
        /// @brief Value of the SDK constant `NSDeviceResolution`.
        static std::string device_resolution();
        /// @brief Value of the SDK constant `NSDeviceColorSpaceName`.
        static std::string device_color_space_name();
        /// @brief Value of the SDK constant `NSDeviceBitsPerSample`.
        static std::string device_bits_per_sample();
        /// @brief Value of the SDK constant `NSDeviceIsScreen`.
        static std::string device_is_screen();
        /// @brief Value of the SDK constant `NSDeviceIsPrinter`.
        static std::string device_is_printer();
        /// @brief Value of the SDK constant `NSDeviceSize`.
        static std::string device_size();
    };

    /** @brief Named constants of type `NSGraphicsContextAttributeKey`; each function reads the SDK symbol at runtime. */
    struct GraphicsContextAttributeKey
    {
        /// @brief Value of the SDK constant `NSGraphicsContextDestinationAttributeName`.
        static std::string graphics_context_destination_attribute_name();
        /// @brief Value of the SDK constant `NSGraphicsContextRepresentationFormatAttributeName`.
        static std::string graphics_context_representation_format_attribute_name();
    };

    /** @brief Named constants of type `NSGraphicsContextRepresentationFormatName`; each function reads the SDK symbol at runtime. */
    struct GraphicsContextRepresentationFormatName
    {
        /// @brief Value of the SDK constant `NSGraphicsContextPSFormat`.
        static std::string graphics_context_ps_format();
        /// @brief Value of the SDK constant `NSGraphicsContextPDFFormat`.
        static std::string graphics_context_pdf_format();
    };

    /** @brief Named constants of type `NSImageHintKey`; each function reads the SDK symbol at runtime. */
    struct ImageHintKey
    {
        /// @brief Value of the SDK constant `NSImageHintCTM`.
        static std::string image_hint_ctm();
        /// @brief Value of the SDK constant `NSImageHintInterpolation`.
        static std::string image_hint_interpolation();
        /// @brief Value of the SDK constant `NSImageHintUserInterfaceLayoutDirection`.
        static std::string image_hint_user_interface_layout_direction();
    };

    /** @brief Named constants of type `NSImageName`; each function reads the SDK symbol at runtime. */
    struct ImageName
    {
        /// @brief Value of the SDK constant `NSImageNameAddTemplate`.
        static std::string add_template();
        /// @brief Value of the SDK constant `NSImageNameBluetoothTemplate`.
        static std::string bluetooth_template();
        /// @brief Value of the SDK constant `NSImageNameBonjour`.
        static std::string bonjour();
        /// @brief Value of the SDK constant `NSImageNameBookmarksTemplate`.
        static std::string bookmarks_template();
        /// @brief Value of the SDK constant `NSImageNameCaution`.
        static std::string caution();
        /// @brief Value of the SDK constant `NSImageNameComputer`.
        static std::string computer();
        /// @brief Value of the SDK constant `NSImageNameEnterFullScreenTemplate`.
        static std::string enter_full_screen_template();
        /// @brief Value of the SDK constant `NSImageNameExitFullScreenTemplate`.
        static std::string exit_full_screen_template();
        /// @brief Value of the SDK constant `NSImageNameFolder`.
        static std::string folder();
        /// @brief Value of the SDK constant `NSImageNameFolderBurnable`.
        static std::string folder_burnable();
        /// @brief Value of the SDK constant `NSImageNameFolderSmart`.
        static std::string folder_smart();
        /// @brief Value of the SDK constant `NSImageNameFollowLinkFreestandingTemplate`.
        static std::string follow_link_freestanding_template();
        /// @brief Value of the SDK constant `NSImageNameHomeTemplate`.
        static std::string home_template();
        /// @brief Value of the SDK constant `NSImageNameIChatTheaterTemplate`.
        static std::string i_chat_theater_template();
        /// @brief Value of the SDK constant `NSImageNameLockLockedTemplate`.
        static std::string lock_locked_template();
        /// @brief Value of the SDK constant `NSImageNameLockUnlockedTemplate`.
        static std::string lock_unlocked_template();
        /// @brief Value of the SDK constant `NSImageNameNetwork`.
        static std::string network();
        /// @brief Value of the SDK constant `NSImageNamePathTemplate`.
        static std::string path_template();
        /// @brief Value of the SDK constant `NSImageNameQuickLookTemplate`.
        static std::string quick_look_template();
        /// @brief Value of the SDK constant `NSImageNameRefreshFreestandingTemplate`.
        static std::string refresh_freestanding_template();
        /// @brief Value of the SDK constant `NSImageNameRefreshTemplate`.
        static std::string refresh_template();
        /// @brief Value of the SDK constant `NSImageNameRemoveTemplate`.
        static std::string remove_template();
        /// @brief Value of the SDK constant `NSImageNameRevealFreestandingTemplate`.
        static std::string reveal_freestanding_template();
        /// @brief Value of the SDK constant `NSImageNameShareTemplate`.
        static std::string share_template();
        /// @brief Value of the SDK constant `NSImageNameSlideshowTemplate`.
        static std::string slideshow_template();
        /// @brief Value of the SDK constant `NSImageNameStatusAvailable`.
        static std::string status_available();
        /// @brief Value of the SDK constant `NSImageNameStatusNone`.
        static std::string status_none();
        /// @brief Value of the SDK constant `NSImageNameStatusPartiallyAvailable`.
        static std::string status_partially_available();
        /// @brief Value of the SDK constant `NSImageNameStatusUnavailable`.
        static std::string status_unavailable();
        /// @brief Value of the SDK constant `NSImageNameStopProgressFreestandingTemplate`.
        static std::string stop_progress_freestanding_template();
        /// @brief Value of the SDK constant `NSImageNameStopProgressTemplate`.
        static std::string stop_progress_template();
        /// @brief Value of the SDK constant `NSImageNameTrashEmpty`.
        static std::string trash_empty();
        /// @brief Value of the SDK constant `NSImageNameTrashFull`.
        static std::string trash_full();
        /// @brief Value of the SDK constant `NSImageNameActionTemplate`.
        static std::string action_template();
        /// @brief Value of the SDK constant `NSImageNameSmartBadgeTemplate`.
        static std::string smart_badge_template();
        /// @brief Value of the SDK constant `NSImageNameIconViewTemplate`.
        static std::string icon_view_template();
        /// @brief Value of the SDK constant `NSImageNameListViewTemplate`.
        static std::string list_view_template();
        /// @brief Value of the SDK constant `NSImageNameColumnViewTemplate`.
        static std::string column_view_template();
        /// @brief Value of the SDK constant `NSImageNameFlowViewTemplate`.
        static std::string flow_view_template();
        /// @brief Value of the SDK constant `NSImageNameInvalidDataFreestandingTemplate`.
        static std::string invalid_data_freestanding_template();
        /// @brief Value of the SDK constant `NSImageNameGoForwardTemplate`.
        static std::string go_forward_template();
        /// @brief Value of the SDK constant `NSImageNameGoBackTemplate`.
        static std::string go_back_template();
        /// @brief Value of the SDK constant `NSImageNameGoRightTemplate`.
        static std::string go_right_template();
        /// @brief Value of the SDK constant `NSImageNameGoLeftTemplate`.
        static std::string go_left_template();
        /// @brief Value of the SDK constant `NSImageNameRightFacingTriangleTemplate`.
        static std::string right_facing_triangle_template();
        /// @brief Value of the SDK constant `NSImageNameLeftFacingTriangleTemplate`.
        static std::string left_facing_triangle_template();
        /// @brief Value of the SDK constant `NSImageNameMobileMe`.
        static std::string mobile_me();
        /// @brief Value of the SDK constant `NSImageNameMultipleDocuments`.
        static std::string multiple_documents();
        /// @brief Value of the SDK constant `NSImageNameUserAccounts`.
        static std::string user_accounts();
        /// @brief Value of the SDK constant `NSImageNamePreferencesGeneral`.
        static std::string preferences_general();
        /// @brief Value of the SDK constant `NSImageNameAdvanced`.
        static std::string advanced();
        /// @brief Value of the SDK constant `NSImageNameInfo`.
        static std::string info();
        /// @brief Value of the SDK constant `NSImageNameFontPanel`.
        static std::string font_panel();
        /// @brief Value of the SDK constant `NSImageNameColorPanel`.
        static std::string color_panel();
        /// @brief Value of the SDK constant `NSImageNameUser`.
        static std::string user();
        /// @brief Value of the SDK constant `NSImageNameUserGroup`.
        static std::string user_group();
        /// @brief Value of the SDK constant `NSImageNameEveryone`.
        static std::string everyone();
        /// @brief Value of the SDK constant `NSImageNameUserGuest`.
        static std::string user_guest();
        /// @brief Value of the SDK constant `NSImageNameMenuOnStateTemplate`.
        static std::string menu_on_state_template();
        /// @brief Value of the SDK constant `NSImageNameMenuMixedStateTemplate`.
        static std::string menu_mixed_state_template();
        /// @brief Value of the SDK constant `NSImageNameApplicationIcon`.
        static std::string application_icon();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAddDetailTemplate`.
        static std::string touch_bar_add_detail_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAddTemplate`.
        static std::string touch_bar_add_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAlarmTemplate`.
        static std::string touch_bar_alarm_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioInputMuteTemplate`.
        static std::string touch_bar_audio_input_mute_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioInputTemplate`.
        static std::string touch_bar_audio_input_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioOutputMuteTemplate`.
        static std::string touch_bar_audio_output_mute_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioOutputVolumeHighTemplate`.
        static std::string touch_bar_audio_output_volume_high_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioOutputVolumeLowTemplate`.
        static std::string touch_bar_audio_output_volume_low_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioOutputVolumeMediumTemplate`.
        static std::string touch_bar_audio_output_volume_medium_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarAudioOutputVolumeOffTemplate`.
        static std::string touch_bar_audio_output_volume_off_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarBookmarksTemplate`.
        static std::string touch_bar_bookmarks_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarColorPickerFill`.
        static std::string touch_bar_color_picker_fill();
        /// @brief Value of the SDK constant `NSImageNameTouchBarColorPickerFont`.
        static std::string touch_bar_color_picker_font();
        /// @brief Value of the SDK constant `NSImageNameTouchBarColorPickerStroke`.
        static std::string touch_bar_color_picker_stroke();
        /// @brief Value of the SDK constant `NSImageNameTouchBarCommunicationAudioTemplate`.
        static std::string touch_bar_communication_audio_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarCommunicationVideoTemplate`.
        static std::string touch_bar_communication_video_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarComposeTemplate`.
        static std::string touch_bar_compose_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarDeleteTemplate`.
        static std::string touch_bar_delete_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarDownloadTemplate`.
        static std::string touch_bar_download_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarEnterFullScreenTemplate`.
        static std::string touch_bar_enter_full_screen_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarExitFullScreenTemplate`.
        static std::string touch_bar_exit_full_screen_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarFastForwardTemplate`.
        static std::string touch_bar_fast_forward_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarFolderCopyToTemplate`.
        static std::string touch_bar_folder_copy_to_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarFolderMoveToTemplate`.
        static std::string touch_bar_folder_move_to_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarFolderTemplate`.
        static std::string touch_bar_folder_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarGetInfoTemplate`.
        static std::string touch_bar_get_info_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarGoBackTemplate`.
        static std::string touch_bar_go_back_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarGoDownTemplate`.
        static std::string touch_bar_go_down_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarGoForwardTemplate`.
        static std::string touch_bar_go_forward_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarGoUpTemplate`.
        static std::string touch_bar_go_up_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarHistoryTemplate`.
        static std::string touch_bar_history_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarIconViewTemplate`.
        static std::string touch_bar_icon_view_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarListViewTemplate`.
        static std::string touch_bar_list_view_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarMailTemplate`.
        static std::string touch_bar_mail_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarNewFolderTemplate`.
        static std::string touch_bar_new_folder_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarNewMessageTemplate`.
        static std::string touch_bar_new_message_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarOpenInBrowserTemplate`.
        static std::string touch_bar_open_in_browser_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarPauseTemplate`.
        static std::string touch_bar_pause_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarPlayPauseTemplate`.
        static std::string touch_bar_play_pause_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarPlayTemplate`.
        static std::string touch_bar_play_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarQuickLookTemplate`.
        static std::string touch_bar_quick_look_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRecordStartTemplate`.
        static std::string touch_bar_record_start_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRecordStopTemplate`.
        static std::string touch_bar_record_stop_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRefreshTemplate`.
        static std::string touch_bar_refresh_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRemoveTemplate`.
        static std::string touch_bar_remove_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRewindTemplate`.
        static std::string touch_bar_rewind_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRotateLeftTemplate`.
        static std::string touch_bar_rotate_left_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarRotateRightTemplate`.
        static std::string touch_bar_rotate_right_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSearchTemplate`.
        static std::string touch_bar_search_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarShareTemplate`.
        static std::string touch_bar_share_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSidebarTemplate`.
        static std::string touch_bar_sidebar_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipAhead15SecondsTemplate`.
        static std::string touch_bar_skip_ahead15_seconds_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipAhead30SecondsTemplate`.
        static std::string touch_bar_skip_ahead30_seconds_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipAheadTemplate`.
        static std::string touch_bar_skip_ahead_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipBack15SecondsTemplate`.
        static std::string touch_bar_skip_back15_seconds_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipBack30SecondsTemplate`.
        static std::string touch_bar_skip_back30_seconds_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipBackTemplate`.
        static std::string touch_bar_skip_back_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipToEndTemplate`.
        static std::string touch_bar_skip_to_end_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSkipToStartTemplate`.
        static std::string touch_bar_skip_to_start_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarSlideshowTemplate`.
        static std::string touch_bar_slideshow_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTagIconTemplate`.
        static std::string touch_bar_tag_icon_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextBoldTemplate`.
        static std::string touch_bar_text_bold_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextBoxTemplate`.
        static std::string touch_bar_text_box_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextCenterAlignTemplate`.
        static std::string touch_bar_text_center_align_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextItalicTemplate`.
        static std::string touch_bar_text_italic_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextJustifiedAlignTemplate`.
        static std::string touch_bar_text_justified_align_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextLeftAlignTemplate`.
        static std::string touch_bar_text_left_align_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextListTemplate`.
        static std::string touch_bar_text_list_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextRightAlignTemplate`.
        static std::string touch_bar_text_right_align_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextStrikethroughTemplate`.
        static std::string touch_bar_text_strikethrough_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarTextUnderlineTemplate`.
        static std::string touch_bar_text_underline_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarUserAddTemplate`.
        static std::string touch_bar_user_add_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarUserGroupTemplate`.
        static std::string touch_bar_user_group_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarUserTemplate`.
        static std::string touch_bar_user_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarVolumeDownTemplate`.
        static std::string touch_bar_volume_down_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarVolumeUpTemplate`.
        static std::string touch_bar_volume_up_template();
        /// @brief Value of the SDK constant `NSImageNameTouchBarPlayheadTemplate`.
        static std::string touch_bar_playhead_template();
    };

    /** @brief Named constants of type `NSBindingInfoKey`; each function reads the SDK symbol at runtime. */
    struct BindingInfoKey
    {
        /// @brief Value of the SDK constant `NSObservedObjectKey`.
        static std::string observed_object_key();
        /// @brief Value of the SDK constant `NSObservedKeyPathKey`.
        static std::string observed_key_path_key();
        /// @brief Value of the SDK constant `NSOptionsKey`.
        static std::string options_key();
    };

    /** @brief Named constants of type `NSBindingName`; each function reads the SDK symbol at runtime. */
    struct BindingName
    {
        /// @brief Value of the SDK constant `NSAlignmentBinding`.
        static std::string alignment_binding();
        /// @brief Value of the SDK constant `NSAlternateImageBinding`.
        static std::string alternate_image_binding();
        /// @brief Value of the SDK constant `NSAlternateTitleBinding`.
        static std::string alternate_title_binding();
        /// @brief Value of the SDK constant `NSAnimateBinding`.
        static std::string animate_binding();
        /// @brief Value of the SDK constant `NSAnimationDelayBinding`.
        static std::string animation_delay_binding();
        /// @brief Value of the SDK constant `NSArgumentBinding`.
        static std::string argument_binding();
        /// @brief Value of the SDK constant `NSAttributedStringBinding`.
        static std::string attributed_string_binding();
        /// @brief Value of the SDK constant `NSContentArrayBinding`.
        static std::string content_array_binding();
        /// @brief Value of the SDK constant `NSContentArrayForMultipleSelectionBinding`.
        static std::string content_array_for_multiple_selection_binding();
        /// @brief Value of the SDK constant `NSContentBinding`.
        static std::string content_binding();
        /// @brief Value of the SDK constant `NSContentDictionaryBinding`.
        static std::string content_dictionary_binding();
        /// @brief Value of the SDK constant `NSContentHeightBinding`.
        static std::string content_height_binding();
        /// @brief Value of the SDK constant `NSContentObjectBinding`.
        static std::string content_object_binding();
        /// @brief Value of the SDK constant `NSContentObjectsBinding`.
        static std::string content_objects_binding();
        /// @brief Value of the SDK constant `NSContentSetBinding`.
        static std::string content_set_binding();
        /// @brief Value of the SDK constant `NSContentValuesBinding`.
        static std::string content_values_binding();
        /// @brief Value of the SDK constant `NSContentWidthBinding`.
        static std::string content_width_binding();
        /// @brief Value of the SDK constant `NSCriticalValueBinding`.
        static std::string critical_value_binding();
        /// @brief Value of the SDK constant `NSDataBinding`.
        static std::string data_binding();
        /// @brief Value of the SDK constant `NSDisplayPatternTitleBinding`.
        static std::string display_pattern_title_binding();
        /// @brief Value of the SDK constant `NSDisplayPatternValueBinding`.
        static std::string display_pattern_value_binding();
        /// @brief Value of the SDK constant `NSDocumentEditedBinding`.
        static std::string document_edited_binding();
        /// @brief Value of the SDK constant `NSDoubleClickArgumentBinding`.
        static std::string double_click_argument_binding();
        /// @brief Value of the SDK constant `NSDoubleClickTargetBinding`.
        static std::string double_click_target_binding();
        /// @brief Value of the SDK constant `NSEditableBinding`.
        static std::string editable_binding();
        /// @brief Value of the SDK constant `NSEnabledBinding`.
        static std::string enabled_binding();
        /// @brief Value of the SDK constant `NSExcludedKeysBinding`.
        static std::string excluded_keys_binding();
        /// @brief Value of the SDK constant `NSFilterPredicateBinding`.
        static std::string filter_predicate_binding();
        /// @brief Value of the SDK constant `NSFontBinding`.
        static std::string font_binding();
        /// @brief Value of the SDK constant `NSFontBoldBinding`.
        static std::string font_bold_binding();
        /// @brief Value of the SDK constant `NSFontFamilyNameBinding`.
        static std::string font_family_name_binding();
        /// @brief Value of the SDK constant `NSFontItalicBinding`.
        static std::string font_italic_binding();
        /// @brief Value of the SDK constant `NSFontNameBinding`.
        static std::string font_name_binding();
        /// @brief Value of the SDK constant `NSFontSizeBinding`.
        static std::string font_size_binding();
        /// @brief Value of the SDK constant `NSHeaderTitleBinding`.
        static std::string header_title_binding();
        /// @brief Value of the SDK constant `NSHiddenBinding`.
        static std::string hidden_binding();
        /// @brief Value of the SDK constant `NSImageBinding`.
        static std::string image_binding();
        /// @brief Value of the SDK constant `NSIncludedKeysBinding`.
        static std::string included_keys_binding();
        /// @brief Value of the SDK constant `NSInitialKeyBinding`.
        static std::string initial_key_binding();
        /// @brief Value of the SDK constant `NSInitialValueBinding`.
        static std::string initial_value_binding();
        /// @brief Value of the SDK constant `NSIsIndeterminateBinding`.
        static std::string is_indeterminate_binding();
        /// @brief Value of the SDK constant `NSLabelBinding`.
        static std::string label_binding();
        /// @brief Value of the SDK constant `NSLocalizedKeyDictionaryBinding`.
        static std::string localized_key_dictionary_binding();
        /// @brief Value of the SDK constant `NSManagedObjectContextBinding`.
        static std::string managed_object_context_binding();
        /// @brief Value of the SDK constant `NSMaximumRecentsBinding`.
        static std::string maximum_recents_binding();
        /// @brief Value of the SDK constant `NSMaxValueBinding`.
        static std::string max_value_binding();
        /// @brief Value of the SDK constant `NSMaxWidthBinding`.
        static std::string max_width_binding();
        /// @brief Value of the SDK constant `NSMinValueBinding`.
        static std::string min_value_binding();
        /// @brief Value of the SDK constant `NSMinWidthBinding`.
        static std::string min_width_binding();
        /// @brief Value of the SDK constant `NSMixedStateImageBinding`.
        static std::string mixed_state_image_binding();
        /// @brief Value of the SDK constant `NSOffStateImageBinding`.
        static std::string off_state_image_binding();
        /// @brief Value of the SDK constant `NSOnStateImageBinding`.
        static std::string on_state_image_binding();
        /// @brief Value of the SDK constant `NSPositioningRectBinding`.
        static std::string positioning_rect_binding();
        /// @brief Value of the SDK constant `NSPredicateBinding`.
        static std::string predicate_binding();
        /// @brief Value of the SDK constant `NSRecentSearchesBinding`.
        static std::string recent_searches_binding();
        /// @brief Value of the SDK constant `NSRepresentedFilenameBinding`.
        static std::string represented_filename_binding();
        /// @brief Value of the SDK constant `NSRowHeightBinding`.
        static std::string row_height_binding();
        /// @brief Value of the SDK constant `NSSelectedIdentifierBinding`.
        static std::string selected_identifier_binding();
        /// @brief Value of the SDK constant `NSSelectedIndexBinding`.
        static std::string selected_index_binding();
        /// @brief Value of the SDK constant `NSSelectedLabelBinding`.
        static std::string selected_label_binding();
        /// @brief Value of the SDK constant `NSSelectedObjectBinding`.
        static std::string selected_object_binding();
        /// @brief Value of the SDK constant `NSSelectedObjectsBinding`.
        static std::string selected_objects_binding();
        /// @brief Value of the SDK constant `NSSelectedTagBinding`.
        static std::string selected_tag_binding();
        /// @brief Value of the SDK constant `NSSelectedValueBinding`.
        static std::string selected_value_binding();
        /// @brief Value of the SDK constant `NSSelectedValuesBinding`.
        static std::string selected_values_binding();
        /// @brief Value of the SDK constant `NSSelectionIndexesBinding`.
        static std::string selection_indexes_binding();
        /// @brief Value of the SDK constant `NSSelectionIndexPathsBinding`.
        static std::string selection_index_paths_binding();
        /// @brief Value of the SDK constant `NSSortDescriptorsBinding`.
        static std::string sort_descriptors_binding();
        /// @brief Value of the SDK constant `NSTargetBinding`.
        static std::string target_binding();
        /// @brief Value of the SDK constant `NSTextColorBinding`.
        static std::string text_color_binding();
        /// @brief Value of the SDK constant `NSTitleBinding`.
        static std::string title_binding();
        /// @brief Value of the SDK constant `NSToolTipBinding`.
        static std::string tool_tip_binding();
        /// @brief Value of the SDK constant `NSTransparentBinding`.
        static std::string transparent_binding();
        /// @brief Value of the SDK constant `NSValueBinding`.
        static std::string value_binding();
        /// @brief Value of the SDK constant `NSValuePathBinding`.
        static std::string value_path_binding();
        /// @brief Value of the SDK constant `NSValueURLBinding`.
        static std::string value_url_binding();
        /// @brief Value of the SDK constant `NSVisibleBinding`.
        static std::string visible_binding();
        /// @brief Value of the SDK constant `NSWarningValueBinding`.
        static std::string warning_value_binding();
        /// @brief Value of the SDK constant `NSWidthBinding`.
        static std::string width_binding();
    };

    /** @brief Named constants of type `NSBindingOption`; each function reads the SDK symbol at runtime. */
    struct BindingOption
    {
        /// @brief Value of the SDK constant `NSAllowsEditingMultipleValuesSelectionBindingOption`.
        static std::string allows_editing_multiple_values_selection_binding_option();
        /// @brief Value of the SDK constant `NSAllowsNullArgumentBindingOption`.
        static std::string allows_null_argument_binding_option();
        /// @brief Value of the SDK constant `NSAlwaysPresentsApplicationModalAlertsBindingOption`.
        static std::string always_presents_application_modal_alerts_binding_option();
        /// @brief Value of the SDK constant `NSConditionallySetsEditableBindingOption`.
        static std::string conditionally_sets_editable_binding_option();
        /// @brief Value of the SDK constant `NSConditionallySetsEnabledBindingOption`.
        static std::string conditionally_sets_enabled_binding_option();
        /// @brief Value of the SDK constant `NSConditionallySetsHiddenBindingOption`.
        static std::string conditionally_sets_hidden_binding_option();
        /// @brief Value of the SDK constant `NSContinuouslyUpdatesValueBindingOption`.
        static std::string continuously_updates_value_binding_option();
        /// @brief Value of the SDK constant `NSCreatesSortDescriptorBindingOption`.
        static std::string creates_sort_descriptor_binding_option();
        /// @brief Value of the SDK constant `NSDeletesObjectsOnRemoveBindingsOption`.
        static std::string deletes_objects_on_remove_bindings_option();
        /// @brief Value of the SDK constant `NSDisplayNameBindingOption`.
        static std::string display_name_binding_option();
        /// @brief Value of the SDK constant `NSDisplayPatternBindingOption`.
        static std::string display_pattern_binding_option();
        /// @brief Value of the SDK constant `NSContentPlacementTagBindingOption`.
        static std::string content_placement_tag_binding_option();
        /// @brief Value of the SDK constant `NSHandlesContentAsCompoundValueBindingOption`.
        static std::string handles_content_as_compound_value_binding_option();
        /// @brief Value of the SDK constant `NSInsertsNullPlaceholderBindingOption`.
        static std::string inserts_null_placeholder_binding_option();
        /// @brief Value of the SDK constant `NSInvokesSeparatelyWithArrayObjectsBindingOption`.
        static std::string invokes_separately_with_array_objects_binding_option();
        /// @brief Value of the SDK constant `NSMultipleValuesPlaceholderBindingOption`.
        static std::string multiple_values_placeholder_binding_option();
        /// @brief Value of the SDK constant `NSNoSelectionPlaceholderBindingOption`.
        static std::string no_selection_placeholder_binding_option();
        /// @brief Value of the SDK constant `NSNotApplicablePlaceholderBindingOption`.
        static std::string not_applicable_placeholder_binding_option();
        /// @brief Value of the SDK constant `NSNullPlaceholderBindingOption`.
        static std::string null_placeholder_binding_option();
        /// @brief Value of the SDK constant `NSRaisesForNotApplicableKeysBindingOption`.
        static std::string raises_for_not_applicable_keys_binding_option();
        /// @brief Value of the SDK constant `NSPredicateFormatBindingOption`.
        static std::string predicate_format_binding_option();
        /// @brief Value of the SDK constant `NSSelectorNameBindingOption`.
        static std::string selector_name_binding_option();
        /// @brief Value of the SDK constant `NSSelectsAllWhenSettingContentBindingOption`.
        static std::string selects_all_when_setting_content_binding_option();
        /// @brief Value of the SDK constant `NSValidatesImmediatelyBindingOption`.
        static std::string validates_immediately_binding_option();
        /// @brief Value of the SDK constant `NSValueTransformerNameBindingOption`.
        static std::string value_transformer_name_binding_option();
        /// @brief Value of the SDK constant `NSValueTransformerBindingOption`.
        static std::string value_transformer_binding_option();
    };

    /** @brief Named constants of type `NSUserInterfaceItemIdentifier`; each function reads the SDK symbol at runtime. */
    struct UserInterfaceItemIdentifier
    {
        /// @brief Value of the SDK constant `NSMenuItemImportFromDeviceIdentifier`.
        static std::string menu_item_import_from_device_identifier();
        /// @brief Value of the SDK constant `NSOutlineViewDisclosureButtonKey`.
        static std::string outline_view_disclosure_button_key();
        /// @brief Value of the SDK constant `NSOutlineViewShowHideButtonKey`.
        static std::string outline_view_show_hide_button_key();
        /// @brief Value of the SDK constant `NSTableViewRowViewKey`.
        static std::string table_view_row_view_key();
    };

    /** @brief Named constants of type `NSTextTabOptionKey`; each function reads the SDK symbol at runtime. */
    struct TextTabOptionKey
    {
        /// @brief Value of the SDK constant `NSTabColumnTerminatorsAttributeName`.
        static std::string tab_column_terminators_attribute_name();
    };

    /** @brief Named constants of type `NSPasteboardType`; each function reads the SDK symbol at runtime. */
    struct PasteboardType
    {
        /// @brief Value of the SDK constant `NSPasteboardTypeString`.
        static std::string string();
        /// @brief Value of the SDK constant `NSPasteboardTypePDF`.
        static std::string pdf();
        /// @brief Value of the SDK constant `NSPasteboardTypeTIFF`.
        static std::string tiff();
        /// @brief Value of the SDK constant `NSPasteboardTypePNG`.
        static std::string png();
        /// @brief Value of the SDK constant `NSPasteboardTypeRTF`.
        static std::string rtf();
        /// @brief Value of the SDK constant `NSPasteboardTypeRTFD`.
        static std::string rtfd();
        /// @brief Value of the SDK constant `NSPasteboardTypeHTML`.
        static std::string html();
        /// @brief Value of the SDK constant `NSPasteboardTypeTabularText`.
        static std::string tabular_text();
        /// @brief Value of the SDK constant `NSPasteboardTypeFont`.
        static std::string font();
        /// @brief Value of the SDK constant `NSPasteboardTypeRuler`.
        static std::string ruler();
        /// @brief Value of the SDK constant `NSPasteboardTypeColor`.
        static std::string color();
        /// @brief Value of the SDK constant `NSPasteboardTypeSound`.
        static std::string sound();
        /// @brief Value of the SDK constant `NSPasteboardTypeMultipleTextSelection`.
        static std::string multiple_text_selection();
        /// @brief Value of the SDK constant `NSPasteboardTypeTextFinderOptions`.
        static std::string text_finder_options();
        /// @brief Value of the SDK constant `NSPasteboardTypeURL`.
        static std::string url();
        /// @brief Value of the SDK constant `NSPasteboardTypeFileURL`.
        static std::string file_url();
        /// @brief Value of the SDK constant `NSFileContentsPboardType`.
        static std::string file_contents_pboard_type();
        /// @brief Value of the SDK constant `NSSoundPboardType`.
        static std::string sound_pboard_type();
        /// @brief Value of the SDK constant `NSFindPanelSearchOptionsPboardType`.
        static std::string find_panel_search_options_pboard_type();
    };

    /** @brief Named constants of type `NSPasteboardName`; each function reads the SDK symbol at runtime. */
    struct PasteboardName
    {
        /// @brief Value of the SDK constant `NSPasteboardNameGeneral`.
        static std::string general();
        /// @brief Value of the SDK constant `NSPasteboardNameFont`.
        static std::string font();
        /// @brief Value of the SDK constant `NSPasteboardNameRuler`.
        static std::string ruler();
        /// @brief Value of the SDK constant `NSPasteboardNameFind`.
        static std::string find();
        /// @brief Value of the SDK constant `NSPasteboardNameDrag`.
        static std::string drag();
    };

    /** @brief Named constants of type `NSPasteboardDetectionPattern`; each function reads the SDK symbol at runtime. */
    struct PasteboardDetectionPattern
    {
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternProbableWebURL`.
        static std::string probable_web_url();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternProbableWebSearch`.
        static std::string probable_web_search();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternNumber`.
        static std::string number();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternLink`.
        static std::string link();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternPhoneNumber`.
        static std::string phone_number();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternEmailAddress`.
        static std::string email_address();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternPostalAddress`.
        static std::string postal_address();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternCalendarEvent`.
        static std::string calendar_event();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternShipmentTrackingNumber`.
        static std::string shipment_tracking_number();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternFlightNumber`.
        static std::string flight_number();
        /// @brief Value of the SDK constant `NSPasteboardDetectionPatternMoneyAmount`.
        static std::string money_amount();
    };

    /** @brief Named constants of type `NSPasteboardMetadataType`; each function reads the SDK symbol at runtime. */
    struct PasteboardMetadataType
    {
        /// @brief Value of the SDK constant `NSPasteboardMetadataTypeContentType`.
        static std::string content_type();
    };

    /** @brief Named constants of type `NSPasteboardReadingOptionKey`; each function reads the SDK symbol at runtime. */
    struct PasteboardReadingOptionKey
    {
        /// @brief Value of the SDK constant `NSPasteboardURLReadingFileURLsOnlyKey`.
        static std::string pasteboard_url_reading_file_ur_ls_only_key();
        /// @brief Value of the SDK constant `NSPasteboardURLReadingContentsConformToTypesKey`.
        static std::string pasteboard_url_reading_contents_conform_to_types_key();
    };

    /** @brief Named constants of type `NSPopoverCloseReasonValue`; each function reads the SDK symbol at runtime. */
    struct PopoverCloseReasonValue
    {
        /// @brief Value of the SDK constant `NSPopoverCloseReasonStandard`.
        static std::string popover_close_reason_standard();
        /// @brief Value of the SDK constant `NSPopoverCloseReasonDetachToWindow`.
        static std::string popover_close_reason_detach_to_window();
    };

    /** @brief Named constants of type `NSPrintInfoAttributeKey`; each function reads the SDK symbol at runtime. */
    struct PrintInfoAttributeKey
    {
        /// @brief Value of the SDK constant `NSPrintPaperName`.
        static std::string print_paper_name();
        /// @brief Value of the SDK constant `NSPrintPaperSize`.
        static std::string print_paper_size();
        /// @brief Value of the SDK constant `NSPrintOrientation`.
        static std::string print_orientation();
        /// @brief Value of the SDK constant `NSPrintScalingFactor`.
        static std::string print_scaling_factor();
        /// @brief Value of the SDK constant `NSPrintLeftMargin`.
        static std::string print_left_margin();
        /// @brief Value of the SDK constant `NSPrintRightMargin`.
        static std::string print_right_margin();
        /// @brief Value of the SDK constant `NSPrintTopMargin`.
        static std::string print_top_margin();
        /// @brief Value of the SDK constant `NSPrintBottomMargin`.
        static std::string print_bottom_margin();
        /// @brief Value of the SDK constant `NSPrintHorizontallyCentered`.
        static std::string print_horizontally_centered();
        /// @brief Value of the SDK constant `NSPrintVerticallyCentered`.
        static std::string print_vertically_centered();
        /// @brief Value of the SDK constant `NSPrintHorizontalPagination`.
        static std::string print_horizontal_pagination();
        /// @brief Value of the SDK constant `NSPrintVerticalPagination`.
        static std::string print_vertical_pagination();
        /// @brief Value of the SDK constant `NSPrintPrinter`.
        static std::string print_printer();
        /// @brief Value of the SDK constant `NSPrintCopies`.
        static std::string print_copies();
        /// @brief Value of the SDK constant `NSPrintAllPages`.
        static std::string print_all_pages();
        /// @brief Value of the SDK constant `NSPrintFirstPage`.
        static std::string print_first_page();
        /// @brief Value of the SDK constant `NSPrintLastPage`.
        static std::string print_last_page();
        /// @brief Value of the SDK constant `NSPrintMustCollate`.
        static std::string print_must_collate();
        /// @brief Value of the SDK constant `NSPrintReversePageOrder`.
        static std::string print_reverse_page_order();
        /// @brief Value of the SDK constant `NSPrintJobDisposition`.
        static std::string print_job_disposition();
        /// @brief Value of the SDK constant `NSPrintPagesAcross`.
        static std::string print_pages_across();
        /// @brief Value of the SDK constant `NSPrintPagesDown`.
        static std::string print_pages_down();
        /// @brief Value of the SDK constant `NSPrintTime`.
        static std::string print_time();
        /// @brief Value of the SDK constant `NSPrintDetailedErrorReporting`.
        static std::string print_detailed_error_reporting();
        /// @brief Value of the SDK constant `NSPrintFaxNumber`.
        static std::string print_fax_number();
        /// @brief Value of the SDK constant `NSPrintPrinterName`.
        static std::string print_printer_name();
        /// @brief Value of the SDK constant `NSPrintSelectionOnly`.
        static std::string print_selection_only();
        /// @brief Value of the SDK constant `NSPrintJobSavingURL`.
        static std::string print_job_saving_url();
        /// @brief Value of the SDK constant `NSPrintJobSavingFileNameExtensionHidden`.
        static std::string print_job_saving_file_name_extension_hidden();
        /// @brief Value of the SDK constant `NSPrintHeaderAndFooter`.
        static std::string print_header_and_footer();
    };

    /** @brief Named constants of type `NSPrintJobDispositionValue`; each function reads the SDK symbol at runtime. */
    struct PrintJobDispositionValue
    {
        /// @brief Value of the SDK constant `NSPrintSpoolJob`.
        static std::string print_spool_job();
        /// @brief Value of the SDK constant `NSPrintPreviewJob`.
        static std::string print_preview_job();
        /// @brief Value of the SDK constant `NSPrintSaveJob`.
        static std::string print_save_job();
        /// @brief Value of the SDK constant `NSPrintCancelJob`.
        static std::string print_cancel_job();
    };

    /** @brief Named constants of type `NSPrintPanelJobStyleHint`; each function reads the SDK symbol at runtime. */
    struct PrintPanelJobStyleHint
    {
        /// @brief Value of the SDK constant `NSPrintPhotoJobStyleHint`.
        static std::string print_photo_job_style_hint();
        /// @brief Value of the SDK constant `NSPrintAllPresetsJobStyleHint`.
        static std::string print_all_presets_job_style_hint();
        /// @brief Value of the SDK constant `NSPrintNoPresetsJobStyleHint`.
        static std::string print_no_presets_job_style_hint();
    };

    /** @brief Named constants of type `NSPrintPanelAccessorySummaryKey`; each function reads the SDK symbol at runtime. */
    struct PrintPanelAccessorySummaryKey
    {
        /// @brief Value of the SDK constant `NSPrintPanelAccessorySummaryItemNameKey`.
        static std::string print_panel_accessory_summary_item_name_key();
        /// @brief Value of the SDK constant `NSPrintPanelAccessorySummaryItemDescriptionKey`.
        static std::string print_panel_accessory_summary_item_description_key();
    };

    /** @brief Named constants of type `NSRuleEditorPredicatePartKey`; each function reads the SDK symbol at runtime. */
    struct RuleEditorPredicatePartKey
    {
        /// @brief Value of the SDK constant `NSRuleEditorPredicateLeftExpression`.
        static std::string rule_editor_predicate_left_expression();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateRightExpression`.
        static std::string rule_editor_predicate_right_expression();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateComparisonModifier`.
        static std::string rule_editor_predicate_comparison_modifier();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateOptions`.
        static std::string rule_editor_predicate_options();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateOperatorType`.
        static std::string rule_editor_predicate_operator_type();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateCustomSelector`.
        static std::string rule_editor_predicate_custom_selector();
        /// @brief Value of the SDK constant `NSRuleEditorPredicateCompoundType`.
        static std::string rule_editor_predicate_compound_type();
    };

    /** @brief Named constants of type `NSRulerViewUnitName`; each function reads the SDK symbol at runtime. */
    struct RulerViewUnitName
    {
        /// @brief Value of the SDK constant `NSRulerViewUnitInches`.
        static std::string ruler_view_unit_inches();
        /// @brief Value of the SDK constant `NSRulerViewUnitCentimeters`.
        static std::string ruler_view_unit_centimeters();
        /// @brief Value of the SDK constant `NSRulerViewUnitPoints`.
        static std::string ruler_view_unit_points();
        /// @brief Value of the SDK constant `NSRulerViewUnitPicas`.
        static std::string ruler_view_unit_picas();
    };

    /** @brief Named constants of type `NSSharingServiceName`; each function reads the SDK symbol at runtime. */
    struct SharingServiceName
    {
        /// @brief Value of the SDK constant `NSSharingServiceNameComposeEmail`.
        static std::string compose_email();
        /// @brief Value of the SDK constant `NSSharingServiceNameComposeMessage`.
        static std::string compose_message();
        /// @brief Value of the SDK constant `NSSharingServiceNameSendViaAirDrop`.
        static std::string send_via_air_drop();
        /// @brief Value of the SDK constant `NSSharingServiceNameAddToSafariReadingList`.
        static std::string add_to_safari_reading_list();
        /// @brief Value of the SDK constant `NSSharingServiceNameAddToIPhoto`.
        static std::string add_to_i_photo();
        /// @brief Value of the SDK constant `NSSharingServiceNameAddToAperture`.
        static std::string add_to_aperture();
        /// @brief Value of the SDK constant `NSSharingServiceNameUseAsDesktopPicture`.
        static std::string use_as_desktop_picture();
        /// @brief Value of the SDK constant `NSSharingServiceNameCloudSharing`.
        static std::string cloud_sharing();
    };

    /** @brief Named constants of type `NSSliderAccessoryWidth`; each function reads the SDK symbol at runtime. */
    struct SliderAccessoryWidth
    {
        /// @brief Value of the SDK constant `NSSliderAccessoryWidthDefault`.
        static double default_();
        /// @brief Value of the SDK constant `NSSliderAccessoryWidthWide`.
        static double wide();
    };

    /** @brief Named constants of type `NSVoiceAttributeKey`; each function reads the SDK symbol at runtime. */
    struct VoiceAttributeKey
    {
        /// @brief Value of the SDK constant `NSVoiceName`.
        static std::string voice_name();
        /// @brief Value of the SDK constant `NSVoiceIdentifier`.
        static std::string voice_identifier();
        /// @brief Value of the SDK constant `NSVoiceAge`.
        static std::string voice_age();
        /// @brief Value of the SDK constant `NSVoiceGender`.
        static std::string voice_gender();
        /// @brief Value of the SDK constant `NSVoiceDemoText`.
        static std::string voice_demo_text();
        /// @brief Value of the SDK constant `NSVoiceLocaleIdentifier`.
        static std::string voice_locale_identifier();
        /// @brief Value of the SDK constant `NSVoiceSupportedCharacters`.
        static std::string voice_supported_characters();
        /// @brief Value of the SDK constant `NSVoiceIndividuallySpokenCharacters`.
        static std::string voice_individually_spoken_characters();
    };

    /** @brief Named constants of type `NSSpeechDictionaryKey`; each function reads the SDK symbol at runtime. */
    struct SpeechDictionaryKey
    {
        /// @brief Value of the SDK constant `NSSpeechDictionaryLocaleIdentifier`.
        static std::string speech_dictionary_locale_identifier();
        /// @brief Value of the SDK constant `NSSpeechDictionaryModificationDate`.
        static std::string speech_dictionary_modification_date();
        /// @brief Value of the SDK constant `NSSpeechDictionaryPronunciations`.
        static std::string speech_dictionary_pronunciations();
        /// @brief Value of the SDK constant `NSSpeechDictionaryAbbreviations`.
        static std::string speech_dictionary_abbreviations();
        /// @brief Value of the SDK constant `NSSpeechDictionaryEntrySpelling`.
        static std::string speech_dictionary_entry_spelling();
        /// @brief Value of the SDK constant `NSSpeechDictionaryEntryPhonemes`.
        static std::string speech_dictionary_entry_phonemes();
    };

    /** @brief Named constants of type `NSVoiceGenderName`; each function reads the SDK symbol at runtime. */
    struct VoiceGenderName
    {
        /// @brief Value of the SDK constant `NSVoiceGenderNeuter`.
        static std::string voice_gender_neuter();
        /// @brief Value of the SDK constant `NSVoiceGenderMale`.
        static std::string voice_gender_male();
        /// @brief Value of the SDK constant `NSVoiceGenderFemale`.
        static std::string voice_gender_female();
        /// @brief Value of the SDK constant `NSVoiceGenderNeutral`.
        static std::string voice_gender_neutral();
    };

    /** @brief Named constants of type `NSSpeechPropertyKey`; each function reads the SDK symbol at runtime. */
    struct SpeechPropertyKey
    {
        /// @brief Value of the SDK constant `NSSpeechStatusProperty`.
        static std::string speech_status_property();
        /// @brief Value of the SDK constant `NSSpeechErrorsProperty`.
        static std::string speech_errors_property();
        /// @brief Value of the SDK constant `NSSpeechInputModeProperty`.
        static std::string speech_input_mode_property();
        /// @brief Value of the SDK constant `NSSpeechCharacterModeProperty`.
        static std::string speech_character_mode_property();
        /// @brief Value of the SDK constant `NSSpeechNumberModeProperty`.
        static std::string speech_number_mode_property();
        /// @brief Value of the SDK constant `NSSpeechRateProperty`.
        static std::string speech_rate_property();
        /// @brief Value of the SDK constant `NSSpeechPitchBaseProperty`.
        static std::string speech_pitch_base_property();
        /// @brief Value of the SDK constant `NSSpeechPitchModProperty`.
        static std::string speech_pitch_mod_property();
        /// @brief Value of the SDK constant `NSSpeechVolumeProperty`.
        static std::string speech_volume_property();
        /// @brief Value of the SDK constant `NSSpeechSynthesizerInfoProperty`.
        static std::string speech_synthesizer_info_property();
        /// @brief Value of the SDK constant `NSSpeechRecentSyncProperty`.
        static std::string speech_recent_sync_property();
        /// @brief Value of the SDK constant `NSSpeechPhonemeSymbolsProperty`.
        static std::string speech_phoneme_symbols_property();
        /// @brief Value of the SDK constant `NSSpeechCurrentVoiceProperty`.
        static std::string speech_current_voice_property();
        /// @brief Value of the SDK constant `NSSpeechCommandDelimiterProperty`.
        static std::string speech_command_delimiter_property();
        /// @brief Value of the SDK constant `NSSpeechResetProperty`.
        static std::string speech_reset_property();
        /// @brief Value of the SDK constant `NSSpeechOutputToFileURLProperty`.
        static std::string speech_output_to_file_url_property();
    };

    /** @brief Named constants of type `NSSpeechMode`; each function reads the SDK symbol at runtime. */
    struct SpeechMode
    {
        /// @brief Value of the SDK constant `NSSpeechModeText`.
        static std::string text();
        /// @brief Value of the SDK constant `NSSpeechModePhoneme`.
        static std::string phoneme();
        /// @brief Value of the SDK constant `NSSpeechModeNormal`.
        static std::string normal();
        /// @brief Value of the SDK constant `NSSpeechModeLiteral`.
        static std::string literal();
    };

    /** @brief Named constants of type `NSSpeechStatusKey`; each function reads the SDK symbol at runtime. */
    struct SpeechStatusKey
    {
        /// @brief Value of the SDK constant `NSSpeechStatusOutputBusy`.
        static std::string speech_status_output_busy();
        /// @brief Value of the SDK constant `NSSpeechStatusOutputPaused`.
        static std::string speech_status_output_paused();
        /// @brief Value of the SDK constant `NSSpeechStatusNumberOfCharactersLeft`.
        static std::string speech_status_number_of_characters_left();
        /// @brief Value of the SDK constant `NSSpeechStatusPhonemeCode`.
        static std::string speech_status_phoneme_code();
    };

    /** @brief Named constants of type `NSSpeechErrorKey`; each function reads the SDK symbol at runtime. */
    struct SpeechErrorKey
    {
        /// @brief Value of the SDK constant `NSSpeechErrorCount`.
        static std::string speech_error_count();
        /// @brief Value of the SDK constant `NSSpeechErrorOldestCode`.
        static std::string speech_error_oldest_code();
        /// @brief Value of the SDK constant `NSSpeechErrorOldestCharacterOffset`.
        static std::string speech_error_oldest_character_offset();
        /// @brief Value of the SDK constant `NSSpeechErrorNewestCode`.
        static std::string speech_error_newest_code();
        /// @brief Value of the SDK constant `NSSpeechErrorNewestCharacterOffset`.
        static std::string speech_error_newest_character_offset();
    };

    /** @brief Named constants of type `NSSpeechSynthesizerInfoKey`; each function reads the SDK symbol at runtime. */
    struct SpeechSynthesizerInfoKey
    {
        /// @brief Value of the SDK constant `NSSpeechSynthesizerInfoIdentifier`.
        static std::string speech_synthesizer_info_identifier();
        /// @brief Value of the SDK constant `NSSpeechSynthesizerInfoVersion`.
        static std::string speech_synthesizer_info_version();
    };

    /** @brief Named constants of type `NSSpeechPhonemeInfoKey`; each function reads the SDK symbol at runtime. */
    struct SpeechPhonemeInfoKey
    {
        /// @brief Value of the SDK constant `NSSpeechPhonemeInfoOpcode`.
        static std::string speech_phoneme_info_opcode();
        /// @brief Value of the SDK constant `NSSpeechPhonemeInfoSymbol`.
        static std::string speech_phoneme_info_symbol();
        /// @brief Value of the SDK constant `NSSpeechPhonemeInfoExample`.
        static std::string speech_phoneme_info_example();
        /// @brief Value of the SDK constant `NSSpeechPhonemeInfoHiliteStart`.
        static std::string speech_phoneme_info_hilite_start();
        /// @brief Value of the SDK constant `NSSpeechPhonemeInfoHiliteEnd`.
        static std::string speech_phoneme_info_hilite_end();
    };

    /** @brief Named constants of type `NSSpeechCommandDelimiterKey`; each function reads the SDK symbol at runtime. */
    struct SpeechCommandDelimiterKey
    {
        /// @brief Value of the SDK constant `NSSpeechCommandPrefix`.
        static std::string speech_command_prefix();
        /// @brief Value of the SDK constant `NSSpeechCommandSuffix`.
        static std::string speech_command_suffix();
    };

    /** @brief Named constants of type `NSTextCheckingOptionKey`; each function reads the SDK symbol at runtime. */
    struct TextCheckingOptionKey
    {
        /// @brief Value of the SDK constant `NSTextCheckingOrthographyKey`.
        static std::string text_checking_orthography_key();
        /// @brief Value of the SDK constant `NSTextCheckingQuotesKey`.
        static std::string text_checking_quotes_key();
        /// @brief Value of the SDK constant `NSTextCheckingReplacementsKey`.
        static std::string text_checking_replacements_key();
        /// @brief Value of the SDK constant `NSTextCheckingReferenceDateKey`.
        static std::string text_checking_reference_date_key();
        /// @brief Value of the SDK constant `NSTextCheckingReferenceTimeZoneKey`.
        static std::string text_checking_reference_time_zone_key();
        /// @brief Value of the SDK constant `NSTextCheckingDocumentURLKey`.
        static std::string text_checking_document_url_key();
        /// @brief Value of the SDK constant `NSTextCheckingDocumentTitleKey`.
        static std::string text_checking_document_title_key();
        /// @brief Value of the SDK constant `NSTextCheckingDocumentAuthorKey`.
        static std::string text_checking_document_author_key();
        /// @brief Value of the SDK constant `NSTextCheckingRegularExpressionsKey`.
        static std::string text_checking_regular_expressions_key();
        /// @brief Value of the SDK constant `NSTextCheckingSelectedRangeKey`.
        static std::string text_checking_selected_range_key();
        /// @brief Value of the SDK constant `NSTextCheckingGenerateInlinePredictionsKey`.
        static std::string text_checking_generate_inline_predictions_key();
        /// @brief Value of the SDK constant `NSTextCheckingAutomaticCapitalizationEnabledKey`.
        static std::string text_checking_automatic_capitalization_enabled_key();
        /// @brief Value of the SDK constant `NSTextCheckingWaitForAllGrammarCheckingResultsKey`.
        static std::string text_checking_wait_for_all_grammar_checking_results_key();
    };

    /** @brief Named constants of type `NSTextContentType`; each function reads the SDK symbol at runtime. */
    struct TextContentType
    {
        /// @brief Value of the SDK constant `NSTextContentTypeUsername`.
        static std::string username();
        /// @brief Value of the SDK constant `NSTextContentTypePassword`.
        static std::string password();
        /// @brief Value of the SDK constant `NSTextContentTypeOneTimeCode`.
        static std::string one_time_code();
        /// @brief Value of the SDK constant `NSTextContentTypeNewPassword`.
        static std::string new_password();
        /// @brief Value of the SDK constant `NSTextContentTypeName`.
        static std::string name();
        /// @brief Value of the SDK constant `NSTextContentTypeNamePrefix`.
        static std::string name_prefix();
        /// @brief Value of the SDK constant `NSTextContentTypeGivenName`.
        static std::string given_name();
        /// @brief Value of the SDK constant `NSTextContentTypeMiddleName`.
        static std::string middle_name();
        /// @brief Value of the SDK constant `NSTextContentTypeFamilyName`.
        static std::string family_name();
        /// @brief Value of the SDK constant `NSTextContentTypeNameSuffix`.
        static std::string name_suffix();
        /// @brief Value of the SDK constant `NSTextContentTypeNickname`.
        static std::string nickname();
        /// @brief Value of the SDK constant `NSTextContentTypeJobTitle`.
        static std::string job_title();
        /// @brief Value of the SDK constant `NSTextContentTypeOrganizationName`.
        static std::string organization_name();
        /// @brief Value of the SDK constant `NSTextContentTypeLocation`.
        static std::string location();
        /// @brief Value of the SDK constant `NSTextContentTypeFullStreetAddress`.
        static std::string full_street_address();
        /// @brief Value of the SDK constant `NSTextContentTypeStreetAddressLine1`.
        static std::string street_address_line1();
        /// @brief Value of the SDK constant `NSTextContentTypeStreetAddressLine2`.
        static std::string street_address_line2();
        /// @brief Value of the SDK constant `NSTextContentTypeAddressCity`.
        static std::string address_city();
        /// @brief Value of the SDK constant `NSTextContentTypeAddressState`.
        static std::string address_state();
        /// @brief Value of the SDK constant `NSTextContentTypeAddressCityAndState`.
        static std::string address_city_and_state();
        /// @brief Value of the SDK constant `NSTextContentTypeSublocality`.
        static std::string sublocality();
        /// @brief Value of the SDK constant `NSTextContentTypeCountryName`.
        static std::string country_name();
        /// @brief Value of the SDK constant `NSTextContentTypePostalCode`.
        static std::string postal_code();
        /// @brief Value of the SDK constant `NSTextContentTypeTelephoneNumber`.
        static std::string telephone_number();
        /// @brief Value of the SDK constant `NSTextContentTypeEmailAddress`.
        static std::string email_address();
        /// @brief Value of the SDK constant `NSTextContentTypeURL`.
        static std::string url();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardNumber`.
        static std::string credit_card_number();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardName`.
        static std::string credit_card_name();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardGivenName`.
        static std::string credit_card_given_name();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardMiddleName`.
        static std::string credit_card_middle_name();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardFamilyName`.
        static std::string credit_card_family_name();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardSecurityCode`.
        static std::string credit_card_security_code();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardExpiration`.
        static std::string credit_card_expiration();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardExpirationMonth`.
        static std::string credit_card_expiration_month();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardExpirationYear`.
        static std::string credit_card_expiration_year();
        /// @brief Value of the SDK constant `NSTextContentTypeCreditCardType`.
        static std::string credit_card_type();
        /// @brief Value of the SDK constant `NSTextContentTypeShipmentTrackingNumber`.
        static std::string shipment_tracking_number();
        /// @brief Value of the SDK constant `NSTextContentTypeFlightNumber`.
        static std::string flight_number();
        /// @brief Value of the SDK constant `NSTextContentTypeDateTime`.
        static std::string date_time();
        /// @brief Value of the SDK constant `NSTextContentTypeBirthdate`.
        static std::string birthdate();
        /// @brief Value of the SDK constant `NSTextContentTypeBirthdateDay`.
        static std::string birthdate_day();
        /// @brief Value of the SDK constant `NSTextContentTypeBirthdateMonth`.
        static std::string birthdate_month();
        /// @brief Value of the SDK constant `NSTextContentTypeBirthdateYear`.
        static std::string birthdate_year();
    };

    /** @brief Named constants of type `NSPasteboardTypeTextFinderOptionKey`; each function reads the SDK symbol at runtime. */
    struct PasteboardTypeTextFinderOptionKey
    {
        /// @brief Value of the SDK constant `NSTextFinderCaseInsensitiveKey`.
        static std::string text_finder_case_insensitive_key();
        /// @brief Value of the SDK constant `NSTextFinderMatchingTypeKey`.
        static std::string text_finder_matching_type_key();
    };

    /** @brief Named constants of type `NSTextListMarkerFormat`; each function reads the SDK symbol at runtime. */
    struct TextListMarkerFormat
    {
        /// @brief Value of the SDK constant `NSTextListMarkerBox`.
        static std::string text_list_marker_box();
        /// @brief Value of the SDK constant `NSTextListMarkerCheck`.
        static std::string text_list_marker_check();
        /// @brief Value of the SDK constant `NSTextListMarkerCircle`.
        static std::string text_list_marker_circle();
        /// @brief Value of the SDK constant `NSTextListMarkerDiamond`.
        static std::string text_list_marker_diamond();
        /// @brief Value of the SDK constant `NSTextListMarkerDisc`.
        static std::string text_list_marker_disc();
        /// @brief Value of the SDK constant `NSTextListMarkerHyphen`.
        static std::string text_list_marker_hyphen();
        /// @brief Value of the SDK constant `NSTextListMarkerSquare`.
        static std::string text_list_marker_square();
        /// @brief Value of the SDK constant `NSTextListMarkerLowercaseHexadecimal`.
        static std::string text_list_marker_lowercase_hexadecimal();
        /// @brief Value of the SDK constant `NSTextListMarkerUppercaseHexadecimal`.
        static std::string text_list_marker_uppercase_hexadecimal();
        /// @brief Value of the SDK constant `NSTextListMarkerOctal`.
        static std::string text_list_marker_octal();
        /// @brief Value of the SDK constant `NSTextListMarkerLowercaseAlpha`.
        static std::string text_list_marker_lowercase_alpha();
        /// @brief Value of the SDK constant `NSTextListMarkerUppercaseAlpha`.
        static std::string text_list_marker_uppercase_alpha();
        /// @brief Value of the SDK constant `NSTextListMarkerLowercaseLatin`.
        static std::string text_list_marker_lowercase_latin();
        /// @brief Value of the SDK constant `NSTextListMarkerUppercaseLatin`.
        static std::string text_list_marker_uppercase_latin();
        /// @brief Value of the SDK constant `NSTextListMarkerLowercaseRoman`.
        static std::string text_list_marker_lowercase_roman();
        /// @brief Value of the SDK constant `NSTextListMarkerUppercaseRoman`.
        static std::string text_list_marker_uppercase_roman();
        /// @brief Value of the SDK constant `NSTextListMarkerDecimal`.
        static std::string text_list_marker_decimal();
    };

    /** @brief Named constants of type `NSPasteboardTypeFindPanelSearchOptionKey`; each function reads the SDK symbol at runtime. */
    struct PasteboardTypeFindPanelSearchOptionKey
    {
        /// @brief Value of the SDK constant `NSFindPanelCaseInsensitiveSearch`.
        static std::string find_panel_case_insensitive_search();
        /// @brief Value of the SDK constant `NSFindPanelSubstringMatch`.
        static std::string find_panel_substring_match();
    };

    /** @brief Named constants of type `NSToolbarUserInfoKey`; each function reads the SDK symbol at runtime. */
    struct ToolbarUserInfoKey
    {
        /// @brief Value of the SDK constant `NSToolbarItemKey`.
        static std::string toolbar_item_key();
        /// @brief Value of the SDK constant `NSToolbarNewIndexKey`.
        static std::string toolbar_new_index_key();
    };

    /** @brief Named constants of type `NSToolbarItemIdentifier`; each function reads the SDK symbol at runtime. */
    struct ToolbarItemIdentifier
    {
        /// @brief Value of the SDK constant `NSToolbarSpaceItemIdentifier`.
        static std::string toolbar_space_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarFlexibleSpaceItemIdentifier`.
        static std::string toolbar_flexible_space_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarShowColorsItemIdentifier`.
        static std::string toolbar_show_colors_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarShowFontsItemIdentifier`.
        static std::string toolbar_show_fonts_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarPrintItemIdentifier`.
        static std::string toolbar_print_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarToggleSidebarItemIdentifier`.
        static std::string toolbar_toggle_sidebar_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarToggleInspectorItemIdentifier`.
        static std::string toolbar_toggle_inspector_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarCloudSharingItemIdentifier`.
        static std::string toolbar_cloud_sharing_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarWritingToolsItemIdentifier`.
        static std::string toolbar_writing_tools_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarSidebarTrackingSeparatorItemIdentifier`.
        static std::string toolbar_sidebar_tracking_separator_item_identifier();
        /// @brief Value of the SDK constant `NSToolbarInspectorTrackingSeparatorItemIdentifier`.
        static std::string toolbar_inspector_tracking_separator_item_identifier();
    };

    /** @brief Named constants of type `NSViewFullScreenModeOptionKey`; each function reads the SDK symbol at runtime. */
    struct ViewFullScreenModeOptionKey
    {
        /// @brief Value of the SDK constant `NSFullScreenModeAllScreens`.
        static std::string full_screen_mode_all_screens();
        /// @brief Value of the SDK constant `NSFullScreenModeSetting`.
        static std::string full_screen_mode_setting();
        /// @brief Value of the SDK constant `NSFullScreenModeWindowLevel`.
        static std::string full_screen_mode_window_level();
        /// @brief Value of the SDK constant `NSFullScreenModeApplicationPresentationOptions`.
        static std::string full_screen_mode_application_presentation_options();
    };

    /** @brief Named constants of type `NSDefinitionOptionKey`; each function reads the SDK symbol at runtime. */
    struct DefinitionOptionKey
    {
        /// @brief Value of the SDK constant `NSDefinitionPresentationTypeKey`.
        static std::string definition_presentation_type_key();
    };

    /** @brief Named constants of type `NSDefinitionPresentationType`; each function reads the SDK symbol at runtime. */
    struct DefinitionPresentationType
    {
        /// @brief Value of the SDK constant `NSDefinitionPresentationTypeOverlay`.
        static std::string overlay();
        /// @brief Value of the SDK constant `NSDefinitionPresentationTypeDictionaryApplication`.
        static std::string dictionary_application();
    };

    /** @brief Named constants of type `NSWorkspaceDesktopImageOptionKey`; each function reads the SDK symbol at runtime. */
    struct WorkspaceDesktopImageOptionKey
    {
        /// @brief Value of the SDK constant `NSWorkspaceDesktopImageScalingKey`.
        static std::string workspace_desktop_image_scaling_key();
        /// @brief Value of the SDK constant `NSWorkspaceDesktopImageAllowClippingKey`.
        static std::string workspace_desktop_image_allow_clipping_key();
        /// @brief Value of the SDK constant `NSWorkspaceDesktopImageFillColorKey`.
        static std::string workspace_desktop_image_fill_color_key();
    };

    /** @brief Named constants of type `NSAttributedStringFormattingContextKey`; each function reads the SDK symbol at runtime. */
    struct AttributedStringFormattingContextKey
    {
        /// @brief Value of the SDK constant `NSInflectionConceptsKey`.
        static std::string inflection_concepts_key();
    };

    /** @brief Named constants of type `NSCalendarIdentifier`; each function reads the SDK symbol at runtime. */
    struct CalendarIdentifier
    {
        /// @brief Value of the SDK constant `NSCalendarIdentifierGregorian`.
        static std::string gregorian();
        /// @brief Value of the SDK constant `NSCalendarIdentifierBuddhist`.
        static std::string buddhist();
        /// @brief Value of the SDK constant `NSCalendarIdentifierChinese`.
        static std::string chinese();
        /// @brief Value of the SDK constant `NSCalendarIdentifierCoptic`.
        static std::string coptic();
        /// @brief Value of the SDK constant `NSCalendarIdentifierEthiopicAmeteMihret`.
        static std::string ethiopic_amete_mihret();
        /// @brief Value of the SDK constant `NSCalendarIdentifierEthiopicAmeteAlem`.
        static std::string ethiopic_amete_alem();
        /// @brief Value of the SDK constant `NSCalendarIdentifierHebrew`.
        static std::string hebrew();
        /// @brief Value of the SDK constant `NSCalendarIdentifierISO8601`.
        static std::string iso8601();
        /// @brief Value of the SDK constant `NSCalendarIdentifierIndian`.
        static std::string indian();
        /// @brief Value of the SDK constant `NSCalendarIdentifierIslamic`.
        static std::string islamic();
        /// @brief Value of the SDK constant `NSCalendarIdentifierIslamicCivil`.
        static std::string islamic_civil();
        /// @brief Value of the SDK constant `NSCalendarIdentifierJapanese`.
        static std::string japanese();
        /// @brief Value of the SDK constant `NSCalendarIdentifierPersian`.
        static std::string persian();
        /// @brief Value of the SDK constant `NSCalendarIdentifierRepublicOfChina`.
        static std::string republic_of_china();
        /// @brief Value of the SDK constant `NSCalendarIdentifierIslamicTabular`.
        static std::string islamic_tabular();
        /// @brief Value of the SDK constant `NSCalendarIdentifierIslamicUmmAlQura`.
        static std::string islamic_umm_al_qura();
        /// @brief Value of the SDK constant `NSCalendarIdentifierBangla`.
        static std::string bangla();
        /// @brief Value of the SDK constant `NSCalendarIdentifierGujarati`.
        static std::string gujarati();
        /// @brief Value of the SDK constant `NSCalendarIdentifierKannada`.
        static std::string kannada();
        /// @brief Value of the SDK constant `NSCalendarIdentifierMalayalam`.
        static std::string malayalam();
        /// @brief Value of the SDK constant `NSCalendarIdentifierMarathi`.
        static std::string marathi();
        /// @brief Value of the SDK constant `NSCalendarIdentifierOdia`.
        static std::string odia();
        /// @brief Value of the SDK constant `NSCalendarIdentifierTamil`.
        static std::string tamil();
        /// @brief Value of the SDK constant `NSCalendarIdentifierTelugu`.
        static std::string telugu();
        /// @brief Value of the SDK constant `NSCalendarIdentifierVikram`.
        static std::string vikram();
        /// @brief Value of the SDK constant `NSCalendarIdentifierDangi`.
        static std::string dangi();
        /// @brief Value of the SDK constant `NSCalendarIdentifierVietnamese`.
        static std::string vietnamese();
    };

    /** @brief Named constants of type `NSDistributedNotificationCenterType`; each function reads the SDK symbol at runtime. */
    struct DistributedNotificationCenterType
    {
        /// @brief Value of the SDK constant `NSLocalNotificationCenterType`.
        static std::string local_notification_center_type();
    };

    /** @brief Named constants of type `NSErrorDomain`; each function reads the SDK symbol at runtime. */
    struct ErrorDomain
    {
        /// @brief Value of the SDK constant `NSCocoaErrorDomain`.
        static std::string cocoa_error_domain();
        /// @brief Value of the SDK constant `NSPOSIXErrorDomain`.
        static std::string posix_error_domain();
        /// @brief Value of the SDK constant `NSOSStatusErrorDomain`.
        static std::string os_status_error_domain();
        /// @brief Value of the SDK constant `NSMachErrorDomain`.
        static std::string mach_error_domain();
        /// @brief Value of the SDK constant `NSNetServicesErrorDomain`.
        static std::string net_services_error_domain();
        /// @brief Value of the SDK constant `NSStreamSocketSSLErrorDomain`.
        static std::string stream_socket_ssl_error_domain();
        /// @brief Value of the SDK constant `NSStreamSOCKSErrorDomain`.
        static std::string stream_socks_error_domain();
        /// @brief Value of the SDK constant `NSURLErrorDomain`.
        static std::string url_error_domain();
        /// @brief Value of the SDK constant `NSXMLParserErrorDomain`.
        static std::string xml_parser_error_domain();
    };

    /** @brief Named constants of type `NSErrorUserInfoKey`; each function reads the SDK symbol at runtime. */
    struct ErrorUserInfoKey
    {
        /// @brief Value of the SDK constant `NSUnderlyingErrorKey`.
        static std::string underlying_error_key();
        /// @brief Value of the SDK constant `NSMultipleUnderlyingErrorsKey`.
        static std::string multiple_underlying_errors_key();
        /// @brief Value of the SDK constant `NSLocalizedDescriptionKey`.
        static std::string localized_description_key();
        /// @brief Value of the SDK constant `NSLocalizedFailureReasonErrorKey`.
        static std::string localized_failure_reason_error_key();
        /// @brief Value of the SDK constant `NSLocalizedRecoverySuggestionErrorKey`.
        static std::string localized_recovery_suggestion_error_key();
        /// @brief Value of the SDK constant `NSLocalizedRecoveryOptionsErrorKey`.
        static std::string localized_recovery_options_error_key();
        /// @brief Value of the SDK constant `NSRecoveryAttempterErrorKey`.
        static std::string recovery_attempter_error_key();
        /// @brief Value of the SDK constant `NSHelpAnchorErrorKey`.
        static std::string help_anchor_error_key();
        /// @brief Value of the SDK constant `NSDebugDescriptionErrorKey`.
        static std::string debug_description_error_key();
        /// @brief Value of the SDK constant `NSLocalizedFailureErrorKey`.
        static std::string localized_failure_error_key();
        /// @brief Value of the SDK constant `NSStringEncodingErrorKey`.
        static std::string string_encoding_error_key();
        /// @brief Value of the SDK constant `NSURLErrorKey`.
        static std::string url_error_key();
        /// @brief Value of the SDK constant `NSFilePathErrorKey`.
        static std::string file_path_error_key();
        /// @brief Value of the SDK constant `NSURLErrorNetworkUnavailableReasonKey`.
        static std::string url_error_network_unavailable_reason_key();
    };

    /** @brief Named constants of type `NSFileAttributeKey`; each function reads the SDK symbol at runtime. */
    struct FileAttributeKey
    {
        /// @brief Value of the SDK constant `NSFileType`.
        static std::string file_type();
        /// @brief Value of the SDK constant `NSFileSize`.
        static std::string file_size();
        /// @brief Value of the SDK constant `NSFileModificationDate`.
        static std::string file_modification_date();
        /// @brief Value of the SDK constant `NSFileReferenceCount`.
        static std::string file_reference_count();
        /// @brief Value of the SDK constant `NSFileDeviceIdentifier`.
        static std::string file_device_identifier();
        /// @brief Value of the SDK constant `NSFileOwnerAccountName`.
        static std::string file_owner_account_name();
        /// @brief Value of the SDK constant `NSFileGroupOwnerAccountName`.
        static std::string file_group_owner_account_name();
        /// @brief Value of the SDK constant `NSFilePosixPermissions`.
        static std::string file_posix_permissions();
        /// @brief Value of the SDK constant `NSFileSystemNumber`.
        static std::string file_system_number();
        /// @brief Value of the SDK constant `NSFileSystemFileNumber`.
        static std::string file_system_file_number();
        /// @brief Value of the SDK constant `NSFileExtensionHidden`.
        static std::string file_extension_hidden();
        /// @brief Value of the SDK constant `NSFileHFSCreatorCode`.
        static std::string file_hfs_creator_code();
        /// @brief Value of the SDK constant `NSFileHFSTypeCode`.
        static std::string file_hfs_type_code();
        /// @brief Value of the SDK constant `NSFileImmutable`.
        static std::string file_immutable();
        /// @brief Value of the SDK constant `NSFileAppendOnly`.
        static std::string file_append_only();
        /// @brief Value of the SDK constant `NSFileCreationDate`.
        static std::string file_creation_date();
        /// @brief Value of the SDK constant `NSFileOwnerAccountID`.
        static std::string file_owner_account_id();
        /// @brief Value of the SDK constant `NSFileGroupOwnerAccountID`.
        static std::string file_group_owner_account_id();
        /// @brief Value of the SDK constant `NSFileBusy`.
        static std::string file_busy();
        /// @brief Value of the SDK constant `NSFileProtectionKey`.
        static std::string file_protection_key();
        /// @brief Value of the SDK constant `NSFileSystemSize`.
        static std::string file_system_size();
        /// @brief Value of the SDK constant `NSFileSystemFreeSize`.
        static std::string file_system_free_size();
        /// @brief Value of the SDK constant `NSFileSystemNodes`.
        static std::string file_system_nodes();
        /// @brief Value of the SDK constant `NSFileSystemFreeNodes`.
        static std::string file_system_free_nodes();
    };

    /** @brief Named constants of type `NSFileAttributeType`; each function reads the SDK symbol at runtime. */
    struct FileAttributeType
    {
        /// @brief Value of the SDK constant `NSFileTypeDirectory`.
        static std::string file_type_directory();
        /// @brief Value of the SDK constant `NSFileTypeRegular`.
        static std::string file_type_regular();
        /// @brief Value of the SDK constant `NSFileTypeSymbolicLink`.
        static std::string file_type_symbolic_link();
        /// @brief Value of the SDK constant `NSFileTypeSocket`.
        static std::string file_type_socket();
        /// @brief Value of the SDK constant `NSFileTypeCharacterSpecial`.
        static std::string file_type_character_special();
        /// @brief Value of the SDK constant `NSFileTypeBlockSpecial`.
        static std::string file_type_block_special();
        /// @brief Value of the SDK constant `NSFileTypeUnknown`.
        static std::string file_type_unknown();
    };

    /** @brief Named constants of type `NSFileProtectionType`; each function reads the SDK symbol at runtime. */
    struct FileProtectionType
    {
        /// @brief Value of the SDK constant `NSFileProtectionNone`.
        static std::string file_protection_none();
        /// @brief Value of the SDK constant `NSFileProtectionComplete`.
        static std::string file_protection_complete();
        /// @brief Value of the SDK constant `NSFileProtectionCompleteUnlessOpen`.
        static std::string file_protection_complete_unless_open();
        /// @brief Value of the SDK constant `NSFileProtectionCompleteUntilFirstUserAuthentication`.
        static std::string file_protection_complete_until_first_user_authentication();
    };

    /** @brief Named constants of type `NSHTTPCookiePropertyKey`; each function reads the SDK symbol at runtime. */
    struct HTTPCookiePropertyKey
    {
        /// @brief Value of the SDK constant `NSHTTPCookieName`.
        static std::string http_cookie_name();
        /// @brief Value of the SDK constant `NSHTTPCookieValue`.
        static std::string http_cookie_value();
        /// @brief Value of the SDK constant `NSHTTPCookieOriginURL`.
        static std::string http_cookie_origin_url();
        /// @brief Value of the SDK constant `NSHTTPCookieVersion`.
        static std::string http_cookie_version();
        /// @brief Value of the SDK constant `NSHTTPCookieDomain`.
        static std::string http_cookie_domain();
        /// @brief Value of the SDK constant `NSHTTPCookiePath`.
        static std::string http_cookie_path();
        /// @brief Value of the SDK constant `NSHTTPCookieSecure`.
        static std::string http_cookie_secure();
        /// @brief Value of the SDK constant `NSHTTPCookieExpires`.
        static std::string http_cookie_expires();
        /// @brief Value of the SDK constant `NSHTTPCookieComment`.
        static std::string http_cookie_comment();
        /// @brief Value of the SDK constant `NSHTTPCookieCommentURL`.
        static std::string http_cookie_comment_url();
        /// @brief Value of the SDK constant `NSHTTPCookieDiscard`.
        static std::string http_cookie_discard();
        /// @brief Value of the SDK constant `NSHTTPCookieMaximumAge`.
        static std::string http_cookie_maximum_age();
        /// @brief Value of the SDK constant `NSHTTPCookiePort`.
        static std::string http_cookie_port();
        /// @brief Value of the SDK constant `NSHTTPCookieSetByJavaScript`.
        static std::string http_cookie_set_by_java_script();
        /// @brief Value of the SDK constant `NSHTTPCookieSameSitePolicy`.
        static std::string http_cookie_same_site_policy();
    };

    /** @brief Named constants of type `NSHTTPCookieStringPolicy`; each function reads the SDK symbol at runtime. */
    struct HTTPCookieStringPolicy
    {
        /// @brief Value of the SDK constant `NSHTTPCookieSameSiteLax`.
        static std::string http_cookie_same_site_lax();
        /// @brief Value of the SDK constant `NSHTTPCookieSameSiteStrict`.
        static std::string http_cookie_same_site_strict();
    };

    /** @brief Named constants of type `NSKeyValueOperator`; each function reads the SDK symbol at runtime. */
    struct KeyValueOperator
    {
        /// @brief Value of the SDK constant `NSAverageKeyValueOperator`.
        static std::string average_key_value_operator();
        /// @brief Value of the SDK constant `NSCountKeyValueOperator`.
        static std::string count_key_value_operator();
        /// @brief Value of the SDK constant `NSDistinctUnionOfArraysKeyValueOperator`.
        static std::string distinct_union_of_arrays_key_value_operator();
        /// @brief Value of the SDK constant `NSDistinctUnionOfObjectsKeyValueOperator`.
        static std::string distinct_union_of_objects_key_value_operator();
        /// @brief Value of the SDK constant `NSDistinctUnionOfSetsKeyValueOperator`.
        static std::string distinct_union_of_sets_key_value_operator();
        /// @brief Value of the SDK constant `NSMaximumKeyValueOperator`.
        static std::string maximum_key_value_operator();
        /// @brief Value of the SDK constant `NSMinimumKeyValueOperator`.
        static std::string minimum_key_value_operator();
        /// @brief Value of the SDK constant `NSSumKeyValueOperator`.
        static std::string sum_key_value_operator();
        /// @brief Value of the SDK constant `NSUnionOfArraysKeyValueOperator`.
        static std::string union_of_arrays_key_value_operator();
        /// @brief Value of the SDK constant `NSUnionOfObjectsKeyValueOperator`.
        static std::string union_of_objects_key_value_operator();
        /// @brief Value of the SDK constant `NSUnionOfSetsKeyValueOperator`.
        static std::string union_of_sets_key_value_operator();
    };

    /** @brief Named constants of type `NSKeyValueChangeKey`; each function reads the SDK symbol at runtime. */
    struct KeyValueChangeKey
    {
        /// @brief Value of the SDK constant `NSKeyValueChangeKindKey`.
        static std::string key_value_change_kind_key();
        /// @brief Value of the SDK constant `NSKeyValueChangeNewKey`.
        static std::string key_value_change_new_key();
        /// @brief Value of the SDK constant `NSKeyValueChangeOldKey`.
        static std::string key_value_change_old_key();
        /// @brief Value of the SDK constant `NSKeyValueChangeIndexesKey`.
        static std::string key_value_change_indexes_key();
        /// @brief Value of the SDK constant `NSKeyValueChangeNotificationIsPriorKey`.
        static std::string key_value_change_notification_is_prior_key();
    };

    /** @brief Named constants of type `NSLocaleKey`; each function reads the SDK symbol at runtime. */
    struct LocaleKey
    {
        /// @brief Value of the SDK constant `NSLocaleIdentifier`.
        static std::string locale_identifier();
        /// @brief Value of the SDK constant `NSLocaleLanguageCode`.
        static std::string locale_language_code();
        /// @brief Value of the SDK constant `NSLocaleCountryCode`.
        static std::string locale_country_code();
        /// @brief Value of the SDK constant `NSLocaleScriptCode`.
        static std::string locale_script_code();
        /// @brief Value of the SDK constant `NSLocaleVariantCode`.
        static std::string locale_variant_code();
        /// @brief Value of the SDK constant `NSLocaleExemplarCharacterSet`.
        static std::string locale_exemplar_character_set();
        /// @brief Value of the SDK constant `NSLocaleCalendar`.
        static std::string locale_calendar();
        /// @brief Value of the SDK constant `NSLocaleCollationIdentifier`.
        static std::string locale_collation_identifier();
        /// @brief Value of the SDK constant `NSLocaleUsesMetricSystem`.
        static std::string locale_uses_metric_system();
        /// @brief Value of the SDK constant `NSLocaleMeasurementSystem`.
        static std::string locale_measurement_system();
        /// @brief Value of the SDK constant `NSLocaleDecimalSeparator`.
        static std::string locale_decimal_separator();
        /// @brief Value of the SDK constant `NSLocaleGroupingSeparator`.
        static std::string locale_grouping_separator();
        /// @brief Value of the SDK constant `NSLocaleCurrencySymbol`.
        static std::string locale_currency_symbol();
        /// @brief Value of the SDK constant `NSLocaleCurrencyCode`.
        static std::string locale_currency_code();
        /// @brief Value of the SDK constant `NSLocaleCollatorIdentifier`.
        static std::string locale_collator_identifier();
        /// @brief Value of the SDK constant `NSLocaleQuotationBeginDelimiterKey`.
        static std::string locale_quotation_begin_delimiter_key();
        /// @brief Value of the SDK constant `NSLocaleQuotationEndDelimiterKey`.
        static std::string locale_quotation_end_delimiter_key();
        /// @brief Value of the SDK constant `NSLocaleAlternateQuotationBeginDelimiterKey`.
        static std::string locale_alternate_quotation_begin_delimiter_key();
        /// @brief Value of the SDK constant `NSLocaleAlternateQuotationEndDelimiterKey`.
        static std::string locale_alternate_quotation_end_delimiter_key();
    };

    /** @brief Named constants of type `NSProgressUserInfoKey`; each function reads the SDK symbol at runtime. */
    struct ProgressUserInfoKey
    {
        /// @brief Value of the SDK constant `NSProgressEstimatedTimeRemainingKey`.
        static std::string progress_estimated_time_remaining_key();
        /// @brief Value of the SDK constant `NSProgressThroughputKey`.
        static std::string progress_throughput_key();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindKey`.
        static std::string progress_file_operation_kind_key();
        /// @brief Value of the SDK constant `NSProgressFileURLKey`.
        static std::string progress_file_url_key();
        /// @brief Value of the SDK constant `NSProgressFileTotalCountKey`.
        static std::string progress_file_total_count_key();
        /// @brief Value of the SDK constant `NSProgressFileCompletedCountKey`.
        static std::string progress_file_completed_count_key();
        /// @brief Value of the SDK constant `NSProgressFileAnimationImageKey`.
        static std::string progress_file_animation_image_key();
        /// @brief Value of the SDK constant `NSProgressFileAnimationImageOriginalRectKey`.
        static std::string progress_file_animation_image_original_rect_key();
        /// @brief Value of the SDK constant `NSProgressFileIconKey`.
        static std::string progress_file_icon_key();
    };

    /** @brief Named constants of type `NSProgressKind`; each function reads the SDK symbol at runtime. */
    struct ProgressKind
    {
        /// @brief Value of the SDK constant `NSProgressKindFile`.
        static std::string file();
    };

    /** @brief Named constants of type `NSProgressFileOperationKind`; each function reads the SDK symbol at runtime. */
    struct ProgressFileOperationKind
    {
        /// @brief Value of the SDK constant `NSProgressFileOperationKindDownloading`.
        static std::string downloading();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindDecompressingAfterDownloading`.
        static std::string decompressing_after_downloading();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindReceiving`.
        static std::string receiving();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindCopying`.
        static std::string copying();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindUploading`.
        static std::string uploading();
        /// @brief Value of the SDK constant `NSProgressFileOperationKindDuplicating`.
        static std::string duplicating();
    };

    /** @brief Named constants of type `NSStreamPropertyKey`; each function reads the SDK symbol at runtime. */
    struct StreamPropertyKey
    {
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelKey`.
        static std::string stream_socket_security_level_key();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyConfigurationKey`.
        static std::string stream_socks_proxy_configuration_key();
        /// @brief Value of the SDK constant `NSStreamDataWrittenToMemoryStreamKey`.
        static std::string stream_data_written_to_memory_stream_key();
        /// @brief Value of the SDK constant `NSStreamFileCurrentOffsetKey`.
        static std::string stream_file_current_offset_key();
        /// @brief Value of the SDK constant `NSStreamNetworkServiceType`.
        static std::string stream_network_service_type();
    };

    /** @brief Named constants of type `NSStreamSocketSecurityLevel`; each function reads the SDK symbol at runtime. */
    struct StreamSocketSecurityLevel
    {
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelNone`.
        static std::string none();
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelSSLv2`.
        static std::string ss_lv2();
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelSSLv3`.
        static std::string ss_lv3();
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelTLSv1`.
        static std::string tl_sv1();
        /// @brief Value of the SDK constant `NSStreamSocketSecurityLevelNegotiatedSSL`.
        static std::string negotiated_ssl();
    };

    /** @brief Named constants of type `NSStreamSOCKSProxyConfiguration`; each function reads the SDK symbol at runtime. */
    struct StreamSOCKSProxyConfiguration
    {
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyHostKey`.
        static std::string stream_socks_proxy_host_key();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyPortKey`.
        static std::string stream_socks_proxy_port_key();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyVersionKey`.
        static std::string stream_socks_proxy_version_key();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyUserKey`.
        static std::string stream_socks_proxy_user_key();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyPasswordKey`.
        static std::string stream_socks_proxy_password_key();
    };

    /** @brief Named constants of type `NSStreamSOCKSProxyVersion`; each function reads the SDK symbol at runtime. */
    struct StreamSOCKSProxyVersion
    {
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyVersion4`.
        static std::string n4();
        /// @brief Value of the SDK constant `NSStreamSOCKSProxyVersion5`.
        static std::string n5();
    };

    /** @brief Named constants of type `NSStreamNetworkServiceTypeValue`; each function reads the SDK symbol at runtime. */
    struct StreamNetworkServiceTypeValue
    {
        /// @brief Value of the SDK constant `NSStreamNetworkServiceTypeVoIP`.
        static std::string stream_network_service_type_vo_ip();
        /// @brief Value of the SDK constant `NSStreamNetworkServiceTypeVideo`.
        static std::string stream_network_service_type_video();
        /// @brief Value of the SDK constant `NSStreamNetworkServiceTypeBackground`.
        static std::string stream_network_service_type_background();
        /// @brief Value of the SDK constant `NSStreamNetworkServiceTypeVoice`.
        static std::string stream_network_service_type_voice();
        /// @brief Value of the SDK constant `NSStreamNetworkServiceTypeCallSignaling`.
        static std::string stream_network_service_type_call_signaling();
    };

    /** @brief Named constants of type `NSStringTransform`; each function reads the SDK symbol at runtime. */
    struct StringTransform
    {
        /// @brief Value of the SDK constant `NSStringTransformLatinToKatakana`.
        static std::string latin_to_katakana();
        /// @brief Value of the SDK constant `NSStringTransformLatinToHiragana`.
        static std::string latin_to_hiragana();
        /// @brief Value of the SDK constant `NSStringTransformLatinToHangul`.
        static std::string latin_to_hangul();
        /// @brief Value of the SDK constant `NSStringTransformLatinToArabic`.
        static std::string latin_to_arabic();
        /// @brief Value of the SDK constant `NSStringTransformLatinToHebrew`.
        static std::string latin_to_hebrew();
        /// @brief Value of the SDK constant `NSStringTransformLatinToThai`.
        static std::string latin_to_thai();
        /// @brief Value of the SDK constant `NSStringTransformLatinToCyrillic`.
        static std::string latin_to_cyrillic();
        /// @brief Value of the SDK constant `NSStringTransformLatinToGreek`.
        static std::string latin_to_greek();
        /// @brief Value of the SDK constant `NSStringTransformToLatin`.
        static std::string to_latin();
        /// @brief Value of the SDK constant `NSStringTransformMandarinToLatin`.
        static std::string mandarin_to_latin();
        /// @brief Value of the SDK constant `NSStringTransformHiraganaToKatakana`.
        static std::string hiragana_to_katakana();
        /// @brief Value of the SDK constant `NSStringTransformFullwidthToHalfwidth`.
        static std::string fullwidth_to_halfwidth();
        /// @brief Value of the SDK constant `NSStringTransformToXMLHex`.
        static std::string to_xml_hex();
        /// @brief Value of the SDK constant `NSStringTransformToUnicodeName`.
        static std::string to_unicode_name();
        /// @brief Value of the SDK constant `NSStringTransformStripCombiningMarks`.
        static std::string strip_combining_marks();
        /// @brief Value of the SDK constant `NSStringTransformStripDiacritics`.
        static std::string strip_diacritics();
    };

    /** @brief Named constants of type `NSStringEncodingDetectionOptionsKey`; each function reads the SDK symbol at runtime. */
    struct StringEncodingDetectionOptionsKey
    {
        /// @brief Value of the SDK constant `NSStringEncodingDetectionSuggestedEncodingsKey`.
        static std::string string_encoding_detection_suggested_encodings_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionDisallowedEncodingsKey`.
        static std::string string_encoding_detection_disallowed_encodings_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionUseOnlySuggestedEncodingsKey`.
        static std::string string_encoding_detection_use_only_suggested_encodings_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionAllowLossyKey`.
        static std::string string_encoding_detection_allow_lossy_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionFromWindowsKey`.
        static std::string string_encoding_detection_from_windows_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionLossySubstitutionKey`.
        static std::string string_encoding_detection_lossy_substitution_key();
        /// @brief Value of the SDK constant `NSStringEncodingDetectionLikelyLanguageKey`.
        static std::string string_encoding_detection_likely_language_key();
    };

    /** @brief Named constants of type `NSTextCheckingKey`; each function reads the SDK symbol at runtime. */
    struct TextCheckingKey
    {
        /// @brief Value of the SDK constant `NSTextCheckingNameKey`.
        static std::string text_checking_name_key();
        /// @brief Value of the SDK constant `NSTextCheckingJobTitleKey`.
        static std::string text_checking_job_title_key();
        /// @brief Value of the SDK constant `NSTextCheckingOrganizationKey`.
        static std::string text_checking_organization_key();
        /// @brief Value of the SDK constant `NSTextCheckingStreetKey`.
        static std::string text_checking_street_key();
        /// @brief Value of the SDK constant `NSTextCheckingCityKey`.
        static std::string text_checking_city_key();
        /// @brief Value of the SDK constant `NSTextCheckingStateKey`.
        static std::string text_checking_state_key();
        /// @brief Value of the SDK constant `NSTextCheckingZIPKey`.
        static std::string text_checking_zip_key();
        /// @brief Value of the SDK constant `NSTextCheckingCountryKey`.
        static std::string text_checking_country_key();
        /// @brief Value of the SDK constant `NSTextCheckingPhoneKey`.
        static std::string text_checking_phone_key();
        /// @brief Value of the SDK constant `NSTextCheckingAirlineKey`.
        static std::string text_checking_airline_key();
        /// @brief Value of the SDK constant `NSTextCheckingFlightKey`.
        static std::string text_checking_flight_key();
    };

    /** @brief Named constants of type `NSURLResourceKey`; each function reads the SDK symbol at runtime. */
    struct URLResourceKey
    {
        /// @brief Value of the SDK constant `NSURLKeysOfUnsetValuesKey`.
        static std::string url_keys_of_unset_values_key();
        /// @brief Value of the SDK constant `NSURLNameKey`.
        static std::string url_name_key();
        /// @brief Value of the SDK constant `NSURLLocalizedNameKey`.
        static std::string url_localized_name_key();
        /// @brief Value of the SDK constant `NSURLIsRegularFileKey`.
        static std::string url_is_regular_file_key();
        /// @brief Value of the SDK constant `NSURLIsDirectoryKey`.
        static std::string url_is_directory_key();
        /// @brief Value of the SDK constant `NSURLIsSymbolicLinkKey`.
        static std::string url_is_symbolic_link_key();
        /// @brief Value of the SDK constant `NSURLIsVolumeKey`.
        static std::string url_is_volume_key();
        /// @brief Value of the SDK constant `NSURLIsPackageKey`.
        static std::string url_is_package_key();
        /// @brief Value of the SDK constant `NSURLIsApplicationKey`.
        static std::string url_is_application_key();
        /// @brief Value of the SDK constant `NSURLApplicationIsScriptableKey`.
        static std::string url_application_is_scriptable_key();
        /// @brief Value of the SDK constant `NSURLIsSystemImmutableKey`.
        static std::string url_is_system_immutable_key();
        /// @brief Value of the SDK constant `NSURLIsUserImmutableKey`.
        static std::string url_is_user_immutable_key();
        /// @brief Value of the SDK constant `NSURLIsHiddenKey`.
        static std::string url_is_hidden_key();
        /// @brief Value of the SDK constant `NSURLHasHiddenExtensionKey`.
        static std::string url_has_hidden_extension_key();
        /// @brief Value of the SDK constant `NSURLCreationDateKey`.
        static std::string url_creation_date_key();
        /// @brief Value of the SDK constant `NSURLContentAccessDateKey`.
        static std::string url_content_access_date_key();
        /// @brief Value of the SDK constant `NSURLContentModificationDateKey`.
        static std::string url_content_modification_date_key();
        /// @brief Value of the SDK constant `NSURLAttributeModificationDateKey`.
        static std::string url_attribute_modification_date_key();
        /// @brief Value of the SDK constant `NSURLLinkCountKey`.
        static std::string url_link_count_key();
        /// @brief Value of the SDK constant `NSURLParentDirectoryURLKey`.
        static std::string url_parent_directory_url_key();
        /// @brief Value of the SDK constant `NSURLVolumeURLKey`.
        static std::string url_volume_url_key();
        /// @brief Value of the SDK constant `NSURLContentTypeKey`.
        static std::string url_content_type_key();
        /// @brief Value of the SDK constant `NSURLLocalizedTypeDescriptionKey`.
        static std::string url_localized_type_description_key();
        /// @brief Value of the SDK constant `NSURLLabelNumberKey`.
        static std::string url_label_number_key();
        /// @brief Value of the SDK constant `NSURLLabelColorKey`.
        static std::string url_label_color_key();
        /// @brief Value of the SDK constant `NSURLLocalizedLabelKey`.
        static std::string url_localized_label_key();
        /// @brief Value of the SDK constant `NSURLEffectiveIconKey`.
        static std::string url_effective_icon_key();
        /// @brief Value of the SDK constant `NSURLCustomIconKey`.
        static std::string url_custom_icon_key();
        /// @brief Value of the SDK constant `NSURLFileResourceIdentifierKey`.
        static std::string url_file_resource_identifier_key();
        /// @brief Value of the SDK constant `NSURLVolumeIdentifierKey`.
        static std::string url_volume_identifier_key();
        /// @brief Value of the SDK constant `NSURLPreferredIOBlockSizeKey`.
        static std::string url_preferred_io_block_size_key();
        /// @brief Value of the SDK constant `NSURLIsReadableKey`.
        static std::string url_is_readable_key();
        /// @brief Value of the SDK constant `NSURLIsWritableKey`.
        static std::string url_is_writable_key();
        /// @brief Value of the SDK constant `NSURLIsExecutableKey`.
        static std::string url_is_executable_key();
        /// @brief Value of the SDK constant `NSURLFileSecurityKey`.
        static std::string url_file_security_key();
        /// @brief Value of the SDK constant `NSURLIsExcludedFromBackupKey`.
        static std::string url_is_excluded_from_backup_key();
        /// @brief Value of the SDK constant `NSURLTagNamesKey`.
        static std::string url_tag_names_key();
        /// @brief Value of the SDK constant `NSURLPathKey`.
        static std::string url_path_key();
        /// @brief Value of the SDK constant `NSURLCanonicalPathKey`.
        static std::string url_canonical_path_key();
        /// @brief Value of the SDK constant `NSURLIsMountTriggerKey`.
        static std::string url_is_mount_trigger_key();
        /// @brief Value of the SDK constant `NSURLGenerationIdentifierKey`.
        static std::string url_generation_identifier_key();
        /// @brief Value of the SDK constant `NSURLDocumentIdentifierKey`.
        static std::string url_document_identifier_key();
        /// @brief Value of the SDK constant `NSURLAddedToDirectoryDateKey`.
        static std::string url_added_to_directory_date_key();
        /// @brief Value of the SDK constant `NSURLQuarantinePropertiesKey`.
        static std::string url_quarantine_properties_key();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeKey`.
        static std::string url_file_resource_type_key();
        /// @brief Value of the SDK constant `NSURLFileIdentifierKey`.
        static std::string url_file_identifier_key();
        /// @brief Value of the SDK constant `NSURLFileContentIdentifierKey`.
        static std::string url_file_content_identifier_key();
        /// @brief Value of the SDK constant `NSURLMayShareFileContentKey`.
        static std::string url_may_share_file_content_key();
        /// @brief Value of the SDK constant `NSURLMayHaveExtendedAttributesKey`.
        static std::string url_may_have_extended_attributes_key();
        /// @brief Value of the SDK constant `NSURLIsPurgeableKey`.
        static std::string url_is_purgeable_key();
        /// @brief Value of the SDK constant `NSURLIsSparseKey`.
        static std::string url_is_sparse_key();
        /// @brief Value of the SDK constant `NSURLFileSizeKey`.
        static std::string url_file_size_key();
        /// @brief Value of the SDK constant `NSURLFileAllocatedSizeKey`.
        static std::string url_file_allocated_size_key();
        /// @brief Value of the SDK constant `NSURLTotalFileSizeKey`.
        static std::string url_total_file_size_key();
        /// @brief Value of the SDK constant `NSURLTotalFileAllocatedSizeKey`.
        static std::string url_total_file_allocated_size_key();
        /// @brief Value of the SDK constant `NSURLIsAliasFileKey`.
        static std::string url_is_alias_file_key();
        /// @brief Value of the SDK constant `NSURLFileProtectionKey`.
        static std::string url_file_protection_key();
        /// @brief Value of the SDK constant `NSURLDirectoryEntryCountKey`.
        static std::string url_directory_entry_count_key();
        /// @brief Value of the SDK constant `NSURLVolumeLocalizedFormatDescriptionKey`.
        static std::string url_volume_localized_format_description_key();
        /// @brief Value of the SDK constant `NSURLVolumeTotalCapacityKey`.
        static std::string url_volume_total_capacity_key();
        /// @brief Value of the SDK constant `NSURLVolumeAvailableCapacityKey`.
        static std::string url_volume_available_capacity_key();
        /// @brief Value of the SDK constant `NSURLVolumeResourceCountKey`.
        static std::string url_volume_resource_count_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsPersistentIDsKey`.
        static std::string url_volume_supports_persistent_i_ds_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsSymbolicLinksKey`.
        static std::string url_volume_supports_symbolic_links_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsHardLinksKey`.
        static std::string url_volume_supports_hard_links_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsJournalingKey`.
        static std::string url_volume_supports_journaling_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsJournalingKey`.
        static std::string url_volume_is_journaling_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsSparseFilesKey`.
        static std::string url_volume_supports_sparse_files_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsZeroRunsKey`.
        static std::string url_volume_supports_zero_runs_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsCaseSensitiveNamesKey`.
        static std::string url_volume_supports_case_sensitive_names_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsCasePreservedNamesKey`.
        static std::string url_volume_supports_case_preserved_names_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsRootDirectoryDatesKey`.
        static std::string url_volume_supports_root_directory_dates_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsVolumeSizesKey`.
        static std::string url_volume_supports_volume_sizes_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsRenamingKey`.
        static std::string url_volume_supports_renaming_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsAdvisoryFileLockingKey`.
        static std::string url_volume_supports_advisory_file_locking_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsExtendedSecurityKey`.
        static std::string url_volume_supports_extended_security_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsBrowsableKey`.
        static std::string url_volume_is_browsable_key();
        /// @brief Value of the SDK constant `NSURLVolumeMaximumFileSizeKey`.
        static std::string url_volume_maximum_file_size_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsEjectableKey`.
        static std::string url_volume_is_ejectable_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsRemovableKey`.
        static std::string url_volume_is_removable_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsInternalKey`.
        static std::string url_volume_is_internal_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsAutomountedKey`.
        static std::string url_volume_is_automounted_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsLocalKey`.
        static std::string url_volume_is_local_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsReadOnlyKey`.
        static std::string url_volume_is_read_only_key();
        /// @brief Value of the SDK constant `NSURLVolumeCreationDateKey`.
        static std::string url_volume_creation_date_key();
        /// @brief Value of the SDK constant `NSURLVolumeURLForRemountingKey`.
        static std::string url_volume_url_for_remounting_key();
        /// @brief Value of the SDK constant `NSURLVolumeUUIDStringKey`.
        static std::string url_volume_uuid_string_key();
        /// @brief Value of the SDK constant `NSURLVolumeNameKey`.
        static std::string url_volume_name_key();
        /// @brief Value of the SDK constant `NSURLVolumeLocalizedNameKey`.
        static std::string url_volume_localized_name_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsEncryptedKey`.
        static std::string url_volume_is_encrypted_key();
        /// @brief Value of the SDK constant `NSURLVolumeIsRootFileSystemKey`.
        static std::string url_volume_is_root_file_system_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsCompressionKey`.
        static std::string url_volume_supports_compression_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsFileCloningKey`.
        static std::string url_volume_supports_file_cloning_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsSwapRenamingKey`.
        static std::string url_volume_supports_swap_renaming_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsExclusiveRenamingKey`.
        static std::string url_volume_supports_exclusive_renaming_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsImmutableFilesKey`.
        static std::string url_volume_supports_immutable_files_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsAccessPermissionsKey`.
        static std::string url_volume_supports_access_permissions_key();
        /// @brief Value of the SDK constant `NSURLVolumeSupportsFileProtectionKey`.
        static std::string url_volume_supports_file_protection_key();
        /// @brief Value of the SDK constant `NSURLVolumeAvailableCapacityForImportantUsageKey`.
        static std::string url_volume_available_capacity_for_important_usage_key();
        /// @brief Value of the SDK constant `NSURLVolumeAvailableCapacityForOpportunisticUsageKey`.
        static std::string url_volume_available_capacity_for_opportunistic_usage_key();
        /// @brief Value of the SDK constant `NSURLVolumeTypeNameKey`.
        static std::string url_volume_type_name_key();
        /// @brief Value of the SDK constant `NSURLVolumeSubtypeKey`.
        static std::string url_volume_subtype_key();
        /// @brief Value of the SDK constant `NSURLVolumeMountFromLocationKey`.
        static std::string url_volume_mount_from_location_key();
        /// @brief Value of the SDK constant `NSURLIsUbiquitousItemKey`.
        static std::string url_is_ubiquitous_item_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemHasUnresolvedConflictsKey`.
        static std::string url_ubiquitous_item_has_unresolved_conflicts_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsDownloadingKey`.
        static std::string url_ubiquitous_item_is_downloading_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsUploadedKey`.
        static std::string url_ubiquitous_item_is_uploaded_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsUploadingKey`.
        static std::string url_ubiquitous_item_is_uploading_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadingStatusKey`.
        static std::string url_ubiquitous_item_downloading_status_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadingErrorKey`.
        static std::string url_ubiquitous_item_downloading_error_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemUploadingErrorKey`.
        static std::string url_ubiquitous_item_uploading_error_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadRequestedKey`.
        static std::string url_ubiquitous_item_download_requested_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemContainerDisplayNameKey`.
        static std::string url_ubiquitous_item_container_display_name_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsExcludedFromSyncKey`.
        static std::string url_ubiquitous_item_is_excluded_from_sync_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsSharedKey`.
        static std::string url_ubiquitous_item_is_shared_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemCurrentUserRoleKey`.
        static std::string url_ubiquitous_shared_item_current_user_role_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemCurrentUserPermissionsKey`.
        static std::string url_ubiquitous_shared_item_current_user_permissions_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemOwnerNameComponentsKey`.
        static std::string url_ubiquitous_shared_item_owner_name_components_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemMostRecentEditorNameComponentsKey`.
        static std::string url_ubiquitous_shared_item_most_recent_editor_name_components_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemSupportedSyncControlsKey`.
        static std::string url_ubiquitous_item_supported_sync_controls_key();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemIsSyncPausedKey`.
        static std::string url_ubiquitous_item_is_sync_paused_key();
    };

    /** @brief Named constants of type `NSURLFileResourceType`; each function reads the SDK symbol at runtime. */
    struct URLFileResourceType
    {
        /// @brief Value of the SDK constant `NSURLFileResourceTypeNamedPipe`.
        static std::string named_pipe();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeCharacterSpecial`.
        static std::string character_special();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeDirectory`.
        static std::string directory();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeBlockSpecial`.
        static std::string block_special();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeRegular`.
        static std::string regular();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeSymbolicLink`.
        static std::string symbolic_link();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeSocket`.
        static std::string socket();
        /// @brief Value of the SDK constant `NSURLFileResourceTypeUnknown`.
        static std::string unknown();
    };

    /** @brief Named constants of type `NSURLFileProtectionType`; each function reads the SDK symbol at runtime. */
    struct URLFileProtectionType
    {
        /// @brief Value of the SDK constant `NSURLFileProtectionNone`.
        static std::string url_file_protection_none();
        /// @brief Value of the SDK constant `NSURLFileProtectionComplete`.
        static std::string url_file_protection_complete();
        /// @brief Value of the SDK constant `NSURLFileProtectionCompleteUnlessOpen`.
        static std::string url_file_protection_complete_unless_open();
        /// @brief Value of the SDK constant `NSURLFileProtectionCompleteUntilFirstUserAuthentication`.
        static std::string url_file_protection_complete_until_first_user_authentication();
    };

    /** @brief Named constants of type `NSURLUbiquitousItemDownloadingStatus`; each function reads the SDK symbol at runtime. */
    struct URLUbiquitousItemDownloadingStatus
    {
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadingStatusNotDownloaded`.
        static std::string not_downloaded();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadingStatusDownloaded`.
        static std::string downloaded();
        /// @brief Value of the SDK constant `NSURLUbiquitousItemDownloadingStatusCurrent`.
        static std::string current();
    };

    /** @brief Named constants of type `NSURLUbiquitousSharedItemRole`; each function reads the SDK symbol at runtime. */
    struct URLUbiquitousSharedItemRole
    {
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemRoleOwner`.
        static std::string owner();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemRoleParticipant`.
        static std::string participant();
    };

    /** @brief Named constants of type `NSURLUbiquitousSharedItemPermissions`; each function reads the SDK symbol at runtime. */
    struct URLUbiquitousSharedItemPermissions
    {
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemPermissionsReadOnly`.
        static std::string read_only();
        /// @brief Value of the SDK constant `NSURLUbiquitousSharedItemPermissionsReadWrite`.
        static std::string read_write();
    };

    /** @brief Named constants of type `NSValueTransformerName`; each function reads the SDK symbol at runtime. */
    struct ValueTransformerName
    {
        /// @brief Value of the SDK constant `NSNegateBooleanTransformerName`.
        static std::string negate_boolean_transformer_name();
        /// @brief Value of the SDK constant `NSIsNilTransformerName`.
        static std::string is_nil_transformer_name();
        /// @brief Value of the SDK constant `NSIsNotNilTransformerName`.
        static std::string is_not_nil_transformer_name();
        /// @brief Value of the SDK constant `NSSecureUnarchiveFromDataTransformerName`.
        static std::string secure_unarchive_from_data_transformer_name();
    };
}
