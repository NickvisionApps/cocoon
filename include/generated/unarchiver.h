#pragma once

#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnarchiver` (Foundation).
     * @details A decoder that restores data from an archive. ''NSUnarchiver'', a concrete subclass of ''NSCoder'', defines methods for decoding a set of Objective-C objects from an archive. Such archives are produced by objects of the ''NSArchiver'' class. In macOS 10.2 and later, ''NSArchiver'' and ''NSUnarchiver'' have been replaced by ''NSKeyedArchiver'' and ''NSKeyedUnarchiver'' respectively—see [Archives and Serializations Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Archiving/Archiving.html\#//apple_ref/doc/uid/10000047i). \@DeprecationSummary { Use ''NSKeyedUnarchiver'' instead. }
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Unarchiver unarchiver;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Unarchiver unarchiver{};
     * unarchiver.class_name_decoded_for_archive_class_name("text");
     * unarchiver.decode_class_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunarchiver
     */
    class Unarchiver : public Coder
    {
    public:
        /// @brief Creates a new `NSUnarchiver` instance and returns a handle to it.
        explicit Unarchiver(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSUnarchiver` instance and returns a handle to it.
        explicit Unarchiver();
        /// @brief Creates a null handle that refers to no native object.
        Unarchiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Unarchiver(Adopt adopt);
        using Coder::system_version;
        /**
     * @brief Calls `-[NSUnarchiver classNameDecodedForArchiveClassName:]`.
     * @details Returns the class name that this unarchiver substitutes for a given archived class name. Returns 'inArchiveName' unless a substitute name has been specified using the instance method ''decodeClassName:asClassName:''. - Parameter inArchiveName: The name of a class. - Returns: The name of the class used when instantiating objects whose ostensible class, according to the archived data, is 'inArchiveName'.
     * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string class_name_decoded_for_archive_class_name(const std::string& in_archive_name) const;
        /**
     * @brief Calls `-[NSUnarchiver decodeClassName:asClassName:]`.
     * @details Sets a per-instance substitution mapping, translating a given class name from the archive to a given replacement class name during decoding. This method enables easy conversion of unarchived data when the name of a class has changed since the archive was created. Note that there's also a class method of the same name. The class method has precedence in case of conflicts. - Parameters: - inArchiveName: The ostensible name of a class in an archive. - trueName: The name of the class to use when instantiating objects whose ostensible class, according to the archived data, is 'inArchiveName'.
     * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
     * @param true_name Argument converted to the Objective-C parameter of the same role.
     */
        void decode_class_name(const std::string& in_archive_name, const std::string& true_name) const;
        /**
     * @brief Calls `-[NSUnarchiver replaceObject:withObject:]`.
     * @details Replaces one object with another during decoding. Causes the receiver to substitute 'newObject' for 'object' whenever 'object' is extracted from the archive. 'newObject' can be of a different class from 'object', and the class mappings set by ''decodeClassName:asClassName:'' are ignored. - Parameters: - object: The archived object to replace. - newObject: The object with which to replace 'object'.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param new_object Argument converted to the Objective-C parameter of the same role.
     */
        void replace_object(const Object& object, const Object& new_object) const;
        /**
     * @brief Calls `+[NSUnarchiver unarchiveObjectWithData:]`.
     * @details Decodes and returns the previously-archived object graph in the given data. This method invokes ''NSUnarchiver/initForReadingWithData:'' and ''NSCoder/decodeObject'' to create a temporary 'NSUnarchiver' object that decodes the object. If the archived object is the root of a graph of objects, the entire graph is unarchived. - Parameter data: An 'NSData' object that contains an archive created using 'NSArchiver'. - Returns: The object, or object graph, that was archived in 'data'. Returns 'nil' if 'data' cannot be unarchived.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object unarchive_object_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSUnarchiver unarchiveObjectWithFile:]`.
     * @details Decodes and returns the previously-archived object graph from the file at the given path. This convenience method reads the file by invoking the 'NSData' method ''NSData/dataWithContentsOfFile:'' and then invokes ''NSUnarchiver/unarchiveObjectWithData:''. - Parameter path: The path to a file that contains an archive created using ''NSArchiver''. - Returns: The object, or object graph, that was archived in the file at 'path'. Returns 'nil' if the file at 'path' cannot be unarchived.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object unarchive_object_with_file(const std::string& path);
        /**
     * @brief Returns the `atEnd` property of `NSUnarchiver`.
     * @details A Boolean value that indicates whether the receiver has reached the end of the encoded data while decoding. You can invoke this after invoking 'decodeObject' to discover whether the archive contains extra data following the encoded object graph. If it does, you can either ignore this anomaly or consider it an error.
     * @return The converted Objective-C result.
     */
        bool is_at_end() const;
        /**
     * @brief Returns the `systemVersion` property of `NSUnarchiver`.
     * @details The system version number in effect when the archive was created. This information is available as soon as the receiver has been initialized.
     * @return The converted Objective-C result.
     */
        unsigned int system_version() const;
    };
}
