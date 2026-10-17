#include "generated/undo_manager.h"
#include "internal.h"

namespace cocoon
{
    UndoManager::UndoManager() : UndoManager(Adopt{cocoon::internal::retain([[::NSUndoManager alloc] init])})
    {
    }

    UndoManager::UndoManager(std::nullptr_t) : Object(nullptr)
    {
    }

    UndoManager::UndoManager(Adopt adopt) : Object(adopt)
    {
    }

    void UndoManager::begin_undo_grouping() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) beginUndoGrouping];
    }

    void UndoManager::disable_undo_registration() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) disableUndoRegistration];
    }

    void UndoManager::enable_undo_registration() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) enableUndoRegistration];
    }

    void UndoManager::end_undo_grouping() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) endUndoGrouping];
    }

    Object UndoManager::prepare_with_invocation_target(const Object& target) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUndoManager>(this) prepareWithInvocationTarget:cocoon::internal::native_id(target)]);
    }

    void UndoManager::redo() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) redo];
    }

    Object UndoManager::redo_action_user_info_value_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUndoManager>(this) redoActionUserInfoValueForKey:cocoon::internal::to(key)]);
    }

    std::string UndoManager::redo_menu_title_for_undo_action_name(const std::string& action_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) redoMenuTitleForUndoActionName:cocoon::internal::to(action_name)]);
    }

    void UndoManager::register_undo_with_target(const Object& target, std::function<void(Object)> undo_handler) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) registerUndoWithTarget:cocoon::internal::native_id(target) handler:(undo_handler ? (void (^)(id)) ^ void(id a251_0) { undo_handler(cocoon::internal::wrap<Object>(a251_0)); } : (void (^)(id))nil)];
    }

    void UndoManager::register_undo_with_target(const Object& target, const std::string& selector, const Object& object) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) registerUndoWithTarget:cocoon::internal::native_id(target) selector:NSSelectorFromString(cocoon::internal::to(selector)) object:cocoon::internal::native_id(object)];
    }

    void UndoManager::remove_all_actions() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) removeAllActions];
    }

    void UndoManager::remove_all_actions_with_target(const Object& target) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) removeAllActionsWithTarget:cocoon::internal::native_id(target)];
    }

    void UndoManager::set_action_is_discardable(bool discardable) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setActionIsDiscardable:static_cast<::BOOL>(discardable)];
    }

    void UndoManager::set_action_name(const std::string& action_name) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setActionName:cocoon::internal::to(action_name)];
    }

    void UndoManager::set_action_user_info_value(const Object& info, const std::string& key) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setActionUserInfoValue:cocoon::internal::native_id(info) forKey:cocoon::internal::to(key)];
    }

    void UndoManager::undo() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) undo];
    }

    Object UndoManager::undo_action_user_info_value_for_key(const std::string& key) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSUndoManager>(this) undoActionUserInfoValueForKey:cocoon::internal::to(key)]);
    }

    std::string UndoManager::undo_menu_title_for_undo_action_name(const std::string& action_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) undoMenuTitleForUndoActionName:cocoon::internal::to(action_name)]);
    }

    void UndoManager::undo_nested_group() const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) undoNestedGroup];
    }

    bool UndoManager::can_redo() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) canRedo]);
    }

    bool UndoManager::can_undo() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) canUndo]);
    }

    std::int64_t UndoManager::grouping_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSUndoManager>(this) groupingLevel]);
    }

    bool UndoManager::groups_by_event() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) groupsByEvent]);
    }

    void UndoManager::set_groups_by_event(bool value) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setGroupsByEvent:static_cast<::BOOL>(value)];
    }

    std::uint64_t UndoManager::levels_of_undo() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSUndoManager>(this) levelsOfUndo]);
    }

    void UndoManager::set_levels_of_undo(std::uint64_t value) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setLevelsOfUndo:static_cast<::NSUInteger>(value)];
    }

    bool UndoManager::redo_action_is_discardable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) redoActionIsDiscardable]);
    }

    std::string UndoManager::redo_action_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) redoActionName]);
    }

    std::uint64_t UndoManager::redo_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSUndoManager>(this) redoCount]);
    }

    std::string UndoManager::redo_menu_item_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) redoMenuItemTitle]);
    }

    bool UndoManager::is_redoing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) isRedoing]);
    }

    std::vector<std::string> UndoManager::run_loop_modes() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSUndoManager>(this) runLoopModes], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    void UndoManager::set_run_loop_modes(const std::vector<std::string>& value) const
    {
        [cocoon::internal::ns<::NSUndoManager>(this) setRunLoopModes:cocoon::internal::to_array(value, [](const std::string& e) -> id
                                                                    {
                                                                        return cocoon::internal::to(e);
                                                                    })];
    }

    bool UndoManager::undo_action_is_discardable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) undoActionIsDiscardable]);
    }

    std::string UndoManager::undo_action_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) undoActionName]);
    }

    std::uint64_t UndoManager::undo_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSUndoManager>(this) undoCount]);
    }

    std::string UndoManager::undo_menu_item_title() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSUndoManager>(this) undoMenuItemTitle]);
    }

    bool UndoManager::is_undo_registration_enabled() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) isUndoRegistrationEnabled]);
    }

    bool UndoManager::is_undoing() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSUndoManager>(this) isUndoing]);
    }
}
