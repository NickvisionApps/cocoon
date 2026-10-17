#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class InputStream;
    class OutputStream;

    /**
     * @brief C++ handle for the Objective-C class `NSPropertyListSerialization` (Foundation).
     * @details An object that converts between a property list and one of several serialized representations. The ''PropertyListSerialization'' class provides methods that convert a property list to and from several serialized formats. A property list is itself an array or dictionary that contains only ''NSData'', ''NSString'', ''NSArray'', ''NSDictionary'', ''NSDate'', and ''NSNumber'' objects. Property list objects are toll-free bridged with their respective Core Foundation types (\<doc://com.apple.documentation/documentation/corefoundation/cfdata>, \<doc://com.apple.documentation/documentation/corefoundation/cfstring>, and so on). See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PropertyListSerialization property_list_serialization;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nspropertylistserialization
     */
    class PropertyListSerialization : public Object
    {
    public:
        /// @brief Creates a new `NSPropertyListSerialization` instance and returns a handle to it.
        explicit PropertyListSerialization();
        /// @brief Creates a null handle that refers to no native object.
        PropertyListSerialization(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PropertyListSerialization(Adopt adopt);
        /**
     * @brief Calls `+[NSPropertyListSerialization dataWithPropertyList:format:options:error:]`.
     * @details Returns an 'NSData' object containing the serialized representation of a given property list in a given format. The format can be either 'NSPropertyListXMLFormat_v1_0' or 'NSPropertyListBinaryFormat_v1_0'. The 'opt' parameter is currently unused and should be set to '0'. If an error occurs the return value will be 'nil' and the error parameter (if non-NULL) set to an autoreleased 'NSError' describing the problem.
     * @param plist Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param opt Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> data_with_property_list(const Object& plist, PropertyListFormat format, std::uint64_t opt);
        /**
     * @brief Calls `+[NSPropertyListSerialization propertyList:isValidForFormat:]`.
     * @details Returns a Boolean value that indicates whether a given property list is valid for a given format.
     * @param plist Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool property_list(const Object& plist, PropertyListFormat format);
        /**
     * @brief Calls `+[NSPropertyListSerialization propertyListWithData:options:format:error:]`.
     * @details Creates and returns a property list from the specified data. The options can be any of 'NSPropertyListMutabilityOptions'. If the format parameter is non-NULL, it will be filled out with the format that the property list was stored in. If an error occurs the return value will be 'nil' and the error parameter (if non-NULL) set to an autoreleased 'NSError' describing the problem.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param opt Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object property_list_with_data(const std::vector<std::uint8_t>& data, PropertyListMutabilityOptions opt, PropertyListFormat* format);
        /**
     * @brief Calls `+[NSPropertyListSerialization propertyListWithStream:options:format:error:]`.
     * @details Creates and returns a property list by reading from the specified stream. The options can be any of 'NSPropertyListMutabilityOptions'. If the format parameter is non-NULL, it will be filled out with the format that the property list was stored in. If an error occurs the return value will be 'nil' and the error parameter (if non-NULL) set to an autoreleased 'NSError' describing the problem.
     * @param stream Argument converted to the Objective-C parameter of the same role.
     * @param opt Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object property_list_with_stream(const InputStream& stream, PropertyListMutabilityOptions opt, PropertyListFormat* format);
        /**
     * @brief Calls `+[NSPropertyListSerialization writePropertyList:toStream:format:options:error:]`.
     * @details Writes a property list to an output stream in a given format. The stream should be opened and configured. The format can be either 'NSPropertyListXMLFormat_v1_0' or 'NSPropertyListBinaryFormat_v1_0'. The 'opt' parameter is currently unused and should be set to '0'. If an error occurs the return value will be '0' and the error parameter (if non-NULL) set to an autoreleased 'NSError' describing the problem. In a successful case, the return value is the number of bytes written to the stream.
     * @param plist Argument converted to the Objective-C parameter of the same role.
     * @param stream Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param opt Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::int64_t write_property_list(const Object& plist, const OutputStream& stream, PropertyListFormat format, std::uint64_t opt);
    };
}
