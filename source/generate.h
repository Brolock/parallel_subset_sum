#pragma once

#include <vector>
#include <algorithm>

#include <stdlib.h> // rand
#include <time.h> // to initialize the seed


#include "printer.h"

namespace tools
{
template<typename T>
std::vector<T> generate_array(std::size_t size, T max = 100)
{
    auto vec = std::vector<T>(size);

    srand(time(nullptr));

    std::for_each(vec.begin(), vec.end(),
            [](T& n){ n = (rand() % 100) - 50; });

    return vec;
}

template<typename T>
std::vector<std::vector<T>> generate_2D_array(std::size_t size, T max = 100)
{
    auto vec = std::vector<std::vector<T>>(size);

    for (auto& columns : vec)
        columns= std::vector<T>(size);

    srand(time(nullptr));

    std::for_each(vec.begin(), vec.end(),
            [](std::vector<T>& columns)
            {
                std::for_each(columns.begin(), columns.end(),
                    [](T& n){ n = (rand() % 100) - 50; });
            });
    return vec;
}
}
