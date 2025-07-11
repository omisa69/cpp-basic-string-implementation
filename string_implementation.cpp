#include <iostream>
#include "String.h"
#include <vector>


int main() {
    // Create a String from a literal
    String s1("Hello");

    // Print it
    std::cout << "s1: " << s1 << std::endl;

    // Get length
    std::cout << "Length of s1: " << s1.len() << std::endl;

    // Use assignment operator
    s1 = "Hi";
    std::cout << "s1 after assignment: " << s1 << std::endl;

    // Add a C-string to s1
    String s2 = s1 + " there!";
    std::cout << "s2 (s1 + \" there!\"): " << s2 << std::endl;

    // Add a String to s1
    String s3;
    std::cout << "What's your name? ";
    std::cin >> s3;
    String s4 = s2 + " " + s3.totitle() + ".";
    std::cout << '\n' << "s4(s2 + s3) : " << s4 << std::endl;
    std::cout << "Uppercase: " << s3.toupper() << std::endl;
    std::cout << "Lowercase: " << s3.tolower() << std::endl;
    String s5, s6;
    s5 = 16;
    s6 = 16.2;
    std::cout << "The numeric value assigned respectively to s5 and s6: "
              << s5 + " and " + s6
              << std::endl;
    return 0;
}
