#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDecimalNumberHandler` (Foundation).
     * @details A class that adopts the decimal number behaviors protocol. This class allows you to set the way an ''NSDecimalNumber'' object rounds off and handles errors, without having to create a custom class. You can use an instance of this class as an argument to any of the ''NSDecimalNumber'' methods that end with '...Behavior:'. If you don't think you need special behavior, you probably don't need this class—it is likely that ''NSDecimalNumber'''s default behavior will suit your needs. For more information, see the ''NSDecimalNumberBehaviors'' protocol specification.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DecimalNumberHandler decimal_number_handler;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DecimalNumberHandler decimal_number_handler{};
     * auto made_0 = cocoon::DecimalNumberHandler::decimal_number_handler_with_rounding_mode(cocoon::RoundingMode::Plain, 1, true, true, true, true);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdecimalnumberhandler
     */
    class DecimalNumberHandler : public Object
    {
    public:
        /// @brief Creates a new `NSDecimalNumberHandler` instance and returns a handle to it.
        explicit DecimalNumberHandler(RoundingMode rounding_mode, std::int16_t scale, bool exact, bool overflow, bool underflow, bool divide_by_zero);
        /// @brief Creates a new `NSDecimalNumberHandler` instance and returns a handle to it.
        explicit DecimalNumberHandler();
        /// @brief Creates a null handle that refers to no native object.
        DecimalNumberHandler(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DecimalNumberHandler(Adopt adopt);
        /**
     * @brief Calls `+[NSDecimalNumberHandler decimalNumberHandlerWithRoundingMode:scale:raiseOnExactness:raiseOnOverflow:raiseOnUnderflow:raiseOnDivideByZero:]`.
     * @details Returns an 'NSDecimalNumberHandler' object with customized behavior. - Parameters: - roundingMode: The rounding mode to use. - scale: The number of digits a rounded value is allowed to have after its decimal point. - exact: If 'YES', raises an exception on loss of precision. - overflow: If 'YES', raises an exception on overflow. - underflow: If 'YES', raises an exception on underflow. - divideByZero: If 'YES', raises an exception on divide by zero. - Returns: An 'NSDecimalNumberHandler' object with customized behavior.
     * @param rounding_mode Argument converted to the Objective-C parameter of the same role.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     * @param exact Argument converted to the Objective-C parameter of the same role.
     * @param overflow Argument converted to the Objective-C parameter of the same role.
     * @param underflow Argument converted to the Objective-C parameter of the same role.
     * @param divide_by_zero Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DecimalNumberHandler decimal_number_handler_with_rounding_mode(RoundingMode rounding_mode, std::int16_t scale, bool exact, bool overflow, bool underflow, bool divide_by_zero);
        /**
     * @brief Returns the `defaultDecimalNumberHandler` property of `NSDecimalNumberHandler`.
     * @details Returns the default instance of 'NSDecimalNumberHandler'. The default handler rounds to closest possible return value (''NSRoundPlain''), assumes precision up to 38 significant digits, and raises on overflow, underflow, and divide by zero.
     * @return The converted Objective-C result.
     */
        static DecimalNumberHandler default_decimal_number_handler();
    };
}
