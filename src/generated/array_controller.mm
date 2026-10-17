#include "generated/array_controller.h"
#include "internal.h"

namespace cocoon
{
    ArrayController::ArrayController() : ArrayController(Adopt{cocoon::internal::retain([[::NSArrayController alloc] init])})
    {
    }

    ArrayController::ArrayController(std::nullptr_t) : ObjectController(nullptr)
    {
    }

    ArrayController::ArrayController(Adopt adopt) : ObjectController(adopt)
    {
    }

    void ArrayController::add(const Object& sender) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) add:cocoon::internal::native_id(sender)];
    }

    void ArrayController::add_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) addObject:cocoon::internal::native_id(object)];
    }

    void ArrayController::add_objects(const std::vector<Object>& objects) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) addObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native_id(e);
                                                                                               })];
    }

    bool ArrayController::add_selected_objects(const std::vector<Object>& objects) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) addSelectedObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                                {
                                                                                                                                    return cocoon::internal::native_id(e);
                                                                                                                                })]);
    }

    bool ArrayController::add_selection_indexes(const IndexSet& indexes) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) addSelectionIndexes:cocoon::internal::native<::NSIndexSet>(indexes)]);
    }

    std::vector<Object> ArrayController::arrange_objects(const std::vector<Object>& objects) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSArrayController>(this) arrangeObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                                               {
                                                                                                                                                   return cocoon::internal::native_id(e);
                                                                                                                                               })],
                                                    [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    void ArrayController::did_change_arrangement_criteria() const
    {
        [cocoon::internal::ns<::NSArrayController>(this) didChangeArrangementCriteria];
    }

    void ArrayController::insert(const Object& sender) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) insert:cocoon::internal::native_id(sender)];
    }

    void ArrayController::insert_object(const Object& object, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) insertObject:cocoon::internal::native_id(object) atArrangedObjectIndex:static_cast<::NSUInteger>(index)];
    }

    void ArrayController::insert_objects(const std::vector<Object>& objects, const IndexSet& indexes) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) insertObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(e);
                                                                                                  })
                                               atArrangedObjectIndexes:cocoon::internal::native<::NSIndexSet>(indexes)];
    }

    void ArrayController::rearrange_objects() const
    {
        [cocoon::internal::ns<::NSArrayController>(this) rearrangeObjects];
    }

    void ArrayController::remove(const Object& sender) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) remove:cocoon::internal::native_id(sender)];
    }

    void ArrayController::remove_object(const Object& object) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) removeObject:cocoon::internal::native_id(object)];
    }

    void ArrayController::remove_object_at_arranged_object_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) removeObjectAtArrangedObjectIndex:static_cast<::NSUInteger>(index)];
    }

    void ArrayController::remove_objects(const std::vector<Object>& objects) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) removeObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(e);
                                                                                                  })];
    }

    void ArrayController::remove_objects_at_arranged_object_indexes(const IndexSet& indexes) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) removeObjectsAtArrangedObjectIndexes:cocoon::internal::native<::NSIndexSet>(indexes)];
    }

    bool ArrayController::remove_selected_objects(const std::vector<Object>& objects) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) removeSelectedObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                                   {
                                                                                                                                       return cocoon::internal::native_id(e);
                                                                                                                                   })]);
    }

    bool ArrayController::remove_selection_indexes(const IndexSet& indexes) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) removeSelectionIndexes:cocoon::internal::native<::NSIndexSet>(indexes)]);
    }

    void ArrayController::select_next(const Object& sender) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) selectNext:cocoon::internal::native_id(sender)];
    }

    void ArrayController::select_previous(const Object& sender) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) selectPrevious:cocoon::internal::native_id(sender)];
    }

    bool ArrayController::set_selected_objects(const std::vector<Object>& objects) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) setSelectedObjects:cocoon::internal::to_array(objects, [](const Object& e) -> id
                                                                                                                                {
                                                                                                                                    return cocoon::internal::native_id(e);
                                                                                                                                })]);
    }

    bool ArrayController::set_selection_index(std::uint64_t index) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) setSelectionIndex:static_cast<::NSUInteger>(index)]);
    }

    bool ArrayController::set_selection_indexes(const IndexSet& indexes) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) setSelectionIndexes:cocoon::internal::native<::NSIndexSet>(indexes)]);
    }

    bool ArrayController::always_uses_multiple_values_marker() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) alwaysUsesMultipleValuesMarker]);
    }

    void ArrayController::set_always_uses_multiple_values_marker(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setAlwaysUsesMultipleValuesMarker:static_cast<::BOOL>(value)];
    }

    Object ArrayController::arranged_objects() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSArrayController>(this) arrangedObjects]);
    }

    std::vector<std::string> ArrayController::automatic_rearrangement_key_paths() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSArrayController>(this) automaticRearrangementKeyPaths], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    bool ArrayController::automatically_rearranges_objects() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) automaticallyRearrangesObjects]);
    }

    void ArrayController::set_automatically_rearranges_objects(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setAutomaticallyRearrangesObjects:static_cast<::BOOL>(value)];
    }

    bool ArrayController::avoids_empty_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) avoidsEmptySelection]);
    }

    void ArrayController::set_avoids_empty_selection(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setAvoidsEmptySelection:static_cast<::BOOL>(value)];
    }

    bool ArrayController::can_insert() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) canInsert]);
    }

    bool ArrayController::can_select_next() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) canSelectNext]);
    }

    bool ArrayController::can_select_previous() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) canSelectPrevious]);
    }

    bool ArrayController::clears_filter_predicate_on_insertion() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) clearsFilterPredicateOnInsertion]);
    }

    void ArrayController::set_clears_filter_predicate_on_insertion(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setClearsFilterPredicateOnInsertion:static_cast<::BOOL>(value)];
    }

    Predicate ArrayController::filter_predicate() const
    {
        return cocoon::internal::wrap<Predicate>([cocoon::internal::ns<::NSArrayController>(this) filterPredicate]);
    }

    void ArrayController::set_filter_predicate(const Predicate& value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setFilterPredicate:cocoon::internal::native<::NSPredicate>(value)];
    }

    bool ArrayController::preserves_selection() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) preservesSelection]);
    }

    void ArrayController::set_preserves_selection(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setPreservesSelection:static_cast<::BOOL>(value)];
    }

    std::vector<Object> ArrayController::selected_objects() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSArrayController>(this) selectedObjects], [](id e) -> Object
                                                    {
                                                        return cocoon::internal::wrap<Object>(e);
                                                    });
    }

    std::uint64_t ArrayController::selection_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSArrayController>(this) selectionIndex]);
    }

    IndexSet ArrayController::selection_indexes() const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSArrayController>(this) selectionIndexes]);
    }

    bool ArrayController::selects_inserted_objects() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSArrayController>(this) selectsInsertedObjects]);
    }

    void ArrayController::set_selects_inserted_objects(bool value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setSelectsInsertedObjects:static_cast<::BOOL>(value)];
    }

    std::vector<SortDescriptor> ArrayController::sort_descriptors() const
    {
        return cocoon::internal::from_array<SortDescriptor>([cocoon::internal::ns<::NSArrayController>(this) sortDescriptors], [](id e) -> SortDescriptor
                                                            {
                                                                return cocoon::internal::wrap<SortDescriptor>((::NSSortDescriptor*)e);
                                                            });
    }

    void ArrayController::set_sort_descriptors(const std::vector<SortDescriptor>& value) const
    {
        [cocoon::internal::ns<::NSArrayController>(this) setSortDescriptors:cocoon::internal::to_array(value, [](const SortDescriptor& e) -> id
                                                                                                       {
                                                                                                           return cocoon::internal::native<::NSSortDescriptor>(e);
                                                                                                       })];
    }
}
