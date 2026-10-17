#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSPDFInfo` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PDFInfo pdf_info;
     * pdf_info.set_url(cocoon::URL());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PDFInfo pdf_info{};
     * pdf_info.set_url(cocoon::URL());
     * auto url = pdf_info.url();
     * pdf_info.set_file_extension_hidden(true);
     * auto file_extension_hidden = pdf_info.is_file_extension_hidden();
     * pdf_info.set_orientation(cocoon::PaperOrientation::Portrait);
     * auto orientation = pdf_info.orientation();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nspdfinfo
     */
    class PDFInfo : public Object
    {
    public:
        /// @brief Creates a new `NSPDFInfo` instance and returns a handle to it.
        explicit PDFInfo();
        /// @brief Creates a null handle that refers to no native object.
        PDFInfo(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PDFInfo(Adopt adopt);
        /**
     * @brief Returns the `URL` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        URL url() const;
        /**
     * @brief Sets the `URL` property of `NSPDFInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_url(const URL& value) const;
        /**
     * @brief Returns the `attributes` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> attributes() const;
        /**
     * @brief Returns the `fileExtensionHidden` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        bool is_file_extension_hidden() const;
        /**
     * @brief Sets the `fileExtensionHidden` property of `NSPDFInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_file_extension_hidden(bool value) const;
        /**
     * @brief Returns the `orientation` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        PaperOrientation orientation() const;
        /**
     * @brief Sets the `orientation` property of `NSPDFInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_orientation(PaperOrientation value) const;
        /**
     * @brief Returns the `paperSize` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        Size paper_size() const;
        /**
     * @brief Sets the `paperSize` property of `NSPDFInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paper_size(const Size& value) const;
        /**
     * @brief Returns the `tagNames` property of `NSPDFInfo`.
     * @return The converted Objective-C result.
     */
        std::vector<std::string> tag_names() const;
        /**
     * @brief Sets the `tagNames` property of `NSPDFInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_tag_names(const std::vector<std::string>& value) const;
    };
}
