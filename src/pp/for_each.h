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
 * for_each.h
 *
 *  Created on: 2014-11-6
 *      Author: jianxiongzhou
 */

#ifndef PP_FOR_EACH_H_
#define PP_FOR_EACH_H_

#include "select.h"

// std::string SEP() {return ",";}
// std::string DO(size_t i, std::string str) {return "xxx";}
// std::string result = "";
// std::vector<std::string> args = __VA_ARGS__;
// size_t size = args.size();
// for (int i = 1; i <= size; i++) {
//   result += DO(i, args[i]);
//   if (i != size) { result += SEP(); }
// }
#define PP_FOR_EACH(DO, SEP, ...) \
        _PP_FOR_EACH_I(DO, SEP, ##__VA_ARGS__)

#define _PP_FOR_EACH_I(DO, SEP, ...) _PP_FOR_PP_EXPAND(_PP_FOR_PP_EXPAND_CAT(_PP_FOR_EACH_II_, PP_SIZE(__VA_ARGS__))(DO, SEP, __VA_ARGS__,))

// redefine PP_EXPAND() and PP_EXPAND_CAT(), to avoid recursive expanding
#define _PP_FOR_PP_EXPAND(x) x
#define _PP_FOR_PP_CAT(x, y) x##y
#define _PP_FOR_PP_EXPAND_CAT(x, y) _PP_FOR_PP_CAT(x, y)

#define _PP_FOR_EACH_II_0(...)
#define _PP_FOR_EACH_II_1(DO,  SEP, ...) DO(1, PP_SELECT(1,  __VA_ARGS__))
#define _PP_FOR_EACH_II_2(DO,  SEP, ...) _PP_FOR_EACH_II_1(DO,  SEP, __VA_ARGS__) SEP() DO(2,  PP_SELECT(2,  __VA_ARGS__))
#define _PP_FOR_EACH_II_3(DO,  SEP, ...) _PP_FOR_EACH_II_2(DO,  SEP, __VA_ARGS__) SEP() DO(3,  PP_SELECT(3,  __VA_ARGS__))
#define _PP_FOR_EACH_II_4(DO,  SEP, ...) _PP_FOR_EACH_II_3(DO,  SEP, __VA_ARGS__) SEP() DO(4,  PP_SELECT(4,  __VA_ARGS__))
#define _PP_FOR_EACH_II_5(DO,  SEP, ...) _PP_FOR_EACH_II_4(DO,  SEP, __VA_ARGS__) SEP() DO(5,  PP_SELECT(5,  __VA_ARGS__))
#define _PP_FOR_EACH_II_6(DO,  SEP, ...) _PP_FOR_EACH_II_5(DO,  SEP, __VA_ARGS__) SEP() DO(6,  PP_SELECT(6,  __VA_ARGS__))
#define _PP_FOR_EACH_II_7(DO,  SEP, ...) _PP_FOR_EACH_II_6(DO,  SEP, __VA_ARGS__) SEP() DO(7,  PP_SELECT(7,  __VA_ARGS__))
#define _PP_FOR_EACH_II_8(DO,  SEP, ...) _PP_FOR_EACH_II_7(DO,  SEP, __VA_ARGS__) SEP() DO(8,  PP_SELECT(8,  __VA_ARGS__))
#define _PP_FOR_EACH_II_9(DO,  SEP, ...) _PP_FOR_EACH_II_8(DO,  SEP, __VA_ARGS__) SEP() DO(9,  PP_SELECT(9,  __VA_ARGS__))
#define _PP_FOR_EACH_II_10(DO, SEP, ...) _PP_FOR_EACH_II_9(DO,  SEP, __VA_ARGS__) SEP() DO(10, PP_SELECT(10, __VA_ARGS__))
#define _PP_FOR_EACH_II_11(DO, SEP, ...) _PP_FOR_EACH_II_10(DO, SEP, __VA_ARGS__) SEP() DO(11, PP_SELECT(11, __VA_ARGS__))
#define _PP_FOR_EACH_II_12(DO, SEP, ...) _PP_FOR_EACH_II_11(DO, SEP, __VA_ARGS__) SEP() DO(12, PP_SELECT(12, __VA_ARGS__))
#define _PP_FOR_EACH_II_13(DO, SEP, ...) _PP_FOR_EACH_II_12(DO, SEP, __VA_ARGS__) SEP() DO(13, PP_SELECT(13, __VA_ARGS__))
#define _PP_FOR_EACH_II_14(DO, SEP, ...) _PP_FOR_EACH_II_13(DO, SEP, __VA_ARGS__) SEP() DO(14, PP_SELECT(14, __VA_ARGS__))
#define _PP_FOR_EACH_II_15(DO, SEP, ...) _PP_FOR_EACH_II_14(DO, SEP, __VA_ARGS__) SEP() DO(15, PP_SELECT(15, __VA_ARGS__))
#define _PP_FOR_EACH_II_16(DO, SEP, ...) _PP_FOR_EACH_II_15(DO, SEP, __VA_ARGS__) SEP() DO(16, PP_SELECT(16, __VA_ARGS__))
#define _PP_FOR_EACH_II_17(DO, SEP, ...) _PP_FOR_EACH_II_16(DO, SEP, __VA_ARGS__) SEP() DO(17, PP_SELECT(17, __VA_ARGS__))
#define _PP_FOR_EACH_II_18(DO, SEP, ...) _PP_FOR_EACH_II_17(DO, SEP, __VA_ARGS__) SEP() DO(18, PP_SELECT(18, __VA_ARGS__))
#define _PP_FOR_EACH_II_19(DO, SEP, ...) _PP_FOR_EACH_II_18(DO, SEP, __VA_ARGS__) SEP() DO(19, PP_SELECT(19, __VA_ARGS__))
#define _PP_FOR_EACH_II_20(DO, SEP, ...) _PP_FOR_EACH_II_19(DO, SEP, __VA_ARGS__) SEP() DO(20, PP_SELECT(20, __VA_ARGS__))
#define _PP_FOR_EACH_II_21(DO, SEP, ...) _PP_FOR_EACH_II_20(DO, SEP, __VA_ARGS__) SEP() DO(21, PP_SELECT(21, __VA_ARGS__))
#define _PP_FOR_EACH_II_22(DO, SEP, ...) _PP_FOR_EACH_II_21(DO, SEP, __VA_ARGS__) SEP() DO(22, PP_SELECT(22, __VA_ARGS__))
#define _PP_FOR_EACH_II_23(DO, SEP, ...) _PP_FOR_EACH_II_22(DO, SEP, __VA_ARGS__) SEP() DO(23, PP_SELECT(23, __VA_ARGS__))
#define _PP_FOR_EACH_II_24(DO, SEP, ...) _PP_FOR_EACH_II_23(DO, SEP, __VA_ARGS__) SEP() DO(24, PP_SELECT(24, __VA_ARGS__))
#define _PP_FOR_EACH_II_25(DO, SEP, ...) _PP_FOR_EACH_II_24(DO, SEP, __VA_ARGS__) SEP() DO(25, PP_SELECT(25, __VA_ARGS__))
#define _PP_FOR_EACH_II_26(DO, SEP, ...) _PP_FOR_EACH_II_25(DO, SEP, __VA_ARGS__) SEP() DO(26, PP_SELECT(26, __VA_ARGS__))
#define _PP_FOR_EACH_II_27(DO, SEP, ...) _PP_FOR_EACH_II_26(DO, SEP, __VA_ARGS__) SEP() DO(27, PP_SELECT(27, __VA_ARGS__))
#define _PP_FOR_EACH_II_28(DO, SEP, ...) _PP_FOR_EACH_II_27(DO, SEP, __VA_ARGS__) SEP() DO(28, PP_SELECT(28, __VA_ARGS__))
#define _PP_FOR_EACH_II_29(DO, SEP, ...) _PP_FOR_EACH_II_28(DO, SEP, __VA_ARGS__) SEP() DO(29, PP_SELECT(29, __VA_ARGS__))
#define _PP_FOR_EACH_II_30(DO, SEP, ...) _PP_FOR_EACH_II_29(DO, SEP, __VA_ARGS__) SEP() DO(30, PP_SELECT(30, __VA_ARGS__))
#define _PP_FOR_EACH_II_31(DO, SEP, ...) _PP_FOR_EACH_II_30(DO, SEP, __VA_ARGS__) SEP() DO(31, PP_SELECT(31, __VA_ARGS__))
#define _PP_FOR_EACH_II_32(DO, SEP, ...) _PP_FOR_EACH_II_31(DO, SEP, __VA_ARGS__) SEP() DO(32, PP_SELECT(32, __VA_ARGS__))
#define _PP_FOR_EACH_II_33(DO, SEP, ...) _PP_FOR_EACH_II_32(DO, SEP, __VA_ARGS__) SEP() DO(33, PP_SELECT(33, __VA_ARGS__))
#define _PP_FOR_EACH_II_34(DO, SEP, ...) _PP_FOR_EACH_II_33(DO, SEP, __VA_ARGS__) SEP() DO(34, PP_SELECT(34, __VA_ARGS__))
#define _PP_FOR_EACH_II_35(DO, SEP, ...) _PP_FOR_EACH_II_34(DO, SEP, __VA_ARGS__) SEP() DO(35, PP_SELECT(35, __VA_ARGS__))
#define _PP_FOR_EACH_II_36(DO, SEP, ...) _PP_FOR_EACH_II_35(DO, SEP, __VA_ARGS__) SEP() DO(36, PP_SELECT(36, __VA_ARGS__))
#define _PP_FOR_EACH_II_37(DO, SEP, ...) _PP_FOR_EACH_II_36(DO, SEP, __VA_ARGS__) SEP() DO(37, PP_SELECT(37, __VA_ARGS__))
#define _PP_FOR_EACH_II_38(DO, SEP, ...) _PP_FOR_EACH_II_37(DO, SEP, __VA_ARGS__) SEP() DO(38, PP_SELECT(38, __VA_ARGS__))
#define _PP_FOR_EACH_II_39(DO, SEP, ...) _PP_FOR_EACH_II_38(DO, SEP, __VA_ARGS__) SEP() DO(39, PP_SELECT(39, __VA_ARGS__))
#define _PP_FOR_EACH_II_40(DO, SEP, ...) _PP_FOR_EACH_II_39(DO, SEP, __VA_ARGS__) SEP() DO(40, PP_SELECT(40, __VA_ARGS__))
#define _PP_FOR_EACH_II_41(DO, SEP, ...) _PP_FOR_EACH_II_40(DO, SEP, __VA_ARGS__) SEP() DO(41, PP_SELECT(41, __VA_ARGS__))
#define _PP_FOR_EACH_II_42(DO, SEP, ...) _PP_FOR_EACH_II_41(DO, SEP, __VA_ARGS__) SEP() DO(42, PP_SELECT(42, __VA_ARGS__))
#define _PP_FOR_EACH_II_43(DO, SEP, ...) _PP_FOR_EACH_II_42(DO, SEP, __VA_ARGS__) SEP() DO(43, PP_SELECT(43, __VA_ARGS__))
#define _PP_FOR_EACH_II_44(DO, SEP, ...) _PP_FOR_EACH_II_43(DO, SEP, __VA_ARGS__) SEP() DO(44, PP_SELECT(44, __VA_ARGS__))
#define _PP_FOR_EACH_II_45(DO, SEP, ...) _PP_FOR_EACH_II_44(DO, SEP, __VA_ARGS__) SEP() DO(45, PP_SELECT(45, __VA_ARGS__))
#define _PP_FOR_EACH_II_46(DO, SEP, ...) _PP_FOR_EACH_II_45(DO, SEP, __VA_ARGS__) SEP() DO(46, PP_SELECT(46, __VA_ARGS__))
#define _PP_FOR_EACH_II_47(DO, SEP, ...) _PP_FOR_EACH_II_46(DO, SEP, __VA_ARGS__) SEP() DO(47, PP_SELECT(47, __VA_ARGS__))
#define _PP_FOR_EACH_II_48(DO, SEP, ...) _PP_FOR_EACH_II_47(DO, SEP, __VA_ARGS__) SEP() DO(48, PP_SELECT(48, __VA_ARGS__))
#define _PP_FOR_EACH_II_49(DO, SEP, ...) _PP_FOR_EACH_II_48(DO, SEP, __VA_ARGS__) SEP() DO(49, PP_SELECT(49, __VA_ARGS__))
#define _PP_FOR_EACH_II_50(DO, SEP, ...) _PP_FOR_EACH_II_49(DO, SEP, __VA_ARGS__) SEP() DO(50, PP_SELECT(50, __VA_ARGS__))
#define _PP_FOR_EACH_II_51(DO, SEP, ...) _PP_FOR_EACH_II_50(DO, SEP, __VA_ARGS__) SEP() DO(51, PP_SELECT(51, __VA_ARGS__))
#define _PP_FOR_EACH_II_52(DO, SEP, ...) _PP_FOR_EACH_II_51(DO, SEP, __VA_ARGS__) SEP() DO(52, PP_SELECT(52, __VA_ARGS__))
#define _PP_FOR_EACH_II_53(DO, SEP, ...) _PP_FOR_EACH_II_52(DO, SEP, __VA_ARGS__) SEP() DO(53, PP_SELECT(53, __VA_ARGS__))
#define _PP_FOR_EACH_II_54(DO, SEP, ...) _PP_FOR_EACH_II_53(DO, SEP, __VA_ARGS__) SEP() DO(54, PP_SELECT(54, __VA_ARGS__))
#define _PP_FOR_EACH_II_55(DO, SEP, ...) _PP_FOR_EACH_II_54(DO, SEP, __VA_ARGS__) SEP() DO(55, PP_SELECT(55, __VA_ARGS__))
#define _PP_FOR_EACH_II_56(DO, SEP, ...) _PP_FOR_EACH_II_55(DO, SEP, __VA_ARGS__) SEP() DO(56, PP_SELECT(56, __VA_ARGS__))
#define _PP_FOR_EACH_II_57(DO, SEP, ...) _PP_FOR_EACH_II_56(DO, SEP, __VA_ARGS__) SEP() DO(57, PP_SELECT(57, __VA_ARGS__))
#define _PP_FOR_EACH_II_58(DO, SEP, ...) _PP_FOR_EACH_II_57(DO, SEP, __VA_ARGS__) SEP() DO(58, PP_SELECT(58, __VA_ARGS__))
#define _PP_FOR_EACH_II_59(DO, SEP, ...) _PP_FOR_EACH_II_58(DO, SEP, __VA_ARGS__) SEP() DO(59, PP_SELECT(59, __VA_ARGS__))
#define _PP_FOR_EACH_II_60(DO, SEP, ...) _PP_FOR_EACH_II_59(DO, SEP, __VA_ARGS__) SEP() DO(60, PP_SELECT(60, __VA_ARGS__))
#define _PP_FOR_EACH_II_61(DO, SEP, ...) _PP_FOR_EACH_II_60(DO, SEP, __VA_ARGS__) SEP() DO(61, PP_SELECT(61, __VA_ARGS__))
#define _PP_FOR_EACH_II_62(DO, SEP, ...) _PP_FOR_EACH_II_61(DO, SEP, __VA_ARGS__) SEP() DO(62, PP_SELECT(62, __VA_ARGS__))
#define _PP_FOR_EACH_II_63(DO, SEP, ...) _PP_FOR_EACH_II_62(DO, SEP, __VA_ARGS__) SEP() DO(63, PP_SELECT(63, __VA_ARGS__))
#define _PP_FOR_EACH_II_64(DO, SEP, ...) _PP_FOR_EACH_II_63(DO, SEP, __VA_ARGS__) SEP() DO(64, PP_SELECT(64, __VA_ARGS__))

#endif /* PP_FOR_EACH_H_ */
