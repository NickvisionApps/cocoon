#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSMetadataQueryResultGroup` (Foundation).
     * @details The 'NSMetadataQueryResultGroup' class represents a collection of grouped attribute results returned by an ''NSMetadataQuery'' object.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MetadataQueryResultGroup metadata_query_result_group;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MetadataQueryResultGroup metadata_query_result_group{};
     * metadata_query_result_group.result_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmetadataqueryresultgroup
     */
    class MetadataQueryResultGroup : public Object
    {
    public:
        /// @brief Creates a new `NSMetadataQueryResultGroup` instance and returns a handle to it.
        explicit MetadataQueryResultGroup();
        /// @brief Creates a null handle that refers to no native object.
        MetadataQueryResultGroup(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MetadataQueryResultGroup(Adopt adopt);
        /**
     * @brief Calls `-[NSMetadataQueryResultGroup resultAtIndex:]`.
     * @details Returns the result at the specified index within this group.
     * @param idx Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object result_at_index(std::uint64_t idx) const;
        /**
     * @brief Returns the `attribute` property of `NSMetadataQueryResultGroup`.
     * @details The attribute name for this result group.
     * @return The converted Objective-C result.
     */
        std::string attribute() const;
        /**
     * @brief Returns the `resultCount` property of `NSMetadataQueryResultGroup`.
     * @details The number of results in this group.
     * @return The converted Objective-C result.
     */
        std::uint64_t result_count() const;
        /**
     * @brief Returns the `results` property of `NSMetadataQueryResultGroup`.
     * @details An array containing the results in this group. This is for K-V Bindings, and causes side-effects on the query.
     * @return The converted Objective-C result.
     */
        std::vector<Object> results() const;
        /**
     * @brief Returns the `subgroups` property of `NSMetadataQueryResultGroup`.
     * @details An array of subgroups for this result group, or nil if this is a leaf group.
     * @return The converted Objective-C result.
     */
        std::vector<MetadataQueryResultGroup> subgroups() const;
        /**
     * @brief Returns the `value` property of `NSMetadataQueryResultGroup`.
     * @details The attribute value for this result group.
     * @return The converted Objective-C result.
     */
        Object value() const;
    };
}
