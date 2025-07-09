#ifndef _STRING_H_
#define _STRING_H_


class String
{
private:
	char* str{nullptr};
	int length;
	int get_length(const char chars[]);

public:

	// Constructors
	String();
	String(const char chars []);
	// Copy Constructor
	
	// Destructor
	~String();
	// Useful Functions
	char* get_str();
	int len();




	// Operator Overloading
	String &operator=(const char *chars);
	
};

#endif // !_STRING_H_