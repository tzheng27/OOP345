/* Name: Tian Zheng
   Student Number: 155394174
   Email: tzheng26@myseneca.ca */

#ifndef SICT_TXT_H
#define SICT_TXT_H

#include <iostream>

namespace sict {
	class Text {
		std::string* texts;
		size_t countstrings;
	public:
		Text();
		Text(char*);
		Text(const Text&);
		Text(Text&&);
		Text& operator=(const Text&);
		Text& operator=(Text&&);
		~Text();
		size_t size() const;
	};
}
#endif // !SICT_TXT_H
