#ifndef _STRING_H_
#define _STRING_H_
#include <ostream>
#include <istream>


class String
{
private:
	char* str;
	int length;
	int get_length(const char chars[]);
	void set_str(const char chars[]);
	void copy(char* const ptr, const char value [], int begin=0);
public:

	// Constructors
	String();
	String(const char chars []);
	// Copy Constructor
	
	// Destructor
	~String();

	// Useful Functions
	const char* get_str() const;
	int len() const;

	// Operator Overloading
	String& operator=(const char *rhs);

	String operator+(const char* rhs);
	String operator+(const String &rhs);
};

std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);
#endif // !_STRING_H_