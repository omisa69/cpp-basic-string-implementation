#include "String.h"
#include <iostream>
#include <stdio.h>

// The Main Constructor
String::String(const char chars[])
    : length{ get_length(chars) }, str{nullptr} {
    str = new char[length + 1];
    copy(str, chars);
}

// The Copy Constructor
String::String(const String& source)
    : length{ source.len() }, str{nullptr} {
    std::cout << "Copying String: " << source.get_str() << std::endl;
    str = new char[length + 1];
    copy(str, source.str);
}

const char* String::get_str() const {
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
int String::len() const {
    return length;
}

// Operator Overloading
// Assignment operator
String& String::operator=(const char* rhs) {
    set_str(rhs);
    return *this;
}

String& String::operator=(int rhs) {
    char buffer[50];
    sprintf_s(buffer, "%d", rhs);
    set_str(buffer);
    return *this;
}

String& String::operator=(double rhs) {
    char buffer[100];
    sprintf_s(buffer, "%f", rhs);
    set_str(buffer);
    return *this;
}

String String::operator+(const char* rhs) {
    String rhs_string {rhs};
    int rhs_length = get_length(rhs);
    return *this + rhs_string;
}

String String::operator+(const String &rhs) {
    int new_length = length + rhs.length;
    char* new_str = new char[new_length+1];

    // Copy old string
    copy(new_str, str);

    // Copy new characters after old string
    copy(new_str, rhs.get_str(), length);
    
    String new_object{ new_str };
    
    delete[] new_str; // clean up the heap memory

    return new_object;

}

std::ostream& operator<<(std::ostream& os, const String &obj) {
    os << obj.get_str();
    return os;
}

std::istream& operator>>(std::istream& is, String& obj) {
    char* input = new char[2000];
    is.get(input, 2000);
    obj = input;  // uses operator=(const char*)
    delete[] input;
    return is;
}
