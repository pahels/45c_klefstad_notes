/*
Developing Your First Program
can we use curly brackets instead of an = ???
*/

/*
CONSTANT VARIABLES
- a value that may not be changed during a program's execution
named/symbolic constants - constant values that are associated with an identifier, cannot be changed during execution
literal constants - constants that are not associated with an identifier

constant variables
- can do const type or type const. const type is preferred 
- const variables must be inititalized and cannot be changed via assignment

type qualifiers 
- modifies how that type behaves
*/
#include <iostream>
#define MY_NAME "Pahel" //will result in macro substitution. it doesn't matter if i do this in a function bc the scope will always be the entire code

int constants(const int x){ //this is allowed but not encouraged
    int age = 100;
    const int constAge {age};
    int age = 101; //this is allowed but it wont change constAge
}

/*
COMPOUND DATA TYPES
data types that can be constructed from fundamental data types
functions, arrays, pointer types, pointer to memeber types, reference types, enumerated types, class types

VALUE CATEGORIES (lvalues and rvalues)
use auto when don't know data type
can do x = 5 but NOT 5 = x

an lvalue is an expression that evaluates to an identifiable object or function
int x = 5
int y = x
x and y are lvalue expressions

modifiable vs unmodifiable lvalue expressions
if lvalue is a const or constexpr it is obviously unmodifiable

an rvalue is an expression that is not an lvalue
int x = 5 //5 is an rvalue expression
can use & to check if something is an lval or rval
- &x will compile but &5 won't, 5 is an rvalue, &function will not compile, so functions are rvals
CSTRINGS ARE AN LVALUE

lvalue to rvalue conversions are hella obvious
*/

/*
LVALUE REFERENCES
- a reference si an alias for an existing object. once it has been defined, any operation on the reference is applied to
the object being referenced
- a reference is identical to the object being referenced

int //normal int type
int& //lvalue refernece to an int object

we can create an lvalue refernece variable, which is a variable that acts as areference to an lvalue. To do this, we just define a variable
with an lvalue reference type

*/
int lvalref(){
    int x { 5 };    // x is a normal integer variable
    int& ref { x }; // ref is an lvalue reference variable that can now be used as an alias for variable x

    std::cout << x << '\n';  // print the value of x (5)
    std::cout << ref << '\n'; // print the value of x via ref (5)

    return 0;
} //this will print 5 5 with a newline between the 5s

int lvalmodify(){
    int x { 5 }; // normal integer variable
    int& ref { x }; // ref is now an alias for variable x
    std::cout << x << ref << '\n'; // print 55
    x = 6; // x now has value 6
    std::cout << x << ref << '\n'; // prints 66
    ref = 7; // the object being referenced (x) now has value 7
    std::cout << x << ref << '\n'; // prints 77
    return 0;
}

/*
all references must be initialized 
lvalue refereneces must be bound to a modifiable value
- can't do int& ref = 5 bc 5 is not modifiable
- usually, the type of the refernece must match the type of the referent (there are some exceptions)
- can't have lvalue references to void (no point)
- references can't be reset (changed to refer to another object)
- scope and duration are the same as normal variables
*/

int main()
{
    int x { 5 };
    int y { 6 };
    int& ref { x }; // ref is now an alias for x
    ref = y; // assigns 6 (the value of y) to x (the object being referenced by ref)
    std::cout << x << '\n'; // user is expecting this to print 5
    return 0;
} //this will print 6 not 5 
//this happens because the expression evaluates as if it was written x=y. since y is 6, x=6 now

int scope()
{
    int x { 5 };
    {
        int& ref { x };   // ref is a reference to x
        std::cout << ref << '\n'; // prints value of ref (5)
    } // ref is destroyed here -- x is unaware of this
    std::cout << x << '\n'; // prints value of x (5)
    return 0;
} // x destroyed here

/*
Dangling references - when an object being referenced is destroyed before the refernece to it, the reference is left referencing
an object that no longer exists. this is called a dangling reference
- wow try saying that out loud
- leads to undefined behavior

Referneces are not objects. it is not required to exist or copy storage. you can't have a reference to a reference
*/

/*
LVALUE REFERNCES TO CONST
*/

int constref(){
    const int x = 5;
    const int& ref = x; //this is allowed!!!
    //ref = 6; //this is NOT allowed
}

int constrefmodify(){
    int x = 5;
    const int& ref = x; //this is allowed!!!
    x = 6; //this is also allowed
}

/*
lvalues references t const can also bind to rvalues
when this happens, a temp object is created and initialized with the rvalue, and the reference to const is bound tothat temp object
*/

int bind2rval(){
    const int& ref {5}; //fine, 5 is an rvalue
    std::cout << ref << '\n'; //prints 5
}

/*
lvalue references to const can bind to  values of a different type as long as those values can be implicitly converted to the reference type
temp objects are normally ddestroyed at the end of the expression in which they are created
*/

int difftype()
{
    // case 1
    const double& r1 { 5 };  // temporary double initialized with value 5, r1 binds to temporary
    std::cout << r1 << '\n'; // prints 5
    // case 2
    char c { 'a' };
    const int& r2 { c };// temporary int initialized with value 'a', r2 binds to temporary
    std::cout << r2 << '\n'; // prints 97 (since r2 is a reference to int)
    return 0;
}

/*
WHAT IS THE DIFFERENCE BETWEEN CONST AND CONSTEXPR
const: Marks variables as immutable post-initialization, ensuring their values cannot be modified.
constexpr: Enables the evaluation of expressions at compile-time, enhancing performance through constants and functions that the 
compiler can resolve prior to runtime.
*/
int g_x { 5 };
int constexprstuff()
{
    [[maybe_unused]] constexpr int& ref1 { g_x }; // ok, can bind to global
    static int s_x { 6 };
    [[maybe_unused]] constexpr int& ref2 { s_x }; // ok, can bind to static local
    int x { 6 };
    //[[maybe_unused]] constexpr int& ref3 { x }; // compile error: can't bind to non-static object
    return 0;
}

//when deifning a constexpr reference to a const variable, we need to use both constexp (applied to reference) and const (applies to type being referneced)
int main()
{
    static const int s_x { 6 }; // a const int
    [[maybe_unused]] constexpr const int& ref2 { s_x }; // needs both constexpr and const

    return 0;
}