#pragma once

#include "generated/availability.h"
#include "generated/control.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class Color;
    class Image;
    class ImageSymbolConfiguration;
    class SymbolContentTransition;
    class SymbolEffect;
    class SymbolEffectOptions;

    /**
     * @brief A view displaying an image.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Control.
     *
     * @par Example
     * @code
     * cocoon::ImageView view(cocoon::Image::symbol("star"));
     * view.set_content_tint_color(cocoon::Color::system_yellow_color());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ImageView image_view{cocoon::Image()};
     * image_view.set_allows_cut_copy_paste(true);
     * auto allows_cut_copy_paste = image_view.allows_cut_copy_paste();
     * image_view.set_animates(true);
     * auto animates = image_view.animates();
     * image_view.set_content_tint_color(cocoon::Color());
     * auto content_tint_color = image_view.content_tint_color();
     * image_view.add_symbol_effect(cocoon::SymbolEffect());
     * image_view.add_symbol_effect(cocoon::SymbolEffect(), cocoon::SymbolEffectOptions());
     * image_view.add_symbol_effect(cocoon::SymbolEffect(), cocoon::SymbolEffectOptions(), true);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsimageview
     */
    class ImageView : public Control
    {
    public:
        /// @brief Creates a new `NSImageView` instance and returns a handle to it.
        explicit ImageView(const Image& image = Image());
        /// @brief Creates a null handle that refers to no native object.
        ImageView(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ImageView(Adopt adopt);
        /**
         * @brief Calls `-[NSImageView addSymbolEffect:]`.
         * @details Adds a symbol effect to the image view with default options and animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         */
        void add_symbol_effect(const SymbolEffect& symbol_effect) const;
        /**
         * @brief Calls `-[NSImageView addSymbolEffect:options:]`.
         * @details Adds a symbol effect to the image view with specified options and default animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void add_symbol_effect(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options) const;
        /**
         * @brief Calls `-[NSImageView addSymbolEffect:options:animated:]`.
         * @details Adds a symbol effect to the image view with specified options and animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param animated Argument converted to the Objective-C parameter of the same role.
         */
        void add_symbol_effect(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options, bool animated) const;
        /**
         * @brief Calls `-[NSImageView removeAllSymbolEffects]`.
         * @details Removes all symbol effects from the image view with default options and animation.
         */
        void remove_all_symbol_effects() const;
        /**
         * @brief Calls `-[NSImageView removeAllSymbolEffectsWithOptions:]`.
         * @details Removes all symbol effects from the image view with specified options and default animation.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void remove_all_symbol_effects_with_options(const SymbolEffectOptions& options) const;
        /**
         * @brief Calls `-[NSImageView removeAllSymbolEffectsWithOptions:animated:]`.
         * @details Removes all symbol effects from the image view with specified options and animation.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param animated Argument converted to the Objective-C parameter of the same role.
         */
        void remove_all_symbol_effects_with_options(const SymbolEffectOptions& options, bool animated) const;
        /**
         * @brief Calls `-[NSImageView removeSymbolEffectOfType:]`.
         * @details Removes from the image view the symbol effect matching the type of effect passed in, with default options and animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         */
        void remove_symbol_effect_of_type(const SymbolEffect& symbol_effect) const;
        /**
         * @brief Calls `-[NSImageView removeSymbolEffectOfType:options:]`.
         * @details Removes from the image view the symbol effect matching the type of effect passed in, with specified options and default animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void remove_symbol_effect_of_type(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options) const;
        /**
         * @brief Calls `-[NSImageView removeSymbolEffectOfType:options:animated:]`.
         * @details Removes from the image view the symbol effect matching the type of effect passed in, with specified options and animation.
         * @param symbol_effect Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @param animated Argument converted to the Objective-C parameter of the same role.
         */
        void remove_symbol_effect_of_type(const SymbolEffect& symbol_effect, const SymbolEffectOptions& options, bool animated) const;
        /**
         * @brief Calls `-[NSImageView setSymbolImage:withContentTransition:]`.
         * @details Sets the symbol image on the image view with a symbol content transition and default options. Passing in a non-symbol image will result in undefined behavior.
         * @param symbol_image Argument converted to the Objective-C parameter of the same role.
         * @param transition Argument converted to the Objective-C parameter of the same role.
         */
        void set_symbol_image(const Image& symbol_image, const SymbolContentTransition& transition) const;
        /**
         * @brief Calls `-[NSImageView setSymbolImage:withContentTransition:options:]`.
         * @details Sets the symbol image on the image view with a symbol content transition and specified options. Passing in a non-symbol image will result in undefined behavior.
         * @param symbol_image Argument converted to the Objective-C parameter of the same role.
         * @param transition Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void set_symbol_image(const Image& symbol_image, const SymbolContentTransition& transition, const SymbolEffectOptions& options) const;
        /**
         * @brief Returns the `allowsCutCopyPaste` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        bool allows_cut_copy_paste() const;
        /**
         * @brief Sets the `allowsCutCopyPaste` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_allows_cut_copy_paste(bool value) const;
        /**
         * @brief Returns the `animates` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        bool animates() const;
        /**
         * @brief Sets the `animates` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_animates(bool value) const;
        /**
         * @brief Returns the `contentTintColor` property of `NSImageView`.
         * @details A tint color to be used when rendering template image content. This color may be combined with other effects to produce a theme-appropriate rendition of the template image. A 'nil' value indicates the standard set of effects without color modification. The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        Color content_tint_color() const;
        /**
         * @brief Sets the `contentTintColor` property of `NSImageView`.
         * @details A tint color to be used when rendering template image content. This color may be combined with other effects to produce a theme-appropriate rendition of the template image. A 'nil' value indicates the standard set of effects without color modification. The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_content_tint_color(const Color& value) const;
        /**
         * @brief Returns the `defaultPreferredImageDynamicRange` property of `NSImageView`.
         * @details Default preferred image dynamic range. Defaults to 'NSImageDynamicRangeConstrainedHigh' on macOS 14 and higher, 'NSImageDynamicRangeStandard' otherwise. Set to another value to change the default for all subsequently created 'NSImageView's in your app.
         * @return The converted Objective-C result.
         */
        static ImageDynamicRange default_preferred_image_dynamic_range();
        /**
         * @brief Sets the `defaultPreferredImageDynamicRange` property of `NSImageView`.
         * @details Default preferred image dynamic range. Defaults to 'NSImageDynamicRangeConstrainedHigh' on macOS 14 and higher, 'NSImageDynamicRangeStandard' otherwise. Set to another value to change the default for all subsequently created 'NSImageView's in your app.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        static void set_default_preferred_image_dynamic_range(ImageDynamicRange value);
        /**
         * @brief Returns the `editable` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        bool is_editable() const;
        /**
         * @brief Sets the `editable` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_editable(bool value) const;
        /**
         * @brief Returns the `image` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        Image image() const;
        /**
         * @brief Sets the `image` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image(const Image& value) const;
        /**
         * @brief Returns the `imageAlignment` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        ImageAlignment image_alignment() const;
        /**
         * @brief Sets the `imageAlignment` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_alignment(ImageAlignment value) const;
        /**
         * @brief Returns the `imageDynamicRange` property of `NSImageView`.
         * @details Resolved dynamic range based on fully resolved image content. Note: this will return 'NSImageDynamicRangeUnspecified' if the image view has not or can not resolve the content (either because it has no resolvable image content or has not resolved because the image view hasn't displayed.)
         * @return The converted Objective-C result.
         */
        ImageDynamicRange image_dynamic_range() const;
        /**
         * @brief Returns the `imageFrameStyle` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        ImageFrameStyle image_frame_style() const;
        /**
         * @brief Sets the `imageFrameStyle` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_frame_style(ImageFrameStyle value) const;
        /**
         * @brief Returns the `imageScaling` property of `NSImageView`.
         * @return The converted Objective-C result.
         */
        ImageScaling image_scaling() const;
        /**
         * @brief Sets the `imageScaling` property of `NSImageView`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_image_scaling(ImageScaling value) const;
        /**
         * @brief Returns the `preferredImageDynamicRange` property of `NSImageView`.
         * @details Preferred dynamic range when displaying an image in the receiving image view.
         * @return The converted Objective-C result.
         */
        ImageDynamicRange preferred_image_dynamic_range() const;
        /**
         * @brief Sets the `preferredImageDynamicRange` property of `NSImageView`.
         * @details Preferred dynamic range when displaying an image in the receiving image view.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_preferred_image_dynamic_range(ImageDynamicRange value) const;
        /**
         * @brief Returns the `symbolConfiguration` property of `NSImageView`.
         * @details Specifies a combination of point size, weight, and scale to use when sizing and displaying symbol images. If a symbol configuration isn't provided, the image view uses a default size, weight, and scale provided by the system. The default value is 'nil'.
         * @return The converted Objective-C result.
         */
        ImageSymbolConfiguration symbol_configuration() const;
        /**
         * @brief Sets the `symbolConfiguration` property of `NSImageView`.
         * @details Specifies a combination of point size, weight, and scale to use when sizing and displaying symbol images. If a symbol configuration isn't provided, the image view uses a default size, weight, and scale provided by the system. The default value is 'nil'.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_symbol_configuration(const ImageSymbolConfiguration& value) const;
    };
}
