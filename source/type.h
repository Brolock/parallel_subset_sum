#pragma once

#include <ctime>
#include <time.h>

// We could use a tuple but the accessors are not really meaningfull
class Rectangle
{
public:
    Rectangle() = default;
    Rectangle(unsigned o_left, unsigned o_top, unsigned o_right, unsigned o_bottom)
        : left(o_left), top(o_top), right(o_right), bottom(o_bottom)
    {}

    Rectangle(const Rectangle& other)
        : left(other.left), top(other.top), right(other.right), bottom(other.bottom)
                {}

    unsigned left, top, right, bottom;
};

class Timer
{
public:
    Timer(const std::string& name)
        : start_(std::clock()), name_(name)
    {
        clock_gettime(CLOCK_MONOTONIC, &clock_start_);
    }

    ~Timer()
    {
        struct timespec clock_end;
        clock_gettime(CLOCK_MONOTONIC, &clock_end);

        auto elapsed = double((std::clock() - start_) / double(CLOCKS_PER_SEC));
        double clock_elapsed = double(clock_end.tv_sec - clock_start_.tv_sec);
        clock_elapsed += double(clock_end.tv_nsec - clock_start_.tv_nsec) / 1000000000.0;
        std::cerr << name_ << " CPU time usage: " << elapsed * 1000 << " ms\n\t\tReal time: "
            << clock_elapsed << std::endl;

    }

private:
    std::clock_t start_;
    struct timespec clock_start_;
    std::string name_;
};
