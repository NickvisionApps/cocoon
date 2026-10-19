#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BezierPath;

    /**
     * @brief C++ handle for the Objective-C class `NSAffineTransform` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AffineTransform affine_transform;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AffineTransform affine_transform{};
     * auto made_0 = cocoon::AffineTransform::transform();
     * affine_transform.append_transform(cocoon::AffineTransform());
     * affine_transform.concat();
     * affine_transform.invert();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsaffinetransform
     */
    class AffineTransform : public Object
    {
    public:
        /// @brief Creates a new `NSAffineTransform` instance and returns a handle to it.
        explicit AffineTransform();
        /// @brief Creates a null handle that refers to no native object.
        AffineTransform(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AffineTransform(Adopt adopt);
        /**
     * @brief Calls `-[NSAffineTransform appendTransform:]`.
     * @param transform Argument converted to the Objective-C parameter of the same role.
     */
        void append_transform(const AffineTransform& transform) const;
        /**
     * @brief Calls `-[NSAffineTransform concat]`.
     */
        void concat() const;
        /**
     * @brief Calls `-[NSAffineTransform invert]`.
     */
        void invert() const;
        /**
     * @brief Calls `-[NSAffineTransform prependTransform:]`.
     * @param transform Argument converted to the Objective-C parameter of the same role.
     */
        void prepend_transform(const AffineTransform& transform) const;
        /**
     * @brief Calls `-[NSAffineTransform rotateByDegrees:]`.
     * @param angle Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_by_degrees(double angle) const;
        /**
     * @brief Calls `-[NSAffineTransform rotateByRadians:]`.
     * @param angle Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_by_radians(double angle) const;
        /**
     * @brief Calls `-[NSAffineTransform scaleBy:]`.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     */
        void scale_by(double scale) const;
        /**
     * @brief Calls `-[NSAffineTransform scaleXBy:yBy:]`.
     * @param scale_x Argument converted to the Objective-C parameter of the same role.
     * @param scale_y Argument converted to the Objective-C parameter of the same role.
     */
        void scale_x_by(double scale_x, double scale_y) const;
        /**
     * @brief Calls `-[NSAffineTransform set]`.
     */
        void set() const;
        /**
     * @brief Calls `+[NSAffineTransform transform]`.
     * @return The converted Objective-C result.
     */
        static AffineTransform transform();
        /**
     * @brief Calls `-[NSAffineTransform transformBezierPath:]`.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        BezierPath transform_bezier_path(const BezierPath& path) const;
        /**
     * @brief Calls `-[NSAffineTransform transformPoint:]`.
     * @param a_point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point transform_point(const Point& a_point) const;
        /**
     * @brief Calls `-[NSAffineTransform transformSize:]`.
     * @param a_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size transform_size(const Size& a_size) const;
        /**
     * @brief Calls `-[NSAffineTransform translateXBy:yBy:]`.
     * @param delta_x Argument converted to the Objective-C parameter of the same role.
     * @param delta_y Argument converted to the Objective-C parameter of the same role.
     */
        void translate_x_by(double delta_x, double delta_y) const;
        /**
     * @brief Returns the `transformStruct` property of `NSAffineTransform`.
     * @return The converted Objective-C result.
     */
        AffineTransformStruct transform_struct() const;
        /**
     * @brief Sets the `transformStruct` property of `NSAffineTransform`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transform_struct(const AffineTransformStruct& value) const;
    };
}
