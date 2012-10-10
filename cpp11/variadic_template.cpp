#include "common.h"

/*
// Stop the recursion
// Both print() and print(const T&arg) are valids
void print()
{

}
*/

// Stop the recursion
template <typename T>
void print(const T&arg)
{
    cout << arg << endl;
}

// Variadic templates
template <typename T, typename... Types>
void print(const T& firstArg, const Types&... args)
{
    cout << firstArg << " ";
    print (args...); // recursive call to the variadic template.
}

template <typename T, typename... Types>
void display(const T& firstArg, const Types&... args)
{
    // sizeof...(args) return the number of "args"
    // note: don't forget to count firstArg.

    cout << "I have "<< sizeof...(args) + 1 << " argument(s): ";
    print (firstArg, args...); // recursive call to the variadic template.
}

void test_variadic_template()
{
    display (7.5, "hello", std::bitset<16>(0xAB), 42);
    display (7.5);

    // display (); //  note: candidate function template not viable: requires at least 1 argument, but 0 were provided
}
