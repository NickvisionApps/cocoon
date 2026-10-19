#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/regular_expression.h"
#include "generated/structs.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSDataDetector` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref RegularExpression.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::DataDetector data_detector;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::DataDetector data_detector{};
     * auto made_0 = cocoon::DataDetector::data_detector_with_types(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsdatadetector
     */
    class DataDetector : public RegularExpression
    {
    public:
        /// @brief Creates a new `NSDataDetector` instance and returns a handle to it.
        explicit DataDetector(std::uint64_t checking_types);
        /// @brief Creates a new `NSDataDetector` instance and returns a handle to it.
        explicit DataDetector();
        /// @brief Creates a null handle that refers to no native object.
        DataDetector(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit DataDetector(Adopt adopt);
        /**
     * @brief Calls `+[NSDataDetector dataDetectorWithTypes:error:]`.
     * @details NSDataDetector is a specialized subclass of NSRegularExpression. Instead of finding matches to regular expression patterns, it matches items identified by Data Detectors, such as dates, addresses, and URLs. The checkingTypes argument should contain one or more of the types NSTextCheckingTypeDate, NSTextCheckingTypeAddress, NSTextCheckingTypeLink, NSTextCheckingTypePhoneNumber, and NSTextCheckingTypeTransitInformation. The NSTextCheckingResult instances returned will be of the appropriate types from that list.
     * @param checking_types Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DataDetector data_detector_with_types(std::uint64_t checking_types);
        /**
     * @brief Returns the `checkingTypes` property of `NSDataDetector`.
     * @return The converted Objective-C result.
     */
        std::uint64_t checking_types() const;
    };
}
