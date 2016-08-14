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
 * stealer.h
 *
 *  Created on: 2014-10-16
 *      Author: jianxiongzhou
 */

#ifndef STEALER_H_
#define STEALER_H_

#include "pp/pp.h"

// class A
// {
// public:
//     A() : a(100) {}
// private:
//     int a;
// };
//
// template<typename Tag, typename Tag::type M>
// struct Rob {
//   friend typename Tag::type get(Tag*) {
//     return M;
//   }
// };
//
// tag used to access A::a
// struct A_f {
//   typedef int A::*type;
//   friend type get(A_f*);
// };
//
// Explicit instantiation; the only place where it is legal to pass
// the address of a private member.
// template struct Rob<A_f, &A::a>;
//
// void func() {
//   A *a = new A();
//   int value = a->*get((A_f*)NULL); // 100
// }


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_SLOT(id) _STEALER_SLOT_I(id, __LINE__)
#define _STEALER_SLOT_I(id, line) _STEALER_SLOT_II(id, line)
#define _STEALER_SLOT_II(id, line) _slot_##id##_##line

#define _STEALER_MOULD _STEALER_MOULD_I(__LINE__)
#define _STEALER_MOULD_I(line) _STEALER_MOULD_II(line)
#define _STEALER_MOULD_II(line) _mould_##line

#define _STEALER_REPRODUCE _STEALER_REPRODUCE_I(__LINE__)
#define _STEALER_REPRODUCE_I(line) _STEALER_REPRODUCE_II(line)
#define _STEALER_REPRODUCE_II(line) __reproduce_##line

///////////////////////////////////////////////////////////////////////////////
#define _STEALER_IS_FIELD_STEAL_FIELD(...) 1
#define _STEALER_IS_FIELD_STEAL_METHOD(...) 0

#define _STEALER_IS_METHOD_STEAL_FIELD(...) 0
#define _STEALER_IS_METHOD_STEAL_METHOD(...) 1

#define _STEALER_FILTER_DO(i, ...) \
        PP_EXPAND(_STEALER_FILTER_DO_I(i, __VA_ARGS__))
#define _STEALER_FILTER_DO_I(i, CHECK, DO, ...) \
        _STEALER_FILTER_DO_II(CHECK, DO, PP_SELECT(i, __VA_ARGS__))
#define _STEALER_FILTER_DO_II(CHECK, DO, x) \
        PP_IF(PP_IS_TUPLE(x), _STEALER_FILTER_DO_III, \
                CHECK, DO, PP_TUPLE_TO_VARS(x))

#define _STEALER_FILTER_DO_III(CHECK, DO, ...) \
        PP_EXPAND(_STEALER_FILTER_DO_IV(CHECK, DO, __VA_ARGS__))
#define _STEALER_FILTER_DO_IV(CHECK, DO, type, ...) \
        _STEALER_FILTER_DO_V(PP_EXPAND_CAT(CHECK, type)(), DO, __VA_ARGS__)
#define _STEALER_FILTER_DO_V(cond, DO, ...) \
        PP_EXPAND(PP_EXPAND_CAT(_STEALER_FILTER_DO_VI_, cond)(DO, __VA_ARGS__))
#define _STEALER_FILTER_DO_VI_0(...)    // nothing
#define _STEALER_FILTER_DO_VI_1(DO, ...) PP_EXPAND(PP_CAT(DO,)(__VA_ARGS__))

#define _STEALER_FILTER(CHECK, DO, ...) \
        PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_FILTER_DO, PP_EMPTY, \
                CHECK, DO, __VA_ARGS__)

#define _STEALER_FILTER_FIELDS(DO, ...) \
        _STEALER_FILTER(_STEALER_IS_FIELD, DO, __VA_ARGS__)

#define _STEALER_FILTER_METHODS(DO, ...) \
        _STEALER_FILTER(_STEALER_IS_METHOD, DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_PREPROCESS_ARGS_DO(i, ...) \
        _STEALER_PREPROCESS_ARGS_DO_I(\
                _STEALER_PREPROCESS_ARGS_DO_II(i, __VA_ARGS__))
#define _STEALER_PREPROCESS_ARGS_DO_I(...) __VA_ARGS__
#define _STEALER_PREPROCESS_ARGS_DO_II(i, clz, ...) \
        PP_IF(PP_IS_TUPLE(PP_SELECT(i, __VA_ARGS__)), \
                _STEALER_PREPROCESS_ARGS_DO_III, i, clz, \
                PP_TUPLE_TO_VARS(PP_SELECT(i, __VA_ARGS__)))
#define _STEALER_PREPROCESS_ARGS_DO_III(id, clz, ...) \
        PP_EXPAND(_STEALER_PREPROCESS_ARGS_DO_IV(id, clz, __VA_ARGS__))
#define _STEALER_PREPROCESS_ARGS_DO_IV(id, clz, type, ...) \
        (type, id, clz, __VA_ARGS__)

#define _STEALER_PREPROCESS_ARGS(clz, ...) \
        PP_FOR(PP_SIZE(__VA_ARGS__), _STEALER_PREPROCESS_ARGS_DO, PP_COMMA, \
                clz, __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////
#define _STEALER_PREPARE_FIELD_DO(id, clz, type, name) \
        struct _STEALER_SLOT(id) { \
            typedef type value_type; \
            typedef value_type(clz::*shape); \
            friend shape _STEALER_REPRODUCE(_STEALER_SLOT(id)*); \
        }; \
        template struct stealer::_STEALER_MOULD<_STEALER_SLOT(id), &clz::name>;

#define _STEALER_PREPARE_FIELDS(...) \
        _STEALER_FILTER_FIELDS(_STEALER_PREPARE_FIELD_DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_PREPARE_METHOD_DO(id, clz, qualifier, ret_type, name, ...) \
        struct _STEALER_SLOT(id) { \
            typedef ret_type return_type; \
            typedef ret_type(clz::*shape)(__VA_ARGS__) qualifier; \
            friend shape _STEALER_REPRODUCE(_STEALER_SLOT(id)*); \
        }; \
        template struct stealer::_STEALER_MOULD<_STEALER_SLOT(id), &clz::name>;

#define _STEALER_PREPARE_METHODS(...) \
        _STEALER_FILTER_METHODS(_STEALER_PREPARE_METHOD_DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_INITIALIZOR_DO(id, clz, type, name) , name(_stealer##name())

#define _STEALER_INITIALIZOR(...) \
        _STEALER_FILTER_FIELDS(_STEALER_INITIALIZOR_DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_DECL_FIELDS_DO(id, clz, type, name) type& name;

#define _STEALER_DECL_FIELDS(...) \
        _STEALER_FILTER_FIELDS(_STEALER_DECL_FIELDS_DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_FIELD_GETTERS_DO(id, clz, type, name) \
        stealer::_STEALER_SLOT(id)::value_type& _stealer##name() { \
            return _obj->*_STEALER_REPRODUCE( \
                    (stealer::_STEALER_SLOT(id)*)NULL); \
        }

#define _STEALER_FIELD_GETTERS(...) \
        _STEALER_FILTER_FIELDS(_STEALER_FIELD_GETTERS_DO, __VA_ARGS__)


///////////////////////////////////////////////////////////////////////////////
#define _STEALER_ARGS_WITH_NAMES(...) \
        _STEALER_ARGS_WITH_NAMES_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _STEALER_ARGS_WITH_NAMES_I(is_empty, ...) \
        PP_EXPAND(PP_EXPAND_CAT(_STEALER_ARGS_WITH_NAMES_II_, is_empty) \
                (__VA_ARGS__))
#define _STEALER_ARGS_WITH_NAMES_II_1(...) // nothing
#define _STEALER_ARGS_WITH_NAMES_II_0(...) \
        PP_FOR_EACH(_STEALER_ARGS_WITH_NAMES_DO, PP_COMMA, __VA_ARGS__)

#define _STEALER_ARGS_WITH_NAMES_DO(i, arg) arg a##i


#define _STEALER_ARGS_ONLY_NAMES(...) \
        _STEALER_ARGS_ONLY_NAMES_I(PP_IS_EMPTY(__VA_ARGS__), __VA_ARGS__)
#define _STEALER_ARGS_ONLY_NAMES_I(is_empty, ...) \
        PP_EXPAND(PP_EXPAND_CAT(_STEALER_ARGS_ONLY_NAMES_II_, is_empty) \
                (__VA_ARGS__))
#define _STEALER_ARGS_ONLY_NAMES_II_1(...) // nothing
#define _STEALER_ARGS_ONLY_NAMES_II_0(...) \
        PP_FOR_EACH(_STEALER_ARGS_ONLY_NAMES_DO, PP_COMMA, __VA_ARGS__)

#define _STEALER_ARGS_ONLY_NAMES_DO(i, arg) a##i


#define _STEALER_METHOD_DO(id, clz, qualifier, ret_type, name, ...) \
        stealer::_STEALER_SLOT(id)::return_type name( \
                _STEALER_ARGS_WITH_NAMES(__VA_ARGS__)) qualifier { \
            return (_obj->*_STEALER_REPRODUCE( \
                    (stealer::_STEALER_SLOT(id)*)NULL)) \
                            (_STEALER_ARGS_ONLY_NAMES(__VA_ARGS__)); \
        }

#define _STEALER_METHODS(...) \
        _STEALER_FILTER_METHODS(_STEALER_METHOD_DO, __VA_ARGS__)

///////////////////////////////////////////////////////////////////////////////
#define STEAL_FIELD(...) (_STEAL_FIELD, __VA_ARGS__)
#define STEAL_METHOD(...) (_STEAL_METHOD, PP_EMPTY(), __VA_ARGS__)
#define STEAL_CONST_METHOD(...) (_STEAL_METHOD, const, __VA_ARGS__)
#define STEAL_QUALIFIED_METHOD(qualifier, ...) \
        (_STEAL_METHOD, qualifier, __VA_ARGS__)

#define STEALER(name, clz, ...) \
        _STEALER_I(name, clz, _STEALER_PREPROCESS_ARGS(clz, __VA_ARGS__))

#define _STEALER_I(name, clz, ...) \
        namespace stealer { \
            template <typename Slot, typename Slot::shape Key> \
            struct _STEALER_MOULD { \
                friend typename Slot::shape _STEALER_REPRODUCE(Slot*) { \
                    return Key; \
                } \
            }; \
            _STEALER_PREPARE_FIELDS(__VA_ARGS__) \
            _STEALER_PREPARE_METHODS(__VA_ARGS__) \
        } \
        class name { \
            typedef clz clz_type; \
            clz_type* _obj; \
        public: \
            explicit name(clz_type* obj) : _obj(obj) \
                    _STEALER_INITIALIZOR(__VA_ARGS__) {} \
            explicit name(clz_type& obj) : _obj(&obj) \
                    _STEALER_INITIALIZOR(__VA_ARGS__) {} \
            _STEALER_DECL_FIELDS(__VA_ARGS__) \
            _STEALER_FIELD_GETTERS(__VA_ARGS__) \
            _STEALER_METHODS(__VA_ARGS__) \
        }

#endif /* STEALER_H_ */
