#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Port;

    /**
     * @brief C++ handle for the Objective-C class `NSPortCoder` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PortCoder port_coder;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PortCoder port_coder{};
     * port_coder.decode_port_object();
     * port_coder.encode_port_object(cocoon::Port());
     * port_coder.is_bycopy();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsportcoder
     */
    class PortCoder : public Coder
    {
    public:
        /// @brief Creates a new `NSPortCoder` instance and returns a handle to it.
        explicit PortCoder();
        /// @brief Creates a null handle that refers to no native object.
        PortCoder(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PortCoder(Adopt adopt);
        /**
         * @brief Calls `-[NSPortCoder decodePortObject]`.
         * @return The converted Objective-C result.
         */
        Port decode_port_object() const;
        /**
         * @brief Calls `-[NSPortCoder encodePortObject:]`.
         * @param aport Argument converted to the Objective-C parameter of the same role.
         */
        void encode_port_object(const Port& aport) const;
        /**
         * @brief Calls `-[NSPortCoder isBycopy]`.
         * @return The converted Objective-C result.
         */
        bool is_bycopy() const;
        /**
         * @brief Calls `-[NSPortCoder isByref]`.
         * @return The converted Objective-C result.
         */
        bool is_byref() const;
    };
}
