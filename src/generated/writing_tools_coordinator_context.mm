#include "generated/writing_tools_coordinator_context.h"
#include "internal.h"

namespace cocoon
{
    WritingToolsCoordinatorContext::WritingToolsCoordinatorContext(const AttributedString& attributed_string, const Range& range) : WritingToolsCoordinatorContext(Adopt{cocoon::internal::retain([[::NSWritingToolsCoordinatorContext alloc] initWithAttributedString:cocoon::internal::native<::NSAttributedString>(attributed_string) range:cocoon::internal::to(range)])})
    {
    }

    WritingToolsCoordinatorContext::WritingToolsCoordinatorContext() : Object(nullptr)
    {
    }

    WritingToolsCoordinatorContext::WritingToolsCoordinatorContext(std::nullptr_t) : Object(nullptr)
    {
    }

    WritingToolsCoordinatorContext::WritingToolsCoordinatorContext(Adopt adopt) : Object(adopt)
    {
    }

    AttributedString WritingToolsCoordinatorContext::attributed_string() const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSWritingToolsCoordinatorContext>(this) attributedString]);
    }

    UUID WritingToolsCoordinatorContext::identifier() const
    {
        return cocoon::internal::wrap<UUID>([cocoon::internal::ns<::NSWritingToolsCoordinatorContext>(this) identifier]);
    }

    Range WritingToolsCoordinatorContext::range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWritingToolsCoordinatorContext>(this) range]);
    }

    Range WritingToolsCoordinatorContext::resolved_range() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSWritingToolsCoordinatorContext>(this) resolvedRange]);
    }
}
