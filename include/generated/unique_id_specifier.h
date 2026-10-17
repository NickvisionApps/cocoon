#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/script_object_specifier.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class ScriptClassDescription;
    class ScriptObjectSpecifier;

    /**
     * @brief C++ handle for the Objective-C class `NSUniqueIDSpecifier` (Foundation).
     * @details A specifier for an object in a collection (or container) by unique ID. This specifier works only for objects that have an ID property. The unique ID object passed to an instance of 'NSUniqueIDSpecifier' must be either an 'NSNumber' object or an 'NSString' object. The exact type should match the scripting dictionary declaration of the ID attribute for the relevant scripting class. You can expect that the ID property will be read only for any object that supports it. Therefore a scripter can obtain the unique ID for an object and refer to the object by the ID, but cannot set the unique ID. You don't normally subclass 'NSUniqueIDSpecifier'. The evaluation of 'NSUniqueIDSpecifier' objects follows these steps until the specified object is found: 1. If the container implements a method whose selector matches the relevant 'valueIn\<Key>WithUniqueID:' pattern established by scripting key-value coding, the method is invoked. This method can potentially be very fast, and it may be relatively easy to implement. 2. As is the case when evaluating any script object specifier, the container of the specified object is given a chance to evaluate the object specifier. If the container class implements the \<doc://com.apple.documentation/documentation/objectivec/nsobject-swift.class/indicesofobjects(byevaluatingobjectspecifier:)> method, the method is invoked. This method can potentially be very fast, but it is relatively difficult to implement. 3. An ''NSWhoseSpecifier'' object that specifies the first object whose relevant ''ID '' attribute matches the ID is synthesized and evaluated. The 'NSWhoseSpecifier' object must search through all of the keyed elements in the container, looking for a match. The search is potentially very slow.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UniqueIDSpecifier unique_id_specifier;
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsuniqueidspecifier
     */
    class UniqueIDSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSUniqueIDSpecifier` instance and returns a handle to it.
        explicit UniqueIDSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const Object& unique_id);
        /// @brief Creates a new `NSUniqueIDSpecifier` instance and returns a handle to it.
        explicit UniqueIDSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        UniqueIDSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UniqueIDSpecifier(Adopt adopt);
        /**
     * @brief Returns the `uniqueID` property of `NSUniqueIDSpecifier`.
     * @details The unique ID of the object to be located.
     * @return The converted Objective-C result.
     */
        Object unique_id() const;
        /**
     * @brief Sets the `uniqueID` property of `NSUniqueIDSpecifier`.
     * @details The unique ID of the object to be located.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_unique_id(const Object& value) const;
    };
}
