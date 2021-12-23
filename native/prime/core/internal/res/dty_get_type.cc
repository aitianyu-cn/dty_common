/**
 * @file dty_get_type.cc(native/core/ext)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-22
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#include "../utilize.hh"

#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

#include <typeinfo>

template<typename T> dty::Type<T> dty::GetType()
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    dty::Type<T> type;
#ifdef __GNUC__
    int status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, &status);
    if (0 != status)
    {
        int32 length = ::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
    }
#else // !__GNUC__
    int32 length = ::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

    return type;
}

template<typename T> dty::Type<T> dty::GetType(T& obj)
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    dty::Type<T> type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
    int status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, &status);
    if (0 != status)
    {
        int32 length = ::strlen(sourceName);
        demangled_name = new char[length + 1];
        for (int32 i = 0; i < length; ++i)
            demangled_name[i] = sourceName[i];
        demangled_name[length] = '\0';
    }
#else // !__GNUC__
    int32 length = ::strlen(sourceName);
    ::string demangled_name = new char[length + 1];
    for (int32 i = 0; i < length; ++i)
        demangled_name[i] = sourceName[i];
    demangled_name[length] = '\0';
#endif // !__GNUC__
    type._Name = demangled_name;
    type._Id = typeid(T).hash_code();

    return type;
}

template<typename T> ::string dty::_dty_native_cpp_default_to_string(T& obj) noexcept
{
    dty::Type<T> otype = dty::GetType(obj);
    ::string str = otype._Name;

    otype._Name = ::null;

    return str;
}
