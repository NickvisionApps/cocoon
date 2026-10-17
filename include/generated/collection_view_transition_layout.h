#pragma once

#include "generated/availability.h"
#include "generated/collection_view_layout.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CollectionViewLayout;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewTransitionLayout` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionViewLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewTransitionLayout collection_view_transition_layout;
     * collection_view_transition_layout.set_transition_progress(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewTransitionLayout collection_view_transition_layout{};
     * collection_view_transition_layout.set_transition_progress(1);
     * auto transition_progress = collection_view_transition_layout.transition_progress();
     * collection_view_transition_layout.update_value(1, "text");
     * collection_view_transition_layout.value_for_animated_key("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewtransitionlayout
     */
    class CollectionViewTransitionLayout : public CollectionViewLayout
    {
    public:
        /// @brief Creates a new `NSCollectionViewTransitionLayout` instance and returns a handle to it.
        explicit CollectionViewTransitionLayout(const CollectionViewLayout& current_layout, const CollectionViewLayout& new_layout);
        /// @brief Creates a new `NSCollectionViewTransitionLayout` instance and returns a handle to it.
        explicit CollectionViewTransitionLayout();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewTransitionLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewTransitionLayout(Adopt adopt);
        /**
     * @brief Calls `-[NSCollectionViewTransitionLayout updateValue:forAnimatedKey:]`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     * @param key Argument converted to the Objective-C parameter of the same role.
     */
        void update_value(double value, const std::string& key) const;
        /**
     * @brief Calls `-[NSCollectionViewTransitionLayout valueForAnimatedKey:]`.
     * @param key Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double value_for_animated_key(const std::string& key) const;
        /**
     * @brief Returns the `currentLayout` property of `NSCollectionViewTransitionLayout`.
     * @return The converted Objective-C result.
     */
        CollectionViewLayout current_layout() const;
        /**
     * @brief Returns the `nextLayout` property of `NSCollectionViewTransitionLayout`.
     * @return The converted Objective-C result.
     */
        CollectionViewLayout next_layout() const;
        /**
     * @brief Returns the `transitionProgress` property of `NSCollectionViewTransitionLayout`.
     * @return The converted Objective-C result.
     */
        double transition_progress() const;
        /**
     * @brief Sets the `transitionProgress` property of `NSCollectionViewTransitionLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_transition_progress(double value) const;
    };
}
