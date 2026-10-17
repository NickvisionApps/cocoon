#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class Image;
    class URL;
    class View;
    class Window;

    /**
     * @brief C++ handle for the Objective-C class `NSSharingService` (AppKit).
     * @details NSSharingService can be used to share items to different kinds of local and remote services. Items are objects which respond to the NSPasteboardWriting protocol, like NSURL, NSImage or NSString. If an NSURL is a file URL (point to a video for example), then the content of the file will be shared. If the URL is remote, then the URL itself will be shared.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::SharingService sharing_service(nullptr);  // null handle; instances normally come from other API calls
     * sharing_service.set_menu_item_title("text");
     * sharing_service.will_share_items().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::SharingService sharing_service(nullptr);
     * sharing_service.set_menu_item_title("text");
     * auto menu_item_title = sharing_service.menu_item_title();
     * sharing_service.set_recipients({"a", "b"});
     * auto recipients = sharing_service.recipients();
     * sharing_service.set_subject("text");
     * auto subject = sharing_service.subject();
     * auto made_0 = cocoon::SharingService::sharing_service_named("text");
     * sharing_service.will_share_items().connect([](std::vector<cocoon::Object> a0) {});
     * sharing_service.did_fail_to_share_items_error().connect([](std::vector<cocoon::Object> a0, cocoon::Error a1) {});
     * sharing_service.did_share_items().connect([](std::vector<cocoon::Object> a0) {});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nssharingservice
     */
    class SharingService : public Object
    {
    public:
        /// @brief Creates a new `NSSharingService` instance and returns a handle to it.
        explicit SharingService(const std::string& title, const Image& image, const Image& alternate_image, std::function<void()> block);
        SharingService();
        /// @brief Creates a null handle that refers to no native object.
        SharingService(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit SharingService(Adopt adopt);
        /**
     * @brief Calls `-[NSSharingService canPerformWithItems:]`.
     * @details Returns whether a service can do something with all the provided items. This can be used to validate a custom UI such as a dedicated Twitter button. If items is nil, the method will return YES when the service is configured. Therefore you could call it once at launch time with nil items to check whether to display the button or not, and then with real items to enable and disable the button depending on the context or selection. The items represent the objects to be shared and must conform to the \<NSPasteboardWriting> protocol or be an NSItemProvider or an NSDocument. (e.g. NSString, NSImage, NSURL, etc.)
     * @param items Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_perform_with_items(const std::vector<Object>& items) const;
        /**
     * @brief Calls `-[NSSharingService performWithItems:]`.
     * @details Manually performs the service on the provided items. In most cases this will display a sharing window. The items represent the objects to be shared and must conform to the \<NSPasteboardWriting> protocol or be an NSItemProvider or an NSDocument. (e.g. NSString, NSImage, NSURL, etc.)
     * @param items Argument converted to the Objective-C parameter of the same role.
     */
        void perform_with_items(const std::vector<Object>& items) const;
        /**
     * @brief Calls `+[NSSharingService sharingServiceNamed:]`.
     * @details Returns an NSSharingService representing one of the built-in services.
     * @param service_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static SharingService sharing_service_named(const std::string& service_name);
        /**
     * @brief Returns the `accountName` property of `NSSharingService`.
     * @details Account name used for sending on Twitter or Sina Weibo
     * @return The converted Objective-C result.
     */
        std::string account_name() const;
        /**
     * @brief Returns the `alternateImage` property of `NSSharingService`.
     * @return The converted Objective-C result.
     */
        Image alternate_image() const;
        /**
     * @brief Returns the `attachmentFileURLs` property of `NSSharingService`.
     * @details NSArray of NSURL objects representing the files that were shared
     * @return The converted Objective-C result.
     */
        std::vector<URL> attachment_file_urls() const;
        /**
     * @brief Returns the `image` property of `NSSharingService`.
     * @return The converted Objective-C result.
     */
        Image image() const;
        /**
     * @brief Returns the `menuItemTitle` property of `NSSharingService`.
     * @details Title of the service in the Share menu. Can be modified.
     * @return The converted Objective-C result.
     */
        std::string menu_item_title() const;
        /**
     * @brief Sets the `menuItemTitle` property of `NSSharingService`.
     * @details Title of the service in the Share menu. Can be modified.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_menu_item_title(const std::string& value) const;
        /**
     * @brief Returns the `messageBody` property of `NSSharingService`.
     * @details Message body as string
     * @return The converted Objective-C result.
     */
        std::string message_body() const;
        /**
     * @brief Returns the `permanentLink` property of `NSSharingService`.
     * @details URL to access the post on Facebook, Twitter, Sina Weibo, etc. (also known as permalink)
     * @return The converted Objective-C result.
     */
        URL permanent_link() const;
        /**
     * @brief Returns the `recipients` property of `NSSharingService`.
     * @details NSArray of NSString objects representing handles (example: email adresses)
     * @return The converted Objective-C result.
     */
        std::vector<std::string> recipients() const;
        /**
     * @brief Sets the `recipients` property of `NSSharingService`.
     * @details NSArray of NSString objects representing handles (example: email adresses)
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_recipients(const std::vector<std::string>& value) const;
        /**
     * @brief Returns the `subject` property of `NSSharingService`.
     * @return The converted Objective-C result.
     */
        std::string subject() const;
        /**
     * @brief Sets the `subject` property of `NSSharingService`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_subject(const std::string& value) const;
        /**
     * @brief Returns the `title` property of `NSSharingService`.
     * @return The converted Objective-C result.
     */
        std::string title() const;
        /// @brief Signal for the delegate/data-source method behind `will_share_items`; connect a callback with `will_share_items().connect(...)`.
        Signal<SharingService, void(std::vector<Object>)> will_share_items() const
        {
            return Signal<SharingService, void(std::vector<Object>)>(handle(), "will_share_items");
        }
        /// @brief Signal for the delegate/data-source method behind `did_fail_to_share_items_error`; connect a callback with `did_fail_to_share_items_error().connect(...)`.
        Signal<SharingService, void(std::vector<Object>, Error)> did_fail_to_share_items_error() const
        {
            return Signal<SharingService, void(std::vector<Object>, Error)>(handle(), "did_fail_to_share_items_error");
        }
        /// @brief Signal for the delegate/data-source method behind `did_share_items`; connect a callback with `did_share_items().connect(...)`.
        Signal<SharingService, void(std::vector<Object>)> did_share_items() const
        {
            return Signal<SharingService, void(std::vector<Object>)>(handle(), "did_share_items");
        }
        /// @brief Signal for the delegate/data-source method behind `source_frame_on_screen_for_share_item`; connect a callback with `source_frame_on_screen_for_share_item().connect(...)`.
        Signal<SharingService, Rect(Object)> source_frame_on_screen_for_share_item() const
        {
            return Signal<SharingService, Rect(Object)>(handle(), "source_frame_on_screen_for_share_item");
        }
        /// @brief Signal for the delegate/data-source method behind `transition_image_for_share_item_content_rect`; connect a callback with `transition_image_for_share_item_content_rect().connect(...)`.
        Signal<SharingService, Image(Object, Rect*)> transition_image_for_share_item_content_rect() const
        {
            return Signal<SharingService, Image(Object, Rect*)>(handle(), "transition_image_for_share_item_content_rect");
        }
        /// @brief Signal for the delegate/data-source method behind `source_window_for_share_items_sharing_content_scope`; connect a callback with `source_window_for_share_items_sharing_content_scope().connect(...)`.
        Signal<SharingService, Window(std::vector<Object>, SharingContentScope*)> source_window_for_share_items_sharing_content_scope() const
        {
            return Signal<SharingService, Window(std::vector<Object>, SharingContentScope*)>(handle(), "source_window_for_share_items_sharing_content_scope");
        }
        /// @brief Signal for the delegate/data-source method behind `anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge`; connect a callback with `anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge().connect(...)`.
        Signal<SharingService, View(Rect*, RectEdge*)> anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge() const
        {
            return Signal<SharingService, View(Rect*, RectEdge*)>(handle(), "anchoring_view_for_sharing_service_show_relative_to_rect_preferred_edge");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
