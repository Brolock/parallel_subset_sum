#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

namespace tools
{
template<typename T>
void print_vector(const std::vector<T>& vec)
{
    std::cout << "[ ";
    std::for_each(vec.begin(), vec.end(),
            [](const T& value){ std::cout << value << " "; });
    std::cout << "]" << std::endl;
}

template<typename T>
void print_vector(const std::vector<std::vector<T>>& vec)
{
    if (vec.size() == 0)
    {
        std::cout << "No sub_array found" << std::endl;
        return;
    }
    std::cout << "[\n";
    for (int j = 0; j < vec[0].size(); ++j)
    {
        std::cout << "{ ";
        for (int i = 0; i < vec.size(); ++i)
        {
            // Boring checking to have a nice alignement in the printing
            if (vec[i][j] >= 0 && vec[i][j] < 10)
                std::cout << "  ";
            else if (vec[i][j] >= 10 || (vec[i][j] < 0 && vec[i][j] > -10))
                std::cout << " ";


            std::cout << vec[i][j] << " ";
        }
        std::cout << "}\n";
    }
    std::cout << "]" << std::endl;
}
}
