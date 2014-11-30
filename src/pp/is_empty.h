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
 * is_empty.h
 *
 *  Created on: 2014-10-21
 *      Author: jianxiongzhou
 */

#ifndef PP_IS_EMPTY_H_
#define PP_IS_EMPTY_H_

#include "size.h"
#include "select.h"
#include "util.h"

#define PP_IS_EMPTY(...) _PP_IS_EMPTY_I(__VA_ARGS__ _PP_IS_EMPTY_HELPER)
#define _PP_IS_EMPTY_I(...) _PP_IS_EMPTY_II(_PP_IS_EMPTY_DEF ## __VA_ARGS__())
#define _PP_IS_EMPTY_II(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)

#define _PP_IS_EMPTY_DEF_PP_IS_EMPTY_HELPER() 1, 1
#define _PP_IS_EMPTY_HELPER() , 0

//#define PP_IS_EMPTY(...) _PP_IS_EMPTY_I(PP_SIZE(__VA_ARGS__))
//#define _PP_IS_EMPTY_I(x) _PP_IS_EMPTY_II(x)
//#define _PP_IS_EMPTY_II(x) _PP_IS_EMPTY_II_##x

#define _PP_IS_EMPTY_II_0  1
#define _PP_IS_EMPTY_II_1  0
#define _PP_IS_EMPTY_II_2  0
#define _PP_IS_EMPTY_II_3  0
#define _PP_IS_EMPTY_II_4  0
#define _PP_IS_EMPTY_II_5  0
#define _PP_IS_EMPTY_II_6  0
#define _PP_IS_EMPTY_II_7  0
#define _PP_IS_EMPTY_II_8  0
#define _PP_IS_EMPTY_II_9  0
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
#define _PP_IS_EMPTY_II_60 0
#define _PP_IS_EMPTY_II_61 0
#define _PP_IS_EMPTY_II_62 0
#define _PP_IS_EMPTY_II_63 0
#define _PP_IS_EMPTY_II_64 0

#endif /* PP_IS_EMPTY_H_ */
