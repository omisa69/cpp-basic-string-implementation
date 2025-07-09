#include "String.h"
#include <iostream>

// The Main Constructor
String::String(const char chars[])
    : length{ get_length(chars) }, str{nullptr} {
    str = new char[length + 1];
    copy(str, chars);
}

// Default Constructor
String::String()
	: String { "" } {
} // Delegates to the main constructor with ""



char* String::get_str() {
	return str;
}

// Destructor Implementation
String::~String() {
    delete[] str;
}

// Helper functions
int String::get_length(const char chars[]) {
    int length{}, index{};
    char c{ chars[index] };
    while (c != '\0') {
        length++;
        index++;
        c = chars[index];
    }
    return length;
}

void String::set_str(const char chars[]) {
    length = get_length(chars);
    if (str != nullptr) {
        delete[] str;
        str = nullptr;
    }
    str = new char[length+1];
    copy(str, chars);

}

void String::copy(char* const ptr, const char value[], int begin) {
    int value_length = get_length(value);
    for (size_t i = 0; i < value_length; i++)
    {
        ptr[i+begin] = value[i];
    }
    ptr[begin+value_length] = '\0';

}

// Usefule Functions
int String::len() {
    return length;
}

// Operator Overloading
String& String::operator=(const char* chars) {
    set_str(chars);
    return *this;
}

String String::operator+(const char* chars) {
    int char_length = get_length(chars);
    int new_length = length + char_length;

    char* new_str = new char [new_length+1];

    // Copy old string
    copy(new_str, str);

    // Copy new characters after old string
    copy(new_str, chars, length);

    String new_object {new_str};

    delete[] new_str; // clean up the heap memory

    return new_object;
}