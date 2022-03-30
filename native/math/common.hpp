/**
 * @file common.hpp(math)
 * @author senyun.yao
 * @brief
 * @version 0.1
 * @date 2022-03-29
 *
 * @copyright aitianyu.cn Copyright (c) 2022
 *
 */

#ifndef __DTY_COMMON_NATIVE_MATH_MATHEMATIC_COMMON_H_PLUS_PLUS__
#define __DTY_COMMON_NATIVE_MATH_MATHEMATIC_COMMON_H_PLUS_PLUS__

#include "../prime/core.hxx"

namespace dty::math
{
    /**
     * @brief comparing results for big number
     *
     */
    _enum NumberCompareResult : int32
    {
        /**
         * @brief unknown result: at least one operation is invalid
         *
         */
        NaN = -2,
        /**
         * @brief operation number 1 is less than operation number 2
         *
         */
        LessThan = -1,
        /**
         * @brief operation number 1 and 2 are same
         *
         */
        Equal = 0,
        /**
         * @brief operation number 1 is great than operation number 2
         *
         */
        GreatThan = 1
    };

    typedef struct bignumber_calculate_metadata
    {
        byte  __POINTER__  _Value;
        int32 __VARIABLE__ _PhySize;
        int32 __VARIABLE__ _MathSize;
    } BigNumCalcMetadata;
}

#endif // __DTY_COMMON_NATIVE_MATH_MATHEMATIC_COMMON_H_PLUS_PLUS__