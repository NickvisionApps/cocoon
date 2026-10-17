#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/stack_view.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief A vertical stack view.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref StackView.
     *
     * @par Example
     * @code
     * cocoon::VStack stack;
     * stack.set_spacing(12);
     * stack.set_edge_insets(cocoon::Insets(24));
     * stack.add_arranged_subview(cocoon::Label("Hello"));
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstackview
     */
    class VStack : public StackView
    {
    public:
        /// @brief Creates a new `NSStackView` instance and returns a handle to it.
        explicit VStack();
        /// @brief Creates a null handle that refers to no native object.
        VStack(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit VStack(Adopt adopt);
    };
}
