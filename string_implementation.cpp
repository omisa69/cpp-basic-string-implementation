#include <iostream>
#include "String.h"
#include <vector>


int main() {
    String s1("Hello");
    // Add s1 to a C-string
    print("s1: " + s1);

    // Get length
    std::cout << "Length of s1: " << s1.len() << std::endl;

    // Use assignment operator
    s1 = "Hi";
    std::cout << "s1 after assignment: " << s1 << std::endl;

    // Add a C-string to s1
    String s2 = s1 + " there!";
    std::cout << "s2 (s1 + \" there!\"): " + s2 << std::endl;

    // Add a String to s1
    String s3;
    std::cout << "What's your name? ";
    // steam extraction operator with s3
    std::cin >> s3;
    String s4 = s2 + " " + s3.totitle() + ".";

    std::cout << '\n' << "s4(s2 + s3) : " << s4 << std::endl;
    print("Uppercase: " + s3.toupper());
    print("Lowercase: " + s3.tolower());
    String s5{16}, s6;
    s6 = 16.2;
    std::cout << "The numeric value assigned respectively to s5 and s6: "
              << s5 + " and " + s6
              << std::endl;
    String s7{ "Hello" };
    s7 += " World!";
    std::cout << s7;
    return 0;
}
