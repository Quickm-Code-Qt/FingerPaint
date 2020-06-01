#ifndef SINGLETONBASE_H
#define SINGLETONBASE_H

template <typename T, typename D = T>
class SingletonBase
{
    friend D;
public:
    static T& getInstance();
protected:

private:
    SingletonBase() = default;
    ~SingletonBase() = default;
    SingletonBase(const SingletonBase&) = delete;
    void operator=(const SingletonBase&) = delete;

    static SingletonBase *  mInstance;
};

template <typename T, typename D>
T& SingletonBase<T, D>::getInstance()
{
    static D instance;
    return instance;
}

#endif // SINGLETONBASE_H
