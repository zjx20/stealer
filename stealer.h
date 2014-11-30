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
#define PP_AS_SINGLE(...) __VA_ARGS__
#define PP_CAT(x,y) x##y
#define PP_COMMA() ,
#define PP_DEC(n) _PP_DEC_I(n)
#define PP_DEC_H_ 
#define PP_EMPTY() 
#define PP_EXPAND(x) x
#define PP_EXPAND_CAT(x,y) PP_CAT(x, y)
#define PP_FIRST(...) _PP_FIRST_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define PP_FOR(iters,DO,SEP,...) _PP_FOR_I(iters(DO, SEP, ##__VA_ARGS__))
#define PP_FOR_EACH(DO,SEP,...) _PP_FOR_EACH_I(PP_SIZE(__VA_ARGS__)(DO, SEP, ##__VA_ARGS__))
#define PP_FOR_EACH_H_ 
#define PP_FOR_H_ 
#define PP_H_ 
#define PP_IS_EMPTY(...) _PP_IS_EMPTY_I(__VA_ARGS__ _PP_IS_EMPTY_HELPER)
#define PP_IS_EMPTY_H_ 
#define PP_LAST(...) _PP_LAST_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define PP_LPAREN() (
#define PP_REMOVE_TAIL_COMMA(...) _PP_REMOVE_TAIL_COMMA_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define PP_RPAREN() )
#define PP_SELECT(i,...) _PP_SELECT_I(i(__VA_ARGS__))
#define PP_SELECT_H_ 
#define PP_SEMI() ;
#define PP_SIZE(...) _PP_SIZE_I(__VA_ARGS__, 64, 63, 62, 61, 60, 59, 58, 57, 56, 55, 54, 53, 52, 51, 50, 49, 48, 47, 46, 45, 44, 43, 42, 41, 40, 39, 38, 37, 36, 35, 34, 33, 32, 31, 30, 29, 28, 27, 26, 25, 24, 23, 22, 21, 20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1,)
#define PP_SIZE_H_ 
#define PP_UTIL_H_ 
#define STEALER(name,clz,...) _STEALER_I(name, clz, _STEALER_PREAPPEND_ARGS(clz, PP_REMOVE_TAIL_COMMA(__VA_ARGS__)))
#define STEALER_H_ 
#define _PP_DEC_I(n) _PP_DEC_II_##n
#define _PP_DEC_II_1 0
#define _PP_DEC_II_10 9
#define _PP_DEC_II_11 10
#define _PP_DEC_II_12 11
#define _PP_DEC_II_13 12
#define _PP_DEC_II_14 13
#define _PP_DEC_II_15 14
#define _PP_DEC_II_16 15
#define _PP_DEC_II_17 16
#define _PP_DEC_II_18 17
#define _PP_DEC_II_19 18
#define _PP_DEC_II_2 1
#define _PP_DEC_II_20 19
#define _PP_DEC_II_21 20
#define _PP_DEC_II_22 21
#define _PP_DEC_II_23 22
#define _PP_DEC_II_24 23
#define _PP_DEC_II_25 24
#define _PP_DEC_II_26 25
#define _PP_DEC_II_27 26
#define _PP_DEC_II_28 27
#define _PP_DEC_II_29 28
#define _PP_DEC_II_3 2
#define _PP_DEC_II_30 29
#define _PP_DEC_II_31 30
#define _PP_DEC_II_32 31
#define _PP_DEC_II_33 32
#define _PP_DEC_II_34 33
#define _PP_DEC_II_35 34
#define _PP_DEC_II_36 35
#define _PP_DEC_II_37 36
#define _PP_DEC_II_38 37
#define _PP_DEC_II_39 38
#define _PP_DEC_II_4 3
#define _PP_DEC_II_40 39
#define _PP_DEC_II_41 40
#define _PP_DEC_II_42 41
#define _PP_DEC_II_43 42
#define _PP_DEC_II_44 43
#define _PP_DEC_II_45 44
#define _PP_DEC_II_46 45
#define _PP_DEC_II_47 46
#define _PP_DEC_II_48 47
#define _PP_DEC_II_49 48
#define _PP_DEC_II_5 4
#define _PP_DEC_II_50 49
#define _PP_DEC_II_51 50
#define _PP_DEC_II_52 51
#define _PP_DEC_II_53 52
#define _PP_DEC_II_54 53
#define _PP_DEC_II_55 54
#define _PP_DEC_II_56 55
#define _PP_DEC_II_57 56
#define _PP_DEC_II_58 57
#define _PP_DEC_II_59 58
#define _PP_DEC_II_6 5
#define _PP_DEC_II_60 59
#define _PP_DEC_II_61 60
#define _PP_DEC_II_62 61
#define _PP_DEC_II_63 62
#define _PP_DEC_II_64 63
#define _PP_DEC_II_7 6
#define _PP_DEC_II_8 7
#define _PP_DEC_II_9 8
#define _PP_FIRST_I(x) _PP_FIRST_II(x)
#define _PP_FIRST_II(x) _PP_FIRST_II_##x
#define _PP_FIRST_II_0(x,...) x
#define _PP_FIRST_II_1(...) 
#define _PP_FOR_EACH_I(x) _PP_FOR_EACH_II(x)
#define _PP_FOR_EACH_II(x) _PP_FOR_EACH_II_##x
#define _PP_FOR_EACH_II_0(...) 
#define _PP_FOR_EACH_II_1(DO,SEP,arg,...) DO(1, arg)
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
#define _PP_FOR_I(x) _PP_FOR_II(x)
#define _PP_FOR_II(x) _PP_FOR_II_##x
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
#define _PP_IS_EMPTY_DEF_PP_IS_EMPTY_HELPER() 1, 1
#define _PP_IS_EMPTY_HELPER() , 0
#define _PP_IS_EMPTY_I(...) _PP_IS_EMPTY_II(_PP_IS_EMPTY_DEF ## __VA_ARGS__())
#define _PP_IS_EMPTY_II(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)
#define _PP_IS_EMPTY_II_0 1
#define _PP_IS_EMPTY_II_1 0
#define _PP_IS_EMPTY_II_10 0
#define _PP_IS_EMPTY_II_11 0
#define _PP_IS_EMPTY_II_12 0
#define _PP_IS_EMPTY_II_13 0
#define _PP_IS_EMPTY_II_14 0
#define _PP_IS_EMPTY_II_15 0
#define _PP_IS_EMPTY_II_16 0
#define _PP_IS_EMPTY_II_17 0
#define _PP_IS_EMPTY_II_18 0
#define _PP_IS_EMPTY_II_19 0
#define _PP_IS_EMPTY_II_2 0
#define _PP_IS_EMPTY_II_20 0
#define _PP_IS_EMPTY_II_21 0
#define _PP_IS_EMPTY_II_22 0
#define _PP_IS_EMPTY_II_23 0
#define _PP_IS_EMPTY_II_24 0
#define _PP_IS_EMPTY_II_25 0
#define _PP_IS_EMPTY_II_26 0
#define _PP_IS_EMPTY_II_27 0
#define _PP_IS_EMPTY_II_28 0
#define _PP_IS_EMPTY_II_29 0
#define _PP_IS_EMPTY_II_3 0
#define _PP_IS_EMPTY_II_30 0
#define _PP_IS_EMPTY_II_31 0
#define _PP_IS_EMPTY_II_32 0
#define _PP_IS_EMPTY_II_33 0
#define _PP_IS_EMPTY_II_34 0
#define _PP_IS_EMPTY_II_35 0
#define _PP_IS_EMPTY_II_36 0
#define _PP_IS_EMPTY_II_37 0
#define _PP_IS_EMPTY_II_38 0
#define _PP_IS_EMPTY_II_39 0
#define _PP_IS_EMPTY_II_4 0
#define _PP_IS_EMPTY_II_40 0
#define _PP_IS_EMPTY_II_41 0
#define _PP_IS_EMPTY_II_42 0
#define _PP_IS_EMPTY_II_43 0
#define _PP_IS_EMPTY_II_44 0
#define _PP_IS_EMPTY_II_45 0
#define _PP_IS_EMPTY_II_46 0
#define _PP_IS_EMPTY_II_47 0
#define _PP_IS_EMPTY_II_48 0
#define _PP_IS_EMPTY_II_49 0
#define _PP_IS_EMPTY_II_5 0
#define _PP_IS_EMPTY_II_50 0
#define _PP_IS_EMPTY_II_51 0
#define _PP_IS_EMPTY_II_52 0
#define _PP_IS_EMPTY_II_53 0
#define _PP_IS_EMPTY_II_54 0
#define _PP_IS_EMPTY_II_55 0
#define _PP_IS_EMPTY_II_56 0
#define _PP_IS_EMPTY_II_57 0
#define _PP_IS_EMPTY_II_58 0
#define _PP_IS_EMPTY_II_59 0
#define _PP_IS_EMPTY_II_6 0
#define _PP_IS_EMPTY_II_60 0
#define _PP_IS_EMPTY_II_61 0
#define _PP_IS_EMPTY_II_62 0
#define _PP_IS_EMPTY_II_63 0
#define _PP_IS_EMPTY_II_64 0
#define _PP_IS_EMPTY_II_7 0
#define _PP_IS_EMPTY_II_8 0
#define _PP_IS_EMPTY_II_9 0
#define _PP_LAST_I(x) _PP_LAST_II(x)
#define _PP_LAST_II(x) _PP_LAST_II_##x
#define _PP_LAST_II_0(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)
#define _PP_LAST_II_1(...) 
#define _PP_REMOVE_TAIL_COMMA_FOR_DO(i,...) PP_SELECT(i, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_I(is_empty,...) _PP_REMOVE_TAIL_COMMA_II(is_empty, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_II(is_empty,...) _PP_REMOVE_TAIL_COMMA_II_##is_empty(__VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_III(is_empty,...) _PP_REMOVE_TAIL_COMMA_IIII(is_empty, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_IIII(is_empty,...) _PP_REMOVE_TAIL_COMMA_IIII_##is_empty(__VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_IIII_0(...) __VA_ARGS__
#define _PP_REMOVE_TAIL_COMMA_IIII_1(...) PP_FOR(PP_DEC(PP_SIZE(__VA_ARGS__)), _PP_REMOVE_TAIL_COMMA_FOR_DO, PP_COMMA, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_II_0(...) _PP_REMOVE_TAIL_COMMA_III( PP_IS_EMPTY(PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)), __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_II_1(...) __VA_ARGS__
#define _PP_SELECT_I(x) _PP_SELECT_II(x)
#define _PP_SELECT_II(x) _PP_SELECT_II_##x
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
#define _PP_SIZE_I(e0,e1,e2,e3,e4,e5,e6,e7,e8,e9,e10,e11,e12,e13,e14,e15,e16,e17,e18,e19,e20,e21,e22,e23,e24,e25,e26,e27,e28,e29,e30,e31,e32,e33,e34,e35,e36,e37,e38,e39,e40,e41,e42,e43,e44,e45,e46,e47,e48,e49,e50,e51,e52,e53,e54,e55,e56,e57,e58,e59,e60,e61,e62,e63,size,...) size
#define _STEALER_ARGS_ONLY_NAMES(...) _STEALER_ARGS_ONLY_NAMES_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define _STEALER_ARGS_ONLY_NAMES_DO(i,arg) a##i
#define _STEALER_ARGS_ONLY_NAMES_I(x) _STEALER_ARGS_ONLY_NAMES_II(x)
#define _STEALER_ARGS_ONLY_NAMES_II(x) _STEALER_ARGS_ONLY_NAMES_II_##x
#define _STEALER_ARGS_ONLY_NAMES_II_0(...) PP_FOR_EACH(_STEALER_ARGS_ONLY_NAMES_DO, PP_COMMA, __VA_ARGS__)
#define _STEALER_ARGS_ONLY_NAMES_II_1(...) 
#define _STEALER_ARGS_WITH_NAMES(...) _STEALER_ARGS_WITH_NAMES_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define _STEALER_ARGS_WITH_NAMES_DO(i,arg) arg a##i
#define _STEALER_ARGS_WITH_NAMES_I(x) _STEALER_ARGS_WITH_NAMES_II(x)
#define _STEALER_ARGS_WITH_NAMES_II(x) _STEALER_ARGS_WITH_NAMES_II_##x
#define _STEALER_ARGS_WITH_NAMES_II_0(...) PP_FOR_EACH(_STEALER_ARGS_WITH_NAMES_DO, PP_COMMA, __VA_ARGS__)
#define _STEALER_ARGS_WITH_NAMES_II_1(...) 
#define _STEALER_DECL_FIELDS(...) _STEALER_FILTER_FIELDS(_STEALER_DECL_FIELDS_DO_, __VA_ARGS__)
#define _STEALER_DECL_FIELDS_DO_0(...) 
#define _STEALER_DECL_FIELDS_DO_1(id,clz,type,name) type& name;
#define _STEALER_FIELD_GETTERS(...) _STEALER_FILTER_FIELDS(_STEALER_FIELD_GETTERS_DO_, __VA_ARGS__)
#define _STEALER_FIELD_GETTERS_DO_0(...) 
#define _STEALER_FIELD_GETTERS_DO_1(id,clz,type,name) ::stealer::_STEALER_SLOT(id)::value_type& _stealer##name() { return _obj->*__reproduce((::stealer::_STEALER_SLOT(id)*)NULL); }
#define _STEALER_FILTER(CHECK,DO,...) PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_FILTER_DO, PP_EMPTY, CHECK, DO, __VA_ARGS__)
#define _STEALER_FILTER_DO(i,CHECK,DO,...) PP_EXPAND_CAT(DO, PP_EXPAND_CAT(CHECK, PP_SELECT(i, __VA_ARGS__)) (PP_EXPAND_CAT(_STEALER_PRINT_, PP_SELECT(i, __VA_ARGS__))) )
#define _STEALER_FILTER_FIELDS(DO,...) _STEALER_FILTER(_STEALER_IS_FIELD_, DO, __VA_ARGS__)
#define _STEALER_FILTER_METHODS(DO,...) _STEALER_FILTER(_STEALER_IS_METHOD_, DO, __VA_ARGS__)
#define _STEALER_I(name,clz,...) namespace stealer { _STEALER_PREPARE_FIELDS(__VA_ARGS__) _STEALER_PREPARE_METHODS(__VA_ARGS__) } class name { typedef clz clz_type; clz_type* _obj; public: explicit name(clz_type* obj) : _obj(obj) _STEALER_INITIALIZOR(__VA_ARGS__) {} explicit name(clz_type& obj) : _obj(&obj) _STEALER_INITIALIZOR(__VA_ARGS__) {} _STEALER_DECL_FIELDS(__VA_ARGS__) _STEALER_FIELD_GETTERS(__VA_ARGS__) _STEALER_METHODS(__VA_ARGS__) }
#define _STEALER_INITIALIZOR(...) _STEALER_FILTER_FIELDS(_STEALER_INITIALIZOR_DO_, __VA_ARGS__)
#define _STEALER_INITIALIZOR_DO_0(...) 
#define _STEALER_INITIALIZOR_DO_1(id,clz,type,name) , name(_stealer##name())
#define _STEALER_IS_FIELD_FIELD(...) 1
#define _STEALER_IS_FIELD_METHOD(...) 0
#define _STEALER_IS_METHOD_FIELD(...) 0
#define _STEALER_IS_METHOD_METHOD(...) 1
#define _STEALER_METHODS(...) _STEALER_FILTER_METHODS(_STEALER_METHOD_DO_, __VA_ARGS__)
#define _STEALER_METHOD_DO_0(...) 
#define _STEALER_METHOD_DO_1(id,clz,ret_type,name,...) ::stealer::_STEALER_SLOT(id)::return_type name( _STEALER_ARGS_WITH_NAMES(__VA_ARGS__)) { return (_obj->*__reproduce((::stealer::_STEALER_SLOT(id)*)NULL)) (_STEALER_ARGS_ONLY_NAMES(__VA_ARGS__)); }
#define _STEALER_PREAPPEND_ARGS(arg,...) PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_PREAPPEND_ARGS_DO, PP_COMMA, arg, __VA_ARGS__)
#define _STEALER_PREAPPEND_ARGS_DO(i,arg,...) PP_EXPAND_CAT(_STEALER_TYPE_, PP_SELECT(i, __VA_ARGS__)) (i, arg, PP_EXPAND_CAT(_STEALER_PRINT_, PP_SELECT(i, __VA_ARGS__)))
#define _STEALER_PREPARE_FIELDS(...) _STEALER_FILTER_FIELDS(_STEALER_PREPARE_FIELD_DO_, __VA_ARGS__)
#define _STEALER_PREPARE_FIELD_DO_0(...) 
#define _STEALER_PREPARE_FIELD_DO_1(id,clz,type,name) struct _STEALER_SLOT(id) { typedef type value_type; typedef value_type(clz::*shape); friend shape __reproduce(_STEALER_SLOT(id)*); }; template struct ::stealer::mould<_STEALER_SLOT(id), &clz::name>;
#define _STEALER_PREPARE_METHODS(...) _STEALER_FILTER_METHODS(_STEALER_PREPARE_METHOD_DO_, __VA_ARGS__)
#define _STEALER_PREPARE_METHOD_DO_0(...) 
#define _STEALER_PREPARE_METHOD_DO_1(id,clz,ret_type,name,...) struct _STEALER_SLOT(id) { typedef ret_type return_type; typedef ret_type(clz::*shape)(__VA_ARGS__); friend shape __reproduce(_STEALER_SLOT(id)*); }; template struct ::stealer::mould<_STEALER_SLOT(id), &clz::name>;
#define _STEALER_PRINT_FIELD(...) __VA_ARGS__
#define _STEALER_PRINT_METHOD(...) __VA_ARGS__
#define _STEALER_SLOT(id) _STEALER_SLOT_I(id, __LINE__)
#define _STEALER_SLOT_I(id,line) _STEALER_SLOT_II(id, line)
#define _STEALER_SLOT_II(id,line) _slot_##id##_##line
#define _STEALER_TYPE_FIELD(...) FIELD
#define _STEALER_TYPE_METHOD(...) METHOD

namespace stealer {

template <typename Slot, typename Slot::shape Key>
struct mould
{
    friend typename Slot::shape __reproduce(Slot*)
    {
        return Key;
    }
};

}

#endif