#include "generated/xml_parser.h"
#include "internal.h"

@interface AKXMLParserDelegate : NSObject <NSXMLParserDelegate>
{
@public
    __weak id host;
}
@end

@implementation AKXMLParserDelegate

- (void)parserDidStartDocument:(NSXMLParser*)parser
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void()>::emit((__bridge void*)strongHost, "parser_did_start_document");
}

- (void)parserDidEndDocument:(NSXMLParser*)parser
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void()>::emit((__bridge void*)strongHost, "parser_did_end_document");
}

- (void)parser:(NSXMLParser*)parser foundNotationDeclarationWithName:(NSString*)name publicID:(NSString*)publicID systemID:(NSString*)systemID
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_notation_declaration_with_name_public_id_system_id", cocoon::internal::from(name), cocoon::internal::from(publicID), cocoon::internal::from(systemID));
}

- (void)parser:(NSXMLParser*)parser foundUnparsedEntityDeclarationWithName:(NSString*)name publicID:(NSString*)publicID systemID:(NSString*)systemID notationName:(NSString*)notationName
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name", cocoon::internal::from(name), cocoon::internal::from(publicID), cocoon::internal::from(systemID), cocoon::internal::from(notationName));
}

- (void)parser:(NSXMLParser*)parser foundAttributeDeclarationWithName:(NSString*)attributeName forElement:(NSString*)elementName type:(NSString*)type defaultValue:(NSString*)defaultValue
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_attribute_declaration_with_name_for_element_type_default_value", cocoon::internal::from(attributeName), cocoon::internal::from(elementName), cocoon::internal::from(type), cocoon::internal::from(defaultValue));
}

- (void)parser:(NSXMLParser*)parser foundElementDeclarationWithName:(NSString*)elementName model:(NSString*)model
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_element_declaration_with_name_model", cocoon::internal::from(elementName), cocoon::internal::from(model));
}

- (void)parser:(NSXMLParser*)parser foundInternalEntityDeclarationWithName:(NSString*)name value:(NSString*)value
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_internal_entity_declaration_with_name_value", cocoon::internal::from(name), cocoon::internal::from(value));
}

- (void)parser:(NSXMLParser*)parser foundExternalEntityDeclarationWithName:(NSString*)name publicID:(NSString*)publicID systemID:(NSString*)systemID
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_external_entity_declaration_with_name_public_id_system_id", cocoon::internal::from(name), cocoon::internal::from(publicID), cocoon::internal::from(systemID));
}

- (void)parser:(NSXMLParser*)parser didStartElement:(NSString*)elementName namespaceURI:(NSString*)namespaceURI qualifiedName:(NSString*)qName attributes:(NSDictionary<NSString*, NSString*>*)attributeDict
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::map<std::string, std::string>)>::emit((__bridge void*)strongHost, "parser_did_start_element_namespace_uri_qualified_name_attributes", cocoon::internal::from(elementName), cocoon::internal::from(namespaceURI), cocoon::internal::from(qName), cocoon::internal::from_dictionary<std::map<std::string, std::string>>(attributeDict, [](id k) -> std::string
                                                                                                                                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                                                                                                                                         return cocoon::internal::from((NSString*)k);
                                                                                                                                                                                                                                                                                                                                                     },
                                                                                                                                                                                                                                                                                                                                                     [](id v) -> std::string
                                                                                                                                                                                                                                                                                                                                                     {
                                                                                                                                                                                                                                                                                                                                                         return cocoon::internal::from((NSString*)v);
                                                                                                                                                                                                                                                                                                                                                     }));
}

- (void)parser:(NSXMLParser*)parser didEndElement:(NSString*)elementName namespaceURI:(NSString*)namespaceURI qualifiedName:(NSString*)qName
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::emit((__bridge void*)strongHost, "parser_did_end_element_namespace_uri_qualified_name", cocoon::internal::from(elementName), cocoon::internal::from(namespaceURI), cocoon::internal::from(qName));
}

- (void)parser:(NSXMLParser*)parser didStartMappingPrefix:(NSString*)prefix toURI:(NSString*)namespaceURI
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::emit((__bridge void*)strongHost, "parser_did_start_mapping_prefix_to_uri", cocoon::internal::from(prefix), cocoon::internal::from(namespaceURI));
}

- (void)parser:(NSXMLParser*)parser didEndMappingPrefix:(NSString*)prefix
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string)>::emit((__bridge void*)strongHost, "parser_did_end_mapping_prefix", cocoon::internal::from(prefix));
}

- (void)parser:(NSXMLParser*)parser foundCharacters:(NSString*)string
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string)>::emit((__bridge void*)strongHost, "parser_found_characters", cocoon::internal::from(string));
}

- (void)parser:(NSXMLParser*)parser foundIgnorableWhitespace:(NSString*)whitespaceString
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string)>::emit((__bridge void*)strongHost, "parser_found_ignorable_whitespace", cocoon::internal::from(whitespaceString));
}

- (void)parser:(NSXMLParser*)parser foundProcessingInstructionWithTarget:(NSString*)target data:(NSString*)data
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::emit((__bridge void*)strongHost, "parser_found_processing_instruction_with_target_data", cocoon::internal::from(target), cocoon::internal::from(data));
}

- (void)parser:(NSXMLParser*)parser foundComment:(NSString*)comment
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::string)>::emit((__bridge void*)strongHost, "parser_found_comment", cocoon::internal::from(comment));
}

- (void)parser:(NSXMLParser*)parser foundCDATA:(NSData*)CDATABlock_
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(std::vector<std::uint8_t>)>::emit((__bridge void*)strongHost, "parser_found_cdata", cocoon::internal::from_data(CDATABlock_));
}

- (NSData*)parser:(NSXMLParser*)parser resolveExternalEntityName:(NSString*)name systemID:(NSString*)systemID
{
    id strongHost = host;
    if (!strongHost)
    {
        return {};
    }
    auto __r = cocoon::Signal<cocoon::XMLParser, std::vector<std::uint8_t>(std::string, std::string)>::emit((__bridge void*)strongHost, "parser_resolve_external_entity_name_system_id", cocoon::internal::from(name), cocoon::internal::from(systemID));
    return cocoon::internal::to_data(__r);
}

- (void)parser:(NSXMLParser*)parser parseErrorOccurred:(NSError*)parseError
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(cocoon::Error)>::emit((__bridge void*)strongHost, "parser_parse_error_occurred", cocoon::internal::wrap<cocoon::Error>(parseError));
}

- (void)parser:(NSXMLParser*)parser validationErrorOccurred:(NSError*)validationError
{
    id strongHost = host;
    if (!strongHost)
    {
        return;
    }
    cocoon::Signal<cocoon::XMLParser, void(cocoon::Error)>::emit((__bridge void*)strongHost, "parser_validation_error_occurred", cocoon::internal::wrap<cocoon::Error>(validationError));
}

- (BOOL)respondsToSelector:(SEL)selector
{
    id strongHost = host;
    if (selector == @selector(parserDidStartDocument:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void()>::connected((__bridge void*)strongHost, "parser_did_start_document");
    }
    if (selector == @selector(parserDidEndDocument:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void()>::connected((__bridge void*)strongHost, "parser_did_end_document");
    }
    if (selector == @selector(parser:foundNotationDeclarationWithName:publicID:systemID:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_notation_declaration_with_name_public_id_system_id");
    }
    if (selector == @selector(parser:foundUnparsedEntityDeclarationWithName:publicID:systemID:notationName:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_unparsed_entity_declaration_with_name_public_id_system_id_notation_name");
    }
    if (selector == @selector(parser:foundAttributeDeclarationWithName:forElement:type:defaultValue:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_attribute_declaration_with_name_for_element_type_default_value");
    }
    if (selector == @selector(parser:foundElementDeclarationWithName:model:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_element_declaration_with_name_model");
    }
    if (selector == @selector(parser:foundInternalEntityDeclarationWithName:value:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_internal_entity_declaration_with_name_value");
    }
    if (selector == @selector(parser:foundExternalEntityDeclarationWithName:publicID:systemID:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_external_entity_declaration_with_name_public_id_system_id");
    }
    if (selector == @selector(parser:didStartElement:namespaceURI:qualifiedName:attributes:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string, std::map<std::string, std::string>)>::connected((__bridge void*)strongHost, "parser_did_start_element_namespace_uri_qualified_name_attributes");
    }
    if (selector == @selector(parser:didEndElement:namespaceURI:qualifiedName:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string, std::string)>::connected((__bridge void*)strongHost, "parser_did_end_element_namespace_uri_qualified_name");
    }
    if (selector == @selector(parser:didStartMappingPrefix:toURI:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::connected((__bridge void*)strongHost, "parser_did_start_mapping_prefix_to_uri");
    }
    if (selector == @selector(parser:didEndMappingPrefix:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string)>::connected((__bridge void*)strongHost, "parser_did_end_mapping_prefix");
    }
    if (selector == @selector(parser:foundCharacters:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string)>::connected((__bridge void*)strongHost, "parser_found_characters");
    }
    if (selector == @selector(parser:foundIgnorableWhitespace:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string)>::connected((__bridge void*)strongHost, "parser_found_ignorable_whitespace");
    }
    if (selector == @selector(parser:foundProcessingInstructionWithTarget:data:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string, std::string)>::connected((__bridge void*)strongHost, "parser_found_processing_instruction_with_target_data");
    }
    if (selector == @selector(parser:foundComment:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::string)>::connected((__bridge void*)strongHost, "parser_found_comment");
    }
    if (selector == @selector(parser:foundCDATA:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(std::vector<std::uint8_t>)>::connected((__bridge void*)strongHost, "parser_found_cdata");
    }
    if (selector == @selector(parser:resolveExternalEntityName:systemID:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, std::vector<std::uint8_t>(std::string, std::string)>::connected((__bridge void*)strongHost, "parser_resolve_external_entity_name_system_id");
    }
    if (selector == @selector(parser:parseErrorOccurred:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(cocoon::Error)>::connected((__bridge void*)strongHost, "parser_parse_error_occurred");
    }
    if (selector == @selector(parser:validationErrorOccurred:))
    {
        return strongHost && cocoon::Signal<cocoon::XMLParser, void(cocoon::Error)>::connected((__bridge void*)strongHost, "parser_validation_error_occurred");
    }
    return [super respondsToSelector:selector];
}

@end

namespace cocoon
{
    XMLParser::XMLParser(const URL& url) : XMLParser(Adopt{cocoon::internal::retain([[::NSXMLParser alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url)])})
    {
        XMLParser::install_delegate_delegate_(handle());
    }

    XMLParser::XMLParser(const std::vector<std::uint8_t>& data) : XMLParser(Adopt{cocoon::internal::retain([[::NSXMLParser alloc] initWithData:cocoon::internal::to_data(data)])})
    {
        XMLParser::install_delegate_delegate_(handle());
    }

    XMLParser::XMLParser(const InputStream& stream) : XMLParser(Adopt{cocoon::internal::retain([[::NSXMLParser alloc] initWithStream:cocoon::internal::native<::NSInputStream>(stream)])})
    {
        XMLParser::install_delegate_delegate_(handle());
    }

    XMLParser::XMLParser() : XMLParser(Adopt{cocoon::internal::retain([[::NSXMLParser alloc] init])})
    {
        XMLParser::install_delegate_delegate_(handle());
    }

    XMLParser::XMLParser(std::nullptr_t) : Object(nullptr)
    {
    }

    XMLParser::XMLParser(Adopt adopt) : Object(adopt)
    {
    }

    void XMLParser::abort_parsing() const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) abortParsing];
    }

    bool XMLParser::parse() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLParser>(this) parse]);
    }

    std::vector<URL> XMLParser::allowed_external_entity_urls() const
    {
        return cocoon::internal::from_array<URL>([[cocoon::internal::ns<::NSXMLParser>(this) allowedExternalEntityURLs] allObjects], [](id e) -> URL
                                   {
                                       return cocoon::internal::wrap<URL>((::NSURL*)e);
                                   });
    }

    void XMLParser::set_allowed_external_entity_urls(const std::vector<URL>& value) const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) setAllowedExternalEntityURLs:[NSSet setWithArray:cocoon::internal::to_array(value, [](const URL& e) -> id
                                                                                                   {
                                                                                                       return cocoon::internal::native<::NSURL>(e);
                                                                                                   })]];
    }

    std::int64_t XMLParser::column_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSXMLParser>(this) columnNumber]);
    }

    XMLParserExternalEntityResolvingPolicy XMLParser::external_entity_resolving_policy() const
    {
        return static_cast<XMLParserExternalEntityResolvingPolicy>([cocoon::internal::ns<::NSXMLParser>(this) externalEntityResolvingPolicy]);
    }

    void XMLParser::set_external_entity_resolving_policy(XMLParserExternalEntityResolvingPolicy value) const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) setExternalEntityResolvingPolicy:static_cast<::NSXMLParserExternalEntityResolvingPolicy>(value)];
    }

    std::int64_t XMLParser::line_number() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSXMLParser>(this) lineNumber]);
    }

    Error XMLParser::parser_error() const
    {
        return cocoon::internal::wrap<Error>([cocoon::internal::ns<::NSXMLParser>(this) parserError]);
    }

    std::string XMLParser::public_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLParser>(this) publicID]);
    }

    bool XMLParser::should_process_namespaces() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLParser>(this) shouldProcessNamespaces]);
    }

    void XMLParser::set_should_process_namespaces(bool value) const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) setShouldProcessNamespaces:static_cast<::BOOL>(value)];
    }

    bool XMLParser::should_report_namespace_prefixes() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLParser>(this) shouldReportNamespacePrefixes]);
    }

    void XMLParser::set_should_report_namespace_prefixes(bool value) const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) setShouldReportNamespacePrefixes:static_cast<::BOOL>(value)];
    }

    bool XMLParser::should_resolve_external_entities() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLParser>(this) shouldResolveExternalEntities]);
    }

    void XMLParser::set_should_resolve_external_entities(bool value) const
    {
        [cocoon::internal::ns<::NSXMLParser>(this) setShouldResolveExternalEntities:static_cast<::BOOL>(value)];
    }

    std::string XMLParser::system_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLParser>(this) systemID]);
    }

    void XMLParser::install_delegate_delegate_(void* native)
    {
        ::NSXMLParser* host = (__bridge ::NSXMLParser*)native;
        AKXMLParserDelegate* delegate = [[AKXMLParserDelegate alloc] init];
        delegate->host = host;
        host.delegate = delegate;
        __weak::NSXMLParser* weakHost = host;
        cocoon::internal::keep_delegate(host, delegate, ^{
            ::NSXMLParser* strongHost = weakHost;
            strongHost.delegate = nil;
            strongHost.delegate = delegate;
        });
    }
}
