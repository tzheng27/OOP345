/*	Name: Tian Zheng
	Student Number: 155394174	*/

#ifndef SICT_STR_H
#define SICT_STR_H

#include <iostream>

namespace sict {
	const int MAX = 3;
	class String {
		char destStr[MAX+1];
	public:
		String(const char*);
		String(const String&);
		String& operator=(const String&);
		void display(std::ostream&) const;
	};

	std::ostream& operator<<(std::ostream&, const String&);
}
#endif // !SICT_STR_H



