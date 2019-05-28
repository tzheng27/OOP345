/*	Name: Tian Zheng
	Student Number: 155394174
	Email: tzheng26@myseneca.ca */

#include <iostream>
#include <cstring>
#include "String.h"

extern int INITIAL;
static int count = INITIAL;

namespace sict {

	String::String() {
		destStr = nullptr;

	}

	String::String(const char* src) {
		destStr = nullptr;
		if (src != nullptr && src[0] != '\0') {
			destStr = new char[strlen(src) + 1];
			int length;
			for (int i = 0; src[i] != '\0'; i++) {
				destStr[i] = src[i];
				length = i;
			}
			destStr[length + 1] = '\0';
		}
		
	}

	String::String(const String& src) {
		destStr = nullptr;
		*this = src;
		
	}

	String& String::operator=(const String& src) {
		if (this != &src) {
			if (src.destStr != nullptr) {
				int length = strlen(src.destStr);
				destStr = new char[length + 1];
				for (int i = 0;i < length; i++) { destStr[i] = src.destStr[i]; }
				destStr[length + 1] = '\0';
			}
			else { destStr = nullptr;  }
		}
		return *this;
	}

	String::~String() {
		delete[] destStr;
		destStr = nullptr;
	}

	void String::display(std::ostream& os) const { os << destStr; }

	std::ostream& operator<<(std::ostream& os, const String& rhstring) {
		
		os << count << ": ";
		rhstring.display(os);
		count++;
		return os;
	}
}

