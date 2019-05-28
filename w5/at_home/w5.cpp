/*Name: Tian Zheng
Student Number: 155394174
Email: tzheng26@myseneca.ca */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include "KVPair.h"
#include "KVList.h"
#include "Taxable.h"
using namespace sict;

float HST = 0.13f;
int fieldWidth = 10;

template <typename L, typename T, typename K, typename V>
L createList(char* filename) {
	std::ifstream file(filename);
	if (!file) {
		L list(0);
		return std::move(list);
	}
	int no_records = 0;
	do {
		char c = file.get();
		if (file.good() && c == '\n') no_records++;
	} while (!file.eof());
	file.clear();
	file.seekg(std::ios::beg);
	L list(no_records);
	do {
		K key;
		V value;
		file >> key;
		if (file) {
			file >> value;
			file.ignore();
			list.push_back(T(key, value));
		}
	} while (file);

	return std::move(list);
}

int main(int argc, char* argv[]) {
	std::cout << "Command Line : ";
	for (int i = 0; i < argc; i++) {
		std::cout << argv[i] << ' ';
	}
	std::cout <<std::endl;

	// check for command line errors
	if (argc != 3) {
		std::cout << "Wrong number of arguments" << std::endl;
		exit(1);
	}

	// set for fixed, 2-decimal point output
	std::cout << std::fixed << std::setprecision(2);

	// process price list file
	KVList<KVPair<std::string, float>> priceList = createList<
		KVList<KVPair<std::string, float>>,
		KVPair<std::string, float>,
		std::string,
		float>
		(argv[1]);
	std::cout << "\nPrice List with G+S Taxes Included\n==================================\n";
	std::cout << "Description:      Price Price+Tax\n";
	priceList.display(std::cout, Taxable(HST));

	// process student file
	try {
		KVList<KVPair<int, float>> studentList = createList<
			KVList<KVPair<int, float>>,
			KVPair<int, float>,
			int,
			float>
			(argv[2]);

		std::cout << "\nStudent List Letter Grades Included\n===================================\n";
		std::cout << "Student No :      Grade    Letter\n";
		studentList.display(std::cout, [](float src) {
			std::string letter;
			if (src >= 90)
				letter = "A+";
			else if (src >= 80)
				letter= "A ";
			else if (src >= 75)
				letter="B+";
			else if (src >= 70)
				letter="B ";
			else if (src >= 65)
				letter="C+";
			else if (src >= 60)
				letter="C ";
			else if (src >= 55)
				letter="D+";
			else if (src >= 50)
				letter="D ";
			else
				letter="F ";

			return letter;
		});
	}
	catch (const char* msg) {
		std::cout << msg << std::endl;
		std::exit(2);
	}
	catch (int& value) {
		std::cout << value << " is outside bounds" << std::endl;
		std::exit(3);
	}
	catch (...) {
		std::exit(4);
	}
	
	
	return 0;
}