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
 * stealer_sample.cpp
 *
 *  Created on: 2014-11-21
 *      Author: jianxiongzhou
 */

#include <string>
#include <iostream>
#include <map>

#include "../src/stealer.h"

class private_t
{
public:
    private_t(const std::string& initial_value)
    {
        _private_int = 123456789;
        _private_string = initial_value;
    }

    void print()
    {
        std::cout << "_private_string: " << _private_string << std::endl <<
                "_private_int: " << _private_int << std::endl <<
                "_private_map.size(): " << _private_map.size() << std::endl;
    }

private:
    void private_method()
    {
        std::cout << "in private_method()!" << std::endl;
    }

    int private_method3(int a, double b, const std::string& str)
    {
        std::cout << "in private_method3(), a = " << a << ", b = " << b <<
                ", str = " << str << std::endl;
        return a;
    }

    template <typename T>
    void private_template()
    {
        std::cout << "in private_template(), typeid(T).name(): " <<
                typeid(T).name() << std::endl;
    }

private:
    int _private_int;
    std::string _private_string;
    std::map<int, char> _private_map;
};

typedef std::map<int, char> map_t;

STEALER(stealer_private_t, private_t,
        FIELD(int, _private_int),
        FIELD(std::string, _private_string),
        FIELD(map_t, _private_map), // typedef helps a lot

        METHOD(void, private_method),
        METHOD(int, private_method3, int, double, const std::string&),
);

int main()
{
    private_t inst("private!");
    inst.print();

    std::cout << std::endl;

    stealer_private_t steal(inst);

    // read private fields
    std::cout <<
            "steal _private_string: " << steal._private_string << std::endl <<
            "steal _private_int: " << steal._private_int << std::endl;

    std::cout << std::endl;

    // call private methods
    steal.private_method();
    steal.private_method3(100, 123.4, "foo");

    std::cout << std::endl;

    // modify private fields
    steal._private_string = "stole!";
    steal._private_int = 0;
    steal._private_map[1] = 'a';

    inst.print();

    return 0;
}
