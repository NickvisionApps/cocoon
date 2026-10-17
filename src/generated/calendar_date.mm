#include "generated/calendar_date.h"
#include "internal.h"

namespace cocoon
{
    CalendarDate::CalendarDate() : CalendarDate(Adopt{cocoon::internal::retain([[::NSCalendarDate alloc] init])})
    {
    }

    CalendarDate::CalendarDate(std::nullptr_t) : Date(nullptr)
    {
    }

    CalendarDate::CalendarDate(Adopt adopt) : Date(adopt)
    {
    }
}
