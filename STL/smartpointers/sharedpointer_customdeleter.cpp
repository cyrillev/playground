#include "common.h"

class SharedPtrWithCustomDeleter;

class SharedObjectWithCustomDeleter : public Verbose
{
public:
    explicit SharedObjectWithCustomDeleter(string name) : Verbose(name) {}
    static shared_ptr<SharedObjectWithCustomDeleter> createSharedObjectWithCustomDeleter();
};


void getRidOfSharedObjectWithCustomDeleter(SharedObjectWithCustomDeleter *pThis)
{
    cout << "getRidOfSharedObjectWithCustomDeleter " << pThis << endl;
    delete pThis;
    // Add specific code if needed (unlock mutex, etc.)
}

shared_ptr<SharedObjectWithCustomDeleter> SharedObjectWithCustomDeleter::createSharedObjectWithCustomDeleter()
{
    // This doesn't compile
    // shared_ptr<SharedObjectWithCustomDeleter>(0, getRidOfSharedObjectWithCustomDeleter);

    shared_ptr<SharedObjectWithCustomDeleter> object(new SharedObjectWithCustomDeleter("SharedObjectWithCustomDeleter"), getRidOfSharedObjectWithCustomDeleter);

    return object;
}

void test_SharedObjectWithCustomDeleter()
{
    shared_ptr<SharedObjectWithCustomDeleter> object( SharedObjectWithCustomDeleter::createSharedObjectWithCustomDeleter() );

}
