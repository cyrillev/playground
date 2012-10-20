#ifndef COMMON_H
#define COMMON_H

// STL string support
#include <ostream>
#include <iostream>
#include <sstream>
#include <string>

// STL exceptions
#include <stdexcept>

// STL smart pointers
#include <memory>

// STL containers
#include <vector>
#include <list>

// STL maths
#include <complex>

// std::tr1
#include <functional>

using namespace std;

//  Boost
#include <boost/algorithm/string/join.hpp>

#ifndef CPLUSPLUS11
#include <boost/shared_ptr.hpp>
#include <boost/function.hpp>
using boost::shared_ptr;
using boost::function;
#endif

// Useful template function to print any object
template<class T>
string to_string(T object)
{
    stringstream ss;
    string s;
    ss << object;
    s = ss.str();

    return s;
}



// see http://lifecs.likai.org/2010/10/c-overloading-operator-for-stdostream.html
template<class T>
class serializable
{
 public:
    void serialize(ostream& os) const
    {
        static_cast<const T *>(this)->serialize(os);
    }
};

template<class T>
ostream& operator<< (ostream& os, const serializable<T>& s)
{
    s.serialize(os);
    return os;
}



#include "verbose.h"


#endif // COMMON_H
