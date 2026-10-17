#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BitmapImageRep;
    class CGColorSpace;
    class CGImage;
    class CGImageSource;
    class CIColor;
    class CVImageBuffer;
    class CVPixelBuffer;
    class IOSurface;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `CIImage` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CIImage ci_image;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CIImage ci_image{};
     * auto made_0 = cocoon::CIImage::empty_image();
     * auto made_1 = cocoon::CIImage::image_with_color(cocoon::CIColor());
     * ci_image.auto_adjustment_filters();
     * ci_image.draw_at_point({0, 0}, {{0, 0}, {100, 100}}, cocoon::CompositingOperation::Clear, 1);
     * ci_image.draw_in_rect({{0, 0}, {100, 100}}, {{0, 0}, {100, 100}}, cocoon::CompositingOperation::Clear, 1);
     * @endcode
     */
    class CIImage : public Object
    {
    public:
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const std::vector<std::uint8_t>& data, std::uint64_t bytes_per_row, const Size& size, int format, const CGColorSpace& color_space);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const BitmapImageRep& bitmap_image_rep);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CGImage& image);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CGImage& image, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CGImageSource& source, std::uint64_t index, const std::map<std::string, Object>& dict);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CVImageBuffer& image_buffer);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CVImageBuffer& image_buffer, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CVPixelBuffer& pixel_buffer);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CVPixelBuffer& pixel_buffer, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const CIColor& color);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const URL& url);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const URL& url, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const Object& data);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const Object& data, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const IOSurface& surface);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(const IOSurface& surface, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(unsigned int name, const Size& size, bool flipped, const CGColorSpace& color_space);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage(unsigned int name, const Size& size, bool flipped, const std::map<std::string, Object>& options);
        /// @brief Creates a new `CIImage` instance and returns a handle to it.
        explicit CIImage();
        /// @brief Creates a null handle that refers to no native object.
        CIImage(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CIImage(Adopt adopt);
        /**
     * @brief Calls `-[CIImage autoAdjustmentFilters]`.
     * @return The converted Objective-C result.
     */
        std::vector<Object> auto_adjustment_filters() const;
        /**
     * @brief Calls `-[CIImage autoAdjustmentFiltersWithOptions:]`.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> auto_adjustment_filters_with_options(const std::map<std::string, Object>& options) const;
        /**
     * @brief Calls `-[CIImage drawAtPoint:fromRect:operation:fraction:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @param from_rect Argument converted to the Objective-C parameter of the same role.
     * @param op Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void draw_at_point(const Point& point, const Rect& from_rect, CompositingOperation op, double delta) const;
        /**
     * @brief Calls `-[CIImage drawInRect:fromRect:operation:fraction:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param from_rect Argument converted to the Objective-C parameter of the same role.
     * @param op Argument converted to the Objective-C parameter of the same role.
     * @param delta Argument converted to the Objective-C parameter of the same role.
     */
        void draw_in_rect(const Rect& rect, const Rect& from_rect, CompositingOperation op, double delta) const;
        /**
     * @brief Calls `+[CIImage emptyImage]`.
     * @return The converted Objective-C result.
     */
        static CIImage empty_image();
        /**
     * @brief Calls `-[CIImage imageByApplyingCGOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_cg_orientation(CGImagePropertyOrientation orientation) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingFilter:]`.
     * @param filter_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_filter(const std::string& filter_name) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingFilter:withInputParameters:]`.
     * @param filter_name Argument converted to the Objective-C parameter of the same role.
     * @param params Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_filter(const std::string& filter_name, const std::map<std::string, Object>& params) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingGainMap:]`.
     * @param gainmap Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_gain_map(const CIImage& gainmap) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingGainMap:headroom:]`.
     * @param gainmap Argument converted to the Objective-C parameter of the same role.
     * @param headroom Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_gain_map(const CIImage& gainmap, float headroom) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingGaussianBlurWithSigma:]`.
     * @param sigma Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_gaussian_blur_with_sigma(double sigma) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_orientation(int orientation) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingTransform:]`.
     * @param matrix Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_transform(const AffineTransform3& matrix) const;
        /**
     * @brief Calls `-[CIImage imageByApplyingTransform:highQualityDownsample:]`.
     * @param matrix Argument converted to the Objective-C parameter of the same role.
     * @param high_quality_downsample Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_applying_transform(const AffineTransform3& matrix, bool high_quality_downsample) const;
        /**
     * @brief Calls `-[CIImage imageByClampingToExtent]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_clamping_to_extent() const;
        /**
     * @brief Calls `-[CIImage imageByClampingToRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_clamping_to_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[CIImage imageByColorMatchingColorSpaceToWorkingSpace:]`.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_color_matching_color_space_to_working_space(const CGColorSpace& color_space) const;
        /**
     * @brief Calls `-[CIImage imageByColorMatchingWorkingSpaceToColorSpace:]`.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_color_matching_working_space_to_color_space(const CGColorSpace& color_space) const;
        /**
     * @brief Calls `-[CIImage imageByCompositingOverImage:]`.
     * @param dest Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_compositing_over_image(const CIImage& dest) const;
        /**
     * @brief Calls `-[CIImage imageByConvertingLabToWorkingSpace]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_converting_lab_to_working_space() const;
        /**
     * @brief Calls `-[CIImage imageByConvertingWorkingSpaceToLab]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_converting_working_space_to_lab() const;
        /**
     * @brief Calls `-[CIImage imageByCroppingToRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_cropping_to_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[CIImage imageByInsertingIntermediate]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_inserting_intermediate() const;
        /**
     * @brief Calls `-[CIImage imageByInsertingIntermediate:]`.
     * @param cache Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_inserting_intermediate(bool cache) const;
        /**
     * @brief Calls `-[CIImage imageByInsertingTiledIntermediate]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_inserting_tiled_intermediate() const;
        /**
     * @brief Calls `-[CIImage imageByPremultiplyingAlpha]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_premultiplying_alpha() const;
        /**
     * @brief Calls `-[CIImage imageBySamplingLinear]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_sampling_linear() const;
        /**
     * @brief Calls `-[CIImage imageBySamplingNearest]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_sampling_nearest() const;
        /**
     * @brief Calls `-[CIImage imageBySettingAlphaOneInExtent:]`.
     * @param extent Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_setting_alpha_one_in_extent(const Rect& extent) const;
        /**
     * @brief Calls `-[CIImage imageBySettingContentAverageLightLevel:]`.
     * @param average Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_setting_content_average_light_level(float average) const;
        /**
     * @brief Calls `-[CIImage imageBySettingContentHeadroom:]`.
     * @param headroom Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_setting_content_headroom(float headroom) const;
        /**
     * @brief Calls `-[CIImage imageBySettingProperties:]`.
     * @param properties Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        CIImage image_by_setting_properties(const std::vector<std::pair<Object, Object>>& properties) const;
        /**
     * @brief Calls `-[CIImage imageByUnpremultiplyingAlpha]`.
     * @return The converted Objective-C result.
     */
        CIImage image_by_unpremultiplying_alpha() const;
        /**
     * @brief Calls `-[CIImage imageTransformForCGOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AffineTransform3 image_transform_for_cg_orientation(CGImagePropertyOrientation orientation) const;
        /**
     * @brief Calls `-[CIImage imageTransformForOrientation:]`.
     * @param orientation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        AffineTransform3 image_transform_for_orientation(int orientation) const;
        /**
     * @brief Calls `+[CIImage imageWithBitmapData:bytesPerRow:size:format:colorSpace:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param bytes_per_row Argument converted to the Objective-C parameter of the same role.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @param format Argument converted to the Objective-C parameter of the same role.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_bitmap_data(const std::vector<std::uint8_t>& data, std::uint64_t bytes_per_row, const Size& size, int format, const CGColorSpace& color_space);
        /**
     * @brief Calls `+[CIImage imageWithCGImage:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cg_image(const CGImage& image);
        /**
     * @brief Calls `+[CIImage imageWithCGImage:options:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cg_image(const CGImage& image, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithCGImageSource:index:options:]`.
     * @param source Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param dict Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cg_image_source(const CGImageSource& source, std::uint64_t index, const std::map<std::string, Object>& dict);
        /**
     * @brief Calls `+[CIImage imageWithCVImageBuffer:]`.
     * @param image_buffer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cv_image_buffer(const CVImageBuffer& image_buffer);
        /**
     * @brief Calls `+[CIImage imageWithCVImageBuffer:options:]`.
     * @param image_buffer Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cv_image_buffer(const CVImageBuffer& image_buffer, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithCVPixelBuffer:]`.
     * @param pixel_buffer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cv_pixel_buffer(const CVPixelBuffer& pixel_buffer);
        /**
     * @brief Calls `+[CIImage imageWithCVPixelBuffer:options:]`.
     * @param pixel_buffer Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_cv_pixel_buffer(const CVPixelBuffer& pixel_buffer, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithColor:]`.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_color(const CIColor& color);
        /**
     * @brief Calls `+[CIImage imageWithContentsOfURL:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_contents_of_url(const URL& url);
        /**
     * @brief Calls `+[CIImage imageWithContentsOfURL:options:]`.
     * @param url Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_contents_of_url(const URL& url, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithData:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_data(const std::vector<std::uint8_t>& data);
        /**
     * @brief Calls `+[CIImage imageWithData:options:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_data(const std::vector<std::uint8_t>& data, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithDepthData:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_depth_data(const Object& data);
        /**
     * @brief Calls `+[CIImage imageWithDepthData:options:]`.
     * @param data Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_depth_data(const Object& data, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithIOSurface:]`.
     * @param surface Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_io_surface(const IOSurface& surface);
        /**
     * @brief Calls `+[CIImage imageWithIOSurface:options:]`.
     * @param surface Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_io_surface(const IOSurface& surface, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithMTLTexture:options:]`.
     * @param texture Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_mtl_texture(const Object& texture, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithPortaitEffectsMatte:]`.
     * @param matte Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_portait_effects_matte(const Object& matte);
        /**
     * @brief Calls `+[CIImage imageWithPortaitEffectsMatte:options:]`.
     * @param matte Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_portait_effects_matte(const Object& matte, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithSemanticSegmentationMatte:]`.
     * @param matte Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_semantic_segmentation_matte(const Object& matte);
        /**
     * @brief Calls `+[CIImage imageWithSemanticSegmentationMatte:options:]`.
     * @param matte Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_semantic_segmentation_matte(const Object& matte, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `+[CIImage imageWithTexture:size:flipped:colorSpace:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @param flipped Argument converted to the Objective-C parameter of the same role.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_texture(unsigned int name, const Size& size, bool flipped, const CGColorSpace& color_space);
        /**
     * @brief Calls `+[CIImage imageWithTexture:size:flipped:options:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @param flipped Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIImage image_with_texture(unsigned int name, const Size& size, bool flipped, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `-[CIImage regionOfInterestForImage:inRect:]`.
     * @param image Argument converted to the Objective-C parameter of the same role.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect region_of_interest_for_image(const CIImage& image, const Rect& rect) const;
        /**
     * @brief Returns the `CGImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        CGImage cg_image() const;
        /**
     * @brief Returns the `blackImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage black_image();
        /**
     * @brief Returns the `blueImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage blue_image();
        /**
     * @brief Returns the `clearImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage clear_image();
        /**
     * @brief Returns the `colorSpace` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        CGColorSpace color_space() const;
        /**
     * @brief Returns the `contentAverageLightLevel` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        float content_average_light_level() const;
        /**
     * @brief Returns the `contentHeadroom` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        float content_headroom() const;
        /**
     * @brief Returns the `cyanImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage cyan_image();
        /**
     * @brief Returns the `definition` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        Object definition() const;
        /**
     * @brief Returns the `depthData` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        Object depth_data() const;
        /**
     * @brief Returns the `extent` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        Rect extent() const;
        /**
     * @brief Returns the `grayImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage gray_image();
        /**
     * @brief Returns the `greenImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage green_image();
        /**
     * @brief Returns the `magentaImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage magenta_image();
        /**
     * @brief Returns the `opaque` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        bool is_opaque() const;
        /**
     * @brief Returns the `pixelBuffer` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        CVPixelBuffer pixel_buffer() const;
        /**
     * @brief Returns the `portraitEffectsMatte` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        Object portrait_effects_matte() const;
        /**
     * @brief Returns the `properties` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> properties() const;
        /**
     * @brief Returns the `redImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage red_image();
        /**
     * @brief Returns the `semanticSegmentationMatte` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        Object semantic_segmentation_matte() const;
        /**
     * @brief Returns the `url` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Returns the `whiteImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage white_image();
        /**
     * @brief Returns the `yellowImage` property of `CIImage`.
     * @return The converted Objective-C result.
     */
        static CIImage yellow_image();
    };
}
