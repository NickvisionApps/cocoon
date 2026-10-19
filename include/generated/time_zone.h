#pragma once

#include "generated/availability.h"
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
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string abbreviation_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone daylightSavingTimeOffsetForDate:]`.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        double daylight_saving_time_offset_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone isDaylightSavingTimeForDate:]`.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_daylight_saving_time_for_date(const Date& a_date) const;
        /**
     * @brief Calls `-[NSTimeZone isEqualToTimeZone:]`.
     * @param a_time_zone Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        bool is_equal_to_time_zone(const TimeZone& a_time_zone) const;
        /**
     * @brief Calls `-[NSTimeZone localizedName:locale:]`.
     * @param style Argument converted to the Objective-C parameter of the same role.
     * @param locale Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string localized_name(TimeZoneNameStyle style, const Locale& locale) const;
        /**
     * @brief Calls `-[NSTimeZone nextDaylightSavingTimeTransitionAfterDate:]`.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Date next_daylight_saving_time_transition_after_date(const Date& a_date) const;
        /**
     * @brief Calls `+[NSTimeZone resetSystemTimeZone]`.
     */
        static void reset_system_time_zone();
        /**
     * @brief Calls `-[NSTimeZone secondsFromGMTForDate:]`.
     * @param a_date Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::int64_t seconds_from_gmt_for_date(const Date& a_date) const;
        /**
     * @brief Calls `+[NSTimeZone timeZoneForSecondsFromGMT:]`.
     * @param seconds Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_for_seconds_from_gmt(std::int64_t seconds);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithAbbreviation:]`.
     * @param abbreviation Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_abbreviation(const std::string& abbreviation);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithName:]`.
     * @param tz_name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_name(const std::string& tz_name);
        /**
     * @brief Calls `+[NSTimeZone timeZoneWithName:data:]`.
     * @param tz_name Argument converted to the Objective-C parameter of the same role.
     * @param a_data Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static TimeZone time_zone_with_name(const std::string& tz_name, const std::vector<std::uint8_t>& a_data);
        /**
     * @brief Returns the `abbreviation` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        std::string abbreviation() const;
        /**
     * @brief Returns the `data` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> data() const;
        /**
     * @brief Returns the `daylightSavingTime` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        bool is_daylight_saving_time() const;
        /**
     * @brief Returns the `daylightSavingTimeOffset` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        double daylight_saving_time_offset() const;
        /**
     * @brief Returns the `defaultTimeZone` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        static TimeZone default_time_zone();
        /**
     * @brief Sets the `defaultTimeZone` property of `NSTimeZone`.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        static void set_default_time_zone(const TimeZone& value);
        /**
     * @brief Returns the `description` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        std::string description() const;
        /**
     * @brief Returns the `knownTimeZoneNames` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        static std::vector<std::string> known_time_zone_names();
        /**
     * @brief Returns the `localTimeZone` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        static TimeZone local_time_zone();
        /**
     * @brief Returns the `name` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Returns the `nextDaylightSavingTimeTransition` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        Date next_daylight_saving_time_transition() const;
        /**
     * @brief Returns the `secondsFromGMT` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        std::int64_t seconds_from_gmt() const;
        /**
     * @brief Returns the `systemTimeZone` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        static TimeZone system_time_zone();
        /**
     * @brief Returns the `timeZoneDataVersion` property of `NSTimeZone`.
     * @return The converted Objective-C result.
     */
        static std::string time_zone_data_version();
    };
}
