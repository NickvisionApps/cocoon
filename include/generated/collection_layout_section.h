#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutBoundarySupplementaryItem;
    class CollectionLayoutDecorationItem;
    class CollectionLayoutGroup;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionLayoutSection` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionLayoutSection collection_layout_section(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionLayoutSection collection_layout_section(nullptr);
     * collection_layout_section.set_inter_group_spacing(1);
     * auto inter_group_spacing = collection_layout_section.inter_group_spacing();
     * collection_layout_section.set_orthogonal_scrolling_behavior(cocoon::CollectionLayoutSectionOrthogonalScrollingBehavior::None);
     * auto orthogonal_scrolling_behavior = collection_layout_section.orthogonal_scrolling_behavior();
     * collection_layout_section.set_supplementaries_follow_content_insets(true);
     * auto supplementaries_follow_content_insets = collection_layout_section.supplementaries_follow_content_insets();
     * auto made_0 = cocoon::CollectionLayoutSection::section_with_group(cocoon::CollectionLayoutGroup());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionlayoutsection
     */
    class CollectionLayoutSection : public Object
    {
    public:
        CollectionLayoutSection();
        /// @brief Creates a null handle that refers to no native object.
        CollectionLayoutSection(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionLayoutSection(Adopt adopt);
        /**
     * @brief Calls `+[NSCollectionLayoutSection sectionWithGroup:]`.
     * @param group Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CollectionLayoutSection section_with_group(const CollectionLayoutGroup& group);
        /**
     * @brief Returns the `boundarySupplementaryItems` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionLayoutBoundarySupplementaryItem> boundary_supplementary_items() const;
        /**
     * @brief Sets the `boundarySupplementaryItems` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_boundary_supplementary_items(const std::vector<CollectionLayoutBoundarySupplementaryItem>& value) const;
        /**
     * @brief Returns the `contentInsets` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        DirectionalEdgeInsets content_insets() const;
        /**
     * @brief Sets the `contentInsets` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_content_insets(const DirectionalEdgeInsets& value) const;
        /**
     * @brief Returns the `decorationItems` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionLayoutDecorationItem> decoration_items() const;
        /**
     * @brief Sets the `decorationItems` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_decoration_items(const std::vector<CollectionLayoutDecorationItem>& value) const;
        /**
     * @brief Returns the `interGroupSpacing` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        double inter_group_spacing() const;
        /**
     * @brief Sets the `interGroupSpacing` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_inter_group_spacing(double value) const;
        /**
     * @brief Returns the `orthogonalScrollingBehavior` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        CollectionLayoutSectionOrthogonalScrollingBehavior orthogonal_scrolling_behavior() const;
        /**
     * @brief Sets the `orthogonalScrollingBehavior` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_orthogonal_scrolling_behavior(CollectionLayoutSectionOrthogonalScrollingBehavior value) const;
        /**
     * @brief Returns the `supplementariesFollowContentInsets` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        bool supplementaries_follow_content_insets() const;
        /**
     * @brief Sets the `supplementariesFollowContentInsets` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_supplementaries_follow_content_insets(bool value) const;
        /**
     * @brief Returns the `visibleItemsInvalidationHandler` property of `NSCollectionLayoutSection`.
     * @return The converted Objective-C result.
     */
        std::function<void(std::vector<Object>, Point, Object)> visible_items_invalidation_handler() const;
        /**
     * @brief Sets the `visibleItemsInvalidationHandler` property of `NSCollectionLayoutSection`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_visible_items_invalidation_handler(std::function<void(std::vector<Object>, Point, Object)> value) const;
    };
}
