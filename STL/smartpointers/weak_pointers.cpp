#include "common.h"

class Person : public enable_shared_from_this<Person>
{
public:
    string name;
    shared_ptr<Person> mother;
    shared_ptr<Person> father;
    vector< weak_ptr<Person> > kids;

    Person(const string& _name,
           shared_ptr<Person> _mother = shared_ptr<Person>(),
           shared_ptr<Person> _father = shared_ptr<Person>())
        : name(_name), mother(_mother), father(_father)
    {}

    void setParentsAndTheirKids (
            shared_ptr<Person> _mother = shared_ptr<Person>(),
            shared_ptr<Person> _father = shared_ptr<Person>())
    {
        mother = _mother;
        father = _father;

        if (_mother)
        {
            // BAD!!! _mother->kids.push_back(shared_ptr<Person>(this));
            _mother->kids.push_back( shared_from_this() );
        }
        if (_father)
        {
            // BAD !!! _father->kids.push_back(shared_ptr<Person>(this));
            _father->kids.push_back( shared_from_this() );
        }
    }

    ~Person() { cout << "delete " << name << endl; }
};

void test_weak_pointers()
{
    {
        cout << "test shared_ptr/weak_ptr" << endl;
        shared_ptr<Person> mother(new Person("nico's mom"));
        shared_ptr<Person> father(new Person("nico's dad"));
        shared_ptr<Person> kid(new Person("nico", mother, father));

        mother->kids.push_back(kid);
        father->kids.push_back(kid);

        cout << "Nico's family:" << endl;
        cout << " - Nico is shared " << kid.use_count() << " times" << endl;
        cout << " - name of 1st kid of nico's mom: " << kid->mother->kids[0].lock()->name << endl;

        kid = shared_ptr<Person>(new Person("new kid"));
    }
    {
        cout << endl << "test shared_from_this" << endl;
        shared_ptr<Person> mother(new Person("nico's mom"));
        shared_ptr<Person> father(new Person("nico's dad"));
        shared_ptr<Person> kid(new Person("nico"));
        kid->setParentsAndTheirKids(mother, father);

        cout << "Nico's family:" << endl;
        cout << " - Nico is shared " << kid.use_count() << " times" << endl;
        cout << " - name of 1st kid of nico's mom: " << kid->mother->kids[0].lock()->name << endl;

        kid = shared_ptr<Person>(new Person("new kid"));
    }
}
