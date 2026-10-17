#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class IndexPath;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewLayoutAttributes` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewLayoutAttributes collection_view_layout_attributes;
     * collection_view_layout_attributes.set_alpha(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewLayoutAttributes collection_view_layout_attributes{};
     * collection_view_layout_attributes.set_alpha(1);
     * auto alpha = collection_view_layout_attributes.alpha();
     * collection_view_layout_attributes.set_frame({{0, 0}, {100, 100}});
     * auto frame = collection_view_layout_attributes.frame();
     * collection_view_layout_attributes.set_hidden(true);
     * auto hidden = collection_view_layout_attributes.is_hidden();
     * auto made_0 = cocoon::CollectionViewLayoutAttributes::layout_attributes_for_decoration_view_of_kind("text", cocoon::IndexPath());
     * auto made_1 = cocoon::CollectionViewLayoutAttributes::layout_attributes_for_inter_item_gap_before_index_path(cocoon::IndexPath());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewlayoutattributes
     */
    class CollectionViewLayoutAttributes : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewLayoutAttributes` instance and returns a handle to it.
        explicit CollectionViewLayoutAttributes();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewLayoutAttributes(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewLayoutAttributes(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionViewLayoutAttributes layoutAttributesForDecorationViewOfKind:withIndexPath:]`.
     * @param decoration_view_kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionViewLayoutAttributes layout_attributes_for_decoration_view_of_kind(const std::string& decoration_view_kind, const IndexPath& index_path);
        /**
     * @brief Calls `+[NSCollectionViewLayoutAttributes layoutAttributesForInterItemGapBeforeIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionViewLayoutAttributes layout_attributes_for_inter_item_gap_before_index_path(const IndexPath& index_path);
        /**
     * @brief Calls `+[NSCollectionViewLayoutAttributes layoutAttributesForItemWithIndexPath:]`.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionViewLayoutAttributes layout_attributes_for_item_with_index_path(const IndexPath& index_path);
        /**
     * @brief Calls `+[NSCollectionViewLayoutAttributes layoutAttributesForSupplementaryViewOfKind:withIndexPath:]`.
     * @param element_kind Argument converted to the Objective-C parameter of the same role.
     * @param index_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionViewLayoutAttributes layout_attributes_for_supplementary_view_of_kind(const std::string& element_kind, const IndexPath& index_path);
        /**
     * @brief Returns the `alpha` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        double alpha() const;
        /**
     * @brief Sets the `alpha` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alpha(double value) const;
        /**
     * @brief Returns the `frame` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        Rect frame() const;
        /**
     * @brief Sets the `frame` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_frame(const Rect& value) const;
        /**
     * @brief Returns the `hidden` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        bool is_hidden() const;
        /**
     * @brief Sets the `hidden` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_hidden(bool value) const;
        /**
     * @brief Returns the `indexPath` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        IndexPath index_path() const;
        /**
     * @brief Sets the `indexPath` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_index_path(const IndexPath& value) const;
        /**
     * @brief Returns the `representedElementCategory` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        CollectionElementCategory represented_element_category() const;
        /**
     * @brief Returns the `representedElementKind` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        std::string represented_element_kind() const;
        /**
     * @brief Returns the `size` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        Size size() const;
        /**
     * @brief Sets the `size` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size(const Size& value) const;
        /**
     * @brief Returns the `zIndex` property of `NSCollectionViewLayoutAttributes`.
     * @return The converted Objective-C result.
     */
        std::int64_t z_index() const;
        /**
     * @brief Sets the `zIndex` property of `NSCollectionViewLayoutAttributes`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_z_index(std::int64_t value) const;
    };
}
