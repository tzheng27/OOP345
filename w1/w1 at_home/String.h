/*	Name: Tian Zheng
	Student Number: 155394174	
	Email: tzheng26@myseneca.ca */

#ifndef SICT_STR_H
#define SICT_STR_H

#include <iostream>

namespace sict {
	class String {
		char* destStr;
	public:
		String();
		String(const char*);
		String(const String&);
		String& operator=(const String&);
		~String();
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const String&);
}
#endif // !SICT_STR_H



