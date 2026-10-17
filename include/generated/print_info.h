#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class PDFInfo;
    class Printer;

    /**
     * @brief C++ handle for the Objective-C class `NSPrintInfo` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::PrintInfo print_info;
     * print_info.set_bottom_margin(1);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::PrintInfo print_info{};
     * print_info.set_bottom_margin(1);
     * auto bottom_margin = print_info.bottom_margin();
     * print_info.set_horizontal_pagination(cocoon::PrintingPaginationMode::Automatic);
     * auto horizontal_pagination = print_info.horizontal_pagination();
     * print_info.set_horizontally_centered(true);
     * auto horizontally_centered = print_info.is_horizontally_centered();
     * print_info.pm_page_format();
     * print_info.pm_print_session();
     * print_info.pm_print_settings();
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsprintinfo
     */
    class PrintInfo : public Object
    {
    public:
        /// @brief Creates a new `NSPrintInfo` instance and returns a handle to it.
        explicit PrintInfo(const std::map<std::string, Object>& attributes);
        /// @brief Creates a new `NSPrintInfo` instance and returns a handle to it.
        explicit PrintInfo();
        /// @brief Creates a null handle that refers to no native object.
        PrintInfo(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit PrintInfo(Adopt adopt);
        /**
     * @brief Calls `-[NSPrintInfo PMPageFormat]`.
     * @return The converted Objective-C result.
     */
        void* pm_page_format() const;
        /**
     * @brief Calls `-[NSPrintInfo PMPrintSession]`.
     * @details Return a Printing Manager PMPrintSession, PMPageFormat, or PMPrintSettings object, respectively. The returned object is always consistent with the state of the NSPrintInfo at the moment the method is invoked, but isn't necessarily updated immediately if other NSPrintInfo methods like -setPaperSize: and -setPaperOrientation: are invoked. The returned object will always be valid (in the Printing Manager sense). If you set any values in the returned PMPageFormat or PMPrintSettings you should afterward invoke -updateFromPMPageFormat or -updateFromPMPrintSettings, respectively. You don't also have to call PMSessionValidatePageFormat() or PMSessionValidatePrintSettings() if you do that. You should not call PMRelease() for the returned object, except of course to balance any calls of PMRetain() you do.
     * @return The converted Objective-C result.
     */
        void* pm_print_session() const;
        /**
     * @brief Calls `-[NSPrintInfo PMPrintSettings]`.
     * @return The converted Objective-C result.
     */
        void* pm_print_settings() const;
        /**
     * @brief Calls `-[NSPrintInfo dictionary]`.
     * @details Return a dictionary that contains attribute entries. This dictionary may contain attributes that were not specified in the dictionary originally passed to this object by -initWithDictionary. Changes to this dictionary will be reflected in the values returned by subsequent invocations of other of this class' methods.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> dictionary() const;
        /**
     * @brief Calls `-[NSPrintInfo setUpPrintOperationDefaultValues]`.
     * @details Validate all of the attributes encapsulated by this object. This method is invoked automatically before the object is used by an NSPrintOperation. This method may be overridden to perform validation of attributes that are not recognized by the NSPrintInfo class.
     */
        void set_up_print_operation_default_values() const;
        /**
     * @brief Calls `-[NSPrintInfo takeSettingsFromPDFInfo:]`.
     * @details Update the receiver with all settings and attributes present in the given NSPDFInfo. Entries in the given NSPDFInfo's attributes dictionary will be copied into the receiver's attributes dictionary ([self dictionary]). If inPDFInfo is the result of an NSPDFPanel with the NSPDFPanelRequestsParentDirectory option enabled, you must first modify inPDFInfo.URL by appending a file name. If inPDFInfo.URL points to a directory, this method will throw an exception.
     * @param in_pdf_info Argument converted to the Objective-C parameter of the same role.
     */
        void take_settings_from_pdf_info(const PDFInfo& in_pdf_info) const;
        /**
     * @brief Calls `-[NSPrintInfo updateFromPMPageFormat]`.
     * @details Given that the NSPrintInfo's PMPageFormat or PMPrintSettings has been changed by something other than the NSPrintInfo itself, update the NSPrintInfo to be consistent.
     */
        void update_from_pm_page_format() const;
        /**
     * @brief Calls `-[NSPrintInfo updateFromPMPrintSettings]`.
     */
        void update_from_pm_print_settings() const;
        /**
     * @brief Returns the `bottomMargin` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        double bottom_margin() const;
        /**
     * @brief Sets the `bottomMargin` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_bottom_margin(double value) const;
        /**
     * @brief Returns the `defaultPrinter` property of `NSPrintInfo`.
     * @details Return the default printer, if one has been selected by the user, nil otherwise.
     * @return The converted Objective-C result.
     */
        static Printer default_printer();
        /**
     * @brief Returns the `horizontalPagination` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        PrintingPaginationMode horizontal_pagination() const;
        /**
     * @brief Sets the `horizontalPagination` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_horizontal_pagination(PrintingPaginationMode value) const;
        /**
     * @brief Returns the `horizontallyCentered` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        bool is_horizontally_centered() const;
        /**
     * @brief Sets the `horizontallyCentered` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_horizontally_centered(bool value) const;
        /**
     * @brief Returns the `imageablePageBounds` property of `NSPrintInfo`.
     * @details Return the imageable area of a page specified by this object, taking into account the current printer, paper, and orientation settings, but not scaling. "Imageable area" is the maximum area that can possibly be marked on by the printer hardware, not the area defined by the current margin settings. The rectangle is in a coordinate space measured by points, with (0, 0) being the lower-left corner of the oriented page and (paperWidth, paperHeight) being the upper-right corner of the oriented page. The imageable bounds may extend past the edges of the page when, for example, a printer driver specifies it so that borderless printing can be done reliably.
     * @return The converted Objective-C result.
     */
        Rect imageable_page_bounds() const;
        /**
     * @brief Returns the `jobDisposition` property of `NSPrintInfo`.
     * @details Set or get the value of the job disposition attribute.
     * @return The converted Objective-C result.
     */
        std::string job_disposition() const;
        /**
     * @brief Sets the `jobDisposition` property of `NSPrintInfo`.
     * @details Set or get the value of the job disposition attribute.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_job_disposition(const std::string& value) const;
        /**
     * @brief Returns the `leftMargin` property of `NSPrintInfo`.
     * @details Set or get the values of the pagination attributes.
     * @return The converted Objective-C result.
     */
        double left_margin() const;
        /**
     * @brief Sets the `leftMargin` property of `NSPrintInfo`.
     * @details Set or get the values of the pagination attributes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_left_margin(double value) const;
        /**
     * @brief Returns the `localizedPaperName` property of `NSPrintInfo`.
     * @details Return the human-readable name of the currently selected paper size, suitable for presentation in user interfaces. This will typically be different from the name returned by -paperName, which is almost never suitable for presentation to to the user.
     * @return The converted Objective-C result.
     */
        std::string localized_paper_name() const;
        /**
     * @brief Returns the `orientation` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        PaperOrientation orientation() const;
        /**
     * @brief Sets the `orientation` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_orientation(PaperOrientation value) const;
        /**
     * @brief Returns the `paperName` property of `NSPrintInfo`.
     * @details Set or get the values of the paper attributes. Because an NSPrintInfo's paper name, paper size, and orientation attributes must be kept consistent, invocation of any of the setting methods in this group may affect the values returned by subsequent invocations of any of the getting methods in this group. For example, paper name and paper size must always agree, and the value returned by -paperSize always takes orientation into account.
     * @return The converted Objective-C result.
     */
        std::string paper_name() const;
        /**
     * @brief Sets the `paperName` property of `NSPrintInfo`.
     * @details Set or get the values of the paper attributes. Because an NSPrintInfo's paper name, paper size, and orientation attributes must be kept consistent, invocation of any of the setting methods in this group may affect the values returned by subsequent invocations of any of the getting methods in this group. For example, paper name and paper size must always agree, and the value returned by -paperSize always takes orientation into account.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paper_name(const std::string& value) const;
        /**
     * @brief Returns the `paperSize` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        Size paper_size() const;
        /**
     * @brief Sets the `paperSize` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_paper_size(const Size& value) const;
        /**
     * @brief Returns the `printSettings` property of `NSPrintInfo`.
     * @details The print info's print settings. You can put values in this dictionary to store them in any preset that the user creates while editing this print info with a print panel. Such values must be property list objects. This class is key-value coding (KVC) and key-value observing (KVO) compliant for "printSettings" so you can often bind controls in print panel accessory views directly to entries in this dictionary. You can also use this dictionary to get values that have been set by other parts of the printing system, like a printer driver's print dialog extension (the same sort of values that are returned by the Carbon Printing Manager's PMPrintSettingsGetValue() function). Other parts of the printing system often use key strings like "com.apple.print.PrintSettings.PMColorSyncProfileID" but dots like those in key strings wouldn't work well with KVC, so those dots are replaced with underscores in keys that appear in this dictionary, as in "com_apple_print_PrintSettings_PMColorSyncProfileID". You should use the same convention when adding entries to this dictionary.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> print_settings() const;
        /**
     * @brief Returns the `printer` property of `NSPrintInfo`.
     * @details Set or get the destination printer specified by this object.
     * @return The converted Objective-C result.
     */
        Printer printer() const;
        /**
     * @brief Sets the `printer` property of `NSPrintInfo`.
     * @details Set or get the destination printer specified by this object.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_printer(const Printer& value) const;
        /**
     * @brief Returns the `rightMargin` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        double right_margin() const;
        /**
     * @brief Sets the `rightMargin` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_right_margin(double value) const;
        /**
     * @brief Returns the `scalingFactor` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        double scaling_factor() const;
        /**
     * @brief Sets the `scalingFactor` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_scaling_factor(double value) const;
        /**
     * @brief Returns the `selectionOnly` property of `NSPrintInfo`.
     * @details Set or get whether only the selected content should be printed.
     * @return The converted Objective-C result.
     */
        bool is_selection_only() const;
        /**
     * @brief Sets the `selectionOnly` property of `NSPrintInfo`.
     * @details Set or get whether only the selected content should be printed.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_selection_only(bool value) const;
        /**
     * @brief Returns the `sharedPrintInfo` property of `NSPrintInfo`.
     * @details Set or get the "shared" instance of NSPrintInfo. The shared print info object is the one that is used automatically by -[NSPageLayout runModal] and +[NSPrintOperation printOperationWithView:].
     * @return The converted Objective-C result.
     */
        static PrintInfo shared_print_info();
        /**
     * @brief Sets the `sharedPrintInfo` property of `NSPrintInfo`.
     * @details Set or get the "shared" instance of NSPrintInfo. The shared print info object is the one that is used automatically by -[NSPageLayout runModal] and +[NSPrintOperation printOperationWithView:].
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_shared_print_info(const PrintInfo& value);
        /**
     * @brief Returns the `topMargin` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        double top_margin() const;
        /**
     * @brief Sets the `topMargin` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_top_margin(double value) const;
        /**
     * @brief Returns the `verticalPagination` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        PrintingPaginationMode vertical_pagination() const;
        /**
     * @brief Sets the `verticalPagination` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_vertical_pagination(PrintingPaginationMode value) const;
        /**
     * @brief Returns the `verticallyCentered` property of `NSPrintInfo`.
     * @return The converted Objective-C result.
     */
        bool is_vertically_centered() const;
        /**
     * @brief Sets the `verticallyCentered` property of `NSPrintInfo`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_vertically_centered(bool value) const;
    };
}
