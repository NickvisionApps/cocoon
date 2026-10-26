#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;

    /**
     * @brief C++ handle for the Objective-C class `NSCoder` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Coder coder;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Coder coder{};
     * coder.contains_value_for_key("text");
     * coder.decode_array_of_objects_of_class("text", "text");
     * coder.decode_array_of_objects_of_classes({"a", "b"}, "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nscoder
     */
    class Coder : public Object
    {
    public:
        /// @brief Creates a new `NSCoder` instance and returns a handle to it.
        explicit Coder();
        /// @brief Creates a null handle that refers to no native object.
        Coder(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Coder(Adopt adopt);
        /**
         * @brief Calls `-[NSCoder containsValueForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_value_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeArrayOfObjCType:count:at:]`.
         * @param item_type Argument converted to the Objective-C parameter of the same role.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @param array Argument converted to the Objective-C parameter of the same role.
         */
        void decode_array_of_obj_c_type(const std::string& item_type, std::uint64_t count, void* array) const;
        /**
         * @brief Calls `-[NSCoder decodeArrayOfObjectsOfClass:forKey:]`.
         * @details Decodes the \\c NSArray object for the given \\c key, which should be an \\c NSArray\<cls>, containing the given non-collection class (no nested arrays or arrays of dictionaries, etc) from the coder. Requires \\c NSSecureCoding otherwise an exception is thrown and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the object for \\c key is not of the expected types, or cannot be decoded, and sets the \\c error on the decoder.
         * @param cls Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> decode_array_of_objects_of_class(const std::string& cls, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeArrayOfObjectsOfClasses:forKey:]`.
         * @details Decodes the \\c NSArray object for the given \\c key, which should be an \\c NSArray, containing the given non-collection classes (no nested arrays or arrays of dictionaries, etc) from the coder. Requires \\c NSSecureCoding otherwise an exception is thrown and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the object for \\c key is not of the expected types, or cannot be decoded, and sets the \\c error on the decoder.
         * @param classes Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> decode_array_of_objects_of_classes(const std::vector<std::string>& classes, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeBoolForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool decode_bool_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeBytesForKey:minimumLength:]`.
         * @details Decode bytes from the decoder for a given key. The length of the bytes must be greater than or equal to the 'length' parameter. If the result exists, but is of insufficient length, then the decoder uses 'failWithError' to fail the entire decode operation. The result of that is configurable on a per-NSCoder basis using 'NSDecodingFailurePolicy'.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        const std::uint8_t* decode_bytes_for_key(const std::string& key, std::uint64_t length) const;
        /**
         * @brief Calls `-[NSCoder decodeBytesForKey:returnedLength:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param lengthp Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        const std::uint8_t* decode_bytes_for_key(const std::string& key, std::uint64_t* lengthp) const;
        /**
         * @brief Calls `-[NSCoder decodeBytesWithMinimumLength:]`.
         * @details Decode bytes from the decoder. The length of the bytes must be greater than or equal to the 'length' parameter. If the result exists, but is of insufficient length, then the decoder uses 'failWithError' to fail the entire decode operation. The result of that is configurable on a per-NSCoder basis using 'NSDecodingFailurePolicy'.
         * @param length Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        void* decode_bytes_with_minimum_length(std::uint64_t length) const;
        /**
         * @brief Calls `-[NSCoder decodeBytesWithReturnedLength:]`.
         * @param lengthp Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        void* decode_bytes_with_returned_length(std::uint64_t* lengthp) const;
        /**
         * @brief Calls `-[NSCoder decodeDataObject]`.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> decode_data_object() const;
        /**
         * @brief Calls `-[NSCoder decodeDictionaryWithKeysOfClass:objectsOfClass:forKey:]`.
         * @details Decodes the \\c NSDictionary object for the given \\c key, which should be an \\c NSDictionary\<keyCls,objectCls> , with keys of type given in \\c keyCls and objects of the given non-collection class \\c objectCls (no nested dictionaries or other dictionaries contained in the dictionary, etc) from the coder. Requires \\c NSSecureCoding otherwise an exception is thrown and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the object for \\c key is not of the expected types, or cannot be decoded, and sets the \\c error on the decoder.
         * @param key_cls Argument converted to the Objective-C parameter of the same role.
         * @param object_cls Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> decode_dictionary_with_keys_of_class(const std::string& key_cls, const std::string& object_cls, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeDictionaryWithKeysOfClasses:objectsOfClasses:forKey:]`.
         * @details Decodes the \\c NSDictionary object for the given \\c key, which should be an \\c NSDictionary, with keys of the types given in \\c keyClasses and objects of the given non-collection classes in \\c objectClasses (no nested dictionaries or other dictionaries contained in the dictionary, etc) from the given coder. Requires \\c NSSecureCoding otherwise an exception is thrown and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the object for \\c key is not of the expected types, or cannot be decoded, and sets the \\c error on the decoder.
         * @param key_classes Argument converted to the Objective-C parameter of the same role.
         * @param object_classes Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::pair<Object, Object>> decode_dictionary_with_keys_of_classes(const std::vector<std::string>& key_classes, const std::vector<std::string>& object_classes, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeDoubleForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double decode_double_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeFloatForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        float decode_float_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeInt32ForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        int decode_int32_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeInt64ForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t decode_int64_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeIntForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        int decode_int_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeIntegerForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t decode_integer_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeObject]`.
         * @return The converted Objective-C result.
         */
        Object decode_object() const;
        /**
         * @brief Calls `-[NSCoder decodeObjectForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_object_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeObjectOfClass:forKey:]`.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_object_of_class(const std::string& a_class, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeObjectOfClasses:forKey:]`.
         * @param classes Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_object_of_classes(const std::vector<std::string>& classes, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodePoint]`.
         * @return The converted Objective-C result.
         */
        Point decode_point() const;
        /**
         * @brief Calls `-[NSCoder decodePointForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Point decode_point_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodePropertyList]`.
         * @return The converted Objective-C result.
         */
        Object decode_property_list() const;
        /**
         * @brief Calls `-[NSCoder decodePropertyListForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_property_list_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeRect]`.
         * @return The converted Objective-C result.
         */
        Rect decode_rect() const;
        /**
         * @brief Calls `-[NSCoder decodeRectForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Rect decode_rect_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeSize]`.
         * @return The converted Objective-C result.
         */
        Size decode_size() const;
        /**
         * @brief Calls `-[NSCoder decodeSizeForKey:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Size decode_size_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectAndReturnError:]`.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_and_return_error() const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectForKey:error:]`.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectOfClass:forKey:error:]`.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_of_class(const std::string& a_class, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectOfClasses:forKey:error:]`.
         * @param classes Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_of_classes(const std::vector<std::string>& classes, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeValueOfObjCType:at:]`.
         * @details This method is unsafe because it could potentially cause buffer overruns. You should use -decodeValueOfObjCType:at:size: instead.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         */
        void decode_value_of_obj_c_type(const std::string& type, void* data) const;
        /**
         * @brief Calls `-[NSCoder decodeValueOfObjCType:at:size:]`.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @param size Argument converted to the Objective-C parameter of the same role.
         */
        void decode_value_of_obj_c_type(const std::string& type, void* data, std::uint64_t size) const;
        /**
         * @brief Calls `-[NSCoder encodeArrayOfObjCType:count:at:]`.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @param array Argument converted to the Objective-C parameter of the same role.
         */
        void encode_array_of_obj_c_type(const std::string& type, std::uint64_t count, const void* array) const;
        /**
         * @brief Calls `-[NSCoder encodeBool:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bool(bool value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeBycopyObject:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bycopy_object(const Object& an_object) const;
        /**
         * @brief Calls `-[NSCoder encodeByrefObject:]`.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_byref_object(const Object& an_object) const;
        /**
         * @brief Calls `-[NSCoder encodeBytes:length:]`.
         * @param byteaddr Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bytes(const void* byteaddr, std::uint64_t length) const;
        /**
         * @brief Calls `-[NSCoder encodeBytes:length:forKey:]`.
         * @param bytes Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeConditionalObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_conditional_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCoder encodeConditionalObject:forKey:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_conditional_object(const Object& object, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeDataObject:]`.
         * @param data Argument converted to the Objective-C parameter of the same role.
         */
        void encode_data_object(const std::vector<std::uint8_t>& data) const;
        /**
         * @brief Calls `-[NSCoder encodeDouble:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_double(double value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeFloat:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_float(float value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt32:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int32(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt64:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int64(std::int64_t value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInteger:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_integer(std::int64_t value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCoder encodeObject:forKey:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_object(const Object& object, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodePoint:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         */
        void encode_point(const Point& point) const;
        /**
         * @brief Calls `-[NSCoder encodePoint:forKey:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_point(const Point& point, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodePropertyList:]`.
         * @param a_property_list Argument converted to the Objective-C parameter of the same role.
         */
        void encode_property_list(const Object& a_property_list) const;
        /**
         * @brief Calls `-[NSCoder encodeRect:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void encode_rect(const Rect& rect) const;
        /**
         * @brief Calls `-[NSCoder encodeRect:forKey:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_rect(const Rect& rect, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeRootObject:]`.
         * @param root_object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_root_object(const Object& root_object) const;
        /**
         * @brief Calls `-[NSCoder encodeSize:]`.
         * @param size Argument converted to the Objective-C parameter of the same role.
         */
        void encode_size(const Size& size) const;
        /**
         * @brief Calls `-[NSCoder encodeSize:forKey:]`.
         * @param size Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_size(const Size& size, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeValueOfObjCType:at:]`.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param addr Argument converted to the Objective-C parameter of the same role.
         */
        void encode_value_of_obj_c_type(const std::string& type, const void* addr) const;
        /**
         * @brief Calls `-[NSCoder failWithError:]`.
         * @details \@abstract Signals to this coder that the decode has failed. \@parameter non-nil error that describes the reason why the decode failed \@discussion Sets an error on this NSCoder once per TopLevel decode; calling it repeatedly will have no effect until the call stack unwinds to one of the TopLevel decode entry-points. This method is only meaningful to call for decodes. Typically, you would want to call this method in your -initWithCoder: implementation when you detect situations like: - lack of secure coding - corruption of your data - domain validation failures After calling -failWithError: within your -initWithCoder: implementation, you should clean up and return nil as early as possible. Once an error has been signaled to a decoder, it remains set until it has handed off to the first TopLevel decode invocation above it. For example, consider the following call graph: A -decodeTopLevelObjectForKey:error: B -initWithCoder: C -decodeObjectForKey: D -initWithCoder: E -decodeObjectForKey: F -failWithError: In this case the error provided in stack-frame F will be returned via the outError in stack-frame A. Furthermore the result object from decodeTopLevelObjectForKey:error: will be nil, regardless of the result of stack-frame B. NSCoder implementations support two mechanisms for the stack-unwinding from F to A: - forced (NSException based) - particpatory (error based) The kind of unwinding you get is determined by the decodingFailurePolicy property of this NSCoder (which defaults to NSDecodingFailurePolicyRaiseException to match historical behavior).
         * @param error Argument converted to the Objective-C parameter of the same role.
         */
        void fail_with_error(const Error& error) const;
        /**
         * @brief Calls `-[NSCoder versionForClassName:]`.
         * @param class_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t version_for_class_name(const std::string& class_name) const;
        /**
         * @brief Returns the `allowedClasses` property of `NSCoder`.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> allowed_classes() const;
        /**
         * @brief Returns the `allowsKeyedCoding` property of `NSCoder`.
         * @return The converted Objective-C result.
         */
        bool allows_keyed_coding() const;
        /**
         * @brief Returns the `decodingFailurePolicy` property of `NSCoder`.
         * @details \@abstract Defines the behavior this NSCoder should take on decode failure (i.e. corrupt archive, invalid data, etc.). \@discussion The default result of this property is NSDecodingFailurePolicyRaiseException, subclasses can change this to an alternative policy.
         * @return The converted Objective-C result.
         */
        DecodingFailurePolicy decoding_failure_policy() const;
        /**
         * @brief Returns the `error` property of `NSCoder`.
         * @details \@abstract The current error (if there is one) for the current TopLevel decode. \@discussion The meaning of this property changes based on the result of the decodingFailurePolicy property: For NSDecodingFailurePolicyRaiseException, this property will always be nil. For NSDecodingFailurePolicySetErrorAndReturn, this property can be non-nil, and if so, indicates that there was a failure while decoding the archive (specifically its the very first error encountered). While .error is non-nil, all attempts to decode data from this coder will return a nil/zero-equivalent value. This error is consumed by a TopLevel decode API (which resets this coder back to a being able to potentially decode data).
         * @return The converted Objective-C result.
         */
        Error error() const;
        /**
         * @brief Returns the `requiresSecureCoding` property of `NSCoder`.
         * @return The converted Objective-C result.
         */
        bool requires_secure_coding() const;
        /**
         * @brief Returns the `systemVersion` property of `NSCoder`.
         * @return The converted Objective-C result.
         */
        unsigned int system_version() const;
    };
}
