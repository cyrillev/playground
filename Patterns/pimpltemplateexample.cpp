#include "pimpltemplateexample.h"
#include "common.h"

namespace std
{
template<typename T>
void swap(PimplTemplateExample<T>& a, PimplTemplateExample<T>& b)
{
    cout << "template swap BEGIN " << a << " <=> " << b << endl;
    a.swap(b);
    cout << "template swap END " << a << " <=> " << b << endl;
}
}


template<typename T>
struct PimplExampleTemplateImplementation : public Verbose
{

    PimplExampleTemplateImplementation() : Verbose() {}
    PimplExampleTemplateImplementation(string name) : Verbose(name) {}

    // Add implementation specific data here
    list<T> my_list;
};

template<typename T>
PimplTemplateExample<T>::PimplTemplateExample()
    : Verbose()
{
    pImpl = new PimplExampleTemplateImplementation<T>();
}


template<typename T>
PimplTemplateExample<T>::PimplTemplateExample(string name)
    : Verbose(name)
{
    pImpl = ptrImpl(new PimplExampleTemplateImplementation<T>(string("implementation of ") + name));
}

template<typename T>
PimplTemplateExample<T>::PimplTemplateExample(const PimplTemplateExample& rhs)
    : Verbose(rhs)
{
    pImpl = ptrImpl( new PimplExampleTemplateImplementation<T>(*(rhs.pImpl)) );
}

template<typename T>
PimplTemplateExample<T>::~PimplTemplateExample()
{
}


template<typename T>
PimplTemplateExample<T>& PimplTemplateExample<T>::operator=(const PimplTemplateExample<T>& rhs)
{
    if (this != &rhs) // identity test
    {
        *pImpl = *(rhs.pImpl); // exception safe
    }

    return *this;
}


template<typename T>
void PimplTemplateExample<T>::swap(PimplTemplateExample<T>& other)
{
    cout << "PimplExampleTemplate::swap BEGIN" << endl;

    using std::swap;
    swap(pImpl, other.pImpl);

    cout << "PimplExampleTemplate::swap END" << endl;
}

template<typename T>
void  PimplTemplateExample<T>::serialize(ostream& os) const
{
    string content = boost::algorithm::join(pImpl->my_list, ", ");
    os << *pImpl << string(" has content: ") << content;
}


template<typename T>
void PimplTemplateExample<T>::add(const T&data)
{
    pImpl->my_list.push_front(data);
}









void test_pimpl_temlate()
{
    //PimplExampleTemplate a;
    //PimplExampleTemplate fake(NULL);

    cout << "==== PimplExampleTemplate a first ==== " << endl;
    PimplTemplateExample<string> a("first");
    a.add("a");
    a.add("aa");

    cout << "==== PimplExampleTemplate b second ==== " << endl;
    PimplTemplateExample<string> b("second");
    b.add("b");
    b.add("bb");

    cout << "==== PimplExampleTemplate c third ==== " << endl;
    PimplTemplateExample<string> c("third");
    c.add("c");
    c.add("c");

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
        PimplTemplateExample<string> e("force_exception_in_copy_constructor");
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
