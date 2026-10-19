#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUUID` (Foundation).
     * @details Note: NSUUID is not toll-free bridged with CFUUID. Use UUID strings to convert between CFUUID and NSUUID, if needed. NSUUIDs are not guaranteed to be comparable by pointer value (as CFUUIDRef is); use isEqual: to compare two NSUUIDs.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UUID uuid;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UUID uuid{};
     * auto made_0 = cocoon::UUID::uuid();
     * uuid.compare(cocoon::UUID());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuuid
     */
    class UUID : public Object
    {
    public:
        /// @brief Creates a new `NSUUID` instance and returns a handle to it.
        explicit UUID(const std::uint8_t* bytes);
        /// @brief Creates a new `NSUUID` instance and returns a handle to it.
        explicit UUID(const std::string& string);
        /// @brief Creates a new `NSUUID` instance and returns a handle to it.
        explicit UUID();
        /// @brief Creates a null handle that refers to no native object.
        UUID(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UUID(Adopt adopt);
        /**
     * @brief Calls `+[NSUUID UUID]`.
     * @details Create a new autoreleased NSUUID with RFC 4122 version 4 random bytes
     * @return The converted Objective-C result.
     */
        static UUID uuid();
        /**
     * @brief Calls `-[NSUUID compare:]`.
     * @details Compare the receiver to another NSUUID in constant time
     * @param other_uuid Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const UUID& other_uuid) const;
        /**
     * @brief Calls `-[NSUUID getUUIDBytes:]`.
     * @details Get the individual bytes of the receiver
     * @param uuid Argument converted to the Objective-C parameter of the same role.
     */
        void get_uuid_bytes(std::uint8_t* uuid) const;
        /**
     * @brief Returns the `UUIDString` property of `NSUUID`.
     * @details Return a string description of the UUID, such as "E621E1F8-C36C-495A-93FC-0C247A3E6E5F"
     * @return The converted Objective-C result.
     */
        std::string uuid_string() const;
    };
}
