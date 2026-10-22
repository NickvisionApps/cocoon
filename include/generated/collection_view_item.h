#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/view_controller.h"
#include "types.h"

namespace cocoon
{
    class CollectionView;
    class DraggingImageComponent;
    class ImageView;
    class TextField;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewItem` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ViewController.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewItem collection_view_item;
     * collection_view_item.set_highlight_state(cocoon::CollectionViewItemHighlightState::None);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewItem collection_view_item{};
     * collection_view_item.set_highlight_state(cocoon::CollectionViewItemHighlightState::None);
     * auto highlight_state = collection_view_item.highlight_state();
     * collection_view_item.set_image_view(cocoon::ImageView());
     * auto image_view = collection_view_item.image_view();
     * collection_view_item.set_selected(true);
     * auto selected = collection_view_item.is_selected();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewitem
     */
    class CollectionViewItem : public ViewController
    {
    public:
        /// @brief Creates a new `NSCollectionViewItem` instance and returns a handle to it.
        explicit CollectionViewItem();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewItem(Adopt adopt);
        /**
         * @brief Returns the `collectionView` property of `NSCollectionViewItem`.
         * @details Non-retained backlink to the containing CollectionView.
         * @return The converted Objective-C result.
         */
        CollectionView collection_view() const;
        /**
         * @brief Returns the `draggingImageComponents` property of `NSCollectionViewItem`.
         * @details Multi-image drag and drop support. The default implementation will return an array of up to two NSDraggingImageComponent instances -- one for the imageView and another for the textField (if not nil). This methods can be subclassed and overridden to provide a custom set of NSDraggingImageComponents to create the drag image. Note: the component frames are relative to a coordinate system that has its origin at the bottom left, so you need to take into account the flippedness of your view when computing the component frames.
         * @return The converted Objective-C result.
         */
        std::vector<DraggingImageComponent> dragging_image_components() const;
        /**
         * @brief Returns the `highlightState` property of `NSCollectionViewItem`.
         * @details Whether the item should be shown as highlighted for proposed selection, deselection, as a drop target, or not highlighted.
         * @return The converted Objective-C result.
         */
        CollectionViewItemHighlightState highlight_state() const;
        /**
         * @brief Sets the `highlightState` property of `NSCollectionViewItem`.
         * @details Whether the item should be shown as highlighted for proposed selection, deselection, as a drop target, or not highlighted.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_highlight_state(CollectionViewItemHighlightState value) const;
        /**
         * @brief Returns the `imageView` property of `NSCollectionViewItem`.
         * @details Convenience outlet to the item's primary NSImageView (if any).
         * @return The converted Objective-C result.
         */
        ImageView image_view() const;
        /**
         * @brief Sets the `imageView` property of `NSCollectionViewItem`.
         * @details Convenience outlet to the item's primary NSImageView (if any).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_view(const ImageView& value) const;
        /**
         * @brief Returns the `selected` property of `NSCollectionViewItem`.
         * @details Whether the item is part of its collectionView's current selection.
         * @return The converted Objective-C result.
         */
        bool is_selected() const;
        /**
         * @brief Sets the `selected` property of `NSCollectionViewItem`.
         * @details Whether the item is part of its collectionView's current selection.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_selected(bool value) const;
        /**
         * @brief Returns the `textField` property of `NSCollectionViewItem`.
         * @details Convenience outlet to the item's primary NSTextField (if any).
         * @return The converted Objective-C result.
         */
        TextField text_field() const;
        /**
         * @brief Sets the `textField` property of `NSCollectionViewItem`.
         * @details Convenience outlet to the item's primary NSTextField (if any).
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_text_field(const TextField& value) const;
    };
}
