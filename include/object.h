#pragma once

#include <cstddef>
#include <memory>
#include <utility>

namespace cocoon
{
    /**
     * @brief Tag that hands ownership of one retained native pointer to a handle.
     * @details Used by `explicit Handle(Adopt)` constructors and by Object::as. Application code rarely needs it.
     */
    struct Adopt
    {
        void* native;
    };

    /// @internal Low level reference counting and signal slot storage shared by handles and signals.
    namespace detail
    {
        /// Adds a retain to the native object and returns it.
        void* retain_native(void* native);
        /// Releases one retain of the native object.
        void release_native(void* native);
        /// Stores (or, when null, removes) the callback registered under `name` on the native object.
        void set_slot(void* native, const char* name, std::shared_ptr<void> slot);
        /// Looks up the callback registered under `name`, or null.
        std::shared_ptr<void> slot(void* native, const char* name);
    }

    /**
     * @brief Root of every wrapper class: a cheap, copyable handle to a retained Objective-C object.
     * @details Copying a handle retains the native object and destroying it releases it, so lifetime follows AppKit's
     * reference counting. Two handles compare equal when they refer to the same native object. Moved-from handles are null.
     * Use Object::as to reinterpret a handle as a more specific class.
     *
     * @par Example
     * @code
     * cocoon::Button button("OK");
     * cocoon::View view = button;                  // shares the same NSButton
     * cocoon::Button again = view.as<cocoon::Button>();
     * bool same = (again == button);                // true
     * cocoon::Button none(nullptr);                 // null handle
     * bool empty = none.is_null();                  // true
     * @endcode
     */
    class Object
    {
    public:
        /// Creates a null handle.
        Object() = default;
        /// Creates a null handle.
        Object(std::nullptr_t)
        {
        }
        /// Takes ownership of an already retained native pointer.
        explicit Object(Adopt adopt) : native_(adopt.native)
        {
        }
        /// Copies the handle, retaining the native object.
        Object(const Object& other) : native_(other.native_ ? detail::retain_native(other.native_) : nullptr)
        {
        }
        /// Moves the handle; `other` becomes null.
        Object(Object&& other) noexcept : native_(std::exchange(other.native_, nullptr))
        {
        }

        /// Copy-assigns, retaining the new native object and releasing the old one.
        Object& operator=(const Object& other)
        {
            if (this != &other)
            {
                Object copy(other);
                std::swap(native_, copy.native_);
            }
            return *this;
        }

        /// Move-assigns.
        Object& operator=(Object&& other) noexcept
        {
            std::swap(native_, other.native_);
            return *this;
        }

        /// Releases the native object.
        ~Object()
        {
            if (native_)
            {
                detail::release_native(native_);
            }
        }

        /// @return The retained native pointer (an `id` in Objective-C terms), or null.
        void* handle() const
        {
            return native_;
        }
        /// @return True if the handle refers to no native object.
        bool is_null() const
        {
            return native_ == nullptr;
        }
        /// @return True if the handle is not null.
        explicit operator bool() const
        {
            return native_ != nullptr;
        }
        /// @return True if both handles refer to the same native object.
        bool operator==(const Object& other) const
        {
            return native_ == other.native_;
        }
        /// @return True if the handles refer to different native objects.
        bool operator!=(const Object& other) const
        {
            return native_ != other.native_;
        }

        template <class T>
        /**
         * Reinterprets the native object as handle type `T` (no runtime type check).
         * @tparam T Target handle class.
         */
        T as() const
        {
            return T(Adopt{native_ ? detail::retain_native(native_) : nullptr});
        }

    private:
        void* native_ = nullptr;
    };
}
