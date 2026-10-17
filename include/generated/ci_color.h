#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class CGColor;
    class CGColorSpace;
    class Color;

    /**
     * @brief C++ handle for the Objective-C class `CIColor` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CIColor ci_color;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CIColor ci_color{};
     * auto made_0 = cocoon::CIColor::color_with_red(1, 1, 1);
     * auto made_1 = cocoon::CIColor::color_with_red(1, 1, 1, 1);
     * @endcode
     */
    class CIColor : public Object
    {
    public:
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(const CGColor& color);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(const Color& color);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(double red, double green, double blue);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(double red, double green, double blue, double alpha);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(double red, double green, double blue, double alpha, const CGColorSpace& color_space);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor(double red, double green, double blue, const CGColorSpace& color_space);
        /// @brief Creates a new `CIColor` instance and returns a handle to it.
        explicit CIColor();
        /// @brief Creates a null handle that refers to no native object.
        CIColor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CIColor(Adopt adopt);
        /**
     * @brief Calls `+[CIColor colorWithCGColor:]`.
     * @param color Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_cg_color(const CGColor& color);
        /**
     * @brief Calls `+[CIColor colorWithRed:green:blue:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_red(double red, double green, double blue);
        /**
     * @brief Calls `+[CIColor colorWithRed:green:blue:alpha:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_red(double red, double green, double blue, double alpha);
        /**
     * @brief Calls `+[CIColor colorWithRed:green:blue:alpha:colorSpace:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param alpha Argument converted to the Objective-C parameter of the same role.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_red(double red, double green, double blue, double alpha, const CGColorSpace& color_space);
        /**
     * @brief Calls `+[CIColor colorWithRed:green:blue:colorSpace:]`.
     * @param red Argument converted to the Objective-C parameter of the same role.
     * @param green Argument converted to the Objective-C parameter of the same role.
     * @param blue Argument converted to the Objective-C parameter of the same role.
     * @param color_space Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_red(double red, double green, double blue, const CGColorSpace& color_space);
        /**
     * @brief Calls `+[CIColor colorWithString:]`.
     * @param representation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static CIColor color_with_string(const std::string& representation);
        /**
     * @brief Returns the `alpha` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        double alpha() const;
        /**
     * @brief Returns the `blackColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor black_color();
        /**
     * @brief Returns the `blue` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        double blue() const;
        /**
     * @brief Returns the `blueColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor blue_color();
        /**
     * @brief Returns the `clearColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor clear_color();
        /**
     * @brief Returns the `components` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        const double* components() const;
        /**
     * @brief Returns the `cyanColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor cyan_color();
        /**
     * @brief Returns the `grayColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor gray_color();
        /**
     * @brief Returns the `green` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        double green() const;
        /**
     * @brief Returns the `greenColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor green_color();
        /**
     * @brief Returns the `magentaColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor magenta_color();
        /**
     * @brief Returns the `numberOfComponents` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        std::uint64_t number_of_components() const;
        /**
     * @brief Returns the `red` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        double red() const;
        /**
     * @brief Returns the `redColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor red_color();
        /**
     * @brief Returns the `stringRepresentation` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        std::string string_representation() const;
        /**
     * @brief Returns the `whiteColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor white_color();
        /**
     * @brief Returns the `yellowColor` property of `CIColor`.
     * @return The converted Objective-C result.
     */
        static CIColor yellow_color();
    };
}
