/*	Name: Tian Zheng
	Student Number: 155394174	*/

#include <iostream>
#include <cstring>
#include "String.h"

extern const int INITIAL;

namespace sict {

	String::String(const char* src) {
		if (src != nullptr) {
			for (int i = 0; i < MAX; i++) {
				destStr[i] = src[i];
			}
			destStr[MAX] = '\0';
		}
		else { destStr[0] = '\0'; }
		
	}

	String::String(const String& src) {
		*this = src;
	}

	String& String::operator=(const String& src) {
		if (this != &src) {
			strcpy(destStr, src.destStr);
		}
		return *this;
	}

	void String::display(std::ostream& os) const {

		os << destStr;
	}

	std::ostream& operator<<(std::ostream& os, const String& rhstring) {
		static int count = INITIAL;
		os << count << ": ";
		rhstring.display(os);
		count++;
		return os;
	}
}

