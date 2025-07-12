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

    
    
    String s5{16}, s6;
    s6 = 16.2;
    std::cout << "The numeric value assigned respectively to s5 and s6: "
              << s5 + " and " + s6
              << std::endl;
    String s7{ "Hello" };
    s7 += " World!";
    print(s7);

    // Slice
    String s8{"Strawberry"};
    print("Slice[1, 5] in Strawberry: " + s8.slice(1, 5));
    std::cout << s8 << " ends with berry? "
        << (s8.ends_with("berry") ? "true" : "false")
              << std::endl;
    std::cout << s8 << " ends with berr? "
        << (s8.ends_with("berr") ? "true" : "false")
        << std::endl;
    std::cout << s8 << " starts with Stra? "
        << (s8.starts_with("Stra") ? "true" : "false")
        << std::endl;
    std::cout << s8 << " starts with tra? "
        << (s8.starts_with("tra") ? "true" : "false")
        << std::endl;
    print(String("Namen") * 3);
    print(4 * String("Repeat"));
    print("Find ber in Strawberry:" + String(s8.find("ber")));
    print("Find bar in Strawberry:" + String(s8.find("bar")));
    std::cout << "Find all 'r' letters in Strawberry" << std::endl;
    print(s8.findall("r"));

    std::cout << "Split this sentence." << std::endl;
    
    std::vector<String> words = String("split this sentences.").split();
    print(words);
    std::cout << "Now, join them back." << std::endl;
    String sentence = String(" ").join(words);
    print(sentence);
    std::cout << "Replace s letters with M." << std::endl;
    print(sentence.replace("s", "M"));
    // Add a String to s1
    String s3;
    std::cout << "What's your name? ";
    // steam extraction operator with s3
    std::cin >> s3;
    String s4 = s2 + " " + s3.totitle() + ".";
    std::cout << "s4(s2 + s3) : " << s4 << std::endl;
    print("Uppercase: " + s3.toupper());
    print("Lowercase: " + s3.tolower());
    return 0;
}
