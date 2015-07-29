#pragma once

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
T kadane(const std::vector<T>& array, int& begin, int& end)
{
    T max_ending_here = 0;
    T result = 0;

    int pos = 0;
    int temp_begin;

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

    std::pair<unsigned, unsigned> first_point, last_point;

    std::vector<T> temp(array.size());
    int begin, end;

    for (int left = 0; left < array[0].size(); ++left)
    {
        for (auto& value : temp)
            value = 0;

        for (int right = left; right < array[0].size(); ++right)
        {
            for (int i = 0; i < array.size(); ++i)
                temp[i] += array[i][right];

            sum = kadane(temp, begin, end);

            if (sum > max_sum)
            {

                max_sum = sum;
                first_point.first = left;
                first_point.second = begin;
                
                last_point.first = right;
                last_point.second = end;
            }
        }
    }

    std::cout << "Top left corner: ("
        << first_point.first << ", " << first_point.second << ")" << std::endl;
    std::cout << "Bottom right corner: ("
        << last_point.first << ", " << last_point.second << ")" << std::endl;

    std::cout << "Sum = " << max_sum << std::endl;

    auto result = std::vector<std::vector<T>>(last_point.second - first_point.second + 1);
    auto col = std::vector<T>(last_point.first - first_point.first + 1);

    for (auto& vec : result)
        vec = col;

    for (int i = first_point.second; i <= last_point.second; ++i)
        for (int j = first_point.first; j <= last_point.first; ++j)
            result[i - first_point.second][j - first_point.first] = array[i][j];

    return result;
}
