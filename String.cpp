#include "String.h"
#include <iostream>

// The Main Constructor
String::String(const char chars[])
    : length{ get_length(chars) } {
    str = new char[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        str[i] = chars[i];
    }
    str[length] = '\0';
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

// Helper function
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

// Usefule Functions
int String::len() {
    return length;
}

// Operator Overloading
String& String::operator=(const char* chars) {
    delete[] str;
    str = new char[get_length(chars)];
    return *this;
}