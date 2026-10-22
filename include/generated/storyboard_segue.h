#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSStoryboardSegue` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StoryboardSegue storyboard_segue;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StoryboardSegue storyboard_segue{};
     * storyboard_segue.perform();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstoryboardsegue
     */
    class StoryboardSegue : public Object
    {
    public:
        /// @brief Creates a new `NSStoryboardSegue` instance and returns a handle to it.
        explicit StoryboardSegue(const std::string& identifier, const Object& source_controller, const Object& destination_controller);
        /// @brief Creates a new `NSStoryboardSegue` instance and returns a handle to it.
        explicit StoryboardSegue();
        /// @brief Creates a null handle that refers to no native object.
        StoryboardSegue(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StoryboardSegue(Adopt adopt);
        /**
         * @brief Calls `-[NSStoryboardSegue perform]`.
         * @details This method is implemented by NSStoryboardSegue subclasses to present a custom transition between two controllers.
         */
        void perform() const;
        /**
         * @brief Calls `+[NSStoryboardSegue segueWithIdentifier:source:destination:performHandler:]`.
         * @param identifier Argument converted to the Objective-C parameter of the same role.
         * @param source_controller Argument converted to the Objective-C parameter of the same role.
         * @param destination_controller Argument converted to the Objective-C parameter of the same role.
         * @param perform_handler Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static StoryboardSegue segue_with_identifier(const std::string& identifier, const Object& source_controller, const Object& destination_controller, std::function<void()> perform_handler);
        /**
         * @brief Returns the `destinationController` property of `NSStoryboardSegue`.
         * @details Subclasses of NSStoryboardSegue can use this property to access the destination view or window controller that's being segued to. This property is also essential for overrides of -[NSViewController prepareForSegue:sender:], which is passed to the source view controller. This property allows the receiver of -[NSViewController prepareForSegue:sender:] to access and pass configuration data to the destination controller.
         * @return The converted Objective-C result.
         */
        Object destination_controller() const;
        /**
         * @brief Returns the `identifier` property of `NSStoryboardSegue`.
         * @details NSStoryboardSegue instances have optional identifiers that can be assigned in Interface Builder. These identifiers can be used in overrides of -[NSViewController prepareForSegue:sender:] to differentiate segues.
         * @return The converted Objective-C result.
         */
        std::string identifier() const;
        /**
         * @brief Returns the `sourceController` property of `NSStoryboardSegue`.
         * @details Subclasses of NSStoryboardSegue can use this property to access the source view or window controller that is being segued away from.
         * @return The converted Objective-C result.
         */
        Object source_controller() const;
    };
}
