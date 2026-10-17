#pragma once

#include "generated/availability.h"
#include "generated/box.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A horizontal or vertical separator line.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Box.
     *
     * @par Example
     * @code
     * cocoon::VStack stack;
     * stack.add_arranged_subview(cocoon::Separator());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbox
     */
    class Separator : public Box
    {
    public:
        /// @brief Creates a new `NSBox` instance and returns a handle to it.
        explicit Separator();
        /// @brief Creates a null handle that refers to no native object.
        Separator(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Separator(Adopt adopt);
    };
}
