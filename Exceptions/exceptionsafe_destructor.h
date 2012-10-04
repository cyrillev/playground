#ifndef EXCEPTIONSAFE_DESTRUCTOR
#define EXCEPTIONSAFE_DESTRUCTOR

#include "verbose.h"

class ExceptionSafeDestructor : private Verbose
{
public:
    ~ExceptionSafeDestructor();

    // these 2 functions may throw an exception
    // sub-classes can override doAcquireResources and doReleaseResources()
    void acquireResources();
    void releaseResources();

protected:
    // these 2 functions may throw an exception
    void doAcquireResources() {}
    void doReleaseResources() {}

private:
    bool hasAcquiredResources;
};

#endif // EXCEPTIONSAFE_DESTRUCTOR
