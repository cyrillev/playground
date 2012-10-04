#ifndef STRATEGY_H
#define STRATEGY_H

/*
 * The Strategy pattern suggests:
 * encapsulating an algorithm in a class hierarchy,
 * having clients of that algorithm hold a pointer to the base class of that hierarchy,
 * and delegating all requests for the algorithm to that “anonymous” contained object.
*/


#include "common.h"

class Context1;



class Context1
{
public:
    typedef function< void (Context1& context, int param) > AlgoFunc;

    explicit Context1(AlgoFunc func, int initialValue);


    int value() const;
    void setValue(int value);

    int compute(int param);

private:
    AlgoFunc algo;
    int currentValue;
};

#endif // STRATEGY_H
