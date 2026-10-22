#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/rule_editor.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class PredicateEditorRowTemplate;

    /**
     * @brief C++ handle for the Objective-C class `NSPredicateEditor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref RuleEditor.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PredicateEditor predicate_editor;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspredicateeditor
     */
    class PredicateEditor : public RuleEditor
    {
    public:
        /// @brief Creates a new `NSPredicateEditor` instance and returns a handle to it.
        explicit PredicateEditor();
        /// @brief Creates a null handle that refers to no native object.
        PredicateEditor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PredicateEditor(Adopt adopt);
        /**
         * @brief Returns the `rowTemplates` property of `NSPredicateEditor`.
         * @details Getter - Returns the row templates for this NSPredicateEditor.
         * @return The converted Objective-C result.
         */
        std::vector<PredicateEditorRowTemplate> row_templates() const;
        /**
         * @brief Sets the `rowTemplates` property of `NSPredicateEditor`.
         * @details Getter - Returns the row templates for this NSPredicateEditor.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_row_templates(const std::vector<PredicateEditorRowTemplate>& value) const;
    };
}
