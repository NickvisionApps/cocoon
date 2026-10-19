#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSValue` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Value value;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Value value{};
     * auto made_0 = cocoon::Value::value_with_edge_insets(cocoon::Insets(8));
     * auto made_1 = cocoon::Value::value_with_point({0, 0});
     * value.is_equal_to_value(cocoon::Value());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsvalue
     */
    class Value : public Object
    {
    public:
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const void* value, const std::string& type);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value();
        /// @brief Creates a null handle that refers to no native object.
        Value(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Value(Adopt adopt);
        /**
     * @brief Calls `-[NSValue getValue:]`.
     * @details This method is unsafe because it could potentially cause buffer overruns. You should use -getValue:size: instead.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void get_value(void* value) const;
        /**
     * @brief Calls `-[NSValue getValue:size:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param size Argument converted to the Objective-C parameter of the same role.
     */
        void get_value(void* value, std::uint64_t size) const;
        /**
     * @brief Calls `-[NSValue isEqualToValue:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_value(const Value& value) const;
        /**
     * @brief Calls `+[NSValue value:withObjCType:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value(const void* value, const std::string& type);
        /**
     * @brief Calls `+[NSValue valueWithBytes:objCType:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param type Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_bytes(const void* value, const std::string& type);
        /**
     * @brief Calls `+[NSValue valueWithCATransform3D:]`.
     * @param t Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_ca_transform3_d(const CATransform3D& t);
        /**
     * @brief Calls `+[NSValue valueWithEdgeInsets:]`.
     * @param insets Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_edge_insets(const Insets& insets);
        /**
     * @brief Calls `+[NSValue valueWithNonretainedObject:]`.
     * @param an_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_nonretained_object(const Object& an_object);
        /**
     * @brief Calls `+[NSValue valueWithPoint:]`.
     * @param point Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_point(const Point& point);
        /**
     * @brief Calls `+[NSValue valueWithPointer:]`.
     * @param pointer Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_pointer(const void* pointer);
        /**
     * @brief Calls `+[NSValue valueWithRange:]`.
     * @param range Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_range(const Range& range);
        /**
     * @brief Calls `+[NSValue valueWithRect:]`.
     * @param rect Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_rect(const Rect& rect);
        /**
     * @brief Calls `+[NSValue valueWithSize:]`.
     * @param size Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Value value_with_size(const Size& size);
        /**
     * @brief Returns the `CATransform3DValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        CATransform3D ca_transform3_d_value() const;
        /**
     * @brief Returns the `edgeInsetsValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Insets edge_insets_value() const;
        /**
     * @brief Returns the `nonretainedObjectValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Object nonretained_object_value() const;
        /**
     * @brief Returns the `objCType` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        std::string obj_c_type() const;
        /**
     * @brief Returns the `pointValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Point point_value() const;
        /**
     * @brief Returns the `pointerValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        void* pointer_value() const;
        /**
     * @brief Returns the `rangeValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Range range_value() const;
        /**
     * @brief Returns the `rectValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Rect rect_value() const;
        /**
     * @brief Returns the `sizeValue` property of `NSValue`.
     * @return The converted Objective-C result.
     */
        Size size_value() const;
    };
}
