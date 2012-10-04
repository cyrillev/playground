#ifndef LIMITEDINSTANCES_H
#define LIMITEDINSTANCES_H

#include "common.h"

// see More effectice C++ - Item 26
template<class T>
class Limiter
{
public:
    class TooManyInstances
    {
    public:
        TooManyInstances(int numInstances) : _numInstances(numInstances) {}
        int nbrOfRunningInstances() const { return _numInstances; }
    private:
        const int _numInstances;
    }; // exception

    static size_t nbrOfRunningInstances();

protected:
    Limiter();
    Limiter(const Limiter& rhs);
    ~Limiter();

protected:
    static size_t numInstances;
    static const size_t maxInstances;

    void init();
};




// IMPLEMENTATION

template<class T>
size_t Limiter<T>::numInstances = 0;

// protected constructor
template<class T>
Limiter<T>::Limiter()
{
    init();
}

// protected copy-constructor
template<class T>
Limiter<T>::Limiter(const Limiter<T> & /* rhs */ )
{
    init();
}

// protected destructor
template<class T>
Limiter<T>::~Limiter()
{
    --numInstances;
    cout << "Limiter: One instance has been destroyed => " << numInstances << "/" << maxInstances << " instances are now running" << endl;
}

template<class T>
void Limiter<T>::init()
{
    if (numInstances >= maxInstances)
        throw TooManyInstances(numInstances);

    ++numInstances;
    cout << "Limiter: One instance has been created => " << numInstances << "/" << maxInstances << " instances are now running" << endl;
}

template<class T>
/* static */ size_t Limiter<T>::nbrOfRunningInstances()
{
    return numInstances;
}

#endif // LIMITEDINSTANCES_H
