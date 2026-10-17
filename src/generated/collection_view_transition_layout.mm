#include "generated/collection_view_transition_layout.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewTransitionLayout::CollectionViewTransitionLayout(const CollectionViewLayout& current_layout, const CollectionViewLayout& new_layout) : CollectionViewTransitionLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewTransitionLayout alloc] initWithCurrentLayout:cocoon::internal::native<::NSCollectionViewLayout>(current_layout) nextLayout:cocoon::internal::native<::NSCollectionViewLayout>(new_layout)])})
    {
    }

    CollectionViewTransitionLayout::CollectionViewTransitionLayout() : CollectionViewTransitionLayout(Adopt{cocoon::internal::retain([[::NSCollectionViewTransitionLayout alloc] init])})
    {
    }

    CollectionViewTransitionLayout::CollectionViewTransitionLayout(std::nullptr_t) : CollectionViewLayout(nullptr)
    {
    }

    CollectionViewTransitionLayout::CollectionViewTransitionLayout(Adopt adopt) : CollectionViewLayout(adopt)
    {
    }

    void CollectionViewTransitionLayout::update_value(double value, const std::string& key) const
    {
        [cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) updateValue:static_cast<::CGFloat>(value) forAnimatedKey:cocoon::internal::to(key)];
    }

    double CollectionViewTransitionLayout::value_for_animated_key(const std::string& key) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) valueForAnimatedKey:cocoon::internal::to(key)]);
    }

    CollectionViewLayout CollectionViewTransitionLayout::current_layout() const
    {
        return cocoon::internal::wrap<CollectionViewLayout>([cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) currentLayout]);
    }

    CollectionViewLayout CollectionViewTransitionLayout::next_layout() const
    {
        return cocoon::internal::wrap<CollectionViewLayout>([cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) nextLayout]);
    }

    double CollectionViewTransitionLayout::transition_progress() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) transitionProgress]);
    }

    void CollectionViewTransitionLayout::set_transition_progress(double value) const
    {
        [cocoon::internal::ns<::NSCollectionViewTransitionLayout>(this) setTransitionProgress:static_cast<::CGFloat>(value)];
    }
}
