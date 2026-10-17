#include "generated/logical_test.h"
#include "internal.h"

namespace cocoon
{
    LogicalTest::LogicalTest(const std::vector<SpecifierTest>& sub_tests) : LogicalTest(Adopt{cocoon::internal::retain([[::NSLogicalTest alloc] initAndTestWithTests:cocoon::internal::to_array(sub_tests, [](const SpecifierTest& e) -> id
                                                                                                                                                                    {
                                                                                                                                                                        return cocoon::internal::native<::NSSpecifierTest>(e);
                                                                                                                                                                    })])})
    {
    }

    LogicalTest::LogicalTest(const ScriptWhoseTest& sub_test) : LogicalTest(Adopt{cocoon::internal::retain([[::NSLogicalTest alloc] initNotTestWithTest:cocoon::internal::native<::NSScriptWhoseTest>(sub_test)])})
    {
    }

    LogicalTest::LogicalTest() : LogicalTest(Adopt{cocoon::internal::retain([[::NSLogicalTest alloc] init])})
    {
    }

    LogicalTest::LogicalTest(std::nullptr_t) : ScriptWhoseTest(nullptr)
    {
    }

    LogicalTest::LogicalTest(Adopt adopt) : ScriptWhoseTest(adopt)
    {
    }
}
