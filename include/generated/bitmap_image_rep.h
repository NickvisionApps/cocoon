#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/image_rep.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CGImage;
    class CIImage;
    class Color;
    class ColorSpace;
    class ImageRep;

    /**
     * @brief C++ handle for the Objective-C class `NSBitmapImageRep` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ImageRep.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BitmapImageRep bitmap_image_rep;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::BitmapImageRep bitmap_image_rep{};
     * bitmap_image_rep.tiff_representation_using_compression(cocoon::TIFFCompression::None, 1);
     * bitmap_image_rep.bitmap_image_rep_by_converting_to_color_space(cocoon::ColorSpace(), cocoon::ColorRenderingIntent::Default);
     * bitmap_image_rep.bitmap_image_rep_by_retagging_with_color_space(cocoon::ColorSpace());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbitmapimagerep
     */
    class BitmapImageRep : public ImageRep
    {
    public:
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep();
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep(std::uint8_t** planes, std::int64_t width, std::int64_t height, std::int64_t bps, std::int64_t spp, bool alpha, bool is_planar, const std::string& color_space_name, BitmapFormat bitmap_format, std::int64_t r_bytes, std::int64_t p_bits);
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep(std::uint8_t** planes, std::int64_t width, std::int64_t height, std::int64_t bps, std::int64_t spp, bool alpha, bool is_planar, const std::string& color_space_name, std::int64_t r_bytes, std::int64_t p_bits);
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep(const CGImage& cg_image);
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep(const CIImage& ci_image);
        /// @brief Creates a new `NSBitmapImageRep` instance and returns a handle to it.
        explicit BitmapImageRep(const std::vector<std::uint8_t>& data);
        /// @brief Creates a null handle that refers to no native object.
        BitmapImageRep(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BitmapImageRep(Adopt adopt);
        /**
     * @brief Calls `+[NSBitmapImageRep TIFFRepresentationOfImageRepsInArray:]`.
     * @param array Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> tiff_representation_of_image_reps_in_array(const std::vector<ImageRep>& array);
        /**
     * @brief Calls `+[NSBitmapImageRep TIFFRepresentationOfImageRepsInArray:usingCompression:factor:]`.
     * @param array Argument converted to the Objective-C parameter of the same role.
     * @param comp Argument converted to the Objective-C parameter of the same role.
     * @param factor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> tiff_representation_of_image_reps_in_array(const std::vector<ImageRep>& array, TIFFCompression comp, float factor);
        /**
     * @brief Calls `-[NSBitmapImageRep TIFFRepresentationUsingCompression:factor:]`.
     * @param comp Argument converted to the Objective-C parameter of the same role.
     * @param factor Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> tiff_representation_using_compression(TIFFCompression comp, float factor) const;
        /**
     * @brief Calls `-[NSBitmapImageRep bitmapImageRepByConvertingToColorSpace:renderingIntent:]`.
     * @param target_space Argument converted to the Objective-C parameter of the same role.
     * @param rendering_intent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BitmapImageRep bitmap_image_rep_by_converting_to_color_space(const ColorSpace& target_space, ColorRenderingIntent rendering_intent) const;
        /**
     * @brief Calls `-[NSBitmapImageRep bitmapImageRepByRetaggingWithColorSpace:]`.
     * @param new_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BitmapImageRep bitmap_image_rep_by_retagging_with_color_space(const ColorSpace& new_space) const;
        /**
     * @brief Calls `-[NSBitmapImageRep canBeCompressedUsing:]`.
     * @param compression Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool can_be_compressed_using(TIFFCompression compression) const;
        /**
     * @brief Calls `-[NSBitmapImageRep colorAtX:y:]`.
     * @param x Argument converted to the Objective-C parameter of the same role.
     * @param y Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Color color_at_x(std::int64_t x, std::int64_t y) const;
        /**
     * @brief Calls `-[NSBitmapImageRep colorizeByMappingGray:toColor:blackMapping:whiteMapping:]`.
     * @details Support for colorization of grayscale images. Maps the image such that: Gray value of midPoint -> midPointColor, black -> shadowColor, white -> lightColor. Works on images with 8-bit SPP; thus either 8-bit gray or 24-bit color (with optional alpha).
     * @param mid_point Argument converted to the Objective-C parameter of the same role.
     * @param mid_point_color Argument converted to the Objective-C parameter of the same role.
     * @param shadow_color Argument converted to the Objective-C parameter of the same role.
     * @param light_color Argument converted to the Objective-C parameter of the same role.
     */
        void colorize_by_mapping_gray(double mid_point, const Color& mid_point_color, const Color& shadow_color, const Color& light_color) const;
        /**
     * @brief Calls `-[NSBitmapImageRep getBitmapDataPlanes:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     */
        void get_bitmap_data_planes(std::uint8_t** data) const;
        /**
     * @brief Calls `-[NSBitmapImageRep getCompression:factor:]`.
     * @param compression Argument converted to the Objective-C parameter of the same role.
     * @param factor Argument converted to the Objective-C parameter of the same role.
     */
        void get_compression(TIFFCompression* compression, float* factor) const;
        /**
     * @brief Calls `-[NSBitmapImageRep getPixel:atX:y:]`.
     * @param p Argument converted to the Objective-C parameter of the same role.
     * @param x Argument converted to the Objective-C parameter of the same role.
     * @param y Argument converted to the Objective-C parameter of the same role.
     */
        void get_pixel(std::uint64_t* p, std::int64_t x, std::int64_t y) const;
        /**
     * @brief Calls `+[NSBitmapImageRep getTIFFCompressionTypes:count:]`.
     * @param list Argument converted to the Objective-C parameter of the same role.
     * @param num_types Argument converted to the Objective-C parameter of the same role.
     */
        static void get_tiff_compression_types(TIFFCompression** list, std::int64_t* num_types);
        /**
     * @brief Calls `+[NSBitmapImageRep imageRepWithData:]`.
     * @details + (NSArray\<NSImageRep > )imageRepsWithData:(NSData )data; / some file formats can contain multiple images
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BitmapImageRep image_rep_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[NSBitmapImageRep imageRepsWithData:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<ImageRep> image_reps_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `-[NSBitmapImageRep incrementalLoadFromData:complete:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param complete Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t incremental_load_from_data(const std::vector<std::uint8_t>& data, bool complete) const;
        /**
     * @brief Calls `+[NSBitmapImageRep localizedNameForTIFFCompressionType:]`.
     * @param compression Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string localized_name_for_tiff_compression_type(TIFFCompression compression);
        /**
     * @brief Calls `+[NSBitmapImageRep representationOfImageRepsInArray:usingType:properties:]`.
     * @param image_reps Argument converted to the Objective-C parameter of the same role.
     * @param storage_type Argument converted to the Objective-C parameter of the same role.
     * @param properties Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> representation_of_image_reps_in_array(const std::vector<ImageRep>& image_reps, BitmapImageFileType storage_type, const std::map<std::string, Object>& properties);
        /**
     * @brief Calls `-[NSBitmapImageRep representationUsingType:properties:]`.
     * @param storage_type Argument converted to the Objective-C parameter of the same role.
     * @param properties Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> representation_using_type(BitmapImageFileType storage_type, const std::map<std::string, Object>& properties) const;
        /**
     * @brief Calls `-[NSBitmapImageRep setColor:atX:y:]`.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @param x Argument converted to the Objective-C parameter of the same role.
     * @param y Argument converted to the Objective-C parameter of the same role.
     */
        void set_color(const Color& color, std::int64_t x, std::int64_t y) const;
        /**
     * @brief Calls `-[NSBitmapImageRep setCompression:factor:]`.
     * @param compression Argument converted to the Objective-C parameter of the same role.
     * @param factor Argument converted to the Objective-C parameter of the same role.
     */
        void set_compression(TIFFCompression compression, float factor) const;
        /**
     * @brief Calls `-[NSBitmapImageRep setPixel:atX:y:]`.
     * @param p Argument converted to the Objective-C parameter of the same role.
     * @param x Argument converted to the Objective-C parameter of the same role.
     * @param y Argument converted to the Objective-C parameter of the same role.
     */
        void set_pixel(std::uint64_t* p, std::int64_t x, std::int64_t y) const;
        /**
     * @brief Calls `-[NSBitmapImageRep setProperty:withValue:]`.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_property(const std::string& property, const Object& value) const;
        /**
     * @brief Calls `-[NSBitmapImageRep valueForProperty:]`.
     * @param property Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object value_for_property(const std::string& property) const;
        /**
     * @brief Returns the `CGImage` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        CGImage cg_image() const;
        /**
     * @brief Returns the `TIFFRepresentation` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> tiff_representation() const;
        /**
     * @brief Returns the `bitmapData` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::uint8_t* bitmap_data() const;
        /**
     * @brief Returns the `bitmapFormat` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        BitmapFormat bitmap_format() const;
        /**
     * @brief Returns the `bitsPerPixel` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t bits_per_pixel() const;
        /**
     * @brief Returns the `bytesPerPlane` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t bytes_per_plane() const;
        /**
     * @brief Returns the `bytesPerRow` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t bytes_per_row() const;
        /**
     * @brief Returns the `colorSpace` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        ColorSpace color_space() const;
        /**
     * @brief Returns the `numberOfPlanes` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_planes() const;
        /**
     * @brief Returns the `planar` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        bool is_planar() const;
        /**
     * @brief Returns the `samplesPerPixel` property of `NSBitmapImageRep`.
     * @return The converted Objective-C result.
     */
        std::int64_t samples_per_pixel() const;
    };
}
