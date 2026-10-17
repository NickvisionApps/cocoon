#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class FileWrapper;
    class PasteboardItem;

    /**
     * @brief C++ handle for the Objective-C class `NSPasteboard` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Pasteboard pasteboard;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Pasteboard pasteboard{};
     * auto made_0 = cocoon::Pasteboard::pasteboard_by_filtering_file("text");
     * auto made_1 = cocoon::Pasteboard::pasteboard_by_filtering_types_in_pasteboard(cocoon::Pasteboard());
     * pasteboard.available_type_from_array({"a", "b"});
     * pasteboard.can_read_item_with_data_conforming_to_types({"a", "b"});
     * pasteboard.clear_contents();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspasteboard
     */
    class Pasteboard : public Object
    {
    public:
        /// @brief Creates a new `NSPasteboard` instance and returns a handle to it.
        explicit Pasteboard();
        /// @brief Creates a null handle that refers to no native object.
        Pasteboard(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Pasteboard(Adopt adopt);
        /**
     * @brief Calls `-[NSPasteboard addTypes:owner:]`.
     * @details This method adds promises for the specified types to the first pasteboard item. If the data for those types is provided immediately, the owner can be nil. If the data for the added types will be provided lazily when requested from the pasteboard, an owner object must be provided that implements the -pasteboard:provideDataForType: method of the NSPasteboardOwner informal protocol.
     * @param new_types Argument converted to the Objective-C parameter of the same role.
     * @param new_owner Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t add_types(const std::vector<std::string>& new_types, const Object& new_owner) const;
        /**
     * @brief Calls `-[NSPasteboard availableTypeFromArray:]`.
     * @param types Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string available_type_from_array(const std::vector<std::string>& types) const;
        /**
     * @brief Calls `-[NSPasteboard canReadItemWithDataConformingToTypes:]`.
     * @details Method to validate whether the pasteboard contains at least one item that conforms to the specified UTIs.
     * @param types Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_read_item_with_data_conforming_to_types(const std::vector<std::string>& types) const;
        /**
     * @brief Calls `-[NSPasteboard canReadObjectForClasses:options:]`.
     * @details Method to validate whether at least one instance of any of the provided classes can be created with data on the pasteboard. Classes in the provided array must implement the NSPasteboardReading protocol. Additional options, such as restricting the search to file URLs, or URLs particular content types, can be specified with an options dictionary. See the comments for the reading option keys for a full description.
     * @param class_array Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_read_object_for_classes(const std::vector<std::string>& class_array, const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSPasteboard clearContents]`.
     * @details Prepares the pasteboard for new contents, clearing the existing contents of the pasteboard. This is equivalent to calling prepareForNewContentsWithOptions: with no options. Returns the change count of the pasteboard.
     * @return The converted Objective-C result.
     */
        std::int64_t clear_contents() const;
        /**
     * @brief Calls `-[NSPasteboard dataForType:]`.
     * @details These methods return a best representation of all items on the pasteboard for the requested type. For almost all data types, this simply means returning the data for the first item on the pasteboard that contains that type. For standard text data types such as string, RTF, and RTFD, the text data from each item will be returned as one combined result separated by newlines.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data_for_type(const std::string& data_type) const;
        /**
     * @brief Calls `-[NSPasteboard declareTypes:owner:]`.
     * @details This method is the equivalent of calling -clearContents, implicitly writing the first pasteboard item, and then calling -addTypes:owner: to promise types for the first pasteboard item. In general, this method should not be used with -writeObjects: since -writeObjects: will always write additional items to the pasteboard, and will not affect items already on the pasteboard, including the item implicitly created by this method.
     * @param new_types Argument converted to the Objective-C parameter of the same role.
     * @param new_owner Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t declare_types(const std::vector<std::string>& new_types, const Object& new_owner) const;
        /**
     * @brief Calls `-[NSPasteboard detectMetadataForTypes:completionHandler:]`.
     * @details Determines available metadata from the specified metadata types for the first pasteboard item, without notifying the person using the app. This method only gives access to limited types of metadata and doesn’t allow the app to access the contents. As a result, the system doesn’t notify the person using the app about reading the contents of the pasteboard. For details about the metadata returned for each type, see ''NSPasteboardMetadataType''. The following example shows how to use this method to find the content type of a file reference in the first item on the pasteboard: '''obj-c [NSPasteboard.generalPasteboard detectMetadataForTypes:[NSSet setWithArray:\@[NSPasteboardMetadataTypeContentType]] completionHandler:^(NSDictionary\<NSPasteboardMetadataType, id> metadata, NSError error) { if (error) { NSLog(\@"Error: \%\@", error); return; } UTType contentType = (UTType)metadata[NSPasteboardMetadataTypeContentType]; if (contentType) { NSLog(\@"Content type is: \%\@", contentType.identifier); } else { NSLog(\@"Couldn't get content type"); } }]; ''' - Parameters: - types: The metadata types to detect on the pasteboard. - completionHandler: A block the system invokes after detecting metadata on the pasteboard. The block receives either a dictionary with the metadata types the system finds on the pasteboard or an error if detection fails. The dictionary keys specify the matched metadata types and the values specify the corresponding metadata.
     * @param types Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void detect_metadata_for_types(const std::vector<std::string>& types, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSPasteboard detectPatternsForPatterns:completionHandler:]`.
     * @details Determines whether the first pasteboard item matches the specified patterns, without notifying the person using the app. This method only gives an indication of whether the first pasteboard item matches a particular pattern, and doesn’t allow the app to access the item's contents. As a result, the system doesn’t notify the person using the app about reading the contents of the pasteboard. The following example shows how to use this method to find email and postal addresses in the first pasteboard item: '''obj-c [NSPasteboard.generalPasteboard detectPatternsForPatterns:[NSSet setWithArray:\@[NSPasteboardDetectionPatternEmailAddress, NSPasteboardDetectionPatternPostalAddress]] completionHandler:^(NSSet\<NSPasteboardDetectionPattern> matchedPatterns, NSError error) { if (error) { NSLog(\@"Error: \%\@", error); return; } BOOL matchedEmail = [matchedPatterns containsObject:NSPasteboardDetectionPatternEmailAddress]; BOOL matchedPostal = [matchedPatterns containsObject: NSPasteboardDetectionPatternPostalAddress]; if (matchedEmail) { NSLog(\@"Email address(es) detected"); } if (matchedPostal) { NSLog(\@"Postal address(es) detected"); } if (!matchedEmail && !matchedPostal) { NSLog(\@"Matched neither email nor postal addresses."); } }]; ''' - Parameters: - patterns: The patterns to detect on the pasteboard. - completionHandler: A block the system invokes after detecting patterns on the pasteboard. The block receives either a set with the patterns the system finds on the pasteboard or an error if detection fails.
     * @param patterns Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void detect_patterns_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::vector<std::string>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSPasteboard detectValuesForPatterns:completionHandler:]`.
     * @details Determines whether the first pasteboard item matches the specified patterns, reading the contents if it finds a match. For details about the types returned for each pattern, see ''NSPasteboardDetectionPattern''. The following example shows how to use this method to find web URLs and web search terms in the first pasteboard item: '''obj-c [NSPasteboard.generalPasteboard detectValuesForPatterns:[NSSet setWithArray:\@[NSPasteboardDetectionPatternProbableWebSearch, NSPasteboardDetectionPatternProbableWebURL]] completionHandler:^(NSDictionary\<NSPasteboardDetectionPattern, id> patternValues, NSError error) { if (error) { NSLog(\@"Error: \%\@", error); return; } NSString searchString = (NSString)patternValues[NSPasteboardDetectionPatternProbableWebSearch]; NSString urlString = (NSString)patternValues[NSPasteboardDetectionPatternProbableWebURL] ; if (searchString != nil) { NSLog(\@"Web search retrieved: \%\@", searchString); } if (urlString != nil) { NSLog(\@"Web URL retrieved: \%\@", urlString); } if (searchString == nil && urlString == nil) { NSLog(\@"No web patterns retrieved."); } }]; ''' > Important: If the system finds a match when calling this method, the system informs the person using the app that the app is trying to read the contents of the pasteboard. If the person denies access to the pasteboard, the completion handler receives an error. - Parameters: - patterns: The patterns to detect on the pasteboard. - completionHandler: A block the system invokes after detecting patterns on the pasteboard. The block returns either a dictionary with the patterns the system finds on the pasteboard or an error if detection fails. The dictionary keys specify the matched patterns and the values specify the corresponding content of the pasteboard.
     * @param patterns Argument converted to the Objective-C parameter of the same role.
     * @param completion_handler Argument converted to the Objective-C parameter of the same role.
     */
        void detect_values_for_patterns(const std::vector<std::string>& patterns, std::function<void(std::map<std::string, Object>, Error)> completion_handler) const;
        /**
     * @brief Calls `-[NSPasteboard indexOfPasteboardItem:]`.
     * @details The index of the provided pasteboard item in the pasteboard. If the pasteboard item has not been added to any pasteboard, or is owned by another pasteboard, returns the value NSNotFound. An item's index in the pasteboard is useful for a pasteboard item data provider that has promised data for multiple items, to be able to easily match the pasteboard item to an array of source data from which to derive the promised data.
     * @param pasteboard_item Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::uint64_t index_of_pasteboard_item(const PasteboardItem& pasteboard_item) const;
        /**
     * @brief Calls `+[NSPasteboard pasteboardByFilteringData:ofType:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Pasteboard pasteboard_by_filtering_data(const std::vector<std::uint8_t>& data, const std::string& type);
        /**
     * @brief Calls `+[NSPasteboard pasteboardByFilteringFile:]`.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Pasteboard pasteboard_by_filtering_file(const std::string& filename);
        /**
     * @brief Calls `+[NSPasteboard pasteboardByFilteringTypesInPasteboard:]`.
     * @param pboard Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Pasteboard pasteboard_by_filtering_types_in_pasteboard(const Pasteboard& pboard);
        /**
     * @brief Calls `+[NSPasteboard pasteboardWithName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Pasteboard pasteboard_with_name(const std::string& name);
        /**
     * @brief Calls `+[NSPasteboard pasteboardWithUniqueName]`.
     * @return The converted Objective-C result.
     */
        static Pasteboard pasteboard_with_unique_name();
        /**
     * @brief Calls `-[NSPasteboard prepareForNewContentsWithOptions:]`.
     * @details Prepares the pasteboard for new contents, clearing the existing contents of the pasteboard. This is the first step in providing data on the pasteboard. Any options specified will persist until prepareForNewContentsWithOptions: or clearContents is called. Returns the change count of the pasteboard.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t prepare_for_new_contents_with_options(PasteboardContentsOptions options) const;
        /**
     * @brief Calls `-[NSPasteboard propertyListForType:]`.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object property_list_for_type(const std::string& data_type) const;
        /**
     * @brief Calls `-[NSPasteboard readFileContentsType:toFile:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string read_file_contents_type(const std::string& type, const std::string& filename) const;
        /**
     * @brief Calls `-[NSPasteboard readFileWrapper]`.
     * @return The converted Objective-C result.
     */
        FileWrapper read_file_wrapper() const;
        /**
     * @brief Calls `-[NSPasteboard readObjectsForClasses:options:]`.
     * @details Classes in the provided array must implement the NSPasteboardReading protocol. Cocoa classes that implement this protocol include NSImage, NSString, NSURL, NSColor, NSAttributedString, and NSPasteboardItem. For every item on the pasteboard, each class in the provided array will be queried for the types it can read using -readableTypesForPasteboard:. An instance will be created of the first class found in the provided array whose readable types match a conforming type contained in that pasteboard item. Any instances that could be created from pasteboard item data is returned to the caller. Additional options, such as restricting the search to file URLs with particular content types, can be specified with an options dictionary. See the comments for the option keys for a full description. Returns nil if there is an error in retrieving the requested items from the pasteboard or if no objects of the specified types can be created. Example: there are five items on the pasteboard, two contain TIFF data, two contain RTF data, one contains a private data type. Calling -readObjectsForClasses: with just the NSImage class, will return an array containing two image objects. Calling with just the NSAttributedString class, will return an array containing two attributed strings. Calling with both classes will return two image objects and two attributed strings. Note that in the above examples, the count of objects returned is less than the number of items on the pasteboard. Only objects of the requested classes are returned. You can always ensure to receive one object per item on the pasteboard by including the NSPasteboardItem class in the array of classes. In this example, an array containing the NSImage, NSAttributedString, and NSSPasteboardItem classes will return an array with two images, two attributed strings, and one pasteboard item containing the private data type.
     * @param class_array Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> read_objects_for_classes(const std::vector<std::string>& class_array, const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[NSPasteboard releaseGlobally]`.
     */
        void release_globally() const;
        /**
     * @brief Calls `-[NSPasteboard setData:forType:]`.
     * @details These methods set data for the specified type on the first pasteboard item.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_data(const std::vector<std::uint8_t>& data, const std::string& data_type) const;
        /**
     * @brief Calls `-[NSPasteboard setPropertyList:forType:]`.
     * @param plist Argument converted to the Objective-C parameter of the same role.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_property_list(const Object& plist, const std::string& data_type) const;
        /**
     * @brief Calls `-[NSPasteboard setString:forType:]`.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool set_string(const std::string& string, const std::string& data_type) const;
        /**
     * @brief Calls `-[NSPasteboard stringForType:]`.
     * @param data_type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string string_for_type(const std::string& data_type) const;
        /**
     * @brief Calls `+[NSPasteboard typesFilterableTo:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> types_filterable_to(const std::string& type);
        /**
     * @brief Calls `-[NSPasteboard writeFileContents:]`.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_file_contents(const std::string& filename) const;
        /**
     * @brief Calls `-[NSPasteboard writeFileWrapper:]`.
     * @param wrapper Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_file_wrapper(const FileWrapper& wrapper) const;
        /**
     * @brief Calls `-[NSPasteboard writeObjects:]`.
     * @details Writes the data of an array of objects that implement the NSPasteboardWriting protocol (including NSPasteboardItem instances). Returns NO if the items were not successfully added to the pasteboard.
     * @param objects Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool write_objects(const std::vector<Object>& objects) const;
        /**
     * @brief Returns the `accessBehavior` property of `NSPasteboard`.
     * @details The current pasteboard access behavior. The user can customize this behavior per-app in System Settings for any app that has triggered a pasteboard access alert in the past.
     * @return The converted Objective-C result.
     */
        PasteboardAccessBehavior access_behavior() const;
        /**
     * @brief Returns the `changeCount` property of `NSPasteboard`.
     * @return The converted Objective-C result.
     */
        std::int64_t change_count() const;
        /**
     * @brief Returns the `generalPasteboard` property of `NSPasteboard`.
     * @return The converted Objective-C result.
     */
        static Pasteboard general_pasteboard();
        /**
     * @brief Returns the `name` property of `NSPasteboard`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `pasteboardItems` property of `NSPasteboard`.
     * @details Returns all pasteboard items. Returns nil if there is an error retrieving pasteboard items.
     * @return The converted Objective-C result.
     */
        std::vector<PasteboardItem> pasteboard_items() const;
        /**
     * @brief Returns the `types` property of `NSPasteboard`.
     * @details These methods provide information about the types available from the entire pasteboard.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> types() const;
    };
}
