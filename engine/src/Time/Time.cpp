#include "Time.hpp"

#include <chrono>
#include <ctime>
#include <stdlib.h>

Time::Time()
{
    _time = Now();
    _strtime = (char*) malloc(sizeof(char) * TIME_STR_LEN);
}

double Time::Since(Time* t)
{
    std::chrono::duration<double> elapsed = Now() - t->GetTime();
    return elapsed.count(); // return elapsed time in seconds
}

const char* Time::String()
{
    time_t tt = std::chrono::high_resolution_clock::to_time_t(_time);
    auto lc = localtime(&tt);
    strftime(_strtime, TIME_STR_LEN, "%d-%m-%Y %H:%M:%S", lc);
    return _strtime;
}
