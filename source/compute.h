#pragma once

#include "type.h"

#include <iostream>

#include <vector>
#include <algorithm>

// See Kadanae algorithme for more details
template<typename T>
std::vector<T> get_max_subarray(const std::vector<T>& array)
{
    T max_ending_here = 0;
    T max_so_far = 0;

    auto result = std::vector<T>(); // stocks the final array
    result.reserve(array.size());

    auto temp = std::vector<T>(); // stocks the temporary array we are calculating the sum on
    temp.reserve(array.size());

    for (const auto& val : array)
    {
        // as soon as the value we are on become negative we can be sure it wont be the max value
        max_ending_here = std::max(0, max_ending_here + val);

        // we get the max sum we have between the previous one we got and the current one
        max_so_far = std::max(max_ending_here, max_so_far);

        // Stocking the array
        if (max_ending_here > 0)
            temp.push_back(val);
        else
            temp.clear();

        if (max_so_far == max_ending_here)
            result = temp;
    }
    std::cout << "The array sum is equal to: " << max_so_far << std::endl;

    return result;
}

// the simple version of the kadane without the array stocking
template<typename T>
T kadane(const std::vector<T>& array, unsigned& begin, unsigned& end)
{
    T max_ending_here = 0;
    T result = 0;

    unsigned pos = 0;
    unsigned temp_begin;

    for (const auto& val : array)
    {
        if (max_ending_here == 0)
            temp_begin = pos;

        // as soon as the value we are on become negative we can be sure it wont be the max value
        max_ending_here = std::max(0, max_ending_here + val);

        // we get the max sum we have between the previous one we got and the current one
        result = std::max(max_ending_here, result);

        if (result == max_ending_here)
        {
            begin = temp_begin;
            end = pos;
        }

        pos++;
    }
    return result;
}

template<typename T>
std::vector<std::vector<T>> get_max_subarray(const std::vector<std::vector<T>>& array)
{
    T max_sum = 0;
    T sum = 0;

    std::vector<T> temp(array.size());
    unsigned left = 0;
    unsigned right = 0;

    Rectangle pos(0, 0, 0, 0);

    for (unsigned top = 0; top < array[0].size(); ++top)
    {
        for (auto& value : temp)
            value = 0;

        for (unsigned bottom = top; bottom < array[0].size(); ++bottom)
        {
            for (unsigned i = 0; i < array.size(); ++i)
                temp[i] += array[i][bottom];

            sum = kadane(temp, left, right);

            if (sum > max_sum)
            {

                max_sum = sum;
                pos = Rectangle(left, top, right, bottom);
            }
        }
    }

    std::cout << "Top left corner: ("
        << pos.top << ", " << pos.left << ")" << std::endl;
    std::cout << "Bottom right corner: ("
        << pos.bottom << ", " << pos.right << ")" << std::endl;

    std::cout << "Sum = " << max_sum << std::endl;

    auto result = std::vector<std::vector<T>>(pos.right - pos.left + 1);
    auto col = std::vector<T>(pos.bottom - pos.top + 1);

    for (auto& vec : result)
        vec = col;

    for (unsigned i = pos.left; i <= pos.right; ++i)
        for (unsigned j = pos.top; j <= pos.bottom; ++j)
            result[i - pos.left][j - pos.top] = array[i][j];

    return result;
}
