#include "generated/secure_unarchive_from_data_transformer.h"
#include "internal.h"

namespace cocoon
{
    SecureUnarchiveFromDataTransformer::SecureUnarchiveFromDataTransformer() : SecureUnarchiveFromDataTransformer(Adopt{cocoon::internal::retain([[::NSSecureUnarchiveFromDataTransformer alloc] init])})
    {
    }

    SecureUnarchiveFromDataTransformer::SecureUnarchiveFromDataTransformer(std::nullptr_t) : ValueTransformer(nullptr)
    {
    }

    SecureUnarchiveFromDataTransformer::SecureUnarchiveFromDataTransformer(Adopt adopt) : ValueTransformer(adopt)
    {
    }

    std::vector<std::string> SecureUnarchiveFromDataTransformer::allowed_top_level_classes()
    {
        return cocoon::internal::from_array<std::string>([::NSSecureUnarchiveFromDataTransformer allowedTopLevelClasses], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from(NSStringFromClass(e));
                                                         });
    }
}
