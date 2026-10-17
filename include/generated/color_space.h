#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGColorSpace;

    /**
     * @brief C++ handle for the Objective-C class `NSColorSpace` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ColorSpace color_space;
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscolorspace
     */
    class ColorSpace : public Object
    {
    public:
        /// @brief Creates a new `NSColorSpace` instance and returns a handle to it.
        explicit ColorSpace(const CGColorSpace& cg_color_space);
        /// @brief Creates a new `NSColorSpace` instance and returns a handle to it.
        explicit ColorSpace(void* prof);
        /// @brief Creates a new `NSColorSpace` instance and returns a handle to it.
        explicit ColorSpace(const std::vector<std::uint8_t>& icc_data);
        /// @brief Creates a new `NSColorSpace` instance and returns a handle to it.
        explicit ColorSpace();
        /// @brief Creates a null handle that refers to no native object.
        ColorSpace(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ColorSpace(Adopt adopt);
        /**
     * @brief Calls `+[NSColorSpace availableColorSpacesWithModel:]`.
     * @details Return the list of color spaces available on the system that are displayed by the color panel, in the order they are displayed in the color panel. Doesn't return arbitrary color spaces which may have been created on the fly, or spaces without user displayable names. Pass model==NSUnknownColorSpaceModel to get all color spaces. Empty array is returned if no color spaces are available for the specified model.
     * @param model Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<ColorSpace> available_color_spaces_with_model(ColorSpaceModel model);
        /**
     * @brief Returns the `CGColorSpace` property of `NSColorSpace`.
     * @details Might return NULL if the NSColorSpace space cannot be represented as a CGColorSpace.
     * @return The converted Objective-C result.
     */
        CGColorSpace cg_color_space() const;
        /**
     * @brief Returns the `ICCProfileData` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> icc_profile_data() const;
        /**
     * @brief Returns the `adobeRGB1998ColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace adobe_rgb1998_color_space();
        /**
     * @brief Returns the `colorSpaceModel` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        ColorSpaceModel color_space_model() const;
        /**
     * @brief Returns the `colorSyncProfile` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        void* color_sync_profile() const;
        /**
     * @brief Returns the `deviceCMYKColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace device_cmyk_color_space();
        /**
     * @brief Returns the `deviceGrayColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace device_gray_color_space();
        /**
     * @brief Returns the `deviceRGBColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace device_rgb_color_space();
        /**
     * @brief Returns the `displayP3ColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace display_p3_color_space();
        /**
     * @brief Returns the `extendedGenericGamma22GrayColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace extended_generic_gamma22_gray_color_space();
        /**
     * @brief Returns the `extendedSRGBColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace extended_srgb_color_space();
        /**
     * @brief Returns the `genericCMYKColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace generic_cmyk_color_space();
        /**
     * @brief Returns the `genericGamma22GrayColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace generic_gamma22_gray_color_space();
        /**
     * @brief Returns the `genericGrayColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace generic_gray_color_space();
        /**
     * @brief Returns the `genericRGBColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace generic_rgb_color_space();
        /**
     * @brief Returns the `localizedName` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        std::string localized_name() const;
        /**
     * @brief Returns the `numberOfColorComponents` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        std::int64_t number_of_color_components() const;
        /**
     * @brief Returns the `sRGBColorSpace` property of `NSColorSpace`.
     * @return The converted Objective-C result.
     */
        static ColorSpace s_rgb_color_space();
    };
}
