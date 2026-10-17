#include "generated/script_whose_test.h"
#include "internal.h"

namespace cocoon
{
    ScriptWhoseTest::ScriptWhoseTest() : ScriptWhoseTest(Adopt{cocoon::internal::retain([[::NSScriptWhoseTest alloc] init])})
    {
    }

    ScriptWhoseTest::ScriptWhoseTest(std::nullptr_t) : Object(nullptr)
    {
    }

    ScriptWhoseTest::ScriptWhoseTest(Adopt adopt) : Object(adopt)
    {
    }

    bool ScriptWhoseTest::is_true() const
    {
        return static_cast<bool>([cocoon::internal::ns<::NSScriptWhoseTest>(this) isTrue]);
    }
}
