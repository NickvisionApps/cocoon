#include "generated/specifier_test.h"
#include "internal.h"

namespace cocoon
{
    SpecifierTest::SpecifierTest(const ScriptObjectSpecifier& obj1, TestComparisonOperation comp_op, const Object& obj2) : SpecifierTest(Adopt{cocoon::internal::retain([[::NSSpecifierTest alloc] initWithObjectSpecifier:cocoon::internal::native<::NSScriptObjectSpecifier>(obj1) comparisonOperator:static_cast<::NSTestComparisonOperation>(comp_op) testObject:cocoon::internal::native_id(obj2)])})
    {
    }

    SpecifierTest::SpecifierTest() : ScriptWhoseTest(nullptr)
    {
    }

    SpecifierTest::SpecifierTest(std::nullptr_t) : ScriptWhoseTest(nullptr)
    {
    }

    SpecifierTest::SpecifierTest(Adopt adopt) : ScriptWhoseTest(adopt)
    {
    }
}
