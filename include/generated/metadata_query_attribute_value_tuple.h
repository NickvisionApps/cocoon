#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMetadataQueryAttributeValueTuple` (Foundation).
     * @details The 'NSMetadataQueryAttributeValueTuple' class represents attribute-value tuples, which are objects that contain the attribute name and value of a metadata attribute. Attribute-value tuples are returned by 'NSMetadataQuery' objects as the results in the value lists. Each attribute/value tuple contains the attribute name, the value, and the number of instances of that value that exist for the attribute name.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MetadataQueryAttributeValueTuple metadata_query_attribute_value_tuple;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmetadataqueryattributevaluetuple
     */
    class MetadataQueryAttributeValueTuple : public Object
    {
    public:
        /// @brief Creates a new `NSMetadataQueryAttributeValueTuple` instance and returns a handle to it.
        explicit MetadataQueryAttributeValueTuple();
        /// @brief Creates a null handle that refers to no native object.
        MetadataQueryAttributeValueTuple(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MetadataQueryAttributeValueTuple(Adopt adopt);
        /**
         * @brief Returns the `attribute` property of `NSMetadataQueryAttributeValueTuple`.
         * @details The attribute name for the tuple.
         * @return The converted Objective-C result.
         */
        std::string attribute() const;
        /**
         * @brief Returns the `count` property of `NSMetadataQueryAttributeValueTuple`.
         * @details The number of results with the given attribute value.
         * @return The converted Objective-C result.
         */
        std::uint64_t count() const;
        /**
         * @brief Returns the `value` property of `NSMetadataQueryAttributeValueTuple`.
         * @details The attribute value for the tuple.
         * @return The converted Objective-C result.
         */
        Object value() const;
    };
}
