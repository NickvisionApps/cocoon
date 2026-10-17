#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class AffineTransform;
    class CGPath;
    class Font;

    /**
     * @brief C++ handle for the Objective-C class `NSBezierPath` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::BezierPath bezier_path;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::BezierPath bezier_path{};
     * bezier_path.set_default_flatness(1);
     * auto default_flatness = bezier_path.default_flatness();
     * bezier_path.set_default_line_cap_style(cocoon::LineCapStyle::Butt);
     * auto default_line_cap_style = bezier_path.default_line_cap_style();
     * bezier_path.set_default_line_join_style(cocoon::LineJoinStyle::Miter);
     * auto default_line_join_style = bezier_path.default_line_join_style();
     * auto made_0 = cocoon::BezierPath::bezier_path();
     * auto made_1 = cocoon::BezierPath::bezier_path_with_oval_in_rect({{0, 0}, {100, 100}});
     * bezier_path.add_clip();
     * bezier_path.append_bezier_path(cocoon::BezierPath());
     * bezier_path.append_bezier_path_with_arc_from_point({0, 0}, {0, 0}, 1);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsbezierpath
     */
    class BezierPath : public Object
    {
    public:
        /// @brief Creates a new `NSBezierPath` instance and returns a handle to it.
        explicit BezierPath();
        /// @brief Creates a null handle that refers to no native object.
        BezierPath(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit BezierPath(Adopt adopt);
        /**
     * @brief Calls `-[NSBezierPath addClip]`.
     */
        void add_clip() const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path(const BezierPath& path) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithArcFromPoint:toPoint:radius:]`.
     * @param point1 Argument converted to the Objective-C parameter of the same role.
     * @param point2 Argument converted to the Objective-C parameter of the same role.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_arc_from_point(const Point& point1, const Point& point2, double radius) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithArcWithCenter:radius:startAngle:endAngle:]`.
     * @details NSBezierPath.h Application Kit Copyright (c) 1997-2024, Apple Inc. All rights reserved. \#import \<Foundation/NSObject.h> \#import \<Foundation/NSGeometry.h> \#import \<AppKit/NSFont.h> \#import \<AppKit/AppKitDefines.h> NS_HEADER_AUDIT_BEGIN(nullability, sendability) APPKIT_API_UNAVAILABLE_BEGIN_MACCATALYST \@class NSAffineTransform; typedef NS_ENUM(NSUInteger, NSLineCapStyle) { NSLineCapStyleButt = 0, NSLineCapStyleRound = 1, NSLineCapStyleSquare = 2 }; typedef NS_ENUM(NSUInteger, NSLineJoinStyle) { NSLineJoinStyleMiter = 0, NSLineJoinStyleRound = 1, NSLineJoinStyleBevel = 2 }; typedef NS_ENUM(NSUInteger, NSWindingRule) { NSWindingRuleNonZero = 0, NSWindingRuleEvenOdd = 1 }; typedef NS_ENUM(NSUInteger, NSBezierPathElement) { NSBezierPathElementMoveTo, NSBezierPathElementLineTo, NSBezierPathElementCubicCurveTo API_AVAILABLE(macos(14.0)), NSBezierPathElementClosePath, NSBezierPathElementQuadraticCurveTo API_AVAILABLE(macos(14.0)), NSBezierPathElementCurveTo API_DEPRECATED_WITH_REPLACEMENT("NSBezierPathElementCubicCurveTo", macos(11.0, 14.0)) = NSBezierPathElementCubicCurveTo, }; \@interface NSBezierPath : NSObject \<NSCopying, NSSecureCoding> // Creating common paths. + (NSBezierPath )bezierPath; + (NSBezierPath )bezierPathWithRect:(NSRect)rect; + (NSBezierPath )bezierPathWithOvalInRect:(NSRect)rect; + (NSBezierPath )bezierPathWithRoundedRect:(NSRect)rect xRadius:(CGFloat)xRadius yRadius:(CGFloat)yRadius API_AVAILABLE(macos(10.5)); + (NSBezierPath )bezierPathWithCGPath:(CGPathRef)cgPath API_AVAILABLE(macos(14.0)); // Getting the CGPath property returns a copied, autoreleasing, immutable CGPathRef; The CGPathRef will // only match the NSBezierPath until the NSBezierPath is mutated. // Setting the CGPath property will create an immutable copy of the provided CGPathRef; Any further // mutations of the path will not effect the NSBezierPath. \@property (nonnull) CGPathRef CGPath API_AVAILABLE(macos(14.0)) CF_RETURNS_NOT_RETAINED; // Immediate mode drawing of common paths. + (void)fillRect:(NSRect)rect; + (void)strokeRect:(NSRect)rect; + (void)clipRect:(NSRect)rect; + (void)strokeLineFromPoint:(NSPoint)point1 toPoint:(NSPoint)point2; + (void)drawPackedGlyphs:(const char )packedGlyphs atPoint:(NSPoint)point; // Default path rendering parameters. \@property (class) CGFloat defaultMiterLimit; \@property (class) CGFloat defaultFlatness; \@property (class) NSWindingRule defaultWindingRule; \@property (class) NSLineCapStyle defaultLineCapStyle; \@property (class) NSLineJoinStyle defaultLineJoinStyle; \@property (class) CGFloat defaultLineWidth; // Path construction. - (void)moveToPoint:(NSPoint)point; - (void)lineToPoint:(NSPoint)point; - (void)curveToPoint:(NSPoint)endPoint controlPoint1:(NSPoint)controlPoint1 controlPoint2:(NSPoint)controlPoint2; - (void)curveToPoint:(NSPoint)endPoint controlPoint:(NSPoint)controlPoint API_AVAILABLE(macos(14.0)); - (void)closePath; - (void)removeAllPoints; // Relative path construction. - (void)relativeMoveToPoint:(NSPoint)point; - (void)relativeLineToPoint:(NSPoint)point; - (void)relativeCurveToPoint:(NSPoint)endPoint controlPoint1:(NSPoint)controlPoint1 controlPoint2:(NSPoint)controlPoint2; - (void)relativeCurveToPoint:(NSPoint)endPoint controlPoint:(NSPoint)controlPoint API_AVAILABLE(macos(14.0)); // Path rendering parameters. \@property CGFloat lineWidth; \@property NSLineCapStyle lineCapStyle; \@property NSLineJoinStyle lineJoinStyle; \@property NSWindingRule windingRule; \@property CGFloat miterLimit; \@property CGFloat flatness; - (void)getLineDash:(nullable CGFloat )pattern count:(nullable NSInteger )count phase:(nullable CGFloat )phase; - (void)setLineDash:(nullable const CGFloat )pattern count:(NSInteger)count phase:(CGFloat)phase; // Path operations. - (void)stroke; - (void)fill; - (void)addClip; - (void)setClip; // Path modifications. \@property (readonly, copy) NSBezierPath bezierPathByFlatteningPath; \@property (readonly, copy) NSBezierPath bezierPathByReversingPath; // Applying transformations. - (void)transformUsingAffineTransform:(NSAffineTransform )transform; // Path info \@property (getter=isEmpty, readonly) BOOL empty; \@property (readonly) NSPoint currentPoint; \@property (readonly) NSRect controlPointBounds; \@property (readonly) NSRect bounds; // Elements. \@property (readonly) NSInteger elementCount; // 'points' should contain space for at least three points. 'points' // may be NULL. In the case of NSBezierPathElementCurveTo, the order // of the points is controlPoint1 (points[0]), controlPoint2 (points[1]), // endPoint (points[2]). - (NSBezierPathElement)elementAtIndex:(NSInteger)index associatedPoints:(nullable NSPointArray)points; // As above with points == NULL. - (NSBezierPathElement)elementAtIndex:(NSInteger)index; - (void)setAssociatedPoints:(nullable NSPointArray)points atIndex:(NSInteger)index; // Appending common paths - (void)appendBezierPath:(NSBezierPath )path; - (void)appendBezierPathWithRect:(NSRect)rect; - (void)appendBezierPathWithPoints:(NSPointArray)points count:(NSInteger)count; - (void)appendBezierPathWithOvalInRect:(NSRect)rect; - (void)appendBezierPathWithArcWithCenter:(NSPoint)center radius:(CGFloat)radius startAngle:(CGFloat)startAngle endAngle:(CGFloat)endAngle clockwise:(BOOL)clockwise; // As above with clockwise == NO.
     * @param center Argument converted to the Objective-C parameter of the same role.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     * @param start_angle Argument converted to the Objective-C parameter of the same role.
     * @param end_angle Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_arc_with_center(const Point& center, double radius, double start_angle, double end_angle) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithArcWithCenter:radius:startAngle:endAngle:clockwise:]`.
     * @param center Argument converted to the Objective-C parameter of the same role.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     * @param start_angle Argument converted to the Objective-C parameter of the same role.
     * @param end_angle Argument converted to the Objective-C parameter of the same role.
     * @param clockwise Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_arc_with_center(const Point& center, double radius, double start_angle, double end_angle, bool clockwise) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithCGGlyph:inFont:]`.
     * @param glyph Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_cg_glyph(std::uint16_t glyph, const Font& font) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithCGGlyphs:count:inFont:]`.
     * @param glyphs Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @param font Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_cg_glyphs(const std::uint16_t* glyphs, std::int64_t count, const Font& font) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithOvalInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_oval_in_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithPoints:count:]`.
     * @param points Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_points(Point* points, std::int64_t count) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_rect(const Rect& rect) const;
        /**
     * @brief Calls `-[NSBezierPath appendBezierPathWithRoundedRect:xRadius:yRadius:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param x_radius Argument converted to the Objective-C parameter of the same role.
     * @param y_radius Argument converted to the Objective-C parameter of the same role.
     */
        void append_bezier_path_with_rounded_rect(const Rect& rect, double x_radius, double y_radius) const;
        /**
     * @brief Calls `+[NSBezierPath bezierPath]`.
     * @return The converted Objective-C result.
     */
        static BezierPath bezier_path();
        /**
     * @brief Calls `+[NSBezierPath bezierPathWithCGPath:]`.
     * @param cg_path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BezierPath bezier_path_with_cg_path(const CGPath& cg_path);
        /**
     * @brief Calls `+[NSBezierPath bezierPathWithOvalInRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BezierPath bezier_path_with_oval_in_rect(const Rect& rect);
        /**
     * @brief Calls `+[NSBezierPath bezierPathWithRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BezierPath bezier_path_with_rect(const Rect& rect);
        /**
     * @brief Calls `+[NSBezierPath bezierPathWithRoundedRect:xRadius:yRadius:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @param x_radius Argument converted to the Objective-C parameter of the same role.
     * @param y_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static BezierPath bezier_path_with_rounded_rect(const Rect& rect, double x_radius, double y_radius);
        /**
     * @brief Calls `+[NSBezierPath clipRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        static void clip_rect(const Rect& rect);
        /**
     * @brief Calls `-[NSBezierPath closePath]`.
     */
        void close_path() const;
        /**
     * @brief Calls `-[NSBezierPath containsPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool contains_point(const Point& point) const;
        /**
     * @brief Calls `-[NSBezierPath curveToPoint:controlPoint1:controlPoint2:]`.
     * @param end_point Argument converted to the Objective-C parameter of the same role.
     * @param control_point1 Argument converted to the Objective-C parameter of the same role.
     * @param control_point2 Argument converted to the Objective-C parameter of the same role.
     */
        void curve_to_point(const Point& end_point, const Point& control_point1, const Point& control_point2) const;
        /**
     * @brief Calls `-[NSBezierPath curveToPoint:controlPoint:]`.
     * @param end_point Argument converted to the Objective-C parameter of the same role.
     * @param control_point Argument converted to the Objective-C parameter of the same role.
     */
        void curve_to_point(const Point& end_point, const Point& control_point) const;
        /**
     * @brief Calls `+[NSBezierPath drawPackedGlyphs:atPoint:]`.
     * @param packed_glyphs Argument converted to the Objective-C parameter of the same role.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        static void draw_packed_glyphs(const std::string& packed_glyphs, const Point& point);
        /**
     * @brief Calls `-[NSBezierPath elementAtIndex:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BezierPathElement element_at_index(std::int64_t index) const;
        /**
     * @brief Calls `-[NSBezierPath elementAtIndex:associatedPoints:]`.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param points Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BezierPathElement element_at_index(std::int64_t index, Point* points) const;
        /**
     * @brief Calls `-[NSBezierPath fill]`.
     */
        void fill() const;
        /**
     * @brief Calls `+[NSBezierPath fillRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        static void fill_rect(const Rect& rect);
        /**
     * @brief Calls `-[NSBezierPath getLineDash:count:phase:]`.
     * @param pattern Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @param phase Argument converted to the Objective-C parameter of the same role.
     */
        void get_line_dash(double* pattern, std::int64_t* count, double* phase) const;
        /**
     * @brief Calls `-[NSBezierPath lineToPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void line_to_point(const Point& point) const;
        /**
     * @brief Calls `-[NSBezierPath moveToPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void move_to_point(const Point& point) const;
        /**
     * @brief Calls `-[NSBezierPath relativeCurveToPoint:controlPoint1:controlPoint2:]`.
     * @param end_point Argument converted to the Objective-C parameter of the same role.
     * @param control_point1 Argument converted to the Objective-C parameter of the same role.
     * @param control_point2 Argument converted to the Objective-C parameter of the same role.
     */
        void relative_curve_to_point(const Point& end_point, const Point& control_point1, const Point& control_point2) const;
        /**
     * @brief Calls `-[NSBezierPath relativeCurveToPoint:controlPoint:]`.
     * @param end_point Argument converted to the Objective-C parameter of the same role.
     * @param control_point Argument converted to the Objective-C parameter of the same role.
     */
        void relative_curve_to_point(const Point& end_point, const Point& control_point) const;
        /**
     * @brief Calls `-[NSBezierPath relativeLineToPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void relative_line_to_point(const Point& point) const;
        /**
     * @brief Calls `-[NSBezierPath relativeMoveToPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     */
        void relative_move_to_point(const Point& point) const;
        /**
     * @brief Calls `-[NSBezierPath removeAllPoints]`.
     */
        void remove_all_points() const;
        /**
     * @brief Calls `-[NSBezierPath setAssociatedPoints:atIndex:]`.
     * @param points Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void set_associated_points(Point* points, std::int64_t index) const;
        /**
     * @brief Calls `-[NSBezierPath setClip]`.
     */
        void set_clip() const;
        /**
     * @brief Calls `-[NSBezierPath setLineDash:count:phase:]`.
     * @param pattern Argument converted to the Objective-C parameter of the same role.
     * @param count Argument converted to the Objective-C parameter of the same role.
     * @param phase Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_dash(const double* pattern, std::int64_t count, double phase) const;
        /**
     * @brief Calls `-[NSBezierPath stroke]`.
     */
        void stroke() const;
        /**
     * @brief Calls `+[NSBezierPath strokeLineFromPoint:toPoint:]`.
     * @param point1 Argument converted to the Objective-C parameter of the same role.
     * @param point2 Argument converted to the Objective-C parameter of the same role.
     */
        static void stroke_line_from_point(const Point& point1, const Point& point2);
        /**
     * @brief Calls `+[NSBezierPath strokeRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     */
        static void stroke_rect(const Rect& rect);
        /**
     * @brief Calls `-[NSBezierPath transformUsingAffineTransform:]`.
     * @param transform Argument converted to the Objective-C parameter of the same role.
     */
        void transform_using_affine_transform(const AffineTransform& transform) const;
        /**
     * @brief Returns the `CGPath` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        CGPath cg_path() const;
        /**
     * @brief Sets the `CGPath` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_cg_path(const CGPath& value) const;
        /**
     * @brief Returns the `bezierPathByFlatteningPath` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        BezierPath bezier_path_by_flattening_path() const;
        /**
     * @brief Returns the `bezierPathByReversingPath` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        BezierPath bezier_path_by_reversing_path() const;
        /**
     * @brief Returns the `bounds` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        Rect bounds() const;
        /**
     * @brief Returns the `controlPointBounds` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        Rect control_point_bounds() const;
        /**
     * @brief Returns the `currentPoint` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        Point current_point() const;
        /**
     * @brief Returns the `defaultFlatness` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static double default_flatness();
        /**
     * @brief Sets the `defaultFlatness` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_flatness(double value);
        /**
     * @brief Returns the `defaultLineCapStyle` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static LineCapStyle default_line_cap_style();
        /**
     * @brief Sets the `defaultLineCapStyle` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_line_cap_style(LineCapStyle value);
        /**
     * @brief Returns the `defaultLineJoinStyle` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static LineJoinStyle default_line_join_style();
        /**
     * @brief Sets the `defaultLineJoinStyle` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_line_join_style(LineJoinStyle value);
        /**
     * @brief Returns the `defaultLineWidth` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static double default_line_width();
        /**
     * @brief Sets the `defaultLineWidth` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_line_width(double value);
        /**
     * @brief Returns the `defaultMiterLimit` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static double default_miter_limit();
        /**
     * @brief Sets the `defaultMiterLimit` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_miter_limit(double value);
        /**
     * @brief Returns the `defaultWindingRule` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        static WindingRule default_winding_rule();
        /**
     * @brief Sets the `defaultWindingRule` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_winding_rule(WindingRule value);
        /**
     * @brief Returns the `elementCount` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        std::int64_t element_count() const;
        /**
     * @brief Returns the `empty` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        bool is_empty() const;
        /**
     * @brief Returns the `flatness` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        double flatness() const;
        /**
     * @brief Sets the `flatness` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_flatness(double value) const;
        /**
     * @brief Returns the `lineCapStyle` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        LineCapStyle line_cap_style() const;
        /**
     * @brief Sets the `lineCapStyle` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_cap_style(LineCapStyle value) const;
        /**
     * @brief Returns the `lineJoinStyle` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        LineJoinStyle line_join_style() const;
        /**
     * @brief Sets the `lineJoinStyle` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_join_style(LineJoinStyle value) const;
        /**
     * @brief Returns the `lineWidth` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        double line_width() const;
        /**
     * @brief Sets the `lineWidth` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_line_width(double value) const;
        /**
     * @brief Returns the `miterLimit` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        double miter_limit() const;
        /**
     * @brief Sets the `miterLimit` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_miter_limit(double value) const;
        /**
     * @brief Returns the `windingRule` property of `NSBezierPath`.
     * @return The converted Objective-C result.
     */
        WindingRule winding_rule() const;
        /**
     * @brief Sets the `windingRule` property of `NSBezierPath`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_winding_rule(WindingRule value) const;
    };
}
