#pragma once

#include <functional>
#include <memory>
#include <type_traits>
#include <utility>
#include "object.h"

namespace cocoon
{
    /// @brief Callback registration point for an event, bound to one native object.
    template <class Sender, class Signature>
    class Signal;

    /**
     * @brief A signal named on one native object; connect a callback to be notified.
     * @details Callbacks are stored on the native object, so they live exactly as long as it does. A callback may take the
     * sender handle as its first argument, or just the signal's own arguments. Capture other handles with WeakRef to avoid
     * retain cycles. Signals are obtained through accessor methods such as `button.clicked()`.
     *
     * @par Example
     * @code
     * cocoon::Button button("Click me");
     * button.clicked().connect([] { });                          // arguments only
     * button.clicked().connect([](cocoon::Button& sender) { });  // with the sender
     * bool wired = button.clicked().is_connected();              // true
     * button.clicked().disconnect();
     * @endcode
     * @tparam Sender Handle type passed to callbacks as the first argument.
     * @tparam R Callback return type (for delegate style queries).
     * @tparam Args Signal argument types.
     */
    template <class Sender, class R, class... Args>
    class Signal<Sender, R(Args...)>
    {
    public:
        /// Type of the stored callback: `std::function<R(Sender&, Args...)>`.
        using Slot = std::function<R(Sender&, Args...)>;

        /// Binds the signal to a native object under a name (normally done by accessor methods).
        Signal(void* native = nullptr, const char* name = "") : native_(native), name_(name)
        {
        }

        template <class F>
        /**
         * Registers `function`, replacing any previous callback.
         * @param function Callable taking `(Sender&, Args...)` or just `(Args...)`.
         */
        void connect(F&& function) const
        {
            if constexpr (std::is_invocable_v<F&, Sender&, Args...>)
            {
                detail::set_slot(native_, name_, std::make_shared<Slot>(std::forward<F>(function)));
            }
            else
            {
                detail::set_slot(native_, name_, std::make_shared<Slot>([function = std::forward<F>(function)](Sender&, Args... args) mutable -> R
                                                                        {
                                                                            return function(std::forward<Args>(args)...);
                                                                        }));
            }
        }

        /// Removes the registered callback.
        void disconnect() const
        {
            detail::set_slot(native_, name_, nullptr);
        }

        /// @return True if a callback is registered.
        bool is_connected() const
        {
            return connected(native_, name_);
        }

        /// Implementation hook: true if a callback is registered on `native` under `name`.
        static bool connected(void* native, const char* name)
        {
            return detail::slot(native, name) != nullptr;
        }

        /// Implementation hook: invokes the registered callback, returning a default value if none.
        static R emit(void* native, const char* name, Args... args)
        {
            std::shared_ptr<void> stored = detail::slot(native, name);
            if (!stored)
            {
                if constexpr (std::is_void_v<R>)
                {
                    return;
                }
                else
                {
                    return R{};
                }
            }
            Sender sender{Adopt{detail::retain_native(native)}};
            return (*static_cast<Slot*>(stored.get()))(sender, std::forward<Args>(args)...);
        }

    private:
        void* native_;
        const char* name_;
    };
}
