#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class FontDescriptor;
    class Locale;
    class Number;

    /**
     * @brief C++ handle for the Objective-C class `NSFontCollection` (AppKit).
     * @details NSFontCollection - immutable font list
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FontCollection font_collection;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FontCollection font_collection{};
     * font_collection.matching_descriptors_for_family("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfontcollection
     */
    class FontCollection : public Object
    {
    public:
        /// @brief Creates a new `NSFontCollection` instance and returns a handle to it.
        explicit FontCollection(const std::vector<FontDescriptor>& query_descriptors);
        /// @brief Creates a new `NSFontCollection` instance and returns a handle to it.
        explicit FontCollection(const Locale& locale);
        /// @brief Creates a new `NSFontCollection` instance and returns a handle to it.
        explicit FontCollection(const std::string& name);
        /// @brief Creates a new `NSFontCollection` instance and returns a handle to it.
        explicit FontCollection(const std::string& name, FontCollectionVisibility visibility);
        /// @brief Creates a new `NSFontCollection` instance and returns a handle to it.
        explicit FontCollection();
        /// @brief Creates a null handle that refers to no native object.
        FontCollection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FontCollection(Adopt adopt);
        /**
     * @brief Calls `+[NSFontCollection hideFontCollectionWithName:visibility:error:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool hide_font_collection_with_name(const std::string& name, FontCollectionVisibility visibility);
        /**
     * @brief Calls `-[NSFontCollection matchingDescriptorsForFamily:]`.
     * @param family Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> matching_descriptors_for_family(const std::string& family) const;
        /**
     * @brief Calls `-[NSFontCollection matchingDescriptorsForFamily:options:]`.
     * @param family Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> matching_descriptors_for_family(const std::string& family, const std::map<std::string, Number>& options) const;
        /**
     * @brief Calls `-[NSFontCollection matchingDescriptorsWithOptions:]`.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> matching_descriptors_with_options(const std::map<std::string, Number>& options) const;
        /**
     * @brief Calls `+[NSFontCollection renameFontCollectionWithName:visibility:toName:error:]`.
     * @param old_name Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @param new_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool rename_font_collection_with_name(const std::string& old_name, FontCollectionVisibility visibility, const std::string& new_name);
        /**
     * @brief Calls `+[NSFontCollection showFontCollection:withName:visibility:error:]`.
     * @param collection Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool show_font_collection(const FontCollection& collection, const std::string& name, FontCollectionVisibility visibility);
        /**
     * @brief Returns the `allFontCollectionNames` property of `NSFontCollection`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> all_font_collection_names();
        /**
     * @brief Returns the `exclusionDescriptors` property of `NSFontCollection`.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> exclusion_descriptors() const;
        /**
     * @brief Returns the `fontCollectionWithAllAvailableDescriptors` property of `NSFontCollection`.
     * @return The converted Objective-C result.
     */
        static FontCollection font_collection_with_all_available_descriptors();
        /**
     * @brief Returns the `matchingDescriptors` property of `NSFontCollection`.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> matching_descriptors() const;
        /**
     * @brief Returns the `queryDescriptors` property of `NSFontCollection`.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> query_descriptors() const;
    };
}
