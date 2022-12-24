#ifndef TIME_HPP
#define TIME_HPP

#include <chrono>
#include <stdlib.h>

#define TIME_STR_LEN 20

class Time
{
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> _time;
        char* _strtime;

    public:
        static inline std::chrono::time_point<std::chrono::high_resolution_clock> Now()
        {
            return std::chrono::high_resolution_clock::now();
        }

    public:
        static double Since(Time* t);

    public:
        Time();
        const char* String();

    public:
        ~Time() { free(_strtime); }
        inline std::chrono::time_point<std::chrono::high_resolution_clock> GetTime() { return _time; }
};

#endif
