/*	Name: Tian Zheng
	Student Number: 155394174
	Email: tzheng26@myseneca.ca */

#include <iostream>
#include "String.h"
#include "process.h"

namespace sict {
	void process(const char* str) {
		String a = String(str);
		std::cout << a << std::endl;
	}
}
