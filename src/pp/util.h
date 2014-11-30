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
#include "dec.h"

#define PP_EXPAND(x) x
#define PP_CAT(x, y) x##y
#define PP_EXPAND_CAT(x, y) PP_CAT(x, y)

#define PP_AS_SINGLE(...) __VA_ARGS__

#define PP_FIRST(...) _PP_FIRST_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define _PP_FIRST_I(x) _PP_FIRST_II(x)
#define _PP_FIRST_II(x) _PP_FIRST_II_##x
#define _PP_FIRST_II_1(...) // empty
#define _PP_FIRST_II_0(x, ...) x

#define PP_LAST(...) _PP_LAST_I(PP_IS_EMPTY(__VA_ARGS__)(__VA_ARGS__))
#define _PP_LAST_I(x) _PP_LAST_II(x)
#define _PP_LAST_II(x) _PP_LAST_II_##x
#define _PP_LAST_II_1(...) // empty
#define _PP_LAST_II_0(...) PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)

#define PP_REMOVE_TAIL_COMMA(...) \
        _PP_REMOVE_TAIL_COMMA_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_I(is_empty, ...) \
        _PP_REMOVE_TAIL_COMMA_II(is_empty, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_II(is_empty, ...) \
        _PP_REMOVE_TAIL_COMMA_II_##is_empty(__VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_II_1(...) __VA_ARGS__
#define _PP_REMOVE_TAIL_COMMA_II_0(...) \
        _PP_REMOVE_TAIL_COMMA_III( \
                PP_IS_EMPTY(PP_SELECT(PP_SIZE(__VA_ARGS__), __VA_ARGS__)), \
                __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_III(is_empty, ...) \
        _PP_REMOVE_TAIL_COMMA_IIII(is_empty, __VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_IIII(is_empty, ...) \
        _PP_REMOVE_TAIL_COMMA_IIII_##is_empty(__VA_ARGS__)
#define _PP_REMOVE_TAIL_COMMA_IIII_0(...) __VA_ARGS__
#define _PP_REMOVE_TAIL_COMMA_IIII_1(...) \
        PP_FOR(PP_DEC(PP_SIZE(__VA_ARGS__)), _PP_REMOVE_TAIL_COMMA_FOR_DO, \
                PP_COMMA, __VA_ARGS__)

#define _PP_REMOVE_TAIL_COMMA_FOR_DO(i, ...) PP_SELECT(i, __VA_ARGS__)

#define PP_EMPTY()
#define PP_COMMA()  ,
#define PP_LPAREN() (
#define PP_RPAREN() )
#define PP_SEMI()   ;

#endif /* PP_UTIL_H_ */
