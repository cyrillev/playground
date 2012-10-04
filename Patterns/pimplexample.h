#ifndef PIMPLEXAMPLE_H
#define PIMPLEXAMPLE_H

#include "common.h"

class PimplExample : public Verbose
{
public:
    PimplExample();
    PimplExample(string name);
    PimplExample(const PimplExample& rhs);
    PimplExample& operator=(const PimplExample& rhs);
    virtual ~PimplExample();

    // implement swap
    void swap(PimplExample& other);

    // overriden from Verbose
    void serialize(ostream& os) const;

private:
    class PimplExampleImplementation;

    // C++11: please use std::unique_ptr
    shared_ptr<PimplExampleImplementation> pImpl;
};

#endif // PIMPLEXAMPLE_H
