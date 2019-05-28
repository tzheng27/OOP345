/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include"Sale.h"
#include"Product.h"

extern int FW;

namespace sict {
	Sale::Sale(char* file) {
		std::ifstream readFile;
		readFile.open(file);

		if (!readFile.is_open()) {
			throw "Unable to read the file";
		}
		else {
			std::string lineholder;
			size_t count = 0;

			while (std::getline(readFile, lineholder)) { count++; }
			readFile.close();

			readFile.open(file);

			for(size_t i=0;i<count;i++){
				products.push_back(readRecord(readFile));
			}
			readFile.close();
		}
	}
	
	void Sale::display(std::ostream& os) const {
		if (!products.empty()) {
			double total = 0.0;
			os.width(FW);
			os << std::endl;
			os << "Product No";
			os.width(FW);
			os << "Cost" << std::endl;
			for (size_t i = 0; i < products.size();i++) {
				products[i]->display(os);
				total += products[i]->price();
			}
			os.width(FW);
			os << "Total";
			os.width(FW);
			os.setf(std::ios::fixed);
			os.precision(2);
			os << total << std::endl;
			os.unsetf(std::ios::fixed);
			os.precision(6);

		}
	}
}