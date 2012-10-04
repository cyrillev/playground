#ifndef UNCOPYABLE_H
#define UNCOPYABLE_H

class Uncopyable
{
protected:
    // Allow the class to be created and destroyed
    Uncopyable() {}
    virtual ~Uncopyable() {}

private:
    // Prevent the class to be copy
    Uncopyable(const Uncopyable&);
    Uncopyable& operator=(const Uncopyable&);
};


#endif // UNCOPYABLE_H
