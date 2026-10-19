#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSMetadataItem` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MetadataItem metadata_item;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::MetadataItem metadata_item{};
     * metadata_item.value_for_attribute("text");
     * metadata_item.values_for_attributes({"a", "b"});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmetadataitem
     */
    class MetadataItem : public Object
    {
    public:
        /// @brief Creates a new `NSMetadataItem` instance and returns a handle to it.
        explicit MetadataItem(const URL& url);
        /// @brief Creates a new `NSMetadataItem` instance and returns a handle to it.
        explicit MetadataItem();
        /// @brief Creates a null handle that refers to no native object.
        MetadataItem(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MetadataItem(Adopt adopt);
        /**
     * @brief Calls `-[NSMetadataItem valueForAttribute:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object value_for_attribute(const std::string& key) const;
        /**
     * @brief Calls `-[NSMetadataItem valuesForAttributes:]`.
     * @param keys Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> values_for_attributes(const std::vector<std::string>& keys) const;
        /**
     * @brief Returns the `attributes` property of `NSMetadataItem`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> attributes() const;
    };
}
