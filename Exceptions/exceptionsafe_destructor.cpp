#include "exceptionsafe_destructor.h"

#include "common.h"

ExceptionSafeDestructor::~ExceptionSafeDestructor()
{
    cout << "ExceptionSafeDestructor BEGIN Destroy " << this << endl;

    try
    {
        // Scott Myers - Effective C++ 3rd ed. - Item 8
        // Destructors shold never emit exceptions
        // Destructors should catch any exceptions and then swallow them or terminate the app.
        if ( ! hasAcquiredResources )
        {
            releaseResources();
        }
    }
    catch(...)
    {
        cout << "Releasing resources has thrown an exception " << endl;
    }

    cout << "ExceptionSafeDestructor END Destroy " << this << endl;
}

void ExceptionSafeDestructor::acquireResources()
{
    cout << "Verbose acquireResources " << endl;
    if (hasAcquiredResources)
    {
        throw "resources already acquired";
    }
    else
    {
        doAcquireResources();
        hasAcquiredResources = true;
    }
}

void ExceptionSafeDestructor::releaseResources()
{
    cout << "Verbose releaseResources " << endl;
    if ( ! hasAcquiredResources)
    {
        throw logic_error( string("resources were not opened") );
    }
    else
    {
        doReleaseResources();
        hasAcquiredResources = false;
    }
}




class BadExample : public Verbose
{
public:
    BadExample() : Verbose("BadExample") {}
    BadExample(string name) : Verbose(name) {}
    ~BadExample() { throw logic_error( string("BadExample throw exception in destructor") ); }
};

class MyExceptionSafeDestructor : public ExceptionSafeDestructor
{
public:
    void releaseResources() { throw logic_error( string("MyExceptionSafeDestructor cannot release resources") ); }
};

void test_ExceptionSafeDestructor()
{
    vector< shared_ptr<ExceptionSafeDestructor> > safeExamples;
    safeExamples.push_back( shared_ptr<ExceptionSafeDestructor>( new ExceptionSafeDestructor() ));
    safeExamples.push_back( shared_ptr<ExceptionSafeDestructor>( new ExceptionSafeDestructor() ));
    safeExamples.push_back( shared_ptr<ExceptionSafeDestructor>( new ExceptionSafeDestructor() ));
    safeExamples.clear();

    try
    {
        BadExample badExample1("badExample1");
    }
    catch(...)
    {
        cout << "It works but next bad example does not";
    }


#if THIS_BAD_CODE_CRASHES
    try
    {
        BadExample badExample2("badExample2");
        BadExample badExample3("badExample3");
    }
    catch(...)
    {
        cout << "This line is never displayed";
    }
#endif
}
