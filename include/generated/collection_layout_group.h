#pragma once

#include "generated/availability.h"
#include "generated/collection_layout_item.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutGroupCustomItem;
    class CollectionLayoutItem;
    class CollectionLayoutSize;
    class CollectionLayoutSpacing;
    class CollectionLayoutSupplementaryItem;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutGroup` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionLayoutItem.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutGroup collection_layout_group(nullptr);  // null handle; instances normally come from other API calls
     * collection_layout_group.set_inter_item_spacing(cocoon::CollectionLayoutSpacing());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutGroup collection_layout_group(nullptr);
     * collection_layout_group.set_inter_item_spacing(cocoon::CollectionLayoutSpacing());
     * auto inter_item_spacing = collection_layout_group.inter_item_spacing();
     * auto made_0 = cocoon::CollectionLayoutGroup::horizontal_group_with_layout_size(cocoon::CollectionLayoutSize(), cocoon::CollectionLayoutItem(), 1);
     * auto made_1 = cocoon::CollectionLayoutGroup::vertical_group_with_layout_size(cocoon::CollectionLayoutSize(), cocoon::CollectionLayoutItem(), 1);
     * collection_layout_group.visual_description();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutgroup
     */
    class CollectionLayoutGroup : public CollectionLayoutItem
    {
    public:
        CollectionLayoutGroup();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutGroup(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutGroup(Adopt adopt);
        using CollectionLayoutItem::supplementary_items;
        /**
     * @brief Calls `+[NSCollectionLayoutGroup customGroupWithLayoutSize:itemProvider:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param item_provider Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroup custom_group_with_layout_size(const CollectionLayoutSize& layout_size, std::function<std::vector<CollectionLayoutGroupCustomItem>(Object)> item_provider);
        /**
     * @brief Calls `+[NSCollectionLayoutGroup horizontalGroupWithLayoutSize:subitem:count:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param subitem Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroup horizontal_group_with_layout_size(const CollectionLayoutSize& layout_size, const CollectionLayoutItem& subitem, std::int64_t count);
        /**
     * @brief Calls `+[NSCollectionLayoutGroup horizontalGroupWithLayoutSize:subitems:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param subitems Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroup horizontal_group_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutItem>& subitems);
        /**
     * @brief Calls `+[NSCollectionLayoutGroup verticalGroupWithLayoutSize:subitem:count:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param subitem Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroup vertical_group_with_layout_size(const CollectionLayoutSize& layout_size, const CollectionLayoutItem& subitem, std::int64_t count);
        /**
     * @brief Calls `+[NSCollectionLayoutGroup verticalGroupWithLayoutSize:subitems:]`.
     * @param layout_size Argument converted to the Objective-C parameter of the same role.
     * @param subitems Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutGroup vertical_group_with_layout_size(const CollectionLayoutSize& layout_size, const std::vector<CollectionLayoutItem>& subitems);
        /**
     * @brief Calls `-[NSCollectionLayoutGroup visualDescription]`.
     * @return The converted Objective-C result.
     */
        std::string visual_description() const;
        /**
     * @brief Returns the `interItemSpacing` property of `NSCollectionLayoutGroup`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSpacing inter_item_spacing() const;
        /**
     * @brief Sets the `interItemSpacing` property of `NSCollectionLayoutGroup`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_inter_item_spacing(const CollectionLayoutSpacing& value) const;
        /**
     * @brief Returns the `subitems` property of `NSCollectionLayoutGroup`.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionLayoutItem> subitems() const;
        /**
     * @brief Returns the `supplementaryItems` property of `NSCollectionLayoutGroup`.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionLayoutSupplementaryItem> supplementary_items() const;
        /**
     * @brief Sets the `supplementaryItems` property of `NSCollectionLayoutGroup`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_supplementary_items(const std::vector<CollectionLayoutSupplementaryItem>& value) const;
    };
}
