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
     * @details A specialized regular expression object that matches natural language text for predefined data patterns. Find dates, addresses, links, phone numbers, and transit information in natural language text with 'NSDataDetector'. 'NSDataDetector' returns the results of matching content in ''NSTextCheckingResult'' objects. The ''NSTextCheckingResult'' objects that 'NSDataDetector' returns are different from those that ''NSRegularExpression'' returns. The results are one of the data detector's types and contain the corresponding properties. For example, results of type ''NSTextCheckingResult/CheckingType/date'' have a ''NSTextCheckingResult/date'', ''NSTextCheckingResult/timeZone'', and ''NSTextCheckingResult/duration''; and results of type ''NSTextCheckingResult/CheckingType/link'' have a ''NSTextCheckingResult/url''. > Important: > Don't use 'NSDataDetector' to validate data. 'NSDataDetector' discards potential matches in case of uncertainty. Use a class specific to the type of data for validation instead. For example, attempt to instantiate a ''URL'' object using ''URL/init(string:)'' to validate a URL string. A valid URL string returns an instance of ''URL'', while an invalid URL string returns \<doc://com.apple.documentation/documentation/objectivec/nil-227m0>. \#\#\# Examples The following shows several graduated examples of using the 'NSDataDetector' class. This code fragment creates a data detector that finds URL links and phone numbers. If an error occurs, it returns in 'error'. '''objc NSError error = nil; NSDataDetector detector = [NSDataDetector dataDetectorWithTypes:NSTextCheckingTypeLink|NSTextCheckingTypePhoneNumber error:&error]; ''' After creating the data detector instance, you can determine the number of matches within a range of a string using the 'NSRegularExpression' method ''NSRegularExpression/numberOfMatches(in:options:range:)''. '''objc NSUInteger numberOfMatches = [detector numberOfMatchesInString:string options:0 range:NSMakeRange(0, [string length])]; ''' If you're interested only in the overall range of the first match, the ''NSRegularExpression/numberOfMatches(in:options:range:)'' method provides it. However, with data detectors, this is less likely than with regular expressions because clients are usually interested in additional information as well. The additional information available depends on the type of the result. For results of type ''NSTextCheckingResult/CheckingType/link'', it's the 'URL' property that's significant. For results of type 'NSTextCheckingTypePhoneNumber' , it's the 'phoneNumber' property instead. The ''NSRegularExpression/matches(in:options:range:)'' method is similar to ''NSRegularExpression/firstMatch(in:options:range:)'', except that it returns all matches rather than only the first. The following code fragment finds all the matches for links and phone numbers in a string: '''objc NSArray matches = [detector matchesInString:string options:0 range:NSMakeRange(0, [string length])]; for (NSTextCheckingResult match in matches) { NSRange matchRange = [match range]; if ([match resultType] == NSTextCheckingTypeLink) { NSURL url = [match URL]; } else if ([match resultType] == NSTextCheckingTypePhoneNumber) { NSString phoneNumber = [match phoneNumber]; } } ''' The 'NSRegularExpression' block object enumerator is the most general and flexible of the matching methods. It allows you to iterate through matches in a string, performing arbitrary actions on each as specified by the code in the block, and to stop partway through if desired. In the following code fragment, the iteration stops after finding a certain number of matches: '''objc block NSUInteger count = 0; [detector enumerateMatchesInString:string options:0 range:NSMakeRange(0, [string length]) usingBlock:^(NSTextCheckingResult match, NSMatchingFlags flags, BOOL stop){ NSRange matchRange = [match range]; if ([match resultType] == NSTextCheckingTypeLink) { NSURL url = [match URL]; } else if ([match resultType] == NSTextCheckingTypePhoneNumber) { NSString phoneNumber = [match phoneNumber]; } if (++count >= 100) stop = YES; }]; ''' > Note: > Only use 'NSDataDetector' on natural language text. > > If you expect text to be in a particular format, use an ''Formatter'' or ''ValueTransformer'' subclass instead. For instance, if you're expecting a date field to be an ISO 8601 timestamp, use ''DateFormatter'' to parse that into an ''NSDate'' object. > > If the text is in a machine-readable format, such as XML or JSON, extract the natural language text, such as by using ''XMLParser'' or ''JSONSerialization'', and match on that rather than attempt to match on the entire document.
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
     * @details NSDataDetector is a specialized subclass of NSRegularExpression. Instead of finding matches to regular expression patterns, it matches items identified by Data Detectors, such as dates, addresses, and URLs. The checkingTypes argument should contain one or more of the types NSTextCheckingTypeDate, NSTextCheckingTypeAddress, NSTextCheckingTypeLink, NSTextCheckingTypePhoneNumber, and NSTextCheckingTypeTransitInformation.
     * @param checking_types Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static DataDetector data_detector_with_types(std::uint64_t checking_types);
        /**
     * @brief Returns the `checkingTypes` property of `NSDataDetector`.
     * @details The checking types for the data detector. The supported subset of checking types are specified in ''NSTextCheckingResult/CheckingType''. Those constants can be combined using the C-bitwise OR operator. Currently, the supported data detector checking types are: ''NSTextCheckingResult/CheckingType/date'', ''NSTextCheckingResult/CheckingType/address'', ''NSTextCheckingResult/CheckingType/link'', phone number, and transit information.
     * @return The converted Objective-C result.
     */
        std::uint64_t checking_types() const;
    };
}
