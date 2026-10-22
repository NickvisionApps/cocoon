#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view.h"
#include "types.h"

namespace cocoon
{
    class View;

    /**
     * @brief C++ handle for the Objective-C class `NSBackgroundExtensionView` (AppKit).
     * @details A view that extends content to fill its own bounds. A background extension view can be laid out to extend outside the safe area, such as under the titlebar, sidebar, or inspector. By default it lays out its content to stay within the safe area, and uses modifications of the content along the edges to fill the container view.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref View.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BackgroundExtensionView background_extension_view;
     * background_extension_view.set_automatically_places_content_view(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::BackgroundExtensionView background_extension_view{};
     * background_extension_view.set_automatically_places_content_view(true);
     * auto automatically_places_content_view = background_extension_view.automatically_places_content_view();
     * background_extension_view.set_content_view(cocoon::View());
     * auto content_view = background_extension_view.content_view();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbackgroundextensionview
     */
    class BackgroundExtensionView : public View
    {
    public:
        /// @brief Creates a new `NSBackgroundExtensionView` instance and returns a handle to it.
        explicit BackgroundExtensionView();
        /// @brief Creates a null handle that refers to no native object.
        BackgroundExtensionView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BackgroundExtensionView(Adopt adopt);
        /**
         * @brief Returns the `automaticallyPlacesContentView` property of `NSBackgroundExtensionView`.
         * @details Controls the automatic safe area placement of the 'contentView' within the container. When 'NO', the frame of the content view must be explicitly set or constraints added. The extension effect will be used to fill the container view around the content. Defaults to 'YES'.
         * @return The converted Objective-C result.
         */
        bool automatically_places_content_view() const;
        /**
         * @brief Sets the `automaticallyPlacesContentView` property of `NSBackgroundExtensionView`.
         * @details Controls the automatic safe area placement of the 'contentView' within the container. When 'NO', the frame of the content view must be explicitly set or constraints added. The extension effect will be used to fill the container view around the content. Defaults to 'YES'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_automatically_places_content_view(bool value) const;
        /**
         * @brief Returns the `contentView` property of `NSBackgroundExtensionView`.
         * @details The content view to extend to fill the 'NSBackgroundExtensionView'. The content view will be added as a subview of the extension view and placed within the safe area by default. See 'automaticallyPlacesContentView' to customize the layout.
         * @return The converted Objective-C result.
         */
        View content_view() const;
        /**
         * @brief Sets the `contentView` property of `NSBackgroundExtensionView`.
         * @details The content view to extend to fill the 'NSBackgroundExtensionView'. The content view will be added as a subview of the extension view and placed within the safe area by default. See 'automaticallyPlacesContentView' to customize the layout.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_view(const View& value) const;
    };
}
