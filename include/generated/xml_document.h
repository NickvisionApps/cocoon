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
     * @details An XML document as internalized into a logical tree structure. An ''XMLDocument'' object can have multiple child nodes but only one element, the root element. Any other node must be a ''XMLNode'' object representing a comment or a processing instruction. If you attempt to add any other kind of child node to an ''XMLDocument'' object, such as an attribute, namespace, another document object, or an element other than the root, ''XMLDocument'' raises an exception. If you add a valid child node and that object already has a parent, ''XMLDocument'' raises an exception. An ''XMLDocument'' object may also have document-global attributes, such as XML version, character encoding, referenced DTD, and MIME type. The initializers of the ''XMLDocument'' class read an external source of XML, whether it be a local file or remote website, parse it, and process it into the tree representation. You can also construct an ''XMLDocument'' programmatically. There are accessor methods for getting and setting document attributes, methods for transforming documents using XSLT, a method for dynamically validating a document, and methods for printing out the content of an ''XMLDocument'' as XML, XHTML, HTML, or plain text. The ''XMLDocument'' class is thread-safe as long as any given instance is used only in one thread. \#\#\# Subclassing Notes \#\#\#\# Methods to Override To subclass 'NSXMLDocument' you need to override the primary initializer, ''init(data:options:)'', and the methods listed below. In most cases, you need only invoke the superclass implementation, adding any subclass-specific code before or after the invocation, as necessary. - ''rootElement()'' - ''setChildren(:)'' - ''removeChild(at:)'' - ''insertChild(:at:)'' - ''characterEncoding'' - ''characterEncoding'' - ''documentContentKind'' - ''documentContentKind'' - ''dtd'' - ''mimeType'' - ''isStandalone'' - ''version'' - ''version'' By default 'NSXMLDocument' implements the 'NSObject' \<doc://com.apple.documentation/documentation/objectivec/nsobjectprotocol/isequal(:)> method to perform a deep comparison: two 'NSXMLDocument' objects are not considered equal unless they have the same name, same child nodes, same attributes, and so on. The comparison does not consider the parent node (and hence the node's location). If you want a different standard of comparison, override 'isEqual:'. \#\#\#\# Special Considerations Because of the architecture and data model of NSXML, when it parses and processes a source of XML it cannot know about your subclass unless you override the class method ''replacementClass(for:)'' to return your custom class in place of an 'NSXML' class. If your custom class has no direct 'NSXML' counterpart—for example, it is a subclass of 'NSXMLNode' that represents CDATA sections—then you can walk the tree after it has been created and insert the new node where appropriate.
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
         * @details Returns the XML string representation of the receiver—that is, the entire document—encapsulated in a data object. The encoding used is based on the value returned from \@c characterEncoding. \@param options One or more options (bit-OR'd if multiple) to affect the output of the document.
         * @param options Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> xml_data_with_options(XMLNodeOptions options) const;
        /**
         * @brief Calls `-[NSXMLDocument addChild:]`.
         * @details Adds a child node after the last of the receiver's existing children. \@param child The \@c NSXMLNode object to be added.
         * @param child Argument converted to the Objective-C parameter of the same role.
         */
        void add_child(const XMLNode& child) const;
        /**
         * @brief Calls `-[NSXMLDocument insertChild:atIndex:]`.
         * @details Inserts a node object at a specified position in the receiver's array of children. \@param child The \@c NSXMLNode object to be inserted. The added node must represent a comment, processing instruction, or the root element. \@param index An integer specifying the index of the children array to insert \@c child. The indexes of children after the new child are incremented. If \@c index is out of bounds, an exception is raised.
         * @param child Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_child(const XMLNode& child, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDocument insertChildren:atIndex:]`.
         * @details Inserts an array of children at a specified position in the receiver's array of children. \@param children An array of \@c NSXMLNode objects representing comments, processing instructions, or the root element. \@param index An integer identifying the location in the receiver's children array for insertion. If \@c index is out of bounds, an exception is raised.
         * @param children Argument converted to the Objective-C parameter of the same role.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDocument objectByApplyingXSLT:arguments:error:]`.
         * @details Applies the XSLT pattern rules and templates (specified as a data object) to the receiver and returns a document object containing transformed XML or HTML markup. Depending on intended output, the method returns an \@c NSXMLDocument object or an \@c NSData object containing transformed XML or HTML markup. \@param xslt A data object containing the XSLT pattern rules and templates. \@param arguments A dictionary containing \@c NSString key-value pairs that are passed as runtime parameters to the XSLT processor. Pass in \@c nil if you have no parameters to pass. \@param error If an error occurs, indirectly returns an \@c NSError object encapsulating error or warning messages generated by XSLT processing.
         * @param xslt Argument converted to the Objective-C parameter of the same role.
         * @param arguments Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_by_applying_xslt(const std::vector<std::uint8_t>& xslt, const std::map<std::string, std::string>& arguments) const;
        /**
         * @brief Calls `-[NSXMLDocument objectByApplyingXSLTAtURL:arguments:error:]`.
         * @details Applies the XSLT pattern rules and templates located at a specified URL to the receiver and returns a document object containing transformed XML markup. Depending on intended output, the method returns an \@c NSXMLDocument object or an \@c NSData object containing transformed XML or HTML markup. \@param xsltURL An \@c NSURL object specifying a valid URL. \@param argument A dictionary containing \@c NSString key-value pairs that are passed as runtime parameters to the XSLT processor. Pass in \@c nil if you have no parameters to pass. \@param error If an error occurs, indirectly returns an \@c NSError object encapsulating error or warning messages generated by XSLT processing or from an attempt to connect to a website identified by the URL.
         * @param xslt_url Argument converted to the Objective-C parameter of the same role.
         * @param argument Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_by_applying_xslt_at_url(const URL& xslt_url, const std::map<std::string, std::string>& argument) const;
        /**
         * @brief Calls `-[NSXMLDocument objectByApplyingXSLTString:arguments:error:]`.
         * @details Applies the XSLT pattern rules and templates (specified as a string) to the receiver and returns a document object containing transformed XML or HTML markup. Depending on intended output, the method returns an \@c NSXMLDocument object or an \@c NSData object containing transformed XML or HTML markup. \@param xslt A string object containing the XSLT pattern rules and templates. \@param arguments A dictionary containing \@c NSString key-value pairs that are passed as runtime parameters to the XSLT processor. Pass in \@c nil if you have no parameters to pass. \@param error If an error occurs, indirectly returns an \@c NSError object encapsulating error or warning messages generated by XSLT processing.
         * @param xslt Argument converted to the Objective-C parameter of the same role.
         * @param arguments Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        Object object_by_applying_xslt_string(const std::string& xslt, const std::map<std::string, std::string>& arguments) const;
        /**
         * @brief Calls `-[NSXMLDocument removeChildAtIndex:]`.
         * @details Removes the child node of the receiver located at a specified position in its array of children. Subsequent children have their indexes decreased by one. The removed \@c NSXMLNode object is autoreleased. \@param index An integer identifying the position of a child in the receiver's array. If \@c index is out of bounds, an exception is raised.
         * @param index Argument converted to the Objective-C parameter of the same role.
         */
        void remove_child_at_index(std::uint64_t index) const;
        /**
         * @brief Calls `-[NSXMLDocument replaceChildAtIndex:withNode:]`.
         * @details Replaces the child node of the receiver located at a specified position with another node. The removed \@c NSXMLNode object is autoreleased. \@param index An integer identifying a position in the receiver's array of children. If \@c index is out of bounds, an exception is raised. \@param node An \@c NSXMLNode object to replace the one at \@c index; it must represent a comment, a processing instruction, or the root element.
         * @param index Argument converted to the Objective-C parameter of the same role.
         * @param node Argument converted to the Objective-C parameter of the same role.
         */
        void replace_child_at_index(std::uint64_t index, const XMLNode& node) const;
        /**
         * @brief Calls `+[NSXMLDocument replacementClassForClass:]`.
         * @details Overridden by subclasses to substitute a custom class for an NSXML class that the parser uses to create node instances. This method is invoked before a document is parsed. The substituted class must be a subclass of \@c NSXMLNode, \@c NSXMLDocument, \@c NSXMLElement, \@c NSXMLDTD, or \@c NSXMLDTDNode. \@param cls A \@c Class object identifying an NSXML class that is to be replaced by your custom class. \@return The substituted class.
         * @param cls Argument converted to the Objective-C parameter of the same role.
         * @return The converted Objective-C result.
         */
        static std::string replacement_class_for_class(const std::string& cls);
        /**
         * @brief Calls `-[NSXMLDocument rootElement]`.
         * @details Returns the root element of the receiver.
         * @return The converted Objective-C result.
         */
        XMLElement root_element() const;
        /**
         * @brief Calls `-[NSXMLDocument setChildren:]`.
         * @details Sets the child nodes of the receiver. Each of these objects must represent comments, processing instructions, or the root element; otherwise, an exception is raised. Pass in \@c nil to remove all children. \@param children An array of \@c NSXMLNode objects.
         * @param children Argument converted to the Objective-C parameter of the same role.
         */
        void set_children(const std::vector<XMLNode>& children) const;
        /**
         * @brief Calls `-[NSXMLDocument setRootElement:]`.
         * @details Sets the root element of the receiver. As a side effect, this method removes all other children, including \@c NSXMLNode objects representing comments and processing-instructions. \@param root An \@c NSXMLElement object that is to be the root element.
         * @param root Argument converted to the Objective-C parameter of the same role.
         */
        void set_root_element(const XMLElement& root) const;
        /**
         * @brief Calls `-[NSXMLDocument validateAndReturnError:]`.
         * @details Validates the document against the governing schema and returns whether the document conforms to the schema. If the schema is defined with a DTD, this method uses the \@c NSXMLDTD object set for the receiver for validation. If the schema is based on XML Schema, the method uses the URL specified as the value of the \@c xsi:schemaLocation attribute of the root element. You can validate an XML document when it is first processed by specifying the \@c NSXMLDocumentValidate option in the initializer methods. \@param error If validation fails, on return contains an \@c NSError object describing the reason or reasons for failure.
         * @return The converted Objective-C result.
         */
        bool validate_and_return_error() const;
        /**
         * @brief Returns the `DTD` property of `NSXMLDocument`.
         * @details The internal DTD associated with the receiver. Returns an \@c NSXMLDTD object representing the internal DTD associated with the receiver or \@c nil if no DTD has been associated. This DTD will be output with the document.
         * @return The converted Objective-C result.
         */
        XMLDTD dtd() const;
        /**
         * @brief Sets the `DTD` property of `NSXMLDocument`.
         * @details The internal DTD associated with the receiver. Returns an \@c NSXMLDTD object representing the internal DTD associated with the receiver or \@c nil if no DTD has been associated. This DTD will be output with the document.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_dtd(const XMLDTD& value) const;
        /**
         * @brief Returns the `MIMEType` property of `NSXMLDocument`.
         * @details The MIME type for the receiver (for example, "text/xml").
         * @return The converted Objective-C result.
         */
        std::string mime_type() const;
        /**
         * @brief Sets the `MIMEType` property of `NSXMLDocument`.
         * @details The MIME type for the receiver (for example, "text/xml").
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_mime_type(const std::string& value) const;
        /**
         * @brief Returns the `XMLData` property of `NSXMLDocument`.
         * @details The XML string representation of the receiver—that is, the entire document—encapsulated in a data object. This property invokes \@c XMLDataWithOptions: with an option of \@c NSXMLNodeOptionsNone. The encoding used is based on the value returned from \@c characterEncoding or UTF-8 if no valid encoding is returned.
         * @return The converted Objective-C result.
         */
        std::vector<std::uint8_t> xml_data() const;
        /**
         * @brief Returns the `characterEncoding` property of `NSXMLDocument`.
         * @details The character encoding of the receiver. The encoding must match the name of an IANA character set. Typically the encoding is specified in the XML declaration of a document that is processed, but it can be set at any time. If the specified encoding does not match the actual encoding, parsing of the document might fail.
         * @return The converted Objective-C result.
         */
        std::string character_encoding() const;
        /**
         * @brief Sets the `characterEncoding` property of `NSXMLDocument`.
         * @details The character encoding of the receiver. The encoding must match the name of an IANA character set. Typically the encoding is specified in the XML declaration of a document that is processed, but it can be set at any time. If the specified encoding does not match the actual encoding, parsing of the document might fail.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_character_encoding(const std::string& value) const;
        /**
         * @brief Returns the `documentContentKind` property of `NSXMLDocument`.
         * @details The kind of output content for the receiver. Most of the differences among document-content kind have to do with the handling of content-less tags such as \@c \\\<br\\> .
         * @return The converted Objective-C result.
         */
        XMLDocumentContentKind document_content_kind() const;
        /**
         * @brief Sets the `documentContentKind` property of `NSXMLDocument`.
         * @details The kind of output content for the receiver. Most of the differences among document-content kind have to do with the handling of content-less tags such as \@c \\\<br\\> .
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_document_content_kind(XMLDocumentContentKind value) const;
        /**
         * @brief Returns the `standalone` property of `NSXMLDocument`.
         * @details A Boolean value that specifies whether the receiver represents a standalone XML document. A standalone document does not have an external DTD associated with it. If this option is set the standalone declaration will appear on output.
         * @return The converted Objective-C result.
         */
        bool is_standalone() const;
        /**
         * @brief Sets the `standalone` property of `NSXMLDocument`.
         * @details A Boolean value that specifies whether the receiver represents a standalone XML document. A standalone document does not have an external DTD associated with it. If this option is set the standalone declaration will appear on output.
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_standalone(bool value) const;
        /**
         * @brief Returns the `version` property of `NSXMLDocument`.
         * @details The version of the receiver's XML. Currently, the version should be either "1.0" or "1.1".
         * @return The converted Objective-C result.
         */
        std::string version() const;
        /**
         * @brief Sets the `version` property of `NSXMLDocument`.
         * @details The version of the receiver's XML. Currently, the version should be either "1.0" or "1.1".
         * @param value Argument converted to the Objective-C parameter of the same role.
         */
        void set_version(const std::string& value) const;
    };
}
