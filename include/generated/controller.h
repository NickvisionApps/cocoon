#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSController` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Controller controller;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Controller controller{};
     * controller.commit_editing();
     * controller.discard_editing();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscontroller
     */
    class Controller : public Object
    {
    public:
        /// @brief Creates a new `NSController` instance and returns a handle to it.
        explicit Controller();
        /// @brief Creates a null handle that refers to no native object.
        Controller(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Controller(Adopt adopt);
        /**
     * @brief Calls `-[NSController commitEditing]`.
     * @return The converted Objective-C result.
     */
        bool commit_editing() const;
        /**
     * @brief Calls `-[NSController commitEditingWithDelegate:didCommitSelector:contextInfo:]`.
     * @param delegate Argument converted to the Objective-C parameter of the same role.
     * @param did_commit_selector Argument converted to the Objective-C parameter of the same role.
     * @param context_info Argument converted to the Objective-C parameter of the same role.
     */
        void commit_editing_with_delegate(const Object& delegate, const std::string& did_commit_selector, void* context_info) const;
        /**
     * @brief Calls `-[NSController discardEditing]`.
     */
        void discard_editing() const;
        /**
     * @brief Calls `-[NSController objectDidBeginEditing:]`.
     * @param editor Argument converted to the Objective-C parameter of the same role.
     */
        void object_did_begin_editing(const Object& editor) const;
        /**
     * @brief Calls `-[NSController objectDidEndEditing:]`.
     * @param editor Argument converted to the Objective-C parameter of the same role.
     */
        void object_did_end_editing(const Object& editor) const;
        /**
     * @brief Returns the `editing` property of `NSController`.
     * @return The converted Objective-C result.
     */
        bool is_editing() const;
    };
}
