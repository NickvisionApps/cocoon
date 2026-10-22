#include "generated/printer.h"
#include "internal.h"

namespace cocoon
{
    Printer::Printer(const std::string& name) : Printer(Adopt{cocoon::internal::retain([::NSPrinter printerWithName:cocoon::internal::to(name)])})
    {
    }

    Printer::Printer() : Printer(Adopt{cocoon::internal::retain([[::NSPrinter alloc] init])})
    {
    }

    Printer::Printer(std::nullptr_t) : Object(nullptr)
    {
    }

    Printer::Printer(Adopt adopt) : Object(adopt)
    {
    }

    Size Printer::page_size_for_paper(const std::string& paper_name) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrinter>(this) pageSizeForPaper:cocoon::internal::to(paper_name)]);
    }

    std::map<std::string, Object> Printer::device_description() const
    {
        return cocoon::internal::from_dictionary<std::map<std::string, Object>>([cocoon::internal::ns<::NSPrinter>(this) deviceDescription], [](id k) -> std::string
                                                                                {
                                                                                    return cocoon::internal::from((NSString*)k);
                                                                                },
                                                                                [](id v) -> Object
                                                                                {
                                                                                    return cocoon::internal::wrap<Object>(v);
                                                                                });
    }

    std::int64_t Printer::language_level() const
    {
        return static_cast<std::int64_t>([cocoon::internal::ns<::NSPrinter>(this) languageLevel]);
    }

    std::string Printer::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrinter>(this) name]);
    }

    std::vector<std::string> Printer::printer_names()
    {
        return cocoon::internal::from_array<std::string>([::NSPrinter printerNames], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::vector<std::string> Printer::printer_types()
    {
        return cocoon::internal::from_array<std::string>([::NSPrinter printerTypes], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string Printer::type() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSPrinter>(this) type]);
    }
}
