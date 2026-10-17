#pragma once

namespace cocoon
{
    /**
     * @brief Standard menu actions that route through the responder chain.
     * @par Example
     * @code
     * cocoon::Menu edit("Edit");
     * edit.add_standard_item(cocoon::StandardAction::Copy);
     * edit.add_standard_item(cocoon::StandardAction::Paste);
     * @endcode
     */
    enum class StandardAction
    {
        /// Show the About panel.
        About,
        /// Hide the application.
        Hide,
        /// Hide all other applications.
        HideOthers,
        /// Unhide all applications.
        ShowAll,
        /// Quit the application.
        Quit,
        /// Undo.
        Undo,
        /// Redo.
        Redo,
        /// Cut.
        Cut,
        /// Copy.
        Copy,
        /// Paste.
        Paste,
        /// Select all.
        SelectAll,
        /// Close the window.
        Close,
        /// Minimize the window.
        Minimize,
        /// Zoom the window.
        Zoom,
        /// Toggle full screen.
        ToggleFullScreen,
        /// Bring all windows to the front.
        BringAllToFront,
        /// Toggle the sidebar of a split view.
        ToggleSidebar,
        /// Show the Help menu.
        ShowHelp,
    };
}
