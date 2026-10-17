#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDiffableDataSourceSnapshot` (AppKit).
     * @details An NSDiffableDataSourceSnapshot represents the complete state of a UI element (e.g. NSCollectionView) Snapshots can be created in two ways: 1. From a connected data source: e.g. '[diffableDataSource snapshot]' This will contain the current state of the UI element. 2. Constructing a new instance: e.g. '[[NSDiffableDataSourceSnapshot\<Int,UUID> alloc] init]' This will construct an empty snapshot with no section or item identifiers. Notes: 1. All identifiers must be unique. Section and Item identifiers do not overlap and may contain values that exist in the other (i.e. it is OK to have a section identifier == 1 and an item identifier == 1) 2. If you pass duplicate values in an item or section array (e.g. '-appendItemsWithIdentifiers:'), the system will throw an exception.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Use the typed template @ref DiffableDataSourceSnapshot to supply SectionIdentifierType, ItemIdentifierType.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DiffableDataSourceSnapshotBase diffable_data_source_snapshot_base;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DiffableDataSourceSnapshotBase diffable_data_source_snapshot_base{};
     * diffable_data_source_snapshot_base.delete_all_items();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsdiffabledatasourcesnapshot
     */
    class DiffableDataSourceSnapshotBase : public Object
    {
    public:
        /// @brief Creates a new `NSDiffableDataSourceSnapshot` instance and returns a handle to it.
        explicit DiffableDataSourceSnapshotBase();
        /// @brief Creates a null handle that refers to no native object.
        DiffableDataSourceSnapshotBase(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DiffableDataSourceSnapshotBase(Adopt adopt);
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot appendItemsWithIdentifiers:]`.
     * @param identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void append_items_with_identifiers(const std::vector<Object>& identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot appendItemsWithIdentifiers:intoSectionWithIdentifier:]`.
     * @param identifiers Argument converted to the Objective-C parameter of the same role.
     * @param section_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void append_items_with_identifiers(const std::vector<Object>& identifiers, const Object& section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot appendSectionsWithIdentifiers:]`.
     * @param section_identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void append_sections_with_identifiers(const std::vector<Object>& section_identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot deleteAllItems]`.
     */
        void delete_all_items() const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot deleteItemsWithIdentifiers:]`.
     * @param identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void delete_items_with_identifiers(const std::vector<Object>& identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot deleteSectionsWithIdentifiers:]`.
     * @param section_identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void delete_sections_with_identifiers(const std::vector<Object>& section_identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot indexOfItemIdentifier:]`.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_item_identifier(const Object& item_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot indexOfSectionIdentifier:]`.
     * @param section_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t index_of_section_identifier(const Object& section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot insertItemsWithIdentifiers:afterItemWithIdentifier:]`.
     * @param identifiers Argument converted to the Objective-C parameter of the same role.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void insert_items_with_identifiers(const std::vector<Object>& identifiers, const Object& item_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot insertSectionsWithIdentifiers:afterSectionWithIdentifier:]`.
     * @param section_identifiers Argument converted to the Objective-C parameter of the same role.
     * @param to_section_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void insert_sections_with_identifiers(const std::vector<Object>& section_identifiers, const Object& to_section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot itemIdentifiersInSectionWithIdentifier:]`.
     * @param section_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> item_identifiers_in_section_with_identifier(const Object& section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot moveItemWithIdentifier:afterItemWithIdentifier:]`.
     * @param from_identifier Argument converted to the Objective-C parameter of the same role.
     * @param to_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void move_item_with_identifier(const Object& from_identifier, const Object& to_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot moveSectionWithIdentifier:afterSectionWithIdentifier:]`.
     * @param from_section_identifier Argument converted to the Objective-C parameter of the same role.
     * @param to_section_identifier Argument converted to the Objective-C parameter of the same role.
     */
        void move_section_with_identifier(const Object& from_section_identifier, const Object& to_section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot numberOfItemsInSection:]`.
     * @param section_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items_in_section(const Object& section_identifier) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot reloadItemsWithIdentifiers:]`.
     * @param identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void reload_items_with_identifiers(const std::vector<Object>& identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot reloadSectionsWithIdentifiers:]`.
     * @param section_identifiers Argument converted to the Objective-C parameter of the same role.
     */
        void reload_sections_with_identifiers(const std::vector<Object>& section_identifiers) const;
        /**
     * @brief Calls `-[NSDiffableDataSourceSnapshot sectionIdentifierForSectionContainingItemIdentifier:]`.
     * @param item_identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object section_identifier_for_section_containing_item_identifier(const Object& item_identifier) const;
        /**
     * @brief Returns the `itemIdentifiers` property of `NSDiffableDataSourceSnapshot`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> item_identifiers() const;
        /**
     * @brief Returns the `numberOfItems` property of `NSDiffableDataSourceSnapshot`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_items() const;
        /**
     * @brief Returns the `numberOfSections` property of `NSDiffableDataSourceSnapshot`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_sections() const;
        /**
     * @brief Returns the `sectionIdentifiers` property of `NSDiffableDataSourceSnapshot`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> section_identifiers() const;
    };

    template <class SectionIdentifierType, class ItemIdentifierType>
    class DiffableDataSourceSnapshot : public DiffableDataSourceSnapshotBase
    {
    public:
        using DiffableDataSourceSnapshotBase::DiffableDataSourceSnapshotBase;
        DiffableDataSourceSnapshot() : DiffableDataSourceSnapshotBase()
        {
        }
        DiffableDataSourceSnapshot(const DiffableDataSourceSnapshotBase& other) : DiffableDataSourceSnapshotBase(other)
        {
        }
        using DiffableDataSourceSnapshotBase::append_items_with_identifiers;
        using DiffableDataSourceSnapshotBase::append_sections_with_identifiers;
        using DiffableDataSourceSnapshotBase::delete_all_items;
        using DiffableDataSourceSnapshotBase::delete_items_with_identifiers;
        using DiffableDataSourceSnapshotBase::delete_sections_with_identifiers;
        using DiffableDataSourceSnapshotBase::index_of_item_identifier;
        using DiffableDataSourceSnapshotBase::index_of_section_identifier;
        using DiffableDataSourceSnapshotBase::insert_items_with_identifiers;
        using DiffableDataSourceSnapshotBase::insert_sections_with_identifiers;
        using DiffableDataSourceSnapshotBase::item_identifiers;
        using DiffableDataSourceSnapshotBase::item_identifiers_in_section_with_identifier;
        using DiffableDataSourceSnapshotBase::move_item_with_identifier;
        using DiffableDataSourceSnapshotBase::move_section_with_identifier;
        using DiffableDataSourceSnapshotBase::number_of_items;
        using DiffableDataSourceSnapshotBase::number_of_items_in_section;
        using DiffableDataSourceSnapshotBase::number_of_sections;
        using DiffableDataSourceSnapshotBase::reload_items_with_identifiers;
        using DiffableDataSourceSnapshotBase::reload_sections_with_identifiers;
        using DiffableDataSourceSnapshotBase::section_identifier_for_section_containing_item_identifier;
        using DiffableDataSourceSnapshotBase::section_identifiers;
        auto append_items_with_identifiers(const std::vector<ItemIdentifierType>& identifiers) const
        {
            DiffableDataSourceSnapshotBase::append_items_with_identifiers(cocoon::box_all(identifiers));
        }
        auto append_items_with_identifiers(const std::vector<ItemIdentifierType>& identifiers, const SectionIdentifierType& section_identifier) const
        {
            DiffableDataSourceSnapshotBase::append_items_with_identifiers(cocoon::box_all(identifiers), cocoon::box(section_identifier));
        }
        auto append_sections_with_identifiers(const std::vector<SectionIdentifierType>& section_identifiers) const
        {
            DiffableDataSourceSnapshotBase::append_sections_with_identifiers(cocoon::box_all(section_identifiers));
        }
        auto delete_items_with_identifiers(const std::vector<ItemIdentifierType>& identifiers) const
        {
            DiffableDataSourceSnapshotBase::delete_items_with_identifiers(cocoon::box_all(identifiers));
        }
        auto delete_sections_with_identifiers(const std::vector<SectionIdentifierType>& section_identifiers) const
        {
            DiffableDataSourceSnapshotBase::delete_sections_with_identifiers(cocoon::box_all(section_identifiers));
        }
        auto index_of_item_identifier(const ItemIdentifierType& item_identifier) const
        {
            return DiffableDataSourceSnapshotBase::index_of_item_identifier(cocoon::box(item_identifier));
        }
        auto index_of_section_identifier(const SectionIdentifierType& section_identifier) const
        {
            return DiffableDataSourceSnapshotBase::index_of_section_identifier(cocoon::box(section_identifier));
        }
        auto insert_items_with_identifiers(const std::vector<ItemIdentifierType>& identifiers, const ItemIdentifierType& item_identifier) const
        {
            DiffableDataSourceSnapshotBase::insert_items_with_identifiers(cocoon::box_all(identifiers), cocoon::box(item_identifier));
        }
        auto insert_sections_with_identifiers(const std::vector<SectionIdentifierType>& section_identifiers, const SectionIdentifierType& to_section_identifier) const
        {
            DiffableDataSourceSnapshotBase::insert_sections_with_identifiers(cocoon::box_all(section_identifiers), cocoon::box(to_section_identifier));
        }
        auto item_identifiers_in_section_with_identifier(const SectionIdentifierType& section_identifier) const
        {
            return cocoon::unbox_all<ItemIdentifierType>(DiffableDataSourceSnapshotBase::item_identifiers_in_section_with_identifier(cocoon::box(section_identifier)));
        }
        auto move_item_with_identifier(const ItemIdentifierType& from_identifier, const ItemIdentifierType& to_identifier) const
        {
            DiffableDataSourceSnapshotBase::move_item_with_identifier(cocoon::box(from_identifier), cocoon::box(to_identifier));
        }
        auto move_section_with_identifier(const SectionIdentifierType& from_section_identifier, const SectionIdentifierType& to_section_identifier) const
        {
            DiffableDataSourceSnapshotBase::move_section_with_identifier(cocoon::box(from_section_identifier), cocoon::box(to_section_identifier));
        }
        auto number_of_items_in_section(const SectionIdentifierType& section_identifier) const
        {
            return DiffableDataSourceSnapshotBase::number_of_items_in_section(cocoon::box(section_identifier));
        }
        auto reload_items_with_identifiers(const std::vector<ItemIdentifierType>& identifiers) const
        {
            DiffableDataSourceSnapshotBase::reload_items_with_identifiers(cocoon::box_all(identifiers));
        }
        auto reload_sections_with_identifiers(const std::vector<SectionIdentifierType>& section_identifiers) const
        {
            DiffableDataSourceSnapshotBase::reload_sections_with_identifiers(cocoon::box_all(section_identifiers));
        }
        auto section_identifier_for_section_containing_item_identifier(const ItemIdentifierType& item_identifier) const
        {
            return cocoon::unbox<SectionIdentifierType>(DiffableDataSourceSnapshotBase::section_identifier_for_section_containing_item_identifier(cocoon::box(item_identifier)));
        }
        auto item_identifiers() const
        {
            return cocoon::unbox_all<ItemIdentifierType>(DiffableDataSourceSnapshotBase::item_identifiers());
        }
        auto section_identifiers() const
        {
            return cocoon::unbox_all<SectionIdentifierType>(DiffableDataSourceSnapshotBase::section_identifiers());
        }
    };
}
