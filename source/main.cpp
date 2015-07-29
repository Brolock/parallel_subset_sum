#include "generate.h"
#include "printer.h"
#include "compute.h"

int main(int argc, const char *argv[])
{
    // 1D array
    auto array = tools::generate_array<int>(10);

    tools::print_vector(array);

    auto sub_array = get_max_subarray(array);
    tools::print_vector(sub_array);

    // 2D array
    auto array_2D = tools::generate_2D_array<int>(4);
    tools::print_vector(array_2D);

    auto sub_array_2D = get_max_subarray(array_2D);

    tools::print_vector(sub_array_2D);
    

    return 0;
}
