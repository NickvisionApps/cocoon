#pragma once

#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class Locale;

    /**
     * @brief C++ handle for the Objective-C class `NSTimeZone` (Foundation).
     * @details Information about standard time conventions associated with a specific geopolitical region. In Swift, this type bridges to ''TimeZone''; use ''NSTimeZone'' when you need reference semantics or other Foundation-specific behavior. Time zones represent the standard time policies for a geopolitical region. Time zones have identifiers like "America/Los\\Angeles" and can also be identified by abbreviations, such as PST for Pacific Standard Time. You can create time zone objects by ID with ''init(name:)'' and by abbreviation with ''init(abbreviation:)''. > Note: > Time zone database entries such as "America/Los\\Angeles" are IDs, not names. An example of a time zone name is "Pacific Daylight Time". Although many ''NSTimeZone'' symbols include the word "name", they actually refer to IDs. Time zones can also represent a temporal offset—either plus or minus—from Greenwich Mean Time (GMT). For example, the temporal offset of Pacific Standard Time is 8 hours behind Greenwich Mean Time (GMT-8). You can create time zone objects with a temporal offset by using ''init(forSecondsFromGMT:)''. You typically work with system time zones rather than creating time zones by identifier or by offset. The ''system'' class property returns the time zone currently used by the system, if known. This value is cached once the property is accessed and doesn't reflect any system time zone changes until you call the ''resetSystemTimeZone()'' method. The ''local'' class property returns an autoupdating proxy object that always returns the current time zone used by the system. You can also set the ''default'' class property to make your app run as if it were in a different time zone than the system. > Tip: > You can't use ''NSTimeZone'' APIs to change the time zone of the device or of other apps. ''NSTimeZone'' is toll-free bridged with its Core Foundation counterpart, \<doc://com.apple.documentation/documentation/corefoundation/cftimezone>. See [Toll-Free Bridging](https://developer.apple.com/library/archive/documentation/General/Conceptual/CocoaEncyclopedia/Toll-FreeBridgin/Toll-FreeBridgin.html\#//apple_ref/doc/uid/TP40010810-CH2) for more information on toll-free bridging. > Important: > The Swift overlay to the Foundation framework provides the ''TimeZone'' structure, which bridges to the ''NSTimeZone'' class. For more information about value types, see \<doc://com.apple.documentation/documentation/swift/working-with-foundation-types>.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::TimeZone time_zone;
     * time_zone.set_default_time_zone(cocoon::TimeZone());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::TimeZone time_zone{};
     * time_zone.set_default_time_zone(cocoon::TimeZone());
     * auto default_time_zone = time_zone.default_time_zone();
     * auto made_0 = cocoon::TimeZone::time_zone_for_seconds_from_gmt(1);
     * auto made_1 = cocoon::TimeZone::time_zone_with_abbreviation("text");
     * time_zone.abbreviation_for_date(cocoon::Date());
     * time_zone.daylight_saving_time_offset_for_date(cocoon::Date());
     * time_zone.is_daylight_saving_time_for_date(cocoon::Date());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nstimezone
     */
    class TimeZone : public Object
    {
    public:
        /// @brief Creates a new `NSTimeZone` instance and returns a handle to it.
        explicit TimeZone(const std::string& tz_name);
        /// @brief Creates a new `NSTimeZone` instance and returns a handle to it.
        explicit TimeZone(const std::string& tz_name, const std::vector<std::uint8_t>& a_data);
        /// @brief Creates a new `NSTimeZone` instance and returns a handle to it.
        explicit TimeZone();
        /// @brief Creates a null handle that refers to no native object.
        TimeZone(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit TimeZone(Adopt adopt);
        /**
     * @brief Calls `+[NSTimeZone abbreviationDictionary]`.
     * @return The converted Objective-C result.
     */
        static std::map<std::string, std::string> abbreviation_dictionary();
        /**
     * @brief Calls `-[NSTimeZone abbreviationForDate:]`.
     * @details Returns the abbreviation for the receiver at a given date. - Parameter aDate: The date for which to get the abbreviation for the receiver. - Returns: The abbreviation for the receiver at 'aDate'. Note that the abbreviation may be different at different dates. For example, during daylight saving time the US/Eastern time zone has an abbreviation of "EDT." At other times, its abbreviation is "EST."
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string abbreviation_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone daylightSavingTimeOffsetForDate:]`.
     * @details Returns the daylight saving time offset for a given date. - Parameter aDate: A date. - Returns: The daylight saving time offset for 'aDate'.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double daylight_saving_time_offset_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone isDaylightSavingTimeForDate:]`.
     * @details Indicates whether the receiver uses daylight saving time on a given date. - Parameter aDate: The date against which to test the receiver. - Returns: 'YES' if the receiver uses daylight saving time at 'aDate', otherwise 'NO'.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_daylight_saving_time_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone isEqualToTimeZone:]`.
     * @details Indicates whether the receiver has the same name and data as the specified time zone. - Parameter aTimeZone: The time zone to compare with the receiver. - Returns: 'YES' if 'aTimeZone' and the receiver have the same name and data, otherwise 'NO'.
     * @param a_time_zone Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_time_zone(const TimeZone& a_time_zone) const;
        /**
     * @brief Calls `-[NSTimeZone localizedName:locale:]`.
     * @details Returns the localized name of the time zone. - Parameter style: The format style for the returned string. - Parameter locale: The locale for which to format the name. - Returns: The name of the receiver localized for the given locale using the given style.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_name(TimeZoneNameStyle style, const Locale& locale) const;
        /**
     * @brief Calls `-[NSTimeZone nextDaylightSavingTimeTransitionAfterDate:]`.
     * @details Returns the next daylight saving time transition after a given date. - Parameter aDate: A date. - Returns: The next daylight saving time transition after 'aDate'. Depending on the time zone of the receiver, this method may return a change of the time zone's offset from GMT. Returns 'nil' if the time zone of the receiver does not observe daylight savings time as of 'aDate'.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date next_daylight_saving_time_transition_after_date(const Date& a_date) const;
        /**
     * @brief Calls `+[NSTimeZone resetSystemTimeZone]`.
     * @details Clears any time zone value cached for the 'systemTimeZone' property. If the app has cached the system time zone by accessing the 'systemTimeZone' class property, this method clears that cached value. If you subsequently access 'systemTimeZone', a new time zone object is created and cached.
     */
        static void reset_system_time_zone();
        /**
     * @brief Calls `-[NSTimeZone secondsFromGMTForDate:]`.
     * @details Returns the difference in seconds between the receiver and Greenwich Mean Time at a given date. - Parameter aDate: The date against which to test the receiver. - Returns: The difference in seconds between the receiver and Greenwich Mean Time at 'aDate'. The difference may be different from the current difference if the time zone changes its offset from GMT at different points in the year--for example, the U.S. time zones change with daylight saving time.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t seconds_from_gmt_for_date(const Date& a_date) const;
        /**
     * @brief Calls `+[NSTimeZone timeZoneForSecondsFromGMT:]`.
     * @details Returns a time zone object offset from Greenwich Mean Time by a given number of seconds. - Parameter seconds: The number of seconds by which the new time zone is offset from GMT. - Returns: A time zone object offset from Greenwich Mean Time by 'seconds'. The name of the new time zone is GMT +/- the offset, in hours and minutes. Time zones created with this method never have daylight savings, and the offset is constant no matter the date.
     * @param seconds Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_for_seconds_from_gmt(std::int64_t seconds);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithAbbreviation:]`.
     * @details Returns the time zone object identified by a given abbreviation. - Parameter abbreviation: An abbreviation for a time zone. - Returns: The time zone object identified by 'abbreviation' determined by resolving the abbreviation to a name using the abbreviation dictionary and then returning the time zone for that name. Returns 'nil' if there is no match for 'abbreviation'. In general, you are discouraged from using abbreviations except for unique instances such as "GMT". Time Zone abbreviations are not standardized and so a given abbreviation may have multiple meanings--for example, "EST" refers to Eastern Time in both the United States and Australia.
     * @param abbreviation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_abbreviation(const std::string& abbreviation);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithName:]`.
     * @details Returns the time zone object identified by a given identifier. - Parameter tzName: The ID for the time zone. - Returns: The time zone in the information directory with a name matching 'tzName'. Returns 'nil' if there is no match for the name.
     * @param tz_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_name(const std::string& tz_name);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithName:data:]`.
     * @details Returns the time zone with a given identifier whose data has been initialized using given data. - Parameter tzName: The ID for the time zone. - Parameter aData: This parameter is ignored. - Returns: The time zone with the ID 'tzName'. As of macOS 10.6, the underlying implementation of this method has been changed to ignore the specified 'data' parameter. You should not use this method. Instead, use 'timeZoneWithName:' to get the time zone object for a given name.
     * @param tz_name Argument converted to the Objective-C parameter of the same role.
     * @param a_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_name(const std::string& tz_name, const std::vector<std::uint8_t>& a_data);
        /**
     * @brief Returns the `abbreviation` property of `NSTimeZone`.
     * @details The abbreviation for the receiver, such as "EDT" (Eastern Daylight Time). Invokes 'abbreviationForDate:' with the current date as the argument.
     * @return The converted Objective-C result.
     */
        std::string abbreviation() const;
        /**
     * @brief Returns the `data` property of `NSTimeZone`.
     * @details The data that stores the information used by the receiver. Treat this data as an opaque object.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data() const;
        /**
     * @brief Returns the `daylightSavingTime` property of `NSTimeZone`.
     * @details A Boolean value that indicates whether the receiver is currently using daylight saving time. Invokes 'isDaylightSavingTimeForDate:' with the current date as the argument.
     * @return The converted Objective-C result.
     */
        bool is_daylight_saving_time() const;
        /**
     * @brief Returns the `daylightSavingTimeOffset` property of `NSTimeZone`.
     * @details The current daylight saving time offset of the receiver.
     * @return The converted Objective-C result.
     */
        double daylight_saving_time_offset() const;
        /**
     * @brief Returns the `defaultTimeZone` property of `NSTimeZone`.
     * @details The default time zone for the current app. If no default time zone has been set, the current system time zone is used. If the current system time zone cannot be determined, the GMT time zone is used instead. The default time zone is used by the app for date and time operations. You can set it to cause the app to run as if it were in a different time zone. Setting this property clears any value that was previously set.
     * @return The converted Objective-C result.
     */
        static TimeZone default_time_zone();
        /**
     * @brief Sets the `defaultTimeZone` property of `NSTimeZone`.
     * @details The default time zone for the current app. If no default time zone has been set, the current system time zone is used. If the current system time zone cannot be determined, the GMT time zone is used instead. The default time zone is used by the app for date and time operations. You can set it to cause the app to run as if it were in a different time zone. Setting this property clears any value that was previously set.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_time_zone(const TimeZone& value);
        /**
     * @brief Returns the `description` property of `NSTimeZone`.
     * @details A textual description of the time zone including the name, abbreviation, offset from GMT, and whether or not daylight saving time is currently in effect.
     * @return The converted Objective-C result.
     */
        std::string description() const;
        /**
     * @brief Returns the `knownTimeZoneNames` property of `NSTimeZone`.
     * @details Returns an array of strings listing the IDs of all the time zones known to the system.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> known_time_zone_names();
        /**
     * @brief Returns the `localTimeZone` property of `NSTimeZone`.
     * @details An object that tracks the current system time zone. Use this property when you want an object that always reflects the current system time zone. Contrast this behavior with that of the 'systemTimeZone' class property, which has its value cached until you manually clear it by calling ''resetSystemTimeZone''.
     * @return The converted Objective-C result.
     */
        static TimeZone local_time_zone();
        /**
     * @brief Returns the `name` property of `NSTimeZone`.
     * @details The geopolitical region ID that identifies the receiver.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `nextDaylightSavingTimeTransition` property of `NSTimeZone`.
     * @details The date of the next daylight saving time transition for the receiver. This property contains the date of the next (after the current instant) daylight saving time transition for the receiver. Depending on the time zone of the receiver, the value of this property may represent a change of the time zone's offset from GMT. Returns 'nil' if the time zone of the receiver does not currently observe daylight saving time.
     * @return The converted Objective-C result.
     */
        Date next_daylight_saving_time_transition() const;
        /**
     * @brief Returns the `secondsFromGMT` property of `NSTimeZone`.
     * @details The current difference in seconds between the receiver and Greenwich Mean Time.
     * @return The converted Objective-C result.
     */
        std::int64_t seconds_from_gmt() const;
        /**
     * @brief Returns the `systemTimeZone` property of `NSTimeZone`.
     * @details The time zone currently used by the system. If the current system time zone cannot be determined, the GMT time zone is used instead. If you access this class property, its value is cached by the app and doesn't update if the user subsequently changes the system time zone. In order for the property to reflect the new time zone, you must first call ''resetSystemTimeZone'' to clear the cached value.
     * @return The converted Objective-C result.
     */
        static TimeZone system_time_zone();
        /**
     * @brief Returns the `timeZoneDataVersion` property of `NSTimeZone`.
     * @details Returns the time zone data version.
     * @return The converted Objective-C result.
     */
        static std::string time_zone_data_version();
    };
}
