#include "print_array.h"

#include <iostream>

void print_array(int array_size, int* array, int shift)
{
    std::cout << array_size << std::endl;
    
    if (array_size == 0)
    {
        std::cout << std::endl;
        return;
    }
    
    int print_position;
    for (int elem = 0; elem < array_size; elem++)
    {
        print_position = (array_size + elem - shift) % array_size;
        std::cout << array[print_position] << " ";
    }
    
    std::cout << std::endl;
}
