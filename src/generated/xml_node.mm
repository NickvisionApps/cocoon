#include "generated/xml_node.h"
#include "internal.h"

namespace cocoon
{
    XMLNode::XMLNode(XMLNodeKind kind) : XMLNode(Adopt{cocoon::internal::retain([[::NSXMLNode alloc] initWithKind:static_cast<::NSXMLNodeKind>(kind)])})
    {
    }

    XMLNode::XMLNode(XMLNodeKind kind, XMLNodeOptions options) : XMLNode(Adopt{cocoon::internal::retain([[::NSXMLNode alloc] initWithKind:static_cast<::NSXMLNodeKind>(kind) options:static_cast<::NSXMLNodeOptions>(options)])})
    {
    }

    XMLNode::XMLNode() : XMLNode(Adopt{cocoon::internal::retain([[::NSXMLNode alloc] init])})
    {
    }

    XMLNode::XMLNode(std::nullptr_t) : Object(nullptr)
    {
    }

    XMLNode::XMLNode(Adopt adopt) : Object(adopt)
    {
    }

    Object XMLNode::dtd_node_with_xml_string(const std::string& string)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode DTDNodeWithXMLString:cocoon::internal::to(string)]);
    }

    std::string XMLNode::xml_string_with_options(XMLNodeOptions options) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) XMLStringWithOptions:static_cast<::NSXMLNodeOptions>(options)]);
    }

    Object XMLNode::attribute_with_name(const std::string& name, const std::string& uri, const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode attributeWithName:cocoon::internal::to(name) URI:cocoon::internal::to(uri) stringValue:cocoon::internal::to(string_value)]);
    }

    Object XMLNode::attribute_with_name(const std::string& name, const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode attributeWithName:cocoon::internal::to(name) stringValue:cocoon::internal::to(string_value)]);
    }

    std::string XMLNode::canonical_xml_string_preserving_comments(bool comments) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) canonicalXMLStringPreservingComments:static_cast<::BOOL>(comments)]);
    }

    XMLNode XMLNode::child_at_index(std::uint64_t index) const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) childAtIndex:static_cast<::NSUInteger>(index)]);
    }

    Object XMLNode::comment_with_string_value(const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode commentWithStringValue:cocoon::internal::to(string_value)]);
    }

    void XMLNode::detach() const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) detach];
    }

    Object XMLNode::document()
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode document]);
    }

    Object XMLNode::document_with_root_element(const XMLElement& element)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode documentWithRootElement:cocoon::internal::native<::NSXMLElement>(element)]);
    }

    Object XMLNode::element_with_name(const std::string& name)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode elementWithName:cocoon::internal::to(name)]);
    }

    Object XMLNode::element_with_name(const std::string& name, const std::string& uri)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode elementWithName:cocoon::internal::to(name) URI:cocoon::internal::to(uri)]);
    }

    Object XMLNode::element_with_name(const std::string& name, const std::vector<XMLNode>& children, const std::vector<XMLNode>& attributes)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode elementWithName:cocoon::internal::to(name)
                                                    children:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                          {
                                                                              return cocoon::internal::native<::NSXMLNode>(e);
                                                                          })
                                                  attributes:cocoon::internal::to_array(attributes, [](const XMLNode& e) -> id
                                                                          {
                                                                              return cocoon::internal::native<::NSXMLNode>(e);
                                                                          })]);
    }

    std::string XMLNode::local_name_for_name(const std::string& name)
    {
        return cocoon::internal::from([::NSXMLNode localNameForName:cocoon::internal::to(name)]);
    }

    Object XMLNode::namespace_with_name(const std::string& name, const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode namespaceWithName:cocoon::internal::to(name) stringValue:cocoon::internal::to(string_value)]);
    }

    std::vector<XMLNode> XMLNode::nodes_for_x_path(const std::string& xpath) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLNode>(this) nodesForXPath:cocoon::internal::to(xpath) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<XMLNode>(__r, [](id e) -> XMLNode
                                       {
                                           return cocoon::internal::wrap<XMLNode>((::NSXMLNode*)e);
                                       });
    }

    std::vector<Object> XMLNode::objects_for_x_query(const std::string& xquery, const std::map<std::string, Object>& constants) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLNode>(this) objectsForXQuery:cocoon::internal::to(xquery)
                                                     constants:cocoon::internal::to_dictionary(constants, [](const std::string& k) -> id
                                                                                 {
                                                                                     return cocoon::internal::to(k);
                                                                                 },
                                                                                 [](const Object& v) -> id
                                                                                 {
                                                                                     return cocoon::internal::native_id(v);
                                                                                 })
                                                         error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<Object>(__r, [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    std::vector<Object> XMLNode::objects_for_x_query(const std::string& xquery) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLNode>(this) objectsForXQuery:cocoon::internal::to(xquery) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::from_array<Object>(__r, [](id e) -> Object
                                      {
                                          return cocoon::internal::wrap<Object>(e);
                                      });
    }

    XMLNode XMLNode::predefined_namespace_for_prefix(const std::string& name)
    {
        return cocoon::internal::wrap<XMLNode>([::NSXMLNode predefinedNamespaceForPrefix:cocoon::internal::to(name)]);
    }

    std::string XMLNode::prefix_for_name(const std::string& name)
    {
        return cocoon::internal::from([::NSXMLNode prefixForName:cocoon::internal::to(name)]);
    }

    Object XMLNode::processing_instruction_with_name(const std::string& name, const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode processingInstructionWithName:cocoon::internal::to(name) stringValue:cocoon::internal::to(string_value)]);
    }

    void XMLNode::set_string_value(const std::string& string, bool resolve) const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) setStringValue:cocoon::internal::to(string) resolvingEntities:static_cast<::BOOL>(resolve)];
    }

    Object XMLNode::text_with_string_value(const std::string& string_value)
    {
        return cocoon::internal::wrap<Object>([::NSXMLNode textWithStringValue:cocoon::internal::to(string_value)]);
    }

    std::string XMLNode::uri() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) URI]);
    }

    void XMLNode::set_uri(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) setURI:cocoon::internal::to(value)];
    }

    std::string XMLNode::xml_string() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) XMLString]);
    }

    std::string XMLNode::x_path() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) XPath]);
    }

    std::uint64_t XMLNode::child_count() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSXMLNode>(this) childCount]);
    }

    std::vector<XMLNode> XMLNode::children() const
    {
        return cocoon::internal::from_array<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) children], [](id e) -> XMLNode
                                       {
                                           return cocoon::internal::wrap<XMLNode>((::NSXMLNode*)e);
                                       });
    }

    std::string XMLNode::description() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) description]);
    }

    std::uint64_t XMLNode::index() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSXMLNode>(this) index]);
    }

    XMLNodeKind XMLNode::kind() const
    {
        return static_cast<XMLNodeKind>([cocoon::internal::ns<::NSXMLNode>(this) kind]);
    }

    std::uint64_t XMLNode::level() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSXMLNode>(this) level]);
    }

    std::string XMLNode::local_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) localName]);
    }

    std::string XMLNode::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) name]);
    }

    void XMLNode::set_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) setName:cocoon::internal::to(value)];
    }

    XMLNode XMLNode::next_node() const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) nextNode]);
    }

    XMLNode XMLNode::next_sibling() const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) nextSibling]);
    }

    Object XMLNode::object_value() const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSXMLNode>(this) objectValue]);
    }

    void XMLNode::set_object_value(const Object& value) const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) setObjectValue:cocoon::internal::native_id(value)];
    }

    XMLNode XMLNode::parent() const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) parent]);
    }

    std::string XMLNode::prefix() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) prefix]);
    }

    XMLNode XMLNode::previous_node() const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) previousNode]);
    }

    XMLNode XMLNode::previous_sibling() const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLNode>(this) previousSibling]);
    }

    XMLDocument XMLNode::root_document() const
    {
        return cocoon::internal::wrap<XMLDocument>([cocoon::internal::ns<::NSXMLNode>(this) rootDocument]);
    }

    std::string XMLNode::string_value() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLNode>(this) stringValue]);
    }

    void XMLNode::set_string_value(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLNode>(this) setStringValue:cocoon::internal::to(value)];
    }
}
