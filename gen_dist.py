#!/usr/bin/env python
# -*- coding: utf-8 -*-

#--
# stealer - https://github.com/zjx20/stealer
#
# The MIT License (MIT)
#
# Copyright (c) 2014 JianXiong Zhou <zhoujianxiong2@gmail.com>
#
# Permission is hereby granted, free of charge, to any person obtaining
# a copy of this software and associated documentation files (the
# "Software"), to deal in the Software without restriction, including
# without limitation the rights to use, copy, modify, merge, publish,
# distribute, sublicense, and/or sell copies of the Software, and to
# permit persons to whom the Software is furnished to do so, subject to
# the following conditions:
#
# The above copyright notice and this permission notice shall be
# included in all copies or substantial portions of the Software.
#
# THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
# EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
# MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
# NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE
# LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION
# OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION
# WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
#++

import os
import sys
import subprocess


def get_pwd():
    return os.path.dirname(os.path.realpath(__file__))


def command(*cmd):
    process = subprocess.Popen(cmd, 
                               stdout=subprocess.PIPE, 
                               stderr=subprocess.PIPE,
                               shell=True)
    stdout, stderr = process.communicate()
    if len(stderr) > 0:
        raise RuntimeError(stderr)
    return stdout


def gen_license_part():
    license_path = get_pwd() + '/LICENSE' 
    with open(license_path, 'r') as license_file:
        lines = license_file.readlines()
    license = '/**\n'
    license += ''.join([' * ' + line for line in lines])
    license += ' */'
    return license


def gen_content():
    filter_lines = '|'.join(['__STDC_HOSTED__', '__STDC_UTF_16__', 
                             '__STDC_UTF_32__', '__STDC_VERSION__', 
                             '__STDC__'])
    
    includes = '-I%s -I%s/src' % (get_pwd(), get_pwd())
    
    get_defines_cmd = 'echo \'#include "src/stealer.h"\' | ' + \
                      'g++ -dM -E -undef %s - | ' % includes + \
                      'grep -vE \'%s\'' % filter_lines
    
    get_content_cmd = 'echo \'#include "src/stealer.h"\' | ' + \
                      'g++ -E %s - | ' % includes + \
                      'grep -vE \'^# [0-9]*\''
    
    result =  '#ifndef STEALER_H_\n'
    result += '#define STEALER_H_\n'
    result += command(get_defines_cmd)
    result += command(get_content_cmd)
    result += '#endif\n'
    
    return result


def gen_dist():
    dist_file_path = get_pwd() + '/stealer.h'
    with open(dist_file_path, 'w') as f:
        f.write(gen_license_part())
        f.write('\n')
        f.write(gen_content())


if __name__ == '__main__':
    gen_dist()
    print 'done!'
