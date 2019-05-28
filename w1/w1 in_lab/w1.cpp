/*	Name: Tian Zheng
	Student Number: 155394174	*/

#include <iostream>
#include "process.h"
using namespace sict;

extern const int INITIAL = 3;

int main(int argc, char *argv[]) {
	if (argc > 1) {
		std::cout << "Command Line : ";
		for (int i = 0; i < argc; i++) {
			std::cout << argv[i] << " ";
		}
		std::cout << std::endl;
		for (int i = 1; i < argc; i++) {
			process(argv[i]);
		}
		return 0;
	}
	else {
		std::cout << "***Insufficient number of arguments***" << std::endl;
		return 1;
	}
}

