#ifndef _STRING_H_
#define _STRING_H_
#include <ostream>
#include <istream>
#include <initializer_list>
#include <vector>

class String
{
private:
	// Private Variables
	char* str;
	int length;
	// Private Functions
	int get_length(const char* chars);
	void set_str(const char* chars);
	void copy(char* const ptr, const char* value, int begin = 0);
	char upper_char(char c);
	char lower_char(char C);
public:
	// Constructors
	String(const char* chars="");
	String(int number);
	String(double number);
	// Copy Constructor
	String(const String& source);
	// Move Constructor
	String(String&& source) noexcept;
	// Destructor
	~String();

	// Utility Functions
	const char* get_str() const;
	int len() const;
	String toupper();
	String tolower();
	String totitle();
	String slice(int start, int stop, int step=1); // end is not included 
	bool ends_with(const char* chars);
	bool ends_with(const String& criterion);
	bool starts_with(const String& criterion);
	bool starts_with(const char* chars);
	int find(const String& string);
	int find(const char* chars);
	std::vector<int> findall(const String& string);
	std::vector<int> findall(const char* chars);
	std::vector<String> split(const String& delimiter=" ");
	std::vector<String> split(const char* chars);
	String join(const std::vector<String> strings);
	//String replace(const char* old, const char* _new);
	String append(const String& string);
	String prepend(const String& string);
	String replace(const String& old, const String& replacer);
	// Operator Overloading
	String& operator=(const char* rhs);
	String& operator=(int rhs);
	String& operator=(double rhs);

	String operator+(const char* rhs);
	String operator+(const String& rhs);

	String operator*(int rhs);

	String operator+=(const char* rhs);
	String operator+=(const String& rhs);
};

// Operator Overloading for Input/Output
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
String operator+(const char* lhs, const String& rhs);
String operator*(const int lhs, const String& rhs);

// Utility friend function
void print(String obj, const char* end_with="\n");
void print(std::vector<String> strings);
void print(std::vector<int> numbers);
void print(std::vector<String> numbers);
#endif // !_STRING_H_