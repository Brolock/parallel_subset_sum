#include "generate.h"

#include <algorithm>

#include <stdlib.h> // rand
#include <time.h> // to initialize the seed

namespace tools
{
std::vector<int> generate_array(std::size_t size, int max)
{
    auto vec = std::vector<int>(size);

    srand(time(nullptr));

    std::for_each(vec.begin(), vec.end(),
            [](int& n){ n = (rand() % 100) - 50; });

    return vec;
}
}
