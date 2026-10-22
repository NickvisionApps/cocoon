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
     * @details An abstract class that declares an interface for objects that create, interpret, and validate the textual representation of values. The Foundation framework provides several concrete subclasses of ''Formatter'', including ''ByteCountFormatter'', ''DateFormatter'', ''DateComponentsFormatter'', ''DateIntervalFormatter'', ''MeasurementFormatter'', ''NumberFormatter'', and ''PersonNameComponentsFormatter''. > Tip: > In Swift, you can use implementations of ''FormatStyle'' rather than ''Formatter''. The ''FormatStyle'' API offers a declarative idiom for customizing the formatting of various types. Also, Foundation caches identical ''FormatStyle'' instances, so you don't need to pass them around your app, or risk wasting memory with duplicate formatters. \#\#\# Subclassing Notes ''Formatter'' is intended for subclassing. A custom formatter can restrict the input and enhance the display of data in novel ways. For example, you could have a custom formatter that ensures that serial numbers entered by a user conform to predefined formats. Before you decide to create a custom formatter, make sure that you cannot configure the public subclasses to satisfy your requirements. For instructions on how to create your own custom formatter, see [Creating a Custom Formatter](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/DataFormatting/Articles/CreatingACustomFormatter.html\#//apple_ref/doc/uid/20000196).
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
         * @details Returns an attributed string representation of a given object.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param attrs Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AttributedString attributed_string_for_object_value(const Object& obj, const std::map<std::string, Object>& attrs) const;
        /**
         * @brief Calls `-[NSFormatter editingStringForObjectValue:]`.
         * @details Returns a string to use for editing a given object.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string editing_string_for_object_value(const Object& obj) const;
        /**
         * @brief Calls `-[NSFormatter isPartialStringValid:newEditingString:errorDescription:]`.
         * @details Returns a Boolean value that indicates whether a partial string is valid. Compatibility method. If a subclass overrides this and does not override the new method below, this will be called as before (the new method just calls this one by default). The selection range will always be set to the end of the text with this method if replacement occurs.
         * @param partial_string Argument converted to the Objective-C parameter of the same role.
         * @param new_string Argument converted to the Objective-C parameter of the same role.
         * @param error Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_partial_string_valid(const std::string& partial_string, std::string& new_string, std::string& error) const;
        /**
         * @brief Calls `-[NSFormatter isPartialStringValid:proposedSelectedRange:originalString:originalSelectedRange:errorDescription:]`.
         * @details This method should be implemented in subclasses that want to validate user changes to a string in a field, where the user changes are not necessarily at the end of the string, and preserve the selection (or set a different one, such as selecting the erroneous part of the string the user has typed).
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
         * @details Returns a string representation of a given object.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string string_for_object_value(const Object& obj) const;
    };
}
