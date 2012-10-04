#include "common.h"


class MyException : public Verbose
{
public:
    MyException() : Verbose("MyException") {}
    MyException(const string & name) : Verbose(name) {}

    virtual const char* what() const throw() // this function throws no exceptions
    { return "because I am MyException"; }
};

class MySpecialException : public MyException
{
public:
    MySpecialException() : MyException("MySpecialException") {}

    virtual const char* what() const throw() // this function throws no exceptions
    { return "because I am MySpecialException"; }
};



void throw_exception_by_value()
{
    MyException e;
    throw e; // object is copied and thrown
}



void throw_exception_by_value_2()
{
    MySpecialException special;
    MyException& ref = special;

    throw ref; // MySpecialException object is copied as a MyException and thrown
}

void throw_special_exception()
{
    throw MySpecialException();
}

void test_exceptions()
{
    cout << "==== throw_exception_by_value ==== " << endl;
    try
    {
        throw_exception_by_value();
    }
    catch(MyException e)
    {
        // a copy of e is caught.
        // MyException has been constructed 3 times!
        cout << "Got exception " << e << " what: " << e.what() << endl;
    }



    cout << endl << "==== throw_exception_by_value_2 ==== " << endl;
    try
    {
        throw_exception_by_value_2();
    }
    catch(MySpecialException e)
    {
        // not caught here! e is a MyException!
        cout << "Got MySpecialException " << e << " what: " << e.what() << endl;
    }
    catch(MyException e)
    {
        // a copy of e is caught.
        // MyException has been constructed 3 times!
        cout << "Got MyException " << e << " what: " << e.what() << endl;
    }




    cout << endl << "==== throw_exception_by_value_catch_by_ref ==== " << endl;
    try
    {
        throw_exception_by_value_2();
    }
    catch(MySpecialException& e)
    {
        // not caught here! e is a MyException!
        cout << "Got MySpecialException " << e << " what: " << e.what() << endl;
    }
    catch(MyException& e)
    {
        // a copy of e is caught.
        // MyException has been constructed 2 times!
        cout << "Got MyException " << e << " what: " << e.what() << endl;
    }

    cout << endl << "==== throw_special_exception_catch_exception_by_value ==== " << endl;
    try
    {
        throw_special_exception();
    }
    catch(MyException e)
    {
        // exception e has been sliced off.
        // what() returns "because I am MyException"
        cout << "Got MyException " << e << " what: " << e.what() << endl;
    }


    cout << endl << "==== throw_special_exception_catch_exception_by_ref ==== " << endl;
    try
    {
        throw_special_exception();
    }
    catch(MyException& e)
    {
        // what() returns "because I am MySpecialException"
        cout << "Got MyException " << e << " what: " << e.what() << endl;
    }

}
