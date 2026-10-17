#include "generated/custom_image_rep.h"
#include "internal.h"

namespace cocoon
{
    CustomImageRep::CustomImageRep(const std::string& selector, const Object& delegate) : CustomImageRep(Adopt{cocoon::internal::retain([[::NSCustomImageRep alloc] initWithDrawSelector:NSSelectorFromString(cocoon::internal::to(selector)) delegate:cocoon::internal::native_id(delegate)])})
    {
    }

    CustomImageRep::CustomImageRep(const Size& size, bool drawing_handler_should_be_called_with_flipped_context, std::function<bool(Rect)> drawing_handler) : CustomImageRep(Adopt{cocoon::internal::retain([[::NSCustomImageRep alloc] initWithSize:cocoon::internal::to(size) flipped:static_cast<::BOOL>(drawing_handler_should_be_called_with_flipped_context) drawingHandler:(drawing_handler ? (BOOL(^)(::NSRect)) ^ ::BOOL(::NSRect a21_0) { auto __r = drawing_handler(cocoon::internal::from(a21_0)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSRect))nil)])})
    {
    }

    CustomImageRep::CustomImageRep() : CustomImageRep(Adopt{cocoon::internal::retain([[::NSCustomImageRep alloc] init])})
    {
    }

    CustomImageRep::CustomImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    CustomImageRep::CustomImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    Object CustomImageRep::delegate() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSCustomImageRep>(this) delegate]);
    }

    std::string CustomImageRep::draw_selector() const
    {
        return cocoon::internal::from(NSStringFromSelector([cocoon::internal::ns<::NSCustomImageRep>(this) drawSelector]));
    }

    std::function<bool(Rect)> CustomImageRep::drawing_handler() const
    {
        return [&]() -> std::function<bool(Rect)>
        {
            auto blk = (BOOL(^)(::NSRect))([cocoon::internal::ns<::NSCustomImageRep>(this) drawingHandler]);
            if (!blk)
            {
                return {};
            }
            return [blk](Rect a22_0) -> bool
            {
                auto __r = blk(cocoon::internal::to(a22_0));
                return static_cast<bool>(__r);
            };
        }();
    }
}
