#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSUnarchiver` (Foundation).
     * @details Archiving: Reading
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Unarchiver unarchiver;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Unarchiver unarchiver{};
     * unarchiver.class_name_decoded_for_archive_class_name("text");
     * unarchiver.decode_class_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsunarchiver
     */
    class Unarchiver : public Coder
    {
    public:
        /// @brief Creates a new `NSUnarchiver` instance and returns a handle to it.
        explicit Unarchiver(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSUnarchiver` instance and returns a handle to it.
        explicit Unarchiver();
        /// @brief Creates a null handle that refers to no native object.
        Unarchiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Unarchiver(Adopt adopt);
        using Coder::system_version;
        /**
         * @brief Calls `-[NSUnarchiver classNameDecodedForArchiveClassName:]`.
         * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string class_name_decoded_for_archive_class_name(const std::string& in_archive_name) const;
        /**
         * @brief Calls `-[NSUnarchiver decodeClassName:asClassName:]`.
         * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
         * @param true_name Argument converted to the Objective-C parameter of the same role.
         */
        void decode_class_name(const std::string& in_archive_name, const std::string& true_name) const;
        /**
         * @brief Calls `-[NSUnarchiver replaceObject:withObject:]`.
         * @param object Argument converted to the Objective-C parameter of the same role.
         * @param new_object Argument converted to the Objective-C parameter of the same role.
         */
        void replace_object(const Object& object, const Object& new_object) const;
        /**
         * @brief Calls `+[NSUnarchiver unarchiveObjectWithData:]`.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object unarchive_object_with_data(const std::vector<std::uint8_t>& data);
        /**
         * @brief Calls `+[NSUnarchiver unarchiveObjectWithFile:]`.
         * @param path Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object unarchive_object_with_file(const std::string& path);
        /**
         * @brief Returns the `atEnd` property of `NSUnarchiver`.
         * @return The converted Objective-C result.
         */
        bool is_at_end() const;
        /**
         * @brief Returns the `systemVersion` property of `NSUnarchiver`.
         * @return The converted Objective-C result.
         */
        unsigned int system_version() const;
    };
}
