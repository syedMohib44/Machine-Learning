#include "thread_guard.h"

// Thread_guard::Thread_guard(std::thread &t)
// {
//     std::cout << "Creating thread";
//     Thread_guard::t = t;
// }

// Thread_guard::~Thread_guard()
// {
//     std::cout << "Ending";
//     if (this->t.joinable())
//         this->t.join();
// }

class Thread_guard
{

    std::thread *t;

public:
    Thread_guard(std::thread &t)
    {
        std::cout << "Creating thread";
        this->t = &t;
    }
    ~Thread_guard()
    {
        std::cout << "Ending";
        if (t->joinable())
            t->join();
    }

    //Delete the copy constructor
    Thread_guard(Thread_guard const &) = delete;

    //Delete the Assignment opeartor
    Thread_guard &operator=(Thread_guard const &) = delete;

    // private:
    //     std::thread t;
};