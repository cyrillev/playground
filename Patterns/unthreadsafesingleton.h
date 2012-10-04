#ifndef UNTHREADSAFESINGLETON_H
#define UNTHREADSAFESINGLETON_H

template<class T>
class UnthreadSafeSingleton
{
    static T * pInstance;

    UnthreadSafeSingleton<T>();
    ~UnthreadSafeSingleton<T>();

    UnthreadSafeSingleton<T>(const UnthreadSafeSingleton<T>& rhs)
    {
        pInstance = rhs.pInstance;
    }

    UnthreadSafeSingleton<T>& operator = (const UnthreadSafeSingleton<T>& rhs)
    {
        if (this != &rhs)
        {
            pInstance = rhs.pInstance;
        }

        return *this;
    }


public:

    static UnthreadSafeSingleton<T>& getInstance()
    {
        static T theInstance;
        pInstance = &theInstance;

        return *pInstance;
    }
};

#endif // UNTHREADSAFESINGLETON_H
