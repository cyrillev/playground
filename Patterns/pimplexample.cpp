#include "pimplexample.h"
#include "common.h"

namespace std
{
template<>
void swap<PimplExample>(PimplExample& a, PimplExample&b)
{
    cout << " swap BEGIN " << a << " <=> " << b << endl;
    a.swap(b);
    cout << " swap END " << a << " <=> " << b << endl;
}
}



class PimplExample::PimplExampleImplementation : public Verbose
{
public:
    PimplExampleImplementation() : Verbose() {}
    PimplExampleImplementation(string name) : Verbose(name) {}
private:
    // Add implementation specific data here
};

PimplExample::PimplExample()
    : Verbose(),
    pImpl( shared_ptr<PimplExampleImplementation>(new PimplExample::PimplExampleImplementation() ))
{}

PimplExample::PimplExample(string name)
    : Verbose(name),
      pImpl ( shared_ptr<PimplExampleImplementation>(new PimplExample::PimplExampleImplementation(string("implementation of ") + name)))
{}

PimplExample::PimplExample(const PimplExample& rhs)
    : Verbose(rhs),
              pImpl( shared_ptr<PimplExampleImplementation>(new PimplExample::PimplExampleImplementation(*(rhs.pImpl)) ))
{}

PimplExample::~PimplExample()
{
}


PimplExample& PimplExample::operator=(const PimplExample& rhs)
{
    if (this != &rhs) // identity test: may not be needed
    {
        *pImpl = *(rhs.pImpl); // exception safe
    }

    return *this;
}


void PimplExample::swap(PimplExample& other)
{
    cout << "PimplExample::swap BEGIN" << endl;

    using std::swap;
    swap(pImpl, other.pImpl);

    cout << "PimplExample::swap END" << endl;
}

void PimplExample::serialize(ostream& os) const
{
    os << *pImpl << string(" has content: ");
}












void test_pimpltemplate()
{
    //PimplExample a;
    //PimplExample fake(NULL);

    cout << "==== PimplExample a first ==== " << endl;
    PimplExample a("first");

    cout << "==== PimplExample b second ==== " << endl;
    PimplExample b("second");

    cout << "==== PimplExample c third ==== " << endl;
    PimplExample c("third");

    cout << "==== b = b ==== " << endl;
    b = b;

    cout << "==== a <=> b ==== " << endl;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    swap(a,b);
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;

    cout << "==== b = exception ==== " << endl;
    cout << "b: " << b << endl;
    try
    {
        PimplExample e("exception");
        b = e;
    } catch(...)
    {
        cout << "got exception " << endl;
    }

    cout << "b: " << b << endl;


    cout << "==== a = b = c ==== " << endl;
    a = b = c;
    cout << "a: " << a << endl;
    cout << "b: " << b << endl;
    cout << "c: " << c << endl;

    cout << "==== END ==== " << endl;
}
