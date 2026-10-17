#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUndoManager` (Foundation).
     * @details A general-purpose recorder of operations that enables undo and redo. You register an undo operation by calling one of the methods described in Registering undo operations. You specify the name of the object that's changing (or the owner of that object) and provide a closure, method, or invocation to revert its state. After you register an undo operation, you can call ''undo()'' on the undo manager to revert to the state of the last undo operation. When undoing an action, ''UndoManager'' saves the operations you revert to so that you can call ''redo()'' automatically. Typically, apps with UI interactions work with ''UndoManager''. For example, UIKit implements undo and redo in its text view object, making it easy for you to undo and redo actions in objects along the responder chain. ''UndoManager'' also serves as a general-purpose state manager, which you can use to undo and redo many kinds of actions. For example, an interactive command-line utility can use this class to undo the last command run, or a networking library can undo a request by sending another request that invalidates the previous one. > Important: 'UndoManager' is \<doc://com.apple.documentation/documentation/swift/MainActor>-isolated in Swift, making it safe to use in UI frameworks like \<doc://com.apple.documentation/documentation/AppKit> and \<doc://com.apple.documentation/documentation/UIKit> that expect to execute code on the main thread, queue, or actor. When registering an undoable action with ''registerUndo(withTarget:handler:)'', the 'handler' closure is also \<doc://com.apple.documentation/documentation/swift/MainActor>-isolated to ensure safety and simplify ergonomics.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UndoManager undo_manager;
     * undo_manager.set_groups_by_event(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UndoManager undo_manager{};
     * undo_manager.set_groups_by_event(true);
     * auto groups_by_event = undo_manager.groups_by_event();
     * undo_manager.set_levels_of_undo(1);
     * auto levels_of_undo = undo_manager.levels_of_undo();
     * undo_manager.set_run_loop_modes({"a", "b"});
     * auto run_loop_modes = undo_manager.run_loop_modes();
     * undo_manager.begin_undo_grouping();
     * undo_manager.disable_undo_registration();
     * undo_manager.enable_undo_registration();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsundomanager
     */
    class UndoManager : public Object
    {
    public:
        /// @brief Creates a new `NSUndoManager` instance and returns a handle to it.
        explicit UndoManager();
        /// @brief Creates a null handle that refers to no native object.
        UndoManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UndoManager(Adopt adopt);
        /**
     * @brief Calls `-[NSUndoManager beginUndoGrouping]`.
     * @details Marks the beginning of an undo group. All individual undo operations before a subsequent ''endUndoGrouping'' message are grouped together and reversed by a later ''undo'' message. By default undo groups are begun automatically at the start of the event loop, but you can begin your own undo groups with this method, and nest them within other groups. This method posts an ''NSUndoManagerCheckpointNotification'' unless a top-level undo is in progress. It posts an ''NSUndoManagerDidOpenUndoGroupNotification'' if a new group was successfully created.
     */
        void begin_undo_grouping() const;
        /**
     * @brief Calls `-[NSUndoManager disableUndoRegistration]`.
     * @details Disables the recording of undo operations. This method can be invoked multiple times by multiple clients. The ''enableUndoRegistration'' method must be invoked an equal number of times to re-enable undo registration.
     */
        void disable_undo_registration() const;
        /**
     * @brief Calls `-[NSUndoManager enableUndoRegistration]`.
     * @details Enables the recording of undo operations. Because undo registration is enabled by default, this is used to balance a prior ''disableUndoRegistration''. Undo registration isn’t actually re-enabled until an enable message balances the last disable message in effect. Raises an NSInternalInconsistencyException if invoked while no disableUndoRegistration() message is in effect.
     */
        void enable_undo_registration() const;
        /**
     * @brief Calls `-[NSUndoManager endUndoGrouping]`.
     * @details Marks the end of an undo group. All individual undo operations back to the matching ''beginUndoGrouping'' message are grouped together and reversed by a later ''undo'' or ''undoNestedGroup'' message. Undo groups can be nested, thus providing functionality similar to nested transactions. Raises an ''NSInternalInconsistencyException'' if there’s no ''beginUndoGrouping'' message in effect. This method posts an ''NSUndoManagerCheckpointNotification'' and an ''NSUndoManagerDidCloseUndoGroupNotification'' just before the group is closed.
     */
        void end_undo_grouping() const;
        /**
     * @brief Calls `-[NSUndoManager prepareWithInvocationTarget:]`.
     * @details Prepares the undo manager for invocation-based undo with the given target as the subject of the next undo operation. For example, when called as: [[undoManager prepareWithInvocationTarget:target] setFont:oldFont color:oldColor] When undo is called, the specified target will be called with [target setFont:oldFont color:oldColor] - Parameter target: The target of the undo operation. The undo manager maintains a weak reference to 'target'. - Returns: A proxy object that forwards messages to the undo manager for recording as undo actions.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object prepare_with_invocation_target(const Object& target) const;
        /**
     * @brief Calls `-[NSUndoManager redo]`.
     * @details Performs the operations in the last group on the redo stack, if there are any, recording them on the undo stack as a single group. Raises an ''NSInternalInconsistencyException'' if the method is invoked during an undo operation. This method posts an ''NSUndoManagerCheckpointNotification'' and ''NSUndoManagerWillRedoChangeNotification'' before it performs the redo operation, and it posts the ''NSUndoManagerDidRedoChangeNotification'' after it performs the redo operation.
     */
        void redo() const;
        /**
     * @brief Calls `-[NSUndoManager redoActionUserInfoValueForKey:]`.
     * @details Retrieves the redo action's user info value for the given key. - Parameter key: Which value should be retrieved
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object redo_action_user_info_value_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSUndoManager redoMenuTitleForUndoActionName:]`.
     * @details Returns the localized title of the Redo menu command for the identified action. Override this method if you want to customize the localization behaviour. This method is invoked by ''redoMenuItemTitle''. - Parameter actionName: The name of the redo action. - Returns: The localized title of the redo menu item.
     * @param action_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string redo_menu_title_for_undo_action_name(const std::string& action_name) const;
        /**
     * @brief Calls `-[NSUndoManager registerUndoWithTarget:handler:]`.
     * @details Registers the specified closure to implement a single undo operation that the target receives. As with other undo operations, this does not strongly retain target. Care should be taken to avoid introducing retain cycles by other references captured by the block. - Parameter target: The target of the undo operation. - Parameter undoHandler: The block to be executed when an operation is undone. The block takes a single argument, the target of the undo operation.
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param undo_handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_undo_with_target(const Object& target, std::function<void(Object)> undo_handler) const;
        /**
     * @brief Calls `-[NSUndoManager registerUndoWithTarget:selector:object:]`.
     * @details Registers the selector of the specified target to implement a single undo operation that the target receives. - Parameter target: The target of the undo operation. The undo manager maintains an unowned reference to 'target' to prevent retain cycles. - Parameter selector: The selector for the undo operation. - Parameter object: The argument sent with the selector. The undo manager maintains a strong reference to 'object'
     * @param target Argument converted to the Objective-C parameter of the same role.
     * @param selector Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void register_undo_with_target(const Object& target, const std::string& selector, const Object& object) const;
        /**
     * @brief Calls `-[NSUndoManager removeAllActions]`.
     * @details Clears the undo and redo stacks and reenables the manager.
     */
        void remove_all_actions() const;
        /**
     * @brief Calls `-[NSUndoManager removeAllActionsWithTarget:]`.
     * @details Clears the undo and redo stacks of all operations involving the specified target as the recipient of the undo message. Doesn't re-enable the receiver if it's disabled. - Parameter target: The recepient of the undo mesages to be removed.
     * @param target Argument converted to the Objective-C parameter of the same role.
     */
        void remove_all_actions_with_target(const Object& target) const;
        /**
     * @brief Calls `-[NSUndoManager setActionIsDiscardable:]`.
     * @details Sets whether the next undo or redo action is discardable. Specifies that the latest undo action may be safely discarded when a document can not be saved for any reason. An example might be an undo action that changes the viewable area of a document. To find out if an undo group contains only discardable actions, look for the ''NSUndoManagerGroupIsDiscardableKey'' in the 'userInfo' dictionary of the ''NSUndoManagerWillCloseUndoGroupNotification''. - Parameter discardable: Specifies if the action is discardable. YES if the next undo or redo action can be discarded; NO otherwise.
     * @param discardable Argument converted to the Objective-C parameter of the same role.
     */
        void set_action_is_discardable(bool discardable) const;
        /**
     * @brief Calls `-[NSUndoManager setActionName:]`.
     * @details Sets the name of the action associated with the Undo or Redo command. If 'actionName' is an empty string, the undo manager removes the action name currently associated with the menu command. - Parameter actionName: The name of the action.
     * @param action_name Argument converted to the Objective-C parameter of the same role.
     */
        void set_action_name(const std::string& action_name) const;
        /**
     * @brief Calls `-[NSUndoManager setActionUserInfoValue:forKey:]`.
     * @details Sets a user info value for an undo or redo action. - Parameter info: Value to be saved in the user info - Parameter key: Key at which the object should be saved
     * @param info Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void set_action_user_info_value(const Object& info, const std::string& key) const;
        /**
     * @brief Calls `-[NSUndoManager undo]`.
     * @details Closes the top-level undo group if necessary, and then performs undo operations on the group. This method also invokes ''endUndoGrouping'' if the nesting level is 1. Raises an ''NSInternalInconsistencyException'' if more than one undo group is open (that is, if the last group isn’t at the top level). This method posts an ''NSUndoManagerCheckpointNotification''.
     */
        void undo() const;
        /**
     * @brief Calls `-[NSUndoManager undoActionUserInfoValueForKey:]`.
     * @details Retrieves the undo action's user info value for the given key. - Parameter key: Which value should be retrieved
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object undo_action_user_info_value_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSUndoManager undoMenuTitleForUndoActionName:]`.
     * @details Returns the localized title of the Undo menu command for the identified action. Override this method if you want to customize the localization behaviour. This method is invoked by ''undoMenuItemTitle''. - Parameter actionName: The name of the undo action. - Returns: The localized title of the undo menu item.
     * @param action_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string undo_menu_title_for_undo_action_name(const std::string& action_name) const;
        /**
     * @brief Calls `-[NSUndoManager undoNestedGroup]`.
     * @details Performs the undo operations in the last undo group (whether top-level or nested), recording the operations on the redo stack as a single group. Raises an ''NSInternalInconsistencyException'' if any undo operations have been registered since the last ''enableUndoRegistration'' message. This method posts an ''NSUndoManagerCheckpointNotification'' and ''NSUndoManagerWillUndoChangeNotification'' before it performs the undo operation, and it posts an ''NSUndoManagerDidUndoChangeNotification'' after it performs the undo operation.
     */
        void undo_nested_group() const;
        /**
     * @brief Returns the `canRedo` property of `NSUndoManager`.
     * @details A Boolean value that indicates whether the manager has any actions to redo. Because any undo operation registered clears the redo stack, this method posts an NSUndoManagerCheckpointNotification to allow clients to apply their pending operations before testing the redo stack.
     * @return The converted Objective-C result.
     */
        bool can_redo() const;
        /**
     * @brief Returns the `canUndo` property of `NSUndoManager`.
     * @details A Boolean value that indicates whether the manager has any actions to undo. The return value does not mean you can safely invoke ''undo'' or ''undoNestedGroup'' — you may have to close open undo groups first.
     * @return The converted Objective-C result.
     */
        bool can_undo() const;
        /**
     * @brief Returns the `groupingLevel` property of `NSUndoManager`.
     * @details The number of nested undo groups (or redo groups, if redo is the most recent operation) in the current event loop. An integer indicating the number of nested groups. If '0' is returned, there is no open undo or redo group.
     * @return The converted Objective-C result.
     */
        std::int64_t grouping_level() const;
        /**
     * @brief Returns the `groupsByEvent` property of `NSUndoManager`.
     * @details A Boolean value that indicates whether the manager automatically creates undo groups around each pass of the run loop. If 'true', the receiver automatically creates undo groups around each pass of the run loop. The default is 'true'. If you turn automatic grouping off, you must close groups explicitly before invoking either ''undo'' or ''undoNestedGroup''.
     * @return The converted Objective-C result.
     */
        bool groups_by_event() const;
        /**
     * @brief Sets the `groupsByEvent` property of `NSUndoManager`.
     * @details A Boolean value that indicates whether the manager automatically creates undo groups around each pass of the run loop. If 'true', the receiver automatically creates undo groups around each pass of the run loop. The default is 'true'. If you turn automatic grouping off, you must close groups explicitly before invoking either ''undo'' or ''undoNestedGroup''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_groups_by_event(bool value) const;
        /**
     * @brief Returns the `levelsOfUndo` property of `NSUndoManager`.
     * @details The maximum number of top-level undo groups the receiver holds. An integer specifying the number of undo groups. A limit of 0 indicates no limit, so old undo groups are never dropped. When ending an undo group results in the number of groups exceeding this limit, the oldest groups are dropped from the stack. The default is 0. If you change the limit to a level below the prior limit, old undo groups are immediately dropped.
     * @return The converted Objective-C result.
     */
        std::uint64_t levels_of_undo() const;
        /**
     * @brief Sets the `levelsOfUndo` property of `NSUndoManager`.
     * @details The maximum number of top-level undo groups the receiver holds. An integer specifying the number of undo groups. A limit of 0 indicates no limit, so old undo groups are never dropped. When ending an undo group results in the number of groups exceeding this limit, the oldest groups are dropped from the stack. The default is 0. If you change the limit to a level below the prior limit, old undo groups are immediately dropped.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_levels_of_undo(std::uint64_t value) const;
        /**
     * @brief Returns the `redoActionIsDiscardable` property of `NSUndoManager`.
     * @details Whether the next redo action is discardable. Specifies that the latest redo action may be safely discarded when a document can not be saved for any reason. These are typically actions that don’t affect persistent state. An example might be an redo action that changes the viewable area of a document.
     * @return The converted Objective-C result.
     */
        bool redo_action_is_discardable() const;
        /**
     * @brief Returns the `redoActionName` property of `NSUndoManager`.
     * @details The name identifying the redo action. The redo action name. Returns an empty string if no action name has been assigned or if there is nothing to redo. For example, if the menu title is “Redo Delete,” the string returned is “Delete.”
     * @return The converted Objective-C result.
     */
        std::string redo_action_name() const;
        /**
     * @brief Returns the `redoCount` property of `NSUndoManager`.
     * @details The number of times you can invoke redo before there are no actions left to redo.
     * @return The converted Objective-C result.
     */
        std::uint64_t redo_count() const;
        /**
     * @brief Returns the `redoMenuItemTitle` property of `NSUndoManager`.
     * @details The title of the Redo menu command, such as Redo Paste. Returns “Redo” if no action name has been assigned or nil if there is nothing to redo.
     * @return The converted Objective-C result.
     */
        std::string redo_menu_item_title() const;
        /**
     * @brief Returns the `redoing` property of `NSUndoManager`.
     * @details Returns a Boolean value that indicates whether the manager is in the process of performing a redo action.
     * @return The converted Objective-C result.
     */
        bool is_redoing() const;
        /**
     * @brief Returns the `runLoopModes` property of `NSUndoManager`.
     * @details The modes governing the types of input handled during a cycle of the run loop. An array of string constants specifying the current run-loop modes. By default, the sole run-loop mode is ''NSDefaultRunLoopMode'' (which excludes data from ''NSConnection'' objects). Some examples of other uses are to limit the input to data received during a mouse-tracking session by setting the mode to ''NSEventTrackingRunLoopMode'', or limit it to data received from a modal panel with ''NSModalPanelRunLoopMode''.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> run_loop_modes() const;
        /**
     * @brief Sets the `runLoopModes` property of `NSUndoManager`.
     * @details The modes governing the types of input handled during a cycle of the run loop. An array of string constants specifying the current run-loop modes. By default, the sole run-loop mode is ''NSDefaultRunLoopMode'' (which excludes data from ''NSConnection'' objects). Some examples of other uses are to limit the input to data received during a mouse-tracking session by setting the mode to ''NSEventTrackingRunLoopMode'', or limit it to data received from a modal panel with ''NSModalPanelRunLoopMode''.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_run_loop_modes(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `undoActionIsDiscardable` property of `NSUndoManager`.
     * @details Whether the next undo action is discardable. Specifies that the latest undo action may be safely discarded when a document can not be saved for any reason. These are typically actions that don’t affect persistent state. An example might be an undo action that changes the viewable area of a document.
     * @return The converted Objective-C result.
     */
        bool undo_action_is_discardable() const;
        /**
     * @brief Returns the `undoActionName` property of `NSUndoManager`.
     * @details The name identifying the undo action. The undo action name. Returns an empty string if no action name has been assigned or if there is nothing to undo. For example, if the menu title is “Undo Delete,” the string returned is “Delete.”
     * @return The converted Objective-C result.
     */
        std::string undo_action_name() const;
        /**
     * @brief Returns the `undoCount` property of `NSUndoManager`.
     * @details The number of times you can invoke undo before there are no actions left to undo. A nonzero value doesn't imply you can safely invoke ''undo'' immediately, because you may have to close open undo groups first.
     * @return The converted Objective-C result.
     */
        std::uint64_t undo_count() const;
        /**
     * @brief Returns the `undoMenuItemTitle` property of `NSUndoManager`.
     * @details The title of the Undo menu command, such as Undo Paste. Returns “Undo” if no action name has been assigned or nil if there is nothing to undo.
     * @return The converted Objective-C result.
     */
        std::string undo_menu_item_title() const;
        /**
     * @brief Returns the `undoRegistrationEnabled` property of `NSUndoManager`.
     * @details A Boolean value that indicates whether the recording of undo operations is enabled.
     * @return The converted Objective-C result.
     */
        bool is_undo_registration_enabled() const;
        /**
     * @brief Returns the `undoing` property of `NSUndoManager`.
     * @details Returns a Boolean value that indicates whether the manager is in the process of performing an undo action.
     * @return The converted Objective-C result.
     */
        bool is_undoing() const;
    };
}
