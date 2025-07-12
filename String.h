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
	int get_length(const char chars[]);
	void set_str(const char chars[]);
	void copy(char* const ptr, const char value[], int begin = 0);
	char upper_char(char c);
	char lower_char(char C);
public:
	// Constructors
	String(const char chars[]="");
	String(int number);
	String(double number);
	// Copy Constructor
	String(const String& source);
	// Destructor
	~String();

	// Useful Functions
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

void print(String obj, const char* end_with="\n");
#endif // !_STRING_H_