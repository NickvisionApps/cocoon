#include "generated/image.h"
#include "internal.h"

@interface AKImageDelegate : NSObject <NSImageDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKImageDelegate

- (NSImage*)imageDidNotDraw:(NSImage*)sender inRect:(NSRect)rect
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::Image, cocoon::Image(cocoon::Rect)>::emit((__bridge void*)strongHost, "did_not_draw_in_rect", cocoon::internal::from(rect));
    return cocoon::internal::native<::NSImage>(__r);
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(imageDidNotDraw:inRect:))
    {
        return strongHost && cocoon::Signal<cocoon::Image, cocoon::Image(cocoon::Rect)>::connected((__bridge void*)strongHost, "did_not_draw_in_rect");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    Image::Image(const std::string& file_name) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initByReferencingFile:cocoon::internal::to(file_name)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(const URL& url) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initByReferencingURL:cocoon::internal::native<::NSURL>(url)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(const CGImage& cg_image, const Size& size) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initWithCGImage:((::CGImageRef)(cg_image).handle()) size:cocoon::internal::to(size)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(const std::vector<std::uint8_t>& data) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initWithData:cocoon::internal::to_data(data)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(const Pasteboard& pasteboard) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(const Size& size) : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] initWithSize:cocoon::internal::to(size)])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image() : Image(Adopt{cocoon::internal::retain([[::NSImage alloc] init])})
    {
        Image::install_delegate_delegate_(handle());
    }

    Image::Image(std::nullptr_t) : Object(nullptr)
    {
    }

    Image::Image(Adopt adopt) : Object(adopt)
    {
    }

    CGImage Image::cg_image_for_proposed_rect(Rect* proposed_dest_rect, const GraphicsContext& reference_context, const std::map<std::string, Object>& hints) const
    {
        return cocoon::internal::wrap_cf<CGImage>((const void*)([cocoon::internal::ns<::NSImage>(this) CGImageForProposedRect:(::NSRect*)(proposed_dest_rect)
                                                                                                                      context:cocoon::internal::native<::NSGraphicsContext>(reference_context)
                                                                                                                        hints:cocoon::internal::to_dictionary(hints, [](const std::string& k) -> id
                                                                                                                                                              {
                                                                                                                                                                  return cocoon::internal::to(k);
                                                                                                                                                              },
                                                                                                                                                              [](const Object& v) -> id
                                                                                                                                                              {
                                                                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                                                                              })]));
    }

    std::vector<std::uint8_t> Image::tiff_representation_using_compression(TIFFCompression comp, float factor) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSImage>(this) TIFFRepresentationUsingCompression:static_cast<::NSTIFFCompression>(comp) factor:static_cast<float>(factor)]);
    }

    void Image::add_representation(const ImageRep& image_rep) const
    {
        [cocoon::internal::ns<::NSImage>(this) addRepresentation:cocoon::internal::native<::NSImageRep>(image_rep)];
    }

    void Image::add_representations(const std::vector<ImageRep>& image_reps) const
    {
        [cocoon::internal::ns<::NSImage>(this) addRepresentations:cocoon::internal::to_array(image_reps, [](const ImageRep& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native<::NSImageRep>(e);
                                                                                             })];
    }

    ImageRep Image::best_representation_for_rect(const Rect& rect, const GraphicsContext& reference_context, const std::map<std::string, Object>& hints) const
    {
        return cocoon::internal::wrap<ImageRep>([cocoon::internal::ns<::NSImage>(this) bestRepresentationForRect:cocoon::internal::to(rect)
                                                                                                         context:cocoon::internal::native<::NSGraphicsContext>(reference_context)
                                                                                                           hints:cocoon::internal::to_dictionary(hints, [](const std::string& k) -> id
                                                                                                                                                 {
                                                                                                                                                     return cocoon::internal::to(k);
                                                                                                                                                 },
                                                                                                                                                 [](const Object& v) -> id
                                                                                                                                                 {
                                                                                                                                                     return cocoon::internal::native_id(v);
                                                                                                                                                 })]);
    }

    bool Image::can_init_with_pasteboard(const Pasteboard& pasteboard)
    {
        return static_cast<bool>([::NSImage canInitWithPasteboard:cocoon::internal::native<::NSPasteboard>(pasteboard)]);
    }

    void Image::draw_at_point(const Point& point, const Rect& from_rect, CompositingOperation op, double delta) const
    {
        [cocoon::internal::ns<::NSImage>(this) drawAtPoint:cocoon::internal::to(point) fromRect:cocoon::internal::to(from_rect) operation:static_cast<::NSCompositingOperation>(op) fraction:static_cast<::CGFloat>(delta)];
    }

    void Image::draw_in_rect(const Rect& rect) const
    {
        [cocoon::internal::ns<::NSImage>(this) drawInRect:cocoon::internal::to(rect)];
    }

    void Image::draw_in_rect(const Rect& rect, const Rect& from_rect, CompositingOperation op, double delta) const
    {
        [cocoon::internal::ns<::NSImage>(this) drawInRect:cocoon::internal::to(rect) fromRect:cocoon::internal::to(from_rect) operation:static_cast<::NSCompositingOperation>(op) fraction:static_cast<::CGFloat>(delta)];
    }

    void Image::draw_in_rect(const Rect& dst_space_portion_rect, const Rect& src_space_portion_rect, CompositingOperation op, double requested_alpha, bool respect_context_is_flipped, const std::map<std::string, Object>& hints) const
    {
        [cocoon::internal::ns<::NSImage>(this) drawInRect:cocoon::internal::to(dst_space_portion_rect)
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
                                                                                          })];
    }

    bool Image::draw_representation(const ImageRep& image_rep, const Rect& rect) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) drawRepresentation:cocoon::internal::native<::NSImageRep>(image_rep) inRect:cocoon::internal::to(rect)]);
    }

    bool Image::hit_test_rect(const Rect& test_rect_dest_space, const Rect& image_rect_dest_space, const GraphicsContext& context, const std::map<std::string, Object>& hints, bool flipped) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) hitTestRect:cocoon::internal::to(test_rect_dest_space)
                                                           withImageDestinationRect:cocoon::internal::to(image_rect_dest_space)
                                                                            context:cocoon::internal::native<::NSGraphicsContext>(context)
                                                                              hints:cocoon::internal::to_dictionary(hints, [](const std::string& k) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::to(k);
                                                                                                                    },
                                                                                                                    [](const Object& v) -> id
                                                                                                                    {
                                                                                                                        return cocoon::internal::native_id(v);
                                                                                                                    })
                                                                            flipped:static_cast<::BOOL>(flipped)]);
    }

    Image Image::image_named(const std::string& name)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageNamed:cocoon::internal::to(name)]);
    }

    Image Image::image_with_locale(const Locale& locale) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSImage>(this) imageWithLocale:cocoon::internal::native<::NSLocale>(locale)]);
    }

    Image Image::image_with_size(const Size& size, bool drawing_handler_should_be_called_with_flipped_context, std::function<bool(Rect)> drawing_handler)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageWithSize:cocoon::internal::to(size) flipped:static_cast<::BOOL>(drawing_handler_should_be_called_with_flipped_context) drawingHandler:(drawing_handler ? (BOOL(^)(::NSRect)) ^ ::BOOL(::NSRect a62_0) { auto __r = drawing_handler(cocoon::internal::from(a62_0)); return static_cast<::BOOL>(__r); } : (BOOL(^)(::NSRect))nil)]);
    }

    Image Image::image_with_symbol_configuration(const ImageSymbolConfiguration& configuration) const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSImage>(this) imageWithSymbolConfiguration:cocoon::internal::native<::NSImageSymbolConfiguration>(configuration)]);
    }

    Image Image::image_with_symbol_name(const std::string& name, const Bundle& bundle, double value)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageWithSymbolName:cocoon::internal::to(name) bundle:cocoon::internal::native<::NSBundle>(bundle) variableValue:static_cast<double>(value)]);
    }

    Image Image::image_with_symbol_name(const std::string& name, double value)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageWithSymbolName:cocoon::internal::to(name) variableValue:static_cast<double>(value)]);
    }

    Image Image::image_with_system_symbol_name(const std::string& name, const std::string& description)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageWithSystemSymbolName:cocoon::internal::to(name) accessibilityDescription:cocoon::internal::to(description)]);
    }

    Image Image::image_with_system_symbol_name(const std::string& name, double value, const std::string& description)
    {
        return cocoon::internal::wrap<Image>([::NSImage imageWithSystemSymbolName:cocoon::internal::to(name) variableValue:static_cast<double>(value) accessibilityDescription:cocoon::internal::to(description)]);
    }

    Object Image::layer_contents_for_contents_scale(double layer_contents_scale) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSImage>(this) layerContentsForContentsScale:static_cast<::CGFloat>(layer_contents_scale)]);
    }

    void Image::lock_focus() const
    {
        [cocoon::internal::ns<::NSImage>(this) lockFocus];
    }

    void Image::lock_focus_flipped(bool flipped) const
    {
        [cocoon::internal::ns<::NSImage>(this) lockFocusFlipped:static_cast<::BOOL>(flipped)];
    }

    std::string Image::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImage>(this) name]);
    }

    void Image::recache() const
    {
        [cocoon::internal::ns<::NSImage>(this) recache];
    }

    double Image::recommended_layer_contents_scale(double preferred_contents_scale) const
    {
        return static_cast<double>([cocoon::internal::ns<::NSImage>(this) recommendedLayerContentsScale:static_cast<::CGFloat>(preferred_contents_scale)]);
    }

    void Image::remove_representation(const ImageRep& image_rep) const
    {
        [cocoon::internal::ns<::NSImage>(this) removeRepresentation:cocoon::internal::native<::NSImageRep>(image_rep)];
    }

    bool Image::set_name(const std::string& string) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) setName:cocoon::internal::to(string)]);
    }

    void Image::unlock_focus() const
    {
        [cocoon::internal::ns<::NSImage>(this) unlockFocus];
    }

    std::vector<std::uint8_t> Image::tiff_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSImage>(this) TIFFRepresentation]);
    }

    std::string Image::accessibility_description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImage>(this) accessibilityDescription]);
    }

    void Image::set_accessibility_description(const std::string& value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setAccessibilityDescription:cocoon::internal::to(value)];
    }

    Rect Image::alignment_rect() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImage>(this) alignmentRect]);
    }

    void Image::set_alignment_rect(const Rect& value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setAlignmentRect:cocoon::internal::to(value)];
    }

    Color Image::background_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSImage>(this) backgroundColor]);
    }

    void Image::set_background_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setBackgroundColor:cocoon::internal::native<::NSColor>(value)];
    }

    ImageCacheMode Image::cache_mode() const
    {
        return static_cast<ImageCacheMode>([cocoon::internal::ns<::NSImage>(this) cacheMode]);
    }

    void Image::set_cache_mode(ImageCacheMode value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setCacheMode:static_cast<::NSImageCacheMode>(value)];
    }

    Insets Image::cap_insets() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImage>(this) capInsets]);
    }

    void Image::set_cap_insets(const Insets& value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setCapInsets:cocoon::internal::to(value)];
    }

    std::vector<std::string> Image::image_types()
    {
        return cocoon::internal::from_array<std::string>([::NSImage imageTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> Image::image_unfiltered_types()
    {
        return cocoon::internal::from_array<std::string>([::NSImage imageUnfilteredTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    Locale Image::locale() const
    {
        return cocoon::internal::wrap<Locale>([cocoon::internal::ns<::NSImage>(this) locale]);
    }

    bool Image::matches_on_multiple_resolution() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) matchesOnMultipleResolution]);
    }

    void Image::set_matches_on_multiple_resolution(bool value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setMatchesOnMultipleResolution:static_cast<::BOOL>(value)];
    }

    bool Image::matches_only_on_best_fitting_axis() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) matchesOnlyOnBestFittingAxis]);
    }

    void Image::set_matches_only_on_best_fitting_axis(bool value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setMatchesOnlyOnBestFittingAxis:static_cast<::BOOL>(value)];
    }

    bool Image::prefers_color_match() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) prefersColorMatch]);
    }

    void Image::set_prefers_color_match(bool value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setPrefersColorMatch:static_cast<::BOOL>(value)];
    }

    std::vector<ImageRep> Image::representations() const
    {
        return cocoon::internal::from_array<ImageRep>([cocoon::internal::ns<::NSImage>(this) representations], [](id e) -> ImageRep
                                                      {
                                                          return cocoon::internal::wrap<ImageRep>((::NSImageRep*)e);
                                                      });
    }

    ImageResizingMode Image::resizing_mode() const
    {
        return static_cast<ImageResizingMode>([cocoon::internal::ns<::NSImage>(this) resizingMode]);
    }

    void Image::set_resizing_mode(ImageResizingMode value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setResizingMode:static_cast<::NSImageResizingMode>(value)];
    }

    Size Image::size() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSImage>(this) size]);
    }

    void Image::set_size(const Size& value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setSize:cocoon::internal::to(value)];
    }

    ImageSymbolConfiguration Image::symbol_configuration() const
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([cocoon::internal::ns<::NSImage>(this) symbolConfiguration]);
    }

    bool Image::is_template() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) isTemplate]);
    }

    void Image::set_template(bool value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setTemplate:static_cast<::BOOL>(value)];
    }

    bool Image::uses_eps_on_resolution_mismatch() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) usesEPSOnResolutionMismatch]);
    }

    void Image::set_uses_eps_on_resolution_mismatch(bool value) const
    {
        [cocoon::internal::ns<::NSImage>(this) setUsesEPSOnResolutionMismatch:static_cast<::BOOL>(value)];
    }

    bool Image::is_valid() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImage>(this) isValid]);
    }

    Image Image::symbol(const std::string& name, const std::string& description)
    {
        return cocoon::internal::wrap<Image>([NSImage imageWithSystemSymbolName:cocoon::internal::to(name) accessibilityDescription:description.empty() ? nil : cocoon::internal::to(description)]);
    }

    void Image::install_delegate_delegate_(void* native)
    {
        ::NSImage* host = (__bridge ::NSImage*)native;
        AKImageDelegate* delegate = [[AKImageDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSImage* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSImage* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
