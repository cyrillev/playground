#include "common.h"

constexpr int square(int i)
{
    // cout << "square: i=" << i;  error: statement not allowed in constexpr function
    // int square = i*i; error: variables cannot be declared in a constexpr function
    // constexpr int result = i*i; // error: constexpr variable 'result' must be initialized by a constant expression

    // no internal variables
    // no dynamic casts
    // no memory allocation
    // no calls to non-constexpr functions
    // no conditional statement


    return i*i; //  non-void return type
}

constexpr int factorial (int n)
{
    return n > 0 ? n * factorial( n - 1 ) : 1;
}


constexpr const char* toString(bool value)
{
    // if (value) // error: statement not allowed in constexpr function
    //    return "true";

    return value ? "true" : "false";
}

class Rectangle
{
    public:
    constexpr Rectangle (int x, int y) : _x( x ), _y( y ) {}
    constexpr double getArea ()
    {
        return _x * _y ;
    }
    private:
        int _x;
        int _y;
};

void test_constexpr()
{
    // Build an array of 3^2 elements
    float array1[ square(3) ];

    // Build an array of factorial 4
   constexpr int factorial_4 = factorial(4);
   float array2[ factorial_4 ];

   cout << "square(3) = " << square(3) << endl;
   cout << "factorial(4) = " << factorial(4) << endl;
   cout << "toString(true) = " << toString(true) << endl;
   cout << "toString(1==2) = " << toString(1==2) << endl;
}
