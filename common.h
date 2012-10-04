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
#include <tr1/memory>

// STL containers
#include <vector>
#include <list>

// std::tr1
#include <tr1/functional>

using namespace std;
using namespace std::tr1;
using namespace std::tr1::placeholders;

//  Boost
#include <boost/algorithm/string/join.hpp>


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
