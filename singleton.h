#ifndef SINGLETON_H
#define SINGLETON_H

#include <mutex>


namespace patterns
{
    class singleton
    {
    public:
        static singleton& get_instance()
        {
            static singleton instance;
            return instance;
        }
    private:
        singleton() {};
        ~singleton() {}
        singleton(singleton const&) = delete;
        void operator=(singleton const&) = delete;
    };

    static std::mutex mtx;

    template<typename T>
    T& single_unsafe()
    {
        static T t;
        return t;
    }

    template<typename T>
    T& single()
    {
        static T* volatile pt;
        if (pt == 0)
        {
            T* tmp;
            {
                std::lock_guard<std::mutex> lock(mtx);
                tmp = &single_unsafe<T>();
            }
            pt = tmp;
        }
        return *pt;
    }
}

#endif // SINGLETON_H
