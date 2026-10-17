#include "generated/exception.h"
#include "internal.h"

namespace cocoon
{
    Exception::Exception(const std::string& a_name, const std::string& a_reason, const std::vector<std::pair<Object, Object>>& a_user_info) : Exception(Adopt{cocoon::internal::retain([[::NSException alloc] initWithName:cocoon::internal::to(a_name)
                                                                                                                                                                                                                    reason:cocoon::internal::to(a_reason)
                                                                                                                                                                                                                  userInfo:cocoon::internal::to_dictionary(a_user_info, [](const Object& k) -> id
                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                               return cocoon::internal::native_id(k);
                                                                                                                                                                                                                                                           },
                                                                                                                                                                                                                                                           [](const Object& v) -> id
                                                                                                                                                                                                                                                           {
                                                                                                                                                                                                                                                               return cocoon::internal::native_id(v);
                                                                                                                                                                                                                                                           })])})
    {
    }

    Exception::Exception() : Exception(Adopt{cocoon::internal::retain([[::NSException alloc] init])})
    {
    }

    Exception::Exception(std::nullptr_t) : Object(nullptr)
    {
    }

    Exception::Exception(Adopt adopt) : Object(adopt)
    {
    }

    Exception Exception::exception_with_name(const std::string& name, const std::string& reason, const std::vector<std::pair<Object, Object>>& user_info)
    {
        return cocoon::internal::wrap<Exception>([::NSException exceptionWithName:cocoon::internal::to(name)
                                                                           reason:cocoon::internal::to(reason)
                                                                         userInfo:cocoon::internal::to_dictionary(user_info, [](const Object& k) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(k);
                                                                                                                  },
                                                                                                                  [](const Object& v) -> id
                                                                                                                  {
                                                                                                                      return cocoon::internal::native_id(v);
                                                                                                                  })]);
    }

    void Exception::raise() const
    {
        [cocoon::internal::ns<::NSException>(this) raise];
    }

    void Exception::raise_(const std::string& name, const std::string& format, const std::vector<VarArg>& args)
    {
        std::vector<std::uint64_t> __slots = cocoon::internal::pack_var_args(args);
        va_list __list = cocoon::internal::make_va_list(__slots);
        [::NSException raise:cocoon::internal::to(name) format:cocoon::internal::to(format) arguments:__list];
    }

    void Exception::raise(const std::string& name, const std::string& format, char* arg_list)
    {
        [::NSException raise:cocoon::internal::to(name) format:cocoon::internal::to(format) arguments:(::va_list)(arg_list)];
    }

    std::vector<Number> Exception::call_stack_return_addresses() const
    {
        return cocoon::internal::from_array<Number>([cocoon::internal::ns<::NSException>(this) callStackReturnAddresses], [](id e) -> Number
                                                    {
                                                        return cocoon::internal::wrap<Number>((::NSNumber*)e);
                                                    });
    }

    std::vector<std::string> Exception::call_stack_symbols() const
    {
        return cocoon::internal::from_array<std::string>([cocoon::internal::ns<::NSException>(this) callStackSymbols], [](id e) -> std::string
                                                         {
                                                             return cocoon::internal::from((NSString*)e);
                                                         });
    }

    std::string Exception::name() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSException>(this) name]);
    }

    std::string Exception::reason() const
    {
        return cocoon::internal::from([cocoon::internal::ns<::NSException>(this) reason]);
    }

    std::vector<std::pair<Object, Object>> Exception::user_info() const
    {
        return cocoon::internal::from_dictionary<std::vector<std::pair<Object, Object>>>([cocoon::internal::ns<::NSException>(this) userInfo], [](id k) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(k);
                                                                                         },
                                                                                         [](id v) -> Object
                                                                                         {
                                                                                             return cocoon::internal::wrap<Object>(v);
                                                                                         });
    }
}
