#include "generated/dragging_image_component.h"
#include "internal.h"

namespace cocoon
{
    DraggingImageComponent::DraggingImageComponent(const std::string& key) : DraggingImageComponent(Adopt{cocoon::internal::retain([[::NSDraggingImageComponent alloc] initWithKey:cocoon::internal::to(key)])})
    {
    }

    DraggingImageComponent::DraggingImageComponent() : Object(nullptr)
    {
    }

    DraggingImageComponent::DraggingImageComponent(std::nullptr_t) : Object(nullptr)
    {
    }

    DraggingImageComponent::DraggingImageComponent(Adopt adopt) : Object(adopt)
    {
    }

    DraggingImageComponent DraggingImageComponent::dragging_image_component_with_key(const std::string& key)
    {
        return cocoon::internal::wrap<DraggingImageComponent>([::NSDraggingImageComponent draggingImageComponentWithKey:cocoon::internal::to(key)]);
    }

    Object DraggingImageComponent::contents() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSDraggingImageComponent>(this) contents]);
    }

    void DraggingImageComponent::set_contents(const Object& value) const
    {
        [cocoon::internal::ns<::NSDraggingImageComponent>(this) setContents:cocoon::internal::native_id(value)];
    }

    Rect DraggingImageComponent::frame() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDraggingImageComponent>(this) frame]);
    }

    void DraggingImageComponent::set_frame(const Rect& value) const
    {
        [cocoon::internal::ns<::NSDraggingImageComponent>(this) setFrame:cocoon::internal::to(value)];
    }

    std::string DraggingImageComponent::key() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSDraggingImageComponent>(this) key]);
    }

    void DraggingImageComponent::set_key(const std::string& value) const
    {
        [cocoon::internal::ns<::NSDraggingImageComponent>(this) setKey:cocoon::internal::to(value)];
    }
}
