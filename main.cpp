#include "common.h"

#define RUN_TEST(test) \
    extern void test(); \
    cout << "----- " << #test << " ------"  << endl; \
    test();  \
    cout << endl;


int main()
{
    // RUN_TEST( test_verbose );
    // RUN_TEST( test_uncopyable );
    // RUN_TEST( test_ExceptionSafeDestructor );
    // RUN_TEST( test_SharedObjectWithCustomDeleter );
    // RUN_TEST( test_pimpl );
    RUN_TEST( test_pimpl_temlate );

}

