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
#define FOR_EACH_DO2(i, arg) PP_EXPAND_CAT(i##_, arg)
#define OVERRIDE1(...) PP_SIZE(__VA_ARGS__)
#define OVERRIDE2(...) PP_LAST(__VA_ARGS__)

void test_basic()
{
    PP_TEST( PP_SIZE(hello), "1" );
    PP_TEST( PP_SIZE(hello, stealer), "2" );
    PP_TEST( PP_SIZE(hello, stealer, !), "3" );

    PP_TEST( PP_SELECT(0, a, b, c), "" );
    PP_TEST( PP_SELECT(1, a, b, c), "a" );
    PP_TEST( PP_SELECT(2, a, b, c), "b" );
    PP_TEST( PP_SELECT(3, a, b, c), "c" );

    PP_TEST( PP_FOR(3, FOR_DO1, FOR_SEP, a, b, c), "1 | 2 | 3" );
    PP_TEST( PP_FOR(3, FOR_DO2, FOR_SEP, a, b, c), "for_a | for_b | for_c" );

    PP_TEST( PP_FOR_EACH(FOR_EACH_DO1, FOR_SEP, 1, 5, 64), "1 | 5 | 64" );
    PP_TEST( PP_FOR_EACH(FOR_EACH_DO2, FOR_SEP, 1, 5, 64), "1_1 | 2_5 | 3_64" );

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
    //PP_TEST( PP_IS_EMPTY((a, b, c)), "0" );   // fails to handle this case
    PP_TEST( PP_IS_EMPTY( ), "1" );

    PP_TEST( PP_FIRST(a, b, c), "a" );
    PP_TEST( PP_LAST(a, b, c), "c" );

    PP_TEST( PP_TUPLE_TO_VARS(( )), "" );
    PP_TEST( PP_TUPLE_TO_VARS((a)), "a" );
    PP_TEST( PP_TUPLE_TO_VARS((a, b, c)), "a, b, c" );

    PP_TEST( PP_OVERRIDE(OVERRIDE, 1, a, b, c, d), "4" );
    PP_TEST( PP_OVERRIDE(OVERRIDE, 2, a, b, c, d), "d" );

    PP_TEST( PP_IF(PP_SELECT(2, 1, 0), PP_SIZE, a, b, c), "" );
    PP_TEST( PP_IF(1, PP_SIZE, a, b, c), "3" );

    PP_TEST( PP_IS_TUPLE(), "0" );
    PP_TEST( PP_IS_TUPLE(a, b, c), "0" );
    PP_TEST( PP_IS_TUPLE(,), "0" );
    PP_TEST( PP_IS_TUPLE(()), "1" );
    PP_TEST( PP_IS_TUPLE((a)), "1" );
    PP_TEST( PP_IS_TUPLE((a, b, c)), "1" );
    PP_TEST( PP_IS_TUPLE((a, b,)), "1" );

    PP_TEST( PP_NOT(0), "1" );
    PP_TEST( PP_NOT(1), "0" );
    PP_TEST( PP_NOT(PP_IS_EMPTY()), "0" );
    PP_TEST( PP_NOT(PP_IS_EMPTY(a,b,c)), "1" );
}

void test_fields_and_methods()
{

#define ARGS(...) (__VA_ARGS__)
#define FAM_TEST1(...) PP_SIZE(__VA_ARGS__)

#define FAM_TEST2(...) \
        PP_FOR(PP_SIZE(__VA_ARGS__), FAM_TEST2_DO, PP_COMMA, __VA_ARGS__)
#define FAM_TEST2_DO(i, ...) \
        PP_SIZE(PP_TUPLE_TO_VARS(PP_SELECT(i, __VA_ARGS__)))

#define FAM_TEST3(CHECK, DO, ...) \
        PP_FOR(PP_SIZE(__VA_ARGS__), FAM_TEST3_DO, PP_COMMA, \
                CHECK, DO, __VA_ARGS__)
#define FAM_TEST3_DO(i, ...) \
        PP_EXPAND(FAM_TEST3_DO_I(i, __VA_ARGS__))
#define FAM_TEST3_DO_I(i, CHECK, DO, ...) \
        FAM_TEST3_DO_II(CHECK, DO, \
                PP_TUPLE_TO_VARS(PP_SELECT(i, __VA_ARGS__)))
#define FAM_TEST3_DO_II(CHECK, DO, ...) \
        PP_EXPAND(FAM_TEST3_DO_III(CHECK, DO, __VA_ARGS__))
#define FAM_TEST3_DO_III(CHECK, DO, type, ...) \
        PP_IF(PP_EXPAND_CAT(CHECK, type)(), DO, __VA_ARGS__)

#define FIELD(...) (_FIELD, ##__VA_ARGS__)
#define METHOD(...) (_METHOD, ##__VA_ARGS__)
#define IS_FIELD_FIELD(...) 1
#define IS_FIELD_METHOD(...) 0
#define IS_METHOD_FIELD(...) 0
#define IS_METHOD_METHOD(...) 1
#define HANDLE_FIELD(type, name) HANDLING_FIELD, type, name
#define HANDLE_METHOD(return_type, name, ...) \
        HANDLING_METHOD, return_type, name, PP_SIZE(__VA_ARGS__) args

    PP_TEST( PP_SIZE(ARGS(a,b), ARGS(x,y,z)), "2" );
    PP_TEST( FAM_TEST1(ARGS(a,b), ARGS(x,y,z)), "2" );
    PP_TEST( FAM_TEST2(ARGS(a,b), ARGS(x,y,z)), "2 , 3" );

    PP_TEST( FAM_TEST3(IS_FIELD, HANDLE_FIELD, METHOD(int, a)), "" );
    PP_TEST( FAM_TEST3(IS_FIELD, HANDLE_FIELD, FIELD(int, a)), \
            "HANDLING_FIELD, int, a" );
    PP_TEST( FAM_TEST3(IS_FIELD, HANDLE_FIELD, 
                    FIELD(int, a), FIELD(float, b), METHOD(int, a)), 
            "HANDLING_FIELD, int, a , HANDLING_FIELD, float, b ," );

    PP_TEST( FAM_TEST3(IS_METHOD, HANDLE_METHOD, FIELD(int, a)), "" );
    PP_TEST( FAM_TEST3(IS_METHOD, HANDLE_METHOD, METHOD(int, a)), 
            "HANDLING_METHOD, int, a, 1 args" );
    PP_TEST( FAM_TEST3(IS_METHOD, HANDLE_METHOD, METHOD(int, a, int, int)), 
            "HANDLING_METHOD, int, a, 2 args" );
    PP_TEST( FAM_TEST3(IS_METHOD, HANDLE_METHOD, 
                    METHOD(int, a, float), METHOD(float, b), FIELD(int, a)), 
            "HANDLING_METHOD, int, a, 1 args , "
            "HANDLING_METHOD, float, b, 1 args ," );
}

void test_insert_elem_to_second_place_of_tuple()
{

#define IETSPOT_TEST1(elem, tuple) \
        IETSPOT_TEST1_I(elem, PP_TUPLE_TO_VARS(tuple))
#define IETSPOT_TEST1_I(elem, ...) \
        PP_EXPAND(IETSPOT_TEST1_II(elem, __VA_ARGS__))
#define IETSPOT_TEST1_II(elem, first, ...) (first, elem, __VA_ARGS__)

#define IETSPOT_TEST2(elem, ...) \
        PP_FOR(PP_SIZE(__VA_ARGS__), IETSPOT_TEST2_I, PP_COMMA, elem, \
                __VA_ARGS__)
#define IETSPOT_TEST2_I(i, ...) \
        PP_EXPAND(IETSPOT_TEST2_II(i, __VA_ARGS__))
#define IETSPOT_TEST2_II(i, elem, ...) \
        IETSPOT_TEST1(elem, PP_SELECT(i, __VA_ARGS__))

    PP_TEST( IETSPOT_TEST1(z, (a, b, c)), "(a, z, b, c)" );

    PP_TEST( IETSPOT_TEST2(z, FIELD(int, a), METHOD(float, b)),
            "(_FIELD, z, int, a) , (_METHOD, z, float, b)" );
}

int main()
{
    try {
        test_basic();
        test_fields_and_methods();
        test_insert_elem_to_second_place_of_tuple();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
