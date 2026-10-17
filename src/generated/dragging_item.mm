#include "generated/dragging_item.h"
#include "internal.h"

namespace cocoon
{
    DraggingItem::DraggingItem(const Object& pasteboard_writer) : DraggingItem(Adopt{cocoon::internal::retain([[::NSDraggingItem alloc] initWithPasteboardWriter:cocoon::internal::native_id(pasteboard_writer)])})
    {
    }

    DraggingItem::DraggingItem() : Object(nullptr)
    {
    }

    DraggingItem::DraggingItem(std::nullptr_t) : Object(nullptr)
    {
    }

    DraggingItem::DraggingItem(Adopt adopt) : Object(adopt)
    {
    }

    void DraggingItem::set_dragging_frame(const Rect& frame, const Object& contents) const
    {
        [cocoon::internal::ns<::NSDraggingItem>(this) setDraggingFrame:cocoon::internal::to(frame) contents:cocoon::internal::native_id(contents)];
    }

    Rect DraggingItem::dragging_frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDraggingItem>(this) draggingFrame]);
    }

    void DraggingItem::set_dragging_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSDraggingItem>(this) setDraggingFrame:cocoon::internal::to(value)];
    }

    std::vector<DraggingImageComponent> DraggingItem::image_components() const
    {
        return cocoon::internal::from_array<DraggingImageComponent>([cocoon::internal::ns<::NSDraggingItem>(this) imageComponents], [](id e) -> DraggingImageComponent
                                                      {
                                                          return cocoon::internal::wrap<DraggingImageComponent>((::NSDraggingImageComponent*)e);
                                                      });
    }

    std::function<std::vector<DraggingImageComponent>()> DraggingItem::image_components_provider() const
    {
        return [&]() -> std::function<std::vector<DraggingImageComponent>()>
        {
            auto blk = (NSArray<NSDraggingImageComponent*> * (^)(void))([cocoon::internal::ns<::NSDraggingItem>(this) imageComponentsProvider]);
            if (!blk)
            {
                return {};
            }
            return [blk]() -> std::vector<DraggingImageComponent>
            {
                auto __r = blk();
                return cocoon::internal::from_array<DraggingImageComponent>(__r, [](id e) -> DraggingImageComponent
                                                              {
                                                                  return cocoon::internal::wrap<DraggingImageComponent>((::NSDraggingImageComponent*)e);
                                                              });
            };
        }();
    }

    void DraggingItem::set_image_components_provider(std::function<std::vector<DraggingImageComponent>()> value) const
    {
        [cocoon::internal::ns<::NSDraggingItem>(this) setImageComponentsProvider:(value ? (NSArray<NSDraggingImageComponent*> * (^)(void)) ^ NSArray * () { auto __r = value(); return cocoon::internal::to_array(__r, [](const DraggingImageComponent& e) -> id { return cocoon::internal::native<::NSDraggingImageComponent>(e); }); } : (NSArray<NSDraggingImageComponent*> * (^)(void)) nil)];
    }

    Object DraggingItem::item() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDraggingItem>(this) item]);
    }
}
