#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "object.h"
#include "types.h"

namespace cocoon
{
    class XMLDocument;
    class XMLElement;

    /**
     * @brief C++ handle for the Objective-C class `NSXMLNode` (Foundation).
     * @details \@class NSXMLNode \@abstract The basic unit of an XML document.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLNode xml_node;
     * xml_node.set_uri("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLNode xml_node{};
     * xml_node.set_uri("text");
     * auto uri = xml_node.uri();
     * xml_node.set_name("text");
     * auto name = xml_node.name();
     * xml_node.set_string_value("text");
     * auto string_value = xml_node.string_value();
     * auto made_0 = cocoon::XMLNode::predefined_namespace_for_prefix("text");
     * xml_node.xml_string_with_options(cocoon::XMLNodeOptions::NodeOptionsNone);
     * xml_node.canonical_xml_string_preserving_comments(true);
     * xml_node.child_at_index(1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmlnode
     */
    class XMLNode : public Object
    {
    public:
        /// @brief Creates a new `NSXMLNode` instance and returns a handle to it.
        explicit XMLNode(XMLNodeKind kind);
        /// @brief Creates a new `NSXMLNode` instance and returns a handle to it.
        explicit XMLNode(XMLNodeKind kind, XMLNodeOptions options);
        /// @brief Creates a new `NSXMLNode` instance and returns a handle to it.
        explicit XMLNode();
        /// @brief Creates a null handle that refers to no native object.
        XMLNode(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLNode(Adopt adopt);
        /**
     * @brief Calls `+[NSXMLNode DTDNodeWithXMLString:]`.
     * @details \@method DTDNodeWithXMLString: \@abstract Returns an element, attribute, entity, or notation DTD node based on the full XML string.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object dtd_node_with_xml_string(const std::string& string);
        /**
     * @brief Calls `-[NSXMLNode XMLStringWithOptions:]`.
     * @details \@method XMLStringWithOptions: \@abstract The representation of this node as it would appear in an XML document, with various output options available.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string xml_string_with_options(XMLNodeOptions options) const;
        /**
     * @brief Calls `+[NSXMLNode attributeWithName:URI:stringValue:]`.
     * @details \@method attributeWithLocalName:URI:stringValue: \@abstract Returns an attribute whose full QName is specified.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param uri Argument converted to the Objective-C parameter of the same role.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object attribute_with_name(const std::string& name, const std::string& uri, const std::string& string_value);
        /**
     * @brief Calls `+[NSXMLNode attributeWithName:stringValue:]`.
     * @details \@method attributeWithName:stringValue: \@abstract Returns an attribute \<tt>name="stringValue"\</tt>.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object attribute_with_name(const std::string& name, const std::string& string_value);
        /**
     * @brief Calls `-[NSXMLNode canonicalXMLStringPreservingComments:]`.
     * @details \@method canonicalXMLStringPreservingComments: \@abstract W3 canonical form (http://www.w3.org/TR/xml-c14n). The input option NSXMLNodePreserveWhitespace should be set for true canonical form.
     * @param comments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string canonical_xml_string_preserving_comments(bool comments) const;
        /**
     * @brief Calls `-[NSXMLNode childAtIndex:]`.
     * @details \@method childAtIndex: \@abstract Returns the child node at a particular index.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        XMLNode child_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `+[NSXMLNode commentWithStringValue:]`.
     * @details \@method commentWithStringValue: \@abstract Returns a comment \<tt>&lt;--stringValue-->\</tt>.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object comment_with_string_value(const std::string& string_value);
        /**
     * @brief Calls `-[NSXMLNode detach]`.
     * @details \@method detach: \@abstract Detaches this node from its parent.
     */
        void detach() const;
        /**
     * @brief Calls `+[NSXMLNode document]`.
     * @details \@method document: \@abstract Returns an empty document.
     * @return The converted Objective-C result.
     */
        static Object document();
        /**
     * @brief Calls `+[NSXMLNode documentWithRootElement:]`.
     * @details \@method documentWithRootElement: \@abstract Returns a document \@param element The document's root node.
     * @param element Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object document_with_root_element(const XMLElement& element);
        /**
     * @brief Calls `+[NSXMLNode elementWithName:]`.
     * @details \@method elementWithName: \@abstract Returns an element \<tt>&lt;name>&lt;/name>\</tt>.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object element_with_name(const std::string& name);
        /**
     * @brief Calls `+[NSXMLNode elementWithName:URI:]`.
     * @details \@method elementWithName:URI: \@abstract Returns an element whose full QName is specified.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param uri Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object element_with_name(const std::string& name, const std::string& uri);
        /**
     * @brief Calls `+[NSXMLNode elementWithName:children:attributes:]`.
     * @details \@method elementWithName:children:attributes: \@abstract Returns an element children and attributes \<tt>&lt;name attr1="foo" attr2="bar">&lt;-- child1 -->child2&lt;/name>\</tt>.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param children Argument converted to the Objective-C parameter of the same role.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object element_with_name(const std::string& name, const std::vector<XMLNode>& children, const std::vector<XMLNode>& attributes);
        /**
     * @brief Calls `+[NSXMLNode localNameForName:]`.
     * @details \@method localNameForName: \@abstract Returns the local name bar in foo:bar.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string local_name_for_name(const std::string& name);
        /**
     * @brief Calls `+[NSXMLNode namespaceWithName:stringValue:]`.
     * @details \@method namespaceWithName:stringValue: \@abstract Returns a namespace \<tt>xmlns:name="stringValue"\</tt>.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object namespace_with_name(const std::string& name, const std::string& string_value);
        /**
     * @brief Calls `-[NSXMLNode nodesForXPath:error:]`.
     * @details \@method nodesForXPath:error: \@abstract Returns the nodes resulting from applying an XPath to this node using the node as the context item ("."). normalizeAdjacentTextNodesPreservingCDATA:NO should be called if there are adjacent text nodes since they are not allowed under the XPath/XQuery Data Model. \@returns An array whose elements are a kind of NSXMLNode.
     * @param xpath Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<XMLNode> nodes_for_x_path(const std::string& xpath) const;
        /**
     * @brief Calls `-[NSXMLNode objectsForXQuery:constants:error:]`.
     * @details \@method objectsForXQuery:constants:error: \@abstract Returns the objects resulting from applying an XQuery to this node using the node as the context item ("."). Constants are a name-value dictionary for constants declared "external" in the query. normalizeAdjacentTextNodesPreservingCDATA:NO should be called if there are adjacent text nodes since they are not allowed under the XPath/XQuery Data Model. \@returns An array whose elements are kinds of NSArray, NSData, NSDate, NSNumber, NSString, NSURL, or NSXMLNode.
     * @param xquery Argument converted to the Objective-C parameter of the same role.
     * @param constants Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> objects_for_x_query(const std::string& xquery, const std::map<std::string, Object>& constants) const;
        /**
     * @brief Calls `-[NSXMLNode objectsForXQuery:error:]`.
     * @param xquery Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<Object> objects_for_x_query(const std::string& xquery) const;
        /**
     * @brief Calls `+[NSXMLNode predefinedNamespaceForPrefix:]`.
     * @details \@method predefinedNamespaceForPrefix: \@abstract Returns the namespace belonging to one of the predefined namespaces xml, xs, or xsi
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static XMLNode predefined_namespace_for_prefix(const std::string& name);
        /**
     * @brief Calls `+[NSXMLNode prefixForName:]`.
     * @details \@method localNameForName: \@abstract Returns the prefix foo in the name foo:bar.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string prefix_for_name(const std::string& name);
        /**
     * @brief Calls `+[NSXMLNode processingInstructionWithName:stringValue:]`.
     * @details \@method processingInstructionWithName:stringValue: \@abstract Returns a processing instruction \<tt>&lt;?name stringValue>\</tt>.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object processing_instruction_with_name(const std::string& name, const std::string& string_value);
        /**
     * @brief Calls `-[NSXMLNode setStringValue:resolvingEntities:]`.
     * @details \@method setStringValue:resolvingEntities: \@abstract Sets the content as with \@link setStringValue: \@/link, but when "resolve" is true, character references, predefined entities and user entities available in the document's dtd are resolved. Entities not available in the dtd remain in their entity form.
     * @param string Argument converted to the Objective-C parameter of the same role.
     * @param resolve Argument converted to the Objective-C parameter of the same role.
     */
        void set_string_value(const std::string& string, bool resolve) const;
        /**
     * @brief Calls `+[NSXMLNode textWithStringValue:]`.
     * @details \@method textWithStringValue: \@abstract Returns a text node.
     * @param string_value Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static Object text_with_string_value(const std::string& string_value);
        /**
     * @brief Returns the `URI` property of `NSXMLNode`.
     * @details \@abstract Set the URI of this element, attribute, or document. For documents it is the URI of document origin. Getter returns the URI of this element, attribute, or document. For documents it is the URI of document origin and is automatically set when using initWithContentsOfURL.
     * @return The converted Objective-C result.
     */
        std::string uri() const;
        /**
     * @brief Sets the `URI` property of `NSXMLNode`.
     * @details \@abstract Set the URI of this element, attribute, or document. For documents it is the URI of document origin. Getter returns the URI of this element, attribute, or document. For documents it is the URI of document origin and is automatically set when using initWithContentsOfURL.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_uri(const std::string& value) const;
        /**
     * @brief Returns the `XMLString` property of `NSXMLNode`.
     * @details \@abstract The representation of this node as it would appear in an XML document.
     * @return The converted Objective-C result.
     */
        std::string xml_string() const;
        /**
     * @brief Returns the `XPath` property of `NSXMLNode`.
     * @details \@abstract Returns the XPath to this node, for example foo/bar[2]/baz.
     * @return The converted Objective-C result.
     */
        std::string x_path() const;
        /**
     * @brief Returns the `childCount` property of `NSXMLNode`.
     * @details \@abstract The amount of children, relevant for documents, elements, and document type declarations. Use this instead of [[self children] count].
     * @return The converted Objective-C result.
     */
        std::uint64_t child_count() const;
        /**
     * @brief Returns the `children` property of `NSXMLNode`.
     * @details \@abstract An immutable array of child nodes. Relevant for documents, elements, and document type declarations.
     * @return The converted Objective-C result.
     */
        std::vector<XMLNode> children() const;
        /**
     * @brief Returns the `description` property of `NSXMLNode`.
     * @details \@abstract Used for debugging. May give more information than XMLString.
     * @return The converted Objective-C result.
     */
        std::string description() const;
        /**
     * @brief Returns the `index` property of `NSXMLNode`.
     * @details \@abstract A node's index amongst its siblings.
     * @return The converted Objective-C result.
     */
        std::uint64_t index() const;
        /**
     * @brief Returns the `kind` property of `NSXMLNode`.
     * @details \@abstract Returns an element, attribute, entity, or notation DTD node based on the full XML string.
     * @return The converted Objective-C result.
     */
        XMLNodeKind kind() const;
        /**
     * @brief Returns the `level` property of `NSXMLNode`.
     * @details \@abstract The depth of the node within the tree. Documents and standalone nodes are level 0.
     * @return The converted Objective-C result.
     */
        std::uint64_t level() const;
        /**
     * @brief Returns the `localName` property of `NSXMLNode`.
     * @details \@abstract Returns the local name bar if this attribute or element's name is foo:bar
     * @return The converted Objective-C result.
     */
        std::string local_name() const;
        /**
     * @brief Returns the `name` property of `NSXMLNode`.
     * @details \@abstract Sets the nodes name. Applicable for element, attribute, namespace, processing-instruction, document type declaration, element declaration, attribute declaration, entity declaration, and notation declaration.
     * @return The converted Objective-C result.
     */
        std::string name() const;
        /**
     * @brief Sets the `name` property of `NSXMLNode`.
     * @details \@abstract Sets the nodes name. Applicable for element, attribute, namespace, processing-instruction, document type declaration, element declaration, attribute declaration, entity declaration, and notation declaration.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_name(const std::string& value) const;
        /**
     * @brief Returns the `nextNode` property of `NSXMLNode`.
     * @details \@abstract Returns the next node in document order. This can be used to walk the tree forwards.
     * @return The converted Objective-C result.
     */
        XMLNode next_node() const;
        /**
     * @brief Returns the `nextSibling` property of `NSXMLNode`.
     * @details \@abstract Returns the next sibling, or nil if there isn't one.
     * @return The converted Objective-C result.
     */
        XMLNode next_sibling() const;
        /**
     * @brief Returns the `objectValue` property of `NSXMLNode`.
     * @details \@abstract Sets the content of the node. Setting the objectValue removes all existing children including processing instructions and comments. Setting the object value on an element creates a single text node child.
     * @return The converted Objective-C result.
     */
        Object object_value() const;
        /**
     * @brief Sets the `objectValue` property of `NSXMLNode`.
     * @details \@abstract Sets the content of the node. Setting the objectValue removes all existing children including processing instructions and comments. Setting the object value on an element creates a single text node child.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_object_value(const Object& value) const;
        /**
     * @brief Returns the `parent` property of `NSXMLNode`.
     * @details \@abstract The parent of this node. Documents and standalone Nodes have a nil parent; there is not a 1-to-1 relationship between parent and children, eg a namespace cannot be a child but has a parent element.
     * @return The converted Objective-C result.
     */
        XMLNode parent() const;
        /**
     * @brief Returns the `prefix` property of `NSXMLNode`.
     * @details \@abstract Returns the prefix foo if this attribute or element's name if foo:bar
     * @return The converted Objective-C result.
     */
        std::string prefix() const;
        /**
     * @brief Returns the `previousNode` property of `NSXMLNode`.
     * @details \@abstract Returns the previous node in document order. This can be used to walk the tree backwards.
     * @return The converted Objective-C result.
     */
        XMLNode previous_node() const;
        /**
     * @brief Returns the `previousSibling` property of `NSXMLNode`.
     * @details \@abstract Returns the previous sibling, or nil if there isn't one.
     * @return The converted Objective-C result.
     */
        XMLNode previous_sibling() const;
        /**
     * @brief Returns the `rootDocument` property of `NSXMLNode`.
     * @details \@abstract The encompassing document or nil.
     * @return The converted Objective-C result.
     */
        XMLDocument root_document() const;
        /**
     * @brief Returns the `stringValue` property of `NSXMLNode`.
     * @details \@abstract Sets the content of the node. Setting the stringValue removes all existing children including processing instructions and comments. Setting the string value on an element creates a single text node child. The getter returns the string value of the node, which may be either its content or child text nodes, depending on the type of node. Elements are recursed and text nodes concatenated in document order with no intervening spaces.
     * @return The converted Objective-C result.
     */
        std::string string_value() const;
        /**
     * @brief Sets the `stringValue` property of `NSXMLNode`.
     * @details \@abstract Sets the content of the node. Setting the stringValue removes all existing children including processing instructions and comments. Setting the string value on an element creates a single text node child. The getter returns the string value of the node, which may be either its content or child text nodes, depending on the type of node. Elements are recursed and text nodes concatenated in document order with no intervening spaces.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_string_value(const std::string& value) const;
    };
}
