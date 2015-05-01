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
 * stealer_test.cpp
 *
 *  Created on: 2015-5-1
 *      Author: jianxiongzhou
 */

#include <string>
#include <iostream>
#include <exception>

#include "../src/stealer.h"

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

#define PP_TEST_EX(x, ...) \
        do { \
            const char* expects[] = {__VA_ARGS__}; \
            bool matched = false; \
            std::string expects_str = "["; \
            int len = (int)(sizeof(expects) / sizeof(expects[0])); \
            for (int i = 0; i < len; i++) { \
                if (std::string(PP_TOSTR(x)) == std::string(expects[i])) { \
                    std::cout << "Pass, " #x " = " \
                              << "\"" << expects[i] << "\"" << std::endl; \
                    matched = true; \
                    break; \
                } \
                expects_str += "\"" + std::string(expects[i]) + "\""; \
                if (i + 1 < len) { \
                    expects_str += ", "; \
                } \
            } \
            expects_str += "]"; \
            if (!matched) { \
                throw std::runtime_error("\"" #x "\"" \
                        " is expected to be expanded as one of " + \
                        expects_str + ", actual is " \
                        "\"" PP_TOSTR(x) "\""); \
            } \
        } while (0)

void test_basic()
{
    PP_TEST( STEAL_FIELD(int, a), "(_STEAL_FIELD, int, a)" );
    PP_TEST( STEAL_METHOD(void, foo, int, float),
            "(_STEAL_METHOD, void, foo, int, float)" );

    PP_TEST( _STEALER_PREPROCESS_ARGS(clz, 
                                      STEAL_FIELD(int, a),
                                      STEAL_METHOD(void, foo),
                                      STEAL_FIELD(float, b)),
            "(_STEAL_FIELD, 1, clz, int, a) , "
            "(_STEAL_METHOD, 2, clz, void, foo) , "
            "(_STEAL_FIELD, 3, clz, float, b)" );

    PP_TEST( _STEALER_IS_FIELD_STEAL_FIELD(), "1" );
    PP_TEST( _STEALER_IS_FIELD_STEAL_METHOD(), "0" );
    PP_TEST( _STEALER_IS_METHOD_STEAL_FIELD(), "0" );
    PP_TEST( _STEALER_IS_METHOD_STEAL_METHOD(), "1" );


#define FILTER_TEST_DO(a, b) a, b

    PP_TEST_EX( _STEALER_FILTER(_STEALER_IS_FIELD, FILTER_TEST_DO,
                                STEAL_FIELD(int, a),
                                STEAL_METHOD(void, foo),
                                STEAL_FIELD(float, b)),
                "int, a    float, b",
                "int, a float, b");

    PP_TEST_EX( _STEALER_FILTER(_STEALER_IS_METHOD, FILTER_TEST_DO,
                                STEAL_FIELD(int, a),
                                STEAL_METHOD(void, foo),
                                STEAL_FIELD(float, b)),
                "  void, foo ",
                "void, foo");

    PP_TEST_EX( _STEALER_FILTER_FIELDS(FILTER_TEST_DO,
                                       STEAL_FIELD(int, a),
                                       STEAL_METHOD(void, foo),
                                       STEAL_FIELD(float, b)),
                "int, a    float, b",
                "int, a float, b" );

    PP_TEST_EX( _STEALER_FILTER_METHODS(FILTER_TEST_DO,
                                        STEAL_FIELD(int, a),
                                        STEAL_METHOD(void, foo),
                                        STEAL_FIELD(float, b)),
                "  void, foo ",
                "void, foo");

//    PP_TEST( STEALER(foo, bar, STEAL_FIELD(int, a)), "");
}

int main()
{
    try {
        test_basic();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
