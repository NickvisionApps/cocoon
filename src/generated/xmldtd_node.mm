#include "generated/xmldtd_node.h"
#include "internal.h"

namespace cocoon
{
    XMLDTDNode::XMLDTDNode(XMLNodeKind kind, XMLNodeOptions options) : XMLDTDNode(Adopt{cocoon::internal::retain([[::NSXMLDTDNode alloc] initWithKind:static_cast<::NSXMLNodeKind>(kind) options:static_cast<::NSXMLNodeOptions>(options)])})
    {
    }

    XMLDTDNode::XMLDTDNode(const std::string& string) : XMLDTDNode(Adopt{cocoon::internal::retain([[::NSXMLDTDNode alloc] initWithXMLString:cocoon::internal::to(string)])})
    {
    }

    XMLDTDNode::XMLDTDNode() : XMLDTDNode(Adopt{cocoon::internal::retain([[::NSXMLDTDNode alloc] init])})
    {
    }

    XMLDTDNode::XMLDTDNode(std::nullptr_t) : XMLNode(nullptr)
    {
    }

    XMLDTDNode::XMLDTDNode(Adopt adopt) : XMLNode(adopt)
    {
    }

    XMLDTDNodeKind XMLDTDNode::dtd_kind() const
    {
        return static_cast<XMLDTDNodeKind>([cocoon::internal::ns<::NSXMLDTDNode>(this) DTDKind]);
    }

    void XMLDTDNode::set_dtd_kind(XMLDTDNodeKind value) const
    {
        [cocoon::internal::ns<::NSXMLDTDNode>(this) setDTDKind:static_cast<::NSXMLDTDNodeKind>(value)];
    }

    bool XMLDTDNode::is_external() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLDTDNode>(this) isExternal]);
    }

    std::string XMLDTDNode::notation_name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDTDNode>(this) notationName]);
    }

    void XMLDTDNode::set_notation_name(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDTDNode>(this) setNotationName:cocoon::internal::to(value)];
    }

    std::string XMLDTDNode::public_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDTDNode>(this) publicID]);
    }

    void XMLDTDNode::set_public_id(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDTDNode>(this) setPublicID:cocoon::internal::to(value)];
    }

    std::string XMLDTDNode::system_id() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDTDNode>(this) systemID]);
    }

    void XMLDTDNode::set_system_id(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDTDNode>(this) setSystemID:cocoon::internal::to(value)];
    }
}
