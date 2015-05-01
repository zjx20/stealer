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
 * util.h
 *
 *  Created on: 2014-10-19
 *      Author: jianxiongzhou
 */

#ifndef PP_UTIL_H_
#define PP_UTIL_H_

#include "size.h"
#include "is_empty.h"
#include "select.h"

#define PP_EXPAND(x) x
#define PP_CAT(x, y) x##y
#define PP_EXPAND_CAT(x, y) PP_CAT(x, y)

#define PP_EMPTY()
#define PP_COMMA()  ,
#define PP_LPAREN() (
#define PP_RPAREN() )
#define PP_SEMI()   ;

#define PP_FIRST(...) _PP_FIRST_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _PP_FIRST_I(is_empty, ...) \
        PP_EXPAND(PP_EXPAND_CAT(_PP_FIRST_II_, is_empty)(__VA_ARGS__))
#define _PP_FIRST_II_1(...) // nothing
#define _PP_FIRST_II_0(x, ...) x

#define PP_LAST(...) _PP_LAST_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _PP_LAST_I(is_empty, ...) \
        PP_EXPAND(PP_EXPAND_CAT(_PP_LAST_II_, is_empty)(__VA_ARGS__))
#define _PP_LAST_II_1(...) // nothing
#define _PP_LAST_II_0(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)

#define PP_OVERRIDE(base, branch, ...) \
        _PP_OVERRIDE_I(base, branch, __VA_ARGS__)
#define _PP_OVERRIDE_I(base, branch, ...) \
        _PP_OVERRIDE_II(base##branch (__VA_ARGS__))
#define _PP_OVERRIDE_II(x) x

#define PP_IF(cond, DO, ...) _PP_IF_I(cond, DO, __VA_ARGS__)
#define _PP_IF_I(cond, DO, ...) PP_OVERRIDE(_PP_IF_II_, cond, DO, __VA_ARGS__)
#define _PP_IF_II_0(...) // nothing
#define _PP_IF_II_1(DO, ...) _PP_IF_III(DO(__VA_ARGS__))
#define _PP_IF_III(x) x

#define PP_NOT(cond) _PP_NOT_I(cond)
#define _PP_NOT_I(cond) _PP_NOT_II_##cond
#define _PP_NOT_II_0 1
#define _PP_NOT_II_1 0

#endif /* PP_UTIL_H_ */
