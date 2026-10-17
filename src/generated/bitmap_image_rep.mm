#include "generated/bitmap_image_rep.h"
#include "internal.h"

namespace cocoon
{
    BitmapImageRep::BitmapImageRep() : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initForIncrementalLoad])})
    {
    }

    BitmapImageRep::BitmapImageRep(std::uint8_t** planes, std::int64_t width, std::int64_t height, std::int64_t bps, std::int64_t spp, bool alpha, bool is_planar, const std::string& color_space_name, BitmapFormat bitmap_format, std::int64_t r_bytes, std::int64_t p_bits) : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initWithBitmapDataPlanes:(unsigned char**)(planes) pixelsWide:static_cast<::NSInteger>(width) pixelsHigh:static_cast<::NSInteger>(height) bitsPerSample:static_cast<::NSInteger>(bps) samplesPerPixel:static_cast<::NSInteger>(spp) hasAlpha:static_cast<::BOOL>(alpha) isPlanar:static_cast<::BOOL>(is_planar) colorSpaceName:cocoon::internal::to(color_space_name) bitmapFormat:static_cast<::NSBitmapFormat>(bitmap_format) bytesPerRow:static_cast<::NSInteger>(r_bytes) bitsPerPixel:static_cast<::NSInteger>(p_bits)])})
    {
    }

    BitmapImageRep::BitmapImageRep(std::uint8_t** planes, std::int64_t width, std::int64_t height, std::int64_t bps, std::int64_t spp, bool alpha, bool is_planar, const std::string& color_space_name, std::int64_t r_bytes, std::int64_t p_bits) : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initWithBitmapDataPlanes:(unsigned char**)(planes) pixelsWide:static_cast<::NSInteger>(width) pixelsHigh:static_cast<::NSInteger>(height) bitsPerSample:static_cast<::NSInteger>(bps) samplesPerPixel:static_cast<::NSInteger>(spp) hasAlpha:static_cast<::BOOL>(alpha) isPlanar:static_cast<::BOOL>(is_planar) colorSpaceName:cocoon::internal::to(color_space_name) bytesPerRow:static_cast<::NSInteger>(r_bytes) bitsPerPixel:static_cast<::NSInteger>(p_bits)])})
    {
    }

    BitmapImageRep::BitmapImageRep(const CGImage& cg_image) : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initWithCGImage:((::CGImageRef)(cg_image).handle())])})
    {
    }

    BitmapImageRep::BitmapImageRep(const CIImage& ci_image) : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initWithCIImage:cocoon::internal::native<::CIImage>(ci_image)])})
    {
    }

    BitmapImageRep::BitmapImageRep(const std::vector<std::uint8_t>& data) : BitmapImageRep(Adopt{cocoon::internal::retain([[::NSBitmapImageRep alloc] initWithData:cocoon::internal::to_data(data)])})
    {
    }

    BitmapImageRep::BitmapImageRep(std::nullptr_t) : ImageRep(nullptr)
    {
    }

    BitmapImageRep::BitmapImageRep(Adopt adopt) : ImageRep(adopt)
    {
    }

    std::vector<std::uint8_t> BitmapImageRep::tiff_representation_of_image_reps_in_array(const std::vector<ImageRep>& array)
    {
        return cocoon::internal::from_data([::NSBitmapImageRep TIFFRepresentationOfImageRepsInArray:cocoon::internal::to_array(array, [](const ImageRep& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSImageRep>(e);
                                                                                                   })]);
    }

    std::vector<std::uint8_t> BitmapImageRep::tiff_representation_of_image_reps_in_array(const std::vector<ImageRep>& array, TIFFCompression comp, float factor)
    {
        return cocoon::internal::from_data([::NSBitmapImageRep TIFFRepresentationOfImageRepsInArray:cocoon::internal::to_array(array, [](const ImageRep& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSImageRep>(e);
                                                                                                   })
                                                                     usingCompression:static_cast<::NSTIFFCompression>(comp)
                                                                               factor:static_cast<float>(factor)]);
    }

    std::vector<std::uint8_t> BitmapImageRep::tiff_representation_using_compression(TIFFCompression comp, float factor) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSBitmapImageRep>(this) TIFFRepresentationUsingCompression:static_cast<::NSTIFFCompression>(comp) factor:static_cast<float>(factor)]);
    }

    BitmapImageRep BitmapImageRep::bitmap_image_rep_by_converting_to_color_space(const ColorSpace& target_space, ColorRenderingIntent rendering_intent) const
    {
        return cocoon::internal::wrap<BitmapImageRep>([cocoon::internal::ns<::NSBitmapImageRep>(this) bitmapImageRepByConvertingToColorSpace:cocoon::internal::native<::NSColorSpace>(target_space) renderingIntent:static_cast<::NSColorRenderingIntent>(rendering_intent)]);
    }

    BitmapImageRep BitmapImageRep::bitmap_image_rep_by_retagging_with_color_space(const ColorSpace& new_space) const
    {
        return cocoon::internal::wrap<BitmapImageRep>([cocoon::internal::ns<::NSBitmapImageRep>(this) bitmapImageRepByRetaggingWithColorSpace:cocoon::internal::native<::NSColorSpace>(new_space)]);
    }

    bool BitmapImageRep::can_be_compressed_using(TIFFCompression compression) const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBitmapImageRep>(this) canBeCompressedUsing:static_cast<::NSTIFFCompression>(compression)]);
    }

    Color BitmapImageRep::color_at_x(std::int64_t x, std::int64_t y) const
    {
        return cocoon::internal::wrap<Color>([cocoon::internal::ns<::NSBitmapImageRep>(this) colorAtX:static_cast<::NSInteger>(x) y:static_cast<::NSInteger>(y)]);
    }

    void BitmapImageRep::colorize_by_mapping_gray(double mid_point, const Color& mid_point_color, const Color& shadow_color, const Color& light_color) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) colorizeByMappingGray:static_cast<::CGFloat>(mid_point) toColor:cocoon::internal::native<::NSColor>(mid_point_color) blackMapping:cocoon::internal::native<::NSColor>(shadow_color) whiteMapping:cocoon::internal::native<::NSColor>(light_color)];
    }

    void BitmapImageRep::get_bitmap_data_planes(std::uint8_t** data) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) getBitmapDataPlanes:(unsigned char**)(data)];
    }

    void BitmapImageRep::get_compression(TIFFCompression* compression, float* factor) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) getCompression:(::NSTIFFCompression*)(compression) factor:(float*)(factor)];
    }

    void BitmapImageRep::get_pixel(std::uint64_t* p, std::int64_t x, std::int64_t y) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) getPixel:(::NSUInteger*)(p) atX:static_cast<::NSInteger>(x) y:static_cast<::NSInteger>(y)];
    }

    void BitmapImageRep::get_tiff_compression_types(TIFFCompression** list, std::int64_t* num_types)
    {
        [::NSBitmapImageRep getTIFFCompressionTypes:(const ::NSTIFFCompression**)(list) count:(::NSInteger*)(num_types)];
    }

    BitmapImageRep BitmapImageRep::image_rep_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<BitmapImageRep>([::NSBitmapImageRep imageRepWithData:cocoon::internal::to_data(data)]);
    }

    std::vector<ImageRep> BitmapImageRep::image_reps_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::from_array<ImageRep>([::NSBitmapImageRep imageRepsWithData:cocoon::internal::to_data(data)], [](id e) -> ImageRep
                                        {
                                            return cocoon::internal::wrap<ImageRep>((::NSImageRep*)e);
                                        });
    }

    std::int64_t BitmapImageRep::incremental_load_from_data(const std::vector<std::uint8_t>& data, bool complete) const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) incrementalLoadFromData:cocoon::internal::to_data(data) complete:static_cast<::BOOL>(complete)]);
    }

    std::string BitmapImageRep::localized_name_for_tiff_compression_type(TIFFCompression compression)
    {
        return cocoon::internal::from([::NSBitmapImageRep localizedNameForTIFFCompressionType:static_cast<::NSTIFFCompression>(compression)]);
    }

    std::vector<std::uint8_t> BitmapImageRep::representation_of_image_reps_in_array(const std::vector<ImageRep>& image_reps, BitmapImageFileType storage_type, const std::map<std::string, Object>& properties)
    {
        return cocoon::internal::from_data([::NSBitmapImageRep representationOfImageRepsInArray:cocoon::internal::to_array(image_reps, [](const ImageRep& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSImageRep>(e);
                                                                                               })
                                                                        usingType:static_cast<::NSBitmapImageFileType>(storage_type)
                                                                       properties:cocoon::internal::to_dictionary(properties, [](const std::string& k) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::to(k);
                                                                                                    },
                                                                                                    [](const Object& v) -> id
                                                                                                    {
                                                                                                        return cocoon::internal::native_id(v);
                                                                                                    })]);
    }

    std::vector<std::uint8_t> BitmapImageRep::representation_using_type(BitmapImageFileType storage_type, const std::map<std::string, Object>& properties) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSBitmapImageRep>(this) representationUsingType:static_cast<::NSBitmapImageFileType>(storage_type)
                                                                            properties:cocoon::internal::to_dictionary(properties, [](const std::string& k) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::to(k);
                                                                                                         },
                                                                                                         [](const Object& v) -> id
                                                                                                         {
                                                                                                             return cocoon::internal::native_id(v);
                                                                                                         })]);
    }

    void BitmapImageRep::set_color(const Color& color, std::int64_t x, std::int64_t y) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) setColor:cocoon::internal::native<::NSColor>(color) atX:static_cast<::NSInteger>(x) y:static_cast<::NSInteger>(y)];
    }

    void BitmapImageRep::set_compression(TIFFCompression compression, float factor) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) setCompression:static_cast<::NSTIFFCompression>(compression) factor:static_cast<float>(factor)];
    }

    void BitmapImageRep::set_pixel(std::uint64_t* p, std::int64_t x, std::int64_t y) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) setPixel:(::NSUInteger*)(p) atX:static_cast<::NSInteger>(x) y:static_cast<::NSInteger>(y)];
    }

    void BitmapImageRep::set_property(const std::string& property, const Object& value) const
    {
        [cocoon::internal::ns<::NSBitmapImageRep>(this) setProperty:cocoon::internal::to(property) withValue:cocoon::internal::native_id(value)];
    }

    Object BitmapImageRep::value_for_property(const std::string& property) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSBitmapImageRep>(this) valueForProperty:cocoon::internal::to(property)]);
    }

    CGImage BitmapImageRep::cg_image() const
    {
        return cocoon::internal::wrap_cf<CGImage>((const void*)([cocoon::internal::ns<::NSBitmapImageRep>(this) CGImage]));
    }

    std::vector<std::uint8_t> BitmapImageRep::tiff_representation() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSBitmapImageRep>(this) TIFFRepresentation]);
    }

    std::uint8_t* BitmapImageRep::bitmap_data() const
    {
        return (std::uint8_t*)([cocoon::internal::ns<::NSBitmapImageRep>(this) bitmapData]);
    }

    BitmapFormat BitmapImageRep::bitmap_format() const
    {
        return static_cast<BitmapFormat>([cocoon::internal::ns<::NSBitmapImageRep>(this) bitmapFormat]);
    }

    std::int64_t BitmapImageRep::bits_per_pixel() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) bitsPerPixel]);
    }

    std::int64_t BitmapImageRep::bytes_per_plane() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) bytesPerPlane]);
    }

    std::int64_t BitmapImageRep::bytes_per_row() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) bytesPerRow]);
    }

    ColorSpace BitmapImageRep::color_space() const
    {
        return cocoon::internal::wrap<ColorSpace>([cocoon::internal::ns<::NSBitmapImageRep>(this) colorSpace]);
    }

    std::int64_t BitmapImageRep::number_of_planes() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) numberOfPlanes]);
    }

    bool BitmapImageRep::is_planar() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSBitmapImageRep>(this) isPlanar]);
    }

    std::int64_t BitmapImageRep::samples_per_pixel() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSBitmapImageRep>(this) samplesPerPixel]);
    }
}
