#include "verbose.h"
#include "common.h"

static unsigned int globalCounter = 0;

unsigned int getNewInstance()
{
    return ++globalCounter;
}


Verbose::Verbose()
    : name("unnamed"),  instance(getNewInstance())
{
    cout << "Default construct " << *this << endl;
}

Verbose::Verbose(const Verbose& rhs)
    : name(string("copy of ") + rhs.name),  instance(getNewInstance())
{
    if (name.find("force_exception_in_copy_constructor") != string::npos)
    {
        cout << "EXCEPTION when creating " << *this << endl;

        throw exception();
        // Note: the destructor of this object is not called
        // because the objet is not yet alive
    }

    cout << "Copy construct " << *this << " from " << rhs << endl;
}

Verbose::Verbose(const string & _name)
    : name(_name),  instance(getNewInstance())
{
    if (name.find("force_exception_in_constructor") != string::npos)
    {
        cout << "EXCEPTION when creating " << *this << endl;

        throw exception();
        // Note: the destructor of this object is not called
        // because the objet is not yet alive
    }

    cout << "Construct " << *this << endl;
}

Verbose::~Verbose()
{
    cout << "Destroy " << *this << endl;
}

void Verbose::serialize(ostream& os) const
{
    os << "object #" + to_string(instance) + " named <" + name + ">";
}

void Verbose::swap(Verbose& rhs)
{
    cout << "Swap " << *this << " <-> " << rhs << endl;
    std::swap(name, rhs.name);
}

Verbose& Verbose::operator = (Verbose rhs)
{
    cout << "assignement " << *this << " = " << rhs << endl;
    swap(rhs);
    return *this;
}





void test_verbose()
{
    const Verbose obj1("const");
    Verbose obj2("obj2");
    Verbose obj3 = obj2;

    obj3.swap(obj2);
    obj3 = obj1;
}
