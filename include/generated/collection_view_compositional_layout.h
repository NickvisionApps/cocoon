#pragma once

#include "generated/availability.h"
#include "generated/collection_view_layout.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    class CollectionLayoutSection;
    class CollectionViewCompositionalLayoutConfiguration;

    /**
     * @brief C++ handle for the Objective-C class `NSCollectionViewCompositionalLayout` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref CollectionViewLayout.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::CollectionViewCompositionalLayout collection_view_compositional_layout{cocoon::CollectionLayoutSection()};
     * collection_view_compositional_layout.set_configuration(cocoon::CollectionViewCompositionalLayoutConfiguration());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::CollectionViewCompositionalLayout collection_view_compositional_layout{cocoon::CollectionLayoutSection()};
     * collection_view_compositional_layout.set_configuration(cocoon::CollectionViewCompositionalLayoutConfiguration());
     * auto configuration = collection_view_compositional_layout.configuration();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nscollectionviewcompositionallayout
     */
    class CollectionViewCompositionalLayout : public CollectionViewLayout
    {
    public:
        /// @brief Creates a new `NSCollectionViewCompositionalLayout` instance and returns a handle to it.
        explicit CollectionViewCompositionalLayout(const CollectionLayoutSection& section);
        /// @brief Creates a new `NSCollectionViewCompositionalLayout` instance and returns a handle to it.
        explicit CollectionViewCompositionalLayout(const CollectionLayoutSection& section, const CollectionViewCompositionalLayoutConfiguration& configuration);
        /// @brief Creates a new `NSCollectionViewCompositionalLayout` instance and returns a handle to it.
        explicit CollectionViewCompositionalLayout(std::function<CollectionLayoutSection(std::int64_t, Object)> section_provider);
        /// @brief Creates a new `NSCollectionViewCompositionalLayout` instance and returns a handle to it.
        explicit CollectionViewCompositionalLayout(std::function<CollectionLayoutSection(std::int64_t, Object)> section_provider, const CollectionViewCompositionalLayoutConfiguration& configuration);
        CollectionViewCompositionalLayout();
        /// @brief Creates a null handle that refers to no native object.
        CollectionViewCompositionalLayout(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit CollectionViewCompositionalLayout(Adopt adopt);
        /**
     * @brief Returns the `configuration` property of `NSCollectionViewCompositionalLayout`.
     * @return The converted Objective-C result.
     */
        CollectionViewCompositionalLayoutConfiguration configuration() const;
        /**
     * @brief Sets the `configuration` property of `NSCollectionViewCompositionalLayout`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_configuration(const CollectionViewCompositionalLayoutConfiguration& value) const;
    };
}
