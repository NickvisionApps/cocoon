#include "generated/decimal_number_handler.h"
#include "internal.h"

namespace cocoon
{
    DecimalNumberHandler::DecimalNumberHandler(RoundingMode rounding_mode, std::int16_t scale, bool exact, bool overflow, bool underflow, bool divide_by_zero) : DecimalNumberHandler(Adopt{cocoon::internal::retain([[::NSDecimalNumberHandler alloc] initWithRoundingMode:static_cast<::NSRoundingMode>(rounding_mode) scale:static_cast<short>(scale) raiseOnExactness:static_cast<::BOOL>(exact) raiseOnOverflow:static_cast<::BOOL>(overflow) raiseOnUnderflow:static_cast<::BOOL>(underflow) raiseOnDivideByZero:static_cast<::BOOL>(divide_by_zero)])})
    {
    }

    DecimalNumberHandler::DecimalNumberHandler() : DecimalNumberHandler(Adopt{cocoon::internal::retain([[::NSDecimalNumberHandler alloc] init])})
    {
    }

    DecimalNumberHandler::DecimalNumberHandler(std::nullptr_t) : Object(nullptr)
    {
    }

    DecimalNumberHandler::DecimalNumberHandler(Adopt adopt) : Object(adopt)
    {
    }

    DecimalNumberHandler DecimalNumberHandler::decimal_number_handler_with_rounding_mode(RoundingMode rounding_mode, std::int16_t scale, bool exact, bool overflow, bool underflow, bool divide_by_zero)
    {
        return cocoon::internal::wrap<DecimalNumberHandler>([::NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:static_cast<::NSRoundingMode>(rounding_mode) scale:static_cast<short>(scale) raiseOnExactness:static_cast<::BOOL>(exact) raiseOnOverflow:static_cast<::BOOL>(overflow) raiseOnUnderflow:static_cast<::BOOL>(underflow) raiseOnDivideByZero:static_cast<::BOOL>(divide_by_zero)]);
    }

    DecimalNumberHandler DecimalNumberHandler::default_decimal_number_handler()
    {
        return cocoon::internal::wrap<DecimalNumberHandler>([::NSDecimalNumberHandler defaultDecimalNumberHandler]);
    }
}
