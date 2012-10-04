#include "limitedinstances.h"




class MyExample : public Verbose, private Limiter<MyExample>
{
public:
    static shared_ptr<MyExample>  makeExample();
    static shared_ptr<MyExample>  makeExample(const string& name);
    static shared_ptr<MyExample>  makeExample(const MyExample& rhs);

    void doSomething() { cout << *this << " did something" << endl; }

private:
    // Private constructors
    MyExample();
    MyExample(const string & name);

    // Private copy-constructor
    MyExample(const MyExample& rhs) : Verbose(rhs), Limiter<MyExample>(rhs) {}
};

template<>
const size_t Limiter<MyExample>::maxInstances = 2;


/* static */ shared_ptr<MyExample> MyExample::makeExample()
{
    return shared_ptr<MyExample>( new MyExample() );
}

/* static */ shared_ptr<MyExample> MyExample::makeExample(const string& name)
{
    return shared_ptr<MyExample>( new MyExample(name) );
}


/* static */ shared_ptr<MyExample> MyExample::makeExample(const MyExample& rhs)
{
    return shared_ptr<MyExample>( new MyExample(rhs) );
}


// Private constructors
MyExample::MyExample()
    : Verbose(), Limiter<MyExample>()
{
}
MyExample::MyExample(const string & name)
    : Verbose(name), Limiter<MyExample>()
{
}




// TEST
void test_limitedInstances()
{
    shared_ptr<MyExample> instance1 = MyExample::makeExample( "instance1" );
    shared_ptr<MyExample> instance2 = MyExample::makeExample( *instance1 );
    shared_ptr<MyExample> instance3;
    try
    {
        instance3 = MyExample::makeExample( *instance2 );
    }
    catch(Limiter<MyExample>::TooManyInstances & e)
    {
        cout << "Too many instances, already " << e.nbrOfRunningInstances() << " running instances" << endl;
    }

    instance1->doSomething();
    instance2->doSomething();

    // destroy instance1
    instance1.reset();


    try
    {
        instance3 = MyExample::makeExample( "force_exception_in_constructor" );
    }
    catch(exception e)
    {
        // The number of running instance must NOT be increased
        cout << "Got exception when creating instance" << endl;
    }

    instance3 = MyExample::makeExample( "instance3" );
    instance3->doSomething();
}
