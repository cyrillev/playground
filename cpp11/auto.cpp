#include "common.h"

void f(int i)
{
    cout << "f: i=" << i;
}

void test_auto()
{
    auto i = 42;
    auto d = f;

    d(i);

    // d = i; // DOES NOT COMPILE: error: assigning to 'void (*)(int)' from incompatible type 'int'
}
