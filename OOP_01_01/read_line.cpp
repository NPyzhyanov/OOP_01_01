//#include "read_line.h"

#include <fstream>
#include <string>

#include "message_codes.h"
#include "const_values.h"

MessageCodes read_line(std::ifstream* p_file, int number_of_words, int* array_to_write, bool last_line_expected)
{
    if (number_of_words < 0 || number_of_words > const_values::MAX_ARRAY_SIZE)
    {
        return wrong_array_size;
    }
    
    bool zero_words = (number_of_words == 0) ? true : false;
    
    MessageCodes return_code = ok;
    
    std::string taken_word;
    int tmp = 0;
    int word = 0;
    
    while ((word < number_of_words) && !zero_words)
    {
        taken_word = "";
        *p_file >> taken_word;
        
        if (taken_word.length() == 0)
        {
            return_code = incomplete_line;
            break;
        }
        
        tmp = std::stoi(taken_word);
        
        if (tmp < const_values::MIN_VALUE || tmp > const_values::MAX_VALUE)
        {
            array_to_write[word] = 0;
            return_code = out_of_bounds;
            break;
        }
        else
        {
            array_to_write[word] = tmp;
        }
        
        if (p_file->eof())
        {
            return_code = (last_line_expected && (word == number_of_words - 1)) ? ok : unexpected_eof_detected;
            break;
        }
        
        word++;
    }
    
    if (return_code != ok)
    {
        return return_code;
    }
    
    while(p_file->get() != '\n' && !p_file->eof())
    {
        return_code = wrong_line_entry;
    }
    
    return return_code;
}
