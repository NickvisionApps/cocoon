#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Value;

    /**
     * @brief C++ handle for the Objective-C class `NSTextFinder` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TextFinder text_finder;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TextFinder text_finder{};
     * text_finder.set_find_indicator_needs_update(true);
     * auto find_indicator_needs_update = text_finder.find_indicator_needs_update();
     * text_finder.set_incremental_searching_enabled(true);
     * auto incremental_searching_enabled = text_finder.is_incremental_searching_enabled();
     * text_finder.set_incremental_searching_should_dim_content_view(true);
     * auto incremental_searching_should_dim_content_view = text_finder.incremental_searching_should_dim_content_view();
     * text_finder.cancel_find_indicator();
     * text_finder.note_client_string_will_change();
     * text_finder.perform_action(cocoon::TextFinderAction::ShowFindInterface);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nstextfinder
     */
    class TextFinder : public Object
    {
    public:
        /// @brief Creates a new `NSTextFinder` instance and returns a handle to it.
        explicit TextFinder();
        /// @brief Creates a null handle that refers to no native object.
        TextFinder(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TextFinder(Adopt adopt);
        /**
         * @brief Calls `-[NSTextFinder cancelFindIndicator]`.
         * @details There may be some circumstances where the find indicator should be immediately cancelled or hidden, such as when the view's content or selection is changed without the knowledge of the NSTextFinder. This method will immediately cancel the current find indicator.
         */
        void cancel_find_indicator() const;
        /**
         * @brief Calls `+[NSTextFinder drawIncrementalMatchHighlightInRect:]`.
         * @details If you set incrementalSearchingShouldDimContentView is NO to highlight incremental matches in your own view, you are encouraged to use this method to draw the highlight.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        static void draw_incremental_match_highlight_in_rect(const Rect& rect);
        /**
         * @brief Calls `-[NSTextFinder noteClientStringWillChange]`.
         * @details When incremental search is enabled, this method must be called when it is known that the client's string will be modified, but before the modification takes place.
         */
        void note_client_string_will_change() const;
        /**
         * @brief Calls `-[NSTextFinder performAction:]`.
         * @details Responders to -performTextFinderAction: should call these methods. The -validateAction: method should be called by an implementation of -validateUserInterfaceItem: to properly validate items with an action of -performTextFinderAction:. The -performAction: method should be called by the implementation of -performTextFinderAction:. Both methods should pass the item's or sender's tag as the action parameter to an instance of NSTextFinder that it creates and initializes with the above method.
         * @param op Argument converted to the Objective-C parameter of the same role.
         */
        void perform_action(TextFinderAction op) const;
        /**
         * @brief Calls `-[NSTextFinder validateAction:]`.
         * @param op Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool validate_action(TextFinderAction op) const;
        /**
         * @brief Returns the `client` property of `NSTextFinder`.
         * @details A text finder must be associated with an object which implements the NSTextFinderClient protocol for it to function. The client is responsible for providing the string to be searched, the location for the find bar, and methods which control feedback to the user about the search results.
         * @return The converted Objective-C result.
         */
        Object client() const;
        /**
         * @brief Sets the `client` property of `NSTextFinder`.
         * @details A text finder must be associated with an object which implements the NSTextFinderClient protocol for it to function. The client is responsible for providing the string to be searched, the location for the find bar, and methods which control feedback to the user about the search results.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_client(const Object& value) const;
        /**
         * @brief Returns the `findBarContainer` property of `NSTextFinder`.
         * @details This property must be set to support the find bar. When an NSTextFinder instance is requested to display the find bar, it will create a view for the find bar and assign it to the findBarView property of its findBarContainer. The container then owns that view and should make it visible when the container’s findBarVisible property is set to true. The container should implement the findBarViewDidChangeHeight method so it can reposition the find bar when its height changes, usually in response to user action. NSScrollView already implements NSTextFinderBarContainer and is an excellent place to display the find bar, in most circumstances. The container may freely modify the find bar view's width and origin, but not its height. If this property is not set, then the find bar cannot be shown.
         * @return The converted Objective-C result.
         */
        Object find_bar_container() const;
        /**
         * @brief Sets the `findBarContainer` property of `NSTextFinder`.
         * @details This property must be set to support the find bar. When an NSTextFinder instance is requested to display the find bar, it will create a view for the find bar and assign it to the findBarView property of its findBarContainer. The container then owns that view and should make it visible when the container’s findBarVisible property is set to true. The container should implement the findBarViewDidChangeHeight method so it can reposition the find bar when its height changes, usually in response to user action. NSScrollView already implements NSTextFinderBarContainer and is an excellent place to display the find bar, in most circumstances. The container may freely modify the find bar view's width and origin, but not its height. If this property is not set, then the find bar cannot be shown.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_find_bar_container(const Object& value) const;
        /**
         * @brief Returns the `findIndicatorNeedsUpdate` property of `NSTextFinder`.
         * @details If your client's document is not scrolled by NSScrollView, then you should set this property to YES when scrolling occurs to cause the find indicator to be updated appropriately.
         * @return The converted Objective-C result.
         */
        bool find_indicator_needs_update() const;
        /**
         * @brief Sets the `findIndicatorNeedsUpdate` property of `NSTextFinder`.
         * @details If your client's document is not scrolled by NSScrollView, then you should set this property to YES when scrolling occurs to cause the find indicator to be updated appropriately.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_find_indicator_needs_update(bool value) const;
        /**
         * @brief Returns the `incrementalMatchRanges` property of `NSTextFinder`.
         * @details This array is updated periodically on the main queue as the incremental search operation on a background queue finds matches. You can use this property when incrementalSearchingShouldDimContentView is NO to know where to draw highlights for incremental matches. This array is KVO compliant and can be observed to know when to update your highlights. When NSKeyValueObservingOptionNew and NSKeyValueObservingOptionOld are used, the KVO change dictionary provides the ranges (and their indexes) that are added or removed so you can invalidate the minimal region needed to bring your highlights into sync with the NSTextFinder's results. If no incremental search is active, or there are no matches found, this array will be empty. If an incremental search is currently in progress, but not yet complete, this will return all the ranges found so far.
         * @return The converted Objective-C result.
         */
        std::vector<Value> incremental_match_ranges() const;
        /**
         * @brief Returns the `incrementalSearchingEnabled` property of `NSTextFinder`.
         * @details An NSTextFinder uses this property's value to determine if it should perform regular or incremental searches. If YES, then the find bar will do incremental searches. If it returns NO, then the find bar will behave regularly. The default value is NO.
         * @return The converted Objective-C result.
         */
        bool is_incremental_searching_enabled() const;
        /**
         * @brief Sets the `incrementalSearchingEnabled` property of `NSTextFinder`.
         * @details An NSTextFinder uses this property's value to determine if it should perform regular or incremental searches. If YES, then the find bar will do incremental searches. If it returns NO, then the find bar will behave regularly. The default value is NO.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_incremental_searching_enabled(bool value) const;
        /**
         * @brief Returns the `incrementalSearchingShouldDimContentView` property of `NSTextFinder`.
         * @details NSTextFinder uses this property's value to determine what kind of incremental search feedback should be presented. If YES, then when an incremental search begins, the findBarContainer's contentView will be dimmed, except for the locations of the incremental matches. If NO, then the incremental matches will not be highlighted automatically, but you can use incrementalMatchRanges to highlight the matches yourself. The default value is YES.
         * @return The converted Objective-C result.
         */
        bool incremental_searching_should_dim_content_view() const;
        /**
         * @brief Sets the `incrementalSearchingShouldDimContentView` property of `NSTextFinder`.
         * @details NSTextFinder uses this property's value to determine what kind of incremental search feedback should be presented. If YES, then when an incremental search begins, the findBarContainer's contentView will be dimmed, except for the locations of the incremental matches. If NO, then the incremental matches will not be highlighted automatically, but you can use incrementalMatchRanges to highlight the matches yourself. The default value is YES.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_incremental_searching_should_dim_content_view(bool value) const;
    };
}
