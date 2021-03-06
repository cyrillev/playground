#ifndef VERBOSE_H
#define VERBOSE_H

#include "common.h"

class Verbose : public serializable<Verbose>
{
public:
    Verbose();
    Verbose(const string& name);
    Verbose(const Verbose& rhs);  // copy constructor
    virtual ~Verbose();
    Verbose& operator = (const Verbose& rhs);   // copy assignement operator
    void swap(Verbose& rhs);

#ifdef CPLUSPLUS11
    Verbose(const Verbose&& rhs); // move constructor
    Verbose& operator = (Verbose&& rhs) ; // move assignement operator
#endif

    const string getName() const;
    virtual void serialize(ostream& os) const;

private:
    string name;
    const unsigned int instance;
};

class VerboseThread : public Verbose
{
public:
    VerboseThread(const string& name);
    void Run();

    // overriden from Verbose
    void serialize(ostream& os) const;

protected:
    void randomSleep();
    virtual void process() = 0;
};

#endif // VERBOSE_H
