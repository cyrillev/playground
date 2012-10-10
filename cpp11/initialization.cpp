#include "common.h"

template<typename T>
string to_string (std::initializer_list<T> vals)
{
    stringstream result;
    for (const auto &p : vals)
    {
        result << p << " ";
    }

    return result.str();
}


class Test
{
public:
    Test(int a, int b)
    { cout << "Test(int a, int b)  with a: " << a << " and b: " << b << endl; }

    Test(std::initializer_list<int> vals)
    { cout << "Test(initializer_list<int> vals) with vals: " << to_string(vals) << endl; }
};


class TestExplicit
{
public:
    explicit TestExplicit(int a, int b)
    { cout << "TestExplicit(int a, int b)  with a: " << a << " and b: " << b << endl; }
};


void test_initialization()
{
    int i;    // warning: variable 'i' is uninitialized when used here [-Wuninitialized]
    int j{};  // j is initialized by 0
    int *p;   // warning: variable 'p' is uninitialized when used here [-Wuninitialized]
    int *q{}; // q is initialized by nullptr
    string s{"hello"};

    vector<string> cities { "Paris", "Oslo" };
    complex<double> c{4.0, 3.0};

    // int x3{5.0}; // error: type 'double' cannot be narrowed to 'int' in initializer list [-Wc++11-narrowing]


    cout << "i: " << i << endl;
    cout << "j: " << j << endl;
    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "cities: " <<  boost::algorithm::join(cities, ", ") << endl;
    cout << "c: " << c << endl;

    cout << to_string( {1, 2, 4, 8} ) << endl;

    {
        Test test1(77,5);
        Test test2{77,5};
        Test test3{1,2,3};
        Test test4 = {11,22};
    }
    {
        TestExplicit test1(1,2);
        TestExplicit test2{3,4}; // should NOT compile because implicit conversion is disallowed by "explicit" constructor
    }

}
