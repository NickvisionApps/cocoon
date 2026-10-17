#include "generated/xmldtd.h"
#include "internal.h"

namespace cocoon
{
    XMLDTD::XMLDTD(const URL& url, XMLNodeOptions mask) : XMLDTD(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                {
                                                                                                    NSError* __error = nil;
                                                                                                    id __r = [[::NSXMLDTD alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSXMLNodeOptions>(mask) error:&__error];
                                                                                                    if (!__r && __error)
                                                                                                    {
                                                                                                        throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                    }
                                                                                                    return __r;
                                                                                                }())})
    {
    }

    XMLDTD::XMLDTD(const std::vector<std::uint8_t>& data, XMLNodeOptions mask) : XMLDTD(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                       {
                                                                                                                           NSError* __error = nil;
                                                                                                                           id __r = [[::NSXMLDTD alloc] initWithData:cocoon::internal::to_data(data) options:static_cast<::NSXMLNodeOptions>(mask) error:&__error];
                                                                                                                           if (!__r && __error)
                                                                                                                           {
                                                                                                                               throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                           }
                                                                                                                           return __r;
                                                                                                                       }())})
    {
    }

    XMLDTD::XMLDTD() : XMLDTD(Adopt{cocoon::internal::retain([[::NSXMLDTD alloc] init])})
    {
    }

    XMLDTD::XMLDTD(std::nullptr_t) : XMLNode(nullptr)
    {
    }

    XMLDTD::XMLDTD(Adopt adopt) : XMLNode(adopt)
    {
    }

    void XMLDTD::add_child(const XMLNode& child) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) addChild:cocoon::internal::native<::NSXMLNode>(child)];
    }

    XMLDTDNode XMLDTD::attribute_declaration_for_name(const std::string& name, const std::string& element_name) const
    {
        return cocoon::internal::wrap<XMLDTDNode>([cocoon::internal::ns<::NSXMLDTD>(this) attributeDeclarationForName:cocoon::internal::to(name) elementName:cocoon::internal::to(element_name)]);
    }

    XMLDTDNode XMLDTD::element_declaration_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLDTDNode>([cocoon::internal::ns<::NSXMLDTD>(this) elementDeclarationForName:cocoon::internal::to(name)]);
    }

    XMLDTDNode XMLDTD::entity_declaration_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLDTDNode>([cocoon::internal::ns<::NSXMLDTD>(this) entityDeclarationForName:cocoon::internal::to(name)]);
    }

    void XMLDTD::insert_child(const XMLNode& child, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) insertChild:cocoon::internal::native<::NSXMLNode>(child) atIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLDTD::insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) insertChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                          {
                                                                                              return cocoon::internal::native<::NSXMLNode>(e);
                                                                                          })
                                                       atIndex:static_cast<::NSUInteger>(index)];
    }

    XMLDTDNode XMLDTD::notation_declaration_for_name(const std::string& name) const
    {
        return cocoon::internal::wrap<XMLDTDNode>([cocoon::internal::ns<::NSXMLDTD>(this) notationDeclarationForName:cocoon::internal::to(name)]);
    }

    XMLDTDNode XMLDTD::predefined_entity_declaration_for_name(const std::string& name)
    {
        return cocoon::internal::wrap<XMLDTDNode>([::NSXMLDTD predefinedEntityDeclarationForName:cocoon::internal::to(name)]);
    }

    void XMLDTD::remove_child_at_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) removeChildAtIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLDTD::replace_child_at_index(std::uint64_t index, const XMLNode& node) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) replaceChildAtIndex:static_cast<::NSUInteger>(index) withNode:cocoon::internal::native<::NSXMLNode>(node)];
    }

    void XMLDTD::set_children(const std::vector<XMLNode>& children) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) setChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                       {
                                                                                           return cocoon::internal::native<::NSXMLNode>(e);
                                                                                       })];
    }

    std::string XMLDTD::public_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDTD>(this) publicID]);
    }

    void XMLDTD::set_public_id(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) setPublicID:cocoon::internal::to(value)];
    }

    std::string XMLDTD::system_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDTD>(this) systemID]);
    }

    void XMLDTD::set_system_id(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDTD>(this) setSystemID:cocoon::internal::to(value)];
    }
}
