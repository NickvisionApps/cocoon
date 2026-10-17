#include "generated/apple_event_descriptor.h"
#include "internal.h"

namespace cocoon
{
    AppleEventDescriptor::AppleEventDescriptor() : AppleEventDescriptor(Adopt{cocoon::internal::retain([[::NSAppleEventDescriptor alloc] initListDescriptor])})
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(const AEDesc* ae_desc) : AppleEventDescriptor(Adopt{cocoon::internal::retain([[::NSAppleEventDescriptor alloc] initWithAEDescNoCopy:(const ::AEDesc*)(ae_desc)])})
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(unsigned int descriptor_type, const void* bytes, std::uint64_t byte_count) : AppleEventDescriptor(Adopt{cocoon::internal::retain([[::NSAppleEventDescriptor alloc] initWithDescriptorType:static_cast<::DescType>(descriptor_type) bytes:bytes length:static_cast<::NSUInteger>(byte_count)])})
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(unsigned int descriptor_type, const std::vector<std::uint8_t>& data) : AppleEventDescriptor(Adopt{cocoon::internal::retain([[::NSAppleEventDescriptor alloc] initWithDescriptorType:static_cast<::DescType>(descriptor_type) data:cocoon::internal::to_data(data)])})
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(unsigned int event_class, unsigned int event_id, const AppleEventDescriptor& target_descriptor, std::int16_t return_id, int transaction_id) : AppleEventDescriptor(Adopt{cocoon::internal::retain([[::NSAppleEventDescriptor alloc] initWithEventClass:static_cast<::AEEventClass>(event_class) eventID:static_cast<::AEEventID>(event_id) targetDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(target_descriptor) returnID:static_cast<::AEReturnID>(return_id) transactionID:static_cast<::AETransactionID>(transaction_id)])})
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(std::nullptr_t) : Object(nullptr)
    {
    }

    AppleEventDescriptor::AppleEventDescriptor(Adopt adopt) : Object(adopt)
    {
    }

    AppleEventDescriptor AppleEventDescriptor::apple_event_with_event_class(unsigned int event_class, unsigned int event_id, const AppleEventDescriptor& target_descriptor, std::int16_t return_id, int transaction_id)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor appleEventWithEventClass:static_cast<::AEEventClass>(event_class) eventID:static_cast<::AEEventID>(event_id) targetDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(target_descriptor) returnID:static_cast<::AEReturnID>(return_id) transactionID:static_cast<::AETransactionID>(transaction_id)]);
    }

    AppleEventDescriptor AppleEventDescriptor::attribute_descriptor_for_keyword(unsigned int keyword) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) attributeDescriptorForKeyword:static_cast<::AEKeyword>(keyword)]);
    }

    AppleEventDescriptor AppleEventDescriptor::coerce_to_descriptor_type(unsigned int descriptor_type) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) coerceToDescriptorType:static_cast<::DescType>(descriptor_type)]);
    }

    AppleEventDescriptor AppleEventDescriptor::current_process_descriptor()
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor currentProcessDescriptor]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_at_index(std::int64_t index) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) descriptorAtIndex:static_cast<::NSInteger>(index)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_for_keyword(unsigned int keyword) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) descriptorForKeyword:static_cast<::AEKeyword>(keyword)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_application_url(const URL& application_url)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithApplicationURL:cocoon::internal::native<::NSURL>(application_url)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_boolean(std::uint8_t boolean)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithBoolean:static_cast<::Boolean>(boolean)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_bundle_identifier(const std::string& bundle_identifier)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithBundleIdentifier:cocoon::internal::to(bundle_identifier)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_date(const Date& date)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithDate:cocoon::internal::native<::NSDate>(date)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_descriptor_type(unsigned int descriptor_type, const void* bytes, std::uint64_t byte_count)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithDescriptorType:static_cast<::DescType>(descriptor_type) bytes:bytes length:static_cast<::NSUInteger>(byte_count)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_descriptor_type(unsigned int descriptor_type, const std::vector<std::uint8_t>& data)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithDescriptorType:static_cast<::DescType>(descriptor_type) data:cocoon::internal::to_data(data)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_double(double double_value)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithDouble:static_cast<double>(double_value)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_enum_code(unsigned int enumerator)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithEnumCode:static_cast<::OSType>(enumerator)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_file_url(const URL& file_url)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithFileURL:cocoon::internal::native<::NSURL>(file_url)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_int32(int signed_int)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithInt32:static_cast<::SInt32>(signed_int)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_process_identifier(int process_identifier)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithProcessIdentifier:static_cast<::pid_t>(process_identifier)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_string(const std::string& string)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithString:cocoon::internal::to(string)]);
    }

    AppleEventDescriptor AppleEventDescriptor::descriptor_with_type_code(unsigned int type_code)
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor descriptorWithTypeCode:static_cast<::OSType>(type_code)]);
    }

    void AppleEventDescriptor::insert_descriptor(const AppleEventDescriptor& descriptor, std::int64_t index) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) insertDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(descriptor) atIndex:static_cast<::NSInteger>(index)];
    }

    unsigned int AppleEventDescriptor::keyword_for_descriptor_at_index(std::int64_t index) const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) keywordForDescriptorAtIndex:static_cast<::NSInteger>(index)]);
    }

    AppleEventDescriptor AppleEventDescriptor::list_descriptor()
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor listDescriptor]);
    }

    AppleEventDescriptor AppleEventDescriptor::null_descriptor()
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor nullDescriptor]);
    }

    AppleEventDescriptor AppleEventDescriptor::param_descriptor_for_keyword(unsigned int keyword) const
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) paramDescriptorForKeyword:static_cast<::AEKeyword>(keyword)]);
    }

    AppleEventDescriptor AppleEventDescriptor::record_descriptor()
    {
        return cocoon::internal::wrap<AppleEventDescriptor>([::NSAppleEventDescriptor recordDescriptor]);
    }

    void AppleEventDescriptor::remove_descriptor_at_index(std::int64_t index) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) removeDescriptorAtIndex:static_cast<::NSInteger>(index)];
    }

    void AppleEventDescriptor::remove_descriptor_with_keyword(unsigned int keyword) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) removeDescriptorWithKeyword:static_cast<::AEKeyword>(keyword)];
    }

    void AppleEventDescriptor::remove_param_descriptor_with_keyword(unsigned int keyword) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) removeParamDescriptorWithKeyword:static_cast<::AEKeyword>(keyword)];
    }

    AppleEventDescriptor AppleEventDescriptor::send_event_with_options(AppleEventSendOptions send_options, double timeout_in_seconds) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSAppleEventDescriptor>(this) sendEventWithOptions:static_cast<::NSAppleEventSendOptions>(send_options) timeout:static_cast<::NSTimeInterval>(timeout_in_seconds) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<AppleEventDescriptor>(__r);
    }

    void AppleEventDescriptor::set_attribute_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) setAttributeDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(descriptor) forKeyword:static_cast<::AEKeyword>(keyword)];
    }

    void AppleEventDescriptor::set_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) setDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(descriptor) forKeyword:static_cast<::AEKeyword>(keyword)];
    }

    void AppleEventDescriptor::set_param_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const
    {
        [cocoon::internal::ns<::NSAppleEventDescriptor>(this) setParamDescriptor:cocoon::internal::native<::NSAppleEventDescriptor>(descriptor) forKeyword:static_cast<::AEKeyword>(keyword)];
    }

    const AEDesc* AppleEventDescriptor::ae_desc() const
    {
        return (const AEDesc*)([cocoon::internal::ns<::NSAppleEventDescriptor>(this) aeDesc]);
    }

    std::uint8_t AppleEventDescriptor::boolean_value() const
    {
        return static_cast<std::uint8_t>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) booleanValue]);
    }

    std::vector<std::uint8_t> AppleEventDescriptor::data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSAppleEventDescriptor>(this) data]);
    }

    Date AppleEventDescriptor::date_value() const
    {
        return cocoon::internal::wrap<Date>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) dateValue]);
    }

    unsigned int AppleEventDescriptor::descriptor_type() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) descriptorType]);
    }

    double AppleEventDescriptor::double_value() const
    {
        return static_cast<double>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) doubleValue]);
    }

    unsigned int AppleEventDescriptor::enum_code_value() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) enumCodeValue]);
    }

    unsigned int AppleEventDescriptor::event_class() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) eventClass]);
    }

    unsigned int AppleEventDescriptor::event_id() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) eventID]);
    }

    URL AppleEventDescriptor::file_url_value() const
    {
        return cocoon::internal::wrap<URL>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) fileURLValue]);
    }

    int AppleEventDescriptor::int32_value() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) int32Value]);
    }

    bool AppleEventDescriptor::is_record_descriptor() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) isRecordDescriptor]);
    }

    std::int64_t AppleEventDescriptor::number_of_items() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) numberOfItems]);
    }

    std::int16_t AppleEventDescriptor::return_id() const
    {
        return static_cast<std::int16_t>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) returnID]);
    }

    std::string AppleEventDescriptor::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSAppleEventDescriptor>(this) stringValue]);
    }

    int AppleEventDescriptor::transaction_id() const
    {
        return static_cast<int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) transactionID]);
    }

    unsigned int AppleEventDescriptor::type_code_value() const
    {
        return static_cast<unsigned int>([cocoon::internal::ns<::NSAppleEventDescriptor>(this) typeCodeValue]);
    }
}
