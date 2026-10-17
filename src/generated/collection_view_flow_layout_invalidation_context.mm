#include "generated/collection_view_flow_layout_invalidation_context.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewFlowLayoutInvalidationContext::CollectionViewFlowLayoutInvalidationContext() : CollectionViewFlowLayoutInvalidationContext(Adopt{cocoon::internal::retain([[::NSCollectionViewFlowLayoutInvalidationContext alloc] init])})
    {
    }

    CollectionViewFlowLayoutInvalidationContext::CollectionViewFlowLayoutInvalidationContext(std::nullptr_t) : CollectionViewLayoutInvalidationContext(nullptr)
    {
    }

    CollectionViewFlowLayoutInvalidationContext::CollectionViewFlowLayoutInvalidationContext(Adopt adopt) : CollectionViewLayoutInvalidationContext(adopt)
    {
    }

    bool CollectionViewFlowLayoutInvalidationContext::invalidate_flow_layout_attributes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewFlowLayoutInvalidationContext>(this) invalidateFlowLayoutAttributes]);
    }

    void CollectionViewFlowLayoutInvalidationContext::set_invalidate_flow_layout_attributes(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayoutInvalidationContext>(this) setInvalidateFlowLayoutAttributes:static_cast<::BOOL>(value)];
    }

    bool CollectionViewFlowLayoutInvalidationContext::invalidate_flow_layout_delegate_metrics() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewFlowLayoutInvalidationContext>(this) invalidateFlowLayoutDelegateMetrics]);
    }

    void CollectionViewFlowLayoutInvalidationContext::set_invalidate_flow_layout_delegate_metrics(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewFlowLayoutInvalidationContext>(this) setInvalidateFlowLayoutDelegateMetrics:static_cast<::BOOL>(value)];
    }
}
