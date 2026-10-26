#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/unit.h"
#include "types.h"

namespace cocoon
{
    class UnitConverter;

    /**
     * @brief C++ handle for the Objective-C class `NSDimension` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Unit.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Dimension dimension{"text", cocoon::UnitConverter()};
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Dimension dimension{"text", cocoon::UnitConverter()};
     * auto made_0 = cocoon::Dimension::base_unit();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdimension
     */
    class Dimension : public Unit
    {
    public:
        /// @brief Creates a new `NSDimension` instance and returns a handle to it.
        explicit Dimension(const std::string& symbol, const UnitConverter& converter);
        Dimension();
        /// @brief Creates a null handle that refers to no native object.
        Dimension(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Dimension(Adopt adopt);
        /**
         * @brief Calls `+[NSDimension baseUnit]`.
         * @details This class method returns an instance of the dimension class that represents the base unit of that dimension. e.g. NSUnitSpeed metersPerSecond = [NSUnitSpeed baseUnit];
         * @return The converted Objective-C result.
         */
        static Dimension base_unit();
        /**
         * @brief Returns the `converter` property of `NSDimension`.
         * @return The converted Objective-C result.
         */
        UnitConverter converter() const;
    };
}
