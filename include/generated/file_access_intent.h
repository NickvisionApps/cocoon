#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFileAccessIntent` (Foundation).
     * @details The details of a coordinated-read or coordinated-write operation. Use this class when performing asynchronous operations with a file coordinator using the coordinator's ''NSFileCoordinator/coordinate(with:queue:byAccessor:)'' method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileAccessIntent file_access_intent;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FileAccessIntent file_access_intent{};
     * auto made_0 = cocoon::FileAccessIntent::reading_intent_with_url(cocoon::URL(), cocoon::FileCoordinatorReadingOptions::WithoutChanges);
     * auto made_1 = cocoon::FileAccessIntent::writing_intent_with_url(cocoon::URL(), cocoon::FileCoordinatorWritingOptions::ForDeleting);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfileaccessintent
     */
    class FileAccessIntent : public Object
    {
    public:
        /// @brief Creates a new `NSFileAccessIntent` instance and returns a handle to it.
        explicit FileAccessIntent();
        /// @brief Creates a null handle that refers to no native object.
        FileAccessIntent(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileAccessIntent(Adopt adopt);
        /**
     * @brief Calls `+[NSFileAccessIntent readingIntentWithURL:options:]`.
     * @details Returns a file access intent object for reading the given URL with the provided options. When calling a file coordinator's ''NSFileCoordinator/coordinate(with:queue:byAccessor:)'' method, you pass an array of file access intent objects. Each intent object represents a specific read or write operation on a single document or directory. Use this method to create an intent object suitable for reading. - Parameters: - url: The URL of the document you intend to read from. - options: The coordinated reading options. For a list of valid values, see ''NSFileCoordinator/ReadingOptions'' in the ''NSFileCoordinator''. - Returns: A newly instantiated and configured file access intent object.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileAccessIntent reading_intent_with_url(const URL& url, FileCoordinatorReadingOptions options);
        /**
     * @brief Calls `+[NSFileAccessIntent writingIntentWithURL:options:]`.
     * @details Returns a file access intent object for writing to the given URL with the provided options. When calling a file coordinator's ''NSFileCoordinator/coordinate(with:queue:byAccessor:)'' method, you pass an array of file access intent objects. Each intent object represents a specific read or write operation on a single document or directory. Use this method to create an intent object suitable for writing. - Parameters: - url: The URL of the document you intend to write to. - options: The coordinated writing options. For a list of valid values, see ''NSFileCoordinator/WritingOptions'' in the ''NSFileCoordinator''. - Returns: A newly instantiated and configured file access intent object.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static FileAccessIntent writing_intent_with_url(const URL& url, FileCoordinatorWritingOptions options);
        /**
     * @brief Returns the `URL` property of `NSFileAccessIntent`.
     * @details The URL of the item. Use this URL within the accessor block. This property may change from its original value in response to actions from other writers.
     * @return The converted Objective-C result.
     */
        URL url() const;
    };
}
