#ifndef VERBOSE_H
#define VERBOSE_H

#include "common.h"

class Verbose : public serializable<Verbose>
{
public:
    Verbose();
    Verbose(const string& name);
    Verbose(const Verbose& rhs);

    virtual ~Verbose();

    Verbose& operator = (Verbose rhs);

    void swap(Verbose& rhs);


    virtual void serialize(ostream& os) const;

private:
    std::string name;
    const unsigned int instance;
};

#endif // VERBOSE_H
