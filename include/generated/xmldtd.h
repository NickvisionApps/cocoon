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
     * @details \@class NSXMLDTD \@abstract Defines the order, repetition, and allowable values for a document
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
         * @details \@method addChild: \@abstract Adds a child to the end of the existing children.
         * @param child Argument converted to the Objective-C parameter of the same role.
         */
        void add_child(const XMLNode& child) const;
        /**
         * @brief Calls `-[NSXMLDTD attributeDeclarationForName:elementName:]`.
         * @details \@method attributeDeclarationForName: \@abstract Returns the attribute declaration matching this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @param element_name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode attribute_declaration_for_name(const std::string& name, const std::string& element_name) const;
        /**
         * @brief Calls `-[NSXMLDTD elementDeclarationForName:]`.
         * @details \@method elementDeclarationForName: \@abstract Returns the element declaration matching this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode element_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLDTD entityDeclarationForName:]`.
         * @details \@method entityDeclarationForName: \@abstract Returns the entity declaration matching this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode entity_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `-[NSXMLDTD insertChild:atIndex:]`.
         * @details \@method insertChild:atIndex: \@abstract Inserts a child at a particular index.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD insertChildren:atIndex:]`.
         * @details \@method insertChildren:atIndex: \@abstract Insert several children at a particular index.
         * @param children Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD notationDeclarationForName:]`.
         * @details \@method notationDeclarationForName: \@abstract Returns the notation declaration matching this name.
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        XMLDTDNode notation_declaration_for_name(const std::string& name) const;
        /**
         * @brief Calls `+[NSXMLDTD predefinedEntityDeclarationForName:]`.
         * @details \@method predefinedEntityDeclarationForName: \@abstract Returns the predefined entity declaration matching this name. \@discussion The five predefined entities are \<ul>\<li>&amp;lt; - &lt;\</li>\<li>&amp;gt; - &gt;\</li>\<li>&amp;amp; - &amp;\</li>\<li>&amp;quot; - &quot;\</li>\<li>&amp;apos; - &amp;\</li>\</ul>
         * @param name Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static XMLDTDNode predefined_entity_declaration_for_name(const std::string& name);
        /**
         * @brief Calls `-[NSXMLDTD removeChildAtIndex:]`.
         * @details \@method removeChildAtIndex: \@abstract Removes a child at a particular index.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_child_at_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDTD replaceChildAtIndex:withNode:]`.
         * @details \@method replaceChildAtIndex:withNode: \@abstract Replaces a child at a particular index with another child.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param node Argument converted to the Objective-C parameter of the same role.
         */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
         * @brief Calls `-[NSXMLDTD setChildren:]`.
         * @details \@method setChildren: \@abstract Removes all existing children and replaces them with the new children. Set children to nil to simply remove all children.
         * @param children Argument converted to the Objective-C parameter of the same role.
         */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
         * @brief Returns the `publicID` property of `NSXMLDTD`.
         * @details \@abstract Sets the public id. This identifier should be in the default catalog in /etc/xml/catalog or in a path specified by the environment variable XML_CATALOG_FILES. When the public id is set the system id must also be set.
         * @return The converted Objective-C result.
         */
        std::string public_id() const;
        /**
         * @brief Sets the `publicID` property of `NSXMLDTD`.
         * @details \@abstract Sets the public id. This identifier should be in the default catalog in /etc/xml/catalog or in a path specified by the environment variable XML_CATALOG_FILES. When the public id is set the system id must also be set.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_public_id(const std::string& value) const;
        /**
         * @brief Returns the `systemID` property of `NSXMLDTD`.
         * @details \@abstract Sets the system id. This should be a URL that points to a valid DTD.
         * @return The converted Objective-C result.
         */
        std::string system_id() const;
        /**
         * @brief Sets the `systemID` property of `NSXMLDTD`.
         * @details \@abstract Sets the system id. This should be a URL that points to a valid DTD.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_system_id(const std::string& value) const;
    };
}
