#include "generated/data_detector.h"
#include "internal.h"

namespace cocoon
{
    DataDetector::DataDetector(std::uint64_t checking_types) : DataDetector(Adopt{cocoon::internal::retain([&]() -> id
                                                                                             {
                                                                                                 NSError* __error = nil;
                                                                                                 id __r = [[::NSDataDetector alloc] initWithTypes:static_cast<::NSTextCheckingTypes>(checking_types) error:&__error];
                                                                                                 if (!__r && __error)
                                                                                                 {
                                                                                                     throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
                                                                                                 }
                                                                                                 return __r;
                                                                                             }())})
    {
    }

    DataDetector::DataDetector() : DataDetector(Adopt{cocoon::internal::retain([[::NSDataDetector alloc] init])})
    {
    }

    DataDetector::DataDetector(std::nullptr_t) : RegularExpression(nullptr)
    {
    }

    DataDetector::DataDetector(Adopt adopt) : RegularExpression(adopt)
    {
    }

    DataDetector DataDetector::data_detector_with_types(std::uint64_t checking_types)
    {
        NSError* __error = nil;
        auto __r = [::NSDataDetector dataDetectorWithTypes:static_cast<::NSTextCheckingTypes>(checking_types) error:&__error];
        if (__error)
        {
            throw cocoon::NativeError(cocoon::internal::from(__error.localizedDescription));
        }
        return cocoon::internal::wrap<DataDetector>(__r);
    }

    std::uint64_t DataDetector::checking_types() const
    {
        return static_cast<std::uint64_t>([cocoon::internal::ns<::NSDataDetector>(this) checkingTypes]);
    }
}
