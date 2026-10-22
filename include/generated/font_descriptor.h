#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AffineTransform;

    /**
     * @brief C++ handle for the Objective-C class `NSFontDescriptor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::FontDescriptor font_descriptor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::FontDescriptor font_descriptor{};
     * font_descriptor.font_descriptor_with_design("text");
     * font_descriptor.font_descriptor_with_face("text");
     * font_descriptor.font_descriptor_with_family("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfontdescriptor
     */
    class FontDescriptor : public Object
    {
    public:
        /// @brief Creates a new `NSFontDescriptor` instance and returns a handle to it.
        explicit FontDescriptor(const std::map<std::string, Object>& attributes);
        /// @brief Creates a new `NSFontDescriptor` instance and returns a handle to it.
        explicit FontDescriptor(const std::string& font_name, const AffineTransform& matrix);
        /// @brief Creates a new `NSFontDescriptor` instance and returns a handle to it.
        explicit FontDescriptor(const std::string& font_name, double size);
        /// @brief Creates a new `NSFontDescriptor` instance and returns a handle to it.
        explicit FontDescriptor();
        /// @brief Creates a null handle that refers to no native object.
        FontDescriptor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit FontDescriptor(Adopt adopt);
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorByAddingAttributes:]`.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_by_adding_attributes(const std::map<std::string, Object>& attributes) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithDesign:]`.
         * @param design Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_design(const std::string& design) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithFace:]`.
         * @param new_face Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_face(const std::string& new_face) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithFamily:]`.
         * @param new_family Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_family(const std::string& new_family) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithMatrix:]`.
         * @param matrix Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_matrix(const AffineTransform& matrix) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithSize:]`.
         * @param new_point_size Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_size(double new_point_size) const;
        /**
         * @brief Calls `-[NSFontDescriptor fontDescriptorWithSymbolicTraits:]`.
         * @param symbolic_traits Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor font_descriptor_with_symbolic_traits(FontDescriptorSymbolicTraits symbolic_traits) const;
        /**
         * @brief Calls `-[NSFontDescriptor matchingFontDescriptorWithMandatoryKeys:]`.
         * @details Returns a "normalized" font descriptor matching the receiver. It is the first element returned from -matchingFontDescriptorsWithMandatoryKeys:. mandatoryKeys is an NSSet instance containing keys that are required to be identical in order to be matched. mandatoryKeys can be nil.
         * @param mandatory_keys Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        FontDescriptor matching_font_descriptor_with_mandatory_keys(const std::vector<std::string>& mandatory_keys) const;
        /**
         * @brief Calls `-[NSFontDescriptor matchingFontDescriptorsWithMandatoryKeys:]`.
         * @details Returns "normalized" font descriptors matching the receiver. mandatoryKeys is an NSSet instance containing keys that are required to be identical in order to be matched. mandatoryKeys can be nil.
         * @param mandatory_keys Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<FontDescriptor> matching_font_descriptors_with_mandatory_keys(const std::vector<std::string>& mandatory_keys) const;
        /**
         * @brief Calls `-[NSFontDescriptor objectForKey:]`.
         * @param attribute Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_for_key(const std::string& attribute) const;
        /**
         * @brief Calls `+[NSFontDescriptor preferredFontDescriptorForTextStyle:options:]`.
         * @param style Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static FontDescriptor preferred_font_descriptor_for_text_style(const std::string& style, const std::map<std::string, Object>& options);
        /**
         * @brief Returns the `fontAttributes` property of `NSFontDescriptor`.
         * @return The converted Objective-C result.
         */
        std::map<std::string, Object> font_attributes() const;
        /**
         * @brief Returns the `matrix` property of `NSFontDescriptor`.
         * @return The converted Objective-C result.
         */
        AffineTransform matrix() const;
        /**
         * @brief Returns the `pointSize` property of `NSFontDescriptor`.
         * @return The converted Objective-C result.
         */
        double point_size() const;
        /**
         * @brief Returns the `postscriptName` property of `NSFontDescriptor`.
         * @details Core attribute access
         * @return The converted Objective-C result.
         */
        std::string postscript_name() const;
        /**
         * @brief Returns the `requiresFontAssetRequest` property of `NSFontDescriptor`.
         * @details YES indicates that any fonts matching the descriptor needs to be downloaded prior to instantiating a font. To ensure that the matching fonts are available before use, use NSFontAssetRequest to download. NO indicates that the descriptor is not available for download, has already been downloaded, or is backed by an installed font.
         * @return The converted Objective-C result.
         */
        bool requires_font_asset_request() const;
        /**
         * @brief Returns the `symbolicTraits` property of `NSFontDescriptor`.
         * @return The converted Objective-C result.
         */
        FontDescriptorSymbolicTraits symbolic_traits() const;
    };
}
