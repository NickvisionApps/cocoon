#pragma once

#include "object.h"

namespace cocoon
{
    /// @internal Zeroing weak reference support.
    namespace detail
    {
        /// Creates a boxed weak reference to the native object.
        void* make_weak(void* native);
        /// Returns a retained strong reference, or null if the object is gone.
        void* lock_weak(void* weak);
    }

    /**
     * @brief A non-owning reference to a handle's native object that becomes null when the object dies.
     * @details Use it inside callbacks to capture a control without creating a retain cycle.
     *
     * @par Example
     * @code
     * cocoon::Label status("Ready");
     * cocoon::WeakRef<cocoon::Label> weak(status);
     * cocoon::Button button("Go");
     * button.clicked().connect([weak] {
     *     cocoon::Label label = weak.lock();
     *     if (label)
     *         label.set_string_value("Done");
     * });
     * @endcode
     * @tparam T Handle class being referenced.
     */
    template <class T>
    class WeakRef
    {
    public:
        WeakRef() = default;
        /// Creates a weak reference to `object`.
        WeakRef(const T& object) : weak_(object.is_null() ? nullptr : detail::make_weak(object.handle()))
        {
        }
        WeakRef(const WeakRef& other) : weak_(other.weak_ ? detail::retain_native(other.weak_) : nullptr)
        {
        }
        WeakRef(WeakRef&& other) noexcept : weak_(std::exchange(other.weak_, nullptr))
        {
        }

        WeakRef& operator=(WeakRef other) noexcept
        {
            std::swap(weak_, other.weak_);
            return *this;
        }

        ~WeakRef()
        {
            if (weak_)
            {
                detail::release_native(weak_);
            }
        }

        /// @return A strong handle, or a null handle if the object was deallocated.
        T lock() const
        {
            return T(Adopt{weak_ ? detail::lock_weak(weak_) : nullptr});
        }

    private:
        void* weak_ = nullptr;
    };
}
