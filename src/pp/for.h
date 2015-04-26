/**
 * stealer - https://github.com/zjx20/stealer
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2014 JianXiong Zhou <zhoujianxiong2@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining
 * a copy of this software and associated documentation files (the
 * "Software"), to deal in the Software without restriction, including
 * without limitation the rights to use, copy, modify, merge, publish,
 * distribute, sublicense, and/or sell copies of the Software, and to
 * permit persons to whom the Software is furnished to do so, subject to
 * the following conditions:
 *
 * The above copyright notice and this permission notice shall be
 * included in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
 * EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 * MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
 * LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
 * OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
 * WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

/*
 * for.h
 *
 *  Created on: 2014-10-19
 *      Author: jianxiongzhou
 */

#ifndef PP_FOR_H_
#define PP_FOR_H_

#include "util.h"
#include "size.h"
#include "select.h"

// std::string SEP() {return ",";}
// std::string DO(size_t i, std::vector<std::string> args) {return "xxx";}
// size_t iters = iters;
// std::vector<std::string> args = __VA_ARGS__;
// std::string result = "";
// for (int i = 1; i <= iters; i++) {
//   result += DO(i, args);
//   if (i != iters) { result += SEP(); }
// }
#define PP_FOR(iters, DO, SEP, ...) \
 		_PP_FOR_I(iters, DO, SEP, ##__VA_ARGS__)

#define _PP_FOR_I(iters, DO, SEP, ...) _PP_FOR_PP_EXPAND(_PP_FOR_PP_EXPAND_CAT(_PP_FOR_II_, iters)(DO, SEP, __VA_ARGS__,))

// redefine PP_EXPAND() and PP_EXPAND_CAT(), to avoid recursive expanding
#define _PP_FOR_PP_EXPAND(x) x
#define _PP_FOR_PP_CAT(x, y) x##y
#define _PP_FOR_PP_EXPAND_CAT(x, y) _PP_FOR_PP_CAT(x, y)

#define _PP_FOR_II_0(...)
#define _PP_FOR_II_1(DO,  SEP, ...) DO(1,  ## __VA_ARGS__)
#define _PP_FOR_II_2(DO,  SEP, ...) _PP_FOR_II_1(DO,  SEP, ## __VA_ARGS__) SEP() DO(2,  ## __VA_ARGS__)
#define _PP_FOR_II_3(DO,  SEP, ...) _PP_FOR_II_2(DO,  SEP, ## __VA_ARGS__) SEP() DO(3,  ## __VA_ARGS__)
#define _PP_FOR_II_4(DO,  SEP, ...) _PP_FOR_II_3(DO,  SEP, ## __VA_ARGS__) SEP() DO(4,  ## __VA_ARGS__)
#define _PP_FOR_II_5(DO,  SEP, ...) _PP_FOR_II_4(DO,  SEP, ## __VA_ARGS__) SEP() DO(5,  ## __VA_ARGS__)
#define _PP_FOR_II_6(DO,  SEP, ...) _PP_FOR_II_5(DO,  SEP, ## __VA_ARGS__) SEP() DO(6,  ## __VA_ARGS__)
#define _PP_FOR_II_7(DO,  SEP, ...) _PP_FOR_II_6(DO,  SEP, ## __VA_ARGS__) SEP() DO(7,  ## __VA_ARGS__)
#define _PP_FOR_II_8(DO,  SEP, ...) _PP_FOR_II_7(DO,  SEP, ## __VA_ARGS__) SEP() DO(8,  ## __VA_ARGS__)
#define _PP_FOR_II_9(DO,  SEP, ...) _PP_FOR_II_8(DO,  SEP, ## __VA_ARGS__) SEP() DO(9,  ## __VA_ARGS__)
#define _PP_FOR_II_10(DO, SEP, ...) _PP_FOR_II_9(DO,  SEP, ## __VA_ARGS__) SEP() DO(10, ## __VA_ARGS__)
#define _PP_FOR_II_11(DO, SEP, ...) _PP_FOR_II_10(DO, SEP, ## __VA_ARGS__) SEP() DO(11, ## __VA_ARGS__)
#define _PP_FOR_II_12(DO, SEP, ...) _PP_FOR_II_11(DO, SEP, ## __VA_ARGS__) SEP() DO(12, ## __VA_ARGS__)
#define _PP_FOR_II_13(DO, SEP, ...) _PP_FOR_II_12(DO, SEP, ## __VA_ARGS__) SEP() DO(13, ## __VA_ARGS__)
#define _PP_FOR_II_14(DO, SEP, ...) _PP_FOR_II_13(DO, SEP, ## __VA_ARGS__) SEP() DO(14, ## __VA_ARGS__)
#define _PP_FOR_II_15(DO, SEP, ...) _PP_FOR_II_14(DO, SEP, ## __VA_ARGS__) SEP() DO(15, ## __VA_ARGS__)
#define _PP_FOR_II_16(DO, SEP, ...) _PP_FOR_II_15(DO, SEP, ## __VA_ARGS__) SEP() DO(16, ## __VA_ARGS__)
#define _PP_FOR_II_17(DO, SEP, ...) _PP_FOR_II_16(DO, SEP, ## __VA_ARGS__) SEP() DO(17, ## __VA_ARGS__)
#define _PP_FOR_II_18(DO, SEP, ...) _PP_FOR_II_17(DO, SEP, ## __VA_ARGS__) SEP() DO(18, ## __VA_ARGS__)
#define _PP_FOR_II_19(DO, SEP, ...) _PP_FOR_II_18(DO, SEP, ## __VA_ARGS__) SEP() DO(19, ## __VA_ARGS__)
#define _PP_FOR_II_20(DO, SEP, ...) _PP_FOR_II_19(DO, SEP, ## __VA_ARGS__) SEP() DO(20, ## __VA_ARGS__)
#define _PP_FOR_II_21(DO, SEP, ...) _PP_FOR_II_20(DO, SEP, ## __VA_ARGS__) SEP() DO(21, ## __VA_ARGS__)
#define _PP_FOR_II_22(DO, SEP, ...) _PP_FOR_II_21(DO, SEP, ## __VA_ARGS__) SEP() DO(22, ## __VA_ARGS__)
#define _PP_FOR_II_23(DO, SEP, ...) _PP_FOR_II_22(DO, SEP, ## __VA_ARGS__) SEP() DO(23, ## __VA_ARGS__)
#define _PP_FOR_II_24(DO, SEP, ...) _PP_FOR_II_23(DO, SEP, ## __VA_ARGS__) SEP() DO(24, ## __VA_ARGS__)
#define _PP_FOR_II_25(DO, SEP, ...) _PP_FOR_II_24(DO, SEP, ## __VA_ARGS__) SEP() DO(25, ## __VA_ARGS__)
#define _PP_FOR_II_26(DO, SEP, ...) _PP_FOR_II_25(DO, SEP, ## __VA_ARGS__) SEP() DO(26, ## __VA_ARGS__)
#define _PP_FOR_II_27(DO, SEP, ...) _PP_FOR_II_26(DO, SEP, ## __VA_ARGS__) SEP() DO(27, ## __VA_ARGS__)
#define _PP_FOR_II_28(DO, SEP, ...) _PP_FOR_II_27(DO, SEP, ## __VA_ARGS__) SEP() DO(28, ## __VA_ARGS__)
#define _PP_FOR_II_29(DO, SEP, ...) _PP_FOR_II_28(DO, SEP, ## __VA_ARGS__) SEP() DO(29, ## __VA_ARGS__)
#define _PP_FOR_II_30(DO, SEP, ...) _PP_FOR_II_29(DO, SEP, ## __VA_ARGS__) SEP() DO(30, ## __VA_ARGS__)
#define _PP_FOR_II_31(DO, SEP, ...) _PP_FOR_II_30(DO, SEP, ## __VA_ARGS__) SEP() DO(31, ## __VA_ARGS__)
#define _PP_FOR_II_32(DO, SEP, ...) _PP_FOR_II_31(DO, SEP, ## __VA_ARGS__) SEP() DO(32, ## __VA_ARGS__)
#define _PP_FOR_II_33(DO, SEP, ...) _PP_FOR_II_32(DO, SEP, ## __VA_ARGS__) SEP() DO(33, ## __VA_ARGS__)
#define _PP_FOR_II_34(DO, SEP, ...) _PP_FOR_II_33(DO, SEP, ## __VA_ARGS__) SEP() DO(34, ## __VA_ARGS__)
#define _PP_FOR_II_35(DO, SEP, ...) _PP_FOR_II_34(DO, SEP, ## __VA_ARGS__) SEP() DO(35, ## __VA_ARGS__)
#define _PP_FOR_II_36(DO, SEP, ...) _PP_FOR_II_35(DO, SEP, ## __VA_ARGS__) SEP() DO(36, ## __VA_ARGS__)
#define _PP_FOR_II_37(DO, SEP, ...) _PP_FOR_II_36(DO, SEP, ## __VA_ARGS__) SEP() DO(37, ## __VA_ARGS__)
#define _PP_FOR_II_38(DO, SEP, ...) _PP_FOR_II_37(DO, SEP, ## __VA_ARGS__) SEP() DO(38, ## __VA_ARGS__)
#define _PP_FOR_II_39(DO, SEP, ...) _PP_FOR_II_38(DO, SEP, ## __VA_ARGS__) SEP() DO(39, ## __VA_ARGS__)
#define _PP_FOR_II_40(DO, SEP, ...) _PP_FOR_II_39(DO, SEP, ## __VA_ARGS__) SEP() DO(40, ## __VA_ARGS__)
#define _PP_FOR_II_41(DO, SEP, ...) _PP_FOR_II_40(DO, SEP, ## __VA_ARGS__) SEP() DO(41, ## __VA_ARGS__)
#define _PP_FOR_II_42(DO, SEP, ...) _PP_FOR_II_41(DO, SEP, ## __VA_ARGS__) SEP() DO(42, ## __VA_ARGS__)
#define _PP_FOR_II_43(DO, SEP, ...) _PP_FOR_II_42(DO, SEP, ## __VA_ARGS__) SEP() DO(43, ## __VA_ARGS__)
#define _PP_FOR_II_44(DO, SEP, ...) _PP_FOR_II_43(DO, SEP, ## __VA_ARGS__) SEP() DO(44, ## __VA_ARGS__)
#define _PP_FOR_II_45(DO, SEP, ...) _PP_FOR_II_44(DO, SEP, ## __VA_ARGS__) SEP() DO(45, ## __VA_ARGS__)
#define _PP_FOR_II_46(DO, SEP, ...) _PP_FOR_II_45(DO, SEP, ## __VA_ARGS__) SEP() DO(46, ## __VA_ARGS__)
#define _PP_FOR_II_47(DO, SEP, ...) _PP_FOR_II_46(DO, SEP, ## __VA_ARGS__) SEP() DO(47, ## __VA_ARGS__)
#define _PP_FOR_II_48(DO, SEP, ...) _PP_FOR_II_47(DO, SEP, ## __VA_ARGS__) SEP() DO(48, ## __VA_ARGS__)
#define _PP_FOR_II_49(DO, SEP, ...) _PP_FOR_II_48(DO, SEP, ## __VA_ARGS__) SEP() DO(49, ## __VA_ARGS__)
#define _PP_FOR_II_50(DO, SEP, ...) _PP_FOR_II_49(DO, SEP, ## __VA_ARGS__) SEP() DO(50, ## __VA_ARGS__)
#define _PP_FOR_II_51(DO, SEP, ...) _PP_FOR_II_50(DO, SEP, ## __VA_ARGS__) SEP() DO(51, ## __VA_ARGS__)
#define _PP_FOR_II_52(DO, SEP, ...) _PP_FOR_II_51(DO, SEP, ## __VA_ARGS__) SEP() DO(52, ## __VA_ARGS__)
#define _PP_FOR_II_53(DO, SEP, ...) _PP_FOR_II_52(DO, SEP, ## __VA_ARGS__) SEP() DO(53, ## __VA_ARGS__)
#define _PP_FOR_II_54(DO, SEP, ...) _PP_FOR_II_53(DO, SEP, ## __VA_ARGS__) SEP() DO(54, ## __VA_ARGS__)
#define _PP_FOR_II_55(DO, SEP, ...) _PP_FOR_II_54(DO, SEP, ## __VA_ARGS__) SEP() DO(55, ## __VA_ARGS__)
#define _PP_FOR_II_56(DO, SEP, ...) _PP_FOR_II_55(DO, SEP, ## __VA_ARGS__) SEP() DO(56, ## __VA_ARGS__)
#define _PP_FOR_II_57(DO, SEP, ...) _PP_FOR_II_56(DO, SEP, ## __VA_ARGS__) SEP() DO(57, ## __VA_ARGS__)
#define _PP_FOR_II_58(DO, SEP, ...) _PP_FOR_II_57(DO, SEP, ## __VA_ARGS__) SEP() DO(58, ## __VA_ARGS__)
#define _PP_FOR_II_59(DO, SEP, ...) _PP_FOR_II_58(DO, SEP, ## __VA_ARGS__) SEP() DO(59, ## __VA_ARGS__)
#define _PP_FOR_II_60(DO, SEP, ...) _PP_FOR_II_59(DO, SEP, ## __VA_ARGS__) SEP() DO(60, ## __VA_ARGS__)
#define _PP_FOR_II_61(DO, SEP, ...) _PP_FOR_II_60(DO, SEP, ## __VA_ARGS__) SEP() DO(61, ## __VA_ARGS__)
#define _PP_FOR_II_62(DO, SEP, ...) _PP_FOR_II_61(DO, SEP, ## __VA_ARGS__) SEP() DO(62, ## __VA_ARGS__)
#define _PP_FOR_II_63(DO, SEP, ...) _PP_FOR_II_62(DO, SEP, ## __VA_ARGS__) SEP() DO(63, ## __VA_ARGS__)
#define _PP_FOR_II_64(DO, SEP, ...) _PP_FOR_II_63(DO, SEP, ## __VA_ARGS__) SEP() DO(64, ## __VA_ARGS__)

#endif /* PP_FOR_H_ */
