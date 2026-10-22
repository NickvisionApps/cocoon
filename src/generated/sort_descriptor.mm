#include "generated/sort_descriptor.h"
#include "internal.h"

namespace cocoon
{
    SortDescriptor::SortDescriptor(const std::string& key, bool ascending) : SortDescriptor(Adopt{cocoon::internal::retain([[::NSSortDescriptor alloc] initWithKey:cocoon::internal::to(key) ascending:static_cast<::BOOL>(ascending)])})
    {
    }

    SortDescriptor::SortDescriptor(const std::string& key, bool ascending, std::function<ComparisonResult(Object, Object)> cmptr) : SortDescriptor(Adopt{cocoon::internal::retain([[::NSSortDescriptor alloc] initWithKey:cocoon::internal::to(key) ascending:static_cast<::BOOL>(ascending) comparator:(cmptr ? (::NSComparator) ^ ::NSComparisonResult(id a217_0, id a217_1) { auto __r = cmptr(cocoon::internal::wrap<Object>(a217_0), cocoon::internal::wrap<Object>(a217_1)); return static_cast<::NSComparisonResult>(__r); } : (::NSComparator)nil)])})
    {
    }

    SortDescriptor::SortDescriptor(const std::string& key, bool ascending, const std::string& selector) : SortDescriptor(Adopt{cocoon::internal::retain([[::NSSortDescriptor alloc] initWithKey:cocoon::internal::to(key) ascending:static_cast<::BOOL>(ascending) selector:NSSelectorFromString(cocoon::internal::to(selector))])})
    {
    }

    SortDescriptor::SortDescriptor() : SortDescriptor(Adopt{cocoon::internal::retain([[::NSSortDescriptor alloc] init])})
    {
    }

    SortDescriptor::SortDescriptor(std::nullptr_t) : Object(nullptr)
    {
    }

    SortDescriptor::SortDescriptor(Adopt adopt) : Object(adopt)
    {
    }

    void SortDescriptor::allow_evaluation() const
    {
        [cocoon::internal::ns<::NSSortDescriptor>(this) allowEvaluation];
    }

    ComparisonResult SortDescriptor::compare_object(const Object& object1, const Object& object2) const
    {
        return static_cast<ComparisonResult>([cocoon::internal::ns<::NSSortDescriptor>(this) compareObject:cocoon::internal::native_id(object1) toObject:cocoon::internal::native_id(object2)]);
    }

    bool SortDescriptor::ascending() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSSortDescriptor>(this) ascending]);
    }

    std::function<ComparisonResult(Object, Object)> SortDescriptor::comparator() const
    {
        return [&]() -> std::function<ComparisonResult(Object, Object)>
        {
            auto blk = (::NSComparator)([cocoon::internal::ns<::NSSortDescriptor>(this) comparator]);
            if (!blk)
            {
                return {};
            }
            return [blk](Object a219_0, Object a219_1) -> ComparisonResult
            {
                auto __r = blk(cocoon::internal::native_id(a219_0), cocoon::internal::native_id(a219_1));
                return static_cast<ComparisonResult>(__r);
            };
        }();
    }

    std::string SortDescriptor::key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSSortDescriptor>(this) key]);
    }

    Object SortDescriptor::reversed_sort_descriptor() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSSortDescriptor>(this) reversedSortDescriptor]);
    }

    std::string SortDescriptor::selector() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSSortDescriptor>(this) selector]));
    }
}
