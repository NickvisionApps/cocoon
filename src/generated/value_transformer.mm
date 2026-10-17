#include "generated/value_transformer.h"
#include "internal.h"

namespace cocoon
{
    ValueTransformer::ValueTransformer() : ValueTransformer(Adopt{cocoon::internal::retain([[::NSValueTransformer alloc] init])})
    {
    }

    ValueTransformer::ValueTransformer(std::nullptr_t) : Object(nullptr)
    {
    }

    ValueTransformer::ValueTransformer(Adopt adopt) : Object(adopt)
    {
    }

    bool ValueTransformer::allows_reverse_transformation()
    {
        return static_cast<bool>([::NSValueTransformer allowsReverseTransformation]);
    }

    Object ValueTransformer::reverse_transformed_value(const Object& value) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSValueTransformer>(this) reverseTransformedValue:cocoon::internal::native_id(value)]);
    }

    void ValueTransformer::set_value_transformer(const ValueTransformer& transformer, const std::string& name)
    {
        [::NSValueTransformer setValueTransformer:cocoon::internal::native<::NSValueTransformer>(transformer) forName:cocoon::internal::to(name)];
    }

    Object ValueTransformer::transformed_value(const Object& value) const
    {
        return cocoon::internal::wrap<Object>([cocoon::internal::ns<::NSValueTransformer>(this) transformedValue:cocoon::internal::native_id(value)]);
    }

    std::string ValueTransformer::transformed_value_class()
    {
        return cocoon::internal::from(NSStringFromClass([::NSValueTransformer transformedValueClass]));
    }

    ValueTransformer ValueTransformer::value_transformer_for_name(const std::string& name)
    {
        return cocoon::internal::wrap<ValueTransformer>([::NSValueTransformer valueTransformerForName:cocoon::internal::to(name)]);
    }

    std::vector<std::string> ValueTransformer::value_transformer_names()
    {
        return cocoon::internal::from_array<std::string>([::NSValueTransformer valueTransformerNames], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
