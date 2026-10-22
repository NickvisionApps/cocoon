#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class Progress;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSItemProvider` (Foundation).
     * @details An item provider for conveying data or a file between processes during drag-and-drop or copy-and-paste activities, or from a host app to an app extension. Starting in iOS 11, item providers play a central role in drag and drop, and in copy and paste. They continue to play a role with app extensions. The system uses an internal queue when calling the completion blocks for the 'NSItemProvider' class. When using an item provider with drag and drop, ensure that UI updates take place on the main queue as follows: '''swift DispatchQueue.main.async { // Work that impacts the user interface. } ''' \#\#\# App extension support An app extension typically encounters item providers when examining the ''NSExtensionItem/attachments'' property of an ''NSExtensionItem'' object. During that examination, the extension can use the ''hasItemConformingToTypeIdentifier(:)'' method to look for data that it recognizes. Item providers use \<doc://com.apple.documentation/documentation/uniformtypeidentifiers> values to identify the data they contain. After finding a type of data that your extension can use, it calls the ''loadItem(forTypeIdentifier:options:completionHandler:)'' method to load the actual data, which is delivered to the provided completion handler. You can create item providers to vend data to another process. An extension that modifies an original data item can create a new 'NSItemProvider' object to send back to the host app. When creating data items, you specify your data object and the type of that object. You can optionally use the ''previewImageHandler'' property to generate a preview image for your data. A single item provider may use custom blocks to provide its data in many different formats. When configuring an item provider, use the ''registerItem(forTypeIdentifier:loadHandler:)'' method to register your blocks and the formats each one supports. When a client requests data in a particular format, the item provider executes the corresponding block, which is then responsible for coercing the data to the appropriate type and returning it to the client.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ItemProvider item_provider;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ItemProvider item_provider{};
     * item_provider.set_suggested_name("text");
     * auto suggested_name = item_provider.suggested_name();
     * item_provider.can_load_object_of_class("text");
     * item_provider.has_item_conforming_to_type_identifier("text");
     * item_provider.has_representation_conforming_to_type_identifier("text", cocoon::ItemProviderFileOptions::Place);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsitemprovider
     */
    class ItemProvider : public Object
    {
    public:
        /// @brief Creates a new `NSItemProvider` instance and returns a handle to it.
        explicit ItemProvider(const URL& file_url);
        /// @brief Creates a new `NSItemProvider` instance and returns a handle to it.
        explicit ItemProvider(const Object& item, const std::string& type_identifier);
        /// @brief Creates a new `NSItemProvider` instance and returns a handle to it.
        explicit ItemProvider(const Object& object);
        /// @brief Creates a new `NSItemProvider` instance and returns a handle to it.
        explicit ItemProvider();
        /// @brief Creates a null handle that refers to no native object.
        ItemProvider(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ItemProvider(Adopt adopt);
        /**
         * @brief Calls `-[NSItemProvider canLoadObjectOfClass:]`.
         * @details Returns a Boolean value indicating whether an item provider can load objects of a specified class. - Parameter aClass: The object class for comparison. - Returns: 'YES' if the item provider can load objects of the class.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool can_load_object_of_class(const std::string& a_class) const;
        /**
         * @brief Calls `-[NSItemProvider hasItemConformingToTypeIdentifier:]`.
         * @details Returns a Boolean value indicating whether an item provider contains a data representation conforming to a specified universal type identifier, with a file options value of zero. - Parameter typeIdentifier: A string that represents the desired UTI. - Returns: 'YES' if the item provider has at least one item that conforms to the supplied type identifier.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_item_conforming_to_type_identifier(const std::string& type_identifier) const;
        /**
         * @brief Calls `-[NSItemProvider hasRepresentationConformingToTypeIdentifier:fileOptions:]`.
         * @details Returns a Boolean value indicating whether an item provider contains a data representation conforming to a specified universal type identifier and to specified open-in-place behavior. To check all registered UTIs for type conformance, pass the value '0' in the 'fileOptions' parameter.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param file_options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool has_representation_conforming_to_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options) const;
        /**
         * @brief Calls `-[NSItemProvider loadDataRepresentationForTypeIdentifier:completionHandler:]`.
         * @details Asynchronously copies the provided, typed data into an 'NSData' object, returning a progress object. If the source app provides a folder URL, the 'NSData' object contains a zip archive with the folder as its top-level entry.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Progress load_data_representation_for_type_identifier(const std::string& type_identifier, std::function<void(std::vector<std::uint8_t>, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider loadFileRepresentationForTypeIdentifier:completionHandler:]`.
         * @details Asynchronously writes a copy of the provided, typed data to a temporary file, returning a progress object. This method writes a copy of the file's data to a temporary file, which the system deletes when the completion handler returns. Your program should copy or move the file within the completion handler.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Progress load_file_representation_for_type_identifier(const std::string& type_identifier, std::function<void(URL, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider loadInPlaceFileRepresentationForTypeIdentifier:completionHandler:]`.
         * @details Asynchronously opens a file in place, if possible, returning a progress object. The system sets the 'isInPlace' parameter to 'YES' if the system successfully opened the file in place, or 'NO' if it made a local copy. In either case, you must access the returned URL using an 'NSFileCoordinator'. If the system created a local copy of a file, it will be automatically deleted after your file coordinator relinquishes its read access to the file.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Progress load_in_place_file_representation_for_type_identifier(const std::string& type_identifier, std::function<void(URL, bool, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider loadItemForTypeIdentifier:options:completionHandler:]`.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void load_item_for_type_identifier(const std::string& type_identifier, const std::vector<std::pair<Object, Object>>& options, std::function<void(Object, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider loadObjectOfClass:completionHandler:]`.
         * @details Asynchronously loads an object of a specified class to an item provider, returning a progress object.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Progress load_object_of_class(const std::string& a_class, std::function<void(Object, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider loadPreviewImageWithOptions:completionHandler:]`.
         * @details Loads the preview image for the item that the item provider represents. To handle image preview yourself, provide a completion handler block that returns an 'NSData' or 'NSURL' object, or an instance of a platform-specific image class ('UIImage' or 'NSImage'). This method supports implicit type coercion for the item parameter of the completion block. - Parameters: - options: A dictionary of keys and values that provide information about the item, such as the size of an image. - completionHandler: A completion handler block to execute with the results.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param completion_handler Argument converted to the Objective-C parameter of the same role.
         */
        void load_preview_image_with_options(const std::vector<std::pair<Object, Object>>& options, std::function<void(Object, Error)> completion_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registerCloudKitShare:container:]`.
         * @param share Argument converted to the Objective-C parameter of the same role.
         * @param container Argument converted to the Objective-C parameter of the same role.
         */
        void register_cloud_kit_share(const Object& share, const Object& container) const;
        /**
         * @brief Calls `-[NSItemProvider registerCloudKitShareWithPreparationHandler:]`.
         * @param preparation_handler Argument converted to the Objective-C parameter of the same role.
         */
        void register_cloud_kit_share_with_preparation_handler(std::function<void(std::function<void(Object, Object, Error)>)> preparation_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registerDataRepresentationForTypeIdentifier:visibility:loadHandler:]`.
         * @details Registers a data-backed representation for an item, specifying item visibility and a load handler. Register higher-fidelity types first, followed by progressively lower-fidelity ones. This ordering helps consumers get the best representation they can handle.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param visibility Argument converted to the Objective-C parameter of the same role.
         * @param load_handler Argument converted to the Objective-C parameter of the same role.
         */
        void register_data_representation_for_type_identifier(const std::string& type_identifier, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(std::vector<std::uint8_t>, Error)>)> load_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registerFileRepresentationForTypeIdentifier:fileOptions:visibility:loadHandler:]`.
         * @details Registers a file-backed representation for an item, specifying file options, item visibility, and a load handler. If a destination app must access the represented file using a file coordinator, set the 'coordinated' parameter in the load handler block to 'YES'. To offer a representation backed by a file provider, return an 'NSURL' object that points to your app's file provider's container. The file provider extension is then invoked to retrieve the file when requested. To offer a representation backed by a file to open in place, set the 'fileOptions' parameter to 'NSItemProviderFileOptionOpenInPlace'; in addition, return an 'NSURL' object that points to your app's file provider's container. Open-in-place support requires that the file provider is visible in the Files app. If 'NSItemProviderFileOptionOpenInPlace' is not provided, the file will be copied before the load handler returns.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param file_options Argument converted to the Objective-C parameter of the same role.
         * @param visibility Argument converted to the Objective-C parameter of the same role.
         * @param load_handler Argument converted to the Objective-C parameter of the same role.
         */
        void register_file_representation_for_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(URL, bool, Error)>)> load_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registerItemForTypeIdentifier:loadHandler:]`.
         * @details Lazily registers an item, according to the item provider type coercion policy. Use this method to register blocks that can take the item provider's file or data object and convert it to a specific data format. Your 'loadHandler' block is executed when a client passes the same 'typeIdentifier' string to the 'loadItemForTypeIdentifier:options:completionHandler:' method. \@deprecated Use 'registerObjectOfClass:visibility:loadHandler:' instead. - Parameters: - typeIdentifier: A string that represents the desired UTI. - loadHandler: A block capable of returning the data item as the specified type.
         * @param type_identifier Argument converted to the Objective-C parameter of the same role.
         * @param load_handler Argument converted to the Objective-C parameter of the same role.
         */
        void register_item_for_type_identifier(const std::string& type_identifier, std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> load_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registerObject:visibility:]`.
         * @details Adds representations of a specified object to an item provider, based on the object's implementation of the 'NSItemProviderWriting' protocol, adhering to a visibility specification. If a representation for a given UTI is already registered, it is preserved (duplicate representations are ignored).
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param visibility Argument converted to the Objective-C parameter of the same role.
         */
        void register_object(const Object& object, ItemProviderRepresentationVisibility visibility) const;
        /**
         * @brief Calls `-[NSItemProvider registerObjectOfClass:visibility:loadHandler:]`.
         * @details Lazily adds representations of a specified object class to an item provider, based on the object's implementation of the 'NSItemProviderWriting' protocol, adhering to a visibility specification.
         * @param a_class Argument converted to the Objective-C parameter of the same role.
         * @param visibility Argument converted to the Objective-C parameter of the same role.
         * @param load_handler Argument converted to the Objective-C parameter of the same role.
         */
        void register_object_of_class(const std::string& a_class, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(Object, Error)>)> load_handler) const;
        /**
         * @brief Calls `-[NSItemProvider registeredTypeIdentifiersWithFileOptions:]`.
         * @details Returns an array with a subset of type identifiers for the item provider, according to the specified file options, in the same order they were registered. To access the array of all registered UTIs, pass the value '0' in the 'fileOptions' parameter. - Parameter fileOptions: The file options to filter by. - Returns: An array of type identifier strings.
         * @param file_options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> registered_type_identifiers_with_file_options(ItemProviderFileOptions file_options) const;
        /**
         * @brief Returns the `containerFrame` property of `NSItemProvider`.
         * @return The converted Objective-C result.
         */
        Rect container_frame() const;
        /**
         * @brief Returns the `preferredPresentationSize` property of `NSItemProvider`.
         * @return The converted Objective-C result.
         */
        Size preferred_presentation_size() const;
        /**
         * @brief Returns the `previewImageHandler` property of `NSItemProvider`.
         * @details The custom preview image handler block for the item provider. In your image handler block, return an ''NSURL'' object that specifies a file, or return an ''NSData'' object.
         * @return The converted Objective-C result.
         */
        std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> preview_image_handler() const;
        /**
         * @brief Sets the `previewImageHandler` property of `NSItemProvider`.
         * @details The custom preview image handler block for the item provider. In your image handler block, return an ''NSURL'' object that specifies a file, or return an ''NSData'' object.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_preview_image_handler(std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> value) const;
        /**
         * @brief Returns the `registeredTypeIdentifiers` property of `NSItemProvider`.
         * @details The array of type identifiers for the item provider, in the same order they were registered.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> registered_type_identifiers() const;
        /**
         * @brief Returns the `sourceFrame` property of `NSItemProvider`.
         * @return The converted Objective-C result.
         */
        Rect source_frame() const;
        /**
         * @brief Returns the `suggestedName` property of `NSItemProvider`.
         * @details The suggested name for the item.
         * @return The converted Objective-C result.
         */
        std::string suggested_name() const;
        /**
         * @brief Sets the `suggestedName` property of `NSItemProvider`.
         * @details The suggested name for the item.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_suggested_name(const std::string& value) const;
    };
}
