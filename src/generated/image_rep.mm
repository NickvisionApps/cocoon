#include "generated/image_rep.h"
#include "internal.h"

namespace cocoon
{
    ImageRep::ImageRep(const std::string& filename) : ImageRep(Adopt{cocoon::internal::retain([::NSImageRep imageRepWithContentsOfFile:cocoon::internal::to(filename)])})
    {
    }

    ImageRep::ImageRep(const URL& url) : ImageRep(Adopt{cocoon::internal::retain([::NSImageRep imageRepWithContentsOfURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    ImageRep::ImageRep(const Pasteboard& pasteboard) : ImageRep(Adopt{cocoon::internal::retain([::NSImageRep imageRepWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)])})
    {
    }

    ImageRep::ImageRep() : ImageRep(Adopt{cocoon::internal::retain([[::NSImageRep alloc] init])})
    {
    }

    ImageRep::ImageRep(std::nullptr_t) : Object(nullptr)
    {
    }

    ImageRep::ImageRep(Adopt adopt) : Object(adopt)
    {
    }

    CGImage ImageRep::cg_image_for_proposed_rect(Rect* proposed_dest_rect, const GraphicsContext& context, const std::map<std::string, Object>& hints) const
    {
        return cocoon::internal::wrap_cf<CGImage>((const void*)([cocoon::internal::ns<::NSImageRep>(this) CGImageForProposedRect:(::NSRect*)(proposed_dest_rect)
                                                                                                                         context:cocoon::internal::native<::NSGraphicsContext>(context)
                                                                                                                           hints:cocoon::internal::to_dictionary(hints, [](const std::string& k) -> id
                                                                                                                                                                 {
                                                                                                                                                                     return cocoon::internal::to(k);
                                                                                                                                                                 },
                                                                                                                                                                 [](const Object& v) -> id
                                                                                                                                                                 {
                                                                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                                                                 })]));
    }

    bool ImageRep::can_init_with_data(const std::vector<std::uint8_t>& data)
    {
        return static_cast<bool>([::NSImageRep canInitWithData:cocoon::internal::to_data(data)]);
    }

    bool ImageRep::can_init_with_pasteboard(const Pasteboard& pasteboard)
    {
        return static_cast<bool>([::NSImageRep canInitWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)]);
    }

    bool ImageRep::draw() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) draw]);
    }

    bool ImageRep::draw_at_point(const Point& point) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) drawAtPoint:cocoon::internal::to(point)]);
    }

    bool ImageRep::draw_in_rect(const Rect& rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) drawInRect:cocoon::internal::to(rect)]);
    }

    bool ImageRep::draw_in_rect(const Rect& dst_space_portion_rect, const Rect& src_space_portion_rect, CompositingOperation op, double requested_alpha, bool respect_context_is_flipped, const std::map<std::string, Object>& hints) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) drawInRect:cocoon::internal::to(dst_space_portion_rect)
                                                                             fromRect:cocoon::internal::to(src_space_portion_rect)
                                                                            operation:static_cast<::NSCompositingOperation>(op)
                                                                             fraction:static_cast<::CGFloat>(requested_alpha)
                                                                       respectFlipped:static_cast<::BOOL>(respect_context_is_flipped)
                                                                                hints:cocoon::internal::to_dictionary(hints, [](const std::string& k) -> id
                                                                                                                      {
                                                                                                                          return cocoon::internal::to(k);
                                                                                                                      },
                                                                                                                      [](const Object& v) -> id
                                                                                                                      {
                                                                                                                          return cocoon::internal::native_id(v);
                                                                                                                      })]);
    }

    std::string ImageRep::image_rep_class_for_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::from(NSStringFromClass([::NSImageRep imageRepClassForData:cocoon::internal::to_data(data)]));
    }

    std::string ImageRep::image_rep_class_for_type(const std::string& type)
    {
        return cocoon::internal::from(NSStringFromClass([::NSImageRep imageRepClassForType:cocoon::internal::to(type)]));
    }

    std::vector<ImageRep> ImageRep::image_reps_with_contents_of_file(const std::string& filename)
    {
        return cocoon::internal::from_array<ImageRep>([::NSImageRep imageRepsWithContentsOfFile:cocoon::internal::to(filename)], [](id e) -> ImageRep
                                                      {
                                                          return cocoon::internal::wrap<ImageRep>((::NSImageRep*)e);
                                                      });
    }

    std::vector<ImageRep> ImageRep::image_reps_with_contents_of_url(const URL& url)
    {
        return cocoon::internal::from_array<ImageRep>([::NSImageRep imageRepsWithContentsOfURL:cocoon::internal::native<::NSURL>(url)], [](id e) -> ImageRep
                                                      {
                                                          return cocoon::internal::wrap<ImageRep>((::NSImageRep*)e);
                                                      });
    }

    std::vector<ImageRep> ImageRep::image_reps_with_pasteboard(const Pasteboard& pasteboard)
    {
        return cocoon::internal::from_array<ImageRep>([::NSImageRep imageRepsWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)], [](id e) -> ImageRep
                                                      {
                                                          return cocoon::internal::wrap<ImageRep>((::NSImageRep*)e);
                                                      });
    }

    void ImageRep::register_image_rep_class(const std::string& image_rep_class)
    {
        [::NSImageRep registerImageRepClass:NSClassFromString(cocoon::internal::to(image_rep_class))];
    }

    void ImageRep::unregister_image_rep_class(const std::string& image_rep_class)
    {
        [::NSImageRep unregisterImageRepClass:NSClassFromString(cocoon::internal::to(image_rep_class))];
    }

    bool ImageRep::has_alpha() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) hasAlpha]);
    }

    void ImageRep::set_alpha(bool value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setAlpha:static_cast<::BOOL>(value)];
    }

    std::int64_t ImageRep::bits_per_sample() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSImageRep>(this) bitsPerSample]);
    }

    void ImageRep::set_bits_per_sample(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setBitsPerSample:static_cast<::NSInteger>(value)];
    }

    std::string ImageRep::color_space_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImageRep>(this) colorSpaceName]);
    }

    void ImageRep::set_color_space_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setColorSpaceName:cocoon::internal::to(value)];
    }

    std::vector<std::string> ImageRep::image_types()
    {
        return cocoon::internal::from_array<std::string>([::NSImageRep imageTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> ImageRep::image_unfiltered_types()
    {
        return cocoon::internal::from_array<std::string>([::NSImageRep imageUnfilteredTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    ImageLayoutDirection ImageRep::layout_direction() const
    {
        return static_cast<ImageLayoutDirection>([cocoon::internal::ns<::NSImageRep>(this) layoutDirection]);
    }

    void ImageRep::set_layout_direction(ImageLayoutDirection value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setLayoutDirection:static_cast<::NSImageLayoutDirection>(value)];
    }

    bool ImageRep::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageRep>(this) isOpaque]);
    }

    void ImageRep::set_opaque(bool value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setOpaque:static_cast<::BOOL>(value)];
    }

    std::int64_t ImageRep::pixels_high() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSImageRep>(this) pixelsHigh]);
    }

    void ImageRep::set_pixels_high(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setPixelsHigh:static_cast<::NSInteger>(value)];
    }

    std::int64_t ImageRep::pixels_wide() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSImageRep>(this) pixelsWide]);
    }

    void ImageRep::set_pixels_wide(std::int64_t value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setPixelsWide:static_cast<::NSInteger>(value)];
    }

    std::vector<std::string> ImageRep::registered_image_rep_classes()
    {
        return cocoon::internal::from_array<std::string>([::NSImageRep registeredImageRepClasses], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from(NSStringFromClass(e));
                                                         });
    }

    Size ImageRep::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImageRep>(this) size]);
    }

    void ImageRep::set_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSImageRep>(this) setSize:cocoon::internal::to(value)];
    }
}
