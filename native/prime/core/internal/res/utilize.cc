/**
 * @file utilize.cc
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2021-12-24
 *
 * @copyright Copyright (c) 2021
 *
 */

#include "../utilize.hh"

#define __TEMPLATE_DEF__ template<typename T>
#define __DTY_TYPE_DEF__ dty::Type<T>
#define __GET_TYPE_DEF__ dty::GetType

 //
//#######################################################################################
// Implementation for GetType API
//#######################################################################################
#ifdef __GNUC__
#include <cxxabi.h>
#endif // !__GNUC__

#include <typeinfo>

__TEMPLATE_DEF__ __DTY_TYPE_DEF__ __GET_TYPE_DEF__()
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __DTY_TYPE_DEF__ type;
#ifdef __GNUC__
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
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

__TEMPLATE_DEF__ __DTY_TYPE_DEF__ __GET_TYPE_DEF__(T& obj)
{
    ::string sourceName = const_cast<::string>(typeid(T).name());

    __DTY_TYPE_DEF__ type((uint64)(__REF_TO_PTR__ obj));
#ifdef __GNUC__
    int32 status;
    ::string demangled_name = abi::__cxa_demangle(sourceName, NULL, NULL, __VAR_TO_PTR__ status);
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

__TEMPLATE_DEF__::string dty::_dty_native_cpp_default_to_string(T& obj) noexcept
{
    __DTY_TYPE_DEF__ otype = __GET_TYPE_DEF__(obj);
    ::string str = otype._Name;

    otype._Name = ::null;

    return str;
}

//#######################################################################################
// Implementation for Type class
//#######################################################################################
__TEMPLATE_DEF__ bool __DTY_TYPE_DEF__::_dummy = false;

__TEMPLATE_DEF__ __construction__ __DTY_TYPE_DEF__::Type()
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(0ULL)
{ }

__TEMPLATE_DEF__ __construction__ __DTY_TYPE_DEF__::Type(uint64 instance)
    : _Name(::null),
    _Id(0ULL),
    _InstanceHash(instance)
{ }

__TEMPLATE_DEF__ __cp_construct__ __DTY_TYPE_DEF__::Type(const __DTY_TYPE_DEF__& other)
    : _Name(::null),
    _Id(other._Id),
    _InstanceHash(other._InstanceHash)
{
    __DTY_TYPE_DEF__& copy = const_cast<__DTY_TYPE_DEF__&>(other);
    this->_Name = copy._Name;

    copy._Name = ::null;
}

__TEMPLATE_DEF__ __destruction__  __DTY_TYPE_DEF__::~Type()
{
    if (::null != this->_Name)
        delete [](this->_Name);
}

__TEMPLATE_DEF__::string __DTY_TYPE_DEF__::Name() const
{
    return this->_Name;
}

__TEMPLATE_DEF__ uint64 __DTY_TYPE_DEF__::Id()
{
    return this->_Id;
}

__TEMPLATE_DEF__ uint64 __DTY_TYPE_DEF__::InstanceHashCode()
{
    return this->_InstanceHash;
}

// to cancel the macro definitions
#undef __TEMPLATE_DEF__
#undef __DTY_TYPE_DEF__
#undef __GET_TYPE_DEF__