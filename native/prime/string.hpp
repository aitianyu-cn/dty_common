/**
 * @file string.hpp(prime)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2021-12-17
 *
 * @copyright aitianyu.cn Copyright (c) 2021
 *
 */

#ifndef __DTY_NATIVE_UTILS_STRING_H_PLUS_PLUS__
#define __DTY_NATIVE_UTILS_STRING_H_PLUS_PLUS__

#include "./core.hxx"
#include "./array.hpp"
#if __cplusplus >= 201103
#include<initializer_list>
#endif // !__cplusplus >= 201103

namespace dty
{
    class String
        : public virtual dty::TianyuObject,
        public virtual dty::collection::IEquatable<String>,
        public virtual dty::collection::ICompareable<String>
    {
        __PUB__ IPropertyGetter<int32> __REFERENCE__ Length = this->_StringLength;

        __PRI__ Property<string> __VARIABLE__ _StringValue;
        __PRI__ Property<int32>  __VARIABLE__ _StringLength;
        __PRI__ int32            __POINTER__  _Reference;

        __PUB__ String();
        __PUB__ String(string_sp    __VARIABLE__ item);
        __PUB__ String(const char   __VARIABLE__ item, int32 __VARIABLE__ repeat);
        __PUB__ String(const string __VARIABLE__ str, int32 __VARIABLE__ length);
        __PRI__ String(const string __VARIABLE__ str, int32 __VARIABLE__ length, bool __VARIABLE__ notCopy);
        __PUB__ String(const string __VARIABLE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);

        __PUB__ String(const String __REFERENCE__ str);
        __PUB__ String(const string __VARIABLE__ str);

        __PUB__ virtual ~String() override;

#pragma region Tianyu String Function
        __PUB__ bool   __VARIABLE__ IsEmpty();
        __PUB__ bool   __VARIABLE__ RemoveAt(int32 __VARIABLE__ index);
        __PUB__ void   __VARIABLE__ Clear();
        __PUB__ char   __VARIABLE__ operator[](int32 __VARIABLE__ index);

        __PUB__ bool   __VARIABLE__ EndWith(const char __VARIABLE__ ch);
        __PUB__ bool   __VARIABLE__ EndWith(String __REFERENCE__ str);
        __PUB__ bool   __VARIABLE__ Contains(const char __VARIABLE__ str);
        __PUB__ bool   __VARIABLE__ Contains(const String __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32  __VARIABLE__ IndexOf(const char __VARIABLE__ ch);
        __PUB__ int32  __VARIABLE__ IndexOf(const char __VARIABLE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32  __VARIABLE__ IndexOf(const char __VARIABLE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32  __VARIABLE__ IndexOf(String __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32  __VARIABLE__ IndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex); // 需要Sunday算法
        __PUB__ int32  __VARIABLE__ IndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex); // 需要Sunday算法
        __PUB__ String __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, const char __VARIABLE__ ch);
        __PUB__ String __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, string __VARIABLE__ str);
        __PUB__ String __VARIABLE__ Insert(int32 __VARIABLE__ insertIndex, String __REFERENCE__ str);
        __PUB__ int32  __VARIABLE__ LastIndexOf(const char __VARIABLE__ ch);
        __PUB__ int32  __VARIABLE__ LastIndexOf(const char __VARIABLE__ ch, int32 __VARIABLE__ startIndex);
        __PUB__ int32  __VARIABLE__ LastIndexOf(const char __VARIABLE__ ch, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ int32  __VARIABLE__ LastIndexOf(String __REFERENCE__ str); // 需要Sunday算法
        __PUB__ int32  __VARIABLE__ LastIndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex); // 需要Sunday算法
        __PUB__ int32  __VARIABLE__ LastIndexOf(String __REFERENCE__ str, int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex); // 需要Sunday算法
        __PUB__ String __VARIABLE__ PadLeft(int32 __VARIABLE__ length);
        __PUB__ String __VARIABLE__ PadLeft(int32 __VARIABLE__ length, const char __VARIABLE__ ch);
        __PUB__ String __VARIABLE__ PadRight(int32 __VARIABLE__ length);
        __PUB__ String __VARIABLE__ PadRight(int32 __VARIABLE__ length, const char __VARIABLE__ ch);
        __PUB__ String __VARIABLE__ Remove(const char __VARIABLE__ elem);
        __PUB__ String __VARIABLE__ Remove(int32 __VARIABLE__ removeIndex);
        __PUB__ String __VARIABLE__ Remove(int32 __VARIABLE__ startIndex, int32 __VARIABLE__ endIndex);
        __PUB__ String __VARIABLE__ Replace(const char __VARIABLE__ findChar, const char __VARIABLE__ replaceChar);
        __PUB__ String __VARIABLE__ Replace(String __REFERENCE__ findStr, String __REFERENCE__ replaceStr); // 需要Sunday算法
        __PUB__ bool   __VARIABLE__ StartWith(const char __VARIABLE__ ch);
        __PUB__ bool   __VARIABLE__ StartWith(String __REFERENCE__ str);
        __PUB__ String __VARIABLE__ ToLower();
        __PUB__ String __VARIABLE__ ToUpper();
        __PUB__ void   __VARIABLE__ Trim();
        __PUB__ void   __VARIABLE__ Trim(const char __VARIABLE__ ch);
        __PUB__ void   __VARIABLE__ Trim(char __VARIABLE__ ch [], int32 __VARIABLE__ length);
        __PUB__ void   __VARIABLE__ TrimStart();
        __PUB__ void   __VARIABLE__ TrimStart(const char __VARIABLE__ ch);
        __PUB__ void   __VARIABLE__ TrimStart(char __VARIABLE__ ch [], int32 __VARIABLE__ length);
        __PUB__ void   __VARIABLE__ TrimEnd();
        __PUB__ void   __VARIABLE__ TrimEnd(const char __VARIABLE__ ch);
        __PUB__ void   __VARIABLE__ TrimEnd(char __VARIABLE__ ch [], int32 __VARIABLE__ length);

        __PUB__ virtual ::string __VARIABLE__ ToString() noexcept override;
        __PUB__ virtual uint64   __VARIABLE__ GetTypeId() override;
        __PUB__ virtual uint64   __VARIABLE__ GetHashCode() override;
        __PUB__ virtual bool     __VARIABLE__ IsNull() override;
        __PUB__ virtual bool     __VARIABLE__ Equals(dty::TianyuObject __REFERENCE__ other) override;

        __PUB__::string   __VARIABLE__ ToCStr();
        __PUB__ string_sp __VARIABLE__ ToSafeCStr();

        __PUB__ collection::CharArray     __VARIABLE__ ToArray();
        __PUB__ collection::Array<String> __VARIABLE__ Split(const char __VARIABLE__ splitChar);
        __PUB__ collection::Array<String> __VARIABLE__ Split(const char __VARIABLE__ splitChar, bool __VARIABLE__ ignoreEmpty);
        __PUB__ collection::Array<String> __VARIABLE__ Split(const char __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit);
        __PUB__ collection::Array<String> __VARIABLE__ Split(const char __VARIABLE__ splitChar, int32 __VARIABLE__ maxSplit, bool __VARIABLE__ ignoreEmpty);
        __PUB__ collection::Array<String> __VARIABLE__ Split(String __REFERENCE__ splitStr, int32 __VARIABLE__ maxSplit); // 需要Sunday算法
        __PUB__ collection::Array<String> __VARIABLE__ Split(String __REFERENCE__ splitStr, int32 __VARIABLE__ maxSplit, bool __VARIABLE__ ignoreEmpty); // 需要Sunday算法

        __PUB__ String __VARIABLE__ operator+(String __REFERENCE__ str);
        __PUB__ String __VARIABLE__ operator+(string __VARIABLE__  str);
        __PUB__ String __VARIABLE__ operator+(const char   __VARIABLE__  ch);

#if __cplusplus >= 201103
        __PUB__ bool   __VARIABLE__ Contains(std::initializer_list<String> strs);
#endif // !__cplusplus >= 201103

        __PUB__ String __VARIABLE__ operator =(String __REFERENCE__ source);
        __PUB__ String __VARIABLE__ operator =(const string __VARIABLE__ source);
        __PUB__ operator string();
        __PUB__ operator string_sp();
#pragma endregion

#pragma region Tianyu IEquatable Interface
        __PUB__ virtual bool __VARIABLE__ Equals(String __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator ==(String __REFERENCE__ other) override;
        __PUB__ virtual bool __VARIABLE__ operator !=(String __REFERENCE__ other) override;
#pragma endregion

#pragma region Tianyu ICompareable Interface
        __PUB__ virtual collection::CompareResult __VARIABLE__ CompareTo(String __REFERENCE__ other) override;

        __PUB__ virtual bool          __VARIABLE__ operator <(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator <=(String __REFERENCE__ other) override;
        __PUB__ virtual bool          __VARIABLE__ operator >=(String __REFERENCE__ other) override;
#pragma endregion

#pragma region Statics for Tianyu String
        __PUB__ static String __VARIABLE__ GetString(const ::string __VARIABLE__ source, bool __VARIABLE__ needCopy);
        __PUB__ static String __VARIABLE__ GetString(const ::string __VARIABLE__ source, int32 __VARIABLE__ sourceLen, bool __VARIABLE__ needCopy);

        __PUB__ static String __VARIABLE__ Empty;

#if __cplusplus >= 201103
        __PUB__ static String __VARIABLE__ Concat(std::initializer_list<String> __VARIABLE__ strs);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, std::initializer_list<String> strs);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, std::initializer_list<string> strs);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, std::initializer_list<String> strs, bool __VARIABLE__ forceEmpty);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, std::initializer_list<string> strs, bool __VARIABLE__ forceEmpty);
#endif // !__cplusplus >= 201103
        __PUB__ static String __VARIABLE__ Concat(String __REFERENCE__ str0, String __REFERENCE__ str1);
        __PUB__ static String __VARIABLE__ Concat(String __REFERENCE__ str0, String __REFERENCE__ str1, String __REFERENCE__ str2);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, String __REFERENCE__ str1, String __REFERENCE__ str2);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, String __REFERENCE__ str1, String __REFERENCE__ str2, bool __VARIABLE__ forceEmpty);
        __PUB__ static String __VARIABLE__ Join(const char __VARIABLE__ joinChar, string __VARIABLE__ str1, int32 __VARIABLE__ length1, string __VARIABLE__ str2, int32 __VARIABLE__ length2);
#pragma endregion

        __PRI__ void __VARIABLE__ Release();
        __PRI__ void __VARIABLE__ UpdateSource(int32 __VARIABLE__ length, string __VARIABLE__ str);
    };
}

#endif // !__DTY_NATIVE_UTILS_STRING_H_PLUS_PLUS__