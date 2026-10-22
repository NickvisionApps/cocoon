#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMediaLibraryBrowserController` (AppKit).
     * @details \@abstract This class configures and displays a media browser panel. \@discussion This class provides no direct access to the panel, and its meaningful contents aren't in the calling process.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MediaLibraryBrowserController media_library_browser_controller;
     * media_library_browser_controller.set_frame({{0, 0}, {100, 100}});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MediaLibraryBrowserController media_library_browser_controller{};
     * media_library_browser_controller.set_frame({{0, 0}, {100, 100}});
     * auto frame = media_library_browser_controller.frame();
     * media_library_browser_controller.set_media_libraries(cocoon::MediaLibrary::Audio);
     * auto media_libraries = media_library_browser_controller.media_libraries();
     * media_library_browser_controller.set_visible(true);
     * auto visible = media_library_browser_controller.is_visible();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsmedialibrarybrowsercontroller
     */
    class MediaLibraryBrowserController : public Object
    {
    public:
        /// @brief Creates a new `NSMediaLibraryBrowserController` instance and returns a handle to it.
        explicit MediaLibraryBrowserController();
        /// @brief Creates a null handle that refers to no native object.
        MediaLibraryBrowserController(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MediaLibraryBrowserController(Adopt adopt);
        /**
         * @brief Calls `-[NSMediaLibraryBrowserController togglePanel:]`.
         * @param sender Argument converted to the Objective-C parameter of the same role.
         */
        void toggle_panel(const Object& sender) const;
        /**
         * @brief Returns the `frame` property of `NSMediaLibraryBrowserController`.
         * @return The converted Objective-C result.
         */
        Rect frame() const;
        /**
         * @brief Sets the `frame` property of `NSMediaLibraryBrowserController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_frame(const Rect& value) const;
        /**
         * @brief Returns the `mediaLibraries` property of `NSMediaLibraryBrowserController`.
         * @return The converted Objective-C result.
         */
        MediaLibrary media_libraries() const;
        /**
         * @brief Sets the `mediaLibraries` property of `NSMediaLibraryBrowserController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_media_libraries(MediaLibrary value) const;
        /**
         * @brief Returns the `sharedMediaLibraryBrowserController` property of `NSMediaLibraryBrowserController`.
         * @return The converted Objective-C result.
         */
        static MediaLibraryBrowserController shared_media_library_browser_controller();
        /**
         * @brief Returns the `visible` property of `NSMediaLibraryBrowserController`.
         * @return The converted Objective-C result.
         */
        bool is_visible() const;
        /**
         * @brief Sets the `visible` property of `NSMediaLibraryBrowserController`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_visible(bool value) const;
    };
}
