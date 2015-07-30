#pragma once

#include "compute.h"
#include "type.h"

#include "tbb/tbb.h"

template<typename T>
class Looper
{
public:
    Looper() = default;

    Looper(const std::vector<std::vector<T>>& vec)
        : max_(0), pos_(0, 0, 0, 0), array_(vec)
    {}

    Looper(Looper& o, tbb::split)
        : max_(o.max_), pos_(o.pos_), array_(o.array_)
    {}

    void join(const Looper& other)
    {
        if (other.max_ > max_)
        {
            max_ = other.max_;
            pos_ = other.pos_;
        }
    }

    void operator()(const tbb::blocked_range<unsigned>& range)
    {
        std::vector<T> temp(array_.size());

        for (auto top = range.begin(); top != range.end(); ++top)
        {
            for (auto& value : temp)
                value = 0;

            unsigned left = 0;
            unsigned right = 0;

            for (unsigned bottom = top; bottom < array_[0].size(); ++bottom)
            {
                for (unsigned i = 0; i < array_.size(); ++i)
                    temp[i] += array_[i][bottom];

                T sum = kadane(temp, left, right);

                if (sum > max_)
                {
                    max_ = sum;
                    pos_ = Rectangle(left, top, right, bottom);
                }
            }
        }
    }

    T get_max() const { return max_; }
    Rectangle get_pos() const { return pos_; }

private:
    T max_;
    Rectangle pos_;

    const std::vector<std::vector<T>> array_;
};

template<typename T>
std::vector<std::vector<T>> parallel_max_subarray(const std::vector<std::vector<T>>& array)
{
    Looper<int> looper(array);

    {
        Timer timer("Parallel loop");
        tbb::parallel_reduce(tbb::blocked_range<unsigned>(0, array[0].size()), looper);
    }

    auto max = looper.get_max();
    auto pos(looper.get_pos());

    std::cerr << "Top left corner: ("
        << pos.top << ", " << pos.left << ")" << std::endl;
    std::cerr << "Bottom right corner: ("
        << pos.bottom << ", " << pos.right << ")" << std::endl;

    std::cerr << "Sum = " << max << std::endl;

    auto result = std::vector<std::vector<T>>(pos.right - pos.left + 1);
    auto col = std::vector<T>(pos.bottom - pos.top + 1);

    for (auto& vec : result)
        vec = col;

    for (unsigned i = pos.left; i <= pos.right; ++i)
        for (unsigned j = pos.top; j <= pos.bottom; ++j)
            result[i - pos.left][j - pos.top] = array[i][j];

    return result;
}
