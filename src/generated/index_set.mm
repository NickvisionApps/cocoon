#include "generated/index_set.h"
#include "internal.h"

namespace cocoon
{
    IndexSet::IndexSet(std::uint64_t value) : IndexSet(Adopt{cocoon::internal::retain([[::NSIndexSet alloc] initWithIndex:static_cast<::NSUInteger>(value)])})
    {
    }

    IndexSet::IndexSet(const Range& range) : IndexSet(Adopt{cocoon::internal::retain([[::NSIndexSet alloc] initWithIndexesInRange:cocoon::internal::to(range)])})
    {
    }

    IndexSet::IndexSet() : IndexSet(Adopt{cocoon::internal::retain([::NSIndexSet indexSet])})
    {
    }

    IndexSet::IndexSet(std::nullptr_t) : Object(nullptr)
    {
    }

    IndexSet::IndexSet(Adopt adopt) : Object(adopt)
    {
    }

    bool IndexSet::contains_index(std::uint64_t value) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSIndexSet>(this) containsIndex:static_cast<::NSUInteger>(value)]);
    }

    bool IndexSet::contains_indexes(const IndexSet& index_set) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSIndexSet>(this) containsIndexes:cocoon::internal::native<::NSIndexSet>(index_set)]);
    }

    bool IndexSet::contains_indexes_in_range(const Range& range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSIndexSet>(this) containsIndexesInRange:cocoon::internal::to(range)]);
    }

    std::uint64_t IndexSet::count_of_indexes_in_range(const Range& range) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) countOfIndexesInRange:cocoon::internal::to(range)]);
    }

    void IndexSet::enumerate_indexes_in_range(const Range& range, EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateIndexesInRange:cocoon::internal::to(range) options:static_cast<::NSEnumerationOptions>(opts) usingBlock:(block ? (void (^)(::NSUInteger, BOOL*)) ^ void(::NSUInteger a157_0, ::BOOL * a157_1) { bool __o157_1 = a157_1 ? static_cast<bool>(*a157_1) : bool(); block(static_cast<std::uint64_t>(a157_0), __o157_1); if (a157_1) { *a157_1 = static_cast<::BOOL>(__o157_1); } } : (void (^)(::NSUInteger, BOOL*))nil)];
    }

    void IndexSet::enumerate_indexes_using_block(std::function<void(std::uint64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateIndexesUsingBlock:(block ? (void (^)(::NSUInteger, BOOL*)) ^ void(::NSUInteger a158_0, ::BOOL * a158_1) { bool __o158_1 = a158_1 ? static_cast<bool>(*a158_1) : bool(); block(static_cast<std::uint64_t>(a158_0), __o158_1); if (a158_1) { *a158_1 = static_cast<::BOOL>(__o158_1); } } : (void (^)(::NSUInteger, BOOL*))nil)];
    }

    void IndexSet::enumerate_indexes_with_options(EnumerationOptions opts, std::function<void(std::uint64_t, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateIndexesWithOptions:static_cast<::NSEnumerationOptions>(opts) usingBlock:(block ? (void (^)(::NSUInteger, BOOL*)) ^ void(::NSUInteger a159_0, ::BOOL * a159_1) { bool __o159_1 = a159_1 ? static_cast<bool>(*a159_1) : bool(); block(static_cast<std::uint64_t>(a159_0), __o159_1); if (a159_1) { *a159_1 = static_cast<::BOOL>(__o159_1); } } : (void (^)(::NSUInteger, BOOL*))nil)];
    }

    void IndexSet::enumerate_ranges_in_range(const Range& range, EnumerationOptions opts, std::function<void(Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateRangesInRange:cocoon::internal::to(range) options:static_cast<::NSEnumerationOptions>(opts) usingBlock:(block ? (void (^)(::NSRange, BOOL*)) ^ void(::NSRange a160_0, ::BOOL * a160_1) { bool __o160_1 = a160_1 ? static_cast<bool>(*a160_1) : bool(); block(cocoon::internal::from(a160_0), __o160_1); if (a160_1) { *a160_1 = static_cast<::BOOL>(__o160_1); } } : (void (^)(::NSRange, BOOL*))nil)];
    }

    void IndexSet::enumerate_ranges_using_block(std::function<void(Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateRangesUsingBlock:(block ? (void (^)(::NSRange, BOOL*)) ^ void(::NSRange a161_0, ::BOOL * a161_1) { bool __o161_1 = a161_1 ? static_cast<bool>(*a161_1) : bool(); block(cocoon::internal::from(a161_0), __o161_1); if (a161_1) { *a161_1 = static_cast<::BOOL>(__o161_1); } } : (void (^)(::NSRange, BOOL*))nil)];
    }

    void IndexSet::enumerate_ranges_with_options(EnumerationOptions opts, std::function<void(Range, bool&)> block) const
    {
        [cocoon::internal::ns<::NSIndexSet>(this) enumerateRangesWithOptions:static_cast<::NSEnumerationOptions>(opts) usingBlock:(block ? (void (^)(::NSRange, BOOL*)) ^ void(::NSRange a162_0, ::BOOL * a162_1) { bool __o162_1 = a162_1 ? static_cast<bool>(*a162_1) : bool(); block(cocoon::internal::from(a162_0), __o162_1); if (a162_1) { *a162_1 = static_cast<::BOOL>(__o162_1); } } : (void (^)(::NSRange, BOOL*))nil)];
    }

    std::uint64_t IndexSet::get_indexes(std::uint64_t* index_buffer, std::uint64_t buffer_size, Range* range) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) getIndexes:(::NSUInteger*)(index_buffer) maxCount:static_cast<::NSUInteger>(buffer_size) inIndexRange:(::NSRangePointer)(range)]);
    }

    std::uint64_t IndexSet::index_greater_than_index(std::uint64_t value) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexGreaterThanIndex:static_cast<::NSUInteger>(value)]);
    }

    std::uint64_t IndexSet::index_greater_than_or_equal_to_index(std::uint64_t value) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexGreaterThanOrEqualToIndex:static_cast<::NSUInteger>(value)]);
    }

    std::uint64_t IndexSet::index_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexInRange:cocoon::internal::to(range) options:static_cast<::NSEnumerationOptions>(opts) passingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a163_0, ::BOOL * a163_1) { bool __o163_1 = a163_1 ? static_cast<bool>(*a163_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a163_0), __o163_1); if (a163_1) { *a163_1 = static_cast<::BOOL>(__o163_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    std::uint64_t IndexSet::index_less_than_index(std::uint64_t value) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexLessThanIndex:static_cast<::NSUInteger>(value)]);
    }

    std::uint64_t IndexSet::index_less_than_or_equal_to_index(std::uint64_t value) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexLessThanOrEqualToIndex:static_cast<::NSUInteger>(value)]);
    }

    std::uint64_t IndexSet::index_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexPassingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a164_0, ::BOOL * a164_1) { bool __o164_1 = a164_1 ? static_cast<bool>(*a164_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a164_0), __o164_1); if (a164_1) { *a164_1 = static_cast<::BOOL>(__o164_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    std::uint64_t IndexSet::index_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) indexWithOptions:static_cast<::NSEnumerationOptions>(opts) passingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a165_0, ::BOOL * a165_1) { bool __o165_1 = a165_1 ? static_cast<bool>(*a165_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a165_0), __o165_1); if (a165_1) { *a165_1 = static_cast<::BOOL>(__o165_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    IndexSet IndexSet::indexes_in_range(const Range& range, EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSIndexSet>(this) indexesInRange:cocoon::internal::to(range) options:static_cast<::NSEnumerationOptions>(opts) passingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a166_0, ::BOOL * a166_1) { bool __o166_1 = a166_1 ? static_cast<bool>(*a166_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a166_0), __o166_1); if (a166_1) { *a166_1 = static_cast<::BOOL>(__o166_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    IndexSet IndexSet::indexes_passing_test(std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSIndexSet>(this) indexesPassingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a167_0, ::BOOL * a167_1) { bool __o167_1 = a167_1 ? static_cast<bool>(*a167_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a167_0), __o167_1); if (a167_1) { *a167_1 = static_cast<::BOOL>(__o167_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    IndexSet IndexSet::indexes_with_options(EnumerationOptions opts, std::function<bool(std::uint64_t, bool&)> predicate) const
    {
        return cocoon::internal::wrap<IndexSet>([cocoon::internal::ns<::NSIndexSet>(this) indexesWithOptions:static_cast<::NSEnumerationOptions>(opts) passingTest:(predicate ? (BOOL(^)(::NSUInteger, BOOL*)) ^ ::BOOL(::NSUInteger a168_0, ::BOOL * a168_1) { bool __o168_1 = a168_1 ? static_cast<bool>(*a168_1) : bool(); auto __r = predicate(static_cast<std::uint64_t>(a168_0), __o168_1); if (a168_1) { *a168_1 = static_cast<::BOOL>(__o168_1); } return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSUInteger, BOOL*))nil)]);
    }

    bool IndexSet::intersects_indexes_in_range(const Range& range) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSIndexSet>(this) intersectsIndexesInRange:cocoon::internal::to(range)]);
    }

    bool IndexSet::is_equal_to_index_set(const IndexSet& index_set) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSIndexSet>(this) isEqualToIndexSet:cocoon::internal::native<::NSIndexSet>(index_set)]);
    }

    std::uint64_t IndexSet::count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) count]);
    }

    std::uint64_t IndexSet::first_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) firstIndex]);
    }

    std::uint64_t IndexSet::last_index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSIndexSet>(this) lastIndex]);
    }
}
