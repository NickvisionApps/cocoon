#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSColorList` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorList color_list;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ColorList color_list{};
     * auto made_0 = cocoon::ColorList::color_list_named("text");
     * color_list.color_with_key("text");
     * color_list.insert_color(cocoon::Color(), "text", 1);
     * color_list.remove_color_with_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorlist
     */
    class ColorList : public Object
    {
    public:
        /// @brief Creates a new `NSColorList` instance and returns a handle to it.
        explicit ColorList(const std::string& name);
        /// @brief Creates a new `NSColorList` instance and returns a handle to it.
        explicit ColorList(const std::string& name, const std::string& path);
        /// @brief Creates a new `NSColorList` instance and returns a handle to it.
        explicit ColorList();
        /// @brief Creates a null handle that refers to no native object.
        ColorList(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorList(Adopt adopt);
        /**
         * @brief Calls `+[NSColorList colorListNamed:]`.
         * @details Returns the named color list from availableColorLists
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ColorList color_list_named(const std::string& name);
        /**
         * @brief Calls `-[NSColorList colorWithKey:]`.
         * @details Returns nil if key doesn't exist.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Color color_with_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSColorList insertColor:key:atIndex:]`.
         * @details Inserts color at the specified location. If a color by the same key is already in the list but at a different location it is removed from there.
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         * @param loc Argument converted to the Objective-C parameter of the same role.
         */
        void insert_color(const Color& color, const std::string& key, std::uint64_t loc) const;
        /**
         * @brief Calls `-[NSColorList removeColorWithKey:]`.
         * @details No-op if key doesn't exist.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void remove_color_with_key(const std::string& key) const;
        /**
         * @brief Calls `-[NSColorList removeFile]`.
         * @details If the color list is in the user's private colorlists directory, removes the corresponding file and the color list from availableColorLists. If there are no outstanding references to the color list this might deallocate the object as well.
         */
        void remove_file() const;
        /**
         * @brief Calls `-[NSColorList setColor:forKey:]`.
         * @details If key already exists, sets the corresponding color. Otherwise inserts the color at the end.
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param key Argument converted to the Objective-C parameter of the same role.
         */
        void set_color(const Color& color, const std::string& key) const;
        /**
         * @brief Calls `-[NSColorList writeToURL:error:]`.
         * @details Save the color list using secure keyed archive format. Specify nil to save to the user's private colorlists directory (and also update availableColorLists), using the name of the color list.
         * @param url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool write_to_url(const URL& url) const;
        /**
         * @brief Returns the `allKeys` property of `NSColorList`.
         * @details Use this array to get count of colors and enumerate them according to the ordering specified when inserting.
         * @return The converted Objective-C result.
         */
        std::vector<std::string> all_keys() const;
        /**
         * @brief Returns the `availableColorLists` property of `NSColorList`.
         * @details Returns all color lists in the user's color list path, including those added at runtime. Creating a named color list and saving with writeToFile:nil will add it to this list; removeFile will remove it from this list. (That is what happens as the user creates and destroys color lists in the color panel.)
         * @return The converted Objective-C result.
         */
        static std::vector<ColorList> available_color_lists();
        /**
         * @brief Returns the `editable` property of `NSColorList`.
         * @details Depends on the source of the colorlist file
         * @return The converted Objective-C result.
         */
        bool is_editable() const;
        /**
         * @brief Returns the `name` property of `NSColorList`.
         * @details Name of the color list
         * @return The converted Objective-C result.
         */
        std::string name() const;
    };
}
