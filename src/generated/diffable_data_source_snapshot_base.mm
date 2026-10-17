#include "generated/diffable_data_source_snapshot_base.h"
#include "internal.h"

namespace cocoon
{
    DiffableDataSourceSnapshotBase::DiffableDataSourceSnapshotBase() : DiffableDataSourceSnapshotBase(Adopt{cocoon::internal::retain([[::NSDiffableDataSourceSnapshot alloc] init])})
    {
    }

    DiffableDataSourceSnapshotBase::DiffableDataSourceSnapshotBase(std::nullptr_t) : Object(nullptr)
    {
    }

    DiffableDataSourceSnapshotBase::DiffableDataSourceSnapshotBase(Adopt adopt) : Object(adopt)
    {
    }

    void DiffableDataSourceSnapshotBase::append_items_with_identifiers(const std::vector<Object>& identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) appendItemsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })];
    }

    void DiffableDataSourceSnapshotBase::append_items_with_identifiers(const std::vector<Object>& identifiers, const Object& section_identifier) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) appendItemsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })
                                                       intoSectionWithIdentifier:cocoon::internal::native_id(section_identifier)];
    }

    void DiffableDataSourceSnapshotBase::append_sections_with_identifiers(const std::vector<Object>& section_identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) appendSectionsWithIdentifiers:cocoon::internal::to_array(section_identifiers, [](const Object& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(e);
                                                                                                 })];
    }

    void DiffableDataSourceSnapshotBase::delete_all_items() const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) deleteAllItems];
    }

    void DiffableDataSourceSnapshotBase::delete_items_with_identifiers(const std::vector<Object>& identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) deleteItemsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })];
    }

    void DiffableDataSourceSnapshotBase::delete_sections_with_identifiers(const std::vector<Object>& section_identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) deleteSectionsWithIdentifiers:cocoon::internal::to_array(section_identifiers, [](const Object& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(e);
                                                                                                 })];
    }

    std::int64_t DiffableDataSourceSnapshotBase::index_of_item_identifier(const Object& item_identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) indexOfItemIdentifier:cocoon::internal::native_id(item_identifier)]);
    }

    std::int64_t DiffableDataSourceSnapshotBase::index_of_section_identifier(const Object& section_identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) indexOfSectionIdentifier:cocoon::internal::native_id(section_identifier)]);
    }

    void DiffableDataSourceSnapshotBase::insert_items_with_identifiers(const std::vector<Object>& identifiers, const Object& item_identifier) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) insertItemsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })
                                                         afterItemWithIdentifier:cocoon::internal::native_id(item_identifier)];
    }

    void DiffableDataSourceSnapshotBase::insert_sections_with_identifiers(const std::vector<Object>& section_identifiers, const Object& to_section_identifier) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) insertSectionsWithIdentifiers:cocoon::internal::to_array(section_identifiers, [](const Object& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(e);
                                                                                                 })
                                                         afterSectionWithIdentifier:cocoon::internal::native_id(to_section_identifier)];
    }

    std::vector<Object> DiffableDataSourceSnapshotBase::item_identifiers_in_section_with_identifier(const Object& section_identifier) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) itemIdentifiersInSectionWithIdentifier:cocoon::internal::native_id(section_identifier)], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void DiffableDataSourceSnapshotBase::move_item_with_identifier(const Object& from_identifier, const Object& to_identifier) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) moveItemWithIdentifier:cocoon::internal::native_id(from_identifier) afterItemWithIdentifier:cocoon::internal::native_id(to_identifier)];
    }

    void DiffableDataSourceSnapshotBase::move_section_with_identifier(const Object& from_section_identifier, const Object& to_section_identifier) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) moveSectionWithIdentifier:cocoon::internal::native_id(from_section_identifier) afterSectionWithIdentifier:cocoon::internal::native_id(to_section_identifier)];
    }

    std::int64_t DiffableDataSourceSnapshotBase::number_of_items_in_section(const Object& section_identifier) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) numberOfItemsInSection:cocoon::internal::native_id(section_identifier)]);
    }

    void DiffableDataSourceSnapshotBase::reload_items_with_identifiers(const std::vector<Object>& identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) reloadItemsWithIdentifiers:cocoon::internal::to_array(identifiers, [](const Object& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native_id(e);
                                                                                              })];
    }

    void DiffableDataSourceSnapshotBase::reload_sections_with_identifiers(const std::vector<Object>& section_identifiers) const
    {
        [cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) reloadSectionsWithIdentifiers:cocoon::internal::to_array(section_identifiers, [](const Object& e) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(e);
                                                                                                 })];
    }

    Object DiffableDataSourceSnapshotBase::section_identifier_for_section_containing_item_identifier(const Object& item_identifier) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) sectionIdentifierForSectionContainingItemIdentifier:cocoon::internal::native_id(item_identifier)]);
    }

    std::vector<Object> DiffableDataSourceSnapshotBase::item_identifiers() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) itemIdentifiers], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::int64_t DiffableDataSourceSnapshotBase::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) numberOfItems]);
    }

    std::int64_t DiffableDataSourceSnapshotBase::number_of_sections() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) numberOfSections]);
    }

    std::vector<Object> DiffableDataSourceSnapshotBase::section_identifiers() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSDiffableDataSourceSnapshot>(this) sectionIdentifiers], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }
}
