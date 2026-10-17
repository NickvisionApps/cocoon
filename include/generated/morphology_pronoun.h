#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Morphology;

    /**
     * @brief C++ handle for the Objective-C class `NSMorphologyPronoun` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::MorphologyPronoun morphology_pronoun{"text", cocoon::Morphology(), cocoon::Morphology()};
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsmorphologypronoun
     */
    class MorphologyPronoun : public Object
    {
    public:
        /// @brief Creates a new `NSMorphologyPronoun` instance and returns a handle to it.
        explicit MorphologyPronoun(const std::string& pronoun, const Morphology& morphology, const Morphology& dependent_morphology);
        MorphologyPronoun();
        /// @brief Creates a null handle that refers to no native object.
        MorphologyPronoun(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit MorphologyPronoun(Adopt adopt);
        /**
     * @brief Returns the `dependentMorphology` property of `NSMorphologyPronoun`.
     * @return The converted Objective-C result.
     */
        Morphology dependent_morphology() const;
        /**
     * @brief Returns the `morphology` property of `NSMorphologyPronoun`.
     * @return The converted Objective-C result.
     */
        Morphology morphology() const;
        /**
     * @brief Returns the `pronoun` property of `NSMorphologyPronoun`.
     * @return The converted Objective-C result.
     */
        std::string pronoun() const;
    };
}
