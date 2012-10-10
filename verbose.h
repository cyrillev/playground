#ifndef VERBOSE_H
#define VERBOSE_H

#include "common.h"

class Verbose : public serializable<Verbose>
{
public:
    Verbose();
    Verbose(const string& name);
    Verbose(const Verbose& rhs);  // copy constructor
    Verbose(const Verbose&& rhs); // move constructor

    virtual ~Verbose();

    Verbose& operator = (const Verbose& rhs);   // copy assignement operator
    Verbose& operator = (Verbose&& rhs) ; // move assignement operator
    void swap(Verbose& rhs);

    const string getName() const;
    virtual void serialize(ostream& os) const;

private:
    string name;
    const unsigned int instance;
};

#endif // VERBOSE_H
