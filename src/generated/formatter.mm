#include "generated/formatter.h"
#include "internal.h"

namespace cocoon
{
    Formatter::Formatter() : Formatter(Adopt{cocoon::internal::retain([[::NSFormatter alloc] init])})
    {
    }

    Formatter::Formatter(std::nullptr_t) : Object(nullptr)
    {
    }

    Formatter::Formatter(Adopt adopt) : Object(adopt)
    {
    }

    AttributedString Formatter::attributed_string_for_object_value(const Object& obj, const std::map<std::string, Object>& attrs) const
    {
        return cocoon::internal::wrap<AttributedString>([cocoon::internal::ns<::NSFormatter>(this) attributedStringForObjectValue:cocoon::internal::native_id(obj)
                                                                                withDefaultAttributes:cocoon::internal::to_dictionary(attrs, [](const std::string& k) -> id
                                                                                                                        {
                                                                                                                            return cocoon::internal::to(k);
                                                                                                                        },
                                                                                                                        [](const Object& v) -> id
                                                                                                                        {
                                                                                                                            return cocoon::internal::native_id(v);
                                                                                                                        })]);
    }

    std::string Formatter::editing_string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFormatter>(this) editingStringForObjectValue:cocoon::internal::native_id(obj)]);
    }

    bool Formatter::is_partial_string_valid(const std::string& partial_string, std::string& new_string, std::string& error) const
    {
        NSString* __v_new_string = nil;
        NSString* __v_error = nil;
        auto __r = [cocoon::internal::ns<::NSFormatter>(this) isPartialStringValid:cocoon::internal::to(partial_string) newEditingString:&__v_new_string errorDescription:&__v_error];
        new_string = cocoon::internal::from(__v_new_string);
        error = cocoon::internal::from(__v_error);
        return static_cast<bool>(__r);
    }

    bool Formatter::is_partial_string_valid(std::string& partial_string_ptr, Range* proposed_sel_range_ptr, const std::string& orig_string, const Range& orig_sel_range, std::string& error) const
    {
        NSString* __v_partial_string_ptr = nil;
        NSString* __v_error = nil;
        auto __r = [cocoon::internal::ns<::NSFormatter>(this) isPartialStringValid:&__v_partial_string_ptr proposedSelectedRange:(::NSRangePointer)(proposed_sel_range_ptr)originalString:cocoon::internal::to(orig_string) originalSelectedRange:cocoon::internal::to(orig_sel_range) errorDescription:&__v_error];
        partial_string_ptr = cocoon::internal::from(__v_partial_string_ptr);
        error = cocoon::internal::from(__v_error);
        return static_cast<bool>(__r);
    }

    std::string Formatter::string_for_object_value(const Object& obj) const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSFormatter>(this) stringForObjectValue:cocoon::internal::native_id(obj)]);
    }
}
