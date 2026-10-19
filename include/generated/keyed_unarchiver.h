#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSKeyedUnarchiver` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::KeyedUnarchiver keyed_unarchiver;
     * keyed_unarchiver.set_decoding_failure_policy(cocoon::DecodingFailurePolicy::RaiseException);
     * keyed_unarchiver.unarchiver_will_replace_object_with_object().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::KeyedUnarchiver keyed_unarchiver{};
     * keyed_unarchiver.set_decoding_failure_policy(cocoon::DecodingFailurePolicy::RaiseException);
     * auto decoding_failure_policy = keyed_unarchiver.decoding_failure_policy();
     * keyed_unarchiver.set_requires_secure_coding(true);
     * auto requires_secure_coding = keyed_unarchiver.requires_secure_coding();
     * keyed_unarchiver.class_for_class_name("text");
     * keyed_unarchiver.contains_value_for_key("text");
     * keyed_unarchiver.decode_bool_for_key("text");
     * keyed_unarchiver.unarchiver_will_replace_object_with_object().connect([](cocoon::Object a0, cocoon::Object a1) {});
     * keyed_unarchiver.unarchiver_will_finish().connect([]() {});
     * keyed_unarchiver.unarchiver_did_finish().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nskeyedunarchiver
     */
    class KeyedUnarchiver : public Coder
    {
    public:
        /// @brief Creates a new `NSKeyedUnarchiver` instance and returns a handle to it.
        explicit KeyedUnarchiver(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSKeyedUnarchiver` instance and returns a handle to it.
        explicit KeyedUnarchiver();
        /// @brief Creates a null handle that refers to no native object.
        KeyedUnarchiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit KeyedUnarchiver(Adopt adopt);
        using Coder::contains_value_for_key;
        using Coder::decode_bool_for_key;
        using Coder::decode_bytes_for_key;
        using Coder::decode_double_for_key;
        using Coder::decode_float_for_key;
        using Coder::decode_int32_for_key;
        using Coder::decode_int64_for_key;
        using Coder::decode_int_for_key;
        using Coder::decode_object_for_key;
        using Coder::decoding_failure_policy;
        using Coder::requires_secure_coding;
        /**
     * @brief Calls `-[NSKeyedUnarchiver classForClassName:]`.
     * @param coded_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string class_for_class_name(const std::string& coded_name) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver containsValueForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_value_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeBoolForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool decode_bool_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeBytesForKey:returnedLength:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @param lengthp Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        const std::uint8_t* decode_bytes_for_key(const std::string& key, std::uint64_t* lengthp) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeDoubleForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double decode_double_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeFloatForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        float decode_float_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeInt32ForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        int decode_int32_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeInt64ForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t decode_int64_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeIntForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        int decode_int_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver decodeObjectForKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object decode_object_for_key(const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver finishDecoding]`.
     */
        void finish_decoding() const;
        /**
     * @brief Calls `-[NSKeyedUnarchiver setClass:forClassName:]`.
     * @param cls Argument converted to the Objective-C parameter of the same role.
     * @param coded_name Argument converted to the Objective-C parameter of the same role.
     */
        void set_class(const std::string& cls, const std::string& coded_name) const;
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedArrayOfObjectsOfClass:fromData:error:]`.
     * @details Decodes the \\c NSArray root object from \\c data which should be an \\c NSArray\<cls> containing the given non-collection class (no nested arrays or arrays of dictionaries, etc) from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param cls Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<Object> unarchived_array_of_objects_of_class(const std::string& cls, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedArrayOfObjectsOfClasses:fromData:error:]`.
     * @details Decodes the \\c NSArray root object from \\c data which should be an \\c NSArray, containing the given non-collection classes in \\c classes (no nested arrays or arrays of dictionaries, etc) from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param classes Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<Object> unarchived_array_of_objects_of_classes(const std::vector<std::string>& classes, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedDictionaryWithKeysOfClass:objectsOfClass:fromData:error:]`.
     * @details Decodes the \\c NSDictionary root object from \\c data which should be an \\c NSDictionary\<keyCls,objectCls> with keys of type given in \\c keyCls and objects of the given non-collection class \\c objectCls (no nested dictionaries or other dictionaries contained in the dictionary, etc) from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param key_cls Argument converted to the Objective-C parameter of the same role.
     * @param value_cls Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::pair<Object, Object>> unarchived_dictionary_with_keys_of_class(const std::string& key_cls, const std::string& value_cls, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedDictionaryWithKeysOfClasses:objectsOfClasses:fromData:error:]`.
     * @details Decodes the \\c NSDictionary root object from \\c data which should be an \\c NSDictionary, with keys of the types given in \\c keyClasses and objects of the given non-collection classes in \\c objectClasses (no nested dictionaries or other dictionaries contained in the dictionary, etc) from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param key_classes Argument converted to the Objective-C parameter of the same role.
     * @param value_classes Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::pair<Object, Object>> unarchived_dictionary_with_keys_of_classes(const std::vector<std::string>& key_classes, const std::vector<std::string>& value_classes, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedObjectOfClass:fromData:error:]`.
     * @details Decodes the root object of the given class from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param cls Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object unarchived_object_of_class(const std::string& cls, const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSKeyedUnarchiver unarchivedObjectOfClasses:fromData:error:]`.
     * @details Decodes the root object of one of the given classes from the given archive, previously encoded by \\c NSKeyedArchiver. Enables \\c requiresSecureCoding and sets the \\c decodingFailurePolicy to \\c NSDecodingFailurePolicySetErrorAndReturn. Returns \\c nil if the given data is not valid or cannot be decoded, and sets the \\c error out parameter.
     * @param classes Argument converted to the Objective-C parameter of the same role.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object unarchived_object_of_classes(const std::vector<std::string>& classes, const std::vector<std::uint8_t>& data);
        /**
     * @brief Returns the `decodingFailurePolicy` property of `NSKeyedUnarchiver`.
     * @return The converted Objective-C result.
     */
        DecodingFailurePolicy decoding_failure_policy() const;
        /**
     * @brief Sets the `decodingFailurePolicy` property of `NSKeyedUnarchiver`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_decoding_failure_policy(DecodingFailurePolicy value) const;
        /**
     * @brief Returns the `requiresSecureCoding` property of `NSKeyedUnarchiver`.
     * @return The converted Objective-C result.
     */
        bool requires_secure_coding() const;
        /**
     * @brief Sets the `requiresSecureCoding` property of `NSKeyedUnarchiver`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_requires_secure_coding(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `unarchiver_cannot_decode_object_of_class_name_original_classes`; connect a callback with `unarchiver_cannot_decode_object_of_class_name_original_classes().connect(...)`.
        Signal<KeyedUnarchiver, std::string(std::string, std::vector<std::string>)> unarchiver_cannot_decode_object_of_class_name_original_classes() const
        {
            return Signal<KeyedUnarchiver, std::string(std::string, std::vector<std::string>)>(handle(), "unarchiver_cannot_decode_object_of_class_name_original_classes");
        }
        /// @brief Signal for the delegate/data-source method behind `unarchiver_did_decode_object`; connect a callback with `unarchiver_did_decode_object().connect(...)`.
        Signal<KeyedUnarchiver, Object(Object)> unarchiver_did_decode_object() const
        {
            return Signal<KeyedUnarchiver, Object(Object)>(handle(), "unarchiver_did_decode_object");
        }
        /// @brief Signal for the delegate/data-source method behind `unarchiver_will_replace_object_with_object`; connect a callback with `unarchiver_will_replace_object_with_object().connect(...)`.
        Signal<KeyedUnarchiver, void(Object, Object)> unarchiver_will_replace_object_with_object() const
        {
            return Signal<KeyedUnarchiver, void(Object, Object)>(handle(), "unarchiver_will_replace_object_with_object");
        }
        /// @brief Signal for the delegate/data-source method behind `unarchiver_will_finish`; connect a callback with `unarchiver_will_finish().connect(...)`.
        Signal<KeyedUnarchiver, void()> unarchiver_will_finish() const
        {
            return Signal<KeyedUnarchiver, void()>(handle(), "unarchiver_will_finish");
        }
        /// @brief Signal for the delegate/data-source method behind `unarchiver_did_finish`; connect a callback with `unarchiver_did_finish().connect(...)`.
        Signal<KeyedUnarchiver, void()> unarchiver_did_finish() const
        {
            return Signal<KeyedUnarchiver, void()>(handle(), "unarchiver_did_finish");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
