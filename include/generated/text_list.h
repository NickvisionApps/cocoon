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
         * @param item_number Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string marker_for_item_number(std::int64_t item_number) const;
        /**
         * @brief Returns the `includesTextListMarkers` property of `NSTextList`.
         * @return The converted Objective-C result.
         */
        static bool includes_text_list_markers();
        /**
         * @brief Returns the `listOptions` property of `NSTextList`.
         * @return The converted Objective-C result.
         */
        TextListOptions list_options() const;
        /**
         * @brief Returns the `markerFormat` property of `NSTextList`.
         * @return The converted Objective-C result.
         */
        std::string marker_format() const;
        /**
         * @brief Returns the `ordered` property of `NSTextList`.
         * @return The converted Objective-C result.
         */
        bool is_ordered() const;
        /**
         * @brief Returns the `startingItemNumber` property of `NSTextList`.
         * @return The converted Objective-C result.
         */
        std::int64_t starting_item_number() const;
        /**
         * @brief Sets the `startingItemNumber` property of `NSTextList`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_starting_item_number(std::int64_t value) const;
    };
}
