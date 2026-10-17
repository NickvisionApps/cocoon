#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUUID` (Foundation).
     * @details A universally unique value that can be used to identify types, interfaces, and other items. In Swift, this object bridges to ''UUID''; use ''NSUUID'' when you need reference semantics or other Foundation-specific behavior. UUIDs (Universally Unique Identifiers), also known as GUIDs (Globally Unique Identifiers) or IIDs (Interface Identifiers), are 128-bit values. UUIDs created by 'NSUUID' conform to RFC 4122 version 4 and are created with random bytes. The standard format for UUIDs represented in ASCII is a string punctuated by hyphens, for example '68753A44-4D6F-1226-9C60-0050E4C00067'. The hex representation looks, as you might expect, like a list of numerical values preceded by 0x. For example, '0xD7', '0x36', '0x95', '0x0A', '0x4D', '0x6E', '0x12', '0x26', '0x80', '0x3A', '0x00', '0x50', '0xE4', '0xC0', '0x00', '0x67'. Because a UUID is expressed simply as an array of bytes, there are no endianness considerations for different platforms. The 'NSUUID' class is not toll-free bridged with CoreFoundation's \<doc://com.apple.documentation/documentation/corefoundation/cfuuid>. Use UUID strings to convert between 'CFUUIDRef' and 'NSUUID', if needed. Two 'NSUUID' objects are not guaranteed to be comparable by pointer value (as \<doc://com.apple.documentation/documentation/corefoundation/cfuuid> is); use \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/isequal(:)> to compare two 'NSUUID' instances. > Important: > The Swift overlay to the Foundation framework provides the ''UUID'' structure, which bridges to the ''NSUUID'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Creates a new autoreleased NSUUID with RFC 4122 version 4 random bytes.
     * @return The converted Objective-C result.
     */
        static UUID uuid();
        /**
     * @brief Calls `-[NSUUID compare:]`.
     * @details Compares the receiver to another NSUUID in constant time.
     * @param other_uuid Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        ComparisonResult compare(const UUID& other_uuid) const;
        /**
     * @brief Calls `-[NSUUID getUUIDBytes:]`.
     * @details Gets the individual bytes of the receiver.
     * @param uuid Argument converted to the Objective-C parameter of the same role.
     */
        void get_uuid_bytes(std::uint8_t* uuid) const;
        /**
     * @brief Returns the `UUIDString` property of `NSUUID`.
     * @details The UUID as a string. A string containing a formatted UUID for example 'E621E1F8-C36C-495A-93FC-0C247A3E6E5F'.
     * @return The converted Objective-C result.
     */
        std::string uuid_string() const;
    };
}
