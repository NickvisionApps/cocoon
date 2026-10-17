#pragma once

#include "generated/enums.h"
#include "generated/font_collection.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class FontDescriptor;
    class Locale;

    /**
     * @brief C++ handle for the Objective-C class `NSMutableFontCollection` (AppKit).
     * @details NSMutableFontCollection - mutable font list
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref FontCollection.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MutableFontCollection mutable_font_collection;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MutableFontCollection mutable_font_collection{};
     * auto made_0 = cocoon::MutableFontCollection::font_collection_with_locale(cocoon::Locale());
     * auto made_1 = cocoon::MutableFontCollection::font_collection_with_name("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmutablefontcollection
     */
    class MutableFontCollection : public FontCollection
    {
    public:
        /// @brief Creates a new `NSMutableFontCollection` instance and returns a handle to it.
        explicit MutableFontCollection();
        /// @brief Creates a null handle that refers to no native object.
        MutableFontCollection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MutableFontCollection(Adopt adopt);
        using FontCollection::exclusion_descriptors;
        using FontCollection::font_collection_with_all_available_descriptors;
        using FontCollection::font_collection_with_descriptors;
        using FontCollection::font_collection_with_locale;
        using FontCollection::font_collection_with_name;
        using FontCollection::query_descriptors;
        /**
     * @brief Calls `-[NSMutableFontCollection addQueryForDescriptors:]`.
     * @param descriptors Argument converted to the Objective-C parameter of the same role.
     */
        void add_query_for_descriptors(const std::vector<FontDescriptor>& descriptors) const;
        /**
     * @brief Calls `+[NSMutableFontCollection fontCollectionWithDescriptors:]`.
     * @param query_descriptors Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MutableFontCollection font_collection_with_descriptors(const std::vector<FontDescriptor>& query_descriptors);
        /**
     * @brief Calls `+[NSMutableFontCollection fontCollectionWithLocale:]`.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MutableFontCollection font_collection_with_locale(const Locale& locale);
        /**
     * @brief Calls `+[NSMutableFontCollection fontCollectionWithName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MutableFontCollection font_collection_with_name(const std::string& name);
        /**
     * @brief Calls `+[NSMutableFontCollection fontCollectionWithName:visibility:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param visibility Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static MutableFontCollection font_collection_with_name(const std::string& name, FontCollectionVisibility visibility);
        /**
     * @brief Calls `-[NSMutableFontCollection removeQueryForDescriptors:]`.
     * @param descriptors Argument converted to the Objective-C parameter of the same role.
     */
        void remove_query_for_descriptors(const std::vector<FontDescriptor>& descriptors) const;
        /**
     * @brief Returns the `exclusionDescriptors` property of `NSMutableFontCollection`.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> exclusion_descriptors() const;
        /**
     * @brief Sets the `exclusionDescriptors` property of `NSMutableFontCollection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_exclusion_descriptors(const std::vector<FontDescriptor>& value) const;
        /**
     * @brief Returns the `fontCollectionWithAllAvailableDescriptors` property of `NSMutableFontCollection`.
     * @return The converted Objective-C result.
     */
        static MutableFontCollection font_collection_with_all_available_descriptors();
        /**
     * @brief Returns the `queryDescriptors` property of `NSMutableFontCollection`.
     * @return The converted Objective-C result.
     */
        std::vector<FontDescriptor> query_descriptors() const;
        /**
     * @brief Sets the `queryDescriptors` property of `NSMutableFontCollection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_query_descriptors(const std::vector<FontDescriptor>& value) const;
    };
}
