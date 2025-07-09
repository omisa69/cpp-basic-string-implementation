#include "String.h"
#include <iostream>

//String::String()
//	: String { "" } {
//
//}

String::String(const char chars [])
	: str {chars} {
}

char* String::get_str() {
	return str;
}
