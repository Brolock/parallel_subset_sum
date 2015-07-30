#pragma once

#include <vector>
#include <iostream>
#include <algorithm>

namespace tools
{
template<typename T>
void print_vector(const std::vector<T>& vec)
{
    std::cerr << "[ ";
    std::for_each(vec.begin(), vec.end(),
            [](const T& value){ std::cerr << value << " "; });
    std::cerr << "]" << std::endl;
}

template<typename T>
void print_vector(const std::vector<std::vector<T>>& vec)
{
    if (vec.size() == 0)
    {
        std::cerr << "No sub_array found" << std::endl;
        return;
    }
    std::cerr << "[\n";
    for (unsigned j = 0; j < vec[0].size(); ++j)
    {
        std::cerr << "{ ";
        for (unsigned i = 0; i < vec.size(); ++i)
        {
            // Boring checking to have a nice alignement in the printing
            if (vec[i][j] >= 0 && vec[i][j] < 10)
                std::cerr << "  ";
            else if (vec[i][j] >= 10 || (vec[i][j] < 0 && vec[i][j] > -10))
                std::cerr << " ";


            std::cerr << vec[i][j] << " ";
        }
        std::cerr << "}\n";
    }
    std::cerr << "]" << std::endl;
}
}
