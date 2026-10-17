#pragma once

#include <stdexcept>

namespace cocoon
{
    /**
     * @brief Thrown when an Objective-C method reports failure through an `NSError**` out parameter.
     * @par Example
     * @code
     * try {
     *     cocoon::OpenPanel panel = cocoon::OpenPanel::open_panel();
     *     panel.run_modal();   // methods with an NSError** parameter throw on failure
     * } catch (const cocoon::NativeError& error) {
     *     std::string message = error.what();
     * }
     * @endcode
     */
    class NativeError : public std::runtime_error
    {
    public:
        using std::runtime_error::runtime_error;
    };
}
