#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUserInterfaceCompressionOptions` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::UserInterfaceCompressionOptions user_interface_compression_options;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::UserInterfaceCompressionOptions user_interface_compression_options{};
     * user_interface_compression_options.contains_options(cocoon::UserInterfaceCompressionOptions());
     * user_interface_compression_options.intersects_options(cocoon::UserInterfaceCompressionOptions());
     * user_interface_compression_options.options_by_adding_options(cocoon::UserInterfaceCompressionOptions());
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsuserinterfacecompressionoptions
     */
    class UserInterfaceCompressionOptions : public Object
    {
    public:
        /// @brief Creates a new `NSUserInterfaceCompressionOptions` instance and returns a handle to it.
        explicit UserInterfaceCompressionOptions(const std::vector<UserInterfaceCompressionOptions>& options);
        /// @brief Creates a new `NSUserInterfaceCompressionOptions` instance and returns a handle to it.
        explicit UserInterfaceCompressionOptions(const std::string& identifier);
        /// @brief Creates a new `NSUserInterfaceCompressionOptions` instance and returns a handle to it.
        explicit UserInterfaceCompressionOptions();
        /// @brief Creates a null handle that refers to no native object.
        UserInterfaceCompressionOptions(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit UserInterfaceCompressionOptions(Adopt adopt);
        /**
         * @brief Calls `-[NSUserInterfaceCompressionOptions containsOptions:]`.
         * @details Returns YES if the all the given options are present in the receiver's options.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool contains_options(const UserInterfaceCompressionOptions& options) const;
        /**
         * @brief Calls `-[NSUserInterfaceCompressionOptions intersectsOptions:]`.
         * @details Returns YES if at least one of the given options are present in the receiver's options.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        bool intersects_options(const UserInterfaceCompressionOptions& options) const;
        /**
         * @brief Calls `-[NSUserInterfaceCompressionOptions optionsByAddingOptions:]`.
         * @details Returns a new NSCompressibleUserInterfaceOptions object which is the union of the caller and the provided options.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        UserInterfaceCompressionOptions options_by_adding_options(const UserInterfaceCompressionOptions& options) const;
        /**
         * @brief Calls `-[NSUserInterfaceCompressionOptions optionsByRemovingOptions:]`.
         * @details Returns a new NSCompressibleUserInterfaceOptions object with the given options removed from the receiver's set of options.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        UserInterfaceCompressionOptions options_by_removing_options(const UserInterfaceCompressionOptions& options) const;
        /**
         * @brief Returns the `breakEqualWidthsOption` property of `NSUserInterfaceCompressionOptions`.
         * @details Option specifying views will no longer maintain equal widths. This is handled by the system and no action is required by the views.
         * @return The converted Objective-C result.
         */
        static UserInterfaceCompressionOptions break_equal_widths_option();
        /**
         * @brief Returns the `empty` property of `NSUserInterfaceCompressionOptions`.
         * @details Returns YES if the option is equivalent to the empty set option.
         * @return The converted Objective-C result.
         */
        bool is_empty() const;
        /**
         * @brief Returns the `hideImagesOption` property of `NSUserInterfaceCompressionOptions`.
         * @details Option specifying views should hide their images if applicable.
         * @return The converted Objective-C result.
         */
        static UserInterfaceCompressionOptions hide_images_option();
        /**
         * @brief Returns the `hideTextOption` property of `NSUserInterfaceCompressionOptions`.
         * @details Option specifying views should hide their text if applicable.
         * @return The converted Objective-C result.
         */
        static UserInterfaceCompressionOptions hide_text_option();
        /**
         * @brief Returns the `reduceMetricsOption` property of `NSUserInterfaceCompressionOptions`.
         * @details Option specifying views should reduce their internal metrics when possible to reduce padding around contents.
         * @return The converted Objective-C result.
         */
        static UserInterfaceCompressionOptions reduce_metrics_option();
        /**
         * @brief Returns the `standardOptions` property of `NSUserInterfaceCompressionOptions`.
         * @details Option which is the composite of all standard options provided by AppKit.
         * @return The converted Objective-C result.
         */
        static UserInterfaceCompressionOptions standard_options();
    };
}
