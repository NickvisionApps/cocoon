#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/xml_node.h"
#include "types.h"

namespace cocoon
{
    /**
     * @brief C++ handle for the Objective-C class `NSXMLDTDNode` (Foundation).
     * @details \@class NSXMLDTDNode \@abstract The nodes that are exclusive to a DTD \@discussion Every DTD node has a name. Object value is defined as follows:\<ul> \<li>\<b>Entity declaration\</b> - the string that that entity resolves to eg "&lt;"\</li> \<li>\<b>Attribute declaration\</b> - the default value, if any\</li> \<li>\<b>Element declaration\</b> - the validation string\</li> \<li>\<b>Notation declaration\</b> - no objectValue\</li>\</ul>
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref XMLNode.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLDTDNode xmldtd_node;
     * xmldtd_node.set_dtd_kind(cocoon::XMLDTDNodeKind::EntityGeneralKind);
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLDTDNode xmldtd_node{};
     * xmldtd_node.set_dtd_kind(cocoon::XMLDTDNodeKind::EntityGeneralKind);
     * auto dtd_kind = xmldtd_node.dtd_kind();
     * xmldtd_node.set_notation_name("text");
     * auto notation_name = xmldtd_node.notation_name();
     * xmldtd_node.set_public_id("text");
     * auto public_id = xmldtd_node.public_id();
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmldtdnode
     */
    class XMLDTDNode : public XMLNode
    {
    public:
        /// @brief Creates a new `NSXMLDTDNode` instance and returns a handle to it.
        explicit XMLDTDNode(XMLNodeKind kind, XMLNodeOptions options);
        /// @brief Creates a new `NSXMLDTDNode` instance and returns a handle to it.
        explicit XMLDTDNode(const std::string& string);
        /// @brief Creates a new `NSXMLDTDNode` instance and returns a handle to it.
        explicit XMLDTDNode();
        /// @brief Creates a null handle that refers to no native object.
        XMLDTDNode(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLDTDNode(Adopt adopt);
        /**
         * @brief Returns the `DTDKind` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the DTD sub kind.
         * @return The converted Objective-C result.
         */
        XMLDTDNodeKind dtd_kind() const;
        /**
         * @brief Sets the `DTDKind` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the DTD sub kind.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_dtd_kind(XMLDTDNodeKind value) const;
        /**
         * @brief Returns the `external` property of `NSXMLDTDNode`.
         * @details \@abstract True if the system id is set. Valid for entities and notations.
         * @return The converted Objective-C result.
         */
        bool is_external() const;
        /**
         * @brief Returns the `notationName` property of `NSXMLDTDNode`.
         * @details \@abstract Set the notation name. Valid for entities only.
         * @return The converted Objective-C result.
         */
        std::string notation_name() const;
        /**
         * @brief Sets the `notationName` property of `NSXMLDTDNode`.
         * @details \@abstract Set the notation name. Valid for entities only.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_notation_name(const std::string& value) const;
        /**
         * @brief Returns the `publicID` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the public id. This identifier should be in the default catalog in /etc/xml/catalog or in a path specified by the environment variable XML_CATALOG_FILES. When the public id is set the system id must also be set. Valid for entities and notations.
         * @return The converted Objective-C result.
         */
        std::string public_id() const;
        /**
         * @brief Sets the `publicID` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the public id. This identifier should be in the default catalog in /etc/xml/catalog or in a path specified by the environment variable XML_CATALOG_FILES. When the public id is set the system id must also be set. Valid for entities and notations.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_public_id(const std::string& value) const;
        /**
         * @brief Returns the `systemID` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the system id. This should be a URL that points to a valid DTD. Valid for entities and notations.
         * @return The converted Objective-C result.
         */
        std::string system_id() const;
        /**
         * @brief Sets the `systemID` property of `NSXMLDTDNode`.
         * @details \@abstract Sets the system id. This should be a URL that points to a valid DTD. Valid for entities and notations.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_system_id(const std::string& value) const;
    };
}
