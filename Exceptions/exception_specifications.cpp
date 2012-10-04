#include "common.h"


class MyException : public Verbose
{
public:
    MyException() : Verbose("MyException") {}
    MyException(string name) : Verbose(name) {}

    virtual const char* what() const throw() // this function throws no exceptions
    { return "because I am MyException"; }
};



// No exception specifications => may throw anything
void function_may_throw_anything()
{
    throw MyException();
}


// exception speficiations: SHOULD only throw int
void function_throw_int() throw(int)
{
    throw 3;
}

// exception speficiations:
// only throw int or the standard exception
// NOTE: it is important that all functions can throw the standard exception
// in order for convertUnexpected to rethrow bad_exception
void function_spec_throw_int()  throw(int, exception)
{
    function_may_throw_anything();
}


void convertUnexpected()
{
    // throw a standard exception
    cout << "convertUnexpected throws bad_exception" << endl;
    throw bad_exception();
}



void test_exception_specifications()
{
    try
    {
        function_throw_int();
    }
    catch(int e)
    {
        cout << "test_exception_specifications got int = " << e << endl;
    }


    std::set_unexpected( convertUnexpected );
    try
    {
        // The application CRASHES because an unexpected exception has been thrown
        // the behaviour is to terminate the application
        // the unexpected can not be caught here.
        function_spec_throw_int();
    }
    catch(exception& e)
    {
        cout << "test_exception_specifications got exception e " << e.what() << endl;
    }
    catch(int e)
    {
         cout << "test_exception_specifications got int = " << e << endl;
    }
}
