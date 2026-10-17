#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutBoundarySupplementaryItem;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewCompositionalLayoutConfiguration` (AppKit).
     * @details End temporary declarations
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewCompositionalLayoutConfiguration collection_view_compositional_layout_configuration;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewCompositionalLayoutConfiguration collection_view_compositional_layout_configuration{};
     * collection_view_compositional_layout_configuration.set_inter_section_spacing(1);
     * auto inter_section_spacing = collection_view_compositional_layout_configuration.inter_section_spacing();
     * collection_view_compositional_layout_configuration.set_scroll_direction(cocoon::CollectionViewScrollDirection::Vertical);
     * auto scroll_direction = collection_view_compositional_layout_configuration.scroll_direction();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewcompositionallayoutconfiguration
     */
    class CollectionViewCompositionalLayoutConfiguration : public Object
    {
    public:
        /// @brief Creates a new `NSCollectionViewCompositionalLayoutConfiguration` instance and returns a handle to it.
        explicit CollectionViewCompositionalLayoutConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewCompositionalLayoutConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewCompositionalLayoutConfiguration(Adopt adopt);
        /**
     * @brief Returns the `boundarySupplementaryItems` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @return The converted Objective-C result.
     */
        std::vector<CollectionLayoutBoundarySupplementaryItem> boundary_supplementary_items() const;
        /**
     * @brief Sets the `boundarySupplementaryItems` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_boundary_supplementary_items(const std::vector<CollectionLayoutBoundarySupplementaryItem>& value) const;
        /**
     * @brief Returns the `interSectionSpacing` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @return The converted Objective-C result.
     */
        double inter_section_spacing() const;
        /**
     * @brief Sets the `interSectionSpacing` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_inter_section_spacing(double value) const;
        /**
     * @brief Returns the `scrollDirection` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @return The converted Objective-C result.
     */
        CollectionViewScrollDirection scroll_direction() const;
        /**
     * @brief Sets the `scrollDirection` property of `NSCollectionViewCompositionalLayoutConfiguration`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scroll_direction(CollectionViewScrollDirection value) const;
    };
}
