#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class Error;
    class InputStream;
    class URL;

    /**
     * @brief C++ handle for the Objective-C class `NSXMLParser` (Foundation).
     * @details An event driven parser of XML documents (including DTD declarations). An ''XMLParser'' notifies its delegate about the items (elements, attributes, CDATA blocks, comments, and so on) that it encounters as it processes an XML document. It does not itself do anything with those parsed items except report them. It also reports parsing errors. For convenience, an ''XMLParser'' object in the following descriptions is sometimes referred to as a parser object. Unless used in a callback, the ''XMLParser'' is a thread-safe class as long as any given instance is only used in one thread. > Note: > Namespace support was implemented in ''XMLParser'' starting in macOS 10.4. Namespace-related methods of ''XMLParser'' prior to this version have no effect.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLParser xml_parser;
     * xml_parser.parser_did_start_document().connect([](auto&&...) {});
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLParser xml_parser{};
     * xml_parser.set_external_entity_resolving_policy(cocoon::XMLParserExternalEntityResolvingPolicy::Never);
     * auto external_entity_resolving_policy = xml_parser.external_entity_resolving_policy();
     * xml_parser.set_should_process_namespaces(true);
     * auto should_process_namespaces = xml_parser.should_process_namespaces();
     * xml_parser.set_should_report_namespace_prefixes(true);
     * auto should_report_namespace_prefixes = xml_parser.should_report_namespace_prefixes();
     * xml_parser.abort_parsing();
     * xml_parser.parse();
     * xml_parser.parser_did_start_document().connect([]() {});
     * xml_parser.parser_did_end_document().connect([]() {});
     * xml_parser.parser_found_notation_declaration_with_name_public_id_system_id().connect([](std::string a0, std::string a1, std::string a2) {});
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmlparser
     */
    class XMLParser : public Object
    {
    public:
        /// @brief Creates a new `NSXMLParser` instance and returns a handle to it.
        explicit XMLParser(const URL& url);
        /// @brief Creates a new `NSXMLParser` instance and returns a handle to it.
        explicit XMLParser(const std::vector<std::uint8_t>& data);
        /// @brief Creates a new `NSXMLParser` instance and returns a handle to it.
        explicit XMLParser(const InputStream& stream);
        /// @brief Creates a new `NSXMLParser` instance and returns a handle to it.
        explicit XMLParser();
        /// @brief Creates a null handle that refers to no native object.
        XMLParser(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLParser(Adopt adopt);
        /**
     * @brief Calls `-[NSXMLParser abortParsing]`.
     * @details Stops the parser object. If you invoke this method, the delegate, if it implements '-parser:parseErrorOccurred:', is informed of the cancelled parsing operation.
     */
        void abort_parsing() const;
        /**
     * @brief Calls `-[NSXMLParser parse]`.
     * @details Starts the event-driven parsing operation. - Returns: 'YES' if the parsing operation succeeds; 'NO' if an error occurs or if the parsing operation aborts.
     * @return The converted Objective-C result.
     */
        bool parse() const;
        /**
     * @brief Returns the `allowedExternalEntityURLs` property of `NSXMLParser`.
     * @details The set of external entity URLs that the parser is allowed to load.
     * @return The converted Objective-C result.
     */
        std::vector<URL> allowed_external_entity_urls() const;
        /**
     * @brief Sets the `allowedExternalEntityURLs` property of `NSXMLParser`.
     * @details The set of external entity URLs that the parser is allowed to load.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_allowed_external_entity_urls(const std::vector<URL>& value) const;
        /**
     * @brief Returns the `columnNumber` property of `NSXMLParser`.
     * @details The column number of the XML document being processed by the parser. The column refers to the nesting level of the XML elements in the document. You may access this property once a parsing operation has begun or after an error occurs.
     * @return The converted Objective-C result.
     */
        std::int64_t column_number() const;
        /**
     * @brief Returns the `externalEntityResolvingPolicy` property of `NSXMLParser`.
     * @details The external entity resolving policy for the parser. Defaults to 'NSXMLParserResolveExternalEntitiesNever'.
     * @return The converted Objective-C result.
     */
        XMLParserExternalEntityResolvingPolicy external_entity_resolving_policy() const;
        /**
     * @brief Sets the `externalEntityResolvingPolicy` property of `NSXMLParser`.
     * @details The external entity resolving policy for the parser. Defaults to 'NSXMLParserResolveExternalEntitiesNever'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_external_entity_resolving_policy(XMLParserExternalEntityResolvingPolicy value) const;
        /**
     * @brief Returns the `lineNumber` property of `NSXMLParser`.
     * @details The line number of the XML document being processed by the parser. You may access this property once a parsing operation has begun or after an error occurs.
     * @return The converted Objective-C result.
     */
        std::int64_t line_number() const;
        /**
     * @brief Returns the `parserError` property of `NSXMLParser`.
     * @details An 'NSError' object from which you can obtain information about a parsing error. You may access this property after a parsing operation abnormally terminates to determine the cause of error.
     * @return The converted Objective-C result.
     */
        Error parser_error() const;
        /**
     * @brief Returns the `publicID` property of `NSXMLParser`.
     * @details The public identifier of the external entity referenced in the XML document. You may access this property once a parsing operation has begun or after an error occurs.
     * @return The converted Objective-C result.
     */
        std::string public_id() const;
        /**
     * @brief Returns the `shouldProcessNamespaces` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports the namespaces and qualified names of elements. 'YES' if the parser reports namespace and qualified name, 'NO' otherwise. The parser reports element names with the delegate methods '-parser:didStartElement:namespaceURI:qualifiedName:attributes:' and '-parser:didEndElement:namespaceURI:qualifiedName:'.
     * @return The converted Objective-C result.
     */
        bool should_process_namespaces() const;
        /**
     * @brief Sets the `shouldProcessNamespaces` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports the namespaces and qualified names of elements. 'YES' if the parser reports namespace and qualified name, 'NO' otherwise. The parser reports element names with the delegate methods '-parser:didStartElement:namespaceURI:qualifiedName:attributes:' and '-parser:didEndElement:namespaceURI:qualifiedName:'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_process_namespaces(bool value) const;
        /**
     * @brief Returns the `shouldReportNamespacePrefixes` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports the prefixes indicating the scope of namespace declarations. 'YES' if the parser reports the scope of namespace declarations, 'NO' otherwise. The default value is 'NO'. The parser reports prefixes with the delegate methods '-parser:didStartMappingPrefix:toURI:' and '-parser:didEndMappingPrefix:'.
     * @return The converted Objective-C result.
     */
        bool should_report_namespace_prefixes() const;
        /**
     * @brief Sets the `shouldReportNamespacePrefixes` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports the prefixes indicating the scope of namespace declarations. 'YES' if the parser reports the scope of namespace declarations, 'NO' otherwise. The default value is 'NO'. The parser reports prefixes with the delegate methods '-parser:didStartMappingPrefix:toURI:' and '-parser:didEndMappingPrefix:'.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_report_namespace_prefixes(bool value) const;
        /**
     * @brief Returns the `shouldResolveExternalEntities` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports declarations of external entities. 'YES' if the parser reports declarations of external entities, 'NO' otherwise. The default value is 'NO'. If you set this property to 'YES', you may cause other I/O operations, either network-based or disk-based, to load the external DTD. Toggles between disabling external entities entirely, and the current setting of the 'externalEntityResolvingPolicy'. The 'externalEntityResolvingPolicy' property should be used instead of this, unless targeting 10.9/7.0 or earlier.
     * @return The converted Objective-C result.
     */
        bool should_resolve_external_entities() const;
        /**
     * @brief Sets the `shouldResolveExternalEntities` property of `NSXMLParser`.
     * @details A Boolean value that determines whether the parser reports declarations of external entities. 'YES' if the parser reports declarations of external entities, 'NO' otherwise. The default value is 'NO'. If you set this property to 'YES', you may cause other I/O operations, either network-based or disk-based, to load the external DTD. Toggles between disabling external entities entirely, and the current setting of the 'externalEntityResolvingPolicy'. The 'externalEntityResolvingPolicy' property should be used instead of this, unless targeting 10.9/7.0 or earlier.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_should_resolve_external_entities(bool value) const;
        /**
     * @brief Returns the `systemID` property of `NSXMLParser`.
     * @details The system identifier of the external entity referenced in the XML document. You may access this property once a parsing operation has begun or after an error occurs.
     * @return The converted Objective-C result.
     */
        std::string system_id() const;
        /// @brief Signal for the delegate/data-source method behind `parser_did_start_document`; connect a callback with `parser_did_start_document().connect(...)`.
        Signal<XMLParser, void()> parser_did_start_document() const
        {
            return Signal<XMLParser, void()>(handle(), "parser_did_start_document");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_did_end_document`; connect a callback with `parser_did_end_document().connect(...)`.
        Signal<XMLParser, void()> parser_did_end_document() const
        {
            return Signal<XMLParser, void()>(handle(), "parser_did_end_document");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_notation_declaration_with_name_public_id_system_id`; connect a callback with `parser_found_notation_declaration_with_name_public_id_system_id().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string)> parser_found_notation_declaration_with_name_public_id_system_id() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string)>(handle(), "parser_found_notation_declaration_with_name_public_id_system_id");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name`; connect a callback with `parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string, std::string)> parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string, std::string)>(handle(), "parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_attribute_declaration_with_name_for_element_type_default_value`; connect a callback with `parser_found_attribute_declaration_with_name_for_element_type_default_value().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string, std::string)> parser_found_attribute_declaration_with_name_for_element_type_default_value() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string, std::string)>(handle(), "parser_found_attribute_declaration_with_name_for_element_type_default_value");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_element_declaration_with_name_model`; connect a callback with `parser_found_element_declaration_with_name_model().connect(...)`.
        Signal<XMLParser, void(std::string, std::string)> parser_found_element_declaration_with_name_model() const
        {
            return Signal<XMLParser, void(std::string, std::string)>(handle(), "parser_found_element_declaration_with_name_model");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_internal_entity_declaration_with_name_value`; connect a callback with `parser_found_internal_entity_declaration_with_name_value().connect(...)`.
        Signal<XMLParser, void(std::string, std::string)> parser_found_internal_entity_declaration_with_name_value() const
        {
            return Signal<XMLParser, void(std::string, std::string)>(handle(), "parser_found_internal_entity_declaration_with_name_value");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_external_entity_declaration_with_name_public_id_system_id`; connect a callback with `parser_found_external_entity_declaration_with_name_public_id_system_id().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string)> parser_found_external_entity_declaration_with_name_public_id_system_id() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string)>(handle(), "parser_found_external_entity_declaration_with_name_public_id_system_id");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_did_start_element_namespace_uri_qualified_name_attributes`; connect a callback with `parser_did_start_element_namespace_uri_qualified_name_attributes().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string, std::map<std::string, std::string>)> parser_did_start_element_namespace_uri_qualified_name_attributes() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string, std::map<std::string, std::string>)>(handle(), "parser_did_start_element_namespace_uri_qualified_name_attributes");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_did_end_element_namespace_uri_qualified_name`; connect a callback with `parser_did_end_element_namespace_uri_qualified_name().connect(...)`.
        Signal<XMLParser, void(std::string, std::string, std::string)> parser_did_end_element_namespace_uri_qualified_name() const
        {
            return Signal<XMLParser, void(std::string, std::string, std::string)>(handle(), "parser_did_end_element_namespace_uri_qualified_name");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_did_start_mapping_prefix_to_uri`; connect a callback with `parser_did_start_mapping_prefix_to_uri().connect(...)`.
        Signal<XMLParser, void(std::string, std::string)> parser_did_start_mapping_prefix_to_uri() const
        {
            return Signal<XMLParser, void(std::string, std::string)>(handle(), "parser_did_start_mapping_prefix_to_uri");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_did_end_mapping_prefix`; connect a callback with `parser_did_end_mapping_prefix().connect(...)`.
        Signal<XMLParser, void(std::string)> parser_did_end_mapping_prefix() const
        {
            return Signal<XMLParser, void(std::string)>(handle(), "parser_did_end_mapping_prefix");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_characters`; connect a callback with `parser_found_characters().connect(...)`.
        Signal<XMLParser, void(std::string)> parser_found_characters() const
        {
            return Signal<XMLParser, void(std::string)>(handle(), "parser_found_characters");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_ignorable_whitespace`; connect a callback with `parser_found_ignorable_whitespace().connect(...)`.
        Signal<XMLParser, void(std::string)> parser_found_ignorable_whitespace() const
        {
            return Signal<XMLParser, void(std::string)>(handle(), "parser_found_ignorable_whitespace");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_processing_instruction_with_target_data`; connect a callback with `parser_found_processing_instruction_with_target_data().connect(...)`.
        Signal<XMLParser, void(std::string, std::string)> parser_found_processing_instruction_with_target_data() const
        {
            return Signal<XMLParser, void(std::string, std::string)>(handle(), "parser_found_processing_instruction_with_target_data");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_comment`; connect a callback with `parser_found_comment().connect(...)`.
        Signal<XMLParser, void(std::string)> parser_found_comment() const
        {
            return Signal<XMLParser, void(std::string)>(handle(), "parser_found_comment");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_found_cdata`; connect a callback with `parser_found_cdata().connect(...)`.
        Signal<XMLParser, void(std::vector<std::uint8_t>)> parser_found_cdata() const
        {
            return Signal<XMLParser, void(std::vector<std::uint8_t>)>(handle(), "parser_found_cdata");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_resolve_external_entity_name_system_id`; connect a callback with `parser_resolve_external_entity_name_system_id().connect(...)`.
        Signal<XMLParser, std::vector<std::uint8_t>(std::string, std::string)> parser_resolve_external_entity_name_system_id() const
        {
            return Signal<XMLParser, std::vector<std::uint8_t>(std::string, std::string)>(handle(), "parser_resolve_external_entity_name_system_id");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_parse_error_occurred`; connect a callback with `parser_parse_error_occurred().connect(...)`.
        Signal<XMLParser, void(Error)> parser_parse_error_occurred() const
        {
            return Signal<XMLParser, void(Error)>(handle(), "parser_parse_error_occurred");
        }
        /// @brief Signal for the delegate/data-source method behind `parser_validation_error_occurred`; connect a callback with `parser_validation_error_occurred().connect(...)`.
        Signal<XMLParser, void(Error)> parser_validation_error_occurred() const
        {
            return Signal<XMLParser, void(Error)>(handle(), "parser_validation_error_occurred");
        }

    protected:
        static void install_delegate_delegate_(void* native);
    };
}
