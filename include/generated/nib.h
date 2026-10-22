#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Bundle;

    /**
     * @brief C++ handle for the Objective-C class `NSNib` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Nib nib;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsnib
     */
    class Nib : public Object
    {
    public:
        /// @brief Creates a new `NSNib` instance and returns a handle to it.
        explicit Nib(const std::vector<std::uint8_t>& nib_data, const Bundle& bundle);
        /// @brief Creates a new `NSNib` instance and returns a handle to it.
        explicit Nib(const std::string& nib_name, const Bundle& bundle);
        /// @brief Creates a new `NSNib` instance and returns a handle to it.
        explicit Nib();
        /// @brief Creates a null handle that refers to no native object.
        Nib(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Nib(Adopt adopt);
        /**
         * @brief Calls `-[NSNib instantiateWithOwner:topLevelObjects:]`.
         * @param owner Argument converted to the Objective-C parameter of the same role.
         * @param top_level_objects Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool instantiate_with_owner(const Object& owner, std::vector<Object>& top_level_objects) const;
    };
}
