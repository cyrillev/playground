#include "common.h"

#include "Patterns/uncopyable.h"



class MyUncopyableExample : private Verbose, private Uncopyable
{
public:
    MyUncopyableExample()
    {
        cout << "MyUncopyableExample with no arg" << endl;
    }

    MyUncopyableExample(int dummy)
    {
        cout << "MyUncopyableExample with dummy: " << dummy << endl;
    }
};


void test_uncopyable()
{
    MyUncopyableExample dummy;
    MyUncopyableExample dummy2(1);

    // DO NOT COMPILE
    // MyUncopyableExample dummy3(dummy);  // error: 'Uncopyable::Uncopyable(const Uncopyable&)' is private
    // MyUncopyableExample dummy4 = dummy; // error: 'Uncopyable::Uncopyable(const Uncopyable&)' is private
    // dummy2 = dummy;                     // error: 'Uncopyable& Uncopyable::operator=(const Uncopyable&)' is private
}
