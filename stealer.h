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
#ifndef STEALER_H_
#define STEALER_H_
#define PP_CAT(x,y) x##y
#define PP_COMMA() ,
#define PP_EMPTY() 
#define PP_EXPAND(x) x
#define PP_EXPAND_CAT(x,y) PP_CAT(x, y)
#define PP_FIRST(...) _PP_FIRST_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define PP_FOR(iters,DO,SEP,...) _PP_FOR_I(iters, DO, SEP, ##__VA_ARGS__)
#define PP_FOR_EACH(DO,SEP,...) _PP_FOR_EACH_I(DO, SEP, ##__VA_ARGS__)
#define PP_FOR_EACH_H_ 
#define PP_FOR_H_ 
#define PP_H_ 
#define PP_IF(cond,DO,...) _PP_IF_I(cond, DO, __VA_ARGS__)
#define PP_IS_EMPTY(...) _PP_IS_EMPTY_I(_PP_IS_EMPTY_HELPER __VA_ARGS__ (),)
#define PP_IS_EMPTY_H_ 
#define PP_IS_TUPLE(...) _PP_IS_TUPLE_I(_PP_IS_TUPLE_HELPER __VA_ARGS__)
#define PP_LAST(...) _PP_LAST_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define PP_LPAREN() (
#define PP_NOT(cond) _PP_NOT_I(cond)
#define PP_OVERRIDE(base,branch,...) _PP_OVERRIDE_I(base, branch, __VA_ARGS__)
#define PP_RPAREN() )
#define PP_SELECT(i,...) _PP_SELECT_I(i, __VA_ARGS__)
#define PP_SELECT_H_ 
#define PP_SEMI() ;
#define PP_SIZE(...) _PP_SIZE_I(_PP_SIZE_II(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, ))
#define PP_SIZE_H_ 
#define PP_TUPLE_H_ 
#define PP_TUPLE_TO_VARS(tuple) _PP_TUPLE_TO_VARS_I(_PP_TUPLE_TO_VARS_II() tuple)
#define PP_UTIL_H_ 
#define STEALER(name,clz,...) _STEALER_I(name, clz, _STEALER_PREPROCESS_ARGS(clz, __VA_ARGS__))
#define STEALER_H_ 
#define STEAL_FIELD(...) (_STEAL_FIELD, __VA_ARGS__)
#define STEAL_METHOD(...) (_STEAL_METHOD, __VA_ARGS__)
#define _PP_FIRST_I(is_empty,...) PP_EXPAND(PP_EXPAND_CAT(_PP_FIRST_II_, is_empty)(__VA_ARGS__))
#define _PP_FIRST_II_0(x,...) x
#define _PP_FIRST_II_1(...) 
#define _PP_FOR_EACH_I(DO,SEP,...) _PP_FOR_PP_EXPAND(_PP_FOR_PP_EXPAND_CAT(_PP_FOR_EACH_II_, PP_SIZE(__VA_ARGS__))(DO, SEP, __VA_ARGS__,))
#define _PP_FOR_EACH_II_0(...) 
#define _PP_FOR_EACH_II_1(DO,SEP,...) DO(1, PP_SELECT(1, __VA_ARGS__))
#define _PP_FOR_EACH_II_10(DO,SEP,...) _PP_FOR_EACH_II_9(DO, SEP, __VA_ARGS__) SEP() DO(10, PP_SELECT(10, __VA_ARGS__))
#define _PP_FOR_EACH_II_11(DO,SEP,...) _PP_FOR_EACH_II_10(DO, SEP, __VA_ARGS__) SEP() DO(11, PP_SELECT(11, __VA_ARGS__))
#define _PP_FOR_EACH_II_12(DO,SEP,...) _PP_FOR_EACH_II_11(DO, SEP, __VA_ARGS__) SEP() DO(12, PP_SELECT(12, __VA_ARGS__))
#define _PP_FOR_EACH_II_13(DO,SEP,...) _PP_FOR_EACH_II_12(DO, SEP, __VA_ARGS__) SEP() DO(13, PP_SELECT(13, __VA_ARGS__))
#define _PP_FOR_EACH_II_14(DO,SEP,...) _PP_FOR_EACH_II_13(DO, SEP, __VA_ARGS__) SEP() DO(14, PP_SELECT(14, __VA_ARGS__))
#define _PP_FOR_EACH_II_15(DO,SEP,...) _PP_FOR_EACH_II_14(DO, SEP, __VA_ARGS__) SEP() DO(15, PP_SELECT(15, __VA_ARGS__))
#define _PP_FOR_EACH_II_16(DO,SEP,...) _PP_FOR_EACH_II_15(DO, SEP, __VA_ARGS__) SEP() DO(16, PP_SELECT(16, __VA_ARGS__))
#define _PP_FOR_EACH_II_17(DO,SEP,...) _PP_FOR_EACH_II_16(DO, SEP, __VA_ARGS__) SEP() DO(17, PP_SELECT(17, __VA_ARGS__))
#define _PP_FOR_EACH_II_18(DO,SEP,...) _PP_FOR_EACH_II_17(DO, SEP, __VA_ARGS__) SEP() DO(18, PP_SELECT(18, __VA_ARGS__))
#define _PP_FOR_EACH_II_19(DO,SEP,...) _PP_FOR_EACH_II_18(DO, SEP, __VA_ARGS__) SEP() DO(19, PP_SELECT(19, __VA_ARGS__))
#define _PP_FOR_EACH_II_2(DO,SEP,...) _PP_FOR_EACH_II_1(DO, SEP, __VA_ARGS__) SEP() DO(2, PP_SELECT(2, __VA_ARGS__))
#define _PP_FOR_EACH_II_20(DO,SEP,...) _PP_FOR_EACH_II_19(DO, SEP, __VA_ARGS__) SEP() DO(20, PP_SELECT(20, __VA_ARGS__))
#define _PP_FOR_EACH_II_21(DO,SEP,...) _PP_FOR_EACH_II_20(DO, SEP, __VA_ARGS__) SEP() DO(21, PP_SELECT(21, __VA_ARGS__))
#define _PP_FOR_EACH_II_22(DO,SEP,...) _PP_FOR_EACH_II_21(DO, SEP, __VA_ARGS__) SEP() DO(22, PP_SELECT(22, __VA_ARGS__))
#define _PP_FOR_EACH_II_23(DO,SEP,...) _PP_FOR_EACH_II_22(DO, SEP, __VA_ARGS__) SEP() DO(23, PP_SELECT(23, __VA_ARGS__))
#define _PP_FOR_EACH_II_24(DO,SEP,...) _PP_FOR_EACH_II_23(DO, SEP, __VA_ARGS__) SEP() DO(24, PP_SELECT(24, __VA_ARGS__))
#define _PP_FOR_EACH_II_25(DO,SEP,...) _PP_FOR_EACH_II_24(DO, SEP, __VA_ARGS__) SEP() DO(25, PP_SELECT(25, __VA_ARGS__))
#define _PP_FOR_EACH_II_26(DO,SEP,...) _PP_FOR_EACH_II_25(DO, SEP, __VA_ARGS__) SEP() DO(26, PP_SELECT(26, __VA_ARGS__))
#define _PP_FOR_EACH_II_27(DO,SEP,...) _PP_FOR_EACH_II_26(DO, SEP, __VA_ARGS__) SEP() DO(27, PP_SELECT(27, __VA_ARGS__))
#define _PP_FOR_EACH_II_28(DO,SEP,...) _PP_FOR_EACH_II_27(DO, SEP, __VA_ARGS__) SEP() DO(28, PP_SELECT(28, __VA_ARGS__))
#define _PP_FOR_EACH_II_29(DO,SEP,...) _PP_FOR_EACH_II_28(DO, SEP, __VA_ARGS__) SEP() DO(29, PP_SELECT(29, __VA_ARGS__))
#define _PP_FOR_EACH_II_3(DO,SEP,...) _PP_FOR_EACH_II_2(DO, SEP, __VA_ARGS__) SEP() DO(3, PP_SELECT(3, __VA_ARGS__))
#define _PP_FOR_EACH_II_30(DO,SEP,...) _PP_FOR_EACH_II_29(DO, SEP, __VA_ARGS__) SEP() DO(30, PP_SELECT(30, __VA_ARGS__))
#define _PP_FOR_EACH_II_31(DO,SEP,...) _PP_FOR_EACH_II_30(DO, SEP, __VA_ARGS__) SEP() DO(31, PP_SELECT(31, __VA_ARGS__))
#define _PP_FOR_EACH_II_32(DO,SEP,...) _PP_FOR_EACH_II_31(DO, SEP, __VA_ARGS__) SEP() DO(32, PP_SELECT(32, __VA_ARGS__))
#define _PP_FOR_EACH_II_33(DO,SEP,...) _PP_FOR_EACH_II_32(DO, SEP, __VA_ARGS__) SEP() DO(33, PP_SELECT(33, __VA_ARGS__))
#define _PP_FOR_EACH_II_34(DO,SEP,...) _PP_FOR_EACH_II_33(DO, SEP, __VA_ARGS__) SEP() DO(34, PP_SELECT(34, __VA_ARGS__))
#define _PP_FOR_EACH_II_35(DO,SEP,...) _PP_FOR_EACH_II_34(DO, SEP, __VA_ARGS__) SEP() DO(35, PP_SELECT(35, __VA_ARGS__))
#define _PP_FOR_EACH_II_36(DO,SEP,...) _PP_FOR_EACH_II_35(DO, SEP, __VA_ARGS__) SEP() DO(36, PP_SELECT(36, __VA_ARGS__))
#define _PP_FOR_EACH_II_37(DO,SEP,...) _PP_FOR_EACH_II_36(DO, SEP, __VA_ARGS__) SEP() DO(37, PP_SELECT(37, __VA_ARGS__))
#define _PP_FOR_EACH_II_38(DO,SEP,...) _PP_FOR_EACH_II_37(DO, SEP, __VA_ARGS__) SEP() DO(38, PP_SELECT(38, __VA_ARGS__))
#define _PP_FOR_EACH_II_39(DO,SEP,...) _PP_FOR_EACH_II_38(DO, SEP, __VA_ARGS__) SEP() DO(39, PP_SELECT(39, __VA_ARGS__))
#define _PP_FOR_EACH_II_4(DO,SEP,...) _PP_FOR_EACH_II_3(DO, SEP, __VA_ARGS__) SEP() DO(4, PP_SELECT(4, __VA_ARGS__))
#define _PP_FOR_EACH_II_40(DO,SEP,...) _PP_FOR_EACH_II_39(DO, SEP, __VA_ARGS__) SEP() DO(40, PP_SELECT(40, __VA_ARGS__))
#define _PP_FOR_EACH_II_41(DO,SEP,...) _PP_FOR_EACH_II_40(DO, SEP, __VA_ARGS__) SEP() DO(41, PP_SELECT(41, __VA_ARGS__))
#define _PP_FOR_EACH_II_42(DO,SEP,...) _PP_FOR_EACH_II_41(DO, SEP, __VA_ARGS__) SEP() DO(42, PP_SELECT(42, __VA_ARGS__))
#define _PP_FOR_EACH_II_43(DO,SEP,...) _PP_FOR_EACH_II_42(DO, SEP, __VA_ARGS__) SEP() DO(43, PP_SELECT(43, __VA_ARGS__))
#define _PP_FOR_EACH_II_44(DO,SEP,...) _PP_FOR_EACH_II_43(DO, SEP, __VA_ARGS__) SEP() DO(44, PP_SELECT(44, __VA_ARGS__))
#define _PP_FOR_EACH_II_45(DO,SEP,...) _PP_FOR_EACH_II_44(DO, SEP, __VA_ARGS__) SEP() DO(45, PP_SELECT(45, __VA_ARGS__))
#define _PP_FOR_EACH_II_46(DO,SEP,...) _PP_FOR_EACH_II_45(DO, SEP, __VA_ARGS__) SEP() DO(46, PP_SELECT(46, __VA_ARGS__))
#define _PP_FOR_EACH_II_47(DO,SEP,...) _PP_FOR_EACH_II_46(DO, SEP, __VA_ARGS__) SEP() DO(47, PP_SELECT(47, __VA_ARGS__))
#define _PP_FOR_EACH_II_48(DO,SEP,...) _PP_FOR_EACH_II_47(DO, SEP, __VA_ARGS__) SEP() DO(48, PP_SELECT(48, __VA_ARGS__))
#define _PP_FOR_EACH_II_49(DO,SEP,...) _PP_FOR_EACH_II_48(DO, SEP, __VA_ARGS__) SEP() DO(49, PP_SELECT(49, __VA_ARGS__))
#define _PP_FOR_EACH_II_5(DO,SEP,...) _PP_FOR_EACH_II_4(DO, SEP, __VA_ARGS__) SEP() DO(5, PP_SELECT(5, __VA_ARGS__))
#define _PP_FOR_EACH_II_50(DO,SEP,...) _PP_FOR_EACH_II_49(DO, SEP, __VA_ARGS__) SEP() DO(50, PP_SELECT(50, __VA_ARGS__))
#define _PP_FOR_EACH_II_51(DO,SEP,...) _PP_FOR_EACH_II_50(DO, SEP, __VA_ARGS__) SEP() DO(51, PP_SELECT(51, __VA_ARGS__))
#define _PP_FOR_EACH_II_52(DO,SEP,...) _PP_FOR_EACH_II_51(DO, SEP, __VA_ARGS__) SEP() DO(52, PP_SELECT(52, __VA_ARGS__))
#define _PP_FOR_EACH_II_53(DO,SEP,...) _PP_FOR_EACH_II_52(DO, SEP, __VA_ARGS__) SEP() DO(53, PP_SELECT(53, __VA_ARGS__))
#define _PP_FOR_EACH_II_54(DO,SEP,...) _PP_FOR_EACH_II_53(DO, SEP, __VA_ARGS__) SEP() DO(54, PP_SELECT(54, __VA_ARGS__))
#define _PP_FOR_EACH_II_55(DO,SEP,...) _PP_FOR_EACH_II_54(DO, SEP, __VA_ARGS__) SEP() DO(55, PP_SELECT(55, __VA_ARGS__))
#define _PP_FOR_EACH_II_56(DO,SEP,...) _PP_FOR_EACH_II_55(DO, SEP, __VA_ARGS__) SEP() DO(56, PP_SELECT(56, __VA_ARGS__))
#define _PP_FOR_EACH_II_57(DO,SEP,...) _PP_FOR_EACH_II_56(DO, SEP, __VA_ARGS__) SEP() DO(57, PP_SELECT(57, __VA_ARGS__))
#define _PP_FOR_EACH_II_58(DO,SEP,...) _PP_FOR_EACH_II_57(DO, SEP, __VA_ARGS__) SEP() DO(58, PP_SELECT(58, __VA_ARGS__))
#define _PP_FOR_EACH_II_59(DO,SEP,...) _PP_FOR_EACH_II_58(DO, SEP, __VA_ARGS__) SEP() DO(59, PP_SELECT(59, __VA_ARGS__))
#define _PP_FOR_EACH_II_6(DO,SEP,...) _PP_FOR_EACH_II_5(DO, SEP, __VA_ARGS__) SEP() DO(6, PP_SELECT(6, __VA_ARGS__))
#define _PP_FOR_EACH_II_60(DO,SEP,...) _PP_FOR_EACH_II_59(DO, SEP, __VA_ARGS__) SEP() DO(60, PP_SELECT(60, __VA_ARGS__))
#define _PP_FOR_EACH_II_61(DO,SEP,...) _PP_FOR_EACH_II_60(DO, SEP, __VA_ARGS__) SEP() DO(61, PP_SELECT(61, __VA_ARGS__))
#define _PP_FOR_EACH_II_62(DO,SEP,...) _PP_FOR_EACH_II_61(DO, SEP, __VA_ARGS__) SEP() DO(62, PP_SELECT(62, __VA_ARGS__))
#define _PP_FOR_EACH_II_63(DO,SEP,...) _PP_FOR_EACH_II_62(DO, SEP, __VA_ARGS__) SEP() DO(63, PP_SELECT(63, __VA_ARGS__))
#define _PP_FOR_EACH_II_64(DO,SEP,...) _PP_FOR_EACH_II_63(DO, SEP, __VA_ARGS__) SEP() DO(64, PP_SELECT(64, __VA_ARGS__))
#define _PP_FOR_EACH_II_7(DO,SEP,...) _PP_FOR_EACH_II_6(DO, SEP, __VA_ARGS__) SEP() DO(7, PP_SELECT(7, __VA_ARGS__))
#define _PP_FOR_EACH_II_8(DO,SEP,...) _PP_FOR_EACH_II_7(DO, SEP, __VA_ARGS__) SEP() DO(8, PP_SELECT(8, __VA_ARGS__))
#define _PP_FOR_EACH_II_9(DO,SEP,...) _PP_FOR_EACH_II_8(DO, SEP, __VA_ARGS__) SEP() DO(9, PP_SELECT(9, __VA_ARGS__))
#define _PP_FOR_I(iters,DO,SEP,...) _PP_FOR_PP_EXPAND(_PP_FOR_PP_EXPAND_CAT(_PP_FOR_II_, iters)(DO, SEP, __VA_ARGS__,))
#define _PP_FOR_II_0(...) 
#define _PP_FOR_II_1(DO,SEP,...) DO(1, ## __VA_ARGS__)
#define _PP_FOR_II_10(DO,SEP,...) _PP_FOR_II_9(DO, SEP, ## __VA_ARGS__) SEP() DO(10, ## __VA_ARGS__)
#define _PP_FOR_II_11(DO,SEP,...) _PP_FOR_II_10(DO, SEP, ## __VA_ARGS__) SEP() DO(11, ## __VA_ARGS__)
#define _PP_FOR_II_12(DO,SEP,...) _PP_FOR_II_11(DO, SEP, ## __VA_ARGS__) SEP() DO(12, ## __VA_ARGS__)
#define _PP_FOR_II_13(DO,SEP,...) _PP_FOR_II_12(DO, SEP, ## __VA_ARGS__) SEP() DO(13, ## __VA_ARGS__)
#define _PP_FOR_II_14(DO,SEP,...) _PP_FOR_II_13(DO, SEP, ## __VA_ARGS__) SEP() DO(14, ## __VA_ARGS__)
#define _PP_FOR_II_15(DO,SEP,...) _PP_FOR_II_14(DO, SEP, ## __VA_ARGS__) SEP() DO(15, ## __VA_ARGS__)
#define _PP_FOR_II_16(DO,SEP,...) _PP_FOR_II_15(DO, SEP, ## __VA_ARGS__) SEP() DO(16, ## __VA_ARGS__)
#define _PP_FOR_II_17(DO,SEP,...) _PP_FOR_II_16(DO, SEP, ## __VA_ARGS__) SEP() DO(17, ## __VA_ARGS__)
#define _PP_FOR_II_18(DO,SEP,...) _PP_FOR_II_17(DO, SEP, ## __VA_ARGS__) SEP() DO(18, ## __VA_ARGS__)
#define _PP_FOR_II_19(DO,SEP,...) _PP_FOR_II_18(DO, SEP, ## __VA_ARGS__) SEP() DO(19, ## __VA_ARGS__)
#define _PP_FOR_II_2(DO,SEP,...) _PP_FOR_II_1(DO, SEP, ## __VA_ARGS__) SEP() DO(2, ## __VA_ARGS__)
#define _PP_FOR_II_20(DO,SEP,...) _PP_FOR_II_19(DO, SEP, ## __VA_ARGS__) SEP() DO(20, ## __VA_ARGS__)
#define _PP_FOR_II_21(DO,SEP,...) _PP_FOR_II_20(DO, SEP, ## __VA_ARGS__) SEP() DO(21, ## __VA_ARGS__)
#define _PP_FOR_II_22(DO,SEP,...) _PP_FOR_II_21(DO, SEP, ## __VA_ARGS__) SEP() DO(22, ## __VA_ARGS__)
#define _PP_FOR_II_23(DO,SEP,...) _PP_FOR_II_22(DO, SEP, ## __VA_ARGS__) SEP() DO(23, ## __VA_ARGS__)
#define _PP_FOR_II_24(DO,SEP,...) _PP_FOR_II_23(DO, SEP, ## __VA_ARGS__) SEP() DO(24, ## __VA_ARGS__)
#define _PP_FOR_II_25(DO,SEP,...) _PP_FOR_II_24(DO, SEP, ## __VA_ARGS__) SEP() DO(25, ## __VA_ARGS__)
#define _PP_FOR_II_26(DO,SEP,...) _PP_FOR_II_25(DO, SEP, ## __VA_ARGS__) SEP() DO(26, ## __VA_ARGS__)
#define _PP_FOR_II_27(DO,SEP,...) _PP_FOR_II_26(DO, SEP, ## __VA_ARGS__) SEP() DO(27, ## __VA_ARGS__)
#define _PP_FOR_II_28(DO,SEP,...) _PP_FOR_II_27(DO, SEP, ## __VA_ARGS__) SEP() DO(28, ## __VA_ARGS__)
#define _PP_FOR_II_29(DO,SEP,...) _PP_FOR_II_28(DO, SEP, ## __VA_ARGS__) SEP() DO(29, ## __VA_ARGS__)
#define _PP_FOR_II_3(DO,SEP,...) _PP_FOR_II_2(DO, SEP, ## __VA_ARGS__) SEP() DO(3, ## __VA_ARGS__)
#define _PP_FOR_II_30(DO,SEP,...) _PP_FOR_II_29(DO, SEP, ## __VA_ARGS__) SEP() DO(30, ## __VA_ARGS__)
#define _PP_FOR_II_31(DO,SEP,...) _PP_FOR_II_30(DO, SEP, ## __VA_ARGS__) SEP() DO(31, ## __VA_ARGS__)
#define _PP_FOR_II_32(DO,SEP,...) _PP_FOR_II_31(DO, SEP, ## __VA_ARGS__) SEP() DO(32, ## __VA_ARGS__)
#define _PP_FOR_II_33(DO,SEP,...) _PP_FOR_II_32(DO, SEP, ## __VA_ARGS__) SEP() DO(33, ## __VA_ARGS__)
#define _PP_FOR_II_34(DO,SEP,...) _PP_FOR_II_33(DO, SEP, ## __VA_ARGS__) SEP() DO(34, ## __VA_ARGS__)
#define _PP_FOR_II_35(DO,SEP,...) _PP_FOR_II_34(DO, SEP, ## __VA_ARGS__) SEP() DO(35, ## __VA_ARGS__)
#define _PP_FOR_II_36(DO,SEP,...) _PP_FOR_II_35(DO, SEP, ## __VA_ARGS__) SEP() DO(36, ## __VA_ARGS__)
#define _PP_FOR_II_37(DO,SEP,...) _PP_FOR_II_36(DO, SEP, ## __VA_ARGS__) SEP() DO(37, ## __VA_ARGS__)
#define _PP_FOR_II_38(DO,SEP,...) _PP_FOR_II_37(DO, SEP, ## __VA_ARGS__) SEP() DO(38, ## __VA_ARGS__)
#define _PP_FOR_II_39(DO,SEP,...) _PP_FOR_II_38(DO, SEP, ## __VA_ARGS__) SEP() DO(39, ## __VA_ARGS__)
#define _PP_FOR_II_4(DO,SEP,...) _PP_FOR_II_3(DO, SEP, ## __VA_ARGS__) SEP() DO(4, ## __VA_ARGS__)
#define _PP_FOR_II_40(DO,SEP,...) _PP_FOR_II_39(DO, SEP, ## __VA_ARGS__) SEP() DO(40, ## __VA_ARGS__)
#define _PP_FOR_II_41(DO,SEP,...) _PP_FOR_II_40(DO, SEP, ## __VA_ARGS__) SEP() DO(41, ## __VA_ARGS__)
#define _PP_FOR_II_42(DO,SEP,...) _PP_FOR_II_41(DO, SEP, ## __VA_ARGS__) SEP() DO(42, ## __VA_ARGS__)
#define _PP_FOR_II_43(DO,SEP,...) _PP_FOR_II_42(DO, SEP, ## __VA_ARGS__) SEP() DO(43, ## __VA_ARGS__)
#define _PP_FOR_II_44(DO,SEP,...) _PP_FOR_II_43(DO, SEP, ## __VA_ARGS__) SEP() DO(44, ## __VA_ARGS__)
#define _PP_FOR_II_45(DO,SEP,...) _PP_FOR_II_44(DO, SEP, ## __VA_ARGS__) SEP() DO(45, ## __VA_ARGS__)
#define _PP_FOR_II_46(DO,SEP,...) _PP_FOR_II_45(DO, SEP, ## __VA_ARGS__) SEP() DO(46, ## __VA_ARGS__)
#define _PP_FOR_II_47(DO,SEP,...) _PP_FOR_II_46(DO, SEP, ## __VA_ARGS__) SEP() DO(47, ## __VA_ARGS__)
#define _PP_FOR_II_48(DO,SEP,...) _PP_FOR_II_47(DO, SEP, ## __VA_ARGS__) SEP() DO(48, ## __VA_ARGS__)
#define _PP_FOR_II_49(DO,SEP,...) _PP_FOR_II_48(DO, SEP, ## __VA_ARGS__) SEP() DO(49, ## __VA_ARGS__)
#define _PP_FOR_II_5(DO,SEP,...) _PP_FOR_II_4(DO, SEP, ## __VA_ARGS__) SEP() DO(5, ## __VA_ARGS__)
#define _PP_FOR_II_50(DO,SEP,...) _PP_FOR_II_49(DO, SEP, ## __VA_ARGS__) SEP() DO(50, ## __VA_ARGS__)
#define _PP_FOR_II_51(DO,SEP,...) _PP_FOR_II_50(DO, SEP, ## __VA_ARGS__) SEP() DO(51, ## __VA_ARGS__)
#define _PP_FOR_II_52(DO,SEP,...) _PP_FOR_II_51(DO, SEP, ## __VA_ARGS__) SEP() DO(52, ## __VA_ARGS__)
#define _PP_FOR_II_53(DO,SEP,...) _PP_FOR_II_52(DO, SEP, ## __VA_ARGS__) SEP() DO(53, ## __VA_ARGS__)
#define _PP_FOR_II_54(DO,SEP,...) _PP_FOR_II_53(DO, SEP, ## __VA_ARGS__) SEP() DO(54, ## __VA_ARGS__)
#define _PP_FOR_II_55(DO,SEP,...) _PP_FOR_II_54(DO, SEP, ## __VA_ARGS__) SEP() DO(55, ## __VA_ARGS__)
#define _PP_FOR_II_56(DO,SEP,...) _PP_FOR_II_55(DO, SEP, ## __VA_ARGS__) SEP() DO(56, ## __VA_ARGS__)
#define _PP_FOR_II_57(DO,SEP,...) _PP_FOR_II_56(DO, SEP, ## __VA_ARGS__) SEP() DO(57, ## __VA_ARGS__)
#define _PP_FOR_II_58(DO,SEP,...) _PP_FOR_II_57(DO, SEP, ## __VA_ARGS__) SEP() DO(58, ## __VA_ARGS__)
#define _PP_FOR_II_59(DO,SEP,...) _PP_FOR_II_58(DO, SEP, ## __VA_ARGS__) SEP() DO(59, ## __VA_ARGS__)
#define _PP_FOR_II_6(DO,SEP,...) _PP_FOR_II_5(DO, SEP, ## __VA_ARGS__) SEP() DO(6, ## __VA_ARGS__)
#define _PP_FOR_II_60(DO,SEP,...) _PP_FOR_II_59(DO, SEP, ## __VA_ARGS__) SEP() DO(60, ## __VA_ARGS__)
#define _PP_FOR_II_61(DO,SEP,...) _PP_FOR_II_60(DO, SEP, ## __VA_ARGS__) SEP() DO(61, ## __VA_ARGS__)
#define _PP_FOR_II_62(DO,SEP,...) _PP_FOR_II_61(DO, SEP, ## __VA_ARGS__) SEP() DO(62, ## __VA_ARGS__)
#define _PP_FOR_II_63(DO,SEP,...) _PP_FOR_II_62(DO, SEP, ## __VA_ARGS__) SEP() DO(63, ## __VA_ARGS__)
#define _PP_FOR_II_64(DO,SEP,...) _PP_FOR_II_63(DO, SEP, ## __VA_ARGS__) SEP() DO(64, ## __VA_ARGS__)
#define _PP_FOR_II_7(DO,SEP,...) _PP_FOR_II_6(DO, SEP, ## __VA_ARGS__) SEP() DO(7, ## __VA_ARGS__)
#define _PP_FOR_II_8(DO,SEP,...) _PP_FOR_II_7(DO, SEP, ## __VA_ARGS__) SEP() DO(8, ## __VA_ARGS__)
#define _PP_FOR_II_9(DO,SEP,...) _PP_FOR_II_8(DO, SEP, ## __VA_ARGS__) SEP() DO(9, ## __VA_ARGS__)
#define _PP_FOR_PP_CAT(x,y) x##y
#define _PP_FOR_PP_EXPAND(x) x
#define _PP_FOR_PP_EXPAND_CAT(x,y) _PP_FOR_PP_CAT(x, y)
#define _PP_IF_I(cond,DO,...) PP_OVERRIDE(_PP_IF_II_, cond, DO, __VA_ARGS__)
#define _PP_IF_III(x) x
#define _PP_IF_II_0(...) 
#define _PP_IF_II_1(DO,...) _PP_IF_III(DO(__VA_ARGS__))
#define _PP_IS_EMPTY_DEF_1 1, PP_EMPTY
#define _PP_IS_EMPTY_DEF__PP_IS_EMPTY_HELPER 0, PP_EMPTY
#define _PP_IS_EMPTY_HELPER() 1
#define _PP_IS_EMPTY_I(test,...) _PP_IS_EMPTY_II( PP_SELECT(1, _PP_IS_EMPTY_PP_EXPAND_CAT(_PP_IS_EMPTY_DEF_, test)))
#define _PP_IS_EMPTY_II(id) id
#define _PP_IS_EMPTY_PP_CAT(x,y) x##y
#define _PP_IS_EMPTY_PP_EXPAND_CAT(x,y,...) _PP_IS_EMPTY_PP_CAT(x, y)
#define _PP_IS_TUPLE_DEF_1 1, PP_EMPTY
#define _PP_IS_TUPLE_DEF__PP_IS_TUPLE_HELPER 0, PP_EMPTY
#define _PP_IS_TUPLE_HELPER(...) 1
#define _PP_IS_TUPLE_I(test,...) _PP_IS_TUPLE_II( PP_SELECT(1, _PP_IS_TUPLE_PP_EXPAND_CAT(_PP_IS_TUPLE_DEF_, test)))
#define _PP_IS_TUPLE_II(x) x
#define _PP_IS_TUPLE_PP_CAT(x,y) x##y
#define _PP_IS_TUPLE_PP_EXPAND_CAT(x,y,...) _PP_IS_TUPLE_PP_CAT(x, y)
#define _PP_LAST_I(is_empty,...) PP_EXPAND(PP_EXPAND_CAT(_PP_LAST_II_, is_empty)(__VA_ARGS__))
#define _PP_LAST_II_0(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)
#define _PP_LAST_II_1(...) 
#define _PP_NOT_I(cond) _PP_NOT_II_##cond
#define _PP_NOT_II_0 1
#define _PP_NOT_II_1 0
#define _PP_OVERRIDE_I(base,branch,...) _PP_OVERRIDE_II(base##branch (__VA_ARGS__))
#define _PP_OVERRIDE_II(x) x
#define _PP_SELECT_I(i,...) _PP_SELECT_PP_EXPAND(_PP_SELECT_PP_EXPAND_CAT(_PP_SELECT_II_, i)(__VA_ARGS__,))
#define _PP_SELECT_II_0(...) 
#define _PP_SELECT_II_1(e0,...) e0
#define _PP_SELECT_II_10(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,...) e9
#define _PP_SELECT_II_11(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,...) e10
#define _PP_SELECT_II_12(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,...) e11
#define _PP_SELECT_II_13(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,...) e12
#define _PP_SELECT_II_14(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,...) e13
#define _PP_SELECT_II_15(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,...) e14
#define _PP_SELECT_II_16(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,...) e15
#define _PP_SELECT_II_17(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,...) e16
#define _PP_SELECT_II_18(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,...) e17
#define _PP_SELECT_II_19(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,...) e18
#define _PP_SELECT_II_2(e0,e1,...) e1
#define _PP_SELECT_II_20(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,...) e19
#define _PP_SELECT_II_21(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,...) e20
#define _PP_SELECT_II_22(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,...) e21
#define _PP_SELECT_II_23(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,...) e22
#define _PP_SELECT_II_24(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,...) e23
#define _PP_SELECT_II_25(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,...) e24
#define _PP_SELECT_II_26(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,...) e25
#define _PP_SELECT_II_27(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,...) e26
#define _PP_SELECT_II_28(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,...) e27
#define _PP_SELECT_II_29(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,...) e28
#define _PP_SELECT_II_3(e0,e1,e2,...) e2
#define _PP_SELECT_II_30(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,...) e29
#define _PP_SELECT_II_31(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,...) e30
#define _PP_SELECT_II_32(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,...) e31
#define _PP_SELECT_II_33(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,...) e32
#define _PP_SELECT_II_34(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,...) e33
#define _PP_SELECT_II_35(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,...) e34
#define _PP_SELECT_II_36(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,...) e35
#define _PP_SELECT_II_37(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,...) e36
#define _PP_SELECT_II_38(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,...) e37
#define _PP_SELECT_II_39(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,...) e38
#define _PP_SELECT_II_4(e0,e1,e2,e3,...) e3
#define _PP_SELECT_II_40(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,...) e39
#define _PP_SELECT_II_41(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,...) e40
#define _PP_SELECT_II_42(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,...) e41
#define _PP_SELECT_II_43(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,...) e42
#define _PP_SELECT_II_44(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,...) e43
#define _PP_SELECT_II_45(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,...) e44
#define _PP_SELECT_II_46(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,...) e45
#define _PP_SELECT_II_47(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,...) e46
#define _PP_SELECT_II_48(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,...) e47
#define _PP_SELECT_II_49(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,...) e48
#define _PP_SELECT_II_5(e0,e1,e2,e3,e4,...) e4
#define _PP_SELECT_II_50(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,...) e49
#define _PP_SELECT_II_51(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,...) e50
#define _PP_SELECT_II_52(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,...) e51
#define _PP_SELECT_II_53(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,...) e52
#define _PP_SELECT_II_54(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,...) e53
#define _PP_SELECT_II_55(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,...) e54
#define _PP_SELECT_II_56(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,...) e55
#define _PP_SELECT_II_57(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,...) e56
#define _PP_SELECT_II_58(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,...) e57
#define _PP_SELECT_II_59(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,...) e58
#define _PP_SELECT_II_6(e0,e1,e2,e3,e4,e5,...) e5
#define _PP_SELECT_II_60(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,...) e59
#define _PP_SELECT_II_61(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,...) e60
#define _PP_SELECT_II_62(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,...) e61
#define _PP_SELECT_II_63(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,...) e62
#define _PP_SELECT_II_64(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,e63,...) e63
#define _PP_SELECT_II_7(e0,e1,e2,e3,e4,e5,e6,...) e6
#define _PP_SELECT_II_8(e0,e1,e2,e3,e4,e5,e6,e7,...) e7
#define _PP_SELECT_II_9(e0,e1,e2,e3,e4,e5,e6,e7,e8,...) e8
#define _PP_SELECT_PP_CAT(x,y) x##y
#define _PP_SELECT_PP_EXPAND(x) x
#define _PP_SELECT_PP_EXPAND_CAT(x,y) _PP_SELECT_PP_CAT(x, y)
#define _PP_SIZE_I(x) x
#define _PP_SIZE_II(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,e63,size,...) size
#define _PP_TUPLE_TO_VARS_I(x) x
#define _PP_TUPLE_TO_VARS_II() _PP_TUPLE_TO_VARS_III
#define _PP_TUPLE_TO_VARS_III(...) __VA_ARGS__
#define _STEALER_ARGS_ONLY_NAMES(...) _STEALER_ARGS_ONLY_NAMES_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _STEALER_ARGS_ONLY_NAMES_DO(i,arg) a##i
#define _STEALER_ARGS_ONLY_NAMES_I(is_empty,...) PP_EXPAND(PP_EXPAND_CAT(_STEALER_ARGS_ONLY_NAMES_II_, is_empty) (__VA_ARGS__))
#define _STEALER_ARGS_ONLY_NAMES_II_0(...) PP_FOR_EACH(_STEALER_ARGS_ONLY_NAMES_DO, PP_COMMA, __VA_ARGS__)
#define _STEALER_ARGS_ONLY_NAMES_II_1(...) 
#define _STEALER_ARGS_WITH_NAMES(...) _STEALER_ARGS_WITH_NAMES_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _STEALER_ARGS_WITH_NAMES_DO(i,arg) arg a##i
#define _STEALER_ARGS_WITH_NAMES_I(is_empty,...) PP_EXPAND(PP_EXPAND_CAT(_STEALER_ARGS_WITH_NAMES_II_, is_empty) (__VA_ARGS__))
#define _STEALER_ARGS_WITH_NAMES_II_0(...) PP_FOR_EACH(_STEALER_ARGS_WITH_NAMES_DO, PP_COMMA, __VA_ARGS__)
#define _STEALER_ARGS_WITH_NAMES_II_1(...) 
#define _STEALER_DECL_FIELDS(...) _STEALER_FILTER_FIELDS(_STEALER_DECL_FIELDS_DO, __VA_ARGS__)
#define _STEALER_DECL_FIELDS_DO(id,clz,type,name) type& name;
#define _STEALER_FIELD_GETTERS(...) _STEALER_FILTER_FIELDS(_STEALER_FIELD_GETTERS_DO, __VA_ARGS__)
#define _STEALER_FIELD_GETTERS_DO(id,clz,type,name) stealer::_STEALER_SLOT(id)::value_type& _stealer##name() { return _obj->*_STEALER_REPRODUCE( (stealer::_STEALER_SLOT(id)*)NULL); }
#define _STEALER_FILTER(CHECK,DO,...) PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_FILTER_DO, PP_EMPTY, CHECK, DO, __VA_ARGS__)
#define _STEALER_FILTER_DO(i,...) PP_EXPAND(_STEALER_FILTER_DO_I(i, __VA_ARGS__))
#define _STEALER_FILTER_DO_I(i,CHECK,DO,...) _STEALER_FILTER_DO_II(CHECK, DO, PP_SELECT(i, __VA_ARGS__))
#define _STEALER_FILTER_DO_II(CHECK,DO,x) PP_IF(PP_IS_TUPLE(x), _STEALER_FILTER_DO_III, CHECK, DO, PP_TUPLE_TO_VARS(x))
#define _STEALER_FILTER_DO_III(CHECK,DO,...) PP_EXPAND(_STEALER_FILTER_DO_IV(CHECK, DO, __VA_ARGS__))
#define _STEALER_FILTER_DO_IV(CHECK,DO,type,...) _STEALER_FILTER_DO_V(PP_EXPAND_CAT(CHECK, type)(), DO, __VA_ARGS__)
#define _STEALER_FILTER_DO_V(cond,DO,...) PP_EXPAND(PP_EXPAND_CAT(_STEALER_FILTER_DO_VI_, cond)(DO, __VA_ARGS__))
#define _STEALER_FILTER_DO_VI_0(...) 
#define _STEALER_FILTER_DO_VI_1(DO,...) PP_EXPAND(PP_CAT(DO,)(__VA_ARGS__))
#define _STEALER_FILTER_FIELDS(DO,...) _STEALER_FILTER(_STEALER_IS_FIELD, DO, __VA_ARGS__)
#define _STEALER_FILTER_METHODS(DO,...) _STEALER_FILTER(_STEALER_IS_METHOD, DO, __VA_ARGS__)
#define _STEALER_I(name,clz,...) namespace stealer { template <typename Slot, typename Slot::shape Key> struct _STEALER_MOULD { friend typename Slot::shape _STEALER_REPRODUCE(Slot*) { return Key; } }; _STEALER_PREPARE_FIELDS(__VA_ARGS__) _STEALER_PREPARE_METHODS(__VA_ARGS__) } class name { typedef clz clz_type; clz_type* _obj; public: explicit name(clz_type* obj) : _obj(obj) _STEALER_INITIALIZOR(__VA_ARGS__) {} explicit name(clz_type& obj) : _obj(&obj) _STEALER_INITIALIZOR(__VA_ARGS__) {} _STEALER_DECL_FIELDS(__VA_ARGS__) _STEALER_FIELD_GETTERS(__VA_ARGS__) _STEALER_METHODS(__VA_ARGS__) }
#define _STEALER_INITIALIZOR(...) _STEALER_FILTER_FIELDS(_STEALER_INITIALIZOR_DO, __VA_ARGS__)
#define _STEALER_INITIALIZOR_DO(id,clz,type,name) , name(_stealer##name())
#define _STEALER_IS_FIELD_STEAL_FIELD(...) 1
#define _STEALER_IS_FIELD_STEAL_METHOD(...) 0
#define _STEALER_IS_METHOD_STEAL_FIELD(...) 0
#define _STEALER_IS_METHOD_STEAL_METHOD(...) 1
#define _STEALER_METHODS(...) _STEALER_FILTER_METHODS(_STEALER_METHOD_DO, __VA_ARGS__)
#define _STEALER_METHOD_DO(id,clz,ret_type,name,...) stealer::_STEALER_SLOT(id)::return_type name( _STEALER_ARGS_WITH_NAMES(__VA_ARGS__)) { return (_obj->*_STEALER_REPRODUCE( (stealer::_STEALER_SLOT(id)*)NULL)) (_STEALER_ARGS_ONLY_NAMES(__VA_ARGS__)); }
#define _STEALER_MOULD _STEALER_MOULD_I(__LINE__)
#define _STEALER_MOULD_I(line) _STEALER_MOULD_II(line)
#define _STEALER_MOULD_II(line) _mould_##line
#define _STEALER_PREPARE_FIELDS(...) _STEALER_FILTER_FIELDS(_STEALER_PREPARE_FIELD_DO, __VA_ARGS__)
#define _STEALER_PREPARE_FIELD_DO(id,clz,type,name) struct _STEALER_SLOT(id) { typedef type value_type; typedef value_type(clz::*shape); friend shape _STEALER_REPRODUCE(_STEALER_SLOT(id)*); }; template struct stealer::_STEALER_MOULD<_STEALER_SLOT(id), &clz::name>;
#define _STEALER_PREPARE_METHODS(...) _STEALER_FILTER_METHODS(_STEALER_PREPARE_METHOD_DO, __VA_ARGS__)
#define _STEALER_PREPARE_METHOD_DO(id,clz,ret_type,name,...) struct _STEALER_SLOT(id) { typedef ret_type return_type; typedef ret_type(clz::*shape)(__VA_ARGS__); friend shape _STEALER_REPRODUCE(_STEALER_SLOT(id)*); }; template struct stealer::_STEALER_MOULD<_STEALER_SLOT(id), &clz::name>;
#define _STEALER_PREPROCESS_ARGS(clz,...) PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_PREPROCESS_ARGS_DO, PP_COMMA, clz, __VA_ARGS__)
#define _STEALER_PREPROCESS_ARGS_DO(i,...) _STEALER_PREPROCESS_ARGS_DO_I( _STEALER_PREPROCESS_ARGS_DO_II(i, __VA_ARGS__))
#define _STEALER_PREPROCESS_ARGS_DO_I(...) __VA_ARGS__
#define _STEALER_PREPROCESS_ARGS_DO_II(i,clz,...) PP_IF(PP_IS_TUPLE(PP_SELECT(i, __VA_ARGS__)), _STEALER_PREPROCESS_ARGS_DO_III, i, clz, PP_TUPLE_TO_VARS(PP_SELECT(i, __VA_ARGS__)))
#define _STEALER_PREPROCESS_ARGS_DO_III(id,clz,...) PP_EXPAND(_STEALER_PREPROCESS_ARGS_DO_IV(id, clz, __VA_ARGS__))
#define _STEALER_PREPROCESS_ARGS_DO_IV(id,clz,type,...) (type, id, clz, __VA_ARGS__)
#define _STEALER_REPRODUCE _STEALER_REPRODUCE_I(__LINE__)
#define _STEALER_REPRODUCE_I(line) _STEALER_REPRODUCE_II(line)
#define _STEALER_REPRODUCE_II(line) __reproduce_##line
#define _STEALER_SLOT(id) _STEALER_SLOT_I(id, __LINE__)
#define _STEALER_SLOT_I(id,line) _STEALER_SLOT_II(id, line)
#define _STEALER_SLOT_II(id,line) _slot_##id##_##line


#endif
