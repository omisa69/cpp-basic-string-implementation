#include <iostream>
#include "String.h"



int get_length(const char chars []) {
    int length{}, index{};
    char c{chars[index]};
    while (c != '\0') {
        length++;
        index++;
        c = chars[index];
    }
    std::cout << "Length :" << length << std::endl;
    return length;
}

char* get_str(const char word []) {
    int length = get_length(word);
    char* string = new char[length+1];
    for (size_t i = 0; i < length; i++)
    {
        string[i] = word[i];
    }
    string[length] = '\0';
    return string;
}

int main()
{
    char* word = get_str("7");
    std::cout << "Word: " << word << std::endl;
    std::cout << "Length: " << get_length(word) << std::endl;
    delete[] word;
    word = nullptr;
    return 0;
}