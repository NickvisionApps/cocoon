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
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_load_object_of_class(const std::string& a_class) const;
        /**
     * @brief Calls `-[NSItemProvider hasItemConformingToTypeIdentifier:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_item_conforming_to_type_identifier(const std::string& type_identifier) const;
        /**
     * @brief Calls `-[NSItemProvider hasRepresentationConformingToTypeIdentifier:fileOptions:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param file_options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool has_representation_conforming_to_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options) const;
        /**
     * @brief Calls `-[NSItemProvider loadDataRepresentationForTypeIdentifier:completionHandler:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Progress load_data_representation_for_type_identifier(const std::string& type_identifier, std::function<void(std::vector<std::uint8_t>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSItemProvider loadFileRepresentationForTypeIdentifier:completionHandler:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Progress load_file_representation_for_type_identifier(const std::string& type_identifier, std::function<void(URL, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSItemProvider loadInPlaceFileRepresentationForTypeIdentifier:completionHandler:]`.
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
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Progress load_object_of_class(const std::string& a_class, std::function<void(Object, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSItemProvider loadPreviewImageWithOptions:completionHandler:]`.
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
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @param load_handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_data_representation_for_type_identifier(const std::string& type_identifier, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(std::vector<std::uint8_t>, Error)>)> load_handler) const;
        /**
     * @brief Calls `-[NSItemProvider registerFileRepresentationForTypeIdentifier:fileOptions:visibility:loadHandler:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param file_options Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @param load_handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_file_representation_for_type_identifier(const std::string& type_identifier, ItemProviderFileOptions file_options, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(URL, bool, Error)>)> load_handler) const;
        /**
     * @brief Calls `-[NSItemProvider registerItemForTypeIdentifier:loadHandler:]`.
     * @param type_identifier Argument converted to the Objective-C parameter of the same role.
     * @param load_handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_item_for_type_identifier(const std::string& type_identifier, std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> load_handler) const;
        /**
     * @brief Calls `-[NSItemProvider registerObject:visibility:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     */
        void register_object(const Object& object, ItemProviderRepresentationVisibility visibility) const;
        /**
     * @brief Calls `-[NSItemProvider registerObjectOfClass:visibility:loadHandler:]`.
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @param load_handler Argument converted to the Objective-C parameter of the same role.
     */
        void register_object_of_class(const std::string& a_class, ItemProviderRepresentationVisibility visibility, std::function<Progress(std::function<void(Object, Error)>)> load_handler) const;
        /**
     * @brief Calls `-[NSItemProvider registeredTypeIdentifiersWithFileOptions:]`.
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
     * @return The converted Objective-C result.
     */
        std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> preview_image_handler() const;
        /**
     * @brief Sets the `previewImageHandler` property of `NSItemProvider`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preview_image_handler(std::function<void(std::function<void(Object, Error)>, std::string, std::vector<std::pair<Object, Object>>)> value) const;
        /**
     * @brief Returns the `registeredTypeIdentifiers` property of `NSItemProvider`.
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
     * @return The converted Objective-C result.
     */
        std::string suggested_name() const;
        /**
     * @brief Sets the `suggestedName` property of `NSItemProvider`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_suggested_name(const std::string& value) const;
    };
}
