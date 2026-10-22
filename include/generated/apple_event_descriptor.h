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
     * @details A wrapper for the Apple event descriptor data type. An instance of ''NSAppleEventDescriptor'' represents a descriptor—the basic building block for Apple events. This class is a wrapper for the underlying Apple event descriptor data type, \<doc://com.apple.documentation/documentation/coreservices/aedesc>. Scriptable Cocoa applications frequently work with instances of ''NSAppleEventDescriptor'', but should rarely need to work directly with the \<doc://com.apple.documentation/documentation/coreservices/aedesc> data structure. A descriptor is a data structure that stores data and an accompanying four-character code. A descriptor can store a value, or it can store a list of other descriptors (which may also be lists). All the information in an Apple event is stored in descriptors and lists of descriptors, and every Apple event is itself a descriptor list that matches certain criteria. > Important: > An instance of 'NSAppleEventDescriptor' can represent any kind of descriptor, from a simple value descriptor, to a descriptor list, to a full-fledged Apple event. Descriptors can be used to build arbitrarily complex containers, so that one Apple event can represent a script statement such as 'tell application "TextEdit" to get word 3 of paragraph 6 of document 3'. In working with Apple event descriptors, it can be useful to understand some of the underlying data types. You'll find terms such as descriptor, descriptor list, Apple event record, and Apple event defined in Building an Apple Event in Apple Events Programming Guide. You'll also find information on the four-character codes used to identify information within a descriptor. Apple event data types are defined in \<doc://com.apple.documentation/documentation/applicationservices/apple_event_manager>. The values of many four-character codes used by Apple (and in some cases reused by developers) can be found in [AppleScript Terminology and Apple Event Codes](http://developer.apple.com/releasenotes/AppleScript/ASTerminology_AppleEventCodes/TermsAndCodes.html). The most common reason to construct an Apple event with an instance of 'NSAppleEventDescriptor' is to supply information in a return Apple event. The most common situation where you might need to extract information from an Apple event (as an instance of 'NSAppleEventDescriptor') is when an Apple event handler installed by your application is invoked, as described in "Installing an Apple Event Handler" in [How Cocoa Applications Handle Apple Events](https://developer.apple.com/library/archive/documentation/Cocoa/Conceptual/ScriptableCocoaApplications/SApps_handle_AEs/SAppsHandleAEs.html\#//apple_ref/doc/uid/20001239). In addition, if you execute an AppleScript script using the 'NSAppleScript' class, you get an instance of 'NSAppleEventDescriptor' as the return value, from which you can extract any required information. When you work with an instance of 'NSAppleEventDescriptor', you can access the underlying descriptor directly, if necessary, with the ''aeDesc'' method. Other methods, including ''descriptorWithDescriptorType:bytes:length:'' make it possible to create and initialize instances of 'NSAppleEventDescriptor' without creating temporary instances of 'NSData'. The designated initializer for 'NSAppleEventDescriptor' is ''init(aeDescNoCopy:)''. However, it is unlikely that you will need to create a subclass of 'NSAppleEventDescriptor'. Cocoa doesn't currently provide a mechanism for applications to directly send raw Apple events (though compiling and executing an AppleScript script with 'NSAppleScript' may result in Apple events being sent). However, Cocoa applications have full access to the Apple Event Manager C APIs for working with Apple events. So, for example, you might use an instance of 'NSAppleEventDescriptor' to assemble an Apple event and call the Apple Event Manager function 'AESend(:::::::)' to send it. If you need to send Apple events, or if you need more information on some of the Apple event concepts described here, see Apple Events Programming Guide and \<doc://com.apple.documentation/documentation/applicationservices/apple_event_manager>.
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
         * @details Creates a descriptor that represents an Apple event, initialized according to the specified information. - Parameters: - eventClass: The event class to be set in the returned descriptor. - eventID: The event ID to be set in the returned descriptor. - targetDescriptor: A pointer to a descriptor that identifies the target application for the Apple event. Passing 'nil' results in an Apple event descriptor that has no 'keyAddressAttr' attribute (it is valid for an Apple event to have no target address attribute). - returnID: The return ID to be set in the returned descriptor. If you pass a value of 'kAutoGenerateReturnID', the Apple Event Manager assigns the created Apple event a return ID that is unique to the current session. If you pass any other value, the Apple Event Manager assigns that value for the ID. - transactionID: The transaction ID to be set in the returned descriptor. A transaction is a sequence of Apple events that are sent back and forth between client and server applications, beginning with the client's initial request for a service. All Apple events that are part of a transaction must have the same transaction ID. You can specify 'kAnyTransactionID' if the Apple event is not one of a series of interdependent Apple events. - Returns: A descriptor for an Apple event, initialized according to the specified parameter values, or 'nil' if an error occurs. Constants such as 'kAutoGenerateReturnID' and 'kAnyTransactionID' are defined in 'AE.framework', a subframework of 'ApplicationServices.framework'.
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
         * @details Returns a descriptor for the receiver's Apple event attribute identified by the specified keyword. - Parameter keyword: A keyword (a four-character code) that identifies the descriptor to obtain. - Returns: The attribute descriptor for the specified keyword, or 'nil' if an error occurs. The receiver must be an Apple event.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor attribute_descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor coerceToDescriptorType:]`.
         * @details Returns a descriptor obtained by coercing the receiver to the specified type. - Parameter descriptorType: The descriptor type to coerce the receiver to. - Returns: A descriptor of the specified type, or 'nil' if an error occurs.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor coerce_to_descriptor_type(unsigned int descriptor_type) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor currentProcessDescriptor]`.
         * @details Creates and returns an application address descriptor using the current process. The result is suitable for use as the 'targetDescriptor' parameter of '+appleEventWithEventClass:eventID:targetDescriptor:returnID:transactionID:'.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor current_process_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor descriptorAtIndex:]`.
         * @details Returns the descriptor at the specified (one-based) position in the receiving descriptor list. - Parameter index: The one-based descriptor list position of the descriptor to return. - Returns: The descriptor from the specified position (one-based) in the descriptor list, or 'nil' if the specified descriptor cannot be obtained.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor descriptorForKeyword:]`.
         * @details Returns the receiver's descriptor for the specified keyword. - Parameter keyword: A keyword (a four-character code) that identifies the descriptor to obtain. - Returns: A descriptor for the specified keyword, or 'nil' if an error occurs.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithApplicationURL:]`.
         * @details Creates and returns an application address descriptor using the specified application URL. The result is suitable for use as the 'targetDescriptor' parameter of '+appleEventWithEventClass:eventID:targetDescriptor:returnID:transactionID:'.
         * @param application_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_application_url(const URL& application_url);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithBoolean:]`.
         * @details Creates a descriptor initialized with type 'typeBoolean' that stores the specified Boolean value. - Parameter boolean: The Boolean value to be set in the returned descriptor. - Returns: A descriptor with the specified Boolean value, or 'nil' if an error occurs.
         * @param boolean Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_boolean(std::uint8_t boolean);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithBundleIdentifier:]`.
         * @details Creates and returns an application address descriptor using the specified bundle identifier. The result is suitable for use as the 'targetDescriptor' parameter of '+appleEventWithEventClass:eventID:targetDescriptor:returnID:transactionID:'.
         * @param bundle_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_bundle_identifier(const std::string& bundle_identifier);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDate:]`.
         * @details Creates a descriptor that stores the specified date value.
         * @param date Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_date(const Date& date);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDescriptorType:bytes:length:]`.
         * @details Creates a descriptor initialized with the specified event type that stores the specified data (from a series of bytes). - Parameters: - descriptorType: The descriptor type to be set in the returned descriptor. - bytes: The data, as a sequence of bytes, to be set in the returned descriptor. - byteCount: The length, in bytes, of the data to be set in the returned descriptor. - Returns: A descriptor with the specified type and data, or 'nil' if an error occurs.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @param bytes Argument converted to the Objective-C parameter of the same role.
         * @param byte_count Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_descriptor_type(unsigned int descriptor_type, const void* bytes, std::uint64_t byte_count);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDescriptorType:data:]`.
         * @details Creates a descriptor initialized with the specified event type that stores the specified data (from an instance of 'NSData'). - Parameters: - descriptorType: The descriptor type to be set in the returned descriptor. - data: The data, as an instance of 'NSData', to be set in the returned descriptor. - Returns: A descriptor with the specified type and data, or 'nil' if an error occurs. You can use this method to create a descriptor that you can build into a complete Apple event by calling methods such as '-setAttributeDescriptor:forKeyword:', '-setDescriptor:forKeyword:', and '-setParamDescriptor:forKeyword:'.
         * @param descriptor_type Argument converted to the Objective-C parameter of the same role.
         * @param data Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_descriptor_type(unsigned int descriptor_type, const std::vector<std::uint8_t>& data);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithDouble:]`.
         * @details Creates a descriptor initialized with Apple event type 'typeIEEE64BitFloatingPoint' that stores the specified double value.
         * @param double_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_double(double double_value);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithEnumCode:]`.
         * @details Creates a descriptor initialized with type 'typeEnumerated' that stores the specified enumerator data type value. - Parameter enumerator: A type code that identifies the type of enumerated data to be stored in the returned descriptor. - Returns: A descriptor with the specified enumerator data type value, or 'nil' if an error occurs.
         * @param enumerator Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_enum_code(unsigned int enumerator);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithFileURL:]`.
         * @details Creates a descriptor that stores the specified file URL.
         * @param file_url Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_file_url(const URL& file_url);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithInt32:]`.
         * @details Creates a descriptor initialized with Apple event type 'typeSInt32' that stores the specified integer value. - Parameter signedInt: The integer value to be stored in the returned descriptor. - Returns: A descriptor containing the specified integer value, or 'nil' if an error occurs.
         * @param signed_int Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_int32(int signed_int);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithProcessIdentifier:]`.
         * @details Creates and returns an application address descriptor using the specified process identifier. The result is suitable for use as the 'targetDescriptor' parameter of '+appleEventWithEventClass:eventID:targetDescriptor:returnID:transactionID:'.
         * @param process_identifier Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_process_identifier(int process_identifier);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithString:]`.
         * @details Creates a descriptor initialized with type 'typeUnicodeText' that stores the text from the specified string. - Parameter string: A string that specifies the text to be stored in the returned descriptor. - Returns: A descriptor that contains the text from the specified string, or 'nil' if an error occurs.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_string(const std::string& string);
        /**
         * @brief Calls `+[NSAppleEventDescriptor descriptorWithTypeCode:]`.
         * @details Creates a descriptor initialized with type 'typeType' that stores the specified type value. - Parameter typeCode: The type value to be set in the returned descriptor. - Returns: A descriptor with the specified type, or 'nil' if an error occurs.
         * @param type_code Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor descriptor_with_type_code(unsigned int type_code);
        /**
         * @brief Calls `-[NSAppleEventDescriptor insertDescriptor:atIndex:]`.
         * @details Inserts a descriptor at the specified (one-based) position in the receiving descriptor list, replacing the existing descriptor, if any, at that position. - Parameters: - descriptor: The descriptor to insert in the receiver. Specifying an index of 0 or count + 1 causes appending to the end of the list. - index: The one-based descriptor list position at which to insert the descriptor. Because it actually replaces the descriptor, if any, at the specified position, this method might better be called 'replaceDescriptor:atIndex:'. The receiver must be a list descriptor. The indices are one-based. Currently provides no indication if an error occurs.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_descriptor(const AppleEventDescriptor& descriptor, std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor keywordForDescriptorAtIndex:]`.
         * @details Returns the keyword for the descriptor at the specified (one-based) position in the receiver. - Parameter index: The one-based descriptor list position of the descriptor to get the keyword for. - Returns: The keyword (a four-character code) for the descriptor at the one-based location specified by 'index', or 0 if an error occurs.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        unsigned int keyword_for_descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor listDescriptor]`.
         * @details Creates and initializes an empty list descriptor. A list descriptor is a descriptor whose data consists of one or more descriptors. You can add items to the list by calling '-insertDescriptor:atIndex:' or remove them with '-removeDescriptorAtIndex:'. Invoking this method is equivalent to allocating an instance of 'NSAppleEventDescriptor' and invoking '-initListDescriptor'.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor list_descriptor();
        /**
         * @brief Calls `+[NSAppleEventDescriptor nullDescriptor]`.
         * @details Creates and initializes a descriptor with no parameter or attribute values set. You don't typically call this method, as most 'NSAppleEventDescriptor' instance methods can't be safely called on the returned empty descriptor.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor null_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor paramDescriptorForKeyword:]`.
         * @details Returns a descriptor for the receiver's Apple event parameter identified by the specified keyword. - Parameter keyword: A keyword (a four-character code) that identifies the parameter descriptor to obtain. - Returns: A descriptor for the specified keyword, or 'nil' if an error occurs. The receiver must be an Apple event.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor param_descriptor_for_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `+[NSAppleEventDescriptor recordDescriptor]`.
         * @details Creates and initializes a descriptor for an Apple event record whose data has yet to be set. An Apple event record is a descriptor whose data is a set of descriptors keyed by four-character codes. You can add information to the descriptor with methods such as '-setAttributeDescriptor:forKeyword:', '-setDescriptor:forKeyword:', and '-setParamDescriptor:forKeyword:'. Invoking this method is equivalent to allocating an instance of 'NSAppleEventDescriptor' and invoking '-initRecordDescriptor'.
         * @return The converted Objective-C result.
         */
        static AppleEventDescriptor record_descriptor();
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeDescriptorAtIndex:]`.
         * @details Removes the descriptor at the specified (one-based) position in the receiving descriptor list. - Parameter index: The one-based position of the descriptor to remove. The receiver must be a list descriptor. The indices are one-based. Currently provides no indication if an error occurs.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_descriptor_at_index(std::int64_t index) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeDescriptorWithKeyword:]`.
         * @details Removes the receiver's descriptor identified by the specified keyword. - Parameter keyword: A keyword (a four-character code) that identifies the descriptor to remove. The receiver must be an Apple event or Apple event record. Currently provides no indication if an error occurs.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void remove_descriptor_with_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor removeParamDescriptorWithKeyword:]`.
         * @details Removes the receiver's parameter descriptor identified by the specified keyword. - Parameter keyword: A keyword (a four-character code) that identifies the parameter descriptor to remove. The receiver must be an Apple event or Apple event record, both of which can contain parameters. Currently provides no indication if an error occurs.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void remove_param_descriptor_with_keyword(unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor sendEventWithOptions:timeout:error:]`.
         * @details Sends an Apple event.
         * @param send_options Argument converted to the Objective-C parameter of the same role.
         * @param timeout_in_seconds Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        AppleEventDescriptor send_event_with_options(AppleEventSendOptions send_options, double timeout_in_seconds) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setAttributeDescriptor:forKeyword:]`.
         * @details Adds a descriptor to the receiver as an attribute identified by the specified keyword. - Parameters: - descriptor: The attribute descriptor to add to the receiver. - keyword: A keyword (a four-character code) that identifies the attribute descriptor to add. If a descriptor with that keyword already exists in the receiver, it is replaced. The receiver must be an Apple event. Currently provides no indication if an error occurs.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_attribute_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setDescriptor:forKeyword:]`.
         * @details Adds a descriptor, identified by a keyword, to the receiver. - Parameters: - descriptor: The descriptor to add to the receiver. - keyword: A keyword (a four-character code) that identifies the descriptor to add. If a descriptor with that keyword already exists in the receiver, it is replaced. The receiver must be an Apple event or Apple event record. Currently provides no indication if an error occurs.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Calls `-[NSAppleEventDescriptor setParamDescriptor:forKeyword:]`.
         * @details Adds a descriptor to the receiver as an Apple event parameter identified by the specified keyword. - Parameters: - descriptor: The parameter descriptor to add to the receiver. - keyword: A keyword (a four-character code) that identifies the parameter descriptor to add. If a descriptor with that keyword already exists in the receiver, it is replaced. The receiver must be an Apple event or Apple event record, both of which can contain parameters.
         * @param descriptor Argument converted to the Objective-C parameter of the same role.
         * @param keyword Argument converted to the Objective-C parameter of the same role.
         */
        void set_param_descriptor(const AppleEventDescriptor& descriptor, unsigned int keyword) const;
        /**
         * @brief Returns the `aeDesc` property of `NSAppleEventDescriptor`.
         * @details The 'AEDesc' structure encapsulated by the receiver, if it has one. If the receiver has a valid 'AEDesc' structure, returns a pointer to it; otherwise returns 'nil'.
         * @return The converted Objective-C result.
         */
        const AEDesc* ae_desc() const;
        /**
         * @brief Returns the `booleanValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a Boolean value, coercing (to 'typeBoolean') if necessary. The contents of the descriptor, as a Boolean value, or 'false' if an error occurs.
         * @return The converted Objective-C result.
         */
        std::uint8_t boolean_value() const;
        /**
         * @brief Returns the `data` property of `NSAppleEventDescriptor`.
         * @details The receiver's data. An instance of 'NSData' containing the receiver's data, or 'nil' if an error occurs.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> data() const;
        /**
         * @brief Returns the `dateValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a date, coercing if necessary.
         * @return The converted Objective-C result.
         */
        Date date_value() const;
        /**
         * @brief Returns the `descriptorType` property of `NSAppleEventDescriptor`.
         * @details The descriptor type of the receiver.
         * @return The converted Objective-C result.
         */
        unsigned int descriptor_type() const;
        /**
         * @brief Returns the `doubleValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a double value, coercing (to 'typeIEEE64BitFloatingPoint') if necessary.
         * @return The converted Objective-C result.
         */
        double double_value() const;
        /**
         * @brief Returns the `enumCodeValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as an enumeration type, coercing to 'typeEnumerated' if necessary. The contents of the descriptor, as an enumeration type, or 0 if an error occurs.
         * @return The converted Objective-C result.
         */
        unsigned int enum_code_value() const;
        /**
         * @brief Returns the `eventClass` property of `NSAppleEventDescriptor`.
         * @details The event class for the receiver. The event class (a four-character code) for the receiver, or 0 if an error occurs. The receiver must be an Apple event. An Apple event is identified by its event class and event ID, a pair of four-character codes stored as 32-bit integers.
         * @return The converted Objective-C result.
         */
        unsigned int event_class() const;
        /**
         * @brief Returns the `eventID` property of `NSAppleEventDescriptor`.
         * @details The event ID for the receiver. The event ID (a four-character code) for the receiver, or 0 if an error occurs. The receiver must be an Apple event.
         * @return The converted Objective-C result.
         */
        unsigned int event_id() const;
        /**
         * @brief Returns the `fileURLValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a file URL, coercing if necessary.
         * @return The converted Objective-C result.
         */
        URL file_url_value() const;
        /**
         * @brief Returns the `int32Value` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as an integer, coercing (to 'typeSInt32') if necessary. The contents of the descriptor, as an integer value, or 0 if an error occurs.
         * @return The converted Objective-C result.
         */
        int int32_value() const;
        /**
         * @brief Returns the `isRecordDescriptor` property of `NSAppleEventDescriptor`.
         * @details Returns whether or not the receiver is a record-like descriptor. Record-like descriptors function as records, but may have a 'descriptorType' other than 'typeAERecord', such as 'typeObjectSpecifier'.
         * @return The converted Objective-C result.
         */
        bool is_record_descriptor() const;
        /**
         * @brief Returns the `numberOfItems` property of `NSAppleEventDescriptor`.
         * @details The number of descriptors in the receiver's descriptor list. The number of descriptors in the receiver's descriptor list (possibly 0); returns 0 if an error occurs.
         * @return The converted Objective-C result.
         */
        std::int64_t number_of_items() const;
        /**
         * @brief Returns the `returnID` property of `NSAppleEventDescriptor`.
         * @details The receiver's return ID (the ID for a reply Apple event). The receiver's return ID (an integer value), or 0 if an error occurs. The receiver must be an Apple event.
         * @return The converted Objective-C result.
         */
        std::int16_t return_id() const;
        /**
         * @brief Returns the `stringValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a Unicode text string, coercing to 'typeUnicodeText' if necessary. The contents of the descriptor, as a string, or 'nil' if an error occurs.
         * @return The converted Objective-C result.
         */
        std::string string_value() const;
        /**
         * @brief Returns the `transactionID` property of `NSAppleEventDescriptor`.
         * @details The receiver's transaction ID, if any. The receiver's transaction ID (an integer value), or 0 if an error occurs. The receiver must be an Apple event.
         * @return The converted Objective-C result.
         */
        int transaction_id() const;
        /**
         * @brief Returns the `typeCodeValue` property of `NSAppleEventDescriptor`.
         * @details The contents of the receiver as a type, coercing to 'typeType' if necessary. The contents of the descriptor, as a type, or 0 if an error occurs.
         * @return The converted Objective-C result.
         */
        unsigned int type_code_value() const;
    };
}
