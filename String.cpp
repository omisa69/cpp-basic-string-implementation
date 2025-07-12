#include "String.h"
#include <iostream>
#include <stdio.h>
#include <cstring> // for strcmp

// The Main Constructor
String::String(const char* chars)
    : length{ 0 }, str{nullptr} {
    set_str(chars);
}

// The Numberic Constructors
String::String(int number)
    : length{ 0 }, str{ nullptr } {
    char buffer [50];
    sprintf_s(buffer, "%d", number);
    set_str(buffer);
}
String::String(double number)
    : length{ 0 }, str{ nullptr } {
    char buffer[100];
    sprintf_s(buffer, "%f", number);
    set_str(buffer);
}

// The Copy Constructor
String::String(const String& source)
    : length{ 0 }, str{ nullptr } {
    /*std::cout << "Copying String: " << source.get_str() << std::endl;*/
    set_str(source.str);
}

// Move Constructor
String::String(String&& source) noexcept
    : str{ source.str }, length{source.length} {
    source.str = nullptr;
}

// str getter (Extranious?)
const char* String::get_str() const {
	return str;
}

// Destructor Implementation
String::~String() {
    delete[] str;
}

// Helper functions
int String::get_length(const char* chars) {
    int length{}, index{};
    char c{ chars[index] };
    while (c != '\0') {
        length++;
        index++;
        c = chars[index];
    }
    return length;
}

void String::set_str(const char* chars) {
    length = get_length(chars);
    if (str != nullptr) {
        delete[] str;
        str = nullptr;
    }
    str = new char[length+1];
    copy(str, chars);

}

void String::copy(char* const ptr, const char* value, int begin) {
    int value_length = get_length(value);
    for (size_t i = 0; i < value_length; i++)
    {
        ptr[i+begin] = value[i];
    }
    ptr[begin+value_length] = '\0';

}

char String::upper_char(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - ('a' - 'A');
    }
    else {
        switch (c) {
            // Nordic/German (your original ones)
        case 'å': return 'Å';
        case 'ä': return 'Ä';
        case 'ö': return 'Ö';
        case 'æ': return 'Æ';
        case 'ø': return 'Ø';
        case 'ü': return 'Ü';

            // French + Spanish accents
        case 'é': return 'É';
        case 'è': return 'È';
        case 'ê': return 'Ê';
        case 'ë': return 'Ë';
        case 'à': return 'À';
        case 'â': return 'Â';
        case 'î': return 'Î';
        case 'ï': return 'Ï';
        case 'ô': return 'Ô';
        case 'ù': return 'Ù';
        case 'û': return 'Û';
        case 'ç': return 'Ç';

        case 'ñ': return 'Ñ';  // Spanish
        case 'á': return 'Á';  // Spanish + French
        case 'í': return 'Í';  // Spanish
        case 'ó': return 'Ó';  // Spanish
        case 'ú': return 'Ú';  // Spanish

        default:
            return c;
        }
    }
}

char String::lower_char(char C) {
    if (C >= 'A' && C <= 'Z') {
        return C + ('a' - 'A');
    }
    else {
        switch (C) {
            // Nordic/German
        case 'Å': return 'å';
        case 'Ä': return 'ä';
        case 'Ö': return 'ö';
        case 'Æ': return 'æ';
        case 'Ø': return 'ø';
        case 'Ü': return 'ü';

            // French + Spanish accents
        case 'É': return 'é';
        case 'È': return 'è';
        case 'Ê': return 'ê';
        case 'Ë': return 'ë';
        case 'À': return 'à';
        case 'Â': return 'â';
        case 'Î': return 'î';
        case 'Ï': return 'ï';
        case 'Ô': return 'ô';
        case 'Ù': return 'ù';
        case 'Û': return 'û';
        case 'Ç': return 'ç';

        case 'Ñ': return 'ñ';  // Spanish
        case 'Á': return 'á';  // Spanish/French
        case 'Í': return 'í';  // Spanish
        case 'Ó': return 'ó';  // Spanish
        case 'Ú': return 'ú';  // Spanish

        default:
            return C;
        }
    }
}

// Utility Functions
int String::len() const {
    return length;
}

String String::toupper() {
    char* buffer = new char[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = upper_char(str[i]);
    }
    buffer[length] = '\0';
    String uppercase(buffer);
    delete [] buffer;
    return uppercase;
}

String String::tolower() {
    char* buffer = new char[length + 1];
    for (size_t i = 0; i < length; i++)
    {
        buffer[i] = lower_char(str[i]);
    }
    buffer[length] = '\0';
    String uppercase(buffer);
    delete[] buffer;
    return uppercase;
}

String String::totitle() {
    String titlecase (str);
    bool new_word{ true }; // The beginning of the fist word
    for (size_t i = 0; i < length; i++)
    {
        char c = titlecase.str[i];
        // Check if the character is white space:
        if (c == ' ' || c == '\n' || c == '\t') {
            new_word = true;
        }
        else if (new_word) {
            titlecase.str[i] = upper_char(c);
            new_word = false;
        }
        else {
            titlecase.str[i] = lower_char(c);
        }
    }
    return titlecase;
}

String String::slice(int start, int end, int step) {
    if (start >= end || end > length || start >= length)
        return String();
    int slice_length = end - start;
    char* buffer = new char [slice_length + 1];
    for (size_t i = 0; i < slice_length; i+=step)
    {
        buffer[i] = str[i + start];
    }
    buffer[slice_length] = '\0';
    String slice (buffer);
    delete[] buffer;
    return slice;
}

bool String::ends_with(const String& criterion) {
    int stop = length;
    int start = length - criterion.length;
    return strcmp(criterion.str, slice(start, stop).str) == 0;
}

bool String::ends_with(const char* chars) {
    return ends_with(String(chars));
}

bool String::starts_with(const String& criterion) {
    int start = 0;
    int stop = criterion.length;
    return strcmp(criterion.str, slice(start, stop).str) == 0;
}

bool String::starts_with(const char* chars) {
    return starts_with(String(chars));
}

int String::find(const String& string) {
    string.length;
    for (int i = 0; i < length; i++)
    {
        if (slice(i, length).starts_with(string))
            return i;
    }
    return -1;
 
}

int String::find(const char* chars) {
    return find(String(chars));
}

std::vector<int> String::findall(const String& string) {
    std::vector<int> indices;
    int index = find(string);
    int start{};
    if (index == -1) {
        return indices;
    }
    while (index != -1) {
        indices.push_back(index);
        start = index + string.length;
        index = slice(start, length).find(string);
        if (index != -1) {
            index += start;
        }
    }
    return indices;
}
std::vector<int> String::findall(const char* chars) {
    return findall(String(chars));
}

std::vector<String> String::split(const String& delimiter) {
    std::vector<String> substrings;
    std::vector<int> indices = findall(delimiter);
    int start{}, stop{};
    for (auto index : indices) {
        stop = index;
        if (stop > start)
            substrings.push_back(slice(start, stop));
        start = stop + delimiter.length;
    }
    if (start < length)
        substrings.push_back(slice(start, length));
    return substrings;
}

std::vector<String> String::split(const char* chars) {
    return split(String(chars));
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

String String::operator+(const String& rhs) {
    int new_length = length + rhs.length;
    char* buffer = new char[new_length + 1];

    copy(buffer, str);  // Copy old string    
    copy(buffer, rhs.get_str(), length);  // Copy new characters after old string

    String new_object{ buffer };

    delete[] buffer; // clean up the heap memory

    return new_object;
}

String String::operator+(const char* rhs) {
    String rhs_string {rhs};
    int rhs_length = get_length(rhs);
    return (*this + rhs_string);
}

String String::operator+=(const char* rhs) {
    String rhs_string{ rhs };
    String result = *this + rhs_string;
    set_str(result.get_str());
    return result;
}

String String::operator+=(const String& rhs) {
    return operator+=(rhs.str);
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

String operator+(const char* lhs, const String& rhs) {
    String lhs_string{ lhs };
    String output = lhs_string + rhs;
    return output;
}

String String::operator*(int rhs) {
    String string;
    for (size_t i = 0; i < rhs; i++)
    {
        string += str;

    }
    return string;
}

String operator*(const int lhs, const String& rhs) {
    String string;
    for (size_t i = 0; i < lhs; i++)
    {
        string += rhs;

    }
    return string;
}

void print(String obj, const char* end_with) {
    if (strcmp(end_with, "\n") == 0) {
        std::cout << obj << std::endl;
    }
    else {
        std::cout << obj << end_with;
    }
}

void print(std::vector<int> numbers) {
    size_t size = numbers.size();
    if (size > 0) {
        std::cout << "[";
        for (size_t i = 0; i < size - 1; i++)
        {
            std::cout << numbers.at(i) << ", ";
        }
        std::cout << numbers.at(size - 1) << "]" << std::endl;
    }
    else {
        std::cout << "[]" << std::endl;
    }
}

void print(std::vector<String> numbers) {
    size_t size = numbers.size();
    if (size > 0) {
        std::cout << "[";
        for (size_t i = 0; i < size - 1; i++)
        {
            std::cout << numbers.at(i) << ", ";
        }
        std::cout << numbers.at(size - 1) << "]" << std::endl;
    }
    else {
        std::cout << "[]" << std::endl;
    }
}