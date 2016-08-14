# Stealer: stealing privates of c++ object

The main purpose of stealer is for testing: that makes it possible to test privates of a class without changing its design.

It was tested in:

* Apple LLVM version 6.1.0 (clang-602.0.49)
* VS2012

## Usage

No installation is needed, just copy and include the *stealer.h*. Here is a small tutorial shows how to use it.

1. **Assume there is an existing class named `private_t`, the definition is:**

    ```cpp
    class private_t
    {
    public:
        private_t(const std::string& initial_value)
        {
            _private_string = initial_value;
            _private_int = 123456789;
        }
    
        void print()
        {
            std::cout << "_private_string: " << _private_string << std::endl <<
                    "_private_int: " << _private_int << std::endl;
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
    
        void private_const_method() const
        {
            std::cout << "in private_const_method()!" << std::endl;
        }
    
        void private_volatile_method() volatile
        {
            std::cout << "in private_volatile_method()!" << std::endl;
        }
    
    private:
        std::string _private_string;
        int _private_int;
    };
    ```

2. **Then declare a stealer wrapper class of `private_t`:**

    ```cpp
    STEALER(stealer_private_t, private_t,
            /* STEAL_FIELD(type_of_the_field, field_name) */
            STEAL_FIELD(int, _private_int),
            STEAL_FIELD(std::string, _private_string),
            
            /* STEAL_METHOD(return_type_of_the_method, method_name, arg1, arg2, ...) */
            STEAL_METHOD(void, private_method),
            STEAL_METHOD(int, private_method3, int, double, const std::string&),
            
            /* STEAL_METHOD() family */
            STEAL_CONST_METHOD(void, private_const_method),
            STEAL_QUALIFIED_METHOD(volatile, void, private_volatile_method),
    );
    ```
    
    the macro will be expanded to this like:
    
    ```cpp
    /*...*/
    class stealer_private_t
    {
        private_t* _obj;
    public:
        stealer_private_t(private_t* obj) _obj(obj) {/*...*/}
        stealer_private_t(private_t& obj) _obj(&obj) {/*...*/}
        
        void private_method() {/*...*/}
        int private_method3(int a1, double a2, const std::string& a3) {/*...*/}
        void private_const_method() const {/*...*/}
        void private_volatile_method() volatile {/*...*/}
        
        int& _private_int;
        std::string& _private_string;
    };
    ```
    
3. **Use the wrapper class for stealing:**

    ```cpp
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
        steal.private_const_method();
        steal.private_volatile_method();
    
        std::cout << std::endl;
    
        // modify private fields
        steal._private_string = "stole!";
        steal._private_int = 0;
        steal._private_map[1] = 'a';
    
        inst.print();
    
        return 0;
    }
    ```
    
    the output:
    
    ```
    _private_string: private!
    _private_int: 123456789
    _private_map.size(): 0
    
    steal _private_string: private!
    steal _private_int: 123456789
    
    in private_method()!
    in private_method3(), a = 100, b = 123.4, str = foo
    in private_const_method()!
    in private_volatile_method()!
    
    _private_string: stole!
    _private_int: 0
    _private_map.size(): 1
    ```

# Technique Detail

Two blog posts explain how it works:
* [Access to private members. That's easy!](http://bloglitb.blogspot.com/2010/07/access-to-private-members-thats-easy.html)
* [Access to private members: Safer nastiness.](http://bloglitb.blogspot.com/2011/12/access-to-private-members-safer.html)

# Limitations

* Although the technique used by strealer is blessed by the c++ standard, not all compilers support that feature. And gcc is recommended.
* Complex types of fields such as `std::map<int, int>` are not supported by stealer directly due to the comma breaks the macro. A workaround is typedef, so commas will be eliminated.
* Overloaded methods are not supported. There is no way to specify which version of overloads should be used (casting doesn't work, it may be a bug of the compiler).
* Private template member methods are also not supported, the compiler just not allows.

# License

This project is released under the MIT license.
