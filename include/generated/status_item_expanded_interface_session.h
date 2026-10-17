#pragma once

#include "generated/availability.h"

#ifdef COCOON_MACOS_27
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSStatusItemExpandedInterfaceSession` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::StatusItemExpandedInterfaceSession status_item_expanded_interface_session;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::StatusItemExpandedInterfaceSession status_item_expanded_interface_session{};
     * status_item_expanded_interface_session.cancel();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsstatusitemexpandedinterfacesession
     */
    class StatusItemExpandedInterfaceSession : public Object
    {
    public:
        /// @brief Creates a new `NSStatusItemExpandedInterfaceSession` instance and returns a handle to it.
        explicit StatusItemExpandedInterfaceSession();
        /// @brief Creates a null handle that refers to no native object.
        StatusItemExpandedInterfaceSession(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit StatusItemExpandedInterfaceSession(Adopt adopt);
#ifdef COCOON_MACOS_27
        /**
     * @brief Calls `-[NSStatusItemExpandedInterfaceSession cancel]`.
     * @details Cancels tracking of the expanded interface state in the menu bar system. NSStatusItemExpandedInterfaceDelegate will receive -statusItemDidEndExpandedInterfaceSession:animated: after cancellation.
     */
        void cancel() const;
#endif
    };
}

#endif
