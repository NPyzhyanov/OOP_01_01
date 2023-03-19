#include <iostream>

#include "const_values.h"
#include "message_codes.h"

void feedback_message(MessageCodes message_code)
{
    setlocale (LC_ALL, "Russian");

    switch (message_code)
    {
        case file_not_opened:
            std::cout << "Не удалось открыть файл \"in.txt\"" << std::endl;
            break;
        case wrong_array_size:
            std::cout << "Введён некорректный размер массива! Введите число в диазоне от 0 до " << const_values::MAX_ARRAY_SIZE << std::endl;
            break;
        case unexpected_eof_detected:
            std::cout << "В файле присутствуют не все данные" << std::endl;
            break;
        case incomplete_line:
            std::cout << "Одна из строк введена не полностью" << std::endl;
            break;
        case out_of_bounds:
            std::cout << "Введено недопустимое число. Значения элементов массивов должны находиться в диапазоне от " << const_values::MIN_VALUE << " до " << const_values::MAX_VALUE << std::endl;
            break;
        case wrong_line_entry:
            std::cout << "В одной из строк присутствуют лишние данные" << std::endl;
            break;
        default:
            std::cerr << "Неизвестная ошибка!" << std::endl;
    }
}
