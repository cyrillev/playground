#include "common.h"

condition_variable c1,c2;
mutex mutex_is_A1_executed;
bool is_A1_executed;
mutex mutex_is_A2_executed;
bool is_A2_executed;

class Thread_A : public VerboseThread
{
public:
    Thread_A() :
        VerboseThread( "Thread_A" ) {}

    ~Thread_A() {}

protected:
    virtual void process()
    {
        randomSleep();

        cout << *this << "==> BEGIN Execute A1" << endl;
        randomSleep();
        {
            lock_guard<mutex> lock(mutex_is_A1_executed);
            is_A1_executed = true;
        }
        cout << *this << "==> END Execute A1" << endl;
        c1.notify_all();

        randomSleep();
        cout << *this << "==> Execute A2" << endl;
        randomSleep();
    }

};

class Thread_B : public VerboseThread
{
public:
    Thread_B() : VerboseThread( "Thread_B" ) {}
    ~Thread_B() {}

protected:
    virtual void process()
    {
        randomSleep();

        unique_lock<mutex> lock(mutex_is_A1_executed);
        if (!is_A1_executed)
        {
            cout << *this << "Wait for A1 to be executed" << endl;
            c1.wait(lock);
        }
        else
        {
            cout << *this << "A1 had already been executed" << endl;

        }

        cout << *this << "==> Execute B1" << endl;
        randomSleep();
        cout << *this << "==> Execute B2" << endl;
    }
};


void test_condition_variable()
{
    Thread_A a;
    Thread_B b;

    thread thread_a( &Thread_A::Run, &a);
    thread thread_b( &Thread_B::Run, &b);

    thread_a.join();
    thread_b.join();
}
