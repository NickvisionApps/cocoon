#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Bundle;
    class Coder;

    /**
     * @brief C++ handle for the Objective-C class `NSStoryboard` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Storyboard storyboard;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Storyboard storyboard{};
     * storyboard.instantiate_controller_with_identifier("text");
     * storyboard.instantiate_initial_controller();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstoryboard
     */
    class Storyboard : public Object
    {
    public:
        /// @brief Creates a new `NSStoryboard` instance and returns a handle to it.
        explicit Storyboard(const std::string& name, const Bundle& storyboard_bundle_or_nil);
        /// @brief Creates a new `NSStoryboard` instance and returns a handle to it.
        explicit Storyboard();
        /// @brief Creates a null handle that refers to no native object.
        Storyboard(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Storyboard(Adopt adopt);
        /**
     * @brief Calls `-[NSStoryboard instantiateControllerWithIdentifier:]`.
     * @details Controllers in Interface Builder have an optional identifier within the storyboard. That identifier is set from the inspector in Interface Builder. The identifiers are optional, meaning that the developer only has to assign an identifier to a controller if they want to be able to manually invoke this method from code.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object instantiate_controller_with_identifier(const std::string& identifier) const;
        /**
     * @brief Calls `-[NSStoryboard instantiateControllerWithIdentifier:creator:]`.
     * @details Controllers in Interface Builder have an optional identifier within the storyboard. That identifier is set from the inspector in Interface Builder. The identifiers are optional, meaning that the developer only has to assign an identifier to a controller if they want to be able to manually invoke this method from code. A creator can be specified for controller instantiation, giving the developer a chance to call an initalizer that takes an NSCoder and additional arguments. If the block returns nil, the view controller will be created using the standard initWithCoder: initializer.
     * @param identifier Argument converted to the Objective-C parameter of the same role.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object instantiate_controller_with_identifier(const std::string& identifier, std::function<Object(Coder)> block) const;
        /**
     * @brief Calls `-[NSStoryboard instantiateInitialController]`.
     * @details Every storyboard may have an initial view or window controller. Each invocation of this method instantiates an instance of the initial controller. The developer chooses the initial controller in an inspector within Interface Builder.
     * @return The converted Objective-C result.
     */
        Object instantiate_initial_controller() const;
        /**
     * @brief Calls `-[NSStoryboard instantiateInitialControllerWithCreator:]`.
     * @details Every storyboard may have an initial view or window controller. Each invocation of this method instantiates an instance of the initial controller. The developer chooses the initial controller in an inspector within Interface Builder. A creator can be specified for controller instantiation, giving the developer a chance to call an initalizer that takes an NSCoder and additional arguments. If the block returns nil, the initial view controller will be created using the standard initWithCoder: initializer.
     * @param block Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object instantiate_initial_controller_with_creator(std::function<Object(Coder)> block) const;
        /**
     * @brief Returns the `mainStoryboard` property of `NSStoryboard`.
     * @details The main UI storyboard for the application, specified by the "NSMainStoryboardFile" key in its Info.plist
     * @return The converted Objective-C result.
     */
        static Storyboard main_storyboard();
    };
}
