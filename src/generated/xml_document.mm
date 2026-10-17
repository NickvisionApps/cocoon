#include "generated/xml_document.h"
#include "internal.h"

namespace cocoon
{
    XMLDocument::XMLDocument(const URL& url, XMLNodeOptions mask) : XMLDocument(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                               {
                                                                                                                   NSError* __error = nil;
                                                                                                                   id __r = [[::NSXMLDocument alloc] initWithContentsOfURL:cocoon::internal::native<::NSURL>(url) options:static_cast<::NSXMLNodeOptions>(mask) error:&__error];
                                                                                                                   if (!__r && __error)
                                                                                                                   {
                                                                                                                       throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                   }
                                                                                                                   return __r;
                                                                                                               }())})
    {
    }

    XMLDocument::XMLDocument(const std::vector<std::uint8_t>& data, XMLNodeOptions mask) : XMLDocument(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                                      {
                                                                                                                                          NSError* __error = nil;
                                                                                                                                          id __r = [[::NSXMLDocument alloc] initWithData:cocoon::internal::to_data(data) options:static_cast<::NSXMLNodeOptions>(mask) error:&__error];
                                                                                                                                          if (!__r && __error)
                                                                                                                                          {
                                                                                                                                              throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                                          }
                                                                                                                                          return __r;
                                                                                                                                      }())})
    {
    }

    XMLDocument::XMLDocument(const XMLElement& element) : XMLDocument(Adopt{cocoon::internal::retain([[::NSXMLDocument alloc] initWithRootElement:cocoon::internal::native<::NSXMLElement>(element)])})
    {
    }

    XMLDocument::XMLDocument(const std::string& string, XMLNodeOptions mask) : XMLDocument(Adopt{cocoon::internal::retain([&]() -> id
                                                                                                                          {
                                                                                                                              NSError* __error = nil;
                                                                                                                              id __r = [[::NSXMLDocument alloc] initWithXMLString:cocoon::internal::to(string) options:static_cast<::NSXMLNodeOptions>(mask) error:&__error];
                                                                                                                              if (!__r && __error)
                                                                                                                              {
                                                                                                                                  throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                                              }
                                                                                                                              return __r;
                                                                                                                          }())})
    {
    }

    XMLDocument::XMLDocument() : XMLDocument(Adopt{cocoon::internal::retain([[::NSXMLDocument alloc] init])})
    {
    }

    XMLDocument::XMLDocument(std::nullptr_t) : XMLNode(nullptr)
    {
    }

    XMLDocument::XMLDocument(Adopt adopt) : XMLNode(adopt)
    {
    }

    std::vector<std::uint8_t> XMLDocument::xml_data_with_options(XMLNodeOptions options) const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSXMLDocument>(this) XMLDataWithOptions:static_cast<::NSXMLNodeOptions>(options)]);
    }

    void XMLDocument::add_child(const XMLNode& child) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) addChild:cocoon::internal::native<::NSXMLNode>(child)];
    }

    void XMLDocument::insert_child(const XMLNode& child, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) insertChild:cocoon::internal::native<::NSXMLNode>(child) atIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLDocument::insert_children(const std::vector<XMLNode>& children, std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) insertChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                               {
                                                                                                   return cocoon::internal::native<::NSXMLNode>(e);
                                                                                               })
                                                            atIndex:static_cast<::NSUInteger>(index)];
    }

    Object XMLDocument::object_by_applying_xslt(const std::vector<std::uint8_t>& xslt, const std::map<std::string, std::string>& arguments) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLDocument>(this) objectByApplyingXSLT:cocoon::internal::to_data(xslt)
                                                                           arguments:cocoon::internal::to_dictionary(arguments, [](const std::string& k) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::to(k);
                                                                                                                     },
                                                                                                                     [](const std::string& v) -> id
                                                                                                                     {
                                                                                                                         return cocoon::internal::to(v);
                                                                                                                     })
                                                                               error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object XMLDocument::object_by_applying_xslt_at_url(const URL& xslt_url, const std::map<std::string, std::string>& argument) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLDocument>(this) objectByApplyingXSLTAtURL:cocoon::internal::native<::NSURL>(xslt_url)
                                                                                arguments:cocoon::internal::to_dictionary(argument, [](const std::string& k) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::to(k);
                                                                                                                          },
                                                                                                                          [](const std::string& v) -> id
                                                                                                                          {
                                                                                                                              return cocoon::internal::to(v);
                                                                                                                          })
                                                                                    error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    Object XMLDocument::object_by_applying_xslt_string(const std::string& xslt, const std::map<std::string, std::string>& arguments) const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLDocument>(this) objectByApplyingXSLTString:cocoon::internal::to(xslt)
                                                                                 arguments:cocoon::internal::to_dictionary(arguments, [](const std::string& k) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::to(k);
                                                                                                                           },
                                                                                                                           [](const std::string& v) -> id
                                                                                                                           {
                                                                                                                               return cocoon::internal::to(v);
                                                                                                                           })
                                                                                     error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<Object>(__r);
    }

    void XMLDocument::remove_child_at_index(std::uint64_t index) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) removeChildAtIndex:static_cast<::NSUInteger>(index)];
    }

    void XMLDocument::replace_child_at_index(std::uint64_t index, const XMLNode& node) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) replaceChildAtIndex:static_cast<::NSUInteger>(index) withNode:cocoon::internal::native<::NSXMLNode>(node)];
    }

    std::string XMLDocument::replacement_class_for_class(const std::string& cls)
    {
        return cocoon::internal::from(NSStringFromClass([::NSXMLDocument replacementClassForClass:NSClassFromString(cocoon::internal::to(cls))]));
    }

    XMLElement XMLDocument::root_element() const
    {
        return cocoon::internal::wrap<XMLElement>([cocoon::internal::ns<::NSXMLDocument>(this) rootElement]);
    }

    void XMLDocument::set_children(const std::vector<XMLNode>& children) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setChildren:cocoon::internal::to_array(children, [](const XMLNode& e) -> id
                                                                                            {
                                                                                                return cocoon::internal::native<::NSXMLNode>(e);
                                                                                            })];
    }

    void XMLDocument::set_root_element(const XMLElement& root) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setRootElement:cocoon::internal::native<::NSXMLElement>(root)];
    }

    bool XMLDocument::validate_and_return_error() const
    {
        NSError* __error = nil;
        auto __r = [cocoon::internal::ns<::NSXMLDocument>(this) validateAndReturnError:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return static_cast<bool>(__r);
    }

    XMLDTD XMLDocument::dtd() const
    {
        return cocoon::internal::wrap<XMLDTD>([cocoon::internal::ns<::NSXMLDocument>(this) DTD]);
    }

    void XMLDocument::set_dtd(const XMLDTD& value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setDTD:cocoon::internal::native<::NSXMLDTD>(value)];
    }

    std::string XMLDocument::mime_type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDocument>(this) MIMEType]);
    }

    void XMLDocument::set_mime_type(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setMIMEType:cocoon::internal::to(value)];
    }

    std::vector<std::uint8_t> XMLDocument::xml_data() const
    {
        return cocoon::internal::from_data([cocoon::internal::ns<::NSXMLDocument>(this) XMLData]);
    }

    std::string XMLDocument::character_encoding() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDocument>(this) characterEncoding]);
    }

    void XMLDocument::set_character_encoding(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setCharacterEncoding:cocoon::internal::to(value)];
    }

    XMLDocumentContentKind XMLDocument::document_content_kind() const
    {
        return static_cast<XMLDocumentContentKind>([cocoon::internal::ns<::NSXMLDocument>(this) documentContentKind]);
    }

    void XMLDocument::set_document_content_kind(XMLDocumentContentKind value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setDocumentContentKind:static_cast<::NSXMLDocumentContentKind>(value)];
    }

    bool XMLDocument::is_standalone() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSXMLDocument>(this) isStandalone]);
    }

    void XMLDocument::set_standalone(bool value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setStandalone:static_cast<::BOOL>(value)];
    }

    std::string XMLDocument::version() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSXMLDocument>(this) version]);
    }

    void XMLDocument::set_version(const std::string& value) const
    {
        [cocoon::internal::ns<::NSXMLDocument>(this) setVersion:cocoon::internal::to(value)];
    }
}
