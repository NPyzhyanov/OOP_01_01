#include "get_arrays.h"
#include "print_array.h"

int main()
{
    int array_N_size = 0;
    int* array_N = nullptr;
    int array_M_size = 0;
    int* array_M = nullptr;
    
    bool arrays_got = get_arrays(&array_N_size, array_N, &array_M_size, array_M);
    if (!arrays_got)
    {
        delete[] array_N;
        delete[] array_M;
        return 1;
    }
    
    print_array(array_M_size, array_M, 1);
    print_array(array_N_size, array_N, -1);
    
    delete[] array_N;
    delete[] array_M;
    array_N = nullptr;
    array_M = nullptr;
    
    return 0;
}
