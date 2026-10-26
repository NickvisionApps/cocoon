#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class InputStream;
    class OutputStream;

    /**
     * @brief C++ handle for the Objective-C class `NSJSONSerialization` (Foundation).
     * @details A class for converting JSON to Foundation objects and converting Foundation objects to JSON. An object that may be converted to JSON must have the following properties: - Top level object is an NSArray or NSDictionary - All objects are NSString, NSNumber, NSArray, NSDictionary, or NSNull - All dictionary keys are NSStrings - NSNumbers are not NaN or infinity
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::JSONSerialization json_serialization;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsjsonserialization
     */
    class JSONSerialization : public Object
    {
    public:
        /// @brief Creates a new `NSJSONSerialization` instance and returns a handle to it.
        explicit JSONSerialization();
        /// @brief Creates a null handle that refers to no native object.
        JSONSerialization(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit JSONSerialization(Adopt adopt);
        /**
         * @brief Calls `+[NSJSONSerialization JSONObjectWithData:options:error:]`.
         * @details Create a Foundation object from JSON data. Set the NSJSONReadingAllowFragments option if the parser should allow top-level objects that are not an NSArray or NSDictionary. Setting the NSJSONReadingMutableContainers option will make the parser generate mutable NSArrays and NSDictionaries. Setting the NSJSONReadingMutableLeaves option will make the parser generate mutable NSString objects. If an error occurs during the parse, then the error parameter will be set and the result will be nil. The data must be in one of the 5 supported encodings listed in the JSON specification: UTF-8, UTF-16LE, UTF-16BE, UTF-32LE, UTF-32BE. The data may or may not have a BOM. The most efficient encoding to use for parsing is UTF-8, so if you have a choice in encoding the data passed to this method, use UTF-8.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @param opt Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object json_object_with_data(const std::vector<std::uint8_t>& data, JSONReadingOptions opt);
        /**
         * @brief Calls `+[NSJSONSerialization JSONObjectWithStream:options:error:]`.
         * @details Create a JSON object from JSON data stream. The stream should be opened and configured. All other behavior of this method is the same as the JSONObjectWithData:options:error: method.
         * @param stream Argument converted to the Objective-C parameter of the same role.
         * @param opt Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object json_object_with_stream(const InputStream& stream, JSONReadingOptions opt);
        /**
         * @brief Calls `+[NSJSONSerialization dataWithJSONObject:options:error:]`.
         * @details Generate JSON data from a Foundation object. If the object will not produce valid JSON then an exception will be thrown. Setting the NSJSONWritingPrettyPrinted option will generate JSON with whitespace designed to make the output more readable. If that option is not set, the most compact possible JSON will be generated. If an error occurs, the error parameter will be set and the return value will be nil. The resulting data is a encoded in UTF-8.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param opt Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::uint8_t> data_with_json_object(const Object& obj, JSONWritingOptions opt);
        /**
         * @brief Calls `+[NSJSONSerialization isValidJSONObject:]`.
         * @details Returns YES if the given object can be converted to JSON data, NO otherwise. The object must have the following properties: - Top level object is an NSArray or NSDictionary - All objects are NSString, NSNumber, NSArray, NSDictionary, or NSNull - All dictionary keys are NSStrings - NSNumbers are not NaN or infinity Other rules may apply. Calling this method or attempting a conversion are the definitive ways to tell if a given object can be converted to JSON data.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool is_valid_json_object(const Object& obj);
        /**
         * @brief Calls `+[NSJSONSerialization writeJSONObject:toStream:options:error:]`.
         * @details Write JSON data into a stream. The stream should be opened and configured. The return value is the number of bytes written to the stream, or 0 on error. All other behavior of this method is the same as the dataWithJSONObject:options:error: method.
         * @param obj Argument converted to the Objective-C parameter of the same role.
         * @param stream Argument converted to the Objective-C parameter of the same role.
         * @param opt Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::int64_t write_json_object(const Object& obj, const OutputStream& stream, JSONWritingOptions opt);
    };
}
