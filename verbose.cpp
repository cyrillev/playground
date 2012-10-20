#include "verbose.h"
#include "common.h"

static unsigned int globalCounter = 0;

unsigned int getNewInstance()
{
    return ++globalCounter;
}


Verbose::Verbose()
    : name(string(typeid(*this).name())),  instance(getNewInstance())
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


#ifdef CPLUSPLUS11
Verbose::Verbose(const Verbose&& rhs)
    : name( std::move(rhs.name)), instance(getNewInstance())
{
    cout << "Move constructor " << *this << " from " << rhs << endl;
}
#endif

Verbose::Verbose(const string & _name)
    : name(_name), instance(getNewInstance())
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

 // our own implementation of swap must NOT throw exceptions
void Verbose::swap(Verbose& rhs)
{
    cout << "Swap " << *this << " <-> " << rhs << endl;
    std::swap(name, rhs.name); // do not throw exceptions
}


Verbose& Verbose::operator = (const Verbose& rhs)
{
    cout << "copy assignement " << *this << " = " << rhs << endl;

    // make a copy of the right-hand side
    // The copy-constructor may throw, but the left-hand side has not been modified yet
    // => the left-hand side (this) is still a valid object
    Verbose copy = rhs;

    // our own implementation of swap must NOT throw exceptions
    swap(copy);
    return *this;
}

#ifdef CPLUSPLUS11
Verbose& Verbose::operator = (Verbose&& rhs)
{
    cout << "Move assignement " << *this << " = " << rhs << endl;

    name = std::move( rhs.name );

    // std::move nullify the right-hand side string
    // butjust to mark it invalid :
    rhs.name = "INVALIDATED AFTER MOVE OPERATION";

    return *this;
}
#endif

const string Verbose::getName() const
{
    return name;
}


void test_verbose()
{
    const Verbose obj1("obj1");

    cout << "-- Verbose obj2(\"obj2\"); -- " << endl;
    Verbose obj2("obj2");

    cout << "-- Verbose obj3 = obj2; -- " << endl;
    Verbose obj3 = obj2;

    cout << "-- obj3.swap(obj2); -- " << endl;
    cout  << "obj3: " << obj3 << endl;
    cout  << "obj2: " << obj2 << endl;
    obj3.swap(obj2);
    cout  << "obj3: " << obj3 << endl;
    cout  << "obj2: " << obj2 << endl;


    cout << "-- obj3 = obj1 -- " << endl;
    cout  << "obj3: " << obj3 << endl;
    cout  << "obj1: " << obj1 << endl;
    obj3 = obj1;
    cout  << "obj3: " << obj3 << endl;
    cout  << "obj1: " << obj1 << endl;

#ifdef CPLUSPLUS11
    cout << "-- obj2 = std::move(obj3) -- " << endl;
    cout  << "obj2: " << obj2 << endl;
    cout  << "obj3: " << obj3 << endl;
    Verbose& mObj3 = obj3;
    obj2 = std::move(mObj3);
    cout  << "obj2: " << obj2 << endl;
    cout  << "obj3: " << obj3 << endl;
#endif
}
