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
     * @return The converted Objective-C result.
     */
        std::string attribute() const;
        /**
     * @brief Returns the `count` property of `NSMetadataQueryAttributeValueTuple`.
     * @return The converted Objective-C result.
     */
        std::uint64_t count() const;
        /**
     * @brief Returns the `value` property of `NSMetadataQueryAttributeValueTuple`.
     * @return The converted Objective-C result.
     */
        Object value() const;
    };
}
