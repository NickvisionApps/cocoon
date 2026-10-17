#include "generated/compound_predicate.h"
#include "internal.h"

namespace cocoon
{
    CompoundPredicate::CompoundPredicate(CompoundPredicateType type, const std::vector<Predicate>& subpredicates) : CompoundPredicate(Adopt{cocoon::internal::retain([[::NSCompoundPredicate alloc] initWithType:static_cast<::NSCompoundPredicateType>(type)
                                                                                                                                                                                     subpredicates:cocoon::internal::to_array(subpredicates, [](const Predicate& e) -> id
                                                                                                                                                                                                                {
                                                                                                                                                                                                                    return cocoon::internal::native<::NSPredicate>(e);
                                                                                                                                                                                                                })])})
    {
    }

    CompoundPredicate::CompoundPredicate() : CompoundPredicate(Adopt{cocoon::internal::retain([[::NSCompoundPredicate alloc] init])})
    {
    }

    CompoundPredicate::CompoundPredicate(std::nullptr_t) : Predicate(nullptr)
    {
    }

    CompoundPredicate::CompoundPredicate(Adopt adopt) : Predicate(adopt)
    {
    }

    CompoundPredicate CompoundPredicate::and_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates)
    {
        return cocoon::internal::wrap<CompoundPredicate>([::NSCompoundPredicate andPredicateWithSubpredicates:cocoon::internal::to_array(subpredicates, [](const Predicate& e) -> id
                                                                                                             {
                                                                                                                 return cocoon::internal::native<::NSPredicate>(e);
                                                                                                             })]);
    }

    CompoundPredicate CompoundPredicate::not_predicate_with_subpredicate(const Predicate& predicate)
    {
        return cocoon::internal::wrap<CompoundPredicate>([::NSCompoundPredicate notPredicateWithSubpredicate:cocoon::internal::native<::NSPredicate>(predicate)]);
    }

    CompoundPredicate CompoundPredicate::or_predicate_with_subpredicates(const std::vector<Predicate>& subpredicates)
    {
        return cocoon::internal::wrap<CompoundPredicate>([::NSCompoundPredicate orPredicateWithSubpredicates:cocoon::internal::to_array(subpredicates, [](const Predicate& e) -> id
                                                                                                            {
                                                                                                                return cocoon::internal::native<::NSPredicate>(e);
                                                                                                            })]);
    }

    CompoundPredicateType CompoundPredicate::compound_predicate_type() const
    {
        return static_cast<CompoundPredicateType>([cocoon::internal::ns<::NSCompoundPredicate>(this) compoundPredicateType]);
    }

    std::vector<Object> CompoundPredicate::subpredicates() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::NSCompoundPredicate>(this) subpredicates], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }
}
