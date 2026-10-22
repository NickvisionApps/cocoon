#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Bundle;
    class CGImage;
    class Color;
    class GraphicsContext;
    class ImageRep;
    class ImageSymbolConfiguration;
    class Locale;
    class Pasteboard;
    class URL;

    /**
     * @brief An image (NSImage).
     * @details \#endif / NSIMAGE_UNAVAILABLE_MACCATALYST
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Image star = cocoon::Image::symbol("star");
     * cocoon::Image photo = cocoon::Image::image_named("photo");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Image image{};
     * image.set_accessibility_description("text");
     * auto accessibility_description = image.accessibility_description();
     * image.set_alignment_rect({{0, 0}, {100, 100}});
     * auto alignment_rect = image.alignment_rect();
     * image.set_background_color(cocoon::Color());
     * auto background_color = image.background_color();
     * auto made_0 = cocoon::Image::image_named("text");
     * image.tiff_representation_using_compression(cocoon::TIFFCompression::None, 1);
     * image.add_representation(cocoon::ImageRep());
     * image.draw_at_point({0, 0}, {{0, 0}, {100, 100}}, cocoon::CompositingOperation::Clear, 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsimage
     */
    class Image : public Object
    {
    public:
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::string& file_name);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const URL& url);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const CGImage& cg_image, const Size& size);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const Pasteboard& pasteboard);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const Size& size);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const Size& size, bool drawing_handler_should_be_called_with_flipped_context, std::function<bool(Rect)> drawing_handler);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::string& name, const Bundle& bundle, double value);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::string& name, double value);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::string& name, const std::string& description);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image(const std::string& name, double value, const std::string& description);
        /// @brief Creates a new `NSImage` instance and returns a handle to it.
        explicit Image();
        /// @brief Creates a null handle that refers to no native object.
        Image(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Image(Adopt adopt);
        /**
         * @brief Calls `-[NSImage CGImageForProposedRect:context:hints:]`.
         * @details Returns a CGImage capturing the drawing of the receiver. This method returns an existing CGImage if one is available, or creates one if not. It behaves the same as drawing the image with respect to caching and related behaviors. This method is typically called, not overridden. An NSImage is potentially resolution independent, and may have representations that allow it to draw well in many contexts. A CGImage is more like a single pixel-based representation. This method produces a snapshot of how the NSImage would draw if it was asked to draw in proposedDestRect in the passed context. Producing this snapshot may be more expensive than just drawing the NSImage, so prefer to use -[NSImage drawInRect:fromRect:operation:fraction:] unless you require a CGImage. The return value in proposedDestRect tells the client where to draw the CGImage. This rect may be outset from the requested rect, because a CGImage must have pixel-integral dimensions while an NSImage need not. All input parameters are optional. They provide hints for how to choose among existing CGImages, or how to create one if there isn't already a CGImage available. The parameters are only hints. Any CGImage is a valid return. If proposedDestRect is NULL, it defaults to the smallest pixel-integral rectangle containing {{0,0}, [self size]}. The proposedDestRect is in user space in the reference context. If referenceContext is nil, the method behaves as if a window context scaled by the default user space scaling factor was passed, though no context is actually created. The properties of the context are used as hints for choosing the best representation and for creating a CGImage if creation is necessary. It also provides the coordinate space in which the proposedDestRect is interpreted. Only the snapshotted state of the context at the moment its passed to this method is relevant. Future changes to the context have no bearing on image behavior. The hints provide more context for selecting or generating a CGImage, and may override properties of the referenceContext. Hints may be nil. Any entries in a device description dictionary (see NSScreen) are valid, as are all CIContext creation options, plus a few extra hints defined below. Unrecognized hints are ignored, but passed down to image reps (see -[NSImageRep CGImageForProposedRect:context:hints:]). Explicit hints are particularly useful when it is not draw time and you don't have a context to pass in. For example, if you want to pass a rect in pixels for proposedDestRect, you should pass a dictionary with the identity transform for NSImageHintCTM. This method will always return a valid CGImage provided the NSImage is able to draw. If the receiver is unable to draw for whatever reason, the error behavior is the same as when drawing the image. The CGImageRef returned is guaranteed to live as long as the current autorelease pool. The caller should not release the CGImage. This is the standard Cocoa convention, but people may not realize that it applies to CFTypes.
         * @param proposed_dest_rect Argument converted to the Objective-C parameter of the same role.
         * @param reference_context Argument converted to the Objective-C parameter of the same role.
         * @param hints Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        CGImage cg_image_for_proposed_rect(Rect* proposed_dest_rect, const GraphicsContext& reference_context, const std::map<std::string, Object>& hints) const;
        /**
         * @brief Calls `-[NSImage TIFFRepresentationUsingCompression:factor:]`.
         * @param comp Argument converted to the Objective-C parameter of the same role.
         * @param factor Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> tiff_representation_using_compression(TIFFCompression comp, float factor) const;
        /**
         * @brief Calls `-[NSImage addRepresentation:]`.
         * @param image_rep Argument converted to the Objective-C parameter of the same role.
         */
        void add_representation(const ImageRep& image_rep) const;
        /**
         * @brief Calls `-[NSImage addRepresentations:]`.
         * @param image_reps Argument converted to the Objective-C parameter of the same role.
         */
        void add_representations(const std::vector<ImageRep>& image_reps) const;
        /**
         * @brief Calls `-[NSImage bestRepresentationForRect:context:hints:]`.
         * @details Select best representation. The parameters have the same meaning and behavior as in -CGImageForProposedRect:context:hints:.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param reference_context Argument converted to the Objective-C parameter of the same role.
         * @param hints Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        ImageRep best_representation_for_rect(const Rect& rect, const GraphicsContext& reference_context, const std::map<std::string, Object>& hints) const;
        /**
         * @brief Calls `+[NSImage canInitWithPasteboard:]`.
         * @param pasteboard Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static bool can_init_with_pasteboard(const Pasteboard& pasteboard);
        /**
         * @brief Calls `-[NSImage drawAtPoint:fromRect:operation:fraction:]`.
         * @param point Argument converted to the Objective-C parameter of the same role.
         * @param from_rect Argument converted to the Objective-C parameter of the same role.
         * @param op Argument converted to the Objective-C parameter of the same role.
         * @param delta Argument converted to the Objective-C parameter of the same role.
         */
        void draw_at_point(const Point& point, const Rect& from_rect, CompositingOperation op, double delta) const;
        /**
         * @brief Calls `-[NSImage drawInRect:]`.
         * @details This is exactly equivalent to calling -[image drawInRect:rect fromRect:NSZeroRect operation:NSCompositeSourceOver fraction:1 respectFlipped:YES hints:nil].
         * @param rect Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& rect) const;
        /**
         * @brief Calls `-[NSImage drawInRect:fromRect:operation:fraction:]`.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param from_rect Argument converted to the Objective-C parameter of the same role.
         * @param op Argument converted to the Objective-C parameter of the same role.
         * @param delta Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& rect, const Rect& from_rect, CompositingOperation op, double delta) const;
        /**
         * @brief Calls `-[NSImage drawInRect:fromRect:operation:fraction:respectFlipped:hints:]`.
         * @param dst_space_portion_rect Argument converted to the Objective-C parameter of the same role.
         * @param src_space_portion_rect Argument converted to the Objective-C parameter of the same role.
         * @param op Argument converted to the Objective-C parameter of the same role.
         * @param requested_alpha Argument converted to the Objective-C parameter of the same role.
         * @param respect_context_is_flipped Argument converted to the Objective-C parameter of the same role.
         * @param hints Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& dst_space_portion_rect, const Rect& src_space_portion_rect, CompositingOperation op, double requested_alpha, bool respect_context_is_flipped, const std::map<std::string, Object>& hints) const;
        /**
         * @brief Calls `-[NSImage drawRepresentation:inRect:]`.
         * @param image_rep Argument converted to the Objective-C parameter of the same role.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool draw_representation(const ImageRep& image_rep, const Rect& rect) const;
        /**
         * @brief Calls `-[NSImage hitTestRect:withImageDestinationRect:context:hints:flipped:]`.
         * @details Answers the question, "If you were to draw the image in the passed destination rect in the passed context respecting the passed flippedness with the passed hints, would the test rect in the context intersect a non-transparent portion of the image?"
         * @param test_rect_dest_space Argument converted to the Objective-C parameter of the same role.
         * @param image_rect_dest_space Argument converted to the Objective-C parameter of the same role.
         * @param context Argument converted to the Objective-C parameter of the same role.
         * @param hints Argument converted to the Objective-C parameter of the same role.
         * @param flipped Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool hit_test_rect(const Rect& test_rect_dest_space, const Rect& image_rect_dest_space, const GraphicsContext& context, const std::map<std::string, Object>& hints, bool flipped) const;
        /**
         * @brief Calls `+[NSImage imageNamed:]`.
         * @details \#endif / NSIMAGE_UNAVAILABLE_MACCATALYST
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Image image_named(const std::string& name);
        /**
         * @brief Calls `-[NSImage imageWithLocale:]`.
         * @details Creates and returns a new image with the specified locale. If the receiver contains locale-sensitive representations, the returned image will prefer to draw using representations appropriate for the specified locale. If locale is 'nil', the returned image uses the default behavior of choosing representations appropriate for the system’s currently-configured locale.
         * @param locale Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image image_with_locale(const Locale& locale) const;
        /**
         * @brief Calls `-[NSImage imageWithSymbolConfiguration:]`.
         * @param configuration Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Image image_with_symbol_configuration(const ImageSymbolConfiguration& configuration) const;
        /**
         * @brief Calls `-[NSImage layerContentsForContentsScale:]`.
         * @param layer_contents_scale Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object layer_contents_for_contents_scale(double layer_contents_scale) const;
        /**
         * @brief Calls `-[NSImage lockFocus]`.
         */
        void lock_focus() const;
        /**
         * @brief Calls `-[NSImage lockFocusFlipped:]`.
         * @param flipped Argument converted to the Objective-C parameter of the same role.
         */
        void lock_focus_flipped(bool flipped) const;
        /**
         * @brief Calls `-[NSImage name]`.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Calls `-[NSImage recache]`.
         */
        void recache() const;
        /**
         * @brief Calls `-[NSImage recommendedLayerContentsScale:]`.
         * @param preferred_contents_scale Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        double recommended_layer_contents_scale(double preferred_contents_scale) const;
        /**
         * @brief Calls `-[NSImage removeRepresentation:]`.
         * @param image_rep Argument converted to the Objective-C parameter of the same role.
         */
        void remove_representation(const ImageRep& image_rep) const;
        /**
         * @brief Calls `-[NSImage setName:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool set_name(const std::string& string) const;
        /**
         * @brief Calls `-[NSImage unlockFocus]`.
         */
        void unlock_focus() const;
        /**
         * @brief Returns the `TIFFRepresentation` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> tiff_representation() const;
        /**
         * @brief Returns the `accessibilityDescription` property of `NSImage`.
         * @details An accessibility description can be set on an image. This description will be used automatically by interface elements that display images. Like all accessibility descriptions, the string should be a short localized string that does not include the name of the interface element. For instance, "delete" rather than "delete button".
         * @return The converted Objective-C result.
         */
        std::string accessibility_description() const;
        /**
         * @brief Sets the `accessibilityDescription` property of `NSImage`.
         * @details An accessibility description can be set on an image. This description will be used automatically by interface elements that display images. Like all accessibility descriptions, the string should be a short localized string that does not include the name of the interface element. For instance, "delete" rather than "delete button".
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_accessibility_description(const std::string& value) const;
        /**
         * @brief Returns the `alignmentRect` property of `NSImage`.
         * @details The alignmentRect of an image is metadata that a client may use to help determine layout. The bottom of the rect gives the baseline of the image. The other edges give similar information in other directions. A 20x20 image of a phone icon with a glow might specify an alignmentRect of {{2,2},{16,16}} that excludes the glow. NSButtonCell can take advantage of the alignmentRect to place the image in the same visual location as an 16x16 phone icon without the glow. A 5x5 star that should render high when aligned with text might specify a rect of {{0,-7},{5,12}}. The alignmentRect of an image has no effect on methods such as drawInRect:fromRect:operation:Fraction: or drawAtPoint:fromRect:operation:fraction:. It is the client's responsibility to take the alignmentRect into account where applicable. The default alignmentRect of an image is {{0,0},imageSize}. The rect is adjusted when setSize: is called.
         * @return The converted Objective-C result.
         */
        Rect alignment_rect() const;
        /**
         * @brief Sets the `alignmentRect` property of `NSImage`.
         * @details The alignmentRect of an image is metadata that a client may use to help determine layout. The bottom of the rect gives the baseline of the image. The other edges give similar information in other directions. A 20x20 image of a phone icon with a glow might specify an alignmentRect of {{2,2},{16,16}} that excludes the glow. NSButtonCell can take advantage of the alignmentRect to place the image in the same visual location as an 16x16 phone icon without the glow. A 5x5 star that should render high when aligned with text might specify a rect of {{0,-7},{5,12}}. The alignmentRect of an image has no effect on methods such as drawInRect:fromRect:operation:Fraction: or drawAtPoint:fromRect:operation:fraction:. It is the client's responsibility to take the alignmentRect into account where applicable. The default alignmentRect of an image is {{0,0},imageSize}. The rect is adjusted when setSize: is called.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_alignment_rect(const Rect& value) const;
        /**
         * @brief Returns the `backgroundColor` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        Color background_color() const;
        /**
         * @brief Sets the `backgroundColor` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_background_color(const Color& value) const;
        /**
         * @brief Returns the `cacheMode` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        ImageCacheMode cache_mode() const;
        /**
         * @brief Sets the `cacheMode` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cache_mode(ImageCacheMode value) const;
        /**
         * @brief Returns the `capInsets` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        Insets cap_insets() const;
        /**
         * @brief Sets the `capInsets` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_cap_insets(const Insets& value) const;
        /**
         * @brief Returns the `imageTypes` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> image_types();
        /**
         * @brief Returns the `imageUnfilteredTypes` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        static std::vector<std::string> image_unfiltered_types();
        /**
         * @brief Returns the `locale` property of `NSImage`.
         * @details The image’s preferred locale for resolving representations, if one has been specified using '-imageWithLocale:'. Otherwise, 'nil'.
         * @return The converted Objective-C result.
         */
        Locale locale() const;
        /**
         * @brief Returns the `matchesOnMultipleResolution` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool matches_on_multiple_resolution() const;
        /**
         * @brief Sets the `matchesOnMultipleResolution` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_matches_on_multiple_resolution(bool value) const;
        /**
         * @brief Returns the `matchesOnlyOnBestFittingAxis` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool matches_only_on_best_fitting_axis() const;
        /**
         * @brief Sets the `matchesOnlyOnBestFittingAxis` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_matches_only_on_best_fitting_axis(bool value) const;
        /**
         * @brief Returns the `prefersColorMatch` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool prefers_color_match() const;
        /**
         * @brief Sets the `prefersColorMatch` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_prefers_color_match(bool value) const;
        /**
         * @brief Returns the `representations` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        std::vector<ImageRep> representations() const;
        /**
         * @brief Returns the `resizingMode` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        ImageResizingMode resizing_mode() const;
        /**
         * @brief Sets the `resizingMode` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_resizing_mode(ImageResizingMode value) const;
        /**
         * @brief Returns the `size` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        Size size() const;
        /**
         * @brief Sets the `size` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_size(const Size& value) const;
        /**
         * @brief Returns the `symbolConfiguration` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        ImageSymbolConfiguration symbol_configuration() const;
        /**
         * @brief Returns the `template` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool is_template() const;
        /**
         * @brief Sets the `template` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_template(bool value) const;
        /**
         * @brief Returns the `usesEPSOnResolutionMismatch` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool uses_eps_on_resolution_mismatch() const;
        /**
         * @brief Sets the `usesEPSOnResolutionMismatch` property of `NSImage`.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uses_eps_on_resolution_mismatch(bool value) const;
        /**
         * @brief Returns the `valid` property of `NSImage`.
         * @return The converted Objective-C result.
         */
        bool is_valid() const;
        /// @brief Convenience helper `symbol` provided by cocoon.
        static Image symbol(const std::string& name, const std::string& description = {});
        /// @brief Signal for the delegate/data-source method behind `did_not_draw_in_rect`; connect a callback with `did_not_draw_in_rect().connect(...)`.
        Signal<Image, Image(Rect)> did_not_draw_in_rect() const
        {
            return Signal<Image, Image(Rect)>(handle(), "did_not_draw_in_rect");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
