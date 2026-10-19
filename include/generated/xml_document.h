#pragma once

#include "generated/availability.h"
#include "generated/enums.h"
#include "generated/structs.h"
#include "generated/xml_node.h"
#include "types.h"

namespace cocoon
{
    class URL;
    class XMLDTD;
    class XMLElement;
    class XMLNode;

    /**
     * @brief C++ handle for the Objective-C class `NSXMLDocument` (Foundation).
     * @details \@class NSXMLDocument \@abstract An XML Document \@discussion Note: if the application of a method would result in more than one element in the children array, an exception is thrown. Trying to add a document, namespace, attribute, or node with a parent also throws an exception. To add a node with a parent first detach or create a copy of it.
     * Handles are cheap, copyable wrappers around a retained native object: copies refer to the same underlying instance.
     * Inherits from @ref XMLNode.
     *
     * @par Example
     * @code
     * #include <cocoon.h>
     *
     * cocoon::XMLDocument xml_document;
     * xml_document.set_dtd(cocoon::XMLDTD());
     * @endcode
     *
     * @par Common tasks
     * Snippets built from this class's own members (values are placeholders).
     * @code
     * cocoon::XMLDocument xml_document{};
     * xml_document.set_dtd(cocoon::XMLDTD());
     * auto dtd = xml_document.dtd();
     * xml_document.set_mime_type("text");
     * auto mime_type = xml_document.mime_type();
     * xml_document.set_character_encoding("text");
     * auto character_encoding = xml_document.character_encoding();
     * xml_document.xml_data_with_options(cocoon::XMLNodeOptions::NodeOptionsNone);
     * xml_document.add_child(cocoon::XMLNode());
     * xml_document.insert_child(cocoon::XMLNode(), 1);
     * @endcode
     * @see https://developer.apple.com/documentation/foundation/nsxmldocument
     */
    class XMLDocument : public XMLNode
    {
    public:
        /// @brief Creates a new `NSXMLDocument` instance and returns a handle to it.
        explicit XMLDocument(const URL& url, XMLNodeOptions mask);
        /// @brief Creates a new `NSXMLDocument` instance and returns a handle to it.
        explicit XMLDocument(const std::vector<std::uint8_t>& data, XMLNodeOptions mask);
        /// @brief Creates a new `NSXMLDocument` instance and returns a handle to it.
        explicit XMLDocument(const XMLElement& element);
        /// @brief Creates a new `NSXMLDocument` instance and returns a handle to it.
        explicit XMLDocument(const std::string& string, XMLNodeOptions mask);
        /// @brief Creates a new `NSXMLDocument` instance and returns a handle to it.
        explicit XMLDocument();
        /// @brief Creates a null handle that refers to no native object.
        XMLDocument(std::nullptr_t);
        /// @brief Wraps an existing retained native object without creating a new one.
        explicit XMLDocument(Adopt adopt);
        /**
     * @brief Calls `-[NSXMLDocument XMLDataWithOptions:]`.
     * @details \@method XMLDataWithOptions: \@abstract The representation of this node as it would appear in an XML document, encoded based on characterEncoding.
     * @param options Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> xml_data_with_options(XMLNodeOptions options) const;
        /**
     * @brief Calls `-[NSXMLDocument addChild:]`.
     * @details \@method addChild: \@abstract Adds a child to the end of the existing children.
     * @param child Argument converted to the Objective-C parameter of the same role.
     */
        void add_child(const XMLNode& child) const;
        /**
     * @brief Calls `-[NSXMLDocument insertChild:atIndex:]`.
     * @details \@method insertChild:atIndex: \@abstract Inserts a child at a particular index.
     * @param child Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLDocument insertChildren:atIndex:]`.
     * @details \@method insertChildren:atIndex: \@abstract Insert several children at a particular index.
     * @param children Argument converted to the Objective-C parameter of the same role.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLDocument objectByApplyingXSLT:arguments:error:]`.
     * @details \@method objectByApplyingXSLT:arguments:error: \@abstract Applies XSLT with arguments (NSString key/value pairs) to this document, returning a new document.
     * @param xslt Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_by_applying_xslt(const std::vector<std::uint8_t>& xslt, const std::map<std::string, std::string>& arguments) const;
        /**
     * @brief Calls `-[NSXMLDocument objectByApplyingXSLTAtURL:arguments:error:]`.
     * @details \@method objectByApplyingXSLTAtURL:arguments:error: \@abstract Applies the XSLT at a URL with arguments (NSString key/value pairs) to this document, returning a new document. Error may contain a connection error from the URL.
     * @param xslt_url Argument converted to the Objective-C parameter of the same role.
     * @param argument Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_by_applying_xslt_at_url(const URL& xslt_url, const std::map<std::string, std::string>& argument) const;
        /**
     * @brief Calls `-[NSXMLDocument objectByApplyingXSLTString:arguments:error:]`.
     * @details \@method objectByApplyingXSLTString:arguments:error: \@abstract Applies XSLT as expressed by a string with arguments (NSString key/value pairs) to this document, returning a new document.
     * @param xslt Argument converted to the Objective-C parameter of the same role.
     * @param arguments Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        Object object_by_applying_xslt_string(const std::string& xslt, const std::map<std::string, std::string>& arguments) const;
        /**
     * @brief Calls `-[NSXMLDocument removeChildAtIndex:]`.
     * @details \@method removeChildAtIndex:atIndex: \@abstract Removes a child at a particular index.
     * @param index Argument converted to the Objective-C parameter of the same role.
     */
        void remove_child_at_index(std::uint64_t index) const;
        /**
     * @brief Calls `-[NSXMLDocument replaceChildAtIndex:withNode:]`.
     * @details \@method replaceChildAtIndex:withNode: \@abstract Replaces a child at a particular index with another child.
     * @param index Argument converted to the Objective-C parameter of the same role.
     * @param node Argument converted to the Objective-C parameter of the same role.
     */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
     * @brief Calls `+[NSXMLDocument replacementClassForClass:]`.
     * @param cls Argument converted to the Objective-C parameter of the same role.
     * @return The converted Objective-C result.
     */
        static std::string replacement_class_for_class(const std::string& cls);
        /**
     * @brief Calls `-[NSXMLDocument rootElement]`.
     * @details \@method rootElement \@abstract The root element.
     * @return The converted Objective-C result.
     */
        XMLElement root_element() const;
        /**
     * @brief Calls `-[NSXMLDocument setChildren:]`.
     * @details \@method setChildren: \@abstract Removes all existing children and replaces them with the new children. Set children to nil to simply remove all children.
     * @param children Argument converted to the Objective-C parameter of the same role.
     */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
     * @brief Calls `-[NSXMLDocument setRootElement:]`.
     * @details \@method setRootElement: \@abstract Set the root element. Removes all other children including comments and processing-instructions.
     * @param root Argument converted to the Objective-C parameter of the same role.
     */
        void set_root_element(const XMLElement& root) const;
        /**
     * @brief Calls `-[NSXMLDocument validateAndReturnError:]`.
     * @return The converted Objective-C result.
     */
        bool validate_and_return_error() const;
        /**
     * @brief Returns the `DTD` property of `NSXMLDocument`.
     * @details \@abstract Set the associated DTD. This DTD will be output with the document.
     * @return The converted Objective-C result.
     */
        XMLDTD dtd() const;
        /**
     * @brief Sets the `DTD` property of `NSXMLDocument`.
     * @details \@abstract Set the associated DTD. This DTD will be output with the document.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_dtd(const XMLDTD& value) const;
        /**
     * @brief Returns the `MIMEType` property of `NSXMLDocument`.
     * @details \@abstract Set the MIME type, eg text/xml.
     * @return The converted Objective-C result.
     */
        std::string mime_type() const;
        /**
     * @brief Sets the `MIMEType` property of `NSXMLDocument`.
     * @details \@abstract Set the MIME type, eg text/xml.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_mime_type(const std::string& value) const;
        /**
     * @brief Returns the `XMLData` property of `NSXMLDocument`.
     * @details \@abstract Invokes XMLDataWithOptions with NSXMLNodeOptionsNone.
     * @return The converted Objective-C result.
     */
        std::vector<std::uint8_t> xml_data() const;
        /**
     * @brief Returns the `characterEncoding` property of `NSXMLDocument`.
     * @details \@abstract Sets the character encoding to an IANA type.
     * @return The converted Objective-C result.
     */
        std::string character_encoding() const;
        /**
     * @brief Sets the `characterEncoding` property of `NSXMLDocument`.
     * @details \@abstract Sets the character encoding to an IANA type.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_character_encoding(const std::string& value) const;
        /**
     * @brief Returns the `documentContentKind` property of `NSXMLDocument`.
     * @details \@abstract The kind of document.
     * @return The converted Objective-C result.
     */
        XMLDocumentContentKind document_content_kind() const;
        /**
     * @brief Sets the `documentContentKind` property of `NSXMLDocument`.
     * @details \@abstract The kind of document.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_document_content_kind(XMLDocumentContentKind value) const;
        /**
     * @brief Returns the `standalone` property of `NSXMLDocument`.
     * @details \@abstract Set whether this document depends on an external DTD. If this option is set the standalone declaration will appear on output.
     * @return The converted Objective-C result.
     */
        bool is_standalone() const;
        /**
     * @brief Sets the `standalone` property of `NSXMLDocument`.
     * @details \@abstract Set whether this document depends on an external DTD. If this option is set the standalone declaration will appear on output.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_standalone(bool value) const;
        /**
     * @brief Returns the `version` property of `NSXMLDocument`.
     * @details \@abstract Sets the XML version. Should be 1.0 or 1.1.
     * @return The converted Objective-C result.
     */
        std::string version() const;
        /**
     * @brief Sets the `version` property of `NSXMLDocument`.
     * @details \@abstract Sets the XML version. Should be 1.0 or 1.1.
     * @param value Argument converted to the Objective-C parameter of the same role.
     */
        void set_version(const std::string& value) const;
    };
}
