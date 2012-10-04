#include "common.h"

// More effective C++ - Item 25
// This pattern can be used by a container
// to duplicate its objects when
// it only has pointers to interface

class Interface : public Verbose
{
public:
    Interface(string name) : Verbose(name) {}

    // virtual copy constructor
    virtual Interface * clone() const = 0;
};

class Class_A : public Interface
{
public:
    Class_A() : Interface("Class_A") {}

    Interface * clone() const
    { return new Class_A(*this); }
};

class Class_B : public Interface
{
public:
    Class_B() : Interface("Class_B") {}

    Interface * clone() const
    { return new Class_B(*this); }
};



class Container
{
public:
    Container();
    Container(const Container& rhs);

private:
    list< shared_ptr<Interface> > components;
};

Container::Container()
{
    shared_ptr<Interface> obj1( new Class_A());
    shared_ptr<Interface> obj2( new Class_B());

    components.push_back( obj1 );
    components.push_back( obj2 );
}

Container::Container(const Container& rhs)
{
    list< shared_ptr<Interface> >::const_iterator it;

    // clone all elements of the list
    for (it = rhs.components.begin();
         it != rhs.components.end();
         ++it )
    {
        components.push_back( shared_ptr<Interface>((*it)->clone()) );
    }
}

void test_virtual_constructor()
{
    Container container1;
    Container container2 = container1;
}
