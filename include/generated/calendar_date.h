#pragma once

#include "generated/availability.h"
#include "generated/date.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCalendarDate` (Foundation).
     * @details A specialized date object with embedded calendar information. \@DeprecationSummary { Use ''NSDate'' and ''NSCalendar'' instead. }
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Date.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CalendarDate calendar_date;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscalendardate
     */
    class CalendarDate : public Date
    {
    public:
        /// @brief Creates a new `NSCalendarDate` instance and returns a handle to it.
        explicit CalendarDate();
        /// @brief Creates a null handle that refers to no native object.
        CalendarDate(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CalendarDate(Adopt adopt);
    };
}
