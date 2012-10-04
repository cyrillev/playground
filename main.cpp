#include "common.h"

#define RUN_TEST(test) \
    extern void test(); \
    cout << "----- " << #test << " ------"  << endl; \
    test();  \
    cout << endl;


int main()
{
    // RUN_TEST( test_verbose );

    // SMART POINTERS
    // RUN_TEST( test_SharedObjectWithCustomDeleter );

    // PATTERNS
    // RUN_TEST( test_uncopyable );
    // RUN_TEST( test_pimpl );
    // RUN_TEST( test_pimpl_temlate );
    // RUN_TEST( test_strategy );

    // EXCEPTIONS
    // RUN_TEST( test_exceptions );
     RUN_TEST( test_exception_specifications );
    // RUN_TEST( test_ExceptionSafeDestructor );
}

