#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BezierPath;
    class Color;
    class ColorSpace;

    /**
     * @brief C++ handle for the Objective-C class `NSGradient` (AppKit).
     * @details An NSGradient defines a transition between colors. The transition is defined over a range from 0.0 to 1.0 inclusive. A gradient typically contains a color at location 0.0, and one at location 1.0 with additional colors assigned to locations between 0.0 and 1.0. An NSGradient is a drawing primitive that can draw itself as a linear or radial gradient. The color value at location 0.0 is considered the starting color, the color value at location 1.0 is considered the ending color. A primitive drawing method is provided for both linear and radial gradients. Each primitive drawing method provides flexibility in specifying the location of its respective gradient. These primitive drawing methods perform no clipping before drawing. In addition, convenience drawing methods take a rectangle or path, and automatically calculate staring and ending locations and perform clipping to provide a convenient means for drawing gradient fills. Two of the convenience methods are demonstrated below: The following code will fill a rectangle with a 45 degree linear gradient, from black to white: NSRect rect; // assume this exists NSGradient gradient = [[NSGradient alloc] initWithStartingColor: [NSColor blackColor] endingColor: [NSColor whiteColor]]; [gradient drawInRect: rect angle: 45.0]; [gradient release]; The following code will fill an arbitrary bezier path with a radial gradient, from the center of the path's bounding box, that transitions through three colors, evenly distributed in the gradient from 0.0 to 1.0. NSBezierPath path // assume this exists NSArray colorArray = [NSArray arrayWithObjects: [NSColor blueColor], [NSColor yellowColor], [NSColor orangeColor], nil]; NSGradient gradient = [[NSGradient alloc] initWithColors: colorArray]; [gradient drawInBezierPath: path relativeCenterPosition: NSZeroPoint]; [gradient release]; An NSGradient has a color space. When initialized, all colors provided are converted to that color space, and interpolation of colors occurs using the components of that color space. The designated initializer takes a color space argument, all other initializers use the default generic RGB color space.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Gradient gradient;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Gradient gradient{};
     * gradient.draw_from_center({0, 0}, 1, {0, 0}, 1, cocoon::GradientDrawingOptions::BeforeStartingLocation);
     * gradient.draw_from_point({0, 0}, {0, 0}, cocoon::GradientDrawingOptions::BeforeStartingLocation);
     * gradient.draw_in_bezier_path(cocoon::BezierPath(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsgradient
     */
    class Gradient : public Object
    {
    public:
        /// @brief Creates a new `NSGradient` instance and returns a handle to it.
        explicit Gradient(const std::vector<Color>& color_array);
        /// @brief Creates a new `NSGradient` instance and returns a handle to it.
        explicit Gradient(const std::vector<Color>& color_array, const double* locations, const ColorSpace& color_space);
        /// @brief Creates a new `NSGradient` instance and returns a handle to it.
        explicit Gradient(const Color& starting_color, const Color& ending_color);
        /// @brief Creates a new `NSGradient` instance and returns a handle to it.
        explicit Gradient();
        /// @brief Creates a null handle that refers to no native object.
        Gradient(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Gradient(Adopt adopt);
        /**
         * @brief Calls `-[NSGradient drawFromCenter:radius:toCenter:radius:options:]`.
         * @details Draws a radial gradient between two circles defined by the center point and radius of each circle. The option flags control whether the gradient draws itself before the start point, or after the end point. The gradient is drawn in the current graphics context without performing any additinal clipping. This is the primitive method for drawing a radial gradient.
         * @param start_center Argument converted to the Objective-C parameter of the same role.
         * @param start_radius Argument converted to the Objective-C parameter of the same role.
         * @param end_center Argument converted to the Objective-C parameter of the same role.
         * @param end_radius Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void draw_from_center(const Point& start_center, double start_radius, const Point& end_center, double end_radius, GradientDrawingOptions options) const;
        /**
         * @brief Calls `-[NSGradient drawFromPoint:toPoint:options:]`.
         * @details Draws a linear gradient from start point to end point. The option flags control whether the gradient draws itself before the start point, or after the end point. The gradient is drawn in the current graphics context without performing any additinal clipping. This is the primitive method for drawing a linear gradient.
         * @param starting_point Argument converted to the Objective-C parameter of the same role.
         * @param ending_point Argument converted to the Objective-C parameter of the same role.
         * @param options Argument converted to the Objective-C parameter of the same role.
         */
        void draw_from_point(const Point& starting_point, const Point& ending_point, GradientDrawingOptions options) const;
        /**
         * @brief Calls `-[NSGradient drawInBezierPath:angle:]`.
         * @details Convenience method for drawing a linear gradient to fill a path. Draws a linear gradient clipped by the provided path. The start point and end point are calculated with respect to the provided path so that the gradient is drawn at the provided angle in degrees. The end points are located such that both the start and end color in the gradient are visible in the path.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @param angle Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_bezier_path(const BezierPath& path, double angle) const;
        /**
         * @brief Calls `-[NSGradient drawInBezierPath:relativeCenterPosition:]`.
         * @details Convenience method for drawing a radial gradient to fill a path. Draws a radial gradient clipped by the provided path. The starting circle is always a single point located at the center of the ending circle which encloses the drawn path. The radius of the ending circle is determined by the relative center position. The relative center position proportionally adjusts the center location of the radial gradient. It maps the four corners of the path bounding rect to (-1.0, -1.0), (1.0, -1.0), (1.0, 1.0) and (-1.0, 1.0), with (0.0, 0.0) in the center of path bounding rect. Use NSZeroPoint to center the radial gradient in the path bounding rect. The radius of the ending circle is the distance from the relative center to the opposite corner of the path bounding rect.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @param relative_center_position Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_bezier_path(const BezierPath& path, const Point& relative_center_position) const;
        /**
         * @brief Calls `-[NSGradient drawInRect:angle:]`.
         * @details Convenience method for drawing a linear gradient to fill a rectangle. Draws a linear gradient clipped to the provided rect. The start point and end point are calculated with respect to the provided rect so that the gradient is drawn at the provided angle in degrees. The end points are located such that both the start and end color in the gradient are visible in the rect.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param angle Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& rect, double angle) const;
        /**
         * @brief Calls `-[NSGradient drawInRect:relativeCenterPosition:]`.
         * @details Convenience method for drawing a radial gradient to fill a rect. Draws a radial gradient clipped by the provided rect. The starting circle is always a single point located at the center of the ending circle which encloses the drawn rect. The radius of the ending circle is determined by the relative center position. The relative center position proportionally adjusts the center location of the radial gradient. It maps the four corners of the rectangle to (-1.0, -1.0), (1.0, -1.0), (1.0, 1.0) and (-1.0, 1.0), with (0.0, 0.0) in the center of the rectangle. Use NSZeroPoint to center the radial gradient in the rect. The radius of the ending circle is the distance from the relative center to the opposite corner of the rect.
         * @param rect Argument converted to the Objective-C parameter of the same role.
         * @param relative_center_position Argument converted to the Objective-C parameter of the same role.
         */
        void draw_in_rect(const Rect& rect, const Point& relative_center_position) const;
        /**
         * @brief Calls `-[NSGradient getColor:location:atIndex:]`.
         * @details Returns the color and location at a particular index in the color gradient
         * @param color Argument converted to the Objective-C parameter of the same role.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void get_color(Color& color, double* location, std::int64_t index) const;
        /**
         * @brief Calls `-[NSGradient interpolatedColorAtLocation:]`.
         * @details This method will return the interpolated gradient value at the given location. For example, in a two color gradient with white at location 0.0 and black at location 1.0, the interpolated color at location 0.5 would be 50\% gray. You should not need to override this method, it reports the color value of the gradient at a particular location, and does not affect the drawn color values.
         * @param location Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Color interpolated_color_at_location(double location) const;
        /**
         * @brief Returns the `colorSpace` property of `NSGradient`.
         * @details Returns the color space of the gradient
         * @return The converted Objective-C result.
         */
        ColorSpace color_space() const;
        /**
         * @brief Returns the `numberOfColorStops` property of `NSGradient`.
         * @details The number of color stops in the color gradient
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_color_stops() const;
    };
}
