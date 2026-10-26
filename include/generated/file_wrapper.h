#pragma once

#include "generated/availability.h"
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
         * @details Add a file wrapper to the receiver's children and return the file name that uniquely identifies it among the receiver's children. The unique file name will be the same as the passed-in file wrapper's preferred file name unless that name is already in use as a key into the receiver's dictionary of children. Beware of the fact that -initDirectoryWithFileWrappers:, -initRegularFileWithContents:, and -initSymbolicLinkWithDestinationURL: do not automatically set the preferred file name.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string add_file_wrapper(const FileWrapper& child) const;
        /**
         * @brief Calls `-[NSFileWrapper addRegularFileWithContents:preferredFilename:]`.
         * @details A convenience method. The default implementation merely allocates a new file wrapper, initializes it with -initRegularFileWithContents:, sends it -setPreferredFileName:fileName, adds it to the receiver with -addFileWrapper:, and returns what -addFileWrapper: returned.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @param file_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string add_regular_file_with_contents(const std::vector<std::uint8_t>& data, const std::string& file_name) const;
        /**
         * @brief Calls `-[NSFileWrapper keyForFileWrapper:]`.
         * @details Return the unique file name that has been assigned to a child or nil if it is not a child of the receiver.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string key_for_file_wrapper(const FileWrapper& child) const;
        /**
         * @brief Calls `-[NSFileWrapper matchesContentsOfURL:]`.
         * @details Whether the receiver matches the directory, regular file, or symbolic link that is located by the URL. For a directory, children are compared against the files in the directory, recursively. The contents of files are not compared; matching of regular files is based on file modification dates. Because children of directory file wrappers are not read immediately by -initWithURL:options:error: or -readFromURL:options:error: unless NSFileWrapperReadingImmediate is used, creating a file wrapper and then later sending it this message is not a reliable way to simply check whether anything in a directory has changed. You can use this method to determine whether the receiver's contents in memory are out of date relative to the file system.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool matches_contents_of_url(const URL& url) const;
        /**
         * @brief Calls `-[NSFileWrapper readFromURL:options:error:]`.
         * @details Recursively reread the entire contents of the receiver from the specified location, and return YES if successful. If not successful, return NO after setting outError to an NSError that encapsulates the reason why the file wrapper could not be reread. When reading a directory children are added and removed as necessary to match the file system.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool read_from_url(const URL& url, FileWrapperReadingOptions options) const;
        /**
         * @brief Calls `-[NSFileWrapper removeFileWrapper:]`.
         * @details Remove a file wrapper from the receiver's children.
         * @param child Argument converted to the Objective-C parameter of the same role.
         */
        void remove_file_wrapper(const FileWrapper& child) const;
        /**
         * @brief Calls `-[NSFileWrapper writeToURL:options:originalContentsURL:error:]`.
         * @details Recursively write the entire contents of the receiver at the specified location, and return YES if successful. If not successful, return NO after setting outError to an NSError that encapsulates the reason why the file wrapper could not be written. originalContentsURL may be nil or it may be the location of a previous revision of what is being written. If it is not nil the default implementation of this method attempts to avoid unnecessary I/O by merely writing hard links to regular files instead of actually writing out their contents. The descendant file wrappers must return accurate values when sent -filename for this to work (use NSFileWrapperWritingWithNameUpdating to increase the likelihood of that).
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param original_contents_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool write_to_url(const URL& url, FileWrapperWritingOptions options, const URL& original_contents_url) const;
        /**
         * @brief Returns the `directory` property of `NSFileWrapper`.
         * @details What kind of file wrapper it is. Invocations of -readFromURL:options:error: may change what subsequent invocations of these methods return.
         * @return The converted Objective-C result.
         */
        bool is_directory() const;
        /**
         * @brief Returns the `fileAttributes` property of `NSFileWrapper`.
         * @details The file attributes, in a dictionary of the same sort as those returned by -[NSFileManager attributesOfItemAtPath:error:].
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> file_attributes() const;
        /**
         * @brief Sets the `fileAttributes` property of `NSFileWrapper`.
         * @details The file attributes, in a dictionary of the same sort as those returned by -[NSFileManager attributesOfItemAtPath:error:].
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_file_attributes(const std::map<std::string, Object>& value) const;
        /**
         * @brief Returns the `fileWrappers` property of `NSFileWrapper`.
         * @details Return a dictionary whose values are the receiver's children and whose keys are the unique file name that has been assigned to each one. This method may return nil if the receiver is the result of reading a parent from the file system (use NSFileWrapperReadingImmediately if appropriate to prevent that).
         * @return The converted Objective-C result.
         */
        std::map<std::string, FileWrapper> file_wrappers() const;
        /**
         * @brief Returns the `filename` property of `NSFileWrapper`.
         * @details The actual file name. Often it will be the same as the preferred file name but might instead be a name derived from the preferred file name. You can use this method to find out the name of a child that's just been read but you should not use it to find out the name of a child that's about to be written, because the name might be about to change. Send -keyForFileWrapper: to the parent instead.
         * @return The converted Objective-C result.
         */
        std::string filename() const;
        /**
         * @brief Sets the `filename` property of `NSFileWrapper`.
         * @details The actual file name. Often it will be the same as the preferred file name but might instead be a name derived from the preferred file name. You can use this method to find out the name of a child that's just been read but you should not use it to find out the name of a child that's about to be written, because the name might be about to change. Send -keyForFileWrapper: to the parent instead.
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
         * @details The file name that is "preferred." When the receiver is added to a parent directory file wrapper the parent will attempt to use this name as the key into its dictionary of children. Usually the preferred file name will actually get used in this situation but it won't be if that key is already in use. The default implementation of this method causes existing parents to remove and re-add the child to accommodate the change. Preferred file names of children are not effectively preserved when you write a file wrapper to disk and then later instantiate another file wrapper by reading. If your application needs to preserve the user-visible names of attachments it has to make its own arrangements for their storage. Some instances of NSFileWrapper may be created without a preferredFilename (e.g. -initDirectoryWithFileWrappers: or -initRegularFileWithContents:), meaning preferredFilename may be nil. However, setting nil is never allowed and will result in an exception.
         * @return The converted Objective-C result.
         */
        std::string preferred_filename() const;
        /**
         * @brief Sets the `preferredFilename` property of `NSFileWrapper`.
         * @details The file name that is "preferred." When the receiver is added to a parent directory file wrapper the parent will attempt to use this name as the key into its dictionary of children. Usually the preferred file name will actually get used in this situation but it won't be if that key is already in use. The default implementation of this method causes existing parents to remove and re-add the child to accommodate the change. Preferred file names of children are not effectively preserved when you write a file wrapper to disk and then later instantiate another file wrapper by reading. If your application needs to preserve the user-visible names of attachments it has to make its own arrangements for their storage. Some instances of NSFileWrapper may be created without a preferredFilename (e.g. -initDirectoryWithFileWrappers: or -initRegularFileWithContents:), meaning preferredFilename may be nil. However, setting nil is never allowed and will result in an exception.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_preferred_filename(const std::string& value) const;
        /**
         * @brief Returns the `regularFile` property of `NSFileWrapper`.
         * @return The converted Objective-C result.
         */
        bool is_regular_file() const;
        /**
         * @brief Returns the `regularFileContents` property of `NSFileWrapper`.
         * @details Return the receiver's contents. This may return nil if the receiver is the result of reading a parent from the file system (use NSFileWrapperReadingImmediately if appropriate to prevent that).
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> regular_file_contents() const;
        /**
         * @brief Returns the `serializedRepresentation` property of `NSFileWrapper`.
         * @details Return an NSData suitable for passing to -initWithSerializedRepresentation:. This method may return nil if the receiver is the result of reading from the file system (use NSFileWrapperReadingImmediately if appropriate to prevent that).
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> serialized_representation() const;
        /**
         * @brief Returns the `symbolicLink` property of `NSFileWrapper`.
         * @return The converted Objective-C result.
         */
        bool is_symbolic_link() const;
        /**
         * @brief Returns the `symbolicLinkDestinationURL` property of `NSFileWrapper`.
         * @details Return the destination link of the receiver. This may return nil if the receiver is the result of reading a parent from the file system (use NSFileWrapperReadingImmediately if appropriate to prevent that).
         * @return The converted Objective-C result.
         */
        URL symbolic_link_destination_url() const;
    };
}
