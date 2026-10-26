#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Date;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSAppleEventDescriptor` (Foundation).
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::AppleEventDescriptor apple_event_descriptor;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::AppleEventDescriptor apple_event_descriptor{};
     * auto made_0 = cocoon::AppleEventDescriptor::apple_event_with_event_class(1, 1, cocoon::AppleEventDescriptor(), 1, 1);
     * auto made_1 = cocoon::AppleEventDescriptor::current_process_descriptor();
     * apple_event_descriptor.attribute_descriptor_for_keyword(1);
     * apple_event_descriptor.coerce_to_descriptor_type(1);
     * apple_event_descriptor.descriptor_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsappleeventdescriptor
     */
    class AppleEventDescriptor : public Object
    {
    public:
        /// @brief Creates a new `NSAppleEventDescriptor` instance and returns a handle to it.
        explicit AppleEventDescriptor();
        /// @brief Creates a new `NSAppleEventDescriptor` instance and returns a handle to it.
        explicit AppleEventDescriptor(const AEDesc* ae_desc);
        /// @brief Creates a new `NSAppleEventDescriptor` instance and returns a handle to it.
        explicit AppleEventDescriptor(unsigned int descriptor_type, const void* bytes, std::uint64_t byte_count);
        /// @brief Creates a new `NSAppleEventDescriptor` instance and returns a handle to it.
        explicit AppleEventDescriptor(unsigned int descriptor_type, const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSAppleEventDescriptor` instance and returns a handle to it.
        explicit AppleEventDescriptor(unsigned int event_class, unsigned int event_id, const AppleEventDescriptor& target_descriptor, std::int16_t return_id, int transaction_id);
        /// @brief Creates a null handle that refers to no native object.
        AppleEventDescriptor(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit AppleEventDescriptor(Adopt adopt);
        /**
         * @brief Calls `+[NSAppleEventDescriptor appleEventWithEventClass:eventID:targetDescriptor:returnID:transactionID:]`.
         * @param event_class Argument converted to the Objective-C parameter of the same role.
         * @param event_id Argument converted to the Objective-C parameter of the same role.
         * @param target_descriptor Argument converted to the Objective-C parameter of the same role.
         * @param return_id Argument converted to the Objective-C parameter of the same role.
         * @param transaction_id Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor apple_event_with_event_class(unsigned int event_class, unsigned int event_id, const AppleEventDescriptor& target_descriptor, std::int16_t return_id, int transaction_id);
        /**
         * @brief Calls `-[NSAppleEventDescriptor attributeDescriptorForKeyword:]`.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor attribute_descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor coerceToDescriptorType:]`.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor coerce_to_descriptor_type(unsigned int descriptor_type) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor currentProcessDescriptor]`.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor current_process_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor descriptorAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor descriptorForKeyword:]`.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithApplicationURL:]`.
         * @param application_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_application_url(const URL& application_url);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithBoolean:]`.
         * @param boolean Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_boolean(std::uint8_t boolean);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithBundleIdentifier:]`.
         * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_bundle_identifier(const std::string& bundle_identifier);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDate:]`.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_date(const Date& date);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDescriptorType:bytes:length:]`.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @param bytes Argument converted to the Objective-C parameter of the same role.
         * @param byte_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_descriptor_type(unsigned int descriptor_type, const void* bytes, std::uint64_t byte_count);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDescriptorType:data:]`.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_descriptor_type(unsigned int descriptor_type, const std::vector<std::uint8_t>& data);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDouble:]`.
         * @param double_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_double(double double_value);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithEnumCode:]`.
         * @param enumerator Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_enum_code(unsigned int enumerator);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithFileURL:]`.
         * @param file_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_file_url(const URL& file_url);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithInt32:]`.
         * @param signed_int Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_int32(int signed_int);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithProcessIdentifier:]`.
         * @param process_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_process_identifier(int process_identifier);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithString:]`.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_string(const std::string& string);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithTypeCode:]`.
         * @param type_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_type_code(unsigned int type_code);
        /**
         * @brief Calls `-[NSAppleEventDescriptor insertDescriptor:atIndex:]`.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_descriptor(const AppleEventDescriptor& descriptor, std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor keywordForDescriptorAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int keyword_for_descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor listDescriptor]`.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor list_descriptor();
        /**
         * @brief Calls `+[NSAppleEventDescriptor nullDescriptor]`.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor null_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor paramDescriptorForKeyword:]`.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor param_descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor recordDescriptor]`.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor record_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeDescriptorAtIndex:]`.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeDescriptorWithKeyword:]`.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void remove_descriptor_with_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeParamDescriptorWithKeyword:]`.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void remove_param_descriptor_with_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor sendEventWithOptions:timeout:error:]`.
         * @param send_options Argument converted to the Objective-C parameter of the same role.
         * @param timeout_in_seconds Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor send_event_with_options(AppleEventSendOptions send_options, double timeout_in_seconds) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setAttributeDescriptor:forKeyword:]`.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_attribute_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setDescriptor:forKeyword:]`.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setParamDescriptor:forKeyword:]`.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_param_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Returns the `aeDesc` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        const AEDesc* ae_desc() const;
        /**
         * @brief Returns the `booleanValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        std::uint8_t boolean_value() const;
        /**
         * @brief Returns the `data` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data() const;
        /**
         * @brief Returns the `dateValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        Date date_value() const;
        /**
         * @brief Returns the `descriptorType` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        unsigned int descriptor_type() const;
        /**
         * @brief Returns the `doubleValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        double double_value() const;
        /**
         * @brief Returns the `enumCodeValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        unsigned int enum_code_value() const;
        /**
         * @brief Returns the `eventClass` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        unsigned int event_class() const;
        /**
         * @brief Returns the `eventID` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        unsigned int event_id() const;
        /**
         * @brief Returns the `fileURLValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        URL file_url_value() const;
        /**
         * @brief Returns the `int32Value` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        int int32_value() const;
        /**
         * @brief Returns the `isRecordDescriptor` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        bool is_record_descriptor() const;
        /**
         * @brief Returns the `numberOfItems` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_items() const;
        /**
         * @brief Returns the `returnID` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        std::int16_t return_id() const;
        /**
         * @brief Returns the `stringValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        std::string string_value() const;
        /**
         * @brief Returns the `transactionID` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        int transaction_id() const;
        /**
         * @brief Returns the `typeCodeValue` property of `NSAppleEventDescriptor`.
         * @return The converted Objective-C result.
         */
        unsigned int type_code_value() const;
    };
}
