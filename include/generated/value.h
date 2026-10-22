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
     * @details A simple container for a single C or Objective-C data item. An ''NSValue'' object can hold any of the scalar types such as 'int', 'float', and 'char', as well as pointers, structures, and object 'id' references. Use this class to work with such data types in collections (such as ''NSArray'' and ''NSSet''), [Key-value coding](https://developer.apple.com/library/archive/documentation/General/Conceptual/DevPedia-CocoaCore/KeyValueCoding.html\#//apple_ref/doc/uid/TP40008195-CH25), and other APIs that require Objective-C objects. ''NSValue'' objects are always immutable. \#\#\# Subclassing Notes The abstract ''NSValue'' class is the public interface of a class cluster consisting mostly of private, concrete classes that create and return a value object appropriate for a given situation. It is possible to subclass ''NSValue'', but doing so requires providing storage facilities for the value (which is not inherited by subclasses) and implementing two primitive methods. \#\#\#\# Methods to Override Any subclass of ''NSValue'' must override the primitive instance methods ''getValue(:)'' and ''objCType''. These methods must operate on the storage that you provide for the value. You might want to implement an initializer for your subclass that is suited to the storage you provide. The ''NSValue'' class does not have a designated initializer, so your initializer need only invoke the \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/init()> method of 'super'. The ''NSValue'' class adopts the ''NSCopying'' and ''NSSecureCoding'' protocols; if you want instances of your own custom subclass created from copying or coding, override the methods in these protocols. You may also wish to implement the \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/hash> method to make your subclass work well in collections. \#\#\#\# Alternatives to Subclassing If you need only to use ''NSValue'' objects for wrap a custom data types or structures defined by your app, you need not create an ''NSValue'' subclass. Instead, create a category that uses existing ''NSValue'' methods to store and retrieve data of your custom type. For example, the code below defines a custom Polyhedron structure and creates ''NSValue'' convenience methods to store and retrieve it: '''objc typedef struct { int numFaces; float radius; } Polyhedron; \@interface NSValue (Polyhedron) + (instancetype)valuewithPolyhedron:(Polyhedron)value; \@property (readonly) Polyhedron polyhedronValue; \@end \@implementation NSValue (Polyhedron) + (instancetype)valuewithPolyhedron:(Polyhedron)value { return [self valueWithBytes:&value objCType:\@encode(Polyhedron)]; } - (Polyhedron) polyhedronValue { Polyhedron value; [self getValue:&value]; return value; } \@end '''
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
        explicit Value(const CATransform3D& t);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Insets& insets);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Object& an_object);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Point& point);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const void* pointer);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Range& range);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Rect& rect);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value(const Size& size);
        /// @brief Creates a new `NSValue` instance and returns a handle to it.
        explicit Value();
        /// @brief Creates a null handle that refers to no native object.
        Value(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Value(Adopt adopt);
        /**
         * @brief Calls `-[NSValue getValue:]`.
         * @details Copies the value into the specified buffer. \@DeprecationSummary { This method is unsafe because it could potentially cause buffer overruns. Use ''NSValue/getValue:size:'' instead. }
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void get_value(void* value) const;
        /**
         * @brief Calls `-[NSValue getValue:size:]`.
         * @details Copies the value into the specified buffer. - Parameters: - value: A buffer into which to copy the value. The buffer must be large enough to hold the value. - size: The number of bytes to copy.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @param size Argument converted to the Objective-C parameter of the same role.
         */
        void get_value(void* value, std::uint64_t size) const;
        /**
         * @brief Calls `-[NSValue isEqualToValue:]`.
         * @details Returns a Boolean value that indicates whether the value object and another value object are equal. - Parameter value: The other value object with which to compare the value object. - Returns: 'YES' if both value objects are equal; otherwise, 'NO'. The ''NSValue'' class compares the type and contents of each value object to determine equality.
         * @param value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool is_equal_to_value(const Value& value) const;
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
         * @details The value as a non-retained pointer to an object. This method is potentially dangerous, because the returned object might have been released by the time it is used. Ensure that the object has a retained reference before using it.
         * @return The converted Objective-C result.
         */
        Object nonretained_object_value() const;
        /**
         * @brief Returns the `objCType` property of `NSValue`.
         * @details A C string containing the Objective-C type of the data contained in the value object, as encoded by the '\@encode()' compiler directive.
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
         * @details Returns the value as an untyped pointer.
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
