#ifndef _STRING_H_
#define _STRING_H_


class String
{
private:
	char *str;
	int length;
public:
	// Constructor
	String();
	String(const char chars []);
	char* get_str();
	// Destructor
	~String();
};

#endif // !_STRING_H_