#pragma once

#include "generated/availability.h"
#include "generated/enumerator_base.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDirectoryEnumerator` (Foundation).
     * @details An object that enumerates the contents of a directory. You obtain a directory enumerator using ''NSFileManager'''s 'enumeratorAtPath:' method. The enumeration provides the pathnames of all files and directories contained within that directory. These pathnames are relative to the directory. An enumeration is recursive, including the files of all subdirectories, and crosses device boundaries. An enumeration does not resolve symbolic links, or attempt to traverse symbolic links that point to directories.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref EnumeratorBase.
     * Use the typed template @ref DirectoryEnumerator to supply ObjectType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DirectoryEnumeratorBase directory_enumerator_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DirectoryEnumeratorBase directory_enumerator_base{};
     * directory_enumerator_base.skip_descendants();
     * directory_enumerator_base.skip_descendents();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdirectoryenumerator
     */
    class DirectoryEnumeratorBase : public EnumeratorBase
    {
    public:
        /// @brief Creates a new `NSDirectoryEnumerator` instance and returns a handle to it.
        explicit DirectoryEnumeratorBase();
        /// @brief Creates a null handle that refers to no native object.
        DirectoryEnumeratorBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DirectoryEnumeratorBase(Adopt adopt);
        /**
     * @brief Calls `-[NSDirectoryEnumerator skipDescendants]`.
     * @details Causes the receiver to skip recursion into the most recently obtained subdirectory. This method is identical to 'skipDescendents' except for the spelling.
     */
        void skip_descendants() const;
        /**
     * @brief Calls `-[NSDirectoryEnumerator skipDescendents]`.
     * @details Causes the receiver to skip recursion into the most recently obtained subdirectory.
     */
        void skip_descendents() const;
        /**
     * @brief Returns the `directoryAttributes` property of `NSDirectoryEnumerator`.
     * @details A dictionary with the attributes of the directory at which enumeration started. See the description of the 'fileAttributesAtPath:traverseLink:' method of ''NSFileManager'' for details on obtaining the attributes from the dictionary.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> directory_attributes() const;
        /**
     * @brief Returns the `fileAttributes` property of `NSDirectoryEnumerator`.
     * @details A dictionary with the attributes of the most recently returned file or subdirectory (as referenced by the pathname). See the description of the 'fileAttributesAtPath:traverseLink:' method of ''NSFileManager'' for details on obtaining the attributes from the dictionary.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> file_attributes() const;
        /**
     * @brief Returns the `isEnumeratingDirectoryPostOrder` property of `NSDirectoryEnumerator`.
     * @details For NSDirectoryEnumerators created with -enumeratorAtURL:includingPropertiesForKeys:options:errorHandler: and the NSDirectoryEnumerationIncludesDirectoriesPostOrder option, this property is YES when the current object is a directory that is being enumerated after all of its contents have been enumerated.
     * @return The converted Objective-C result.
     */
        bool is_enumerating_directory_post_order() const;
        /**
     * @brief Returns the `level` property of `NSDirectoryEnumerator`.
     * @details The number of levels deep the current object is in the directory hierarchy being enumerated. The number of levels, with the directory passed to 'enumeratorAtURL:includingPropertiesForKeys:options:errorHandler:' considered to be level '0'.
     * @return The converted Objective-C result.
     */
        std::uint64_t level() const;
    };

    template <class ObjectType>
    class DirectoryEnumerator : public DirectoryEnumeratorBase
    {
    public:
        using DirectoryEnumeratorBase::DirectoryEnumeratorBase;
        DirectoryEnumerator() : DirectoryEnumeratorBase()
        {
        }
        DirectoryEnumerator(const DirectoryEnumeratorBase& other) : DirectoryEnumeratorBase(other)
        {
        }
        using DirectoryEnumeratorBase::directory_attributes;
        using DirectoryEnumeratorBase::file_attributes;
        using DirectoryEnumeratorBase::is_enumerating_directory_post_order;
        using DirectoryEnumeratorBase::level;
        using DirectoryEnumeratorBase::skip_descendants;
        using DirectoryEnumeratorBase::skip_descendents;
    };
}
