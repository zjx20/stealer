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
 * pp_test.cpp
 *
 *  Created on: 2015-4-25
 *      Author: jianxiongzhou
 */

#include <string>
#include <iostream>
#include <exception>

#include "../src/pp/pp.h"

#define PP_TOSTR(...) #__VA_ARGS__
#define PP_TEST(x, expected) \
        do { \
            if (std::string(PP_TOSTR(x)) != std::string(expected)) { \
                throw std::runtime_error("\"" #x "\"" \
                        " is expected to be expanded as " \
                        "\"" expected "\"" ", actual is " \
                        "\"" PP_TOSTR(x) "\""); \
            } else { \
                std::cout << "Pass, " #x " = " \
                          << "\"" expected "\"" << std::endl; \
            } \
        } while (0)

#define EMPTY
#define FOR_SEP() |
#define FOR_DO1(i, ...) i
#define FOR_DO2(i, ...) PP_EXPAND_CAT(for_, PP_SELECT(i, ##__VA_ARGS__))
#define FOR_EACH_DO1(i, arg) arg
// #define FOR_EACH_DO(i, arg) PP_EXPAND_CAT(i##_, PP_EXPAND_CAT(PP_DEC(arg),))
#define FOR_EACH_DO2(i, arg) PP_EXPAND_CAT(i##_, PP_EXPAND_CAT(PP_DEC(arg),))

void test()
{
    PP_TEST( PP_SIZE(hello), "1" );
    PP_TEST( PP_SIZE(hello, stealer), "2" );
    PP_TEST( PP_SIZE(hello, stealer, !), "3" );

    PP_TEST( PP_DEC(1), "0" );
    PP_TEST( PP_DEC(50), "49" );
    PP_TEST( PP_DEC(64), "63" );

    PP_TEST( PP_SELECT(0, a, b, c), "" );
    PP_TEST( PP_SELECT(1, a, b, c), "a" );
    PP_TEST( PP_SELECT(2, a, b, c), "b" );
    PP_TEST( PP_SELECT(3, a, b, c), "c" );

    PP_TEST( PP_FOR(3, FOR_DO1, FOR_SEP, a, b, c), "1 | 2 | 3" );
    PP_TEST( PP_FOR(3, FOR_DO2, FOR_SEP, a, b, c), "for_a | for_b | for_c" );

    PP_TEST( PP_FOR_EACH(FOR_EACH_DO1, FOR_SEP, 1, 5, 64), "1 | 5 | 64" );
    PP_TEST( PP_FOR_EACH(FOR_EACH_DO2, FOR_SEP, 1, 5, 64), "1_0 | 2_4 | 3_63" );

    PP_TEST( PP_CAT(x, y), "xy" );
    PP_TEST( PP_EXPAND(PP_CAT(EM, PTY)), "" );
    PP_TEST( PP_EXPAND_CAT(EM, PTY), "" );

    PP_TEST( PP_EMPTY(), "" );
    PP_TEST( PP_COMMA(), "," );
    //PP_TEST( PP_LPAREN(), "(" );  // compile error on gcc, but on VS is ok...
    PP_TEST( PP_LPAREN()PP_RPAREN(), "()" );
    PP_TEST( PP_SEMI(), ";" );

    PP_TEST( PP_IS_EMPTY(a), "0" );
    PP_TEST( PP_IS_EMPTY(,), "0" );
    PP_TEST( PP_IS_EMPTY(,,,), "0" );
    PP_TEST( PP_IS_EMPTY("a"), "0" );
    PP_TEST( PP_IS_EMPTY(a, b), "0" );
    PP_TEST( PP_IS_EMPTY(a, b, c), "0" );
    PP_TEST( PP_IS_EMPTY( ), "1" );

    PP_TEST( PP_FIRST(a, b, c), "a" );
    PP_TEST( PP_LAST(a, b, c), "c" );

    PP_TEST( PP_REMOVE_TAIL_COMMA( ), "" );
    PP_TEST( PP_REMOVE_TAIL_COMMA(a, b, c), "a, b, c" );
    PP_TEST( PP_REMOVE_TAIL_COMMA(a, b, c, ), "a , b , c" );
}

int main()
{
    try {
        test();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
