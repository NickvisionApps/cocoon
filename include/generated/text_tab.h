#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CharacterSet;
    class Locale;

    /**
     * @brief C++ handle for the Objective-C class `NSTextTab` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextTab text_tab;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstexttab
     */
    class TextTab : public Object
    {
    public:
        /// @brief Creates a new `NSTextTab` instance and returns a handle to it.
        explicit TextTab(TextTabType type, double loc);
        /// @brief Creates a new `NSTextTab` instance and returns a handle to it.
        explicit TextTab();
        /// @brief Creates a null handle that refers to no native object.
        TextTab(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextTab(Adopt adopt);
        /**
     * @brief Calls `+[NSTextTab columnTerminatorsForLocale:]`.
     * @param a_locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CharacterSet column_terminators_for_locale(const Locale& a_locale);
        /**
     * @brief Returns the `location` property of `NSTextTab`.
     * @return The converted Objective-C result.
     */
        double location() const;
        /**
     * @brief Returns the `options` property of `NSTextTab`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> options() const;
        /**
     * @brief Returns the `tabStopType` property of `NSTextTab`.
     * @return The converted Objective-C result.
     */
        TextTabType tab_stop_type() const;
    };
}
