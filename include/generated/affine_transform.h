#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class BezierPath;

    /**
     * @brief C++ handle for the Objective-C class `NSAffineTransform` (Foundation).
     * @details A graphics coordinate transformation. In Swift, this object bridges to ''AffineTransform''; use ''NSAffineTransform'' when you need reference semantics or other Foundation-specific behavior. A transformation specifies how points in one coordinate system are transformed to points in another coordinate system. An affine transformation is a special type of transformation that preserves parallel lines in a path but does not necessarily preserve lengths or angles. Scaling, rotation, and translation are the most commonly used manipulations supported by affine transforms, but shearing is also possible. > Note: > In OS X 10.3 and earlier the ''NSAffineTransform'' class was declared and implemented entirely in the Application Kit framework. As of macOS 10.4 the ''NSAffineTransform'' class has been split across the Foundation and Application Kit frameworks. Methods for applying affine transformations to the current graphics context and a method for applying an affine transformation to an \<doc://com.apple.documentation/documentation/appkit/nsbezierpath> object are described in NSAffineTransform Additions Reference in the Application Kit. > Important: > The Swift overlay to the Foundation framework provides the ''AffineTransform'' structure, which bridges to the ''NSAffineTransform'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
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
     * @details Appends the specified matrix to the receiver's matrix. This method multiplies the receiver's matrix by the matrix in 'transform' and replaces the receiver's matrix with the results. This type of operation is the same as applying the transformations in the receiver followed by the transformations in 'transform'. - Parameter transform: The matrix to append to the receiver.
     * @param transform Argument converted to the Objective-C parameter of the same role.
     */
        void append_transform(const AffineTransform& transform) const;
        /**
     * @brief Calls `-[NSAffineTransform concat]`.
     */
        void concat() const;
        /**
     * @brief Calls `-[NSAffineTransform invert]`.
     * @details Replaces the receiver's matrix with its inverse matrix. Inverse matrices are useful for undoing the effects of a matrix. If a previous point (x,y) was transformed to (x',y'), inverting the matrix and applying it to point (x',y') yields the point (x,y). You can also use inverse matrices in conjunction with the 'concat()' method to remove the effects of concatenating the matrix to the current transformation matrix of the current graphic context.
     */
        void invert() const;
        /**
     * @brief Calls `-[NSAffineTransform prependTransform:]`.
     * @details Prepends the specified matrix to the receiver's matrix. This method multiplies the matrix in 'transform' by the receiver's matrix and replaces the receiver's matrix with the result. This type of operation is the same as applying the transformations in 'transform' followed by the transformations in the receiver. - Parameter transform: The matrix to prepend to the receiver.
     * @param transform Argument converted to the Objective-C parameter of the same role.
     */
        void prepend_transform(const AffineTransform& transform) const;
        /**
     * @brief Calls `-[NSAffineTransform rotateByDegrees:]`.
     * @details Applies a rotation factor (measured in degrees) to the receiver's transformation matrix. After invoking this method, applying the receiver's matrix turns the axes counterclockwise about the current origin by 'angle' degrees, in addition to performing all previous transformations. - Parameter angle: The rotation angle, measured in degrees.
     * @param angle Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_by_degrees(double angle) const;
        /**
     * @brief Calls `-[NSAffineTransform rotateByRadians:]`.
     * @details Applies a rotation factor (measured in radians) to the receiver's transformation matrix. After invoking this method, applying the receiver's matrix turns the axes counterclockwise about the current origin by 'angle' radians, in addition to performing all previous transformations. - Parameter angle: The rotation angle, measured in radians.
     * @param angle Argument converted to the Objective-C parameter of the same role.
     */
        void rotate_by_radians(double angle) const;
        /**
     * @brief Calls `-[NSAffineTransform scaleBy:]`.
     * @details Applies the specified scaling factor along both x and y axes to the receiver's transformation matrix. After invoking this method, applying the receiver's matrix modifies the unit lengths along the current x and y axes by a factor of 'scale', in addition to performing all previous transformations. - Parameter scale: The scaling factor to apply to both axes. Specifying a negative value has the effect of inverting the direction of the axes in addition to scaling them. A scaling factor of 1.0 scales the content to exactly the same size.
     * @param scale Argument converted to the Objective-C parameter of the same role.
     */
        void scale_by(double scale) const;
        /**
     * @brief Calls `-[NSAffineTransform scaleXBy:yBy:]`.
     * @details Applies scaling factors to each axis of the receiver's transformation matrix. After invoking this method, applying the receiver's matrix modifies the unit length on the x axis by a factor of 'scaleX' and the y axis by a factor of 'scaleY', in addition to performing all previous transformations. A value of 1.0 for either axis scales the content on that axis to the same size. - Parameter scaleX: The scaling factor to apply to the x axis. - Parameter scaleY: The scaling factor to apply to the y axis.
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
     * @details Creates a new affine transform initialized to the identity matrix. - Returns: A new identity transform object. This matrix transforms any point to the same point.
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
     * @details Applies the receiver's transform to the specified point and returns the result. - Parameter aPoint: The point in the current coordinate system to which you want to apply the matrix. - Returns: The resulting point after applying the receiver's transformations.
     * @param a_point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Point transform_point(const Point& a_point) const;
        /**
     * @brief Calls `-[NSAffineTransform transformSize:]`.
     * @details Applies the receiver's transform to the specified size and returns the results. This method applies the current rotation and scaling factors to 'aSize'; it does not apply translation factors. You can think of this method as transforming a vector whose origin is (0, 0) and whose end point is specified by the value in 'aSize'. After the rotation and scaling factors are applied, this method effectively returns the end point of the new vector. This method is useful for transforming delta or distance values when you need to take scaling and rotation factors into account. - Parameter aSize: The size data to which you want to apply the matrix. - Returns: The resulting size after applying the receiver's transformations.
     * @param a_size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size transform_size(const Size& a_size) const;
        /**
     * @brief Calls `-[NSAffineTransform translateXBy:yBy:]`.
     * @details Applies the specified translation factors to the receiver's transformation matrix. Subsequent transformations cause coordinates to be shifted by 'deltaX' units along the x axis and by 'deltaY' units along the y axis. Translation factors do not affect 'NSSize' values, which specify a differential between points. - Parameter deltaX: The number of units to move along the x axis. - Parameter deltaY: The number of units to move along the y axis.
     * @param delta_x Argument converted to the Objective-C parameter of the same role.
     * @param delta_y Argument converted to the Objective-C parameter of the same role.
     */
        void translate_x_by(double delta_x, double delta_y) const;
        /**
     * @brief Returns the `transformStruct` property of `NSAffineTransform`.
     * @details The matrix coefficients stored as the transformation matrix. The ''NSAffineTransformStruct'' structure is an alternate representation of a transformation matrix that can be used to specify matrix values directly. The six-element structure is of the form '{m11, m12, m21, m22, tX, tY}'.
     * @return The converted Objective-C result.
     */
        AffineTransformStruct transform_struct() const;
        /**
     * @brief Sets the `transformStruct` property of `NSAffineTransform`.
     * @details The matrix coefficients stored as the transformation matrix. The ''NSAffineTransformStruct'' structure is an alternate representation of a transformation matrix that can be used to specify matrix values directly. The six-element structure is of the form '{m11, m12, m21, m22, tX, tY}'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transform_struct(const AffineTransformStruct& value) const;
    };
}
