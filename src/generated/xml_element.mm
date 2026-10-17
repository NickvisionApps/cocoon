#include "generated/xml_element.h"
#include "internal.h"

namespace cocoon
{
    XMLElement::XMLElement(XMLNodeKind kind, XMLNodeOptions options) : XMLElement(Adopt{cocoon::internal::retain([[::NSXMLElement alloc] initWithKind:static_cast<::NSXMLNodeKind>(kind) options:static_cast<::NSXMLNodeOptions>(options)])})
    {
    }

    XMLElement::XMLElement(const std::string& name) : XMLElement(Adopt{cocoon::internal::retain([[::NSXMLElement alloc] initWithName:cocoon::internal::to(name)])})
    {
    }

    XMLElement::XMLElement(const std::string& name, const std::string& uri) : XMLElement(Adopt{cocoon::internal::retain([[::NSXMLElement alloc] initWithName:cocoon::internal::to(name) URI:cocoon::internal::to(uri)])})
    {
    }

    XMLElement::XMLElement() : XMLElement(Adopt{cocoon::internal::retain([[::NSXMLElement alloc] init])})
    {
    }

    XMLElement::XMLElement(std::nullptr_t) : XMLNode(nullptr)
    {
    }

    XMLElement::XMLElement(Adopt adopt) : XMLNode(adopt)
    {
    }

    void XMLElement::add_attribute(const XMLNode& attribute) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) addAttribute:cocoon::internal::native<::NSXMLNode>(attribute)];
    }

    void XMLElement::add_child(const XMLNode& child) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) addChild:cocoon::internal::native<::NSXMLNode>(child)];
    }

    void XMLElement::add_namespace(const XMLNode& a_namespace) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) addNamespace:cocoon::internal::native<::NSXMLNode>(a_namespace)];
    }

    XMLNode XMLElement::attribute_for_local_name(const std::string& local_name, const std::string& uri) const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) attributeForLocalName:cocoon::internal::to(local_name) URI:cocoon::internal::to(uri)]);
    }

    XMLNode XMLElement::attribute_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) attributeForName:cocoon::internal::to(name)]);
    }

    std::vector<XMLElement> XMLElement::elements_for_local_name(const std::string& local_name, const std::string& uri) const
    {
        return cocoon::internal::from_array<XMLElement>([cocoon::internal::ns<::NSXMLElement>(this) elementsForLocalName:cocoon::internal::to(local_name) URI:cocoon::internal::to(uri)], [](id e) -> XMLElement
                                                        {
                                                            return cocoon::internal::wrap<XMLElement>((::NSXMLElement*)e);
                                                        });
    }

    std::vector<XMLElement> XMLElement::elements_for_name(const std::string& name) const
    {
        return cocoon::internal::from_array<XMLElement>([cocoon::internal::ns<::NSXMLElement>(this) elementsForName:cocoon::internal::to(name)], [](id e) -> XMLElement
                                                        {
                                                            return cocoon::internal::wrap<XMLElement>((::NSXMLElement*)e);
                                                        });
    }

    void XMLElement::insert_child(const XMLNode& child, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) insertChild:cocoon::internal::native<::NSXMLNode>(child) atIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLElement::insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) insertChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                              {
                                                                                                  return cocoon::internal::native<::NSXMLNode>(e);
                                                                                              })
                                                           atIndex:static_cast<::NSUInteger>(index)];
    }

    XMLNode XMLElement::namespace_for_prefix(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) namespaceForPrefix:cocoon::internal::to(name)]);
    }

    void XMLElement::normalize_adjacent_text_nodes_preserving_cdata(bool preserve) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) normalizeAdjacentTextNodesPreservingCDATA:static_cast<::BOOL>(preserve)];
    }

    void XMLElement::remove_attribute_for_name(const std::string& name) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) removeAttributeForName:cocoon::internal::to(name)];
    }

    void XMLElement::remove_child_at_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) removeChildAtIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLElement::remove_namespace_for_prefix(const std::string& name) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) removeNamespaceForPrefix:cocoon::internal::to(name)];
    }

    void XMLElement::replace_child_at_index(std::uint64_t index, const XMLNode& node) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) replaceChildAtIndex:static_cast<::NSUInteger>(index) withNode:cocoon::internal::native<::NSXMLNode>(node)];
    }

    XMLNode XMLElement::resolve_namespace_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) resolveNamespaceForName:cocoon::internal::to(name)]);
    }

    std::string XMLElement::resolve_prefix_for_namespace_uri(const std::string& namespace_uri) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLElement>(this) resolvePrefixForNamespaceURI:cocoon::internal::to(namespace_uri)]);
    }

    void XMLElement::set_attributes_as_dictionary(const std::vector<std::pair<Object, Object>>& attributes) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) setAttributesAsDictionary:cocoon::internal::to_dictionary(attributes, [](const Object& k) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native_id(k);
                                                                                                              },
                                                                                                              [](const Object& v) -> id
                                                                                                              {
                                                                                                                  return cocoon::internal::native_id(v);
                                                                                                              })];
    }

    void XMLElement::set_attributes_with_dictionary(const std::map<std::string, std::string>& attributes) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) setAttributesWithDictionary:cocoon::internal::to_dictionary(attributes, [](const std::string& k) -> id
                                                                                                                {
                                                                                                                    return cocoon::internal::to(k);
                                                                                                                },
                                                                                                                [](const std::string& v) -> id
                                                                                                                {
                                                                                                                    return cocoon::internal::to(v);
                                                                                                                })];
    }

    void XMLElement::set_children(const std::vector<XMLNode>& children) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) setChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                           {
                                                                                               return cocoon::internal::native<::NSXMLNode>(e);
                                                                                           })];
    }

    std::vector<XMLNode> XMLElement::attributes() const
    {
        return cocoon::internal::from_array<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) attributes], [](id e) -> XMLNode
                                                     {
                                                         return cocoon::internal::wrap<XMLNode>((::NSXMLNode*)e);
                                                     });
    }

    void XMLElement::set_attributes(const std::vector<XMLNode>& value) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) setAttributes:cocoon::internal::to_array(value, [](const XMLNode& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native<::NSXMLNode>(e);
                                                                                             })];
    }

    std::vector<XMLNode> XMLElement::namespaces() const
    {
        return cocoon::internal::from_array<XMLNode>([cocoon::internal::ns<::NSXMLElement>(this) namespaces], [](id e) -> XMLNode
                                                     {
                                                         return cocoon::internal::wrap<XMLNode>((::NSXMLNode*)e);
                                                     });
    }

    void XMLElement::set_namespaces(const std::vector<XMLNode>& value) const
    {
        [cocoon::internal::ns<::NSXMLElement>(this) setNamespaces:cocoon::internal::to_array(value, [](const XMLNode& e) -> id
                                                                                             {
                                                                                                 return cocoon::internal::native<::NSXMLNode>(e);
                                                                                             })];
    }
}
