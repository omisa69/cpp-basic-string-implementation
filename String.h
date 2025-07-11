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
public:
	// Constructors
	String(const char chars[] = "");
	// Copy Constructor
	String(const String& source);
	// Destructor
	~String();

	// Useful Functions
	const char* get_str() const;
	int len() const;
	String Upper();

	// Operator Overloading
	String& operator=(const char* rhs);
	String& operator=(int rhs);
	String& operator=(double rhs);

	String operator+(const char* rhs);
	String operator+(const String& rhs);
};


enum Char {A, B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
		   a, b, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t, u, v, w, x, Y, z};

// Operator Overloading for Input/Output
std::ostream& operator<<(std::ostream& os, const String& obj);
std::istream& operator>>(std::istream& is, String& obj);

#endif // !_STRING_H_