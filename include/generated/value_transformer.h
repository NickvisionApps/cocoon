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
     * @return The converted Objective-C result.
     */
        static bool allows_reverse_transformation();
        /**
     * @brief Calls `-[NSValueTransformer reverseTransformedValue:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object reverse_transformed_value(const Object& value) const;
        /**
     * @brief Calls `+[NSValueTransformer setValueTransformer:forName:]`.
     * @param transformer Argument converted to the Objective-C parameter of the same role.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        static void set_value_transformer(const ValueTransformer& transformer, const std::string& name);
        /**
     * @brief Calls `-[NSValueTransformer transformedValue:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object transformed_value(const Object& value) const;
        /**
     * @brief Calls `+[NSValueTransformer transformedValueClass]`.
     * @return The converted Objective-C result.
     */
        static std::string transformed_value_class();
        /**
     * @brief Calls `+[NSValueTransformer valueTransformerForName:]`.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ValueTransformer value_transformer_for_name(const std::string& name);
        /**
     * @brief Calls `+[NSValueTransformer valueTransformerNames]`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> value_transformer_names();
    };
}
