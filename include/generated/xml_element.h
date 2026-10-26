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
     * @details \@class NSXMLElement \@abstract An XML element \@discussion Note: Trying to add a document, namespace, attribute, or node with a parent throws an exception. To add a node with a parent first detach or create a copy of it.
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
         * @details \@method addAttribute: \@abstract Adds an attribute. Attributes with duplicate names are not added.
         * @param attribute Argument converted to the Objective-C parameter of the same role.
         */
        void add_attribute(const XMLNode& attribute) const;
        /**
         * @brief Calls `-[NSXMLElement addChild:]`.
         * @details \@method addChild: \@abstract Adds a child to the end of the existing children.
         * @param child Argument converted to the Objective-C parameter of the same role.
         */
        void add_child(const XMLNode& child) const;
        /**
         * @brief Calls `-[NSXMLElement addNamespace:]`.
         * @details \@method addNamespace:URI: \@abstract Adds a namespace. Namespaces with duplicate names are not added.
         * @param a_namespace Argument converted to the Objective-C parameter of the same role.
         */
        void add_namespace(const XMLNode& a_namespace) const;
        /**
         * @brief Calls `-[NSXMLElement attributeForLocalName:URI:]`.
         * @details \@method attributeForLocalName:URI: \@abstract Returns an attribute matching this localname URI pair.
         * @param local_name Argument converted to the Objective-C parameter of the same role.
         * @param uri Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLNode attribute_for_local_name(const std::string& local_name, const std::string& uri) const;
        /**
         * @brief Calls `-[NSXMLElement attributeForName:]`.
         * @details \@method attributeForName: \@abstract Returns an attribute matching this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLNode attribute_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement elementsForLocalName:URI:]`.
         * @details \@method elementsForLocalName:URI \@abstract Returns all of the child elements that match this localname URI pair.
         * @param local_name Argument converted to the Objective-C parameter of the same role.
         * @param uri Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<XMLElement> elements_for_local_name(const std::string& local_name, const std::string& uri) const;
        /**
         * @brief Calls `-[NSXMLElement elementsForName:]`.
         * @details \@method elementsForName: \@abstract Returns all of the child elements that match this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<XMLElement> elements_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement insertChild:atIndex:]`.
         * @details \@method insertChild:atIndex: \@abstract Inserts a child at a particular index.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLElement insertChildren:atIndex:]`.
         * @details \@method insertChildren:atIndex: \@abstract Insert several children at a particular index.
         * @param children Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLElement namespaceForPrefix:]`.
         * @details \@method namespaceForPrefix: \@abstract Returns the namespace matching this prefix.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLNode namespace_for_prefix(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement normalizeAdjacentTextNodesPreservingCDATA:]`.
         * @details \@method normalizeAdjacentTextNodesPreservingCDATA: \@abstract Adjacent text nodes are coalesced. If the node's value is the empty string, it is removed. This should be called with a value of NO before using XQuery or XPath.
         * @param preserve Argument converted to the Objective-C parameter of the same role.
         */
        void normalize_adjacent_text_nodes_preserving_cdata(bool preserve) const;
        /**
         * @brief Calls `-[NSXMLElement removeAttributeForName:]`.
         * @details \@method removeAttributeForName: \@abstract Removes an attribute based on its name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_attribute_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement removeChildAtIndex:]`.
         * @details \@method removeChildAtIndex:atIndex: \@abstract Removes a child at a particular index.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_child_at_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLElement removeNamespaceForPrefix:]`.
         * @details \@method addNamespace:URI: \@abstract Removes a namespace with a particular name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         */
        void remove_namespace_for_prefix(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement replaceChildAtIndex:withNode:]`.
         * @details \@method replaceChildAtIndex:withNode: \@abstract Replaces a child at a particular index with another child.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param node Argument converted to the Objective-C parameter of the same role.
         */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
         * @brief Calls `-[NSXMLElement resolveNamespaceForName:]`.
         * @details \@method resolveNamespaceForName: \@abstract Returns the namespace who matches the prefix of the name given. Looks in the entire namespace chain.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLNode resolve_namespace_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLElement resolvePrefixForNamespaceURI:]`.
         * @details \@method resolvePrefixForNamespaceURI: \@abstract Returns the URI of this prefix. Looks in the entire namespace chain.
         * @param namespace_uri Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::string resolve_prefix_for_namespace_uri(const std::string& namespace_uri) const;
        /**
         * @brief Calls `-[NSXMLElement setAttributesAsDictionary:]`.
         * @details \@method setAttributesAsDictionary: \@abstract Set the attributes base on a name-value dictionary. \@discussion This method is deprecated and does not function correctly. Use -setAttributesWithDictionary: instead.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributes_as_dictionary(const std::vector<std::pair<Object, Object>>& attributes) const;
        /**
         * @brief Calls `-[NSXMLElement setAttributesWithDictionary:]`.
         * @details \@method setAttributesWithDictionary: \@abstract Set the attributes based on a name-value dictionary.
         * @param attributes Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributes_with_dictionary(const std::map<std::string, std::string>& attributes) const;
        /**
         * @brief Calls `-[NSXMLElement setChildren:]`.
         * @details \@method setChildren: \@abstract Removes all existing children and replaces them with the new children. Set children to nil to simply remove all children.
         * @param children Argument converted to the Objective-C parameter of the same role.
         */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
         * @brief Returns the `attributes` property of `NSXMLElement`.
         * @details \@abstract Set the attributes. In the case of duplicate names, the first attribute with the name is used.
         * @return The converted Objective-C result.
         */
        std::vector<XMLNode> attributes() const;
        /**
         * @brief Sets the `attributes` property of `NSXMLElement`.
         * @details \@abstract Set the attributes. In the case of duplicate names, the first attribute with the name is used.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_attributes(const std::vector<XMLNode>& value) const;
        /**
         * @brief Returns the `namespaces` property of `NSXMLElement`.
         * @details \@abstract Set the namespaces. In the case of duplicate names, the first namespace with the name is used.
         * @return The converted Objective-C result.
         */
        std::vector<XMLNode> namespaces() const;
        /**
         * @brief Sets the `namespaces` property of `NSXMLElement`.
         * @details \@abstract Set the namespaces. In the case of duplicate names, the first namespace with the name is used.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_namespaces(const std::vector<XMLNode>& value) const;
    };
}
