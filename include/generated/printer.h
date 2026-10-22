#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSPrinter` (AppKit).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::Printer printer;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::Printer printer{};
     * printer.page_size_for_paper("text");
     * @endcode
     * @see https://developer.apple.com/documentation/appkit/nsprinter
     */
    class Printer : public Object
    {
    public:
        /// @brief Creates a new `NSPrinter` instance and returns a handle to it.
        explicit Printer(const std::string& name);
        /// @brief Creates a new `NSPrinter` instance and returns a handle to it.
        explicit Printer();
        /// @brief Creates a null handle that refers to no native object.
        Printer(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit Printer(Adopt adopt);
        /**
     * @brief Calls `-[NSPrinter pageSizeForPaper:]`.
     * @details Given a valid paper name, return the corresponding paper size in points, or NSZeroSize for failure.
     * @param paper_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Size page_size_for_paper(const std::string& paper_name) const;
        /**
     * @brief Returns the `deviceDescription` property of `NSPrinter`.
     * @details Return a dictionary that describes the printing device using entries keyed by the NSDevice... strings declared in NSGraphics.h. The only entry that is guaranteed to exist in the returned dictionary is NSDeviceIsPrinter.
     * @return The converted Objective-C result.
     */
        std::map<std::string, Object> device_description() const;
        /**
     * @brief Returns the `languageLevel` property of `NSPrinter`.
     * @details Return the PostScript language level of the printer if it is a PostScript printer, or 0 if it is not a PostScript printer or for failure.
     * @return The converted Objective-C result.
     */
        std::int64_t language_level() const;
        /**
     * @brief Returns the `name` property of `NSPrinter`.
     * @details Return the printer's human-readable name, or an empty string for failure.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `printerNames` property of `NSPrinter`.
     * @details Return an array of strings that contain the human-readable names of all available printers.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> printer_names();
        /**
     * @brief Returns the `printerTypes` property of `NSPrinter`.
     * @details Return an array of strings that contain the human-readable descriptions of the makes and models of all available printers. The array may contain fewer entries than the array that would be returned by an invocation of +printerNames.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> printer_types();
        /**
     * @brief Returns the `type` property of `NSPrinter`.
     * @details Return a human-readable description of the printer's make and model, or an empty string for failure.
     * @return The converted Objective-C result.
     */
        std::string type() const;
    };
}
