/**
 * @file ostream.hpp(io/base_stream)
 * @author ysydty
 * @brief
 * @version 0.1
 * @date 2022-04-29
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

#ifndef __DTY_COMMON_NATIVE_IO_BASE_STREAM_OSTREAM_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_IO_BASE_STREAM_OSTREAM_H_PLUS_PLUS__

#include <ostream>
#include "../../prime.hxx"

namespace dty::io
{
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, String __REFERENCE__ str);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, TimeSpan __REFERENCE__ span);
    std::ostream __REFERENCE__ operator<<(std::ostream __REFERENCE__ os, DateTime __REFERENCE__ date);
}

#endif // !__DTY_COMMON_NATIVE_IO_BASE_STREAM_OSTREAM_H_PLUS_PLUS__