#include "generate.h"
#include "printer.h"
#include "compute.h"

#include "parallel_compute.h"

int main(int argc, const char *argv[])
{
    // 2D array
    if (argc < 2)
        return -1;

    auto array_2D = tools::generate_2D_array<int>(atoi(argv[1]));
    tools::print_vector(array_2D);

    auto sub_array_2D = get_max_subarray(array_2D);

    tools::print_vector(sub_array_2D);

    //Parallel 2D
    //auto parallel_array = tools::generate_2D_array<int>(4);
    
    auto sub_thread = parallel_max_subarray(array_2D);

    tools::print_vector(sub_thread);

    return 0;
}
