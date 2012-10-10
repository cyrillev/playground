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
    // RUN_TEST( test_virtual_constructor );
    // RUN_TEST( test_limitedInstances );
    // RUN_TEST( test_double_dispatcher );

    // EXCEPTIONS
     //RUN_TEST( test_exceptions );
     //RUN_TEST( test_exception_specifications );
     // RUN_TEST( test_ExceptionSafeDestructor );

    // C++11
    // RUN_TEST( test_auto );
    // RUN_TEST( test_initialization );
    // RUN_TEST( test_lambda );
    // RUN_TEST( test_for );
    RUN_TEST( test_constexpr );
}

