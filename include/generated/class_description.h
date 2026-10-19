#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSClassDescription` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ClassDescription class_description;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ClassDescription class_description{};
     * auto made_0 = cocoon::ClassDescription::class_description_for_class("text");
     * class_description.inverse_for_relationship_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsclassdescription
     */
    class ClassDescription : public Object
    {
    public:
        /// @brief Creates a new `NSClassDescription` instance and returns a handle to it.
        explicit ClassDescription();
        /// @brief Creates a null handle that refers to no native object.
        ClassDescription(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ClassDescription(Adopt adopt);
        /**
     * @brief Calls `+[NSClassDescription classDescriptionForClass:]`.
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ClassDescription class_description_for_class(const std::string& a_class);
        /**
     * @brief Calls `+[NSClassDescription invalidateClassDescriptionCache]`.
     */
        static void invalidate_class_description_cache();
        /**
     * @brief Calls `-[NSClassDescription inverseForRelationshipKey:]`.
     * @param relationship_key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string inverse_for_relationship_key(const std::string& relationship_key) const;
        /**
     * @brief Calls `+[NSClassDescription registerClassDescription:forClass:]`.
     * @param description Argument converted to the Objective-C parameter of the same role.
     * @param a_class Argument converted to the Objective-C parameter of the same role.
     */
        static void register_class_description(const ClassDescription& description, const std::string& a_class);
        /**
     * @brief Returns the `attributeKeys` property of `NSClassDescription`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> attribute_keys() const;
        /**
     * @brief Returns the `toManyRelationshipKeys` property of `NSClassDescription`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> to_many_relationship_keys() const;
        /**
     * @brief Returns the `toOneRelationshipKeys` property of `NSClassDescription`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> to_one_relationship_keys() const;
    };
}
