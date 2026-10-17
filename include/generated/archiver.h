#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSArchiver` (Foundation).
     * @details A coder that stores an object's data to an archive. ''NSArchiver'', a concrete subclass of ''NSCoder'', provides a way to encode objects into an architecture-independent format that can be stored in a file. When you archive a graph of objects, the class information and instance variables for each object are written to the archive. The companion class ''NSUnarchiver'' decodes the data in an archive and creates a graph of objects equivalent to the original set. ''NSArchiver'' stores the archive data in a mutable data object (''NSMutableData''). After encoding the objects, you can have the ''NSArchiver'' object write this mutable data object immediately to a file, or you can retrieve the mutable data object for some other use. In macOS 10.2 and later, ''NSArchiver'' and ''NSUnarchiver'' have been replaced by ''NSKeyedArchiver'' and ''NSKeyedUnarchiver'' respectively—see [Archives and Serializations Programming Guide](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/Archiving/Archiving.html\#//apple_ref/doc/uid/10000047i). \@DeprecationSummary { Use ''NSKeyedArchiver'' instead. }
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Archiver archiver;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Archiver archiver{};
     * archiver.class_name_encoded_for_true_class_name("text");
     * archiver.encode_class_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsarchiver
     */
    class Archiver : public Coder
    {
    public:
        /// @brief Creates a new `NSArchiver` instance and returns a handle to it.
        explicit Archiver(const std::vector<std::uint8_t>& mdata);
        /// @brief Creates a new `NSArchiver` instance and returns a handle to it.
        explicit Archiver();
        /// @brief Creates a null handle that refers to no native object.
        Archiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Archiver(Adopt adopt);
        using Coder::encode_conditional_object;
        using Coder::encode_root_object;
        /**
     * @brief Calls `+[NSArchiver archiveRootObject:toFile:]`.
     * @details Archives an object graph rooted at a given object by encoding it into a data object then atomically writing the resulting data object to a file at a given path. This convenience method invokes ''NSArchiver/archivedDataWithRootObject:'' to get the encoded data, and then sends that data object the message ''NSData/writeToFile:atomically:'', using 'path' for the first argument and 'YES' for the second. The archived data should be retrieved from the archive by an ''NSUnarchiver'' object. - Parameters: - rootObject: The root object of the object graph to archive. - path: The location of the file into which to write the archive. - Returns: 'YES' if the archive was written successfully, otherwise 'NO'.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool archive_root_object(const Object& root_object, const std::string& path);
        /**
     * @brief Calls `+[NSArchiver archivedDataWithRootObject:]`.
     * @details Returns a data object that contains the encoded form of the object graph formed by the given root object. This method invokes ''NSArchiver/initForWritingWithMutableData:'' and ''NSArchiver/encodeRootObject:'' to create a temporary archiver that encodes the object graph. - Parameter rootObject: The root object of the object graph to archive. - Returns: A data object containing the encoded form of the object graph whose root object is 'rootObject'.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> archived_data_with_root_object(const Object& root_object);
        /**
     * @brief Calls `-[NSArchiver classNameEncodedForTrueClassName:]`.
     * @details Returns the name under which a given class was encoded. - Parameter trueName: The real name of an encoded class. - Returns: The name of the class used to archive instances of the class 'trueName'.
     * @param true_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string class_name_encoded_for_true_class_name(const std::string& true_name) const;
        /**
     * @brief Calls `-[NSArchiver encodeClassName:intoClassName:]`.
     * @details Encodes a given class under a given name. Any subsequently encountered objects of class 'trueName' are archived as instances of class 'inArchiveName'. It is safest not to invoke this method during the archiving process (that is, within an ''NSCoding/encode(with:)'' method). Instead, invoke it before ''encodeRootObject:''. - Parameters: - trueName: The real name of a class in the object graph being archived. - inArchiveName: The name of the class to use in the archive in place of 'trueName'.
     * @param true_name Argument converted to the Objective-C parameter of the same role.
     * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
     */
        void encode_class_name(const std::string& true_name, const std::string& in_archive_name) const;
        /**
     * @brief Calls `-[NSArchiver encodeConditionalObject:]`.
     * @details Encodes an object only if it is referenced by another object in the archive. This method overrides the superclass implementation to allow 'object' to be encoded only if it is also encoded unconditionally by another object in the object graph. Conditional encoding lets you encode one part of a graph detached from the rest. This method should be invoked only from within an ''NSCoding/encode(with:)'' method. If 'object' is 'nil', the 'NSArchiver' object encodes it unconditionally as 'nil'. This method raises an 'NSInvalidArgumentException' if no root object has been encoded. - Parameter object: The object to archive.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void encode_conditional_object(const Object& object) const;
        /**
     * @brief Calls `-[NSArchiver encodeRootObject:]`.
     * @details Encodes a given root object, along with all of the objects it's connected to. If any object is encountered more than once while traversing the graph, it is encoded only once, but the multiple references to it are stored. This message must not be sent more than once to a given 'NSArchiver' object; an 'NSInvalidArgumentException' is raised if a root object has already been encoded. If you need to encode multiple object graphs, don't attempt to reuse an 'NSArchiver' instance; instead, create a new one for each graph. - Parameter rootObject: The root object of the object graph to archive.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     */
        void encode_root_object(const Object& root_object) const;
        /**
     * @brief Calls `-[NSArchiver replaceObject:withObject:]`.
     * @details Replaces one object with another during encoding. Causes the receiver to treat subsequent requests to encode 'object' as though they were requests to encode 'newObject' instead. Both 'object' and 'newObject' must be valid objects. - Parameters: - object: An object in the object graph being archived. - newObject: The object with which to replace 'object' in the archive.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param new_object Argument converted to the Objective-C parameter of the same role.
     */
        void replace_object(const Object& object, const Object& new_object) const;
        /**
     * @brief Returns the `archiverData` property of `NSArchiver`.
     * @details The receiver's archive data. The returned data object is the same one specified as the argument to ''NSArchiver/init(forWritingWith:)''. It contains whatever data has been encoded thus far by invocations of the various encoding methods. It is safest not to invoke this method until after ''NSArchiver/encodeRootObject(:)'' has returned. In other words, although it is possible for a class to invoke this method from within its ''NSCoding/encode(with:)'' method, that method must not alter the data.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> archiver_data() const;
    };
}
