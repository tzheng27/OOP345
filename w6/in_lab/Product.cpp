/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#include<iostream>
#include<fstream>
#include"Product.h"

extern int FW;

namespace sict {
	Product::Product(int srcNum, double srcPrice) {
		if (srcNum > 0 && srcPrice > 0) {
			prod_num = srcNum;
			prod_price = srcPrice;
		}
		else {
			prod_num = 0;
			prod_price = 0;
		}
	}

	double Product::price() const {
		return prod_price;
	}

	void Product::display(std::ostream& os) const {
		if (prod_num > 0) {
			os.width(FW);
			os << prod_num;
			os.width(FW);
			os.setf(std::ios::fixed);
			os.precision(2);
			os << prod_price;
			os.unsetf(std::ios::fixed);
			os.precision(6);
			os << std::endl;
		}
	}

	std::ostream& operator<<(std::ostream& os, const iProduct& p) {
		p.display(os);
		return os;
	}

	iProduct* readRecord(std::ifstream& file) {
		iProduct* newProd = nullptr;
		int newNum;
		double newPrice;
		file >> newNum >> newPrice;
		newProd = new Product(newNum, newPrice);
		return newProd;
	}

}