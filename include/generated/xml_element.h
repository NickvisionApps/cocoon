#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/xml_node.h"
#include "types.h"

namespace cocoon
{
    class XMLNode;

    /**
     * @brief C++ handle for the Objective-C class `NSXMLElement` (Foundation).
     * @details The element nodes in an XML tree structure. An ''XMLElement'' object may have child nodes, specifically comment nodes, processing-instruction nodes, text nodes, and other ''XMLElement'' nodes. It may also have attribute nodes and namespace nodes associated with it (however, namespace and attribute nodes are not considered children). Any attempt to add a ''XMLDocument'' node, ''XMLDTD'' node, namespace node, or attribute node as a child raises an exception. If you add a child node to an ''XMLElement'' object and that child already has a parent, ''XMLElement'' raises an exception; the child must be detached or copied first. \#\#\# Subclassing Notes You can subclass 'NSXMLElement' if you want element nodes with more specialized attributes or behavior, for example, paragraph and font attributes that specify how the string value of the element should appear. \#\#\#\# Methods to Override To subclass 'NSXMLElement' you need to override the primary initializer, ''init(name:uri:)'', and the methods listed below. In most cases, you need only invoke the superclass implementation, adding any subclass-specific code before or after the invocation, as necessary. | ''addAttribute(:)'' | ''removeNamespace(forPrefix:)'' | |---|---| | ''removeAttribute(forName:)'' | ''namespaces'' | | ''attributes'' | ''namespaces'' | | ''attribute(forLocalName:uri:)'' | ''insertChild(:at:)'' | | ''attributes'' | ''removeChild(at:)'' | | ''addNamespace(:)'' | ''setChildren(:)'' | 'NSXMLElement' implements \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/isequal(:)> to perform a deep comparison: two ''XMLDocument'' objects are not considered equal unless they have the same name, same child nodes, same attributes, and so on. If you want a different standard of comparison, override 'isEqual:'. \#\#\#\# Special Considerations Because of the architecture and data model of NSXML, when it parses and processes a source of XML it cannot know about your subclass unless you override the class method ''XMLDocument/replacementClass(for:)'' to return your custom class in place of an NSXML class. If your custom class has no direct NSXML counterpart—for example, it is a subclass of 'NSXMLNode' that represents CDATA sections—then you can walk the tree after it has been created and insert the new node where appropriate. Note that you can safely set the root element of the XML document (using the 'NSXMLDocument' ''XMLDocument/setRootElement(:)''method) to be an instance of your subclass because this method only checks to see if the added node is of an element kind ('NSXMLElementKind'). These precautions do not apply, of course, if you are creating an XML tree programmatically.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref XMLNode.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLElement xml_element;
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLElement xml_element{};
     * xml_element.add_attribute(cocoon::XMLNode());
     * xml_element.add_child(cocoon::XMLNode());
     * xml_element.add_namespace(cocoon::XMLNode());
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmlelement
     */
    class XMLElement : public XMLNode
    {
    public:
        /// @brief Creates a new `NSXMLElement` instance and returns a handle to it.
        explicit XMLElement(XMLNodeKind kind, XMLNodeOptions options);
        /// @brief Creates a new `NSXMLElement` instance and returns a handle to it.
        explicit XMLElement(const std::string& name);
        /// @brief Creates a new `NSXMLElement` instance and returns a handle to it.
        explicit XMLElement(const std::string& name, const std::string& uri);
        /// @brief Creates a new `NSXMLElement` instance and returns a handle to it.
        explicit XMLElement();
        /// @brief Creates a null handle that refers to no native object.
        XMLElement(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLElement(Adopt adopt);
        /**
     * @brief Calls `-[NSXMLElement addAttribute:]`.
     * @details Adds an attribute node to the receiver. If the receiver already has an attribute with the same name, \@c attribute replaces the old attribute. The order of multiple attributes is preserved if the \@c NSXMLPreserveAttributeOrder option is specified when the element is created. \@param attribute An XML node object representing an attribute.
     * @param attribute Argument converted to the Objective-C parameter of the same role.
     */
        void add_attribute(const XMLNode& attribute) const;
        /**
     * @brief Calls `-[NSXMLElement addChild:]`.
     * @details Adds a child node at the end of the receiver's current list of children. The new node has an index value that is one greater than the last of the current children. \@param child An XML node object to add to the receiver's children.
     * @param child Argument converted to the Objective-C parameter of the same role.
     */
        void add_child(const XMLNode& child) const;
        /**
     * @brief Calls `-[NSXMLElement addNamespace:]`.
     * @details Adds a namespace node to the receiver. If the receiver already has a namespace with the same name, \@c aNamespace is not added. \@param aNamespace An XML node object of kind \@c NSXMLNamespaceKind.
     * @param a_namespace Argument converted to the Objective-C parameter of the same role.
     */
        void add_namespace(const XMLNode& a_namespace) const;
        /**
     * @brief Calls `-[NSXMLElement attributeForLocalName:URI:]`.
     * @details Returns the attribute node of the receiver that is identified by a local name and URI. \@param localName A string specifying the local name of an attribute. \@param URI A string identifying the URI associated with an attribute. \@return An XML node object representing a matching attribute or \@c nil if no such node was found.
     * @param local_name Argument converted to the Objective-C parameter of the same role.
     * @param uri Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        XMLNode attribute_for_local_name(const std::string& local_name, const std::string& uri) const;
        /**
     * @brief Calls `-[NSXMLElement attributeForName:]`.
     * @details Returns the attribute node of the receiver with the specified name. If \@c name is a qualified name, then this method invokes \@c attributeForLocalName:URI: with the URI parameter set to the URI associated with the prefix. Otherwise comparison is based on string equality of the qualified or non-qualified name. \@param name A string specifying the name of an attribute. \@return An XML node object representing a matching attribute or \@c nil if no such node was found.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        XMLNode attribute_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement elementsForLocalName:URI:]`.
     * @details Returns the child element nodes (as \@c NSXMLElement objects) of the receiver that are matched with the specified local name and URI. \@param localName A string specifying a local name of an element. \@param URI A string specifying a URI associated with an element. \@return An array of \@c NSXMLElement objects or an empty array if no matching children could be found.
     * @param local_name Argument converted to the Objective-C parameter of the same role.
     * @param uri Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<XMLElement> elements_for_local_name(const std::string& local_name, const std::string& uri) const;
        /**
     * @brief Calls `-[NSXMLElement elementsForName:]`.
     * @details Returns the child element nodes (as \@c NSXMLElement objects) of the receiver that have a specified name. If \@c name is a qualified name, then this method invokes \@c elementsForLocalName:URI: with the URI parameter set to the URI associated with the prefix. Otherwise comparison is based on string equality of the qualified or non-qualified name. \@param name A string specifying the name of the child element nodes to find and return. \@return An array of \@c NSXMLElement objects or an empty array if no matching children can be found.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<XMLElement> elements_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement insertChild:atIndex:]`.
     * @details Inserts a new child node at a specified location in the receiver's list of child nodes. Insertion of the node increments the indexes of sibling nodes after it. \@param child An XML node object to be inserted as a child of the receiver. \@param index An integer identifying a position in the receiver's list of children. An exception is raised if \@c index is out of bounds.
     * @param child Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLElement insertChildren:atIndex:]`.
     * @details Inserts an array of child nodes at a specified location in the receiver's list of children. Insertion of the nodes increases the indexes of sibling nodes after them by the count of \@c children. \@param children An array of XML node objects to add as children of the receiver. \@param index An integer identifying a position in the receiver's list of children. An exception is raised if \@c index is out of bounds.
     * @param children Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLElement namespaceForPrefix:]`.
     * @details Returns the namespace node with a specified prefix. \@param name A string specifying a namespace prefix. \@return An \@c NSXMLNode object of kind \@c NSXMLNamespaceKind or \@c nil if there is no namespace node with that prefix.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        XMLNode namespace_for_prefix(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement normalizeAdjacentTextNodesPreservingCDATA:]`.
     * @details Coalesces adjacent text nodes of the receiver that you have explicitly added, optionally including CDATA sections. A text node with a value of an empty string is removed. When you process an input source of XML, adjacent text nodes are automatically normalized. You should invoke this method (with \@c preserve as \@c NO) before using the \@c NSXMLNode methods \@c objectsForXQuery:constants:error: or \@c nodesForXPath:error: . \@param preserve \@c YES if CDATA sections are left alone as text nodes, \@c NO otherwise.
     * @param preserve Argument converted to the Objective-C parameter of the same role.
     */
        void normalize_adjacent_text_nodes_preserving_cdata(bool preserve) const;
        /**
     * @brief Calls `-[NSXMLElement removeAttributeForName:]`.
     * @details Removes an attribute node identified by name. \@param name A string specifying the name of an attribute.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        void remove_attribute_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement removeChildAtIndex:]`.
     * @details Removes the child node of the receiver identified by a given index. The XML node object is released upon removal. The indices of subsequent children are decremented by one. \@param index An integer identifying the node in the receiver's list of children to remove. An exception is raised if \@c index is out of bounds.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_child_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLElement removeNamespaceForPrefix:]`.
     * @details Removes a namespace node that is identified by a given prefix. \@param name A string that is the prefix for a namespace.
     * @param name Argument converted to the Objective-C parameter of the same role.
     */
        void remove_namespace_for_prefix(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement replaceChildAtIndex:withNode:]`.
     * @details Replaces a child node at a specified location with another child node. The replaced XML node object is released upon removal. \@param index An integer identifying a position in the receiver's list of children. An exception is raised if \@c index is out of bounds. \@param node An XML node object that will replace the current child.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param node Argument converted to the Objective-C parameter of the same role.
     */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
     * @brief Calls `-[NSXMLElement resolveNamespaceForName:]`.
     * @details Returns the namespace node with the prefix matching the given qualified name. The method looks in the entire namespace chain for the prefix. \@param name A string that is the qualified name for a namespace (a qualified name is prefix plus local name). \@return An \@c NSXMLNode object of kind \@c NSXMLNamespaceKind or \@c nil if there is no matching namespace node.
     * @param name Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        XMLNode resolve_namespace_for_name(const std::string& name) const;
        /**
     * @brief Calls `-[NSXMLElement resolvePrefixForNamespaceURI:]`.
     * @details Returns the prefix associated with the specified URI. The method looks in the entire namespace chain for the URI. \@param namespaceURI A string identifying the URI associated with the namespace. \@return A string that is the matching prefix or \@c nil if it finds no matching prefix.
     * @param namespace_uri Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::string resolve_prefix_for_namespace_uri(const std::string& namespace_uri) const;
        /**
     * @brief Calls `-[NSXMLElement setAttributesAsDictionary:]`.
     * @details Sets the attributes based on a name-value dictionary. \@deprecated This method is deprecated because it does not function properly. Use \@c setAttributesWithDictionary: instead. \@param attributes A dictionary of key-value pairs where the attribute name is the key and the object value of the attribute is the dictionary value.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributes_as_dictionary(const std::vector<std::pair<Object, Object>>& attributes) const;
        /**
     * @brief Calls `-[NSXMLElement setAttributesWithDictionary:]`.
     * @details Sets the attributes of the receiver based on a name-value dictionary. The method uses these names and object values to create \@c NSXMLNode objects of kind \@c NSXMLAttributeKind. Existing attributes are removed. \@param attributes A dictionary of key-value pairs where the attribute name is the key and the object value of the attribute is the dictionary value.
     * @param attributes Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributes_with_dictionary(const std::map<std::string, std::string>& attributes) const;
        /**
     * @brief Calls `-[NSXMLElement setChildren:]`.
     * @details Removes all existing children and replaces them with the new children. Set \@c children to \@c nil to simply remove all children. \@param children An array of \@c NSXMLElement objects or \@c NSXMLNode objects.
     * @param children Argument converted to the Objective-C parameter of the same role.
     */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
     * @brief Returns the `attributes` property of `NSXMLElement`.
     * @details The attributes of the receiver. In the case of duplicate names, the first attribute with the name is used. To set attributes using an \@c NSDictionary object as the input parameter, see \@c setAttributesWithDictionary: .
     * @return The converted Objective-C result.
     */
        std::vector<XMLNode> attributes() const;
        /**
     * @brief Sets the `attributes` property of `NSXMLElement`.
     * @details The attributes of the receiver. In the case of duplicate names, the first attribute with the name is used. To set attributes using an \@c NSDictionary object as the input parameter, see \@c setAttributesWithDictionary: .
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_attributes(const std::vector<XMLNode>& value) const;
        /**
     * @brief Returns the `namespaces` property of `NSXMLElement`.
     * @details The namespace nodes of the receiver. In the case of duplicate names, the first namespace with the name is used. Set to \@c nil to remove all namespace nodes.
     * @return The converted Objective-C result.
     */
        std::vector<XMLNode> namespaces() const;
        /**
     * @brief Sets the `namespaces` property of `NSXMLElement`.
     * @details The namespace nodes of the receiver. In the case of duplicate names, the first namespace with the name is used. Set to \@c nil to remove all namespace nodes.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_namespaces(const std::vector<XMLNode>& value) const;
    };
}
