#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/stack_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A horizontal stack view.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref StackView.
     *
     * @par Example
     * @code
     * cocoon::HStack row;
     * row.add_arranged_subview(cocoon::Button("OK"));
     * row.add_arranged_subview(cocoon::Button("Cancel"));
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstackview
     */
    class HStack : public StackView
    {
    public:
        /// @brief Creates a new `NSStackView` instance and returns a handle to it.
        explicit HStack();
        /// @brief Creates a null handle that refers to no native object.
        HStack(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit HStack(Adopt adopt);
    };
}
