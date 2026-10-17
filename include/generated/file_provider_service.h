#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class XPCConnection;

    /**
     * @brief C++ handle for the Objective-C class `NSFileProviderService` (Foundation).
     * @details A service that provides a custom communication channel between your app and a File Provider extension. To communicate, both your app and the File Provider extension must implement their part of the service: - Your app requests the proxy object, and calls its methods. - The File Provider extension declares the supported services and vends a proxy object that implements the protocol for each service. The app and File Provider extension communicate using an XPC service. This service performs actions only on items managed by the File Provider extension. For more information, see [Creating XPC Services](https://developer.apple.com/library/archive/documentation/MacOSX/Conceptual/BPSystemStartup/Chapters/CreatingXPCServices.html\#//apple_ref/doc/uid/10000172i-SW6). \#\#\# Defining the Service’s Protocol Services let you define custom actions that are not provided by Apple's APIs. Both the app and the File Provider extension must agree upon the service's name and protocol. Communicate the name and protocol through an outside source (for example, posting a header file that defines both the name and protocol, or publishing a library that includes them both). The service can be defined by either the app or the File Provider extension: - Apps can define a service for features they would like to use. File providers can then choose to support those features by implementing the service. - File Provider extensions can provide a service for the features they support. Apps can then choose to use the specified service. When defining a service's protocol, the parameters for each method must adhere to the following rules: - The parameter's class must conform to ''NSSecureCoding''. - The parameter's class must be defined in both the app and the File Provider extension (for example, standard system types or classes defined in a library imported by both sides). - If a collection parameter contains types other than property list types (see [Property List Types and Objects](https://developer.apple.com/library/archive/documentation/General/Conceptual/DevPedia-CocoaCore/PropertyList.html\#//apple_ref/doc/uid/TP40008195-CH44-SW2)), declare the valid types using the ''NSXPCInterface'' class's ''NSXPCInterface/classes(for:argumentIndex:ofReply:)'' method.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FileProviderService file_provider_service;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsfileproviderservice
     */
    class FileProviderService : public Object
    {
    public:
        /// @brief Creates a new `NSFileProviderService` instance and returns a handle to it.
        explicit FileProviderService();
        /// @brief Creates a null handle that refers to no native object.
        FileProviderService(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FileProviderService(Adopt adopt);
        /**
     * @brief Calls `-[NSFileProviderService getFileProviderConnectionWithCompletionHandler:]`.
     * @details Asynchronously returns the service's connection object. - Parameters: - completionHandler: A block that is called on an anonymous background queue. The block receives the 'NSXPCConnection' object for the service, or 'nil' if an error occurs, and an 'NSError' describing the error if one occurred.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void get_file_provider_connection_with_completion_handler(std::function<void(XPCConnection, Error)> completion_handler) const;
        /**
     * @brief Returns the `name` property of `NSFileProviderService`.
     * @details The File Provider service's name.
     * @return The converted Objective-C result.
     */
        std::string name() const;
    };
}
