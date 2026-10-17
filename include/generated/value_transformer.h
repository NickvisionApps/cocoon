#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSValueTransformer` (Foundation).
     * @details An abstract class used to transform values from one representation to another.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ValueTransformer value_transformer;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ValueTransformer value_transformer{};
     * auto made_0 = cocoon::ValueTransformer::value_transformer_for_name("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsvaluetransformer
     */
    class ValueTransformer : public Object
    {
    public:
        /// @brief Creates a new `NSValueTransformer` instance and returns a handle to it.
        explicit ValueTransformer();
        /// @brief Creates a null handle that refers to no native object.
        ValueTransformer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ValueTransformer(Adopt adopt);
        /**
     * @brief Calls `+[NSValueTransformer allowsReverseTransformation]`.
     * @details Returns a Boolean value that indicates whether the receiver can reverse a transformation.
     * @return The converted Objective-C result.
     */
        static bool allows_reverse_transformation();
        /**
     * @brief Calls `-[NSValueTransformer reverseTransformedValue:]`.
     * @details Returns the result of the reverse transformation of a given value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object reverse_transformed_value(const Object& value) const;
        /**
     * @brief Calls `+[NSValueTransformer setValueTransformer:forName:]`.
     * @details Registers the provided value transformer with a given identifier.
     * @param transformer Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        static void set_value_transformer(const ValueTransformer& transformer, const std::string& name);
        /**
     * @brief Calls `-[NSValueTransformer transformedValue:]`.
     * @details Returns the result of transforming a given value.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object transformed_value(const Object& value) const;
        /**
     * @brief Calls `+[NSValueTransformer transformedValueClass]`.
     * @details Returns the class of objects returned when applying the value transformer.
     * @return The converted Objective-C result.
     */
        static std::string transformed_value_class();
        /**
     * @brief Calls `+[NSValueTransformer valueTransformerForName:]`.
     * @details Returns the value transformer identified by a given identifier.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ValueTransformer value_transformer_for_name(const std::string& name);
        /**
     * @brief Calls `+[NSValueTransformer valueTransformerNames]`.
     * @details Returns an array of all the registered value transformer names.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> value_transformer_names();
    };
}
