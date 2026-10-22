#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AffineTransform;
    class CharacterSet;
    class FontDescriptor;
    class GraphicsContext;

    /**
     * @brief A font (NSFont).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * cocoon::Font title = cocoon::Font::bold_system_font_of_size(24);
     * cocoon::Font body = cocoon::Font::system_font_of_size(13);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Font font{};
     * auto made_0 = cocoon::Font::bold_system_font_of_size(1);
     * auto made_1 = cocoon::Font::control_content_font_of_size(1);
     * font.advancement_for_cg_glyph(1);
     * font.advancement_for_glyph(1);
     * font.bounding_rect_for_cg_glyph(1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsfont
     */
    class Font : public Object
    {
    public:
        /// @brief Creates a new `NSFont` instance and returns a handle to it.
        explicit Font(const FontDescriptor& font_descriptor, double font_size);
        /// @brief Creates a new `NSFont` instance and returns a handle to it.
        explicit Font(const FontDescriptor& font_descriptor, const AffineTransform& text_transform);
        /// @brief Creates a new `NSFont` instance and returns a handle to it.
        explicit Font(const std::string& font_name, const double* font_matrix);
        /// @brief Creates a new `NSFont` instance and returns a handle to it.
        explicit Font(const std::string& font_name, double font_size);
        /// @brief Creates a new `NSFont` instance and returns a handle to it.
        explicit Font();
        /// @brief Creates a null handle that refers to no native object.
        Font(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Font(Adopt adopt);
        /**
     * @brief Calls `-[NSFont advancementForCGGlyph:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size advancement_for_cg_glyph(std::uint16_t glyph) const;
        /**
     * @brief Calls `-[NSFont advancementForGlyph:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size advancement_for_glyph(unsigned int glyph) const;
        /**
     * @brief Calls `+[NSFont boldSystemFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font bold_system_font_of_size(double font_size);
        /**
     * @brief Calls `-[NSFont boundingRectForCGGlyph:]`.
     * @details Glyph metrics
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounding_rect_for_cg_glyph(std::uint16_t glyph) const;
        /**
     * @brief Calls `-[NSFont boundingRectForGlyph:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Rect bounding_rect_for_glyph(unsigned int glyph) const;
        /**
     * @brief Calls `+[NSFont controlContentFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font control_content_font_of_size(double font_size);
        /**
     * @brief Calls `-[NSFont fontWithSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Font font_with_size(double font_size) const;
        /**
     * @brief Calls `-[NSFont getAdvancements:forCGGlyphs:count:]`.
     * @param advancements Argument converted to the Objective-C parameter of the same role.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param glyph_count Argument converted to the Objective-C parameter of the same role.
     */
        void get_advancements(Size* advancements, const std::uint16_t* glyphs, std::uint64_t glyph_count) const;
        /**
     * @brief Calls `-[NSFont getAdvancements:forGlyphs:count:]`.
     * @param advancements Argument converted to the Objective-C parameter of the same role.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param glyph_count Argument converted to the Objective-C parameter of the same role.
     */
        void get_advancements(Size* advancements, const unsigned int* glyphs, std::uint64_t glyph_count) const;
        /**
     * @brief Calls `-[NSFont getAdvancements:forPackedGlyphs:length:]`.
     * @param advancements Argument converted to the Objective-C parameter of the same role.
     * @param packed_glyphs Argument converted to the Objective-C parameter of the same role.
     * @param length Argument converted to the Objective-C parameter of the same role.
     */
        void get_advancements(Size* advancements, const void* packed_glyphs, std::uint64_t length) const;
        /**
     * @brief Calls `-[NSFont getBoundingRects:forCGGlyphs:count:]`.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param glyph_count Argument converted to the Objective-C parameter of the same role.
     */
        void get_bounding_rects(Rect* bounds, const std::uint16_t* glyphs, std::uint64_t glyph_count) const;
        /**
     * @brief Calls `-[NSFont getBoundingRects:forGlyphs:count:]`.
     * @param bounds Argument converted to the Objective-C parameter of the same role.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param glyph_count Argument converted to the Objective-C parameter of the same role.
     */
        void get_bounding_rects(Rect* bounds, const unsigned int* glyphs, std::uint64_t glyph_count) const;
        /**
     * @brief Calls `-[NSFont glyphWithName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        unsigned int glyph_with_name(const std::string& name) const;
        /**
     * @brief Calls `+[NSFont labelFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font label_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont menuBarFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font menu_bar_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont menuFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font menu_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont messageFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font message_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont monospacedDigitSystemFontOfSize:weight:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font monospaced_digit_system_font_of_size(double font_size, double weight);
        /**
     * @brief Calls `+[NSFont monospacedSystemFontOfSize:weight:]`.
     * @details Returns current default monospaced font for system UI. Clients of this API should be aware that the monospaced system font has a similar coverage of default system UI font, which includes Latin and common symbols used for displaying text like source code. For the characters it does not cover, the subtituted fonts are usually not the same width as the monospaced system font, they can be wider, narrower, or variable. To ensure fixed advances in text layout, clients can consider using string attributes like NSFontFixedAdvanceAttribute.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font monospaced_system_font_of_size(double font_size, double weight);
        /**
     * @brief Calls `+[NSFont paletteFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font palette_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont preferredFontForTextStyle:options:]`.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font preferred_font_for_text_style(const std::string& style, const std::map<std::string, Object>& options);
        /**
     * @brief Calls `-[NSFont screenFontWithRenderingMode:]`.
     * @param rendering_mode Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Font screen_font_with_rendering_mode(FontRenderingMode rendering_mode) const;
        /**
     * @brief Calls `-[NSFont set]`.
     * @details NSGraphicsContext-related
     */
        void set() const;
        /**
     * @brief Calls `-[NSFont setInContext:]`.
     * @param graphics_context Argument converted to the Objective-C parameter of the same role.
     */
        void set_in_context(const GraphicsContext& graphics_context) const;
        /**
     * @brief Calls `+[NSFont setUserFixedPitchFont:]`.
     * @param font Argument converted to the Objective-C parameter of the same role.
     */
        static void set_user_fixed_pitch_font(const Font& font);
        /**
     * @brief Calls `+[NSFont setUserFont:]`.
     * @param font Argument converted to the Objective-C parameter of the same role.
     */
        static void set_user_font(const Font& font);
        /**
     * @brief Calls `+[NSFont systemFontOfSize:]`.
     * @details UI font settings
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font system_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont systemFontOfSize:weight:]`.
     * @details Following two factory methods return system font with NSFontWeightTrait. Returns the system font object corresponding to fontSize and weight. +monospacedDigitSystemFontOfSize:weight: always return a system font instance with monospaced digit glyphs. It's recommended to use the symbolic weight values declared in NSFontDescriptor.h. Due to sophisticated system font weight matching logic underneath, it's recommended to use this factory method all the time when getting non-standard weight system fonts instead of transforming existing instances via methods like -[NSFontManager convertFont:toSize]. When asked for a missing weight for the running version of OS X, this method returns the nearest heavier weight available if the application is linked against the current or older SDK; otherwise, it returns the nearest lighter weight available.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font system_font_of_size(double font_size, double weight);
        /**
     * @brief Calls `+[NSFont systemFontOfSize:weight:width:]`.
     * @details Returns an instance with the specified weight and width. Width values are declared in NSFontDescriptor.h.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @param weight Argument converted to the Objective-C parameter of the same role.
     * @param width Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font system_font_of_size(double font_size, double weight, double width);
        /**
     * @brief Calls `+[NSFont systemFontSizeForControlSize:]`.
     * @param control_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static double system_font_size_for_control_size(ControlSize control_size);
        /**
     * @brief Calls `+[NSFont titleBarFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font title_bar_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont toolTipsFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font tool_tips_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont userFixedPitchFontOfSize:]`.
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font user_fixed_pitch_font_of_size(double font_size);
        /**
     * @brief Calls `+[NSFont userFontOfSize:]`.
     * @details User font settings
     * @param font_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Font user_font_of_size(double font_size);
        /**
     * @brief Returns the `ascender` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double ascender() const;
        /**
     * @brief Returns the `boundingRectForFont` property of `NSFont`.
     * @details These methods return scaled numbers. If the font was created with a matrix, the matrix is applied automatically; otherwise the coordinates are multiplied by size.
     * @return The converted Objective-C result.
     */
        Rect bounding_rect_for_font() const;
        /**
     * @brief Returns the `capHeight` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double cap_height() const;
        /**
     * @brief Returns the `coveredCharacterSet` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        CharacterSet covered_character_set() const;
        /**
     * @brief Returns the `descender` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double descender() const;
        /**
     * @brief Returns the `displayName` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        std::string display_name() const;
        /**
     * @brief Returns the `familyName` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        std::string family_name() const;
        /**
     * @brief Returns the `fixedPitch` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        bool is_fixed_pitch() const;
        /**
     * @brief Returns the `fontDescriptor` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        FontDescriptor font_descriptor() const;
        /**
     * @brief Returns the `fontName` property of `NSFont`.
     * @details Core font attribute
     * @return The converted Objective-C result.
     */
        std::string font_name() const;
        /**
     * @brief Returns the `italicAngle` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double italic_angle() const;
        /**
     * @brief Returns the `labelFontSize` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        static double label_font_size();
        /**
     * @brief Returns the `leading` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double leading() const;
        /**
     * @brief Returns the `matrix` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        const double* matrix() const;
        /**
     * @brief Returns the `maximumAdvancement` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        Size maximum_advancement() const;
        /**
     * @brief Returns the `mostCompatibleStringEncoding` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        std::uint64_t most_compatible_string_encoding() const;
        /**
     * @brief Returns the `numberOfGlyphs` property of `NSFont`.
     * @details Glyph coverage
     * @return The converted Objective-C result.
     */
        std::uint64_t number_of_glyphs() const;
        /**
     * @brief Returns the `pointSize` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double point_size() const;
        /**
     * @brief Returns the `printerFont` property of `NSFont`.
     * @details Rendering mode
     * @return The converted Objective-C result.
     */
        Font printer_font() const;
        /**
     * @brief Returns the `renderingMode` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        FontRenderingMode rendering_mode() const;
        /**
     * @brief Returns the `screenFont` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        Font screen_font() const;
        /**
     * @brief Returns the `smallSystemFontSize` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        static double small_system_font_size();
        /**
     * @brief Returns the `systemFontSize` property of `NSFont`.
     * @details UI font size settings
     * @return The converted Objective-C result.
     */
        static double system_font_size();
        /**
     * @brief Returns the `textTransform` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        AffineTransform text_transform() const;
        /**
     * @brief Returns the `underlinePosition` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double underline_position() const;
        /**
     * @brief Returns the `underlineThickness` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double underline_thickness() const;
        /**
     * @brief Returns the `vertical` property of `NSFont`.
     * @details Returns YES if a vertical variant
     * @return The converted Objective-C result.
     */
        bool is_vertical() const;
        /**
     * @brief Returns the `verticalFont` property of `NSFont`.
     * @details Returns a vertical version of the receiver if such a configuration is supported. Returns the receiver if no vertical variant available. A vertical font applies appropriate rotation to the text matrix in -setInContext:, returns vertical metrics, and enables the vertical glyph substitution feature by default.
     * @return The converted Objective-C result.
     */
        Font vertical_font() const;
        /**
     * @brief Returns the `xHeight` property of `NSFont`.
     * @return The converted Objective-C result.
     */
        double x_height() const;
    };
}
