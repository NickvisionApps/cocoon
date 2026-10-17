#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGImage;
    class GraphicsContext;
    class Pasteboard;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ImageRep image_rep;
     * image_rep.set_alpha(true);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ImageRep image_rep{};
     * image_rep.set_alpha(true);
     * auto alpha = image_rep.has_alpha();
     * image_rep.set_bits_per_sample(1);
     * auto bits_per_sample = image_rep.bits_per_sample();
     * image_rep.set_color_space_name("text");
     * auto color_space_name = image_rep.color_space_name();
     * auto made_0 = cocoon::ImageRep::image_rep_with_contents_of_file("text");
     * auto made_1 = cocoon::ImageRep::image_rep_with_contents_of_url(cocoon::URL());
     * image_rep.draw();
     * image_rep.draw_at_point({0, 0});
     * image_rep.draw_in_rect({{0, 0}, {100, 100}});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsimagerep
     */
    class ImageRep : public Object
    {
    public:
        /// @brief Creates a new `NSImageRep` instance and returns a handle to it.
        explicit ImageRep();
        /// @brief Creates a null handle that refers to no native object.
        ImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ImageRep(Adopt adopt);
        /**
     * @brief Calls `-[NSImageRep CGImageForProposedRect:context:hints:]`.
     * @details The parameters have the same meaning and behavior as in -[NSImage CGImageForProposedRect:context:hints:]. This method is intended to be overridden or called, though the primary caller is NSImage. At the NSImageRep level, it creates a CGImage by drawing the receiver into a new context. The passed context and hints are used as a model for the new context. If [self draw] returns NO, this method returns NULL. If your image rep subclass naturally uses a CGImage that it can return, override this method and return it. You should not need to take care to cache within an implementation of this method. This main caller of this method is typically NSImage, and NSImage will hold onto the resulting CGImage if appropriate. The CGImageRef returned is guaranteed to live as long as the current autorelease pool. The caller should not release the CGImage. This is the standard Cocoa convention, but people may not realize that it applies to CFTypes.
     * @param proposed_dest_rect Argument converted to the Objective-C parameter of the same role.
     * @param context Argument converted to the Objective-C parameter of the same role.
     * @param hints Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CGImage cg_image_for_proposed_rect(Rect* proposed_dest_rect, const GraphicsContext& context, const std::map<std::string, Object>& hints) const;
        /**
     * @brief Calls `+[NSImageRep canInitWithData:]`.
     * @details Should be overridden by subclassers to load an unfiltered image.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSImageRep canInitWithPasteboard:]`.
     * @details Convenience method: Checks to see if any of the types on the pasteboard can be understood by a registered imagerep class after filtering or if the pasteboard contains a filename that can be understood by a registered imagerep class after filtering. If sent to a subclass, does this for just the types understood by the subclass.
     * @param pasteboard Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool can_init_with_pasteboard(const Pasteboard& pasteboard);
        /**
     * @brief Calls `-[NSImageRep draw]`.
     * @details Drawing methods. draw is the only primitive.
     * @return The converted Objective-C result.
     */
        bool draw() const;
        /**
     * @brief Calls `-[NSImageRep drawAtPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool draw_at_point(const Point& point) const;
        /**
     * @brief Calls `-[NSImageRep drawInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool draw_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSImageRep drawInRect:fromRect:operation:fraction:respectFlipped:hints:]`.
     * @param dst_space_portion_rect Argument converted to the Objective-C parameter of the same role.
     * @param src_space_portion_rect Argument converted to the Objective-C parameter of the same role.
     * @param op Argument converted to the Objective-C parameter of the same role.
     * @param requested_alpha Argument converted to the Objective-C parameter of the same role.
     * @param respect_context_is_flipped Argument converted to the Objective-C parameter of the same role.
     * @param hints Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool draw_in_rect(const Rect& dst_space_portion_rect, const Rect& src_space_portion_rect, CompositingOperation op, double requested_alpha, bool respect_context_is_flipped, const std::map<std::string, Object>& hints) const;
        /**
     * @brief Calls `+[NSImageRep imageRepClassForData:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string image_rep_class_for_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSImageRep imageRepClassForType:]`.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string image_rep_class_for_type(const std::string& type);
        /**
     * @brief Calls `+[NSImageRep imageRepWithContentsOfFile:]`.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageRep image_rep_with_contents_of_file(const std::string& filename);
        /**
     * @brief Calls `+[NSImageRep imageRepWithContentsOfURL:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageRep image_rep_with_contents_of_url(const URL& url);
        /**
     * @brief Calls `+[NSImageRep imageRepWithPasteboard:]`.
     * @param pasteboard Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ImageRep image_rep_with_pasteboard(const Pasteboard& pasteboard);
        /**
     * @brief Calls `+[NSImageRep imageRepsWithContentsOfFile:]`.
     * @details Convenience methods: Checks to see if the provided file or pasteboard types can be understood by a registered imagerep class after filtering; if so, calls imageRepsWithData: or imageRepWithData:. If sent to a subclass, does this just for the types understood by that subclass.
     * @param filename Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<ImageRep> image_reps_with_contents_of_file(const std::string& filename);
        /**
     * @brief Calls `+[NSImageRep imageRepsWithContentsOfURL:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<ImageRep> image_reps_with_contents_of_url(const URL& url);
        /**
     * @brief Calls `+[NSImageRep imageRepsWithPasteboard:]`.
     * @param pasteboard Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<ImageRep> image_reps_with_pasteboard(const Pasteboard& pasteboard);
        /**
     * @brief Calls `+[NSImageRep registerImageRepClass:]`.
     * @details Registry management: Subclasses which deal with file & pasteboard types should register themselves. These classes should also implement imageUnfilteredFileTypes, imageUnfilteredPasteboardTypes, initWithData:, canInitWithData:, imageRepWithData:, and, if they have the ability to read multiple images from a file, imageRepsWithData:. These last three should not do any filtering; all filtering is automatic.
     * @param image_rep_class Argument converted to the Objective-C parameter of the same role.
     */
        static void register_image_rep_class(const std::string& image_rep_class);
        /**
     * @brief Calls `+[NSImageRep unregisterImageRepClass:]`.
     * @param image_rep_class Argument converted to the Objective-C parameter of the same role.
     */
        static void unregister_image_rep_class(const std::string& image_rep_class);
        /**
     * @brief Returns the `alpha` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        bool has_alpha() const;
        /**
     * @brief Sets the `alpha` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_alpha(bool value) const;
        /**
     * @brief Returns the `bitsPerSample` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t bits_per_sample() const;
        /**
     * @brief Sets the `bitsPerSample` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bits_per_sample(std::int64_t value) const;
        /**
     * @brief Returns the `colorSpaceName` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        std::string color_space_name() const;
        /**
     * @brief Sets the `colorSpaceName` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_color_space_name(const std::string& value) const;
        /**
     * @brief Returns the `imageTypes` property of `NSImageRep`.
     * @details This expands the unfiltered list returned by imageUnfilteredTypes.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> image_types();
        /**
     * @brief Returns the `imageUnfilteredTypes` property of `NSImageRep`.
     * @details Implemented by subclassers to indicate what UTI-identified data types they can deal with.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> image_unfiltered_types();
        /**
     * @brief Returns the `layoutDirection` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        ImageLayoutDirection layout_direction() const;
        /**
     * @brief Sets the `layoutDirection` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_layout_direction(ImageLayoutDirection value) const;
        /**
     * @brief Returns the `opaque` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Sets the `opaque` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_opaque(bool value) const;
        /**
     * @brief Returns the `pixelsHigh` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t pixels_high() const;
        /**
     * @brief Sets the `pixelsHigh` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pixels_high(std::int64_t value) const;
        /**
     * @brief Returns the `pixelsWide` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t pixels_wide() const;
        /**
     * @brief Sets the `pixelsWide` property of `NSImageRep`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_pixels_wide(std::int64_t value) const;
        /**
     * @brief Returns the `registeredImageRepClasses` property of `NSImageRep`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> registered_image_rep_classes();
        /**
     * @brief Returns the `size` property of `NSImageRep`.
     * @details Methods to return info about the image. NSImageRep provides storage for all of these; however, it's illegal to set them in some subclasses.
     * @return The converted Objective-C result.
     */
        Size size() const;
        /**
     * @brief Sets the `size` property of `NSImageRep`.
     * @details Methods to return info about the image. NSImageRep provides storage for all of these; however, it's illegal to set them in some subclasses.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_size(const Size& value) const;
    };
}
