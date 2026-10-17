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
     * @brief C++ handle for the Objective-C class `NSNameSpecifier` (Foundation).
     * @details A specifier for an object in a collection (or container) by name. As an example, the following script specifies both an application and a window by name. In this script, the named window's implicitly specified container is the Finder application's list of open windows. '''objc tell application "Finder" -- specifies an application by name close window "Reports" -- specifies a window by name end tell ''' This specifier works only for objects that have a name property. You don't normally subclass 'NSNameSpecifier'. The evaluation of an instance of 'NSNameSpecifier' follows these steps until the specified object is found: 1. If the container implements a method whose selector matches the relevant 'valueIn\<Key>WithName:' pattern established by scripting key-value coding, the method is invoked. This method can potentially be very fast, and it may be relatively easy to implement. 2. As is the case when evaluating any script object specifier, the container of the specified object is given a chance to evaluate the object specifier. If the container class implements the 'indicesOfObjectsByEvaluatingObjectSpecifier' method, the method is invoked. This method can potentially be very fast, but it is relatively difficult to implement. 3. An instance of 'NSWhoseSpecifier' that specifies the first object whose relevant ''pnam'' attribute matches the name is synthesized and evaluated. The instance of 'NSWhoseSpecifier' must search through all of the keyed elements in the container, looking for a match. The search is potentially very slow.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref ScriptObjectSpecifier.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::NameSpecifier name_specifier;
     * name_specifier.set_name("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::NameSpecifier name_specifier{};
     * name_specifier.set_name("text");
     * auto name = name_specifier.name();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsnamespecifier
     */
    class NameSpecifier : public ScriptObjectSpecifier
    {
    public:
        /// @brief Creates a new `NSNameSpecifier` instance and returns a handle to it.
        explicit NameSpecifier(const ScriptClassDescription& class_desc, const ScriptObjectSpecifier& container, const std::string& property, const std::string& name);
        /// @brief Creates a new `NSNameSpecifier` instance and returns a handle to it.
        explicit NameSpecifier();
        /// @brief Creates a null handle that refers to no native object.
        NameSpecifier(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit NameSpecifier(Adopt adopt);
        /**
     * @brief Returns the `name` property of `NSNameSpecifier`.
     * @details The name of the object to be retrieved.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSNameSpecifier`.
     * @details The name of the object to be retrieved.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
    };
}
