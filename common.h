#ifndef COMMON_H
#define COMMON_H

#include <ostream>
#include <iostream>
#include <sstream>
#include <string>
#include <stdexcept>
#include <memory>
#include <vector>
#include <list>
#include <complex>
#include <functional>

using namespace std;

//  Boost
#include <boost/algorithm/string/join.hpp>

#ifndef CPLUSPLUS11
#include <boost/shared_ptr.hpp>
#include <boost/weak_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/function.hpp>
#include <boost/thread.hpp>
#include <boost/thread/mutex.hpp>
#include <boost/thread/locks.hpp>
#include <boost/random.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>

using boost::weak_ptr;
using boost::shared_ptr;
using boost::enable_shared_from_this;
using boost::function;
using boost::thread;
using boost::mutex;
using boost::lock_guard;
using boost::unique_lock;
using boost::condition_variable;

using namespace boost::random;
using namespace boost::posix_time;

namespace this_thread
{
void sleep_for(time_duration abs_time);
}

#else
#include <random>
#include <chrono>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std::chrono;

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
