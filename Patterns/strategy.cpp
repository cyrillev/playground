#include "strategy.h"
#include "common.h"

Context1::Context1(AlgoFunc func, int initialValue)
    : algo(func), currentValue(initialValue)
{}

int Context1::value() const
{
    return currentValue;
}

void Context1::setValue(int value)
{
    currentValue = value;
}

int Context1::compute(int param)
{
    algo(*this, param);

    return currentValue;
}



void multiply(Context1& context, int param)
{
    const int oldValue = context.value();
    const int newValue = oldValue*param;
    context.setValue( newValue );

    cout << "multiply " << oldValue << " with " << param << " -> " << newValue << endl;
}


struct Calculator
{
    Calculator(int _extra) : extra(_extra) {}

    void operator()(Context1& context, int param)
    {
        const int oldValue = context.value();
        const int newValue = oldValue + param;
        context.setValue( newValue );

        extra = newValue/2;

        cout << "add " << param << " to " <<  oldValue << " with extra " << extra << " -> " << newValue << endl;
    }

    int extra;
};


struct BindedCalculator
{
    BindedCalculator(int _extra) : extra(_extra) {}

    void substract(Context1& context, int param)
    {
        const int oldValue = context.value();
        const int newValue = oldValue + param;
        context.setValue( newValue );

        extra = newValue/2;

        cout << "substract " << param << " to " <<  oldValue << " with extra " << extra << " -> " << newValue << endl;
    }

    int extra;
};


void test_strategy()
{
    // Example using a function
    Context1 cxt_1_1( multiply, 2 );
    cxt_1_1.compute( 4 );
    cxt_1_1.compute( 5 );

    // Example using a functor
    Context1 cxt_1_2( Calculator(20), 2 );
    cxt_1_2.compute( 4 );
    cxt_1_2.compute( 5 );
}
