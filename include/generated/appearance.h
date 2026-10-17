#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Bundle;

    /**
     * @brief C++ handle for the Objective-C class `NSAppearance` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Appearance appearance;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Appearance appearance{};
     * auto made_0 = cocoon::Appearance::appearance_named("text");
     * appearance.best_match_from_appearances_with_names({"a", "b"});
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsappearance
     */
    class Appearance : public Object
    {
    public:
        /// @brief Creates a new `NSAppearance` instance and returns a handle to it.
        explicit Appearance(const std::string& name, const Bundle& bundle);
        /// @brief Creates a new `NSAppearance` instance and returns a handle to it.
        explicit Appearance();
        /// @brief Creates a null handle that refers to no native object.
        Appearance(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Appearance(Adopt adopt);
        /**
     * @brief Calls `+[NSAppearance appearanceNamed:]`.
     * @details Finds and returns an NSAppearance based on the name. For standard appearances such as NSAppearanceNameAqua, a built-in appearance is returned. For other names, the main bundle is searched.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Appearance appearance_named(const std::string& name);
        /**
     * @brief Calls `-[NSAppearance bestMatchFromAppearancesWithNames:]`.
     * @details Given a list of appearance names, returns the one that best matches the receiver
     * @param appearances Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string best_match_from_appearances_with_names(const std::vector<std::string>& appearances) const;
        /**
     * @brief Calls `-[NSAppearance performAsCurrentDrawingAppearance:]`.
     * @param block Argument converted to the Objective-C parameter of the same role.
     */
        void perform_as_current_drawing_appearance(std::function<void()> block) const;
        /**
     * @brief Returns the `allowsVibrancy` property of `NSAppearance`.
     * @details Query allowsVibrancy to see if the given appearance actually needs vibrant drawing. You may want to draw differently if the current apperance is vibrant.
     * @return The converted Objective-C result.
     */
        bool allows_vibrancy() const;
        /**
     * @brief Returns the `currentDrawingAppearance` property of `NSAppearance`.
     * @return The converted Objective-C result.
     */
        static Appearance current_drawing_appearance();
        /**
     * @brief Returns the `name` property of `NSAppearance`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
    };
}
