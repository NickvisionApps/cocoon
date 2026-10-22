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
     * @details An abstract class that serves as the basis for objects that enable archiving and distribution of other objects. ''NSCoder'' declares the interface used by concrete subclasses to transfer objects and other values between memory and some other format. This capability provides the basis for archiving (storing objects and data on disk) and distribution (copying objects and data items between different processes or threads). The concrete subclasses provided by Foundation for these purposes are ''NSArchiver'', ''NSUnarchiver'', ''NSKeyedArchiver'', ''NSKeyedUnarchiver'', and ''NSPortCoder''. Concrete subclasses of ''NSCoder'' are "coder classes", and instances of these classes are "coder objects" (or simply "coders"). A coder that can only encode values is an "encoder", and one that can only decode values is a "decoder". ''NSCoder'' operates on objects, scalars, C arrays, structures, strings, and on pointers to these types. It doesn't handle types whose implementation varies across platforms, such as 'union', 'void ', function pointers, and long chains of pointers. A coder stores object type information along with the data, so an object decoded from a stream of bytes is normally of the same class as the object that was originally encoded into the stream. An object can change its class when encoded, however; this is described in [Archives and Serializations Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Archiving/Archiving.html\#//apple_ref/doc/uid/10000047i). The AVFoundation framework adds methods to the ''NSCoder'' class to make it easier to create archives including Core Media time structures, and extract Core Media time structure from archives. \#\#\# Subclassing Notes For details of how to create a subclass of 'NSCoder', see [Subclassing NSCoder](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Archiving/Articles/subclassing.html\#//apple_ref/doc/uid/20000951) in [Archives and Serializations Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Archiving/Archiving.html\#//apple_ref/doc/uid/10000047i).
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
         * @details Returns a Boolean value that indicates whether an encoded value is available for a string. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_value_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeArrayOfObjCType:count:at:]`.
         * @details Decodes an array of 'count' items, whose Objective-C type is given by 'itemType'. The items are decoded into the buffer beginning at 'array', which must be large enough to contain them all. 'itemType' must contain exactly one type code. This method matches an ''encodeArrayOfObjCType:count:at:'' message used during encoding. You should not use this method to decode C arrays of Objective-C objects.
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
         * @details Decodes and returns a boolean value that was previously encoded and associated with the string 'key'. Subclasses must override this method if they perform keyed coding.
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
         * @details Decodes a buffer of data that was previously encoded with ''encodeBytes:length:forKey:'' and associated with the string 'key'. The buffer's length is returned by reference in 'lengthp'. The returned bytes are immutable. Subclasses must override this method if they perform keyed coding.
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
         * @details Decodes a buffer of data whose types are unspecified. The buffer's length is returned by reference in 'lengthp'. If you need the bytes beyond the scope of the current '\@autoreleasepool' block, you must copy them. This method matches an ''encodeBytes:length:'' message used during encoding.
         * @param lengthp Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        void* decode_bytes_with_returned_length(std::uint64_t* lengthp) const;
        /**
         * @brief Calls `-[NSCoder decodeDataObject]`.
         * @details Decodes and returns an 'NSData' object that was previously encoded with ''encodeDataObject:''. Subclasses must override this method.
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
         * @details Decodes and returns a double value that was previously encoded and associated with the string 'key'. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double decode_double_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeFloatForKey:]`.
         * @details Decodes and returns a float value that was previously encoded and associated with the string 'key'. If the value was encoded as a double, the extra precision is lost. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        float decode_float_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeInt32ForKey:]`.
         * @details Decodes and returns a 32-bit integer value that was previously encoded and associated with the string 'key'. If the encoded integer does not fit into a 32-bit integer, the method raises an 'NSRangeException'. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        int decode_int32_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeInt64ForKey:]`.
         * @details Decodes and returns a 64-bit integer value that was previously encoded and associated with the string 'key'. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t decode_int64_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeIntForKey:]`.
         * @details Decodes and returns an int value that was previously encoded and associated with the string 'key'. If the encoded integer does not fit into the default integer size, the method raises an 'NSRangeException'. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        int decode_int_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeIntegerForKey:]`.
         * @details Decodes and returns an NSInteger value that was previously encoded and associated with the string 'key'. If the encoded integer does not fit into the NSInteger size, the method raises an 'NSRangeException'. Subclasses must override this method if they perform keyed coding.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::int64_t decode_integer_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeObject]`.
         * @details Decodes and returns a previously-encoded object. 'NSCoder''s implementation invokes ''decodeValueOfObjCType:at:size:'' to decode the object data. Subclasses may need to override this method if they override any of the corresponding 'encode...Object' methods.
         * @return The converted Objective-C result.
         */
        Object decode_object() const;
        /**
         * @brief Calls `-[NSCoder decodeObjectForKey:]`.
         * @details Decodes and returns a previously-encoded object that was associated with the string 'key'. Subclasses must override this method if they perform keyed coding.
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
         * @details Decodes a property list that was previously encoded with ''encodePropertyList:''.
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
         * @details Decodes a previously-encoded object, returning an error if decoding fails.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_and_return_error() const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectForKey:error:]`.
         * @details Decodes and returns a previously-encoded object for the given key, returning an error if decoding fails.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_for_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectOfClass:forKey:error:]`.
         * @details Decodes an object for the key and restricted class, returning an error if decoding fails.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_of_class(const std::string& a_class, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeTopLevelObjectOfClasses:forKey:error:]`.
         * @details Decodes an object for the key and restricted classes, returning an error if decoding fails.
         * @param classes Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object decode_top_level_object_of_classes(const std::vector<std::string>& classes, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder decodeValueOfObjCType:at:]`.
         * @details Decodes a single value, whose Objective-C type is given by 'type'. \@DeprecationSummary { Use ''decodeValueOfObjCType:at:size:'' instead. } This method is unsafe because it could potentially cause buffer overruns.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         */
        void decode_value_of_obj_c_type(const std::string& type, void* data) const;
        /**
         * @brief Calls `-[NSCoder decodeValueOfObjCType:at:size:]`.
         * @details Decodes a single value of a known type from the specified data buffer. The 'type' parameter must contain exactly one type code, and the buffer specified by 'data' must be large enough to hold the value corresponding to that type code. Subclasses must override this method and provide an implementation to decode the value. This method matches an ''encodeValueOfObjCType:at:'' message used during encoding.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @param size Argument converted to the Objective-C parameter of the same role.
         */
        void decode_value_of_obj_c_type(const std::string& type, void* data, std::uint64_t size) const;
        /**
         * @brief Calls `-[NSCoder encodeArrayOfObjCType:count:at:]`.
         * @details Encodes an array of the given Objective-C type, provided the number of items and a pointer. The values are encoded from the buffer beginning at 'array'. 'type' must contain exactly one type code. This method must be matched by a subsequent ''decodeArrayOfObjCType:count:at:'' message. You should not use this method to encode C arrays of Objective-C objects.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param count Argument converted to the Objective-C parameter of the same role.
         * @param array Argument converted to the Objective-C parameter of the same role.
         */
        void encode_array_of_obj_c_type(const std::string& type, std::uint64_t count, const void* array) const;
        /**
         * @brief Calls `-[NSCoder encodeBool:forKey:]`.
         * @details Encodes a Boolean value and associates it with the string 'key'. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bool(bool value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeBycopyObject:]`.
         * @details An encoding method for subclasses to override such that it creates a copy, rather than a proxy, when decoded. 'NSCoder''s implementation simply invokes ''encodeObject:''. This method must be matched by a corresponding ''decodeObject'' message.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bycopy_object(const Object& an_object) const;
        /**
         * @brief Calls `-[NSCoder encodeByrefObject:]`.
         * @details An encoding method for subclasses to override such that it creates a proxy, rather than a copy, when decoded. 'NSCoder''s implementation simply invokes ''encodeObject:''. This method must be matched by a corresponding ''decodeObject'' message.
         * @param an_object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_byref_object(const Object& an_object) const;
        /**
         * @brief Calls `-[NSCoder encodeBytes:length:]`.
         * @details Encodes a buffer of data of an unspecified type. The buffer to be encoded begins at 'byteaddr', and its length in bytes is given by 'length'. This method must be matched by a corresponding ''decodeBytesWithReturnedLength:'' message.
         * @param byteaddr Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bytes(const void* byteaddr, std::uint64_t length) const;
        /**
         * @brief Calls `-[NSCoder encodeBytes:length:forKey:]`.
         * @details Encodes a buffer of data, given its length and a pointer, and associates it with a string key. Subclasses must override this method if they perform keyed coding.
         * @param bytes Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeConditionalObject:]`.
         * @details An encoding method for subclasses to override to conditionally encode an object, preserving common references to it. In the overriding method, 'object' should be encoded only if it's unconditionally encoded elsewhere (with any other 'encode...Object:' method). 'NSCoder''s implementation simply invokes ''encodeObject:''. This method must be matched by a subsequent ''decodeObject'' message.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_conditional_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCoder encodeConditionalObject:forKey:]`.
         * @details An encoding method for subclasses to override to conditionally encode an object, preserving common references to it, only if it has been unconditionally encoded. Subclasses must override this method if they support keyed coding.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_conditional_object(const Object& object, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeDataObject:]`.
         * @details Encodes a given data object. Subclasses must override this method. This method must be matched by a subsequent ''decodeDataObject'' message.
         * @param data Argument converted to the Objective-C parameter of the same role.
         */
        void encode_data_object(const std::vector<std::uint8_t>& data) const;
        /**
         * @brief Calls `-[NSCoder encodeDouble:forKey:]`.
         * @details Encodes a double-precision floating point value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_double(double value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeFloat:forKey:]`.
         * @details Encodes a floating point value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_float(float value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt32:forKey:]`.
         * @details Encodes a 32-bit integer value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int32(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt64:forKey:]`.
         * @details Encodes a 64-bit integer value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int64(std::int64_t value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInt:forKey:]`.
         * @details Encodes a C integer value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeInteger:forKey:]`.
         * @details Encodes an integer value and associates it with the string key. Subclasses must override this method if they perform keyed coding.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_integer(std::int64_t value, const std::string& key) const;
        /**
         * @brief Calls `-[NSCoder encodeObject:]`.
         * @details Encodes an object. 'NSCoder''s implementation simply invokes ''encodeValueOfObjCType:at:'' to encode 'object'. Subclasses can override this method to encode a reference to 'object' instead of 'object' itself. This method must be matched by a subsequent ''decodeObject'' message.
         * @param object Argument converted to the Objective-C parameter of the same role.
         */
        void encode_object(const Object& object) const;
        /**
         * @brief Calls `-[NSCoder encodeObject:forKey:]`.
         * @details Encodes an object and associates it with the string key. Subclasses must override this method to identify multiple encodings of 'object' and encode a reference to 'object' instead.
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
         * @details Encodes a property list. 'NSCoder''s implementation invokes ''encodeValueOfObjCType:at:'' to encode the property list. This method must be matched by a subsequent ''decodePropertyList'' message.
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
         * @details An encoding method for subclasses to override to encode an interconnected group of objects, starting with the provided root object. 'NSCoder''s implementation simply invokes ''encodeObject:''. This method must be matched by a subsequent ''decodeObject'' message.
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
         * @details Encodes a value of the given type at the given address. Subclasses must override this method, and match it with a subsequent ''decodeValueOfObjCType:at:size:'' message. When calling this method, 'type' must contain exactly one type code. You should not use this method to encode Objective-C objects.
         * @param type Argument converted to the Objective-C parameter of the same role.
         * @param addr Argument converted to the Objective-C parameter of the same role.
         */
        void encode_value_of_obj_c_type(const std::string& type, const void* addr) const;
        /**
         * @brief Calls `-[NSCoder failWithError:]`.
         * @details Signals to this coder that the decode operation has failed. Typically, you call this method in your ''NSCoding/init(coder:)'' implementation. You should set the error when you detect problems such as lack of secure coding, data corruption, or a domain validation failure. This method is only meaningful to call for decodes. The effect of calling this method depends on the value of ''decodingFailurePolicy'', as follows: - If the policy is ''DecodingFailurePolicy/raiseException'', calling this method throws an exception immediately. Swift code cannot catch this kind of exception. - If the policy is ''DecodingFailurePolicy/setErrorAndReturn'', calling this method sets the error property once per call to one of the 'decode' methods. Calling it repeatedly has no effect until the call stack unwinds to one of these methods' entry points. After calling 'failWithError:' within your ''NSCoding/init(coder:)'' implementation, you should clean up and return 'nil' as early as possible. - Parameter error: An error that indicates why decoding failed.
         * @param error Argument converted to the Objective-C parameter of the same role.
         */
        void fail_with_error(const Error& error) const;
        /**
         * @brief Calls `-[NSCoder versionForClassName:]`.
         * @details This method is present for historical reasons and is not used with keyed archivers. - Returns: The version in effect for the class named 'className' or 'NSNotFound' if no class named 'className' exists.
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
         * @details A Boolean value that indicates whether the receiver supports keyed coding of objects. 'NO' by default. Concrete subclasses that support keyed coding, such as 'NSKeyedArchiver', need to override this property to return 'YES'.
         * @return The converted Objective-C result.
         */
        bool allows_keyed_coding() const;
        /**
         * @brief Returns the `decodingFailurePolicy` property of `NSCoder`.
         * @details The action the coder should take when decoding fails. A decode call can fail for the following reasons: - The keyed archive data is corrupt or missing. - A type mismatch occurs, such as expecting a class but encountering a numeric type instead. This also occurs when 'decodeInteger(forKey:)' encounters a value encoded as floating-point, or vice versa. - A secure coding violation occurs. This happens when you attempt to decode an object that doesn't conform to 'NSSecureCoding', or when the encoded type doesn't match any of the expected types.
         * @return The converted Objective-C result.
         */
        DecodingFailurePolicy decoding_failure_policy() const;
        /**
         * @brief Returns the `error` property of `NSCoder`.
         * @details An error in the top-level decode. The meaning of this property depends on the setting of the 'decodingFailurePolicy' property. For 'NSDecodingFailurePolicyRaiseException', this property is always 'nil'. For 'NSDecodingFailurePolicySetErrorAndReturn', a non-'nil' value represents the first error encountered while decoding the archive. While 'error' is non-'nil', all attempts to decode data from this coder will return a 'nil'/zero-equivalent value. This error is consumed by a top-level decode API, which resets the coder back to being able to potentially decode data.
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
         * @details The system version in effect for the archive. During encoding, the current version. During decoding, the version that was in effect when the data was encoded. Subclasses that implement decoding must override this property to return the system version of the data being decoded.
         * @return The converted Objective-C result.
         */
        unsigned int system_version() const;
    };
}
