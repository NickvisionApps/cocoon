#pragma once

#include "generated/availability.h"
#include "generated/cell.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSBrowserCell` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Cell.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BrowserCell browser_cell;
     * browser_cell.set_alternate_image(cocoon::Image());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::BrowserCell browser_cell{};
     * browser_cell.set_alternate_image(cocoon::Image());
     * auto alternate_image = browser_cell.alternate_image();
     * browser_cell.set_image(cocoon::Image());
     * auto image = browser_cell.image();
     * browser_cell.set_leaf(true);
     * auto leaf = browser_cell.is_leaf();
     * browser_cell.highlight_color_in_view(cocoon::View());
     * browser_cell.reset();
     * browser_cell.set();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbrowsercell
     */
    class BrowserCell : public Cell
    {
    public:
        /// @brief Creates a new `NSBrowserCell` instance and returns a handle to it.
        explicit BrowserCell(const Image& image);
        /// @brief Creates a new `NSBrowserCell` instance and returns a handle to it.
        explicit BrowserCell(const std::string& string);
        /// @brief Creates a new `NSBrowserCell` instance and returns a handle to it.
        explicit BrowserCell();
        /// @brief Creates a null handle that refers to no native object.
        BrowserCell(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BrowserCell(Adopt adopt);
        using Cell::image;
        using Cell::set_image;
        /**
     * @brief Calls `-[NSBrowserCell highlightColorInView:]`.
     * @param control_view Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color highlight_color_in_view(const View& control_view) const;
        /**
     * @brief Calls `-[NSBrowserCell reset]`.
     */
        void reset() const;
        /**
     * @brief Calls `-[NSBrowserCell set]`.
     */
        void set() const;
        /**
     * @brief Returns the `alternateImage` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        Image alternate_image() const;
        /**
     * @brief Sets the `alternateImage` property of `NSBrowserCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alternate_image(const Image& value) const;
        /**
     * @brief Returns the `branchImage` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        static Image branch_image();
        /**
     * @brief Returns the `highlightedBranchImage` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        static Image highlighted_branch_image();
        /**
     * @brief Returns the `image` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Sets the `image` property of `NSBrowserCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_image(const Image& value) const;
        /**
     * @brief Returns the `leaf` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        bool is_leaf() const;
        /**
     * @brief Sets the `leaf` property of `NSBrowserCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_leaf(bool value) const;
        /**
     * @brief Returns the `loaded` property of `NSBrowserCell`.
     * @return The converted Objective-C result.
     */
        bool is_loaded() const;
        /**
     * @brief Sets the `loaded` property of `NSBrowserCell`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_loaded(bool value) const;
    };
}
