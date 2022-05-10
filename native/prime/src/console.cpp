#include "../console.hpp"
#include "string.h"

typedef struct out_list_item
{
    ::string             __VARIABLE__ _Str;
    int32                __VARIABLE__ _StrLength;

    struct out_list_item __POINTER__  _Next;
}OutListItem;

class ConsoleWriteHandler
{
    __PRI__ const ::string __VARIABLE__ DefaultVoidPointerName = "dty.object";

    __PUB__ template<typename ...Args>
        static void __VARIABLE__ Write(const ::string __VARIABLE__ formatter, OutListItem __POINTER__ header, Args ...params)
    {
        int32 paramsCount = ConsoleWriteHandler::HandleParams(header, params...);
        ConsoleWriteHandler::HandleWrite(formatter, header, paramsCount);
    }

    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::byte __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::b2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::sbyte __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::sb2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::int16 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::s2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::uint16 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::us2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::int32 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::i2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::uint32 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::ui2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::int64 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::l2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, ::uint64 __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::ul2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, float __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::f2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, double __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = ::d2str(param, ::null);
        newItem->_StrLength = dty::strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, const char __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_Str = new char[2]{ param, '\0' };
        newItem->_StrLength = 1;

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, const ::string __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_StrLength = dty::strlen(param);
        newItem->_Str = new char[newItem->_StrLength + 1];
        for (int32 i = 0; i < newItem->_StrLength; ++i)
            newItem->_Str[i] = param[i];
        newItem->_Str[newItem->_StrLength] = '\0';

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, const ::object __VARIABLE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        newItem->_StrLength = 10;
        newItem->_Str = new char[newItem->_StrLength + 1];
        for (int32 i = 0; i < newItem->_StrLength; ++i)
            newItem->_Str[i] = ConsoleWriteHandler::DefaultVoidPointerName[i];
        newItem->_Str[newItem->_StrLength] = '\0';

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ template<typename T, typename ...Args>
        static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem, T __REFERENCE__ param, Args ...params)
    {
        OutListItem __POINTER__ newItem = new OutListItem();

        static_assert(std::is_base_of<dty::TianyuObject, T>::value, "Args...Params<T, ...> should be based from TianyuObject");

        dty::TianyuObject __REFERENCE__ obj = param;
        newItem->_Str = obj.ToString();
        newItem->_StrLength = strlen(newItem->_Str);

        preItem->_Next = newItem;
        newItem->_Next = ::null;

        // call override HandleParams to process the next params
        return ConsoleWriteHandler::HandleParams(preItem->_Next, params...) + 1;
    }
    __PRI__ static int32 __VARIABLE__ HandleParams(OutListItem __POINTER__ preItem)
    {
        // end handle params, return 0 and roll back.
        return 0;
    }

    __PRI__ static void __VARIABLE__ HandleWrite(const ::string __VARIABLE__ formatter, OutListItem __POINTER__ params, int32 __VARIABLE__ paramsCount)
    {
        return;
    }
};

namespace dty
{

}