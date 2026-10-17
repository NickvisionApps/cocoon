#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSWritingToolsCoordinatorAnimationParameters` (AppKit).
     * @details An object you use to configure additional tasks or animations to run alongside the Writing Tools animations. When Writing Tools replaces text in one of your context objects, it provides an 'NSWritingToolsCoordinator.AnimationParameters' object for you to use to configure any additional animations. During a Writing Tools session, you hide the text under evaluation and provide a targeted preview of your content. Writing Tools animations changes to that preview, but you might need to provide additional animations for other parts of your view’s content. For example, you might need to animate any layout changes caused by the insertion or removal of text in other parts of your view. Use this object to configure those animations. You don’t create an 'NSWritingToolsCoordinator.AnimationParameters' object directly. Instead, the system creates one and passes it to the ''NSWritingToolsCoordinator/Delegate/writingToolsCoordinator(:replace:in:proposedText:reason:animationParameters:completion:)'' method of your ''NSWritingToolsCoordinator/Delegate'' object. Use that object to specify the blocks to run during and after the system animations.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::WritingToolsCoordinatorAnimationParameters writing_tools_coordinator_animation_parameters(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nswritingtoolscoordinatoranimationparameters
     */
    class WritingToolsCoordinatorAnimationParameters : public Object
    {
    public:
        WritingToolsCoordinatorAnimationParameters();
        /// @brief Creates a null handle that refers to no native object.
        WritingToolsCoordinatorAnimationParameters(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit WritingToolsCoordinatorAnimationParameters(Adopt adopt);
        /**
     * @brief Returns the `completionHandler` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details A custom block to run when the system animations finish. Set this property to a block that you want the system to run when any animations finish. The block you provide must have no return value and no parameters. The system executes this block once when the current animation finish.
     * @return The converted Objective-C result.
     */
        std::function<void()> completion_handler() const;
        /**
     * @brief Sets the `completionHandler` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details A custom block to run when the system animations finish. Set this property to a block that you want the system to run when any animations finish. The block you provide must have no return value and no parameters. The system executes this block once when the current animation finish.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_completion_handler(std::function<void()> value) const;
        /**
     * @brief Returns the `delay` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details The number of seconds the system waits before starting its animations.
     * @return The converted Objective-C result.
     */
        double delay() const;
        /**
     * @brief Returns the `duration` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details The number of seconds it takes the system animations to run.
     * @return The converted Objective-C result.
     */
        double duration() const;
        /**
     * @brief Returns the `progressHandler` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details A custom block that runs at the same time as the system animations. If you have animations you want to run at the same time as the system animations, assign a block to this property and use it to run your animations. The block you provide must have no return value and take a floating-point value as a parameter. The parameter indicates the current progress of the animations as a percentage value between '0.0' to '1.0'. The system executes your block multiple times during the course of the animations, providing an updated completion value each time.
     * @return The converted Objective-C result.
     */
        std::function<void(float)> progress_handler() const;
        /**
     * @brief Sets the `progressHandler` property of `NSWritingToolsCoordinatorAnimationParameters`.
     * @details A custom block that runs at the same time as the system animations. If you have animations you want to run at the same time as the system animations, assign a block to this property and use it to run your animations. The block you provide must have no return value and take a floating-point value as a parameter. The parameter indicates the current progress of the animations as a percentage value between '0.0' to '1.0'. The system executes your block multiple times during the course of the animations, providing an updated completion value each time.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_progress_handler(std::function<void(float)> value) const;
    };
}
