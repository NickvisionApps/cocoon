#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;
    class Bundle;

    /**
     * @brief C++ handle for the Objective-C class `NSHelpManager` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::HelpManager help_manager;
     * help_manager.set_context_help_mode_active(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::HelpManager help_manager{};
     * help_manager.set_context_help_mode_active(true);
     * auto context_help_mode_active = help_manager.is_context_help_mode_active();
     * help_manager.find_string("text", "text");
     * help_manager.open_help_anchor("text", "text");
     * help_manager.register_books_in_bundle(cocoon::Bundle());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nshelpmanager
     */
    class HelpManager : public Object
    {
    public:
        /// @brief Creates a new `NSHelpManager` instance and returns a handle to it.
        explicit HelpManager();
        /// @brief Creates a null handle that refers to no native object.
        HelpManager(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HelpManager(Adopt adopt);
        /**
     * @brief Calls `-[NSHelpManager contextHelpForObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AttributedString context_help_for_object(const Object& object) const;
        /**
     * @brief Calls `-[NSHelpManager findString:inBook:]`.
     * @param query Argument converted to the Objective-C parameter of the same role.
     * @param book Argument converted to the Objective-C parameter of the same role.
     */
        void find_string(const std::string& query, const std::string& book) const;
        /**
     * @brief Calls `-[NSHelpManager openHelpAnchor:inBook:]`.
     * @param anchor Argument converted to the Objective-C parameter of the same role.
     * @param book Argument converted to the Objective-C parameter of the same role.
     */
        void open_help_anchor(const std::string& anchor, const std::string& book) const;
        /**
     * @brief Calls `-[NSHelpManager registerBooksInBundle:]`.
     * @details Register one or more help books in the given bundle. The main bundle is automatically registered by -openHelpAnchor:inBook: and -findString:inBook:. You can use -registerBooksInBundle: to register help books in a plugin bundle, for example. The Info.plist in the bundle should contain a help book directory path, which specifies one or more folders containing help books. Returns NO if the bundle doesn't contain any help books or if registration fails. Returns YES on successful registration.
     * @param bundle Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool register_books_in_bundle(const Bundle& bundle) const;
        /**
     * @brief Calls `-[NSHelpManager removeContextHelpForObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void remove_context_help_for_object(const Object& object) const;
        /**
     * @brief Calls `-[NSHelpManager setContextHelp:forObject:]`.
     * @param attr_string Argument converted to the Objective-C parameter of the same role.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void set_context_help(const AttributedString& attr_string, const Object& object) const;
        /**
     * @brief Calls `-[NSHelpManager showContextHelpForObject:locationHint:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param pt Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool show_context_help_for_object(const Object& object, const Point& pt) const;
        /**
     * @brief Returns the `contextHelpModeActive` property of `NSHelpManager`.
     * @return The converted Objective-C result.
     */
        static bool is_context_help_mode_active();
        /**
     * @brief Sets the `contextHelpModeActive` property of `NSHelpManager`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_context_help_mode_active(bool value);
        /**
     * @brief Returns the `sharedHelpManager` property of `NSHelpManager`.
     * @return The converted Objective-C result.
     */
        static HelpManager shared_help_manager();
    };
}
