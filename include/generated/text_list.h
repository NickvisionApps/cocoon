#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSTextList` (AppKit).
     * @details A section of text that forms a single list. The visible elements of the list, including list markers, appear in the text as they do for lists created by hand. The list object, however, allows the list to be recognized as such by the text system. This enables automatic creation of markers and spacing. Text lists are used in HTML import and export. Text lists appear as attributes on paragraphs, as part of the paragraph style. An ''NSParagraphStyle'' may have an array of text lists, representing the nested lists containing the paragraph, in order from outermost to innermost. For example, if list1 contains four paragraphs, the middle two of which are also in the inner list2, then the text lists array for the first and fourth paragraphs is (list1), while the text lists array for the second and third paragraphs is (list1, list2). The methods implementing this are ''NSParagraphStyle/textLists'' on ''NSParagraphStyle'', and ''NSMutableParagraphStyle/textLists'' on ''NSMutableParagraphStyle''. In addition, \<doc://com.apple.documentation/documentation/foundation/nsattributedstring> has convenience methods for lists, such as \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/1525314-range>, which determines the range covered by a list, and \<doc://com.apple.documentation/documentation/foundation/nsattributedstring/1527303-itemnumber>, which determines the ordinal position within a list of a particular item.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextList text_list;
     * text_list.set_starting_item_number(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextList text_list{};
     * text_list.set_starting_item_number(1);
     * auto starting_item_number = text_list.starting_item_number();
     * text_list.marker_for_item_number(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextlist
     */
    class TextList : public Object
    {
    public:
        /// @brief Creates a new `NSTextList` instance and returns a handle to it.
        explicit TextList(const std::string& marker_format, std::uint64_t options);
        /// @brief Creates a new `NSTextList` instance and returns a handle to it.
        explicit TextList(const std::string& marker_format, TextListOptions options, std::int64_t starting_item_number);
        /// @brief Creates a new `NSTextList` instance and returns a handle to it.
        explicit TextList();
        /// @brief Creates a null handle that refers to no native object.
        TextList(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextList(Adopt adopt);
        /**
         * @brief Calls `-[NSTextList markerForItemNumber:]`.
         * @details Returns the computed value for a specific ordinal position in the list. - Parameters: - itemNumber: The ordinal position in the list whose computed marker value is desired. The receiver ignores this parameter if 'itemNumber' is less than 1 or ''isOrdered'' is 'false'. - Returns: The computed marker value for 'itemNumber'.
         * @param item_number Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string marker_for_item_number(std::int64_t item_number) const;
        /**
         * @brief Returns the `includesTextListMarkers` property of `NSTextList`.
         * @details A Boolean value that indicates whether TextKit includes text list markers in the contents. The default value is 'false'.
         * @return The converted Objective-C result.
         */
        static bool includes_text_list_markers();
        /**
         * @brief Returns the `listOptions` property of `NSTextList`.
         * @details The list options mask value of the receiver.
         * @return The converted Objective-C result.
         */
        TextListOptions list_options() const;
        /**
         * @brief Returns the `markerFormat` property of `NSTextList`.
         * @details The marker format string used by the receiver. \#\# See Also - ''NSTextList/init(markerFormat:options:)''
         * @return The converted Objective-C result.
         */
        std::string marker_format() const;
        /**
         * @brief Returns the `ordered` property of `NSTextList`.
         * @details A Boolean value that indicates whether the list is ordered.
         * @return The converted Objective-C result.
         */
        bool is_ordered() const;
        /**
         * @brief Returns the `startingItemNumber` property of `NSTextList`.
         * @details The starting item number for the text list. The default value is '1'. This value will be used only for ordered lists, and ignored in other cases.
         * @return The converted Objective-C result.
         */
        std::int64_t starting_item_number() const;
        /**
         * @brief Sets the `startingItemNumber` property of `NSTextList`.
         * @details The starting item number for the text list. The default value is '1'. This value will be used only for ordered lists, and ignored in other cases.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_starting_item_number(std::int64_t value) const;
    };
}
