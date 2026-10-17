#include "generated/assertion_handler.h"
#include "internal.h"

namespace cocoon
{
    AssertionHandler::AssertionHandler() : AssertionHandler(Adopt{cocoon::internal::retain([[::NSAssertionHandler alloc] init])})
    {
    }

    AssertionHandler::AssertionHandler(std::nullptr_t) : Object(nullptr)
    {
    }

    AssertionHandler::AssertionHandler(Adopt adopt) : Object(adopt)
    {
    }

    AssertionHandler AssertionHandler::current_handler()
    {
        return cocoon::internal::wrap<AssertionHandler>([::NSAssertionHandler currentHandler]);
    }
}
