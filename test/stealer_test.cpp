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
                        "\"" expected "\"" ", actual result is " \
                        "\"" PP_TOSTR(x) "\""); \
            } else { \
                std::cout << "Pass, " #x " = " \
                          << "\"" expected "\"" << std::endl; \
            } \
        } while (0)

#define PP_TEST_EX(x, expected) \
        do { \
            std::string result = normalize(PP_TOSTR(x)); \
            std::string normalized = normalize(expected); \
            if (result != normalized) { \
                throw std::runtime_error("\"" #x "\"" \
                        " is expected to be expanded as " \
                        "\"" + normalized + "\"" ", actual result is " \
                        "\"" + result + "\""); \
            } else { \
                std::cout << "Pass, " #x " = " \
                          << "\"" expected "\"" << std::endl; \
            } \
        } while (0)


std::string normalize(const std::string& str)
{
    const std::string SEPARATORS = ",()";
    const std::string SPACES = " ";
    // Adds an extra separator to trim right side spaces
    std::string original = str + ",";
    std::string result = "";
    bool skip_space = true;
    for (size_t i = 0; i < original.size(); i++) {
        std::string::value_type ch = original[i];
        if (SPACES.find(ch) != std::string::npos) {
            if (!skip_space) {
                // Trims successive spaces
                skip_space = true;
                result += " ";
            }
        } else if (SEPARATORS.find(ch) != std::string::npos) {
            // Trims spaces at both side of a separator
            skip_space = true;
            if (!result.empty() &&
                    SPACES.find(*result.rbegin()) != std::string::npos) {
                *result.rbegin() = ch;
            } else {
                result += ch;
            }
        } else {
            // Needs a space as a separator
            skip_space = false;
            result += ch;
        }
    }
    // Don't return the artificial character
    return result.substr(0, result.length() - 1);
}

void test_normalize()
{
    const char* cases[][2] = {
            {
                    "    ",
                    ""
            },
            {
                    "  ,   ,   ) (  ",
                    ",,)("
            },
            {
                    " , void, foo const, int, const_foo const , float, cv_foo ",
                    ",void,foo const,int,const_foo const,float,cv_foo"
            }
    };

    for (size_t i = 0; i < sizeof(cases)/sizeof(char*[2]); i++) {
        std::string result = normalize(cases[i][0]);
        if (result != cases[i][1]) {
            throw std::runtime_error(
                    "normalize(\"" + std::string(cases[i][0]) + "\")" +
                    " is expected to be equal to " +
                    "\"" + cases[i][1] + "\"" ", actual result is " +
                    "\"" + result + "\"");
        }
    }
}

void test_stealer()
{
    PP_TEST( STEAL_FIELD(int, a), "(_STEAL_FIELD, int, a)" );
    PP_TEST( STEAL_METHOD(void, foo, int, float),
            "(_STEAL_METHOD, , void, foo, int, float)" );
    PP_TEST( STEAL_CONST_METHOD(int, foo, int, float),
            "(_STEAL_METHOD, const, int, foo, int, float)" );
    PP_TEST( STEAL_QUALIFIED_METHOD(const volatile, float, foo, int, float),
            "(_STEAL_METHOD, const volatile, float, foo, int, float)" );

    PP_TEST( _STEALER_PREPROCESS_ARGS(clz, 
                      STEAL_FIELD(int, a),
                      STEAL_METHOD(void, foo),
                      STEAL_CONST_METHOD(int, const_foo),
                      STEAL_QUALIFIED_METHOD(const volatile, float, cv_foo),
                      STEAL_FIELD(float, b)),
            "(_STEAL_FIELD, 1, clz, int, a) , "
            "(_STEAL_METHOD, 2, clz, , void, foo) , "
            "(_STEAL_METHOD, 3, clz, const, int, const_foo) , "
            "(_STEAL_METHOD, 4, clz, const volatile, float, cv_foo) , "
            "(_STEAL_FIELD, 5, clz, float, b)" );

    PP_TEST( _STEALER_IS_FIELD_STEAL_FIELD(), "1" );
    PP_TEST( _STEALER_IS_FIELD_STEAL_METHOD(), "0" );
    PP_TEST( _STEALER_IS_METHOD_STEAL_FIELD(), "0" );
    PP_TEST( _STEALER_IS_METHOD_STEAL_METHOD(), "1" );


#define FILTER_TEST_DO(...) __VA_ARGS__

    PP_TEST_EX( _STEALER_FILTER(_STEALER_IS_FIELD, FILTER_TEST_DO,
                        STEAL_FIELD(int, a),
                        STEAL_METHOD(void, foo),
                        STEAL_CONST_METHOD(int, const_foo),
                        STEAL_QUALIFIED_METHOD(const volatile, float, cv_foo),
                        STEAL_FIELD(float, b)),
                "int, a float, b");

    PP_TEST_EX( _STEALER_FILTER(_STEALER_IS_METHOD, FILTER_TEST_DO,
                        STEAL_FIELD(int, a),
                        STEAL_METHOD(void, foo),
                        STEAL_CONST_METHOD(int, const_foo),
                        STEAL_QUALIFIED_METHOD(const volatile, float, cv_foo),
                        STEAL_FIELD(float, b)),
                ", void, foo const, int, const_foo " \
                "const volatile, float, cv_foo");

    PP_TEST_EX( _STEALER_FILTER_FIELDS(FILTER_TEST_DO,
                        STEAL_FIELD(int, a),
                        STEAL_METHOD(void, foo),
                        STEAL_CONST_METHOD(int, const_foo),
                        STEAL_QUALIFIED_METHOD(const volatile, float, cv_foo),
                        STEAL_FIELD(float, b)),
                "int, a float, b" );

    PP_TEST_EX( _STEALER_FILTER_METHODS(FILTER_TEST_DO,
                        STEAL_FIELD(int, a),
                        STEAL_METHOD(void, foo),
                        STEAL_CONST_METHOD(int, const_foo),
                        STEAL_QUALIFIED_METHOD(const volatile, float, cv_foo),
                        STEAL_FIELD(float, b)),
                ", void, foo const, int, const_foo " \
                "const volatile, float, cv_foo");

//    PP_TEST( STEALER(foo, bar, STEAL_FIELD(int, a)), "");
}

int main()
{
    try {
        test_normalize();
        test_stealer();
    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    return 0;
}
