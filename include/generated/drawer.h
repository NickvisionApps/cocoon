#pragma once

#include "generated/enums.h"
#include "generated/responder.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSDrawer` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Responder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Drawer drawer;
     * drawer.set_content_size({100, 100});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Drawer drawer{};
     * drawer.set_content_size({100, 100});
     * auto content_size = drawer.content_size();
     * drawer.set_content_view(cocoon::View());
     * auto content_view = drawer.content_view();
     * drawer.set_leading_offset(1);
     * auto leading_offset = drawer.leading_offset();
     * drawer.close();
     * drawer.open();
     * drawer.open_on_edge(cocoon::RectEdge::MinX);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdrawer
     */
    class Drawer : public Responder
    {
    public:
        /// @brief Creates a new `NSDrawer` instance and returns a handle to it.
        explicit Drawer(const Size& content_size, RectEdge edge);
        /// @brief Creates a new `NSDrawer` instance and returns a handle to it.
        explicit Drawer();
        /// @brief Creates a null handle that refers to no native object.
        Drawer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Drawer(Adopt adopt);
        /**
     * @brief Calls `-[NSDrawer close]`.
     */
        void close() const;
        /**
     * @brief Calls `-[NSDrawer close:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void close(const Object& sender) const;
        /**
     * @brief Calls `-[NSDrawer open]`.
     */
        void open() const;
        /**
     * @brief Calls `-[NSDrawer open:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void open(const Object& sender) const;
        /**
     * @brief Calls `-[NSDrawer openOnEdge:]`.
     * @param edge Argument converted to the Objective-C parameter of the same role.
     */
        void open_on_edge(RectEdge edge) const;
        /**
     * @brief Calls `-[NSDrawer toggle:]`.
     * @param sender Argument converted to the Objective-C parameter of the same role.
     */
        void toggle(const Object& sender) const;
        /**
     * @brief Returns the `contentSize` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        Size content_size() const;
        /**
     * @brief Sets the `contentSize` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_size(const Size& value) const;
        /**
     * @brief Returns the `contentView` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        View content_view() const;
        /**
     * @brief Sets the `contentView` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_view(const View& value) const;
        /**
     * @brief Returns the `edge` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        RectEdge edge() const;
        /**
     * @brief Returns the `leadingOffset` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        double leading_offset() const;
        /**
     * @brief Sets the `leadingOffset` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_leading_offset(double value) const;
        /**
     * @brief Returns the `maxContentSize` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        Size max_content_size() const;
        /**
     * @brief Sets the `maxContentSize` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_max_content_size(const Size& value) const;
        /**
     * @brief Returns the `minContentSize` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        Size min_content_size() const;
        /**
     * @brief Sets the `minContentSize` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_min_content_size(const Size& value) const;
        /**
     * @brief Returns the `parentWindow` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        Window parent_window() const;
        /**
     * @brief Sets the `parentWindow` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_parent_window(const Window& value) const;
        /**
     * @brief Returns the `preferredEdge` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        RectEdge preferred_edge() const;
        /**
     * @brief Sets the `preferredEdge` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_preferred_edge(RectEdge value) const;
        /**
     * @brief Returns the `state` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        std::int64_t state() const;
        /**
     * @brief Returns the `trailingOffset` property of `NSDrawer`.
     * @return The converted Objective-C result.
     */
        double trailing_offset() const;
        /**
     * @brief Sets the `trailingOffset` property of `NSDrawer`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_trailing_offset(double value) const;
    };
}
