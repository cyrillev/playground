#include "common.h"

void test_for()
{
    cout << "--- Range-based for loops, elem is a copy ---" << endl;
    for (Verbose obj1 : {Verbose("Paris"), Verbose("Oslo")})
    {
        // obj is a copy of the element in the initialization list
        cout << "obj1: " << obj1 << endl;
    }

    cout << "--- Range-based for loops, elem is a reference ---" << endl;
    {
        list<Verbose> cities;

        auto orleans = Verbose("Orleans");
        auto york = Verbose("York");
        cities.push_back( std::move(orleans) );
        cities.push_back( std::move(york) );

        for (Verbose& obj2 : cities)
        {
            // obj is a reference of the element in the initialization list
            cout << " => obj2: " << obj2 << endl;
            obj2 = Verbose("New " + obj2.getName());
        }

        for (Verbose& obj3 : cities)
        {
            // obj is a reference of the element in the initialization list
            cout << " => obj3: " << obj3 << endl;
        }
    }

    int sum = 10;
    for ( auto elem : { sum, sum*2, sum*4} )
    {
        cout << elem << endl;
    }
}
