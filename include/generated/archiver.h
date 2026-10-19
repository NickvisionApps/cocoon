#pragma once

#include "generated/availability.h"
#include "generated/coder.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSArchiver` (Foundation).
     * @details Archiving: Writing
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref Coder.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Archiver archiver;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Archiver archiver{};
     * archiver.class_name_encoded_for_true_class_name("text");
     * archiver.encode_class_name("text", "text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsarchiver
     */
    class Archiver : public Coder
    {
    public:
        /// @brief Creates a new `NSArchiver` instance and returns a handle to it.
        explicit Archiver(const std::vector<std::uint8_t>& mdata);
        /// @brief Creates a new `NSArchiver` instance and returns a handle to it.
        explicit Archiver();
        /// @brief Creates a null handle that refers to no native object.
        Archiver(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Archiver(Adopt adopt);
        using Coder::encode_conditional_object;
        using Coder::encode_root_object;
        /**
     * @brief Calls `+[NSArchiver archiveRootObject:toFile:]`.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @param path Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static bool archive_root_object(const Object& root_object, const std::string& path);
        /**
     * @brief Calls `+[NSArchiver archivedDataWithRootObject:]`.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::vector<std::uint8_t> archived_data_with_root_object(const Object& root_object);
        /**
     * @brief Calls `-[NSArchiver classNameEncodedForTrueClassName:]`.
     * @param true_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string class_name_encoded_for_true_class_name(const std::string& true_name) const;
        /**
     * @brief Calls `-[NSArchiver encodeClassName:intoClassName:]`.
     * @param true_name Argument converted to the Objective-C parameter of the same role.
     * @param in_archive_name Argument converted to the Objective-C parameter of the same role.
     */
        void encode_class_name(const std::string& true_name, const std::string& in_archive_name) const;
        /**
     * @brief Calls `-[NSArchiver encodeConditionalObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     */
        void encode_conditional_object(const Object& object) const;
        /**
     * @brief Calls `-[NSArchiver encodeRootObject:]`.
     * @param root_object Argument converted to the Objective-C parameter of the same role.
     */
        void encode_root_object(const Object& root_object) const;
        /**
     * @brief Calls `-[NSArchiver replaceObject:withObject:]`.
     * @param object Argument converted to the Objective-C parameter of the same role.
     * @param new_object Argument converted to the Objective-C parameter of the same role.
     */
        void replace_object(const Object& object, const Object& new_object) const;
        /**
     * @brief Returns the `archiverData` property of `NSArchiver`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> archiver_data() const;
    };
}
