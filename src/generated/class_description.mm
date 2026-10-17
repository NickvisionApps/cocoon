#include "generated/class_description.h"
#include "internal.h"

namespace cocoon
{
    ClassDescription::ClassDescription() : ClassDescription(Adopt{cocoon::internal::retain([[::NSClassDescription alloc] init])})
    {
    }

    ClassDescription::ClassDescription(std::nullptr_t) : Object(nullptr)
    {
    }

    ClassDescription::ClassDescription(Adopt adopt) : Object(adopt)
    {
    }

    ClassDescription ClassDescription::class_description_for_class(const std::string& a_class)
    {
        return cocoon::internal::wrap<ClassDescription>([::NSClassDescription classDescriptionForClass:NSClassFromString(cocoon::internal::to(a_class))]);
    }

    void ClassDescription::invalidate_class_description_cache()
    {
        [::NSClassDescription invalidateClassDescriptionCache];
    }

    std::string ClassDescription::inverse_for_relationship_key(const std::string& relationship_key) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSClassDescription>(this) inverseForRelationshipKey:cocoon::internal::to(relationship_key)]);
    }

    void ClassDescription::register_class_description(const ClassDescription& description, const std::string& a_class)
    {
        [::NSClassDescription registerClassDescription:cocoon::internal::native<::NSClassDescription>(description) forClass:NSClassFromString(cocoon::internal::to(a_class))];
    }

    std::vector<std::string> ClassDescription::attribute_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSClassDescription>(this) attributeKeys], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> ClassDescription::to_many_relationship_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSClassDescription>(this) toManyRelationshipKeys], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }

    std::vector<std::string> ClassDescription::to_one_relationship_keys() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSClassDescription>(this) toOneRelationshipKeys], [](id e) -> std::string
                                           {
                                               return cocoon::internal::from((NSString*)e);
                                           });
    }
}
