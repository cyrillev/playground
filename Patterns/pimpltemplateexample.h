#ifndef PIMPLTEMPLATEEXAMPLE_H
#define PIMPLTEMPLATEEXAMPLE_H


#include "common.h"

template<typename U> class PimplExampleTemplateImplementation;

template<typename T>
class PimplTemplateExample : public Verbose
{
public:
    PimplTemplateExample();
    PimplTemplateExample(string name);
    PimplTemplateExample(const PimplTemplateExample<T>& rhs);
    PimplTemplateExample& operator=(const PimplTemplateExample<T>& rhs);
    virtual ~PimplTemplateExample();

    // implement swap
    void swap(PimplTemplateExample<T>& other);

    // overriden from Verbose
    void serialize(ostream& os) const;

    void add(const T& data);

private:


    // C++11: please use std::unique_ptr
    typedef shared_ptr< PimplExampleTemplateImplementation<T> > ptrImpl;
    ptrImpl pImpl;
};

#endif // PIMPLTEMPLATEEXAMPLE_H
