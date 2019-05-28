/*
Name: Tian Zheng
Student number: 155394174
Email: tzheng26@myseneca.ca
*/

#ifndef PROD_H
#define PROD_H

#include <iostream>
#include "iProduct.h"



namespace sict {
	class Product : public iProduct {
		int prod_num;
		double prod_price;
	public:
		Product(int, double);
		double price() const;
		void display(std::ostream& os) const;
	};

	std::ostream& operator<<(std::ostream& os, const iProduct& p);
	iProduct* readRecord(std::ifstream& file);
}


#endif // !PROD_H

