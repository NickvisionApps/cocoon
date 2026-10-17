#include "generated/collection_view_item.h"
#include "internal.h"

namespace cocoon
{
    CollectionViewItem::CollectionViewItem() : CollectionViewItem(Adopt{cocoon::internal::retain([[::NSCollectionViewItem alloc] init])})
    {
    }

    CollectionViewItem::CollectionViewItem(std::nullptr_t) : ViewController(nullptr)
    {
    }

    CollectionViewItem::CollectionViewItem(Adopt adopt) : ViewController(adopt)
    {
    }

    CollectionView CollectionViewItem::collection_view() const
    {
        return cocoon::internal::wrap<CollectionView>([cocoon::internal::ns<::NSCollectionViewItem>(this) collectionView]);
    }

    std::vector<DraggingImageComponent> CollectionViewItem::dragging_image_components() const
    {
        return cocoon::internal::from_array<DraggingImageComponent>([cocoon::internal::ns<::NSCollectionViewItem>(this) draggingImageComponents], [](id e) -> DraggingImageComponent
                                                                    {
                                                                        return cocoon::internal::wrap<DraggingImageComponent>((::NSDraggingImageComponent*)e);
                                                                    });
    }

    CollectionViewItemHighlightState CollectionViewItem::highlight_state() const
    {
        return static_cast<CollectionViewItemHighlightState>([cocoon::internal::ns<::NSCollectionViewItem>(this) highlightState]);
    }

    void CollectionViewItem::set_highlight_state(CollectionViewItemHighlightState value) const
    {
        [cocoon::internal::ns<::NSCollectionViewItem>(this) setHighlightState:static_cast<::NSCollectionViewItemHighlightState>(value)];
    }

    ImageView CollectionViewItem::image_view() const
    {
        return cocoon::internal::wrap<ImageView>([cocoon::internal::ns<::NSCollectionViewItem>(this) imageView]);
    }

    void CollectionViewItem::set_image_view(const ImageView& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewItem>(this) setImageView:cocoon::internal::native<::NSImageView>(value)];
    }

    bool CollectionViewItem::is_selected() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSCollectionViewItem>(this) isSelected]);
    }

    void CollectionViewItem::set_selected(bool value) const
    {
        [cocoon::internal::ns<::NSCollectionViewItem>(this) setSelected:static_cast<::BOOL>(value)];
    }

    TextField CollectionViewItem::text_field() const
    {
        return cocoon::internal::wrap<TextField>([cocoon::internal::ns<::NSCollectionViewItem>(this) textField]);
    }

    void CollectionViewItem::set_text_field(const TextField& value) const
    {
        [cocoon::internal::ns<::NSCollectionViewItem>(this) setTextField:cocoon::internal::native<::NSTextField>(value)];
    }
}
