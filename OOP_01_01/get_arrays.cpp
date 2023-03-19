#include "get_arrays.h"

#include <fstream>

#include "message_codes.h"
#include "feedback_message.h"
#include "read_line.h"

bool get_arrays(int* p_array_N_size, int* &array_N, int* p_array_M_size, int* &array_M)
{
    std::ifstream input_file("../OOP_01_01/in.txt");
    if (! input_file.is_open())
    {
        feedback_message(file_not_opened);
        return false;
    }
    
    std::ifstream* p_file = &input_file;
    
    MessageCodes return_code = read_line(p_file, 1, p_array_N_size, false);
    if (return_code != ok)
    {
        feedback_message(return_code);
        if (return_code != wrong_line_entry)
        {
            input_file.close();
            return false;
        }
    }
    
    int array_N_size = *p_array_N_size;
    array_N = new int[array_N_size]();
    
    return_code = read_line(p_file, array_N_size, array_N, false);
    if (return_code != ok)
    {
        feedback_message(return_code);
        if (return_code != wrong_line_entry)
        {
            input_file.close();
            return false;
        }
    }
    
    return_code = read_line(p_file, 1, p_array_M_size, false);
    if (return_code != ok)
    {
        feedback_message(return_code);
        if (return_code != wrong_line_entry)
        {
            input_file.close();
            return false;
        }
    }
    
    int array_M_size = *p_array_M_size;
    array_M = new int[array_M_size]();
    
    return_code = read_line(p_file, array_M_size, array_M, true);
    if (return_code != ok)
    {
        feedback_message(return_code);
        if (return_code != wrong_line_entry)
        {
            input_file.close();
            return false;
        }
    }
    
    input_file.close();
    
    return true;
}
