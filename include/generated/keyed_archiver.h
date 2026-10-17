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
     * @details An encoder that stores an object's data to an archive referenced by keys. ''NSKeyedArchiver'', a concrete subclass of ''NSCoder'', provides a way to encode objects (and scalar values) into an architecture-independent format suitable for storage in a file. When you archive a set of objects, the archiver writes the class information and instance variables for each object to the archive. The companion class ''NSKeyedUnarchiver'' decodes the data in an archive and creates a set of objects equivalent to the original set. A keyed archive differs from a non-keyed archive in that all the objects and values encoded into the archive have names, or keys. When decoding a non-keyed archive, the decoder must decode values in the same order the original encoder used. When decoding a keyed archive, the decoder requests values by name, meaning it can decode values out of sequence or not at all. Keyed archives, therefore, provide better support for forward and backward compatibility. The keys given to encoded values must be unique only within the scope of the currently-encoding object. A keyed archive is hierarchical, so the keys used by object A to encode its instance variables don't conflict with the keys used by object B. This is true even if A and B are instances of the same class. Within a single object, however, the keys used by a subclass can conflict with keys used in its superclasses. An ''NSArchiver'' object can write the archive data to a file or to a mutable-data object (an instance of ''NSMutableData'') that you provide.
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
        explicit KeyedArchiver(const std::vector<std::uint8_t>& data);
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
     * @brief Calls `+[NSKeyedArchiver archiveRootObject:toFile:]`.
     * @details Archives an object graph rooted at a given object to a file at a given path. \@DeprecationSummary { Use ''NSKeyedArchiver/archivedDataWithRootObject:requiringSecureCoding:error:'' and '-writeToURL:options:error:' instead. } This method archives the graph formed by the root object to a data object, then atomically writes it to the given path. The format of the archive is 'NSPropertyListBinaryFormat_v1_0'.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool archive_root_object(const Object& root_object, const std::string& path);
        /**
     * @brief Calls `+[NSKeyedArchiver archivedDataWithRootObject:]`.
     * @details Returns a data object that contains the encoded form of the object graph formed by the given root object. \@DeprecationSummary { Use ''NSKeyedArchiver/archivedDataWithRootObject:requiringSecureCoding:error:'' instead. } The format of the archive is 'NSPropertyListBinaryFormat_v1_0'.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> archived_data_with_root_object(const Object& root_object);
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
     * @details Returns the class name with which this archiver encodes instances of a given class. Returns 'nil' if the receiver does not have a translation mapping for 'cls'. The class's separate translation map is not searched.
     * @param cls Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string class_name_for_class(const std::string& cls) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeBool:forKey:]`.
     * @details Encodes a given Boolean value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_bool(bool value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeBytes:length:forKey:]`.
     * @details Encodes a given number of bytes from a given C array of bytes and associates them with a key.
     * @param bytes Argument converted to the Objective-C parameter of the same role.
     * @param length Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_bytes(const std::uint8_t* bytes, std::uint64_t length, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeConditionalObject:forKey:]`.
     * @details Encodes a reference to a given object and associates it with a key only if it has been unconditionally encoded elsewhere in the archive.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_conditional_object(const Object& object, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeDouble:forKey:]`.
     * @details Encodes a given 'double' value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_double(double value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeFloat:forKey:]`.
     * @details Encodes a given 'float' value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_float(float value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeInt32:forKey:]`.
     * @details Encodes a given 32-bit integer value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_int32(int value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeInt64:forKey:]`.
     * @details Encodes a given 64-bit integer value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_int64(std::int64_t value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeInt:forKey:]`.
     * @details Encodes a given 'int' value and associates it with a key.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_int(int value, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver encodeObject:forKey:]`.
     * @details Encodes a given object and associates it with a given key.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void encode_object(const Object& object, const std::string& key) const;
        /**
     * @brief Calls `-[NSKeyedArchiver finishEncoding]`.
     * @details Instructs the receiver to construct the final data stream. No more values can be encoded after this method is called. You must call this method when finished.
     */
        void finish_encoding() const;
        /**
     * @brief Calls `-[NSKeyedArchiver setClassName:forClass:]`.
     * @details Sets a mapping for this archiver to encode instances of a given class with the provided name, rather than their real name. When encoding, the receiver's translation map overrides any translation that may also be present in the class's map.
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
     * @details The format in which the receiver encodes its data. The available formats are XML and binary.
     * @return The converted Objective-C result.
     */
        PropertyListFormat output_format() const;
        /**
     * @brief Sets the `outputFormat` property of `NSKeyedArchiver`.
     * @details The format in which the receiver encodes its data. The available formats are XML and binary.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_output_format(PropertyListFormat value) const;
        /**
     * @brief Returns the `requiresSecureCoding` property of `NSKeyedArchiver`.
     * @details Indicates whether the archiver requires all archived classes to resist object substitution attacks. If you set the archiver to require secure coding, it throws an exception if you attempt to archive a class which doesn't conform to 'NSSecureCoding'. Note that the getter is on the superclass, 'NSCoder'. See 'NSCoder' for more information about secure coding. Enabling secure coding doesn't change the output format of the archive.
     * @return The converted Objective-C result.
     */
        bool requires_secure_coding() const;
        /**
     * @brief Sets the `requiresSecureCoding` property of `NSKeyedArchiver`.
     * @details Indicates whether the archiver requires all archived classes to resist object substitution attacks. If you set the archiver to require secure coding, it throws an exception if you attempt to archive a class which doesn't conform to 'NSSecureCoding'. Note that the getter is on the superclass, 'NSCoder'. See 'NSCoder' for more information about secure coding. Enabling secure coding doesn't change the output format of the archive.
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
