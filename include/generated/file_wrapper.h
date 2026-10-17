#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Image;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileWrapper` (Foundation).
     * @details A representation of a node (a file, directory, or symbolic link) in the file system. The ''FileWrapper'' class provides access to the attributes and contents of file system nodes. A file system node is a file, directory, or symbolic link. Instances of this class are known as file wrappers. > Note: > Starting in macOS 10.7, ''FileWrapper'' moved from Application Kit to Foundation. As a result of this the 'icon', and 'setIcon:' methods have moved to a new category of ''FileWrapper'' that remains in Application Kit. File wrappers represent a file system node as an object that can be displayed as an image (and possibly edited in place), saved to the file system, or transmitted to another application. There are three types of file wrappers: - Regular-file file wrapper: Represents a regular file. - Directory file wrapper: Represents a directory. - Symbolic-link file wrapper: Represents a symbolic link. A file wrapper has these attributes: - Filename. Name of the file system node the file wrapper represents. - file-system attributes. See ''FileManager'' for information on the contents of the 'attributes' dictionary. - Regular-file contents. Applicable only to regular-file file wrappers. - File wrappers. Applicable only to directory file wrappers. - Destination node. Applicable only to symbolic-link file wrappers.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileWrapper file_wrapper;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileWrapper file_wrapper{};
     * file_wrapper.set_filename("text");
     * auto filename = file_wrapper.filename();
     * file_wrapper.set_icon(cocoon::Image());
     * auto icon = file_wrapper.icon();
     * file_wrapper.set_preferred_filename("text");
     * auto preferred_filename = file_wrapper.preferred_filename();
     * file_wrapper.add_file_wrapper(cocoon::FileWrapper());
     * file_wrapper.key_for_file_wrapper(cocoon::FileWrapper());
     * file_wrapper.matches_contents_of_url(cocoon::URL());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfilewrapper
     */
    class FileWrapper : public Object
    {
    public:
        /// @brief Creates a new `NSFileWrapper` instance and returns a handle to it.
        explicit FileWrapper(const std::map<std::string, FileWrapper>& children_by_preferred_name);
        /// @brief Creates a new `NSFileWrapper` instance and returns a handle to it.
        explicit FileWrapper(const std::vector<std::uint8_t>& contents);
        /// @brief Creates a new `NSFileWrapper` instance and returns a handle to it.
        explicit FileWrapper(const URL& url);
        /// @brief Creates a new `NSFileWrapper` instance and returns a handle to it.
        explicit FileWrapper(const URL& url, FileWrapperReadingOptions options);
        /// @brief Creates a new `NSFileWrapper` instance and returns a handle to it.
        explicit FileWrapper();
        /// @brief Creates a null handle that refers to no native object.
        FileWrapper(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileWrapper(Adopt adopt);
        /**
     * @brief Calls `-[NSFileWrapper addFileWrapper:]`.
     * @details Adds a child file wrapper to the receiver, which must be a directory file wrapper. Use this method to add an existing file wrapper as a child of a directory file wrapper. If the file wrapper does not have a preferred filename, set the 'preferredFilename' property to give it one before calling -addFileWrapper:. To create a new file wrapper and add it to a directory, use the -addRegularFileWithContents:preferredFilename: method. This method raises 'NSInternalInconsistencyException' if the receiver is not a directory file wrapper. This method raises 'NSInvalidArgumentException' if the child file wrapper doesn't have a preferred name. - Parameter child: File wrapper to add to the directory. - Returns: Dictionary key used to store 'fileWrapper' in the directory's list of file wrappers. The dictionary key is a unique filename, which is the same as the passed-in file wrapper's preferred filename unless that name is already in use as a key in the directory's dictionary of children.
     * @param child Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string add_file_wrapper(const FileWrapper& child) const;
        /**
     * @brief Calls `-[NSFileWrapper addRegularFileWithContents:preferredFilename:]`.
     * @details Creates a regular-file file wrapper with the given contents and adds it to the receiver, which must be a directory file wrapper. This is a convenience method. The default implementation allocates a new file wrapper, initializes it with -initRegularFileWithContents:, sets its preferred filename, adds it to the directory with -addFileWrapper:, and returns what -addFileWrapper: returned. This method raises 'NSInternalInconsistencyException' if the receiver is not a directory file wrapper. This method raises 'NSInvalidArgumentException' if you pass 'nil' or an empty value for 'filename'. - Parameters: - data: Contents for the new regular-file file wrapper. - fileName: Preferred filename for the new regular-file file wrapper. - Returns: Dictionary key used to store the new file wrapper in the directory's list of file wrappers. The dictionary key is a unique filename, which is the same as the passed-in file wrapper's preferred filename unless that name is already in use as a key in the directory's dictionary of children.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param file_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string add_regular_file_with_contents(const std::vector<std::uint8_t>& data, const std::string& file_name) const;
        /**
     * @brief Calls `-[NSFileWrapper keyForFileWrapper:]`.
     * @details Returns the dictionary key used by a directory to identify a given file wrapper. The dictionary key is a unique filename, which may not be the same as the passed-in file wrapper's preferred filename if more than one file wrapper in the directory's dictionary of children has the same preferred filename. Returns 'nil' if the file wrapper specified in 'child' is not a child of the directory. This method raises 'NSInternalInconsistencyException' if the receiver is not a directory file wrapper. - Parameter child: The child file wrapper for which you want the key. - Returns: Dictionary key used to store the file wrapper in the directory's list of file wrappers.
     * @param child Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string key_for_file_wrapper(const FileWrapper& child) const;
        /**
     * @brief Calls `-[NSFileWrapper matchesContentsOfURL:]`.
     * @details Indicates whether the contents of a file wrapper matches a directory, regular file, or symbolic link on disk. The contents of files are not compared; matching of regular files is based on file modification dates. For a directory, children are compared against the files in the directory, recursively. Because children of directory file wrappers are not read immediately by the -initWithURL:options:error: method unless the NSFileWrapperReadingImmediate reading option is used, even a newly-created directory file wrapper might not have the same contents as the directory on disk. You can use this method to determine whether the file wrapper's contents in memory need to be updated. If the file wrapper needs updating, use the -readFromURL:options:error: method with the NSFileWrapperReadingImmediate reading option. - Parameter url: URL of the file-system node with which to compare the file wrapper. - Returns: 'YES' when the contents of the file wrapper match the contents of 'url', 'NO' otherwise.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool matches_contents_of_url(const URL& url) const;
        /**
     * @brief Calls `-[NSFileWrapper readFromURL:options:error:]`.
     * @details Recursively rereads the entire contents of a file wrapper from the specified location on disk. When reading a directory, children are added and removed as necessary to match the file system. - Parameters: - url: URL of the file-system node corresponding to the file wrapper. - options: Option flags for reading the node located at 'url'. See 'NSFileWrapperReadingOptions' for possible values. - outError: If an error occurs, upon return contains an 'NSError' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: 'YES' if successful. If not successful, returns 'NO' after setting 'outError' to an 'NSError' object that describes the reason why the file wrapper could not be reread.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool read_from_url(const URL& url, FileWrapperReadingOptions options) const;
        /**
     * @brief Calls `-[NSFileWrapper removeFileWrapper:]`.
     * @details Removes a child file wrapper from the receiver, which must be a directory file wrapper. This method raises 'NSInternalInconsistencyException' if the receiver is not a directory file wrapper. - Parameter child: File wrapper to remove from the directory.
     * @param child Argument converted to the Objective-C parameter of the same role.
     */
        void remove_file_wrapper(const FileWrapper& child) const;
        /**
     * @brief Calls `-[NSFileWrapper writeToURL:options:originalContentsURL:error:]`.
     * @details Recursively writes the entire contents of a file wrapper to a given file-system URL. - Parameters: - url: URL of the file-system node to which the file wrapper's contents are written. - options: Option flags for writing to the node located at 'url'. See 'NSFileWrapperWritingOptions' for possible values. - originalContentsURL: The location of a previous revision of the contents being written. The default implementation of this method attempts to avoid unnecessary I/O by writing hard links to regular files instead of actually writing out their contents when the contents have not changed. The child file wrappers must return accurate values when sent -filename for this to work. Use the NSFileWrapperWritingWithNameUpdating writing option to increase the likelihood of that. Specify 'nil' for this parameter if there is no earlier version of the contents or if you want to ensure that all the contents are written to files. - outError: If an error occurs, upon return contains an 'NSError' object that describes the problem. Pass 'NULL' if you do not want error information. - Returns: 'YES' when the write operation is successful. If not successful, returns 'NO' after setting 'outError' to an 'NSError' object that describes the reason why the file wrapper's contents could not be written.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @param original_contents_url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_to_url(const URL& url, FileWrapperWritingOptions options, const URL& original_contents_url) const;
        /**
     * @brief Returns the `directory` property of `NSFileWrapper`.
     * @details This property contains a boolean value indicating whether the file wrapper is a directory file wrapper. Invocations of -readFromURL:options:error: may change the value of this property, if the type of the file on disk has changed.
     * @return The converted Objective-C result.
     */
        bool is_directory() const;
        /**
     * @brief Returns the `fileAttributes` property of `NSFileWrapper`.
     * @details A dictionary of file attributes. The file attributes' dictionary is the same format as that returned by -[NSFileManager attributesOfItemAtPath:error:].
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> file_attributes() const;
        /**
     * @brief Sets the `fileAttributes` property of `NSFileWrapper`.
     * @details A dictionary of file attributes. The file attributes' dictionary is the same format as that returned by -[NSFileManager attributesOfItemAtPath:error:].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_attributes(const std::map<std::string, Object>& value) const;
        /**
     * @brief Returns the `fileWrappers` property of `NSFileWrapper`.
     * @details The file wrappers contained by a directory file wrapper. The dictionary contains entries whose values are the file wrappers and whose keys are the unique filenames that have been assigned to each one. This property may contain 'nil' if the user modifies the directory after you call -readFromURL:options:error: or -initWithURL:options:error: but before NSFileWrapper has read the contents of the directory. Use the NSFileWrapperReadingImmediate reading option to reduce the likelihood of that problem. This property raises 'NSInternalInconsistencyException' if the file wrapper object is not a directory file wrapper.
     * @return The converted Objective-C result.
     */
        std::map<std::string, FileWrapper> file_wrappers() const;
        /**
     * @brief Returns the `filename` property of `NSFileWrapper`.
     * @details The filename of the file wrapper object. This property contains the file wrapper's filename, or 'nil' when the file wrapper has no corresponding file-system node. The filename is used for record-keeping purposes only and is set automatically when the file wrapper is created from the file system using -initWithURL:options:error: and when it's saved to the file system using -writeToURL:options:originalContentsURL:error: (although this method allows you to request that the filename not be updated). The filename is usually the same as the preferred filename, but might instead be a name derived from the preferred filename. You can use this method to get the name of a child that's just been read. Don't use this method to get the name of a child that's about to be written, because the name might be about to change; send -keyForFileWrapper: to the parent instead.
     * @return The converted Objective-C result.
     */
        std::string filename() const;
        /**
     * @brief Sets the `filename` property of `NSFileWrapper`.
     * @details The filename of the file wrapper object. This property contains the file wrapper's filename, or 'nil' when the file wrapper has no corresponding file-system node. The filename is used for record-keeping purposes only and is set automatically when the file wrapper is created from the file system using -initWithURL:options:error: and when it's saved to the file system using -writeToURL:options:originalContentsURL:error: (although this method allows you to request that the filename not be updated). The filename is usually the same as the preferred filename, but might instead be a name derived from the preferred filename. You can use this method to get the name of a child that's just been read. Don't use this method to get the name of a child that's about to be written, because the name might be about to change; send -keyForFileWrapper: to the parent instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_filename(const std::string& value) const;
        /**
     * @brief Returns the `icon` property of `NSFileWrapper`.
     * @return The converted Objective-C result.
     */
        Image icon() const;
        /**
     * @brief Sets the `icon` property of `NSFileWrapper`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_icon(const Image& value) const;
        /**
     * @brief Returns the `preferredFilename` property of `NSFileWrapper`.
     * @details The preferred filename for the file wrapper object. This name is normally used as the dictionary key when a child file wrapper is added to a directory file wrapper. However, if another file wrapper with the same preferred name already exists in the directory file wrapper when this object is added, the filename assigned as the dictionary key may differ from the preferred filename. When you change the preferred filename, the default implementation of this property causes the existing parent directory file wrappers to remove and re-add the child to accommodate the change. Preferred filenames of children are not preserved when you write a file wrapper to disk and then later instantiate another file wrapper by reading the file from disk. If you need to preserve the user-visible names of attachments, you have to store the names yourself. Some instances of NSFileWrapper may be created without a preferredFilename (e.g. -initDirectoryWithFileWrappers: or -initRegularFileWithContents:), meaning preferredFilename may be nil. However, setting nil is never allowed and will result in an exception.
     * @return The converted Objective-C result.
     */
        std::string preferred_filename() const;
        /**
     * @brief Sets the `preferredFilename` property of `NSFileWrapper`.
     * @details The preferred filename for the file wrapper object. This name is normally used as the dictionary key when a child file wrapper is added to a directory file wrapper. However, if another file wrapper with the same preferred name already exists in the directory file wrapper when this object is added, the filename assigned as the dictionary key may differ from the preferred filename. When you change the preferred filename, the default implementation of this property causes the existing parent directory file wrappers to remove and re-add the child to accommodate the change. Preferred filenames of children are not preserved when you write a file wrapper to disk and then later instantiate another file wrapper by reading the file from disk. If you need to preserve the user-visible names of attachments, you have to store the names yourself. Some instances of NSFileWrapper may be created without a preferredFilename (e.g. -initDirectoryWithFileWrappers: or -initRegularFileWithContents:), meaning preferredFilename may be nil. However, setting nil is never allowed and will result in an exception.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_filename(const std::string& value) const;
        /**
     * @brief Returns the `regularFile` property of `NSFileWrapper`.
     * @details This property contains a boolean value that indicates whether the file wrapper object is a regular-file. Invocations of -readFromURL:options:error: may change the value of this property if the type of the file on disk has changed.
     * @return The converted Objective-C result.
     */
        bool is_regular_file() const;
        /**
     * @brief Returns the `regularFileContents` property of `NSFileWrapper`.
     * @details The contents of the file-system node associated with a regular-file file wrapper. This property may contain 'nil' if the user modifies the file after you call -readFromURL:options:error: or -initWithURL:options:error: but before NSFileWrapper has read the contents of the file. Use the NSFileWrapperReadingImmediate reading option to reduce the likelihood of that problem. This property raises 'NSInternalInconsistencyException' if the file wrapper object is not a regular-file file wrapper.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> regular_file_contents() const;
        /**
     * @brief Returns the `serializedRepresentation` property of `NSFileWrapper`.
     * @details The contents of the file wrapper as an opaque data object. This property contains a data object in the format used by the NSFileContentsPboardType pasteboard type. This data object is also suitable for passing to -initWithSerializedRepresentation:. This property may be 'nil' if the user modifies the contents of the file system node after you call -readFromURL:options:error: or -initWithURL:options:error:, but before NSFileWrapper has read the contents of the file. You can use the NSFileWrapperReadingImmediate reading option to reduce the likelihood of this problem.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> serialized_representation() const;
        /**
     * @brief Returns the `symbolicLink` property of `NSFileWrapper`.
     * @details A boolean that indicates whether the file wrapper object is a symbolic-link file wrapper. Invocations of -readFromURL:options:error: may change the value contained by this property, if the type of the file on disk has changed.
     * @return The converted Objective-C result.
     */
        bool is_symbolic_link() const;
        /**
     * @brief Returns the `symbolicLinkDestinationURL` property of `NSFileWrapper`.
     * @details The URL referenced by the file wrapper object, which must be a symbolic-link file wrapper. This property may contain 'nil' if the user modifies the symbolic link after you call -readFromURL:options:error: or -initWithURL:options:error: but before NSFileWrapper has read the contents of the link. Use the NSFileWrapperReadingImmediate reading option to reduce the likelihood of that problem. This property raises 'NSInternalInconsistencyException' if the file wrapper object is not a symbolic-link file wrapper.
     * @return The converted Objective-C result.
     */
        URL symbolic_link_destination_url() const;
    };
}
