#ifndef VERBOSE_H
#define VERBOSE_H

#include "common.h"

class Verbose : public serializable<Verbose>
{
public:
    Verbose();
    Verbose(std::string name);
    Verbose(const Verbose& rhs);

    virtual ~Verbose();

    Verbose& operator = (Verbose rhs);

    void swap(Verbose& rhs);


    virtual void serialize(std::ostream& os) const;

private:
    std::string name;
    const unsigned int instance;
};

#endif // VERBOSE_H
