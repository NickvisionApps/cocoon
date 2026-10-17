#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class ViewCornerRadius;

    /**
     * @brief C++ handle for the Objective-C class `NSViewCornerConfiguration` (AppKit).
     * @details A configuration object that defines the corner styles of a view’s overall shape.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ViewCornerConfiguration view_corner_configuration(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ViewCornerConfiguration view_corner_configuration(nullptr);
     * auto made_0 = cocoon::ViewCornerConfiguration::capsule_corner_configuration_with_maximum_radius(1);
     * auto made_1 = cocoon::ViewCornerConfiguration::configuration_with_radius(cocoon::ViewCornerRadius());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewcornerconfiguration
     */
    class ViewCornerConfiguration : public Object
    {
    public:
        ViewCornerConfiguration();
        /// @brief Creates a null handle that refers to no native object.
        ViewCornerConfiguration(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewCornerConfiguration(Adopt adopt);
        /**
     * @brief Calls `+[NSViewCornerConfiguration capsuleCornerConfigurationWithMaximumRadius:]`.
     * @details A configuration where the container is to take on a capsule shape, scaling with the view’s size. and clamped to the 'maximumRadius'. - Parameters maximumRadius: Maximum radius for the capsule.
     * @param maximum_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration capsule_corner_configuration_with_maximum_radius(double maximum_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithRadius:]`.
     * @details A configuration that applies the given radius independently to all corners. When used with a container concentric radius, this allows each individual corner to resolve to different radii.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_radius(const ViewCornerRadius& radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithTopLeftRadius:topRightRadius:bottomLeftRadius:bottomRightRadius:]`.
     * @details A configuration with independent radii for each corner. - Parameters: - topLeftRadius: Radius of top left corner. - topRightRadius: Radius of top right corner. - bottomLeftRadius: Radius of bottom left corner. - bottomRightRadius: Radius of bottom right corner.
     * @param top_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_right_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_top_left_radius(const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformBottomRadius:topLeftRadius:topRightRadius:]`.
     * @details A configuration that applies the 'bottomRadius' uniformly to the bottom-left and bottom-right corners, with optional independent radii for the top-left and top-right corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - bottomRadius: Radius for bottom edge. - topLeftRadius: Radius for the top left corner. - topRightRadius: Radius for the top right corner.
     * @param bottom_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_bottom_radius(const ViewCornerRadius& bottom_radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformLeftRadius:rightRadius:]`.
     * @details A configuration that applies the 'leftRadius' uniformly to the top-left and bottom-left corners, and the 'rightRadius' uniformly to the top-right and bottom-right corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - leftRadius: Radius for left edge. - rightRadius: Radius for the right edge.
     * @param left_radius Argument converted to the Objective-C parameter of the same role.
     * @param right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_left_radius(const ViewCornerRadius& left_radius, const ViewCornerRadius& right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformLeftRadius:topRightRadius:bottomRightRadius:]`.
     * @details A configuration that applies the 'leftRadius' uniformly to the top-left and bottom-left corners, with optional independent radii for the top-right and bottom-right corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - leftRadius: Radius for left edge. - topRightRadius: Radius for the top right corner. - bottomRightRadius: Radius for the bottom right corner.
     * @param left_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_right_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_left_radius(const ViewCornerRadius& left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformRadius:]`.
     * @details A configuration that applies the given radius uniformly to all corners, using the largest of the resolved corner radii when they differ. - Parameters radius: Radius for all corners.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_radius(const ViewCornerRadius& radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformRadius:topLeftRadius:topRightRadius:bottomLeftRadius:bottomRightRadius:]`.
     * @details A configuration that applies the given uniform radius uniformly to all corners that are otherwise unspecified. Any specified corner is independent of the others. - Parameters: - radius: Uniform radius for all unspecified corners. - topLeftRadius: Radius of top left corner. - topRightRadius: Radius of top right corner. - bottomLeftRadius: Radius of bottom left corner. - bottomRightRadius: Radius of bottom right corner.
     * @param radius Argument converted to the Objective-C parameter of the same role.
     * @param top_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_right_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_radius(const ViewCornerRadius& radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& top_right_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformRightRadius:topLeftRadius:bottomLeftRadius:]`.
     * @details A configuration that applies the 'rightRadius' uniformly to the top-right and bottom-right corners, with optional independent radii for the top-left and bottom-left corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - rightRadius: Radius for right edge. - topLeftRadius: Radius for the top left corner. - bottomLeftRadius: Radius for the bottom left corner.
     * @param right_radius Argument converted to the Objective-C parameter of the same role.
     * @param top_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_left_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_right_radius(const ViewCornerRadius& right_radius, const ViewCornerRadius& top_left_radius, const ViewCornerRadius& bottom_left_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformTopRadius:bottomLeftRadius:bottomRightRadius:]`.
     * @details A configuration that applies the 'topRadius' uniformly to the top-left and top-right corners, with optional independent radii for the bottom-left and bottom-right corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - topRadius: Radius for top edge. - bottomLeftRadius: Radius for the bottom left corner. - bottomRightRadius: Radius for the bottom right corner.
     * @param top_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_left_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_right_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_top_radius(const ViewCornerRadius& top_radius, const ViewCornerRadius& bottom_left_radius, const ViewCornerRadius& bottom_right_radius);
        /**
     * @brief Calls `+[NSViewCornerConfiguration configurationWithUniformTopRadius:bottomRadius:]`.
     * @details A configuration that applies the 'topRadius' uniformly to the top-left and top-right corners, and the 'bottomRadius' uniformly to the bottom-left and bottom-right corners. When the uniform corners differ, it uses the largest of the resolved corner radii. - Parameters: - topRadius: Radius for top edge. - bottomRadius: Radius for the bottom edge.
     * @param top_radius Argument converted to the Objective-C parameter of the same role.
     * @param bottom_radius Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration configuration_with_uniform_top_radius(const ViewCornerRadius& top_radius, const ViewCornerRadius& bottom_radius);
        /**
     * @brief Returns the `capsuleCornerConfiguration` property of `NSViewCornerConfiguration`.
     * @details A configuration where the container is to take on a capsule shape, scaling with the view’s size.
     * @return The converted Objective-C result.
     */
        static ViewCornerConfiguration capsule_corner_configuration();
    };
}
