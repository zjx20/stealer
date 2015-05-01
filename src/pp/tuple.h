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
 * tuple.h
 *
 *  Created on: 2015-4-29
 *      Author: jianxiongzhou
 */

#ifndef PP_TUPLE_H_
#define PP_TUPLE_H_

#include "select.h"

#define PP_TUPLE_TO_VARS(tuple) \
        _PP_TUPLE_TO_VARS_I(_PP_TUPLE_TO_VARS_II() tuple)
#define _PP_TUPLE_TO_VARS_I(x) x
#define _PP_TUPLE_TO_VARS_II() _PP_TUPLE_TO_VARS_III
#define _PP_TUPLE_TO_VARS_III(...) __VA_ARGS__

#define PP_IS_TUPLE(...) _PP_IS_TUPLE_I(_PP_IS_TUPLE_HELPER __VA_ARGS__)
#define _PP_IS_TUPLE_I(test, ...) _PP_IS_TUPLE_II( \
        PP_SELECT(1, _PP_IS_TUPLE_PP_EXPAND_CAT(_PP_IS_TUPLE_DEF_, test)))
#define _PP_IS_TUPLE_II(x) x

// workaround for VS2012
#define _PP_IS_TUPLE_PP_CAT(x, y) x##y
#define _PP_IS_TUPLE_PP_EXPAND_CAT(x, y, ...) _PP_IS_TUPLE_PP_CAT(x, y)

#define _PP_IS_TUPLE_HELPER(...) 1
#define _PP_IS_TUPLE_DEF_1 1, PP_EMPTY
#define _PP_IS_TUPLE_DEF__PP_IS_TUPLE_HELPER 0, PP_EMPTY

#endif /* PP_TUPLE_H_ */
