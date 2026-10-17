#include "generated/ci_image.h"
#include "internal.h"

namespace cocoon
{
    CIImage::CIImage(const std::vector<std::uint8_t>& data, std::uint64_t bytes_per_row, const Size& size, int format, const CGColorSpace& color_space) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithBitmapData:cocoon::internal::to_data(data) bytesPerRow:static_cast<::size_t>(bytes_per_row) size:cocoon::internal::to(size) format:static_cast<::CIFormat>(format) colorSpace:((::CGColorSpaceRef)(color_space).handle())])})
    {
    }

    CIImage::CIImage(const BitmapImageRep& bitmap_image_rep) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithBitmapImageRep:cocoon::internal::native<::NSBitmapImageRep>(bitmap_image_rep)])})
    {
    }

    CIImage::CIImage(const CGImage& image) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCGImage:((::CGImageRef)(image).handle())])})
    {
    }

    CIImage::CIImage(const CGImage& image, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCGImage:((::CGImageRef)(image).handle())
                                                                                                                                               options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::to(k);
                                                                                                                                                                         },
                                                                                                                                                                         [](const Object& v) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::native_id(v);
                                                                                                                                                                         })])})
    {
    }

    CIImage::CIImage(const CGImageSource& source, std::uint64_t index, const std::map<std::string, Object>& dict) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCGImageSource:((::CGImageSourceRef)(source).handle())
                                                                                                                                                                                index:static_cast<::size_t>(index)
                                                                                                                                                                              options:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                                                                                                                                        {
                                                                                                                                                                                                            return cocoon::internal::to(k);
                                                                                                                                                                                                        },
                                                                                                                                                                                                        [](const Object& v) -> id
                                                                                                                                                                                                        {
                                                                                                                                                                                                            return cocoon::internal::native_id(v);
                                                                                                                                                                                                        })])})
    {
    }

    CIImage::CIImage(const CVImageBuffer& image_buffer) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCVImageBuffer:((::CVImageBufferRef)(image_buffer).handle())])})
    {
    }

    CIImage::CIImage(const CVImageBuffer& image_buffer, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCVImageBuffer:((::CVImageBufferRef)(image_buffer).handle())
                                                                                                                                                                  options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                                            {
                                                                                                                                                                                                return cocoon::internal::to(k);
                                                                                                                                                                                            },
                                                                                                                                                                                            [](const Object& v) -> id
                                                                                                                                                                                            {
                                                                                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                                                                                            })])})
    {
    }

    CIImage::CIImage(const CVPixelBuffer& pixel_buffer) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCVPixelBuffer:((::CVPixelBufferRef)(pixel_buffer).handle())])})
    {
    }

    CIImage::CIImage(const CVPixelBuffer& pixel_buffer, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithCVPixelBuffer:((::CVPixelBufferRef)(pixel_buffer).handle())
                                                                                                                                                                  options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                                            {
                                                                                                                                                                                                return cocoon::internal::to(k);
                                                                                                                                                                                            },
                                                                                                                                                                                            [](const Object& v) -> id
                                                                                                                                                                                            {
                                                                                                                                                                                                return cocoon::internal::native_id(v);
                                                                                                                                                                                            })])})
    {
    }

    CIImage::CIImage(const CIColor& color) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithColor:cocoon::internal::native<::CIColor>(color)])})
    {
    }

    CIImage::CIImage(const URL& url) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url)])})
    {
    }

    CIImage::CIImage(const URL& url, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url)
                                                                                                                                               options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::to(k);
                                                                                                                                                                         },
                                                                                                                                                                         [](const Object& v) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::native_id(v);
                                                                                                                                                                         })])})
    {
    }

    CIImage::CIImage(const std::vector<std::uint8_t>& data) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithData:cocoon::internal::to_data(data)])})
    {
    }

    CIImage::CIImage(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithData:cocoon::internal::to_data(data)
                                                                                                                                                             options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                                       {
                                                                                                                                                                                           return cocoon::internal::to(k);
                                                                                                                                                                                       },
                                                                                                                                                                                       [](const Object& v) -> id
                                                                                                                                                                                       {
                                                                                                                                                                                           return cocoon::internal::native_id(v);
                                                                                                                                                                                       })])})
    {
    }

    CIImage::CIImage(const Object& data) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithDepthData:cocoon::internal::native_id(data)])})
    {
    }

    CIImage::CIImage(const Object& data, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithDepthData:cocoon::internal::native_id(data)
                                                                                                                                               options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::to(k);
                                                                                                                                                                         },
                                                                                                                                                                         [](const Object& v) -> id
                                                                                                                                                                         {
                                                                                                                                                                             return cocoon::internal::native_id(v);
                                                                                                                                                                         })])})
    {
    }

    CIImage::CIImage(const IOSurface& surface) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithIOSurface:((::IOSurfaceRef)(surface).handle())])})
    {
    }

    CIImage::CIImage(const IOSurface& surface, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithIOSurface:((::IOSurfaceRef)(surface).handle())
                                                                                                                                                     options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                               {
                                                                                                                                                                                   return cocoon::internal::to(k);
                                                                                                                                                                               },
                                                                                                                                                                               [](const Object& v) -> id
                                                                                                                                                                               {
                                                                                                                                                                                   return cocoon::internal::native_id(v);
                                                                                                                                                                               })])})
    {
    }

    CIImage::CIImage(unsigned int name, const Size& size, bool flipped, const CGColorSpace& color_space) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithTexture:static_cast<unsigned int>(name) size:cocoon::internal::to(size) flipped:static_cast<::BOOL>(flipped) colorSpace:((::CGColorSpaceRef)(color_space).handle())])})
    {
    }

    CIImage::CIImage(unsigned int name, const Size& size, bool flipped, const std::map<std::string, Object>& options) : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] initWithTexture:static_cast<unsigned int>(name)
                                                                                                                                                                               size:cocoon::internal::to(size)
                                                                                                                                                                            flipped:static_cast<::BOOL>(flipped)
                                                                                                                                                                            options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                                                                                                      {
                                                                                                                                                                                                          return cocoon::internal::to(k);
                                                                                                                                                                                                      },
                                                                                                                                                                                                      [](const Object& v) -> id
                                                                                                                                                                                                      {
                                                                                                                                                                                                          return cocoon::internal::native_id(v);
                                                                                                                                                                                                      })])})
    {
    }

    CIImage::CIImage() : CIImage(Adopt{cocoon::internal::retain([[::CIImage alloc] init])})
    {
    }

    CIImage::CIImage(std::nullptr_t) : Object(nullptr)
    {
    }

    CIImage::CIImage(Adopt adopt) : Object(adopt)
    {
    }

    std::vector<Object> CIImage::auto_adjustment_filters() const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::CIImage>(this) autoAdjustmentFilters], [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<Object> CIImage::auto_adjustment_filters_with_options(const std::map<std::string, Object>& options) const
    {
        return cocoon::internal::from_array<Object>([cocoon::internal::ns<::CIImage>(this) autoAdjustmentFiltersWithOptions:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::to(k);
                                                                                                                  },
                                                                                                                  [](const Object& v) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(v);
                                                                                                                  })],
                                      [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    void CIImage::draw_at_point(const Point& point, const Rect& from_rect, CompositingOperation op, double delta) const
    {
        [cocoon::internal::ns<::CIImage>(this) drawAtPoint:cocoon::internal::to(point) fromRect:cocoon::internal::to(from_rect) operation:static_cast<::NSCompositingOperation>(op) fraction:static_cast<::CGFloat>(delta)];
    }

    void CIImage::draw_in_rect(const Rect& rect, const Rect& from_rect, CompositingOperation op, double delta) const
    {
        [cocoon::internal::ns<::CIImage>(this) drawInRect:cocoon::internal::to(rect) fromRect:cocoon::internal::to(from_rect) operation:static_cast<::NSCompositingOperation>(op) fraction:static_cast<::CGFloat>(delta)];
    }

    CIImage CIImage::empty_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage emptyImage]);
    }

    CIImage CIImage::image_by_applying_cg_orientation(CGImagePropertyOrientation orientation) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingCGOrientation:static_cast<::CGImagePropertyOrientation>(orientation)]);
    }

    CIImage CIImage::image_by_applying_filter(const std::string& filter_name) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingFilter:cocoon::internal::to(filter_name)]);
    }

    CIImage CIImage::image_by_applying_filter(const std::string& filter_name, const std::map<std::string, Object>& params) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingFilter:cocoon::internal::to(filter_name)
                                                            withInputParameters:cocoon::internal::to_dictionary(params, [](const std::string& k) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::to(k);
                                                                                                  },
                                                                                                  [](const Object& v) -> id
                                                                                                  {
                                                                                                      return cocoon::internal::native_id(v);
                                                                                                  })]);
    }

    CIImage CIImage::image_by_applying_gain_map(const CIImage& gainmap) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingGainMap:cocoon::internal::native<::CIImage>(gainmap)]);
    }

    CIImage CIImage::image_by_applying_gain_map(const CIImage& gainmap, float headroom) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingGainMap:cocoon::internal::native<::CIImage>(gainmap) headroom:static_cast<float>(headroom)]);
    }

    CIImage CIImage::image_by_applying_gaussian_blur_with_sigma(double sigma) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingGaussianBlurWithSigma:static_cast<double>(sigma)]);
    }

    CIImage CIImage::image_by_applying_orientation(int orientation) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingOrientation:static_cast<int>(orientation)]);
    }

    CIImage CIImage::image_by_applying_transform(const AffineTransform3& matrix) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingTransform:cocoon::internal::to(matrix)]);
    }

    CIImage CIImage::image_by_applying_transform(const AffineTransform3& matrix, bool high_quality_downsample) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByApplyingTransform:cocoon::internal::to(matrix) highQualityDownsample:static_cast<::BOOL>(high_quality_downsample)]);
    }

    CIImage CIImage::image_by_clamping_to_extent() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByClampingToExtent]);
    }

    CIImage CIImage::image_by_clamping_to_rect(const Rect& rect) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByClampingToRect:cocoon::internal::to(rect)]);
    }

    CIImage CIImage::image_by_color_matching_color_space_to_working_space(const CGColorSpace& color_space) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByColorMatchingColorSpaceToWorkingSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIImage CIImage::image_by_color_matching_working_space_to_color_space(const CGColorSpace& color_space) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByColorMatchingWorkingSpaceToColorSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIImage CIImage::image_by_compositing_over_image(const CIImage& dest) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByCompositingOverImage:cocoon::internal::native<::CIImage>(dest)]);
    }

    CIImage CIImage::image_by_converting_lab_to_working_space() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByConvertingLabToWorkingSpace]);
    }

    CIImage CIImage::image_by_converting_working_space_to_lab() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByConvertingWorkingSpaceToLab]);
    }

    CIImage CIImage::image_by_cropping_to_rect(const Rect& rect) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByCroppingToRect:cocoon::internal::to(rect)]);
    }

    CIImage CIImage::image_by_inserting_intermediate() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByInsertingIntermediate]);
    }

    CIImage CIImage::image_by_inserting_intermediate(bool cache) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByInsertingIntermediate:static_cast<::BOOL>(cache)]);
    }

    CIImage CIImage::image_by_inserting_tiled_intermediate() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByInsertingTiledIntermediate]);
    }

    CIImage CIImage::image_by_premultiplying_alpha() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByPremultiplyingAlpha]);
    }

    CIImage CIImage::image_by_sampling_linear() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySamplingLinear]);
    }

    CIImage CIImage::image_by_sampling_nearest() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySamplingNearest]);
    }

    CIImage CIImage::image_by_setting_alpha_one_in_extent(const Rect& extent) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySettingAlphaOneInExtent:cocoon::internal::to(extent)]);
    }

    CIImage CIImage::image_by_setting_content_average_light_level(float average) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySettingContentAverageLightLevel:static_cast<float>(average)]);
    }

    CIImage CIImage::image_by_setting_content_headroom(float headroom) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySettingContentHeadroom:static_cast<float>(headroom)]);
    }

    CIImage CIImage::image_by_setting_properties(const std::vector<std::pair<Object, Object>>& properties) const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageBySettingProperties:cocoon::internal::to_dictionary(properties, [](const Object& k) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native_id(k);
                                                                                                     },
                                                                                                     [](const Object& v) -> id
                                                                                                     {
                                                                                                         return cocoon::internal::native_id(v);
                                                                                                     })]);
    }

    CIImage CIImage::image_by_unpremultiplying_alpha() const
    {
        return cocoon::internal::wrap<CIImage>([cocoon::internal::ns<::CIImage>(this) imageByUnpremultiplyingAlpha]);
    }

    AffineTransform3 CIImage::image_transform_for_cg_orientation(CGImagePropertyOrientation orientation) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CIImage>(this) imageTransformForCGOrientation:static_cast<::CGImagePropertyOrientation>(orientation)]);
    }

    AffineTransform3 CIImage::image_transform_for_orientation(int orientation) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CIImage>(this) imageTransformForOrientation:static_cast<int>(orientation)]);
    }

    CIImage CIImage::image_with_bitmap_data(const std::vector<std::uint8_t>& data, std::uint64_t bytes_per_row, const Size& size, int format, const CGColorSpace& color_space)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithBitmapData:cocoon::internal::to_data(data) bytesPerRow:static_cast<::size_t>(bytes_per_row) size:cocoon::internal::to(size) format:static_cast<::CIFormat>(format) colorSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIImage CIImage::image_with_cg_image(const CGImage& image)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCGImage:((::CGImageRef)(image).handle())]);
    }

    CIImage CIImage::image_with_cg_image(const CGImage& image, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCGImage:((::CGImageRef)(image).handle())
                                                     options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                               {
                                                                                   return cocoon::internal::to(k);
                                                                               },
                                                                               [](const Object& v) -> id
                                                                               {
                                                                                   return cocoon::internal::native_id(v);
                                                                               })]);
    }

    CIImage CIImage::image_with_cg_image_source(const CGImageSource& source, std::uint64_t index, const std::map<std::string, Object>& dict)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCGImageSource:((::CGImageSourceRef)(source).handle())
                                                             index:static_cast<::size_t>(index)
                                                           options:cocoon::internal::to_dictionary(dict, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })]);
    }

    CIImage CIImage::image_with_cv_image_buffer(const CVImageBuffer& image_buffer)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCVImageBuffer:((::CVImageBufferRef)(image_buffer).handle())]);
    }

    CIImage CIImage::image_with_cv_image_buffer(const CVImageBuffer& image_buffer, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCVImageBuffer:((::CVImageBufferRef)(image_buffer).handle())
                                                           options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })]);
    }

    CIImage CIImage::image_with_cv_pixel_buffer(const CVPixelBuffer& pixel_buffer)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCVPixelBuffer:((::CVPixelBufferRef)(pixel_buffer).handle())]);
    }

    CIImage CIImage::image_with_cv_pixel_buffer(const CVPixelBuffer& pixel_buffer, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithCVPixelBuffer:((::CVPixelBufferRef)(pixel_buffer).handle())
                                                           options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })]);
    }

    CIImage CIImage::image_with_color(const CIColor& color)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithColor:cocoon::internal::native<::CIColor>(color)]);
    }

    CIImage CIImage::image_with_contents_of_url(const URL& url)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithContentsOfURL:cocoon::internal::native<::NSURL>(url)]);
    }

    CIImage CIImage::image_with_contents_of_url(const URL& url, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithContentsOfURL:cocoon::internal::native<::NSURL>(url)
                                                           options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                     {
                                                                                         return cocoon::internal::to(k);
                                                                                     },
                                                                                     [](const Object& v) -> id
                                                                                     {
                                                                                         return cocoon::internal::native_id(v);
                                                                                     })]);
    }

    CIImage CIImage::image_with_data(const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithData:cocoon::internal::to_data(data)]);
    }

    CIImage CIImage::image_with_data(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithData:cocoon::internal::to_data(data)
                                                  options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                            {
                                                                                return cocoon::internal::to(k);
                                                                            },
                                                                            [](const Object& v) -> id
                                                                            {
                                                                                return cocoon::internal::native_id(v);
                                                                            })]);
    }

    CIImage CIImage::image_with_depth_data(const Object& data)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithDepthData:cocoon::internal::native_id(data)]);
    }

    CIImage CIImage::image_with_depth_data(const Object& data, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithDepthData:cocoon::internal::native_id(data)
                                                       options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                 {
                                                                                     return cocoon::internal::to(k);
                                                                                 },
                                                                                 [](const Object& v) -> id
                                                                                 {
                                                                                     return cocoon::internal::native_id(v);
                                                                                 })]);
    }

    CIImage CIImage::image_with_io_surface(const IOSurface& surface)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithIOSurface:((::IOSurfaceRef)(surface).handle())]);
    }

    CIImage CIImage::image_with_io_surface(const IOSurface& surface, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithIOSurface:((::IOSurfaceRef)(surface).handle())
                                                       options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                 {
                                                                                     return cocoon::internal::to(k);
                                                                                 },
                                                                                 [](const Object& v) -> id
                                                                                 {
                                                                                     return cocoon::internal::native_id(v);
                                                                                 })]);
    }

    CIImage CIImage::image_with_mtl_texture(const Object& texture, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithMTLTexture:cocoon::internal::native_id(texture)
                                                        options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                  {
                                                                                      return cocoon::internal::to(k);
                                                                                  },
                                                                                  [](const Object& v) -> id
                                                                                  {
                                                                                      return cocoon::internal::native_id(v);
                                                                                  })]);
    }

    CIImage CIImage::image_with_portait_effects_matte(const Object& matte)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithPortaitEffectsMatte:cocoon::internal::native_id(matte)]);
    }

    CIImage CIImage::image_with_portait_effects_matte(const Object& matte, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithPortaitEffectsMatte:cocoon::internal::native_id(matte)
                                                                 options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                           {
                                                                                               return cocoon::internal::to(k);
                                                                                           },
                                                                                           [](const Object& v) -> id
                                                                                           {
                                                                                               return cocoon::internal::native_id(v);
                                                                                           })]);
    }

    CIImage CIImage::image_with_semantic_segmentation_matte(const Object& matte)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithSemanticSegmentationMatte:cocoon::internal::native_id(matte)]);
    }

    CIImage CIImage::image_with_semantic_segmentation_matte(const Object& matte, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithSemanticSegmentationMatte:cocoon::internal::native_id(matte)
                                                                       options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::to(k);
                                                                                                 },
                                                                                                 [](const Object& v) -> id
                                                                                                 {
                                                                                                     return cocoon::internal::native_id(v);
                                                                                                 })]);
    }

    CIImage CIImage::image_with_texture(unsigned int name, const Size& size, bool flipped, const CGColorSpace& color_space)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithTexture:static_cast<unsigned int>(name) size:cocoon::internal::to(size) flipped:static_cast<::BOOL>(flipped) colorSpace:((::CGColorSpaceRef)(color_space).handle())]);
    }

    CIImage CIImage::image_with_texture(unsigned int name, const Size& size, bool flipped, const std::map<std::string, Object>& options)
    {
        return cocoon::internal::wrap<CIImage>([::CIImage imageWithTexture:static_cast<unsigned int>(name)
                                                        size:cocoon::internal::to(size)
                                                     flipped:static_cast<::BOOL>(flipped)
                                                     options:cocoon::internal::to_dictionary(options, [](const std::string& k) -> id
                                                                               {
                                                                                   return cocoon::internal::to(k);
                                                                               },
                                                                               [](const Object& v) -> id
                                                                               {
                                                                                   return cocoon::internal::native_id(v);
                                                                               })]);
    }

    Rect CIImage::region_of_interest_for_image(const CIImage& image, const Rect& rect) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CIImage>(this) regionOfInterestForImage:cocoon::internal::native<::CIImage>(image) inRect:cocoon::internal::to(rect)]);
    }

    CGImage CIImage::cg_image() const
    {
        return cocoon::internal::wrap_cf<CGImage>((const void*)([cocoon::internal::ns<::CIImage>(this) CGImage]));
    }

    CIImage CIImage::black_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage blackImage]);
    }

    CIImage CIImage::blue_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage blueImage]);
    }

    CIImage CIImage::clear_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage clearImage]);
    }

    CGColorSpace CIImage::color_space() const
    {
        return cocoon::internal::wrap_cf<CGColorSpace>((const void*)([cocoon::internal::ns<::CIImage>(this) colorSpace]));
    }

    float CIImage::content_average_light_level() const
    {
        return static_cast<float>([cocoon::internal::ns<::CIImage>(this) contentAverageLightLevel]);
    }

    float CIImage::content_headroom() const
    {
        return static_cast<float>([cocoon::internal::ns<::CIImage>(this) contentHeadroom]);
    }

    CIImage CIImage::cyan_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage cyanImage]);
    }

    Object CIImage::definition() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CIImage>(this) definition]);
    }

    Object CIImage::depth_data() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CIImage>(this) depthData]);
    }

    Rect CIImage::extent() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::CIImage>(this) extent]);
    }

    CIImage CIImage::gray_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage grayImage]);
    }

    CIImage CIImage::green_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage greenImage]);
    }

    CIImage CIImage::magenta_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage magentaImage]);
    }

    bool CIImage::is_opaque() const
    {
        return static_cast<bool>([cocoon::internal::ns<::CIImage>(this) isOpaque]);
    }

    CVPixelBuffer CIImage::pixel_buffer() const
    {
        return cocoon::internal::wrap_cf<CVPixelBuffer>((const void*)([cocoon::internal::ns<::CIImage>(this) pixelBuffer]));
    }

    Object CIImage::portrait_effects_matte() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CIImage>(this) portraitEffectsMatte]);
    }

    std::map<std::string, Object> CIImage::properties() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::CIImage>(this) properties], [](id k) -> std::string
                                                                  {
                                                                      return cocoon::internal::from((NSString*)k);
                                                                  },
                                                                  [](id v) -> Object
                                                                  {
                                                                      return cocoon::internal::wrap<Object>(v);
                                                                  });
    }

    CIImage CIImage::red_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage redImage]);
    }

    Object CIImage::semantic_segmentation_matte() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::CIImage>(this) semanticSegmentationMatte]);
    }

    URL CIImage::url() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::CIImage>(this) url]);
    }

    CIImage CIImage::white_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage whiteImage]);
    }

    CIImage CIImage::yellow_image()
    {
        return cocoon::internal::wrap<CIImage>([::CIImage yellowImage]);
    }
}
