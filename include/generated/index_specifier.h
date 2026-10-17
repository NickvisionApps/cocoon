#pragma once

#include "generated/enums.h"
#include "generated/script_object_specifier.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSIndexSpecifier` (Foundation).
     * @details A specifier representing an object in a collection (or container) with an index number. The script terms 'first' and 'front' specify the object with index '0', while 'last' specifies the object with index of 'count-1'. A negative index indicates a location by counting backward from the last object in the collection. You don't normally subclass 'NSIndexSpecifier'.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::IndexSpecifier index_specifier;
     * index_specifier.set_index(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::IndexSpecifier index_specifier{};
     * index_specifier.set_index(1);
     * auto index = index_specifier.index();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsindexspecifier
     */
    class IndexSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSIndexSpecifier` instance and returns a handle to it.
        explicit IndexSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, std::int64_t index);
        /// @brief Creates a new `NSIndexSpecifier` instance and returns a handle to it.
        explicit IndexSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        IndexSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit IndexSpecifier(Adopt adopt);
        /**
     * @brief Returns the `index` property of `NSIndexSpecifier`.
     * @details The index position of the object to be retrieved.
     * @return The converted Objective-C result.
     */
        std::int64_t index() const;
        /**
     * @brief Sets the `index` property of `NSIndexSpecifier`.
     * @details The index position of the object to be retrieved.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_index(std::int64_t value) const;
    };
}
