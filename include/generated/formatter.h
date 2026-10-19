#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AttributedString;

    /**
     * @brief C++ handle for the Objective-C class `NSFormatter` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Formatter formatter;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsformatter
     */
    class Formatter : public Object
    {
    public:
        /// @brief Creates a new `NSFormatter` instance and returns a handle to it.
        explicit Formatter();
        /// @brief Creates a null handle that refers to no native object.
        Formatter(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Formatter(Adopt adopt);
        /**
     * @brief Calls `-[NSFormatter attributedStringForObjectValue:withDefaultAttributes:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @param attrs Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AttributedString attributed_string_for_object_value(const Object& obj, const std::map<std::string, Object>& attrs) const;
        /**
     * @brief Calls `-[NSFormatter editingStringForObjectValue:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string editing_string_for_object_value(const Object& obj) const;
        /**
     * @brief Calls `-[NSFormatter isPartialStringValid:newEditingString:errorDescription:]`.
     * @param partial_string Argument converted to the Objective-C parameter of the same role.
     * @param new_string Argument converted to the Objective-C parameter of the same role.
     * @param error Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_partial_string_valid(const std::string& partial_string, std::string& new_string, std::string& error) const;
        /**
     * @brief Calls `-[NSFormatter isPartialStringValid:proposedSelectedRange:originalString:originalSelectedRange:errorDescription:]`.
     * @param partial_string_ptr Argument converted to the Objective-C parameter of the same role.
     * @param proposed_sel_range_ptr Argument converted to the Objective-C parameter of the same role.
     * @param orig_string Argument converted to the Objective-C parameter of the same role.
     * @param orig_sel_range Argument converted to the Objective-C parameter of the same role.
     * @param error Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_partial_string_valid(std::string& partial_string_ptr, Range* proposed_sel_range_ptr, const std::string& orig_string, const Range& orig_sel_range, std::string& error) const;
        /**
     * @brief Calls `-[NSFormatter stringForObjectValue:]`.
     * @param obj Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_object_value(const Object& obj) const;
    };
}
