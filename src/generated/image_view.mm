#include "generated/image_view.h"
#include "internal.h"

namespace cocoon
{
    ImageView::ImageView(const Image& image) : ImageView(Adopt{cocoon::internal::retain(cocoon::internal::make_image_view(image))})
    {
    }

    ImageView::ImageView(std::nullptr_t) : Control(nullptr)
    {
    }

    ImageView::ImageView(Adopt adopt) : Control(adopt)
    {
    }

    void ImageView::add_symbol_effect(const SymbolEffect& symbol_effect) const
    {
        [cocoon::internal::ns<::NSImageView>(this) addSymbolEffect:cocoon::internal::native<::NSSymbolEffect>(symbol_effect)];
    }

    void ImageView::add_symbol_effect(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options) const
    {
        [cocoon::internal::ns<::NSImageView>(this) addSymbolEffect:cocoon::internal::native<::NSSymbolEffect>(symbol_effect) options:cocoon::internal::native<::NSSymbolEffectOptions>(options)];
    }

    void ImageView::add_symbol_effect(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options, bool animated) const
    {
        [cocoon::internal::ns<::NSImageView>(this) addSymbolEffect:cocoon::internal::native<::NSSymbolEffect>(symbol_effect) options:cocoon::internal::native<::NSSymbolEffectOptions>(options) animated:static_cast<::BOOL>(animated)];
    }

    ImageView ImageView::image_view_with_image(const Image& image)
    {
        return cocoon::internal::wrap<ImageView>([::NSImageView imageViewWithImage:cocoon::internal::native<::NSImage>(image)]);
    }

    void ImageView::remove_all_symbol_effects() const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeAllSymbolEffects];
    }

    void ImageView::remove_all_symbol_effects_with_options(const SymbolEffectOptions& options) const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeAllSymbolEffectsWithOptions:cocoon::internal::native<::NSSymbolEffectOptions>(options)];
    }

    void ImageView::remove_all_symbol_effects_with_options(const SymbolEffectOptions& options, bool animated) const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeAllSymbolEffectsWithOptions:cocoon::internal::native<::NSSymbolEffectOptions>(options) animated:static_cast<::BOOL>(animated)];
    }

    void ImageView::remove_symbol_effect_of_type(const SymbolEffect& symbol_effect) const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeSymbolEffectOfType:cocoon::internal::native<::NSSymbolEffect>(symbol_effect)];
    }

    void ImageView::remove_symbol_effect_of_type(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options) const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeSymbolEffectOfType:cocoon::internal::native<::NSSymbolEffect>(symbol_effect) options:cocoon::internal::native<::NSSymbolEffectOptions>(options)];
    }

    void ImageView::remove_symbol_effect_of_type(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options, bool animated) const
    {
        [cocoon::internal::ns<::NSImageView>(this) removeSymbolEffectOfType:cocoon::internal::native<::NSSymbolEffect>(symbol_effect) options:cocoon::internal::native<::NSSymbolEffectOptions>(options) animated:static_cast<::BOOL>(animated)];
    }

    void ImageView::set_symbol_image(const Image& symbol_image, const SymbolContentTransition& transition) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setSymbolImage:cocoon::internal::native<::NSImage>(symbol_image) withContentTransition:cocoon::internal::native<::NSSymbolContentTransition>(transition)];
    }

    void ImageView::set_symbol_image(const Image& symbol_image, const SymbolContentTransition& transition, const SymbolEffectOptions& options) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setSymbolImage:cocoon::internal::native<::NSImage>(symbol_image) withContentTransition:cocoon::internal::native<::NSSymbolContentTransition>(transition) options:cocoon::internal::native<::NSSymbolEffectOptions>(options)];
    }

    bool ImageView::allows_cut_copy_paste() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageView>(this) allowsCutCopyPaste]);
    }

    void ImageView::set_allows_cut_copy_paste(bool value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setAllowsCutCopyPaste:static_cast<::BOOL>(value)];
    }

    bool ImageView::animates() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageView>(this) animates]);
    }

    void ImageView::set_animates(bool value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setAnimates:static_cast<::BOOL>(value)];
    }

    Color ImageView::content_tint_color() const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSImageView>(this) contentTintColor]);
    }

    void ImageView::set_content_tint_color(const Color& value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setContentTintColor:cocoon::internal::native<::NSColor>(value)];
    }

    ImageDynamicRange ImageView::default_preferred_image_dynamic_range()
    {
        return static_cast<ImageDynamicRange>([::NSImageView defaultPreferredImageDynamicRange]);
    }

    void ImageView::set_default_preferred_image_dynamic_range(ImageDynamicRange value)
    {
        [::NSImageView setDefaultPreferredImageDynamicRange:static_cast<::NSImageDynamicRange>(value)];
    }

    bool ImageView::is_editable() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSImageView>(this) isEditable]);
    }

    void ImageView::set_editable(bool value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setEditable:static_cast<::BOOL>(value)];
    }

    Image ImageView::image() const
    {
        return cocoon::internal::wrap<Image>([cocoon::internal::ns<::NSImageView>(this) image]);
    }

    void ImageView::set_image(const Image& value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setImage:cocoon::internal::native<::NSImage>(value)];
    }

    ImageAlignment ImageView::image_alignment() const
    {
        return static_cast<ImageAlignment>([cocoon::internal::ns<::NSImageView>(this) imageAlignment]);
    }

    void ImageView::set_image_alignment(ImageAlignment value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setImageAlignment:static_cast<::NSImageAlignment>(value)];
    }

    ImageDynamicRange ImageView::image_dynamic_range() const
    {
        return static_cast<ImageDynamicRange>([cocoon::internal::ns<::NSImageView>(this) imageDynamicRange]);
    }

    ImageFrameStyle ImageView::image_frame_style() const
    {
        return static_cast<ImageFrameStyle>([cocoon::internal::ns<::NSImageView>(this) imageFrameStyle]);
    }

    void ImageView::set_image_frame_style(ImageFrameStyle value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setImageFrameStyle:static_cast<::NSImageFrameStyle>(value)];
    }

    ImageScaling ImageView::image_scaling() const
    {
        return static_cast<ImageScaling>([cocoon::internal::ns<::NSImageView>(this) imageScaling]);
    }

    void ImageView::set_image_scaling(ImageScaling value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setImageScaling:static_cast<::NSImageScaling>(value)];
    }

    ImageDynamicRange ImageView::preferred_image_dynamic_range() const
    {
        return static_cast<ImageDynamicRange>([cocoon::internal::ns<::NSImageView>(this) preferredImageDynamicRange]);
    }

    void ImageView::set_preferred_image_dynamic_range(ImageDynamicRange value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setPreferredImageDynamicRange:static_cast<::NSImageDynamicRange>(value)];
    }

    ImageSymbolConfiguration ImageView::symbol_configuration() const
    {
        return cocoon::internal::wrap<ImageSymbolConfiguration>([cocoon::internal::ns<::NSImageView>(this) symbolConfiguration]);
    }

    void ImageView::set_symbol_configuration(const ImageSymbolConfiguration& value) const
    {
        [cocoon::internal::ns<::NSImageView>(this) setSymbolConfiguration:cocoon::internal::native<::NSImageSymbolConfiguration>(value)];
    }
}
