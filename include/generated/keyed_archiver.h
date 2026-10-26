#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSKeyedArchiver` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::KeyedArchiver keyed_archiver;
     * keyed_archiver.set_output_format(cocoon::PropertyListFormat::OpenStepFormat);
     * keyed_archiver.archiver_did_encode_object().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::KeyedArchiver keyed_archiver{};
     * keyed_archiver.set_output_format(cocoon::PropertyListFormat::OpenStepFormat);
     * auto output_format = keyed_archiver.output_format();
     * keyed_archiver.set_requires_secure_coding(true);
     * auto requires_secure_coding = keyed_archiver.requires_secure_coding();
     * keyed_archiver.class_name_for_class("text");
     * keyed_archiver.encode_bool(true, "text");
     * keyed_archiver.encode_double(1, "text");
     * keyed_archiver.archiver_did_encode_object().connect([](cocoon::Object a0) {});
     * keyed_archiver.archiver_will_replace_object_with_object().connect([](cocoon::Object a0, cocoon::Object a1) {});
     * keyed_archiver.archiver_will_finish().connect([]() {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nskeyedarchiver
     */
    class KeyedArchiver : public Coder
    {
    public:
        /// @brief Creates a new `NSKeyedArchiver` instance and returns a handle to it.
        explicit KeyedArchiver(bool requires_secure_coding);
        /// @brief Creates a new `NSKeyedArchiver` instance and returns a handle to it.
        explicit KeyedArchiver();
        /// @brief Creates a null handle that refers to no native object.
        KeyedArchiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit KeyedArchiver(Adopt adopt);
        using Coder::encode_bool;
        using Coder::encode_bytes;
        using Coder::encode_conditional_object;
        using Coder::encode_double;
        using Coder::encode_float;
        using Coder::encode_int;
        using Coder::encode_int32;
        using Coder::encode_int64;
        using Coder::encode_object;
        using Coder::requires_secure_coding;
        /**
         * @brief Calls `+[NSKeyedArchiver archivedDataWithRootObject:requiringSecureCoding:error:]`.
         * @details Returns an \\c NSData object containing the encoded form of the object graph whose root object is given, optionally disabling secure coding. If \\c NSSecureCoding cannot be used, \\c requiresSecureCoding may be turned off here; for improved security, however, \\c requiresSecureCoding should be left enabled whenever possible. \\c requiresSecureCoding ensures that all encoded objects conform to \\c NSSecureCoding, preventing the possibility of encoding objects which cannot be decoded later. If the object graph cannot be encoded, returns \\c nil and sets the \\c error out parameter.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param requires_secure_coding Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::vector<std::uint8_t> archived_data_with_root_object(const Object& object, bool requires_secure_coding);
        /**
         * @brief Calls `-[NSKeyedArchiver classNameForClass:]`.
         * @param cls Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string class_name_for_class(const std::string& cls) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeBool:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bool(bool value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeBytes:length:forKey:]`.
         * @param bytes Argument converted to the Objective-C parameter of the same role.
         * @param length Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeConditionalObject:forKey:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_conditional_object(const Object& object, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeDouble:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_double(double value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeFloat:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_float(float value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeInt32:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int32(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeInt64:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int64(std::int64_t value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeInt:forKey:]`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_int(int value, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver encodeObject:forKey:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void encode_object(const Object& object, const std::string& key) const;
        /**
         * @brief Calls `-[NSKeyedArchiver finishEncoding]`.
         */
        void finish_encoding() const;
        /**
         * @brief Calls `-[NSKeyedArchiver setClassName:forClass:]`.
         * @param coded_name Argument converted to the Objective-C parameter of the same role.
         * @param cls Argument converted to the Objective-C parameter of the same role.
         */
        void set_class_name(const std::string& coded_name, const std::string& cls) const;
        /**
         * @brief Returns the `encodedData` property of `NSKeyedArchiver`.
         * @details If encoding has not yet finished, then invoking this property will call finishEncoding and return the data. If you initialized the keyed archiver with a specific mutable data instance, then it will be returned from this property after finishEncoding is called.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> encoded_data() const;
        /**
         * @brief Returns the `outputFormat` property of `NSKeyedArchiver`.
         * @return The converted Objective-C result.
         */
        PropertyListFormat output_format() const;
        /**
         * @brief Sets the `outputFormat` property of `NSKeyedArchiver`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_output_format(PropertyListFormat value) const;
        /**
         * @brief Returns the `requiresSecureCoding` property of `NSKeyedArchiver`.
         * @return The converted Objective-C result.
         */
        bool requires_secure_coding() const;
        /**
         * @brief Sets the `requiresSecureCoding` property of `NSKeyedArchiver`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_requires_secure_coding(bool value) const;
        /// @brief Signal for the delegate/data-source method behind `archiver_will_encode_object`; connect a callback with `archiver_will_encode_object().connect(...)`.
        Signal<KeyedArchiver, Object(Object)> archiver_will_encode_object() const
        {
            return Signal<KeyedArchiver, Object(Object)>(handle(), "archiver_will_encode_object");
        }
        /// @brief Signal for the delegate/data-source method behind `archiver_did_encode_object`; connect a callback with `archiver_did_encode_object().connect(...)`.
        Signal<KeyedArchiver, void(Object)> archiver_did_encode_object() const
        {
            return Signal<KeyedArchiver, void(Object)>(handle(), "archiver_did_encode_object");
        }
        /// @brief Signal for the delegate/data-source method behind `archiver_will_replace_object_with_object`; connect a callback with `archiver_will_replace_object_with_object().connect(...)`.
        Signal<KeyedArchiver, void(Object, Object)> archiver_will_replace_object_with_object() const
        {
            return Signal<KeyedArchiver, void(Object, Object)>(handle(), "archiver_will_replace_object_with_object");
        }
        /// @brief Signal for the delegate/data-source method behind `archiver_will_finish`; connect a callback with `archiver_will_finish().connect(...)`.
        Signal<KeyedArchiver, void()> archiver_will_finish() const
        {
            return Signal<KeyedArchiver, void()>(handle(), "archiver_will_finish");
        }
        /// @brief Signal for the delegate/data-source method behind `archiver_did_finish`; connect a callback with `archiver_did_finish().connect(...)`.
        Signal<KeyedArchiver, void()> archiver_did_finish() const
        {
            return Signal<KeyedArchiver, void()>(handle(), "archiver_did_finish");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
