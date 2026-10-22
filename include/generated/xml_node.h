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
     * @details The nodes in the abstract, logical tree structure that represents an XML document. Node objects can be of different kinds, corresponding to the following markup constructs in an XML document: element, attribute, text, processing instruction, namespace, and comment. In addition, a document-node object (specifically, an instance of ''XMLDocument'') represents an XML document in its entirety. ''XMLNode'' objects can also represent document type declarations as well as declarations in Document Type Definitions (DTDs). Class factory methods of ''XMLNode'' enable you to create nodes of each kind. Only document, element, and DTD nodes may have child nodes. Among the XML family of classes (excluding ''XMLParser'') the ''XMLNode'' class is the base class. Inheriting from it are the classes ''XMLElement'', ''XMLDocument'', ''XMLDTD'', and ''XMLDTDNode''. ''XMLNode'' specifies the interface common to all XML node objects and defines common node behavior and attributes, for example hierarchy level, node name and value, tree traversal, and the ability to emit representative XML markup text. \#\#\# Subclassing Notes You can subclass ''XMLNode'' if you want nodes of kinds different from the supported ones, You can also create a subclass with more specialized attributes or behavior than ''XMLNode''. \#\#\#\# Methods to Override To subclass ''XMLNode'' you need to override the primary initializer, ''init(kind:options:)'', and the methods listed below. In most cases, you need only invoke the superclass implementation, adding any subclass-specific code before or after the invocation, as necessary. | ''kind'' | ''parent'' | |---|---| | ''name'' | ''child(at:)'' | | ''name'' | ''childCount'' | | ''objectValue'' | ''children'' | | ''objectValue'' | ''detach()'' | | ''stringValue'' | ''localName'' | | ''setStringValue(:resolvingEntities:)'' | ''prefix'' | | ''index'' | ''uri'' | By default ''XMLNode'' implements the 'NSObject' \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/isequal(:)> method to perform a deep comparison: two ''XMLNode'' objects are not considered equal unless they have the same name, same child nodes, same attributes, and so on. The comparison looks at the node and its children, but does not include the node's parent. If you want a different standard of comparison, override 'isEqual:'. \#\#\#\# Special Considerations Because of the architecture and data model of NSXML, when it parses and processes a source of XML it cannot know about your subclass unless you override the ''XMLDocument'' class method ''XMLDocument/replacementClass(for:)'' to return your custom class in place of an NSXML class. If your custom class has no direct NSXML counterpart—for example, it is a subclass of ''XMLNode'' that represents CDATA sections—then you can walk the tree after it has been created and insert the new node where appropriate.
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
         * @details Returns an \@c NSXMLDTDNode object representing the DTD declaration for an element, attribute, entity, or notation based on a given string. \@c NSXMLNode is able to assign the created node object a kind by parsing the string. Note that if an attribute-list declaration (\@c \\\<!ATTLIST...\\>) has multiple attributes, \@c NSXMLNode only creates an \@c NSXMLDTDNode object for the last attribute in the declaration. \@param string A string that is a DTD declaration. The receiver parses this string to determine the kind of DTD node to create.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object dtd_node_with_xml_string(const std::string& string);
        /**
         * @brief Calls `-[NSXMLNode XMLStringWithOptions:]`.
         * @details Returns the string representation of the receiver as it would appear in an XML document, with one or more output options specified. The returned string includes the string representations of all children. \@param options One or more \@c enum constants identifying an output option; bit-OR multiple constants together.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string xml_string_with_options(XMLNodeOptions options) const;
        /**
         * @brief Calls `+[NSXMLNode attributeWithName:URI:stringValue:]`.
         * @details Returns an \@c NSXMLNode object representing an attribute node with a given qualified name and string. For example, in the attribute "bst:id='12345'", "bst" is the name qualifier (derived from the URI), "id" is the attribute name, and "12345" is the attribute value. \@param name A string that is the name of an attribute. \@param URI A URI (Universal Resource Identifier) that qualifies \@c name. \@param stringValue A string that is the value of the attribute.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param uri Argument converted to the Objective-C parameter of the same role.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object attribute_with_name(const std::string& name, const std::string& uri, const std::string& string_value);
        /**
         * @brief Calls `+[NSXMLNode attributeWithName:stringValue:]`.
         * @details Returns an \@c NSXMLNode object representing an attribute node with a given name and string. For example, in the attribute "id='12345'", "id" is the attribute name and "12345" is the attribute value. \@param name A string that is the name of an attribute. \@param stringValue A string that is the value of an attribute.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object attribute_with_name(const std::string& name, const std::string& string_value);
        /**
         * @brief Calls `-[NSXMLNode canonicalXMLStringPreservingComments:]`.
         * @details Returns a string object encapsulating the receiver's XML in canonical form. Be sure to set the input option \@c NSXMLNodePreserveWhitespace for true canonical form. The canonical form of an XML document is defined by the World Wide Web Consortium at http://www.w3.org/TR/xml-c14n. \@param comments \@c YES to preserve comments, \@c NO otherwise.
         * @param comments Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string canonical_xml_string_preserving_comments(bool comments) const;
        /**
         * @brief Calls `-[NSXMLNode childAtIndex:]`.
         * @details Returns the child node of the receiver at the specified location. The receiver should be an \@c NSXMLNode object representing a document, element, or document type declaration. The returned node object can represent an element, comment, text, or processing instruction. \@param index An integer specifying a node position in the receiver's array of children. If \@c index is out of bounds, an exception is raised.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLNode child_at_index(std::uint64_t index) const;
        /**
         * @brief Calls `+[NSXMLNode commentWithStringValue:]`.
         * @details Returns an \@c NSXMLNode object representing a comment node containing given text. \@param stringValue A string specifying the text of the comment. You may specify \@c nil or an empty string.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object comment_with_string_value(const std::string& string_value);
        /**
         * @brief Calls `-[NSXMLNode detach]`.
         * @details Detaches the receiver from its parent node. This method is applicable to \@c NSXMLNode objects representing elements, text, comments, processing instructions, attributes, and namespaces. Once the node object is detached, you can add it as a child node of another parent.
         */
        void detach() const;
        /**
         * @brief Calls `+[NSXMLNode document]`.
         * @details Returns an empty document node. Returns an \@c NSXMLDocument instance without a root element or XML-declaration information (version, encoding, standalone flag). Returns \@c nil if the object couldn't be created.
         * @return The converted Objective-C result.
         */
        static Object document();
        /**
         * @brief Calls `+[NSXMLNode documentWithRootElement:]`.
         * @details Returns an \@c NSXMLDocument object initialized with a given root element. \@param element An \@c NSXMLElement object representing an element.
         * @param element Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object document_with_root_element(const XMLElement& element);
        /**
         * @brief Calls `+[NSXMLNode elementWithName:]`.
         * @details Returns an \@c NSXMLElement object with a given tag identifier, or name. The equivalent XML markup is \@c \\\<name\\>\\\</name\\> . \@param name A string that is the name (or tag identifier) of an element.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object element_with_name(const std::string& name);
        /**
         * @brief Calls `+[NSXMLNode elementWithName:URI:]`.
         * @details Returns an element whose fully qualified name is specified. \@param name A string that is the name (or tag identifier) of an element. \@param URI A URI (Universal Resource Identifier) that qualifies \@c name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param uri Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object element_with_name(const std::string& name, const std::string& uri);
        /**
         * @brief Calls `+[NSXMLNode elementWithName:children:attributes:]`.
         * @details Returns an \@c NSXMLElement object with the given tag (name), attributes, and children. \@param name A string that is the name (tag identifier) of the element. \@param children An array of \@c NSXMLElement objects or \@c NSXMLNode objects. Specify \@c nil if there are no children to add to this node object. \@param attributes An array of \@c NSXMLNode objects of kind \@c NSXMLAttributeKind. Specify \@c nil if there are no attributes to add to this node object.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param children Argument converted to the Objective-C parameter of the same role.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object element_with_name(const std::string& name, const std::vector<XMLNode>& children, const std::vector<XMLNode>& attributes);
        /**
         * @brief Calls `+[NSXMLNode localNameForName:]`.
         * @details Returns the local name from the specified qualified name. For example, if the qualified name is "bst:title", this method returns "title". \@param name A string that is a qualified name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string local_name_for_name(const std::string& name);
        /**
         * @brief Calls `+[NSXMLNode namespaceWithName:stringValue:]`.
         * @details Returns an \@c NSXMLNode object representing a namespace with a specified name and URI. The equivalent namespace declaration in XML markup is \@c xmlns:name="value" . \@param name A string that is the name of the namespace. Specify an empty string for \@c name to get the default namespace. \@param stringValue A string that identifies the URI associated with the namespace.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object namespace_with_name(const std::string& name, const std::string& string_value);
        /**
         * @brief Calls `-[NSXMLNode nodesForXPath:error:]`.
         * @details Returns the nodes resulting from executing an XPath query upon the receiver. The receiver acts as the context item for the query ("."). If you have explicitly added adjacent text nodes as children of an element, you should invoke the \@c NSXMLElement method \@c normalizeAdjacentTextNodesPreservingCDATA: (with an argument of \@c NO) on the element before applying any XPath queries to it; this method coalesces these text nodes. \@param xpath A string that expresses an XPath query. \@param error If query errors occur, indirectly returns an \@c NSError object describing the errors. \@return An array of \@c NSXMLNode objects that match the query, or an empty array if there are no matches.
         * @param xpath Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<XMLNode> nodes_for_x_path(const std::string& xpath) const;
        /**
         * @brief Calls `-[NSXMLNode objectsForXQuery:constants:error:]`.
         * @details Returns the objects resulting from executing an XQuery query upon the receiver. The receiver acts as the context item for the query ("."). If the receiver has been changed after parsing to have multiple adjacent text nodes, you should invoke the \@c NSXMLElement method \@c normalizeAdjacentTextNodesPreservingCDATA: (with an argument of \@c NO) to coalesce the text nodes before querying. \@param xquery A string that expresses an XQuery query. \@param constants A dictionary containing externally declared constants where the name of each constant variable is a key. \@param error If query errors occur, indirectly returns an \@c NSError object describing the errors. \@return An array whose elements are kinds of \@c NSArray, \@c NSData, \@c NSDate, \@c NSNumber, \@c NSString, \@c NSURL, or \@c NSXMLNode.
         * @param xquery Argument converted to the Objective-C parameter of the same role.
         * @param constants Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> objects_for_x_query(const std::string& xquery, const std::map<std::string, Object>& constants) const;
        /**
         * @brief Calls `-[NSXMLNode objectsForXQuery:error:]`.
         * @details Returns the objects resulting from executing an XQuery query upon the receiver. This convenience method invokes \@c objectsForXQuery:constants:error: with \@c nil for the \@c constants dictionary. \@param xquery A string that expresses an XQuery query. \@param error If query errors occur, indirectly returns an \@c NSError object describing the errors.
         * @param xquery Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<Object> objects_for_x_query(const std::string& xquery) const;
        /**
         * @brief Calls `+[NSXMLNode predefinedNamespaceForPrefix:]`.
         * @details Returns an \@c NSXMLNode object representing one of the predefined namespaces with the specified prefix. \@param name A string specifying a prefix for a predefined namespace, for example "xml", "xs", or "xsi". If something other than a predefined-namespace prefix is specified, the method returns \@c nil.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static XMLNode predefined_namespace_for_prefix(const std::string& name);
        /**
         * @brief Calls `+[NSXMLNode prefixForName:]`.
         * @details Returns the prefix from the specified qualified name. For example, if the qualified name is "bst:title", this method returns "bst". \@param name A string that is a qualified name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string prefix_for_name(const std::string& name);
        /**
         * @brief Calls `+[NSXMLNode processingInstructionWithName:stringValue:]`.
         * @details Returns an \@c NSXMLNode object representing a processing instruction with a specified name and value. The equivalent XML markup is \@c \\\<?name\\ value?\\> . \@param name A string that is the name of the processing instruction. \@param stringValue A string that is the value of the processing instruction.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object processing_instruction_with_name(const std::string& name, const std::string& string_value);
        /**
         * @brief Calls `-[NSXMLNode setStringValue:resolvingEntities:]`.
         * @details Sets the content as with \@c setStringValue:, but when \@c resolve is \@c YES, character references, predefined entities and user entities available in the document's DTD are resolved. Entities not available in the DTD remain in their entity form. User-defined entities not declared in the DTD remain in their unresolved form. This method can only be invoked on \@c NSXMLNode objects that may have content. Setting the string value of a node object removes all existing children, including processing instructions and comments. Setting the string value of an element node object creates a text node as the sole child. \@param string A string to assign as the value of the receiver. \@param resolve \@c YES to resolve character references, predefined entities, and user-defined entities as declared in the associated DTD; \@c NO otherwise.
         * @param string Argument converted to the Objective-C parameter of the same role.
         * @param resolve Argument converted to the Objective-C parameter of the same role.
         */
        void set_string_value(const std::string& string, bool resolve) const;
        /**
         * @brief Calls `+[NSXMLNode textWithStringValue:]`.
         * @details Returns an \@c NSXMLNode object representing a text node with specified content. \@param stringValue A string that is the textual content of the node.
         * @param string_value Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static Object text_with_string_value(const std::string& string_value);
        /**
         * @brief Returns the `URI` property of `NSXMLNode`.
         * @details The URI associated with the receiver. A node's URI is derived from its namespace or a document's URI; for documents, the URI comes either from the parsed XML or is explicitly set. You cannot change the URI for a particular node other than for a namespace or document node.
         * @return The converted Objective-C result.
         */
        std::string uri() const;
        /**
         * @brief Sets the `URI` property of `NSXMLNode`.
         * @details The URI associated with the receiver. A node's URI is derived from its namespace or a document's URI; for documents, the URI comes either from the parsed XML or is explicitly set. You cannot change the URI for a particular node other than for a namespace or document node.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_uri(const std::string& value) const;
        /**
         * @brief Returns the `XMLString` property of `NSXMLNode`.
         * @details The string representation of the receiver as it would appear in an XML document. The returned string includes the string representations of all children. This property invokes \@c XMLStringWithOptions: with an \@c options argument of \@c NSXMLNodeOptionsNone.
         * @return The converted Objective-C result.
         */
        std::string xml_string() const;
        /**
         * @brief Returns the `XPath` property of `NSXMLNode`.
         * @details The XPath expression identifying the receiver's location in the document tree. For example, this property might return a string such as "foo/bar[2]/baz". The result of this property can be used directly in the \@c nodesForXPath:error: and \@c objectsForXQuery:constants:error: methods.
         * @return The converted Objective-C result.
         */
        std::string x_path() const;
        /**
         * @brief Returns the `childCount` property of `NSXMLNode`.
         * @details The number of child nodes the receiver has. The receiver should be an \@c NSXMLNode object representing a document, element, or document type declaration. For performance reasons, use this property instead of getting the count from the array returned by \@c children.
         * @return The converted Objective-C result.
         */
        std::uint64_t child_count() const;
        /**
         * @brief Returns the `children` property of `NSXMLNode`.
         * @details An immutable array containing the child nodes of the receiver (as \@c NSXMLNode objects).
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
         * @details The index of the receiver identifying its position relative to its sibling nodes. The first child node of a parent has an index of zero.
         * @return The converted Objective-C result.
         */
        std::uint64_t index() const;
        /**
         * @brief Returns the `kind` property of `NSXMLNode`.
         * @details Returns the kind of node the receiver is as a constant of type \@c NSXMLNodeKind. \@c NSXMLNode objects can represent documents, elements, attributes, namespaces, text, processing instructions, comments, document type declarations, and specific declarations within DTDs.
         * @return The converted Objective-C result.
         */
        XMLNodeKind kind() const;
        /**
         * @brief Returns the `level` property of `NSXMLNode`.
         * @details The nesting level of the receiver within the tree hierarchy. The root element of a document has a nesting level of one.
         * @return The converted Objective-C result.
         */
        std::uint64_t level() const;
        /**
         * @brief Returns the `localName` property of `NSXMLNode`.
         * @details The local name of the receiver. The local name is the part of a node name that follows a namespace-qualifying colon or the full name if there is no colon. For example, "chapter" is the local name in the qualified name "acme:chapter".
         * @return The converted Objective-C result.
         */
        std::string local_name() const;
        /**
         * @brief Returns the `name` property of `NSXMLNode`.
         * @details The name of the receiver. This property is applicable only to \@c NSXMLNode objects representing elements, attributes, namespaces, processing instructions, and DTD-declaration nodes. If the receiver is not an object of one of these kinds, this property returns \@c nil. If the name is associated with a namespace, the qualified name is returned.
         * @return The converted Objective-C result.
         */
        std::string name() const;
        /**
         * @brief Sets the `name` property of `NSXMLNode`.
         * @details The name of the receiver. This property is applicable only to \@c NSXMLNode objects representing elements, attributes, namespaces, processing instructions, and DTD-declaration nodes. If the receiver is not an object of one of these kinds, this property returns \@c nil. If the name is associated with a namespace, the qualified name is returned.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_name(const std::string& value) const;
        /**
         * @brief Returns the `nextNode` property of `NSXMLNode`.
         * @details The next \@c NSXMLNode object in document order. You use this property to "walk" forward through the tree structure representing an XML document or document section. Document order is the natural order that XML constructs appear in markup text. If you send this message to the last node in the tree, \@c nil is returned. \@c NSXMLNode bypasses namespace and attribute nodes when it traverses a tree in document order.
         * @return The converted Objective-C result.
         */
        XMLNode next_node() const;
        /**
         * @brief Returns the `nextSibling` property of `NSXMLNode`.
         * @details The next \@c NSXMLNode object that is a sibling node to the receiver. This object will have an index value that is one more than the receiver's. If there are no more subsequent siblings (that is, other child nodes of the receiver's parent) the property returns \@c nil.
         * @return The converted Objective-C result.
         */
        XMLNode next_sibling() const;
        /**
         * @brief Returns the `objectValue` property of `NSXMLNode`.
         * @details The object value of the receiver. The object value may be the same as the value returned by \@c stringValue. For nodes without content (for example, document nodes), this property returns the string value, or an empty string if there is no string value.
         * @return The converted Objective-C result.
         */
        Object object_value() const;
        /**
         * @brief Sets the `objectValue` property of `NSXMLNode`.
         * @details The object value of the receiver. The object value may be the same as the value returned by \@c stringValue. For nodes without content (for example, document nodes), this property returns the string value, or an empty string if there is no string value.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_object_value(const Object& value) const;
        /**
         * @brief Returns the `parent` property of `NSXMLNode`.
         * @details The parent node of the receiver. Document nodes and standalone nodes (that is, the root of a detached branch of a tree) have no parent, and sending this message to them returns \@c nil. A one-to-one relationship does not always exist between a parent and its children; although a namespace or attribute node cannot be a child, it still has a parent element.
         * @return The converted Objective-C result.
         */
        XMLNode parent() const;
        /**
         * @brief Returns the `prefix` property of `NSXMLNode`.
         * @details The prefix of the receiver's name. The prefix is the part of a namespace-qualified name that precedes the colon. For example, "acme" is the prefix in the qualified name "acme:chapter". Returns an empty string if the receiver's name is not qualified by a namespace.
         * @return The converted Objective-C result.
         */
        std::string prefix() const;
        /**
         * @brief Returns the `previousNode` property of `NSXMLNode`.
         * @details The previous \@c NSXMLNode object in document order. You use this property to "walk" backward through the tree structure representing an XML document or document section. Document order is the natural order that XML constructs appear in markup text. If you send this message to the first node in the tree (that is, the root element), \@c nil is returned. \@c NSXMLNode bypasses namespace and attribute nodes when it traverses a tree in document order.
         * @return The converted Objective-C result.
         */
        XMLNode previous_node() const;
        /**
         * @brief Returns the `previousSibling` property of `NSXMLNode`.
         * @details The previous \@c NSXMLNode object that is a sibling node to the receiver. This object will have an index value that is one less than the receiver's. If there are no more previous siblings (that is, other child nodes of the receiver's parent) the property returns \@c nil.
         * @return The converted Objective-C result.
         */
        XMLNode previous_sibling() const;
        /**
         * @brief Returns the `rootDocument` property of `NSXMLNode`.
         * @details The \@c NSXMLDocument object containing the root element and representing the XML document as a whole. If the receiver is a standalone node (that is, a node at the head of a detached branch of the tree), this property returns \@c nil.
         * @return The converted Objective-C result.
         */
        XMLDocument root_document() const;
        /**
         * @brief Returns the `stringValue` property of `NSXMLNode`.
         * @details The content of the receiver as a string value. If the receiver is a node object of element kind, the content is that of any text-node children. This method recursively visits element nodes and concatenates their text nodes in document order with no intervening spaces.
         * @return The converted Objective-C result.
         */
        std::string string_value() const;
        /**
         * @brief Sets the `stringValue` property of `NSXMLNode`.
         * @details The content of the receiver as a string value. If the receiver is a node object of element kind, the content is that of any text-node children. This method recursively visits element nodes and concatenates their text nodes in document order with no intervening spaces.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_string_value(const std::string& value) const;
    };
}
