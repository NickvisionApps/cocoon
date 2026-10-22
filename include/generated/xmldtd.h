#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/xml_node.h"
#include "types.h"

namespace cocoon
{
    class URL;
    class XMLDTDNode;
    class XMLNode;

    /**
     * @brief C++ handle for the Objective-C class `NSXMLDTD` (Foundation).
     * @details A representation of a Document Type Definition. An instance of the ''XMLDTD'' class is held as a property of an ''XMLDocument'' instance, accessed through the ''XMLDocument'' property ''XMLDocument/dtd''. In the data model, an ''XMLDTD'' object is conceptually similar to namespace and attribute nodes: it is not considered to be a child of the ''XMLDocument'' object although it is closely associated with it. It is at the "root" of a shallow tree consisting primarily of nodes representing DTD declarations. Acceptable child nodes are instances of the ''XMLDTDNode'' class as well as ''XMLNode'' objects representing comment nodes and processing-instruction nodes. You create an 'NSXMLDTD' object in one of three ways: - By processing an XML document with its own internal (in-line) DTD - By process a standalone (external) DTD - Programmatically Once an ''XMLDTD'' instance is in place, you can add, remove, and change the ''XMLDTDNode'' objects representing various DTD declarations. When you write the document out as XML, the new or modified internal DTD is included (assuming you set the DTD in the ''XMLDocument'' instance). You may also programmatically create an external DTD and write that out to its own file.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref XMLNode.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLDTD xmldtd;
     * xmldtd.set_public_id("text");
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLDTD xmldtd{};
     * xmldtd.set_public_id("text");
     * auto public_id = xmldtd.public_id();
     * xmldtd.set_system_id("text");
     * auto system_id = xmldtd.system_id();
     * xmldtd.add_child(cocoon::XMLNode());
     * xmldtd.attribute_declaration_for_name("text", "text");
     * xmldtd.element_declaration_for_name("text");
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmldtd
     */
    class XMLDTD : public XMLNode
    {
    public:
        /// @brief Creates a new `NSXMLDTD` instance and returns a handle to it.
        explicit XMLDTD(const URL& url, XMLNodeOptions mask);
        /// @brief Creates a new `NSXMLDTD` instance and returns a handle to it.
        explicit XMLDTD(const std::vector<std::uint8_t>& data, XMLNodeOptions mask);
        /// @brief Creates a new `NSXMLDTD` instance and returns a handle to it.
        explicit XMLDTD();
        /// @brief Creates a null handle that refers to no native object.
        XMLDTD(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLDTD(Adopt adopt);
        /**
         * @brief Calls `-[NSXMLDTD addChild:]`.
         * @details Adds a child node to the end of the list of existing children. - Parameter child: The node object to add to the existing children.
         * @param child Argument converted to the Objective-C parameter of the same role.
         */
        void add_child(const XMLNode& child) const;
        /**
         * @brief Calls `-[NSXMLDTD attributeDeclarationForName:elementName:]`.
         * @details Returns the DTD node representing an attribute-list declaration for a given attribute and its element. - Parameters: - name: A string object identifying the name of an attribute. - elementName: A string object identifying the name of an element. - Returns: An autoreleased ''XMLDTDNode'' object, or 'nil' if there is no matching attribute-list declaration. For example, in the attribute-list declaration '\<!ATTLIST person idnum CDATA "0000">', "idnum" would correspond to 'attrName' and "person" would correspond to 'elementName'.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param element_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode attribute_declaration_for_name(const std::string& name, const std::string& element_name) const;
        /**
         * @brief Calls `-[NSXMLDTD elementDeclarationForName:]`.
         * @details Returns the DTD node representing an element declaration for a specified element. - Parameter name: A string that is the name of an element. - Returns: An autoreleased ''XMLDTDNode'' object, or 'nil' if there is no match.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode element_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLDTD entityDeclarationForName:]`.
         * @details Returns the DTD node representing the entity declaration matching this name. - Parameter name: A string that is the name of an entity. - Returns: An autoreleased ''XMLDTDNode'' object, or 'nil' if there is no match.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode entity_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLDTD insertChild:atIndex:]`.
         * @details Inserts a child node in the receiver's list of children at a specific location in the list. - Parameters: - child: An XML-node object that represents the child to insert. - index: An integer identifying the location in the receiver's list of children to insert 'child'. The indices of subsequent children in the list are incremented by one.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD insertChildren:atIndex:]`.
         * @details Inserts an array of child nodes at a specified location in the receiver's list of children. - Parameters: - children: An array of ''XMLNode'' objects to insert as children of the receiver. - index: An integer identifying the location in the list of current children to make the insertion. The indices of subsequent children in the list are incremented by the number of inserted children.
         * @param children Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD notationDeclarationForName:]`.
         * @details Returns the DTD node representing the notation declaration identified by the specified notation name. - Parameter name: A string that is the name of a notation. - Returns: An autoreleased ''XMLDTDNode'' object, or 'nil' if there is no match.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode notation_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `+[NSXMLDTD predefinedEntityDeclarationForName:]`.
         * @details Returns a DTD node representing the predefined entity declaration with the specified name. - Parameter name: A string identifying a predefined entity declaration. - Returns: An autoreleased ''XMLDTDNode'' object, or 'nil' if there is no match for 'name'. The five predefined entity references (or character references) are '&lt;' (less-than sign), '&gt;' (greater-than sign), '&amp;' (ampersand), '&quot;' (quotation mark), and '&apos;' (apostrophe).
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static XMLDTDNode predefined_entity_declaration_for_name(const std::string& name);
        /**
         * @brief Calls `-[NSXMLDTD removeChildAtIndex:]`.
         * @details Removes the child node at a particular location in the receiver's list of children. - Parameter index: An integer identifying the child node to remove. The indices of subsequent children in the list are decremented by one. The removed child node is released.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_child_at_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD replaceChildAtIndex:withNode:]`.
         * @details Replaces a child at a particular index with another child. - Parameters: - index: An integer identifying the position of a node in the receiver's list of child nodes. - node: An ''XMLNode'' object to replace the object at 'index'. The replaced child node is released.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param node Argument converted to the Objective-C parameter of the same role.
         */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
         * @brief Calls `-[NSXMLDTD setChildren:]`.
         * @details Removes all existing children of the receiver and replaces them with an array of new child nodes. - Parameter children: An array of ''XMLNode'' objects. To remove all existing children, pass in 'nil'. Replaced or removed child nodes are released.
         * @param children Argument converted to the Objective-C parameter of the same role.
         */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
         * @brief Returns the `publicID` property of `NSXMLDTD`.
         * @details Returns the receiver's public identifier. This identifier should be in the default catalog in '/etc/xml/catalog' or in a path specified by the environment variable 'XML_CATALOG_FILES'. When the public id is set the system id must also be set.
         * @return The converted Objective-C result.
         */
        std::string public_id() const;
        /**
         * @brief Sets the `publicID` property of `NSXMLDTD`.
         * @details Returns the receiver's public identifier. This identifier should be in the default catalog in '/etc/xml/catalog' or in a path specified by the environment variable 'XML_CATALOG_FILES'. When the public id is set the system id must also be set.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_public_id(const std::string& value) const;
        /**
         * @brief Returns the `systemID` property of `NSXMLDTD`.
         * @details Returns the receiver's system identifier. This should be a URL that points to a valid DTD.
         * @return The converted Objective-C result.
         */
        std::string system_id() const;
        /**
         * @brief Sets the `systemID` property of `NSXMLDTD`.
         * @details Returns the receiver's system identifier. This should be a URL that points to a valid DTD.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_system_id(const std::string& value) const;
    };
}
