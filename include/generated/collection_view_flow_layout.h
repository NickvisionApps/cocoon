#pragma once

#include "generated/availability.h"
#include "generated/collection_view_layout.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewFlowLayout` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionViewLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewFlowLayout collection_view_flow_layout;
     * collection_view_flow_layout.set_estimated_item_size({100, 100});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewFlowLayout collection_view_flow_layout{};
     * collection_view_flow_layout.set_estimated_item_size({100, 100});
     * auto estimated_item_size = collection_view_flow_layout.estimated_item_size();
     * collection_view_flow_layout.set_footer_reference_size({100, 100});
     * auto footer_reference_size = collection_view_flow_layout.footer_reference_size();
     * collection_view_flow_layout.set_header_reference_size({100, 100});
     * auto header_reference_size = collection_view_flow_layout.header_reference_size();
     * collection_view_flow_layout.collapse_section_at_index(1);
     * collection_view_flow_layout.expand_section_at_index(1);
     * collection_view_flow_layout.section_at_index_is_collapsed(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewflowlayout
     */
    class CollectionViewFlowLayout : public CollectionViewLayout
    {
    public:
        /// @brief Creates a new `NSCollectionViewFlowLayout` instance and returns a handle to it.
        explicit CollectionViewFlowLayout();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewFlowLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewFlowLayout(Adopt adopt);
        /**
     * @brief Calls `-[NSCollectionViewFlowLayout collapseSectionAtIndex:]`.
     * @details Collapses the specified section to a single row, if it is not already collapsed.
     * @param section_index Argument converted to the Objective-C parameter of the same role.
     */
        void collapse_section_at_index(std::uint64_t section_index) const;
        /**
     * @brief Calls `-[NSCollectionViewFlowLayout expandSectionAtIndex:]`.
     * @details Un-collapses the specified section, if it is currently collapsed.
     * @param section_index Argument converted to the Objective-C parameter of the same role.
     */
        void expand_section_at_index(std::uint64_t section_index) const;
        /**
     * @brief Calls `-[NSCollectionViewFlowLayout sectionAtIndexIsCollapsed:]`.
     * @details Returns YES if the specified section is currently collapsed; NO if not, or if there is no such section. Defaults to NO.
     * @param section_index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool section_at_index_is_collapsed(std::uint64_t section_index) const;
        /**
     * @brief Returns the `estimatedItemSize` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        Size estimated_item_size() const;
        /**
     * @brief Sets the `estimatedItemSize` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_estimated_item_size(const Size& value) const;
        /**
     * @brief Returns the `footerReferenceSize` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        Size footer_reference_size() const;
        /**
     * @brief Sets the `footerReferenceSize` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_footer_reference_size(const Size& value) const;
        /**
     * @brief Returns the `headerReferenceSize` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        Size header_reference_size() const;
        /**
     * @brief Sets the `headerReferenceSize` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_header_reference_size(const Size& value) const;
        /**
     * @brief Returns the `itemSize` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        Size item_size() const;
        /**
     * @brief Sets the `itemSize` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_item_size(const Size& value) const;
        /**
     * @brief Returns the `minimumInteritemSpacing` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        double minimum_interitem_spacing() const;
        /**
     * @brief Sets the `minimumInteritemSpacing` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_interitem_spacing(double value) const;
        /**
     * @brief Returns the `minimumLineSpacing` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        double minimum_line_spacing() const;
        /**
     * @brief Sets the `minimumLineSpacing` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_minimum_line_spacing(double value) const;
        /**
     * @brief Returns the `scrollDirection` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        CollectionViewScrollDirection scroll_direction() const;
        /**
     * @brief Sets the `scrollDirection` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scroll_direction(CollectionViewScrollDirection value) const;
        /**
     * @brief Returns the `sectionFootersPinToVisibleBounds` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        bool section_footers_pin_to_visible_bounds() const;
        /**
     * @brief Sets the `sectionFootersPinToVisibleBounds` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_section_footers_pin_to_visible_bounds(bool value) const;
        /**
     * @brief Returns the `sectionHeadersPinToVisibleBounds` property of `NSCollectionViewFlowLayout`.
     * @details Set these properties to YES to get headers that pin to the top of the visible area and footers that pin to the bottom while scrolling. Archived with the layout's other persistent properties. Enabling this feature may affect the parenting of header and footer views.
     * @return The converted Objective-C result.
     */
        bool section_headers_pin_to_visible_bounds() const;
        /**
     * @brief Sets the `sectionHeadersPinToVisibleBounds` property of `NSCollectionViewFlowLayout`.
     * @details Set these properties to YES to get headers that pin to the top of the visible area and footers that pin to the bottom while scrolling. Archived with the layout's other persistent properties. Enabling this feature may affect the parenting of header and footer views.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_section_headers_pin_to_visible_bounds(bool value) const;
        /**
     * @brief Returns the `sectionInset` property of `NSCollectionViewFlowLayout`.
     * @return The converted Objective-C result.
     */
        Insets section_inset() const;
        /**
     * @brief Sets the `sectionInset` property of `NSCollectionViewFlowLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_section_inset(const Insets& value) const;
    };
}
