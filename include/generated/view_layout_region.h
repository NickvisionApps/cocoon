#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSViewLayoutRegion` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::ViewLayoutRegion view_layout_region(nullptr);  // null handle; instances normally come from other API calls
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::ViewLayoutRegion view_layout_region(nullptr);
     * auto made_0 = cocoon::ViewLayoutRegion::margins_layout_region_with_corner_adaptation(cocoon::ViewLayoutRegionAdaptivityAxis::None);
     * auto made_1 = cocoon::ViewLayoutRegion::safe_area_layout_region_with_corner_adaptation(cocoon::ViewLayoutRegionAdaptivityAxis::None);
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsviewlayoutregion
     */
    class ViewLayoutRegion : public Object
    {
    public:
        ViewLayoutRegion();
        /// @brief Creates a null handle that refers to no native object.
        ViewLayoutRegion(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit ViewLayoutRegion(Adopt adopt);
        /**
         * @brief Calls `+[NSViewLayoutRegion marginsLayoutRegionWithCornerAdaptation:]`.
         * @param adaptivity_axis Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ViewLayoutRegion margins_layout_region_with_corner_adaptation(ViewLayoutRegionAdaptivityAxis adaptivity_axis);
        /**
         * @brief Calls `+[NSViewLayoutRegion safeAreaLayoutRegionWithCornerAdaptation:]`.
         * @param adaptivity_axis Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static ViewLayoutRegion safe_area_layout_region_with_corner_adaptation(ViewLayoutRegionAdaptivityAxis adaptivity_axis);
    };
}
