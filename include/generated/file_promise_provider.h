#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class OperationQueue;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSFilePromiseProvider` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FilePromiseProvider file_promise_provider;
     * file_promise_provider.set_file_type("text");
     * file_promise_provider.write_promise_to_url_completion_handler().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FilePromiseProvider file_promise_provider{};
     * file_promise_provider.set_file_type("text");
     * auto file_type = file_promise_provider.file_type();
     * file_promise_provider.write_promise_to_url_completion_handler().connect([](cocoon::URL a0, std::function<void(cocoon::Error)> a1) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfilepromiseprovider
     */
    class FilePromiseProvider : public Object
    {
    public:
        /// @brief Creates a new `NSFilePromiseProvider` instance and returns a handle to it.
        explicit FilePromiseProvider(const std::string& file_type, const Object& delegate);
        /// @brief Creates a new `NSFilePromiseProvider` instance and returns a handle to it.
        explicit FilePromiseProvider();
        /// @brief Creates a null handle that refers to no native object.
        FilePromiseProvider(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FilePromiseProvider(Adopt adopt);
        /**
     * @brief Returns the `fileType` property of `NSFilePromiseProvider`.
     * @details The UTI of the promised file type. An exception is thrown if the fileType does not conform to kUTTypeData or kUTTypeDirectory
     * @return The converted Objective-C result.
     */
        std::string file_type() const;
        /**
     * @brief Sets the `fileType` property of `NSFilePromiseProvider`.
     * @details The UTI of the promised file type. An exception is thrown if the fileType does not conform to kUTTypeData or kUTTypeDirectory
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_type(const std::string& value) const;
        /**
     * @brief Returns the `userInfo` property of `NSFilePromiseProvider`.
     * @details When a simple string identifier is not enough. Store a pointer to an object that contains the source of the promised file data.
     * @return The converted Objective-C result.
     */
        Object user_info() const;
        /**
     * @brief Sets the `userInfo` property of `NSFilePromiseProvider`.
     * @details When a simple string identifier is not enough. Store a pointer to an object that contains the source of the promised file data.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_user_info(const Object& value) const;
        /// @brief Signal for the delegate/data-source method behind `file_name_for_type`; connect a callback with `file_name_for_type().connect(...)`.
        Signal<FilePromiseProvider, std::string(std::string)> file_name_for_type() const
        {
            return Signal<FilePromiseProvider, std::string(std::string)>(handle(), "file_name_for_type");
        }
        /// @brief Signal for the delegate/data-source method behind `write_promise_to_url_completion_handler`; connect a callback with `write_promise_to_url_completion_handler().connect(...)`.
        Signal<FilePromiseProvider, void(URL, std::function<void(Error)>)> write_promise_to_url_completion_handler() const
        {
            return Signal<FilePromiseProvider, void(URL, std::function<void(Error)>)>(handle(), "write_promise_to_url_completion_handler");
        }
        /// @brief Signal for the delegate/data-source method behind `operation_queue_for_file_promise_provider`; connect a callback with `operation_queue_for_file_promise_provider().connect(...)`.
        Signal<FilePromiseProvider, OperationQueue()> operation_queue_for_file_promise_provider() const
        {
            return Signal<FilePromiseProvider, OperationQueue()>(handle(), "operation_queue_for_file_promise_provider");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
