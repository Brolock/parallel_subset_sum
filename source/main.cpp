#include "generate.h"
#include "printer.h"
#include "compute.h"

#include "parallel_compute.h"

int main(int argc, const char *argv[])
{
    // 2D array
    if (argc < 2)
        return -1;
    
    int nb_threads = 4;
    if (argc > 2)
        nb_threads = atoi(argv[2]);

    tbb::task_scheduler_init init(nb_threads);

    std::cout << "array of size: " << atoi(argv[1]) << "x" << atoi(argv[1]) << std::endl;
    std::cout << "using " << nb_threads << " threads" << std::endl;

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
